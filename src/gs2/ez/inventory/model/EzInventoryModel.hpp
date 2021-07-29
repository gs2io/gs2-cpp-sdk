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

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace inventory {

class InventoryModel;

}

namespace ez { namespace inventory {

class EzInventoryModel : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** インベントリの種類名 */
        StringHolder name;
        /** インベントリの種類のメタデータ */
        StringHolder metadata;
        /** インベントリの初期サイズ */
        Int32 initialCapacity;
        /** インベントリの最大サイズ */
        Int32 maxCapacity;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::inventory::InventoryModel& inventoryModel);
        Data(const gs2::optional<gs2::inventory::InventoryModel>& inventoryModel);
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

    EzInventoryModel(gs2::inventory::InventoryModel inventoryModel);
    EzInventoryModel(gs2::optional<gs2::inventory::InventoryModel> inventoryModel);

    EzInventoryModel& operator=(const EzInventoryModel& ezInventoryModel) = default;
    EzInventoryModel& operator=(EzInventoryModel&& ezInventoryModel) = default;

    EzInventoryModel deepCopy() const;

    gs2::inventory::InventoryModel ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getName() const
    {
        return ensureData().name;
    }

    const StringHolder& getMetadata() const
    {
        return ensureData().metadata;
    }

    Int32 getInitialCapacity() const
    {
        return ensureData().initialCapacity;
    }

    Int32 getMaxCapacity() const
    {
        return ensureData().maxCapacity;
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