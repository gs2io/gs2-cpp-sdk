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

#ifndef GS2_EZ_DISTRIBUTOR_EZRUNSTAMPTASKWITHOUTNAMESPACERESULT_HPP_
#define GS2_EZ_DISTRIBUTOR_EZRUNSTAMPTASKWITHOUTNAMESPACERESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/distributor/result/RunStampTaskWithoutNamespaceResult.hpp>


namespace gs2 { namespace ez { namespace distributor {

class EzRunStampTaskWithoutNamespaceResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** タスクの実行結果を反映したコンテキストスタック */
        StringHolder contextStack;
        /** レスポンス内容 */
        StringHolder result;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            contextStack(data.contextStack),
            result(data.result)
        {
        }

        Data(Data&& data) = default;

        Data(const gs2::distributor::RunStampTaskWithoutNamespaceResult& runStampTaskWithoutNamespaceResult) :
            contextStack(runStampTaskWithoutNamespaceResult.getContextStack() ? *runStampTaskWithoutNamespaceResult.getContextStack() : StringHolder()),
            result(runStampTaskWithoutNamespaceResult.getResult() ? *runStampTaskWithoutNamespaceResult.getResult() : StringHolder())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzRunStampTaskWithoutNamespaceResult() = default;
    EzRunStampTaskWithoutNamespaceResult(const EzRunStampTaskWithoutNamespaceResult& result) = default;
    EzRunStampTaskWithoutNamespaceResult(EzRunStampTaskWithoutNamespaceResult&& result) = default;
    ~EzRunStampTaskWithoutNamespaceResult() = default;

    EzRunStampTaskWithoutNamespaceResult(gs2::distributor::RunStampTaskWithoutNamespaceResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzRunStampTaskWithoutNamespaceResult& operator=(const EzRunStampTaskWithoutNamespaceResult& result) = default;
    EzRunStampTaskWithoutNamespaceResult& operator=(EzRunStampTaskWithoutNamespaceResult&& result) = default;

    EzRunStampTaskWithoutNamespaceResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzRunStampTaskWithoutNamespaceResult);
    }

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getContextStack() const
    {
        return ensureData().contextStack;
    }

    const StringHolder& getResult() const
    {
        return ensureData().result;
    }
};

typedef gs2::AsyncResult<EzRunStampTaskWithoutNamespaceResult> AsyncEzRunStampTaskWithoutNamespaceResult;

}}}

#endif //GS2_EZ_DISTRIBUTOR_EZRUNSTAMPTASKWITHOUTNAMESPACERESULT_HPP_