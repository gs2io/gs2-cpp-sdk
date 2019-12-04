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

#include "EzMold.hpp"
#include <gs2/formation/model/Mold.hpp>


namespace gs2 { namespace ez { namespace formation {

EzMold::Data::Data(const Data& data) :
    Gs2Object(data),
    name(data.name),
    userId(data.userId),
    capacity(data.capacity)
{
}

EzMold::Data::Data(const gs2::formation::Mold& mold) :
    name(mold.getName()),
    userId(mold.getUserId()),
    capacity(mold.getCapacity() ? *mold.getCapacity() : 0)
{
}

EzMold::EzMold(gs2::formation::Mold mold) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(mold)
{
}

EzMold EzMold::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzMold);
}

gs2::formation::Mold EzMold::ToModel() const
{
    gs2::formation::Mold mold;
    mold.setName(getName());
    mold.setUserId(getUserId());
    mold.setCapacity(getCapacity());
    return mold;
}

}}}