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

#include "WorkingResource.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace deploy {

WorkingResource::Data::Data(const Data& data) :
    detail::json::IModel(data),
    resourceId(data.resourceId),
    context(data.context),
    type(data.type),
    name(data.name),
    request(data.request),
    rollbackContext(data.rollbackContext),
    rollbackRequest(data.rollbackRequest),
    workId(data.workId),
    createdAt(data.createdAt),
    updatedAt(data.updatedAt)
{
    if (data.after)
    {
        after = data.after->deepCopy();
    }
    if (data.rollbackAfter)
    {
        rollbackAfter = data.rollbackAfter->deepCopy();
    }
    if (data.outputFields)
    {
        outputFields = data.outputFields->deepCopy();
    }
}

void WorkingResource::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "resourceId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->resourceId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "context") == 0)
    {
        if (jsonValue.IsString())
        {
            this->context.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "type") == 0)
    {
        if (jsonValue.IsString())
        {
            this->type.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "name") == 0)
    {
        if (jsonValue.IsString())
        {
            this->name.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "request") == 0)
    {
        if (jsonValue.IsString())
        {
            this->request.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "after") == 0)
    {
        if (jsonValue.IsArray())
        {
            const auto& array = jsonValue.GetArray();
            this->after.emplace();
            for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                if (json->IsString())
                {
                    auto valueStr = json->GetString();
                    StringHolder stringHolder(valueStr);
                    *this->after += std::move(stringHolder);
                }
            }
        }
    }
    else if (std::strcmp(name_, "rollbackContext") == 0)
    {
        if (jsonValue.IsString())
        {
            this->rollbackContext.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "rollbackRequest") == 0)
    {
        if (jsonValue.IsString())
        {
            this->rollbackRequest.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "rollbackAfter") == 0)
    {
        if (jsonValue.IsArray())
        {
            const auto& array = jsonValue.GetArray();
            this->rollbackAfter.emplace();
            for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                if (json->IsString())
                {
                    auto valueStr = json->GetString();
                    StringHolder stringHolder(valueStr);
                    *this->rollbackAfter += std::move(stringHolder);
                }
            }
        }
    }
    else if (std::strcmp(name_, "outputFields") == 0)
    {
        if (jsonValue.IsArray())
        {
            const auto& array = jsonValue.GetArray();
            this->outputFields.emplace();
            for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                OutputField item;
                detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                *this->outputFields += std::move(item);
            }
        }
    }
    else if (std::strcmp(name_, "workId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->workId.emplace(jsonValue.GetString());
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

WorkingResource WorkingResource::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(WorkingResource);
}

bool operator!=(const WorkingResource& lhs, const WorkingResource& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->resourceId != lhr.m_pData->resourceId)
        {
            return true;
        }
        if (lhs.m_pData->context != lhr.m_pData->context)
        {
            return true;
        }
        if (lhs.m_pData->type != lhr.m_pData->type)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->request != lhr.m_pData->request)
        {
            return true;
        }
        if (lhs.m_pData->after != lhr.m_pData->after)
        {
            return true;
        }
        if (lhs.m_pData->rollbackContext != lhr.m_pData->rollbackContext)
        {
            return true;
        }
        if (lhs.m_pData->rollbackRequest != lhr.m_pData->rollbackRequest)
        {
            return true;
        }
        if (lhs.m_pData->rollbackAfter != lhr.m_pData->rollbackAfter)
        {
            return true;
        }
        if (lhs.m_pData->outputFields != lhr.m_pData->outputFields)
        {
            return true;
        }
        if (lhs.m_pData->workId != lhr.m_pData->workId)
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