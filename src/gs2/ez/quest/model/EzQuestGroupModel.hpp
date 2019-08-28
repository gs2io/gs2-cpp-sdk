

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

#ifndef GS2_EZ_QUEST_MODEL_EZQUESTGROUPMODEL_HPP_
#define GS2_EZ_QUEST_MODEL_EZQUESTGROUPMODEL_HPP_

#include <gs2/quest/model/QuestGroupModel.hpp>
#include "EzQuestModel.hpp"


namespace gs2 { namespace ez { namespace quest {

class EzQuestGroupModel : public gs2::Gs2Object
{
private:
    /** クエストグループ名 */
    gs2::optional<StringHolder> m_Name;
    /** クエストグループのメタデータ */
    gs2::optional<StringHolder> m_Metadata;
    /** グループに属するクエスト */
    gs2::optional<List<EzQuestModel>> m_Quests;
    /** 挑戦可能な期間を指定するイベントマスター のGRN */
    gs2::optional<StringHolder> m_ChallengePeriodEventId;

public:
    EzQuestGroupModel() = default;

    EzQuestGroupModel(gs2::quest::QuestGroupModel questGroupModel) :
        m_Name(questGroupModel.getName()),
        m_Metadata(questGroupModel.getMetadata()),
        m_ChallengePeriodEventId(questGroupModel.getChallengePeriodEventId())
    {
        m_Quests.emplace();
        if (questGroupModel.getQuests())
        {
            for (int i = 0; i < questGroupModel.getQuests()->getCount(); ++i)
            {
                *m_Quests += EzQuestModel((*questGroupModel.getQuests())[i]);
            }
        }
    }

    gs2::quest::QuestGroupModel ToModel() const
    {
        gs2::quest::QuestGroupModel questGroupModel;
        questGroupModel.setName(*m_Name);
        questGroupModel.setMetadata(*m_Metadata);
        {
            gs2::List<gs2::quest::QuestModel> list;
            auto& quests = *m_Quests;
            for (int i = 0; i < quests.getCount(); ++i)
            {
                list += quests[i].ToModel();
            }
            questGroupModel.setQuests(list);
        }
        questGroupModel.setChallengePeriodEventId(*m_ChallengePeriodEventId);
        return questGroupModel;
    }

    // ========================================
    //   Getters
    // ========================================

    const gs2::StringHolder& getName() const
    {
        return *m_Name;
    }

    gs2::StringHolder& getName()
    {
        return *m_Name;
    }

    const gs2::StringHolder& getMetadata() const
    {
        return *m_Metadata;
    }

    gs2::StringHolder& getMetadata()
    {
        return *m_Metadata;
    }

    const List<EzQuestModel>& getQuests() const
    {
        return *m_Quests;
    }

    List<EzQuestModel>& getQuests()
    {
        return *m_Quests;
    }

    const gs2::StringHolder& getChallengePeriodEventId() const
    {
        return *m_ChallengePeriodEventId;
    }

    gs2::StringHolder& getChallengePeriodEventId()
    {
        return *m_ChallengePeriodEventId;
    }

    // ========================================
    //   Setters
    // ========================================

    void setName(Char* name)
    {
        m_Name.emplace(name);
    }

    void setMetadata(Char* metadata)
    {
        m_Metadata.emplace(metadata);
    }

    void setQuests(const List<EzQuestModel>& quests)
    {
        m_Quests = quests;
    }

    void setQuests(List<EzQuestModel>&& quests)
    {
        m_Quests = std::move(quests);
    }

    void setChallengePeriodEventId(Char* challengePeriodEventId)
    {
        m_ChallengePeriodEventId.emplace(challengePeriodEventId);
    }

    EzQuestGroupModel& withName(Char* name)
    {
        setName(name);
        return *this;
    }

    EzQuestGroupModel& withMetadata(Char* metadata)
    {
        setMetadata(metadata);
        return *this;
    }

    EzQuestGroupModel& withQuests(const List<EzQuestModel>& quests)
    {
        setQuests(quests);
        return *this;
    }

    EzQuestGroupModel& withQuests(List<EzQuestModel>&& quests)
    {
        setQuests(std::move(quests));
        return *this;
    }

    EzQuestGroupModel& withChallengePeriodEventId(Char* challengePeriodEventId)
    {
        setChallengePeriodEventId(challengePeriodEventId);
        return *this;
    }
};

}}}

#endif //GS2_EZ_QUEST_EZQUESTGROUPMODEL_HPP_