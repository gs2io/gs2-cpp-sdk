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
    std::lock_guard<std::mutex> lock(m_Gs2RestSession.m_Mutex);

    if (auto* pDisconnectCallbackHolder = m_Gs2RestSession.m_DisconnectCallbackHolderList.pop())
    {
        // ログイン処理中に disconnect() が呼ばれた場合

        m_Gs2RestSession.m_ProjectToken.reset();

        // connect() はすべてキャンセルする
        Gs2ClientException gs2ClientException;
        gs2ClientException.setType(Gs2ClientException::UnknownException);   // TODO
        AsyncResult<void> result(&gs2ClientException);
        while (auto* pConnectCallbackHolder = m_Gs2RestSession.m_ConnectCallbackHolderList.pop())
        {
            pConnectCallbackHolder->callback()(result);
            delete pConnectCallbackHolder;
        }

        do
        {
            pDisconnectCallbackHolder->callback()();
            delete pDisconnectCallbackHolder;
        }
        while ((pDisconnectCallbackHolder = m_Gs2RestSession.m_DisconnectCallbackHolderList.pop()) != nullptr);
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
            while (auto* pConnectCallbackHolder = m_Gs2RestSession.m_ConnectCallbackHolderList.pop())
            {
                pConnectCallbackHolder->callback()(result);
                delete pConnectCallbackHolder;
            }
        }
        else
        {
            // 応答からプロジェクトトークンが取得できなかった場合

            Gs2ClientException gs2ClientException;
            gs2ClientException.setType(Gs2ClientException::UnknownException);   // TODO

            AsyncResult<void> result(&gs2ClientException);
            while (auto* pConnectCallbackHolder = m_Gs2RestSession.m_ConnectCallbackHolderList.pop())
            {
                pConnectCallbackHolder->callback()(result);
                delete pConnectCallbackHolder;
            }
        }
    }
    else
    {
        // ログイン処理がエラーになった場合

        AsyncResult<void> result(pClientException);
        while (auto* pConnectCallbackHolder = m_Gs2RestSession.m_ConnectCallbackHolderList.pop())
        {
            pConnectCallbackHolder->callback()(result);
            delete pConnectCallbackHolder;
        }
    }

    // Gs2LoginTask (HttpTask) はコールバック呼出後に自殺するのでポインタだけを無効化する
    m_Gs2RestSession.m_pGs2LoginTask = nullptr;
}

Gs2RestSession::~Gs2RestSession()
{
    // TODO: disconnect() して完了待ち
}

void Gs2RestSession::connect(ConnectCallbackType callback)
{
    std::lock_guard<std::mutex> lock(m_Mutex);

    if (m_ProjectToken)
    {
        AsyncResult<void> result;
        callback(result);
    }
    else
    {
        m_ConnectCallbackHolderList.push(*new ConnectCallbackHolder(std::move(callback)));

        if (m_pGs2LoginTask == nullptr)
        {
            m_pGs2LoginTask = new Gs2LoginTask(*this);
            m_pGs2LoginTask->send();
        }
    }
}

void Gs2RestSession::disconnect(DisconnectCallbackType callback)
{
    std::lock_guard<std::mutex> lock(m_Mutex);

    if (m_pGs2LoginTask == nullptr)
    {
        m_ProjectToken.reset();
        callback();
    }
    else
    {
        m_DisconnectCallbackHolderList.push(*new DisconnectCallbackHolder(std::move(callback)));
    }
}

GS2_END_OF_NAMESPACE
