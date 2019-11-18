

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
    class Data : public gs2::Gs2Object
    {
    public:
        /** 商品名 */
        gs2::optional<StringHolder> name;
        /** 商品のメタデータ */
        gs2::optional<StringHolder> metadata;
        /** インベントリに格納可能なアイテムモデル一覧 */
        gs2::optional<List<EzDisplayItem>> displayItems;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            name(data.name),
            metadata(data.metadata)
        {
            if (data.displayItems)
            {
                displayItems = data.displayItems->deepCopy();
            }
        }

        Data(Data&& data) = default;

        Data(const gs2::showcase::Showcase& showcase) :
            name(showcase.getName()),
            metadata(showcase.getMetadata())
        {
            displayItems.emplace();
            if (showcase.getDisplayItems())
            {
                for (int i = 0; i < showcase.getDisplayItems()->getCount(); ++i)
                {
                    *displayItems += EzDisplayItem((*showcase.getDisplayItems())[i]);
                }
            }
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzShowcase() = default;
    EzShowcase(const EzShowcase& ezShowcase) = default;
    EzShowcase(EzShowcase&& ezShowcase) = default;
    ~EzShowcase() = default;

    EzShowcase(gs2::showcase::Showcase showcase) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(showcase)
    {}

    EzShowcase& operator=(const EzShowcase& ezShowcase) = default;
    EzShowcase& operator=(EzShowcase&& ezShowcase) = default;

    EzShowcase deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzShowcase);
    }

    gs2::showcase::Showcase ToModel() const
    {
        gs2::showcase::Showcase showcase;
        showcase.setName(getName());
        showcase.setMetadata(getMetadata());
        {
            gs2::List<gs2::showcase::DisplayItem> list;
            auto& displayItems = getDisplayItems();
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

    const StringHolder& getName() const
    {
        return *ensureData().name;
    }

    const StringHolder& getMetadata() const
    {
        return *ensureData().metadata;
    }

    const List<EzDisplayItem>& getDisplayItems() const
    {
        return *ensureData().displayItems;
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

    void setDisplayItems(List<EzDisplayItem> displayItems)
    {
        ensureData().displayItems = std::move(displayItems);
    }

    EzShowcase& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    EzShowcase& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    EzShowcase& withDisplayItems(List<EzDisplayItem> displayItems)
    {
        setDisplayItems(std::move(displayItems));
        return *this;
    }
};

}}}

#endif //GS2_EZ_SHOWCASE_EZSHOWCASE_HPP_