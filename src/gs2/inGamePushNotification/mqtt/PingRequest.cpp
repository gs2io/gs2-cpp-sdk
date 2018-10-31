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

#include "PingRequest.hpp"
#include "MessageBufferProxy.hpp"
#include "MqttTypes.hpp"

GS2_IN_GAME_PUSH_NOTIFICATION_START_OF_NAMESPACE
namespace detail2 {

namespace {
const char MqttProtocolIdentifier[] = {'M', 'Q', 'I', 's', 'd', 'p'};
}

PingRequest::PingRequest()
{
}

UInt32 PingRequest::getRemainingMessageLength() const {
    return 0;
}

void PingRequest::dump(MessageBufferProxy &messageBufferProxy) const {
    messageBufferProxy.writeU8(static_cast<UInt8>(MessageType::PINGREQ) << 4);
    messageBufferProxy.writeMbi(getRemainingMessageLength());
}

}
GS2_IN_GAME_PUSH_NOTIFICATION_END_OF_NAMESPACE
