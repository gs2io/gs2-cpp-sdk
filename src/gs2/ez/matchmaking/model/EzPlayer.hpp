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

#ifndef GS2_EZ_MATCHMAKING_MODEL_EZPLAYER_HPP_
#define GS2_EZ_MATCHMAKING_MODEL_EZPLAYER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "EzAttribute.hpp"
#include <memory>


namespace gs2 {

namespace matchmaking {

class Player;

}

namespace ez { namespace matchmaking {

class EzPlayer : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** ユーザーID */
        gs2::optional<StringHolder> userId;
        /** 属性値のリスト */
        gs2::optional<List<EzAttribute>> attributes;
        /** ロール名 */
        gs2::optional<StringHolder> roleName;
        /** 参加を拒否するユーザIDリスト */
        gs2::optional<List<StringHolder>> denyUserIds;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::matchmaking::Player& player);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzPlayer() = default;
    EzPlayer(const EzPlayer& ezPlayer) = default;
    EzPlayer(EzPlayer&& ezPlayer) = default;
    ~EzPlayer() = default;

    EzPlayer(gs2::matchmaking::Player player);

    EzPlayer& operator=(const EzPlayer& ezPlayer) = default;
    EzPlayer& operator=(EzPlayer&& ezPlayer) = default;

    EzPlayer deepCopy() const;

    gs2::matchmaking::Player ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getUserId() const
    {
        return *ensureData().userId;
    }

    const List<EzAttribute>& getAttributes() const
    {
        return *ensureData().attributes;
    }

    const StringHolder& getRoleName() const
    {
        return *ensureData().roleName;
    }

    const List<StringHolder>& getDenyUserIds() const
    {
        return *ensureData().denyUserIds;
    }

    // ========================================
    //   Setters
    // ========================================

    void setUserId(StringHolder userId)
    {
        ensureData().userId = std::move(userId);
    }

    void setAttributes(List<EzAttribute> attributes)
    {
        ensureData().attributes = std::move(attributes);
    }

    void setRoleName(StringHolder roleName)
    {
        ensureData().roleName = std::move(roleName);
    }

    void setDenyUserIds(List<StringHolder> denyUserIds)
    {
        ensureData().denyUserIds = std::move(denyUserIds);
    }

    EzPlayer& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    EzPlayer& withAttributes(List<EzAttribute> attributes)
    {
        setAttributes(std::move(attributes));
        return *this;
    }

    EzPlayer& withRoleName(StringHolder roleName)
    {
        setRoleName(std::move(roleName));
        return *this;
    }

    EzPlayer& withDenyUserIds(List<StringHolder> denyUserIds)
    {
        setDenyUserIds(std::move(denyUserIds));
        return *this;
    }
};

}}}

#endif //GS2_EZ_MATCHMAKING_EZPLAYER_HPP_