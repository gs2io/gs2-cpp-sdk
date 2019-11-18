

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
    class Data : public gs2::Gs2Object
    {
    public:
        /** アイテムモデルの種類名 */
        gs2::optional<StringHolder> name;
        /** アイテムモデルの種類のメタデータ */
        gs2::optional<StringHolder> metadata;
        /** スタック可能な最大数量 */
        gs2::optional<Int64> stackingLimit;
        /** スタック可能な最大数量を超えた時複数枠にアイテムを保管することを許すか */
        gs2::optional<Bool> allowMultipleStacks;
        /** 表示順番 */
        gs2::optional<Int32> sortValue;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            name(data.name),
            metadata(data.metadata),
            stackingLimit(data.stackingLimit),
            allowMultipleStacks(data.allowMultipleStacks),
            sortValue(data.sortValue)
        {
        }

        Data(Data&& data) = default;

        Data(const gs2::inventory::ItemModel& itemModel) :
            name(itemModel.getName()),
            metadata(itemModel.getMetadata()),
            stackingLimit(itemModel.getStackingLimit() ? *itemModel.getStackingLimit() : 0),
            allowMultipleStacks(itemModel.getAllowMultipleStacks() ? *itemModel.getAllowMultipleStacks() : false),
            sortValue(itemModel.getSortValue() ? *itemModel.getSortValue() : 0)
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzItemModel() = default;
    EzItemModel(const EzItemModel& ezItemModel) = default;
    EzItemModel(EzItemModel&& ezItemModel) = default;
    ~EzItemModel() = default;

    EzItemModel(gs2::inventory::ItemModel itemModel) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(itemModel)
    {}

    EzItemModel& operator=(const EzItemModel& ezItemModel) = default;
    EzItemModel& operator=(EzItemModel&& ezItemModel) = default;

    EzItemModel deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzItemModel);
    }

    gs2::inventory::ItemModel ToModel() const
    {
        gs2::inventory::ItemModel itemModel;
        itemModel.setName(getName());
        itemModel.setMetadata(getMetadata());
        itemModel.setStackingLimit(getStackingLimit());
        itemModel.setAllowMultipleStacks(getAllowMultipleStacks());
        itemModel.setSortValue(getSortValue());
        return itemModel;
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

    Int64 getStackingLimit() const
    {
        return *ensureData().stackingLimit;
    }

    Bool getAllowMultipleStacks() const
    {
        return *ensureData().allowMultipleStacks;
    }

    Int32 getSortValue() const
    {
        return *ensureData().sortValue;
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

    void setStackingLimit(Int64 stackingLimit)
    {
        ensureData().stackingLimit = stackingLimit;
    }

    void setAllowMultipleStacks(Bool allowMultipleStacks)
    {
        ensureData().allowMultipleStacks = allowMultipleStacks;
    }

    void setSortValue(Int32 sortValue)
    {
        ensureData().sortValue = sortValue;
    }

    EzItemModel& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    EzItemModel& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
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