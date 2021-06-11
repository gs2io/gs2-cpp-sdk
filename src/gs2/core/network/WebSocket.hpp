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

class IWebSocket;
class FString;

GS2_START_OF_NAMESPACE

class Gs2ClientException;

namespace detail {

class Gs2WebSocketResponse;

class Gs2WebSocket : public Gs2Object
{
private:
    TSharedRef<IWebSocket> m_pWebSocket;

    void onConnectError(const FString& error);
    void onClosed(int32 i, const FString& str, bool b);
    void onConnectComplete();
    void onReceiveData(const FString& data);

private:
    virtual void onOpen() = 0;
    virtual void onMessage(Gs2WebSocketResponse& gs2WebSocketResponse) = 0;
    virtual void onClose() = 0;
    virtual void onError(Gs2ClientException& gs2ClientException) = 0;

public:
    Gs2WebSocket();
    virtual ~Gs2WebSocket();

    bool open();

    void close();

    void send(const Char message[]);
};

}

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_NETWORK_WEBSOCKET_HPP_
