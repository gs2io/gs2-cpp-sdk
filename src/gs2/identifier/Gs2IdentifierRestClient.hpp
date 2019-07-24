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

#ifndef GS2_IDENTIFIER_GS2IDENTIFIERRESTCLIENT_HPP_
#define GS2_IDENTIFIER_GS2IDENTIFIERRESTCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2RestSessionTask.hpp>
#include <gs2/core/network/Gs2RestSession.hpp>
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "model/model.hpp"
#include "request/DescribeUsersRequest.hpp"
#include "request/CreateUserRequest.hpp"
#include "request/UpdateUserRequest.hpp"
#include "request/GetUserRequest.hpp"
#include "request/DeleteUserRequest.hpp"
#include "request/DescribeSecurityPoliciesRequest.hpp"
#include "request/DescribeCommonSecurityPoliciesRequest.hpp"
#include "request/CreateSecurityPolicyRequest.hpp"
#include "request/UpdateSecurityPolicyRequest.hpp"
#include "request/GetSecurityPolicyRequest.hpp"
#include "request/DeleteSecurityPolicyRequest.hpp"
#include "request/DescribeIdentifiersRequest.hpp"
#include "request/CreateIdentifierRequest.hpp"
#include "request/GetIdentifierRequest.hpp"
#include "request/DeleteIdentifierRequest.hpp"
#include "request/GetHasSecurityPolicyRequest.hpp"
#include "request/AttachSecurityPolicyRequest.hpp"
#include "request/DetachSecurityPolicyRequest.hpp"
#include "request/LoginRequest.hpp"
#include "result/DescribeUsersResult.hpp"
#include "result/CreateUserResult.hpp"
#include "result/UpdateUserResult.hpp"
#include "result/GetUserResult.hpp"
#include "result/DeleteUserResult.hpp"
#include "result/DescribeSecurityPoliciesResult.hpp"
#include "result/DescribeCommonSecurityPoliciesResult.hpp"
#include "result/CreateSecurityPolicyResult.hpp"
#include "result/UpdateSecurityPolicyResult.hpp"
#include "result/GetSecurityPolicyResult.hpp"
#include "result/DeleteSecurityPolicyResult.hpp"
#include "result/DescribeIdentifiersResult.hpp"
#include "result/CreateIdentifierResult.hpp"
#include "result/GetIdentifierResult.hpp"
#include "result/DeleteIdentifierResult.hpp"
#include "result/GetHasSecurityPolicyResult.hpp"
#include "result/AttachSecurityPolicyResult.hpp"
#include "result/DetachSecurityPolicyResult.hpp"
#include "result/LoginResult.hpp"
#include <cstring>

namespace gs2 { namespace identifier {

typedef AsyncResult<DescribeUsersResult> AsyncDescribeUsersResult;
typedef AsyncResult<CreateUserResult> AsyncCreateUserResult;
typedef AsyncResult<UpdateUserResult> AsyncUpdateUserResult;
typedef AsyncResult<GetUserResult> AsyncGetUserResult;
typedef AsyncResult<void> AsyncDeleteUserResult;
typedef AsyncResult<DescribeSecurityPoliciesResult> AsyncDescribeSecurityPoliciesResult;
typedef AsyncResult<DescribeCommonSecurityPoliciesResult> AsyncDescribeCommonSecurityPoliciesResult;
typedef AsyncResult<CreateSecurityPolicyResult> AsyncCreateSecurityPolicyResult;
typedef AsyncResult<UpdateSecurityPolicyResult> AsyncUpdateSecurityPolicyResult;
typedef AsyncResult<GetSecurityPolicyResult> AsyncGetSecurityPolicyResult;
typedef AsyncResult<void> AsyncDeleteSecurityPolicyResult;
typedef AsyncResult<DescribeIdentifiersResult> AsyncDescribeIdentifiersResult;
typedef AsyncResult<CreateIdentifierResult> AsyncCreateIdentifierResult;
typedef AsyncResult<GetIdentifierResult> AsyncGetIdentifierResult;
typedef AsyncResult<void> AsyncDeleteIdentifierResult;
typedef AsyncResult<GetHasSecurityPolicyResult> AsyncGetHasSecurityPolicyResult;
typedef AsyncResult<AttachSecurityPolicyResult> AsyncAttachSecurityPolicyResult;
typedef AsyncResult<DetachSecurityPolicyResult> AsyncDetachSecurityPolicyResult;
typedef AsyncResult<LoginResult> AsyncLoginResult;

/**
 * GS2 Identifier API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2IdentifierRestClient : public AbstractGs2ClientBase
{
private:
    static void write(detail::json::JsonWriter& writer, const User& obj)
    {
        writer.writeObjectStart();
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.writeCharArray(*obj.getUserId());
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

    static void write(detail::json::JsonWriter& writer, const SecurityPolicy& obj)
    {
        writer.writeObjectStart();
        if (obj.getSecurityPolicyId())
        {
            writer.writePropertyName("securityPolicyId");
            writer.writeCharArray(*obj.getSecurityPolicyId());
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
        if (obj.getDescription())
        {
            writer.writePropertyName("description");
            writer.writeCharArray(*obj.getDescription());
        }
        if (obj.getPolicy())
        {
            writer.writePropertyName("policy");
            writer.writeCharArray(*obj.getPolicy());
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

    static void write(detail::json::JsonWriter& writer, const Identifier& obj)
    {
        writer.writeObjectStart();
        if (obj.getOwnerId())
        {
            writer.writePropertyName("ownerId");
            writer.writeCharArray(*obj.getOwnerId());
        }
        if (obj.getClientId())
        {
            writer.writePropertyName("clientId");
            writer.writeCharArray(*obj.getClientId());
        }
        if (obj.getUserName())
        {
            writer.writePropertyName("userName");
            writer.writeCharArray(*obj.getUserName());
        }
        if (obj.getClientSecret())
        {
            writer.writePropertyName("clientSecret");
            writer.writeCharArray(*obj.getClientSecret());
        }
        if (obj.getCreatedAt())
        {
            writer.writePropertyName("createdAt");
            writer.writeInt64(*obj.getCreatedAt());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const AttachSecurityPolicy& obj)
    {
        writer.writeObjectStart();
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.writeCharArray(*obj.getUserId());
        }
        if (obj.getSecurityPolicyIds())
        {
            writer.writePropertyName("securityPolicyIds");
            writer.writeArrayStart();
            auto& list = *obj.getSecurityPolicyIds();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                writer.writeCharArray(list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getAttachedAt())
        {
            writer.writePropertyName("attachedAt");
            writer.writeInt64(*obj.getAttachedAt());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const ProjectToken& obj)
    {
        writer.writeObjectStart();
        if (obj.getToken())
        {
            writer.writePropertyName("token");
            writer.writeCharArray(*obj.getToken());
        }
        writer.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
     */
    explicit Gs2IdentifierRestClient(Gs2RestSession& gs2RestSession) :
        AbstractGs2ClientBase(gs2RestSession)
    {
    }

	/**
	 * ユーザの一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeUsers(std::function<void(AsyncDescribeUsersResult&)> callback, DescribeUsersRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeUsersResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "identifier");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/user";

        Char joint[] = { '?', '\0' };
        if (request.getPageToken()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getPageToken(), sizeof(urlSafeValue));
            url += joint;
            url += "pageToken=";
            url += urlSafeValue;
            joint[0] = '&';
        }
        if (request.getLimit()) {
            Char urlSafeValue[32];
            Int64 value = *request.getLimit();
            std::sprintf(urlSafeValue, "%lld", value);
            url += joint;
            url += "limit=";
            url += urlSafeValue;
            joint[0] = '&';
        }
        httpRequest.SetURL(url.c_str());

        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ユーザを新規作成します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createUser(std::function<void(AsyncCreateUserResult&)> callback, CreateUserRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<CreateUserResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "identifier");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/user";
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
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

        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ユーザを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateUser(std::function<void(AsyncUpdateUserResult&)> callback, UpdateUserRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<UpdateUserResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("PUT");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "identifier");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/user/{userName}";
        {
            auto& value = request.getUserName();
            url.replace("{userName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
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

        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ユーザを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getUser(std::function<void(AsyncGetUserResult&)> callback, GetUserRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetUserResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "identifier");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/user/{userName}";
        {
            auto& value = request.getUserName();
            url.replace("{userName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());

        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ユーザを削除します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteUser(std::function<void(AsyncDeleteUserResult&)> callback, DeleteUserRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<void>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("DELETE");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "identifier");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/user/{userName}";
        {
            auto& value = request.getUserName();
            url.replace("{userName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());

        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * セキュリティポリシーの一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeSecurityPolicies(std::function<void(AsyncDescribeSecurityPoliciesResult&)> callback, DescribeSecurityPoliciesRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeSecurityPoliciesResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "identifier");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/securityPolicy";

        Char joint[] = { '?', '\0' };
        if (request.getPageToken()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getPageToken(), sizeof(urlSafeValue));
            url += joint;
            url += "pageToken=";
            url += urlSafeValue;
            joint[0] = '&';
        }
        if (request.getLimit()) {
            Char urlSafeValue[32];
            Int64 value = *request.getLimit();
            std::sprintf(urlSafeValue, "%lld", value);
            url += joint;
            url += "limit=";
            url += urlSafeValue;
            joint[0] = '&';
        }
        httpRequest.SetURL(url.c_str());

        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * オーナーIDを指定してセキュリティポリシーの一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCommonSecurityPolicies(std::function<void(AsyncDescribeCommonSecurityPoliciesResult&)> callback, DescribeCommonSecurityPoliciesRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeCommonSecurityPoliciesResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "identifier");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/securityPolicy/common";

        Char joint[] = { '?', '\0' };
        if (request.getPageToken()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getPageToken(), sizeof(urlSafeValue));
            url += joint;
            url += "pageToken=";
            url += urlSafeValue;
            joint[0] = '&';
        }
        if (request.getLimit()) {
            Char urlSafeValue[32];
            Int64 value = *request.getLimit();
            std::sprintf(urlSafeValue, "%lld", value);
            url += joint;
            url += "limit=";
            url += urlSafeValue;
            joint[0] = '&';
        }
        httpRequest.SetURL(url.c_str());

        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * セキュリティポリシーを新規作成します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createSecurityPolicy(std::function<void(AsyncCreateSecurityPolicyResult&)> callback, CreateSecurityPolicyRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<CreateSecurityPolicyResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "identifier");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/securityPolicy";
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
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
        if (request.getPolicy())
        {
            writer.writePropertyName("policy");
            writer.writeCharArray(*request.getPolicy());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");

        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * セキュリティポリシーを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateSecurityPolicy(std::function<void(AsyncUpdateSecurityPolicyResult&)> callback, UpdateSecurityPolicyRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<UpdateSecurityPolicyResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("PUT");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "identifier");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/securityPolicy/{securityPolicyName}";
        {
            auto& value = request.getSecurityPolicyName();
            url.replace("{securityPolicyName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.writeCharArray(*request.getDescription());
        }
        if (request.getPolicy())
        {
            writer.writePropertyName("policy");
            writer.writeCharArray(*request.getPolicy());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");

        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * セキュリティポリシーを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getSecurityPolicy(std::function<void(AsyncGetSecurityPolicyResult&)> callback, GetSecurityPolicyRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetSecurityPolicyResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "identifier");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/securityPolicy/{securityPolicyName}";
        {
            auto& value = request.getSecurityPolicyName();
            url.replace("{securityPolicyName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());

        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * セキュリティポリシーを削除します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteSecurityPolicy(std::function<void(AsyncDeleteSecurityPolicyResult&)> callback, DeleteSecurityPolicyRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<void>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("DELETE");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "identifier");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/securityPolicy/{securityPolicyName}";
        {
            auto& value = request.getSecurityPolicyName();
            url.replace("{securityPolicyName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());

        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * クレデンシャルの一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeIdentifiers(std::function<void(AsyncDescribeIdentifiersResult&)> callback, DescribeIdentifiersRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeIdentifiersResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "identifier");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/user/{userName}/identifier";
        {
            auto& value = request.getUserName();
            url.replace("{userName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (request.getPageToken()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getPageToken(), sizeof(urlSafeValue));
            url += joint;
            url += "pageToken=";
            url += urlSafeValue;
            joint[0] = '&';
        }
        if (request.getLimit()) {
            Char urlSafeValue[32];
            Int64 value = *request.getLimit();
            std::sprintf(urlSafeValue, "%lld", value);
            url += joint;
            url += "limit=";
            url += urlSafeValue;
            joint[0] = '&';
        }
        httpRequest.SetURL(url.c_str());

        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * クレデンシャルを新規作成します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createIdentifier(std::function<void(AsyncCreateIdentifierResult&)> callback, CreateIdentifierRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<CreateIdentifierResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "identifier");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/user/{userName}/identifier";
        {
            auto& value = request.getUserName();
            url.replace("{userName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");

        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * クレデンシャルを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getIdentifier(std::function<void(AsyncGetIdentifierResult&)> callback, GetIdentifierRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetIdentifierResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "identifier");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/user/{userName}/identifier/{clientId}";
        {
            auto& value = request.getUserName();
            url.replace("{userName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getClientId();
            url.replace("{clientId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());

        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * クレデンシャルを削除します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteIdentifier(std::function<void(AsyncDeleteIdentifierResult&)> callback, DeleteIdentifierRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<void>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("DELETE");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "identifier");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/user/{userName}/identifier/{clientId}";
        {
            auto& value = request.getUserName();
            url.replace("{userName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getClientId();
            url.replace("{clientId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());

        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * 割り当てられたセキュリティポリシーの一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getHasSecurityPolicy(std::function<void(AsyncGetHasSecurityPolicyResult&)> callback, GetHasSecurityPolicyRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetHasSecurityPolicyResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "identifier");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/user/{userName}/securityPolicy";
        {
            auto& value = request.getUserName();
            url.replace("{userName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());

        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * 割り当てられたセキュリティポリシーを新しくユーザーに割り当てます<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void attachSecurityPolicy(std::function<void(AsyncAttachSecurityPolicyResult&)> callback, AttachSecurityPolicyRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<AttachSecurityPolicyResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "identifier");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/user/{userName}/securityPolicy";
        {
            auto& value = request.getUserName();
            url.replace("{userName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getSecurityPolicyId())
        {
            writer.writePropertyName("securityPolicyId");
            writer.writeCharArray(*request.getSecurityPolicyId());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");

        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * 割り当てられたセキュリティポリシーをユーザーから外します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void detachSecurityPolicy(std::function<void(AsyncDetachSecurityPolicyResult&)> callback, DetachSecurityPolicyRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DetachSecurityPolicyResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("DELETE");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "identifier");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/user/{userName}/securityPolicy/{securityPolicyId}";
        {
            auto& value = request.getUserName();
            url.replace("{userName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getSecurityPolicyId();
            url.replace("{securityPolicyId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());

        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * プロジェクトトークン を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void login(std::function<void(AsyncLoginResult&)> callback, LoginRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<LoginResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "identifier");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/projectToken/login";
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getClientId())
        {
            writer.writePropertyName("clientId");
            writer.writeCharArray(*request.getClientId());
        }
        if (request.getClientSecret())
        {
            writer.writePropertyName("clientSecret");
            writer.writeCharArray(*request.getClientSecret());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");

        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
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

#endif //GS2_IDENTIFIER_GS2IDENTIFIERRESTCLIENT_HPP_