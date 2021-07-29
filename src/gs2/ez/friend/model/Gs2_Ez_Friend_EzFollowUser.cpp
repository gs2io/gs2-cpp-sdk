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

#include "EzFollowUser.hpp"
#include <gs2/friend/model/FollowUser.hpp>


namespace gs2 { namespace ez { namespace friend_ {

EzFollowUser::Data::Data(const Data& data) :
    Gs2Object(data),
    userId(data.userId)
{
}

EzFollowUser::Data::Data(const gs2::friend_::FollowUser& followUser) :
    userId(followUser.getUserId() ? *followUser.getUserId() : StringHolder())
{
}

EzFollowUser::Data::Data(const gs2::optional<gs2::friend_::FollowUser>& followUser) :
    userId(followUser && followUser->getUserId() ? *followUser->getUserId() : StringHolder())
{
}

EzFollowUser::EzFollowUser(gs2::friend_::FollowUser followUser) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(followUser)
{
}

EzFollowUser::EzFollowUser(gs2::optional<gs2::friend_::FollowUser> followUser) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(followUser)
{
}

EzFollowUser EzFollowUser::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzFollowUser);
}

gs2::friend_::FollowUser EzFollowUser::ToModel() const
{
    gs2::friend_::FollowUser followUser;
    followUser.setUserId(getUserId());
    return followUser;
}

}}}