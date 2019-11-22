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

#ifndef GS2_FRIEND_MODEL_FOLLOWUSER_HPP_
#define GS2_FRIEND_MODEL_FOLLOWUSER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>

namespace gs2 { namespace friend_ {

/**
 * フォローしているユーザー
 *
 * @author Game Server Services, Inc.
 *
 */
class FollowUser : public Gs2Object
{
    friend bool operator!=(const FollowUser& lhs, const FollowUser& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** ユーザーID */
        optional<StringHolder> userId;
        /** 公開されるプロフィール */
        optional<StringHolder> publicProfile;
        /** フォロワー向けに公開されるプロフィール */
        optional<StringHolder> followerProfile;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        ~Data() GS2_OVERRIDE = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        void set(const Char name_[], const detail::json::JsonConstValue& jsonValue) GS2_OVERRIDE;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    FollowUser() = default;
    FollowUser(const FollowUser& followUser) = default;
    FollowUser(FollowUser&& followUser) = default;
    ~FollowUser() = default;

    FollowUser& operator=(const FollowUser& followUser) = default;
    FollowUser& operator=(FollowUser&& followUser) = default;

    FollowUser deepCopy() const;

    const FollowUser* operator->() const
    {
        return this;
    }

    FollowUser* operator->()
    {
        return this;
    }
    /**
     * ユーザーIDを取得
     *
     * @return ユーザーID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    void setUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    FollowUser& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    /**
     * 公開されるプロフィールを取得
     *
     * @return 公開されるプロフィール
     */
    const optional<StringHolder>& getPublicProfile() const
    {
        return ensureData().publicProfile;
    }

    /**
     * 公開されるプロフィールを設定
     *
     * @param publicProfile 公開されるプロフィール
     */
    void setPublicProfile(StringHolder publicProfile)
    {
        ensureData().publicProfile.emplace(std::move(publicProfile));
    }

    /**
     * 公開されるプロフィールを設定
     *
     * @param publicProfile 公開されるプロフィール
     */
    FollowUser& withPublicProfile(StringHolder publicProfile)
    {
        setPublicProfile(std::move(publicProfile));
        return *this;
    }

    /**
     * フォロワー向けに公開されるプロフィールを取得
     *
     * @return フォロワー向けに公開されるプロフィール
     */
    const optional<StringHolder>& getFollowerProfile() const
    {
        return ensureData().followerProfile;
    }

    /**
     * フォロワー向けに公開されるプロフィールを設定
     *
     * @param followerProfile フォロワー向けに公開されるプロフィール
     */
    void setFollowerProfile(StringHolder followerProfile)
    {
        ensureData().followerProfile.emplace(std::move(followerProfile));
    }

    /**
     * フォロワー向けに公開されるプロフィールを設定
     *
     * @param followerProfile フォロワー向けに公開されるプロフィール
     */
    FollowUser& withFollowerProfile(StringHolder followerProfile)
    {
        setFollowerProfile(std::move(followerProfile));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const FollowUser& lhs, const FollowUser& lhr);

inline bool operator==(const FollowUser& lhs, const FollowUser& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_FRIEND_MODEL_FOLLOWUSER_HPP_