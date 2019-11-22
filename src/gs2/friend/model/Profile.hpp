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

#ifndef GS2_FRIEND_MODEL_PROFILE_HPP_
#define GS2_FRIEND_MODEL_PROFILE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>

namespace gs2 { namespace friend_ {

/**
 * プロフィール
 *
 * @author Game Server Services, Inc.
 *
 */
class Profile : public Gs2Object
{
    friend bool operator!=(const Profile& lhs, const Profile& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** プロフィール */
        optional<StringHolder> profileId;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** 公開されるプロフィール */
        optional<StringHolder> publicProfile;
        /** フォロワー向けに公開されるプロフィール */
        optional<StringHolder> followerProfile;
        /** フレンド向けに公開されるプロフィール */
        optional<StringHolder> friendProfile;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

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
    Profile() = default;
    Profile(const Profile& profile) = default;
    Profile(Profile&& profile) = default;
    ~Profile() = default;

    Profile& operator=(const Profile& profile) = default;
    Profile& operator=(Profile&& profile) = default;

    Profile deepCopy() const;

    const Profile* operator->() const
    {
        return this;
    }

    Profile* operator->()
    {
        return this;
    }
    /**
     * プロフィールを取得
     *
     * @return プロフィール
     */
    const optional<StringHolder>& getProfileId() const
    {
        return ensureData().profileId;
    }

    /**
     * プロフィールを設定
     *
     * @param profileId プロフィール
     */
    void setProfileId(StringHolder profileId)
    {
        ensureData().profileId.emplace(std::move(profileId));
    }

    /**
     * プロフィールを設定
     *
     * @param profileId プロフィール
     */
    Profile& withProfileId(StringHolder profileId)
    {
        setProfileId(std::move(profileId));
        return *this;
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
    Profile& withUserId(StringHolder userId)
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
    Profile& withPublicProfile(StringHolder publicProfile)
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
    Profile& withFollowerProfile(StringHolder followerProfile)
    {
        setFollowerProfile(std::move(followerProfile));
        return *this;
    }

    /**
     * フレンド向けに公開されるプロフィールを取得
     *
     * @return フレンド向けに公開されるプロフィール
     */
    const optional<StringHolder>& getFriendProfile() const
    {
        return ensureData().friendProfile;
    }

    /**
     * フレンド向けに公開されるプロフィールを設定
     *
     * @param friendProfile フレンド向けに公開されるプロフィール
     */
    void setFriendProfile(StringHolder friendProfile)
    {
        ensureData().friendProfile.emplace(std::move(friendProfile));
    }

    /**
     * フレンド向けに公開されるプロフィールを設定
     *
     * @param friendProfile フレンド向けに公開されるプロフィール
     */
    Profile& withFriendProfile(StringHolder friendProfile)
    {
        setFriendProfile(std::move(friendProfile));
        return *this;
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getCreatedAt() const
    {
        return ensureData().createdAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    void setCreatedAt(Int64 createdAt)
    {
        ensureData().createdAt.emplace(createdAt);
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    Profile& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }

    /**
     * 最終更新日時を取得
     *
     * @return 最終更新日時
     */
    const optional<Int64>& getUpdatedAt() const
    {
        return ensureData().updatedAt;
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    void setUpdatedAt(Int64 updatedAt)
    {
        ensureData().updatedAt.emplace(updatedAt);
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    Profile& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const Profile& lhs, const Profile& lhr);

inline bool operator==(const Profile& lhs, const Profile& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_FRIEND_MODEL_PROFILE_HPP_