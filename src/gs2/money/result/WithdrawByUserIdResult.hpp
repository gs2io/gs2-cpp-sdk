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

#ifndef GS2_MONEY_CONTROL_WITHDRAWBYUSERIDRESULT_HPP_
#define GS2_MONEY_CONTROL_WITHDRAWBYUSERIDRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace money
{

/**
 * ユーザーIDを指定してウォレットから残高を消費します のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class WithdrawByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 消費後のウォレット */
        optional<Wallet> item;
        /** 消費した通貨の価格 */
        optional<Float> price;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            item(data.item),
            price(data.price)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            item(std::move(data.item)),
            price(std::move(data.price))
        {}

        virtual ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "item") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->item.emplace();
                    detail::json::JsonParser::parse(&this->item->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "price") == 0) {
                if (jsonValue.IsFloat())
                {
                    this->price = jsonValue.GetFloat();
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
    WithdrawByUserIdResult() :
        m_pData(nullptr)
    {}

    WithdrawByUserIdResult(const WithdrawByUserIdResult& withdrawByUserIdResult) :
        Gs2Object(withdrawByUserIdResult),
        m_pData(withdrawByUserIdResult.m_pData != nullptr ? new Data(*withdrawByUserIdResult.m_pData) : nullptr)
    {}

    WithdrawByUserIdResult(WithdrawByUserIdResult&& withdrawByUserIdResult) :
        Gs2Object(std::move(withdrawByUserIdResult)),
        m_pData(withdrawByUserIdResult.m_pData)
    {
        withdrawByUserIdResult.m_pData = nullptr;
    }

    ~WithdrawByUserIdResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    WithdrawByUserIdResult& operator=(const WithdrawByUserIdResult& withdrawByUserIdResult)
    {
        Gs2Object::operator=(withdrawByUserIdResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*withdrawByUserIdResult.m_pData);

        return *this;
    }

    WithdrawByUserIdResult& operator=(WithdrawByUserIdResult&& withdrawByUserIdResult)
    {
        Gs2Object::operator=(std::move(withdrawByUserIdResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = withdrawByUserIdResult.m_pData;
        withdrawByUserIdResult.m_pData = nullptr;

        return *this;
    }

    const WithdrawByUserIdResult* operator->() const
    {
        return this;
    }

    WithdrawByUserIdResult* operator->()
    {
        return this;
    }
    /**
     * 消費後のウォレットを取得
     *
     * @return 消費後のウォレット
     */
    const optional<Wallet>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 消費後のウォレットを設定
     *
     * @param item 消費後のウォレット
     */
    void setItem(const Wallet& item)
    {
        ensureData().item.emplace(item);
    }

    /**
     * 消費した通貨の価格を取得
     *
     * @return 消費した通貨の価格
     */
    const optional<Float>& getPrice() const
    {
        return ensureData().price;
    }

    /**
     * 消費した通貨の価格を設定
     *
     * @param price 消費した通貨の価格
     */
    void setPrice(Float price)
    {
        ensureData().price.emplace(price);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<WithdrawByUserIdResult> AsyncWithdrawByUserIdResult;

} }

#endif //GS2_MONEY_CONTROL_WITHDRAWBYUSERIDRESULT_HPP_