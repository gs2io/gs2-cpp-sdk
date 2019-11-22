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

#include "Score.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace ranking {

Score::Data::Data(const Data& data) :
    detail::json::IModel(data),
    scoreId(data.scoreId),
    categoryName(data.categoryName),
    userId(data.userId),
    uniqueId(data.uniqueId),
    scorerUserId(data.scorerUserId),
    score(data.score),
    metadata(data.metadata),
    createdAt(data.createdAt)
{
}

void Score::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "scoreId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->scoreId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "categoryName") == 0)
    {
        if (jsonValue.IsString())
        {
            this->categoryName.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "userId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->userId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "uniqueId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->uniqueId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "scorerUserId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->scorerUserId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "score") == 0)
    {
        if (jsonValue.IsInt64())
        {
            this->score = jsonValue.GetInt64();
        }
    }
    else if (std::strcmp(name_, "metadata") == 0)
    {
        if (jsonValue.IsString())
        {
            this->metadata.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "createdAt") == 0)
    {
        if (jsonValue.IsInt64())
        {
            this->createdAt = jsonValue.GetInt64();
        }
    }
}

Score Score::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Score);
}

bool operator!=(const Score& lhs, const Score& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->scoreId != lhr.m_pData->scoreId)
        {
            return true;
        }
        if (lhs.m_pData->categoryName != lhr.m_pData->categoryName)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->uniqueId != lhr.m_pData->uniqueId)
        {
            return true;
        }
        if (lhs.m_pData->scorerUserId != lhr.m_pData->scorerUserId)
        {
            return true;
        }
        if (lhs.m_pData->score != lhr.m_pData->score)
        {
            return true;
        }
        if (lhs.m_pData->metadata != lhr.m_pData->metadata)
        {
            return true;
        }
        if (lhs.m_pData->createdAt != lhr.m_pData->createdAt)
        {
            return true;
        }
    }
    return false;
}

} }