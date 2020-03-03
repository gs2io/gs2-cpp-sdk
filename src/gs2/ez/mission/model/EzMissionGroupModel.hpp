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

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "EzMissionTaskModel.hpp"
#include <memory>


namespace gs2 {

namespace mission {

class MissionGroupModel;

}

namespace ez { namespace mission {

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
        /** リセットタイミング */
        gs2::optional<StringHolder> resetType;
        /** リセットをする日にち */
        gs2::optional<Int32> resetDayOfMonth;
        /** リセットする曜日 */
        gs2::optional<StringHolder> resetDayOfWeek;
        /** リセット時刻 */
        gs2::optional<Int32> resetHour;
        /** ミッションを達成したときの通知先ネームスペース のGRN */
        gs2::optional<StringHolder> completeNotificationNamespaceId;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::mission::MissionGroupModel& missionGroupModel);
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

    EzMissionGroupModel(gs2::mission::MissionGroupModel missionGroupModel);

    EzMissionGroupModel& operator=(const EzMissionGroupModel& ezMissionGroupModel) = default;
    EzMissionGroupModel& operator=(EzMissionGroupModel&& ezMissionGroupModel) = default;

    EzMissionGroupModel deepCopy() const;

    gs2::mission::MissionGroupModel ToModel() const;

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

    const StringHolder& getResetType() const
    {
        return *ensureData().resetType;
    }

    Int32 getResetDayOfMonth() const
    {
        return *ensureData().resetDayOfMonth;
    }

    const StringHolder& getResetDayOfWeek() const
    {
        return *ensureData().resetDayOfWeek;
    }

    Int32 getResetHour() const
    {
        return *ensureData().resetHour;
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

    void setResetType(StringHolder resetType)
    {
        ensureData().resetType = std::move(resetType);
    }

    void setResetDayOfMonth(Int32 resetDayOfMonth)
    {
        ensureData().resetDayOfMonth = resetDayOfMonth;
    }

    void setResetDayOfWeek(StringHolder resetDayOfWeek)
    {
        ensureData().resetDayOfWeek = std::move(resetDayOfWeek);
    }

    void setResetHour(Int32 resetHour)
    {
        ensureData().resetHour = resetHour;
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

    EzMissionGroupModel& withResetType(StringHolder resetType)
    {
        setResetType(std::move(resetType));
        return *this;
    }

    EzMissionGroupModel& withResetDayOfMonth(Int32 resetDayOfMonth)
    {
        setResetDayOfMonth(resetDayOfMonth);
        return *this;
    }

    EzMissionGroupModel& withResetDayOfWeek(StringHolder resetDayOfWeek)
    {
        setResetDayOfWeek(std::move(resetDayOfWeek));
        return *this;
    }

    EzMissionGroupModel& withResetHour(Int32 resetHour)
    {
        setResetHour(resetHour);
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