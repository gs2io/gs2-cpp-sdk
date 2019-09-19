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

#ifndef GS2_EZ_DISTRIBUTOR_EZRUNSTAMPSHEETRESULT_HPP_
#define GS2_EZ_DISTRIBUTOR_EZRUNSTAMPSHEETRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/distributor/result/RunStampSheetResult.hpp>


namespace gs2 { namespace ez { namespace distributor {

class EzRunStampSheetResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** レスポンス内容 */
        StringHolder result;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            result(data.result)
        {
        }

        Data(Data&& data) = default;

        Data(const gs2::distributor::RunStampSheetResult& runStampSheetResult) :
            result(*runStampSheetResult.getResult())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzRunStampSheetResult() = default;
    EzRunStampSheetResult(const EzRunStampSheetResult& result) = default;
    EzRunStampSheetResult(EzRunStampSheetResult&& result) = default;
    ~EzRunStampSheetResult() = default;

    EzRunStampSheetResult(gs2::distributor::RunStampSheetResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzRunStampSheetResult& operator=(const EzRunStampSheetResult& result) = default;
    EzRunStampSheetResult& operator=(EzRunStampSheetResult&& result) = default;

    EzRunStampSheetResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzRunStampSheetResult);
    }

    static bool isConvertible(const gs2::distributor::RunStampSheetResult& result)
    {
        return
            result.getResult().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getResult() const
    {
        return ensureData().result;
    }
};

typedef gs2::AsyncResult<EzRunStampSheetResult> AsyncEzRunStampSheetResult;

}}}

#endif //GS2_EZ_DISTRIBUTOR_EZRUNSTAMPSHEETRESULT_HPP_