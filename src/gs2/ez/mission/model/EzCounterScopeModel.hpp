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

#ifndef GS2_EZ_MISSION_MODEL_EZCOUNTERSCOPEMODEL_HPP_
#define GS2_EZ_MISSION_MODEL_EZCOUNTERSCOPEMODEL_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace mission {

class CounterScopeModel;

}

namespace ez { namespace mission {

class EzCounterScopeModel : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** リセットタイミング */
        gs2::optional<StringHolder> resetType;
        /** リセットをする日にち */
        gs2::optional<Int32> resetDayOfMonth;
        /** リセットする曜日 */
        gs2::optional<StringHolder> resetDayOfWeek;
        /** リセット時刻 */
        gs2::optional<Int32> resetHour;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::mission::CounterScopeModel& counterScopeModel);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzCounterScopeModel() = default;
    EzCounterScopeModel(const EzCounterScopeModel& ezCounterScopeModel) = default;
    EzCounterScopeModel(EzCounterScopeModel&& ezCounterScopeModel) = default;
    ~EzCounterScopeModel() = default;

    EzCounterScopeModel(gs2::mission::CounterScopeModel counterScopeModel);

    EzCounterScopeModel& operator=(const EzCounterScopeModel& ezCounterScopeModel) = default;
    EzCounterScopeModel& operator=(EzCounterScopeModel&& ezCounterScopeModel) = default;

    EzCounterScopeModel deepCopy() const;

    gs2::mission::CounterScopeModel ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getResetType() const
    {
        return *ensureData().resetType;
    }

    Int32 getResetDayOfMonth() const
    {
        return *ensureData().resetDayOfMonth;
    }

    const StringHolder& getResetDayOfWeek() const
    {
        return *ensureData().resetDayOfWeek;
    }

    Int32 getResetHour() const
    {
        return *ensureData().resetHour;
    }

    // ========================================
    //   Setters
    // ========================================

    void setResetType(StringHolder resetType)
    {
        ensureData().resetType = std::move(resetType);
    }

    void setResetDayOfMonth(Int32 resetDayOfMonth)
    {
        ensureData().resetDayOfMonth = resetDayOfMonth;
    }

    void setResetDayOfWeek(StringHolder resetDayOfWeek)
    {
        ensureData().resetDayOfWeek = std::move(resetDayOfWeek);
    }

    void setResetHour(Int32 resetHour)
    {
        ensureData().resetHour = resetHour;
    }

    EzCounterScopeModel& withResetType(StringHolder resetType)
    {
        setResetType(std::move(resetType));
        return *this;
    }

    EzCounterScopeModel& withResetDayOfMonth(Int32 resetDayOfMonth)
    {
        setResetDayOfMonth(resetDayOfMonth);
        return *this;
    }

    EzCounterScopeModel& withResetDayOfWeek(StringHolder resetDayOfWeek)
    {
        setResetDayOfWeek(std::move(resetDayOfWeek));
        return *this;
    }

    EzCounterScopeModel& withResetHour(Int32 resetHour)
    {
        setResetHour(resetHour);
        return *this;
    }
};

}}}

#endif //GS2_EZ_MISSION_EZCOUNTERSCOPEMODEL_HPP_