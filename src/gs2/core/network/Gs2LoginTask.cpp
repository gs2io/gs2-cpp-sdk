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

#include "Gs2LoginTask.hpp"
#include "../model/BasicGs2Credential.hpp"
#include "../json/JsonWriter.hpp"
#include "../json/JsonParser.hpp"

GS2_START_OF_NAMESPACE

namespace detail {

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

Gs2LoginTask::Gs2LoginTask(BasicGs2Credential& basicGs2Credential) :
    Gs2HttpTask(),
    m_BasicGs2Credential(basicGs2Credential),
    m_pGs2StandardHttpTaskHead(nullptr)
{
    getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
    auto& writer = detail::json::JsonWriter::getInstance();
    writer.reset();
    writer.writeObjectStart();
    writer.writePropertyName("client_id");
    writer.writeCharArray(basicGs2Credential.getClientId());
    writer.writePropertyName("client_secret");
    writer.writeCharArray(basicGs2Credential.getClientSecret());
    writer.writeObjectEnd();
    auto body = writer.toString();
    auto bodySize = strlen(body);
    getHttpRequest().setRequestData(body, bodySize);

    getHttpRequest().setUrl("https://asia-northeast1-gs2-on-gcp.cloudfunctions.net/identifier-handler?handler=gs2_identifier%2Fhandler%2FProjectTokenFunctionHandler.login");   // TODO
    std::vector<std::string> headerEntries;
    headerEntries.emplace_back("Content-Type: application/json");
    getHttpRequest().setHeaders(headerEntries);
}

Gs2LoginTask::~Gs2LoginTask()
{
    Gs2ClientException gs2ClientException;
    gs2ClientException.setType(Gs2ClientException::UnknownException);
    while (auto* pGs2StandardHttpTaskHead = popGs2HttpStandardHttpTask())
    {
        pGs2StandardHttpTaskHead->callbackGs2Response("", &gs2ClientException);
    }
}

void Gs2LoginTask::callbackGs2Response(const Char responseBody[], Gs2ClientException* pClientException)
{
    std::lock_guard<std::mutex> lock(m_BasicGs2Credential.m_Mutex);

    if (pClientException == nullptr)
    {
        LoginResultModel resultModel;
        if (responseBody != nullptr)
        {
            json::JsonParser::parse(&resultModel, responseBody);
        }

        if (resultModel.accessToken)
        {
            m_BasicGs2Credential.m_ProjectToken = std::move(*resultModel.accessToken);

            while (auto* pGs2StandardHttpTask = popGs2HttpStandardHttpTask())
            {
                m_BasicGs2Credential.authorizeAndExecuteImpl(*pGs2StandardHttpTask);
            }
        }
        else
        {
            Gs2ClientException gs2ClientException;
            gs2ClientException.setType(Gs2ClientException::UnknownException);
            while (auto* pGs2StandardHttpTaskHead = popGs2HttpStandardHttpTask())
            {
                pGs2StandardHttpTaskHead->callbackGs2Response("", &gs2ClientException);
            }
        }
    }
    else
    {
        while (auto* pGs2StandardHttpTaskHead = popGs2HttpStandardHttpTask())
        {
            pGs2StandardHttpTaskHead->callbackGs2Response("", pClientException);
        }
    }

    m_BasicGs2Credential.m_pGs2LoginTask = nullptr;
}

}

GS2_END_OF_NAMESPACE
