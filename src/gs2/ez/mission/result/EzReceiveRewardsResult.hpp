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

#ifndef GS2_EZ_MISSION_EZRECEIVEREWARDSRESULT_HPP_
#define GS2_EZ_MISSION_EZRECEIVEREWARDSRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/mission/result/CompleteResult.hpp>


namespace gs2 { namespace ez { namespace mission {

class EzReceiveRewardsResult : public gs2::Gs2Object
{
private:
    /** ミッションの達成報酬を受領するスタンプシート */
    StringHolder m_StampSheet;

public:
    EzReceiveRewardsResult(const gs2::mission::CompleteResult& result) :
        m_StampSheet(*result.getStampSheet())
    {
    }

    static bool isConvertible(const gs2::mission::CompleteResult& result)
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

typedef gs2::AsyncResult<EzReceiveRewardsResult> AsyncEzReceiveRewardsResult;

}}}

#endif //GS2_EZ_MISSION_EZRECEIVEREWARDSRESULT_HPP_