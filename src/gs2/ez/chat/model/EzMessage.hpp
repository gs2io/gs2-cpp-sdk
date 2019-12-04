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

#ifndef GS2_EZ_CHAT_MODEL_EZMESSAGE_HPP_
#define GS2_EZ_CHAT_MODEL_EZMESSAGE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace chat {

class Message;

}

namespace ez { namespace chat {

class EzMessage : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** ルーム名 */
        gs2::optional<StringHolder> roomName;
        /** 発言したユーザID */
        gs2::optional<StringHolder> userId;
        /** メッセージの種類を分類したい時の種類番号 */
        gs2::optional<Int32> category;
        /** メタデータ */
        gs2::optional<StringHolder> metadata;
        /** 作成日時 */
        gs2::optional<Int64> createdAt;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::chat::Message& message);
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

    EzMessage(gs2::chat::Message message);

    EzMessage& operator=(const EzMessage& ezMessage) = default;
    EzMessage& operator=(EzMessage&& ezMessage) = default;

    EzMessage deepCopy() const;

    gs2::chat::Message ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getRoomName() const
    {
        return *ensureData().roomName;
    }

    const StringHolder& getUserId() const
    {
        return *ensureData().userId;
    }

    Int32 getCategory() const
    {
        return *ensureData().category;
    }

    const StringHolder& getMetadata() const
    {
        return *ensureData().metadata;
    }

    Int64 getCreatedAt() const
    {
        return *ensureData().createdAt;
    }

    // ========================================
    //   Setters
    // ========================================

    void setRoomName(StringHolder roomName)
    {
        ensureData().roomName = std::move(roomName);
    }

    void setUserId(StringHolder userId)
    {
        ensureData().userId = std::move(userId);
    }

    void setCategory(Int32 category)
    {
        ensureData().category = category;
    }

    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata = std::move(metadata);
    }

    void setCreatedAt(Int64 createdAt)
    {
        ensureData().createdAt = createdAt;
    }

    EzMessage& withRoomName(StringHolder roomName)
    {
        setRoomName(std::move(roomName));
        return *this;
    }

    EzMessage& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    EzMessage& withCategory(Int32 category)
    {
        setCategory(category);
        return *this;
    }

    EzMessage& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    EzMessage& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }
};

}}}

#endif //GS2_EZ_CHAT_EZMESSAGE_HPP_