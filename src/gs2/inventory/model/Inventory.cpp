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

#include "Inventory.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace inventory {

Inventory::Data::Data(const Data& data) :
    detail::json::IModel(data),
    inventoryId(data.inventoryId),
    inventoryName(data.inventoryName),
    userId(data.userId),
    currentInventoryCapacityUsage(data.currentInventoryCapacityUsage),
    currentInventoryMaxCapacity(data.currentInventoryMaxCapacity),
    createdAt(data.createdAt),
    updatedAt(data.updatedAt)
{
}

void Inventory::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "inventoryId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->inventoryId.emplace(jsonValue.GetString());
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
    else if (std::strcmp(name_, "currentInventoryCapacityUsage") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->currentInventoryCapacityUsage = jsonValue.GetInt();
        }
    }
    else if (std::strcmp(name_, "currentInventoryMaxCapacity") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->currentInventoryMaxCapacity = jsonValue.GetInt();
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

Inventory Inventory::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Inventory);
}

bool operator!=(const Inventory& lhs, const Inventory& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->inventoryId != lhr.m_pData->inventoryId)
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
        if (lhs.m_pData->currentInventoryCapacityUsage != lhr.m_pData->currentInventoryCapacityUsage)
        {
            return true;
        }
        if (lhs.m_pData->currentInventoryMaxCapacity != lhr.m_pData->currentInventoryMaxCapacity)
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