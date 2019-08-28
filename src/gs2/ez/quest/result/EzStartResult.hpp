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

#ifndef GS2_EZ_QUEST_EZSTARTRESULT_HPP_
#define GS2_EZ_QUEST_EZSTARTRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/quest/result/StartResult.hpp>


namespace gs2 { namespace ez { namespace quest {

class EzStartResult : public gs2::Gs2Object
{
private:
    /** クエストの開始処理の実行に使用するスタンプシート */
    StringHolder m_StampSheet;

public:
    EzStartResult(const gs2::quest::StartResult& result) :
        m_StampSheet(*result.getStampSheet())
    {
    }

    static bool isConvertible(const gs2::quest::StartResult& result)
    {
        return
            result.getStampSheet().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const gs2::StringHolder& getStampSheet() const
    {
        return m_StampSheet;
    }

    gs2::StringHolder& getStampSheet()
    {
        return m_StampSheet;
    }
};

typedef gs2::AsyncResult<EzStartResult> AsyncEzStartResult;

}}}

#endif //GS2_EZ_QUEST_EZSTARTRESULT_HPP_