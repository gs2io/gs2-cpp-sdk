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
#include "WebSocketBlueprintLibrary.h"
#include "WebSocketBase.h"
#include "WebSocketDelegateAdaptor.h"

GS2_START_OF_NAMESPACE

namespace {

// Gs2WebSocket::Gs2WebSocket() の初期化子で渡すためのもの。
// 失敗するのはわかっているので値を参照することはない。
bool isConnectFailed;

}

namespace detail {

Gs2WebSocket::Gs2WebSocket() :
    m_pWebSocketBase(UWebSocketBlueprintLibrary::Connect("", isConnectFailed)),
    m_pWebSocketDelegateAdaptor(NewObject<UWebSocketDelegateAdaptor>())
{
    m_pWebSocketBase->AddToRoot();
    m_pWebSocketDelegateAdaptor->AddToRoot();

    m_pWebSocketDelegateAdaptor->OnConnectCompleteStatic.AddRaw(this, &Gs2WebSocket::onConnectComplete);
    m_pWebSocketDelegateAdaptor->OnConnectErrorStatic.AddRaw(this, &Gs2WebSocket::onConnectError);
    m_pWebSocketDelegateAdaptor->OnReceiveDataStatic.AddRaw(this, &Gs2WebSocket::onReceiveData);
    m_pWebSocketDelegateAdaptor->OnClosedStatic.AddRaw(this, &Gs2WebSocket::onClosed);

    m_pWebSocketDelegateAdaptor->AddTo(*m_pWebSocketBase);
}

Gs2WebSocket::~Gs2WebSocket()
{
    m_pWebSocketDelegateAdaptor->RemoveFrom(*m_pWebSocketBase);
    m_pWebSocketDelegateAdaptor->RemoveFromRoot();
    m_pWebSocketBase->RemoveFromRoot();
}

bool Gs2WebSocket::open()
{
    return m_pWebSocketBase->Connect("wss://gateway-ws.ap-northeast-1.gen2.gs2io.com", TMap<FString, FString>());
}

void Gs2WebSocket::close()
{
    m_pWebSocketBase->Close();
}

void Gs2WebSocket::send(const gs2::Char message[])
{
    m_pWebSocketBase->SendText(message);
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

void Gs2WebSocket::onClosed()
{
    onClose();
}

}

GS2_END_OF_NAMESPACE
