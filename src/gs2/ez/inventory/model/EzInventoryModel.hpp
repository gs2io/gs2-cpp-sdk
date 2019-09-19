

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

#ifndef GS2_EZ_INVENTORY_MODEL_EZINVENTORYMODEL_HPP_
#define GS2_EZ_INVENTORY_MODEL_EZINVENTORYMODEL_HPP_

#include <gs2/inventory/model/InventoryModel.hpp>


namespace gs2 { namespace ez { namespace inventory {

class EzInventoryModel : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** インベントリの種類名 */
        gs2::optional<StringHolder> name;
        /** インベントリの種類のメタデータ */
        gs2::optional<StringHolder> metadata;
        /** インベントリの初期サイズ */
        gs2::optional<Int32> initialCapacity;
        /** インベントリの最大サイズ */
        gs2::optional<Int32> maxCapacity;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            name(data.name),
            metadata(data.metadata),
            initialCapacity(data.initialCapacity),
            maxCapacity(data.maxCapacity)
        {
        }

        Data(Data&& data) = default;

        Data(const gs2::inventory::InventoryModel& inventoryModel) :
            name(inventoryModel.getName()),
            metadata(inventoryModel.getMetadata()),
            initialCapacity(inventoryModel.getInitialCapacity() ? *inventoryModel.getInitialCapacity() : 0),
            maxCapacity(inventoryModel.getMaxCapacity() ? *inventoryModel.getMaxCapacity() : 0)
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzInventoryModel() = default;
    EzInventoryModel(const EzInventoryModel& ezInventoryModel) = default;
    EzInventoryModel(EzInventoryModel&& ezInventoryModel) = default;
    ~EzInventoryModel() = default;

    EzInventoryModel(gs2::inventory::InventoryModel inventoryModel) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(inventoryModel)
    {}

    EzInventoryModel& operator=(const EzInventoryModel& ezInventoryModel) = default;
    EzInventoryModel& operator=(EzInventoryModel&& ezInventoryModel) = default;

    EzInventoryModel deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzInventoryModel);
    }

    gs2::inventory::InventoryModel ToModel() const
    {
        gs2::inventory::InventoryModel inventoryModel;
        inventoryModel.setName(getName());
        inventoryModel.setMetadata(getMetadata());
        inventoryModel.setInitialCapacity(getInitialCapacity());
        inventoryModel.setMaxCapacity(getMaxCapacity());
        return inventoryModel;
    }

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getName() const
    {
        return *ensureData().name;
    }

    const StringHolder& getMetadata() const
    {
        return *ensureData().metadata;
    }

    Int32 getInitialCapacity() const
    {
        return *ensureData().initialCapacity;
    }

    Int32 getMaxCapacity() const
    {
        return *ensureData().maxCapacity;
    }

    // ========================================
    //   Setters
    // ========================================

    void setName(StringHolder name)
    {
        ensureData().name = std::move(name);
    }

    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata = std::move(metadata);
    }

    void setInitialCapacity(Int32 initialCapacity)
    {
        ensureData().initialCapacity = initialCapacity;
    }

    void setMaxCapacity(Int32 maxCapacity)
    {
        ensureData().maxCapacity = maxCapacity;
    }

    EzInventoryModel& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    EzInventoryModel& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    EzInventoryModel& withInitialCapacity(Int32 initialCapacity)
    {
        setInitialCapacity(initialCapacity);
        return *this;
    }

    EzInventoryModel& withMaxCapacity(Int32 maxCapacity)
    {
        setMaxCapacity(maxCapacity);
        return *this;
    }
};

}}}

#endif //GS2_EZ_INVENTORY_EZINVENTORYMODEL_HPP_