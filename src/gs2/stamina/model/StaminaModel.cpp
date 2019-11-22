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

#include "StaminaModel.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace stamina {

StaminaModel::Data::Data(const Data& data) :
    detail::json::IModel(data),
    staminaModelId(data.staminaModelId),
    name(data.name),
    metadata(data.metadata),
    recoverIntervalMinutes(data.recoverIntervalMinutes),
    recoverValue(data.recoverValue),
    initialCapacity(data.initialCapacity),
    isOverflow(data.isOverflow),
    maxCapacity(data.maxCapacity)
{
    if (data.maxStaminaTable)
    {
        maxStaminaTable = data.maxStaminaTable->deepCopy();
    }
    if (data.recoverIntervalTable)
    {
        recoverIntervalTable = data.recoverIntervalTable->deepCopy();
    }
    if (data.recoverValueTable)
    {
        recoverValueTable = data.recoverValueTable->deepCopy();
    }
}

void StaminaModel::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
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
    else if (std::strcmp(name_, "maxStaminaTable") == 0)
    {
        if (jsonValue.IsObject())
        {
            const auto& jsonObject = detail::json::getObject(jsonValue);
            this->maxStaminaTable.emplace();
            detail::json::JsonParser::parse(&this->maxStaminaTable->getModel(), jsonObject);
        }
    }
    else if (std::strcmp(name_, "recoverIntervalTable") == 0)
    {
        if (jsonValue.IsObject())
        {
            const auto& jsonObject = detail::json::getObject(jsonValue);
            this->recoverIntervalTable.emplace();
            detail::json::JsonParser::parse(&this->recoverIntervalTable->getModel(), jsonObject);
        }
    }
    else if (std::strcmp(name_, "recoverValueTable") == 0)
    {
        if (jsonValue.IsObject())
        {
            const auto& jsonObject = detail::json::getObject(jsonValue);
            this->recoverValueTable.emplace();
            detail::json::JsonParser::parse(&this->recoverValueTable->getModel(), jsonObject);
        }
    }
}

StaminaModel StaminaModel::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(StaminaModel);
}

bool operator!=(const StaminaModel& lhs, const StaminaModel& lhr)
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
        if (lhs.m_pData->maxStaminaTable != lhr.m_pData->maxStaminaTable)
        {
            return true;
        }
        if (lhs.m_pData->recoverIntervalTable != lhr.m_pData->recoverIntervalTable)
        {
            return true;
        }
        if (lhs.m_pData->recoverValueTable != lhr.m_pData->recoverValueTable)
        {
            return true;
        }
    }
    return false;
}

} }