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

#ifndef GS2_EZ_LOTTERY_EZLISTPROBABILITIESRESULT_HPP_
#define GS2_EZ_LOTTERY_EZLISTPROBABILITIESRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/lottery/result/DescribeProbabilitiesResult.hpp>


namespace gs2 { namespace ez { namespace lottery {

class EzListProbabilitiesResult : public gs2::Gs2Object
{
private:
    /** 景品の当選確率リスト */
    List<EzProbability> m_Items;

public:
    EzListProbabilitiesResult(const gs2::lottery::DescribeProbabilitiesResult& result)
    {
        {
            auto& list = *result.getItems();
            for (int i = 0; i < list.getCount(); ++i)
            {
                m_Items += EzProbability(list[i]);
            }
        }
    }

    static bool isConvertible(const gs2::lottery::DescribeProbabilitiesResult& result)
    {
        return
            result.getItems().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const List<EzProbability>& getItems() const
    {
        return m_Items;
    }

    List<EzProbability>& getItems()
    {
        return m_Items;
    }
};

typedef gs2::AsyncResult<EzListProbabilitiesResult> AsyncEzListProbabilitiesResult;

}}}

#endif //GS2_EZ_LOTTERY_EZLISTPROBABILITIESRESULT_HPP_