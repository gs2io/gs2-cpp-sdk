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

#include "EzMaxStaminaTable.hpp"
#include <gs2/stamina/model/MaxStaminaTable.hpp>


namespace gs2 { namespace ez { namespace stamina {

EzMaxStaminaTable::Data::Data(const Data& data) :
    Gs2Object(data),
    name(data.name),
    metadata(data.metadata),
    experienceModelId(data.experienceModelId)
{
    values = data.values.deepCopy();
}

EzMaxStaminaTable::Data::Data(const gs2::stamina::MaxStaminaTable& maxStaminaTable) :
    name(maxStaminaTable.getName() ? *maxStaminaTable.getName() : StringHolder()),
    metadata(maxStaminaTable.getMetadata() ? *maxStaminaTable.getMetadata() : StringHolder()),
    experienceModelId(maxStaminaTable.getExperienceModelId() ? *maxStaminaTable.getExperienceModelId() : StringHolder()),
    values(maxStaminaTable.getValues() ? *maxStaminaTable.getValues() : List<Int32>())
{
}

EzMaxStaminaTable::Data::Data(const gs2::optional<gs2::stamina::MaxStaminaTable>& maxStaminaTable) :
    name(maxStaminaTable && maxStaminaTable->getName() ? *maxStaminaTable->getName() : StringHolder()),
    metadata(maxStaminaTable && maxStaminaTable->getMetadata() ? *maxStaminaTable->getMetadata() : StringHolder()),
    experienceModelId(maxStaminaTable && maxStaminaTable->getExperienceModelId() ? *maxStaminaTable->getExperienceModelId() : StringHolder()),
    values(maxStaminaTable && maxStaminaTable->getValues() ? *maxStaminaTable->getValues() : List<Int32>())
{
}

EzMaxStaminaTable::EzMaxStaminaTable(gs2::stamina::MaxStaminaTable maxStaminaTable) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(maxStaminaTable)
{
}

EzMaxStaminaTable::EzMaxStaminaTable(gs2::optional<gs2::stamina::MaxStaminaTable> maxStaminaTable) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(maxStaminaTable)
{
}

EzMaxStaminaTable EzMaxStaminaTable::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzMaxStaminaTable);
}

gs2::stamina::MaxStaminaTable EzMaxStaminaTable::ToModel() const
{
    gs2::stamina::MaxStaminaTable maxStaminaTable;
    maxStaminaTable.setName(getName());
    maxStaminaTable.setMetadata(getMetadata());
    maxStaminaTable.setExperienceModelId(getExperienceModelId());
    maxStaminaTable.setValues(getValues());
    return maxStaminaTable;
}

}}}