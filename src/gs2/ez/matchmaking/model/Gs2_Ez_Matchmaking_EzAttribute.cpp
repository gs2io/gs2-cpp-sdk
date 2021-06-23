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

#include "EzAttribute.hpp"
#include <gs2/matchmaking/model/Attribute.hpp>


namespace gs2 { namespace ez { namespace matchmaking {

EzAttribute::Data::Data(const Data& data) :
    Gs2Object(data),
    name(data.name),
    value(data.value)
{
}

EzAttribute::Data::Data(const gs2::matchmaking::Attribute& attribute) :
    name(attribute.getName()),
    value(attribute.getValue() ? *attribute.getValue() : 0)
{
}

EzAttribute::EzAttribute(gs2::matchmaking::Attribute attribute) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(attribute)
{
}

EzAttribute EzAttribute::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzAttribute);
}

gs2::matchmaking::Attribute EzAttribute::ToModel() const
{
    gs2::matchmaking::Attribute attribute;
    attribute.setName(getName());
    attribute.setValue(getValue());
    return attribute;
}

}}}