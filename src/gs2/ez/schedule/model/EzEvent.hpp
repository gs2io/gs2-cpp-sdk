

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

#ifndef GS2_EZ_SCHEDULE_MODEL_EZEVENT_HPP_
#define GS2_EZ_SCHEDULE_MODEL_EZEVENT_HPP_

#include <gs2/schedule/model/Event.hpp>


namespace gs2 { namespace ez { namespace schedule {

class EzEvent : public gs2::Gs2Object
{
private:
    /** イベントの種類名 */
    gs2::optional<StringHolder> m_Name;
    /** イベントの種類のメタデータ */
    gs2::optional<StringHolder> m_Metadata;
    /** イベント期間の種類 */
    gs2::optional<StringHolder> m_ScheduleType;
    /** イベントの開始日時 */
    gs2::optional<Int64> m_AbsoluteBegin;
    /** イベントの終了日時 */
    gs2::optional<Int64> m_AbsoluteEnd;
    /** イベントの開始トリガー */
    gs2::optional<StringHolder> m_RelativeTriggerName;
    /** イベントの開催期間(秒) */
    gs2::optional<Int32> m_RelativeDuration;

public:
    EzEvent() = default;

    EzEvent(gs2::schedule::Event event) :
        m_Name(event.getName()),
        m_Metadata(event.getMetadata()),
        m_ScheduleType(event.getScheduleType()),
        m_AbsoluteBegin(event.getAbsoluteBegin() ? *event.getAbsoluteBegin() : 0),
        m_AbsoluteEnd(event.getAbsoluteEnd() ? *event.getAbsoluteEnd() : 0),
        m_RelativeTriggerName(event.getRelativeTriggerName()),
        m_RelativeDuration(event.getRelativeDuration() ? *event.getRelativeDuration() : 0)
    {
    }

    gs2::schedule::Event ToModel() const
    {
        gs2::schedule::Event event;
        event.setName(*m_Name);
        event.setMetadata(*m_Metadata);
        event.setScheduleType(*m_ScheduleType);
        event.setAbsoluteBegin(*m_AbsoluteBegin);
        event.setAbsoluteEnd(*m_AbsoluteEnd);
        event.setRelativeTriggerName(*m_RelativeTriggerName);
        event.setRelativeDuration(*m_RelativeDuration);
        return event;
    }

    // ========================================
    //   Getters
    // ========================================

    const gs2::StringHolder& getName() const
    {
        return *m_Name;
    }

    gs2::StringHolder& getName()
    {
        return *m_Name;
    }

    const gs2::StringHolder& getMetadata() const
    {
        return *m_Metadata;
    }

    gs2::StringHolder& getMetadata()
    {
        return *m_Metadata;
    }

    const gs2::StringHolder& getScheduleType() const
    {
        return *m_ScheduleType;
    }

    gs2::StringHolder& getScheduleType()
    {
        return *m_ScheduleType;
    }

    Int64 getAbsoluteBegin() const
    {
        return *m_AbsoluteBegin;
    }

    Int64 getAbsoluteEnd() const
    {
        return *m_AbsoluteEnd;
    }

    const gs2::StringHolder& getRelativeTriggerName() const
    {
        return *m_RelativeTriggerName;
    }

    gs2::StringHolder& getRelativeTriggerName()
    {
        return *m_RelativeTriggerName;
    }

    Int32 getRelativeDuration() const
    {
        return *m_RelativeDuration;
    }

    // ========================================
    //   Setters
    // ========================================

    void setName(Char* name)
    {
        m_Name.emplace(name);
    }

    void setMetadata(Char* metadata)
    {
        m_Metadata.emplace(metadata);
    }

    void setScheduleType(Char* scheduleType)
    {
        m_ScheduleType.emplace(scheduleType);
    }

    void setAbsoluteBegin(Int64 absoluteBegin)
    {
        m_AbsoluteBegin = absoluteBegin;
    }

    void setAbsoluteEnd(Int64 absoluteEnd)
    {
        m_AbsoluteEnd = absoluteEnd;
    }

    void setRelativeTriggerName(Char* relativeTriggerName)
    {
        m_RelativeTriggerName.emplace(relativeTriggerName);
    }

    void setRelativeDuration(Int32 relativeDuration)
    {
        m_RelativeDuration = relativeDuration;
    }

    EzEvent& withName(Char* name)
    {
        setName(name);
        return *this;
    }

    EzEvent& withMetadata(Char* metadata)
    {
        setMetadata(metadata);
        return *this;
    }

    EzEvent& withScheduleType(Char* scheduleType)
    {
        setScheduleType(scheduleType);
        return *this;
    }

    EzEvent& withAbsoluteBegin(Int64 absoluteBegin)
    {
        setAbsoluteBegin(absoluteBegin);
        return *this;
    }

    EzEvent& withAbsoluteEnd(Int64 absoluteEnd)
    {
        setAbsoluteEnd(absoluteEnd);
        return *this;
    }

    EzEvent& withRelativeTriggerName(Char* relativeTriggerName)
    {
        setRelativeTriggerName(relativeTriggerName);
        return *this;
    }

    EzEvent& withRelativeDuration(Int32 relativeDuration)
    {
        setRelativeDuration(relativeDuration);
        return *this;
    }
};

}}}

#endif //GS2_EZ_SCHEDULE_EZEVENT_HPP_