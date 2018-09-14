/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
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
#include "control/controller.hpp"
#include "model/model.hpp"
#include <cstring>

namespace gs2 { namespace identifier {

typedef AsyncResult<CreateIdentifierResult> AsyncCreateIdentifierResult;
typedef AsyncResult<void> AsyncDeleteIdentifierResult;
typedef AsyncResult<DescribeIdentifierResult> AsyncDescribeIdentifierResult;
typedef AsyncResult<GetIdentifierResult> AsyncGetIdentifierResult;
typedef AsyncResult<CreateSecurityPolicyResult> AsyncCreateSecurityPolicyResult;
typedef AsyncResult<void> AsyncDeleteSecurityPolicyResult;
typedef AsyncResult<DescribeCommonSecurityPolicyResult> AsyncDescribeCommonSecurityPolicyResult;
typedef AsyncResult<DescribeSecurityPolicyResult> AsyncDescribeSecurityPolicyResult;
typedef AsyncResult<GetSecurityPolicyResult> AsyncGetSecurityPolicyResult;
typedef AsyncResult<UpdateSecurityPolicyResult> AsyncUpdateSecurityPolicyResult;
typedef AsyncResult<void> AsyncAttachSecurityPolicyResult;
typedef AsyncResult<CreateUserResult> AsyncCreateUserResult;
typedef AsyncResult<void> AsyncDeleteUserResult;
typedef AsyncResult<DescribeUserResult> AsyncDescribeUserResult;
typedef AsyncResult<void> AsyncDetachSecurityPolicyResult;
typedef AsyncResult<GetHasSecurityPolicyResult> AsyncGetHasSecurityPolicyResult;
typedef AsyncResult<GetUserResult> AsyncGetUserResult;

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
        if (obj.getCreateAt())
        {
            writer.writePropertyName("createAt");
            writer.write(*obj.getCreateAt());
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
        if (obj.getIdentifierId())
        {
            writer.writePropertyName("identifierId");
            writer.write(*obj.getIdentifierId());
        }
        if (obj.getOwnerId())
        {
            writer.writePropertyName("ownerId");
            writer.write(*obj.getOwnerId());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.write(*obj.getUserId());
        }
        if (obj.getClientId())
        {
            writer.writePropertyName("clientId");
            writer.write(*obj.getClientId());
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
        if (obj.getIdentifierId())
        {
            writer.writePropertyName("identifierId");
            writer.write(*obj.getIdentifierId());
        }
        if (obj.getOwnerId())
        {
            writer.writePropertyName("ownerId");
            writer.write(*obj.getOwnerId());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.write(*obj.getUserId());
        }
        if (obj.getClientId())
        {
            writer.writePropertyName("clientId");
            writer.write(*obj.getClientId());
        }
        if (obj.getClientSecret())
        {
            writer.writePropertyName("clientSecret");
            writer.write(*obj.getClientSecret());
        }
        if (obj.getCreateAt())
        {
            writer.writePropertyName("createAt");
            writer.write(*obj.getCreateAt());
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
     * GSIを新規作成します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createIdentifier(std::function<void(AsyncCreateIdentifierResult&)> callback, CreateIdentifierRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateIdentifierResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/user/").append(detail::StringUtil::toStr(buffer, request.getUserName())).append("/identifier");
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
     * GSIを削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteIdentifier(std::function<void(AsyncDeleteIdentifierResult&)> callback, DeleteIdentifierRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/user/").append(detail::StringUtil::toStr(buffer, request.getUserName())).append("/identifier/").append(detail::StringUtil::toStr(buffer, request.getIdentifierId())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * GSIの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeIdentifier(std::function<void(AsyncDescribeIdentifierResult&)> callback, DescribeIdentifierRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeIdentifierResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/user/").append(detail::StringUtil::toStr(buffer, request.getUserName())).append("/identifier");
        }
        detail::StringVariable queryString("");
        Char encodeBuffer[1024];
        if (request.getPageToken()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPageToken()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("pageToken={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (request.getLimit()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLimit()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("limit={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (queryString.endsWith("&")) {
            url += "?" + queryString.substr(0, queryString.size() - 1);
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * GSIを取得します。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getIdentifier(std::function<void(AsyncGetIdentifierResult&)> callback, GetIdentifierRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetIdentifierResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/user/").append(detail::StringUtil::toStr(buffer, request.getUserName())).append("/identifier/").append(detail::StringUtil::toStr(buffer, request.getIdentifierId())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * セキュリティポリシーを新規作成します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createSecurityPolicy(std::function<void(AsyncCreateSecurityPolicyResult&)> callback, CreateSecurityPolicyRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateSecurityPolicyResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/securityPolicy");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getName())
        {
            writer.writePropertyName("name");
            writer.write(*request.getName());
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
     * セキュリティポリシーを削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteSecurityPolicy(std::function<void(AsyncDeleteSecurityPolicyResult&)> callback, DeleteSecurityPolicyRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/securityPolicy/").append(detail::StringUtil::toStr(buffer, request.getSecurityPolicyName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 共用セキュリティポリシーの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCommonSecurityPolicy(std::function<void(AsyncDescribeCommonSecurityPolicyResult&)> callback, DescribeCommonSecurityPolicyRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeCommonSecurityPolicyResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/securityPolicy/common");
        }
        detail::StringVariable queryString("");
        Char encodeBuffer[1024];
        if (request.getPageToken()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPageToken()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("pageToken={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (request.getLimit()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLimit()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("limit={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (queryString.endsWith("&")) {
            url += "?" + queryString.substr(0, queryString.size() - 1);
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * セキュリティポリシーの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeSecurityPolicy(std::function<void(AsyncDescribeSecurityPolicyResult&)> callback, DescribeSecurityPolicyRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeSecurityPolicyResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/securityPolicy");
        }
        detail::StringVariable queryString("");
        Char encodeBuffer[1024];
        if (request.getPageToken()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPageToken()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("pageToken={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (request.getLimit()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLimit()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("limit={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (queryString.endsWith("&")) {
            url += "?" + queryString.substr(0, queryString.size() - 1);
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * セキュリティポリシーを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getSecurityPolicy(std::function<void(AsyncGetSecurityPolicyResult&)> callback, GetSecurityPolicyRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetSecurityPolicyResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/securityPolicy/").append(detail::StringUtil::toStr(buffer, request.getSecurityPolicyName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * セキュリティポリシーを更新します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateSecurityPolicy(std::function<void(AsyncUpdateSecurityPolicyResult&)> callback, UpdateSecurityPolicyRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateSecurityPolicyResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/securityPolicy/").append(detail::StringUtil::toStr(buffer, request.getSecurityPolicyName())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
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
     * ユーザにセキュリティポリシーを割り当てます<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void attachSecurityPolicy(std::function<void(AsyncAttachSecurityPolicyResult&)> callback, AttachSecurityPolicyRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/user/").append(detail::StringUtil::toStr(buffer, request.getUserName())).append("/securityPolicy");
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
     * ユーザを新規作成します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createUser(std::function<void(AsyncCreateUserResult&)> callback, CreateUserRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateUserResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/user");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getName())
        {
            writer.writePropertyName("name");
            writer.write(*request.getName());
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
     * ユーザを削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteUser(std::function<void(AsyncDeleteUserResult&)> callback, DeleteUserRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/user/").append(detail::StringUtil::toStr(buffer, request.getUserName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ユーザの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeUser(std::function<void(AsyncDescribeUserResult&)> callback, DescribeUserRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeUserResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/user");
        }
        detail::StringVariable queryString("");
        Char encodeBuffer[1024];
        if (request.getPageToken()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPageToken()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("pageToken={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (request.getLimit()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLimit()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("limit={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (queryString.endsWith("&")) {
            url += "?" + queryString.substr(0, queryString.size() - 1);
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ユーザに割り当てられたセキュリティポリシーを解除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void detachSecurityPolicy(std::function<void(AsyncDetachSecurityPolicyResult&)> callback, DetachSecurityPolicyRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/user/").append(detail::StringUtil::toStr(buffer, request.getUserName())).append("/securityPolicy/").append(detail::StringUtil::toStr(buffer, request.getSecurityPolicyId())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ユーザが保持しているセキュリティポリシー一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getHasSecurityPolicy(std::function<void(AsyncGetHasSecurityPolicyResult&)> callback, GetHasSecurityPolicyRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetHasSecurityPolicyResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/user/").append(detail::StringUtil::toStr(buffer, request.getUserName())).append("/securityPolicy");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ユーザを取得します。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getUser(std::function<void(AsyncGetUserResult&)> callback, GetUserRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetUserResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/user/").append(detail::StringUtil::toStr(buffer, request.getUserName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

};

} }

#endif //GS2_IDENTIFIER_GS2IDENTIFIERCLIENT_HPP_