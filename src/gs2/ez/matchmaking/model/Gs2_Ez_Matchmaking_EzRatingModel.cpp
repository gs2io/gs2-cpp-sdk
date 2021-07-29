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

#include "EzRatingModel.hpp"
#include <gs2/matchmaking/model/RatingModel.hpp>


namespace gs2 { namespace ez { namespace matchmaking {

EzRatingModel::Data::Data(const Data& data) :
    Gs2Object(data),
    name(data.name),
    metadata(data.metadata),
    volatility(data.volatility)
{
}

EzRatingModel::Data::Data(const gs2::matchmaking::RatingModel& ratingModel) :
    name(ratingModel.getName() ? *ratingModel.getName() : StringHolder()),
    metadata(ratingModel.getMetadata() ? *ratingModel.getMetadata() : StringHolder()),
    volatility(ratingModel.getVolatility() ? *ratingModel.getVolatility() : 0)
{
}

EzRatingModel::Data::Data(const gs2::optional<gs2::matchmaking::RatingModel>& ratingModel) :
    name(ratingModel && ratingModel->getName() ? *ratingModel->getName() : StringHolder()),
    metadata(ratingModel && ratingModel->getMetadata() ? *ratingModel->getMetadata() : StringHolder()),
    volatility(ratingModel && ratingModel->getVolatility() ? *ratingModel->getVolatility() : 0)
{
}

EzRatingModel::EzRatingModel(gs2::matchmaking::RatingModel ratingModel) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(ratingModel)
{
}

EzRatingModel::EzRatingModel(gs2::optional<gs2::matchmaking::RatingModel> ratingModel) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(ratingModel)
{
}

EzRatingModel EzRatingModel::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzRatingModel);
}

gs2::matchmaking::RatingModel EzRatingModel::ToModel() const
{
    gs2::matchmaking::RatingModel ratingModel;
    ratingModel.setName(getName());
    ratingModel.setMetadata(getMetadata());
    ratingModel.setVolatility(getVolatility());
    return ratingModel;
}

}}}