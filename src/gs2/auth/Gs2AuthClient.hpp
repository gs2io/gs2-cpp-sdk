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

#ifndef GS2_AUTH_GS2AUTHCLIENT_HPP_
#define GS2_AUTH_GS2AUTHCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/HttpRequest.hpp>
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "control/controller.hpp"
#include "model/model.hpp"
#include <cstring>

namespace gs2 { namespace auth {

typedef AsyncResult<CreateOnceOnetimeTokenResult> AsyncCreateOnceOnetimeTokenResult;
typedef AsyncResult<CreateTimeOnetimeTokenResult> AsyncCreateTimeOnetimeTokenResult;
typedef AsyncResult<LoginResult> AsyncLoginResult;
typedef AsyncResult<LoginWithSignResult> AsyncLoginWithSignResult;

class Gs2AuthClient : public AbstractGs2ClientBase
{
private:
    constexpr static const Char* ENDPOINT = "auth";

    virtual const Char* getEndPoint() const
    {
        return ENDPOINT;
    }

private:

    void write(detail::json::JsonWriter& writer, const AccountToken& obj)
    {
        writer.writeObjectStart();
        if (obj.getOwnerId())
        {
            writer.writePropertyName("ownerId");
            writer.write(*obj.getOwnerId());
        }
        if (obj.getGameName())
        {
            writer.writePropertyName("gameName");
            writer.write(*obj.getGameName());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.write(*obj.getUserId());
        }
        if (obj.getTimestamp())
        {
            writer.writePropertyName("timestamp");
            writer.write(*obj.getTimestamp());
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
     * 実行回数制限付きワンタイムトークンを発行します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createOnceOnetimeToken(std::function<void(AsyncCreateOnceOnetimeTokenResult&)> callback, CreateOnceOnetimeTokenRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateOnceOnetimeTokenResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/onetime/once/token");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getScriptName())
        {
            writer.writePropertyName("scriptName");
            writer.write(*request.getScriptName());
        }
        if (request.getGrant())
        {
            writer.writePropertyName("grant");
            writer.write(*request.getGrant());
        }
        if (request.getArgs())
        {
            writer.writePropertyName("args");
            writer.write(*request.getArgs());
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
     * 1回のみ実行を許可するワンタイムトークンを発行します<br>
     * このトークンはスタミナの回復処理など、有効期間内だからといって何度も実行されたくない処理を1度だけ許可したい場合に発行します。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createTimeOnetimeToken(std::function<void(AsyncCreateTimeOnetimeTokenResult&)> callback, CreateTimeOnetimeTokenRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateTimeOnetimeTokenResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/onetime/time/token");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getScriptName())
        {
            writer.writePropertyName("scriptName");
            writer.write(*request.getScriptName());
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
     * ログイン処理を実行します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void login(std::function<void(AsyncLoginResult&)> callback, LoginRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<LoginResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/login");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getServiceId())
        {
            writer.writePropertyName("serviceId");
            writer.write(*request.getServiceId());
        }
        if (request.getUserId())
        {
            writer.writePropertyName("userId");
            writer.write(*request.getUserId());
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
     * GS2-Accountの認証署名付きログイン処理を実行します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void loginWithSign(std::function<void(AsyncLoginWithSignResult&)> callback, LoginWithSignRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<LoginWithSignResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/login/signed");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getServiceId())
        {
            writer.writePropertyName("serviceId");
            writer.write(*request.getServiceId());
        }
        if (request.getUserId())
        {
            writer.writePropertyName("userId");
            writer.write(*request.getUserId());
        }
        if (request.getKeyName())
        {
            writer.writePropertyName("keyName");
            writer.write(*request.getKeyName());
        }
        if (request.getSign())
        {
            writer.writePropertyName("sign");
            writer.write(*request.getSign());
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

#endif //GS2_AUTH_GS2AUTHCLIENT_HPP_