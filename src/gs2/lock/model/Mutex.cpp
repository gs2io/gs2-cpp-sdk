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

#include "Mutex.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace lock {

Mutex::Data::Data(const Data& data) :
    detail::json::IModel(data),
    mutexId(data.mutexId),
    userId(data.userId),
    propertyId(data.propertyId),
    transactionId(data.transactionId),
    referenceCount(data.referenceCount),
    createdAt(data.createdAt),
    ttlAt(data.ttlAt)
{
}

void Mutex::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "mutexId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->mutexId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "userId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->userId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "propertyId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->propertyId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "transactionId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->transactionId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "referenceCount") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->referenceCount = jsonValue.GetInt();
        }
    }
    else if (std::strcmp(name_, "createdAt") == 0)
    {
        if (jsonValue.IsInt64())
        {
            this->createdAt = jsonValue.GetInt64();
        }
    }
    else if (std::strcmp(name_, "ttlAt") == 0)
    {
        if (jsonValue.IsInt64())
        {
            this->ttlAt = jsonValue.GetInt64();
        }
    }
}

Mutex Mutex::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Mutex);
}

bool operator!=(const Mutex& lhs, const Mutex& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->mutexId != lhr.m_pData->mutexId)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->propertyId != lhr.m_pData->propertyId)
        {
            return true;
        }
        if (lhs.m_pData->transactionId != lhr.m_pData->transactionId)
        {
            return true;
        }
        if (lhs.m_pData->referenceCount != lhr.m_pData->referenceCount)
        {
            return true;
        }
        if (lhs.m_pData->createdAt != lhr.m_pData->createdAt)
        {
            return true;
        }
        if (lhs.m_pData->ttlAt != lhr.m_pData->ttlAt)
        {
            return true;
        }
    }
    return false;
}

} }