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

#include "DeadLetterJob.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace jobQueue {

DeadLetterJob::Data::Data(const Data& data) :
    detail::json::IModel(data),
    deadLetterJobId(data.deadLetterJobId),
    name(data.name),
    userId(data.userId),
    scriptId(data.scriptId),
    args(data.args),
    createdAt(data.createdAt),
    updatedAt(data.updatedAt)
{
    if (data.result)
    {
        result = data.result->deepCopy();
    }
}

void DeadLetterJob::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "deadLetterJobId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->deadLetterJobId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "name") == 0)
    {
        if (jsonValue.IsString())
        {
            this->name.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "userId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->userId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "scriptId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->scriptId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "args") == 0)
    {
        if (jsonValue.IsString())
        {
            this->args.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "result") == 0)
    {
        if (jsonValue.IsArray())
        {
            const auto& array = jsonValue.GetArray();
            this->result.emplace();
            for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                JobResultBody item;
                detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                *this->result += std::move(item);
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

DeadLetterJob DeadLetterJob::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DeadLetterJob);
}

bool operator!=(const DeadLetterJob& lhs, const DeadLetterJob& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->deadLetterJobId != lhr.m_pData->deadLetterJobId)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->scriptId != lhr.m_pData->scriptId)
        {
            return true;
        }
        if (lhs.m_pData->args != lhr.m_pData->args)
        {
            return true;
        }
        if (lhs.m_pData->result != lhr.m_pData->result)
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