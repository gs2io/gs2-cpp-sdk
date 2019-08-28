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

#ifndef GS2_EZ_MISSION_EZGETCOMPLETERESULT_HPP_
#define GS2_EZ_MISSION_EZGETCOMPLETERESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/mission/result/GetCompleteResult.hpp>


namespace gs2 { namespace ez { namespace mission {

class EzGetCompleteResult : public gs2::Gs2Object
{
private:
    /** 達成状況 */
    EzComplete m_Item;

public:
    EzGetCompleteResult(const gs2::mission::GetCompleteResult& result) :
        m_Item(*result.getItem())
    {
    }

    static bool isConvertible(const gs2::mission::GetCompleteResult& result)
    {
        return
            result.getItem().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const EzComplete& getItem() const
    {
        return m_Item;
    }

    EzComplete& getItem()
    {
        return m_Item;
    }
};

typedef gs2::AsyncResult<EzGetCompleteResult> AsyncEzGetCompleteResult;

}}}

#endif //GS2_EZ_MISSION_EZGETCOMPLETERESULT_HPP_