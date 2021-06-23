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

#include "EzScopedValue.hpp"
#include <gs2/mission/model/ScopedValue.hpp>


namespace gs2 { namespace ez { namespace mission {

EzScopedValue::Data::Data(const Data& data) :
    Gs2Object(data),
    resetType(data.resetType),
    value(data.value)
{
}

EzScopedValue::Data::Data(const gs2::mission::ScopedValue& scopedValue) :
    resetType(scopedValue.getResetType()),
    value(scopedValue.getValue() ? *scopedValue.getValue() : 0)
{
}

EzScopedValue::EzScopedValue(gs2::mission::ScopedValue scopedValue) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(scopedValue)
{
}

EzScopedValue EzScopedValue::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzScopedValue);
}

gs2::mission::ScopedValue EzScopedValue::ToModel() const
{
    gs2::mission::ScopedValue scopedValue;
    scopedValue.setResetType(getResetType());
    scopedValue.setValue(getValue());
    return scopedValue;
}

}}}