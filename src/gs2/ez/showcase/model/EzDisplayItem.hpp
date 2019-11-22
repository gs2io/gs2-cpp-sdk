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

#ifndef GS2_EZ_SHOWCASE_MODEL_EZDISPLAYITEM_HPP_
#define GS2_EZ_SHOWCASE_MODEL_EZDISPLAYITEM_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "EzSalesItem.hpp"
#include "EzSalesItemGroup.hpp"
#include <memory>


namespace gs2 {

namespace showcase {

class DisplayItem;

}

namespace ez { namespace showcase {

class EzDisplayItem : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 陳列商品ID */
        gs2::optional<StringHolder> displayItemId;
        /** 種類 */
        gs2::optional<StringHolder> type;
        /** 陳列する商品 */
        gs2::optional<EzSalesItem> salesItem;
        /** 陳列する商品グループ */
        gs2::optional<EzSalesItemGroup> salesItemGroup;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::showcase::DisplayItem& displayItem);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzDisplayItem() = default;
    EzDisplayItem(const EzDisplayItem& ezDisplayItem) = default;
    EzDisplayItem(EzDisplayItem&& ezDisplayItem) = default;
    ~EzDisplayItem() = default;

    EzDisplayItem(gs2::showcase::DisplayItem displayItem);

    EzDisplayItem& operator=(const EzDisplayItem& ezDisplayItem) = default;
    EzDisplayItem& operator=(EzDisplayItem&& ezDisplayItem) = default;

    EzDisplayItem deepCopy() const;

    gs2::showcase::DisplayItem ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getDisplayItemId() const
    {
        return *ensureData().displayItemId;
    }

    const StringHolder& getType() const
    {
        return *ensureData().type;
    }

    const EzSalesItem& getSalesItem() const
    {
        return *ensureData().salesItem;
    }

    const EzSalesItemGroup& getSalesItemGroup() const
    {
        return *ensureData().salesItemGroup;
    }

    // ========================================
    //   Setters
    // ========================================

    void setDisplayItemId(StringHolder displayItemId)
    {
        ensureData().displayItemId = std::move(displayItemId);
    }

    void setType(StringHolder type)
    {
        ensureData().type = std::move(type);
    }

    void setSalesItem(EzSalesItem salesItem)
    {
        ensureData().salesItem = std::move(salesItem);
    }

    void setSalesItemGroup(EzSalesItemGroup salesItemGroup)
    {
        ensureData().salesItemGroup = std::move(salesItemGroup);
    }

    EzDisplayItem& withDisplayItemId(StringHolder displayItemId)
    {
        setDisplayItemId(std::move(displayItemId));
        return *this;
    }

    EzDisplayItem& withType(StringHolder type)
    {
        setType(std::move(type));
        return *this;
    }

    EzDisplayItem& withSalesItem(EzSalesItem salesItem)
    {
        setSalesItem(std::move(salesItem));
        return *this;
    }

    EzDisplayItem& withSalesItemGroup(EzSalesItemGroup salesItemGroup)
    {
        setSalesItemGroup(std::move(salesItemGroup));
        return *this;
    }
};

}}}

#endif //GS2_EZ_SHOWCASE_EZDISPLAYITEM_HPP_