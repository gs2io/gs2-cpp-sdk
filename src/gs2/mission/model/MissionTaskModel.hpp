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

#ifndef GS2_MISSION_MODEL_MISSIONTASKMODEL_HPP_
#define GS2_MISSION_MODEL_MISSIONTASKMODEL_HPP_

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
 * ミッションタスク
 *
 * @author Game Server Services, Inc.
 *
 */
class MissionTaskModel : public Gs2Object
{
    friend bool operator!=(const MissionTaskModel& lhs, const MissionTaskModel& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** ミッションタスク */
        optional<StringHolder> missionTaskId;
        /** タスク名 */
        optional<StringHolder> name;
        /** メタデータ */
        optional<StringHolder> metadata;
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

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            missionTaskId(data.missionTaskId),
            name(data.name),
            metadata(data.metadata),
            counterName(data.counterName),
            resetType(data.resetType),
            targetValue(data.targetValue),
            completeAcquireActions(data.completeAcquireActions),
            challengePeriodEventId(data.challengePeriodEventId),
            premiseMissionTaskName(data.premiseMissionTaskName)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            missionTaskId(std::move(data.missionTaskId)),
            name(std::move(data.name)),
            metadata(std::move(data.metadata)),
            counterName(std::move(data.counterName)),
            resetType(std::move(data.resetType)),
            targetValue(std::move(data.targetValue)),
            completeAcquireActions(std::move(data.completeAcquireActions)),
            challengePeriodEventId(std::move(data.challengePeriodEventId)),
            premiseMissionTaskName(std::move(data.premiseMissionTaskName))
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
    MissionTaskModel() :
        m_pData(nullptr)
    {}

    MissionTaskModel(const MissionTaskModel& missionTaskModel) :
        Gs2Object(missionTaskModel),
        m_pData(missionTaskModel.m_pData != nullptr ? new Data(*missionTaskModel.m_pData) : nullptr)
    {}

    MissionTaskModel(MissionTaskModel&& missionTaskModel) :
        Gs2Object(std::move(missionTaskModel)),
        m_pData(missionTaskModel.m_pData)
    {
        missionTaskModel.m_pData = nullptr;
    }

    ~MissionTaskModel()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    MissionTaskModel& operator=(const MissionTaskModel& missionTaskModel)
    {
        Gs2Object::operator=(missionTaskModel);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*missionTaskModel.m_pData);

        return *this;
    }

    MissionTaskModel& operator=(MissionTaskModel&& missionTaskModel)
    {
        Gs2Object::operator=(std::move(missionTaskModel));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = missionTaskModel.m_pData;
        missionTaskModel.m_pData = nullptr;

        return *this;
    }

    const MissionTaskModel* operator->() const
    {
        return this;
    }

    MissionTaskModel* operator->()
    {
        return this;
    }
    /**
     * ミッションタスクを取得
     *
     * @return ミッションタスク
     */
    const optional<StringHolder>& getMissionTaskId() const
    {
        return ensureData().missionTaskId;
    }

    /**
     * ミッションタスクを設定
     *
     * @param missionTaskId ミッションタスク
     */
    void setMissionTaskId(const Char* missionTaskId)
    {
        ensureData().missionTaskId.emplace(missionTaskId);
    }

    /**
     * ミッションタスクを設定
     *
     * @param missionTaskId ミッションタスク
     */
    MissionTaskModel& withMissionTaskId(const Char* missionTaskId)
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
    MissionTaskModel& withName(const Char* name)
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
    MissionTaskModel& withMetadata(const Char* metadata)
    {
        setMetadata(metadata);
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
    MissionTaskModel& withCounterName(const Char* counterName)
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
    MissionTaskModel& withResetType(const Char* resetType)
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
    MissionTaskModel& withTargetValue(Int64 targetValue)
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
    MissionTaskModel& withCompleteAcquireActions(const List<AcquireAction>& completeAcquireActions)
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
    MissionTaskModel& withChallengePeriodEventId(const Char* challengePeriodEventId)
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
    MissionTaskModel& withPremiseMissionTaskName(const Char* premiseMissionTaskName)
    {
        setPremiseMissionTaskName(premiseMissionTaskName);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const MissionTaskModel& lhs, const MissionTaskModel& lhr)
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
    }
    return false;
}

bool operator==(const MissionTaskModel& lhs, const MissionTaskModel& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_MISSION_MODEL_MISSIONTASKMODEL_HPP_