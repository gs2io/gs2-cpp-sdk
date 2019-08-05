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
#include <gs2/core/external/optional/optional.hpp>
#include "MissionTaskModel.hpp"
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
        /** ミッションを達成したときの通知先ネームスペース のGRN */
        optional<StringHolder> completeNotificationNamespaceId;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            missionGroupId(data.missionGroupId),
            name(data.name),
            metadata(data.metadata),
            tasks(data.tasks),
            completeNotificationNamespaceId(data.completeNotificationNamespaceId)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            missionGroupId(std::move(data.missionGroupId)),
            name(std::move(data.name)),
            metadata(std::move(data.metadata)),
            tasks(std::move(data.tasks)),
            completeNotificationNamespaceId(std::move(data.completeNotificationNamespaceId))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "missionGroupId") == 0) {
                if (jsonValue.IsString())
                {
                    this->missionGroupId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "metadata") == 0) {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "tasks") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->tasks.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        MissionTaskModel item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        detail::addToList(*this->tasks, std::move(item));
                    }
                }
            }
            else if (std::strcmp(name, "completeNotificationNamespaceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->completeNotificationNamespaceId.emplace(jsonValue.GetString());
                }
            }
        }
    };

    Data* m_pData;

    Data& ensureData() {
        if (m_pData == nullptr) {
            m_pData = new Data();
        }
        return *m_pData;
    }

    const Data& ensureData() const {
        if (m_pData == nullptr) {
            *const_cast<Data**>(&m_pData) = new Data();
        }
        return *m_pData;
    }

public:
    MissionGroupModel() :
        m_pData(nullptr)
    {}

    MissionGroupModel(const MissionGroupModel& missionGroupModel) :
        Gs2Object(missionGroupModel),
        m_pData(missionGroupModel.m_pData != nullptr ? new Data(*missionGroupModel.m_pData) : nullptr)
    {}

    MissionGroupModel(MissionGroupModel&& missionGroupModel) :
        Gs2Object(std::move(missionGroupModel)),
        m_pData(missionGroupModel.m_pData)
    {
        missionGroupModel.m_pData = nullptr;
    }

    ~MissionGroupModel()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    MissionGroupModel& operator=(const MissionGroupModel& missionGroupModel)
    {
        Gs2Object::operator=(missionGroupModel);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*missionGroupModel.m_pData);

        return *this;
    }

    MissionGroupModel& operator=(MissionGroupModel&& missionGroupModel)
    {
        Gs2Object::operator=(std::move(missionGroupModel));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = missionGroupModel.m_pData;
        missionGroupModel.m_pData = nullptr;

        return *this;
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
    void setMissionGroupId(const Char* missionGroupId)
    {
        ensureData().missionGroupId.emplace(missionGroupId);
    }

    /**
     * ミッショングループを設定
     *
     * @param missionGroupId ミッショングループ
     */
    MissionGroupModel& withMissionGroupId(const Char* missionGroupId)
    {
        setMissionGroupId(missionGroupId);
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
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * グループ名を設定
     *
     * @param name グループ名
     */
    MissionGroupModel& withName(const Char* name)
    {
        setName(name);
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
    void setMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
    }

    /**
     * メタデータを設定
     *
     * @param metadata メタデータ
     */
    MissionGroupModel& withMetadata(const Char* metadata)
    {
        setMetadata(metadata);
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
    void setTasks(const List<MissionTaskModel>& tasks)
    {
        ensureData().tasks.emplace(tasks);
    }

    /**
     * タスクリストを設定
     *
     * @param tasks タスクリスト
     */
    MissionGroupModel& withTasks(const List<MissionTaskModel>& tasks)
    {
        setTasks(tasks);
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
    void setCompleteNotificationNamespaceId(const Char* completeNotificationNamespaceId)
    {
        ensureData().completeNotificationNamespaceId.emplace(completeNotificationNamespaceId);
    }

    /**
     * ミッションを達成したときの通知先ネームスペース のGRNを設定
     *
     * @param completeNotificationNamespaceId ミッションを達成したときの通知先ネームスペース のGRN
     */
    MissionGroupModel& withCompleteNotificationNamespaceId(const Char* completeNotificationNamespaceId)
    {
        setCompleteNotificationNamespaceId(completeNotificationNamespaceId);
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
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
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