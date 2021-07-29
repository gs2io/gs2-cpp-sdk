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

#include "EzInventoryModel.hpp"
#include <gs2/inventory/model/InventoryModel.hpp>


namespace gs2 { namespace ez { namespace inventory {

EzInventoryModel::Data::Data(const Data& data) :
    Gs2Object(data),
    name(data.name),
    metadata(data.metadata),
    initialCapacity(data.initialCapacity),
    maxCapacity(data.maxCapacity)
{
}

EzInventoryModel::Data::Data(const gs2::inventory::InventoryModel& inventoryModel) :
    name(inventoryModel.getName() ? *inventoryModel.getName() : StringHolder()),
    metadata(inventoryModel.getMetadata() ? *inventoryModel.getMetadata() : StringHolder()),
    initialCapacity(inventoryModel.getInitialCapacity() ? *inventoryModel.getInitialCapacity() : 0),
    maxCapacity(inventoryModel.getMaxCapacity() ? *inventoryModel.getMaxCapacity() : 0)
{
}

EzInventoryModel::Data::Data(const gs2::optional<gs2::inventory::InventoryModel>& inventoryModel) :
    name(inventoryModel && inventoryModel->getName() ? *inventoryModel->getName() : StringHolder()),
    metadata(inventoryModel && inventoryModel->getMetadata() ? *inventoryModel->getMetadata() : StringHolder()),
    initialCapacity(inventoryModel && inventoryModel->getInitialCapacity() ? *inventoryModel->getInitialCapacity() : 0),
    maxCapacity(inventoryModel && inventoryModel->getMaxCapacity() ? *inventoryModel->getMaxCapacity() : 0)
{
}

EzInventoryModel::EzInventoryModel(gs2::inventory::InventoryModel inventoryModel) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(inventoryModel)
{
}

EzInventoryModel::EzInventoryModel(gs2::optional<gs2::inventory::InventoryModel> inventoryModel) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(inventoryModel)
{
}

EzInventoryModel EzInventoryModel::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzInventoryModel);
}

gs2::inventory::InventoryModel EzInventoryModel::ToModel() const
{
    gs2::inventory::InventoryModel inventoryModel;
    inventoryModel.setName(getName());
    inventoryModel.setMetadata(getMetadata());
    inventoryModel.setInitialCapacity(getInitialCapacity());
    inventoryModel.setMaxCapacity(getMaxCapacity());
    return inventoryModel;
}

}}}