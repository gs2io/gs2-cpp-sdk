

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
    class Data : public gs2::Gs2Object
    {
    public:
        /** グループ名 */
        gs2::optional<StringHolder> name;
        /** メタデータ */
        gs2::optional<StringHolder> metadata;
        /** タスクリスト */
        gs2::optional<List<EzMissionTaskModel>> tasks;
        /** ミッションを達成したときの通知先ネームスペース のGRN */
        gs2::optional<StringHolder> completeNotificationNamespaceId;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            name(data.name),
            metadata(data.metadata),
            completeNotificationNamespaceId(data.completeNotificationNamespaceId)
        {
            if (data.tasks)
            {
                tasks = data.tasks->deepCopy();
            }
        }

        Data(Data&& data) = default;

        Data(const gs2::mission::MissionGroupModel& missionGroupModel) :
            name(missionGroupModel.getName()),
            metadata(missionGroupModel.getMetadata()),
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

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzMissionGroupModel() = default;
    EzMissionGroupModel(const EzMissionGroupModel& ezMissionGroupModel) = default;
    EzMissionGroupModel(EzMissionGroupModel&& ezMissionGroupModel) = default;
    ~EzMissionGroupModel() = default;

    EzMissionGroupModel(gs2::mission::MissionGroupModel missionGroupModel) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(missionGroupModel)
    {}

    EzMissionGroupModel& operator=(const EzMissionGroupModel& ezMissionGroupModel) = default;
    EzMissionGroupModel& operator=(EzMissionGroupModel&& ezMissionGroupModel) = default;

    EzMissionGroupModel deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzMissionGroupModel);
    }

    gs2::mission::MissionGroupModel ToModel() const
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
        missionGroupModel.setCompleteNotificationNamespaceId(getCompleteNotificationNamespaceId());
        return missionGroupModel;
    }

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getName() const
    {
        return *ensureData().name;
    }

    const StringHolder& getMetadata() const
    {
        return *ensureData().metadata;
    }

    const List<EzMissionTaskModel>& getTasks() const
    {
        return *ensureData().tasks;
    }

    const StringHolder& getCompleteNotificationNamespaceId() const
    {
        return *ensureData().completeNotificationNamespaceId;
    }

    // ========================================
    //   Setters
    // ========================================

    void setName(StringHolder name)
    {
        ensureData().name = std::move(name);
    }

    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata = std::move(metadata);
    }

    void setTasks(List<EzMissionTaskModel> tasks)
    {
        ensureData().tasks = std::move(tasks);
    }

    void setCompleteNotificationNamespaceId(StringHolder completeNotificationNamespaceId)
    {
        ensureData().completeNotificationNamespaceId = std::move(completeNotificationNamespaceId);
    }

    EzMissionGroupModel& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    EzMissionGroupModel& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    EzMissionGroupModel& withTasks(List<EzMissionTaskModel> tasks)
    {
        setTasks(std::move(tasks));
        return *this;
    }

    EzMissionGroupModel& withCompleteNotificationNamespaceId(StringHolder completeNotificationNamespaceId)
    {
        setCompleteNotificationNamespaceId(std::move(completeNotificationNamespaceId));
        return *this;
    }
};

}}}

#endif //GS2_EZ_MISSION_EZMISSIONGROUPMODEL_HPP_