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

#ifndef GS2_EZ_EXPERIENCE_EZGETEXPERIENCEMODELRESULT_HPP_
#define GS2_EZ_EXPERIENCE_EZGETEXPERIENCEMODELRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/experience/result/GetExperienceModelResult.hpp>


namespace gs2 { namespace ez { namespace experience {

class EzGetExperienceModelResult : public gs2::Gs2Object
{
private:
    /** 経験値・ランクアップ閾値モデル */
    EzExperienceModel m_Item;

public:
    EzGetExperienceModelResult(const gs2::experience::GetExperienceModelResult& result) :
        m_Item(*result.getItem())
    {
    }

    static bool isConvertible(const gs2::experience::GetExperienceModelResult& result)
    {
        return
            result.getItem().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const EzExperienceModel& getItem() const
    {
        return m_Item;
    }

    EzExperienceModel& getItem()
    {
        return m_Item;
    }
};

typedef gs2::AsyncResult<EzGetExperienceModelResult> AsyncEzGetExperienceModelResult;

}}}

#endif //GS2_EZ_EXPERIENCE_EZGETEXPERIENCEMODELRESULT_HPP_