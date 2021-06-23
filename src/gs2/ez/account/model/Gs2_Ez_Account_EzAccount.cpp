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

#include "EzAccount.hpp"
#include <gs2/account/model/Account.hpp>


namespace gs2 { namespace ez { namespace account {

EzAccount::Data::Data(const Data& data) :
    Gs2Object(data),
    userId(data.userId),
    password(data.password),
    createdAt(data.createdAt)
{
}

EzAccount::Data::Data(const gs2::account::Account& account) :
    userId(account.getUserId()),
    password(account.getPassword()),
    createdAt(account.getCreatedAt() ? *account.getCreatedAt() : 0)
{
}

EzAccount::EzAccount(gs2::account::Account account) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(account)
{
}

EzAccount EzAccount::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzAccount);
}

gs2::account::Account EzAccount::ToModel() const
{
    gs2::account::Account account;
    account.setUserId(getUserId());
    account.setPassword(getPassword());
    account.setCreatedAt(getCreatedAt());
    return account;
}

}}}