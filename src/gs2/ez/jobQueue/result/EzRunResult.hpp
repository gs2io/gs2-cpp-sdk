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
    /** ジョブ */
    EzJob m_Item;
    /** ジョブの実行結果 */
    EzJobResultBody m_Result;
    /** None */
    Bool m_IsLastJob;

public:
    EzRunResult(const gs2::jobQueue::RunResult& result) :
        m_Item(*result.getItem()),
        m_Result(*result.getResult()),
        m_IsLastJob(*result.getIsLastJob())
    {
    }

    static bool isConvertible(const gs2::jobQueue::RunResult& result)
    {
        return
            result.getItem().has_value() &&
            result.getResult().has_value() &&
            result.getIsLastJob().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const EzJob& getItem() const
    {
        return m_Item;
    }

    EzJob& getItem()
    {
        return m_Item;
    }

    const EzJobResultBody& getResult() const
    {
        return m_Result;
    }

    EzJobResultBody& getResult()
    {
        return m_Result;
    }

    Bool getIsLastJob() const
    {
        return m_IsLastJob;
    }
};

typedef gs2::AsyncResult<EzRunResult> AsyncEzRunResult;

}}}

#endif //GS2_EZ_JOBQUEUE_EZRUNRESULT_HPP_