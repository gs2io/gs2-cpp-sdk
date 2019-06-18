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

void Gs2WebSocketSession::WebSocket::onOpen()
{
    // TODO: キャンセル対応
    assert(m_Gs2WebSocketSession.m_State == State::Opening);

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

    m_Gs2WebSocketSession.m_State = State::LoggingIn;

    send(loginMessageBuffer);
}

void Gs2WebSocketSession::WebSocket::onMessage(detail::Gs2WebSocketResponse& gs2WebSocketResponse)
{
    switch (m_Gs2WebSocketSession.m_State)
    {
    case State::Idle:
    case State::Opening:
        // 来ない
        break;

    case State::LoggingIn:
        if (gs2WebSocketResponse.getGs2SessionTaskId() == LoginTaskIdValue)
        {
            if (gs2WebSocketResponse.getGs2ClientException())
            {
                m_Gs2WebSocketSession.m_LastGs2ClientException = std::move(*gs2WebSocketResponse.getGs2ClientException());
                m_Gs2WebSocketSession.m_State = State::LoginFailed;
                close();
            }
            else
            {
                detail::LoginResultModel loginResultModel;
                gs2WebSocketResponse.exportTo(loginResultModel);

                if (loginResultModel.accessToken)   // パース成功
                {
                    m_Gs2WebSocketSession.m_State = State::Available;
                    m_Gs2WebSocketSession.connectCallback(&*loginResultModel.accessToken, nullptr);
                }
                else
                {
                    // 「正常に」エラー応答がパースされた場合もこちら
                    Gs2ClientException gs2ClientException;
                    gs2ClientException.setType(Gs2ClientException::UnknownException);   // TODO
                    m_Gs2WebSocketSession.m_LastGs2ClientException = std::move(gs2ClientException);
                    m_Gs2WebSocketSession.m_State = State::LoginFailed;
                    close();
                }
            }
        }
        else
        {
            // ここでメッセージは届かないはずだけど、届いたらエラーにする？
        }
        break;

    case State::LoginFailed:
        // ここでメッセージは届かないはず
        break;

    case State::Available:
        if (gs2WebSocketResponse.getGs2SessionTaskId() == detail::Gs2SessionTaskId::InvalidIdValue)
        {
            // API 応答以外のメッセージ
        }
        else
        {
            auto* pGs2SessionTask = m_Gs2WebSocketSession.findGs2SessionTask(gs2WebSocketResponse.getGs2SessionTaskId());
            if (pGs2SessionTask != nullptr)
            {
                // API 応答
                pGs2SessionTask->callback(gs2WebSocketResponse);
            }
            else
            {
                // このようなメッセージは届かないはず
            }
        }
        break;
    }
}

void Gs2WebSocketSession::WebSocket::onClose()
{
    auto state = m_Gs2WebSocketSession.m_State;

    m_Gs2WebSocketSession.m_State = State::Idle;

    switch (state)
    {
    case State::Idle:
        // 来ない
        break;

    case State::Opening:
    case State::LoggingIn:
    case State::LoginFailed:
        // Gs2Session としては Connected になっていないので disconnectCallback ではなく connectCallback に失敗を伝える
        m_Gs2WebSocketSession.connectCallback(nullptr, &m_Gs2WebSocketSession.m_LastGs2ClientException);
        break;

    case State::Available:
        // 自発的な切断も外部要因による切断もここ
        Gs2ClientException gs2ClientException;
        gs2ClientException.setType(Gs2ClientException::UnknownException);  // TODO
        m_Gs2WebSocketSession.disconnectCallback(gs2ClientException, false);
        break;
    }
}

void Gs2WebSocketSession::WebSocket::onError(gs2::Gs2ClientException& gs2ClientException)
{
    switch (m_Gs2WebSocketSession.m_State)
    {
    case State::Idle:   // 来ない
        break;

    case State::Opening:
        // この直後に onClose() が呼ばれる
        m_Gs2WebSocketSession.m_LastGs2ClientException = std::move(gs2ClientException);
        break;

    case State::LoggingIn:
        m_Gs2WebSocketSession.m_LastGs2ClientException = std::move(gs2ClientException);
        m_Gs2WebSocketSession.m_State = State::LoginFailed;
        close();
        break;

    case State::LoginFailed:
        // 来ないはず
        break;

    case State::Available:
        // 実行中のタスクのどれが失敗したのかわからないので、全部失敗にする
        m_Gs2WebSocketSession.cancelTasksCallback(gs2ClientException);
        break;
    }
}

void Gs2WebSocketSession::connectImpl()
{
    assert(m_State == State::Idle);

    m_State = State::Opening;   // Idle のあいだにコールバックは来ないので、別スレッドから状態変更できる

    m_WebSocket.open();
}

void Gs2WebSocketSession::cancelConnectImpl()
{
    m_WebSocket.close();
}

bool Gs2WebSocketSession::disconnectImpl()
{
    // コールバックスレッド以外からのステート変更は排他を保証できない
    // （Gs2Session と独立してロックを用意するとデッドロックしうる）ので、
    // ステートは変化させない

    m_WebSocket.close();

    return false;
}

GS2_END_OF_NAMESPACE
