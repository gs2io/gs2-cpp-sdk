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

#ifndef GS2_AUTH_GS2AUTHWEBSOCKETCLIENT_HPP_
#define GS2_AUTH_GS2AUTHWEBSOCKETCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2WebSocketSessionTask.hpp>
#include <gs2/core/network/Gs2WebSocketSession.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include "model/model.hpp"
#include "request/LoginRequest.hpp"
#include "request/LoginBySignatureRequest.hpp"
#include "result/LoginResult.hpp"
#include "result/LoginBySignatureResult.hpp"
#include <cstring>

namespace gs2 { namespace auth {

/**
 * GS2 Auth API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2AuthWebSocketClient : public AbstractGs2ClientBase
{
private:

    class LoginTask : public detail::Gs2WebSocketSessionTask<LoginResult>
    {
    private:
        LoginRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "auth";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "accessToken";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "login";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getTimeOffset())
            {
                jsonWriter.writePropertyName("timeOffset");
                jsonWriter.writeInt32(*m_Request.getTimeOffset());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        LoginTask(
            LoginRequest request,
            Gs2WebSocketSessionTask<LoginResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<LoginResult>(callback),
            m_Request(std::move(request))
        {}

        ~LoginTask() GS2_OVERRIDE = default;
    };

    class LoginBySignatureTask : public detail::Gs2WebSocketSessionTask<LoginBySignatureResult>
    {
    private:
        LoginBySignatureRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "auth";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "accessToken";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "loginBySignature";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getKeyId())
            {
                jsonWriter.writePropertyName("keyId");
                jsonWriter.writeCharArray(*m_Request.getKeyId());
            }
            if (m_Request.getBody())
            {
                jsonWriter.writePropertyName("body");
                jsonWriter.writeCharArray(*m_Request.getBody());
            }
            if (m_Request.getSignature())
            {
                jsonWriter.writePropertyName("signature");
                jsonWriter.writeCharArray(*m_Request.getSignature());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        LoginBySignatureTask(
            LoginBySignatureRequest request,
            Gs2WebSocketSessionTask<LoginBySignatureResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<LoginBySignatureResult>(callback),
            m_Request(std::move(request))
        {}

        ~LoginBySignatureTask() GS2_OVERRIDE = default;
    };

private:
    static void write(detail::json::JsonWriter& jsonWriter, const AccessToken& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getOwnerId())
        {
            jsonWriter.writePropertyName("ownerId");
            jsonWriter.writeCharArray(*obj.getOwnerId());
        }
        if (obj.getToken())
        {
            jsonWriter.writePropertyName("token");
            jsonWriter.writeCharArray(*obj.getToken());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getExpire())
        {
            jsonWriter.writePropertyName("expire");
            jsonWriter.writeInt64(*obj.getExpire());
        }
        jsonWriter.writeObjectEnd();
    }


public:
    /**
     * コンストラクタ。
     *
     * @param gs2WebSocketSession WebSocket API 用セッション
     */
    explicit Gs2AuthWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
        AbstractGs2ClientBase(gs2WebSocketSession)
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
    void login(LoginRequest request, std::function<void(AsyncLoginResult)> callback)
    {
        LoginTask& task = *new LoginTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 指定したユーザIDでGS2にログインし、アクセストークンを取得します<br>
	 *   ユーザIDの署名検証を実施することで、本APIはクライアントから呼び出しても安全です。<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void loginBySignature(LoginBySignatureRequest request, std::function<void(AsyncLoginBySignatureResult)> callback)
    {
        LoginBySignatureTask& task = *new LoginBySignatureTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_AUTH_GS2AUTHWEBSOCKETCLIENT_HPP_