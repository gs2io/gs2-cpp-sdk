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

#include "Stamina.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace stamina {

Stamina::Data::Data(const Data& data) :
    detail::json::IModel(data),
    staminaId(data.staminaId),
    staminaName(data.staminaName),
    userId(data.userId),
    value(data.value),
    maxValue(data.maxValue),
    recoverIntervalMinutes(data.recoverIntervalMinutes),
    recoverValue(data.recoverValue),
    overflowValue(data.overflowValue),
    nextRecoverAt(data.nextRecoverAt),
    lastRecoveredAt(data.lastRecoveredAt),
    createdAt(data.createdAt),
    updatedAt(data.updatedAt)
{
}

void Stamina::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "staminaId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->staminaId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "staminaName") == 0)
    {
        if (jsonValue.IsString())
        {
            this->staminaName.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "userId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->userId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "value") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->value = jsonValue.GetInt();
        }
    }
    else if (std::strcmp(name_, "maxValue") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->maxValue = jsonValue.GetInt();
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
    else if (std::strcmp(name_, "overflowValue") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->overflowValue = jsonValue.GetInt();
        }
    }
    else if (std::strcmp(name_, "nextRecoverAt") == 0)
    {
        if (jsonValue.IsInt64())
        {
            this->nextRecoverAt = jsonValue.GetInt64();
        }
    }
    else if (std::strcmp(name_, "lastRecoveredAt") == 0)
    {
        if (jsonValue.IsInt64())
        {
            this->lastRecoveredAt = jsonValue.GetInt64();
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

Stamina Stamina::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Stamina);
}

bool operator!=(const Stamina& lhs, const Stamina& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->staminaId != lhr.m_pData->staminaId)
        {
            return true;
        }
        if (lhs.m_pData->staminaName != lhr.m_pData->staminaName)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->value != lhr.m_pData->value)
        {
            return true;
        }
        if (lhs.m_pData->maxValue != lhr.m_pData->maxValue)
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
        if (lhs.m_pData->overflowValue != lhr.m_pData->overflowValue)
        {
            return true;
        }
        if (lhs.m_pData->nextRecoverAt != lhr.m_pData->nextRecoverAt)
        {
            return true;
        }
        if (lhs.m_pData->lastRecoveredAt != lhr.m_pData->lastRecoveredAt)
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