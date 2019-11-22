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

#include "AcceptVersion.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace version {

AcceptVersion::Data::Data(const Data& data) :
    detail::json::IModel(data),
    acceptVersionId(data.acceptVersionId),
    versionName(data.versionName),
    userId(data.userId),
    createdAt(data.createdAt),
    updatedAt(data.updatedAt)
{
    if (data.version)
    {
        version = data.version->deepCopy();
    }
}

void AcceptVersion::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "acceptVersionId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->acceptVersionId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "versionName") == 0)
    {
        if (jsonValue.IsString())
        {
            this->versionName.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "userId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->userId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "version") == 0)
    {
        if (jsonValue.IsObject())
        {
            const auto& jsonObject = detail::json::getObject(jsonValue);
            this->version.emplace();
            detail::json::JsonParser::parse(&this->version->getModel(), jsonObject);
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

AcceptVersion AcceptVersion::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(AcceptVersion);
}

bool operator!=(const AcceptVersion& lhs, const AcceptVersion& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->acceptVersionId != lhr.m_pData->acceptVersionId)
        {
            return true;
        }
        if (lhs.m_pData->versionName != lhr.m_pData->versionName)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->version != lhr.m_pData->version)
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