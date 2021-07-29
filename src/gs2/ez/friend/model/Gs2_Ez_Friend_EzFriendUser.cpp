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

#include "EzFriendUser.hpp"
#include <gs2/friend/model/FriendUser.hpp>


namespace gs2 { namespace ez { namespace friend_ {

EzFriendUser::Data::Data(const Data& data) :
    Gs2Object(data),
    userId(data.userId),
    publicProfile(data.publicProfile),
    friendProfile(data.friendProfile)
{
}

EzFriendUser::Data::Data(const gs2::friend_::FriendUser& friendUser) :
    userId(friendUser.getUserId() ? *friendUser.getUserId() : StringHolder()),
    publicProfile(friendUser.getPublicProfile() ? *friendUser.getPublicProfile() : StringHolder()),
    friendProfile(friendUser.getFriendProfile() ? *friendUser.getFriendProfile() : StringHolder())
{
}

EzFriendUser::Data::Data(const gs2::optional<gs2::friend_::FriendUser>& friendUser) :
    userId(friendUser && friendUser->getUserId() ? *friendUser->getUserId() : StringHolder()),
    publicProfile(friendUser && friendUser->getPublicProfile() ? *friendUser->getPublicProfile() : StringHolder()),
    friendProfile(friendUser && friendUser->getFriendProfile() ? *friendUser->getFriendProfile() : StringHolder())
{
}

EzFriendUser::EzFriendUser(gs2::friend_::FriendUser friendUser) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(friendUser)
{
}

EzFriendUser::EzFriendUser(gs2::optional<gs2::friend_::FriendUser> friendUser) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(friendUser)
{
}

EzFriendUser EzFriendUser::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzFriendUser);
}

gs2::friend_::FriendUser EzFriendUser::ToModel() const
{
    gs2::friend_::FriendUser friendUser;
    friendUser.setUserId(getUserId());
    friendUser.setPublicProfile(getPublicProfile());
    friendUser.setFriendProfile(getFriendProfile());
    return friendUser;
}

}}}