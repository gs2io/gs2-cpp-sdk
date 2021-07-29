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

#include "EzAttributeRange.hpp"
#include <gs2/matchmaking/model/AttributeRange.hpp>


namespace gs2 { namespace ez { namespace matchmaking {

EzAttributeRange::Data::Data(const Data& data) :
    Gs2Object(data),
    name(data.name),
    min(data.min),
    max(data.max)
{
}

EzAttributeRange::Data::Data(const gs2::matchmaking::AttributeRange& attributeRange) :
    name(attributeRange.getName() ? *attributeRange.getName() : StringHolder()),
    min(attributeRange.getMin() ? *attributeRange.getMin() : 0),
    max(attributeRange.getMax() ? *attributeRange.getMax() : 0)
{
}

EzAttributeRange::Data::Data(const gs2::optional<gs2::matchmaking::AttributeRange>& attributeRange) :
    name(attributeRange && attributeRange->getName() ? *attributeRange->getName() : StringHolder()),
    min(attributeRange && attributeRange->getMin() ? *attributeRange->getMin() : 0),
    max(attributeRange && attributeRange->getMax() ? *attributeRange->getMax() : 0)
{
}

EzAttributeRange::EzAttributeRange(gs2::matchmaking::AttributeRange attributeRange) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(attributeRange)
{
}

EzAttributeRange::EzAttributeRange(gs2::optional<gs2::matchmaking::AttributeRange> attributeRange) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(attributeRange)
{
}

EzAttributeRange EzAttributeRange::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzAttributeRange);
}

gs2::matchmaking::AttributeRange EzAttributeRange::ToModel() const
{
    gs2::matchmaking::AttributeRange attributeRange;
    attributeRange.setName(getName());
    attributeRange.setMin(getMin());
    attributeRange.setMax(getMax());
    return attributeRange;
}

}}}