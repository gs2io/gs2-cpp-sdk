

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

#ifndef GS2_EZ_FRIEND_MODEL_EZFRIENDUSER_HPP_
#define GS2_EZ_FRIEND_MODEL_EZFRIENDUSER_HPP_

#include <gs2/friend/model/FriendUser.hpp>


namespace gs2 { namespace ez { namespace friend_ {

class EzFriendUser : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** ユーザーID */
        gs2::optional<StringHolder> userId;
        /** 公開されるプロフィール */
        gs2::optional<StringHolder> publicProfile;
        /** フレンド向けに公開されるプロフィール */
        gs2::optional<StringHolder> friendProfile;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            userId(data.userId),
            publicProfile(data.publicProfile),
            friendProfile(data.friendProfile)
        {
        }

        Data(Data&& data) = default;

        Data(const gs2::friend_::FriendUser& friendUser) :
            userId(friendUser.getUserId()),
            publicProfile(friendUser.getPublicProfile()),
            friendProfile(friendUser.getFriendProfile())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzFriendUser() = default;
    EzFriendUser(const EzFriendUser& ezFriendUser) = default;
    EzFriendUser(EzFriendUser&& ezFriendUser) = default;
    ~EzFriendUser() = default;

    EzFriendUser(gs2::friend_::FriendUser friendUser) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(friendUser)
    {}

    EzFriendUser& operator=(const EzFriendUser& ezFriendUser) = default;
    EzFriendUser& operator=(EzFriendUser&& ezFriendUser) = default;

    EzFriendUser deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzFriendUser);
    }

    gs2::friend_::FriendUser ToModel() const
    {
        gs2::friend_::FriendUser friendUser;
        friendUser.setUserId(getUserId());
        friendUser.setPublicProfile(getPublicProfile());
        friendUser.setFriendProfile(getFriendProfile());
        return friendUser;
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

    void setFriendProfile(StringHolder friendProfile)
    {
        ensureData().friendProfile = std::move(friendProfile);
    }

    EzFriendUser& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    EzFriendUser& withPublicProfile(StringHolder publicProfile)
    {
        setPublicProfile(std::move(publicProfile));
        return *this;
    }

    EzFriendUser& withFriendProfile(StringHolder friendProfile)
    {
        setFriendProfile(std::move(friendProfile));
        return *this;
    }
};

}}}

#endif //GS2_EZ_FRIEND_EZFRIENDUSER_HPP_