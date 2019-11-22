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

#include "AccessLog.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace log {

AccessLog::Data::Data(const Data& data) :
    detail::json::IModel(data),
    timestamp(data.timestamp),
    requestId(data.requestId),
    service(data.service),
    method(data.method),
    userId(data.userId),
    request(data.request),
    result(data.result)
{
}

void AccessLog::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "timestamp") == 0)
    {
        if (jsonValue.IsInt64())
        {
            this->timestamp = jsonValue.GetInt64();
        }
    }
    else if (std::strcmp(name_, "requestId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->requestId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "service") == 0)
    {
        if (jsonValue.IsString())
        {
            this->service.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "method") == 0)
    {
        if (jsonValue.IsString())
        {
            this->method.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "userId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->userId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "request") == 0)
    {
        if (jsonValue.IsString())
        {
            this->request.emplace(jsonValue.GetString());
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

AccessLog AccessLog::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(AccessLog);
}

bool operator!=(const AccessLog& lhs, const AccessLog& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->timestamp != lhr.m_pData->timestamp)
        {
            return true;
        }
        if (lhs.m_pData->requestId != lhr.m_pData->requestId)
        {
            return true;
        }
        if (lhs.m_pData->service != lhr.m_pData->service)
        {
            return true;
        }
        if (lhs.m_pData->method != lhr.m_pData->method)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->request != lhr.m_pData->request)
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