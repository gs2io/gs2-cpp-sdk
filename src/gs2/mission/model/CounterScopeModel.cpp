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

#include "CounterScopeModel.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace mission {

CounterScopeModel::Data::Data(const Data& data) :
    detail::json::IModel(data),
    resetType(data.resetType),
    resetDayOfMonth(data.resetDayOfMonth),
    resetDayOfWeek(data.resetDayOfWeek),
    resetHour(data.resetHour)
{
}

void CounterScopeModel::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "resetType") == 0)
    {
        if (jsonValue.IsString())
        {
            this->resetType.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "resetDayOfMonth") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->resetDayOfMonth = jsonValue.GetInt();
        }
    }
    else if (std::strcmp(name_, "resetDayOfWeek") == 0)
    {
        if (jsonValue.IsString())
        {
            this->resetDayOfWeek.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "resetHour") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->resetHour = jsonValue.GetInt();
        }
    }
}

CounterScopeModel CounterScopeModel::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CounterScopeModel);
}

bool operator!=(const CounterScopeModel& lhs, const CounterScopeModel& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->resetType != lhr.m_pData->resetType)
        {
            return true;
        }
        if (lhs.m_pData->resetDayOfMonth != lhr.m_pData->resetDayOfMonth)
        {
            return true;
        }
        if (lhs.m_pData->resetDayOfWeek != lhr.m_pData->resetDayOfWeek)
        {
            return true;
        }
        if (lhs.m_pData->resetHour != lhr.m_pData->resetHour)
        {
            return true;
        }
    }
    return false;
}

} }