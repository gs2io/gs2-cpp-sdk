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

#include "EzGameResult.hpp"
#include <gs2/matchmaking/model/GameResult.hpp>


namespace gs2 { namespace ez { namespace matchmaking {

EzGameResult::Data::Data(const Data& data) :
    Gs2Object(data),
    rank(data.rank),
    userId(data.userId)
{
}

EzGameResult::Data::Data(const gs2::matchmaking::GameResult& gameResult) :
    rank(gameResult.getRank() ? *gameResult.getRank() : 0),
    userId(gameResult.getUserId() ? *gameResult.getUserId() : StringHolder())
{
}

EzGameResult::Data::Data(const gs2::optional<gs2::matchmaking::GameResult>& gameResult) :
    rank(gameResult && gameResult->getRank() ? *gameResult->getRank() : 0),
    userId(gameResult && gameResult->getUserId() ? *gameResult->getUserId() : StringHolder())
{
}

EzGameResult::EzGameResult(gs2::matchmaking::GameResult gameResult) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(gameResult)
{
}

EzGameResult::EzGameResult(gs2::optional<gs2::matchmaking::GameResult> gameResult) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(gameResult)
{
}

EzGameResult EzGameResult::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzGameResult);
}

gs2::matchmaking::GameResult EzGameResult::ToModel() const
{
    gs2::matchmaking::GameResult gameResult;
    gameResult.setRank(getRank());
    gameResult.setUserId(getUserId());
    return gameResult;
}

}}}