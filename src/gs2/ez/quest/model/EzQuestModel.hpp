

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

#ifndef GS2_EZ_QUEST_MODEL_EZQUESTMODEL_HPP_
#define GS2_EZ_QUEST_MODEL_EZQUESTMODEL_HPP_

#include <gs2/quest/model/QuestModel.hpp>
#include "EzContents.hpp"
#include "EzConsumeAction.hpp"
#include "EzAcquireAction.hpp"


namespace gs2 { namespace ez { namespace quest {

class EzQuestModel : public gs2::Gs2Object
{
private:
    /** クエストモデル名 */
    gs2::optional<StringHolder> m_Name;
    /** クエストモデルのメタデータ */
    gs2::optional<StringHolder> m_Metadata;
    /** クエストの内容 */
    gs2::optional<List<EzContents>> m_Contents;
    /** 挑戦可能な期間を指定するイベントマスター のGRN */
    gs2::optional<StringHolder> m_ChallengePeriodEventId;
    /** クエストの参加料 */
    gs2::optional<List<EzConsumeAction>> m_ConsumeActions;
    /** クエスト失敗時の報酬 */
    gs2::optional<List<EzAcquireAction>> m_FailedAcquireActions;
    /** クエストに挑戦するためにクリアしておく必要のあるクエスト名 */
    gs2::optional<List<StringHolder>> m_PremiseQuestNames;

public:
    EzQuestModel() = default;

    EzQuestModel(gs2::quest::QuestModel questModel) :
        m_Name(questModel.getName()),
        m_Metadata(questModel.getMetadata()),
        m_ChallengePeriodEventId(questModel.getChallengePeriodEventId()),
        m_PremiseQuestNames(questModel.getPremiseQuestNames())
    {
        m_Contents.emplace();
        if (questModel.getContents())
        {
            for (int i = 0; i < questModel.getContents()->getCount(); ++i)
            {
                *m_Contents += EzContents((*questModel.getContents())[i]);
            }
        }
        m_ConsumeActions.emplace();
        if (questModel.getConsumeActions())
        {
            for (int i = 0; i < questModel.getConsumeActions()->getCount(); ++i)
            {
                *m_ConsumeActions += EzConsumeAction((*questModel.getConsumeActions())[i]);
            }
        }
        m_FailedAcquireActions.emplace();
        if (questModel.getFailedAcquireActions())
        {
            for (int i = 0; i < questModel.getFailedAcquireActions()->getCount(); ++i)
            {
                *m_FailedAcquireActions += EzAcquireAction((*questModel.getFailedAcquireActions())[i]);
            }
        }
    }

    gs2::quest::QuestModel ToModel() const
    {
        gs2::quest::QuestModel questModel;
        questModel.setName(*m_Name);
        questModel.setMetadata(*m_Metadata);
        {
            gs2::List<gs2::quest::Contents> list;
            auto& contents = *m_Contents;
            for (int i = 0; i < contents.getCount(); ++i)
            {
                list += contents[i].ToModel();
            }
            questModel.setContents(list);
        }
        questModel.setChallengePeriodEventId(*m_ChallengePeriodEventId);
        {
            gs2::List<gs2::quest::ConsumeAction> list;
            auto& consumeActions = *m_ConsumeActions;
            for (int i = 0; i < consumeActions.getCount(); ++i)
            {
                list += consumeActions[i].ToModel();
            }
            questModel.setConsumeActions(list);
        }
        {
            gs2::List<gs2::quest::AcquireAction> list;
            auto& failedAcquireActions = *m_FailedAcquireActions;
            for (int i = 0; i < failedAcquireActions.getCount(); ++i)
            {
                list += failedAcquireActions[i].ToModel();
            }
            questModel.setFailedAcquireActions(list);
        }
        questModel.setPremiseQuestNames(*m_PremiseQuestNames);
        return questModel;
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

    const List<EzContents>& getContents() const
    {
        return *m_Contents;
    }

    List<EzContents>& getContents()
    {
        return *m_Contents;
    }

    const gs2::StringHolder& getChallengePeriodEventId() const
    {
        return *m_ChallengePeriodEventId;
    }

    gs2::StringHolder& getChallengePeriodEventId()
    {
        return *m_ChallengePeriodEventId;
    }

    const List<EzConsumeAction>& getConsumeActions() const
    {
        return *m_ConsumeActions;
    }

    List<EzConsumeAction>& getConsumeActions()
    {
        return *m_ConsumeActions;
    }

    const List<EzAcquireAction>& getFailedAcquireActions() const
    {
        return *m_FailedAcquireActions;
    }

    List<EzAcquireAction>& getFailedAcquireActions()
    {
        return *m_FailedAcquireActions;
    }

    const List<StringHolder>& getPremiseQuestNames() const
    {
        return *m_PremiseQuestNames;
    }

    List<StringHolder>& getPremiseQuestNames()
    {
        return *m_PremiseQuestNames;
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

    void setContents(const List<EzContents>& contents)
    {
        m_Contents = contents;
    }

    void setContents(List<EzContents>&& contents)
    {
        m_Contents = std::move(contents);
    }

    void setChallengePeriodEventId(Char* challengePeriodEventId)
    {
        m_ChallengePeriodEventId.emplace(challengePeriodEventId);
    }

    void setConsumeActions(const List<EzConsumeAction>& consumeActions)
    {
        m_ConsumeActions = consumeActions;
    }

    void setConsumeActions(List<EzConsumeAction>&& consumeActions)
    {
        m_ConsumeActions = std::move(consumeActions);
    }

    void setFailedAcquireActions(const List<EzAcquireAction>& failedAcquireActions)
    {
        m_FailedAcquireActions = failedAcquireActions;
    }

    void setFailedAcquireActions(List<EzAcquireAction>&& failedAcquireActions)
    {
        m_FailedAcquireActions = std::move(failedAcquireActions);
    }

    void setPremiseQuestNames(const List<StringHolder>& premiseQuestNames)
    {
        m_PremiseQuestNames = premiseQuestNames;
    }

    void setPremiseQuestNames(List<StringHolder>&& premiseQuestNames)
    {
        m_PremiseQuestNames = std::move(premiseQuestNames);
    }

    EzQuestModel& withName(Char* name)
    {
        setName(name);
        return *this;
    }

    EzQuestModel& withMetadata(Char* metadata)
    {
        setMetadata(metadata);
        return *this;
    }

    EzQuestModel& withContents(const List<EzContents>& contents)
    {
        setContents(contents);
        return *this;
    }

    EzQuestModel& withContents(List<EzContents>&& contents)
    {
        setContents(std::move(contents));
        return *this;
    }

    EzQuestModel& withChallengePeriodEventId(Char* challengePeriodEventId)
    {
        setChallengePeriodEventId(challengePeriodEventId);
        return *this;
    }

    EzQuestModel& withConsumeActions(const List<EzConsumeAction>& consumeActions)
    {
        setConsumeActions(consumeActions);
        return *this;
    }

    EzQuestModel& withConsumeActions(List<EzConsumeAction>&& consumeActions)
    {
        setConsumeActions(std::move(consumeActions));
        return *this;
    }

    EzQuestModel& withFailedAcquireActions(const List<EzAcquireAction>& failedAcquireActions)
    {
        setFailedAcquireActions(failedAcquireActions);
        return *this;
    }

    EzQuestModel& withFailedAcquireActions(List<EzAcquireAction>&& failedAcquireActions)
    {
        setFailedAcquireActions(std::move(failedAcquireActions));
        return *this;
    }

    EzQuestModel& withPremiseQuestNames(const List<StringHolder>& premiseQuestNames)
    {
        setPremiseQuestNames(premiseQuestNames);
        return *this;
    }

    EzQuestModel& withPremiseQuestNames(List<StringHolder>&& premiseQuestNames)
    {
        setPremiseQuestNames(std::move(premiseQuestNames));
        return *this;
    }
};

}}}

#endif //GS2_EZ_QUEST_EZQUESTMODEL_HPP_