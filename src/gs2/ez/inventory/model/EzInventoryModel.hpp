

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
    /** インベントリの種類名 */
    gs2::optional<StringHolder> m_Name;
    /** インベントリの種類のメタデータ */
    gs2::optional<StringHolder> m_Metadata;
    /** インベントリの初期サイズ */
    gs2::optional<Int32> m_InitialCapacity;
    /** インベントリの最大サイズ */
    gs2::optional<Int32> m_MaxCapacity;

public:
    EzInventoryModel() = default;

    EzInventoryModel(gs2::inventory::InventoryModel inventoryModel) :
        m_Name(inventoryModel.getName()),
        m_Metadata(inventoryModel.getMetadata()),
        m_InitialCapacity(inventoryModel.getInitialCapacity() ? *inventoryModel.getInitialCapacity() : 0),
        m_MaxCapacity(inventoryModel.getMaxCapacity() ? *inventoryModel.getMaxCapacity() : 0)
    {
    }

    gs2::inventory::InventoryModel ToModel() const
    {
        gs2::inventory::InventoryModel inventoryModel;
        inventoryModel.setName(*m_Name);
        inventoryModel.setMetadata(*m_Metadata);
        inventoryModel.setInitialCapacity(*m_InitialCapacity);
        inventoryModel.setMaxCapacity(*m_MaxCapacity);
        return inventoryModel;
    }

    // ========================================
    //   Getters
    // ========================================

    const gs2::StringHolder& getName() const
    {
        return *m_Name;
    }

    gs2::StringHolder& getName()
    {
        return *m_Name;
    }

    const gs2::StringHolder& getMetadata() const
    {
        return *m_Metadata;
    }

    gs2::StringHolder& getMetadata()
    {
        return *m_Metadata;
    }

    Int32 getInitialCapacity() const
    {
        return *m_InitialCapacity;
    }

    Int32 getMaxCapacity() const
    {
        return *m_MaxCapacity;
    }

    // ========================================
    //   Setters
    // ========================================

    void setName(Char* name)
    {
        m_Name.emplace(name);
    }

    void setMetadata(Char* metadata)
    {
        m_Metadata.emplace(metadata);
    }

    void setInitialCapacity(Int32 initialCapacity)
    {
        m_InitialCapacity = initialCapacity;
    }

    void setMaxCapacity(Int32 maxCapacity)
    {
        m_MaxCapacity = maxCapacity;
    }

    EzInventoryModel& withName(Char* name)
    {
        setName(name);
        return *this;
    }

    EzInventoryModel& withMetadata(Char* metadata)
    {
        setMetadata(metadata);
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