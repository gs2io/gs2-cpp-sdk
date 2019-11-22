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

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace inventory {

class ItemSet;

}

namespace ez { namespace inventory {

class EzItemSet : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 有効期限ごとのアイテム所持数量 */
        gs2::optional<StringHolder> itemSetId;
        /** インベントリの名前 */
        gs2::optional<StringHolder> inventoryName;
        /** アイテムマスターの名前 */
        gs2::optional<StringHolder> itemName;
        /** 所持数量 */
        gs2::optional<Int64> count;
        /** 有効期限 */
        gs2::optional<Int64> expiresAt;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::inventory::ItemSet& itemSet);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzItemSet() = default;
    EzItemSet(const EzItemSet& ezItemSet) = default;
    EzItemSet(EzItemSet&& ezItemSet) = default;
    ~EzItemSet() = default;

    EzItemSet(gs2::inventory::ItemSet itemSet);

    EzItemSet& operator=(const EzItemSet& ezItemSet) = default;
    EzItemSet& operator=(EzItemSet&& ezItemSet) = default;

    EzItemSet deepCopy() const;

    gs2::inventory::ItemSet ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getItemSetId() const
    {
        return *ensureData().itemSetId;
    }

    const StringHolder& getInventoryName() const
    {
        return *ensureData().inventoryName;
    }

    const StringHolder& getItemName() const
    {
        return *ensureData().itemName;
    }

    Int64 getCount() const
    {
        return *ensureData().count;
    }

    Int64 getExpiresAt() const
    {
        return *ensureData().expiresAt;
    }

    // ========================================
    //   Setters
    // ========================================

    void setItemSetId(StringHolder itemSetId)
    {
        ensureData().itemSetId = std::move(itemSetId);
    }

    void setInventoryName(StringHolder inventoryName)
    {
        ensureData().inventoryName = std::move(inventoryName);
    }

    void setItemName(StringHolder itemName)
    {
        ensureData().itemName = std::move(itemName);
    }

    void setCount(Int64 count)
    {
        ensureData().count = count;
    }

    void setExpiresAt(Int64 expiresAt)
    {
        ensureData().expiresAt = expiresAt;
    }

    EzItemSet& withItemSetId(StringHolder itemSetId)
    {
        setItemSetId(std::move(itemSetId));
        return *this;
    }

    EzItemSet& withInventoryName(StringHolder inventoryName)
    {
        setInventoryName(std::move(inventoryName));
        return *this;
    }

    EzItemSet& withItemName(StringHolder itemName)
    {
        setItemName(std::move(itemName));
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