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

#include "InventoryModelMaster.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace inventory {

InventoryModelMaster::Data::Data(const Data& data) :
    detail::json::IModel(data),
    inventoryModelId(data.inventoryModelId),
    name(data.name),
    metadata(data.metadata),
    description(data.description),
    initialCapacity(data.initialCapacity),
    maxCapacity(data.maxCapacity),
    createdAt(data.createdAt),
    updatedAt(data.updatedAt)
{
}

void InventoryModelMaster::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "inventoryModelId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->inventoryModelId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "name") == 0)
    {
        if (jsonValue.IsString())
        {
            this->name.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "metadata") == 0)
    {
        if (jsonValue.IsString())
        {
            this->metadata.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "description") == 0)
    {
        if (jsonValue.IsString())
        {
            this->description.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "initialCapacity") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->initialCapacity = jsonValue.GetInt();
        }
    }
    else if (std::strcmp(name_, "maxCapacity") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->maxCapacity = jsonValue.GetInt();
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

InventoryModelMaster InventoryModelMaster::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(InventoryModelMaster);
}

bool operator!=(const InventoryModelMaster& lhs, const InventoryModelMaster& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->inventoryModelId != lhr.m_pData->inventoryModelId)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->metadata != lhr.m_pData->metadata)
        {
            return true;
        }
        if (lhs.m_pData->description != lhr.m_pData->description)
        {
            return true;
        }
        if (lhs.m_pData->initialCapacity != lhr.m_pData->initialCapacity)
        {
            return true;
        }
        if (lhs.m_pData->maxCapacity != lhr.m_pData->maxCapacity)
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