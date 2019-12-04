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

#ifndef GS2_EZ_FRIEND_MODEL_EZPUBLICPROFILE_HPP_
#define GS2_EZ_FRIEND_MODEL_EZPUBLICPROFILE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace friend_ {

class PublicProfile;

}

namespace ez { namespace friend_ {

class EzPublicProfile : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** ユーザーID */
        gs2::optional<StringHolder> userId;
        /** 公開されるプロフィール */
        gs2::optional<StringHolder> publicProfile;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::friend_::PublicProfile& publicProfile);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzPublicProfile() = default;
    EzPublicProfile(const EzPublicProfile& ezPublicProfile) = default;
    EzPublicProfile(EzPublicProfile&& ezPublicProfile) = default;
    ~EzPublicProfile() = default;

    EzPublicProfile(gs2::friend_::PublicProfile publicProfile);

    EzPublicProfile& operator=(const EzPublicProfile& ezPublicProfile) = default;
    EzPublicProfile& operator=(EzPublicProfile&& ezPublicProfile) = default;

    EzPublicProfile deepCopy() const;

    gs2::friend_::PublicProfile ToModel() const;

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

    EzPublicProfile& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    EzPublicProfile& withPublicProfile(StringHolder publicProfile)
    {
        setPublicProfile(std::move(publicProfile));
        return *this;
    }
};

}}}

#endif //GS2_EZ_FRIEND_EZPUBLICPROFILE_HPP_