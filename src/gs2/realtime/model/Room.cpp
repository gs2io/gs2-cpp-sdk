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

#include "Room.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace realtime {

Room::Data::Data(const Data& data) :
    detail::json::IModel(data),
    roomId(data.roomId),
    name(data.name),
    ipAddress(data.ipAddress),
    port(data.port),
    encryptionKey(data.encryptionKey),
    createdAt(data.createdAt),
    updatedAt(data.updatedAt)
{
    if (data.notificationUserIds)
    {
        notificationUserIds = data.notificationUserIds->deepCopy();
    }
}

void Room::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "roomId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->roomId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "name") == 0)
    {
        if (jsonValue.IsString())
        {
            this->name.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "ipAddress") == 0)
    {
        if (jsonValue.IsString())
        {
            this->ipAddress.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "port") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->port = jsonValue.GetInt();
        }
    }
    else if (std::strcmp(name_, "encryptionKey") == 0)
    {
        if (jsonValue.IsString())
        {
            this->encryptionKey.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "notificationUserIds") == 0)
    {
        if (jsonValue.IsArray())
        {
            const auto& array = jsonValue.GetArray();
            this->notificationUserIds.emplace();
            for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                if (json->IsString())
                {
                    auto valueStr = json->GetString();
                    StringHolder stringHolder(valueStr);
                    *this->notificationUserIds += std::move(stringHolder);
                }
            }
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

Room Room::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Room);
}

bool operator!=(const Room& lhs, const Room& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->roomId != lhr.m_pData->roomId)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->ipAddress != lhr.m_pData->ipAddress)
        {
            return true;
        }
        if (lhs.m_pData->port != lhr.m_pData->port)
        {
            return true;
        }
        if (lhs.m_pData->encryptionKey != lhr.m_pData->encryptionKey)
        {
            return true;
        }
        if (lhs.m_pData->notificationUserIds != lhr.m_pData->notificationUserIds)
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