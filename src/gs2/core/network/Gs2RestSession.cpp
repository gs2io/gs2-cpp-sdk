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
#include "Gs2RestSessionTask.hpp"
#include "Gs2RestResponse.hpp"
#include "../json/JsonWriter.hpp"
#include "../json/JsonParser.hpp"
#include "../util/StringVariable.hpp"
#include "LoginResultModel.hpp"

GS2_START_OF_NAMESPACE

const char* Gs2RestSession::EndpointHost = "https://{service}.{region}.gen2.gs2io.com";

Gs2RestSession::Gs2LoginTask::Gs2LoginTask(Gs2RestSession& gs2RestSession) :
    Gs2HttpTask(),
    m_Gs2RestSession(gs2RestSession)
{
    setVerb(Verb::Post);

    detail::json::JsonWriter jsonWriter;
    jsonWriter.writeObjectStart();
    jsonWriter.writePropertyName("client_id");
    jsonWriter.writeCharArray(gs2RestSession.getGs2Credential().getClientId());
    jsonWriter.writePropertyName("client_secret");
    jsonWriter.writeCharArray(gs2RestSession.getGs2Credential().getClientSecret());
    jsonWriter.writeObjectEnd();
    setBody(jsonWriter.toString());

    detail::StringVariable url(Gs2RestSession::EndpointHost);
    url.replace("{service}", "identifier");
    url.replace("{region}", gs2RestSession.getRegion().getName());
    url += "/projectToken/login";
    setUrl(url.c_str());

    addHeaderEntry("Content-Type", "application/json");
}

void Gs2RestSession::Gs2LoginTask::callback(detail::Gs2RestResponse& gs2RestResponse)
{
    // 接続完了コールバック

    if (m_Gs2RestSession.m_IsOpenCancelled)
    {
        // キャンセルされた場合

        optional<StringHolder> projectToken;
        Gs2ClientException gs2ClientException;
        gs2ClientException.setType(Gs2ClientException::UnknownException);   // TODO
        m_Gs2RestSession.openCallback(nullptr, &gs2ClientException);
    }
    else if (gs2RestResponse.getGs2ClientException())
    {
        // ログイン処理がエラーになった場合

        m_Gs2RestSession.openCallback(nullptr, &*gs2RestResponse.getGs2ClientException());
    }
    else
    {
        // ログイン処理がエラーなく応答された場合

        detail::LoginResultModel resultModel;
        gs2RestResponse.exportTo(resultModel);

        if (resultModel.accessToken)
        {
            // 応答からプロジェクトトークンが取得できた場合

            m_Gs2RestSession.openCallback(&*resultModel.accessToken, nullptr);
        }
        else
        {
            // 応答からプロジェクトトークンが取得できなかった場合

            Gs2ClientException gs2ClientException;
            gs2ClientException.setType(Gs2ClientException::UnknownException);   // TODO
            m_Gs2RestSession.openCallback(nullptr, &gs2ClientException);
        }
    }

    delete this;
}

void Gs2RestSession::openImpl()
{
    m_IsOpenCancelled = false;

    (new Gs2LoginTask(*this))->send();
}

void Gs2RestSession::cancelOpenImpl()
{
    m_IsOpenCancelled = true;
}

void Gs2RestSession::closeImpl()
{
    Gs2ClientException gs2ClientException;  // TODO
    closeCallback(gs2ClientException, true);
}

GS2_END_OF_NAMESPACE
