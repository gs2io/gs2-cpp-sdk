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

#include "Reward.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace quest {

Reward::Data::Data(const Data& data) :
    detail::json::IModel(data),
    action(data.action),
    request(data.request),
    itemId(data.itemId),
    value(data.value)
{
}

void Reward::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "action") == 0)
    {
        if (jsonValue.IsString())
        {
            this->action.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "request") == 0)
    {
        if (jsonValue.IsString())
        {
            this->request.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "itemId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->itemId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "value") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->value = jsonValue.GetInt();
        }
    }
}

Reward Reward::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Reward);
}

bool operator!=(const Reward& lhs, const Reward& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->action != lhr.m_pData->action)
        {
            return true;
        }
        if (lhs.m_pData->request != lhr.m_pData->request)
        {
            return true;
        }
        if (lhs.m_pData->itemId != lhr.m_pData->itemId)
        {
            return true;
        }
        if (lhs.m_pData->value != lhr.m_pData->value)
        {
            return true;
        }
    }
    return false;
}

} }