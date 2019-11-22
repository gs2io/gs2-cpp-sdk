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

#include "TargetVersion.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace version {

TargetVersion::Data::Data(const Data& data) :
    detail::json::IModel(data),
    versionName(data.versionName),
    body(data.body),
    signature(data.signature)
{
    if (data.version)
    {
        version = data.version->deepCopy();
    }
}

void TargetVersion::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "versionName") == 0)
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
    else if (std::strcmp(name_, "body") == 0)
    {
        if (jsonValue.IsString())
        {
            this->body.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "signature") == 0)
    {
        if (jsonValue.IsString())
        {
            this->signature.emplace(jsonValue.GetString());
        }
    }
}

TargetVersion TargetVersion::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(TargetVersion);
}

bool operator!=(const TargetVersion& lhs, const TargetVersion& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
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
        if (lhs.m_pData->body != lhr.m_pData->body)
        {
            return true;
        }
        if (lhs.m_pData->signature != lhr.m_pData->signature)
        {
            return true;
        }
    }
    return false;
}

} }