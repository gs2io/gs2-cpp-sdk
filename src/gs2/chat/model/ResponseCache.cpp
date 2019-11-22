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

#include "ResponseCache.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace chat {

ResponseCache::Data::Data(const Data& data) :
    detail::json::IModel(data),
    region(data.region),
    ownerId(data.ownerId),
    responseCacheId(data.responseCacheId),
    requestHash(data.requestHash),
    result(data.result)
{
}

void ResponseCache::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
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
    else if (std::strcmp(name_, "responseCacheId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->responseCacheId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "requestHash") == 0)
    {
        if (jsonValue.IsString())
        {
            this->requestHash.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "result") == 0)
    {
        if (jsonValue.IsString())
        {
            this->result.emplace(jsonValue.GetString());
        }
    }
}

ResponseCache ResponseCache::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(ResponseCache);
}

bool operator!=(const ResponseCache& lhs, const ResponseCache& lhr)
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
        if (lhs.m_pData->responseCacheId != lhr.m_pData->responseCacheId)
        {
            return true;
        }
        if (lhs.m_pData->requestHash != lhr.m_pData->requestHash)
        {
            return true;
        }
        if (lhs.m_pData->result != lhr.m_pData->result)
        {
            return true;
        }
    }
    return false;
}

} }