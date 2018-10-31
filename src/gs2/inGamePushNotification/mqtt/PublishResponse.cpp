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

#include "PublishResponse.hpp"
#include "MessageBufferProxy.hpp"

GS2_IN_GAME_PUSH_NOTIFICATION_START_OF_NAMESPACE
namespace detail2 {

PublishResponse::PublishResponse(void *message, UInt32 size) {
    MessageBufferProxy messageBufferProxy(message, size);
    messageBufferProxy.readU8();     // message type | message info
    auto messageLength = messageBufferProxy.readMbi();
    auto topicNameLength = messageBufferProxy.readU16();
    messageBufferProxy.skip(topicNameLength);    // topic name
    m_Payload = messageBufferProxy.getCurrent();
    m_PayloadSize = messageLength - 2 - topicNameLength;
}

}
GS2_IN_GAME_PUSH_NOTIFICATION_END_OF_NAMESPACE
