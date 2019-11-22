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

#include "AccessToken.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace auth {

AccessToken::Data::Data(const Data& data) :
    detail::json::IModel(data),
    ownerId(data.ownerId),
    token(data.token),
    userId(data.userId),
    expire(data.expire)
{
}

void AccessToken::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "ownerId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->ownerId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "token") == 0)
    {
        if (jsonValue.IsString())
        {
            this->token.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "userId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->userId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "expire") == 0)
    {
        if (jsonValue.IsInt64())
        {
            this->expire = jsonValue.GetInt64();
        }
    }
}

AccessToken AccessToken::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(AccessToken);
}

bool operator!=(const AccessToken& lhs, const AccessToken& lhr)
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
        if (lhs.m_pData->token != lhr.m_pData->token)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->expire != lhr.m_pData->expire)
        {
            return true;
        }
    }
    return false;
}

} }