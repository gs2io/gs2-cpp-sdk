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

#include "EzThreshold.hpp"
#include <gs2/experience/model/Threshold.hpp>


namespace gs2 { namespace ez { namespace experience {

EzThreshold::Data::Data(const Data& data) :
    Gs2Object(data),
    metadata(data.metadata)
{
    if (data.values)
    {
        values = data.values->deepCopy();
    }
}

EzThreshold::Data::Data(const gs2::experience::Threshold& threshold) :
    metadata(threshold.getMetadata()),
    values(threshold.getValues())
{
}

EzThreshold::EzThreshold(gs2::experience::Threshold threshold) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(threshold)
{
}

EzThreshold EzThreshold::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzThreshold);
}

gs2::experience::Threshold EzThreshold::ToModel() const
{
    gs2::experience::Threshold threshold;
    threshold.setMetadata(getMetadata());
    threshold.setValues(getValues());
    return threshold;
}

}}}