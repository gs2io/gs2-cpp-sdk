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

#include "ScriptSetting.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace inbox {

ScriptSetting::Data::Data(const Data& data) :
    detail::json::IModel(data),
    triggerScriptId(data.triggerScriptId),
    doneTriggerScriptId(data.doneTriggerScriptId),
    doneTriggerQueueNamespaceId(data.doneTriggerQueueNamespaceId)
{
}

void ScriptSetting::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "triggerScriptId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->triggerScriptId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "doneTriggerScriptId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->doneTriggerScriptId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "doneTriggerQueueNamespaceId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->doneTriggerQueueNamespaceId.emplace(jsonValue.GetString());
        }
    }
}

ScriptSetting ScriptSetting::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(ScriptSetting);
}

bool operator!=(const ScriptSetting& lhs, const ScriptSetting& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->triggerScriptId != lhr.m_pData->triggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->doneTriggerScriptId != lhr.m_pData->doneTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->doneTriggerQueueNamespaceId != lhr.m_pData->doneTriggerQueueNamespaceId)
        {
            return true;
        }
    }
    return false;
}

} }