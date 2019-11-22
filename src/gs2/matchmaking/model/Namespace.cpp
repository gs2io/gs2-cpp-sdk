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

#include "Namespace.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace matchmaking {

Namespace::Data::Data(const Data& data) :
    detail::json::IModel(data),
    namespaceId(data.namespaceId),
    ownerId(data.ownerId),
    name(data.name),
    description(data.description),
    createGatheringTriggerType(data.createGatheringTriggerType),
    createGatheringTriggerRealtimeNamespaceId(data.createGatheringTriggerRealtimeNamespaceId),
    createGatheringTriggerScriptId(data.createGatheringTriggerScriptId),
    completeMatchmakingTriggerType(data.completeMatchmakingTriggerType),
    completeMatchmakingTriggerRealtimeNamespaceId(data.completeMatchmakingTriggerRealtimeNamespaceId),
    completeMatchmakingTriggerScriptId(data.completeMatchmakingTriggerScriptId),
    createdAt(data.createdAt),
    updatedAt(data.updatedAt)
{
    if (data.joinNotification)
    {
        joinNotification = data.joinNotification->deepCopy();
    }
    if (data.leaveNotification)
    {
        leaveNotification = data.leaveNotification->deepCopy();
    }
    if (data.completeNotification)
    {
        completeNotification = data.completeNotification->deepCopy();
    }
    if (data.logSetting)
    {
        logSetting = data.logSetting->deepCopy();
    }
}

void Namespace::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "namespaceId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->namespaceId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "ownerId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->ownerId.emplace(jsonValue.GetString());
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
    else if (std::strcmp(name_, "createGatheringTriggerType") == 0)
    {
        if (jsonValue.IsString())
        {
            this->createGatheringTriggerType.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "createGatheringTriggerRealtimeNamespaceId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->createGatheringTriggerRealtimeNamespaceId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "createGatheringTriggerScriptId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->createGatheringTriggerScriptId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "completeMatchmakingTriggerType") == 0)
    {
        if (jsonValue.IsString())
        {
            this->completeMatchmakingTriggerType.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "completeMatchmakingTriggerRealtimeNamespaceId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->completeMatchmakingTriggerRealtimeNamespaceId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "completeMatchmakingTriggerScriptId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->completeMatchmakingTriggerScriptId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "joinNotification") == 0)
    {
        if (jsonValue.IsObject())
        {
            const auto& jsonObject = detail::json::getObject(jsonValue);
            this->joinNotification.emplace();
            detail::json::JsonParser::parse(&this->joinNotification->getModel(), jsonObject);
        }
    }
    else if (std::strcmp(name_, "leaveNotification") == 0)
    {
        if (jsonValue.IsObject())
        {
            const auto& jsonObject = detail::json::getObject(jsonValue);
            this->leaveNotification.emplace();
            detail::json::JsonParser::parse(&this->leaveNotification->getModel(), jsonObject);
        }
    }
    else if (std::strcmp(name_, "completeNotification") == 0)
    {
        if (jsonValue.IsObject())
        {
            const auto& jsonObject = detail::json::getObject(jsonValue);
            this->completeNotification.emplace();
            detail::json::JsonParser::parse(&this->completeNotification->getModel(), jsonObject);
        }
    }
    else if (std::strcmp(name_, "logSetting") == 0)
    {
        if (jsonValue.IsObject())
        {
            const auto& jsonObject = detail::json::getObject(jsonValue);
            this->logSetting.emplace();
            detail::json::JsonParser::parse(&this->logSetting->getModel(), jsonObject);
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

Namespace Namespace::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Namespace);
}

bool operator!=(const Namespace& lhs, const Namespace& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->namespaceId != lhr.m_pData->namespaceId)
        {
            return true;
        }
        if (lhs.m_pData->ownerId != lhr.m_pData->ownerId)
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
        if (lhs.m_pData->createGatheringTriggerType != lhr.m_pData->createGatheringTriggerType)
        {
            return true;
        }
        if (lhs.m_pData->createGatheringTriggerRealtimeNamespaceId != lhr.m_pData->createGatheringTriggerRealtimeNamespaceId)
        {
            return true;
        }
        if (lhs.m_pData->createGatheringTriggerScriptId != lhr.m_pData->createGatheringTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->completeMatchmakingTriggerType != lhr.m_pData->completeMatchmakingTriggerType)
        {
            return true;
        }
        if (lhs.m_pData->completeMatchmakingTriggerRealtimeNamespaceId != lhr.m_pData->completeMatchmakingTriggerRealtimeNamespaceId)
        {
            return true;
        }
        if (lhs.m_pData->completeMatchmakingTriggerScriptId != lhr.m_pData->completeMatchmakingTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->joinNotification != lhr.m_pData->joinNotification)
        {
            return true;
        }
        if (lhs.m_pData->leaveNotification != lhr.m_pData->leaveNotification)
        {
            return true;
        }
        if (lhs.m_pData->completeNotification != lhr.m_pData->completeNotification)
        {
            return true;
        }
        if (lhs.m_pData->logSetting != lhr.m_pData->logSetting)
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