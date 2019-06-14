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

void Gs2Session::changeStateToIdle()
{
    assert(m_State == State::Connecting || m_State == State::CancellingConnect || m_State == State::Disconnecting);

    assert(m_ConnectCallbackHolderList.isEmpty());      // すべてコールバックされ（るために取り出され）ているべき
    assert(m_DisconnectCallbackHolderList.isEmpty());   // すべてコールバックされ（るために取り出され）ているべき
    assert(m_Gs2SessionTaskList.isEmpty());             // Connected になる前に登録はできない

    m_State = State::Idle;

    exitStateLock();
}

void Gs2Session::changeStateToConnecting()
{
    assert(m_State == State::Idle || m_State == State::Disconnecting);

    assert(!m_ConnectCallbackHolderList.isEmpty());     // connect() タスクが登録されているときのみ遷移する
    assert(m_DisconnectCallbackHolderList.isEmpty());   // すべてコールバックされ（るために取り出され）ているべき
    assert(m_Gs2SessionTaskList.isEmpty());             // Connected になる前に登録はできない

    m_State = State::Connecting;

    connectImpl();

    exitStateLock();
}

void Gs2Session::changeStateToCancellingConnect()
{
    assert(m_State == State::Connecting);

    assert(!m_ConnectCallbackHolderList.isEmpty());     // Connecting は connect() タスクが必ず存在する
    assert(!m_DisconnectCallbackHolderList.isEmpty());  // 接続処理中の disconnect() によってのみ遷移する
    assert(m_Gs2SessionTaskList.isEmpty());             // Connected になる前に登録はできない

    m_State = State::CancellingConnect;

    cancelConnectImpl();

    exitStateLock();
}

void Gs2Session::changeStateToConnected(StringHolder&& projectToken)
{
    assert(m_State == State::Connecting);

    assert(m_ConnectCallbackHolderList.isEmpty());      // すべてコールバックされ（るために取り出され）ているべき
    assert(m_DisconnectCallbackHolderList.isEmpty());   // disconnect() が呼ばれている場合は Disconnecting に遷移しなければならない
    assert(m_Gs2SessionTaskList.isEmpty());             // Connected になる前に登録はできない

    m_ProjectToken = std::move(projectToken);

    m_State = State::Connected;

    exitStateLock();
}

void Gs2Session::changeStateToCancellingTasks()
{
    assert(m_State == State::Connected);

    assert(m_ConnectCallbackHolderList.isEmpty());      // Connected のあいだの connect() は即時返却される
    // 外部要因による切断の場合に disconnect() を呼ばなくても遷移することがある
    assert(!m_Gs2SessionTaskList.isEmpty());            // キャンセルしたいタスクがあるから遷移するのである

    m_State = State::CancellingTasks;

    exitStateLock();
}

void Gs2Session::changeStateToDisconnecting()
{
    assert(m_State == State::Connecting || m_State == State::CancellingConnect || m_State == State::Connected || m_State == State::CancellingTasks);

    // CancellingTasks のあいだには次の connect() が積まれることがある
    // 外部要因による切断の場合に disconnect() を呼ばなくても遷移することがある
    assert(m_Gs2SessionTaskList.isEmpty());             // タスクがなくなったときに遷移する

    m_ProjectToken.reset();

    m_State = State::Disconnecting;

    bool isDisconnectInstant = disconnectImpl();

    if (isDisconnectInstant)
    {
        // Idle か Connecting に遷移しているはずだけど、ロックから出てしまっているので検証はしない
    }
    else
    {
        exitStateLock();
    }
}

void Gs2Session::keepCurrentState()
{
    exitStateLock();
}

void Gs2Session::connect(ConnectCallbackType callback)
{
    enterStateLock();

    switch (m_State)
    {
    case State::Idle:
        m_ConnectCallbackHolderList.push(*new ConnectCallbackHolder(std::move(callback)));
        changeStateToConnecting();
        break;

    case State::Connecting:
    case State::CancellingConnect:
    case State::CancellingTasks:    // 切断処理が終わってから実行される
    case State::Disconnecting:      // 切断処理が終わってから実行される
        m_ConnectCallbackHolderList.push(*new ConnectCallbackHolder(std::move(callback)));
        keepCurrentState();
        break;

    case State::Connected:
        keepCurrentState();
        AsyncResult<void> result;
        callback(result);
        break;
    }
}

void Gs2Session::connectCallback(optional<StringHolder>& projectToken, Gs2ClientException* pClientException)
{
    // 接続完了コールバック

    enterStateLock();

    if (pClientException == nullptr)
    {
        // ログイン処理がエラーなく応答された場合

        if (projectToken)
        {
            detail::IntrusiveList<ConnectCallbackHolder> connectCallbackHolderList(std::move(m_ConnectCallbackHolderList));

            if (m_DisconnectCallbackHolderList.isEmpty())
            {
                changeStateToConnected(std::move(*projectToken));
            }
            else
            {
                changeStateToDisconnecting();
            }

            AsyncResult<void> result;
            Gs2Session::triggerConnectCallback(connectCallbackHolderList, result);
        }
        else
        {
            // 応答からプロジェクトトークンが取得できなかった場合
            // ただし、ここには来ないように派生クラスを実装しなければならない

            detail::IntrusiveList<ConnectCallbackHolder> connectCallbackHolderList(std::move(m_ConnectCallbackHolderList));
            detail::IntrusiveList<DisconnectCallbackHolder> disconnectCallbackHolderList(std::move(m_DisconnectCallbackHolderList));

            changeStateToIdle();

            Gs2ClientException gs2ClientException;
            gs2ClientException.setType(Gs2ClientException::UnknownException);   // TODO

            AsyncResult<void> result(&gs2ClientException);
            Gs2Session::triggerConnectCallback(connectCallbackHolderList, result);
            Gs2Session::triggerDisconnectCallback(disconnectCallbackHolderList);
        }
    }
    else
    {
        // ログイン処理がエラーになった場合

        detail::IntrusiveList<ConnectCallbackHolder> connectCallbackHolderList(std::move(m_ConnectCallbackHolderList));
        detail::IntrusiveList<DisconnectCallbackHolder> disconnectCallbackHolderList(std::move(m_DisconnectCallbackHolderList));

        changeStateToIdle();

        AsyncResult<void> result(pClientException);
        Gs2Session::triggerConnectCallback(connectCallbackHolderList, result);
        Gs2Session::triggerDisconnectCallback(disconnectCallbackHolderList);
    }
}

void Gs2Session::disconnect(DisconnectCallbackType callback)
{
    enterStateLock();

    if (m_State == State::Idle)
    {
        // 即コールバック
        keepCurrentState();

        callback();
    }
    else
    {
        m_DisconnectCallbackHolderList.push(*new DisconnectCallbackHolder(std::move(callback)));

        switch(m_State)
        {
        case State::Connecting:
            changeStateToCancellingConnect();
            break;

        case State::Connected:
            if (m_Gs2SessionTaskList.isEmpty())
            {
                changeStateToDisconnecting();
            }
            else
            {
                changeStateToCancellingTasks();
            }
            break;

        case State::Idle:   // ここには来ない
        case State::CancellingConnect:
        case State::CancellingTasks:
        case State::Disconnecting:
            keepCurrentState();
            break;
        }
    }
}

void Gs2Session::disconnectCallback(bool isDisconnectInstant)
{
    if (!isDisconnectInstant)
    {
        enterStateLock();
    }

    detail::IntrusiveList<DisconnectCallbackHolder> disconnectCallbackHolderList(std::move(m_DisconnectCallbackHolderList));

    if (m_ConnectCallbackHolderList.isEmpty())
    {
        changeStateToIdle();
    }
    else
    {
        changeStateToConnecting();
    }

    Gs2Session::triggerDisconnectCallback(disconnectCallbackHolderList);
}

void Gs2Session::execute(detail::Gs2SessionTask &gs2SessionTask)
{
    enterStateLock();

    if (m_State == State::Connected)
    {
        gs2SessionTask.m_Gs2SessionTaskId = m_Gs2SessionIdTaskGenerator.issue();

        prepareImpl(gs2SessionTask);

        m_Gs2SessionTaskList.push(gs2SessionTask);

        keepCurrentState();

        gs2SessionTask.executeImpl();
    }
    else
    {
        keepCurrentState();

        Gs2ClientException gs2ClientException;
        gs2ClientException.setType(Gs2ClientException::UnknownException);   // TODO
        gs2SessionTask.callback("", &gs2ClientException);
    }
}

void Gs2Session::notifyComplete(detail::Gs2SessionTask& gs2SessionTask)
{
    enterStateLock();

    m_Gs2SessionTaskList.remove(gs2SessionTask);

    if (m_State == State::CancellingTasks && m_Gs2SessionTaskList.isEmpty())
    {
        changeStateToDisconnecting();
    }
    else
    {
        keepCurrentState();
    }
}

detail::Gs2SessionTask* Gs2Session::findGs2SessionTask(const detail::Gs2SessionTaskId& gs2SessionTaskId)
{
    std::lock_guard<std::mutex> lock(m_Mutex);

    for (auto p = m_Gs2SessionTaskList.getHead(); p != nullptr; p = p->getNext())
    {
        if (p->m_Gs2SessionTaskId == gs2SessionTaskId)
        {
            return p;
        }
    }

    return nullptr;
}

GS2_END_OF_NAMESPACE
