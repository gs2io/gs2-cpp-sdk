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

#ifndef GS2_EZ_SHOWCASE_EZBUYRESULT_HPP_
#define GS2_EZ_SHOWCASE_EZBUYRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/showcase/result/BuyResult.hpp>


namespace gs2 { namespace ez { namespace showcase {

class EzBuyResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 商品 */
        EzSalesItem item;
        /** 購入処理の実行に使用するスタンプシート */
        StringHolder stampSheet;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            stampSheet(data.stampSheet)
        {
            item = data.item.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::showcase::BuyResult& buyResult) :
            item(*buyResult.getItem()),
            stampSheet(*buyResult.getStampSheet())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzBuyResult() = default;
    EzBuyResult(const EzBuyResult& result) = default;
    EzBuyResult(EzBuyResult&& result) = default;
    ~EzBuyResult() = default;

    EzBuyResult(gs2::showcase::BuyResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzBuyResult& operator=(const EzBuyResult& result) = default;
    EzBuyResult& operator=(EzBuyResult&& result) = default;

    EzBuyResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzBuyResult);
    }

    static bool isConvertible(const gs2::showcase::BuyResult& result)
    {
        return
            result.getItem().has_value() &&
            result.getStampSheet().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const EzSalesItem& getItem() const
    {
        return ensureData().item;
    }

    const StringHolder& getStampSheet() const
    {
        return ensureData().stampSheet;
    }
};

typedef gs2::AsyncResult<EzBuyResult> AsyncEzBuyResult;

}}}

#endif //GS2_EZ_SHOWCASE_EZBUYRESULT_HPP_