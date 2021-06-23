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
#include <gs2/mission/model/Counter.hpp>


namespace gs2 { namespace ez { namespace mission {

EzCounter::Data::Data(const Data& data) :
    Gs2Object(data),
    name(data.name)
{
    if (data.values)
    {
        values = data.values->deepCopy();
    }
}

EzCounter::Data::Data(const gs2::mission::Counter& counter) :
    name(counter.getName())
{
    values.emplace();
    if (counter.getValues())
    {
        for (int i = 0; i < counter.getValues()->getCount(); ++i)
        {
            *values += EzScopedValue((*counter.getValues())[i]);
        }
    }
}

EzCounter::EzCounter(gs2::mission::Counter counter) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(counter)
{
}

EzCounter EzCounter::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzCounter);
}

gs2::mission::Counter EzCounter::ToModel() const
{
    gs2::mission::Counter counter;
    counter.setName(getName());
    {
        gs2::List<gs2::mission::ScopedValue> list;
        auto& values = getValues();
        for (int i = 0; i < values.getCount(); ++i)
        {
            list += values[i].ToModel();
        }
        counter.setValues(list);
    }
    return counter;
}

}}}