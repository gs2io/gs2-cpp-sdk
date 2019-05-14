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
#include <gs2/core/network/HttpRequest.hpp>
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
            writer.write(*obj.getUserId());
        }
        if (obj.getOwnerId())
        {
            writer.writePropertyName("ownerId");
            writer.write(*obj.getOwnerId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.write(*obj.getName());
        }
        if (obj.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*obj.getDescription());
        }
        if (obj.getCreateAt())
        {
            writer.writePropertyName("createAt");
            writer.write(*obj.getCreateAt());
        }
        if (obj.getUpdateAt())
        {
            writer.writePropertyName("updateAt");
            writer.write(*obj.getUpdateAt());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const SecurityPolicy& obj)
    {
        writer.writeObjectStart();
        if (obj.getSecurityPolicyId())
        {
            writer.writePropertyName("securityPolicyId");
            writer.write(*obj.getSecurityPolicyId());
        }
        if (obj.getOwnerId())
        {
            writer.writePropertyName("ownerId");
            writer.write(*obj.getOwnerId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.write(*obj.getName());
        }
        if (obj.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*obj.getDescription());
        }
        if (obj.getPolicy())
        {
            writer.writePropertyName("policy");
            writer.write(*obj.getPolicy());
        }
        if (obj.getCreateAt())
        {
            writer.writePropertyName("createAt");
            writer.write(*obj.getCreateAt());
        }
        if (obj.getUpdateAt())
        {
            writer.writePropertyName("updateAt");
            writer.write(*obj.getUpdateAt());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const Identifier& obj)
    {
        writer.writeObjectStart();
        if (obj.getOwnerId())
        {
            writer.writePropertyName("ownerId");
            writer.write(*obj.getOwnerId());
        }
        if (obj.getClientId())
        {
            writer.writePropertyName("clientId");
            writer.write(*obj.getClientId());
        }
        if (obj.getUserName())
        {
            writer.writePropertyName("userName");
            writer.write(*obj.getUserName());
        }
        if (obj.getCreateAt())
        {
            writer.writePropertyName("createAt");
            writer.write(*obj.getCreateAt());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const FullIdentifier& obj)
    {
        writer.writeObjectStart();
        if (obj.getOwnerId())
        {
            writer.writePropertyName("ownerId");
            writer.write(*obj.getOwnerId());
        }
        if (obj.getClientId())
        {
            writer.writePropertyName("clientId");
            writer.write(*obj.getClientId());
        }
        if (obj.getUserName())
        {
            writer.writePropertyName("userName");
            writer.write(*obj.getUserName());
        }
        if (obj.getCreateAt())
        {
            writer.writePropertyName("createAt");
            writer.write(*obj.getCreateAt());
        }
        if (obj.getClientSecret())
        {
            writer.writePropertyName("clientSecret");
            writer.write(*obj.getClientSecret());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const AttachSecurityPolicy& obj)
    {
        writer.writeObjectStart();
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.write(*obj.getUserId());
        }
        if (obj.getSecurityPolicyIds())
        {
            writer.writePropertyName("securityPolicyIds");
            writer.writeArrayStart();
            auto& list = *obj.getSecurityPolicyIds();
            for (Int32 i = 0; i < list.getCount(); ++i)
            {
                writer.write(list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getAttachAt())
        {
            writer.writePropertyName("attachAt");
            writer.write(*obj.getAttachAt());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const ProjectToken& obj)
    {
        writer.writeObjectStart();
        if (obj.getToken())
        {
            writer.writePropertyName("token");
            writer.write(*obj.getToken());
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
        auto& httpRequest = *new detail::HttpRequest<DescribeUsersResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
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

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * ユーザーを新規作成します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createUser(std::function<void(AsyncCreateUserResult&)> callback, CreateUserRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateUserResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/identifier-handler?handler=gs2_identifier%2Fhandler%2FUserFunctionHandler.createUser");
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getName())
        {
            writer.writePropertyName("name");
            writer.write(*request.getName());
        }
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*request.getDescription());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * ユーザーを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateUser(std::function<void(AsyncUpdateUserResult&)> callback, UpdateUserRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateUserResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
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
            writer.write(*request.getDescription());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * ユーザーを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getUserStatus(std::function<void(AsyncGetUserStatusResult&)> callback, GetUserStatusRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetUserStatusResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/identifier-handler?handler=gs2_identifier%2Fhandler%2FUserFunctionHandler.getUserStatus");
        Char encodeBuffer[2048];
        if (request.getUserName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * ユーザーを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getUser(std::function<void(AsyncGetUserResult&)> callback, GetUserRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetUserResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/identifier-handler?handler=gs2_identifier%2Fhandler%2FUserFunctionHandler.getUser");
        Char encodeBuffer[2048];
        if (request.getUserName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * ユーザーを削除します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteUser(std::function<void(AsyncDeleteUserResult&)> callback, DeleteUserRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/identifier-handler?handler=gs2_identifier%2Fhandler%2FUserFunctionHandler.deleteUser");
        Char encodeBuffer[2048];
        if (request.getUserName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * セキュリティポリシーの一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeSecurityPolicies(std::function<void(AsyncDescribeSecurityPoliciesResult&)> callback, DescribeSecurityPoliciesRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeSecurityPoliciesResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
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

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * オーナーIDを指定してセキュリティポリシーの一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCommonSecurityPolicies(std::function<void(AsyncDescribeCommonSecurityPoliciesResult&)> callback, DescribeCommonSecurityPoliciesRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeCommonSecurityPoliciesResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
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

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * セキュリティポリシーを新規作成します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createSecurityPolicy(std::function<void(AsyncCreateSecurityPolicyResult&)> callback, CreateSecurityPolicyRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateSecurityPolicyResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/identifier-handler?handler=gs2_identifier%2Fhandler%2FSecurityPolicyFunctionHandler.createSecurityPolicy");
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getName())
        {
            writer.writePropertyName("name");
            writer.write(*request.getName());
        }
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*request.getDescription());
        }
        if (request.getPolicy())
        {
            writer.writePropertyName("policy");
            writer.write(*request.getPolicy());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * セキュリティポリシーを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateSecurityPolicy(std::function<void(AsyncUpdateSecurityPolicyResult&)> callback, UpdateSecurityPolicyRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateSecurityPolicyResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
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
            writer.write(*request.getDescription());
        }
        if (request.getPolicy())
        {
            writer.writePropertyName("policy");
            writer.write(*request.getPolicy());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * セキュリティポリシーを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getSecurityPolicyStatus(std::function<void(AsyncGetSecurityPolicyStatusResult&)> callback, GetSecurityPolicyStatusRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetSecurityPolicyStatusResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/identifier-handler?handler=gs2_identifier%2Fhandler%2FSecurityPolicyFunctionHandler.getSecurityPolicyStatus");
        Char encodeBuffer[2048];
        if (request.getSecurityPolicyName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getSecurityPolicyName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("securityPolicyName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * セキュリティポリシーを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getSecurityPolicy(std::function<void(AsyncGetSecurityPolicyResult&)> callback, GetSecurityPolicyRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetSecurityPolicyResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/identifier-handler?handler=gs2_identifier%2Fhandler%2FSecurityPolicyFunctionHandler.getSecurityPolicy");
        Char encodeBuffer[2048];
        if (request.getSecurityPolicyName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getSecurityPolicyName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("securityPolicyName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * セキュリティポリシーを削除します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteSecurityPolicy(std::function<void(AsyncDeleteSecurityPolicyResult&)> callback, DeleteSecurityPolicyRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/identifier-handler?handler=gs2_identifier%2Fhandler%2FSecurityPolicyFunctionHandler.deleteSecurityPolicy");
        Char encodeBuffer[2048];
        if (request.getSecurityPolicyName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getSecurityPolicyName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("securityPolicyName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * GSIの一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeIdentifiers(std::function<void(AsyncDescribeIdentifiersResult&)> callback, DescribeIdentifiersRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeIdentifiersResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
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

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * GSIを新規作成します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createIdentifier(std::function<void(AsyncCreateIdentifierResult&)> callback, CreateIdentifierRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateIdentifierResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
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
        httpRequest.setRequestData(body, bodySize);

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * GSIを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getIdentifier(std::function<void(AsyncGetIdentifierResult&)> callback, GetIdentifierRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetIdentifierResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
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

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * GSIを削除します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteIdentifier(std::function<void(AsyncDeleteIdentifierResult&)> callback, DeleteIdentifierRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
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

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * 割り当てられたセキュリティポリシーの一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getHasSecurityPolicy(std::function<void(AsyncGetHasSecurityPolicyResult&)> callback, GetHasSecurityPolicyRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetHasSecurityPolicyResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/identifier-handler?handler=gs2_identifier%2Fhandler%2FAttachSecurityPolicyFunctionHandler.getHasSecurityPolicy");
        Char encodeBuffer[2048];
        if (request.getUserName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * 割り当てられたセキュリティポリシーを新しくユーザーに割り当てます<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void attachSecurityPolicy(std::function<void(AsyncAttachSecurityPolicyResult&)> callback, AttachSecurityPolicyRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<AttachSecurityPolicyResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
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
            writer.write(*request.getSecurityPolicyId());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * 割り当てられたセキュリティポリシーをユーザーから外します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void detachSecurityPolicy(std::function<void(AsyncDetachSecurityPolicyResult&)> callback, DetachSecurityPolicyRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DetachSecurityPolicyResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
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

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * プロジェクトトークン を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void login(std::function<void(AsyncLoginResult&)> callback, LoginRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<LoginResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/identifier-handler?handler=gs2_identifier%2Fhandler%2FProjectTokenFunctionHandler.login");
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getClientId())
        {
            writer.writePropertyName("clientId");
            writer.write(*request.getClientId());
        }
        if (request.getClientSecret())
        {
            writer.writePropertyName("clientSecret");
            writer.write(*request.getClientSecret());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }
};

} }

#endif //GS2_IDENTIFIER_GS2IDENTIFIERCLIENT_HPP_