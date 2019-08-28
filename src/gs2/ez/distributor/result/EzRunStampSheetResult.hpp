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
    /** レスポンス内容 */
    StringHolder m_Result;

public:
    EzRunStampSheetResult(const gs2::distributor::RunStampSheetResult& result) :
        m_Result(*result.getResult())
    {
    }

    static bool isConvertible(const gs2::distributor::RunStampSheetResult& result)
    {
        return
            result.getResult().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const gs2::StringHolder& getResult() const
    {
        return m_Result;
    }

    gs2::StringHolder& getResult()
    {
        return m_Result;
    }
};

typedef gs2::AsyncResult<EzRunStampSheetResult> AsyncEzRunStampSheetResult;

}}}

#endif //GS2_EZ_DISTRIBUTOR_EZRUNSTAMPSHEETRESULT_HPP_