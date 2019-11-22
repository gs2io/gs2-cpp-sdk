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

#include "EzItemModel.hpp"
#include <gs2/inventory/model/ItemModel.hpp>


namespace gs2 { namespace ez { namespace inventory {

EzItemModel::Data::Data(const Data& data) :
    Gs2Object(data),
    name(data.name),
    metadata(data.metadata),
    stackingLimit(data.stackingLimit),
    allowMultipleStacks(data.allowMultipleStacks),
    sortValue(data.sortValue)
{
}

EzItemModel::Data::Data(const gs2::inventory::ItemModel& itemModel) :
    name(itemModel.getName()),
    metadata(itemModel.getMetadata()),
    stackingLimit(itemModel.getStackingLimit() ? *itemModel.getStackingLimit() : 0),
    allowMultipleStacks(itemModel.getAllowMultipleStacks() ? *itemModel.getAllowMultipleStacks() : false),
    sortValue(itemModel.getSortValue() ? *itemModel.getSortValue() : 0)
{
}

EzItemModel::EzItemModel(gs2::inventory::ItemModel itemModel) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(itemModel)
{
}

EzItemModel EzItemModel::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzItemModel);
}

gs2::inventory::ItemModel EzItemModel::ToModel() const
{
    gs2::inventory::ItemModel itemModel;
    itemModel.setName(getName());
    itemModel.setMetadata(getMetadata());
    itemModel.setStackingLimit(getStackingLimit());
    itemModel.setAllowMultipleStacks(getAllowMultipleStacks());
    itemModel.setSortValue(getSortValue());
    return itemModel;
}

}}}