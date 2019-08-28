

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

#ifndef GS2_EZ_INVENTORY_MODEL_EZITEMSET_HPP_
#define GS2_EZ_INVENTORY_MODEL_EZITEMSET_HPP_

#include <gs2/inventory/model/ItemSet.hpp>


namespace gs2 { namespace ez { namespace inventory {

class EzItemSet : public gs2::Gs2Object
{
private:
    /** 有効期限ごとのアイテム所持数量 */
    gs2::optional<StringHolder> m_ItemSetId;
    /** インベントリの名前 */
    gs2::optional<StringHolder> m_InventoryName;
    /** アイテムマスターの名前 */
    gs2::optional<StringHolder> m_ItemName;
    /** 所持数量 */
    gs2::optional<Int64> m_Count;
    /** 有効期限 */
    gs2::optional<Int64> m_ExpiresAt;

public:
    EzItemSet() = default;

    EzItemSet(gs2::inventory::ItemSet itemSet) :
        m_ItemSetId(itemSet.getItemSetId()),
        m_InventoryName(itemSet.getInventoryName()),
        m_ItemName(itemSet.getItemName()),
        m_Count(itemSet.getCount() ? *itemSet.getCount() : 0),
        m_ExpiresAt(itemSet.getExpiresAt() ? *itemSet.getExpiresAt() : 0)
    {
    }

    gs2::inventory::ItemSet ToModel() const
    {
        gs2::inventory::ItemSet itemSet;
        itemSet.setItemSetId(*m_ItemSetId);
        itemSet.setInventoryName(*m_InventoryName);
        itemSet.setItemName(*m_ItemName);
        itemSet.setCount(*m_Count);
        itemSet.setExpiresAt(*m_ExpiresAt);
        return itemSet;
    }

    // ========================================
    //   Getters
    // ========================================

    const gs2::StringHolder& getItemSetId() const
    {
        return *m_ItemSetId;
    }

    gs2::StringHolder& getItemSetId()
    {
        return *m_ItemSetId;
    }

    const gs2::StringHolder& getInventoryName() const
    {
        return *m_InventoryName;
    }

    gs2::StringHolder& getInventoryName()
    {
        return *m_InventoryName;
    }

    const gs2::StringHolder& getItemName() const
    {
        return *m_ItemName;
    }

    gs2::StringHolder& getItemName()
    {
        return *m_ItemName;
    }

    Int64 getCount() const
    {
        return *m_Count;
    }

    Int64 getExpiresAt() const
    {
        return *m_ExpiresAt;
    }

    // ========================================
    //   Setters
    // ========================================

    void setItemSetId(Char* itemSetId)
    {
        m_ItemSetId.emplace(itemSetId);
    }

    void setInventoryName(Char* inventoryName)
    {
        m_InventoryName.emplace(inventoryName);
    }

    void setItemName(Char* itemName)
    {
        m_ItemName.emplace(itemName);
    }

    void setCount(Int64 count)
    {
        m_Count = count;
    }

    void setExpiresAt(Int64 expiresAt)
    {
        m_ExpiresAt = expiresAt;
    }

    EzItemSet& withItemSetId(Char* itemSetId)
    {
        setItemSetId(itemSetId);
        return *this;
    }

    EzItemSet& withInventoryName(Char* inventoryName)
    {
        setInventoryName(inventoryName);
        return *this;
    }

    EzItemSet& withItemName(Char* itemName)
    {
        setItemName(itemName);
        return *this;
    }

    EzItemSet& withCount(Int64 count)
    {
        setCount(count);
        return *this;
    }

    EzItemSet& withExpiresAt(Int64 expiresAt)
    {
        setExpiresAt(expiresAt);
        return *this;
    }
};

}}}

#endif //GS2_EZ_INVENTORY_EZITEMSET_HPP_