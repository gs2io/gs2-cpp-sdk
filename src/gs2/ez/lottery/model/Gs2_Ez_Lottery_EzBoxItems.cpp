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

#include "EzBoxItems.hpp"
#include <gs2/lottery/model/BoxItems.hpp>


namespace gs2 { namespace ez { namespace lottery {

EzBoxItems::Data::Data(const Data& data) :
    Gs2Object(data),
    boxId(data.boxId),
    prizeTableName(data.prizeTableName)
{
    items = data.items.deepCopy();
}

EzBoxItems::Data::Data(const gs2::lottery::BoxItems& boxItems) :
    boxId(boxItems.getBoxId() ? *boxItems.getBoxId() : StringHolder()),
    prizeTableName(boxItems.getPrizeTableName() ? *boxItems.getPrizeTableName() : StringHolder())
{
    if (boxItems.getItems())
    {
        for (int i = 0; i < boxItems.getItems()->getCount(); ++i)
        {
            items += EzBoxItem((*boxItems.getItems())[i]);
        }
    }
}

EzBoxItems::Data::Data(const gs2::optional<gs2::lottery::BoxItems>& boxItems) :
    boxId(boxItems && boxItems->getBoxId() ? *boxItems->getBoxId() : StringHolder()),
    prizeTableName(boxItems && boxItems->getPrizeTableName() ? *boxItems->getPrizeTableName() : StringHolder())
{
    if (boxItems && boxItems->getItems())
    {
        for (int i = 0; i < boxItems->getItems()->getCount(); ++i)
        {
            items += EzBoxItem((*boxItems->getItems())[i]);
        }
    }
}

EzBoxItems::EzBoxItems(gs2::lottery::BoxItems boxItems) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(boxItems)
{
}

EzBoxItems::EzBoxItems(gs2::optional<gs2::lottery::BoxItems> boxItems) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(boxItems)
{
}

EzBoxItems EzBoxItems::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzBoxItems);
}

gs2::lottery::BoxItems EzBoxItems::ToModel() const
{
    gs2::lottery::BoxItems boxItems;
    boxItems.setBoxId(getBoxId());
    boxItems.setPrizeTableName(getPrizeTableName());
    {
        gs2::List<gs2::lottery::BoxItem> list;
        auto& items = getItems();
        for (int i = 0; i < items.getCount(); ++i)
        {
            list += items[i].ToModel();
        }
        boxItems.setItems(list);
    }
    return boxItems;
}

}}}