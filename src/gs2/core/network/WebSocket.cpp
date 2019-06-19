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

#include "WebSocket.hpp"
#include "Gs2WebSocketResponse.hpp"
#include "../exception/Gs2ClientException.hpp"
#include "../json/IModel.hpp"
#include "../json/JsonParser.hpp"
#include "../model/IGs2Credential.hpp"
#include "RootCaCertificates.hpp"
#include <platform/CCFileUtils.h>
#include <cstdlib>
#include <limits>
//#include <base/CCDirector.h>
//#include <base/CCScheduler.h>

GS2_START_OF_NAMESPACE

namespace detail {

void WebSocket::Delegate::onOpen(cocos2d::network::WebSocket* pWebSocket)
{
    GS2_NOT_USED(pWebSocket);
    m_WebSocket.onOpen();
}

void WebSocket::Delegate::onMessage(cocos2d::network::WebSocket* pWebSocket, const cocos2d::network::WebSocket::Data& data)
{
    GS2_NOT_USED(pWebSocket);
    m_WebSocket.onMessage(data);
}

void WebSocket::Delegate::onClose(cocos2d::network::WebSocket* pWebSocket)
{
    GS2_NOT_USED(pWebSocket);
    m_WebSocket.onClose();
}

void WebSocket::Delegate::onError(cocos2d::network::WebSocket* pWebSocket, const cocos2d::network::WebSocket::ErrorCode& errorCode)
{
    GS2_NOT_USED(pWebSocket);
    m_WebSocket.onError(errorCode);
}

WebSocket::WebSocket() :
    m_Delegate(*this)
{
    // ping を定期的に送信する
//    cocos2d::Director::getInstance()->getScheduler()->schedule(
//        [this](float time) {
//            detail2::PingRequest pingRequest;
//            this->send(pingRequest);
//            // CCLOG("PingRequest sent.");
//        },
//        this, static_cast<float>(KeepAliveIntervalInSeconds), true, KeepAliveFunctionIdentifier
//    );
}

WebSocket::~WebSocket()
{
//    cocos2d::Director::getInstance()->getScheduler()->unschedule(KeepAliveFunctionIdentifier, this);
    // TODO: close をきちんと待つ
}

bool WebSocket::open()
{
    m_WebSocket.emplace();

    auto path = std::move(cocos2d::FileUtils::getInstance()->getWritablePath() + "root-ca");

    if (cocos2d::FileUtils::getInstance()->isFileExist(path))
    {
        return m_WebSocket->init(m_Delegate, "wss://gateway-ws.ap-northeast-1.gen2.gs2io.com", nullptr, path);
    }
    else
    {
        cocos2d::Data data;
        data.copy(reinterpret_cast<const unsigned char*>(RootCaCertificates), SizeOfRootCaCertificates - 1);
        cocos2d::FileUtils::getInstance()->writeDataToFile(
            std::move(data),
            path,
            [this](bool isSuccessful) {
                this->writeRootCaCertificatesCallback(isSuccessful);
            }
        );

        return true;
    }
}

void WebSocket::writeRootCaCertificatesCallback(bool isSuccessful)
{
    if (isSuccessful)
    {
        auto path = std::move(cocos2d::FileUtils::getInstance()->getWritablePath() + "root-ca");
        isSuccessful = m_WebSocket->init(m_Delegate, "wss://gateway-ws.ap-northeast-1.gen2.gs2io.com", nullptr, path);
    }

    if (!isSuccessful)
    {
        onError(cocos2d::network::WebSocket::ErrorCode::CONNECTION_FAILURE);    // TODO?
        onClose();
    }
}

void WebSocket::close()
{
    m_WebSocket->closeAsync();
}

void WebSocket::send(const gs2::Char message[])
{
    m_WebSocket->send(message);
}

void Gs2WebSocket::onMessage(const cocos2d::network::WebSocket::Data& data)
{
    if (data.isBinary)
    {
        // バイナリメッセージは非対応
    }
    else
    {
        Gs2WebSocketResponse gs2WebSocketResponse(data.bytes);
        onMessage(gs2WebSocketResponse);
    }
}

void Gs2WebSocket::onError(const cocos2d::network::WebSocket::ErrorCode& errorCode)
{
    // TODO
    GS2_NOT_USED(errorCode);

    Gs2ClientException::Type type;
    switch (errorCode)  // TODO
    {
    case cocos2d::network::WebSocket::ErrorCode::CONNECTION_FAILURE:
    case cocos2d::network::WebSocket::ErrorCode::TIME_OUT:
    case cocos2d::network::WebSocket::ErrorCode::UNKNOWN:
        type = Gs2ClientException::UnknownException;
        break;
    }

    Gs2ClientException gs2ClientException;
    gs2ClientException.setType(type);
    onError(gs2ClientException);
}

}

GS2_END_OF_NAMESPACE
