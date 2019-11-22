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

#include "Probability.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace lottery {

Probability::Data::Data(const Data& data) :
    detail::json::IModel(data),
    rate(data.rate)
{
    if (data.prize)
    {
        prize = data.prize->deepCopy();
    }
}

void Probability::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "prize") == 0)
    {
        if (jsonValue.IsObject())
        {
            const auto& jsonObject = detail::json::getObject(jsonValue);
            this->prize.emplace();
            detail::json::JsonParser::parse(&this->prize->getModel(), jsonObject);
        }
    }
    else if (std::strcmp(name_, "rate") == 0)
    {
        if (jsonValue.IsFloat())
        {
            this->rate = jsonValue.GetFloat();
        }
    }
}

Probability Probability::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Probability);
}

bool operator!=(const Probability& lhs, const Probability& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->prize != lhr.m_pData->prize)
        {
            return true;
        }
        if (lhs.m_pData->rate != lhr.m_pData->rate)
        {
            return true;
        }
    }
    return false;
}

} }