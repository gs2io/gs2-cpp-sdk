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

#include "EzMissionTaskModel.hpp"
#include <gs2/mission/model/MissionTaskModel.hpp>


namespace gs2 { namespace ez { namespace mission {

EzMissionTaskModel::Data::Data(const Data& data) :
    Gs2Object(data),
    name(data.name),
    metadata(data.metadata),
    counterName(data.counterName),
    targetValue(data.targetValue),
    challengePeriodEventId(data.challengePeriodEventId),
    premiseMissionTaskName(data.premiseMissionTaskName)
{
    completeAcquireActions = data.completeAcquireActions.deepCopy();
}

EzMissionTaskModel::Data::Data(const gs2::mission::MissionTaskModel& missionTaskModel) :
    name(missionTaskModel.getName() ? *missionTaskModel.getName() : StringHolder()),
    metadata(missionTaskModel.getMetadata() ? *missionTaskModel.getMetadata() : StringHolder()),
    counterName(missionTaskModel.getCounterName() ? *missionTaskModel.getCounterName() : StringHolder()),
    targetValue(missionTaskModel.getTargetValue() ? *missionTaskModel.getTargetValue() : 0),
    challengePeriodEventId(missionTaskModel.getChallengePeriodEventId() ? *missionTaskModel.getChallengePeriodEventId() : StringHolder()),
    premiseMissionTaskName(missionTaskModel.getPremiseMissionTaskName() ? *missionTaskModel.getPremiseMissionTaskName() : StringHolder())
{
    if (missionTaskModel.getCompleteAcquireActions())
    {
        for (int i = 0; i < missionTaskModel.getCompleteAcquireActions()->getCount(); ++i)
        {
            completeAcquireActions += EzAcquireAction((*missionTaskModel.getCompleteAcquireActions())[i]);
        }
    }
}

EzMissionTaskModel::Data::Data(const gs2::optional<gs2::mission::MissionTaskModel>& missionTaskModel) :
    name(missionTaskModel && missionTaskModel->getName() ? *missionTaskModel->getName() : StringHolder()),
    metadata(missionTaskModel && missionTaskModel->getMetadata() ? *missionTaskModel->getMetadata() : StringHolder()),
    counterName(missionTaskModel && missionTaskModel->getCounterName() ? *missionTaskModel->getCounterName() : StringHolder()),
    targetValue(missionTaskModel && missionTaskModel->getTargetValue() ? *missionTaskModel->getTargetValue() : 0),
    challengePeriodEventId(missionTaskModel && missionTaskModel->getChallengePeriodEventId() ? *missionTaskModel->getChallengePeriodEventId() : StringHolder()),
    premiseMissionTaskName(missionTaskModel && missionTaskModel->getPremiseMissionTaskName() ? *missionTaskModel->getPremiseMissionTaskName() : StringHolder())
{
    if (missionTaskModel && missionTaskModel->getCompleteAcquireActions())
    {
        for (int i = 0; i < missionTaskModel->getCompleteAcquireActions()->getCount(); ++i)
        {
            completeAcquireActions += EzAcquireAction((*missionTaskModel->getCompleteAcquireActions())[i]);
        }
    }
}

EzMissionTaskModel::EzMissionTaskModel(gs2::mission::MissionTaskModel missionTaskModel) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(missionTaskModel)
{
}

EzMissionTaskModel::EzMissionTaskModel(gs2::optional<gs2::mission::MissionTaskModel> missionTaskModel) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(missionTaskModel)
{
}

EzMissionTaskModel EzMissionTaskModel::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzMissionTaskModel);
}

gs2::mission::MissionTaskModel EzMissionTaskModel::ToModel() const
{
    gs2::mission::MissionTaskModel missionTaskModel;
    missionTaskModel.setName(getName());
    missionTaskModel.setMetadata(getMetadata());
    missionTaskModel.setCounterName(getCounterName());
    missionTaskModel.setTargetValue(getTargetValue());
    {
        gs2::List<gs2::mission::AcquireAction> list;
        auto& completeAcquireActions = getCompleteAcquireActions();
        for (int i = 0; i < completeAcquireActions.getCount(); ++i)
        {
            list += completeAcquireActions[i].ToModel();
        }
        missionTaskModel.setCompleteAcquireActions(list);
    }
    missionTaskModel.setChallengePeriodEventId(getChallengePeriodEventId());
    missionTaskModel.setPremiseMissionTaskName(getPremiseMissionTaskName());
    return missionTaskModel;
}

}}}