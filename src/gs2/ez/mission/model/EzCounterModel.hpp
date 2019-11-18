

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
    class Data : public gs2::Gs2Object
    {
    public:
        /** カウンター名 */
        gs2::optional<StringHolder> name;
        /** メタデータ */
        gs2::optional<StringHolder> metadata;
        /** カウンターのリセットタイミング */
        gs2::optional<List<EzCounterScopeModel>> scopes;
        /** カウントアップ可能な期間を指定するイベントマスター のGRN */
        gs2::optional<StringHolder> challengePeriodEventId;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            name(data.name),
            metadata(data.metadata),
            challengePeriodEventId(data.challengePeriodEventId)
        {
            if (data.scopes)
            {
                scopes = data.scopes->deepCopy();
            }
        }

        Data(Data&& data) = default;

        Data(const gs2::mission::CounterModel& counterModel) :
            name(counterModel.getName()),
            metadata(counterModel.getMetadata()),
            challengePeriodEventId(counterModel.getChallengePeriodEventId())
        {
            scopes.emplace();
            if (counterModel.getScopes())
            {
                for (int i = 0; i < counterModel.getScopes()->getCount(); ++i)
                {
                    *scopes += EzCounterScopeModel((*counterModel.getScopes())[i]);
                }
            }
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzCounterModel() = default;
    EzCounterModel(const EzCounterModel& ezCounterModel) = default;
    EzCounterModel(EzCounterModel&& ezCounterModel) = default;
    ~EzCounterModel() = default;

    EzCounterModel(gs2::mission::CounterModel counterModel) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(counterModel)
    {}

    EzCounterModel& operator=(const EzCounterModel& ezCounterModel) = default;
    EzCounterModel& operator=(EzCounterModel&& ezCounterModel) = default;

    EzCounterModel deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzCounterModel);
    }

    gs2::mission::CounterModel ToModel() const
    {
        gs2::mission::CounterModel counterModel;
        counterModel.setName(getName());
        counterModel.setMetadata(getMetadata());
        {
            gs2::List<gs2::mission::CounterScopeModel> list;
            auto& scopes = getScopes();
            for (int i = 0; i < scopes.getCount(); ++i)
            {
                list += scopes[i].ToModel();
            }
            counterModel.setScopes(list);
        }
        counterModel.setChallengePeriodEventId(getChallengePeriodEventId());
        return counterModel;
    }

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

    const List<EzCounterScopeModel>& getScopes() const
    {
        return *ensureData().scopes;
    }

    const StringHolder& getChallengePeriodEventId() const
    {
        return *ensureData().challengePeriodEventId;
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

    void setScopes(List<EzCounterScopeModel> scopes)
    {
        ensureData().scopes = std::move(scopes);
    }

    void setChallengePeriodEventId(StringHolder challengePeriodEventId)
    {
        ensureData().challengePeriodEventId = std::move(challengePeriodEventId);
    }

    EzCounterModel& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    EzCounterModel& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    EzCounterModel& withScopes(List<EzCounterScopeModel> scopes)
    {
        setScopes(std::move(scopes));
        return *this;
    }

    EzCounterModel& withChallengePeriodEventId(StringHolder challengePeriodEventId)
    {
        setChallengePeriodEventId(std::move(challengePeriodEventId));
        return *this;
    }
};

}}}

#endif //GS2_EZ_MISSION_EZCOUNTERMODEL_HPP_