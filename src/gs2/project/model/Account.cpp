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

#include "Account.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace project {

Account::Data::Data(const Data& data) :
    detail::json::IModel(data),
    accountId(data.accountId),
    ownerId(data.ownerId),
    name(data.name),
    email(data.email),
    fullName(data.fullName),
    companyName(data.companyName),
    password(data.password),
    status(data.status),
    createdAt(data.createdAt),
    updatedAt(data.updatedAt)
{
}

void Account::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "accountId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->accountId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "ownerId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->ownerId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "name") == 0)
    {
        if (jsonValue.IsString())
        {
            this->name.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "email") == 0)
    {
        if (jsonValue.IsString())
        {
            this->email.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "fullName") == 0)
    {
        if (jsonValue.IsString())
        {
            this->fullName.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "companyName") == 0)
    {
        if (jsonValue.IsString())
        {
            this->companyName.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "password") == 0)
    {
        if (jsonValue.IsString())
        {
            this->password.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "status") == 0)
    {
        if (jsonValue.IsString())
        {
            this->status.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "createdAt") == 0)
    {
        if (jsonValue.IsInt64())
        {
            this->createdAt = jsonValue.GetInt64();
        }
    }
    else if (std::strcmp(name_, "updatedAt") == 0)
    {
        if (jsonValue.IsInt64())
        {
            this->updatedAt = jsonValue.GetInt64();
        }
    }
}

Account Account::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Account);
}

bool operator!=(const Account& lhs, const Account& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->accountId != lhr.m_pData->accountId)
        {
            return true;
        }
        if (lhs.m_pData->ownerId != lhr.m_pData->ownerId)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->email != lhr.m_pData->email)
        {
            return true;
        }
        if (lhs.m_pData->fullName != lhr.m_pData->fullName)
        {
            return true;
        }
        if (lhs.m_pData->companyName != lhr.m_pData->companyName)
        {
            return true;
        }
        if (lhs.m_pData->password != lhr.m_pData->password)
        {
            return true;
        }
        if (lhs.m_pData->status != lhr.m_pData->status)
        {
            return true;
        }
        if (lhs.m_pData->createdAt != lhr.m_pData->createdAt)
        {
            return true;
        }
        if (lhs.m_pData->updatedAt != lhr.m_pData->updatedAt)
        {
            return true;
        }
    }
    return false;
}

} }