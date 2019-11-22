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

#include "SignTargetVersion.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace version {

SignTargetVersion::Data::Data(const Data& data) :
    detail::json::IModel(data),
    region(data.region),
    ownerId(data.ownerId),
    namespaceName(data.namespaceName),
    versionName(data.versionName)
{
    if (data.version)
    {
        version = data.version->deepCopy();
    }
}

void SignTargetVersion::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "region") == 0)
    {
        if (jsonValue.IsString())
        {
            this->region.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "ownerId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->ownerId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "namespaceName") == 0)
    {
        if (jsonValue.IsString())
        {
            this->namespaceName.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "versionName") == 0)
    {
        if (jsonValue.IsString())
        {
            this->versionName.emplace(jsonValue.GetString());
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
}

SignTargetVersion SignTargetVersion::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(SignTargetVersion);
}

bool operator!=(const SignTargetVersion& lhs, const SignTargetVersion& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->region != lhr.m_pData->region)
        {
            return true;
        }
        if (lhs.m_pData->ownerId != lhr.m_pData->ownerId)
        {
            return true;
        }
        if (lhs.m_pData->namespaceName != lhr.m_pData->namespaceName)
        {
            return true;
        }
        if (lhs.m_pData->versionName != lhr.m_pData->versionName)
        {
            return true;
        }
        if (lhs.m_pData->version != lhr.m_pData->version)
        {
            return true;
        }
    }
    return false;
}

} }