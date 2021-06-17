/*
 * Copyright 2016 Game Server Services, Inc. or its affiliates. All Rights
 * Reserved.
 *
 * Licensed under the Apache License, Version 2.0(the "License").
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

#include "Client.hpp"
#include "../Profile.hpp"
#include "../GameSession.hpp"
#include <gs2/chat/Gs2ChatWebSocketClient.hpp>


namespace gs2 { namespace ez { namespace chat {

Client::Client(gs2::ez::Profile& profile) :
    m_Profile(profile),
    m_pClient(new gs2::chat::Gs2ChatWebSocketClient(profile.getGs2Session()))
{
}

Client::~Client()
{
    delete m_pClient;
}

void Client::createRoom(
    std::function<void(AsyncEzCreateRoomResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    gs2::optional<StringHolder> name,
    gs2::optional<StringHolder> metadata,
    gs2::optional<StringHolder> password,
    gs2::optional<List<StringHolder>> whiteListUserIds
)
{
    gs2::chat::CreateRoomRequest request;
    request.setNamespaceName(namespaceName);
    if (name)
    {
        request.setName(std::move(*name));
    }
    if (metadata)
    {
        request.setMetadata(std::move(*metadata));
    }
    if (password)
    {
        request.setPassword(std::move(*password));
    }
    if (whiteListUserIds)
    {
        request.setWhiteListUserIds(std::move(*whiteListUserIds));
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pClient->createRoom(
        request,
        [callback](gs2::chat::AsyncCreateRoomResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzCreateRoomResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzCreateRoomResult::isConvertible(*r.getResult()))
            {
                EzCreateRoomResult ezResult(*r.getResult());
                AsyncEzCreateRoomResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzCreateRoomResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getRoom(
    std::function<void(AsyncEzGetRoomResult)> callback,
    StringHolder namespaceName,
    StringHolder roomName
)
{
    gs2::chat::GetRoomRequest request;
    request.setNamespaceName(namespaceName);
    request.setRoomName(roomName);
    m_pClient->getRoom(
        request,
        [callback](gs2::chat::AsyncGetRoomResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetRoomResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetRoomResult::isConvertible(*r.getResult()))
            {
                EzGetRoomResult ezResult(*r.getResult());
                AsyncEzGetRoomResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetRoomResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::deleteRoom(
    std::function<void(AsyncEzDeleteRoomResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder roomName
)
{
    gs2::chat::DeleteRoomRequest request;
    request.setNamespaceName(namespaceName);
    request.setRoomName(roomName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pClient->deleteRoom(
        request,
        [callback](gs2::chat::AsyncDeleteRoomResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzDeleteRoomResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzDeleteRoomResult::isConvertible(*r.getResult()))
            {
                EzDeleteRoomResult ezResult(*r.getResult());
                AsyncEzDeleteRoomResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzDeleteRoomResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::post(
    std::function<void(AsyncEzPostResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder roomName,
    Int32 category,
    StringHolder metadata,
    gs2::optional<StringHolder> password
)
{
    gs2::chat::PostRequest request;
    request.setNamespaceName(namespaceName);
    request.setRoomName(roomName);
    request.setCategory(category);
    request.setMetadata(metadata);
    if (password)
    {
        request.setPassword(std::move(*password));
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pClient->post(
        request,
        [callback](gs2::chat::AsyncPostResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzPostResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzPostResult::isConvertible(*r.getResult()))
            {
                EzPostResult ezResult(*r.getResult());
                AsyncEzPostResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzPostResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::listMessages(
    std::function<void(AsyncEzListMessagesResult)> callback,
    StringHolder namespaceName,
    StringHolder roomName,
    gs2::optional<Int64> startAt,
    gs2::optional<Int64> limit,
    gs2::optional<StringHolder> password
)
{
    gs2::chat::DescribeMessagesRequest request;
    request.setNamespaceName(namespaceName);
    request.setRoomName(roomName);
    if (startAt)
    {
        request.setStartAt(std::move(*startAt));
    }
    if (limit)
    {
        request.setLimit(std::move(*limit));
    }
    if (password)
    {
        request.setPassword(std::move(*password));
    }
    m_pClient->describeMessages(
        request,
        [callback](gs2::chat::AsyncDescribeMessagesResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListMessagesResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzListMessagesResult::isConvertible(*r.getResult()))
            {
                EzListMessagesResult ezResult(*r.getResult());
                AsyncEzListMessagesResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzListMessagesResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::listSubscribeRooms(
    std::function<void(AsyncEzListSubscribeRoomsResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    gs2::optional<StringHolder> pageToken,
    gs2::optional<Int64> limit
)
{
    gs2::chat::DescribeSubscribesRequest request;
    request.setNamespaceName(namespaceName);
    if (pageToken)
    {
        request.setPageToken(std::move(*pageToken));
    }
    if (limit)
    {
        request.setLimit(std::move(*limit));
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pClient->describeSubscribes(
        request,
        [callback](gs2::chat::AsyncDescribeSubscribesResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListSubscribeRoomsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzListSubscribeRoomsResult::isConvertible(*r.getResult()))
            {
                EzListSubscribeRoomsResult ezResult(*r.getResult());
                AsyncEzListSubscribeRoomsResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzListSubscribeRoomsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::subscribe(
    std::function<void(AsyncEzSubscribeResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder roomName,
    gs2::optional<List<EzNotificationType>> notificationTypes
)
{
    gs2::chat::SubscribeRequest request;
    request.setNamespaceName(namespaceName);
    request.setRoomName(roomName);
    if (notificationTypes)
    {
        gs2::List<gs2::chat::NotificationType> list;
        for (int i = 0; i < notificationTypes->getCount(); ++i)
        {
            list += (*notificationTypes)[i].ToModel();
        }
        request.setNotificationTypes(list);
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pClient->subscribe(
        request,
        [callback](gs2::chat::AsyncSubscribeResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzSubscribeResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzSubscribeResult::isConvertible(*r.getResult()))
            {
                EzSubscribeResult ezResult(*r.getResult());
                AsyncEzSubscribeResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzSubscribeResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::updateSubscribeSetting(
    std::function<void(AsyncEzUpdateSubscribeSettingResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder roomName,
    gs2::optional<List<EzNotificationType>> notificationTypes
)
{
    gs2::chat::UpdateNotificationTypeRequest request;
    request.setNamespaceName(namespaceName);
    request.setRoomName(roomName);
    if (notificationTypes)
    {
        gs2::List<gs2::chat::NotificationType> list;
        for (int i = 0; i < notificationTypes->getCount(); ++i)
        {
            list += (*notificationTypes)[i].ToModel();
        }
        request.setNotificationTypes(list);
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pClient->updateNotificationType(
        request,
        [callback](gs2::chat::AsyncUpdateNotificationTypeResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzUpdateSubscribeSettingResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzUpdateSubscribeSettingResult::isConvertible(*r.getResult()))
            {
                EzUpdateSubscribeSettingResult ezResult(*r.getResult());
                AsyncEzUpdateSubscribeSettingResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzUpdateSubscribeSettingResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::unsubscribe(
    std::function<void(AsyncEzUnsubscribeResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder roomName
)
{
    gs2::chat::UnsubscribeRequest request;
    request.setNamespaceName(namespaceName);
    request.setRoomName(roomName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pClient->unsubscribe(
        request,
        [callback](gs2::chat::AsyncUnsubscribeResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzUnsubscribeResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzUnsubscribeResult::isConvertible(*r.getResult()))
            {
                EzUnsubscribeResult ezResult(*r.getResult());
                AsyncEzUnsubscribeResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzUnsubscribeResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

}}}