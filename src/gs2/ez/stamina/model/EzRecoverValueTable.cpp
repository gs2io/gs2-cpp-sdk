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

#include "EzRecoverValueTable.hpp"
#include <gs2/stamina/model/RecoverValueTable.hpp>


namespace gs2 { namespace ez { namespace stamina {

EzRecoverValueTable::Data::Data(const Data& data) :
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

EzRecoverValueTable::Data::Data(const gs2::stamina::RecoverValueTable& recoverValueTable) :
    name(recoverValueTable.getName()),
    metadata(recoverValueTable.getMetadata()),
    experienceModelId(recoverValueTable.getExperienceModelId()),
    values(recoverValueTable.getValues())
{
}

EzRecoverValueTable::EzRecoverValueTable(gs2::stamina::RecoverValueTable recoverValueTable) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(recoverValueTable)
{
}

EzRecoverValueTable EzRecoverValueTable::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzRecoverValueTable);
}

gs2::stamina::RecoverValueTable EzRecoverValueTable::ToModel() const
{
    gs2::stamina::RecoverValueTable recoverValueTable;
    recoverValueTable.setName(getName());
    recoverValueTable.setMetadata(getMetadata());
    recoverValueTable.setExperienceModelId(getExperienceModelId());
    recoverValueTable.setValues(getValues());
    return recoverValueTable;
}

}}}