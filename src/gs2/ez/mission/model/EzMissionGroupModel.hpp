

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

#ifndef GS2_EZ_MISSION_MODEL_EZMISSIONGROUPMODEL_HPP_
#define GS2_EZ_MISSION_MODEL_EZMISSIONGROUPMODEL_HPP_

#include <gs2/mission/model/MissionGroupModel.hpp>
#include "EzMissionTaskModel.hpp"


namespace gs2 { namespace ez { namespace mission {

class EzMissionGroupModel : public gs2::Gs2Object
{
private:
    /** グループ名 */
    gs2::optional<StringHolder> m_Name;
    /** メタデータ */
    gs2::optional<StringHolder> m_Metadata;
    /** タスクリスト */
    gs2::optional<List<EzMissionTaskModel>> m_Tasks;
    /** ミッションを達成したときの通知先ネームスペース のGRN */
    gs2::optional<StringHolder> m_CompleteNotificationNamespaceId;

public:
    EzMissionGroupModel() = default;

    EzMissionGroupModel(gs2::mission::MissionGroupModel missionGroupModel) :
        m_Name(missionGroupModel.getName()),
        m_Metadata(missionGroupModel.getMetadata()),
        m_CompleteNotificationNamespaceId(missionGroupModel.getCompleteNotificationNamespaceId())
    {
        m_Tasks.emplace();
        if (missionGroupModel.getTasks())
        {
            for (int i = 0; i < missionGroupModel.getTasks()->getCount(); ++i)
            {
                *m_Tasks += EzMissionTaskModel((*missionGroupModel.getTasks())[i]);
            }
        }
    }

    gs2::mission::MissionGroupModel ToModel() const
    {
        gs2::mission::MissionGroupModel missionGroupModel;
        missionGroupModel.setName(*m_Name);
        missionGroupModel.setMetadata(*m_Metadata);
        {
            gs2::List<gs2::mission::MissionTaskModel> list;
            auto& tasks = *m_Tasks;
            for (int i = 0; i < tasks.getCount(); ++i)
            {
                list += tasks[i].ToModel();
            }
            missionGroupModel.setTasks(list);
        }
        missionGroupModel.setCompleteNotificationNamespaceId(*m_CompleteNotificationNamespaceId);
        return missionGroupModel;
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

    const List<EzMissionTaskModel>& getTasks() const
    {
        return *m_Tasks;
    }

    List<EzMissionTaskModel>& getTasks()
    {
        return *m_Tasks;
    }

    const gs2::StringHolder& getCompleteNotificationNamespaceId() const
    {
        return *m_CompleteNotificationNamespaceId;
    }

    gs2::StringHolder& getCompleteNotificationNamespaceId()
    {
        return *m_CompleteNotificationNamespaceId;
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

    void setTasks(const List<EzMissionTaskModel>& tasks)
    {
        m_Tasks = tasks;
    }

    void setTasks(List<EzMissionTaskModel>&& tasks)
    {
        m_Tasks = std::move(tasks);
    }

    void setCompleteNotificationNamespaceId(Char* completeNotificationNamespaceId)
    {
        m_CompleteNotificationNamespaceId.emplace(completeNotificationNamespaceId);
    }

    EzMissionGroupModel& withName(Char* name)
    {
        setName(name);
        return *this;
    }

    EzMissionGroupModel& withMetadata(Char* metadata)
    {
        setMetadata(metadata);
        return *this;
    }

    EzMissionGroupModel& withTasks(const List<EzMissionTaskModel>& tasks)
    {
        setTasks(tasks);
        return *this;
    }

    EzMissionGroupModel& withTasks(List<EzMissionTaskModel>&& tasks)
    {
        setTasks(std::move(tasks));
        return *this;
    }

    EzMissionGroupModel& withCompleteNotificationNamespaceId(Char* completeNotificationNamespaceId)
    {
        setCompleteNotificationNamespaceId(completeNotificationNamespaceId);
        return *this;
    }
};

}}}

#endif //GS2_EZ_MISSION_EZMISSIONGROUPMODEL_HPP_