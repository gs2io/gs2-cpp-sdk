

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

#ifndef GS2_EZ_CHAT_MODEL_EZSUBSCRIBE_HPP_
#define GS2_EZ_CHAT_MODEL_EZSUBSCRIBE_HPP_

#include <gs2/chat/model/Subscribe.hpp>
#include "EzNotificationType.hpp"


namespace gs2 { namespace ez { namespace chat {

class EzSubscribe : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 購読するユーザID */
        gs2::optional<StringHolder> userId;
        /** 購読するルーム名 */
        gs2::optional<StringHolder> roomName;
        /** 新着メッセージ通知を受け取るカテゴリリスト */
        gs2::optional<List<EzNotificationType>> notificationTypes;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            userId(data.userId),
            roomName(data.roomName)
        {
            if (data.notificationTypes)
            {
                notificationTypes = data.notificationTypes->deepCopy();
            }
        }

        Data(Data&& data) = default;

        Data(const gs2::chat::Subscribe& subscribe) :
            userId(subscribe.getUserId()),
            roomName(subscribe.getRoomName())
        {
            notificationTypes.emplace();
            if (subscribe.getNotificationTypes())
            {
                for (int i = 0; i < subscribe.getNotificationTypes()->getCount(); ++i)
                {
                    *notificationTypes += EzNotificationType((*subscribe.getNotificationTypes())[i]);
                }
            }
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzSubscribe() = default;
    EzSubscribe(const EzSubscribe& ezSubscribe) = default;
    EzSubscribe(EzSubscribe&& ezSubscribe) = default;
    ~EzSubscribe() = default;

    EzSubscribe(gs2::chat::Subscribe subscribe) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(subscribe)
    {}

    EzSubscribe& operator=(const EzSubscribe& ezSubscribe) = default;
    EzSubscribe& operator=(EzSubscribe&& ezSubscribe) = default;

    EzSubscribe deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzSubscribe);
    }

    gs2::chat::Subscribe ToModel() const
    {
        gs2::chat::Subscribe subscribe;
        subscribe.setUserId(getUserId());
        subscribe.setRoomName(getRoomName());
        {
            gs2::List<gs2::chat::NotificationType> list;
            auto& notificationTypes = getNotificationTypes();
            for (int i = 0; i < notificationTypes.getCount(); ++i)
            {
                list += notificationTypes[i].ToModel();
            }
            subscribe.setNotificationTypes(list);
        }
        return subscribe;
    }

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getUserId() const
    {
        return *ensureData().userId;
    }

    const StringHolder& getRoomName() const
    {
        return *ensureData().roomName;
    }

    const List<EzNotificationType>& getNotificationTypes() const
    {
        return *ensureData().notificationTypes;
    }

    // ========================================
    //   Setters
    // ========================================

    void setUserId(StringHolder userId)
    {
        ensureData().userId = std::move(userId);
    }

    void setRoomName(StringHolder roomName)
    {
        ensureData().roomName = std::move(roomName);
    }

    void setNotificationTypes(List<EzNotificationType> notificationTypes)
    {
        ensureData().notificationTypes = std::move(notificationTypes);
    }

    EzSubscribe& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    EzSubscribe& withRoomName(StringHolder roomName)
    {
        setRoomName(std::move(roomName));
        return *this;
    }

    EzSubscribe& withNotificationTypes(List<EzNotificationType> notificationTypes)
    {
        setNotificationTypes(std::move(notificationTypes));
        return *this;
    }
};

}}}

#endif //GS2_EZ_CHAT_EZSUBSCRIBE_HPP_