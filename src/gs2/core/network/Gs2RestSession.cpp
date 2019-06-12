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

#include "Gs2RestSession.hpp"
#include "../json/JsonWriter.hpp"
#include "../json/JsonParser.hpp"
#include "Gs2StandardHttpTask.hpp"

GS2_START_OF_NAMESPACE

namespace {

struct LoginResultModel : public detail::json::IModel
{
    /** プロジェクトトークン */
    optional<StringHolder> accessToken;

    void set(const Char name[], const detail::json::JsonConstValue& jsonValue) GS2_OVERRIDE
    {
        if (std::strcmp(name, "access_token") == 0) {
            if (jsonValue.IsString())
            {
                this->accessToken.emplace(jsonValue.GetString());
            }
        }
    }
};

}

Gs2RestSession::Gs2LoginTask::Gs2LoginTask(Gs2RestSession& gs2RestSession) :
    Gs2HttpTask(),
    m_Gs2RestSession(gs2RestSession)
{
    getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
    auto& writer = detail::json::JsonWriter::getInstance();
    writer.reset();
    writer.writeObjectStart();
    writer.writePropertyName("client_id");
    writer.writeCharArray(gs2RestSession.m_Gs2Credential.getClientId());
    writer.writePropertyName("client_secret");
    writer.writeCharArray(gs2RestSession.m_Gs2Credential.getClientSecret());
    writer.writeObjectEnd();
    auto body = writer.toString();
    auto bodySize = strlen(body);
    getHttpRequest().setRequestData(body, bodySize);

    getHttpRequest().setUrl("https://asia-northeast1-gs2-on-gcp.cloudfunctions.net/identifier-handler?handler=gs2_identifier%2Fhandler%2FProjectTokenFunctionHandler.login");   // TODO
    std::vector<std::string> headerEntries;
    headerEntries.emplace_back("Content-Type: application/json");
    getHttpRequest().setHeaders(headerEntries);
}

Gs2RestSession::~Gs2RestSession()
{
    // disconnect() が複数のコールバックを叩き終わらないうちに破棄されないように、1回ロックへ入る
    std::lock_guard<std::mutex> lock(m_Mutex);
}

void Gs2RestSession::triggerConnectCallback(detail::IntrusiveList<ConnectCallbackHolder>& connectCallbackHolderList, AsyncResult<void>& result)
{
    while (auto* pConnectCallbackHolder = connectCallbackHolderList.pop())
    {
        pConnectCallbackHolder->callback()(result);
        delete pConnectCallbackHolder;
    }
}

void Gs2RestSession::triggerDisconnectCallback(detail::IntrusiveList<DisconnectCallbackHolder>& disconnectCallbackHolderList)
{
    while (auto* pDisconnectCallbackHolder = disconnectCallbackHolderList.pop())
    {
        pDisconnectCallbackHolder->callback()();
        delete pDisconnectCallbackHolder;
    }
}

void Gs2RestSession::connect(ConnectCallbackType callback)
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
            (new Gs2LoginTask(*this))->send();
        }

        // isConnecting() はコールバックホルダリストが空かどうかで判定するので、追加はあとから行う
        m_ConnectCallbackHolderList.push(*new ConnectCallbackHolder(std::move(callback)));

        m_Mutex.unlock();
    }
}

void Gs2RestSession::connectCallback(const Char responseBody[], Gs2ClientException* pClientException)
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
        Gs2RestSession::triggerConnectCallback(connectCallbackHolderList, result);

        Gs2RestSession::triggerDisconnectCallback(disconnectCallbackHolderList);
    }
    else if (pClientException == nullptr)
    {
        // ログイン処理がエラーなく応答された場合

        LoginResultModel resultModel;
        if (responseBody != nullptr)
        {
            detail::json::JsonParser::parse(&resultModel, responseBody);
        }

        if (resultModel.accessToken)
        {
            // 応答からプロジェクトトークンが取得できた場合

            m_ProjectToken = std::move(*resultModel.accessToken);
            detail::IntrusiveList<ConnectCallbackHolder> connectCallbackHolderList(std::move(m_ConnectCallbackHolderList));

            m_Mutex.unlock();

            AsyncResult<void> result;
            Gs2RestSession::triggerConnectCallback(connectCallbackHolderList, result);
        }
        else
        {
            // 応答からプロジェクトトークンが取得できなかった場合

            detail::IntrusiveList<ConnectCallbackHolder> connectCallbackHolderList(std::move(m_ConnectCallbackHolderList));

            m_Mutex.unlock();

            Gs2ClientException gs2ClientException;
            gs2ClientException.setType(Gs2ClientException::UnknownException);   // TODO

            AsyncResult<void> result(&gs2ClientException);
            Gs2RestSession::triggerConnectCallback(connectCallbackHolderList, result);
        }
    }
    else
    {
        // ログイン処理がエラーになった場合

        detail::IntrusiveList<ConnectCallbackHolder> connectCallbackHolderList(std::move(m_ConnectCallbackHolderList));

        m_Mutex.unlock();

        AsyncResult<void> result(pClientException);
        Gs2RestSession::triggerConnectCallback(connectCallbackHolderList, result);
    }
}

void Gs2RestSession::disconnect(DisconnectCallbackType callback)
{
    m_Mutex.lock();

    if (isConnecting() || isUsed())
    {
        // 接続処理中、もしくは処理中のタスクがあるなら、コールバックは接続処理完了後に返す
        m_DisconnectCallbackHolderList.push(*new DisconnectCallbackHolder(std::move(callback)));

        m_Mutex.unlock();
    }
    else
    {
        // 接続処理中、もしくは処理中でなければ、即座にコールバックを返す
        m_ProjectToken.reset();

        m_Mutex.unlock();

        callback();
    }
}

void Gs2RestSession::authorizeAndExecute(detail::Gs2SessionTask& gs2SessionTask)
{
    // TODO: [TORIAEZU]
    detail::Gs2StandardHttpTaskBase& gs2StandardHttpTaskBase = *static_cast<detail::Gs2StandardHttpTaskBase*>(&gs2SessionTask);

    m_Mutex.lock();

    if (isAvailable() && !isDisconnecting())
    {
        // connect が完了していて、かつ disconnect が呼ばれていなければタスクを実行

        auto headers = gs2StandardHttpTaskBase.getGs2HttpTask().getHttpRequest().getHeaders();

        detail::HttpTask::addHeaderEntry(headers, "X-GS2-CLIENT-ID", m_Gs2Credential.getClientId());
        detail::HttpTask::addHeaderEntry(headers, "X-GS2-PROJECT-TOKEN", *m_ProjectToken);

        gs2StandardHttpTaskBase.getGs2HttpTask().getHttpRequest().setHeaders(headers);

        m_Gs2StandardHttpTaskBaseList.push(gs2StandardHttpTaskBase);

        gs2StandardHttpTaskBase.execute();

        m_Mutex.unlock();
    }
    else
    {
        // 失敗を即コールバック

        m_Mutex.unlock();

        Gs2ClientException gs2ClientException;
        gs2ClientException.setType(Gs2ClientException::UnknownException);   // TODO
        gs2StandardHttpTaskBase.callback("", &gs2ClientException);
    }
}

void Gs2RestSession::notifyComplete(detail::Gs2SessionTask& gs2SessionTask)
{
    // TODO: [TORIAEZU]
    detail::Gs2StandardHttpTaskBase& gs2StandardHttpTaskBase = *static_cast<detail::Gs2StandardHttpTaskBase*>(&gs2SessionTask);

    m_Mutex.lock();

    m_Gs2StandardHttpTaskBaseList.remove(gs2StandardHttpTaskBase);

    if (isDisconnecting() && !isUsed())
    {
        // タスク終了を待機していた disconnect があれば実行してコールバック

        m_ProjectToken.reset();

        detail::IntrusiveList<DisconnectCallbackHolder> disconnectCallbackHolderList(std::move(m_DisconnectCallbackHolderList));

        m_Mutex.unlock();

        Gs2RestSession::triggerDisconnectCallback(disconnectCallbackHolderList);
    }
    else
    {
        m_Mutex.unlock();
    }
}

GS2_END_OF_NAMESPACE
