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

#include "ItemModelMaster.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace inventory {

ItemModelMaster::Data::Data(const Data& data) :
    detail::json::IModel(data),
    itemModelId(data.itemModelId),
    inventoryName(data.inventoryName),
    name(data.name),
    description(data.description),
    metadata(data.metadata),
    stackingLimit(data.stackingLimit),
    allowMultipleStacks(data.allowMultipleStacks),
    sortValue(data.sortValue),
    createdAt(data.createdAt),
    updatedAt(data.updatedAt)
{
}

void ItemModelMaster::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "itemModelId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->itemModelId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "inventoryName") == 0)
    {
        if (jsonValue.IsString())
        {
            this->inventoryName.emplace(jsonValue.GetString());
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
    else if (std::strcmp(name_, "stackingLimit") == 0)
    {
        if (jsonValue.IsInt64())
        {
            this->stackingLimit = jsonValue.GetInt64();
        }
    }
    else if (std::strcmp(name_, "allowMultipleStacks") == 0)
    {
        if (jsonValue.IsBool())
        {
            this->allowMultipleStacks = jsonValue.GetBool();
        }
    }
    else if (std::strcmp(name_, "sortValue") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->sortValue = jsonValue.GetInt();
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

ItemModelMaster ItemModelMaster::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(ItemModelMaster);
}

bool operator!=(const ItemModelMaster& lhs, const ItemModelMaster& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->itemModelId != lhr.m_pData->itemModelId)
        {
            return true;
        }
        if (lhs.m_pData->inventoryName != lhr.m_pData->inventoryName)
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
        if (lhs.m_pData->stackingLimit != lhr.m_pData->stackingLimit)
        {
            return true;
        }
        if (lhs.m_pData->allowMultipleStacks != lhr.m_pData->allowMultipleStacks)
        {
            return true;
        }
        if (lhs.m_pData->sortValue != lhr.m_pData->sortValue)
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