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

#ifndef GS2_FRIEND_CONTROL_UPDATEPROFILEBYUSERIDREQUEST_HPP_
#define GS2_FRIEND_CONTROL_UPDATEPROFILEBYUSERIDREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/friend/Gs2FriendConst.hpp>
#include <gs2/friend/model/model.hpp>
#include <memory>

namespace gs2 { namespace friend_
{

/**
 * ユーザーIDを指定してプロフィールを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateProfileByUserIdRequest : public Gs2BasicRequest, public Gs2Friend
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** 公開されるプロフィール */
        optional<StringHolder> publicProfile;
        /** フォロワー向けに公開されるプロフィール */
        optional<StringHolder> followerProfile;
        /** フレンド向けに公開されるプロフィール */
        optional<StringHolder> friendProfile;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            userId(data.userId),
            publicProfile(data.publicProfile),
            followerProfile(data.followerProfile),
            friendProfile(data.friendProfile),
            duplicationAvoider(data.duplicationAvoider)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

    Gs2BasicRequest::Data& getData_() GS2_OVERRIDE
    {
        return ensureData();
    }

    const Gs2BasicRequest::Data& getData_() const GS2_OVERRIDE
    {
        return ensureData();
    }

public:
    UpdateProfileByUserIdRequest() = default;
    UpdateProfileByUserIdRequest(const UpdateProfileByUserIdRequest& updateProfileByUserIdRequest) = default;
    UpdateProfileByUserIdRequest(UpdateProfileByUserIdRequest&& updateProfileByUserIdRequest) = default;
    ~UpdateProfileByUserIdRequest() GS2_OVERRIDE = default;

    UpdateProfileByUserIdRequest& operator=(const UpdateProfileByUserIdRequest& updateProfileByUserIdRequest) = default;
    UpdateProfileByUserIdRequest& operator=(UpdateProfileByUserIdRequest&& updateProfileByUserIdRequest) = default;

    UpdateProfileByUserIdRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(UpdateProfileByUserIdRequest);
    }

    const UpdateProfileByUserIdRequest* operator->() const
    {
        return this;
    }

    UpdateProfileByUserIdRequest* operator->()
    {
        return this;
    }

    /**
     * ネームスペース名を取得
     *
     * @return ネームスペース名
     */
    const optional<StringHolder>& getNamespaceName() const
    {
        return ensureData().namespaceName;
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    void setNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    UpdateProfileByUserIdRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
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
    UpdateProfileByUserIdRequest& withUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
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
    UpdateProfileByUserIdRequest& withPublicProfile(StringHolder publicProfile)
    {
        ensureData().publicProfile.emplace(std::move(publicProfile));
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
    UpdateProfileByUserIdRequest& withFollowerProfile(StringHolder followerProfile)
    {
        ensureData().followerProfile.emplace(std::move(followerProfile));
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
    UpdateProfileByUserIdRequest& withFriendProfile(StringHolder friendProfile)
    {
        ensureData().friendProfile.emplace(std::move(friendProfile));
        return *this;
    }

    /**
     * 重複実行回避機能に使用するIDを取得
     *
     * @return 重複実行回避機能に使用するID
     */
    const optional<StringHolder>& getDuplicationAvoider() const
    {
        return ensureData().duplicationAvoider;
    }

    /**
     * 重複実行回避機能に使用するIDを設定
     *
     * @param duplicationAvoider 重複実行回避機能に使用するID
     */
    void setDuplicationAvoider(StringHolder duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(std::move(duplicationAvoider));
    }

    /**
     * 重複実行回避機能に使用するIDを設定
     *
     * @param duplicationAvoider 重複実行回避機能に使用するID
     */
    UpdateProfileByUserIdRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(std::move(duplicationAvoider));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateProfileByUserIdRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateProfileByUserIdRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_FRIEND_CONTROL_UPDATEPROFILEBYUSERIDREQUEST_HPP_