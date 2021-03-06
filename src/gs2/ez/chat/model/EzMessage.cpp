/*
 * Copyright 2016 Game Server Services, Inc. or its affiliates. All Rights
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

#include "EzMessage.hpp"
#include <gs2/chat/model/Message.hpp>


namespace gs2 { namespace ez { namespace chat {

EzMessage::Data::Data(const Data& data) :
    Gs2Object(data),
    roomName(data.roomName),
    userId(data.userId),
    category(data.category),
    metadata(data.metadata),
    createdAt(data.createdAt)
{
}

EzMessage::Data::Data(const gs2::chat::Message& message) :
    roomName(message.getRoomName()),
    userId(message.getUserId()),
    category(message.getCategory() ? *message.getCategory() : 0),
    metadata(message.getMetadata()),
    createdAt(message.getCreatedAt() ? *message.getCreatedAt() : 0)
{
}

EzMessage::EzMessage(gs2::chat::Message message) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(message)
{
}

EzMessage EzMessage::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzMessage);
}

gs2::chat::Message EzMessage::ToModel() const
{
    gs2::chat::Message message;
    message.setRoomName(getRoomName());
    message.setUserId(getUserId());
    message.setCategory(getCategory());
    message.setMetadata(getMetadata());
    message.setCreatedAt(getCreatedAt());
    return message;
}

}}}