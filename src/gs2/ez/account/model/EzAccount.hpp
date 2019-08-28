

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

#ifndef GS2_EZ_ACCOUNT_MODEL_EZACCOUNT_HPP_
#define GS2_EZ_ACCOUNT_MODEL_EZACCOUNT_HPP_

#include <gs2/account/model/Account.hpp>


namespace gs2 { namespace ez { namespace account {

class EzAccount : public gs2::Gs2Object
{
private:
    /** アカウントID */
    gs2::optional<StringHolder> m_UserId;
    /** パスワード */
    gs2::optional<StringHolder> m_Password;
    /** 作成日時 */
    gs2::optional<Int64> m_CreatedAt;

public:
    EzAccount() = default;

    EzAccount(gs2::account::Account account) :
        m_UserId(account.getUserId()),
        m_Password(account.getPassword()),
        m_CreatedAt(account.getCreatedAt() ? *account.getCreatedAt() : 0)
    {
    }

    gs2::account::Account ToModel() const
    {
        gs2::account::Account account;
        account.setUserId(*m_UserId);
        account.setPassword(*m_Password);
        account.setCreatedAt(*m_CreatedAt);
        return account;
    }

    // ========================================
    //   Getters
    // ========================================

    const gs2::StringHolder& getUserId() const
    {
        return *m_UserId;
    }

    gs2::StringHolder& getUserId()
    {
        return *m_UserId;
    }

    const gs2::StringHolder& getPassword() const
    {
        return *m_Password;
    }

    gs2::StringHolder& getPassword()
    {
        return *m_Password;
    }

    Int64 getCreatedAt() const
    {
        return *m_CreatedAt;
    }

    // ========================================
    //   Setters
    // ========================================

    void setUserId(Char* userId)
    {
        m_UserId.emplace(userId);
    }

    void setPassword(Char* password)
    {
        m_Password.emplace(password);
    }

    void setCreatedAt(Int64 createdAt)
    {
        m_CreatedAt = createdAt;
    }

    EzAccount& withUserId(Char* userId)
    {
        setUserId(userId);
        return *this;
    }

    EzAccount& withPassword(Char* password)
    {
        setPassword(password);
        return *this;
    }

    EzAccount& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }
};

}}}

#endif //GS2_EZ_ACCOUNT_EZACCOUNT_HPP_