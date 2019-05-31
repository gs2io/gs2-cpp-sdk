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

#include "ConnectRequest.hpp"
#include "MessageBufferProxy.hpp"
#include "MqttTypes.hpp"

GS2_IN_GAME_PUSH_NOTIFICATION_START_OF_NAMESPACE
namespace detail2 {

namespace {
const char MqttProtocolIdentifier[] = {'M', 'Q', 'I', 's', 'd', 'p'};
}

ConnectRequest::ConnectRequest()
        : m_IsCleanSession(true),
          m_pUserId(""),
          m_KeepAliveInterval(60)
{
}

UInt32 ConnectRequest::getRemainingMessageLength() const {
    UInt32 remainingMessageLength = 0;
    remainingMessageLength += sizeof(UInt16);         // protocol name length
    remainingMessageLength += sizeof(MqttProtocolIdentifier);   // protocol name
    remainingMessageLength += sizeof(UInt8);          // protocol version
    remainingMessageLength += sizeof(UInt8);          // connect flags
    remainingMessageLength += sizeof(UInt16);         // keep alive interval
    remainingMessageLength += sizeof(UInt16);         // user id length
    remainingMessageLength += std::strlen(m_pUserId);    // user id
    return remainingMessageLength;
}

void ConnectRequest::dump(MessageBufferProxy &messageBufferProxy) const {
    messageBufferProxy.writeU8(static_cast<UInt8>(MessageType::CONNECT) << 4);
    messageBufferProxy.writeMbi(getRemainingMessageLength());
    messageBufferProxy.writeU16(sizeof(MqttProtocolIdentifier));
    messageBufferProxy.writeBinary(MqttProtocolIdentifier, sizeof(MqttProtocolIdentifier));
    messageBufferProxy.writeU8(3);  // protocol version
    messageBufferProxy.writeU8(m_IsCleanSession ? 0x02 : 0x00);
    messageBufferProxy.writeU16(m_KeepAliveInterval);
    auto userIdLength = std::strlen(m_pUserId);
    messageBufferProxy.writeU16(userIdLength);
    messageBufferProxy.writeBinary(m_pUserId, userIdLength);
}

}
GS2_IN_GAME_PUSH_NOTIFICATION_END_OF_NAMESPACE
