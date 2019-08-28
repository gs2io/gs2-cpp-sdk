

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

#ifndef GS2_EZ_AUTH_MODEL_EZACCESSTOKEN_HPP_
#define GS2_EZ_AUTH_MODEL_EZACCESSTOKEN_HPP_

#include <gs2/auth/model/AccessToken.hpp>


namespace gs2 { namespace ez { namespace auth {

class EzAccessToken : public gs2::Gs2Object
{
private:
    /** アクセストークン */
    gs2::optional<StringHolder> m_Token;
    /** ユーザーID */
    gs2::optional<StringHolder> m_UserId;
    /** 有効期限 */
    gs2::optional<Int64> m_Expire;

public:
    EzAccessToken() = default;

    EzAccessToken(gs2::auth::AccessToken accessToken) :
        m_Token(accessToken.getToken()),
        m_UserId(accessToken.getUserId()),
        m_Expire(accessToken.getExpire() ? *accessToken.getExpire() : 0)
    {
    }

    gs2::auth::AccessToken ToModel() const
    {
        gs2::auth::AccessToken accessToken;
        accessToken.setToken(*m_Token);
        accessToken.setUserId(*m_UserId);
        accessToken.setExpire(*m_Expire);
        return accessToken;
    }

    // ========================================
    //   Getters
    // ========================================

    const gs2::StringHolder& getToken() const
    {
        return *m_Token;
    }

    gs2::StringHolder& getToken()
    {
        return *m_Token;
    }

    const gs2::StringHolder& getUserId() const
    {
        return *m_UserId;
    }

    gs2::StringHolder& getUserId()
    {
        return *m_UserId;
    }

    Int64 getExpire() const
    {
        return *m_Expire;
    }

    // ========================================
    //   Setters
    // ========================================

    void setToken(Char* token)
    {
        m_Token.emplace(token);
    }

    void setUserId(Char* userId)
    {
        m_UserId.emplace(userId);
    }

    void setExpire(Int64 expire)
    {
        m_Expire = expire;
    }

    EzAccessToken& withToken(Char* token)
    {
        setToken(token);
        return *this;
    }

    EzAccessToken& withUserId(Char* userId)
    {
        setUserId(userId);
        return *this;
    }

    EzAccessToken& withExpire(Int64 expire)
    {
        setExpire(expire);
        return *this;
    }
};

}}}

#endif //GS2_EZ_AUTH_EZACCESSTOKEN_HPP_