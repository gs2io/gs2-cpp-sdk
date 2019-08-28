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
    /** 消費後のウォレット */
    EzWalletDetail m_Item;
    /** 消費した通貨の価格 */
    Float m_Price;

public:
    EzWithdrawResult(const gs2::money::WithdrawResult& result) :
        m_Item(*result.getItem()),
        m_Price(*result.getPrice())
    {
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

    const EzWalletDetail& getItem() const
    {
        return m_Item;
    }

    EzWalletDetail& getItem()
    {
        return m_Item;
    }

    Float getPrice() const
    {
        return m_Price;
    }
};

typedef gs2::AsyncResult<EzWithdrawResult> AsyncEzWithdrawResult;

}}}

#endif //GS2_EZ_MONEY_EZWITHDRAWRESULT_HPP_