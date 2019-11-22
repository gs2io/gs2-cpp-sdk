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

#include "CompletedQuestList.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace quest {

CompletedQuestList::Data::Data(const Data& data) :
    detail::json::IModel(data),
    completedQuestListId(data.completedQuestListId),
    userId(data.userId),
    questGroupName(data.questGroupName),
    createdAt(data.createdAt),
    updatedAt(data.updatedAt)
{
    if (data.completeQuestNames)
    {
        completeQuestNames = data.completeQuestNames->deepCopy();
    }
}

void CompletedQuestList::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "completedQuestListId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->completedQuestListId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "userId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->userId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "questGroupName") == 0)
    {
        if (jsonValue.IsString())
        {
            this->questGroupName.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "completeQuestNames") == 0)
    {
        if (jsonValue.IsArray())
        {
            const auto& array = jsonValue.GetArray();
            this->completeQuestNames.emplace();
            for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                if (json->IsString())
                {
                    auto valueStr = json->GetString();
                    StringHolder stringHolder(valueStr);
                    *this->completeQuestNames += std::move(stringHolder);
                }
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

CompletedQuestList CompletedQuestList::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CompletedQuestList);
}

bool operator!=(const CompletedQuestList& lhs, const CompletedQuestList& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->completedQuestListId != lhr.m_pData->completedQuestListId)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->questGroupName != lhr.m_pData->questGroupName)
        {
            return true;
        }
        if (lhs.m_pData->completeQuestNames != lhr.m_pData->completeQuestNames)
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