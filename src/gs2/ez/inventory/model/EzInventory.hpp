

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

#ifndef GS2_EZ_INVENTORY_MODEL_EZINVENTORY_HPP_
#define GS2_EZ_INVENTORY_MODEL_EZINVENTORY_HPP_

#include <gs2/inventory/model/Inventory.hpp>


namespace gs2 { namespace ez { namespace inventory {

class EzInventory : public gs2::Gs2Object
{
private:
    /** インベントリ */
    gs2::optional<StringHolder> m_InventoryId;
    /** インベントリモデル名 */
    gs2::optional<StringHolder> m_InventoryName;
    /** 現在のインベントリのキャパシティ使用量 */
    gs2::optional<Int32> m_CurrentInventoryCapacityUsage;
    /** 現在のインベントリの最大キャパシティ */
    gs2::optional<Int32> m_CurrentInventoryMaxCapacity;

public:
    EzInventory() = default;

    EzInventory(gs2::inventory::Inventory inventory) :
        m_InventoryId(inventory.getInventoryId()),
        m_InventoryName(inventory.getInventoryName()),
        m_CurrentInventoryCapacityUsage(inventory.getCurrentInventoryCapacityUsage() ? *inventory.getCurrentInventoryCapacityUsage() : 0),
        m_CurrentInventoryMaxCapacity(inventory.getCurrentInventoryMaxCapacity() ? *inventory.getCurrentInventoryMaxCapacity() : 0)
    {
    }

    gs2::inventory::Inventory ToModel() const
    {
        gs2::inventory::Inventory inventory;
        inventory.setInventoryId(*m_InventoryId);
        inventory.setInventoryName(*m_InventoryName);
        inventory.setCurrentInventoryCapacityUsage(*m_CurrentInventoryCapacityUsage);
        inventory.setCurrentInventoryMaxCapacity(*m_CurrentInventoryMaxCapacity);
        return inventory;
    }

    // ========================================
    //   Getters
    // ========================================

    const gs2::StringHolder& getInventoryId() const
    {
        return *m_InventoryId;
    }

    gs2::StringHolder& getInventoryId()
    {
        return *m_InventoryId;
    }

    const gs2::StringHolder& getInventoryName() const
    {
        return *m_InventoryName;
    }

    gs2::StringHolder& getInventoryName()
    {
        return *m_InventoryName;
    }

    Int32 getCurrentInventoryCapacityUsage() const
    {
        return *m_CurrentInventoryCapacityUsage;
    }

    Int32 getCurrentInventoryMaxCapacity() const
    {
        return *m_CurrentInventoryMaxCapacity;
    }

    // ========================================
    //   Setters
    // ========================================

    void setInventoryId(Char* inventoryId)
    {
        m_InventoryId.emplace(inventoryId);
    }

    void setInventoryName(Char* inventoryName)
    {
        m_InventoryName.emplace(inventoryName);
    }

    void setCurrentInventoryCapacityUsage(Int32 currentInventoryCapacityUsage)
    {
        m_CurrentInventoryCapacityUsage = currentInventoryCapacityUsage;
    }

    void setCurrentInventoryMaxCapacity(Int32 currentInventoryMaxCapacity)
    {
        m_CurrentInventoryMaxCapacity = currentInventoryMaxCapacity;
    }

    EzInventory& withInventoryId(Char* inventoryId)
    {
        setInventoryId(inventoryId);
        return *this;
    }

    EzInventory& withInventoryName(Char* inventoryName)
    {
        setInventoryName(inventoryName);
        return *this;
    }

    EzInventory& withCurrentInventoryCapacityUsage(Int32 currentInventoryCapacityUsage)
    {
        setCurrentInventoryCapacityUsage(currentInventoryCapacityUsage);
        return *this;
    }

    EzInventory& withCurrentInventoryMaxCapacity(Int32 currentInventoryMaxCapacity)
    {
        setCurrentInventoryMaxCapacity(currentInventoryMaxCapacity);
        return *this;
    }
};

}}}

#endif //GS2_EZ_INVENTORY_EZINVENTORY_HPP_