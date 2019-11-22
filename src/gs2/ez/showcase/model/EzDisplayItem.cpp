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

#include "EzDisplayItem.hpp"
#include <gs2/showcase/model/DisplayItem.hpp>


namespace gs2 { namespace ez { namespace showcase {

EzDisplayItem::Data::Data(const Data& data) :
    Gs2Object(data),
    displayItemId(data.displayItemId),
    type(data.type)
{
    if (data.salesItem)
    {
        salesItem = data.salesItem->deepCopy();
    }
    if (data.salesItemGroup)
    {
        salesItemGroup = data.salesItemGroup->deepCopy();
    }
}

EzDisplayItem::Data::Data(const gs2::showcase::DisplayItem& displayItem) :
    displayItemId(displayItem.getDisplayItemId()),
    type(displayItem.getType()),
    salesItem(*displayItem.getSalesItem()),
    salesItemGroup(*displayItem.getSalesItemGroup())
{
}

EzDisplayItem::EzDisplayItem(gs2::showcase::DisplayItem displayItem) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(displayItem)
{
}

EzDisplayItem EzDisplayItem::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzDisplayItem);
}

gs2::showcase::DisplayItem EzDisplayItem::ToModel() const
{
    gs2::showcase::DisplayItem displayItem;
    displayItem.setDisplayItemId(getDisplayItemId());
    displayItem.setType(getType());
    displayItem.setSalesItem(getSalesItem().ToModel());
    displayItem.setSalesItemGroup(getSalesItemGroup().ToModel());
    return displayItem;
}

}}}