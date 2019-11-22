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

#include "DistributorModelMaster.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace distributor {

DistributorModelMaster::Data::Data(const Data& data) :
    detail::json::IModel(data),
    distributorModelId(data.distributorModelId),
    name(data.name),
    description(data.description),
    metadata(data.metadata),
    inboxNamespaceId(data.inboxNamespaceId),
    createdAt(data.createdAt),
    updatedAt(data.updatedAt)
{
    if (data.whiteListTargetIds)
    {
        whiteListTargetIds = data.whiteListTargetIds->deepCopy();
    }
}

void DistributorModelMaster::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "distributorModelId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->distributorModelId.emplace(jsonValue.GetString());
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
    else if (std::strcmp(name_, "inboxNamespaceId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->inboxNamespaceId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "whiteListTargetIds") == 0)
    {
        if (jsonValue.IsArray())
        {
            const auto& array = jsonValue.GetArray();
            this->whiteListTargetIds.emplace();
            for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                if (json->IsString())
                {
                    auto valueStr = json->GetString();
                    StringHolder stringHolder(valueStr);
                    *this->whiteListTargetIds += std::move(stringHolder);
                }
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

DistributorModelMaster DistributorModelMaster::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DistributorModelMaster);
}

bool operator!=(const DistributorModelMaster& lhs, const DistributorModelMaster& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->distributorModelId != lhr.m_pData->distributorModelId)
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
        if (lhs.m_pData->inboxNamespaceId != lhr.m_pData->inboxNamespaceId)
        {
            return true;
        }
        if (lhs.m_pData->whiteListTargetIds != lhr.m_pData->whiteListTargetIds)
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