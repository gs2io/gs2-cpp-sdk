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

#ifndef GS2_EZ_EXCHANGE_EZSKIPRESULT_HPP_
#define GS2_EZ_EXCHANGE_EZSKIPRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/exchange/result/SkipResult.hpp>


namespace gs2 { namespace ez { namespace exchange {

class EzSkipResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 交換待機 */
        EzAwait item;
        /** 報酬取得処理の実行に使用するスタンプシート */
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

        Data(const gs2::exchange::SkipResult& skipResult) :
            item(*skipResult.getItem()),
            stampSheet(*skipResult.getStampSheet()),
            stampSheetEncryptionKeyId(*skipResult.getStampSheetEncryptionKeyId())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzSkipResult() = default;
    EzSkipResult(const EzSkipResult& result) = default;
    EzSkipResult(EzSkipResult&& result) = default;
    ~EzSkipResult() = default;

    EzSkipResult(gs2::exchange::SkipResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzSkipResult& operator=(const EzSkipResult& result) = default;
    EzSkipResult& operator=(EzSkipResult&& result) = default;

    EzSkipResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzSkipResult);
    }

    static bool isConvertible(const gs2::exchange::SkipResult& result)
    {
        return
            result.getItem().has_value() &&
            result.getStampSheet().has_value() &&
            result.getStampSheetEncryptionKeyId().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const EzAwait& getItem() const
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

typedef gs2::AsyncResult<EzSkipResult> AsyncEzSkipResult;

}}}

#endif //GS2_EZ_EXCHANGE_EZSKIPRESULT_HPP_