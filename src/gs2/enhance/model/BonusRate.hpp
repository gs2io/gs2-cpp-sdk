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

#ifndef GS2_ENHANCE_MODEL_BONUSRATE_HPP_
#define GS2_ENHANCE_MODEL_BONUSRATE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace enhance {

/**
 * 消費アクション
 *
 * @author Game Server Services, Inc.
 *
 */
class BonusRate : public Gs2Object
{
    friend bool operator!=(const BonusRate& lhs, const BonusRate& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 経験値ボーナスの倍率(1.0=ボーナスなし) */
        optional<Float> rate;
        /** 抽選重み */
        optional<Int32> weight;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            rate(data.rate),
            weight(data.weight)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "rate") == 0)
            {
                if (jsonValue.IsFloat())
                {
                    this->rate = jsonValue.GetFloat();
                }
            }
            else if (std::strcmp(name_, "weight") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->weight = jsonValue.GetInt();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    BonusRate() = default;
    BonusRate(const BonusRate& bonusRate) = default;
    BonusRate(BonusRate&& bonusRate) = default;
    ~BonusRate() = default;

    BonusRate& operator=(const BonusRate& bonusRate) = default;
    BonusRate& operator=(BonusRate&& bonusRate) = default;

    BonusRate deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(BonusRate);
    }

    const BonusRate* operator->() const
    {
        return this;
    }

    BonusRate* operator->()
    {
        return this;
    }
    /**
     * 経験値ボーナスの倍率(1.0=ボーナスなし)を取得
     *
     * @return 経験値ボーナスの倍率(1.0=ボーナスなし)
     */
    const optional<Float>& getRate() const
    {
        return ensureData().rate;
    }

    /**
     * 経験値ボーナスの倍率(1.0=ボーナスなし)を設定
     *
     * @param rate 経験値ボーナスの倍率(1.0=ボーナスなし)
     */
    void setRate(Float rate)
    {
        ensureData().rate.emplace(rate);
    }

    /**
     * 経験値ボーナスの倍率(1.0=ボーナスなし)を設定
     *
     * @param rate 経験値ボーナスの倍率(1.0=ボーナスなし)
     */
    BonusRate& withRate(Float rate)
    {
        setRate(rate);
        return *this;
    }

    /**
     * 抽選重みを取得
     *
     * @return 抽選重み
     */
    const optional<Int32>& getWeight() const
    {
        return ensureData().weight;
    }

    /**
     * 抽選重みを設定
     *
     * @param weight 抽選重み
     */
    void setWeight(Int32 weight)
    {
        ensureData().weight.emplace(weight);
    }

    /**
     * 抽選重みを設定
     *
     * @param weight 抽選重み
     */
    BonusRate& withWeight(Int32 weight)
    {
        setWeight(weight);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const BonusRate& lhs, const BonusRate& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->rate != lhr.m_pData->rate)
        {
            return true;
        }
        if (lhs.m_pData->weight != lhr.m_pData->weight)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const BonusRate& lhs, const BonusRate& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_ENHANCE_MODEL_BONUSRATE_HPP_