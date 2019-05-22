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

#ifndef GS2_AUTH_GS2AUTHCLIENT_HPP_
#define GS2_AUTH_GS2AUTHCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2StandardHttpTask.hpp>
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "model/model.hpp"
#include "request/LoginRequest.hpp"
#include "request/LoginBySignatureRequest.hpp"
#include "result/LoginResult.hpp"
#include "result/LoginBySignatureResult.hpp"
#include <cstring>
#include <network/HttpRequest.h>

namespace gs2 { namespace auth {

typedef AsyncResult<LoginResult> AsyncLoginResult;
typedef AsyncResult<LoginBySignatureResult> AsyncLoginBySignatureResult;

/**
 * GS2 Auth API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2AuthClient : public AbstractGs2ClientBase
{
private:
    constexpr static const Char* ENDPOINT = "auth";

    virtual const Char* getEndPoint() const
    {
        return ENDPOINT;
    }

private:
    void write(detail::json::JsonWriter& writer, const AccessToken& obj)
    {
        writer.writeObjectStart();
        if (obj.getOwnerId())
        {
            writer.writePropertyName("ownerId");
            writer.write(*obj.getOwnerId());
        }
        if (obj.getToken())
        {
            writer.writePropertyName("token");
            writer.write(*obj.getToken());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.write(*obj.getUserId());
        }
        if (obj.getExpire())
        {
            writer.writePropertyName("expire");
            writer.write(*obj.getExpire());
        }
        writer.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
     */
    Gs2AuthClient(IGs2Credential& credential) :
        AbstractGs2ClientBase(credential)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2AuthClient(IGs2Credential& credential, const Region& region) :
        AbstractGs2ClientBase(credential, region)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2AuthClient(IGs2Credential& credential, const Char region[]) :
        AbstractGs2ClientBase(credential, region)
    {
    }

	/**
	 * 指定したユーザIDでGS2にログインし、アクセストークンを取得します<br>
	 *   本APIは信頼出来るゲームサーバーから呼び出されることを想定しています。<br>
	 *   ユーザIDの値の検証処理が存在しないため、クライアントから呼び出すのは不適切です。<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void login(std::function<void(AsyncLoginResult&)> callback, LoginRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<LoginResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/auth-handler?handler=gs2_auth%2Fhandler%2FAccessTokenFunctionHandler.login");
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getUserId())
        {
            writer.writePropertyName("userId");
            writer.write(*request.getUserId());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        setHeaderEntries(headerEntries, request);
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * 指定したユーザIDでGS2にログインし、アクセストークンを取得します<br>
	 *   ユーザIDの署名検証を実施することで、本APIはクライアントから呼び出しても安全です。<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void loginBySignature(std::function<void(AsyncLoginBySignatureResult&)> callback, LoginBySignatureRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<LoginBySignatureResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/auth-handler?handler=gs2_auth%2Fhandler%2FAccessTokenFunctionHandler.loginBySignature");
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getUserId())
        {
            writer.writePropertyName("userId");
            writer.write(*request.getUserId());
        }
        if (request.getKeyId())
        {
            writer.writePropertyName("keyId");
            writer.write(*request.getKeyId());
        }
        if (request.getBody())
        {
            writer.writePropertyName("body");
            writer.write(*request.getBody());
        }
        if (request.getSignature())
        {
            writer.writePropertyName("signature");
            writer.write(*request.getSignature());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        setHeaderEntries(headerEntries, request);
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }
};

} }

#endif //GS2_AUTH_GS2AUTHCLIENT_HPP_