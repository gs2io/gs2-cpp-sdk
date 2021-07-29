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

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace inventory {

class Inventory;

}

namespace ez { namespace inventory {

class EzInventory : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** インベントリ */
        StringHolder inventoryId;
        /** インベントリモデル名 */
        StringHolder inventoryName;
        /** 現在のインベントリのキャパシティ使用量 */
        Int32 currentInventoryCapacityUsage;
        /** 現在のインベントリの最大キャパシティ */
        Int32 currentInventoryMaxCapacity;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::inventory::Inventory& inventory);
        Data(const gs2::optional<gs2::inventory::Inventory>& inventory);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzInventory() = default;
    EzInventory(const EzInventory& ezInventory) = default;
    EzInventory(EzInventory&& ezInventory) = default;
    ~EzInventory() = default;

    EzInventory(gs2::inventory::Inventory inventory);
    EzInventory(gs2::optional<gs2::inventory::Inventory> inventory);

    EzInventory& operator=(const EzInventory& ezInventory) = default;
    EzInventory& operator=(EzInventory&& ezInventory) = default;

    EzInventory deepCopy() const;

    gs2::inventory::Inventory ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getInventoryId() const
    {
        return ensureData().inventoryId;
    }

    const StringHolder& getInventoryName() const
    {
        return ensureData().inventoryName;
    }

    Int32 getCurrentInventoryCapacityUsage() const
    {
        return ensureData().currentInventoryCapacityUsage;
    }

    Int32 getCurrentInventoryMaxCapacity() const
    {
        return ensureData().currentInventoryMaxCapacity;
    }

    // ========================================
    //   Setters
    // ========================================

    void setInventoryId(StringHolder inventoryId)
    {
        ensureData().inventoryId = std::move(inventoryId);
    }

    void setInventoryName(StringHolder inventoryName)
    {
        ensureData().inventoryName = std::move(inventoryName);
    }

    void setCurrentInventoryCapacityUsage(Int32 currentInventoryCapacityUsage)
    {
        ensureData().currentInventoryCapacityUsage = currentInventoryCapacityUsage;
    }

    void setCurrentInventoryMaxCapacity(Int32 currentInventoryMaxCapacity)
    {
        ensureData().currentInventoryMaxCapacity = currentInventoryMaxCapacity;
    }

    EzInventory& withInventoryId(StringHolder inventoryId)
    {
        setInventoryId(std::move(inventoryId));
        return *this;
    }

    EzInventory& withInventoryName(StringHolder inventoryName)
    {
        setInventoryName(std::move(inventoryName));
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