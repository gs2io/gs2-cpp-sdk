

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

#ifndef GS2_EZ_SHOWCASE_MODEL_EZSALESITEMGROUP_HPP_
#define GS2_EZ_SHOWCASE_MODEL_EZSALESITEMGROUP_HPP_

#include <gs2/showcase/model/SalesItemGroup.hpp>
#include "EzSalesItem.hpp"


namespace gs2 { namespace ez { namespace showcase {

class EzSalesItemGroup : public gs2::Gs2Object
{
private:
    /** 商品グループ名 */
    gs2::optional<StringHolder> m_Name;
    /** メタデータ */
    gs2::optional<StringHolder> m_Metadata;
    /** 商品リスト */
    gs2::optional<List<EzSalesItem>> m_SalesItems;

public:
    EzSalesItemGroup() = default;

    EzSalesItemGroup(gs2::showcase::SalesItemGroup salesItemGroup) :
        m_Name(salesItemGroup.getName()),
        m_Metadata(salesItemGroup.getMetadata())
    {
        m_SalesItems.emplace();
        if (salesItemGroup.getSalesItems())
        {
            for (int i = 0; i < salesItemGroup.getSalesItems()->getCount(); ++i)
            {
                *m_SalesItems += EzSalesItem((*salesItemGroup.getSalesItems())[i]);
            }
        }
    }

    gs2::showcase::SalesItemGroup ToModel() const
    {
        gs2::showcase::SalesItemGroup salesItemGroup;
        salesItemGroup.setName(*m_Name);
        salesItemGroup.setMetadata(*m_Metadata);
        {
            gs2::List<gs2::showcase::SalesItem> list;
            auto& salesItems = *m_SalesItems;
            for (int i = 0; i < salesItems.getCount(); ++i)
            {
                list += salesItems[i].ToModel();
            }
            salesItemGroup.setSalesItems(list);
        }
        return salesItemGroup;
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

    const List<EzSalesItem>& getSalesItems() const
    {
        return *m_SalesItems;
    }

    List<EzSalesItem>& getSalesItems()
    {
        return *m_SalesItems;
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

    void setSalesItems(const List<EzSalesItem>& salesItems)
    {
        m_SalesItems = salesItems;
    }

    void setSalesItems(List<EzSalesItem>&& salesItems)
    {
        m_SalesItems = std::move(salesItems);
    }

    EzSalesItemGroup& withName(Char* name)
    {
        setName(name);
        return *this;
    }

    EzSalesItemGroup& withMetadata(Char* metadata)
    {
        setMetadata(metadata);
        return *this;
    }

    EzSalesItemGroup& withSalesItems(const List<EzSalesItem>& salesItems)
    {
        setSalesItems(salesItems);
        return *this;
    }

    EzSalesItemGroup& withSalesItems(List<EzSalesItem>&& salesItems)
    {
        setSalesItems(std::move(salesItems));
        return *this;
    }
};

}}}

#endif //GS2_EZ_SHOWCASE_EZSALESITEMGROUP_HPP_