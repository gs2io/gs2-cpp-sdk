

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

#ifndef GS2_EZ_MISSION_MODEL_EZCOUNTERMODEL_HPP_
#define GS2_EZ_MISSION_MODEL_EZCOUNTERMODEL_HPP_

#include <gs2/mission/model/CounterModel.hpp>
#include "EzCounterScopeModel.hpp"


namespace gs2 { namespace ez { namespace mission {

class EzCounterModel : public gs2::Gs2Object
{
private:
    /** カウンター名 */
    gs2::optional<StringHolder> m_Name;
    /** メタデータ */
    gs2::optional<StringHolder> m_Metadata;
    /** カウンターのリセットタイミング */
    gs2::optional<List<EzCounterScopeModel>> m_Scopes;
    /** カウントアップ可能な期間を指定するイベントマスター のGRN */
    gs2::optional<StringHolder> m_ChallengePeriodEventId;

public:
    EzCounterModel() = default;

    EzCounterModel(gs2::mission::CounterModel counterModel) :
        m_Name(counterModel.getName()),
        m_Metadata(counterModel.getMetadata()),
        m_ChallengePeriodEventId(counterModel.getChallengePeriodEventId())
    {
        m_Scopes.emplace();
        if (counterModel.getScopes())
        {
            for (int i = 0; i < counterModel.getScopes()->getCount(); ++i)
            {
                *m_Scopes += EzCounterScopeModel((*counterModel.getScopes())[i]);
            }
        }
    }

    gs2::mission::CounterModel ToModel() const
    {
        gs2::mission::CounterModel counterModel;
        counterModel.setName(*m_Name);
        counterModel.setMetadata(*m_Metadata);
        {
            gs2::List<gs2::mission::CounterScopeModel> list;
            auto& scopes = *m_Scopes;
            for (int i = 0; i < scopes.getCount(); ++i)
            {
                list += scopes[i].ToModel();
            }
            counterModel.setScopes(list);
        }
        counterModel.setChallengePeriodEventId(*m_ChallengePeriodEventId);
        return counterModel;
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

    const List<EzCounterScopeModel>& getScopes() const
    {
        return *m_Scopes;
    }

    List<EzCounterScopeModel>& getScopes()
    {
        return *m_Scopes;
    }

    const gs2::StringHolder& getChallengePeriodEventId() const
    {
        return *m_ChallengePeriodEventId;
    }

    gs2::StringHolder& getChallengePeriodEventId()
    {
        return *m_ChallengePeriodEventId;
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

    void setScopes(const List<EzCounterScopeModel>& scopes)
    {
        m_Scopes = scopes;
    }

    void setScopes(List<EzCounterScopeModel>&& scopes)
    {
        m_Scopes = std::move(scopes);
    }

    void setChallengePeriodEventId(Char* challengePeriodEventId)
    {
        m_ChallengePeriodEventId.emplace(challengePeriodEventId);
    }

    EzCounterModel& withName(Char* name)
    {
        setName(name);
        return *this;
    }

    EzCounterModel& withMetadata(Char* metadata)
    {
        setMetadata(metadata);
        return *this;
    }

    EzCounterModel& withScopes(const List<EzCounterScopeModel>& scopes)
    {
        setScopes(scopes);
        return *this;
    }

    EzCounterModel& withScopes(List<EzCounterScopeModel>&& scopes)
    {
        setScopes(std::move(scopes));
        return *this;
    }

    EzCounterModel& withChallengePeriodEventId(Char* challengePeriodEventId)
    {
        setChallengePeriodEventId(challengePeriodEventId);
        return *this;
    }
};

}}}

#endif //GS2_EZ_MISSION_EZCOUNTERMODEL_HPP_