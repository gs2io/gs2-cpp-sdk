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

#include "EzMissionGroupModel.hpp"
#include <gs2/mission/model/MissionGroupModel.hpp>


namespace gs2 { namespace ez { namespace mission {

EzMissionGroupModel::Data::Data(const Data& data) :
    Gs2Object(data),
    name(data.name),
    metadata(data.metadata),
    resetType(data.resetType),
    resetDayOfMonth(data.resetDayOfMonth),
    resetDayOfWeek(data.resetDayOfWeek),
    resetHour(data.resetHour),
    completeNotificationNamespaceId(data.completeNotificationNamespaceId)
{
    if (data.tasks)
    {
        tasks = data.tasks->deepCopy();
    }
}

EzMissionGroupModel::Data::Data(const gs2::mission::MissionGroupModel& missionGroupModel) :
    name(missionGroupModel.getName()),
    metadata(missionGroupModel.getMetadata()),
    resetType(missionGroupModel.getResetType()),
    resetDayOfMonth(missionGroupModel.getResetDayOfMonth() ? *missionGroupModel.getResetDayOfMonth() : 0),
    resetDayOfWeek(missionGroupModel.getResetDayOfWeek()),
    resetHour(missionGroupModel.getResetHour() ? *missionGroupModel.getResetHour() : 0),
    completeNotificationNamespaceId(missionGroupModel.getCompleteNotificationNamespaceId())
{
    tasks.emplace();
    if (missionGroupModel.getTasks())
    {
        for (int i = 0; i < missionGroupModel.getTasks()->getCount(); ++i)
        {
            *tasks += EzMissionTaskModel((*missionGroupModel.getTasks())[i]);
        }
    }
}

EzMissionGroupModel::EzMissionGroupModel(gs2::mission::MissionGroupModel missionGroupModel) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(missionGroupModel)
{
}

EzMissionGroupModel EzMissionGroupModel::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzMissionGroupModel);
}

gs2::mission::MissionGroupModel EzMissionGroupModel::ToModel() const
{
    gs2::mission::MissionGroupModel missionGroupModel;
    missionGroupModel.setName(getName());
    missionGroupModel.setMetadata(getMetadata());
    {
        gs2::List<gs2::mission::MissionTaskModel> list;
        auto& tasks = getTasks();
        for (int i = 0; i < tasks.getCount(); ++i)
        {
            list += tasks[i].ToModel();
        }
        missionGroupModel.setTasks(list);
    }
    missionGroupModel.setResetType(getResetType());
    missionGroupModel.setResetDayOfMonth(getResetDayOfMonth());
    missionGroupModel.setResetDayOfWeek(getResetDayOfWeek());
    missionGroupModel.setResetHour(getResetHour());
    missionGroupModel.setCompleteNotificationNamespaceId(getCompleteNotificationNamespaceId());
    return missionGroupModel;
}

}}}