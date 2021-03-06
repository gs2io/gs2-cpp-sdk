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

#include "EzQuestModel.hpp"
#include <gs2/quest/model/QuestModel.hpp>


namespace gs2 { namespace ez { namespace quest {

EzQuestModel::Data::Data(const Data& data) :
    Gs2Object(data),
    questModelId(data.questModelId),
    name(data.name),
    metadata(data.metadata),
    challengePeriodEventId(data.challengePeriodEventId)
{
    if (data.contents)
    {
        contents = data.contents->deepCopy();
    }
    if (data.consumeActions)
    {
        consumeActions = data.consumeActions->deepCopy();
    }
    if (data.failedAcquireActions)
    {
        failedAcquireActions = data.failedAcquireActions->deepCopy();
    }
    if (data.premiseQuestNames)
    {
        premiseQuestNames = data.premiseQuestNames->deepCopy();
    }
}

EzQuestModel::Data::Data(const gs2::quest::QuestModel& questModel) :
    questModelId(questModel.getQuestModelId()),
    name(questModel.getName()),
    metadata(questModel.getMetadata()),
    challengePeriodEventId(questModel.getChallengePeriodEventId()),
    premiseQuestNames(questModel.getPremiseQuestNames())
{
    contents.emplace();
    if (questModel.getContents())
    {
        for (int i = 0; i < questModel.getContents()->getCount(); ++i)
        {
            *contents += EzContents((*questModel.getContents())[i]);
        }
    }
    consumeActions.emplace();
    if (questModel.getConsumeActions())
    {
        for (int i = 0; i < questModel.getConsumeActions()->getCount(); ++i)
        {
            *consumeActions += EzConsumeAction((*questModel.getConsumeActions())[i]);
        }
    }
    failedAcquireActions.emplace();
    if (questModel.getFailedAcquireActions())
    {
        for (int i = 0; i < questModel.getFailedAcquireActions()->getCount(); ++i)
        {
            *failedAcquireActions += EzAcquireAction((*questModel.getFailedAcquireActions())[i]);
        }
    }
}

EzQuestModel::EzQuestModel(gs2::quest::QuestModel questModel) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(questModel)
{
}

EzQuestModel EzQuestModel::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzQuestModel);
}

gs2::quest::QuestModel EzQuestModel::ToModel() const
{
    gs2::quest::QuestModel questModel;
    questModel.setQuestModelId(getQuestModelId());
    questModel.setName(getName());
    questModel.setMetadata(getMetadata());
    {
        gs2::List<gs2::quest::Contents> list;
        auto& contents = getContents();
        for (int i = 0; i < contents.getCount(); ++i)
        {
            list += contents[i].ToModel();
        }
        questModel.setContents(list);
    }
    questModel.setChallengePeriodEventId(getChallengePeriodEventId());
    {
        gs2::List<gs2::quest::ConsumeAction> list;
        auto& consumeActions = getConsumeActions();
        for (int i = 0; i < consumeActions.getCount(); ++i)
        {
            list += consumeActions[i].ToModel();
        }
        questModel.setConsumeActions(list);
    }
    {
        gs2::List<gs2::quest::AcquireAction> list;
        auto& failedAcquireActions = getFailedAcquireActions();
        for (int i = 0; i < failedAcquireActions.getCount(); ++i)
        {
            list += failedAcquireActions[i].ToModel();
        }
        questModel.setFailedAcquireActions(list);
    }
    questModel.setPremiseQuestNames(getPremiseQuestNames());
    return questModel;
}

}}}