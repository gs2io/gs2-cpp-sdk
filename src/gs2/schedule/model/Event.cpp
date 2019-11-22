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

#include "Event.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace schedule {

Event::Data::Data(const Data& data) :
    detail::json::IModel(data),
    eventId(data.eventId),
    name(data.name),
    metadata(data.metadata),
    scheduleType(data.scheduleType),
    repeatType(data.repeatType),
    absoluteBegin(data.absoluteBegin),
    absoluteEnd(data.absoluteEnd),
    repeatBeginDayOfMonth(data.repeatBeginDayOfMonth),
    repeatEndDayOfMonth(data.repeatEndDayOfMonth),
    repeatBeginDayOfWeek(data.repeatBeginDayOfWeek),
    repeatEndDayOfWeek(data.repeatEndDayOfWeek),
    repeatBeginHour(data.repeatBeginHour),
    repeatEndHour(data.repeatEndHour),
    relativeTriggerName(data.relativeTriggerName),
    relativeDuration(data.relativeDuration)
{
}

void Event::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "eventId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->eventId.emplace(jsonValue.GetString());
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
    else if (std::strcmp(name_, "scheduleType") == 0)
    {
        if (jsonValue.IsString())
        {
            this->scheduleType.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "repeatType") == 0)
    {
        if (jsonValue.IsString())
        {
            this->repeatType.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "absoluteBegin") == 0)
    {
        if (jsonValue.IsInt64())
        {
            this->absoluteBegin = jsonValue.GetInt64();
        }
    }
    else if (std::strcmp(name_, "absoluteEnd") == 0)
    {
        if (jsonValue.IsInt64())
        {
            this->absoluteEnd = jsonValue.GetInt64();
        }
    }
    else if (std::strcmp(name_, "repeatBeginDayOfMonth") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->repeatBeginDayOfMonth = jsonValue.GetInt();
        }
    }
    else if (std::strcmp(name_, "repeatEndDayOfMonth") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->repeatEndDayOfMonth = jsonValue.GetInt();
        }
    }
    else if (std::strcmp(name_, "repeatBeginDayOfWeek") == 0)
    {
        if (jsonValue.IsString())
        {
            this->repeatBeginDayOfWeek.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "repeatEndDayOfWeek") == 0)
    {
        if (jsonValue.IsString())
        {
            this->repeatEndDayOfWeek.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "repeatBeginHour") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->repeatBeginHour = jsonValue.GetInt();
        }
    }
    else if (std::strcmp(name_, "repeatEndHour") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->repeatEndHour = jsonValue.GetInt();
        }
    }
    else if (std::strcmp(name_, "relativeTriggerName") == 0)
    {
        if (jsonValue.IsString())
        {
            this->relativeTriggerName.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "relativeDuration") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->relativeDuration = jsonValue.GetInt();
        }
    }
}

Event Event::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Event);
}

bool operator!=(const Event& lhs, const Event& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->eventId != lhr.m_pData->eventId)
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
        if (lhs.m_pData->scheduleType != lhr.m_pData->scheduleType)
        {
            return true;
        }
        if (lhs.m_pData->repeatType != lhr.m_pData->repeatType)
        {
            return true;
        }
        if (lhs.m_pData->absoluteBegin != lhr.m_pData->absoluteBegin)
        {
            return true;
        }
        if (lhs.m_pData->absoluteEnd != lhr.m_pData->absoluteEnd)
        {
            return true;
        }
        if (lhs.m_pData->repeatBeginDayOfMonth != lhr.m_pData->repeatBeginDayOfMonth)
        {
            return true;
        }
        if (lhs.m_pData->repeatEndDayOfMonth != lhr.m_pData->repeatEndDayOfMonth)
        {
            return true;
        }
        if (lhs.m_pData->repeatBeginDayOfWeek != lhr.m_pData->repeatBeginDayOfWeek)
        {
            return true;
        }
        if (lhs.m_pData->repeatEndDayOfWeek != lhr.m_pData->repeatEndDayOfWeek)
        {
            return true;
        }
        if (lhs.m_pData->repeatBeginHour != lhr.m_pData->repeatBeginHour)
        {
            return true;
        }
        if (lhs.m_pData->repeatEndHour != lhr.m_pData->repeatEndHour)
        {
            return true;
        }
        if (lhs.m_pData->relativeTriggerName != lhr.m_pData->relativeTriggerName)
        {
            return true;
        }
        if (lhs.m_pData->relativeDuration != lhr.m_pData->relativeDuration)
        {
            return true;
        }
    }
    return false;
}

} }