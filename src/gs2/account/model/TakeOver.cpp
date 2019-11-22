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

#include "TakeOver.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace account {

TakeOver::Data::Data(const Data& data) :
    detail::json::IModel(data),
    takeOverId(data.takeOverId),
    userId(data.userId),
    type(data.type),
    userIdentifier(data.userIdentifier),
    password(data.password),
    createdAt(data.createdAt)
{
}

void TakeOver::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "takeOverId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->takeOverId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "userId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->userId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "type") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->type = jsonValue.GetInt();
        }
    }
    else if (std::strcmp(name_, "userIdentifier") == 0)
    {
        if (jsonValue.IsString())
        {
            this->userIdentifier.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "password") == 0)
    {
        if (jsonValue.IsString())
        {
            this->password.emplace(jsonValue.GetString());
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

TakeOver TakeOver::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(TakeOver);
}

bool operator!=(const TakeOver& lhs, const TakeOver& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->takeOverId != lhr.m_pData->takeOverId)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->type != lhr.m_pData->type)
        {
            return true;
        }
        if (lhs.m_pData->userIdentifier != lhr.m_pData->userIdentifier)
        {
            return true;
        }
        if (lhs.m_pData->password != lhr.m_pData->password)
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