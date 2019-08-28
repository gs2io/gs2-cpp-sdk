

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

#ifndef GS2_EZ_MISSION_MODEL_EZCOMPLETE_HPP_
#define GS2_EZ_MISSION_MODEL_EZCOMPLETE_HPP_

#include <gs2/mission/model/Complete.hpp>


namespace gs2 { namespace ez { namespace mission {

class EzComplete : public gs2::Gs2Object
{
private:
    /** ミッショングループ名 */
    gs2::optional<StringHolder> m_MissionGroupName;
    /** 達成済みのタスク名リスト */
    gs2::optional<List<StringHolder>> m_CompletedMissionTaskNames;
    /** 報酬の受け取り済みのタスク名リスト */
    gs2::optional<List<StringHolder>> m_ReceivedMissionTaskNames;

public:
    EzComplete() = default;

    EzComplete(gs2::mission::Complete complete) :
        m_MissionGroupName(complete.getMissionGroupName()),
        m_CompletedMissionTaskNames(complete.getCompletedMissionTaskNames()),
        m_ReceivedMissionTaskNames(complete.getReceivedMissionTaskNames())
    {
    }

    gs2::mission::Complete ToModel() const
    {
        gs2::mission::Complete complete;
        complete.setMissionGroupName(*m_MissionGroupName);
        complete.setCompletedMissionTaskNames(*m_CompletedMissionTaskNames);
        complete.setReceivedMissionTaskNames(*m_ReceivedMissionTaskNames);
        return complete;
    }

    // ========================================
    //   Getters
    // ========================================

    const gs2::StringHolder& getMissionGroupName() const
    {
        return *m_MissionGroupName;
    }

    gs2::StringHolder& getMissionGroupName()
    {
        return *m_MissionGroupName;
    }

    const List<StringHolder>& getCompletedMissionTaskNames() const
    {
        return *m_CompletedMissionTaskNames;
    }

    List<StringHolder>& getCompletedMissionTaskNames()
    {
        return *m_CompletedMissionTaskNames;
    }

    const List<StringHolder>& getReceivedMissionTaskNames() const
    {
        return *m_ReceivedMissionTaskNames;
    }

    List<StringHolder>& getReceivedMissionTaskNames()
    {
        return *m_ReceivedMissionTaskNames;
    }

    // ========================================
    //   Setters
    // ========================================

    void setMissionGroupName(Char* missionGroupName)
    {
        m_MissionGroupName.emplace(missionGroupName);
    }

    void setCompletedMissionTaskNames(const List<StringHolder>& completedMissionTaskNames)
    {
        m_CompletedMissionTaskNames = completedMissionTaskNames;
    }

    void setCompletedMissionTaskNames(List<StringHolder>&& completedMissionTaskNames)
    {
        m_CompletedMissionTaskNames = std::move(completedMissionTaskNames);
    }

    void setReceivedMissionTaskNames(const List<StringHolder>& receivedMissionTaskNames)
    {
        m_ReceivedMissionTaskNames = receivedMissionTaskNames;
    }

    void setReceivedMissionTaskNames(List<StringHolder>&& receivedMissionTaskNames)
    {
        m_ReceivedMissionTaskNames = std::move(receivedMissionTaskNames);
    }

    EzComplete& withMissionGroupName(Char* missionGroupName)
    {
        setMissionGroupName(missionGroupName);
        return *this;
    }

    EzComplete& withCompletedMissionTaskNames(const List<StringHolder>& completedMissionTaskNames)
    {
        setCompletedMissionTaskNames(completedMissionTaskNames);
        return *this;
    }

    EzComplete& withCompletedMissionTaskNames(List<StringHolder>&& completedMissionTaskNames)
    {
        setCompletedMissionTaskNames(std::move(completedMissionTaskNames));
        return *this;
    }

    EzComplete& withReceivedMissionTaskNames(const List<StringHolder>& receivedMissionTaskNames)
    {
        setReceivedMissionTaskNames(receivedMissionTaskNames);
        return *this;
    }

    EzComplete& withReceivedMissionTaskNames(List<StringHolder>&& receivedMissionTaskNames)
    {
        setReceivedMissionTaskNames(std::move(receivedMissionTaskNames));
        return *this;
    }
};

}}}

#endif //GS2_EZ_MISSION_EZCOMPLETE_HPP_