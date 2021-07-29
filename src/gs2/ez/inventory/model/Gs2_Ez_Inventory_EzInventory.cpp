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

#include "EzInventory.hpp"
#include <gs2/inventory/model/Inventory.hpp>


namespace gs2 { namespace ez { namespace inventory {

EzInventory::Data::Data(const Data& data) :
    Gs2Object(data),
    inventoryId(data.inventoryId),
    inventoryName(data.inventoryName),
    currentInventoryCapacityUsage(data.currentInventoryCapacityUsage),
    currentInventoryMaxCapacity(data.currentInventoryMaxCapacity)
{
}

EzInventory::Data::Data(const gs2::inventory::Inventory& inventory) :
    inventoryId(inventory.getInventoryId() ? *inventory.getInventoryId() : StringHolder()),
    inventoryName(inventory.getInventoryName() ? *inventory.getInventoryName() : StringHolder()),
    currentInventoryCapacityUsage(inventory.getCurrentInventoryCapacityUsage() ? *inventory.getCurrentInventoryCapacityUsage() : 0),
    currentInventoryMaxCapacity(inventory.getCurrentInventoryMaxCapacity() ? *inventory.getCurrentInventoryMaxCapacity() : 0)
{
}

EzInventory::Data::Data(const gs2::optional<gs2::inventory::Inventory>& inventory) :
    inventoryId(inventory && inventory->getInventoryId() ? *inventory->getInventoryId() : StringHolder()),
    inventoryName(inventory && inventory->getInventoryName() ? *inventory->getInventoryName() : StringHolder()),
    currentInventoryCapacityUsage(inventory && inventory->getCurrentInventoryCapacityUsage() ? *inventory->getCurrentInventoryCapacityUsage() : 0),
    currentInventoryMaxCapacity(inventory && inventory->getCurrentInventoryMaxCapacity() ? *inventory->getCurrentInventoryMaxCapacity() : 0)
{
}

EzInventory::EzInventory(gs2::inventory::Inventory inventory) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(inventory)
{
}

EzInventory::EzInventory(gs2::optional<gs2::inventory::Inventory> inventory) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(inventory)
{
}

EzInventory EzInventory::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzInventory);
}

gs2::inventory::Inventory EzInventory::ToModel() const
{
    gs2::inventory::Inventory inventory;
    inventory.setInventoryId(getInventoryId());
    inventory.setInventoryName(getInventoryName());
    inventory.setCurrentInventoryCapacityUsage(getCurrentInventoryCapacityUsage());
    inventory.setCurrentInventoryMaxCapacity(getCurrentInventoryMaxCapacity());
    return inventory;
}

}}}