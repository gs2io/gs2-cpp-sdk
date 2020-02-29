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

#ifndef GS2_EZ_MISSION_MODEL_EZMISSIONTASKMODEL_HPP_
#define GS2_EZ_MISSION_MODEL_EZMISSIONTASKMODEL_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "EzAcquireAction.hpp"
#include <memory>


namespace gs2 {

namespace mission {

class MissionTaskModel;

}

namespace ez { namespace mission {

class EzMissionTaskModel : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** タスク名 */
        gs2::optional<StringHolder> name;
        /** メタデータ */
        gs2::optional<StringHolder> metadata;
        /** カウンター名 */
        gs2::optional<StringHolder> counterName;
        /** 目標値 */
        gs2::optional<Int64> targetValue;
        /** ミッション達成時の報酬 */
        gs2::optional<List<EzAcquireAction>> completeAcquireActions;
        /** 達成報酬の受け取り可能な期間を指定するイベントマスター のGRN */
        gs2::optional<StringHolder> challengePeriodEventId;
        /** このタスクに挑戦するために達成しておく必要のあるタスクの名前 */
        gs2::optional<StringHolder> premiseMissionTaskName;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::mission::MissionTaskModel& missionTaskModel);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzMissionTaskModel() = default;
    EzMissionTaskModel(const EzMissionTaskModel& ezMissionTaskModel) = default;
    EzMissionTaskModel(EzMissionTaskModel&& ezMissionTaskModel) = default;
    ~EzMissionTaskModel() = default;

    EzMissionTaskModel(gs2::mission::MissionTaskModel missionTaskModel);

    EzMissionTaskModel& operator=(const EzMissionTaskModel& ezMissionTaskModel) = default;
    EzMissionTaskModel& operator=(EzMissionTaskModel&& ezMissionTaskModel) = default;

    EzMissionTaskModel deepCopy() const;

    gs2::mission::MissionTaskModel ToModel() const;

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

    const StringHolder& getCounterName() const
    {
        return *ensureData().counterName;
    }

    Int64 getTargetValue() const
    {
        return *ensureData().targetValue;
    }

    const List<EzAcquireAction>& getCompleteAcquireActions() const
    {
        return *ensureData().completeAcquireActions;
    }

    const StringHolder& getChallengePeriodEventId() const
    {
        return *ensureData().challengePeriodEventId;
    }

    const StringHolder& getPremiseMissionTaskName() const
    {
        return *ensureData().premiseMissionTaskName;
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

    void setCounterName(StringHolder counterName)
    {
        ensureData().counterName = std::move(counterName);
    }

    void setTargetValue(Int64 targetValue)
    {
        ensureData().targetValue = targetValue;
    }

    void setCompleteAcquireActions(List<EzAcquireAction> completeAcquireActions)
    {
        ensureData().completeAcquireActions = std::move(completeAcquireActions);
    }

    void setChallengePeriodEventId(StringHolder challengePeriodEventId)
    {
        ensureData().challengePeriodEventId = std::move(challengePeriodEventId);
    }

    void setPremiseMissionTaskName(StringHolder premiseMissionTaskName)
    {
        ensureData().premiseMissionTaskName = std::move(premiseMissionTaskName);
    }

    EzMissionTaskModel& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    EzMissionTaskModel& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    EzMissionTaskModel& withCounterName(StringHolder counterName)
    {
        setCounterName(std::move(counterName));
        return *this;
    }

    EzMissionTaskModel& withTargetValue(Int64 targetValue)
    {
        setTargetValue(targetValue);
        return *this;
    }

    EzMissionTaskModel& withCompleteAcquireActions(List<EzAcquireAction> completeAcquireActions)
    {
        setCompleteAcquireActions(std::move(completeAcquireActions));
        return *this;
    }

    EzMissionTaskModel& withChallengePeriodEventId(StringHolder challengePeriodEventId)
    {
        setChallengePeriodEventId(std::move(challengePeriodEventId));
        return *this;
    }

    EzMissionTaskModel& withPremiseMissionTaskName(StringHolder premiseMissionTaskName)
    {
        setPremiseMissionTaskName(std::move(premiseMissionTaskName));
        return *this;
    }
};

}}}

#endif //GS2_EZ_MISSION_EZMISSIONTASKMODEL_HPP_