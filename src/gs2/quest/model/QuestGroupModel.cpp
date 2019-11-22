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

#include "QuestGroupModel.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace quest {

QuestGroupModel::Data::Data(const Data& data) :
    detail::json::IModel(data),
    questGroupModelId(data.questGroupModelId),
    name(data.name),
    metadata(data.metadata),
    challengePeriodEventId(data.challengePeriodEventId)
{
    if (data.quests)
    {
        quests = data.quests->deepCopy();
    }
}

void QuestGroupModel::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "questGroupModelId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->questGroupModelId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "name") == 0)
    {
        if (jsonValue.IsString())
        {
            this->name.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "metadata") == 0)
    {
        if (jsonValue.IsString())
        {
            this->metadata.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "quests") == 0)
    {
        if (jsonValue.IsArray())
        {
            const auto& array = jsonValue.GetArray();
            this->quests.emplace();
            for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                QuestModel item;
                detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                *this->quests += std::move(item);
            }
        }
    }
    else if (std::strcmp(name_, "challengePeriodEventId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->challengePeriodEventId.emplace(jsonValue.GetString());
        }
    }
}

QuestGroupModel QuestGroupModel::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(QuestGroupModel);
}

bool operator!=(const QuestGroupModel& lhs, const QuestGroupModel& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->questGroupModelId != lhr.m_pData->questGroupModelId)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->metadata != lhr.m_pData->metadata)
        {
            return true;
        }
        if (lhs.m_pData->quests != lhr.m_pData->quests)
        {
            return true;
        }
        if (lhs.m_pData->challengePeriodEventId != lhr.m_pData->challengePeriodEventId)
        {
            return true;
        }
    }
    return false;
}

} }