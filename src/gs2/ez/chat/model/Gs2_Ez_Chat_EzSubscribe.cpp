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

#include "EzSubscribe.hpp"
#include <gs2/chat/model/Subscribe.hpp>


namespace gs2 { namespace ez { namespace chat {

EzSubscribe::Data::Data(const Data& data) :
    Gs2Object(data),
    userId(data.userId),
    roomName(data.roomName)
{
    notificationTypes = data.notificationTypes.deepCopy();
}

EzSubscribe::Data::Data(const gs2::chat::Subscribe& subscribe) :
    userId(subscribe.getUserId() ? *subscribe.getUserId() : StringHolder()),
    roomName(subscribe.getRoomName() ? *subscribe.getRoomName() : StringHolder())
{
    if (subscribe.getNotificationTypes())
    {
        for (int i = 0; i < subscribe.getNotificationTypes()->getCount(); ++i)
        {
            notificationTypes += EzNotificationType((*subscribe.getNotificationTypes())[i]);
        }
    }
}

EzSubscribe::Data::Data(const gs2::optional<gs2::chat::Subscribe>& subscribe) :
    userId(subscribe && subscribe->getUserId() ? *subscribe->getUserId() : StringHolder()),
    roomName(subscribe && subscribe->getRoomName() ? *subscribe->getRoomName() : StringHolder())
{
    if (subscribe && subscribe->getNotificationTypes())
    {
        for (int i = 0; i < subscribe->getNotificationTypes()->getCount(); ++i)
        {
            notificationTypes += EzNotificationType((*subscribe->getNotificationTypes())[i]);
        }
    }
}

EzSubscribe::EzSubscribe(gs2::chat::Subscribe subscribe) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(subscribe)
{
}

EzSubscribe::EzSubscribe(gs2::optional<gs2::chat::Subscribe> subscribe) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(subscribe)
{
}

EzSubscribe EzSubscribe::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzSubscribe);
}

gs2::chat::Subscribe EzSubscribe::ToModel() const
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

}}}