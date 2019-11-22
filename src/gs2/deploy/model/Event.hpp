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
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>

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
    void setEventId(StringHolder eventId)
    {
        ensureData().eventId.emplace(std::move(eventId));
    }

    /**
     * 発生したイベントを設定
     *
     * @param eventId 発生したイベント
     */
    Event& withEventId(StringHolder eventId)
    {
        setEventId(std::move(eventId));
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
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * イベント名を設定
     *
     * @param name イベント名
     */
    Event& withName(StringHolder name)
    {
        setName(std::move(name));
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
    void setResourceName(StringHolder resourceName)
    {
        ensureData().resourceName.emplace(std::move(resourceName));
    }

    /**
     * イベントの種類を設定
     *
     * @param resourceName イベントの種類
     */
    Event& withResourceName(StringHolder resourceName)
    {
        setResourceName(std::move(resourceName));
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
    void setType(StringHolder type)
    {
        ensureData().type.emplace(std::move(type));
    }

    /**
     * イベントの種類を設定
     *
     * @param type イベントの種類
     */
    Event& withType(StringHolder type)
    {
        setType(std::move(type));
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
    void setMessage(StringHolder message)
    {
        ensureData().message.emplace(std::move(message));
    }

    /**
     * メッセージを設定
     *
     * @param message メッセージ
     */
    Event& withMessage(StringHolder message)
    {
        setMessage(std::move(message));
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

bool operator!=(const Event& lhs, const Event& lhr);

inline bool operator==(const Event& lhs, const Event& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_DEPLOY_MODEL_EVENT_HPP_