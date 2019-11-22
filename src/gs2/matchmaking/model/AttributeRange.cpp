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

#include "AttributeRange.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace matchmaking {

AttributeRange::Data::Data(const Data& data) :
    detail::json::IModel(data),
    name(data.name),
    min(data.min),
    max(data.max)
{
}

void AttributeRange::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "name") == 0)
    {
        if (jsonValue.IsString())
        {
            this->name.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "min") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->min = jsonValue.GetInt();
        }
    }
    else if (std::strcmp(name_, "max") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->max = jsonValue.GetInt();
        }
    }
}

AttributeRange AttributeRange::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(AttributeRange);
}

bool operator!=(const AttributeRange& lhs, const AttributeRange& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->min != lhr.m_pData->min)
        {
            return true;
        }
        if (lhs.m_pData->max != lhr.m_pData->max)
        {
            return true;
        }
    }
    return false;
}

} }