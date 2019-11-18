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

#ifndef GS2_MONEY_CONTROL_WITHDRAWRESULT_HPP_
#define GS2_MONEY_CONTROL_WITHDRAWRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/money/model/model.hpp>
#include <memory>

namespace gs2 { namespace money
{

/**
 * ウォレットから残高を消費します のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class WithdrawResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 消費後のウォレット */
        optional<Wallet> item;
        /** 消費した通貨の価格 */
        optional<Float> price;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            price(data.price)
        {
            if (data.item)
            {
                item = data.item->deepCopy();
            }
        }

        Data(Data&& data) = default;

        virtual ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "item") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->item.emplace();
                    detail::json::JsonParser::parse(&this->item->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "price") == 0)
            {
                if (jsonValue.IsFloat())
                {
                    this->price = jsonValue.GetFloat();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    WithdrawResult() = default;
    WithdrawResult(const WithdrawResult& withdrawResult) = default;
    WithdrawResult(WithdrawResult&& withdrawResult) = default;
    ~WithdrawResult() = default;

    WithdrawResult& operator=(const WithdrawResult& withdrawResult) = default;
    WithdrawResult& operator=(WithdrawResult&& withdrawResult) = default;

    WithdrawResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(WithdrawResult);
    }

    const WithdrawResult* operator->() const
    {
        return this;
    }

    WithdrawResult* operator->()
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
    void setItem(Wallet item)
    {
        ensureData().item.emplace(std::move(item));
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

typedef AsyncResult<WithdrawResult> AsyncWithdrawResult;

} }

#endif //GS2_MONEY_CONTROL_WITHDRAWRESULT_HPP_