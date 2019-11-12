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

#ifndef GS2_SCHEDULE_MODEL_EVENTMASTER_HPP_
#define GS2_SCHEDULE_MODEL_EVENTMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace schedule {

/**
 * イベントマスター
 *
 * @author Game Server Services, Inc.
 *
 */
class EventMaster : public Gs2Object
{
    friend bool operator!=(const EventMaster& lhs, const EventMaster& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** イベントマスター */
        optional<StringHolder> eventId;
        /** イベントの種類名 */
        optional<StringHolder> name;
        /** イベントマスターの説明 */
        optional<StringHolder> description;
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
        /** イベントの開始トリガー名 */
        optional<StringHolder> relativeTriggerName;
        /** イベントの開催期間(秒) */
        optional<Int32> relativeDuration;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            eventId(data.eventId),
            name(data.name),
            description(data.description),
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
            relativeDuration(data.relativeDuration),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
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
            else if (std::strcmp(name_, "description") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
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
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EventMaster() = default;
    EventMaster(const EventMaster& eventMaster) = default;
    EventMaster(EventMaster&& eventMaster) = default;
    ~EventMaster() = default;

    EventMaster& operator=(const EventMaster& eventMaster) = default;
    EventMaster& operator=(EventMaster&& eventMaster) = default;

    EventMaster deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EventMaster);
    }

    const EventMaster* operator->() const
    {
        return this;
    }

    EventMaster* operator->()
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
    EventMaster& withEventId(StringHolder eventId)
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
    EventMaster& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * イベントマスターの説明を取得
     *
     * @return イベントマスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * イベントマスターの説明を設定
     *
     * @param description イベントマスターの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * イベントマスターの説明を設定
     *
     * @param description イベントマスターの説明
     */
    EventMaster& withDescription(StringHolder description)
    {
        setDescription(std::move(description));
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
    EventMaster& withMetadata(StringHolder metadata)
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
    EventMaster& withScheduleType(StringHolder scheduleType)
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
    EventMaster& withRepeatType(StringHolder repeatType)
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
    EventMaster& withAbsoluteBegin(Int64 absoluteBegin)
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
    EventMaster& withAbsoluteEnd(Int64 absoluteEnd)
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
    EventMaster& withRepeatBeginDayOfMonth(Int32 repeatBeginDayOfMonth)
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
    EventMaster& withRepeatEndDayOfMonth(Int32 repeatEndDayOfMonth)
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
    EventMaster& withRepeatBeginDayOfWeek(StringHolder repeatBeginDayOfWeek)
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
    EventMaster& withRepeatEndDayOfWeek(StringHolder repeatEndDayOfWeek)
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
    EventMaster& withRepeatBeginHour(Int32 repeatBeginHour)
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
    EventMaster& withRepeatEndHour(Int32 repeatEndHour)
    {
        setRepeatEndHour(repeatEndHour);
        return *this;
    }

    /**
     * イベントの開始トリガー名を取得
     *
     * @return イベントの開始トリガー名
     */
    const optional<StringHolder>& getRelativeTriggerName() const
    {
        return ensureData().relativeTriggerName;
    }

    /**
     * イベントの開始トリガー名を設定
     *
     * @param relativeTriggerName イベントの開始トリガー名
     */
    void setRelativeTriggerName(StringHolder relativeTriggerName)
    {
        ensureData().relativeTriggerName.emplace(std::move(relativeTriggerName));
    }

    /**
     * イベントの開始トリガー名を設定
     *
     * @param relativeTriggerName イベントの開始トリガー名
     */
    EventMaster& withRelativeTriggerName(StringHolder relativeTriggerName)
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
    EventMaster& withRelativeDuration(Int32 relativeDuration)
    {
        setRelativeDuration(relativeDuration);
        return *this;
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getCreatedAt() const
    {
        return ensureData().createdAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    void setCreatedAt(Int64 createdAt)
    {
        ensureData().createdAt.emplace(createdAt);
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    EventMaster& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }

    /**
     * 最終更新日時を取得
     *
     * @return 最終更新日時
     */
    const optional<Int64>& getUpdatedAt() const
    {
        return ensureData().updatedAt;
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    void setUpdatedAt(Int64 updatedAt)
    {
        ensureData().updatedAt.emplace(updatedAt);
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    EventMaster& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const EventMaster& lhs, const EventMaster& lhr)
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
        if (lhs.m_pData->description != lhr.m_pData->description)
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

inline bool operator==(const EventMaster& lhs, const EventMaster& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_SCHEDULE_MODEL_EVENTMASTER_HPP_