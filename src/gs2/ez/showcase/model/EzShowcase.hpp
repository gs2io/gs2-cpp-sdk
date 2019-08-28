

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

#ifndef GS2_EZ_SHOWCASE_MODEL_EZSHOWCASE_HPP_
#define GS2_EZ_SHOWCASE_MODEL_EZSHOWCASE_HPP_

#include <gs2/showcase/model/Showcase.hpp>
#include "EzDisplayItem.hpp"


namespace gs2 { namespace ez { namespace showcase {

class EzShowcase : public gs2::Gs2Object
{
private:
    /** 商品名 */
    gs2::optional<StringHolder> m_Name;
    /** 商品のメタデータ */
    gs2::optional<StringHolder> m_Metadata;
    /** インベントリに格納可能なアイテムモデル一覧 */
    gs2::optional<List<EzDisplayItem>> m_DisplayItems;

public:
    EzShowcase() = default;

    EzShowcase(gs2::showcase::Showcase showcase) :
        m_Name(showcase.getName()),
        m_Metadata(showcase.getMetadata())
    {
        m_DisplayItems.emplace();
        if (showcase.getDisplayItems())
        {
            for (int i = 0; i < showcase.getDisplayItems()->getCount(); ++i)
            {
                *m_DisplayItems += EzDisplayItem((*showcase.getDisplayItems())[i]);
            }
        }
    }

    gs2::showcase::Showcase ToModel() const
    {
        gs2::showcase::Showcase showcase;
        showcase.setName(*m_Name);
        showcase.setMetadata(*m_Metadata);
        {
            gs2::List<gs2::showcase::DisplayItem> list;
            auto& displayItems = *m_DisplayItems;
            for (int i = 0; i < displayItems.getCount(); ++i)
            {
                list += displayItems[i].ToModel();
            }
            showcase.setDisplayItems(list);
        }
        return showcase;
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

    const List<EzDisplayItem>& getDisplayItems() const
    {
        return *m_DisplayItems;
    }

    List<EzDisplayItem>& getDisplayItems()
    {
        return *m_DisplayItems;
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

    void setDisplayItems(const List<EzDisplayItem>& displayItems)
    {
        m_DisplayItems = displayItems;
    }

    void setDisplayItems(List<EzDisplayItem>&& displayItems)
    {
        m_DisplayItems = std::move(displayItems);
    }

    EzShowcase& withName(Char* name)
    {
        setName(name);
        return *this;
    }

    EzShowcase& withMetadata(Char* metadata)
    {
        setMetadata(metadata);
        return *this;
    }

    EzShowcase& withDisplayItems(const List<EzDisplayItem>& displayItems)
    {
        setDisplayItems(displayItems);
        return *this;
    }

    EzShowcase& withDisplayItems(List<EzDisplayItem>&& displayItems)
    {
        setDisplayItems(std::move(displayItems));
        return *this;
    }
};

}}}

#endif //GS2_EZ_SHOWCASE_EZSHOWCASE_HPP_