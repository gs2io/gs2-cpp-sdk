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

#include "EzEntryModel.hpp"
#include <gs2/dictionary/model/EntryModel.hpp>


namespace gs2 { namespace ez { namespace dictionary {

EzEntryModel::Data::Data(const Data& data) :
    Gs2Object(data),
    name(data.name),
    metadata(data.metadata)
{
}

EzEntryModel::Data::Data(const gs2::dictionary::EntryModel& entryModel) :
    name(entryModel.getName() ? *entryModel.getName() : StringHolder()),
    metadata(entryModel.getMetadata() ? *entryModel.getMetadata() : StringHolder())
{
}

EzEntryModel::Data::Data(const gs2::optional<gs2::dictionary::EntryModel>& entryModel) :
    name(entryModel && entryModel->getName() ? *entryModel->getName() : StringHolder()),
    metadata(entryModel && entryModel->getMetadata() ? *entryModel->getMetadata() : StringHolder())
{
}

EzEntryModel::EzEntryModel(gs2::dictionary::EntryModel entryModel) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(entryModel)
{
}

EzEntryModel::EzEntryModel(gs2::optional<gs2::dictionary::EntryModel> entryModel) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(entryModel)
{
}

EzEntryModel EzEntryModel::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzEntryModel);
}

gs2::dictionary::EntryModel EzEntryModel::ToModel() const
{
    gs2::dictionary::EntryModel entryModel;
    entryModel.setName(getName());
    entryModel.setMetadata(getMetadata());
    return entryModel;
}

}}}