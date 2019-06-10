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

void Gs2RestSession::Gs2LoginTask::callbackGs2Response(const Char responseBody[], Gs2ClientException* pClientException)
{
    // 接続完了コールバック

    std::lock_guard<std::mutex> lock(m_Gs2RestSession.m_Mutex);

    if (m_Gs2RestSession.isDisconnecting())
    {
        // ログイン処理中に disconnect() が呼ばれた場合

        m_Gs2RestSession.m_ProjectToken.reset();

        // connect() はすべてキャンセルする
        Gs2ClientException gs2ClientException;
        gs2ClientException.setType(Gs2ClientException::UnknownException);   // TODO
        AsyncResult<void> result(&gs2ClientException);
        m_Gs2RestSession.triggerConnectCallback(result);

        m_Gs2RestSession.triggerDisconnectCallback();
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

            m_Gs2RestSession.m_ProjectToken = std::move(*resultModel.accessToken);

            AsyncResult<void> result;
            m_Gs2RestSession.triggerConnectCallback(result);
        }
        else
        {
            // 応答からプロジェクトトークンが取得できなかった場合

            Gs2ClientException gs2ClientException;
            gs2ClientException.setType(Gs2ClientException::UnknownException);   // TODO

            AsyncResult<void> result(&gs2ClientException);
            m_Gs2RestSession.triggerConnectCallback(result);
        }
    }
    else
    {
        // ログイン処理がエラーになった場合

        AsyncResult<void> result(pClientException);
        m_Gs2RestSession.triggerConnectCallback(result);
    }

    // Gs2LoginTask (HttpTask) はコールバック呼出後に自殺するのでポインタだけを無効化する
    m_Gs2RestSession.m_pGs2LoginTask = nullptr;
}

Gs2RestSession::~Gs2RestSession()
{
    // TODO: disconnect() して完了待ち
}

void Gs2RestSession::triggerConnectCallback(AsyncResult<void>& result)
{
    while (auto* pConnectCallbackHolder = m_ConnectCallbackHolderList.pop())
    {
        pConnectCallbackHolder->callback()(result);
        delete pConnectCallbackHolder;
    }
}

void Gs2RestSession::triggerDisconnectCallback()
{
    while (auto* pDisconnectCallbackHolder = m_DisconnectCallbackHolderList.pop())
    {
        pDisconnectCallbackHolder->callback()();
        delete pDisconnectCallbackHolder;
    }
}

void Gs2RestSession::connect(ConnectCallbackType callback)
{
    std::lock_guard<std::mutex> lock(m_Mutex);

    if (isAvailable())
    {
        AsyncResult<void> result;
        callback(result);
    }
    else
    {
        if (!isConnecting())
        {
            assert(m_pGs2LoginTask == nullptr);
            m_pGs2LoginTask = new Gs2LoginTask(*this);
            m_pGs2LoginTask->send();
        }

        // isConnecting() はコールバックホルダリストが空かどうかで判定するので、追加はあとから行う
        m_ConnectCallbackHolderList.push(*new ConnectCallbackHolder(std::move(callback)));
    }
}

void Gs2RestSession::disconnect(DisconnectCallbackType callback)
{
    std::lock_guard<std::mutex> lock(m_Mutex);

    if (isConnecting())
    {
        // 接続処理中なら、コールバックは接続処理完了後に返す
        m_DisconnectCallbackHolderList.push(*new DisconnectCallbackHolder(std::move(callback)));
    }
    else
    {
        // 接続処理中でなければ、即座にコールバックを返す
        m_ProjectToken.reset();
        callback();
    }
}

void Gs2RestSession::authorizeAndExecute(detail::Gs2StandardHttpTaskBase& gs2StandardHttpTaskBase)
{
    std::lock_guard<std::mutex> lock(m_Mutex);

    if (isAvailable())
    {
        auto headers = gs2StandardHttpTaskBase.getHttpRequest().getHeaders();

        detail::HttpTask::addHeaderEntry(headers, "X-GS2-CLIENT-ID", m_Gs2Credential.getClientId());
        detail::HttpTask::addHeaderEntry(headers, "X-GS2-PROJECT-TOKEN", *m_ProjectToken);

        gs2StandardHttpTaskBase.getHttpRequest().setHeaders(headers);

        // TODO: 実行中タスクに登録

        gs2StandardHttpTaskBase.send();
    }
    else
    {
        // 失敗を即コールバック

        Gs2ClientException gs2ClientException;
        gs2ClientException.setType(Gs2ClientException::UnknownException);   // TODO
        gs2StandardHttpTaskBase.callbackGs2Response("", &gs2ClientException);
    }
}

GS2_END_OF_NAMESPACE
