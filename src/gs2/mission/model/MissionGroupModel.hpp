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

#ifndef GS2_MISSION_MODEL_MISSIONGROUPMODEL_HPP_
#define GS2_MISSION_MODEL_MISSIONGROUPMODEL_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "MissionTaskModel.hpp"
#include <memory>

namespace gs2 { namespace mission {

/**
 * ミッショングループ
 *
 * @author Game Server Services, Inc.
 *
 */
class MissionGroupModel : public Gs2Object
{
    friend bool operator!=(const MissionGroupModel& lhs, const MissionGroupModel& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** ミッショングループ */
        optional<StringHolder> missionGroupId;
        /** グループ名 */
        optional<StringHolder> name;
        /** メタデータ */
        optional<StringHolder> metadata;
        /** タスクリスト */
        optional<List<MissionTaskModel>> tasks;
        /** ミッションを達成したときの通知先ネームスペース のGRN */
        optional<StringHolder> completeNotificationNamespaceId;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        ~Data() GS2_OVERRIDE = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        void set(const Char name_[], const detail::json::JsonConstValue& jsonValue) GS2_OVERRIDE;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    MissionGroupModel() = default;
    MissionGroupModel(const MissionGroupModel& missionGroupModel) = default;
    MissionGroupModel(MissionGroupModel&& missionGroupModel) = default;
    ~MissionGroupModel() = default;

    MissionGroupModel& operator=(const MissionGroupModel& missionGroupModel) = default;
    MissionGroupModel& operator=(MissionGroupModel&& missionGroupModel) = default;

    MissionGroupModel deepCopy() const;

    const MissionGroupModel* operator->() const
    {
        return this;
    }

    MissionGroupModel* operator->()
    {
        return this;
    }
    /**
     * ミッショングループを取得
     *
     * @return ミッショングループ
     */
    const optional<StringHolder>& getMissionGroupId() const
    {
        return ensureData().missionGroupId;
    }

    /**
     * ミッショングループを設定
     *
     * @param missionGroupId ミッショングループ
     */
    void setMissionGroupId(StringHolder missionGroupId)
    {
        ensureData().missionGroupId.emplace(std::move(missionGroupId));
    }

    /**
     * ミッショングループを設定
     *
     * @param missionGroupId ミッショングループ
     */
    MissionGroupModel& withMissionGroupId(StringHolder missionGroupId)
    {
        setMissionGroupId(std::move(missionGroupId));
        return *this;
    }

    /**
     * グループ名を取得
     *
     * @return グループ名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * グループ名を設定
     *
     * @param name グループ名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * グループ名を設定
     *
     * @param name グループ名
     */
    MissionGroupModel& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * メタデータを取得
     *
     * @return メタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * メタデータを設定
     *
     * @param metadata メタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * メタデータを設定
     *
     * @param metadata メタデータ
     */
    MissionGroupModel& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    /**
     * タスクリストを取得
     *
     * @return タスクリスト
     */
    const optional<List<MissionTaskModel>>& getTasks() const
    {
        return ensureData().tasks;
    }

    /**
     * タスクリストを設定
     *
     * @param tasks タスクリスト
     */
    void setTasks(List<MissionTaskModel> tasks)
    {
        ensureData().tasks.emplace(std::move(tasks));
    }

    /**
     * タスクリストを設定
     *
     * @param tasks タスクリスト
     */
    MissionGroupModel& withTasks(List<MissionTaskModel> tasks)
    {
        setTasks(std::move(tasks));
        return *this;
    }

    /**
     * ミッションを達成したときの通知先ネームスペース のGRNを取得
     *
     * @return ミッションを達成したときの通知先ネームスペース のGRN
     */
    const optional<StringHolder>& getCompleteNotificationNamespaceId() const
    {
        return ensureData().completeNotificationNamespaceId;
    }

    /**
     * ミッションを達成したときの通知先ネームスペース のGRNを設定
     *
     * @param completeNotificationNamespaceId ミッションを達成したときの通知先ネームスペース のGRN
     */
    void setCompleteNotificationNamespaceId(StringHolder completeNotificationNamespaceId)
    {
        ensureData().completeNotificationNamespaceId.emplace(std::move(completeNotificationNamespaceId));
    }

    /**
     * ミッションを達成したときの通知先ネームスペース のGRNを設定
     *
     * @param completeNotificationNamespaceId ミッションを達成したときの通知先ネームスペース のGRN
     */
    MissionGroupModel& withCompleteNotificationNamespaceId(StringHolder completeNotificationNamespaceId)
    {
        setCompleteNotificationNamespaceId(std::move(completeNotificationNamespaceId));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const MissionGroupModel& lhs, const MissionGroupModel& lhr);

inline bool operator==(const MissionGroupModel& lhs, const MissionGroupModel& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_MISSION_MODEL_MISSIONGROUPMODEL_HPP_