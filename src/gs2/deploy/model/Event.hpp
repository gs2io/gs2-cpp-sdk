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

#ifndef GS2_DEPLOY_MODEL_EVENT_HPP_
#define GS2_DEPLOY_MODEL_EVENT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace deploy {

/**
 * 発生したイベント
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
        /** 発生したイベント */
        optional<StringHolder> eventId;
        /** イベント名 */
        optional<StringHolder> name;
        /** イベントの種類 */
        optional<StringHolder> resourceName;
        /** イベントの種類 */
        optional<StringHolder> type;
        /** メッセージ */
        optional<StringHolder> message;
        /** 日時 */
        optional<Int64> eventAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            eventId(data.eventId),
            name(data.name),
            resourceName(data.resourceName),
            type(data.type),
            message(data.message),
            eventAt(data.eventAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            eventId(std::move(data.eventId)),
            name(std::move(data.name)),
            resourceName(std::move(data.resourceName)),
            type(std::move(data.type)),
            message(std::move(data.message)),
            eventAt(std::move(data.eventAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "eventId") == 0) {
                if (jsonValue.IsString())
                {
                    this->eventId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "resourceName") == 0) {
                if (jsonValue.IsString())
                {
                    this->resourceName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "type") == 0) {
                if (jsonValue.IsString())
                {
                    this->type.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "message") == 0) {
                if (jsonValue.IsString())
                {
                    this->message.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "eventAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->eventAt = jsonValue.GetInt64();
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
     * 発生したイベントを取得
     *
     * @return 発生したイベント
     */
    const optional<StringHolder>& getEventId() const
    {
        return ensureData().eventId;
    }

    /**
     * 発生したイベントを設定
     *
     * @param eventId 発生したイベント
     */
    void setEventId(const Char* eventId)
    {
        ensureData().eventId.emplace(eventId);
    }

    /**
     * 発生したイベントを設定
     *
     * @param eventId 発生したイベント
     */
    Event& withEventId(const Char* eventId)
    {
        setEventId(eventId);
        return *this;
    }

    /**
     * イベント名を取得
     *
     * @return イベント名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * イベント名を設定
     *
     * @param name イベント名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * イベント名を設定
     *
     * @param name イベント名
     */
    Event& withName(const Char* name)
    {
        setName(name);
        return *this;
    }

    /**
     * イベントの種類を取得
     *
     * @return イベントの種類
     */
    const optional<StringHolder>& getResourceName() const
    {
        return ensureData().resourceName;
    }

    /**
     * イベントの種類を設定
     *
     * @param resourceName イベントの種類
     */
    void setResourceName(const Char* resourceName)
    {
        ensureData().resourceName.emplace(resourceName);
    }

    /**
     * イベントの種類を設定
     *
     * @param resourceName イベントの種類
     */
    Event& withResourceName(const Char* resourceName)
    {
        setResourceName(resourceName);
        return *this;
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
     * イベントの種類を設定
     *
     * @param type イベントの種類
     */
    Event& withType(const Char* type)
    {
        setType(type);
        return *this;
    }

    /**
     * メッセージを取得
     *
     * @return メッセージ
     */
    const optional<StringHolder>& getMessage() const
    {
        return ensureData().message;
    }

    /**
     * メッセージを設定
     *
     * @param message メッセージ
     */
    void setMessage(const Char* message)
    {
        ensureData().message.emplace(message);
    }

    /**
     * メッセージを設定
     *
     * @param message メッセージ
     */
    Event& withMessage(const Char* message)
    {
        setMessage(message);
        return *this;
    }

    /**
     * 日時を取得
     *
     * @return 日時
     */
    const optional<Int64>& getEventAt() const
    {
        return ensureData().eventAt;
    }

    /**
     * 日時を設定
     *
     * @param eventAt 日時
     */
    void setEventAt(Int64 eventAt)
    {
        ensureData().eventAt.emplace(eventAt);
    }

    /**
     * 日時を設定
     *
     * @param eventAt 日時
     */
    Event& withEventAt(Int64 eventAt)
    {
        setEventAt(eventAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Event& lhs, const Event& lhr)
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
        if (lhs.m_pData->resourceName != lhr.m_pData->resourceName)
        {
            return true;
        }
        if (lhs.m_pData->type != lhr.m_pData->type)
        {
            return true;
        }
        if (lhs.m_pData->message != lhr.m_pData->message)
        {
            return true;
        }
        if (lhs.m_pData->eventAt != lhr.m_pData->eventAt)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const Event& lhs, const Event& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_DEPLOY_MODEL_EVENT_HPP_