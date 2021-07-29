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

#include "EzFriendRequest.hpp"
#include <gs2/friend/model/FriendRequest.hpp>


namespace gs2 { namespace ez { namespace friend_ {

EzFriendRequest::Data::Data(const Data& data) :
    Gs2Object(data),
    userId(data.userId),
    targetUserId(data.targetUserId)
{
}

EzFriendRequest::Data::Data(const gs2::friend_::FriendRequest& friendRequest) :
    userId(friendRequest.getUserId() ? *friendRequest.getUserId() : StringHolder()),
    targetUserId(friendRequest.getTargetUserId() ? *friendRequest.getTargetUserId() : StringHolder())
{
}

EzFriendRequest::Data::Data(const gs2::optional<gs2::friend_::FriendRequest>& friendRequest) :
    userId(friendRequest && friendRequest->getUserId() ? *friendRequest->getUserId() : StringHolder()),
    targetUserId(friendRequest && friendRequest->getTargetUserId() ? *friendRequest->getTargetUserId() : StringHolder())
{
}

EzFriendRequest::EzFriendRequest(gs2::friend_::FriendRequest friendRequest) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(friendRequest)
{
}

EzFriendRequest::EzFriendRequest(gs2::optional<gs2::friend_::FriendRequest> friendRequest) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(friendRequest)
{
}

EzFriendRequest EzFriendRequest::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzFriendRequest);
}

gs2::friend_::FriendRequest EzFriendRequest::ToModel() const
{
    gs2::friend_::FriendRequest friendRequest;
    friendRequest.setUserId(getUserId());
    friendRequest.setTargetUserId(getTargetUserId());
    return friendRequest;
}

}}}