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

#include "Status.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace experience {

Status::Data::Data(const Data& data) :
    detail::json::IModel(data),
    statusId(data.statusId),
    experienceName(data.experienceName),
    userId(data.userId),
    propertyId(data.propertyId),
    experienceValue(data.experienceValue),
    rankValue(data.rankValue),
    rankCapValue(data.rankCapValue),
    createdAt(data.createdAt),
    updatedAt(data.updatedAt)
{
}

void Status::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "statusId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->statusId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "experienceName") == 0)
    {
        if (jsonValue.IsString())
        {
            this->experienceName.emplace(jsonValue.GetString());
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
    else if (std::strcmp(name_, "experienceValue") == 0)
    {
        if (jsonValue.IsInt64())
        {
            this->experienceValue = jsonValue.GetInt64();
        }
    }
    else if (std::strcmp(name_, "rankValue") == 0)
    {
        if (jsonValue.IsInt64())
        {
            this->rankValue = jsonValue.GetInt64();
        }
    }
    else if (std::strcmp(name_, "rankCapValue") == 0)
    {
        if (jsonValue.IsInt64())
        {
            this->rankCapValue = jsonValue.GetInt64();
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

Status Status::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Status);
}

bool operator!=(const Status& lhs, const Status& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->statusId != lhr.m_pData->statusId)
        {
            return true;
        }
        if (lhs.m_pData->experienceName != lhr.m_pData->experienceName)
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
        if (lhs.m_pData->experienceValue != lhr.m_pData->experienceValue)
        {
            return true;
        }
        if (lhs.m_pData->rankValue != lhr.m_pData->rankValue)
        {
            return true;
        }
        if (lhs.m_pData->rankCapValue != lhr.m_pData->rankCapValue)
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