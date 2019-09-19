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

#ifndef GS2_LOTTERY_MODEL_PROBABILITY_HPP_
#define GS2_LOTTERY_MODEL_PROBABILITY_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "DrawnPrize.hpp"
#include <memory>
#include <cstring>

namespace gs2 { namespace lottery {

/**
 * 排出レート
 *
 * @author Game Server Services, Inc.
 *
 */
class Probability : public Gs2Object
{
    friend bool operator!=(const Probability& lhs, const Probability& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 景品の種類 */
        optional<DrawnPrize> prize;
        /** 排出確率(0.0〜1.0) */
        optional<Float> rate;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            rate(data.rate)
        {
            if (data.prize)
            {
                prize = data.prize->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "prize") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->prize.emplace();
                    detail::json::JsonParser::parse(&this->prize->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "rate") == 0)
            {
                if (jsonValue.IsFloat())
                {
                    this->rate = jsonValue.GetFloat();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Probability() = default;
    Probability(const Probability& probability) = default;
    Probability(Probability&& probability) = default;
    ~Probability() = default;

    Probability& operator=(const Probability& probability) = default;
    Probability& operator=(Probability&& probability) = default;

    Probability deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Probability);
    }

    const Probability* operator->() const
    {
        return this;
    }

    Probability* operator->()
    {
        return this;
    }
    /**
     * 景品の種類を取得
     *
     * @return 景品の種類
     */
    const optional<DrawnPrize>& getPrize() const
    {
        return ensureData().prize;
    }

    /**
     * 景品の種類を設定
     *
     * @param prize 景品の種類
     */
    void setPrize(DrawnPrize prize)
    {
        ensureData().prize.emplace(std::move(prize));
    }

    /**
     * 景品の種類を設定
     *
     * @param prize 景品の種類
     */
    Probability& withPrize(DrawnPrize prize)
    {
        setPrize(std::move(prize));
        return *this;
    }

    /**
     * 排出確率(0.0〜1.0)を取得
     *
     * @return 排出確率(0.0〜1.0)
     */
    const optional<Float>& getRate() const
    {
        return ensureData().rate;
    }

    /**
     * 排出確率(0.0〜1.0)を設定
     *
     * @param rate 排出確率(0.0〜1.0)
     */
    void setRate(Float rate)
    {
        ensureData().rate.emplace(rate);
    }

    /**
     * 排出確率(0.0〜1.0)を設定
     *
     * @param rate 排出確率(0.0〜1.0)
     */
    Probability& withRate(Float rate)
    {
        setRate(rate);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Probability& lhs, const Probability& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->prize != lhr.m_pData->prize)
        {
            return true;
        }
        if (lhs.m_pData->rate != lhr.m_pData->rate)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const Probability& lhs, const Probability& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_LOTTERY_MODEL_PROBABILITY_HPP_