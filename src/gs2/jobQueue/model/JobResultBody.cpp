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

#include "JobResultBody.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace jobQueue {

JobResultBody::Data::Data(const Data& data) :
    detail::json::IModel(data),
    tryNumber(data.tryNumber),
    statusCode(data.statusCode),
    result(data.result),
    tryAt(data.tryAt)
{
}

void JobResultBody::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "tryNumber") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->tryNumber = jsonValue.GetInt();
        }
    }
    else if (std::strcmp(name_, "statusCode") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->statusCode = jsonValue.GetInt();
        }
    }
    else if (std::strcmp(name_, "result") == 0)
    {
        if (jsonValue.IsString())
        {
            this->result.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "tryAt") == 0)
    {
        if (jsonValue.IsInt64())
        {
            this->tryAt = jsonValue.GetInt64();
        }
    }
}

JobResultBody JobResultBody::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(JobResultBody);
}

bool operator!=(const JobResultBody& lhs, const JobResultBody& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->tryNumber != lhr.m_pData->tryNumber)
        {
            return true;
        }
        if (lhs.m_pData->statusCode != lhr.m_pData->statusCode)
        {
            return true;
        }
        if (lhs.m_pData->result != lhr.m_pData->result)
        {
            return true;
        }
        if (lhs.m_pData->tryAt != lhr.m_pData->tryAt)
        {
            return true;
        }
    }
    return false;
}

} }