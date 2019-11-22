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

#ifndef GS2_SCHEDULE_MODEL_EVENT_HPP_
#define GS2_SCHEDULE_MODEL_EVENT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>

namespace gs2 { namespace schedule {

/**
 * イベント
 *
 * @author Game Server Services, Inc.
 *
 */
class Event : public Gs2Object
{
    friend bool operator!=(const Event& lhs, const Event& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** イベントマスター */
        optional<StringHolder> eventId;
        /** イベントの種類名 */
        optional<StringHolder> name;
        /** イベントの種類のメタデータ */
        optional<StringHolder> metadata;
        /** イベント期間の種類 */
        optional<StringHolder> scheduleType;
        /** 繰り返しの種類 */
        optional<StringHolder> repeatType;
        /** イベントの開始日時 */
        optional<Int64> absoluteBegin;
        /** イベントの終了日時 */
        optional<Int64> absoluteEnd;
        /** イベントの繰り返し開始日 */
        optional<Int32> repeatBeginDayOfMonth;
        /** イベントの繰り返し終了日 */
        optional<Int32> repeatEndDayOfMonth;
        /** イベントの繰り返し開始曜日 */
        optional<StringHolder> repeatBeginDayOfWeek;
        /** イベントの繰り返し終了曜日 */
        optional<StringHolder> repeatEndDayOfWeek;
        /** イベントの繰り返し開始時間 */
        optional<Int32> repeatBeginHour;
        /** イベントの繰り返し終了時間 */
        optional<Int32> repeatEndHour;
        /** イベントの開始トリガー */
        optional<StringHolder> relativeTriggerName;
        /** イベントの開催期間(秒) */
        optional<Int32> relativeDuration;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        ~Data() GS2_OVERRIDE = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        void set(const Char name_[], const detail::json::JsonConstValue& jsonValue) GS2_OVERRIDE;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Event() = default;
    Event(const Event& event) = default;
    Event(Event&& event) = default;
    ~Event() = default;

    Event& operator=(const Event& event) = default;
    Event& operator=(Event&& event) = default;

    Event deepCopy() const;

    const Event* operator->() const
    {
        return this;
    }

    Event* operator->()
    {
        return this;
    }
    /**
     * イベントマスターを取得
     *
     * @return イベントマスター
     */
    const optional<StringHolder>& getEventId() const
    {
        return ensureData().eventId;
    }

    /**
     * イベントマスターを設定
     *
     * @param eventId イベントマスター
     */
    void setEventId(StringHolder eventId)
    {
        ensureData().eventId.emplace(std::move(eventId));
    }

    /**
     * イベントマスターを設定
     *
     * @param eventId イベントマスター
     */
    Event& withEventId(StringHolder eventId)
    {
        setEventId(std::move(eventId));
        return *this;
    }

    /**
     * イベントの種類名を取得
     *
     * @return イベントの種類名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * イベントの種類名を設定
     *
     * @param name イベントの種類名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * イベントの種類名を設定
     *
     * @param name イベントの種類名
     */
    Event& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * イベントの種類のメタデータを取得
     *
     * @return イベントの種類のメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * イベントの種類のメタデータを設定
     *
     * @param metadata イベントの種類のメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * イベントの種類のメタデータを設定
     *
     * @param metadata イベントの種類のメタデータ
     */
    Event& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    /**
     * イベント期間の種類を取得
     *
     * @return イベント期間の種類
     */
    const optional<StringHolder>& getScheduleType() const
    {
        return ensureData().scheduleType;
    }

    /**
     * イベント期間の種類を設定
     *
     * @param scheduleType イベント期間の種類
     */
    void setScheduleType(StringHolder scheduleType)
    {
        ensureData().scheduleType.emplace(std::move(scheduleType));
    }

    /**
     * イベント期間の種類を設定
     *
     * @param scheduleType イベント期間の種類
     */
    Event& withScheduleType(StringHolder scheduleType)
    {
        setScheduleType(std::move(scheduleType));
        return *this;
    }

    /**
     * 繰り返しの種類を取得
     *
     * @return 繰り返しの種類
     */
    const optional<StringHolder>& getRepeatType() const
    {
        return ensureData().repeatType;
    }

    /**
     * 繰り返しの種類を設定
     *
     * @param repeatType 繰り返しの種類
     */
    void setRepeatType(StringHolder repeatType)
    {
        ensureData().repeatType.emplace(std::move(repeatType));
    }

    /**
     * 繰り返しの種類を設定
     *
     * @param repeatType 繰り返しの種類
     */
    Event& withRepeatType(StringHolder repeatType)
    {
        setRepeatType(std::move(repeatType));
        return *this;
    }

    /**
     * イベントの開始日時を取得
     *
     * @return イベントの開始日時
     */
    const optional<Int64>& getAbsoluteBegin() const
    {
        return ensureData().absoluteBegin;
    }

    /**
     * イベントの開始日時を設定
     *
     * @param absoluteBegin イベントの開始日時
     */
    void setAbsoluteBegin(Int64 absoluteBegin)
    {
        ensureData().absoluteBegin.emplace(absoluteBegin);
    }

    /**
     * イベントの開始日時を設定
     *
     * @param absoluteBegin イベントの開始日時
     */
    Event& withAbsoluteBegin(Int64 absoluteBegin)
    {
        setAbsoluteBegin(absoluteBegin);
        return *this;
    }

    /**
     * イベントの終了日時を取得
     *
     * @return イベントの終了日時
     */
    const optional<Int64>& getAbsoluteEnd() const
    {
        return ensureData().absoluteEnd;
    }

    /**
     * イベントの終了日時を設定
     *
     * @param absoluteEnd イベントの終了日時
     */
    void setAbsoluteEnd(Int64 absoluteEnd)
    {
        ensureData().absoluteEnd.emplace(absoluteEnd);
    }

    /**
     * イベントの終了日時を設定
     *
     * @param absoluteEnd イベントの終了日時
     */
    Event& withAbsoluteEnd(Int64 absoluteEnd)
    {
        setAbsoluteEnd(absoluteEnd);
        return *this;
    }

    /**
     * イベントの繰り返し開始日を取得
     *
     * @return イベントの繰り返し開始日
     */
    const optional<Int32>& getRepeatBeginDayOfMonth() const
    {
        return ensureData().repeatBeginDayOfMonth;
    }

    /**
     * イベントの繰り返し開始日を設定
     *
     * @param repeatBeginDayOfMonth イベントの繰り返し開始日
     */
    void setRepeatBeginDayOfMonth(Int32 repeatBeginDayOfMonth)
    {
        ensureData().repeatBeginDayOfMonth.emplace(repeatBeginDayOfMonth);
    }

    /**
     * イベントの繰り返し開始日を設定
     *
     * @param repeatBeginDayOfMonth イベントの繰り返し開始日
     */
    Event& withRepeatBeginDayOfMonth(Int32 repeatBeginDayOfMonth)
    {
        setRepeatBeginDayOfMonth(repeatBeginDayOfMonth);
        return *this;
    }

    /**
     * イベントの繰り返し終了日を取得
     *
     * @return イベントの繰り返し終了日
     */
    const optional<Int32>& getRepeatEndDayOfMonth() const
    {
        return ensureData().repeatEndDayOfMonth;
    }

    /**
     * イベントの繰り返し終了日を設定
     *
     * @param repeatEndDayOfMonth イベントの繰り返し終了日
     */
    void setRepeatEndDayOfMonth(Int32 repeatEndDayOfMonth)
    {
        ensureData().repeatEndDayOfMonth.emplace(repeatEndDayOfMonth);
    }

    /**
     * イベントの繰り返し終了日を設定
     *
     * @param repeatEndDayOfMonth イベントの繰り返し終了日
     */
    Event& withRepeatEndDayOfMonth(Int32 repeatEndDayOfMonth)
    {
        setRepeatEndDayOfMonth(repeatEndDayOfMonth);
        return *this;
    }

    /**
     * イベントの繰り返し開始曜日を取得
     *
     * @return イベントの繰り返し開始曜日
     */
    const optional<StringHolder>& getRepeatBeginDayOfWeek() const
    {
        return ensureData().repeatBeginDayOfWeek;
    }

    /**
     * イベントの繰り返し開始曜日を設定
     *
     * @param repeatBeginDayOfWeek イベントの繰り返し開始曜日
     */
    void setRepeatBeginDayOfWeek(StringHolder repeatBeginDayOfWeek)
    {
        ensureData().repeatBeginDayOfWeek.emplace(std::move(repeatBeginDayOfWeek));
    }

    /**
     * イベントの繰り返し開始曜日を設定
     *
     * @param repeatBeginDayOfWeek イベントの繰り返し開始曜日
     */
    Event& withRepeatBeginDayOfWeek(StringHolder repeatBeginDayOfWeek)
    {
        setRepeatBeginDayOfWeek(std::move(repeatBeginDayOfWeek));
        return *this;
    }

    /**
     * イベントの繰り返し終了曜日を取得
     *
     * @return イベントの繰り返し終了曜日
     */
    const optional<StringHolder>& getRepeatEndDayOfWeek() const
    {
        return ensureData().repeatEndDayOfWeek;
    }

    /**
     * イベントの繰り返し終了曜日を設定
     *
     * @param repeatEndDayOfWeek イベントの繰り返し終了曜日
     */
    void setRepeatEndDayOfWeek(StringHolder repeatEndDayOfWeek)
    {
        ensureData().repeatEndDayOfWeek.emplace(std::move(repeatEndDayOfWeek));
    }

    /**
     * イベントの繰り返し終了曜日を設定
     *
     * @param repeatEndDayOfWeek イベントの繰り返し終了曜日
     */
    Event& withRepeatEndDayOfWeek(StringHolder repeatEndDayOfWeek)
    {
        setRepeatEndDayOfWeek(std::move(repeatEndDayOfWeek));
        return *this;
    }

    /**
     * イベントの繰り返し開始時間を取得
     *
     * @return イベントの繰り返し開始時間
     */
    const optional<Int32>& getRepeatBeginHour() const
    {
        return ensureData().repeatBeginHour;
    }

    /**
     * イベントの繰り返し開始時間を設定
     *
     * @param repeatBeginHour イベントの繰り返し開始時間
     */
    void setRepeatBeginHour(Int32 repeatBeginHour)
    {
        ensureData().repeatBeginHour.emplace(repeatBeginHour);
    }

    /**
     * イベントの繰り返し開始時間を設定
     *
     * @param repeatBeginHour イベントの繰り返し開始時間
     */
    Event& withRepeatBeginHour(Int32 repeatBeginHour)
    {
        setRepeatBeginHour(repeatBeginHour);
        return *this;
    }

    /**
     * イベントの繰り返し終了時間を取得
     *
     * @return イベントの繰り返し終了時間
     */
    const optional<Int32>& getRepeatEndHour() const
    {
        return ensureData().repeatEndHour;
    }

    /**
     * イベントの繰り返し終了時間を設定
     *
     * @param repeatEndHour イベントの繰り返し終了時間
     */
    void setRepeatEndHour(Int32 repeatEndHour)
    {
        ensureData().repeatEndHour.emplace(repeatEndHour);
    }

    /**
     * イベントの繰り返し終了時間を設定
     *
     * @param repeatEndHour イベントの繰り返し終了時間
     */
    Event& withRepeatEndHour(Int32 repeatEndHour)
    {
        setRepeatEndHour(repeatEndHour);
        return *this;
    }

    /**
     * イベントの開始トリガーを取得
     *
     * @return イベントの開始トリガー
     */
    const optional<StringHolder>& getRelativeTriggerName() const
    {
        return ensureData().relativeTriggerName;
    }

    /**
     * イベントの開始トリガーを設定
     *
     * @param relativeTriggerName イベントの開始トリガー
     */
    void setRelativeTriggerName(StringHolder relativeTriggerName)
    {
        ensureData().relativeTriggerName.emplace(std::move(relativeTriggerName));
    }

    /**
     * イベントの開始トリガーを設定
     *
     * @param relativeTriggerName イベントの開始トリガー
     */
    Event& withRelativeTriggerName(StringHolder relativeTriggerName)
    {
        setRelativeTriggerName(std::move(relativeTriggerName));
        return *this;
    }

    /**
     * イベントの開催期間(秒)を取得
     *
     * @return イベントの開催期間(秒)
     */
    const optional<Int32>& getRelativeDuration() const
    {
        return ensureData().relativeDuration;
    }

    /**
     * イベントの開催期間(秒)を設定
     *
     * @param relativeDuration イベントの開催期間(秒)
     */
    void setRelativeDuration(Int32 relativeDuration)
    {
        ensureData().relativeDuration.emplace(relativeDuration);
    }

    /**
     * イベントの開催期間(秒)を設定
     *
     * @param relativeDuration イベントの開催期間(秒)
     */
    Event& withRelativeDuration(Int32 relativeDuration)
    {
        setRelativeDuration(relativeDuration);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const Event& lhs, const Event& lhr);

inline bool operator==(const Event& lhs, const Event& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_SCHEDULE_MODEL_EVENT_HPP_