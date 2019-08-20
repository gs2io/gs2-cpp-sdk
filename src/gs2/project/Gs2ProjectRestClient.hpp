/*
 * Copyright 2016 Game Server Services, Inc. or its affiliates. All Rights
 * Reserved.
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

#ifndef GS2_PROJECT_GS2PROJECTRESTCLIENT_HPP_
#define GS2_PROJECT_GS2PROJECTRESTCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2RestSessionTask.hpp>
#include <gs2/core/network/Gs2RestSession.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include "model/model.hpp"
#include "request/CreateAccountRequest.hpp"
#include "request/VerifyRequest.hpp"
#include "request/SignInRequest.hpp"
#include "request/IssueAccountTokenRequest.hpp"
#include "request/ForgetRequest.hpp"
#include "request/IssuePasswordRequest.hpp"
#include "request/UpdateAccountRequest.hpp"
#include "request/DeleteAccountRequest.hpp"
#include "request/DescribeProjectsRequest.hpp"
#include "request/CreateProjectRequest.hpp"
#include "request/GetProjectRequest.hpp"
#include "request/GetProjectTokenRequest.hpp"
#include "request/UpdateProjectRequest.hpp"
#include "request/DeleteProjectRequest.hpp"
#include "result/CreateAccountResult.hpp"
#include "result/VerifyResult.hpp"
#include "result/SignInResult.hpp"
#include "result/IssueAccountTokenResult.hpp"
#include "result/ForgetResult.hpp"
#include "result/IssuePasswordResult.hpp"
#include "result/UpdateAccountResult.hpp"
#include "result/DeleteAccountResult.hpp"
#include "result/DescribeProjectsResult.hpp"
#include "result/CreateProjectResult.hpp"
#include "result/GetProjectResult.hpp"
#include "result/GetProjectTokenResult.hpp"
#include "result/UpdateProjectResult.hpp"
#include "result/DeleteProjectResult.hpp"
#include <cstring>

namespace gs2 { namespace project {

typedef AsyncResult<CreateAccountResult> AsyncCreateAccountResult;
typedef AsyncResult<VerifyResult> AsyncVerifyResult;
typedef AsyncResult<SignInResult> AsyncSignInResult;
typedef AsyncResult<IssueAccountTokenResult> AsyncIssueAccountTokenResult;
typedef AsyncResult<ForgetResult> AsyncForgetResult;
typedef AsyncResult<IssuePasswordResult> AsyncIssuePasswordResult;
typedef AsyncResult<UpdateAccountResult> AsyncUpdateAccountResult;
typedef AsyncResult<void> AsyncDeleteAccountResult;
typedef AsyncResult<DescribeProjectsResult> AsyncDescribeProjectsResult;
typedef AsyncResult<CreateProjectResult> AsyncCreateProjectResult;
typedef AsyncResult<GetProjectResult> AsyncGetProjectResult;
typedef AsyncResult<GetProjectTokenResult> AsyncGetProjectTokenResult;
typedef AsyncResult<UpdateProjectResult> AsyncUpdateProjectResult;
typedef AsyncResult<DeleteProjectResult> AsyncDeleteProjectResult;

/**
 * GS2 Project API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2ProjectRestClient : public AbstractGs2ClientBase
{
private:
    static void write(detail::json::JsonWriter& writer, const Account& obj)
    {
        writer.writeObjectStart();
        if (obj.getAccountId())
        {
            writer.writePropertyName("accountId");
            writer.writeCharArray(*obj.getAccountId());
        }
        if (obj.getOwnerId())
        {
            writer.writePropertyName("ownerId");
            writer.writeCharArray(*obj.getOwnerId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*obj.getName());
        }
        if (obj.getEmail())
        {
            writer.writePropertyName("email");
            writer.writeCharArray(*obj.getEmail());
        }
        if (obj.getFullName())
        {
            writer.writePropertyName("fullName");
            writer.writeCharArray(*obj.getFullName());
        }
        if (obj.getCompanyName())
        {
            writer.writePropertyName("companyName");
            writer.writeCharArray(*obj.getCompanyName());
        }
        if (obj.getPassword())
        {
            writer.writePropertyName("password");
            writer.writeCharArray(*obj.getPassword());
        }
        if (obj.getStatus())
        {
            writer.writePropertyName("status");
            writer.writeCharArray(*obj.getStatus());
        }
        if (obj.getCreatedAt())
        {
            writer.writePropertyName("createdAt");
            writer.writeInt64(*obj.getCreatedAt());
        }
        if (obj.getUpdatedAt())
        {
            writer.writePropertyName("updatedAt");
            writer.writeInt64(*obj.getUpdatedAt());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const Project& obj)
    {
        writer.writeObjectStart();
        if (obj.getProjectId())
        {
            writer.writePropertyName("projectId");
            writer.writeCharArray(*obj.getProjectId());
        }
        if (obj.getAccountName())
        {
            writer.writePropertyName("accountName");
            writer.writeCharArray(*obj.getAccountName());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*obj.getName());
        }
        if (obj.getDescription())
        {
            writer.writePropertyName("description");
            writer.writeCharArray(*obj.getDescription());
        }
        if (obj.getCreatedAt())
        {
            writer.writePropertyName("createdAt");
            writer.writeInt64(*obj.getCreatedAt());
        }
        if (obj.getUpdatedAt())
        {
            writer.writePropertyName("updatedAt");
            writer.writeInt64(*obj.getUpdatedAt());
        }
        writer.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
     */
    explicit Gs2ProjectRestClient(Gs2RestSession& gs2RestSession) :
        AbstractGs2ClientBase(gs2RestSession)
    {
    }

	/**
	 * アカウントを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createAccount(std::function<void(AsyncCreateAccountResult&)> callback, CreateAccountRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<CreateAccountResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "project");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/account";
        httpRequest.SetURL(url.c_str());
        detail::json::JsonWriter writer;

        writer.writeObjectStart();
        if (request.getContextStack())
        {
            writer.writePropertyName("contextStack");
            writer.writeCharArray(*request.getContextStack());
        }
        if (request.getEmail())
        {
            writer.writePropertyName("email");
            writer.writeCharArray(*request.getEmail());
        }
        if (request.getFullName())
        {
            writer.writePropertyName("fullName");
            writer.writeCharArray(*request.getFullName());
        }
        if (request.getCompanyName())
        {
            writer.writePropertyName("companyName");
            writer.writeCharArray(*request.getCompanyName());
        }
        if (request.getPassword())
        {
            writer.writePropertyName("password");
            writer.writeCharArray(*request.getPassword());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");

        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * GS2アカウントを有効化します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void verify(std::function<void(AsyncVerifyResult&)> callback, VerifyRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<VerifyResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "project");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/account/verify";
        httpRequest.SetURL(url.c_str());
        detail::json::JsonWriter writer;

        writer.writeObjectStart();
        if (request.getContextStack())
        {
            writer.writePropertyName("contextStack");
            writer.writeCharArray(*request.getContextStack());
        }
        if (request.getVerifyToken())
        {
            writer.writePropertyName("verifyToken");
            writer.writeCharArray(*request.getVerifyToken());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");

        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * サインインします<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void signIn(std::function<void(AsyncSignInResult&)> callback, SignInRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<SignInResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "project");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/account/signIn";
        httpRequest.SetURL(url.c_str());
        detail::json::JsonWriter writer;

        writer.writeObjectStart();
        if (request.getContextStack())
        {
            writer.writePropertyName("contextStack");
            writer.writeCharArray(*request.getContextStack());
        }
        if (request.getEmail())
        {
            writer.writePropertyName("email");
            writer.writeCharArray(*request.getEmail());
        }
        if (request.getPassword())
        {
            writer.writePropertyName("password");
            writer.writeCharArray(*request.getPassword());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");

        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * 指定したアカウント名のアカウントトークンを発行<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void issueAccountToken(std::function<void(AsyncIssueAccountTokenResult&)> callback, IssueAccountTokenRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<IssueAccountTokenResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "project");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/account/accountToken";
        httpRequest.SetURL(url.c_str());
        detail::json::JsonWriter writer;

        writer.writeObjectStart();
        if (request.getContextStack())
        {
            writer.writePropertyName("contextStack");
            writer.writeCharArray(*request.getContextStack());
        }
        if (request.getAccountName())
        {
            writer.writePropertyName("accountName");
            writer.writeCharArray(*request.getAccountName());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");

        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * パスワード再発行トークンを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void forget(std::function<void(AsyncForgetResult&)> callback, ForgetRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<ForgetResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "project");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/account/forget";
        httpRequest.SetURL(url.c_str());
        detail::json::JsonWriter writer;

        writer.writeObjectStart();
        if (request.getContextStack())
        {
            writer.writePropertyName("contextStack");
            writer.writeCharArray(*request.getContextStack());
        }
        if (request.getEmail())
        {
            writer.writePropertyName("email");
            writer.writeCharArray(*request.getEmail());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");

        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * パスワードを再発行<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void issuePassword(std::function<void(AsyncIssuePasswordResult&)> callback, IssuePasswordRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<IssuePasswordResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "project");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/account/password/issue";
        httpRequest.SetURL(url.c_str());
        detail::json::JsonWriter writer;

        writer.writeObjectStart();
        if (request.getContextStack())
        {
            writer.writePropertyName("contextStack");
            writer.writeCharArray(*request.getContextStack());
        }
        if (request.getIssuePasswordToken())
        {
            writer.writePropertyName("issuePasswordToken");
            writer.writeCharArray(*request.getIssuePasswordToken());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");

        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * GS2アカウントを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateAccount(std::function<void(AsyncUpdateAccountResult&)> callback, UpdateAccountRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<UpdateAccountResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("PUT");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "project");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/account";
        httpRequest.SetURL(url.c_str());
        detail::json::JsonWriter writer;

        writer.writeObjectStart();
        if (request.getContextStack())
        {
            writer.writePropertyName("contextStack");
            writer.writeCharArray(*request.getContextStack());
        }
        if (request.getEmail())
        {
            writer.writePropertyName("email");
            writer.writeCharArray(*request.getEmail());
        }
        if (request.getFullName())
        {
            writer.writePropertyName("fullName");
            writer.writeCharArray(*request.getFullName());
        }
        if (request.getCompanyName())
        {
            writer.writePropertyName("companyName");
            writer.writeCharArray(*request.getCompanyName());
        }
        if (request.getPassword())
        {
            writer.writePropertyName("password");
            writer.writeCharArray(*request.getPassword());
        }
        if (request.getAccountToken())
        {
            writer.writePropertyName("accountToken");
            writer.writeCharArray(*request.getAccountToken());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");

        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * GS2アカウントを削除します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteAccount(std::function<void(AsyncDeleteAccountResult&)> callback, DeleteAccountRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<void>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("DELETE");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "project");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/account";

        Char joint[] = { '?', '\0' };
        if (request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        httpRequest.SetURL(url.c_str());
        {
            TArray<uint8> content(reinterpret_cast<const uint8*>("[]"), sizeof("[]") - 1);
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");

        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * プロジェクトの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeProjects(std::function<void(AsyncDescribeProjectsResult&)> callback, DescribeProjectsRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeProjectsResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "project");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/account/me/project";

        Char joint[] = { '?', '\0' };
        if (request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        if (request.getAccountToken())
        {
            url += joint;
            url += "accountToken=";
            url += detail::StringVariable(*request.getAccountToken(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        if (request.getPageToken())
        {
            url += joint;
            url += "pageToken=";
            url += detail::StringVariable(*request.getPageToken(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        if (request.getLimit())
        {
            url += joint;
            url += "limit=";
            url += detail::StringVariable(*request.getLimit()).c_str();
            joint[0] = '&';
        }
        httpRequest.SetURL(url.c_str());

        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * プロジェクトを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createProject(std::function<void(AsyncCreateProjectResult&)> callback, CreateProjectRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<CreateProjectResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "project");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/account/me/project";
        httpRequest.SetURL(url.c_str());
        detail::json::JsonWriter writer;

        writer.writeObjectStart();
        if (request.getContextStack())
        {
            writer.writePropertyName("contextStack");
            writer.writeCharArray(*request.getContextStack());
        }
        if (request.getAccountToken())
        {
            writer.writePropertyName("accountToken");
            writer.writeCharArray(*request.getAccountToken());
        }
        if (request.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*request.getName());
        }
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.writeCharArray(*request.getDescription());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");

        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * プロジェクトを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getProject(std::function<void(AsyncGetProjectResult&)> callback, GetProjectRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetProjectResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "project");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/account/me/project/{projectName}";
        {
            auto& value = request.getProjectName();
            url.replace("{projectName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        if (request.getAccountToken())
        {
            url += joint;
            url += "accountToken=";
            url += detail::StringVariable(*request.getAccountToken(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        httpRequest.SetURL(url.c_str());

        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * プロジェクトトークンを発行します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getProjectToken(std::function<void(AsyncGetProjectTokenResult&)> callback, GetProjectTokenRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetProjectTokenResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "project");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/project/{projectName}/projectToken";
        {
            auto& value = request.getProjectName();
            url.replace("{projectName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        detail::json::JsonWriter writer;

        writer.writeObjectStart();
        if (request.getContextStack())
        {
            writer.writePropertyName("contextStack");
            writer.writeCharArray(*request.getContextStack());
        }
        if (request.getAccountToken())
        {
            writer.writePropertyName("accountToken");
            writer.writeCharArray(*request.getAccountToken());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");

        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * プロジェクトを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateProject(std::function<void(AsyncUpdateProjectResult&)> callback, UpdateProjectRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<UpdateProjectResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("PUT");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "project");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/account/me/project/{projectName}";
        {
            auto& value = request.getProjectName();
            url.replace("{projectName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        detail::json::JsonWriter writer;

        writer.writeObjectStart();
        if (request.getContextStack())
        {
            writer.writePropertyName("contextStack");
            writer.writeCharArray(*request.getContextStack());
        }
        if (request.getAccountToken())
        {
            writer.writePropertyName("accountToken");
            writer.writeCharArray(*request.getAccountToken());
        }
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.writeCharArray(*request.getDescription());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");

        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * プロジェクトを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteProject(std::function<void(AsyncDeleteProjectResult&)> callback, DeleteProjectRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DeleteProjectResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("DELETE");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "project");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/account/me/project/{projectName}";
        {
            auto& value = request.getProjectName();
            url.replace("{projectName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        if (request.getAccountToken())
        {
            url += joint;
            url += "accountToken=";
            url += detail::StringVariable(*request.getAccountToken(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        httpRequest.SetURL(url.c_str());
        {
            TArray<uint8> content(reinterpret_cast<const uint8*>("[]"), sizeof("[]") - 1);
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");

        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

protected:
    Gs2RestSession& getGs2RestSession()
    {
        return static_cast<Gs2RestSession&>(getGs2Session());
    }
};

} }

#endif //GS2_PROJECT_GS2PROJECTRESTCLIENT_HPP_