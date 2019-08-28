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

#ifndef GS2_EZ_MISSION_EZLISTMISSIONGROUPMODELSRESULT_HPP_
#define GS2_EZ_MISSION_EZLISTMISSIONGROUPMODELSRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/mission/result/DescribeMissionGroupModelsResult.hpp>


namespace gs2 { namespace ez { namespace mission {

class EzListMissionGroupModelsResult : public gs2::Gs2Object
{
private:
    /** ミッショングループのリスト */
    List<EzMissionGroupModel> m_Items;

public:
    EzListMissionGroupModelsResult(const gs2::mission::DescribeMissionGroupModelsResult& result)
    {
        {
            auto& list = *result.getItems();
            for (int i = 0; i < list.getCount(); ++i)
            {
                m_Items += EzMissionGroupModel(list[i]);
            }
        }
    }

    static bool isConvertible(const gs2::mission::DescribeMissionGroupModelsResult& result)
    {
        return
            result.getItems().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const List<EzMissionGroupModel>& getItems() const
    {
        return m_Items;
    }

    List<EzMissionGroupModel>& getItems()
    {
        return m_Items;
    }
};

typedef gs2::AsyncResult<EzListMissionGroupModelsResult> AsyncEzListMissionGroupModelsResult;

}}}

#endif //GS2_EZ_MISSION_EZLISTMISSIONGROUPMODELSRESULT_HPP_