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

#include "StaminaModelMaster.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace stamina {

StaminaModelMaster::Data::Data(const Data& data) :
    detail::json::IModel(data),
    staminaModelId(data.staminaModelId),
    name(data.name),
    metadata(data.metadata),
    description(data.description),
    recoverIntervalMinutes(data.recoverIntervalMinutes),
    recoverValue(data.recoverValue),
    initialCapacity(data.initialCapacity),
    isOverflow(data.isOverflow),
    maxCapacity(data.maxCapacity),
    maxStaminaTableId(data.maxStaminaTableId),
    recoverIntervalTableId(data.recoverIntervalTableId),
    recoverValueTableId(data.recoverValueTableId),
    createdAt(data.createdAt),
    updatedAt(data.updatedAt)
{
}

void StaminaModelMaster::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "staminaModelId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->staminaModelId.emplace(jsonValue.GetString());
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
    else if (std::strcmp(name_, "recoverIntervalMinutes") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->recoverIntervalMinutes = jsonValue.GetInt();
        }
    }
    else if (std::strcmp(name_, "recoverValue") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->recoverValue = jsonValue.GetInt();
        }
    }
    else if (std::strcmp(name_, "initialCapacity") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->initialCapacity = jsonValue.GetInt();
        }
    }
    else if (std::strcmp(name_, "isOverflow") == 0)
    {
        if (jsonValue.IsBool())
        {
            this->isOverflow = jsonValue.GetBool();
        }
    }
    else if (std::strcmp(name_, "maxCapacity") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->maxCapacity = jsonValue.GetInt();
        }
    }
    else if (std::strcmp(name_, "maxStaminaTableId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->maxStaminaTableId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "recoverIntervalTableId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->recoverIntervalTableId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "recoverValueTableId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->recoverValueTableId.emplace(jsonValue.GetString());
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

StaminaModelMaster StaminaModelMaster::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(StaminaModelMaster);
}

bool operator!=(const StaminaModelMaster& lhs, const StaminaModelMaster& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->staminaModelId != lhr.m_pData->staminaModelId)
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
        if (lhs.m_pData->recoverIntervalMinutes != lhr.m_pData->recoverIntervalMinutes)
        {
            return true;
        }
        if (lhs.m_pData->recoverValue != lhr.m_pData->recoverValue)
        {
            return true;
        }
        if (lhs.m_pData->initialCapacity != lhr.m_pData->initialCapacity)
        {
            return true;
        }
        if (lhs.m_pData->isOverflow != lhr.m_pData->isOverflow)
        {
            return true;
        }
        if (lhs.m_pData->maxCapacity != lhr.m_pData->maxCapacity)
        {
            return true;
        }
        if (lhs.m_pData->maxStaminaTableId != lhr.m_pData->maxStaminaTableId)
        {
            return true;
        }
        if (lhs.m_pData->recoverIntervalTableId != lhr.m_pData->recoverIntervalTableId)
        {
            return true;
        }
        if (lhs.m_pData->recoverValueTableId != lhr.m_pData->recoverValueTableId)
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