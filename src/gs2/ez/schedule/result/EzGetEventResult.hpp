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

#ifndef GS2_EZ_SCHEDULE_EZGETEVENTRESULT_HPP_
#define GS2_EZ_SCHEDULE_EZGETEVENTRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/schedule/result/GetEventResult.hpp>


namespace gs2 { namespace ez { namespace schedule {

class EzGetEventResult : public gs2::Gs2Object
{
private:
    /** イベント */
    EzEvent m_Item;

public:
    EzGetEventResult(const gs2::schedule::GetEventResult& result) :
        m_Item(*result.getItem())
    {
    }

    static bool isConvertible(const gs2::schedule::GetEventResult& result)
    {
        return
            result.getItem().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const EzEvent& getItem() const
    {
        return m_Item;
    }

    EzEvent& getItem()
    {
        return m_Item;
    }
};

typedef gs2::AsyncResult<EzGetEventResult> AsyncEzGetEventResult;

}}}

#endif //GS2_EZ_SCHEDULE_EZGETEVENTRESULT_HPP_