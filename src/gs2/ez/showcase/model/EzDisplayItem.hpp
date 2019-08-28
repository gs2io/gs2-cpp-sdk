

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

#include <gs2/showcase/model/DisplayItem.hpp>
#include "EzSalesItem.hpp"
#include "EzSalesItemGroup.hpp"


namespace gs2 { namespace ez { namespace showcase {

class EzDisplayItem : public gs2::Gs2Object
{
private:
    /** 陳列商品ID */
    gs2::optional<StringHolder> m_DisplayItemId;
    /** 種類 */
    gs2::optional<StringHolder> m_Type;
    /** 陳列する商品 */
    gs2::optional<EzSalesItem> m_SalesItem;
    /** 陳列する商品グループ */
    gs2::optional<EzSalesItemGroup> m_SalesItemGroup;

public:
    EzDisplayItem() = default;

    EzDisplayItem(gs2::showcase::DisplayItem displayItem) :
        m_DisplayItemId(displayItem.getDisplayItemId()),
        m_Type(displayItem.getType()),
        m_SalesItem(*displayItem.getSalesItem()),
        m_SalesItemGroup(*displayItem.getSalesItemGroup())
    {
    }

    gs2::showcase::DisplayItem ToModel() const
    {
        gs2::showcase::DisplayItem displayItem;
        displayItem.setDisplayItemId(*m_DisplayItemId);
        displayItem.setType(*m_Type);
        displayItem.setSalesItem(m_SalesItem->ToModel());
        displayItem.setSalesItemGroup(m_SalesItemGroup->ToModel());
        return displayItem;
    }

    // ========================================
    //   Getters
    // ========================================

    const gs2::StringHolder& getDisplayItemId() const
    {
        return *m_DisplayItemId;
    }

    gs2::StringHolder& getDisplayItemId()
    {
        return *m_DisplayItemId;
    }

    const gs2::StringHolder& getType() const
    {
        return *m_Type;
    }

    gs2::StringHolder& getType()
    {
        return *m_Type;
    }

    const EzSalesItem& getSalesItem() const
    {
        return *m_SalesItem;
    }

    EzSalesItem& getSalesItem()
    {
        return *m_SalesItem;
    }

    const EzSalesItemGroup& getSalesItemGroup() const
    {
        return *m_SalesItemGroup;
    }

    EzSalesItemGroup& getSalesItemGroup()
    {
        return *m_SalesItemGroup;
    }

    // ========================================
    //   Setters
    // ========================================

    void setDisplayItemId(Char* displayItemId)
    {
        m_DisplayItemId.emplace(displayItemId);
    }

    void setType(Char* type)
    {
        m_Type.emplace(type);
    }

    void setSalesItem(const EzSalesItem& salesItem)
    {
        m_SalesItem = salesItem;
    }

    void setSalesItem(EzSalesItem&& salesItem)
    {
        m_SalesItem = std::move(salesItem);
    }

    void setSalesItemGroup(const EzSalesItemGroup& salesItemGroup)
    {
        m_SalesItemGroup = salesItemGroup;
    }

    void setSalesItemGroup(EzSalesItemGroup&& salesItemGroup)
    {
        m_SalesItemGroup = std::move(salesItemGroup);
    }

    EzDisplayItem& withDisplayItemId(Char* displayItemId)
    {
        setDisplayItemId(displayItemId);
        return *this;
    }

    EzDisplayItem& withType(Char* type)
    {
        setType(type);
        return *this;
    }

    EzDisplayItem& withSalesItem(const EzSalesItem& salesItem)
    {
        setSalesItem(salesItem);
        return *this;
    }

    EzDisplayItem& withSalesItem(EzSalesItem&& salesItem)
    {
        setSalesItem(std::move(salesItem));
        return *this;
    }

    EzDisplayItem& withSalesItemGroup(const EzSalesItemGroup& salesItemGroup)
    {
        setSalesItemGroup(salesItemGroup);
        return *this;
    }

    EzDisplayItem& withSalesItemGroup(EzSalesItemGroup&& salesItemGroup)
    {
        setSalesItemGroup(std::move(salesItemGroup));
        return *this;
    }
};

}}}

#endif //GS2_EZ_SHOWCASE_EZDISPLAYITEM_HPP_