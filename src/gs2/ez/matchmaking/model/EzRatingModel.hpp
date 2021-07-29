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

#ifndef GS2_EZ_MATCHMAKING_MODEL_EZRATINGMODEL_HPP_
#define GS2_EZ_MATCHMAKING_MODEL_EZRATINGMODEL_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace matchmaking {

class RatingModel;

}

namespace ez { namespace matchmaking {

class EzRatingModel : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** レーティングの種類名 */
        StringHolder name;
        /** レーティングの種類のメタデータ */
        StringHolder metadata;
        /** レート値の変動の大きさ */
        Int32 volatility;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::matchmaking::RatingModel& ratingModel);
        Data(const gs2::optional<gs2::matchmaking::RatingModel>& ratingModel);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzRatingModel() = default;
    EzRatingModel(const EzRatingModel& ezRatingModel) = default;
    EzRatingModel(EzRatingModel&& ezRatingModel) = default;
    ~EzRatingModel() = default;

    EzRatingModel(gs2::matchmaking::RatingModel ratingModel);
    EzRatingModel(gs2::optional<gs2::matchmaking::RatingModel> ratingModel);

    EzRatingModel& operator=(const EzRatingModel& ezRatingModel) = default;
    EzRatingModel& operator=(EzRatingModel&& ezRatingModel) = default;

    EzRatingModel deepCopy() const;

    gs2::matchmaking::RatingModel ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getName() const
    {
        return ensureData().name;
    }

    const StringHolder& getMetadata() const
    {
        return ensureData().metadata;
    }

    Int32 getVolatility() const
    {
        return ensureData().volatility;
    }

    // ========================================
    //   Setters
    // ========================================

    void setName(StringHolder name)
    {
        ensureData().name = std::move(name);
    }

    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata = std::move(metadata);
    }

    void setVolatility(Int32 volatility)
    {
        ensureData().volatility = volatility;
    }

    EzRatingModel& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    EzRatingModel& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    EzRatingModel& withVolatility(Int32 volatility)
    {
        setVolatility(volatility);
        return *this;
    }
};

}}}

#endif //GS2_EZ_MATCHMAKING_EZRATINGMODEL_HPP_