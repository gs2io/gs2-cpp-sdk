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

#ifndef GS2_IDENTIFIER_GS2IDENTIFIERCLIENT_HPP_
#define GS2_IDENTIFIER_GS2IDENTIFIERCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2StandardHttpTask.hpp>
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "model/model.hpp"
#include "request/DescribeUsersRequest.hpp"
#include "request/CreateUserRequest.hpp"
#include "request/UpdateUserRequest.hpp"
#include "request/GetUserStatusRequest.hpp"
#include "request/GetUserRequest.hpp"
#include "request/DeleteUserRequest.hpp"
#include "request/DescribeSecurityPoliciesRequest.hpp"
#include "request/DescribeCommonSecurityPoliciesRequest.hpp"
#include "request/CreateSecurityPolicyRequest.hpp"
#include "request/UpdateSecurityPolicyRequest.hpp"
#include "request/GetSecurityPolicyStatusRequest.hpp"
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
#include "result/GetUserStatusResult.hpp"
#include "result/GetUserResult.hpp"
#include "result/DeleteUserResult.hpp"
#include "result/DescribeSecurityPoliciesResult.hpp"
#include "result/DescribeCommonSecurityPoliciesResult.hpp"
#include "result/CreateSecurityPolicyResult.hpp"
#include "result/UpdateSecurityPolicyResult.hpp"
#include "result/GetSecurityPolicyStatusResult.hpp"
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
#include <network/HttpRequest.h>

namespace gs2 { namespace identifier {

typedef AsyncResult<DescribeUsersResult> AsyncDescribeUsersResult;
typedef AsyncResult<CreateUserResult> AsyncCreateUserResult;
typedef AsyncResult<UpdateUserResult> AsyncUpdateUserResult;
typedef AsyncResult<GetUserStatusResult> AsyncGetUserStatusResult;
typedef AsyncResult<GetUserResult> AsyncGetUserResult;
typedef AsyncResult<void> AsyncDeleteUserResult;
typedef AsyncResult<DescribeSecurityPoliciesResult> AsyncDescribeSecurityPoliciesResult;
typedef AsyncResult<DescribeCommonSecurityPoliciesResult> AsyncDescribeCommonSecurityPoliciesResult;
typedef AsyncResult<CreateSecurityPolicyResult> AsyncCreateSecurityPolicyResult;
typedef AsyncResult<UpdateSecurityPolicyResult> AsyncUpdateSecurityPolicyResult;
typedef AsyncResult<GetSecurityPolicyStatusResult> AsyncGetSecurityPolicyStatusResult;
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
class Gs2IdentifierClient : public AbstractGs2ClientBase
{
private:
    constexpr static const Char* ENDPOINT = "identifier";

    virtual const Char* getEndPoint() const
    {
        return ENDPOINT;
    }

private:
    void write(detail::json::JsonWriter& writer, const User& obj)
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
        if (obj.getCreateAt())
        {
            writer.writePropertyName("createAt");
            writer.writeInt64(*obj.getCreateAt());
        }
        if (obj.getUpdateAt())
        {
            writer.writePropertyName("updateAt");
            writer.writeInt64(*obj.getUpdateAt());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const SecurityPolicy& obj)
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
        if (obj.getCreateAt())
        {
            writer.writePropertyName("createAt");
            writer.writeInt64(*obj.getCreateAt());
        }
        if (obj.getUpdateAt())
        {
            writer.writePropertyName("updateAt");
            writer.writeInt64(*obj.getUpdateAt());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const Identifier& obj)
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
        if (obj.getCreateAt())
        {
            writer.writePropertyName("createAt");
            writer.writeInt64(*obj.getCreateAt());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const FullIdentifier& obj)
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
        if (obj.getCreateAt())
        {
            writer.writePropertyName("createAt");
            writer.writeInt64(*obj.getCreateAt());
        }
        if (obj.getClientSecret())
        {
            writer.writePropertyName("clientSecret");
            writer.writeCharArray(*obj.getClientSecret());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const AttachSecurityPolicy& obj)
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
        if (obj.getAttachAt())
        {
            writer.writePropertyName("attachAt");
            writer.writeInt64(*obj.getAttachAt());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const ProjectToken& obj)
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
     * @param credential 認証情報
     */
    Gs2IdentifierClient(IGs2Credential& credential) :
        AbstractGs2ClientBase(credential)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2IdentifierClient(IGs2Credential& credential, const Region& region) :
        AbstractGs2ClientBase(credential, region)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2IdentifierClient(IGs2Credential& credential, const Char region[]) :
        AbstractGs2ClientBase(credential, region)
    {
    }

	/**
	 * ユーザーの一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeUsers(std::function<void(AsyncDescribeUsersResult&)> callback, DescribeUsersRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DescribeUsersResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/identifier-handler?handler=gs2_identifier%2Fhandler%2FUserFunctionHandler.describeUsers");
        Char encodeBuffer[2048];
        if (request.getPageToken()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPageToken()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("pageToken={value}").replace("{value}", encodeBuffer);
        }
        if (request.getLimit()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLimit()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("limit={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ユーザーを新規作成します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createUser(std::function<void(AsyncCreateUserResult&)> callback, CreateUserRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<CreateUserResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/identifier-handler?handler=gs2_identifier%2Fhandler%2FUserFunctionHandler.createUser");
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
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ユーザーを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateUser(std::function<void(AsyncUpdateUserResult&)> callback, UpdateUserRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<UpdateUserResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/identifier-handler?handler=gs2_identifier%2Fhandler%2FUserFunctionHandler.updateUser");
        Char encodeBuffer[2048];
        if (request.getUserName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userName={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.writeCharArray(*request.getDescription());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ユーザーを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getUserStatus(std::function<void(AsyncGetUserStatusResult&)> callback, GetUserStatusRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetUserStatusResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/identifier-handler?handler=gs2_identifier%2Fhandler%2FUserFunctionHandler.getUserStatus");
        Char encodeBuffer[2048];
        if (request.getUserName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ユーザーを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getUser(std::function<void(AsyncGetUserResult&)> callback, GetUserRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetUserResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/identifier-handler?handler=gs2_identifier%2Fhandler%2FUserFunctionHandler.getUser");
        Char encodeBuffer[2048];
        if (request.getUserName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ユーザーを削除します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteUser(std::function<void(AsyncDeleteUserResult&)> callback, DeleteUserRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<void>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/identifier-handler?handler=gs2_identifier%2Fhandler%2FUserFunctionHandler.deleteUser");
        Char encodeBuffer[2048];
        if (request.getUserName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * セキュリティポリシーの一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeSecurityPolicies(std::function<void(AsyncDescribeSecurityPoliciesResult&)> callback, DescribeSecurityPoliciesRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DescribeSecurityPoliciesResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/identifier-handler?handler=gs2_identifier%2Fhandler%2FSecurityPolicyFunctionHandler.describeSecurityPolicies");
        Char encodeBuffer[2048];
        if (request.getPageToken()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPageToken()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("pageToken={value}").replace("{value}", encodeBuffer);
        }
        if (request.getLimit()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLimit()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("limit={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * オーナーIDを指定してセキュリティポリシーの一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCommonSecurityPolicies(std::function<void(AsyncDescribeCommonSecurityPoliciesResult&)> callback, DescribeCommonSecurityPoliciesRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DescribeCommonSecurityPoliciesResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/identifier-handler?handler=gs2_identifier%2Fhandler%2FSecurityPolicyFunctionHandler.describeCommonSecurityPolicies");
        Char encodeBuffer[2048];
        if (request.getPageToken()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPageToken()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("pageToken={value}").replace("{value}", encodeBuffer);
        }
        if (request.getLimit()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLimit()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("limit={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * セキュリティポリシーを新規作成します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createSecurityPolicy(std::function<void(AsyncCreateSecurityPolicyResult&)> callback, CreateSecurityPolicyRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<CreateSecurityPolicyResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/identifier-handler?handler=gs2_identifier%2Fhandler%2FSecurityPolicyFunctionHandler.createSecurityPolicy");
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
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * セキュリティポリシーを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateSecurityPolicy(std::function<void(AsyncUpdateSecurityPolicyResult&)> callback, UpdateSecurityPolicyRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<UpdateSecurityPolicyResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/identifier-handler?handler=gs2_identifier%2Fhandler%2FSecurityPolicyFunctionHandler.updateSecurityPolicy");
        Char encodeBuffer[2048];
        if (request.getSecurityPolicyName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getSecurityPolicyName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("securityPolicyName={value}").replace("{value}", encodeBuffer);
        }
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
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * セキュリティポリシーを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getSecurityPolicyStatus(std::function<void(AsyncGetSecurityPolicyStatusResult&)> callback, GetSecurityPolicyStatusRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetSecurityPolicyStatusResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/identifier-handler?handler=gs2_identifier%2Fhandler%2FSecurityPolicyFunctionHandler.getSecurityPolicyStatus");
        Char encodeBuffer[2048];
        if (request.getSecurityPolicyName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getSecurityPolicyName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("securityPolicyName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * セキュリティポリシーを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getSecurityPolicy(std::function<void(AsyncGetSecurityPolicyResult&)> callback, GetSecurityPolicyRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetSecurityPolicyResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/identifier-handler?handler=gs2_identifier%2Fhandler%2FSecurityPolicyFunctionHandler.getSecurityPolicy");
        Char encodeBuffer[2048];
        if (request.getSecurityPolicyName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getSecurityPolicyName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("securityPolicyName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * セキュリティポリシーを削除します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteSecurityPolicy(std::function<void(AsyncDeleteSecurityPolicyResult&)> callback, DeleteSecurityPolicyRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<void>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/identifier-handler?handler=gs2_identifier%2Fhandler%2FSecurityPolicyFunctionHandler.deleteSecurityPolicy");
        Char encodeBuffer[2048];
        if (request.getSecurityPolicyName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getSecurityPolicyName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("securityPolicyName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * GSIの一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeIdentifiers(std::function<void(AsyncDescribeIdentifiersResult&)> callback, DescribeIdentifiersRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DescribeIdentifiersResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/identifier-handler?handler=gs2_identifier%2Fhandler%2FIdentifierFunctionHandler.describeIdentifiers");
        Char encodeBuffer[2048];
        if (request.getUserName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getPageToken()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPageToken()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("pageToken={value}").replace("{value}", encodeBuffer);
        }
        if (request.getLimit()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLimit()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("limit={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * GSIを新規作成します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createIdentifier(std::function<void(AsyncCreateIdentifierResult&)> callback, CreateIdentifierRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<CreateIdentifierResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/identifier-handler?handler=gs2_identifier%2Fhandler%2FIdentifierFunctionHandler.createIdentifier");
        Char encodeBuffer[2048];
        if (request.getUserName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userName={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * GSIを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getIdentifier(std::function<void(AsyncGetIdentifierResult&)> callback, GetIdentifierRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetIdentifierResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/identifier-handler?handler=gs2_identifier%2Fhandler%2FIdentifierFunctionHandler.getIdentifier");
        Char encodeBuffer[2048];
        if (request.getUserName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getClientId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getClientId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("clientId={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * GSIを削除します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteIdentifier(std::function<void(AsyncDeleteIdentifierResult&)> callback, DeleteIdentifierRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<void>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/identifier-handler?handler=gs2_identifier%2Fhandler%2FIdentifierFunctionHandler.deleteIdentifier");
        Char encodeBuffer[2048];
        if (request.getUserName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getClientId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getClientId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("clientId={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * 割り当てられたセキュリティポリシーの一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getHasSecurityPolicy(std::function<void(AsyncGetHasSecurityPolicyResult&)> callback, GetHasSecurityPolicyRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetHasSecurityPolicyResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/identifier-handler?handler=gs2_identifier%2Fhandler%2FAttachSecurityPolicyFunctionHandler.getHasSecurityPolicy");
        Char encodeBuffer[2048];
        if (request.getUserName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * 割り当てられたセキュリティポリシーを新しくユーザーに割り当てます<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void attachSecurityPolicy(std::function<void(AsyncAttachSecurityPolicyResult&)> callback, AttachSecurityPolicyRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<AttachSecurityPolicyResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/identifier-handler?handler=gs2_identifier%2Fhandler%2FAttachSecurityPolicyFunctionHandler.attachSecurityPolicy");
        Char encodeBuffer[2048];
        if (request.getUserName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userName={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getSecurityPolicyId())
        {
            writer.writePropertyName("securityPolicyId");
            writer.writeCharArray(*request.getSecurityPolicyId());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * 割り当てられたセキュリティポリシーをユーザーから外します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void detachSecurityPolicy(std::function<void(AsyncDetachSecurityPolicyResult&)> callback, DetachSecurityPolicyRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DetachSecurityPolicyResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/identifier-handler?handler=gs2_identifier%2Fhandler%2FAttachSecurityPolicyFunctionHandler.detachSecurityPolicy");
        Char encodeBuffer[2048];
        if (request.getUserName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getSecurityPolicyId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getSecurityPolicyId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("securityPolicyId={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * プロジェクトトークン を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void login(std::function<void(AsyncLoginResult&)> callback, LoginRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<LoginResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/identifier-handler?handler=gs2_identifier%2Fhandler%2FProjectTokenFunctionHandler.login");
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
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }
};

} }

#endif //GS2_IDENTIFIER_GS2IDENTIFIERCLIENT_HPP_