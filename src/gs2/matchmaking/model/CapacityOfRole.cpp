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

#include "CapacityOfRole.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace matchmaking {

CapacityOfRole::Data::Data(const Data& data) :
    detail::json::IModel(data),
    roleName(data.roleName),
    capacity(data.capacity)
{
    if (data.roleAliases)
    {
        roleAliases = data.roleAliases->deepCopy();
    }
    if (data.participants)
    {
        participants = data.participants->deepCopy();
    }
}

void CapacityOfRole::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "roleName") == 0)
    {
        if (jsonValue.IsString())
        {
            this->roleName.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "roleAliases") == 0)
    {
        if (jsonValue.IsArray())
        {
            const auto& array = jsonValue.GetArray();
            this->roleAliases.emplace();
            for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                if (json->IsString())
                {
                    auto valueStr = json->GetString();
                    StringHolder stringHolder(valueStr);
                    *this->roleAliases += std::move(stringHolder);
                }
            }
        }
    }
    else if (std::strcmp(name_, "capacity") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->capacity = jsonValue.GetInt();
        }
    }
    else if (std::strcmp(name_, "participants") == 0)
    {
        if (jsonValue.IsArray())
        {
            const auto& array = jsonValue.GetArray();
            this->participants.emplace();
            for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                Player item;
                detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                *this->participants += std::move(item);
            }
        }
    }
}

CapacityOfRole CapacityOfRole::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CapacityOfRole);
}

bool operator!=(const CapacityOfRole& lhs, const CapacityOfRole& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->roleName != lhr.m_pData->roleName)
        {
            return true;
        }
        if (lhs.m_pData->roleAliases != lhr.m_pData->roleAliases)
        {
            return true;
        }
        if (lhs.m_pData->capacity != lhr.m_pData->capacity)
        {
            return true;
        }
        if (lhs.m_pData->participants != lhr.m_pData->participants)
        {
            return true;
        }
    }
    return false;
}

} }