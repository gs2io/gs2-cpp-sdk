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

#ifndef GS2_EZ_ENHANCE_EZSTARTRESULT_HPP_
#define GS2_EZ_ENHANCE_EZSTARTRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/enhance/result/StartResult.hpp>


namespace gs2 { namespace ez { namespace enhance {

class EzStartResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 強化の開始処理の実行に使用するスタンプシート */
        StringHolder stampSheet;
        /** スタンプシートの署名計算に使用した暗号鍵GRN */
        StringHolder stampSheetEncryptionKeyId;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            stampSheet(data.stampSheet),
            stampSheetEncryptionKeyId(data.stampSheetEncryptionKeyId)
        {
        }

        Data(Data&& data) = default;

        Data(const gs2::enhance::StartResult& startResult) :
            stampSheet(*startResult.getStampSheet()),
            stampSheetEncryptionKeyId(*startResult.getStampSheetEncryptionKeyId())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzStartResult() = default;
    EzStartResult(const EzStartResult& result) = default;
    EzStartResult(EzStartResult&& result) = default;
    ~EzStartResult() = default;

    EzStartResult(gs2::enhance::StartResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzStartResult& operator=(const EzStartResult& result) = default;
    EzStartResult& operator=(EzStartResult&& result) = default;

    EzStartResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzStartResult);
    }

    static bool isConvertible(const gs2::enhance::StartResult& result)
    {
        return
            result.getStampSheet().has_value() &&
            result.getStampSheetEncryptionKeyId().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getStampSheet() const
    {
        return ensureData().stampSheet;
    }

    const StringHolder& getStampSheetEncryptionKeyId() const
    {
        return ensureData().stampSheetEncryptionKeyId;
    }
};

typedef gs2::AsyncResult<EzStartResult> AsyncEzStartResult;

}}}

#endif //GS2_EZ_ENHANCE_EZSTARTRESULT_HPP_