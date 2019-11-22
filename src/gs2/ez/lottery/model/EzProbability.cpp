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

#include "EzProbability.hpp"
#include <gs2/lottery/model/Probability.hpp>


namespace gs2 { namespace ez { namespace lottery {

EzProbability::Data::Data(const Data& data) :
    Gs2Object(data),
    rate(data.rate)
{
    if (data.prize)
    {
        prize = data.prize->deepCopy();
    }
}

EzProbability::Data::Data(const gs2::lottery::Probability& probability) :
    prize(*probability.getPrize()),
    rate(probability.getRate() ? *probability.getRate() : 0)
{
}

EzProbability::EzProbability(gs2::lottery::Probability probability) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(probability)
{
}

EzProbability EzProbability::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzProbability);
}

gs2::lottery::Probability EzProbability::ToModel() const
{
    gs2::lottery::Probability probability;
    probability.setPrize(getPrize().ToModel());
    probability.setRate(getRate());
    return probability;
}

}}}