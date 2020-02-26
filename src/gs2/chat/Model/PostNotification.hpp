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

#ifndef GS2_CHAT_MODEL_POSTNOTIFICATION_HPP_
#define GS2_CHAT_MODEL_POSTNOTIFICATION_HPP_

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
 * 
 *
 * @author Game Server Services, Inc.
 *
 */
class PostNotification : public Gs2Object
{
    friend bool operator!=(const PostNotification& lhs, const PostNotification& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** ルーム名 */
        optional<StringHolder> roomName;
        /** 発言したユーザID */
        optional<StringHolder> userId;
        /** メッセージの種類を分類したい時の種類番号 */
        optional<Int32> category;
        /** 作成日時 */
        optional<Int64> createdAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            namespaceName(data.namespaceName),
            roomName(data.roomName),
            userId(data.userId),
            category(data.category),
            createdAt(data.createdAt)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "namespaceName") == 0) {
                if (jsonValue.IsString())
                {
                    this->namespaceName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "roomName") == 0) {
                if (jsonValue.IsString())
                {
                    this->roomName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "userId") == 0) {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "category") == 0) {
                if (jsonValue.IsInt())
                {
                    this->category = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "createdAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    PostNotification() = default;
    PostNotification(const PostNotification& postNotification) = default;
    PostNotification(PostNotification&& postNotification) = default;
    ~PostNotification() = default;

    PostNotification& operator=(const PostNotification& postNotification) = default;
    PostNotification& operator=(PostNotification&& postNotification) = default;

    PostNotification deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(PostNotification);
    }

    const PostNotification* operator->() const
    {
        return this;
    }

    PostNotification* operator->()
    {
        return this;
    }
    /**
     * ネームスペース名を取得
     *
     * @return ネームスペース名
     */
    const optional<StringHolder>& getNamespaceName() const
    {
        return ensureData().namespaceName;
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    void setNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(
            std::move(namespaceName)
        );
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    PostNotification& withNamespaceName(StringHolder namespaceName)
    {
        setNamespaceName(
            std::move(namespaceName)
        );
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
        ensureData().roomName.emplace(
            std::move(roomName)
        );
    }

    /**
     * ルーム名を設定
     *
     * @param roomName ルーム名
     */
    PostNotification& withRoomName(StringHolder roomName)
    {
        setRoomName(
            std::move(roomName)
        );
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
        ensureData().userId.emplace(
            std::move(userId)
        );
    }

    /**
     * 発言したユーザIDを設定
     *
     * @param userId 発言したユーザID
     */
    PostNotification& withUserId(StringHolder userId)
    {
        setUserId(
            std::move(userId)
        );
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
        ensureData().category.emplace(
            category
        );
    }

    /**
     * メッセージの種類を分類したい時の種類番号を設定
     *
     * @param category メッセージの種類を分類したい時の種類番号
     */
    PostNotification& withCategory(Int32 category)
    {
        setCategory(
            category
        );
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
        ensureData().createdAt.emplace(
            createdAt
        );
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    PostNotification& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(
            createdAt
        );
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const PostNotification& lhs, const PostNotification& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData || lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->namespaceName != lhr.m_pData->namespaceName)
        {
            return true;
        }
        if (lhs.m_pData->roomName != lhr.m_pData->roomName)
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
        if (lhs.m_pData->createdAt != lhr.m_pData->createdAt)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const PostNotification& lhs, const PostNotification& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_CHAT_MODEL_POSTNOTIFICATION_HPP_