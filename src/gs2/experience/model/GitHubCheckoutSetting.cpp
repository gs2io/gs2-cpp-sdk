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

#include "GitHubCheckoutSetting.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace experience {

GitHubCheckoutSetting::Data::Data(const Data& data) :
    detail::json::IModel(data),
    gitHubApiKeyId(data.gitHubApiKeyId),
    repositoryName(data.repositoryName),
    sourcePath(data.sourcePath),
    referenceType(data.referenceType),
    commitHash(data.commitHash),
    branchName(data.branchName),
    tagName(data.tagName)
{
}

void GitHubCheckoutSetting::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "gitHubApiKeyId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->gitHubApiKeyId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "repositoryName") == 0)
    {
        if (jsonValue.IsString())
        {
            this->repositoryName.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "sourcePath") == 0)
    {
        if (jsonValue.IsString())
        {
            this->sourcePath.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "referenceType") == 0)
    {
        if (jsonValue.IsString())
        {
            this->referenceType.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "commitHash") == 0)
    {
        if (jsonValue.IsString())
        {
            this->commitHash.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "branchName") == 0)
    {
        if (jsonValue.IsString())
        {
            this->branchName.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "tagName") == 0)
    {
        if (jsonValue.IsString())
        {
            this->tagName.emplace(jsonValue.GetString());
        }
    }
}

GitHubCheckoutSetting GitHubCheckoutSetting::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(GitHubCheckoutSetting);
}

bool operator!=(const GitHubCheckoutSetting& lhs, const GitHubCheckoutSetting& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->gitHubApiKeyId != lhr.m_pData->gitHubApiKeyId)
        {
            return true;
        }
        if (lhs.m_pData->repositoryName != lhr.m_pData->repositoryName)
        {
            return true;
        }
        if (lhs.m_pData->sourcePath != lhr.m_pData->sourcePath)
        {
            return true;
        }
        if (lhs.m_pData->referenceType != lhr.m_pData->referenceType)
        {
            return true;
        }
        if (lhs.m_pData->commitHash != lhr.m_pData->commitHash)
        {
            return true;
        }
        if (lhs.m_pData->branchName != lhr.m_pData->branchName)
        {
            return true;
        }
        if (lhs.m_pData->tagName != lhr.m_pData->tagName)
        {
            return true;
        }
    }
    return false;
}

} }