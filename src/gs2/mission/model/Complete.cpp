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

#include "Complete.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace mission {

Complete::Data::Data(const Data& data) :
    detail::json::IModel(data),
    completeId(data.completeId),
    userId(data.userId),
    missionGroupName(data.missionGroupName),
    createdAt(data.createdAt),
    updatedAt(data.updatedAt)
{
    if (data.completedMissionTaskNames)
    {
        completedMissionTaskNames = data.completedMissionTaskNames->deepCopy();
    }
    if (data.receivedMissionTaskNames)
    {
        receivedMissionTaskNames = data.receivedMissionTaskNames->deepCopy();
    }
}

void Complete::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "completeId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->completeId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "userId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->userId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "missionGroupName") == 0)
    {
        if (jsonValue.IsString())
        {
            this->missionGroupName.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "completedMissionTaskNames") == 0)
    {
        if (jsonValue.IsArray())
        {
            const auto& array = jsonValue.GetArray();
            this->completedMissionTaskNames.emplace();
            for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                if (json->IsString())
                {
                    auto valueStr = json->GetString();
                    StringHolder stringHolder(valueStr);
                    *this->completedMissionTaskNames += std::move(stringHolder);
                }
            }
        }
    }
    else if (std::strcmp(name_, "receivedMissionTaskNames") == 0)
    {
        if (jsonValue.IsArray())
        {
            const auto& array = jsonValue.GetArray();
            this->receivedMissionTaskNames.emplace();
            for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                if (json->IsString())
                {
                    auto valueStr = json->GetString();
                    StringHolder stringHolder(valueStr);
                    *this->receivedMissionTaskNames += std::move(stringHolder);
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

Complete Complete::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Complete);
}

bool operator!=(const Complete& lhs, const Complete& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->completeId != lhr.m_pData->completeId)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->missionGroupName != lhr.m_pData->missionGroupName)
        {
            return true;
        }
        if (lhs.m_pData->completedMissionTaskNames != lhr.m_pData->completedMissionTaskNames)
        {
            return true;
        }
        if (lhs.m_pData->receivedMissionTaskNames != lhr.m_pData->receivedMissionTaskNames)
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