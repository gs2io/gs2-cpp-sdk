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

#include "EzSlotWithSignature.hpp"
#include <gs2/formation/model/SlotWithSignature.hpp>


namespace gs2 { namespace ez { namespace formation {

EzSlotWithSignature::Data::Data(const Data& data) :
    Gs2Object(data),
    name(data.name),
    propertyType(data.propertyType),
    body(data.body),
    signature(data.signature),
    metadata(data.metadata)
{
}

EzSlotWithSignature::Data::Data(const gs2::formation::SlotWithSignature& slotWithSignature) :
    name(slotWithSignature.getName()),
    propertyType(slotWithSignature.getPropertyType()),
    body(slotWithSignature.getBody()),
    signature(slotWithSignature.getSignature()),
    metadata(slotWithSignature.getMetadata())
{
}

EzSlotWithSignature::EzSlotWithSignature(gs2::formation::SlotWithSignature slotWithSignature) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(slotWithSignature)
{
}

EzSlotWithSignature EzSlotWithSignature::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzSlotWithSignature);
}

gs2::formation::SlotWithSignature EzSlotWithSignature::ToModel() const
{
    gs2::formation::SlotWithSignature slotWithSignature;
    slotWithSignature.setName(getName());
    slotWithSignature.setPropertyType(getPropertyType());
    slotWithSignature.setBody(getBody());
    slotWithSignature.setSignature(getSignature());
    slotWithSignature.setMetadata(getMetadata());
    return slotWithSignature;
}

}}}