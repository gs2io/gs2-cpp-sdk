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

#include "Identifier.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace identifier {

Identifier::Data::Data(const Data& data) :
    detail::json::IModel(data),
    ownerId(data.ownerId),
    clientId(data.clientId),
    userName(data.userName),
    clientSecret(data.clientSecret),
    createdAt(data.createdAt)
{
}

void Identifier::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "ownerId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->ownerId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "clientId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->clientId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "userName") == 0)
    {
        if (jsonValue.IsString())
        {
            this->userName.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "clientSecret") == 0)
    {
        if (jsonValue.IsString())
        {
            this->clientSecret.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "createdAt") == 0)
    {
        if (jsonValue.IsInt64())
        {
            this->createdAt = jsonValue.GetInt64();
        }
    }
}

Identifier Identifier::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Identifier);
}

bool operator!=(const Identifier& lhs, const Identifier& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->ownerId != lhr.m_pData->ownerId)
        {
            return true;
        }
        if (lhs.m_pData->clientId != lhr.m_pData->clientId)
        {
            return true;
        }
        if (lhs.m_pData->userName != lhr.m_pData->userName)
        {
            return true;
        }
        if (lhs.m_pData->clientSecret != lhr.m_pData->clientSecret)
        {
            return true;
        }
        if (lhs.m_pData->createdAt != lhr.m_pData->createdAt)
        {
            return true;
        }
    }
    return false;
}

} }