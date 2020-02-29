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
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "MissionTaskModel.hpp"
#include <memory>
#include <cstring>

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
        /** リセットタイミング */
        optional<StringHolder> resetType;
        /** リセットをする日にち */
        optional<Int32> resetDayOfMonth;
        /** リセットする曜日 */
        optional<StringHolder> resetDayOfWeek;
        /** リセット時刻 */
        optional<Int32> resetHour;
        /** ミッションを達成したときの通知先ネームスペース のGRN */
        optional<StringHolder> completeNotificationNamespaceId;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            missionGroupId(data.missionGroupId),
            name(data.name),
            metadata(data.metadata),
            resetType(data.resetType),
            resetDayOfMonth(data.resetDayOfMonth),
            resetDayOfWeek(data.resetDayOfWeek),
            resetHour(data.resetHour),
            completeNotificationNamespaceId(data.completeNotificationNamespaceId)
        {
            if (data.tasks)
            {
                tasks = data.tasks->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "missionGroupId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->missionGroupId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "metadata") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "tasks") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->tasks.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        MissionTaskModel item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        *this->tasks += std::move(item);
                    }
                }
            }
            else if (std::strcmp(name_, "resetType") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->resetType.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "resetDayOfMonth") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->resetDayOfMonth = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "resetDayOfWeek") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->resetDayOfWeek.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "resetHour") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->resetHour = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "completeNotificationNamespaceId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->completeNotificationNamespaceId.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    MissionGroupModel() = default;
    MissionGroupModel(const MissionGroupModel& missionGroupModel) = default;
    MissionGroupModel(MissionGroupModel&& missionGroupModel) = default;
    ~MissionGroupModel() = default;

    MissionGroupModel& operator=(const MissionGroupModel& missionGroupModel) = default;
    MissionGroupModel& operator=(MissionGroupModel&& missionGroupModel) = default;

    MissionGroupModel deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(MissionGroupModel);
    }

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
     * リセットタイミングを取得
     *
     * @return リセットタイミング
     */
    const optional<StringHolder>& getResetType() const
    {
        return ensureData().resetType;
    }

    /**
     * リセットタイミングを設定
     *
     * @param resetType リセットタイミング
     */
    void setResetType(StringHolder resetType)
    {
        ensureData().resetType.emplace(std::move(resetType));
    }

    /**
     * リセットタイミングを設定
     *
     * @param resetType リセットタイミング
     */
    MissionGroupModel& withResetType(StringHolder resetType)
    {
        setResetType(std::move(resetType));
        return *this;
    }

    /**
     * リセットをする日にちを取得
     *
     * @return リセットをする日にち
     */
    const optional<Int32>& getResetDayOfMonth() const
    {
        return ensureData().resetDayOfMonth;
    }

    /**
     * リセットをする日にちを設定
     *
     * @param resetDayOfMonth リセットをする日にち
     */
    void setResetDayOfMonth(Int32 resetDayOfMonth)
    {
        ensureData().resetDayOfMonth.emplace(resetDayOfMonth);
    }

    /**
     * リセットをする日にちを設定
     *
     * @param resetDayOfMonth リセットをする日にち
     */
    MissionGroupModel& withResetDayOfMonth(Int32 resetDayOfMonth)
    {
        setResetDayOfMonth(resetDayOfMonth);
        return *this;
    }

    /**
     * リセットする曜日を取得
     *
     * @return リセットする曜日
     */
    const optional<StringHolder>& getResetDayOfWeek() const
    {
        return ensureData().resetDayOfWeek;
    }

    /**
     * リセットする曜日を設定
     *
     * @param resetDayOfWeek リセットする曜日
     */
    void setResetDayOfWeek(StringHolder resetDayOfWeek)
    {
        ensureData().resetDayOfWeek.emplace(std::move(resetDayOfWeek));
    }

    /**
     * リセットする曜日を設定
     *
     * @param resetDayOfWeek リセットする曜日
     */
    MissionGroupModel& withResetDayOfWeek(StringHolder resetDayOfWeek)
    {
        setResetDayOfWeek(std::move(resetDayOfWeek));
        return *this;
    }

    /**
     * リセット時刻を取得
     *
     * @return リセット時刻
     */
    const optional<Int32>& getResetHour() const
    {
        return ensureData().resetHour;
    }

    /**
     * リセット時刻を設定
     *
     * @param resetHour リセット時刻
     */
    void setResetHour(Int32 resetHour)
    {
        ensureData().resetHour.emplace(resetHour);
    }

    /**
     * リセット時刻を設定
     *
     * @param resetHour リセット時刻
     */
    MissionGroupModel& withResetHour(Int32 resetHour)
    {
        setResetHour(resetHour);
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

inline bool operator!=(const MissionGroupModel& lhs, const MissionGroupModel& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->missionGroupId != lhr.m_pData->missionGroupId)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->metadata != lhr.m_pData->metadata)
        {
            return true;
        }
        if (lhs.m_pData->tasks != lhr.m_pData->tasks)
        {
            return true;
        }
        if (lhs.m_pData->resetType != lhr.m_pData->resetType)
        {
            return true;
        }
        if (lhs.m_pData->resetDayOfMonth != lhr.m_pData->resetDayOfMonth)
        {
            return true;
        }
        if (lhs.m_pData->resetDayOfWeek != lhr.m_pData->resetDayOfWeek)
        {
            return true;
        }
        if (lhs.m_pData->resetHour != lhr.m_pData->resetHour)
        {
            return true;
        }
        if (lhs.m_pData->completeNotificationNamespaceId != lhr.m_pData->completeNotificationNamespaceId)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const MissionGroupModel& lhs, const MissionGroupModel& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_MISSION_MODEL_MISSIONGROUPMODEL_HPP_