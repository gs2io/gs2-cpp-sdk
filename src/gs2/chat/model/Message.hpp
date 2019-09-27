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

#ifndef GS2_CHAT_MODEL_MESSAGE_HPP_
#define GS2_CHAT_MODEL_MESSAGE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace chat {

/**
 * メッセージ
 *
 * @author Game Server Services, Inc.
 *
 */
class Message : public Gs2Object
{
    friend bool operator!=(const Message& lhs, const Message& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** メッセージ */
        optional<StringHolder> messageId;
        /** ルーム名 */
        optional<StringHolder> roomName;
        /** メッセージ名 */
        optional<StringHolder> name;
        /** 発言したユーザID */
        optional<StringHolder> userId;
        /** メッセージの種類を分類したい時の種類番号 */
        optional<Int32> category;
        /** メタデータ */
        optional<StringHolder> metadata;
        /** 作成日時 */
        optional<Int64> createdAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            messageId(data.messageId),
            roomName(data.roomName),
            name(data.name),
            userId(data.userId),
            category(data.category),
            metadata(data.metadata),
            createdAt(data.createdAt)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "messageId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->messageId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "roomName") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->roomName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "userId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "category") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->category = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "metadata") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "createdAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Message() = default;
    Message(const Message& message) = default;
    Message(Message&& message) = default;
    ~Message() = default;

    Message& operator=(const Message& message) = default;
    Message& operator=(Message&& message) = default;

    Message deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Message);
    }

    const Message* operator->() const
    {
        return this;
    }

    Message* operator->()
    {
        return this;
    }
    /**
     * メッセージを取得
     *
     * @return メッセージ
     */
    const optional<StringHolder>& getMessageId() const
    {
        return ensureData().messageId;
    }

    /**
     * メッセージを設定
     *
     * @param messageId メッセージ
     */
    void setMessageId(StringHolder messageId)
    {
        ensureData().messageId.emplace(std::move(messageId));
    }

    /**
     * メッセージを設定
     *
     * @param messageId メッセージ
     */
    Message& withMessageId(StringHolder messageId)
    {
        setMessageId(std::move(messageId));
        return *this;
    }

    /**
     * ルーム名を取得
     *
     * @return ルーム名
     */
    const optional<StringHolder>& getRoomName() const
    {
        return ensureData().roomName;
    }

    /**
     * ルーム名を設定
     *
     * @param roomName ルーム名
     */
    void setRoomName(StringHolder roomName)
    {
        ensureData().roomName.emplace(std::move(roomName));
    }

    /**
     * ルーム名を設定
     *
     * @param roomName ルーム名
     */
    Message& withRoomName(StringHolder roomName)
    {
        setRoomName(std::move(roomName));
        return *this;
    }

    /**
     * メッセージ名を取得
     *
     * @return メッセージ名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * メッセージ名を設定
     *
     * @param name メッセージ名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * メッセージ名を設定
     *
     * @param name メッセージ名
     */
    Message& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * 発言したユーザIDを取得
     *
     * @return 発言したユーザID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * 発言したユーザIDを設定
     *
     * @param userId 発言したユーザID
     */
    void setUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
    }

    /**
     * 発言したユーザIDを設定
     *
     * @param userId 発言したユーザID
     */
    Message& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    /**
     * メッセージの種類を分類したい時の種類番号を取得
     *
     * @return メッセージの種類を分類したい時の種類番号
     */
    const optional<Int32>& getCategory() const
    {
        return ensureData().category;
    }

    /**
     * メッセージの種類を分類したい時の種類番号を設定
     *
     * @param category メッセージの種類を分類したい時の種類番号
     */
    void setCategory(Int32 category)
    {
        ensureData().category.emplace(category);
    }

    /**
     * メッセージの種類を分類したい時の種類番号を設定
     *
     * @param category メッセージの種類を分類したい時の種類番号
     */
    Message& withCategory(Int32 category)
    {
        setCategory(category);
        return *this;
    }

    /**
     * メタデータを取得
     *
     * @return メタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * メタデータを設定
     *
     * @param metadata メタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * メタデータを設定
     *
     * @param metadata メタデータ
     */
    Message& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getCreatedAt() const
    {
        return ensureData().createdAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    void setCreatedAt(Int64 createdAt)
    {
        ensureData().createdAt.emplace(createdAt);
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    Message& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Message& lhs, const Message& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->messageId != lhr.m_pData->messageId)
        {
            return true;
        }
        if (lhs.m_pData->roomName != lhr.m_pData->roomName)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->category != lhr.m_pData->category)
        {
            return true;
        }
        if (lhs.m_pData->metadata != lhr.m_pData->metadata)
        {
            return true;
        }
        if (lhs.m_pData->createdAt != lhr.m_pData->createdAt)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const Message& lhs, const Message& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_CHAT_MODEL_MESSAGE_HPP_