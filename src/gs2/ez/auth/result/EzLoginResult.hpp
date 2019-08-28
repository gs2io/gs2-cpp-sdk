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

#ifndef GS2_EZ_AUTH_EZLOGINRESULT_HPP_
#define GS2_EZ_AUTH_EZLOGINRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/auth/result/LoginBySignatureResult.hpp>


namespace gs2 { namespace ez { namespace auth {

class EzLoginResult : public gs2::Gs2Object
{
private:
    /** アクセストークン */
    StringHolder m_Token;
    /** ユーザーID */
    StringHolder m_UserId;
    /** 有効期限 */
    Int64 m_Expire;

public:
    EzLoginResult(const gs2::auth::LoginBySignatureResult& result) :
        m_Token(*result.getToken()),
        m_UserId(*result.getUserId()),
        m_Expire(*result.getExpire())
    {
    }

    static bool isConvertible(const gs2::auth::LoginBySignatureResult& result)
    {
        return
            result.getToken().has_value() &&
            result.getUserId().has_value() &&
            result.getExpire().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const gs2::StringHolder& getToken() const
    {
        return m_Token;
    }

    gs2::StringHolder& getToken()
    {
        return m_Token;
    }

    const gs2::StringHolder& getUserId() const
    {
        return m_UserId;
    }

    gs2::StringHolder& getUserId()
    {
        return m_UserId;
    }

    Int64 getExpire() const
    {
        return m_Expire;
    }
};

typedef gs2::AsyncResult<EzLoginResult> AsyncEzLoginResult;

}}}

#endif //GS2_EZ_AUTH_EZLOGINRESULT_HPP_