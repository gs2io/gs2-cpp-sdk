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

#ifndef GS2_EZ_DISTRIBUTOR_EZRUNSTAMPTASKRESULT_HPP_
#define GS2_EZ_DISTRIBUTOR_EZRUNSTAMPTASKRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/distributor/result/RunStampTaskResult.hpp>


namespace gs2 { namespace ez { namespace distributor {

class EzRunStampTaskResult : public gs2::Gs2Object
{
private:
    /** タスクの実行結果を反映したコンテキストスタック */
    StringHolder m_ContextStack;
    /** レスポンス内容 */
    StringHolder m_Result;

public:
    EzRunStampTaskResult(const gs2::distributor::RunStampTaskResult& result) :
        m_ContextStack(*result.getContextStack()),
        m_Result(*result.getResult())
    {
    }

    static bool isConvertible(const gs2::distributor::RunStampTaskResult& result)
    {
        return
            result.getContextStack().has_value() &&
            result.getResult().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const gs2::StringHolder& getContextStack() const
    {
        return m_ContextStack;
    }

    gs2::StringHolder& getContextStack()
    {
        return m_ContextStack;
    }

    const gs2::StringHolder& getResult() const
    {
        return m_Result;
    }

    gs2::StringHolder& getResult()
    {
        return m_Result;
    }
};

typedef gs2::AsyncResult<EzRunStampTaskResult> AsyncEzRunStampTaskResult;

}}}

#endif //GS2_EZ_DISTRIBUTOR_EZRUNSTAMPTASKRESULT_HPP_