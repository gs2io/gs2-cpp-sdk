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

#include "EzCounterScopeModel.hpp"
#include <gs2/mission/model/CounterScopeModel.hpp>


namespace gs2 { namespace ez { namespace mission {

EzCounterScopeModel::Data::Data(const Data& data) :
    Gs2Object(data),
    resetType(data.resetType),
    resetDayOfMonth(data.resetDayOfMonth),
    resetDayOfWeek(data.resetDayOfWeek),
    resetHour(data.resetHour)
{
}

EzCounterScopeModel::Data::Data(const gs2::mission::CounterScopeModel& counterScopeModel) :
    resetType(counterScopeModel.getResetType()),
    resetDayOfMonth(counterScopeModel.getResetDayOfMonth() ? *counterScopeModel.getResetDayOfMonth() : 0),
    resetDayOfWeek(counterScopeModel.getResetDayOfWeek()),
    resetHour(counterScopeModel.getResetHour() ? *counterScopeModel.getResetHour() : 0)
{
}

EzCounterScopeModel::EzCounterScopeModel(gs2::mission::CounterScopeModel counterScopeModel) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(counterScopeModel)
{
}

EzCounterScopeModel EzCounterScopeModel::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzCounterScopeModel);
}

gs2::mission::CounterScopeModel EzCounterScopeModel::ToModel() const
{
    gs2::mission::CounterScopeModel counterScopeModel;
    counterScopeModel.setResetType(getResetType());
    counterScopeModel.setResetDayOfMonth(getResetDayOfMonth());
    counterScopeModel.setResetDayOfWeek(getResetDayOfWeek());
    counterScopeModel.setResetHour(getResetHour());
    return counterScopeModel;
}

}}}