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

#include "SubscribeRequest.hpp"
#include "MqttTypes.hpp"

GS2_IN_GAME_PUSH_NOTIFICATION_START_OF_NAMESPACE
namespace detail2 {

SubscribeRequest::SubscribeRequest()
        : m_pTopics(nullptr),
          m_NumberOfTopics(0)
{
}

UInt32 SubscribeRequest::getRemainingMessageLength() const {
    UInt32 remainingMessageLength = 0;
    remainingMessageLength += sizeof(UInt16);         // message id
    for (UInt32 i = 0; i < m_NumberOfTopics; ++i) {
        remainingMessageLength += sizeof(UInt16);         // topic length
        remainingMessageLength += std::strlen(m_pTopics[i]); // topic
        remainingMessageLength += sizeof(UInt8);          // qos
    }
    return remainingMessageLength;
}

void SubscribeRequest::dump(MessageBufferProxy &messageBufferProxy) const {
    messageBufferProxy.writeU8((static_cast<UInt8>(MessageType::SUBSCRIBE) << 4) | 0x02);    // QoS 1
    messageBufferProxy.writeMbi(getRemainingMessageLength());
    messageBufferProxy.writeU16(1);     // TODO: [TORIAEZU] QoS 1 だけど再送処理を書いていないので Message ID は常に 1
    for (UInt32 i = 0; i < m_NumberOfTopics; ++i)
    {
        auto topicLength = std::strlen(m_pTopics[i]);
        messageBufferProxy.writeU16(topicLength);
        messageBufferProxy.writeBinary(m_pTopics[i], topicLength);
        messageBufferProxy.writeU8(0);  // request qos: 0
    }
}

}
GS2_IN_GAME_PUSH_NOTIFICATION_END_OF_NAMESPACE
