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

#ifndef GS2_EZ_AUTH_MODEL_EZACCESSTOKEN_HPP_
#define GS2_EZ_AUTH_MODEL_EZACCESSTOKEN_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace auth {

class AccessToken;

}

namespace ez { namespace auth {

class EzAccessToken : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** アクセストークン */
        StringHolder token;
        /** ユーザーID */
        StringHolder userId;
        /** 有効期限 */
        Int64 expire;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::auth::AccessToken& accessToken);
        Data(const gs2::optional<gs2::auth::AccessToken>& accessToken);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzAccessToken() = default;
    EzAccessToken(const EzAccessToken& ezAccessToken) = default;
    EzAccessToken(EzAccessToken&& ezAccessToken) = default;
    ~EzAccessToken() = default;

    EzAccessToken(gs2::auth::AccessToken accessToken);
    EzAccessToken(gs2::optional<gs2::auth::AccessToken> accessToken);

    EzAccessToken& operator=(const EzAccessToken& ezAccessToken) = default;
    EzAccessToken& operator=(EzAccessToken&& ezAccessToken) = default;

    EzAccessToken deepCopy() const;

    gs2::auth::AccessToken ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getToken() const
    {
        return ensureData().token;
    }

    const StringHolder& getUserId() const
    {
        return ensureData().userId;
    }

    Int64 getExpire() const
    {
        return ensureData().expire;
    }

    // ========================================
    //   Setters
    // ========================================

    void setToken(StringHolder token)
    {
        ensureData().token = std::move(token);
    }

    void setUserId(StringHolder userId)
    {
        ensureData().userId = std::move(userId);
    }

    void setExpire(Int64 expire)
    {
        ensureData().expire = expire;
    }

    EzAccessToken& withToken(StringHolder token)
    {
        setToken(std::move(token));
        return *this;
    }

    EzAccessToken& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    EzAccessToken& withExpire(Int64 expire)
    {
        setExpire(expire);
        return *this;
    }
};

}}}

#endif //GS2_EZ_AUTH_EZACCESSTOKEN_HPP_