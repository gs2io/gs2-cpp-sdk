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

#include "EzItemSet.hpp"
#include <gs2/inventory/model/ItemSet.hpp>


namespace gs2 { namespace ez { namespace inventory {

EzItemSet::Data::Data(const Data& data) :
    Gs2Object(data),
    itemSetId(data.itemSetId),
    name(data.name),
    inventoryName(data.inventoryName),
    itemName(data.itemName),
    count(data.count),
    sortValue(data.sortValue),
    expiresAt(data.expiresAt)
{
}

EzItemSet::Data::Data(const gs2::inventory::ItemSet& itemSet) :
    itemSetId(itemSet.getItemSetId() ? *itemSet.getItemSetId() : StringHolder()),
    name(itemSet.getName() ? *itemSet.getName() : StringHolder()),
    inventoryName(itemSet.getInventoryName() ? *itemSet.getInventoryName() : StringHolder()),
    itemName(itemSet.getItemName() ? *itemSet.getItemName() : StringHolder()),
    count(itemSet.getCount() ? *itemSet.getCount() : 0),
    sortValue(itemSet.getSortValue() ? *itemSet.getSortValue() : 0),
    expiresAt(itemSet.getExpiresAt() ? *itemSet.getExpiresAt() : 0)
{
}

EzItemSet::Data::Data(const gs2::optional<gs2::inventory::ItemSet>& itemSet) :
    itemSetId(itemSet && itemSet->getItemSetId() ? *itemSet->getItemSetId() : StringHolder()),
    name(itemSet && itemSet->getName() ? *itemSet->getName() : StringHolder()),
    inventoryName(itemSet && itemSet->getInventoryName() ? *itemSet->getInventoryName() : StringHolder()),
    itemName(itemSet && itemSet->getItemName() ? *itemSet->getItemName() : StringHolder()),
    count(itemSet && itemSet->getCount() ? *itemSet->getCount() : 0),
    sortValue(itemSet && itemSet->getSortValue() ? *itemSet->getSortValue() : 0),
    expiresAt(itemSet && itemSet->getExpiresAt() ? *itemSet->getExpiresAt() : 0)
{
}

EzItemSet::EzItemSet(gs2::inventory::ItemSet itemSet) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(itemSet)
{
}

EzItemSet::EzItemSet(gs2::optional<gs2::inventory::ItemSet> itemSet) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(itemSet)
{
}

EzItemSet EzItemSet::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzItemSet);
}

gs2::inventory::ItemSet EzItemSet::ToModel() const
{
    gs2::inventory::ItemSet itemSet;
    itemSet.setItemSetId(getItemSetId());
    itemSet.setName(getName());
    itemSet.setInventoryName(getInventoryName());
    itemSet.setItemName(getItemName());
    itemSet.setCount(getCount());
    itemSet.setSortValue(getSortValue());
    itemSet.setExpiresAt(getExpiresAt());
    return itemSet;
}

}}}