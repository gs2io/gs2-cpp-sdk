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

#ifndef GS2_EZ_FRIEND_MODEL_EZFRIENDREQUEST_HPP_
#define GS2_EZ_FRIEND_MODEL_EZFRIENDREQUEST_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace friend_ {

class FriendRequest;

}

namespace ez { namespace friend_ {

class EzFriendRequest : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** ユーザーID */
        gs2::optional<StringHolder> userId;
        /** ユーザーID */
        gs2::optional<StringHolder> targetUserId;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::friend_::FriendRequest& friendRequest);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzFriendRequest() = default;
    EzFriendRequest(const EzFriendRequest& ezFriendRequest) = default;
    EzFriendRequest(EzFriendRequest&& ezFriendRequest) = default;
    ~EzFriendRequest() = default;

    EzFriendRequest(gs2::friend_::FriendRequest friendRequest);

    EzFriendRequest& operator=(const EzFriendRequest& ezFriendRequest) = default;
    EzFriendRequest& operator=(EzFriendRequest&& ezFriendRequest) = default;

    EzFriendRequest deepCopy() const;

    gs2::friend_::FriendRequest ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getUserId() const
    {
        return *ensureData().userId;
    }

    const StringHolder& getTargetUserId() const
    {
        return *ensureData().targetUserId;
    }

    // ========================================
    //   Setters
    // ========================================

    void setUserId(StringHolder userId)
    {
        ensureData().userId = std::move(userId);
    }

    void setTargetUserId(StringHolder targetUserId)
    {
        ensureData().targetUserId = std::move(targetUserId);
    }

    EzFriendRequest& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    EzFriendRequest& withTargetUserId(StringHolder targetUserId)
    {
        setTargetUserId(std::move(targetUserId));
        return *this;
    }
};

}}}

#endif //GS2_EZ_FRIEND_EZFRIENDREQUEST_HPP_