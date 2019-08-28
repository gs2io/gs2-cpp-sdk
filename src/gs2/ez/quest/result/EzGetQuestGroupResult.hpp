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

#ifndef GS2_EZ_QUEST_EZGETQUESTGROUPRESULT_HPP_
#define GS2_EZ_QUEST_EZGETQUESTGROUPRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/quest/result/GetQuestGroupModelResult.hpp>


namespace gs2 { namespace ez { namespace quest {

class EzGetQuestGroupResult : public gs2::Gs2Object
{
private:
    /** クエストグループ */
    EzQuestGroupModel m_Item;

public:
    EzGetQuestGroupResult(const gs2::quest::GetQuestGroupModelResult& result) :
        m_Item(*result.getItem())
    {
    }

    static bool isConvertible(const gs2::quest::GetQuestGroupModelResult& result)
    {
        return
            result.getItem().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const EzQuestGroupModel& getItem() const
    {
        return m_Item;
    }

    EzQuestGroupModel& getItem()
    {
        return m_Item;
    }
};

typedef gs2::AsyncResult<EzGetQuestGroupResult> AsyncEzGetQuestGroupResult;

}}}

#endif //GS2_EZ_QUEST_EZGETQUESTGROUPRESULT_HPP_