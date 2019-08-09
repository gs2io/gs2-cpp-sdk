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

#include <gs2/core/util/StringVariable.hpp>
#include "Gs2RestSession.hpp"
#include "../json/JsonWriter.hpp"
#include "../json/JsonParser.hpp"
#include "Gs2RestSessionTask.hpp"
#include "LoginResultModel.hpp"

GS2_START_OF_NAMESPACE

const char Gs2RestSession::EndpointHost[] = "https://{service}.{region}.gen2.gs2io.com";

Gs2RestSession::Gs2LoginTask::Gs2LoginTask(Gs2RestSession& gs2RestSession) :
    Gs2HttpTask(),
    m_Gs2RestSession(gs2RestSession)
{
    getHttpRequest().SetVerb("POST");
    detail::json::JsonWriter writer;
    writer.writeObjectStart();
    writer.writePropertyName("client_id");
    writer.writeCharArray(gs2RestSession.getGs2Credential().getClientId());
    writer.writePropertyName("client_secret");
    writer.writeCharArray(gs2RestSession.getGs2Credential().getClientSecret());
    writer.writeObjectEnd();
    auto body = writer.toString();
    getHttpRequest().SetContentAsString(body);

    detail::StringVariable url(Gs2RestSession::EndpointHost);
    url.replace("{service}", "identifier");
    url.replace("{region}", gs2RestSession.getRegion().getName());
    url += "/projectToken/login";
    getHttpRequest().SetURL(url.c_str());
    std::vector<std::string> headerEntries;
    getHttpRequest().SetHeader("Content-Type", "application/json");
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
        m_Gs2RestSession.openCallback(nullptr, &gs2ClientException, false);
    }
    else if (gs2RestResponse.getGs2ClientException())
    {
        // ログイン処理がエラーになった場合

        m_Gs2RestSession.openCallback(nullptr, &*gs2RestResponse.getGs2ClientException(), false);
    }
    else
    {
        // ログイン処理がエラーなく応答された場合

        detail::LoginResultModel resultModel;
        gs2RestResponse.exportTo(resultModel);

        if (resultModel.accessToken)
        {
            // 応答からプロジェクトトークンが取得できた場合

            m_Gs2RestSession.openCallback(&*resultModel.accessToken, nullptr, false);
        }
        else
        {
            // 応答からプロジェクトトークンが取得できなかった場合

            Gs2ClientException gs2ClientException;
            gs2ClientException.setType(Gs2ClientException::UnknownException);   // TODO
            m_Gs2RestSession.openCallback(nullptr, &gs2ClientException, false);
        }
    }

    delete this;
}

bool Gs2RestSession::openImpl()
{
    m_IsOpenCancelled = false;

    (new Gs2LoginTask(*this))->send();

    return false;
}

void Gs2RestSession::cancelOpenImpl()
{
    m_IsOpenCancelled = true;
}

bool Gs2RestSession::closeImpl()
{
    Gs2ClientException gs2ClientException;  // TODO
    closeCallback(gs2ClientException, true);

    return true;
}

GS2_END_OF_NAMESPACE
