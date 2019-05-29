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
#include <gs2/core/external/optional/optional.hpp>
#include "DrawnPrize.hpp"
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
        /** 排出された景品 */
        optional<DrawnPrize> prize;
        /** 排出確率(0.0〜1.0) */
        optional<Float> rate;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            prize(data.prize),
            rate(data.rate)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            prize(std::move(data.prize)),
            rate(std::move(data.rate))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "prize") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = jsonValue.GetObject();
                    this->prize.emplace();
                    detail::json::JsonParser::parse(&this->prize->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name, "rate") == 0) {
                if (jsonValue.IsFloat())
                {
                    this->rate = jsonValue.GetFloat();
                }
            }
        }
    };

    Data* m_pData;

    Data& ensureData() {
        if (m_pData == nullptr) {
            m_pData = new Data();
        }
        return *m_pData;
    }

    const Data& ensureData() const {
        if (m_pData == nullptr) {
            *const_cast<Data**>(&m_pData) = new Data();
        }
        return *m_pData;
    }

public:
    Probability() :
        m_pData(nullptr)
    {}

    Probability(const Probability& probability) :
        Gs2Object(probability),
        m_pData(probability.m_pData != nullptr ? new Data(*probability.m_pData) : nullptr)
    {}

    Probability(Probability&& probability) :
        Gs2Object(std::move(probability)),
        m_pData(probability.m_pData)
    {
        probability.m_pData = nullptr;
    }

    ~Probability()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Probability& operator=(const Probability& probability)
    {
        Gs2Object::operator=(probability);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*probability.m_pData);

        return *this;
    }

    Probability& operator=(Probability&& probability)
    {
        Gs2Object::operator=(std::move(probability));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = probability.m_pData;
        probability.m_pData = nullptr;

        return *this;
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
     * 排出された景品を取得
     *
     * @return 排出された景品
     */
    const optional<DrawnPrize>& getPrize() const
    {
        return ensureData().prize;
    }

    /**
     * 排出された景品を設定
     *
     * @param prize 排出された景品
     */
    void setPrize(const DrawnPrize& prize)
    {
        ensureData().prize.emplace(prize);
    }

    /**
     * 排出された景品を設定
     *
     * @param prize 排出された景品
     */
    Probability& withPrize(const DrawnPrize& prize)
    {
        setPrize(prize);
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

bool operator!=(const Probability& lhs, const Probability& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
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

bool operator==(const Probability& lhs, const Probability& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_LOTTERY_MODEL_PROBABILITY_HPP_