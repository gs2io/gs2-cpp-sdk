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

#include "EzPublicProfile.hpp"
#include <gs2/friend/model/PublicProfile.hpp>


namespace gs2 { namespace ez { namespace friend_ {

EzPublicProfile::Data::Data(const Data& data) :
    Gs2Object(data),
    userId(data.userId),
    publicProfile(data.publicProfile)
{
}

EzPublicProfile::Data::Data(const gs2::friend_::PublicProfile& publicProfile) :
    userId(publicProfile.getUserId() ? *publicProfile.getUserId() : StringHolder()),
    publicProfile(publicProfile.getPublicProfile() ? *publicProfile.getPublicProfile() : StringHolder())
{
}

EzPublicProfile::Data::Data(const gs2::optional<gs2::friend_::PublicProfile>& publicProfile) :
    userId(publicProfile && publicProfile->getUserId() ? *publicProfile->getUserId() : StringHolder()),
    publicProfile(publicProfile && publicProfile->getPublicProfile() ? *publicProfile->getPublicProfile() : StringHolder())
{
}

EzPublicProfile::EzPublicProfile(gs2::friend_::PublicProfile publicProfile) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(publicProfile)
{
}

EzPublicProfile::EzPublicProfile(gs2::optional<gs2::friend_::PublicProfile> publicProfile) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(publicProfile)
{
}

EzPublicProfile EzPublicProfile::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzPublicProfile);
}

gs2::friend_::PublicProfile EzPublicProfile::ToModel() const
{
    gs2::friend_::PublicProfile publicProfile;
    publicProfile.setUserId(getUserId());
    publicProfile.setPublicProfile(getPublicProfile());
    return publicProfile;
}

}}}