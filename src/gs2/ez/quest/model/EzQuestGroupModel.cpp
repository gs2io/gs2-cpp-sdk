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

#include "EzQuestGroupModel.hpp"
#include <gs2/quest/model/QuestGroupModel.hpp>


namespace gs2 { namespace ez { namespace quest {

EzQuestGroupModel::Data::Data(const Data& data) :
    Gs2Object(data),
    name(data.name),
    metadata(data.metadata),
    challengePeriodEventId(data.challengePeriodEventId)
{
    if (data.quests)
    {
        quests = data.quests->deepCopy();
    }
}

EzQuestGroupModel::Data::Data(const gs2::quest::QuestGroupModel& questGroupModel) :
    name(questGroupModel.getName()),
    metadata(questGroupModel.getMetadata()),
    challengePeriodEventId(questGroupModel.getChallengePeriodEventId())
{
    quests.emplace();
    if (questGroupModel.getQuests())
    {
        for (int i = 0; i < questGroupModel.getQuests()->getCount(); ++i)
        {
            *quests += EzQuestModel((*questGroupModel.getQuests())[i]);
        }
    }
}

EzQuestGroupModel::EzQuestGroupModel(gs2::quest::QuestGroupModel questGroupModel) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(questGroupModel)
{
}

EzQuestGroupModel EzQuestGroupModel::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzQuestGroupModel);
}

gs2::quest::QuestGroupModel EzQuestGroupModel::ToModel() const
{
    gs2::quest::QuestGroupModel questGroupModel;
    questGroupModel.setName(getName());
    questGroupModel.setMetadata(getMetadata());
    {
        gs2::List<gs2::quest::QuestModel> list;
        auto& quests = getQuests();
        for (int i = 0; i < quests.getCount(); ++i)
        {
            list += quests[i].ToModel();
        }
        questGroupModel.setQuests(list);
    }
    questGroupModel.setChallengePeriodEventId(getChallengePeriodEventId());
    return questGroupModel;
}

}}}