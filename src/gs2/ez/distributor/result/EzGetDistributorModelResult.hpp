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

#ifndef GS2_EZ_DISTRIBUTOR_EZGETDISTRIBUTORMODELRESULT_HPP_
#define GS2_EZ_DISTRIBUTOR_EZGETDISTRIBUTORMODELRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/distributor/result/GetDistributorModelResult.hpp>


namespace gs2 { namespace ez { namespace distributor {

class EzGetDistributorModelResult : public gs2::Gs2Object
{
private:
    /** 配信設定 */
    EzDistributorModel m_Item;

public:
    EzGetDistributorModelResult(const gs2::distributor::GetDistributorModelResult& result) :
        m_Item(*result.getItem())
    {
    }

    static bool isConvertible(const gs2::distributor::GetDistributorModelResult& result)
    {
        return
            result.getItem().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const EzDistributorModel& getItem() const
    {
        return m_Item;
    }

    EzDistributorModel& getItem()
    {
        return m_Item;
    }
};

typedef gs2::AsyncResult<EzGetDistributorModelResult> AsyncEzGetDistributorModelResult;

}}}

#endif //GS2_EZ_DISTRIBUTOR_EZGETDISTRIBUTORMODELRESULT_HPP_