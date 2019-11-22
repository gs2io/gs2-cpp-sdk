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

#include "MissionTaskModel.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace mission {

MissionTaskModel::Data::Data(const Data& data) :
    detail::json::IModel(data),
    missionTaskId(data.missionTaskId),
    name(data.name),
    metadata(data.metadata),
    counterName(data.counterName),
    resetType(data.resetType),
    targetValue(data.targetValue),
    challengePeriodEventId(data.challengePeriodEventId),
    premiseMissionTaskName(data.premiseMissionTaskName)
{
    if (data.completeAcquireActions)
    {
        completeAcquireActions = data.completeAcquireActions->deepCopy();
    }
}

void MissionTaskModel::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "missionTaskId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->missionTaskId.emplace(jsonValue.GetString());
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
    else if (std::strcmp(name_, "counterName") == 0)
    {
        if (jsonValue.IsString())
        {
            this->counterName.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "resetType") == 0)
    {
        if (jsonValue.IsString())
        {
            this->resetType.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "targetValue") == 0)
    {
        if (jsonValue.IsInt64())
        {
            this->targetValue = jsonValue.GetInt64();
        }
    }
    else if (std::strcmp(name_, "completeAcquireActions") == 0)
    {
        if (jsonValue.IsArray())
        {
            const auto& array = jsonValue.GetArray();
            this->completeAcquireActions.emplace();
            for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                AcquireAction item;
                detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                *this->completeAcquireActions += std::move(item);
            }
        }
    }
    else if (std::strcmp(name_, "challengePeriodEventId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->challengePeriodEventId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "premiseMissionTaskName") == 0)
    {
        if (jsonValue.IsString())
        {
            this->premiseMissionTaskName.emplace(jsonValue.GetString());
        }
    }
}

MissionTaskModel MissionTaskModel::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(MissionTaskModel);
}

bool operator!=(const MissionTaskModel& lhs, const MissionTaskModel& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->missionTaskId != lhr.m_pData->missionTaskId)
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
        if (lhs.m_pData->counterName != lhr.m_pData->counterName)
        {
            return true;
        }
        if (lhs.m_pData->resetType != lhr.m_pData->resetType)
        {
            return true;
        }
        if (lhs.m_pData->targetValue != lhr.m_pData->targetValue)
        {
            return true;
        }
        if (lhs.m_pData->completeAcquireActions != lhr.m_pData->completeAcquireActions)
        {
            return true;
        }
        if (lhs.m_pData->challengePeriodEventId != lhr.m_pData->challengePeriodEventId)
        {
            return true;
        }
        if (lhs.m_pData->premiseMissionTaskName != lhr.m_pData->premiseMissionTaskName)
        {
            return true;
        }
    }
    return false;
}

} }