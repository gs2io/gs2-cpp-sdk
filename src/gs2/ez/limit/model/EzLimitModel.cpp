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

#include "EzLimitModel.hpp"
#include <gs2/limit/model/LimitModel.hpp>


namespace gs2 { namespace ez { namespace limit {

EzLimitModel::Data::Data(const Data& data) :
    Gs2Object(data),
    limitModelId(data.limitModelId),
    name(data.name),
    metadata(data.metadata),
    resetType(data.resetType),
    resetDayOfMonth(data.resetDayOfMonth),
    resetDayOfWeek(data.resetDayOfWeek),
    resetHour(data.resetHour)
{
}

EzLimitModel::Data::Data(const gs2::limit::LimitModel& limitModel) :
    limitModelId(limitModel.getLimitModelId()),
    name(limitModel.getName()),
    metadata(limitModel.getMetadata()),
    resetType(limitModel.getResetType()),
    resetDayOfMonth(limitModel.getResetDayOfMonth() ? *limitModel.getResetDayOfMonth() : 0),
    resetDayOfWeek(limitModel.getResetDayOfWeek()),
    resetHour(limitModel.getResetHour() ? *limitModel.getResetHour() : 0)
{
}

EzLimitModel::EzLimitModel(gs2::limit::LimitModel limitModel) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(limitModel)
{
}

EzLimitModel EzLimitModel::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzLimitModel);
}

gs2::limit::LimitModel EzLimitModel::ToModel() const
{
    gs2::limit::LimitModel limitModel;
    limitModel.setLimitModelId(getLimitModelId());
    limitModel.setName(getName());
    limitModel.setMetadata(getMetadata());
    limitModel.setResetType(getResetType());
    limitModel.setResetDayOfMonth(getResetDayOfMonth());
    limitModel.setResetDayOfWeek(getResetDayOfWeek());
    limitModel.setResetHour(getResetHour());
    return limitModel;
}

}}}