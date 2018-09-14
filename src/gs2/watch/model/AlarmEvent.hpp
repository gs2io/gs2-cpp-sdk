/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
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

#ifndef GS2_WATCH_MODEL_ALARMEVENT_HPP_
#define GS2_WATCH_MODEL_ALARMEVENT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace watch {

/**
 * アラームイベント
 *
 * @author Game Server Services, Inc.
 *
 */
class AlarmEvent : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** イベントID */
        optional<StringHolder> eventId;
        /** アラームID */
        optional<StringHolder> alarmId;
        /** イベントの種類 */
        optional<StringHolder> type;
        /** 発生日時(エポック秒) */
        optional<Int32> eventAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            eventId(data.eventId),
            alarmId(data.alarmId),
            type(data.type),
            eventAt(data.eventAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            eventId(std::move(data.eventId)),
            alarmId(std::move(data.alarmId)),
            type(std::move(data.type)),
            eventAt(std::move(data.eventAt))
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
            else if (std::strcmp(name, "alarmId") == 0) {
                if (jsonValue.IsString())
                {
                    this->alarmId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "type") == 0) {
                if (jsonValue.IsString())
                {
                    this->type.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "eventAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->eventAt = jsonValue.GetInt();
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
    AlarmEvent() :
        m_pData(nullptr)
    {}

    AlarmEvent(const AlarmEvent& alarmEvent) :
        Gs2Object(alarmEvent),
        m_pData(alarmEvent.m_pData != nullptr ? new Data(*alarmEvent.m_pData) : nullptr)
    {}

    AlarmEvent(AlarmEvent&& alarmEvent) :
        Gs2Object(std::move(alarmEvent)),
        m_pData(alarmEvent.m_pData)
    {
        alarmEvent.m_pData = nullptr;
    }

    ~AlarmEvent()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    AlarmEvent& operator=(const AlarmEvent& alarmEvent)
    {
        Gs2Object::operator=(alarmEvent);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*alarmEvent.m_pData);

        return *this;
    }

    AlarmEvent& operator=(AlarmEvent&& alarmEvent)
    {
        Gs2Object::operator=(std::move(alarmEvent));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = alarmEvent.m_pData;
        alarmEvent.m_pData = nullptr;

        return *this;
    }

    const AlarmEvent* operator->() const
    {
        return this;
    }

    AlarmEvent* operator->()
    {
        return this;
    }


    /**
     * イベントIDを取得
     *
     * @return イベントID
     */
    const optional<StringHolder>& getEventId() const
    {
        return ensureData().eventId;
    }

    /**
     * イベントIDを設定
     *
     * @param eventId イベントID
     */
    void setEventId(const Char* eventId)
    {
        ensureData().eventId.emplace(eventId);
    }

    /**
     * アラームIDを取得
     *
     * @return アラームID
     */
    const optional<StringHolder>& getAlarmId() const
    {
        return ensureData().alarmId;
    }

    /**
     * アラームIDを設定
     *
     * @param alarmId アラームID
     */
    void setAlarmId(const Char* alarmId)
    {
        ensureData().alarmId.emplace(alarmId);
    }

    /**
     * イベントの種類を取得
     *
     * @return イベントの種類
     */
    const optional<StringHolder>& getType() const
    {
        return ensureData().type;
    }

    /**
     * イベントの種類を設定
     *
     * @param type イベントの種類
     */
    void setType(const Char* type)
    {
        ensureData().type.emplace(type);
    }

    /**
     * 発生日時(エポック秒)を取得
     *
     * @return 発生日時(エポック秒)
     */
    const optional<Int32>& getEventAt() const
    {
        return ensureData().eventAt;
    }

    /**
     * 発生日時(エポック秒)を設定
     *
     * @param eventAt 発生日時(エポック秒)
     */
    void setEventAt(Int32 eventAt)
    {
        ensureData().eventAt.emplace(eventAt);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_WATCH_MODEL_ALARMEVENT_HPP_