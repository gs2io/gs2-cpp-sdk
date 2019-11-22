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

#include "Namespace.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace log {

Namespace::Data::Data(const Data& data) :
    detail::json::IModel(data),
    namespaceId(data.namespaceId),
    ownerId(data.ownerId),
    name(data.name),
    description(data.description),
    type(data.type),
    gcpCredentialJson(data.gcpCredentialJson),
    bigQueryDatasetName(data.bigQueryDatasetName),
    logExpireDays(data.logExpireDays),
    awsRegion(data.awsRegion),
    awsAccessKeyId(data.awsAccessKeyId),
    awsSecretAccessKey(data.awsSecretAccessKey),
    firehoseStreamName(data.firehoseStreamName),
    createdAt(data.createdAt),
    updatedAt(data.updatedAt)
{
}

void Namespace::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "namespaceId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->namespaceId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "ownerId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->ownerId.emplace(jsonValue.GetString());
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
    else if (std::strcmp(name_, "type") == 0)
    {
        if (jsonValue.IsString())
        {
            this->type.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "gcpCredentialJson") == 0)
    {
        if (jsonValue.IsString())
        {
            this->gcpCredentialJson.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "bigQueryDatasetName") == 0)
    {
        if (jsonValue.IsString())
        {
            this->bigQueryDatasetName.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "logExpireDays") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->logExpireDays = jsonValue.GetInt();
        }
    }
    else if (std::strcmp(name_, "awsRegion") == 0)
    {
        if (jsonValue.IsString())
        {
            this->awsRegion.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "awsAccessKeyId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->awsAccessKeyId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "awsSecretAccessKey") == 0)
    {
        if (jsonValue.IsString())
        {
            this->awsSecretAccessKey.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "firehoseStreamName") == 0)
    {
        if (jsonValue.IsString())
        {
            this->firehoseStreamName.emplace(jsonValue.GetString());
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

Namespace Namespace::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Namespace);
}

bool operator!=(const Namespace& lhs, const Namespace& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->namespaceId != lhr.m_pData->namespaceId)
        {
            return true;
        }
        if (lhs.m_pData->ownerId != lhr.m_pData->ownerId)
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
        if (lhs.m_pData->type != lhr.m_pData->type)
        {
            return true;
        }
        if (lhs.m_pData->gcpCredentialJson != lhr.m_pData->gcpCredentialJson)
        {
            return true;
        }
        if (lhs.m_pData->bigQueryDatasetName != lhr.m_pData->bigQueryDatasetName)
        {
            return true;
        }
        if (lhs.m_pData->logExpireDays != lhr.m_pData->logExpireDays)
        {
            return true;
        }
        if (lhs.m_pData->awsRegion != lhr.m_pData->awsRegion)
        {
            return true;
        }
        if (lhs.m_pData->awsAccessKeyId != lhr.m_pData->awsAccessKeyId)
        {
            return true;
        }
        if (lhs.m_pData->awsSecretAccessKey != lhr.m_pData->awsSecretAccessKey)
        {
            return true;
        }
        if (lhs.m_pData->firehoseStreamName != lhr.m_pData->firehoseStreamName)
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