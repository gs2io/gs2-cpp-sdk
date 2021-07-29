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

#include "EzRating.hpp"
#include <gs2/matchmaking/model/Rating.hpp>


namespace gs2 { namespace ez { namespace matchmaking {

EzRating::Data::Data(const Data& data) :
    Gs2Object(data),
    ratingId(data.ratingId),
    name(data.name),
    userId(data.userId),
    rateValue(data.rateValue),
    createdAt(data.createdAt),
    updatedAt(data.updatedAt)
{
}

EzRating::Data::Data(const gs2::matchmaking::Rating& rating) :
    ratingId(rating.getRatingId() ? *rating.getRatingId() : StringHolder()),
    name(rating.getName() ? *rating.getName() : StringHolder()),
    userId(rating.getUserId() ? *rating.getUserId() : StringHolder()),
    rateValue(rating.getRateValue() ? *rating.getRateValue() : 0),
    createdAt(rating.getCreatedAt() ? *rating.getCreatedAt() : 0),
    updatedAt(rating.getUpdatedAt() ? *rating.getUpdatedAt() : 0)
{
}

EzRating::Data::Data(const gs2::optional<gs2::matchmaking::Rating>& rating) :
    ratingId(rating && rating->getRatingId() ? *rating->getRatingId() : StringHolder()),
    name(rating && rating->getName() ? *rating->getName() : StringHolder()),
    userId(rating && rating->getUserId() ? *rating->getUserId() : StringHolder()),
    rateValue(rating && rating->getRateValue() ? *rating->getRateValue() : 0),
    createdAt(rating && rating->getCreatedAt() ? *rating->getCreatedAt() : 0),
    updatedAt(rating && rating->getUpdatedAt() ? *rating->getUpdatedAt() : 0)
{
}

EzRating::EzRating(gs2::matchmaking::Rating rating) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(rating)
{
}

EzRating::EzRating(gs2::optional<gs2::matchmaking::Rating> rating) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(rating)
{
}

EzRating EzRating::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzRating);
}

gs2::matchmaking::Rating EzRating::ToModel() const
{
    gs2::matchmaking::Rating rating;
    rating.setRatingId(getRatingId());
    rating.setName(getName());
    rating.setUserId(getUserId());
    rating.setRateValue(getRateValue());
    rating.setCreatedAt(getCreatedAt());
    rating.setUpdatedAt(getUpdatedAt());
    return rating;
}

}}}