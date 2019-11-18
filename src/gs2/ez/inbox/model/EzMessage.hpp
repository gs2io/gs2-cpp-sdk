

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

#ifndef GS2_EZ_INBOX_MODEL_EZMESSAGE_HPP_
#define GS2_EZ_INBOX_MODEL_EZMESSAGE_HPP_

#include <gs2/inbox/model/Message.hpp>
#include "EzAcquireAction.hpp"


namespace gs2 { namespace ez { namespace inbox {

class EzMessage : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** メッセージ */
        gs2::optional<StringHolder> messageId;
        /** メッセージID */
        gs2::optional<StringHolder> name;
        /** メッセージの内容に相当するメタデータ */
        gs2::optional<StringHolder> metadata;
        /** 既読状態 */
        gs2::optional<Bool> isRead;
        /** 開封時に実行する入手アクション */
        gs2::optional<List<EzAcquireAction>> readAcquireActions;
        /** 作成日時 */
        gs2::optional<Int64> receivedAt;
        /** 最終更新日時 */
        gs2::optional<Int64> readAt;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            messageId(data.messageId),
            name(data.name),
            metadata(data.metadata),
            isRead(data.isRead),
            receivedAt(data.receivedAt),
            readAt(data.readAt)
        {
            if (data.readAcquireActions)
            {
                readAcquireActions = data.readAcquireActions->deepCopy();
            }
        }

        Data(Data&& data) = default;

        Data(const gs2::inbox::Message& message) :
            messageId(message.getMessageId()),
            name(message.getName()),
            metadata(message.getMetadata()),
            isRead(message.getIsRead() ? *message.getIsRead() : false),
            receivedAt(message.getReceivedAt() ? *message.getReceivedAt() : 0),
            readAt(message.getReadAt() ? *message.getReadAt() : 0)
        {
            readAcquireActions.emplace();
            if (message.getReadAcquireActions())
            {
                for (int i = 0; i < message.getReadAcquireActions()->getCount(); ++i)
                {
                    *readAcquireActions += EzAcquireAction((*message.getReadAcquireActions())[i]);
                }
            }
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzMessage() = default;
    EzMessage(const EzMessage& ezMessage) = default;
    EzMessage(EzMessage&& ezMessage) = default;
    ~EzMessage() = default;

    EzMessage(gs2::inbox::Message message) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(message)
    {}

    EzMessage& operator=(const EzMessage& ezMessage) = default;
    EzMessage& operator=(EzMessage&& ezMessage) = default;

    EzMessage deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzMessage);
    }

    gs2::inbox::Message ToModel() const
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
        return message;
    }

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getMessageId() const
    {
        return *ensureData().messageId;
    }

    const StringHolder& getName() const
    {
        return *ensureData().name;
    }

    const StringHolder& getMetadata() const
    {
        return *ensureData().metadata;
    }

    Bool getIsRead() const
    {
        return *ensureData().isRead;
    }

    const List<EzAcquireAction>& getReadAcquireActions() const
    {
        return *ensureData().readAcquireActions;
    }

    Int64 getReceivedAt() const
    {
        return *ensureData().receivedAt;
    }

    Int64 getReadAt() const
    {
        return *ensureData().readAt;
    }

    // ========================================
    //   Setters
    // ========================================

    void setMessageId(StringHolder messageId)
    {
        ensureData().messageId = std::move(messageId);
    }

    void setName(StringHolder name)
    {
        ensureData().name = std::move(name);
    }

    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata = std::move(metadata);
    }

    void setIsRead(Bool isRead)
    {
        ensureData().isRead = isRead;
    }

    void setReadAcquireActions(List<EzAcquireAction> readAcquireActions)
    {
        ensureData().readAcquireActions = std::move(readAcquireActions);
    }

    void setReceivedAt(Int64 receivedAt)
    {
        ensureData().receivedAt = receivedAt;
    }

    void setReadAt(Int64 readAt)
    {
        ensureData().readAt = readAt;
    }

    EzMessage& withMessageId(StringHolder messageId)
    {
        setMessageId(std::move(messageId));
        return *this;
    }

    EzMessage& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    EzMessage& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    EzMessage& withIsRead(Bool isRead)
    {
        setIsRead(isRead);
        return *this;
    }

    EzMessage& withReadAcquireActions(List<EzAcquireAction> readAcquireActions)
    {
        setReadAcquireActions(std::move(readAcquireActions));
        return *this;
    }

    EzMessage& withReceivedAt(Int64 receivedAt)
    {
        setReceivedAt(receivedAt);
        return *this;
    }

    EzMessage& withReadAt(Int64 readAt)
    {
        setReadAt(readAt);
        return *this;
    }
};

}}}

#endif //GS2_EZ_INBOX_EZMESSAGE_HPP_