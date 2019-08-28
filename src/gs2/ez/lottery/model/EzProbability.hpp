

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

#include <gs2/lottery/model/Probability.hpp>
#include "EzDrawnPrize.hpp"


namespace gs2 { namespace ez { namespace lottery {

class EzProbability : public gs2::Gs2Object
{
private:
    /** 景品の種類 */
    gs2::optional<EzDrawnPrize> m_Prize;
    /** 排出確率(0.0〜1.0) */
    gs2::optional<Float> m_Rate;

public:
    EzProbability() = default;

    EzProbability(gs2::lottery::Probability probability) :
        m_Prize(*probability.getPrize()),
        m_Rate(probability.getRate() ? *probability.getRate() : 0)
    {
    }

    gs2::lottery::Probability ToModel() const
    {
        gs2::lottery::Probability probability;
        probability.setPrize(m_Prize->ToModel());
        probability.setRate(*m_Rate);
        return probability;
    }

    // ========================================
    //   Getters
    // ========================================

    const EzDrawnPrize& getPrize() const
    {
        return *m_Prize;
    }

    EzDrawnPrize& getPrize()
    {
        return *m_Prize;
    }

    Float getRate() const
    {
        return *m_Rate;
    }

    // ========================================
    //   Setters
    // ========================================

    void setPrize(const EzDrawnPrize& prize)
    {
        m_Prize = prize;
    }

    void setPrize(EzDrawnPrize&& prize)
    {
        m_Prize = std::move(prize);
    }

    void setRate(Float rate)
    {
        m_Rate = rate;
    }

    EzProbability& withPrize(const EzDrawnPrize& prize)
    {
        setPrize(prize);
        return *this;
    }

    EzProbability& withPrize(EzDrawnPrize&& prize)
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