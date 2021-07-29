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

#ifndef GS2_EZ_FRIEND_MODEL_EZFOLLOWUSER_HPP_
#define GS2_EZ_FRIEND_MODEL_EZFOLLOWUSER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace friend_ {

class FollowUser;

}

namespace ez { namespace friend_ {

class EzFollowUser : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** ユーザーID */
        StringHolder userId;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::friend_::FollowUser& followUser);
        Data(const gs2::optional<gs2::friend_::FollowUser>& followUser);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzFollowUser() = default;
    EzFollowUser(const EzFollowUser& ezFollowUser) = default;
    EzFollowUser(EzFollowUser&& ezFollowUser) = default;
    ~EzFollowUser() = default;

    EzFollowUser(gs2::friend_::FollowUser followUser);
    EzFollowUser(gs2::optional<gs2::friend_::FollowUser> followUser);

    EzFollowUser& operator=(const EzFollowUser& ezFollowUser) = default;
    EzFollowUser& operator=(EzFollowUser&& ezFollowUser) = default;

    EzFollowUser deepCopy() const;

    gs2::friend_::FollowUser ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getUserId() const
    {
        return ensureData().userId;
    }

    // ========================================
    //   Setters
    // ========================================

    void setUserId(StringHolder userId)
    {
        ensureData().userId = std::move(userId);
    }

    EzFollowUser& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }
};

}}}

#endif //GS2_EZ_FRIEND_EZFOLLOWUSER_HPP_