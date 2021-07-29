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

#ifndef GS2_EZ_EXCHANGE_EZEXCHANGERESULT_HPP_
#define GS2_EZ_EXCHANGE_EZEXCHANGERESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/exchange/result/ExchangeResult.hpp>


namespace gs2 { namespace ez { namespace exchange {

class EzExchangeResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 交換レートモデル */
        EzRateModel item;
        /** 交換処理の実行に使用するスタンプシート */
        StringHolder stampSheet;
        /** スタンプシートの署名計算に使用した暗号鍵GRN */
        StringHolder stampSheetEncryptionKeyId;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            stampSheet(data.stampSheet),
            stampSheetEncryptionKeyId(data.stampSheetEncryptionKeyId)
        {
            item = data.item.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::exchange::ExchangeResult& exchangeResult) :
            item(exchangeResult.getItem()),
            stampSheet(exchangeResult.getStampSheet() ? *exchangeResult.getStampSheet() : StringHolder()),
            stampSheetEncryptionKeyId(exchangeResult.getStampSheetEncryptionKeyId() ? *exchangeResult.getStampSheetEncryptionKeyId() : StringHolder())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzExchangeResult() = default;
    EzExchangeResult(const EzExchangeResult& result) = default;
    EzExchangeResult(EzExchangeResult&& result) = default;
    ~EzExchangeResult() = default;

    EzExchangeResult(gs2::exchange::ExchangeResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzExchangeResult& operator=(const EzExchangeResult& result) = default;
    EzExchangeResult& operator=(EzExchangeResult&& result) = default;

    EzExchangeResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzExchangeResult);
    }

    // ========================================
    //   Getters
    // ========================================

    const EzRateModel& getItem() const
    {
        return ensureData().item;
    }

    const StringHolder& getStampSheet() const
    {
        return ensureData().stampSheet;
    }

    const StringHolder& getStampSheetEncryptionKeyId() const
    {
        return ensureData().stampSheetEncryptionKeyId;
    }
};

typedef gs2::AsyncResult<EzExchangeResult> AsyncEzExchangeResult;

}}}

#endif //GS2_EZ_EXCHANGE_EZEXCHANGERESULT_HPP_