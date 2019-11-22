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

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "EzAcquireAction.hpp"
#include <memory>


namespace gs2 {

namespace inbox {

class Message;

}

namespace ez { namespace inbox {

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
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::inbox::Message& message);
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

    EzMessage(gs2::inbox::Message message);

    EzMessage& operator=(const EzMessage& ezMessage) = default;
    EzMessage& operator=(EzMessage&& ezMessage) = default;

    EzMessage deepCopy() const;

    gs2::inbox::Message ToModel() const;

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