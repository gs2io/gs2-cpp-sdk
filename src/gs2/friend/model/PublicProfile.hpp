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

#ifndef GS2_FRIEND_MODEL_PUBLICPROFILE_HPP_
#define GS2_FRIEND_MODEL_PUBLICPROFILE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>

namespace gs2 { namespace friend_ {

/**
 * 公開プロフィール
 *
 * @author Game Server Services, Inc.
 *
 */
class PublicProfile : public Gs2Object
{
    friend bool operator!=(const PublicProfile& lhs, const PublicProfile& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** ユーザーID */
        optional<StringHolder> userId;
        /** 公開されるプロフィール */
        optional<StringHolder> publicProfile;

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
    PublicProfile() = default;
    PublicProfile(const PublicProfile& publicProfile) = default;
    PublicProfile(PublicProfile&& publicProfile) = default;
    ~PublicProfile() = default;

    PublicProfile& operator=(const PublicProfile& publicProfile) = default;
    PublicProfile& operator=(PublicProfile&& publicProfile) = default;

    PublicProfile deepCopy() const;

    const PublicProfile* operator->() const
    {
        return this;
    }

    PublicProfile* operator->()
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
    PublicProfile& withUserId(StringHolder userId)
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
    PublicProfile& withPublicProfile(StringHolder publicProfile)
    {
        setPublicProfile(std::move(publicProfile));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const PublicProfile& lhs, const PublicProfile& lhr);

inline bool operator==(const PublicProfile& lhs, const PublicProfile& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_FRIEND_MODEL_PUBLICPROFILE_HPP_