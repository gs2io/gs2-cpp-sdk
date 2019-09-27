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

#ifndef GS2_RANKING_MODEL_SUBSCRIBEUSER_HPP_
#define GS2_RANKING_MODEL_SUBSCRIBEUSER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace ranking {

/**
 * 購読対象
 *
 * @author Game Server Services, Inc.
 *
 */
class SubscribeUser : public Gs2Object
{
    friend bool operator!=(const SubscribeUser& lhs, const SubscribeUser& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** カテゴリ名 */
        optional<StringHolder> categoryName;
        /** 購読するユーザID */
        optional<StringHolder> userId;
        /** 購読されるユーザID */
        optional<StringHolder> targetUserId;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            categoryName(data.categoryName),
            userId(data.userId),
            targetUserId(data.targetUserId)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "categoryName") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->categoryName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "userId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "targetUserId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->targetUserId.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    SubscribeUser() = default;
    SubscribeUser(const SubscribeUser& subscribeUser) = default;
    SubscribeUser(SubscribeUser&& subscribeUser) = default;
    ~SubscribeUser() = default;

    SubscribeUser& operator=(const SubscribeUser& subscribeUser) = default;
    SubscribeUser& operator=(SubscribeUser&& subscribeUser) = default;

    SubscribeUser deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(SubscribeUser);
    }

    const SubscribeUser* operator->() const
    {
        return this;
    }

    SubscribeUser* operator->()
    {
        return this;
    }
    /**
     * カテゴリ名を取得
     *
     * @return カテゴリ名
     */
    const optional<StringHolder>& getCategoryName() const
    {
        return ensureData().categoryName;
    }

    /**
     * カテゴリ名を設定
     *
     * @param categoryName カテゴリ名
     */
    void setCategoryName(StringHolder categoryName)
    {
        ensureData().categoryName.emplace(std::move(categoryName));
    }

    /**
     * カテゴリ名を設定
     *
     * @param categoryName カテゴリ名
     */
    SubscribeUser& withCategoryName(StringHolder categoryName)
    {
        setCategoryName(std::move(categoryName));
        return *this;
    }

    /**
     * 購読するユーザIDを取得
     *
     * @return 購読するユーザID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * 購読するユーザIDを設定
     *
     * @param userId 購読するユーザID
     */
    void setUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
    }

    /**
     * 購読するユーザIDを設定
     *
     * @param userId 購読するユーザID
     */
    SubscribeUser& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    /**
     * 購読されるユーザIDを取得
     *
     * @return 購読されるユーザID
     */
    const optional<StringHolder>& getTargetUserId() const
    {
        return ensureData().targetUserId;
    }

    /**
     * 購読されるユーザIDを設定
     *
     * @param targetUserId 購読されるユーザID
     */
    void setTargetUserId(StringHolder targetUserId)
    {
        ensureData().targetUserId.emplace(std::move(targetUserId));
    }

    /**
     * 購読されるユーザIDを設定
     *
     * @param targetUserId 購読されるユーザID
     */
    SubscribeUser& withTargetUserId(StringHolder targetUserId)
    {
        setTargetUserId(std::move(targetUserId));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const SubscribeUser& lhs, const SubscribeUser& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->categoryName != lhr.m_pData->categoryName)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->targetUserId != lhr.m_pData->targetUserId)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const SubscribeUser& lhs, const SubscribeUser& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_RANKING_MODEL_SUBSCRIBEUSER_HPP_