

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

#ifndef GS2_EZ_INVENTORY_MODEL_EZITEMMODEL_HPP_
#define GS2_EZ_INVENTORY_MODEL_EZITEMMODEL_HPP_

#include <gs2/inventory/model/ItemModel.hpp>


namespace gs2 { namespace ez { namespace inventory {

class EzItemModel : public gs2::Gs2Object
{
private:
    /** アイテムモデルの種類名 */
    gs2::optional<StringHolder> m_Name;
    /** アイテムモデルの種類のメタデータ */
    gs2::optional<StringHolder> m_Metadata;
    /** スタック可能な最大数量 */
    gs2::optional<Int64> m_StackingLimit;
    /** スタック可能な最大数量を超えた時複数枠にアイテムを保管することを許すか */
    gs2::optional<Bool> m_AllowMultipleStacks;
    /** 表示順番 */
    gs2::optional<Int32> m_SortValue;

public:
    EzItemModel() = default;

    EzItemModel(gs2::inventory::ItemModel itemModel) :
        m_Name(itemModel.getName()),
        m_Metadata(itemModel.getMetadata()),
        m_StackingLimit(itemModel.getStackingLimit() ? *itemModel.getStackingLimit() : 0),
        m_AllowMultipleStacks(itemModel.getAllowMultipleStacks() ? *itemModel.getAllowMultipleStacks() : false),
        m_SortValue(itemModel.getSortValue() ? *itemModel.getSortValue() : 0)
    {
    }

    gs2::inventory::ItemModel ToModel() const
    {
        gs2::inventory::ItemModel itemModel;
        itemModel.setName(*m_Name);
        itemModel.setMetadata(*m_Metadata);
        itemModel.setStackingLimit(*m_StackingLimit);
        itemModel.setAllowMultipleStacks(*m_AllowMultipleStacks);
        itemModel.setSortValue(*m_SortValue);
        return itemModel;
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

    Int64 getStackingLimit() const
    {
        return *m_StackingLimit;
    }

    Bool getAllowMultipleStacks() const
    {
        return *m_AllowMultipleStacks;
    }

    Int32 getSortValue() const
    {
        return *m_SortValue;
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

    void setStackingLimit(Int64 stackingLimit)
    {
        m_StackingLimit = stackingLimit;
    }

    void setAllowMultipleStacks(Bool allowMultipleStacks)
    {
        m_AllowMultipleStacks = allowMultipleStacks;
    }

    void setSortValue(Int32 sortValue)
    {
        m_SortValue = sortValue;
    }

    EzItemModel& withName(Char* name)
    {
        setName(name);
        return *this;
    }

    EzItemModel& withMetadata(Char* metadata)
    {
        setMetadata(metadata);
        return *this;
    }

    EzItemModel& withStackingLimit(Int64 stackingLimit)
    {
        setStackingLimit(stackingLimit);
        return *this;
    }

    EzItemModel& withAllowMultipleStacks(Bool allowMultipleStacks)
    {
        setAllowMultipleStacks(allowMultipleStacks);
        return *this;
    }

    EzItemModel& withSortValue(Int32 sortValue)
    {
        setSortValue(sortValue);
        return *this;
    }
};

}}}

#endif //GS2_EZ_INVENTORY_EZITEMMODEL_HPP_