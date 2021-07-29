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

#include "EzSubscribeUser.hpp"
#include <gs2/ranking/model/SubscribeUser.hpp>


namespace gs2 { namespace ez { namespace ranking {

EzSubscribeUser::Data::Data(const Data& data) :
    Gs2Object(data),
    userId(data.userId),
    targetUserId(data.targetUserId)
{
}

EzSubscribeUser::Data::Data(const gs2::ranking::SubscribeUser& subscribeUser) :
    userId(subscribeUser.getUserId() ? *subscribeUser.getUserId() : StringHolder()),
    targetUserId(subscribeUser.getTargetUserId() ? *subscribeUser.getTargetUserId() : StringHolder())
{
}

EzSubscribeUser::Data::Data(const gs2::optional<gs2::ranking::SubscribeUser>& subscribeUser) :
    userId(subscribeUser && subscribeUser->getUserId() ? *subscribeUser->getUserId() : StringHolder()),
    targetUserId(subscribeUser && subscribeUser->getTargetUserId() ? *subscribeUser->getTargetUserId() : StringHolder())
{
}

EzSubscribeUser::EzSubscribeUser(gs2::ranking::SubscribeUser subscribeUser) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(subscribeUser)
{
}

EzSubscribeUser::EzSubscribeUser(gs2::optional<gs2::ranking::SubscribeUser> subscribeUser) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(subscribeUser)
{
}

EzSubscribeUser EzSubscribeUser::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzSubscribeUser);
}

gs2::ranking::SubscribeUser EzSubscribeUser::ToModel() const
{
    gs2::ranking::SubscribeUser subscribeUser;
    subscribeUser.setUserId(getUserId());
    subscribeUser.setTargetUserId(getTargetUserId());
    return subscribeUser;
}

}}}