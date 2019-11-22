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
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/money/model/model.hpp>
#include <memory>

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

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        ~Data() GS2_OVERRIDE = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        void set(const Char name_[], const detail::json::JsonConstValue& jsonValue) GS2_OVERRIDE;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    WithdrawByUserIdResult() = default;
    WithdrawByUserIdResult(const WithdrawByUserIdResult& withdrawByUserIdResult) = default;
    WithdrawByUserIdResult(WithdrawByUserIdResult&& withdrawByUserIdResult) = default;
    ~WithdrawByUserIdResult() = default;

    WithdrawByUserIdResult& operator=(const WithdrawByUserIdResult& withdrawByUserIdResult) = default;
    WithdrawByUserIdResult& operator=(WithdrawByUserIdResult&& withdrawByUserIdResult) = default;

    WithdrawByUserIdResult deepCopy() const;

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

typedef AsyncResult<WithdrawByUserIdResult> AsyncWithdrawByUserIdResult;

} }

#endif //GS2_MONEY_CONTROL_WITHDRAWBYUSERIDRESULT_HPP_