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

#ifndef GS2_EZ_RANKING_MODEL_EZSUBSCRIBEUSER_HPP_
#define GS2_EZ_RANKING_MODEL_EZSUBSCRIBEUSER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace ranking {

class SubscribeUser;

}

namespace ez { namespace ranking {

class EzSubscribeUser : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 購読するユーザID */
        gs2::optional<StringHolder> userId;
        /** 購読されるユーザID */
        gs2::optional<StringHolder> targetUserId;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::ranking::SubscribeUser& subscribeUser);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzSubscribeUser() = default;
    EzSubscribeUser(const EzSubscribeUser& ezSubscribeUser) = default;
    EzSubscribeUser(EzSubscribeUser&& ezSubscribeUser) = default;
    ~EzSubscribeUser() = default;

    EzSubscribeUser(gs2::ranking::SubscribeUser subscribeUser);

    EzSubscribeUser& operator=(const EzSubscribeUser& ezSubscribeUser) = default;
    EzSubscribeUser& operator=(EzSubscribeUser&& ezSubscribeUser) = default;

    EzSubscribeUser deepCopy() const;

    gs2::ranking::SubscribeUser ToModel() const;

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

    EzSubscribeUser& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    EzSubscribeUser& withTargetUserId(StringHolder targetUserId)
    {
        setTargetUserId(std::move(targetUserId));
        return *this;
    }
};

}}}

#endif //GS2_EZ_RANKING_EZSUBSCRIBEUSER_HPP_