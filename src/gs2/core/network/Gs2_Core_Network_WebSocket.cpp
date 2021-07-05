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

#include "../exception/Gs2ClientException.hpp"
#include "Gs2WebSocketResponse.hpp"
#include "WebSocket.hpp"
#include <Modules/ModuleManager.h>
#include <WebSocketsModule.h>
#include <IWebSocket.h>

GS2_START_OF_NAMESPACE

namespace detail {

Gs2WebSocket::Gs2WebSocket()
{
}

Gs2WebSocket::~Gs2WebSocket()
{
    if (m_pWebSocket)
    {
        m_pWebSocket->OnConnected().Clear();
        m_pWebSocket->OnConnectionError().Clear();
        m_pWebSocket->OnMessage().Clear();
        m_pWebSocket->OnClosed().Clear();
    }
}

bool Gs2WebSocket::open(const char url[])
{
    auto websocketModule =
        FModuleManager::Get().IsModuleLoaded(TEXT("WebSockets")) ?
        FWebSocketsModule::Get() :
        FModuleManager::LoadModuleChecked<FWebSocketsModule>(TEXT("WebSockets"));

    m_pWebSocket = websocketModule.CreateWebSocket(url);

    m_pWebSocket->OnConnected().AddRaw(this, &Gs2WebSocket::onConnectComplete);
    m_pWebSocket->OnConnectionError().AddRaw(this, &Gs2WebSocket::onConnectError);
    m_pWebSocket->OnMessage().AddRaw(this, &Gs2WebSocket::onReceiveData);
    m_pWebSocket->OnClosed().AddRaw(this, &Gs2WebSocket::onClosed);

    m_pWebSocket->Connect();
    return true;
}

void Gs2WebSocket::close()
{
    m_pWebSocket->Close();
}

void Gs2WebSocket::send(const gs2::Char message[])
{
    m_pWebSocket->Send(message);
}

void Gs2WebSocket::onConnectComplete()
{
    onOpen();
}

void Gs2WebSocket::onConnectError(const FString& error)
{
    GS2_NOT_USED(error);
    Gs2ClientException gs2ClientException;
    gs2ClientException.setType(Gs2ClientException::Type::SessionNotOpenException);
    onError(gs2ClientException);
    onClose();
}

void Gs2WebSocket::onReceiveData(const FString& data)
{
    std::string response = TCHAR_TO_UTF8(*data);
    Gs2WebSocketResponse gs2WebSocketResponse(response.c_str());
    onMessage(gs2WebSocketResponse);
}

void Gs2WebSocket::onClosed(int32 i, const FString& str, bool b)
{
    onClose();
}

}

GS2_END_OF_NAMESPACE
