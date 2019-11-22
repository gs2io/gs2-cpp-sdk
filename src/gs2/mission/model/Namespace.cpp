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

namespace gs2 { namespace mission {

Namespace::Data::Data(const Data& data) :
    detail::json::IModel(data),
    namespaceId(data.namespaceId),
    ownerId(data.ownerId),
    name(data.name),
    description(data.description),
    missionCompleteTriggerScriptId(data.missionCompleteTriggerScriptId),
    missionCompleteDoneTriggerScriptId(data.missionCompleteDoneTriggerScriptId),
    missionCompleteDoneTriggerQueueNamespaceId(data.missionCompleteDoneTriggerQueueNamespaceId),
    counterIncrementTriggerScriptId(data.counterIncrementTriggerScriptId),
    counterIncrementDoneTriggerScriptId(data.counterIncrementDoneTriggerScriptId),
    counterIncrementDoneTriggerQueueNamespaceId(data.counterIncrementDoneTriggerQueueNamespaceId),
    receiveRewardsTriggerScriptId(data.receiveRewardsTriggerScriptId),
    receiveRewardsDoneTriggerScriptId(data.receiveRewardsDoneTriggerScriptId),
    receiveRewardsDoneTriggerQueueNamespaceId(data.receiveRewardsDoneTriggerQueueNamespaceId),
    queueNamespaceId(data.queueNamespaceId),
    keyId(data.keyId),
    createdAt(data.createdAt),
    updatedAt(data.updatedAt)
{
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
    else if (std::strcmp(name_, "missionCompleteTriggerScriptId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->missionCompleteTriggerScriptId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "missionCompleteDoneTriggerScriptId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->missionCompleteDoneTriggerScriptId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "missionCompleteDoneTriggerQueueNamespaceId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->missionCompleteDoneTriggerQueueNamespaceId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "counterIncrementTriggerScriptId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->counterIncrementTriggerScriptId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "counterIncrementDoneTriggerScriptId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->counterIncrementDoneTriggerScriptId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "counterIncrementDoneTriggerQueueNamespaceId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->counterIncrementDoneTriggerQueueNamespaceId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "receiveRewardsTriggerScriptId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->receiveRewardsTriggerScriptId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "receiveRewardsDoneTriggerScriptId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->receiveRewardsDoneTriggerScriptId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "receiveRewardsDoneTriggerQueueNamespaceId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->receiveRewardsDoneTriggerQueueNamespaceId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "queueNamespaceId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->queueNamespaceId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "keyId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->keyId.emplace(jsonValue.GetString());
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
        if (lhs.m_pData->missionCompleteTriggerScriptId != lhr.m_pData->missionCompleteTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->missionCompleteDoneTriggerScriptId != lhr.m_pData->missionCompleteDoneTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->missionCompleteDoneTriggerQueueNamespaceId != lhr.m_pData->missionCompleteDoneTriggerQueueNamespaceId)
        {
            return true;
        }
        if (lhs.m_pData->counterIncrementTriggerScriptId != lhr.m_pData->counterIncrementTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->counterIncrementDoneTriggerScriptId != lhr.m_pData->counterIncrementDoneTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->counterIncrementDoneTriggerQueueNamespaceId != lhr.m_pData->counterIncrementDoneTriggerQueueNamespaceId)
        {
            return true;
        }
        if (lhs.m_pData->receiveRewardsTriggerScriptId != lhr.m_pData->receiveRewardsTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->receiveRewardsDoneTriggerScriptId != lhr.m_pData->receiveRewardsDoneTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->receiveRewardsDoneTriggerQueueNamespaceId != lhr.m_pData->receiveRewardsDoneTriggerQueueNamespaceId)
        {
            return true;
        }
        if (lhs.m_pData->queueNamespaceId != lhr.m_pData->queueNamespaceId)
        {
            return true;
        }
        if (lhs.m_pData->keyId != lhr.m_pData->keyId)
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