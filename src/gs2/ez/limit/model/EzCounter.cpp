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

#include "EzCounter.hpp"
#include <gs2/limit/model/Counter.hpp>


namespace gs2 { namespace ez { namespace limit {

EzCounter::Data::Data(const Data& data) :
    Gs2Object(data),
    counterId(data.counterId),
    name(data.name),
    count(data.count),
    createdAt(data.createdAt),
    updatedAt(data.updatedAt)
{
}

EzCounter::Data::Data(const gs2::limit::Counter& counter) :
    counterId(counter.getCounterId()),
    name(counter.getName()),
    count(counter.getCount() ? *counter.getCount() : 0),
    createdAt(counter.getCreatedAt() ? *counter.getCreatedAt() : 0),
    updatedAt(counter.getUpdatedAt() ? *counter.getUpdatedAt() : 0)
{
}

EzCounter::EzCounter(gs2::limit::Counter counter) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(counter)
{
}

EzCounter EzCounter::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzCounter);
}

gs2::limit::Counter EzCounter::ToModel() const
{
    gs2::limit::Counter counter;
    counter.setCounterId(getCounterId());
    counter.setName(getName());
    counter.setCount(getCount());
    counter.setCreatedAt(getCreatedAt());
    counter.setUpdatedAt(getUpdatedAt());
    return counter;
}

}}}