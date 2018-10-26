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

#include "MqttClient.hpp"
#include "MessageBufferProxy.hpp"
#include "MqttTypes.hpp"
#include "AbstractRequest.hpp"
#include "ConnectRequest.hpp"
#include "SubscribeRequest.hpp"
#include "ConnectResponse.hpp"
#include "PublishResponse.hpp"
#include "PingRequest.hpp"
#include <gs2/core/util/StringVariable.hpp>
#include <base/CCDirector.h>
#include <base/CCScheduler.h>
#include <platform/CCFileUtils.h>

GS2_IN_GAME_PUSH_NOTIFICATION_START_OF_NAMESPACE

namespace {

const char KeepAliveFunctionIdentifier[] = "gs2::mqtt::MqttClient::sendKeepAliveRequest()";

}

void MqttClient::Delegate::onOpen(cocos2d::network::WebSocket* pWebSocket)
{
    CCLOG("Delegate onOpen");

    detail2::ConnectRequest connectRequest;
    connectRequest
        .withUserId(m_MqttClient.m_UserId)
        .withKeepAliveInterval(static_cast<UInt16>(KeepAliveIntervalInSeconds));
    m_MqttClient.send(connectRequest);
}

void MqttClient::Delegate::onMessage(cocos2d::network::WebSocket* pWebSocket, const cocos2d::network::WebSocket::Data& data)
{
    CCLOG("Delegate onMessage (%i)", data.len);

//    if (e.IsPing)
//    {
//
//    }
//    else

    detail2::MessageBufferProxy messageBufferProxy(data.bytes, data.len);
    auto byte0 = messageBufferProxy.readU8();
    auto messageLength = messageBufferProxy.readMbi();

    if (messageLength > messageBufferProxy.getRemainingSize())
    {
        // TODO: return error
    }

    auto messageType = static_cast<detail2::MessageType>((byte0 >> 4) & 0x0f);
    CCLOG("MQTT Response: %i", messageType);

    switch (messageType)
    {
        case detail2::MessageType::CONNACK:
            {
                CCLOG("MQTT Response: CONNACK");
                detail2::ConnectResponse connectResponse(data.bytes, data.len);
                if (connectResponse.getReturnCode() != 0)
                {
                    // TODO: m_MqttClient.onError.invoke();
                    CCLOG("  Return Code: %i", connectResponse.getReturnCode());
                }
                else
                {
                    // TODO: m_MqttClient.m_Host.getGameId().has_value()
                    detail::StringVariable topic(*m_MqttClient.m_WebSocketHost.getGameId());
                    topic.append("/users/");
                    topic.append(m_MqttClient.m_UserId);
                    const char* topics[1] = {topic.c_str()};    // TODO: OK?
                    CCLOG("topic: %s", topics[0]);
                    detail2::SubscribeRequest subscribeRequest;
                    subscribeRequest.withTopics(topics, GS2_COUNT_OF(topics));
                    m_MqttClient.send(subscribeRequest);
                    CCLOG("SubscribeRequest sent.");
                }
            }
            break;

        case detail2::MessageType::SUBACK:
            CCLOG("MQTT Response: SUBACK");
            cocos2d::Director::getInstance()->getScheduler()->resumeTarget(&m_MqttClient);
            m_MqttClient.onConnect.invoke();
            break;

        case detail2::MessageType::PUBLISH:
            {
                CCLOG("MQTT Response: PUBLISH");
                detail2::PublishResponse publishResponse(data.bytes, data.len);
                // '\0' 終端を追加してからコールバックに渡す
                auto payloadSize = publishResponse.getPayloadSize();
                Char* payload = reinterpret_cast<Char*>(Gs2Object::getAllocator().malloc(payloadSize + 1));
                std::memcpy(payload, publishResponse.getPayload(), payloadSize);
                payload[payloadSize] = '\0';
                m_MqttClient.onReceive.invoke(payload);
            }
            break;

        default:
            break;
    }
}

void MqttClient::Delegate::onClose(cocos2d::network::WebSocket* pWebSocket)
{
    CCLOG("Delegate onClose");

    cocos2d::Director::getInstance()->getScheduler()->pauseTarget(&m_MqttClient);
    m_MqttClient.onClose.invoke();
}

void MqttClient::Delegate::onError(cocos2d::network::WebSocket* pWebSocket, const cocos2d::network::WebSocket::ErrorCode& errorCode)
{
    CCLOG("Delegate onError: %i", errorCode);

    m_MqttClient.onError.invoke(errorCode);
}

MqttClient::MqttClient() :
    m_Delegate(*this),
    m_UserId("")
{
    cocos2d::Director::getInstance()->getScheduler()->schedule(
        [this](float time) {
            detail2::PingRequest pingRequest;
            this->send(pingRequest);
            CCLOG("PingRequest sent.");
        },
        this, static_cast<float>(KeepAliveIntervalInSeconds), true, KeepAliveFunctionIdentifier
    );
}

MqttClient::~MqttClient()
{
    cocos2d::Director::getInstance()->getScheduler()->unschedule(KeepAliveFunctionIdentifier, this);
}

void MqttClient::send(const detail2::AbstractRequest &request)
{
    auto size = request.getMessageLength();
    void* buffer = Gs2Object::getAllocator().malloc(size);
    detail2::MessageBufferProxy messageBufferProxy(buffer, size);
    request.dump(messageBufferProxy);
    m_WebSocket.send(reinterpret_cast<const unsigned char*>(buffer), size);
    Gs2Object::getAllocator().free(buffer);
}

void MqttClient::writeRootCaCallback(bool isSuccessful)
{
    if (!isSuccessful)
    {
        onError.invoke(Error::UNKNOWN);
        return;
    }

    CCLOG("Root CA: %s", rootCertificateFilePath);
    CCLOG("Endpoint: %s", *host.getEndpoint());
    std::vector<std::string> protocols;
    protocols.push_back("mqtt");
    auto isInitialized = m_WebSocket.init(m_Delegate, m_WebSocketHost.getEndpoint()->getCString(), &protocols, m_RootCertificateFilePath);

    if (!isInitialized)
    {
        onError.invoke(Error::UNKNOWN);
        return;
    }
}

void MqttClient::connectAsync(const WebSocketHost& webSocketHost, const char userId[], const char rootCertificateFilePath[])
{
    auto webSocketHostCopy = webSocketHost;
    connectAsync(std::move(webSocketHostCopy), userId, rootCertificateFilePath);
}

void MqttClient::connectAsync(WebSocketHost&& webSocketHost, const char userId[], const char rootCertificateFilePath[])
{
    m_WebSocketHost = std::move(webSocketHost);
    m_UserId = userId;
    m_RootCertificateFilePath = rootCertificateFilePath == nullptr ?
        std::move(cocos2d::FileUtils::getInstance()->getWritablePath() + "root-ca") :
        rootCertificateFilePath;

    cocos2d::Data data;
    auto& rootCertificate = *m_WebSocketHost.getRootCertificate();
    data.copy(reinterpret_cast<const unsigned char*>(rootCertificate.getCString()), rootCertificate.getSize() - 1);
    cocos2d::FileUtils::getInstance()->writeDataToFile(
        std::move(data),
        m_RootCertificateFilePath,
        [this](bool isSuccessful) {
            this->writeRootCaCallback(isSuccessful);
        }
    );
}

void MqttClient::disconnectAsync()
{
    m_WebSocket.closeAsync();
}

GS2_IN_GAME_PUSH_NOTIFICATION_END_OF_NAMESPACE
