/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All
 * Rights Reserved.
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

#include "Gs2WebSocketSession.hpp"
#include "../json/JsonWriter.hpp"
#include "../json/JsonParser.hpp"
#include "Gs2WebSocketSessionTask.hpp"
#include "Gs2WebSocketResponse.hpp"
#include "LoginResultModel.hpp"
#include <cstring>

GS2_START_OF_NAMESPACE

const char* Gs2WebSocketSession::EndpointHost = "wss://gateway-ws.ap-northeast-1.gen2.gs2io.com/v2";

void Gs2WebSocketSession::WebSocket::onOpen()
{
    // TODO: キャンセル対応
    assert(m_Gs2WebSocketSession.m_State == Gs2WebSocketSession::State::Opening);

    auto& gs2Credential = m_Gs2WebSocketSession.getGs2Credential();     // 不変なのでロックの外で取り出してアクセスしてもよい

    Char loginMessageBuffer[1024];
    std::snprintf(
        loginMessageBuffer,
        sizeof(loginMessageBuffer),
        "{"
            "\"client_id\": \"%s\","
            "\"client_secret\": \"%s\","
            "\"x_gs2\": {"
                "\"service\": \"identifier\","
                "\"component\": \"projectToken\","
                "\"function\": \"login\","
                "\"contentType\": \"application/json\","
                "\"requestId\": \"%u\""
            "}"
        "}",
        gs2Credential.getClientId().getCString(),
        gs2Credential.getClientSecret().getCString(),
        LoginTaskIdValue
    );

    m_Gs2WebSocketSession.m_State = Gs2WebSocketSession::State::LoggingIn;

    send(loginMessageBuffer);
}

void Gs2WebSocketSession::WebSocket::onMessage(detail::Gs2WebSocketResponse& gs2WebSocketResponse)
{
    switch (m_Gs2WebSocketSession.m_State)
    {
    case Gs2WebSocketSession::State::Idle:
    case Gs2WebSocketSession::State::Opening:
        // 来ない
        break;

    case Gs2WebSocketSession::State::LoggingIn:
        if (gs2WebSocketResponse.getGs2SessionTaskId() == LoginTaskIdValue)
        {
            if (gs2WebSocketResponse.getGs2ClientException())
            {
                m_Gs2WebSocketSession.m_LastGs2ClientException = std::move(*gs2WebSocketResponse.getGs2ClientException());
                m_Gs2WebSocketSession.m_State = Gs2WebSocketSession::State::LoginFailed;
                close();
            }
            else
            {
                detail::LoginResultModel loginResultModel;
                gs2WebSocketResponse.exportTo(loginResultModel);

                if (loginResultModel.accessToken)   // パース成功
                {
                    m_Gs2WebSocketSession.m_State = Gs2WebSocketSession::State::Available;
                    m_Gs2WebSocketSession.openCallback(&*loginResultModel.accessToken, nullptr);
                }
                else
                {
                    // 「正常に」エラー応答がパースされた場合もこちら
                    Gs2ClientException gs2ClientException;
                    gs2ClientException.setType(Gs2ClientException::SessionNotOpenException);   // TODO
                    m_Gs2WebSocketSession.m_LastGs2ClientException = std::move(gs2ClientException);
                    m_Gs2WebSocketSession.m_State = Gs2WebSocketSession::State::LoginFailed;
                    close();
                }
            }
        }
        else
        {
            // ここでメッセージは届かないはずだけど、届いたらエラーにする？
        }
        break;

    case Gs2WebSocketSession::State::LoginFailed:
        // ここでメッセージは届かないはず
        break;

    case Gs2WebSocketSession::State::Available:
        if (gs2WebSocketResponse.getGs2SessionTaskId() == detail::Gs2SessionTaskId::InvalidIdValue)
        {
            // API 応答以外のメッセージ
            if (m_Gs2WebSocketSession.m_OnNotificationMessage)
            {
                NotificationMessage notificationMessage;
                gs2WebSocketResponse.exportTo(notificationMessage.getModel());
                m_Gs2WebSocketSession.m_OnNotificationMessage(notificationMessage);
            }
        }
        else
        {
            m_Gs2WebSocketSession.onResponse(gs2WebSocketResponse.getGs2SessionTaskId(), gs2WebSocketResponse);
        }
        break;
    }
}

void Gs2WebSocketSession::WebSocket::onClose()
{
    auto state = m_Gs2WebSocketSession.m_State;

    m_Gs2WebSocketSession.m_State = Gs2WebSocketSession::State::Idle;

    switch (state)
    {
    case Gs2WebSocketSession::State::Idle:
        // 来ない
        break;

    case Gs2WebSocketSession::State::Opening:
    case Gs2WebSocketSession::State::LoggingIn:
    case Gs2WebSocketSession::State::LoginFailed:
        // Gs2Session としては Available になっていないので closeCallback ではなく openCallback に失敗を伝える
        m_Gs2WebSocketSession.openCallback(nullptr, &m_Gs2WebSocketSession.m_LastGs2ClientException);
        break;

    case Gs2WebSocketSession::State::Available:
        // 自発的な切断も外部要因による切断もここ
        Gs2ClientException gs2ClientException;
        gs2ClientException.setType(Gs2ClientException::SessionNotOpenException);  // TODO
        m_Gs2WebSocketSession.closeCallback(gs2ClientException);
        break;
    }
}

void Gs2WebSocketSession::WebSocket::onError(gs2::Gs2ClientException& gs2ClientException)
{
    switch (m_Gs2WebSocketSession.m_State)
    {
    case Gs2WebSocketSession::State::Idle:   // 来ない
        break;

    case Gs2WebSocketSession::State::Opening:
        // この直後に onClose() が呼ばれる
        m_Gs2WebSocketSession.m_LastGs2ClientException = std::move(gs2ClientException);
        break;

    case Gs2WebSocketSession::State::LoggingIn:
        m_Gs2WebSocketSession.m_LastGs2ClientException = std::move(gs2ClientException);
        m_Gs2WebSocketSession.m_State = Gs2WebSocketSession::State::LoginFailed;
        close();
        break;

    case Gs2WebSocketSession::State::LoginFailed:
        // 来ないはず
        break;

    case Gs2WebSocketSession::State::Available:
        // 実行中のタスクのどれが失敗したのかわからないので、全部失敗にする
        m_Gs2WebSocketSession.cancelTasksCallback(gs2ClientException);
        break;
    }
}

void Gs2WebSocketSession::setOnNotificationMessage(NotificationMessageCallbackType callback)
{
    m_OnNotificationMessage = callback;
}

void Gs2WebSocketSession::openImpl()
{
    assert(m_State == State::Idle);

    m_State = State::Opening;   // Idle のあいだにコールバックは来ないので、別スレッドから状態変更できる

    if (!m_WebSocket.open(EndpointHost))
    {
        Gs2ClientException gs2ClientException;
        gs2ClientException.setType(Gs2ClientException::Type::SessionNotOpenException);  // TODO
        openCallback(nullptr, &gs2ClientException, true);
    }
}

void Gs2WebSocketSession::cancelOpenImpl()
{
    m_WebSocket.close();
}

void Gs2WebSocketSession::closeImpl()
{
    // コールバックスレッド以外からのステート変更は排他を保証できない
    // （Gs2Session と独立してロックを用意するとデッドロックしうる）ので、
    // ステートは変化させない

    m_WebSocket.close();
}

GS2_END_OF_NAMESPACE
