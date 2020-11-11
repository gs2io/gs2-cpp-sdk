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

#ifndef GS2_EZ_ENHANCE_EZENHANCERESULT_HPP_
#define GS2_EZ_ENHANCE_EZENHANCERESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/enhance/result/DirectEnhanceResult.hpp>


namespace gs2 { namespace ez { namespace enhance {

class EzEnhanceResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 強化レートモデル */
        EzRateModel item;
        /** 強化処理の実行に使用するスタンプシート */
        StringHolder stampSheet;
        /** スタンプシートの署名計算に使用した暗号鍵GRN */
        StringHolder stampSheetEncryptionKeyId;
        /** 獲得経験値量 */
        Int64 acquireExperience;
        /** 経験値ボーナスの倍率(1.0=ボーナスなし) */
        Float bonusRate;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            stampSheet(data.stampSheet),
            stampSheetEncryptionKeyId(data.stampSheetEncryptionKeyId),
            acquireExperience(data.acquireExperience),
            bonusRate(data.bonusRate)
        {
            item = data.item.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::enhance::DirectEnhanceResult& directEnhanceResult) :
            item(*directEnhanceResult.getItem()),
            stampSheet(*directEnhanceResult.getStampSheet()),
            stampSheetEncryptionKeyId(*directEnhanceResult.getStampSheetEncryptionKeyId()),
            acquireExperience(*directEnhanceResult.getAcquireExperience()),
            bonusRate(*directEnhanceResult.getBonusRate())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzEnhanceResult() = default;
    EzEnhanceResult(const EzEnhanceResult& result) = default;
    EzEnhanceResult(EzEnhanceResult&& result) = default;
    ~EzEnhanceResult() = default;

    EzEnhanceResult(gs2::enhance::DirectEnhanceResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzEnhanceResult& operator=(const EzEnhanceResult& result) = default;
    EzEnhanceResult& operator=(EzEnhanceResult&& result) = default;

    EzEnhanceResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzEnhanceResult);
    }

    static bool isConvertible(const gs2::enhance::DirectEnhanceResult& result)
    {
        return
            result.getItem().has_value() &&
            result.getStampSheet().has_value() &&
            result.getStampSheetEncryptionKeyId().has_value() &&
            result.getAcquireExperience().has_value() &&
            result.getBonusRate().has_value();
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

    Int64 getAcquireExperience() const
    {
        return ensureData().acquireExperience;
    }

    Float getBonusRate() const
    {
        return ensureData().bonusRate;
    }
};

typedef gs2::AsyncResult<EzEnhanceResult> AsyncEzEnhanceResult;

}}}

#endif //GS2_EZ_ENHANCE_EZENHANCERESULT_HPP_