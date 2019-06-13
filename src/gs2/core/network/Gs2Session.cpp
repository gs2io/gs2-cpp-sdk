/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All
 * Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

#include "Gs2Session.hpp"
#include "Gs2SessionTask.hpp"
#include "../json/JsonWriter.hpp"
#include "../json/JsonParser.hpp"

GS2_START_OF_NAMESPACE

Gs2Session::~Gs2Session()
{
    // disconnect() が複数のコールバックを叩き終わらないうちに破棄されないように、1回ロックへ入る
    std::lock_guard<std::mutex> lock(m_Mutex);
}

void Gs2Session::triggerConnectCallback(detail::IntrusiveList<ConnectCallbackHolder>& connectCallbackHolderList, AsyncResult<void>& result)
{
    while (auto* pConnectCallbackHolder = connectCallbackHolderList.pop())
    {
        pConnectCallbackHolder->callback()(result);
        delete pConnectCallbackHolder;
    }
}

void Gs2Session::triggerDisconnectCallback(detail::IntrusiveList<DisconnectCallbackHolder>& disconnectCallbackHolderList)
{
    while (auto* pDisconnectCallbackHolder = disconnectCallbackHolderList.pop())
    {
        pDisconnectCallbackHolder->callback()();
        delete pDisconnectCallbackHolder;
    }
}

void Gs2Session::connect(ConnectCallbackType callback)
{
    m_Mutex.lock();

    if (isAvailable())
    {
        m_Mutex.unlock();

        AsyncResult<void> result;
        callback(result);
    }
    else
    {
        if (!isConnecting())
        {
            connectImpl();
        }

        // isConnecting() はコールバックホルダリストが空かどうかで判定するので、追加はあとから行う
        m_ConnectCallbackHolderList.push(*new ConnectCallbackHolder(std::move(callback)));

        m_Mutex.unlock();
    }
}

void Gs2Session::connectCallback(optional<StringHolder>& projectToken, Gs2ClientException* pClientException)
{
    // 接続完了コールバック

    m_Mutex.lock();

    if (isDisconnecting())
    {
        // ログイン処理中に disconnect() が呼ばれた場合

        m_ProjectToken.reset();

        detail::IntrusiveList<ConnectCallbackHolder> connectCallbackHolderList(std::move(m_ConnectCallbackHolderList));
        detail::IntrusiveList<DisconnectCallbackHolder> disconnectCallbackHolderList(std::move(m_DisconnectCallbackHolderList));

        m_Mutex.unlock();

        // connect() はすべてキャンセルする
        Gs2ClientException gs2ClientException;
        gs2ClientException.setType(Gs2ClientException::UnknownException);   // TODO
        AsyncResult<void> result(&gs2ClientException);
        Gs2Session::triggerConnectCallback(connectCallbackHolderList, result);

        Gs2Session::triggerDisconnectCallback(disconnectCallbackHolderList);
    }
    else if (pClientException == nullptr)
    {
        // ログイン処理がエラーなく応答された場合

        if (projectToken)
        {
            m_ProjectToken = std::move(projectToken);

            detail::IntrusiveList<ConnectCallbackHolder> connectCallbackHolderList(std::move(m_ConnectCallbackHolderList));

            m_Mutex.unlock();

            AsyncResult<void> result;
            Gs2Session::triggerConnectCallback(connectCallbackHolderList, result);
        }
        else
        {
            // 応答からプロジェクトトークンが取得できなかった場合

            detail::IntrusiveList<ConnectCallbackHolder> connectCallbackHolderList(std::move(m_ConnectCallbackHolderList));

            m_Mutex.unlock();

            Gs2ClientException gs2ClientException;
            gs2ClientException.setType(Gs2ClientException::UnknownException);   // TODO

            AsyncResult<void> result(&gs2ClientException);
            Gs2Session::triggerConnectCallback(connectCallbackHolderList, result);
        }
    }
    else
    {
        // ログイン処理がエラーになった場合

        detail::IntrusiveList<ConnectCallbackHolder> connectCallbackHolderList(std::move(m_ConnectCallbackHolderList));

        m_Mutex.unlock();

        AsyncResult<void> result(pClientException);
        Gs2Session::triggerConnectCallback(connectCallbackHolderList, result);
    }
}

void Gs2Session::disconnect(DisconnectCallbackType callback)
{
    m_Mutex.lock();

    m_DisconnectCallbackHolderList.push(*new DisconnectCallbackHolder(std::move(callback)));

    if (isConnecting() || isUsed())
    {
        // 接続処理中、もしくは処理中のタスクがあるなら、切断処理は notifyComplete() の中で処理完了後に開始する

        m_Mutex.unlock();
    }
    else
    {
        // 接続処理中、もしくは処理中でなければ、即座に切断処理を開始する

        bool isDisconnectInstant = startDisconnect();

        if (!isDisconnectInstant)
        {
            m_Mutex.unlock();
        }
    }
}

bool Gs2Session::startDisconnect()
{
    // m_Mutex のロックを取った上で呼ぶこと

    m_ProjectToken.reset();
    return disconnectImpl();
}

void Gs2Session::disconnectCallback(bool isDisconnectInstant)
{
    if (!isDisconnectInstant)
    {
        m_Mutex.lock();
    }

    detail::IntrusiveList<DisconnectCallbackHolder> disconnectCallbackHolderList(std::move(m_DisconnectCallbackHolderList));

    m_Mutex.unlock();

    Gs2Session::triggerDisconnectCallback(disconnectCallbackHolderList);
}

void Gs2Session::execute(detail::Gs2SessionTask &gs2SessionTask)
{
    m_Mutex.lock();

    if (isAvailable() && !isDisconnecting())
    {
        // connect が完了していて、かつ disconnect が呼ばれていなければタスクを実行

        prepareImpl(gs2SessionTask);

        m_Gs2SessionTaskList.push(gs2SessionTask);

        m_Mutex.unlock();

        gs2SessionTask.executeImpl();
    }
    else
    {
        // 失敗を即コールバック

        m_Mutex.unlock();

        Gs2ClientException gs2ClientException;
        gs2ClientException.setType(Gs2ClientException::UnknownException);   // TODO
        gs2SessionTask.callback("", &gs2ClientException);
    }
}

void Gs2Session::notifyComplete(detail::Gs2SessionTask& gs2SessionTask)
{
    m_Mutex.lock();

    m_Gs2SessionTaskList.remove(gs2SessionTask);

    if (isDisconnecting() && !isUsed())
    {
        // タスク終了を待機していた disconnect があれば実行

        bool isDisconnectInstant = startDisconnect();

        if (!isDisconnectInstant)
        {
            m_Mutex.unlock();
        }
    }
    else
    {
        m_Mutex.unlock();
    }
}

GS2_END_OF_NAMESPACE
