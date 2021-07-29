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

#include "EzShowcase.hpp"
#include <gs2/showcase/model/Showcase.hpp>


namespace gs2 { namespace ez { namespace showcase {

EzShowcase::Data::Data(const Data& data) :
    Gs2Object(data),
    name(data.name),
    metadata(data.metadata)
{
    displayItems = data.displayItems.deepCopy();
}

EzShowcase::Data::Data(const gs2::showcase::Showcase& showcase) :
    name(showcase.getName() ? *showcase.getName() : StringHolder()),
    metadata(showcase.getMetadata() ? *showcase.getMetadata() : StringHolder())
{
    if (showcase.getDisplayItems())
    {
        for (int i = 0; i < showcase.getDisplayItems()->getCount(); ++i)
        {
            displayItems += EzDisplayItem((*showcase.getDisplayItems())[i]);
        }
    }
}

EzShowcase::Data::Data(const gs2::optional<gs2::showcase::Showcase>& showcase) :
    name(showcase && showcase->getName() ? *showcase->getName() : StringHolder()),
    metadata(showcase && showcase->getMetadata() ? *showcase->getMetadata() : StringHolder())
{
    if (showcase && showcase->getDisplayItems())
    {
        for (int i = 0; i < showcase->getDisplayItems()->getCount(); ++i)
        {
            displayItems += EzDisplayItem((*showcase->getDisplayItems())[i]);
        }
    }
}

EzShowcase::EzShowcase(gs2::showcase::Showcase showcase) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(showcase)
{
}

EzShowcase::EzShowcase(gs2::optional<gs2::showcase::Showcase> showcase) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(showcase)
{
}

EzShowcase EzShowcase::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzShowcase);
}

gs2::showcase::Showcase EzShowcase::ToModel() const
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

}}}