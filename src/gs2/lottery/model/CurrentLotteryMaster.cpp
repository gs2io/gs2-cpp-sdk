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

#include "CurrentLotteryMaster.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace lottery {

CurrentLotteryMaster::Data::Data(const Data& data) :
    detail::json::IModel(data),
    namespaceName(data.namespaceName),
    settings(data.settings)
{
}

void CurrentLotteryMaster::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "namespaceName") == 0)
    {
        if (jsonValue.IsString())
        {
            this->namespaceName.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "settings") == 0)
    {
        if (jsonValue.IsString())
        {
            this->settings.emplace(jsonValue.GetString());
        }
    }
}

CurrentLotteryMaster CurrentLotteryMaster::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CurrentLotteryMaster);
}

bool operator!=(const CurrentLotteryMaster& lhs, const CurrentLotteryMaster& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->namespaceName != lhr.m_pData->namespaceName)
        {
            return true;
        }
        if (lhs.m_pData->settings != lhr.m_pData->settings)
        {
            return true;
        }
    }
    return false;
}

} }