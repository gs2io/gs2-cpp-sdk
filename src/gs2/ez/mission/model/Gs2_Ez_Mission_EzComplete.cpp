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

#include "EzComplete.hpp"
#include <gs2/mission/model/Complete.hpp>


namespace gs2 { namespace ez { namespace mission {

EzComplete::Data::Data(const Data& data) :
    Gs2Object(data),
    missionGroupName(data.missionGroupName)
{
    completedMissionTaskNames = data.completedMissionTaskNames.deepCopy();
    receivedMissionTaskNames = data.receivedMissionTaskNames.deepCopy();
}

EzComplete::Data::Data(const gs2::mission::Complete& complete) :
    missionGroupName(complete.getMissionGroupName() ? *complete.getMissionGroupName() : StringHolder()),
    completedMissionTaskNames(complete.getCompletedMissionTaskNames() ? *complete.getCompletedMissionTaskNames() : List<StringHolder>()),
    receivedMissionTaskNames(complete.getReceivedMissionTaskNames() ? *complete.getReceivedMissionTaskNames() : List<StringHolder>())
{
}

EzComplete::Data::Data(const gs2::optional<gs2::mission::Complete>& complete) :
    missionGroupName(complete && complete->getMissionGroupName() ? *complete->getMissionGroupName() : StringHolder()),
    completedMissionTaskNames(complete && complete->getCompletedMissionTaskNames() ? *complete->getCompletedMissionTaskNames() : List<StringHolder>()),
    receivedMissionTaskNames(complete && complete->getReceivedMissionTaskNames() ? *complete->getReceivedMissionTaskNames() : List<StringHolder>())
{
}

EzComplete::EzComplete(gs2::mission::Complete complete) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(complete)
{
}

EzComplete::EzComplete(gs2::optional<gs2::mission::Complete> complete) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(complete)
{
}

EzComplete EzComplete::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzComplete);
}

gs2::mission::Complete EzComplete::ToModel() const
{
    gs2::mission::Complete complete;
    complete.setMissionGroupName(getMissionGroupName());
    complete.setCompletedMissionTaskNames(getCompletedMissionTaskNames());
    complete.setReceivedMissionTaskNames(getReceivedMissionTaskNames());
    return complete;
}

}}}