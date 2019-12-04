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

#include "EzBoxItem.hpp"
#include <gs2/lottery/model/BoxItem.hpp>


namespace gs2 { namespace ez { namespace lottery {

EzBoxItem::Data::Data(const Data& data) :
    Gs2Object(data),
    remaining(data.remaining),
    initial(data.initial)
{
    if (data.acquireActions)
    {
        acquireActions = data.acquireActions->deepCopy();
    }
}

EzBoxItem::Data::Data(const gs2::lottery::BoxItem& boxItem) :
    remaining(boxItem.getRemaining() ? *boxItem.getRemaining() : 0),
    initial(boxItem.getInitial() ? *boxItem.getInitial() : 0)
{
    acquireActions.emplace();
    if (boxItem.getAcquireActions())
    {
        for (int i = 0; i < boxItem.getAcquireActions()->getCount(); ++i)
        {
            *acquireActions += EzAcquireAction((*boxItem.getAcquireActions())[i]);
        }
    }
}

EzBoxItem::EzBoxItem(gs2::lottery::BoxItem boxItem) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(boxItem)
{
}

EzBoxItem EzBoxItem::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzBoxItem);
}

gs2::lottery::BoxItem EzBoxItem::ToModel() const
{
    gs2::lottery::BoxItem boxItem;
    {
        gs2::List<gs2::lottery::AcquireAction> list;
        auto& acquireActions = getAcquireActions();
        for (int i = 0; i < acquireActions.getCount(); ++i)
        {
            list += acquireActions[i].ToModel();
        }
        boxItem.setAcquireActions(list);
    }
    boxItem.setRemaining(getRemaining());
    boxItem.setInitial(getInitial());
    return boxItem;
}

}}}