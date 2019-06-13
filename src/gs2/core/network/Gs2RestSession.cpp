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
#include "Gs2RestSessionTask.hpp"

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
    writer.writeCharArray(gs2RestSession.getGs2Credential().getClientId());
    writer.writePropertyName("client_secret");
    writer.writeCharArray(gs2RestSession.getGs2Credential().getClientSecret());
    writer.writeObjectEnd();
    auto body = writer.toString();
    auto bodySize = strlen(body);
    getHttpRequest().setRequestData(body, bodySize);

    getHttpRequest().setUrl("https://asia-northeast1-gs2-on-gcp.cloudfunctions.net/identifier-handler?handler=gs2_identifier%2Fhandler%2FProjectTokenFunctionHandler.login");   // TODO
    std::vector<std::string> headerEntries;
    headerEntries.emplace_back("Content-Type: application/json");
    getHttpRequest().setHeaders(headerEntries);
}

void Gs2RestSession::Gs2LoginTask::callback(const Char responseBody[], Gs2ClientException* pClientException)
{
    // 接続完了コールバック

    if (pClientException == nullptr)
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

            m_Gs2RestSession.connectCallback(resultModel.accessToken, pClientException);
        }
        else
        {
            // 応答からプロジェクトトークンが取得できなかった場合

            Gs2ClientException gs2ClientException;
            gs2ClientException.setType(Gs2ClientException::UnknownException);   // TODO
            m_Gs2RestSession.connectCallback(resultModel.accessToken, &gs2ClientException);
        }
    }
    else
    {
        // ログイン処理がエラーになった場合

        optional<StringHolder> projectToken;
        m_Gs2RestSession.connectCallback(projectToken, pClientException);
    }

    delete this;
}

void Gs2RestSession::connectImpl()
{
    (new Gs2LoginTask(*this))->send();
}

bool Gs2RestSession::disconnectImpl()
{
    disconnectCallback(true);

    return true;
}

void Gs2RestSession::prepareImpl(detail::Gs2SessionTask& gs2SessionTask)
{
    auto& gs2StandardHttpTaskBase = static_cast<detail::Gs2RestSessionTaskBase&>(gs2SessionTask);

    auto headers = gs2StandardHttpTaskBase.getGs2HttpTask().getHttpRequest().getHeaders();

    detail::HttpTask::addHeaderEntry(headers, "X-GS2-CLIENT-ID", getGs2Credential().getClientId());
    detail::HttpTask::addHeaderEntry(headers, "X-GS2-PROJECT-TOKEN", *getProjectToken());

    gs2StandardHttpTaskBase.getGs2HttpTask().getHttpRequest().setHeaders(headers);
}

GS2_END_OF_NAMESPACE
