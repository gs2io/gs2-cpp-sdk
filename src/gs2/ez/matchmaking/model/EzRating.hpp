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

#ifndef GS2_EZ_MATCHMAKING_MODEL_EZRATING_HPP_
#define GS2_EZ_MATCHMAKING_MODEL_EZRATING_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace matchmaking {

class Rating;

}

namespace ez { namespace matchmaking {

class EzRating : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** レーティング */
        StringHolder ratingId;
        /** レーティング名 */
        StringHolder name;
        /** ユーザーID */
        StringHolder userId;
        /** None */
        Float rateValue;
        /** 作成日時 */
        Int64 createdAt;
        /** 最終更新日時 */
        Int64 updatedAt;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::matchmaking::Rating& rating);
        Data(const gs2::optional<gs2::matchmaking::Rating>& rating);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzRating() = default;
    EzRating(const EzRating& ezRating) = default;
    EzRating(EzRating&& ezRating) = default;
    ~EzRating() = default;

    EzRating(gs2::matchmaking::Rating rating);
    EzRating(gs2::optional<gs2::matchmaking::Rating> rating);

    EzRating& operator=(const EzRating& ezRating) = default;
    EzRating& operator=(EzRating&& ezRating) = default;

    EzRating deepCopy() const;

    gs2::matchmaking::Rating ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getRatingId() const
    {
        return ensureData().ratingId;
    }

    const StringHolder& getName() const
    {
        return ensureData().name;
    }

    const StringHolder& getUserId() const
    {
        return ensureData().userId;
    }

    Float getRateValue() const
    {
        return ensureData().rateValue;
    }

    Int64 getCreatedAt() const
    {
        return ensureData().createdAt;
    }

    Int64 getUpdatedAt() const
    {
        return ensureData().updatedAt;
    }

    // ========================================
    //   Setters
    // ========================================

    void setRatingId(StringHolder ratingId)
    {
        ensureData().ratingId = std::move(ratingId);
    }

    void setName(StringHolder name)
    {
        ensureData().name = std::move(name);
    }

    void setUserId(StringHolder userId)
    {
        ensureData().userId = std::move(userId);
    }

    void setRateValue(Float rateValue)
    {
        ensureData().rateValue = rateValue;
    }

    void setCreatedAt(Int64 createdAt)
    {
        ensureData().createdAt = createdAt;
    }

    void setUpdatedAt(Int64 updatedAt)
    {
        ensureData().updatedAt = updatedAt;
    }

    EzRating& withRatingId(StringHolder ratingId)
    {
        setRatingId(std::move(ratingId));
        return *this;
    }

    EzRating& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    EzRating& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    EzRating& withRateValue(Float rateValue)
    {
        setRateValue(rateValue);
        return *this;
    }

    EzRating& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }

    EzRating& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }
};

}}}

#endif //GS2_EZ_MATCHMAKING_EZRATING_HPP_