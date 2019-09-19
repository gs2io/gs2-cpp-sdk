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

#ifndef GS2_CORE_NETWORK_GS2WEBSOCKETSESSION_HPP_
#define GS2_CORE_NETWORK_GS2WEBSOCKETSESSION_HPP_

#include "Gs2Session.hpp"
#include "WebSocket.hpp"
#include "Gs2WebSocketSessionTask.hpp"

GS2_START_OF_NAMESPACE

class Gs2WebSocketSession : public Gs2Session
{
    friend class detail::Gs2WebSocketSessionTaskBase;

private:
    static const detail::Gs2SessionTaskId::ValueType LoginTaskIdValue = 1U;

    enum class State {
        Idle,
        Opening,
        LoggingIn,
        LoginFailed,
        Available,
    };

    class WebSocket : public detail::Gs2WebSocket
    {
    private:
        Gs2WebSocketSession& m_Gs2WebSocketSession;

        void onOpen() GS2_OVERRIDE;
        void onMessage(detail::Gs2WebSocketResponse& gs2WebSocketResponse) GS2_OVERRIDE;
        void onClose() GS2_OVERRIDE;
        void onError(Gs2ClientException& gs2ClientException) GS2_OVERRIDE;

    public:
        explicit WebSocket(Gs2WebSocketSession& gs2WebSocketSession) :
            m_Gs2WebSocketSession(gs2WebSocketSession)
        {}

        ~WebSocket() GS2_OVERRIDE = default;
    };

private:
    State m_State;

    WebSocket m_WebSocket;
    Gs2ClientException m_LastGs2ClientException;

    NotificationMessageCallbackType m_OnNotificationMessage;

    void send(const Char message[])
    {
        m_WebSocket.send(message);
    }

public:
    explicit Gs2WebSocketSession(BasicGs2Credential gs2Credential) :
        Gs2Session(gs2Credential),
        m_State(State::Idle),
        m_WebSocket(*this)
    {}

    Gs2WebSocketSession(BasicGs2Credential gs2Credential, Region region) :
        Gs2Session(gs2Credential, region),
        m_State(State::Idle),
        m_WebSocket(*this)
    {}

    Gs2WebSocketSession(BasicGs2Credential gs2Credential, const Char region[]) :
        Gs2Session(gs2Credential, region),
        m_State(State::Idle),
        m_WebSocket(*this)
    {}

    ~Gs2WebSocketSession() GS2_OVERRIDE = default;

    void setOnNotificationMessage(NotificationMessageCallbackType callback);

    void execute(detail::Gs2WebSocketSessionTaskBase& gs2WebSocketSessionTask)
    {
        Gs2Session::execute(gs2WebSocketSessionTask);
    }

private:
    void openImpl() GS2_OVERRIDE;
    void cancelOpenImpl() GS2_OVERRIDE;
    void closeImpl() GS2_OVERRIDE;
};

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_NETWORK_GS2WEBSOCKETSESSION_HPP_
