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

#include "EzStatus.hpp"
#include <gs2/experience/model/Status.hpp>


namespace gs2 { namespace ez { namespace experience {

EzStatus::Data::Data(const Data& data) :
    Gs2Object(data),
    experienceName(data.experienceName),
    propertyId(data.propertyId),
    experienceValue(data.experienceValue),
    rankValue(data.rankValue),
    rankCapValue(data.rankCapValue)
{
}

EzStatus::Data::Data(const gs2::experience::Status& status) :
    experienceName(status.getExperienceName()),
    propertyId(status.getPropertyId()),
    experienceValue(status.getExperienceValue() ? *status.getExperienceValue() : 0),
    rankValue(status.getRankValue() ? *status.getRankValue() : 0),
    rankCapValue(status.getRankCapValue() ? *status.getRankCapValue() : 0)
{
}

EzStatus::EzStatus(gs2::experience::Status status) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(status)
{
}

EzStatus EzStatus::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzStatus);
}

gs2::experience::Status EzStatus::ToModel() const
{
    gs2::experience::Status status;
    status.setExperienceName(getExperienceName());
    status.setPropertyId(getPropertyId());
    status.setExperienceValue(getExperienceValue());
    status.setRankValue(getRankValue());
    status.setRankCapValue(getRankCapValue());
    return status;
}

}}}