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

typedef AsyncResult<LoginResult> AsyncLoginResult;
typedef AsyncResult<LoginBySignatureResult> AsyncLoginBySignatureResult;

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
        LoginRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getUserId())
            {
                writer.writePropertyName("userId");
                writer.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getTimeOffset())
            {
                writer.writePropertyName("timeOffset");
                writer.writeInt32(*m_Request.getTimeOffset());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("auth");
            writer.writePropertyName("component");
            writer.writeCharArray("accessToken");
            writer.writePropertyName("function");
            writer.writeCharArray("login");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        LoginTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            LoginRequest& request,
            Gs2WebSocketSessionTask<LoginResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<LoginResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~LoginTask() GS2_OVERRIDE = default;
    };

    class LoginBySignatureTask : public detail::Gs2WebSocketSessionTask<LoginBySignatureResult>
    {
    private:
        LoginBySignatureRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getUserId())
            {
                writer.writePropertyName("userId");
                writer.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getKeyId())
            {
                writer.writePropertyName("keyId");
                writer.writeCharArray(*m_Request.getKeyId());
            }
            if (m_Request.getBody())
            {
                writer.writePropertyName("body");
                writer.writeCharArray(*m_Request.getBody());
            }
            if (m_Request.getSignature())
            {
                writer.writePropertyName("signature");
                writer.writeCharArray(*m_Request.getSignature());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("auth");
            writer.writePropertyName("component");
            writer.writeCharArray("accessToken");
            writer.writePropertyName("function");
            writer.writeCharArray("loginBySignature");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        LoginBySignatureTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            LoginBySignatureRequest& request,
            Gs2WebSocketSessionTask<LoginBySignatureResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<LoginBySignatureResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~LoginBySignatureTask() GS2_OVERRIDE = default;
    };

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
    void login(std::function<void(AsyncLoginResult&)> callback, LoginRequest& request)
    {
        LoginTask& task = *new LoginTask(getGs2WebSocketSession(), request, callback);
        task.execute();
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
        LoginBySignatureTask& task = *new LoginBySignatureTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_AUTH_GS2AUTHWEBSOCKETCLIENT_HPP_