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

#include "Prize.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace lottery {

Prize::Data::Data(const Data& data) :
    detail::json::IModel(data),
    prizeId(data.prizeId),
    type(data.type),
    prizeTableName(data.prizeTableName),
    weight(data.weight)
{
    if (data.acquireActions)
    {
        acquireActions = data.acquireActions->deepCopy();
    }
}

void Prize::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "prizeId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->prizeId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "type") == 0)
    {
        if (jsonValue.IsString())
        {
            this->type.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "acquireActions") == 0)
    {
        if (jsonValue.IsArray())
        {
            const auto& array = jsonValue.GetArray();
            this->acquireActions.emplace();
            for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                AcquireAction item;
                detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                *this->acquireActions += std::move(item);
            }
        }
    }
    else if (std::strcmp(name_, "prizeTableName") == 0)
    {
        if (jsonValue.IsString())
        {
            this->prizeTableName.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "weight") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->weight = jsonValue.GetInt();
        }
    }
}

Prize Prize::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Prize);
}

bool operator!=(const Prize& lhs, const Prize& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->prizeId != lhr.m_pData->prizeId)
        {
            return true;
        }
        if (lhs.m_pData->type != lhr.m_pData->type)
        {
            return true;
        }
        if (lhs.m_pData->acquireActions != lhr.m_pData->acquireActions)
        {
            return true;
        }
        if (lhs.m_pData->prizeTableName != lhr.m_pData->prizeTableName)
        {
            return true;
        }
        if (lhs.m_pData->weight != lhr.m_pData->weight)
        {
            return true;
        }
    }
    return false;
}

} }