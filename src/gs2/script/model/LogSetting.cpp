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

#include "LogSetting.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace script {

LogSetting::Data::Data(const Data& data) :
    detail::json::IModel(data),
    loggingNamespaceId(data.loggingNamespaceId)
{
}

void LogSetting::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "loggingNamespaceId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->loggingNamespaceId.emplace(jsonValue.GetString());
        }
    }
}

LogSetting LogSetting::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(LogSetting);
}

bool operator!=(const LogSetting& lhs, const LogSetting& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->loggingNamespaceId != lhr.m_pData->loggingNamespaceId)
        {
            return true;
        }
    }
    return false;
}

} }