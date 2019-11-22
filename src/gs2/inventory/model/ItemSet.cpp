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

#include "ItemSet.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace inventory {

ItemSet::Data::Data(const Data& data) :
    detail::json::IModel(data),
    itemSetId(data.itemSetId),
    inventoryName(data.inventoryName),
    userId(data.userId),
    itemName(data.itemName),
    count(data.count),
    sortValue(data.sortValue),
    expiresAt(data.expiresAt),
    createdAt(data.createdAt),
    updatedAt(data.updatedAt)
{
}

void ItemSet::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "itemSetId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->itemSetId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "inventoryName") == 0)
    {
        if (jsonValue.IsString())
        {
            this->inventoryName.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "userId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->userId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "itemName") == 0)
    {
        if (jsonValue.IsString())
        {
            this->itemName.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "count") == 0)
    {
        if (jsonValue.IsInt64())
        {
            this->count = jsonValue.GetInt64();
        }
    }
    else if (std::strcmp(name_, "sortValue") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->sortValue = jsonValue.GetInt();
        }
    }
    else if (std::strcmp(name_, "expiresAt") == 0)
    {
        if (jsonValue.IsInt64())
        {
            this->expiresAt = jsonValue.GetInt64();
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

ItemSet ItemSet::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(ItemSet);
}

bool operator!=(const ItemSet& lhs, const ItemSet& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->itemSetId != lhr.m_pData->itemSetId)
        {
            return true;
        }
        if (lhs.m_pData->inventoryName != lhr.m_pData->inventoryName)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->itemName != lhr.m_pData->itemName)
        {
            return true;
        }
        if (lhs.m_pData->count != lhr.m_pData->count)
        {
            return true;
        }
        if (lhs.m_pData->sortValue != lhr.m_pData->sortValue)
        {
            return true;
        }
        if (lhs.m_pData->expiresAt != lhr.m_pData->expiresAt)
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