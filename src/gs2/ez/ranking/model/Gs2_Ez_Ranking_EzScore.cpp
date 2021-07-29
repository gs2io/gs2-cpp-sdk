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

#include "EzScore.hpp"
#include <gs2/ranking/model/Score.hpp>


namespace gs2 { namespace ez { namespace ranking {

EzScore::Data::Data(const Data& data) :
    Gs2Object(data),
    categoryName(data.categoryName),
    userId(data.userId),
    scorerUserId(data.scorerUserId),
    score(data.score),
    metadata(data.metadata)
{
}

EzScore::Data::Data(const gs2::ranking::Score& score) :
    categoryName(score.getCategoryName() ? *score.getCategoryName() : StringHolder()),
    userId(score.getUserId() ? *score.getUserId() : StringHolder()),
    scorerUserId(score.getScorerUserId() ? *score.getScorerUserId() : StringHolder()),
    score(score.getScore() ? *score.getScore() : 0),
    metadata(score.getMetadata() ? *score.getMetadata() : StringHolder())
{
}

EzScore::Data::Data(const gs2::optional<gs2::ranking::Score>& score) :
    categoryName(score && score->getCategoryName() ? *score->getCategoryName() : StringHolder()),
    userId(score && score->getUserId() ? *score->getUserId() : StringHolder()),
    scorerUserId(score && score->getScorerUserId() ? *score->getScorerUserId() : StringHolder()),
    score(score && score->getScore() ? *score->getScore() : 0),
    metadata(score && score->getMetadata() ? *score->getMetadata() : StringHolder())
{
}

EzScore::EzScore(gs2::ranking::Score score) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(score)
{
}

EzScore::EzScore(gs2::optional<gs2::ranking::Score> score) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(score)
{
}

EzScore EzScore::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzScore);
}

gs2::ranking::Score EzScore::ToModel() const
{
    gs2::ranking::Score score;
    score.setCategoryName(getCategoryName());
    score.setUserId(getUserId());
    score.setScorerUserId(getScorerUserId());
    score.setScore(getScore());
    score.setMetadata(getMetadata());
    return score;
}

}}}