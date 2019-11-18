

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

#include <gs2/matchmaking/model/CapacityOfRole.hpp>
#include "EzPlayer.hpp"


namespace gs2 { namespace ez { namespace matchmaking {

class EzCapacityOfRole : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** ロール名 */
        gs2::optional<StringHolder> roleName;
        /** ロール名の別名リスト */
        gs2::optional<List<StringHolder>> roleAliases;
        /** 募集人数 */
        gs2::optional<Int32> capacity;
        /** 参加者のプレイヤー情報リスト */
        gs2::optional<List<EzPlayer>> participants;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            roleName(data.roleName),
            capacity(data.capacity)
        {
            if (data.roleAliases)
            {
                roleAliases = data.roleAliases->deepCopy();
            }
            if (data.participants)
            {
                participants = data.participants->deepCopy();
            }
        }

        Data(Data&& data) = default;

        Data(const gs2::matchmaking::CapacityOfRole& capacityOfRole) :
            roleName(capacityOfRole.getRoleName()),
            roleAliases(capacityOfRole.getRoleAliases()),
            capacity(capacityOfRole.getCapacity() ? *capacityOfRole.getCapacity() : 0)
        {
            participants.emplace();
            if (capacityOfRole.getParticipants())
            {
                for (int i = 0; i < capacityOfRole.getParticipants()->getCount(); ++i)
                {
                    *participants += EzPlayer((*capacityOfRole.getParticipants())[i]);
                }
            }
        }

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

    EzCapacityOfRole(gs2::matchmaking::CapacityOfRole capacityOfRole) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(capacityOfRole)
    {}

    EzCapacityOfRole& operator=(const EzCapacityOfRole& ezCapacityOfRole) = default;
    EzCapacityOfRole& operator=(EzCapacityOfRole&& ezCapacityOfRole) = default;

    EzCapacityOfRole deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzCapacityOfRole);
    }

    gs2::matchmaking::CapacityOfRole ToModel() const
    {
        gs2::matchmaking::CapacityOfRole capacityOfRole;
        capacityOfRole.setRoleName(getRoleName());
        capacityOfRole.setRoleAliases(getRoleAliases());
        capacityOfRole.setCapacity(getCapacity());
        {
            gs2::List<gs2::matchmaking::Player> list;
            auto& participants = getParticipants();
            for (int i = 0; i < participants.getCount(); ++i)
            {
                list += participants[i].ToModel();
            }
            capacityOfRole.setParticipants(list);
        }
        return capacityOfRole;
    }

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getRoleName() const
    {
        return *ensureData().roleName;
    }

    const List<StringHolder>& getRoleAliases() const
    {
        return *ensureData().roleAliases;
    }

    Int32 getCapacity() const
    {
        return *ensureData().capacity;
    }

    const List<EzPlayer>& getParticipants() const
    {
        return *ensureData().participants;
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