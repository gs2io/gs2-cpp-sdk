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

#ifndef GS2_EZ_DISTRIBUTOR_EZRUNSTAMPSHEETEXPRESSWITHOUTNAMESPACERESULT_HPP_
#define GS2_EZ_DISTRIBUTOR_EZRUNSTAMPSHEETEXPRESSWITHOUTNAMESPACERESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/distributor/result/RunStampSheetExpressWithoutNamespaceResult.hpp>


namespace gs2 { namespace ez { namespace distributor {

class EzRunStampSheetExpressWithoutNamespaceResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** スタンプタスクの実行結果 */
        List<StringHolder> taskResults;
        /** スタンプシートの実行結果レスポンス内容 */
        StringHolder sheetResult;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            sheetResult(data.sheetResult)
        {
            taskResults = data.taskResults.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::distributor::RunStampSheetExpressWithoutNamespaceResult& runStampSheetExpressWithoutNamespaceResult) :
            taskResults(*runStampSheetExpressWithoutNamespaceResult.getTaskResults()),
            sheetResult(*runStampSheetExpressWithoutNamespaceResult.getSheetResult())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzRunStampSheetExpressWithoutNamespaceResult() = default;
    EzRunStampSheetExpressWithoutNamespaceResult(const EzRunStampSheetExpressWithoutNamespaceResult& result) = default;
    EzRunStampSheetExpressWithoutNamespaceResult(EzRunStampSheetExpressWithoutNamespaceResult&& result) = default;
    ~EzRunStampSheetExpressWithoutNamespaceResult() = default;

    EzRunStampSheetExpressWithoutNamespaceResult(gs2::distributor::RunStampSheetExpressWithoutNamespaceResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzRunStampSheetExpressWithoutNamespaceResult& operator=(const EzRunStampSheetExpressWithoutNamespaceResult& result) = default;
    EzRunStampSheetExpressWithoutNamespaceResult& operator=(EzRunStampSheetExpressWithoutNamespaceResult&& result) = default;

    EzRunStampSheetExpressWithoutNamespaceResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzRunStampSheetExpressWithoutNamespaceResult);
    }

    static bool isConvertible(const gs2::distributor::RunStampSheetExpressWithoutNamespaceResult& result)
    {
        return
            result.getTaskResults().has_value() &&
            result.getSheetResult().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const List<StringHolder>& getTaskResults() const
    {
        return ensureData().taskResults;
    }

    const StringHolder& getSheetResult() const
    {
        return ensureData().sheetResult;
    }
};

typedef gs2::AsyncResult<EzRunStampSheetExpressWithoutNamespaceResult> AsyncEzRunStampSheetExpressWithoutNamespaceResult;

}}}

#endif //GS2_EZ_DISTRIBUTOR_EZRUNSTAMPSHEETEXPRESSWITHOUTNAMESPACERESULT_HPP_