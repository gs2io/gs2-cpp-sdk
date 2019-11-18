

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

#ifndef GS2_EZ_FRIEND_MODEL_EZPROFILE_HPP_
#define GS2_EZ_FRIEND_MODEL_EZPROFILE_HPP_

#include <gs2/friend/model/Profile.hpp>


namespace gs2 { namespace ez { namespace friend_ {

class EzProfile : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** ユーザーID */
        gs2::optional<StringHolder> userId;
        /** 公開されるプロフィール */
        gs2::optional<StringHolder> publicProfile;
        /** フォロワー向けに公開されるプロフィール */
        gs2::optional<StringHolder> followerProfile;
        /** フレンド向けに公開されるプロフィール */
        gs2::optional<StringHolder> friendProfile;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            userId(data.userId),
            publicProfile(data.publicProfile),
            followerProfile(data.followerProfile),
            friendProfile(data.friendProfile)
        {
        }

        Data(Data&& data) = default;

        Data(const gs2::friend_::Profile& profile) :
            userId(profile.getUserId()),
            publicProfile(profile.getPublicProfile()),
            followerProfile(profile.getFollowerProfile()),
            friendProfile(profile.getFriendProfile())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzProfile() = default;
    EzProfile(const EzProfile& ezProfile) = default;
    EzProfile(EzProfile&& ezProfile) = default;
    ~EzProfile() = default;

    EzProfile(gs2::friend_::Profile profile) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(profile)
    {}

    EzProfile& operator=(const EzProfile& ezProfile) = default;
    EzProfile& operator=(EzProfile&& ezProfile) = default;

    EzProfile deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzProfile);
    }

    gs2::friend_::Profile ToModel() const
    {
        gs2::friend_::Profile profile;
        profile.setUserId(getUserId());
        profile.setPublicProfile(getPublicProfile());
        profile.setFollowerProfile(getFollowerProfile());
        profile.setFriendProfile(getFriendProfile());
        return profile;
    }

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getUserId() const
    {
        return *ensureData().userId;
    }

    const StringHolder& getPublicProfile() const
    {
        return *ensureData().publicProfile;
    }

    const StringHolder& getFollowerProfile() const
    {
        return *ensureData().followerProfile;
    }

    const StringHolder& getFriendProfile() const
    {
        return *ensureData().friendProfile;
    }

    // ========================================
    //   Setters
    // ========================================

    void setUserId(StringHolder userId)
    {
        ensureData().userId = std::move(userId);
    }

    void setPublicProfile(StringHolder publicProfile)
    {
        ensureData().publicProfile = std::move(publicProfile);
    }

    void setFollowerProfile(StringHolder followerProfile)
    {
        ensureData().followerProfile = std::move(followerProfile);
    }

    void setFriendProfile(StringHolder friendProfile)
    {
        ensureData().friendProfile = std::move(friendProfile);
    }

    EzProfile& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    EzProfile& withPublicProfile(StringHolder publicProfile)
    {
        setPublicProfile(std::move(publicProfile));
        return *this;
    }

    EzProfile& withFollowerProfile(StringHolder followerProfile)
    {
        setFollowerProfile(std::move(followerProfile));
        return *this;
    }

    EzProfile& withFriendProfile(StringHolder friendProfile)
    {
        setFriendProfile(std::move(friendProfile));
        return *this;
    }
};

}}}

#endif //GS2_EZ_FRIEND_EZPROFILE_HPP_