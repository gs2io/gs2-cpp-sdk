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
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "AcquireAction.hpp"
#include <memory>

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
    MissionTaskModel() = default;
    MissionTaskModel(const MissionTaskModel& missionTaskModel) = default;
    MissionTaskModel(MissionTaskModel&& missionTaskModel) = default;
    ~MissionTaskModel() = default;

    MissionTaskModel& operator=(const MissionTaskModel& missionTaskModel) = default;
    MissionTaskModel& operator=(MissionTaskModel&& missionTaskModel) = default;

    MissionTaskModel deepCopy() const;

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
    void setMissionTaskId(StringHolder missionTaskId)
    {
        ensureData().missionTaskId.emplace(std::move(missionTaskId));
    }

    /**
     * ミッションタスクを設定
     *
     * @param missionTaskId ミッションタスク
     */
    MissionTaskModel& withMissionTaskId(StringHolder missionTaskId)
    {
        setMissionTaskId(std::move(missionTaskId));
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
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * タスク名を設定
     *
     * @param name タスク名
     */
    MissionTaskModel& withName(StringHolder name)
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
    MissionTaskModel& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
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
    void setCounterName(StringHolder counterName)
    {
        ensureData().counterName.emplace(std::move(counterName));
    }

    /**
     * カウンター名を設定
     *
     * @param counterName カウンター名
     */
    MissionTaskModel& withCounterName(StringHolder counterName)
    {
        setCounterName(std::move(counterName));
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
    MissionTaskModel& withResetType(StringHolder resetType)
    {
        setResetType(std::move(resetType));
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
    void setCompleteAcquireActions(List<AcquireAction> completeAcquireActions)
    {
        ensureData().completeAcquireActions.emplace(std::move(completeAcquireActions));
    }

    /**
     * ミッション達成時の報酬を設定
     *
     * @param completeAcquireActions ミッション達成時の報酬
     */
    MissionTaskModel& withCompleteAcquireActions(List<AcquireAction> completeAcquireActions)
    {
        setCompleteAcquireActions(std::move(completeAcquireActions));
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
    void setChallengePeriodEventId(StringHolder challengePeriodEventId)
    {
        ensureData().challengePeriodEventId.emplace(std::move(challengePeriodEventId));
    }

    /**
     * 達成報酬の受け取り可能な期間を指定するイベントマスター のGRNを設定
     *
     * @param challengePeriodEventId 達成報酬の受け取り可能な期間を指定するイベントマスター のGRN
     */
    MissionTaskModel& withChallengePeriodEventId(StringHolder challengePeriodEventId)
    {
        setChallengePeriodEventId(std::move(challengePeriodEventId));
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
    void setPremiseMissionTaskName(StringHolder premiseMissionTaskName)
    {
        ensureData().premiseMissionTaskName.emplace(std::move(premiseMissionTaskName));
    }

    /**
     * このタスクに挑戦するために達成しておく必要のあるタスクの名前を設定
     *
     * @param premiseMissionTaskName このタスクに挑戦するために達成しておく必要のあるタスクの名前
     */
    MissionTaskModel& withPremiseMissionTaskName(StringHolder premiseMissionTaskName)
    {
        setPremiseMissionTaskName(std::move(premiseMissionTaskName));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const MissionTaskModel& lhs, const MissionTaskModel& lhr);

inline bool operator==(const MissionTaskModel& lhs, const MissionTaskModel& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_MISSION_MODEL_MISSIONTASKMODEL_HPP_