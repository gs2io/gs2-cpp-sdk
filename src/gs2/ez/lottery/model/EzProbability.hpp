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

#ifndef GS2_EZ_LOTTERY_MODEL_EZPROBABILITY_HPP_
#define GS2_EZ_LOTTERY_MODEL_EZPROBABILITY_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "EzDrawnPrize.hpp"
#include <memory>


namespace gs2 {

namespace lottery {

class Probability;

}

namespace ez { namespace lottery {

class EzProbability : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 景品の種類 */
        gs2::optional<EzDrawnPrize> prize;
        /** 排出確率(0.0〜1.0) */
        gs2::optional<Float> rate;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::lottery::Probability& probability);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzProbability() = default;
    EzProbability(const EzProbability& ezProbability) = default;
    EzProbability(EzProbability&& ezProbability) = default;
    ~EzProbability() = default;

    EzProbability(gs2::lottery::Probability probability);

    EzProbability& operator=(const EzProbability& ezProbability) = default;
    EzProbability& operator=(EzProbability&& ezProbability) = default;

    EzProbability deepCopy() const;

    gs2::lottery::Probability ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const EzDrawnPrize& getPrize() const
    {
        return *ensureData().prize;
    }

    Float getRate() const
    {
        return *ensureData().rate;
    }

    // ========================================
    //   Setters
    // ========================================

    void setPrize(EzDrawnPrize prize)
    {
        ensureData().prize = std::move(prize);
    }

    void setRate(Float rate)
    {
        ensureData().rate = rate;
    }

    EzProbability& withPrize(EzDrawnPrize prize)
    {
        setPrize(std::move(prize));
        return *this;
    }

    EzProbability& withRate(Float rate)
    {
        setRate(rate);
        return *this;
    }
};

}}}

#endif //GS2_EZ_LOTTERY_EZPROBABILITY_HPP_