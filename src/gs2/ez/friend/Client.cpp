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
#include <gs2/friend/Gs2FriendWebSocketClient.hpp>
#include <gs2/friend/Gs2FriendRestClient.hpp>


namespace gs2 { namespace ez { namespace friend_ {

Client::Client(gs2::ez::Profile& profile) :
    m_Profile(profile),
    m_pWebSocketClient(new gs2::friend_::Gs2FriendWebSocketClient(profile.getGs2WebSocketSession())),
    m_pRestClient(new gs2::friend_::Gs2FriendRestClient(profile.getGs2RestSession()))
{
}

Client::~Client()
{
    delete m_pWebSocketClient;
    delete m_pRestClient;
}

void Client::getProfile(
    std::function<void(AsyncEzGetProfileResult)> callback,
    GameSession& session,
    StringHolder namespaceName
)
{
    gs2::friend_::GetProfileRequest request;
    request.setNamespaceName(namespaceName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pWebSocketClient->getProfile(
        request,
        [callback](gs2::friend_::AsyncGetProfileResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetProfileResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetProfileResult::isConvertible(*r.getResult()))
            {
                EzGetProfileResult ezResult(*r.getResult());
                AsyncEzGetProfileResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetProfileResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::updateProfile(
    std::function<void(AsyncEzUpdateProfileResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    gs2::optional<StringHolder> publicProfile,
    gs2::optional<StringHolder> followerProfile,
    gs2::optional<StringHolder> friendProfile
)
{
    gs2::friend_::UpdateProfileRequest request;
    request.setNamespaceName(namespaceName);
    if (publicProfile)
    {
        request.setPublicProfile(std::move(*publicProfile));
    }
    if (followerProfile)
    {
        request.setFollowerProfile(std::move(*followerProfile));
    }
    if (friendProfile)
    {
        request.setFriendProfile(std::move(*friendProfile));
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pWebSocketClient->updateProfile(
        request,
        [callback](gs2::friend_::AsyncUpdateProfileResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzUpdateProfileResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzUpdateProfileResult::isConvertible(*r.getResult()))
            {
                EzUpdateProfileResult ezResult(*r.getResult());
                AsyncEzUpdateProfileResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzUpdateProfileResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getPublicProfile(
    std::function<void(AsyncEzGetPublicProfileResult)> callback,
    StringHolder namespaceName,
    StringHolder userId
)
{
    gs2::friend_::GetPublicProfileRequest request;
    request.setNamespaceName(namespaceName);
    request.setUserId(userId);
    m_pWebSocketClient->getPublicProfile(
        request,
        [callback](gs2::friend_::AsyncGetPublicProfileResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetPublicProfileResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetPublicProfileResult::isConvertible(*r.getResult()))
            {
                EzGetPublicProfileResult ezResult(*r.getResult());
                AsyncEzGetPublicProfileResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetPublicProfileResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::describeFollowUsers(
    std::function<void(AsyncEzDescribeFollowUsersResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    Bool withProfile,
    gs2::optional<StringHolder> pageToken,
    gs2::optional<Int64> limit
)
{
    gs2::friend_::DescribeFollowsRequest request;
    request.setNamespaceName(namespaceName);
    request.setWithProfile(withProfile);
    if (pageToken)
    {
        request.setPageToken(std::move(*pageToken));
    }
    if (limit)
    {
        request.setLimit(std::move(*limit));
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pRestClient->describeFollows(
        request,
        [callback](gs2::friend_::AsyncDescribeFollowsResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzDescribeFollowUsersResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzDescribeFollowUsersResult::isConvertible(*r.getResult()))
            {
                EzDescribeFollowUsersResult ezResult(*r.getResult());
                AsyncEzDescribeFollowUsersResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzDescribeFollowUsersResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::follow(
    std::function<void(AsyncEzFollowResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder targetUserId
)
{
    gs2::friend_::FollowRequest request;
    request.setNamespaceName(namespaceName);
    request.setTargetUserId(targetUserId);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pWebSocketClient->follow(
        request,
        [callback](gs2::friend_::AsyncFollowResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzFollowResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzFollowResult::isConvertible(*r.getResult()))
            {
                EzFollowResult ezResult(*r.getResult());
                AsyncEzFollowResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzFollowResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::unfollow(
    std::function<void(AsyncEzUnfollowResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder targetUserId
)
{
    gs2::friend_::UnfollowRequest request;
    request.setNamespaceName(namespaceName);
    request.setTargetUserId(targetUserId);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pWebSocketClient->unfollow(
        request,
        [callback](gs2::friend_::AsyncUnfollowResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzUnfollowResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzUnfollowResult::isConvertible(*r.getResult()))
            {
                EzUnfollowResult ezResult(*r.getResult());
                AsyncEzUnfollowResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzUnfollowResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::describeFriends(
    std::function<void(AsyncEzDescribeFriendsResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    Bool withProfile,
    gs2::optional<StringHolder> pageToken,
    gs2::optional<Int64> limit
)
{
    gs2::friend_::DescribeFriendsRequest request;
    request.setNamespaceName(namespaceName);
    request.setWithProfile(withProfile);
    if (pageToken)
    {
        request.setPageToken(std::move(*pageToken));
    }
    if (limit)
    {
        request.setLimit(std::move(*limit));
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pRestClient->describeFriends(
        request,
        [callback](gs2::friend_::AsyncDescribeFriendsResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzDescribeFriendsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzDescribeFriendsResult::isConvertible(*r.getResult()))
            {
                EzDescribeFriendsResult ezResult(*r.getResult());
                AsyncEzDescribeFriendsResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzDescribeFriendsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getFriend(
    std::function<void(AsyncEzGetFriendResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder targetUserId,
    Bool withProfile
)
{
    gs2::friend_::GetFriendRequest request;
    request.setNamespaceName(namespaceName);
    request.setTargetUserId(targetUserId);
    request.setWithProfile(withProfile);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pWebSocketClient->getFriend(
        request,
        [callback](gs2::friend_::AsyncGetFriendResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetFriendResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetFriendResult::isConvertible(*r.getResult()))
            {
                EzGetFriendResult ezResult(*r.getResult());
                AsyncEzGetFriendResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetFriendResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::deleteFriend(
    std::function<void(AsyncEzDeleteFriendResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder targetUserId
)
{
    gs2::friend_::DeleteFriendRequest request;
    request.setNamespaceName(namespaceName);
    request.setTargetUserId(targetUserId);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pWebSocketClient->deleteFriend(
        request,
        [callback](gs2::friend_::AsyncDeleteFriendResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzDeleteFriendResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzDeleteFriendResult::isConvertible(*r.getResult()))
            {
                EzDeleteFriendResult ezResult(*r.getResult());
                AsyncEzDeleteFriendResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzDeleteFriendResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::describeSendRequests(
    std::function<void(AsyncEzDescribeSendRequestsResult)> callback,
    GameSession& session,
    StringHolder namespaceName
)
{
    gs2::friend_::DescribeSendRequestsRequest request;
    request.setNamespaceName(namespaceName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pRestClient->describeSendRequests(
        request,
        [callback](gs2::friend_::AsyncDescribeSendRequestsResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzDescribeSendRequestsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzDescribeSendRequestsResult::isConvertible(*r.getResult()))
            {
                EzDescribeSendRequestsResult ezResult(*r.getResult());
                AsyncEzDescribeSendRequestsResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzDescribeSendRequestsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::sendRequest(
    std::function<void(AsyncEzSendRequestResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder targetUserId
)
{
    gs2::friend_::SendRequestRequest request;
    request.setNamespaceName(namespaceName);
    request.setTargetUserId(targetUserId);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pWebSocketClient->sendRequest(
        request,
        [callback](gs2::friend_::AsyncSendRequestResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzSendRequestResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzSendRequestResult::isConvertible(*r.getResult()))
            {
                EzSendRequestResult ezResult(*r.getResult());
                AsyncEzSendRequestResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzSendRequestResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::deleteRequest(
    std::function<void(AsyncEzDeleteRequestResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder targetUserId
)
{
    gs2::friend_::DeleteRequestRequest request;
    request.setNamespaceName(namespaceName);
    request.setTargetUserId(targetUserId);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pWebSocketClient->deleteRequest(
        request,
        [callback](gs2::friend_::AsyncDeleteRequestResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzDeleteRequestResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzDeleteRequestResult::isConvertible(*r.getResult()))
            {
                EzDeleteRequestResult ezResult(*r.getResult());
                AsyncEzDeleteRequestResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzDeleteRequestResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::describeReceiveRequests(
    std::function<void(AsyncEzDescribeReceiveRequestsResult)> callback,
    GameSession& session,
    StringHolder namespaceName
)
{
    gs2::friend_::DescribeReceiveRequestsRequest request;
    request.setNamespaceName(namespaceName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pRestClient->describeReceiveRequests(
        request,
        [callback](gs2::friend_::AsyncDescribeReceiveRequestsResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzDescribeReceiveRequestsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzDescribeReceiveRequestsResult::isConvertible(*r.getResult()))
            {
                EzDescribeReceiveRequestsResult ezResult(*r.getResult());
                AsyncEzDescribeReceiveRequestsResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzDescribeReceiveRequestsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::accept(
    std::function<void(AsyncEzAcceptResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder fromUserId
)
{
    gs2::friend_::AcceptRequestRequest request;
    request.setNamespaceName(namespaceName);
    request.setFromUserId(fromUserId);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pWebSocketClient->acceptRequest(
        request,
        [callback](gs2::friend_::AsyncAcceptRequestResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzAcceptResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzAcceptResult::isConvertible(*r.getResult()))
            {
                EzAcceptResult ezResult(*r.getResult());
                AsyncEzAcceptResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzAcceptResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::reject(
    std::function<void(AsyncEzRejectResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder fromUserId
)
{
    gs2::friend_::RejectRequestRequest request;
    request.setNamespaceName(namespaceName);
    request.setFromUserId(fromUserId);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pWebSocketClient->rejectRequest(
        request,
        [callback](gs2::friend_::AsyncRejectRequestResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzRejectResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzRejectResult::isConvertible(*r.getResult()))
            {
                EzRejectResult ezResult(*r.getResult());
                AsyncEzRejectResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzRejectResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getBlackList(
    std::function<void(AsyncEzGetBlackListResult)> callback,
    GameSession& session,
    StringHolder namespaceName
)
{
    gs2::friend_::DescribeBlackListRequest request;
    request.setNamespaceName(namespaceName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pRestClient->describeBlackList(
        request,
        [callback](gs2::friend_::AsyncDescribeBlackListResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetBlackListResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetBlackListResult::isConvertible(*r.getResult()))
            {
                EzGetBlackListResult ezResult(*r.getResult());
                AsyncEzGetBlackListResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetBlackListResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::registerBlackList(
    std::function<void(AsyncEzRegisterBlackListResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder targetUserId
)
{
    gs2::friend_::RegisterBlackListRequest request;
    request.setNamespaceName(namespaceName);
    request.setTargetUserId(targetUserId);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pWebSocketClient->registerBlackList(
        request,
        [callback](gs2::friend_::AsyncRegisterBlackListResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzRegisterBlackListResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzRegisterBlackListResult::isConvertible(*r.getResult()))
            {
                EzRegisterBlackListResult ezResult(*r.getResult());
                AsyncEzRegisterBlackListResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzRegisterBlackListResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::unregisterBlackList(
    std::function<void(AsyncEzUnregisterBlackListResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder targetUserId
)
{
    gs2::friend_::UnregisterBlackListRequest request;
    request.setNamespaceName(namespaceName);
    request.setTargetUserId(targetUserId);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pWebSocketClient->unregisterBlackList(
        request,
        [callback](gs2::friend_::AsyncUnregisterBlackListResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzUnregisterBlackListResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzUnregisterBlackListResult::isConvertible(*r.getResult()))
            {
                EzUnregisterBlackListResult ezResult(*r.getResult());
                AsyncEzUnregisterBlackListResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzUnregisterBlackListResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

}}}