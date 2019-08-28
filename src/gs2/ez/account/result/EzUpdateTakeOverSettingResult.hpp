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

#ifndef GS2_EZ_ACCOUNT_EZUPDATETAKEOVERSETTINGRESULT_HPP_
#define GS2_EZ_ACCOUNT_EZUPDATETAKEOVERSETTINGRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/account/result/UpdateTakeOverResult.hpp>


namespace gs2 { namespace ez { namespace account {

class EzUpdateTakeOverSettingResult : public gs2::Gs2Object
{
private:
    /** 引き継ぎ設定 */
    EzTakeOver m_Item;

public:
    EzUpdateTakeOverSettingResult(const gs2::account::UpdateTakeOverResult& result) :
        m_Item(*result.getItem())
    {
    }

    static bool isConvertible(const gs2::account::UpdateTakeOverResult& result)
    {
        return
            result.getItem().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const EzTakeOver& getItem() const
    {
        return m_Item;
    }

    EzTakeOver& getItem()
    {
        return m_Item;
    }
};

typedef gs2::AsyncResult<EzUpdateTakeOverSettingResult> AsyncEzUpdateTakeOverSettingResult;

}}}

#endif //GS2_EZ_ACCOUNT_EZUPDATETAKEOVERSETTINGRESULT_HPP_