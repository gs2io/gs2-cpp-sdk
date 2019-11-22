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

#include "GitHubApiKey.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace key {

GitHubApiKey::Data::Data(const Data& data) :
    detail::json::IModel(data),
    apiKeyId(data.apiKeyId),
    name(data.name),
    description(data.description),
    apiKey(data.apiKey),
    encryptionKeyName(data.encryptionKeyName),
    createdAt(data.createdAt),
    updatedAt(data.updatedAt)
{
}

void GitHubApiKey::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "apiKeyId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->apiKeyId.emplace(jsonValue.GetString());
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
    else if (std::strcmp(name_, "apiKey") == 0)
    {
        if (jsonValue.IsString())
        {
            this->apiKey.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "encryptionKeyName") == 0)
    {
        if (jsonValue.IsString())
        {
            this->encryptionKeyName.emplace(jsonValue.GetString());
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

GitHubApiKey GitHubApiKey::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(GitHubApiKey);
}

bool operator!=(const GitHubApiKey& lhs, const GitHubApiKey& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->apiKeyId != lhr.m_pData->apiKeyId)
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
        if (lhs.m_pData->apiKey != lhr.m_pData->apiKey)
        {
            return true;
        }
        if (lhs.m_pData->encryptionKeyName != lhr.m_pData->encryptionKeyName)
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