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

#ifndef GS2_CORE_NETWORK_WEBSOCKET_HPP_
#define GS2_CORE_NETWORK_WEBSOCKET_HPP_

#include "../Gs2Object.hpp"
#include "../external/optional/optional.hpp"
#include "../util/StringHolder.hpp"
#include "Gs2SessionTaskId.hpp"
#include <network/WebSocket.h>
#include <mutex>

GS2_START_OF_NAMESPACE

class Gs2ClientException;

namespace detail {

class Gs2WebSocketResponse;

class WebSocket : public Gs2Object
{
private:
    enum class State
    {
        Idle,
        WritingFile,
        Opening,
        Cancelling,
        Available,
    };

    class Delegate : public cocos2d::network::WebSocket::Delegate
    {
    private:
        WebSocket& m_WebSocket;

        void onOpen(cocos2d::network::WebSocket* pWebSocket) GS2_OVERRIDE;
        void onMessage(cocos2d::network::WebSocket* pWebSocket, const cocos2d::network::WebSocket::Data& data) GS2_OVERRIDE;
        void onClose(cocos2d::network::WebSocket* pWebSocket) GS2_OVERRIDE;
        void onError(cocos2d::network::WebSocket* pWebSocket, const cocos2d::network::WebSocket::ErrorCode& errorCode) GS2_OVERRIDE;

    public:
        explicit Delegate(WebSocket& webSocket) :
            m_WebSocket(webSocket)
        {}

        ~Delegate() GS2_OVERRIDE = default;
    };

private:
    std::mutex m_Mutex;

    State m_State;

    StringHolder m_Url;

    optional<cocos2d::network::WebSocket> m_WebSocket;
    Delegate m_Delegate;

    void writeRootCaCertificatesCallback(bool isSuccessful);

    virtual void onOpen() = 0;
    virtual void onMessage(const cocos2d::network::WebSocket::Data& data) = 0;
    virtual void onClose() = 0;
    virtual void onError(const cocos2d::network::WebSocket::ErrorCode& errorCode) = 0;

public:
    WebSocket();
    virtual ~WebSocket();

    bool open(StringHolder url);

    void close();

    void send(const Char message[]);
};


class Gs2WebSocket : public WebSocket
{
private:
    void onMessage(const cocos2d::network::WebSocket::Data& data) GS2_OVERRIDE;
    void onError(const cocos2d::network::WebSocket::ErrorCode& errorCode) GS2_OVERRIDE;

    virtual void onMessage(Gs2WebSocketResponse& gs2WebSocketResponse) = 0;
    virtual void onError(Gs2ClientException& gs2ClientException) = 0;

public:
    Gs2WebSocket() = default;
    ~Gs2WebSocket() GS2_OVERRIDE = default;
};

}

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_NETWORK_WEBSOCKET_HPP_
