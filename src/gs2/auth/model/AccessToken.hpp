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

#ifndef GS2_AUTH_MODEL_ACCESSTOKEN_HPP_
#define GS2_AUTH_MODEL_ACCESSTOKEN_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>

namespace gs2 { namespace auth {

/**
 * アクセストークン
 *
 * @author Game Server Services, Inc.
 *
 */
class AccessToken : public Gs2Object
{
    friend bool operator!=(const AccessToken& lhs, const AccessToken& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** アクセストークン */
        optional<StringHolder> token;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** 有効期限 */
        optional<Int64> expire;

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
    AccessToken() = default;
    AccessToken(const AccessToken& accessToken) = default;
    AccessToken(AccessToken&& accessToken) = default;
    ~AccessToken() = default;

    AccessToken& operator=(const AccessToken& accessToken) = default;
    AccessToken& operator=(AccessToken&& accessToken) = default;

    AccessToken deepCopy() const;

    const AccessToken* operator->() const
    {
        return this;
    }

    AccessToken* operator->()
    {
        return this;
    }
    /**
     * オーナーIDを取得
     *
     * @return オーナーID
     */
    const optional<StringHolder>& getOwnerId() const
    {
        return ensureData().ownerId;
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    void setOwnerId(StringHolder ownerId)
    {
        ensureData().ownerId.emplace(std::move(ownerId));
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    AccessToken& withOwnerId(StringHolder ownerId)
    {
        setOwnerId(std::move(ownerId));
        return *this;
    }

    /**
     * アクセストークンを取得
     *
     * @return アクセストークン
     */
    const optional<StringHolder>& getToken() const
    {
        return ensureData().token;
    }

    /**
     * アクセストークンを設定
     *
     * @param token アクセストークン
     */
    void setToken(StringHolder token)
    {
        ensureData().token.emplace(std::move(token));
    }

    /**
     * アクセストークンを設定
     *
     * @param token アクセストークン
     */
    AccessToken& withToken(StringHolder token)
    {
        setToken(std::move(token));
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
    AccessToken& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    /**
     * 有効期限を取得
     *
     * @return 有効期限
     */
    const optional<Int64>& getExpire() const
    {
        return ensureData().expire;
    }

    /**
     * 有効期限を設定
     *
     * @param expire 有効期限
     */
    void setExpire(Int64 expire)
    {
        ensureData().expire.emplace(expire);
    }

    /**
     * 有効期限を設定
     *
     * @param expire 有効期限
     */
    AccessToken& withExpire(Int64 expire)
    {
        setExpire(expire);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const AccessToken& lhs, const AccessToken& lhr);

inline bool operator==(const AccessToken& lhs, const AccessToken& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_AUTH_MODEL_ACCESSTOKEN_HPP_