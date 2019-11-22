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

#include "MissionGroupModel.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace mission {

MissionGroupModel::Data::Data(const Data& data) :
    detail::json::IModel(data),
    missionGroupId(data.missionGroupId),
    name(data.name),
    metadata(data.metadata),
    completeNotificationNamespaceId(data.completeNotificationNamespaceId)
{
    if (data.tasks)
    {
        tasks = data.tasks->deepCopy();
    }
}

void MissionGroupModel::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "missionGroupId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->missionGroupId.emplace(jsonValue.GetString());
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
    else if (std::strcmp(name_, "tasks") == 0)
    {
        if (jsonValue.IsArray())
        {
            const auto& array = jsonValue.GetArray();
            this->tasks.emplace();
            for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                MissionTaskModel item;
                detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                *this->tasks += std::move(item);
            }
        }
    }
    else if (std::strcmp(name_, "completeNotificationNamespaceId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->completeNotificationNamespaceId.emplace(jsonValue.GetString());
        }
    }
}

MissionGroupModel MissionGroupModel::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(MissionGroupModel);
}

bool operator!=(const MissionGroupModel& lhs, const MissionGroupModel& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->missionGroupId != lhr.m_pData->missionGroupId)
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
        if (lhs.m_pData->tasks != lhr.m_pData->tasks)
        {
            return true;
        }
        if (lhs.m_pData->completeNotificationNamespaceId != lhr.m_pData->completeNotificationNamespaceId)
        {
            return true;
        }
    }
    return false;
}

} }