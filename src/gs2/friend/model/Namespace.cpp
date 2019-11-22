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

namespace gs2 { namespace friend_ {

Namespace::Data::Data(const Data& data) :
    detail::json::IModel(data),
    namespaceId(data.namespaceId),
    ownerId(data.ownerId),
    name(data.name),
    description(data.description),
    createdAt(data.createdAt),
    updatedAt(data.updatedAt)
{
    if (data.followScript)
    {
        followScript = data.followScript->deepCopy();
    }
    if (data.unfollowScript)
    {
        unfollowScript = data.unfollowScript->deepCopy();
    }
    if (data.sendRequestScript)
    {
        sendRequestScript = data.sendRequestScript->deepCopy();
    }
    if (data.cancelRequestScript)
    {
        cancelRequestScript = data.cancelRequestScript->deepCopy();
    }
    if (data.acceptRequestScript)
    {
        acceptRequestScript = data.acceptRequestScript->deepCopy();
    }
    if (data.rejectRequestScript)
    {
        rejectRequestScript = data.rejectRequestScript->deepCopy();
    }
    if (data.deleteFriendScript)
    {
        deleteFriendScript = data.deleteFriendScript->deepCopy();
    }
    if (data.updateProfileScript)
    {
        updateProfileScript = data.updateProfileScript->deepCopy();
    }
    if (data.followNotification)
    {
        followNotification = data.followNotification->deepCopy();
    }
    if (data.receiveRequestNotification)
    {
        receiveRequestNotification = data.receiveRequestNotification->deepCopy();
    }
    if (data.acceptRequestNotification)
    {
        acceptRequestNotification = data.acceptRequestNotification->deepCopy();
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
    else if (std::strcmp(name_, "followScript") == 0)
    {
        if (jsonValue.IsObject())
        {
            const auto& jsonObject = detail::json::getObject(jsonValue);
            this->followScript.emplace();
            detail::json::JsonParser::parse(&this->followScript->getModel(), jsonObject);
        }
    }
    else if (std::strcmp(name_, "unfollowScript") == 0)
    {
        if (jsonValue.IsObject())
        {
            const auto& jsonObject = detail::json::getObject(jsonValue);
            this->unfollowScript.emplace();
            detail::json::JsonParser::parse(&this->unfollowScript->getModel(), jsonObject);
        }
    }
    else if (std::strcmp(name_, "sendRequestScript") == 0)
    {
        if (jsonValue.IsObject())
        {
            const auto& jsonObject = detail::json::getObject(jsonValue);
            this->sendRequestScript.emplace();
            detail::json::JsonParser::parse(&this->sendRequestScript->getModel(), jsonObject);
        }
    }
    else if (std::strcmp(name_, "cancelRequestScript") == 0)
    {
        if (jsonValue.IsObject())
        {
            const auto& jsonObject = detail::json::getObject(jsonValue);
            this->cancelRequestScript.emplace();
            detail::json::JsonParser::parse(&this->cancelRequestScript->getModel(), jsonObject);
        }
    }
    else if (std::strcmp(name_, "acceptRequestScript") == 0)
    {
        if (jsonValue.IsObject())
        {
            const auto& jsonObject = detail::json::getObject(jsonValue);
            this->acceptRequestScript.emplace();
            detail::json::JsonParser::parse(&this->acceptRequestScript->getModel(), jsonObject);
        }
    }
    else if (std::strcmp(name_, "rejectRequestScript") == 0)
    {
        if (jsonValue.IsObject())
        {
            const auto& jsonObject = detail::json::getObject(jsonValue);
            this->rejectRequestScript.emplace();
            detail::json::JsonParser::parse(&this->rejectRequestScript->getModel(), jsonObject);
        }
    }
    else if (std::strcmp(name_, "deleteFriendScript") == 0)
    {
        if (jsonValue.IsObject())
        {
            const auto& jsonObject = detail::json::getObject(jsonValue);
            this->deleteFriendScript.emplace();
            detail::json::JsonParser::parse(&this->deleteFriendScript->getModel(), jsonObject);
        }
    }
    else if (std::strcmp(name_, "updateProfileScript") == 0)
    {
        if (jsonValue.IsObject())
        {
            const auto& jsonObject = detail::json::getObject(jsonValue);
            this->updateProfileScript.emplace();
            detail::json::JsonParser::parse(&this->updateProfileScript->getModel(), jsonObject);
        }
    }
    else if (std::strcmp(name_, "followNotification") == 0)
    {
        if (jsonValue.IsObject())
        {
            const auto& jsonObject = detail::json::getObject(jsonValue);
            this->followNotification.emplace();
            detail::json::JsonParser::parse(&this->followNotification->getModel(), jsonObject);
        }
    }
    else if (std::strcmp(name_, "receiveRequestNotification") == 0)
    {
        if (jsonValue.IsObject())
        {
            const auto& jsonObject = detail::json::getObject(jsonValue);
            this->receiveRequestNotification.emplace();
            detail::json::JsonParser::parse(&this->receiveRequestNotification->getModel(), jsonObject);
        }
    }
    else if (std::strcmp(name_, "acceptRequestNotification") == 0)
    {
        if (jsonValue.IsObject())
        {
            const auto& jsonObject = detail::json::getObject(jsonValue);
            this->acceptRequestNotification.emplace();
            detail::json::JsonParser::parse(&this->acceptRequestNotification->getModel(), jsonObject);
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
        if (lhs.m_pData->followScript != lhr.m_pData->followScript)
        {
            return true;
        }
        if (lhs.m_pData->unfollowScript != lhr.m_pData->unfollowScript)
        {
            return true;
        }
        if (lhs.m_pData->sendRequestScript != lhr.m_pData->sendRequestScript)
        {
            return true;
        }
        if (lhs.m_pData->cancelRequestScript != lhr.m_pData->cancelRequestScript)
        {
            return true;
        }
        if (lhs.m_pData->acceptRequestScript != lhr.m_pData->acceptRequestScript)
        {
            return true;
        }
        if (lhs.m_pData->rejectRequestScript != lhr.m_pData->rejectRequestScript)
        {
            return true;
        }
        if (lhs.m_pData->deleteFriendScript != lhr.m_pData->deleteFriendScript)
        {
            return true;
        }
        if (lhs.m_pData->updateProfileScript != lhr.m_pData->updateProfileScript)
        {
            return true;
        }
        if (lhs.m_pData->followNotification != lhr.m_pData->followNotification)
        {
            return true;
        }
        if (lhs.m_pData->receiveRequestNotification != lhr.m_pData->receiveRequestNotification)
        {
            return true;
        }
        if (lhs.m_pData->acceptRequestNotification != lhr.m_pData->acceptRequestNotification)
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