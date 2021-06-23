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

#include "EzRecoverIntervalTable.hpp"
#include <gs2/stamina/model/RecoverIntervalTable.hpp>


namespace gs2 { namespace ez { namespace stamina {

EzRecoverIntervalTable::Data::Data(const Data& data) :
    Gs2Object(data),
    name(data.name),
    metadata(data.metadata),
    experienceModelId(data.experienceModelId)
{
    if (data.values)
    {
        values = data.values->deepCopy();
    }
}

EzRecoverIntervalTable::Data::Data(const gs2::stamina::RecoverIntervalTable& recoverIntervalTable) :
    name(recoverIntervalTable.getName()),
    metadata(recoverIntervalTable.getMetadata()),
    experienceModelId(recoverIntervalTable.getExperienceModelId()),
    values(recoverIntervalTable.getValues())
{
}

EzRecoverIntervalTable::EzRecoverIntervalTable(gs2::stamina::RecoverIntervalTable recoverIntervalTable) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(recoverIntervalTable)
{
}

EzRecoverIntervalTable EzRecoverIntervalTable::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzRecoverIntervalTable);
}

gs2::stamina::RecoverIntervalTable EzRecoverIntervalTable::ToModel() const
{
    gs2::stamina::RecoverIntervalTable recoverIntervalTable;
    recoverIntervalTable.setName(getName());
    recoverIntervalTable.setMetadata(getMetadata());
    recoverIntervalTable.setExperienceModelId(getExperienceModelId());
    recoverIntervalTable.setValues(getValues());
    return recoverIntervalTable;
}

}}}