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

#ifndef GS2_CHAT_MODEL_SUBSCRIBE_HPP_
#define GS2_CHAT_MODEL_SUBSCRIBE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "NotificationType.hpp"
#include <memory>
#include <cstring>

namespace gs2 { namespace chat {

/**
 * 購読
 *
 * @author Game Server Services, Inc.
 *
 */
class Subscribe : public Gs2Object
{
    friend bool operator!=(const Subscribe& lhs, const Subscribe& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 購読 */
        optional<StringHolder> subscribeId;
        /** 購読するユーザID */
        optional<StringHolder> userId;
        /** 購読するルーム名 */
        optional<StringHolder> roomName;
        /** 新着メッセージ通知を受け取るカテゴリリスト */
        optional<List<NotificationType>> notificationTypes;
        /** 作成日時 */
        optional<Int64> createdAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            subscribeId(data.subscribeId),
            userId(data.userId),
            roomName(data.roomName),
            createdAt(data.createdAt)
        {
            if (data.notificationTypes)
            {
                notificationTypes = data.notificationTypes->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "subscribeId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->subscribeId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "userId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "roomName") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->roomName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "notificationTypes") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->notificationTypes.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        NotificationType item_;
                        detail::json::JsonParser::parse(&item_.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        *this->notificationTypes += std::move(item_);
                    }
                }
            }
            else if (std::strcmp(name_, "createdAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Subscribe() = default;
    Subscribe(const Subscribe& subscribe) = default;
    Subscribe(Subscribe&& subscribe) = default;
    ~Subscribe() = default;

    Subscribe& operator=(const Subscribe& subscribe) = default;
    Subscribe& operator=(Subscribe&& subscribe) = default;

    Subscribe deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Subscribe);
    }

    const Subscribe* operator->() const
    {
        return this;
    }

    Subscribe* operator->()
    {
        return this;
    }
    /**
     * 購読を取得
     *
     * @return 購読
     */
    const optional<StringHolder>& getSubscribeId() const
    {
        return ensureData().subscribeId;
    }

    /**
     * 購読を設定
     *
     * @param subscribeId 購読
     */
    void setSubscribeId(StringHolder subscribeId)
    {
        ensureData().subscribeId.emplace(std::move(subscribeId));
    }

    /**
     * 購読を設定
     *
     * @param subscribeId 購読
     */
    Subscribe& withSubscribeId(StringHolder subscribeId)
    {
        setSubscribeId(std::move(subscribeId));
        return *this;
    }

    /**
     * 購読するユーザIDを取得
     *
     * @return 購読するユーザID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * 購読するユーザIDを設定
     *
     * @param userId 購読するユーザID
     */
    void setUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
    }

    /**
     * 購読するユーザIDを設定
     *
     * @param userId 購読するユーザID
     */
    Subscribe& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    /**
     * 購読するルーム名を取得
     *
     * @return 購読するルーム名
     */
    const optional<StringHolder>& getRoomName() const
    {
        return ensureData().roomName;
    }

    /**
     * 購読するルーム名を設定
     *
     * @param roomName 購読するルーム名
     */
    void setRoomName(StringHolder roomName)
    {
        ensureData().roomName.emplace(std::move(roomName));
    }

    /**
     * 購読するルーム名を設定
     *
     * @param roomName 購読するルーム名
     */
    Subscribe& withRoomName(StringHolder roomName)
    {
        setRoomName(std::move(roomName));
        return *this;
    }

    /**
     * 新着メッセージ通知を受け取るカテゴリリストを取得
     *
     * @return 新着メッセージ通知を受け取るカテゴリリスト
     */
    const optional<List<NotificationType>>& getNotificationTypes() const
    {
        return ensureData().notificationTypes;
    }

    /**
     * 新着メッセージ通知を受け取るカテゴリリストを設定
     *
     * @param notificationTypes 新着メッセージ通知を受け取るカテゴリリスト
     */
    void setNotificationTypes(List<NotificationType> notificationTypes)
    {
        ensureData().notificationTypes.emplace(std::move(notificationTypes));
    }

    /**
     * 新着メッセージ通知を受け取るカテゴリリストを設定
     *
     * @param notificationTypes 新着メッセージ通知を受け取るカテゴリリスト
     */
    Subscribe& withNotificationTypes(List<NotificationType> notificationTypes)
    {
        setNotificationTypes(std::move(notificationTypes));
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
    Subscribe& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Subscribe& lhs, const Subscribe& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->subscribeId != lhr.m_pData->subscribeId)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->roomName != lhr.m_pData->roomName)
        {
            return true;
        }
        if (lhs.m_pData->notificationTypes != lhr.m_pData->notificationTypes)
        {
            return true;
        }
        if (lhs.m_pData->createdAt != lhr.m_pData->createdAt)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const Subscribe& lhs, const Subscribe& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_CHAT_MODEL_SUBSCRIBE_HPP_