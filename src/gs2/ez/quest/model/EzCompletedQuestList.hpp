

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

#ifndef GS2_EZ_QUEST_MODEL_EZCOMPLETEDQUESTLIST_HPP_
#define GS2_EZ_QUEST_MODEL_EZCOMPLETEDQUESTLIST_HPP_

#include <gs2/quest/model/CompletedQuestList.hpp>


namespace gs2 { namespace ez { namespace quest {

class EzCompletedQuestList : public gs2::Gs2Object
{
private:
    /** クエストグループ名 */
    gs2::optional<StringHolder> m_QuestGroupName;
    /** 攻略済みのクエスト名一覧のリスト */
    gs2::optional<List<StringHolder>> m_CompleteQuestNames;

public:
    EzCompletedQuestList() = default;

    EzCompletedQuestList(gs2::quest::CompletedQuestList completedQuestList) :
        m_QuestGroupName(completedQuestList.getQuestGroupName()),
        m_CompleteQuestNames(completedQuestList.getCompleteQuestNames())
    {
    }

    gs2::quest::CompletedQuestList ToModel() const
    {
        gs2::quest::CompletedQuestList completedQuestList;
        completedQuestList.setQuestGroupName(*m_QuestGroupName);
        completedQuestList.setCompleteQuestNames(*m_CompleteQuestNames);
        return completedQuestList;
    }

    // ========================================
    //   Getters
    // ========================================

    const gs2::StringHolder& getQuestGroupName() const
    {
        return *m_QuestGroupName;
    }

    gs2::StringHolder& getQuestGroupName()
    {
        return *m_QuestGroupName;
    }

    const List<StringHolder>& getCompleteQuestNames() const
    {
        return *m_CompleteQuestNames;
    }

    List<StringHolder>& getCompleteQuestNames()
    {
        return *m_CompleteQuestNames;
    }

    // ========================================
    //   Setters
    // ========================================

    void setQuestGroupName(Char* questGroupName)
    {
        m_QuestGroupName.emplace(questGroupName);
    }

    void setCompleteQuestNames(const List<StringHolder>& completeQuestNames)
    {
        m_CompleteQuestNames = completeQuestNames;
    }

    void setCompleteQuestNames(List<StringHolder>&& completeQuestNames)
    {
        m_CompleteQuestNames = std::move(completeQuestNames);
    }

    EzCompletedQuestList& withQuestGroupName(Char* questGroupName)
    {
        setQuestGroupName(questGroupName);
        return *this;
    }

    EzCompletedQuestList& withCompleteQuestNames(const List<StringHolder>& completeQuestNames)
    {
        setCompleteQuestNames(completeQuestNames);
        return *this;
    }

    EzCompletedQuestList& withCompleteQuestNames(List<StringHolder>&& completeQuestNames)
    {
        setCompleteQuestNames(std::move(completeQuestNames));
        return *this;
    }
};

}}}

#endif //GS2_EZ_QUEST_EZCOMPLETEDQUESTLIST_HPP_