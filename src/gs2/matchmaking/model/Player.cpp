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

#include "Player.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace matchmaking {

Player::Data::Data(const Data& data) :
    detail::json::IModel(data),
    userId(data.userId),
    roleName(data.roleName)
{
    if (data.attributes)
    {
        attributes = data.attributes->deepCopy();
    }
    if (data.denyUserIds)
    {
        denyUserIds = data.denyUserIds->deepCopy();
    }
}

void Player::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "userId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->userId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "attributes") == 0)
    {
        if (jsonValue.IsArray())
        {
            const auto& array = jsonValue.GetArray();
            this->attributes.emplace();
            for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                Attribute item;
                detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                *this->attributes += std::move(item);
            }
        }
    }
    else if (std::strcmp(name_, "roleName") == 0)
    {
        if (jsonValue.IsString())
        {
            this->roleName.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "denyUserIds") == 0)
    {
        if (jsonValue.IsArray())
        {
            const auto& array = jsonValue.GetArray();
            this->denyUserIds.emplace();
            for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                if (json->IsString())
                {
                    auto valueStr = json->GetString();
                    StringHolder stringHolder(valueStr);
                    *this->denyUserIds += std::move(stringHolder);
                }
            }
        }
    }
}

Player Player::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Player);
}

bool operator!=(const Player& lhs, const Player& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->attributes != lhr.m_pData->attributes)
        {
            return true;
        }
        if (lhs.m_pData->roleName != lhr.m_pData->roleName)
        {
            return true;
        }
        if (lhs.m_pData->denyUserIds != lhr.m_pData->denyUserIds)
        {
            return true;
        }
    }
    return false;
}

} }