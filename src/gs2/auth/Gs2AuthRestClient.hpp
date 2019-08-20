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

#ifndef GS2_AUTH_GS2AUTHRESTCLIENT_HPP_
#define GS2_AUTH_GS2AUTHRESTCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2RestSessionTask.hpp>
#include <gs2/core/network/Gs2RestSession.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include "model/model.hpp"
#include "request/LoginRequest.hpp"
#include "request/LoginBySignatureRequest.hpp"
#include "result/LoginResult.hpp"
#include "result/LoginBySignatureResult.hpp"
#include <cstring>

namespace gs2 { namespace auth {

typedef AsyncResult<LoginResult> AsyncLoginResult;
typedef AsyncResult<LoginBySignatureResult> AsyncLoginBySignatureResult;

/**
 * GS2 Auth API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2AuthRestClient : public AbstractGs2ClientBase
{
private:
    static void write(detail::json::JsonWriter& writer, const AccessToken& obj)
    {
        writer.writeObjectStart();
        if (obj.getOwnerId())
        {
            writer.writePropertyName("ownerId");
            writer.writeCharArray(*obj.getOwnerId());
        }
        if (obj.getToken())
        {
            writer.writePropertyName("token");
            writer.writeCharArray(*obj.getToken());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.writeCharArray(*obj.getUserId());
        }
        if (obj.getExpire())
        {
            writer.writePropertyName("expire");
            writer.writeInt64(*obj.getExpire());
        }
        writer.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
     */
    explicit Gs2AuthRestClient(Gs2RestSession& gs2RestSession) :
        AbstractGs2ClientBase(gs2RestSession)
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
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<LoginResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "auth");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/login";
        httpRequest.SetURL(url.c_str());
        detail::json::JsonWriter writer;

        writer.writeObjectStart();
        if (request.getContextStack())
        {
            writer.writePropertyName("contextStack");
            writer.writeCharArray(*request.getContextStack());
        }
        if (request.getUserId())
        {
            writer.writePropertyName("userId");
            writer.writeCharArray(*request.getUserId());
        }
        if (request.getTimeOffset())
        {
            writer.writePropertyName("timeOffset");
            writer.writeInt32(*request.getTimeOffset());
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
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
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
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<LoginBySignatureResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "auth");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/login/signed";
        httpRequest.SetURL(url.c_str());
        detail::json::JsonWriter writer;

        writer.writeObjectStart();
        if (request.getContextStack())
        {
            writer.writePropertyName("contextStack");
            writer.writeCharArray(*request.getContextStack());
        }
        if (request.getUserId())
        {
            writer.writePropertyName("userId");
            writer.writeCharArray(*request.getUserId());
        }
        if (request.getKeyId())
        {
            writer.writePropertyName("keyId");
            writer.writeCharArray(*request.getKeyId());
        }
        if (request.getBody())
        {
            writer.writePropertyName("body");
            writer.writeCharArray(*request.getBody());
        }
        if (request.getSignature())
        {
            writer.writePropertyName("signature");
            writer.writeCharArray(*request.getSignature());
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
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
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

#endif //GS2_AUTH_GS2AUTHRESTCLIENT_HPP_