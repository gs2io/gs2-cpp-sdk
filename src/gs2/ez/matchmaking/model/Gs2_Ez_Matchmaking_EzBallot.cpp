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

#include "EzBallot.hpp"
#include <gs2/matchmaking/model/Ballot.hpp>


namespace gs2 { namespace ez { namespace matchmaking {

EzBallot::Data::Data(const Data& data) :
    Gs2Object(data),
    userId(data.userId),
    ratingName(data.ratingName),
    gatheringName(data.gatheringName),
    numberOfPlayer(data.numberOfPlayer)
{
}

EzBallot::Data::Data(const gs2::matchmaking::Ballot& ballot) :
    userId(ballot.getUserId()),
    ratingName(ballot.getRatingName()),
    gatheringName(ballot.getGatheringName()),
    numberOfPlayer(ballot.getNumberOfPlayer() ? *ballot.getNumberOfPlayer() : 0)
{
}

EzBallot::EzBallot(gs2::matchmaking::Ballot ballot) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(ballot)
{
}

EzBallot EzBallot::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzBallot);
}

gs2::matchmaking::Ballot EzBallot::ToModel() const
{
    gs2::matchmaking::Ballot ballot;
    ballot.setUserId(getUserId());
    ballot.setRatingName(getRatingName());
    ballot.setGatheringName(getGatheringName());
    ballot.setNumberOfPlayer(getNumberOfPlayer());
    return ballot;
}

}}}