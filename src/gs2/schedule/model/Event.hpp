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
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

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
        /** イベント のGRN */
        optional<StringHolder> eventId;
        /** ディストリビューターの種類名 */
        optional<StringHolder> name;
        /** ディストリビューターの種類のメタデータ */
        optional<StringHolder> metadata;
        /** イベント期間の種類 */
        optional<StringHolder> scheduleType;
        /** イベントの開始日時 */
        optional<Int64> absoluteBegin;
        /** イベントの終了日時 */
        optional<Int64> absoluteEnd;
        /** イベントの開始トリガー */
        optional<StringHolder> relativeTriggerName;
        /** イベントの開催期間(秒) */
        optional<Int32> relativeDuration;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            eventId(data.eventId),
            name(data.name),
            metadata(data.metadata),
            scheduleType(data.scheduleType),
            absoluteBegin(data.absoluteBegin),
            absoluteEnd(data.absoluteEnd),
            relativeTriggerName(data.relativeTriggerName),
            relativeDuration(data.relativeDuration)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            eventId(std::move(data.eventId)),
            name(std::move(data.name)),
            metadata(std::move(data.metadata)),
            scheduleType(std::move(data.scheduleType)),
            absoluteBegin(std::move(data.absoluteBegin)),
            absoluteEnd(std::move(data.absoluteEnd)),
            relativeTriggerName(std::move(data.relativeTriggerName)),
            relativeDuration(std::move(data.relativeDuration))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "eventId") == 0) {
                if (jsonValue.IsString())
                {
                    this->eventId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "metadata") == 0) {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "scheduleType") == 0) {
                if (jsonValue.IsString())
                {
                    this->scheduleType.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "absoluteBegin") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->absoluteBegin = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "absoluteEnd") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->absoluteEnd = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "relativeTriggerName") == 0) {
                if (jsonValue.IsString())
                {
                    this->relativeTriggerName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "relativeDuration") == 0) {
                if (jsonValue.IsInt())
                {
                    this->relativeDuration = jsonValue.GetInt();
                }
            }
        }
    };

    Data* m_pData;

    Data& ensureData() {
        if (m_pData == nullptr) {
            m_pData = new Data();
        }
        return *m_pData;
    }

    const Data& ensureData() const {
        if (m_pData == nullptr) {
            *const_cast<Data**>(&m_pData) = new Data();
        }
        return *m_pData;
    }

public:
    Event() :
        m_pData(nullptr)
    {}

    Event(const Event& event) :
        Gs2Object(event),
        m_pData(event.m_pData != nullptr ? new Data(*event.m_pData) : nullptr)
    {}

    Event(Event&& event) :
        Gs2Object(std::move(event)),
        m_pData(event.m_pData)
    {
        event.m_pData = nullptr;
    }

    ~Event()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Event& operator=(const Event& event)
    {
        Gs2Object::operator=(event);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*event.m_pData);

        return *this;
    }

    Event& operator=(Event&& event)
    {
        Gs2Object::operator=(std::move(event));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = event.m_pData;
        event.m_pData = nullptr;

        return *this;
    }

    const Event* operator->() const
    {
        return this;
    }

    Event* operator->()
    {
        return this;
    }
    /**
     * イベント のGRNを取得
     *
     * @return イベント のGRN
     */
    const optional<StringHolder>& getEventId() const
    {
        return ensureData().eventId;
    }

    /**
     * イベント のGRNを設定
     *
     * @param eventId イベント のGRN
     */
    void setEventId(const Char* eventId)
    {
        ensureData().eventId.emplace(eventId);
    }

    /**
     * イベント のGRNを設定
     *
     * @param eventId イベント のGRN
     */
    Event& withEventId(const Char* eventId)
    {
        setEventId(eventId);
        return *this;
    }

    /**
     * ディストリビューターの種類名を取得
     *
     * @return ディストリビューターの種類名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * ディストリビューターの種類名を設定
     *
     * @param name ディストリビューターの種類名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * ディストリビューターの種類名を設定
     *
     * @param name ディストリビューターの種類名
     */
    Event& withName(const Char* name)
    {
        setName(name);
        return *this;
    }

    /**
     * ディストリビューターの種類のメタデータを取得
     *
     * @return ディストリビューターの種類のメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * ディストリビューターの種類のメタデータを設定
     *
     * @param metadata ディストリビューターの種類のメタデータ
     */
    void setMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
    }

    /**
     * ディストリビューターの種類のメタデータを設定
     *
     * @param metadata ディストリビューターの種類のメタデータ
     */
    Event& withMetadata(const Char* metadata)
    {
        setMetadata(metadata);
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
    void setScheduleType(const Char* scheduleType)
    {
        ensureData().scheduleType.emplace(scheduleType);
    }

    /**
     * イベント期間の種類を設定
     *
     * @param scheduleType イベント期間の種類
     */
    Event& withScheduleType(const Char* scheduleType)
    {
        setScheduleType(scheduleType);
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
    void setRelativeTriggerName(const Char* relativeTriggerName)
    {
        ensureData().relativeTriggerName.emplace(relativeTriggerName);
    }

    /**
     * イベントの開始トリガーを設定
     *
     * @param relativeTriggerName イベントの開始トリガー
     */
    Event& withRelativeTriggerName(const Char* relativeTriggerName)
    {
        setRelativeTriggerName(relativeTriggerName);
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

bool operator!=(const Event& lhs, const Event& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
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
        if (lhs.m_pData->absoluteBegin != lhr.m_pData->absoluteBegin)
        {
            return true;
        }
        if (lhs.m_pData->absoluteEnd != lhr.m_pData->absoluteEnd)
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

bool operator==(const Event& lhs, const Event& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_SCHEDULE_MODEL_EVENT_HPP_