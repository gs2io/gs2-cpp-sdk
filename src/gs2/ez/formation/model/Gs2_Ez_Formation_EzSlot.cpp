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

#include "EzSlot.hpp"
#include <gs2/formation/model/Slot.hpp>


namespace gs2 { namespace ez { namespace formation {

EzSlot::Data::Data(const Data& data) :
    Gs2Object(data),
    name(data.name),
    propertyId(data.propertyId),
    metadata(data.metadata)
{
}

EzSlot::Data::Data(const gs2::formation::Slot& slot) :
    name(slot.getName()),
    propertyId(slot.getPropertyId()),
    metadata(slot.getMetadata())
{
}

EzSlot::EzSlot(gs2::formation::Slot slot) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(slot)
{
}

EzSlot EzSlot::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzSlot);
}

gs2::formation::Slot EzSlot::ToModel() const
{
    gs2::formation::Slot slot;
    slot.setName(getName());
    slot.setPropertyId(getPropertyId());
    slot.setMetadata(getMetadata());
    return slot;
}

}}}