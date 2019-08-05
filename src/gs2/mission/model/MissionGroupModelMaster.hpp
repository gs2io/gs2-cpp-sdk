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

#ifndef GS2_MISSION_MODEL_MISSIONGROUPMODELMASTER_HPP_
#define GS2_MISSION_MODEL_MISSIONGROUPMODELMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace mission {

/**
 * ミッショングループマスター
 *
 * @author Game Server Services, Inc.
 *
 */
class MissionGroupModelMaster : public Gs2Object
{
    friend bool operator!=(const MissionGroupModelMaster& lhs, const MissionGroupModelMaster& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** ミッショングループマスター */
        optional<StringHolder> missionGroupId;
        /** ミッショングループ名 */
        optional<StringHolder> name;
        /** メタデータ */
        optional<StringHolder> metadata;
        /** ミッショングループの説明 */
        optional<StringHolder> description;
        /** ミッションを達成したときの通知先ネームスペース のGRN */
        optional<StringHolder> completeNotificationNamespaceId;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            missionGroupId(data.missionGroupId),
            name(data.name),
            metadata(data.metadata),
            description(data.description),
            completeNotificationNamespaceId(data.completeNotificationNamespaceId),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            missionGroupId(std::move(data.missionGroupId)),
            name(std::move(data.name)),
            metadata(std::move(data.metadata)),
            description(std::move(data.description)),
            completeNotificationNamespaceId(std::move(data.completeNotificationNamespaceId)),
            createdAt(std::move(data.createdAt)),
            updatedAt(std::move(data.updatedAt))
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
            else if (std::strcmp(name, "description") == 0) {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "completeNotificationNamespaceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->completeNotificationNamespaceId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createdAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "updatedAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
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
    MissionGroupModelMaster() :
        m_pData(nullptr)
    {}

    MissionGroupModelMaster(const MissionGroupModelMaster& missionGroupModelMaster) :
        Gs2Object(missionGroupModelMaster),
        m_pData(missionGroupModelMaster.m_pData != nullptr ? new Data(*missionGroupModelMaster.m_pData) : nullptr)
    {}

    MissionGroupModelMaster(MissionGroupModelMaster&& missionGroupModelMaster) :
        Gs2Object(std::move(missionGroupModelMaster)),
        m_pData(missionGroupModelMaster.m_pData)
    {
        missionGroupModelMaster.m_pData = nullptr;
    }

    ~MissionGroupModelMaster()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    MissionGroupModelMaster& operator=(const MissionGroupModelMaster& missionGroupModelMaster)
    {
        Gs2Object::operator=(missionGroupModelMaster);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*missionGroupModelMaster.m_pData);

        return *this;
    }

    MissionGroupModelMaster& operator=(MissionGroupModelMaster&& missionGroupModelMaster)
    {
        Gs2Object::operator=(std::move(missionGroupModelMaster));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = missionGroupModelMaster.m_pData;
        missionGroupModelMaster.m_pData = nullptr;

        return *this;
    }

    const MissionGroupModelMaster* operator->() const
    {
        return this;
    }

    MissionGroupModelMaster* operator->()
    {
        return this;
    }
    /**
     * ミッショングループマスターを取得
     *
     * @return ミッショングループマスター
     */
    const optional<StringHolder>& getMissionGroupId() const
    {
        return ensureData().missionGroupId;
    }

    /**
     * ミッショングループマスターを設定
     *
     * @param missionGroupId ミッショングループマスター
     */
    void setMissionGroupId(const Char* missionGroupId)
    {
        ensureData().missionGroupId.emplace(missionGroupId);
    }

    /**
     * ミッショングループマスターを設定
     *
     * @param missionGroupId ミッショングループマスター
     */
    MissionGroupModelMaster& withMissionGroupId(const Char* missionGroupId)
    {
        setMissionGroupId(missionGroupId);
        return *this;
    }

    /**
     * ミッショングループ名を取得
     *
     * @return ミッショングループ名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * ミッショングループ名を設定
     *
     * @param name ミッショングループ名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * ミッショングループ名を設定
     *
     * @param name ミッショングループ名
     */
    MissionGroupModelMaster& withName(const Char* name)
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
    MissionGroupModelMaster& withMetadata(const Char* metadata)
    {
        setMetadata(metadata);
        return *this;
    }

    /**
     * ミッショングループの説明を取得
     *
     * @return ミッショングループの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * ミッショングループの説明を設定
     *
     * @param description ミッショングループの説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * ミッショングループの説明を設定
     *
     * @param description ミッショングループの説明
     */
    MissionGroupModelMaster& withDescription(const Char* description)
    {
        setDescription(description);
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
    MissionGroupModelMaster& withCompleteNotificationNamespaceId(const Char* completeNotificationNamespaceId)
    {
        setCompleteNotificationNamespaceId(completeNotificationNamespaceId);
        return *this;
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getCreatedAt() const
    {
        return ensureData().createdAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    void setCreatedAt(Int64 createdAt)
    {
        ensureData().createdAt.emplace(createdAt);
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    MissionGroupModelMaster& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }

    /**
     * 最終更新日時を取得
     *
     * @return 最終更新日時
     */
    const optional<Int64>& getUpdatedAt() const
    {
        return ensureData().updatedAt;
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    void setUpdatedAt(Int64 updatedAt)
    {
        ensureData().updatedAt.emplace(updatedAt);
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    MissionGroupModelMaster& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const MissionGroupModelMaster& lhs, const MissionGroupModelMaster& lhr)
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
        if (lhs.m_pData->description != lhr.m_pData->description)
        {
            return true;
        }
        if (lhs.m_pData->completeNotificationNamespaceId != lhr.m_pData->completeNotificationNamespaceId)
        {
            return true;
        }
        if (lhs.m_pData->createdAt != lhr.m_pData->createdAt)
        {
            return true;
        }
        if (lhs.m_pData->updatedAt != lhr.m_pData->updatedAt)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const MissionGroupModelMaster& lhs, const MissionGroupModelMaster& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_MISSION_MODEL_MISSIONGROUPMODELMASTER_HPP_