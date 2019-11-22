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

#include "ExperienceModelMaster.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace experience {

ExperienceModelMaster::Data::Data(const Data& data) :
    detail::json::IModel(data),
    experienceModelId(data.experienceModelId),
    name(data.name),
    description(data.description),
    metadata(data.metadata),
    defaultExperience(data.defaultExperience),
    defaultRankCap(data.defaultRankCap),
    maxRankCap(data.maxRankCap),
    rankThresholdId(data.rankThresholdId),
    createdAt(data.createdAt),
    updatedAt(data.updatedAt)
{
}

void ExperienceModelMaster::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "experienceModelId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->experienceModelId.emplace(jsonValue.GetString());
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
    else if (std::strcmp(name_, "metadata") == 0)
    {
        if (jsonValue.IsString())
        {
            this->metadata.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "defaultExperience") == 0)
    {
        if (jsonValue.IsInt64())
        {
            this->defaultExperience = jsonValue.GetInt64();
        }
    }
    else if (std::strcmp(name_, "defaultRankCap") == 0)
    {
        if (jsonValue.IsInt64())
        {
            this->defaultRankCap = jsonValue.GetInt64();
        }
    }
    else if (std::strcmp(name_, "maxRankCap") == 0)
    {
        if (jsonValue.IsInt64())
        {
            this->maxRankCap = jsonValue.GetInt64();
        }
    }
    else if (std::strcmp(name_, "rankThresholdId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->rankThresholdId.emplace(jsonValue.GetString());
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

ExperienceModelMaster ExperienceModelMaster::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(ExperienceModelMaster);
}

bool operator!=(const ExperienceModelMaster& lhs, const ExperienceModelMaster& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->experienceModelId != lhr.m_pData->experienceModelId)
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
        if (lhs.m_pData->metadata != lhr.m_pData->metadata)
        {
            return true;
        }
        if (lhs.m_pData->defaultExperience != lhr.m_pData->defaultExperience)
        {
            return true;
        }
        if (lhs.m_pData->defaultRankCap != lhr.m_pData->defaultRankCap)
        {
            return true;
        }
        if (lhs.m_pData->maxRankCap != lhr.m_pData->maxRankCap)
        {
            return true;
        }
        if (lhs.m_pData->rankThresholdId != lhr.m_pData->rankThresholdId)
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