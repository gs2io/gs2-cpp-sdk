

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

#include <gs2/mission/model/CounterScopeModel.hpp>


namespace gs2 { namespace ez { namespace mission {

class EzCounterScopeModel : public gs2::Gs2Object
{
private:
    /** リセットタイミング */
    gs2::optional<StringHolder> m_ResetType;
    /** リセットをする日にち */
    gs2::optional<Int32> m_ResetDayOfMonth;
    /** リセットする曜日 */
    gs2::optional<StringHolder> m_ResetDayOfWeek;
    /** リセット時刻 */
    gs2::optional<Int32> m_ResetHour;

public:
    EzCounterScopeModel() = default;

    EzCounterScopeModel(gs2::mission::CounterScopeModel counterScopeModel) :
        m_ResetType(counterScopeModel.getResetType()),
        m_ResetDayOfMonth(counterScopeModel.getResetDayOfMonth() ? *counterScopeModel.getResetDayOfMonth() : 0),
        m_ResetDayOfWeek(counterScopeModel.getResetDayOfWeek()),
        m_ResetHour(counterScopeModel.getResetHour() ? *counterScopeModel.getResetHour() : 0)
    {
    }

    gs2::mission::CounterScopeModel ToModel() const
    {
        gs2::mission::CounterScopeModel counterScopeModel;
        counterScopeModel.setResetType(*m_ResetType);
        counterScopeModel.setResetDayOfMonth(*m_ResetDayOfMonth);
        counterScopeModel.setResetDayOfWeek(*m_ResetDayOfWeek);
        counterScopeModel.setResetHour(*m_ResetHour);
        return counterScopeModel;
    }

    // ========================================
    //   Getters
    // ========================================

    const gs2::StringHolder& getResetType() const
    {
        return *m_ResetType;
    }

    gs2::StringHolder& getResetType()
    {
        return *m_ResetType;
    }

    Int32 getResetDayOfMonth() const
    {
        return *m_ResetDayOfMonth;
    }

    const gs2::StringHolder& getResetDayOfWeek() const
    {
        return *m_ResetDayOfWeek;
    }

    gs2::StringHolder& getResetDayOfWeek()
    {
        return *m_ResetDayOfWeek;
    }

    Int32 getResetHour() const
    {
        return *m_ResetHour;
    }

    // ========================================
    //   Setters
    // ========================================

    void setResetType(Char* resetType)
    {
        m_ResetType.emplace(resetType);
    }

    void setResetDayOfMonth(Int32 resetDayOfMonth)
    {
        m_ResetDayOfMonth = resetDayOfMonth;
    }

    void setResetDayOfWeek(Char* resetDayOfWeek)
    {
        m_ResetDayOfWeek.emplace(resetDayOfWeek);
    }

    void setResetHour(Int32 resetHour)
    {
        m_ResetHour = resetHour;
    }

    EzCounterScopeModel& withResetType(Char* resetType)
    {
        setResetType(resetType);
        return *this;
    }

    EzCounterScopeModel& withResetDayOfMonth(Int32 resetDayOfMonth)
    {
        setResetDayOfMonth(resetDayOfMonth);
        return *this;
    }

    EzCounterScopeModel& withResetDayOfWeek(Char* resetDayOfWeek)
    {
        setResetDayOfWeek(resetDayOfWeek);
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