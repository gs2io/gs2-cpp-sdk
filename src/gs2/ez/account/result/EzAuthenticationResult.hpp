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

#ifndef GS2_EZ_ACCOUNT_EZAUTHENTICATIONRESULT_HPP_
#define GS2_EZ_ACCOUNT_EZAUTHENTICATIONRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/account/result/AuthenticationResult.hpp>


namespace gs2 { namespace ez { namespace account {

class EzAuthenticationResult : public gs2::Gs2Object
{
private:
    /** ゲームプレイヤーアカウント */
    EzAccount m_Item;
    /** 署名対象のアカウント情報 */
    StringHolder m_Body;
    /** 署名 */
    StringHolder m_Signature;

public:
    EzAuthenticationResult(const gs2::account::AuthenticationResult& result) :
        m_Item(*result.getItem()),
        m_Body(*result.getBody()),
        m_Signature(*result.getSignature())
    {
    }

    static bool isConvertible(const gs2::account::AuthenticationResult& result)
    {
        return
            result.getItem().has_value() &&
            result.getBody().has_value() &&
            result.getSignature().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const EzAccount& getItem() const
    {
        return m_Item;
    }

    EzAccount& getItem()
    {
        return m_Item;
    }

    const gs2::StringHolder& getBody() const
    {
        return m_Body;
    }

    gs2::StringHolder& getBody()
    {
        return m_Body;
    }

    const gs2::StringHolder& getSignature() const
    {
        return m_Signature;
    }

    gs2::StringHolder& getSignature()
    {
        return m_Signature;
    }
};

typedef gs2::AsyncResult<EzAuthenticationResult> AsyncEzAuthenticationResult;

}}}

#endif //GS2_EZ_ACCOUNT_EZAUTHENTICATIONRESULT_HPP_