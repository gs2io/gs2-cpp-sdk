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

#ifndef GS2_EZ_JOBQUEUE_EZRUNRESULT_HPP_
#define GS2_EZ_JOBQUEUE_EZRUNRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/jobQueue/result/RunResult.hpp>


namespace gs2 { namespace ez { namespace jobQueue {

class EzRunResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** ジョブ */
        optional<EzJob> item;
        /** ジョブの実行結果 */
        optional<EzJobResultBody> result;
        /** None */
        Bool isLastJob;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            isLastJob(data.isLastJob)
        {
            if (data.item)
            {
                item = data.item->deepCopy();
            }
            if (data.result)
            {
                result = data.result->deepCopy();
            }
        }

        Data(Data&& data) = default;

        Data(const gs2::jobQueue::RunResult& runResult) :
            isLastJob(runResult.getIsLastJob() ? *runResult.getIsLastJob() : false)
        {
            if (runResult.getItem())
            {
                item = EzJob(*runResult.getItem());
            }
            if (runResult.getResult())
            {
                result = EzJobResultBody(*runResult.getResult());
            }
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzRunResult() = default;
    EzRunResult(const EzRunResult& result) = default;
    EzRunResult(EzRunResult&& result) = default;
    ~EzRunResult() = default;

    EzRunResult(gs2::jobQueue::RunResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzRunResult& operator=(const EzRunResult& result) = default;
    EzRunResult& operator=(EzRunResult&& result) = default;

    EzRunResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzRunResult);
    }

    // ========================================
    //   Getters
    // ========================================

    const optional<EzJob>& getItem() const
    {
        return ensureData().item;
    }

    const optional<EzJobResultBody>& getResult() const
    {
        return ensureData().result;
    }

    Bool getIsLastJob() const
    {
        return ensureData().isLastJob;
    }
};

typedef gs2::AsyncResult<EzRunResult> AsyncEzRunResult;

}}}

#endif //GS2_EZ_JOBQUEUE_EZRUNRESULT_HPP_