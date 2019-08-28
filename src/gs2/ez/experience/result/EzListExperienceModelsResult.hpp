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

#ifndef GS2_EZ_EXPERIENCE_EZLISTEXPERIENCEMODELSRESULT_HPP_
#define GS2_EZ_EXPERIENCE_EZLISTEXPERIENCEMODELSRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/experience/result/DescribeExperienceModelsResult.hpp>


namespace gs2 { namespace ez { namespace experience {

class EzListExperienceModelsResult : public gs2::Gs2Object
{
private:
    /** 経験値・ランクアップ閾値モデルのリスト */
    List<EzExperienceModel> m_Items;

public:
    EzListExperienceModelsResult(const gs2::experience::DescribeExperienceModelsResult& result)
    {
        {
            auto& list = *result.getItems();
            for (int i = 0; i < list.getCount(); ++i)
            {
                m_Items += EzExperienceModel(list[i]);
            }
        }
    }

    static bool isConvertible(const gs2::experience::DescribeExperienceModelsResult& result)
    {
        return
            result.getItems().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const List<EzExperienceModel>& getItems() const
    {
        return m_Items;
    }

    List<EzExperienceModel>& getItems()
    {
        return m_Items;
    }
};

typedef gs2::AsyncResult<EzListExperienceModelsResult> AsyncEzListExperienceModelsResult;

}}}

#endif //GS2_EZ_EXPERIENCE_EZLISTEXPERIENCEMODELSRESULT_HPP_