

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

#include <gs2/mission/model/MissionTaskModel.hpp>
#include "EzAcquireAction.hpp"


namespace gs2 { namespace ez { namespace mission {

class EzMissionTaskModel : public gs2::Gs2Object
{
private:
    /** タスク名 */
    gs2::optional<StringHolder> m_Name;
    /** メタデータ */
    gs2::optional<StringHolder> m_Metadata;
    /** カウンター名 */
    gs2::optional<StringHolder> m_CounterName;
    /** リセットタイミング */
    gs2::optional<StringHolder> m_ResetType;
    /** 目標値 */
    gs2::optional<Int64> m_TargetValue;
    /** ミッション達成時の報酬 */
    gs2::optional<List<EzAcquireAction>> m_CompleteAcquireActions;
    /** 達成報酬の受け取り可能な期間を指定するイベントマスター のGRN */
    gs2::optional<StringHolder> m_ChallengePeriodEventId;
    /** このタスクに挑戦するために達成しておく必要のあるタスクの名前 */
    gs2::optional<StringHolder> m_PremiseMissionTaskName;

public:
    EzMissionTaskModel() = default;

    EzMissionTaskModel(gs2::mission::MissionTaskModel missionTaskModel) :
        m_Name(missionTaskModel.getName()),
        m_Metadata(missionTaskModel.getMetadata()),
        m_CounterName(missionTaskModel.getCounterName()),
        m_ResetType(missionTaskModel.getResetType()),
        m_TargetValue(missionTaskModel.getTargetValue() ? *missionTaskModel.getTargetValue() : 0),
        m_ChallengePeriodEventId(missionTaskModel.getChallengePeriodEventId()),
        m_PremiseMissionTaskName(missionTaskModel.getPremiseMissionTaskName())
    {
        m_CompleteAcquireActions.emplace();
        if (missionTaskModel.getCompleteAcquireActions())
        {
            for (int i = 0; i < missionTaskModel.getCompleteAcquireActions()->getCount(); ++i)
            {
                *m_CompleteAcquireActions += EzAcquireAction((*missionTaskModel.getCompleteAcquireActions())[i]);
            }
        }
    }

    gs2::mission::MissionTaskModel ToModel() const
    {
        gs2::mission::MissionTaskModel missionTaskModel;
        missionTaskModel.setName(*m_Name);
        missionTaskModel.setMetadata(*m_Metadata);
        missionTaskModel.setCounterName(*m_CounterName);
        missionTaskModel.setResetType(*m_ResetType);
        missionTaskModel.setTargetValue(*m_TargetValue);
        {
            gs2::List<gs2::mission::AcquireAction> list;
            auto& completeAcquireActions = *m_CompleteAcquireActions;
            for (int i = 0; i < completeAcquireActions.getCount(); ++i)
            {
                list += completeAcquireActions[i].ToModel();
            }
            missionTaskModel.setCompleteAcquireActions(list);
        }
        missionTaskModel.setChallengePeriodEventId(*m_ChallengePeriodEventId);
        missionTaskModel.setPremiseMissionTaskName(*m_PremiseMissionTaskName);
        return missionTaskModel;
    }

    // ========================================
    //   Getters
    // ========================================

    const gs2::StringHolder& getName() const
    {
        return *m_Name;
    }

    gs2::StringHolder& getName()
    {
        return *m_Name;
    }

    const gs2::StringHolder& getMetadata() const
    {
        return *m_Metadata;
    }

    gs2::StringHolder& getMetadata()
    {
        return *m_Metadata;
    }

    const gs2::StringHolder& getCounterName() const
    {
        return *m_CounterName;
    }

    gs2::StringHolder& getCounterName()
    {
        return *m_CounterName;
    }

    const gs2::StringHolder& getResetType() const
    {
        return *m_ResetType;
    }

    gs2::StringHolder& getResetType()
    {
        return *m_ResetType;
    }

    Int64 getTargetValue() const
    {
        return *m_TargetValue;
    }

    const List<EzAcquireAction>& getCompleteAcquireActions() const
    {
        return *m_CompleteAcquireActions;
    }

    List<EzAcquireAction>& getCompleteAcquireActions()
    {
        return *m_CompleteAcquireActions;
    }

    const gs2::StringHolder& getChallengePeriodEventId() const
    {
        return *m_ChallengePeriodEventId;
    }

    gs2::StringHolder& getChallengePeriodEventId()
    {
        return *m_ChallengePeriodEventId;
    }

    const gs2::StringHolder& getPremiseMissionTaskName() const
    {
        return *m_PremiseMissionTaskName;
    }

    gs2::StringHolder& getPremiseMissionTaskName()
    {
        return *m_PremiseMissionTaskName;
    }

    // ========================================
    //   Setters
    // ========================================

    void setName(Char* name)
    {
        m_Name.emplace(name);
    }

    void setMetadata(Char* metadata)
    {
        m_Metadata.emplace(metadata);
    }

    void setCounterName(Char* counterName)
    {
        m_CounterName.emplace(counterName);
    }

    void setResetType(Char* resetType)
    {
        m_ResetType.emplace(resetType);
    }

    void setTargetValue(Int64 targetValue)
    {
        m_TargetValue = targetValue;
    }

    void setCompleteAcquireActions(const List<EzAcquireAction>& completeAcquireActions)
    {
        m_CompleteAcquireActions = completeAcquireActions;
    }

    void setCompleteAcquireActions(List<EzAcquireAction>&& completeAcquireActions)
    {
        m_CompleteAcquireActions = std::move(completeAcquireActions);
    }

    void setChallengePeriodEventId(Char* challengePeriodEventId)
    {
        m_ChallengePeriodEventId.emplace(challengePeriodEventId);
    }

    void setPremiseMissionTaskName(Char* premiseMissionTaskName)
    {
        m_PremiseMissionTaskName.emplace(premiseMissionTaskName);
    }

    EzMissionTaskModel& withName(Char* name)
    {
        setName(name);
        return *this;
    }

    EzMissionTaskModel& withMetadata(Char* metadata)
    {
        setMetadata(metadata);
        return *this;
    }

    EzMissionTaskModel& withCounterName(Char* counterName)
    {
        setCounterName(counterName);
        return *this;
    }

    EzMissionTaskModel& withResetType(Char* resetType)
    {
        setResetType(resetType);
        return *this;
    }

    EzMissionTaskModel& withTargetValue(Int64 targetValue)
    {
        setTargetValue(targetValue);
        return *this;
    }

    EzMissionTaskModel& withCompleteAcquireActions(const List<EzAcquireAction>& completeAcquireActions)
    {
        setCompleteAcquireActions(completeAcquireActions);
        return *this;
    }

    EzMissionTaskModel& withCompleteAcquireActions(List<EzAcquireAction>&& completeAcquireActions)
    {
        setCompleteAcquireActions(std::move(completeAcquireActions));
        return *this;
    }

    EzMissionTaskModel& withChallengePeriodEventId(Char* challengePeriodEventId)
    {
        setChallengePeriodEventId(challengePeriodEventId);
        return *this;
    }

    EzMissionTaskModel& withPremiseMissionTaskName(Char* premiseMissionTaskName)
    {
        setPremiseMissionTaskName(premiseMissionTaskName);
        return *this;
    }
};

}}}

#endif //GS2_EZ_MISSION_EZMISSIONTASKMODEL_HPP_