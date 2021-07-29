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
    values = data.values.deepCopy();
}

EzRecoverIntervalTable::Data::Data(const gs2::stamina::RecoverIntervalTable& recoverIntervalTable) :
    name(recoverIntervalTable.getName() ? *recoverIntervalTable.getName() : StringHolder()),
    metadata(recoverIntervalTable.getMetadata() ? *recoverIntervalTable.getMetadata() : StringHolder()),
    experienceModelId(recoverIntervalTable.getExperienceModelId() ? *recoverIntervalTable.getExperienceModelId() : StringHolder()),
    values(recoverIntervalTable.getValues() ? *recoverIntervalTable.getValues() : List<Int32>())
{
}

EzRecoverIntervalTable::Data::Data(const gs2::optional<gs2::stamina::RecoverIntervalTable>& recoverIntervalTable) :
    name(recoverIntervalTable && recoverIntervalTable->getName() ? *recoverIntervalTable->getName() : StringHolder()),
    metadata(recoverIntervalTable && recoverIntervalTable->getMetadata() ? *recoverIntervalTable->getMetadata() : StringHolder()),
    experienceModelId(recoverIntervalTable && recoverIntervalTable->getExperienceModelId() ? *recoverIntervalTable->getExperienceModelId() : StringHolder()),
    values(recoverIntervalTable && recoverIntervalTable->getValues() ? *recoverIntervalTable->getValues() : List<Int32>())
{
}

EzRecoverIntervalTable::EzRecoverIntervalTable(gs2::stamina::RecoverIntervalTable recoverIntervalTable) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(recoverIntervalTable)
{
}

EzRecoverIntervalTable::EzRecoverIntervalTable(gs2::optional<gs2::stamina::RecoverIntervalTable> recoverIntervalTable) :
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