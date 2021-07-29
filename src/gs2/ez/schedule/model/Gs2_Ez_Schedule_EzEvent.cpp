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
    name(event.getName() ? *event.getName() : StringHolder()),
    metadata(event.getMetadata() ? *event.getMetadata() : StringHolder()),
    scheduleType(event.getScheduleType() ? *event.getScheduleType() : StringHolder()),
    repeatType(event.getRepeatType() ? *event.getRepeatType() : StringHolder()),
    absoluteBegin(event.getAbsoluteBegin() ? *event.getAbsoluteBegin() : 0),
    absoluteEnd(event.getAbsoluteEnd() ? *event.getAbsoluteEnd() : 0),
    repeatBeginDayOfMonth(event.getRepeatBeginDayOfMonth() ? *event.getRepeatBeginDayOfMonth() : 0),
    repeatEndDayOfMonth(event.getRepeatEndDayOfMonth() ? *event.getRepeatEndDayOfMonth() : 0),
    repeatBeginDayOfWeek(event.getRepeatBeginDayOfWeek() ? *event.getRepeatBeginDayOfWeek() : StringHolder()),
    repeatEndDayOfWeek(event.getRepeatEndDayOfWeek() ? *event.getRepeatEndDayOfWeek() : StringHolder()),
    repeatBeginHour(event.getRepeatBeginHour() ? *event.getRepeatBeginHour() : 0),
    repeatEndHour(event.getRepeatEndHour() ? *event.getRepeatEndHour() : 0),
    relativeTriggerName(event.getRelativeTriggerName() ? *event.getRelativeTriggerName() : StringHolder()),
    relativeDuration(event.getRelativeDuration() ? *event.getRelativeDuration() : 0)
{
}

EzEvent::Data::Data(const gs2::optional<gs2::schedule::Event>& event) :
    name(event && event->getName() ? *event->getName() : StringHolder()),
    metadata(event && event->getMetadata() ? *event->getMetadata() : StringHolder()),
    scheduleType(event && event->getScheduleType() ? *event->getScheduleType() : StringHolder()),
    repeatType(event && event->getRepeatType() ? *event->getRepeatType() : StringHolder()),
    absoluteBegin(event && event->getAbsoluteBegin() ? *event->getAbsoluteBegin() : 0),
    absoluteEnd(event && event->getAbsoluteEnd() ? *event->getAbsoluteEnd() : 0),
    repeatBeginDayOfMonth(event && event->getRepeatBeginDayOfMonth() ? *event->getRepeatBeginDayOfMonth() : 0),
    repeatEndDayOfMonth(event && event->getRepeatEndDayOfMonth() ? *event->getRepeatEndDayOfMonth() : 0),
    repeatBeginDayOfWeek(event && event->getRepeatBeginDayOfWeek() ? *event->getRepeatBeginDayOfWeek() : StringHolder()),
    repeatEndDayOfWeek(event && event->getRepeatEndDayOfWeek() ? *event->getRepeatEndDayOfWeek() : StringHolder()),
    repeatBeginHour(event && event->getRepeatBeginHour() ? *event->getRepeatBeginHour() : 0),
    repeatEndHour(event && event->getRepeatEndHour() ? *event->getRepeatEndHour() : 0),
    relativeTriggerName(event && event->getRelativeTriggerName() ? *event->getRelativeTriggerName() : StringHolder()),
    relativeDuration(event && event->getRelativeDuration() ? *event->getRelativeDuration() : 0)
{
}

EzEvent::EzEvent(gs2::schedule::Event event) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(event)
{
}

EzEvent::EzEvent(gs2::optional<gs2::schedule::Event> event) :
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