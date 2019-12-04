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

#include "EzEvent.hpp"
#include <gs2/schedule/model/Event.hpp>


namespace gs2 { namespace ez { namespace schedule {

EzEvent::Data::Data(const Data& data) :
    Gs2Object(data),
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

EzEvent::Data::Data(const gs2::schedule::Event& event) :
    name(event.getName()),
    metadata(event.getMetadata()),
    scheduleType(event.getScheduleType()),
    repeatType(event.getRepeatType()),
    absoluteBegin(event.getAbsoluteBegin() ? *event.getAbsoluteBegin() : 0),
    absoluteEnd(event.getAbsoluteEnd() ? *event.getAbsoluteEnd() : 0),
    repeatBeginDayOfMonth(event.getRepeatBeginDayOfMonth() ? *event.getRepeatBeginDayOfMonth() : 0),
    repeatEndDayOfMonth(event.getRepeatEndDayOfMonth() ? *event.getRepeatEndDayOfMonth() : 0),
    repeatBeginDayOfWeek(event.getRepeatBeginDayOfWeek()),
    repeatEndDayOfWeek(event.getRepeatEndDayOfWeek()),
    repeatBeginHour(event.getRepeatBeginHour() ? *event.getRepeatBeginHour() : 0),
    repeatEndHour(event.getRepeatEndHour() ? *event.getRepeatEndHour() : 0),
    relativeTriggerName(event.getRelativeTriggerName()),
    relativeDuration(event.getRelativeDuration() ? *event.getRelativeDuration() : 0)
{
}

EzEvent::EzEvent(gs2::schedule::Event event) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(event)
{
}

EzEvent EzEvent::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzEvent);
}

gs2::schedule::Event EzEvent::ToModel() const
{
    gs2::schedule::Event event;
    event.setName(getName());
    event.setMetadata(getMetadata());
    event.setScheduleType(getScheduleType());
    event.setRepeatType(getRepeatType());
    event.setAbsoluteBegin(getAbsoluteBegin());
    event.setAbsoluteEnd(getAbsoluteEnd());
    event.setRepeatBeginDayOfMonth(getRepeatBeginDayOfMonth());
    event.setRepeatEndDayOfMonth(getRepeatEndDayOfMonth());
    event.setRepeatBeginDayOfWeek(getRepeatBeginDayOfWeek());
    event.setRepeatEndDayOfWeek(getRepeatEndDayOfWeek());
    event.setRepeatBeginHour(getRepeatBeginHour());
    event.setRepeatEndHour(getRepeatEndHour());
    event.setRelativeTriggerName(getRelativeTriggerName());
    event.setRelativeDuration(getRelativeDuration());
    return event;
}

}}}