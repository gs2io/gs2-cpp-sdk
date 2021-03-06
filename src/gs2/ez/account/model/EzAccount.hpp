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

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace account {

class Account;

}

namespace ez { namespace account {

class EzAccount : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** アカウントID */
        gs2::optional<StringHolder> userId;
        /** パスワード */
        gs2::optional<StringHolder> password;
        /** 作成日時 */
        gs2::optional<Int64> createdAt;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::account::Account& account);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzAccount() = default;
    EzAccount(const EzAccount& ezAccount) = default;
    EzAccount(EzAccount&& ezAccount) = default;
    ~EzAccount() = default;

    EzAccount(gs2::account::Account account);

    EzAccount& operator=(const EzAccount& ezAccount) = default;
    EzAccount& operator=(EzAccount&& ezAccount) = default;

    EzAccount deepCopy() const;

    gs2::account::Account ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getUserId() const
    {
        return *ensureData().userId;
    }

    const StringHolder& getPassword() const
    {
        return *ensureData().password;
    }

    Int64 getCreatedAt() const
    {
        return *ensureData().createdAt;
    }

    // ========================================
    //   Setters
    // ========================================

    void setUserId(StringHolder userId)
    {
        ensureData().userId = std::move(userId);
    }

    void setPassword(StringHolder password)
    {
        ensureData().password = std::move(password);
    }

    void setCreatedAt(Int64 createdAt)
    {
        ensureData().createdAt = createdAt;
    }

    EzAccount& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    EzAccount& withPassword(StringHolder password)
    {
        setPassword(std::move(password));
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