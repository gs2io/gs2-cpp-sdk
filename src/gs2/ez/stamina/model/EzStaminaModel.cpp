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

#include "EzStaminaModel.hpp"
#include <gs2/stamina/model/StaminaModel.hpp>


namespace gs2 { namespace ez { namespace stamina {

EzStaminaModel::Data::Data(const Data& data) :
    Gs2Object(data),
    name(data.name),
    metadata(data.metadata),
    recoverIntervalMinutes(data.recoverIntervalMinutes),
    recoverValue(data.recoverValue),
    initialCapacity(data.initialCapacity),
    isOverflow(data.isOverflow),
    maxCapacity(data.maxCapacity)
{
    if (data.maxStaminaTable)
    {
        maxStaminaTable = data.maxStaminaTable->deepCopy();
    }
    if (data.recoverIntervalTable)
    {
        recoverIntervalTable = data.recoverIntervalTable->deepCopy();
    }
    if (data.recoverValueTable)
    {
        recoverValueTable = data.recoverValueTable->deepCopy();
    }
}

EzStaminaModel::Data::Data(const gs2::stamina::StaminaModel& staminaModel) :
    name(staminaModel.getName()),
    metadata(staminaModel.getMetadata()),
    recoverIntervalMinutes(staminaModel.getRecoverIntervalMinutes() ? *staminaModel.getRecoverIntervalMinutes() : 0),
    recoverValue(staminaModel.getRecoverValue() ? *staminaModel.getRecoverValue() : 0),
    initialCapacity(staminaModel.getInitialCapacity() ? *staminaModel.getInitialCapacity() : 0),
    isOverflow(staminaModel.getIsOverflow() ? *staminaModel.getIsOverflow() : false),
    maxCapacity(staminaModel.getMaxCapacity() ? *staminaModel.getMaxCapacity() : 0),
    maxStaminaTable(*staminaModel.getMaxStaminaTable()),
    recoverIntervalTable(*staminaModel.getRecoverIntervalTable()),
    recoverValueTable(*staminaModel.getRecoverValueTable())
{
}

EzStaminaModel::EzStaminaModel(gs2::stamina::StaminaModel staminaModel) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(staminaModel)
{
}

EzStaminaModel EzStaminaModel::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzStaminaModel);
}

gs2::stamina::StaminaModel EzStaminaModel::ToModel() const
{
    gs2::stamina::StaminaModel staminaModel;
    staminaModel.setName(getName());
    staminaModel.setMetadata(getMetadata());
    staminaModel.setRecoverIntervalMinutes(getRecoverIntervalMinutes());
    staminaModel.setRecoverValue(getRecoverValue());
    staminaModel.setInitialCapacity(getInitialCapacity());
    staminaModel.setIsOverflow(getIsOverflow());
    staminaModel.setMaxCapacity(getMaxCapacity());
    staminaModel.setMaxStaminaTable(getMaxStaminaTable().ToModel());
    staminaModel.setRecoverIntervalTable(getRecoverIntervalTable().ToModel());
    staminaModel.setRecoverValueTable(getRecoverValueTable().ToModel());
    return staminaModel;
}

}}}