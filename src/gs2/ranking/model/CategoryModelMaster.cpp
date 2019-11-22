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

#include "CategoryModelMaster.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace ranking {

CategoryModelMaster::Data::Data(const Data& data) :
    detail::json::IModel(data),
    categoryModelId(data.categoryModelId),
    name(data.name),
    description(data.description),
    metadata(data.metadata),
    minimumValue(data.minimumValue),
    maximumValue(data.maximumValue),
    orderDirection(data.orderDirection),
    scope(data.scope),
    uniqueByUserId(data.uniqueByUserId),
    calculateIntervalMinutes(data.calculateIntervalMinutes),
    createdAt(data.createdAt),
    updatedAt(data.updatedAt)
{
}

void CategoryModelMaster::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "categoryModelId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->categoryModelId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "name") == 0)
    {
        if (jsonValue.IsString())
        {
            this->name.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "description") == 0)
    {
        if (jsonValue.IsString())
        {
            this->description.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "metadata") == 0)
    {
        if (jsonValue.IsString())
        {
            this->metadata.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "minimumValue") == 0)
    {
        if (jsonValue.IsInt64())
        {
            this->minimumValue = jsonValue.GetInt64();
        }
    }
    else if (std::strcmp(name_, "maximumValue") == 0)
    {
        if (jsonValue.IsInt64())
        {
            this->maximumValue = jsonValue.GetInt64();
        }
    }
    else if (std::strcmp(name_, "orderDirection") == 0)
    {
        if (jsonValue.IsString())
        {
            this->orderDirection.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "scope") == 0)
    {
        if (jsonValue.IsString())
        {
            this->scope.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "uniqueByUserId") == 0)
    {
        if (jsonValue.IsBool())
        {
            this->uniqueByUserId = jsonValue.GetBool();
        }
    }
    else if (std::strcmp(name_, "calculateIntervalMinutes") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->calculateIntervalMinutes = jsonValue.GetInt();
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

CategoryModelMaster CategoryModelMaster::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CategoryModelMaster);
}

bool operator!=(const CategoryModelMaster& lhs, const CategoryModelMaster& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->categoryModelId != lhr.m_pData->categoryModelId)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->description != lhr.m_pData->description)
        {
            return true;
        }
        if (lhs.m_pData->metadata != lhr.m_pData->metadata)
        {
            return true;
        }
        if (lhs.m_pData->minimumValue != lhr.m_pData->minimumValue)
        {
            return true;
        }
        if (lhs.m_pData->maximumValue != lhr.m_pData->maximumValue)
        {
            return true;
        }
        if (lhs.m_pData->orderDirection != lhr.m_pData->orderDirection)
        {
            return true;
        }
        if (lhs.m_pData->scope != lhr.m_pData->scope)
        {
            return true;
        }
        if (lhs.m_pData->uniqueByUserId != lhr.m_pData->uniqueByUserId)
        {
            return true;
        }
        if (lhs.m_pData->calculateIntervalMinutes != lhr.m_pData->calculateIntervalMinutes)
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