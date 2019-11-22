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

#include "AttachSecurityPolicy.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace identifier {

AttachSecurityPolicy::Data::Data(const Data& data) :
    detail::json::IModel(data),
    userId(data.userId),
    attachedAt(data.attachedAt)
{
    if (data.securityPolicyIds)
    {
        securityPolicyIds = data.securityPolicyIds->deepCopy();
    }
}

void AttachSecurityPolicy::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "userId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->userId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "securityPolicyIds") == 0)
    {
        if (jsonValue.IsArray())
        {
            const auto& array = jsonValue.GetArray();
            this->securityPolicyIds.emplace();
            for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                if (json->IsString())
                {
                    auto valueStr = json->GetString();
                    StringHolder stringHolder(valueStr);
                    *this->securityPolicyIds += std::move(stringHolder);
                }
            }
        }
    }
    else if (std::strcmp(name_, "attachedAt") == 0)
    {
        if (jsonValue.IsInt64())
        {
            this->attachedAt = jsonValue.GetInt64();
        }
    }
}

AttachSecurityPolicy AttachSecurityPolicy::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(AttachSecurityPolicy);
}

bool operator!=(const AttachSecurityPolicy& lhs, const AttachSecurityPolicy& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->securityPolicyIds != lhr.m_pData->securityPolicyIds)
        {
            return true;
        }
        if (lhs.m_pData->attachedAt != lhr.m_pData->attachedAt)
        {
            return true;
        }
    }
    return false;
}

} }