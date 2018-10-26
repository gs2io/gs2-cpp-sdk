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

#ifndef GS2_INGAMEPUSHNOTIFICATION_MQTT_MQTTCLIENT_HPP_
#define GS2_INGAMEPUSHNOTIFICATION_MQTT_MQTTCLIENT_HPP_

#include "../common.hpp"
#include <gs2/core/Gs2Object.hpp>
#include "EventHandler.hpp"
#include "../model/WebSocketHost.hpp"
#include <gs2/core/util/StringHolder.hpp>
#include <network/WebSocket.h>

GS2_IN_GAME_PUSH_NOTIFICATION_START_OF_NAMESPACE

namespace detail2 {
class AbstractRequest;
}

class MqttClient : public Gs2Object
{
public:
    typedef cocos2d::network::WebSocket::ErrorCode Error;

    RootEventHandler<ConnectEventHandler> onConnect;
    RootEventHandler<ReceiveEventHandler, const char[]> onReceive;
    RootEventHandler<CloseEventHandler> onClose;
    RootEventHandler<EventHandler<ErrorEventHandlerTraits, Error>, Error> onError;

private:
    static const int KeepAliveIntervalInSeconds = 180;

    cocos2d::network::WebSocket m_WebSocket;

    class Delegate : public cocos2d::network::WebSocket::Delegate {
    private:
        MqttClient& m_MqttClient;

    public:
        Delegate(MqttClient& mqttClient)
                : m_MqttClient(mqttClient)
        {
        }

        void onOpen(cocos2d::network::WebSocket* pWebSocket) GS2_OVERRIDE;
        void onMessage(cocos2d::network::WebSocket* pWebSocket, const cocos2d::network::WebSocket::Data& data) GS2_OVERRIDE;
        void onClose(cocos2d::network::WebSocket* pWebSocket) GS2_OVERRIDE;
        void onError(cocos2d::network::WebSocket* pWebSocket, const cocos2d::network::WebSocket::ErrorCode& errorCode) GS2_OVERRIDE;
    } m_Delegate;

    WebSocketHost m_WebSocketHost;
    StringHolder m_UserId;
    std::string m_RootCertificateFilePath;

    void send(const detail2::AbstractRequest& request);

    void writeRootCaCallback(bool isSuccessful);

public:
    MqttClient();

    ~MqttClient();

    void connectAsync(const WebSocketHost& webSocketHost, const char userId[], const char rootCertificateFilePath[] = nullptr);
    void connectAsync(WebSocketHost&& webSocketHost, const char userId[], const char rootCertificateFilePath[] = nullptr);

    void disconnectAsync();
};

GS2_IN_GAME_PUSH_NOTIFICATION_END_OF_NAMESPACE

#endif //GS2_INGAMEPUSHNOTIFICATION_MQTT_MQTTCLIENT_HPP_
