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

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "EzCounterScopeModel.hpp"
#include <memory>


namespace gs2 {

namespace mission {

class CounterModel;

}

namespace ez { namespace mission {

class EzCounterModel : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** カウンター名 */
        StringHolder name;
        /** メタデータ */
        StringHolder metadata;
        /** カウンターのリセットタイミング */
        List<EzCounterScopeModel> scopes;
        /** カウントアップ可能な期間を指定するイベントマスター のGRN */
        StringHolder challengePeriodEventId;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::mission::CounterModel& counterModel);
        Data(const gs2::optional<gs2::mission::CounterModel>& counterModel);
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

    EzCounterModel(gs2::mission::CounterModel counterModel);
    EzCounterModel(gs2::optional<gs2::mission::CounterModel> counterModel);

    EzCounterModel& operator=(const EzCounterModel& ezCounterModel) = default;
    EzCounterModel& operator=(EzCounterModel&& ezCounterModel) = default;

    EzCounterModel deepCopy() const;

    gs2::mission::CounterModel ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getName() const
    {
        return ensureData().name;
    }

    const StringHolder& getMetadata() const
    {
        return ensureData().metadata;
    }

    const List<EzCounterScopeModel>& getScopes() const
    {
        return ensureData().scopes;
    }

    const StringHolder& getChallengePeriodEventId() const
    {
        return ensureData().challengePeriodEventId;
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