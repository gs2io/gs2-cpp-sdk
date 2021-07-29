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

#ifndef GS2_EZ_MATCHMAKING_MODEL_EZCAPACITYOFROLE_HPP_
#define GS2_EZ_MATCHMAKING_MODEL_EZCAPACITYOFROLE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "EzPlayer.hpp"
#include <memory>


namespace gs2 {

namespace matchmaking {

class CapacityOfRole;

}

namespace ez { namespace matchmaking {

class EzCapacityOfRole : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** ロール名 */
        StringHolder roleName;
        /** ロール名の別名リスト */
        List<StringHolder> roleAliases;
        /** 募集人数 */
        Int32 capacity;
        /** 参加者のプレイヤー情報リスト */
        List<EzPlayer> participants;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::matchmaking::CapacityOfRole& capacityOfRole);
        Data(const gs2::optional<gs2::matchmaking::CapacityOfRole>& capacityOfRole);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzCapacityOfRole() = default;
    EzCapacityOfRole(const EzCapacityOfRole& ezCapacityOfRole) = default;
    EzCapacityOfRole(EzCapacityOfRole&& ezCapacityOfRole) = default;
    ~EzCapacityOfRole() = default;

    EzCapacityOfRole(gs2::matchmaking::CapacityOfRole capacityOfRole);
    EzCapacityOfRole(gs2::optional<gs2::matchmaking::CapacityOfRole> capacityOfRole);

    EzCapacityOfRole& operator=(const EzCapacityOfRole& ezCapacityOfRole) = default;
    EzCapacityOfRole& operator=(EzCapacityOfRole&& ezCapacityOfRole) = default;

    EzCapacityOfRole deepCopy() const;

    gs2::matchmaking::CapacityOfRole ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getRoleName() const
    {
        return ensureData().roleName;
    }

    const List<StringHolder>& getRoleAliases() const
    {
        return ensureData().roleAliases;
    }

    Int32 getCapacity() const
    {
        return ensureData().capacity;
    }

    const List<EzPlayer>& getParticipants() const
    {
        return ensureData().participants;
    }

    // ========================================
    //   Setters
    // ========================================

    void setRoleName(StringHolder roleName)
    {
        ensureData().roleName = std::move(roleName);
    }

    void setRoleAliases(List<StringHolder> roleAliases)
    {
        ensureData().roleAliases = std::move(roleAliases);
    }

    void setCapacity(Int32 capacity)
    {
        ensureData().capacity = capacity;
    }

    void setParticipants(List<EzPlayer> participants)
    {
        ensureData().participants = std::move(participants);
    }

    EzCapacityOfRole& withRoleName(StringHolder roleName)
    {
        setRoleName(std::move(roleName));
        return *this;
    }

    EzCapacityOfRole& withRoleAliases(List<StringHolder> roleAliases)
    {
        setRoleAliases(std::move(roleAliases));
        return *this;
    }

    EzCapacityOfRole& withCapacity(Int32 capacity)
    {
        setCapacity(capacity);
        return *this;
    }

    EzCapacityOfRole& withParticipants(List<EzPlayer> participants)
    {
        setParticipants(std::move(participants));
        return *this;
    }
};

}}}

#endif //GS2_EZ_MATCHMAKING_EZCAPACITYOFROLE_HPP_