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

#ifndef GS2_FRIEND_MODEL_FRIEND_HPP_
#define GS2_FRIEND_MODEL_FRIEND_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace friend_ {

/**
 * フレンド
 *
 * @author Game Server Services, Inc.
 *
 */
class Friend : public Gs2Object
{
    friend bool operator!=(const Friend& lhs, const Friend& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** フレンド */
        optional<StringHolder> friendId;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** フレンドのユーザーIDリスト */
        optional<List<StringHolder>> targetUserIds;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            friendId(data.friendId),
            userId(data.userId),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {
            if (data.targetUserIds)
            {
                targetUserIds = data.targetUserIds->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "friendId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->friendId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "userId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "targetUserIds") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->targetUserIds.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        if (json->IsString())
                        {
                            auto valueStr = json->GetString();
                            StringHolder stringHolder(valueStr);
                            detail::addToList(*this->targetUserIds, std::move(stringHolder));
                        }
                    }
                }
            }
            else if (std::strcmp(name_, "createdAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "updatedAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Friend() = default;
    Friend(const Friend& friend_) = default;
    Friend(Friend&& friend_) = default;
    ~Friend() = default;

    Friend& operator=(const Friend& friend_) = default;
    Friend& operator=(Friend&& friend_) = default;

    Friend deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Friend);
    }

    const Friend* operator->() const
    {
        return this;
    }

    Friend* operator->()
    {
        return this;
    }
    /**
     * フレンドを取得
     *
     * @return フレンド
     */
    const optional<StringHolder>& getFriendId() const
    {
        return ensureData().friendId;
    }

    /**
     * フレンドを設定
     *
     * @param friendId フレンド
     */
    void setFriendId(StringHolder friendId)
    {
        ensureData().friendId.emplace(std::move(friendId));
    }

    /**
     * フレンドを設定
     *
     * @param friendId フレンド
     */
    Friend& withFriendId(StringHolder friendId)
    {
        setFriendId(std::move(friendId));
        return *this;
    }

    /**
     * ユーザーIDを取得
     *
     * @return ユーザーID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    void setUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    Friend& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    /**
     * フレンドのユーザーIDリストを取得
     *
     * @return フレンドのユーザーIDリスト
     */
    const optional<List<StringHolder>>& getTargetUserIds() const
    {
        return ensureData().targetUserIds;
    }

    /**
     * フレンドのユーザーIDリストを設定
     *
     * @param targetUserIds フレンドのユーザーIDリスト
     */
    void setTargetUserIds(List<StringHolder> targetUserIds)
    {
        ensureData().targetUserIds.emplace(std::move(targetUserIds));
    }

    /**
     * フレンドのユーザーIDリストを設定
     *
     * @param targetUserIds フレンドのユーザーIDリスト
     */
    Friend& withTargetUserIds(List<StringHolder> targetUserIds)
    {
        setTargetUserIds(std::move(targetUserIds));
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
    Friend& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }

    /**
     * 最終更新日時を取得
     *
     * @return 最終更新日時
     */
    const optional<Int64>& getUpdatedAt() const
    {
        return ensureData().updatedAt;
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    void setUpdatedAt(Int64 updatedAt)
    {
        ensureData().updatedAt.emplace(updatedAt);
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    Friend& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Friend& lhs, const Friend& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->friendId != lhr.m_pData->friendId)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->targetUserIds != lhr.m_pData->targetUserIds)
        {
            return true;
        }
        if (lhs.m_pData->createdAt != lhr.m_pData->createdAt)
        {
            return true;
        }
        if (lhs.m_pData->updatedAt != lhr.m_pData->updatedAt)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const Friend& lhs, const Friend& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_FRIEND_MODEL_FRIEND_HPP_