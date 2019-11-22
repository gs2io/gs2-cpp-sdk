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

#include "Progress.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace quest {

Progress::Data::Data(const Data& data) :
    detail::json::IModel(data),
    progressId(data.progressId),
    userId(data.userId),
    transactionId(data.transactionId),
    questModelId(data.questModelId),
    randomSeed(data.randomSeed),
    createdAt(data.createdAt),
    updatedAt(data.updatedAt)
{
    if (data.rewards)
    {
        rewards = data.rewards->deepCopy();
    }
}

void Progress::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "progressId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->progressId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "userId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->userId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "transactionId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->transactionId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "questModelId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->questModelId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "randomSeed") == 0)
    {
        if (jsonValue.IsInt64())
        {
            this->randomSeed = jsonValue.GetInt64();
        }
    }
    else if (std::strcmp(name_, "rewards") == 0)
    {
        if (jsonValue.IsArray())
        {
            const auto& array = jsonValue.GetArray();
            this->rewards.emplace();
            for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                Reward item;
                detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                *this->rewards += std::move(item);
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

Progress Progress::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Progress);
}

bool operator!=(const Progress& lhs, const Progress& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->progressId != lhr.m_pData->progressId)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->transactionId != lhr.m_pData->transactionId)
        {
            return true;
        }
        if (lhs.m_pData->questModelId != lhr.m_pData->questModelId)
        {
            return true;
        }
        if (lhs.m_pData->randomSeed != lhr.m_pData->randomSeed)
        {
            return true;
        }
        if (lhs.m_pData->rewards != lhr.m_pData->rewards)
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