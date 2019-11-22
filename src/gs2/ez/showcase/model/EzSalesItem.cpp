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

#include "EzSalesItem.hpp"
#include <gs2/showcase/model/SalesItem.hpp>


namespace gs2 { namespace ez { namespace showcase {

EzSalesItem::Data::Data(const Data& data) :
    Gs2Object(data),
    name(data.name),
    metadata(data.metadata)
{
    if (data.consumeActions)
    {
        consumeActions = data.consumeActions->deepCopy();
    }
    if (data.acquireActions)
    {
        acquireActions = data.acquireActions->deepCopy();
    }
}

EzSalesItem::Data::Data(const gs2::showcase::SalesItem& salesItem) :
    name(salesItem.getName()),
    metadata(salesItem.getMetadata())
{
    consumeActions.emplace();
    if (salesItem.getConsumeActions())
    {
        for (int i = 0; i < salesItem.getConsumeActions()->getCount(); ++i)
        {
            *consumeActions += EzConsumeAction((*salesItem.getConsumeActions())[i]);
        }
    }
    acquireActions.emplace();
    if (salesItem.getAcquireActions())
    {
        for (int i = 0; i < salesItem.getAcquireActions()->getCount(); ++i)
        {
            *acquireActions += EzAcquireAction((*salesItem.getAcquireActions())[i]);
        }
    }
}

EzSalesItem::EzSalesItem(gs2::showcase::SalesItem salesItem) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(salesItem)
{
}

EzSalesItem EzSalesItem::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzSalesItem);
}

gs2::showcase::SalesItem EzSalesItem::ToModel() const
{
    gs2::showcase::SalesItem salesItem;
    salesItem.setName(getName());
    salesItem.setMetadata(getMetadata());
    {
        gs2::List<gs2::showcase::ConsumeAction> list;
        auto& consumeActions = getConsumeActions();
        for (int i = 0; i < consumeActions.getCount(); ++i)
        {
            list += consumeActions[i].ToModel();
        }
        salesItem.setConsumeActions(list);
    }
    {
        gs2::List<gs2::showcase::AcquireAction> list;
        auto& acquireActions = getAcquireActions();
        for (int i = 0; i < acquireActions.getCount(); ++i)
        {
            list += acquireActions[i].ToModel();
        }
        salesItem.setAcquireActions(list);
    }
    return salesItem;
}

}}}