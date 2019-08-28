

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

#ifndef GS2_EZ_ACCOUNT_MODEL_EZTAKEOVER_HPP_
#define GS2_EZ_ACCOUNT_MODEL_EZTAKEOVER_HPP_

#include <gs2/account/model/TakeOver.hpp>


namespace gs2 { namespace ez { namespace account {

class EzTakeOver : public gs2::Gs2Object
{
private:
    /** ユーザーID */
    gs2::optional<StringHolder> m_UserId;
    /** スロット番号 */
    gs2::optional<Int32> m_Type;
    /** 引き継ぎ用ユーザーID */
    gs2::optional<StringHolder> m_UserIdentifier;
    /** 作成日時 */
    gs2::optional<Int64> m_CreatedAt;

public:
    EzTakeOver() = default;

    EzTakeOver(gs2::account::TakeOver takeOver) :
        m_UserId(takeOver.getUserId()),
        m_Type(takeOver.getType() ? *takeOver.getType() : 0),
        m_UserIdentifier(takeOver.getUserIdentifier()),
        m_CreatedAt(takeOver.getCreatedAt() ? *takeOver.getCreatedAt() : 0)
    {
    }

    gs2::account::TakeOver ToModel() const
    {
        gs2::account::TakeOver takeOver;
        takeOver.setUserId(*m_UserId);
        takeOver.setType(*m_Type);
        takeOver.setUserIdentifier(*m_UserIdentifier);
        takeOver.setCreatedAt(*m_CreatedAt);
        return takeOver;
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

    Int32 getType() const
    {
        return *m_Type;
    }

    const gs2::StringHolder& getUserIdentifier() const
    {
        return *m_UserIdentifier;
    }

    gs2::StringHolder& getUserIdentifier()
    {
        return *m_UserIdentifier;
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

    void setType(Int32 type)
    {
        m_Type = type;
    }

    void setUserIdentifier(Char* userIdentifier)
    {
        m_UserIdentifier.emplace(userIdentifier);
    }

    void setCreatedAt(Int64 createdAt)
    {
        m_CreatedAt = createdAt;
    }

    EzTakeOver& withUserId(Char* userId)
    {
        setUserId(userId);
        return *this;
    }

    EzTakeOver& withType(Int32 type)
    {
        setType(type);
        return *this;
    }

    EzTakeOver& withUserIdentifier(Char* userIdentifier)
    {
        setUserIdentifier(userIdentifier);
        return *this;
    }

    EzTakeOver& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }
};

}}}

#endif //GS2_EZ_ACCOUNT_EZTAKEOVER_HPP_