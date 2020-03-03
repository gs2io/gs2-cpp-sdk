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

#ifndef GS2_MONEY_MODEL_WALLETDETAIL_HPP_
#define GS2_MONEY_MODEL_WALLETDETAIL_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace money {

/**
 * ウォレットの詳細
 *
 * @author Game Server Services, Inc.
 *
 */
class WalletDetail : public Gs2Object
{
    friend bool operator!=(const WalletDetail& lhs, const WalletDetail& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 単価 */
        optional<Float> price;
        /** 所持量 */
        optional<Int32> count;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            price(data.price),
            count(data.count)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "price") == 0)
            {
                if (jsonValue.IsFloat())
                {
                    this->price = jsonValue.GetFloat();
                }
            }
            else if (std::strcmp(name_, "count") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->count = jsonValue.GetInt();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    WalletDetail() = default;
    WalletDetail(const WalletDetail& walletDetail) = default;
    WalletDetail(WalletDetail&& walletDetail) = default;
    ~WalletDetail() = default;

    WalletDetail& operator=(const WalletDetail& walletDetail) = default;
    WalletDetail& operator=(WalletDetail&& walletDetail) = default;

    WalletDetail deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(WalletDetail);
    }

    const WalletDetail* operator->() const
    {
        return this;
    }

    WalletDetail* operator->()
    {
        return this;
    }
    /**
     * 単価を取得
     *
     * @return 単価
     */
    const optional<Float>& getPrice() const
    {
        return ensureData().price;
    }

    /**
     * 単価を設定
     *
     * @param price 単価
     */
    void setPrice(Float price)
    {
        ensureData().price.emplace(price);
    }

    /**
     * 単価を設定
     *
     * @param price 単価
     */
    WalletDetail& withPrice(Float price)
    {
        setPrice(price);
        return *this;
    }

    /**
     * 所持量を取得
     *
     * @return 所持量
     */
    const optional<Int32>& getCount() const
    {
        return ensureData().count;
    }

    /**
     * 所持量を設定
     *
     * @param count 所持量
     */
    void setCount(Int32 count)
    {
        ensureData().count.emplace(count);
    }

    /**
     * 所持量を設定
     *
     * @param count 所持量
     */
    WalletDetail& withCount(Int32 count)
    {
        setCount(count);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const WalletDetail& lhs, const WalletDetail& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->price != lhr.m_pData->price)
        {
            return true;
        }
        if (lhs.m_pData->count != lhr.m_pData->count)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const WalletDetail& lhs, const WalletDetail& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_MONEY_MODEL_WALLETDETAIL_HPP_