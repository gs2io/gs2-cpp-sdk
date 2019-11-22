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

namespace gs2 { namespace chat {

Namespace::Data::Data(const Data& data) :
    detail::json::IModel(data),
    namespaceId(data.namespaceId),
    ownerId(data.ownerId),
    name(data.name),
    description(data.description),
    allowCreateRoom(data.allowCreateRoom),
    createdAt(data.createdAt),
    updatedAt(data.updatedAt)
{
    if (data.postMessageScript)
    {
        postMessageScript = data.postMessageScript->deepCopy();
    }
    if (data.createRoomScript)
    {
        createRoomScript = data.createRoomScript->deepCopy();
    }
    if (data.deleteRoomScript)
    {
        deleteRoomScript = data.deleteRoomScript->deepCopy();
    }
    if (data.subscribeRoomScript)
    {
        subscribeRoomScript = data.subscribeRoomScript->deepCopy();
    }
    if (data.unsubscribeRoomScript)
    {
        unsubscribeRoomScript = data.unsubscribeRoomScript->deepCopy();
    }
    if (data.postNotification)
    {
        postNotification = data.postNotification->deepCopy();
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
    else if (std::strcmp(name_, "allowCreateRoom") == 0)
    {
        if (jsonValue.IsBool())
        {
            this->allowCreateRoom = jsonValue.GetBool();
        }
    }
    else if (std::strcmp(name_, "postMessageScript") == 0)
    {
        if (jsonValue.IsObject())
        {
            const auto& jsonObject = detail::json::getObject(jsonValue);
            this->postMessageScript.emplace();
            detail::json::JsonParser::parse(&this->postMessageScript->getModel(), jsonObject);
        }
    }
    else if (std::strcmp(name_, "createRoomScript") == 0)
    {
        if (jsonValue.IsObject())
        {
            const auto& jsonObject = detail::json::getObject(jsonValue);
            this->createRoomScript.emplace();
            detail::json::JsonParser::parse(&this->createRoomScript->getModel(), jsonObject);
        }
    }
    else if (std::strcmp(name_, "deleteRoomScript") == 0)
    {
        if (jsonValue.IsObject())
        {
            const auto& jsonObject = detail::json::getObject(jsonValue);
            this->deleteRoomScript.emplace();
            detail::json::JsonParser::parse(&this->deleteRoomScript->getModel(), jsonObject);
        }
    }
    else if (std::strcmp(name_, "subscribeRoomScript") == 0)
    {
        if (jsonValue.IsObject())
        {
            const auto& jsonObject = detail::json::getObject(jsonValue);
            this->subscribeRoomScript.emplace();
            detail::json::JsonParser::parse(&this->subscribeRoomScript->getModel(), jsonObject);
        }
    }
    else if (std::strcmp(name_, "unsubscribeRoomScript") == 0)
    {
        if (jsonValue.IsObject())
        {
            const auto& jsonObject = detail::json::getObject(jsonValue);
            this->unsubscribeRoomScript.emplace();
            detail::json::JsonParser::parse(&this->unsubscribeRoomScript->getModel(), jsonObject);
        }
    }
    else if (std::strcmp(name_, "postNotification") == 0)
    {
        if (jsonValue.IsObject())
        {
            const auto& jsonObject = detail::json::getObject(jsonValue);
            this->postNotification.emplace();
            detail::json::JsonParser::parse(&this->postNotification->getModel(), jsonObject);
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
        if (lhs.m_pData->allowCreateRoom != lhr.m_pData->allowCreateRoom)
        {
            return true;
        }
        if (lhs.m_pData->postMessageScript != lhr.m_pData->postMessageScript)
        {
            return true;
        }
        if (lhs.m_pData->createRoomScript != lhr.m_pData->createRoomScript)
        {
            return true;
        }
        if (lhs.m_pData->deleteRoomScript != lhr.m_pData->deleteRoomScript)
        {
            return true;
        }
        if (lhs.m_pData->subscribeRoomScript != lhr.m_pData->subscribeRoomScript)
        {
            return true;
        }
        if (lhs.m_pData->unsubscribeRoomScript != lhr.m_pData->unsubscribeRoomScript)
        {
            return true;
        }
        if (lhs.m_pData->postNotification != lhr.m_pData->postNotification)
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