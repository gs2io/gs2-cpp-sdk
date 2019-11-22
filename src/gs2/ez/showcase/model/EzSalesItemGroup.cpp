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

#include "EzSalesItemGroup.hpp"
#include <gs2/showcase/model/SalesItemGroup.hpp>


namespace gs2 { namespace ez { namespace showcase {

EzSalesItemGroup::Data::Data(const Data& data) :
    Gs2Object(data),
    name(data.name),
    metadata(data.metadata)
{
    if (data.salesItems)
    {
        salesItems = data.salesItems->deepCopy();
    }
}

EzSalesItemGroup::Data::Data(const gs2::showcase::SalesItemGroup& salesItemGroup) :
    name(salesItemGroup.getName()),
    metadata(salesItemGroup.getMetadata())
{
    salesItems.emplace();
    if (salesItemGroup.getSalesItems())
    {
        for (int i = 0; i < salesItemGroup.getSalesItems()->getCount(); ++i)
        {
            *salesItems += EzSalesItem((*salesItemGroup.getSalesItems())[i]);
        }
    }
}

EzSalesItemGroup::EzSalesItemGroup(gs2::showcase::SalesItemGroup salesItemGroup) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(salesItemGroup)
{
}

EzSalesItemGroup EzSalesItemGroup::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzSalesItemGroup);
}

gs2::showcase::SalesItemGroup EzSalesItemGroup::ToModel() const
{
    gs2::showcase::SalesItemGroup salesItemGroup;
    salesItemGroup.setName(getName());
    salesItemGroup.setMetadata(getMetadata());
    {
        gs2::List<gs2::showcase::SalesItem> list;
        auto& salesItems = getSalesItems();
        for (int i = 0; i < salesItems.getCount(); ++i)
        {
            list += salesItems[i].ToModel();
        }
        salesItemGroup.setSalesItems(list);
    }
    return salesItemGroup;
}

}}}