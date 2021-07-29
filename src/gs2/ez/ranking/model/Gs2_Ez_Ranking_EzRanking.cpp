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

#include "EzRanking.hpp"
#include <gs2/ranking/model/Ranking.hpp>


namespace gs2 { namespace ez { namespace ranking {

EzRanking::Data::Data(const Data& data) :
    Gs2Object(data),
    rank(data.rank),
    index(data.index),
    userId(data.userId),
    score(data.score),
    metadata(data.metadata),
    createdAt(data.createdAt)
{
}

EzRanking::Data::Data(const gs2::ranking::Ranking& ranking) :
    rank(ranking.getRank() ? *ranking.getRank() : 0),
    index(ranking.getIndex() ? *ranking.getIndex() : 0),
    userId(ranking.getUserId() ? *ranking.getUserId() : StringHolder()),
    score(ranking.getScore() ? *ranking.getScore() : 0),
    metadata(ranking.getMetadata() ? *ranking.getMetadata() : StringHolder()),
    createdAt(ranking.getCreatedAt() ? *ranking.getCreatedAt() : 0)
{
}

EzRanking::Data::Data(const gs2::optional<gs2::ranking::Ranking>& ranking) :
    rank(ranking && ranking->getRank() ? *ranking->getRank() : 0),
    index(ranking && ranking->getIndex() ? *ranking->getIndex() : 0),
    userId(ranking && ranking->getUserId() ? *ranking->getUserId() : StringHolder()),
    score(ranking && ranking->getScore() ? *ranking->getScore() : 0),
    metadata(ranking && ranking->getMetadata() ? *ranking->getMetadata() : StringHolder()),
    createdAt(ranking && ranking->getCreatedAt() ? *ranking->getCreatedAt() : 0)
{
}

EzRanking::EzRanking(gs2::ranking::Ranking ranking) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(ranking)
{
}

EzRanking::EzRanking(gs2::optional<gs2::ranking::Ranking> ranking) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(ranking)
{
}

EzRanking EzRanking::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzRanking);
}

gs2::ranking::Ranking EzRanking::ToModel() const
{
    gs2::ranking::Ranking ranking;
    ranking.setRank(getRank());
    ranking.setIndex(getIndex());
    ranking.setUserId(getUserId());
    ranking.setScore(getScore());
    ranking.setMetadata(getMetadata());
    ranking.setCreatedAt(getCreatedAt());
    return ranking;
}

}}}