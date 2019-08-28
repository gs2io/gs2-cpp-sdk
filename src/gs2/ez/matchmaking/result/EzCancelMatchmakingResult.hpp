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

#ifndef GS2_EZ_MATCHMAKING_EZCANCELMATCHMAKINGRESULT_HPP_
#define GS2_EZ_MATCHMAKING_EZCANCELMATCHMAKINGRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/matchmaking/result/CancelMatchmakingResult.hpp>


namespace gs2 { namespace ez { namespace matchmaking {

class EzCancelMatchmakingResult : public gs2::Gs2Object
{
private:
    /** ギャザリング */
    EzGathering m_Item;

public:
    EzCancelMatchmakingResult(const gs2::matchmaking::CancelMatchmakingResult& result) :
        m_Item(*result.getItem())
    {
    }

    static bool isConvertible(const gs2::matchmaking::CancelMatchmakingResult& result)
    {
        return
            result.getItem().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const EzGathering& getItem() const
    {
        return m_Item;
    }

    EzGathering& getItem()
    {
        return m_Item;
    }
};

typedef gs2::AsyncResult<EzCancelMatchmakingResult> AsyncEzCancelMatchmakingResult;

}}}

#endif //GS2_EZ_MATCHMAKING_EZCANCELMATCHMAKINGRESULT_HPP_