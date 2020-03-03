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

#ifndef GS2_EZ_MONEY_EZWITHDRAWRESULT_HPP_
#define GS2_EZ_MONEY_EZWITHDRAWRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/money/result/WithdrawResult.hpp>


namespace gs2 { namespace ez { namespace money {

class EzWithdrawResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 消費後のウォレット */
        EzWallet item;
        /** 消費した通貨の価格 */
        Float price;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            price(data.price)
        {
            item = data.item.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::money::WithdrawResult& withdrawResult) :
            item(*withdrawResult.getItem()),
            price(*withdrawResult.getPrice())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzWithdrawResult() = default;
    EzWithdrawResult(const EzWithdrawResult& result) = default;
    EzWithdrawResult(EzWithdrawResult&& result) = default;
    ~EzWithdrawResult() = default;

    EzWithdrawResult(gs2::money::WithdrawResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzWithdrawResult& operator=(const EzWithdrawResult& result) = default;
    EzWithdrawResult& operator=(EzWithdrawResult&& result) = default;

    EzWithdrawResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzWithdrawResult);
    }

    static bool isConvertible(const gs2::money::WithdrawResult& result)
    {
        return
            result.getItem().has_value() &&
            result.getPrice().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const EzWallet& getItem() const
    {
        return ensureData().item;
    }

    Float getPrice() const
    {
        return ensureData().price;
    }
};

typedef gs2::AsyncResult<EzWithdrawResult> AsyncEzWithdrawResult;

}}}

#endif //GS2_EZ_MONEY_EZWITHDRAWRESULT_HPP_