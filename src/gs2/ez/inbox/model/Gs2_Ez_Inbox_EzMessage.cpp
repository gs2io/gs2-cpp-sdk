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
#include <gs2/inbox/model/Message.hpp>


namespace gs2 { namespace ez { namespace inbox {

EzMessage::Data::Data(const Data& data) :
    Gs2Object(data),
    messageId(data.messageId),
    name(data.name),
    metadata(data.metadata),
    isRead(data.isRead),
    receivedAt(data.receivedAt),
    readAt(data.readAt),
    expiresAt(data.expiresAt)
{
    readAcquireActions = data.readAcquireActions.deepCopy();
}

EzMessage::Data::Data(const gs2::inbox::Message& message) :
    messageId(message.getMessageId() ? *message.getMessageId() : StringHolder()),
    name(message.getName() ? *message.getName() : StringHolder()),
    metadata(message.getMetadata() ? *message.getMetadata() : StringHolder()),
    isRead(message.getIsRead() ? *message.getIsRead() : false),
    receivedAt(message.getReceivedAt() ? *message.getReceivedAt() : 0),
    readAt(message.getReadAt() ? *message.getReadAt() : 0),
    expiresAt(message.getExpiresAt() ? *message.getExpiresAt() : 0)
{
    if (message.getReadAcquireActions())
    {
        for (int i = 0; i < message.getReadAcquireActions()->getCount(); ++i)
        {
            readAcquireActions += EzAcquireAction((*message.getReadAcquireActions())[i]);
        }
    }
}

EzMessage::Data::Data(const gs2::optional<gs2::inbox::Message>& message) :
    messageId(message && message->getMessageId() ? *message->getMessageId() : StringHolder()),
    name(message && message->getName() ? *message->getName() : StringHolder()),
    metadata(message && message->getMetadata() ? *message->getMetadata() : StringHolder()),
    isRead(message && message->getIsRead() ? *message->getIsRead() : false),
    receivedAt(message && message->getReceivedAt() ? *message->getReceivedAt() : 0),
    readAt(message && message->getReadAt() ? *message->getReadAt() : 0),
    expiresAt(message && message->getExpiresAt() ? *message->getExpiresAt() : 0)
{
    if (message && message->getReadAcquireActions())
    {
        for (int i = 0; i < message->getReadAcquireActions()->getCount(); ++i)
        {
            readAcquireActions += EzAcquireAction((*message->getReadAcquireActions())[i]);
        }
    }
}

EzMessage::EzMessage(gs2::inbox::Message message) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(message)
{
}

EzMessage::EzMessage(gs2::optional<gs2::inbox::Message> message) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(message)
{
}

EzMessage EzMessage::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzMessage);
}

gs2::inbox::Message EzMessage::ToModel() const
{
    gs2::inbox::Message message;
    message.setMessageId(getMessageId());
    message.setName(getName());
    message.setMetadata(getMetadata());
    message.setIsRead(getIsRead());
    {
        gs2::List<gs2::inbox::AcquireAction> list;
        auto& readAcquireActions = getReadAcquireActions();
        for (int i = 0; i < readAcquireActions.getCount(); ++i)
        {
            list += readAcquireActions[i].ToModel();
        }
        message.setReadAcquireActions(list);
    }
    message.setReceivedAt(getReceivedAt());
    message.setReadAt(getReadAt());
    message.setExpiresAt(getExpiresAt());
    return message;
}

}}}