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

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace schedule {

class Event;

}

namespace ez { namespace schedule {

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
        /** 繰り返しの種類 */
        gs2::optional<StringHolder> repeatType;
        /** イベントの開始日時 */
        gs2::optional<Int64> absoluteBegin;
        /** イベントの終了日時 */
        gs2::optional<Int64> absoluteEnd;
        /** イベントの繰り返し開始日 */
        gs2::optional<Int32> repeatBeginDayOfMonth;
        /** イベントの繰り返し終了日 */
        gs2::optional<Int32> repeatEndDayOfMonth;
        /** イベントの繰り返し開始曜日 */
        gs2::optional<StringHolder> repeatBeginDayOfWeek;
        /** イベントの繰り返し終了曜日 */
        gs2::optional<StringHolder> repeatEndDayOfWeek;
        /** イベントの繰り返し開始時間 */
        gs2::optional<Int32> repeatBeginHour;
        /** イベントの繰り返し終了時間 */
        gs2::optional<Int32> repeatEndHour;
        /** イベントの開始トリガー */
        gs2::optional<StringHolder> relativeTriggerName;
        /** イベントの開催期間(秒) */
        gs2::optional<Int32> relativeDuration;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::schedule::Event& event);
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

    EzEvent(gs2::schedule::Event event);

    EzEvent& operator=(const EzEvent& ezEvent) = default;
    EzEvent& operator=(EzEvent&& ezEvent) = default;

    EzEvent deepCopy() const;

    gs2::schedule::Event ToModel() const;

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

    const StringHolder& getRepeatType() const
    {
        return *ensureData().repeatType;
    }

    Int64 getAbsoluteBegin() const
    {
        return *ensureData().absoluteBegin;
    }

    Int64 getAbsoluteEnd() const
    {
        return *ensureData().absoluteEnd;
    }

    Int32 getRepeatBeginDayOfMonth() const
    {
        return *ensureData().repeatBeginDayOfMonth;
    }

    Int32 getRepeatEndDayOfMonth() const
    {
        return *ensureData().repeatEndDayOfMonth;
    }

    const StringHolder& getRepeatBeginDayOfWeek() const
    {
        return *ensureData().repeatBeginDayOfWeek;
    }

    const StringHolder& getRepeatEndDayOfWeek() const
    {
        return *ensureData().repeatEndDayOfWeek;
    }

    Int32 getRepeatBeginHour() const
    {
        return *ensureData().repeatBeginHour;
    }

    Int32 getRepeatEndHour() const
    {
        return *ensureData().repeatEndHour;
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

    void setRepeatType(StringHolder repeatType)
    {
        ensureData().repeatType = std::move(repeatType);
    }

    void setAbsoluteBegin(Int64 absoluteBegin)
    {
        ensureData().absoluteBegin = absoluteBegin;
    }

    void setAbsoluteEnd(Int64 absoluteEnd)
    {
        ensureData().absoluteEnd = absoluteEnd;
    }

    void setRepeatBeginDayOfMonth(Int32 repeatBeginDayOfMonth)
    {
        ensureData().repeatBeginDayOfMonth = repeatBeginDayOfMonth;
    }

    void setRepeatEndDayOfMonth(Int32 repeatEndDayOfMonth)
    {
        ensureData().repeatEndDayOfMonth = repeatEndDayOfMonth;
    }

    void setRepeatBeginDayOfWeek(StringHolder repeatBeginDayOfWeek)
    {
        ensureData().repeatBeginDayOfWeek = std::move(repeatBeginDayOfWeek);
    }

    void setRepeatEndDayOfWeek(StringHolder repeatEndDayOfWeek)
    {
        ensureData().repeatEndDayOfWeek = std::move(repeatEndDayOfWeek);
    }

    void setRepeatBeginHour(Int32 repeatBeginHour)
    {
        ensureData().repeatBeginHour = repeatBeginHour;
    }

    void setRepeatEndHour(Int32 repeatEndHour)
    {
        ensureData().repeatEndHour = repeatEndHour;
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

    EzEvent& withRepeatType(StringHolder repeatType)
    {
        setRepeatType(std::move(repeatType));
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

    EzEvent& withRepeatBeginDayOfMonth(Int32 repeatBeginDayOfMonth)
    {
        setRepeatBeginDayOfMonth(repeatBeginDayOfMonth);
        return *this;
    }

    EzEvent& withRepeatEndDayOfMonth(Int32 repeatEndDayOfMonth)
    {
        setRepeatEndDayOfMonth(repeatEndDayOfMonth);
        return *this;
    }

    EzEvent& withRepeatBeginDayOfWeek(StringHolder repeatBeginDayOfWeek)
    {
        setRepeatBeginDayOfWeek(std::move(repeatBeginDayOfWeek));
        return *this;
    }

    EzEvent& withRepeatEndDayOfWeek(StringHolder repeatEndDayOfWeek)
    {
        setRepeatEndDayOfWeek(std::move(repeatEndDayOfWeek));
        return *this;
    }

    EzEvent& withRepeatBeginHour(Int32 repeatBeginHour)
    {
        setRepeatBeginHour(repeatBeginHour);
        return *this;
    }

    EzEvent& withRepeatEndHour(Int32 repeatEndHour)
    {
        setRepeatEndHour(repeatEndHour);
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