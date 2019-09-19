

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
    class Data : public gs2::Gs2Object
    {
    public:
        /** イベントの種類名 */
        gs2::optional<StringHolder> name;
        /** イベントの種類のメタデータ */
        gs2::optional<StringHolder> metadata;
        /** イベント期間の種類 */
        gs2::optional<StringHolder> scheduleType;
        /** イベントの開始日時 */
        gs2::optional<Int64> absoluteBegin;
        /** イベントの終了日時 */
        gs2::optional<Int64> absoluteEnd;
        /** イベントの開始トリガー */
        gs2::optional<StringHolder> relativeTriggerName;
        /** イベントの開催期間(秒) */
        gs2::optional<Int32> relativeDuration;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            name(data.name),
            metadata(data.metadata),
            scheduleType(data.scheduleType),
            absoluteBegin(data.absoluteBegin),
            absoluteEnd(data.absoluteEnd),
            relativeTriggerName(data.relativeTriggerName),
            relativeDuration(data.relativeDuration)
        {
        }

        Data(Data&& data) = default;

        Data(const gs2::schedule::Event& event) :
            name(event.getName()),
            metadata(event.getMetadata()),
            scheduleType(event.getScheduleType()),
            absoluteBegin(event.getAbsoluteBegin() ? *event.getAbsoluteBegin() : 0),
            absoluteEnd(event.getAbsoluteEnd() ? *event.getAbsoluteEnd() : 0),
            relativeTriggerName(event.getRelativeTriggerName()),
            relativeDuration(event.getRelativeDuration() ? *event.getRelativeDuration() : 0)
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzEvent() = default;
    EzEvent(const EzEvent& ezEvent) = default;
    EzEvent(EzEvent&& ezEvent) = default;
    ~EzEvent() = default;

    EzEvent(gs2::schedule::Event event) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(event)
    {}

    EzEvent& operator=(const EzEvent& ezEvent) = default;
    EzEvent& operator=(EzEvent&& ezEvent) = default;

    EzEvent deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzEvent);
    }

    gs2::schedule::Event ToModel() const
    {
        gs2::schedule::Event event;
        event.setName(getName());
        event.setMetadata(getMetadata());
        event.setScheduleType(getScheduleType());
        event.setAbsoluteBegin(getAbsoluteBegin());
        event.setAbsoluteEnd(getAbsoluteEnd());
        event.setRelativeTriggerName(getRelativeTriggerName());
        event.setRelativeDuration(getRelativeDuration());
        return event;
    }

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getName() const
    {
        return *ensureData().name;
    }

    const StringHolder& getMetadata() const
    {
        return *ensureData().metadata;
    }

    const StringHolder& getScheduleType() const
    {
        return *ensureData().scheduleType;
    }

    Int64 getAbsoluteBegin() const
    {
        return *ensureData().absoluteBegin;
    }

    Int64 getAbsoluteEnd() const
    {
        return *ensureData().absoluteEnd;
    }

    const StringHolder& getRelativeTriggerName() const
    {
        return *ensureData().relativeTriggerName;
    }

    Int32 getRelativeDuration() const
    {
        return *ensureData().relativeDuration;
    }

    // ========================================
    //   Setters
    // ========================================

    void setName(StringHolder name)
    {
        ensureData().name = std::move(name);
    }

    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata = std::move(metadata);
    }

    void setScheduleType(StringHolder scheduleType)
    {
        ensureData().scheduleType = std::move(scheduleType);
    }

    void setAbsoluteBegin(Int64 absoluteBegin)
    {
        ensureData().absoluteBegin = absoluteBegin;
    }

    void setAbsoluteEnd(Int64 absoluteEnd)
    {
        ensureData().absoluteEnd = absoluteEnd;
    }

    void setRelativeTriggerName(StringHolder relativeTriggerName)
    {
        ensureData().relativeTriggerName = std::move(relativeTriggerName);
    }

    void setRelativeDuration(Int32 relativeDuration)
    {
        ensureData().relativeDuration = relativeDuration;
    }

    EzEvent& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    EzEvent& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    EzEvent& withScheduleType(StringHolder scheduleType)
    {
        setScheduleType(std::move(scheduleType));
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

    EzEvent& withRelativeTriggerName(StringHolder relativeTriggerName)
    {
        setRelativeTriggerName(std::move(relativeTriggerName));
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