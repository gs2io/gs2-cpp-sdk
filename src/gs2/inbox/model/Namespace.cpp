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

namespace gs2 { namespace inbox {

Namespace::Data::Data(const Data& data) :
    detail::json::IModel(data),
    namespaceId(data.namespaceId),
    ownerId(data.ownerId),
    name(data.name),
    description(data.description),
    isAutomaticDeletingEnabled(data.isAutomaticDeletingEnabled),
    queueNamespaceId(data.queueNamespaceId),
    keyId(data.keyId),
    createdAt(data.createdAt),
    updatedAt(data.updatedAt)
{
    if (data.receiveMessageScript)
    {
        receiveMessageScript = data.receiveMessageScript->deepCopy();
    }
    if (data.readMessageScript)
    {
        readMessageScript = data.readMessageScript->deepCopy();
    }
    if (data.deleteMessageScript)
    {
        deleteMessageScript = data.deleteMessageScript->deepCopy();
    }
    if (data.receiveNotification)
    {
        receiveNotification = data.receiveNotification->deepCopy();
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
    else if (std::strcmp(name_, "isAutomaticDeletingEnabled") == 0)
    {
        if (jsonValue.IsBool())
        {
            this->isAutomaticDeletingEnabled = jsonValue.GetBool();
        }
    }
    else if (std::strcmp(name_, "receiveMessageScript") == 0)
    {
        if (jsonValue.IsObject())
        {
            const auto& jsonObject = detail::json::getObject(jsonValue);
            this->receiveMessageScript.emplace();
            detail::json::JsonParser::parse(&this->receiveMessageScript->getModel(), jsonObject);
        }
    }
    else if (std::strcmp(name_, "readMessageScript") == 0)
    {
        if (jsonValue.IsObject())
        {
            const auto& jsonObject = detail::json::getObject(jsonValue);
            this->readMessageScript.emplace();
            detail::json::JsonParser::parse(&this->readMessageScript->getModel(), jsonObject);
        }
    }
    else if (std::strcmp(name_, "deleteMessageScript") == 0)
    {
        if (jsonValue.IsObject())
        {
            const auto& jsonObject = detail::json::getObject(jsonValue);
            this->deleteMessageScript.emplace();
            detail::json::JsonParser::parse(&this->deleteMessageScript->getModel(), jsonObject);
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
    else if (std::strcmp(name_, "receiveNotification") == 0)
    {
        if (jsonValue.IsObject())
        {
            const auto& jsonObject = detail::json::getObject(jsonValue);
            this->receiveNotification.emplace();
            detail::json::JsonParser::parse(&this->receiveNotification->getModel(), jsonObject);
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
        if (lhs.m_pData->isAutomaticDeletingEnabled != lhr.m_pData->isAutomaticDeletingEnabled)
        {
            return true;
        }
        if (lhs.m_pData->receiveMessageScript != lhr.m_pData->receiveMessageScript)
        {
            return true;
        }
        if (lhs.m_pData->readMessageScript != lhr.m_pData->readMessageScript)
        {
            return true;
        }
        if (lhs.m_pData->deleteMessageScript != lhr.m_pData->deleteMessageScript)
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
        if (lhs.m_pData->receiveNotification != lhr.m_pData->receiveNotification)
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