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

#ifndef GS2_EZ_SCHEDULE_EZLISTEVENTSRESULT_HPP_
#define GS2_EZ_SCHEDULE_EZLISTEVENTSRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/schedule/result/DescribeEventsResult.hpp>


namespace gs2 { namespace ez { namespace schedule {

class EzListEventsResult : public gs2::Gs2Object
{
private:
    /** イベントのリスト */
    List<EzEvent> m_Items;

public:
    EzListEventsResult(const gs2::schedule::DescribeEventsResult& result)
    {
        {
            auto& list = *result.getItems();
            for (int i = 0; i < list.getCount(); ++i)
            {
                m_Items += EzEvent(list[i]);
            }
        }
    }

    static bool isConvertible(const gs2::schedule::DescribeEventsResult& result)
    {
        return
            result.getItems().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const List<EzEvent>& getItems() const
    {
        return m_Items;
    }

    List<EzEvent>& getItems()
    {
        return m_Items;
    }
};

typedef gs2::AsyncResult<EzListEventsResult> AsyncEzListEventsResult;

}}}

#endif //GS2_EZ_SCHEDULE_EZLISTEVENTSRESULT_HPP_