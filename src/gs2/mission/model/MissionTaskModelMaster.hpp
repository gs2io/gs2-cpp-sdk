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

#ifndef GS2_MISSION_MODEL_MISSIONTASKMODELMASTER_HPP_
#define GS2_MISSION_MODEL_MISSIONTASKMODELMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "AcquireAction.hpp"
#include <cstring>

namespace gs2 { namespace mission {

/**
 * ミッションタスクマスター
 *
 * @author Game Server Services, Inc.
 *
 */
class MissionTaskModelMaster : public Gs2Object
{
    friend bool operator!=(const MissionTaskModelMaster& lhs, const MissionTaskModelMaster& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** ミッションタスクマスター */
        optional<StringHolder> missionTaskId;
        /** タスク名 */
        optional<StringHolder> name;
        /** メタデータ */
        optional<StringHolder> metadata;
        /** ミッションタスクの説明 */
        optional<StringHolder> description;
        /** カウンター名 */
        optional<StringHolder> counterName;
        /** リセットタイミング */
        optional<StringHolder> resetType;
        /** 目標値 */
        optional<Int64> targetValue;
        /** ミッション達成時の報酬 */
        optional<List<AcquireAction>> completeAcquireActions;
        /** 達成報酬の受け取り可能な期間を指定するイベントマスター のGRN */
        optional<StringHolder> challengePeriodEventId;
        /** このタスクに挑戦するために達成しておく必要のあるタスクの名前 */
        optional<StringHolder> premiseMissionTaskName;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            missionTaskId(data.missionTaskId),
            name(data.name),
            metadata(data.metadata),
            description(data.description),
            counterName(data.counterName),
            resetType(data.resetType),
            targetValue(data.targetValue),
            completeAcquireActions(data.completeAcquireActions),
            challengePeriodEventId(data.challengePeriodEventId),
            premiseMissionTaskName(data.premiseMissionTaskName),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            missionTaskId(std::move(data.missionTaskId)),
            name(std::move(data.name)),
            metadata(std::move(data.metadata)),
            description(std::move(data.description)),
            counterName(std::move(data.counterName)),
            resetType(std::move(data.resetType)),
            targetValue(std::move(data.targetValue)),
            completeAcquireActions(std::move(data.completeAcquireActions)),
            challengePeriodEventId(std::move(data.challengePeriodEventId)),
            premiseMissionTaskName(std::move(data.premiseMissionTaskName)),
            createdAt(std::move(data.createdAt)),
            updatedAt(std::move(data.updatedAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "missionTaskId") == 0) {
                if (jsonValue.IsString())
                {
                    this->missionTaskId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name, "counterName") == 0) {
                if (jsonValue.IsString())
                {
                    this->counterName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "resetType") == 0) {
                if (jsonValue.IsString())
                {
                    this->resetType.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "targetValue") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->targetValue = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "completeAcquireActions") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->completeAcquireActions.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        AcquireAction item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        detail::addToList(*this->completeAcquireActions, std::move(item));
                    }
                }
            }
            else if (std::strcmp(name, "challengePeriodEventId") == 0) {
                if (jsonValue.IsString())
                {
                    this->challengePeriodEventId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "premiseMissionTaskName") == 0) {
                if (jsonValue.IsString())
                {
                    this->premiseMissionTaskName.emplace(jsonValue.GetString());
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
    MissionTaskModelMaster() :
        m_pData(nullptr)
    {}

    MissionTaskModelMaster(const MissionTaskModelMaster& missionTaskModelMaster) :
        Gs2Object(missionTaskModelMaster),
        m_pData(missionTaskModelMaster.m_pData != nullptr ? new Data(*missionTaskModelMaster.m_pData) : nullptr)
    {}

    MissionTaskModelMaster(MissionTaskModelMaster&& missionTaskModelMaster) :
        Gs2Object(std::move(missionTaskModelMaster)),
        m_pData(missionTaskModelMaster.m_pData)
    {
        missionTaskModelMaster.m_pData = nullptr;
    }

    ~MissionTaskModelMaster()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    MissionTaskModelMaster& operator=(const MissionTaskModelMaster& missionTaskModelMaster)
    {
        Gs2Object::operator=(missionTaskModelMaster);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*missionTaskModelMaster.m_pData);

        return *this;
    }

    MissionTaskModelMaster& operator=(MissionTaskModelMaster&& missionTaskModelMaster)
    {
        Gs2Object::operator=(std::move(missionTaskModelMaster));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = missionTaskModelMaster.m_pData;
        missionTaskModelMaster.m_pData = nullptr;

        return *this;
    }

    const MissionTaskModelMaster* operator->() const
    {
        return this;
    }

    MissionTaskModelMaster* operator->()
    {
        return this;
    }
    /**
     * ミッションタスクマスターを取得
     *
     * @return ミッションタスクマスター
     */
    const optional<StringHolder>& getMissionTaskId() const
    {
        return ensureData().missionTaskId;
    }

    /**
     * ミッションタスクマスターを設定
     *
     * @param missionTaskId ミッションタスクマスター
     */
    void setMissionTaskId(const Char* missionTaskId)
    {
        ensureData().missionTaskId.emplace(missionTaskId);
    }

    /**
     * ミッションタスクマスターを設定
     *
     * @param missionTaskId ミッションタスクマスター
     */
    MissionTaskModelMaster& withMissionTaskId(const Char* missionTaskId)
    {
        setMissionTaskId(missionTaskId);
        return *this;
    }

    /**
     * タスク名を取得
     *
     * @return タスク名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * タスク名を設定
     *
     * @param name タスク名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * タスク名を設定
     *
     * @param name タスク名
     */
    MissionTaskModelMaster& withName(const Char* name)
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
    MissionTaskModelMaster& withMetadata(const Char* metadata)
    {
        setMetadata(metadata);
        return *this;
    }

    /**
     * ミッションタスクの説明を取得
     *
     * @return ミッションタスクの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * ミッションタスクの説明を設定
     *
     * @param description ミッションタスクの説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * ミッションタスクの説明を設定
     *
     * @param description ミッションタスクの説明
     */
    MissionTaskModelMaster& withDescription(const Char* description)
    {
        setDescription(description);
        return *this;
    }

    /**
     * カウンター名を取得
     *
     * @return カウンター名
     */
    const optional<StringHolder>& getCounterName() const
    {
        return ensureData().counterName;
    }

    /**
     * カウンター名を設定
     *
     * @param counterName カウンター名
     */
    void setCounterName(const Char* counterName)
    {
        ensureData().counterName.emplace(counterName);
    }

    /**
     * カウンター名を設定
     *
     * @param counterName カウンター名
     */
    MissionTaskModelMaster& withCounterName(const Char* counterName)
    {
        setCounterName(counterName);
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
    void setResetType(const Char* resetType)
    {
        ensureData().resetType.emplace(resetType);
    }

    /**
     * リセットタイミングを設定
     *
     * @param resetType リセットタイミング
     */
    MissionTaskModelMaster& withResetType(const Char* resetType)
    {
        setResetType(resetType);
        return *this;
    }

    /**
     * 目標値を取得
     *
     * @return 目標値
     */
    const optional<Int64>& getTargetValue() const
    {
        return ensureData().targetValue;
    }

    /**
     * 目標値を設定
     *
     * @param targetValue 目標値
     */
    void setTargetValue(Int64 targetValue)
    {
        ensureData().targetValue.emplace(targetValue);
    }

    /**
     * 目標値を設定
     *
     * @param targetValue 目標値
     */
    MissionTaskModelMaster& withTargetValue(Int64 targetValue)
    {
        setTargetValue(targetValue);
        return *this;
    }

    /**
     * ミッション達成時の報酬を取得
     *
     * @return ミッション達成時の報酬
     */
    const optional<List<AcquireAction>>& getCompleteAcquireActions() const
    {
        return ensureData().completeAcquireActions;
    }

    /**
     * ミッション達成時の報酬を設定
     *
     * @param completeAcquireActions ミッション達成時の報酬
     */
    void setCompleteAcquireActions(const List<AcquireAction>& completeAcquireActions)
    {
        ensureData().completeAcquireActions.emplace(completeAcquireActions);
    }

    /**
     * ミッション達成時の報酬を設定
     *
     * @param completeAcquireActions ミッション達成時の報酬
     */
    MissionTaskModelMaster& withCompleteAcquireActions(const List<AcquireAction>& completeAcquireActions)
    {
        setCompleteAcquireActions(completeAcquireActions);
        return *this;
    }

    /**
     * 達成報酬の受け取り可能な期間を指定するイベントマスター のGRNを取得
     *
     * @return 達成報酬の受け取り可能な期間を指定するイベントマスター のGRN
     */
    const optional<StringHolder>& getChallengePeriodEventId() const
    {
        return ensureData().challengePeriodEventId;
    }

    /**
     * 達成報酬の受け取り可能な期間を指定するイベントマスター のGRNを設定
     *
     * @param challengePeriodEventId 達成報酬の受け取り可能な期間を指定するイベントマスター のGRN
     */
    void setChallengePeriodEventId(const Char* challengePeriodEventId)
    {
        ensureData().challengePeriodEventId.emplace(challengePeriodEventId);
    }

    /**
     * 達成報酬の受け取り可能な期間を指定するイベントマスター のGRNを設定
     *
     * @param challengePeriodEventId 達成報酬の受け取り可能な期間を指定するイベントマスター のGRN
     */
    MissionTaskModelMaster& withChallengePeriodEventId(const Char* challengePeriodEventId)
    {
        setChallengePeriodEventId(challengePeriodEventId);
        return *this;
    }

    /**
     * このタスクに挑戦するために達成しておく必要のあるタスクの名前を取得
     *
     * @return このタスクに挑戦するために達成しておく必要のあるタスクの名前
     */
    const optional<StringHolder>& getPremiseMissionTaskName() const
    {
        return ensureData().premiseMissionTaskName;
    }

    /**
     * このタスクに挑戦するために達成しておく必要のあるタスクの名前を設定
     *
     * @param premiseMissionTaskName このタスクに挑戦するために達成しておく必要のあるタスクの名前
     */
    void setPremiseMissionTaskName(const Char* premiseMissionTaskName)
    {
        ensureData().premiseMissionTaskName.emplace(premiseMissionTaskName);
    }

    /**
     * このタスクに挑戦するために達成しておく必要のあるタスクの名前を設定
     *
     * @param premiseMissionTaskName このタスクに挑戦するために達成しておく必要のあるタスクの名前
     */
    MissionTaskModelMaster& withPremiseMissionTaskName(const Char* premiseMissionTaskName)
    {
        setPremiseMissionTaskName(premiseMissionTaskName);
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
    MissionTaskModelMaster& withCreatedAt(Int64 createdAt)
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
    MissionTaskModelMaster& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const MissionTaskModelMaster& lhs, const MissionTaskModelMaster& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->missionTaskId != lhr.m_pData->missionTaskId)
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
        if (lhs.m_pData->counterName != lhr.m_pData->counterName)
        {
            return true;
        }
        if (lhs.m_pData->resetType != lhr.m_pData->resetType)
        {
            return true;
        }
        if (lhs.m_pData->targetValue != lhr.m_pData->targetValue)
        {
            return true;
        }
        if (lhs.m_pData->completeAcquireActions != lhr.m_pData->completeAcquireActions)
        {
            return true;
        }
        if (lhs.m_pData->challengePeriodEventId != lhr.m_pData->challengePeriodEventId)
        {
            return true;
        }
        if (lhs.m_pData->premiseMissionTaskName != lhr.m_pData->premiseMissionTaskName)
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

bool operator==(const MissionTaskModelMaster& lhs, const MissionTaskModelMaster& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_MISSION_MODEL_MISSIONTASKMODELMASTER_HPP_