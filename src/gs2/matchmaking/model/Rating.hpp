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

#ifndef GS2_MATCHMAKING_MODEL_RATING_HPP_
#define GS2_MATCHMAKING_MODEL_RATING_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace matchmaking {

/**
 * レーティング
 *
 * @author Game Server Services, Inc.
 *
 */
class Rating : public Gs2Object
{
    friend bool operator!=(const Rating& lhs, const Rating& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** レーティング */
        optional<StringHolder> ratingId;
        /** レーティング名 */
        optional<StringHolder> name;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** None */
        optional<Float> rateValue;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            ratingId(data.ratingId),
            name(data.name),
            userId(data.userId),
            rateValue(data.rateValue),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "ratingId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->ratingId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name_, "rateValue") == 0)
            {
                if (jsonValue.IsFloat())
                {
                    this->rateValue = jsonValue.GetFloat();
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
    Rating() = default;
    Rating(const Rating& rating) = default;
    Rating(Rating&& rating) = default;
    ~Rating() = default;

    Rating& operator=(const Rating& rating) = default;
    Rating& operator=(Rating&& rating) = default;

    Rating deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Rating);
    }

    const Rating* operator->() const
    {
        return this;
    }

    Rating* operator->()
    {
        return this;
    }
    /**
     * レーティングを取得
     *
     * @return レーティング
     */
    const optional<StringHolder>& getRatingId() const
    {
        return ensureData().ratingId;
    }

    /**
     * レーティングを設定
     *
     * @param ratingId レーティング
     */
    void setRatingId(StringHolder ratingId)
    {
        ensureData().ratingId.emplace(std::move(ratingId));
    }

    /**
     * レーティングを設定
     *
     * @param ratingId レーティング
     */
    Rating& withRatingId(StringHolder ratingId)
    {
        setRatingId(std::move(ratingId));
        return *this;
    }

    /**
     * レーティング名を取得
     *
     * @return レーティング名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * レーティング名を設定
     *
     * @param name レーティング名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * レーティング名を設定
     *
     * @param name レーティング名
     */
    Rating& withName(StringHolder name)
    {
        setName(std::move(name));
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
    Rating& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    /**
     * Noneを取得
     *
     * @return None
     */
    const optional<Float>& getRateValue() const
    {
        return ensureData().rateValue;
    }

    /**
     * Noneを設定
     *
     * @param rateValue None
     */
    void setRateValue(Float rateValue)
    {
        ensureData().rateValue.emplace(rateValue);
    }

    /**
     * Noneを設定
     *
     * @param rateValue None
     */
    Rating& withRateValue(Float rateValue)
    {
        setRateValue(rateValue);
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
    Rating& withCreatedAt(Int64 createdAt)
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
    Rating& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Rating& lhs, const Rating& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->ratingId != lhr.m_pData->ratingId)
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
        if (lhs.m_pData->rateValue != lhr.m_pData->rateValue)
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

inline bool operator==(const Rating& lhs, const Rating& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_MATCHMAKING_MODEL_RATING_HPP_