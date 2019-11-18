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

#ifndef GS2_FRIEND_MODEL_FOLLOW_HPP_
#define GS2_FRIEND_MODEL_FOLLOW_HPP_

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
 * フォロー
 *
 * @author Game Server Services, Inc.
 *
 */
class Follow : public Gs2Object
{
    friend bool operator!=(const Follow& lhs, const Follow& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** フォロー */
        optional<StringHolder> followId;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** フォローしているユーザーIDリスト */
        optional<List<StringHolder>> targetUserIds;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            followId(data.followId),
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
            if (std::strcmp(name_, "followId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->followId.emplace(jsonValue.GetString());
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
    Follow() = default;
    Follow(const Follow& follow) = default;
    Follow(Follow&& follow) = default;
    ~Follow() = default;

    Follow& operator=(const Follow& follow) = default;
    Follow& operator=(Follow&& follow) = default;

    Follow deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Follow);
    }

    const Follow* operator->() const
    {
        return this;
    }

    Follow* operator->()
    {
        return this;
    }
    /**
     * フォローを取得
     *
     * @return フォロー
     */
    const optional<StringHolder>& getFollowId() const
    {
        return ensureData().followId;
    }

    /**
     * フォローを設定
     *
     * @param followId フォロー
     */
    void setFollowId(StringHolder followId)
    {
        ensureData().followId.emplace(std::move(followId));
    }

    /**
     * フォローを設定
     *
     * @param followId フォロー
     */
    Follow& withFollowId(StringHolder followId)
    {
        setFollowId(std::move(followId));
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
    Follow& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    /**
     * フォローしているユーザーIDリストを取得
     *
     * @return フォローしているユーザーIDリスト
     */
    const optional<List<StringHolder>>& getTargetUserIds() const
    {
        return ensureData().targetUserIds;
    }

    /**
     * フォローしているユーザーIDリストを設定
     *
     * @param targetUserIds フォローしているユーザーIDリスト
     */
    void setTargetUserIds(List<StringHolder> targetUserIds)
    {
        ensureData().targetUserIds.emplace(std::move(targetUserIds));
    }

    /**
     * フォローしているユーザーIDリストを設定
     *
     * @param targetUserIds フォローしているユーザーIDリスト
     */
    Follow& withTargetUserIds(List<StringHolder> targetUserIds)
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
    Follow& withCreatedAt(Int64 createdAt)
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
    Follow& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Follow& lhs, const Follow& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->followId != lhr.m_pData->followId)
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

inline bool operator==(const Follow& lhs, const Follow& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_FRIEND_MODEL_FOLLOW_HPP_