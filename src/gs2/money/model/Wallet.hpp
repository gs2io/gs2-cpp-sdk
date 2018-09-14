/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
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

#ifndef GS2_MONEY_MODEL_WALLET_HPP_
#define GS2_MONEY_MODEL_WALLET_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace money {

/**
 * ウォレットの詳細
 *
 * @author Game Server Services, Inc.
 *
 */
class Wallet : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 単価 */
        optional<Double> price;
        /** 所持数 */
        optional<Int32> count;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            price(data.price),
            count(data.count)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            price(std::move(data.price)),
            count(std::move(data.count))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "price") == 0) {
                if (jsonValue.IsDouble())
                {
                    this->price = jsonValue.GetDouble();
                }
            }
            else if (std::strcmp(name, "count") == 0) {
                if (jsonValue.IsInt())
                {
                    this->count = jsonValue.GetInt();
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
    Wallet() :
        m_pData(nullptr)
    {}

    Wallet(const Wallet& wallet) :
        Gs2Object(wallet),
        m_pData(wallet.m_pData != nullptr ? new Data(*wallet.m_pData) : nullptr)
    {}

    Wallet(Wallet&& wallet) :
        Gs2Object(std::move(wallet)),
        m_pData(wallet.m_pData)
    {
        wallet.m_pData = nullptr;
    }

    ~Wallet()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Wallet& operator=(const Wallet& wallet)
    {
        Gs2Object::operator=(wallet);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*wallet.m_pData);

        return *this;
    }

    Wallet& operator=(Wallet&& wallet)
    {
        Gs2Object::operator=(std::move(wallet));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = wallet.m_pData;
        wallet.m_pData = nullptr;

        return *this;
    }

    const Wallet* operator->() const
    {
        return this;
    }

    Wallet* operator->()
    {
        return this;
    }


    /**
     * 単価を取得
     *
     * @return 単価
     */
    const optional<Double>& getPrice() const
    {
        return ensureData().price;
    }

    /**
     * 単価を設定
     *
     * @param price 単価
     */
    void setPrice(Double price)
    {
        ensureData().price.emplace(price);
    }

    /**
     * 所持数を取得
     *
     * @return 所持数
     */
    const optional<Int32>& getCount() const
    {
        return ensureData().count;
    }

    /**
     * 所持数を設定
     *
     * @param count 所持数
     */
    void setCount(Int32 count)
    {
        ensureData().count.emplace(count);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_MONEY_MODEL_WALLET_HPP_