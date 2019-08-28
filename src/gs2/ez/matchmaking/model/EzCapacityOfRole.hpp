

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
    /** ロール名 */
    gs2::optional<StringHolder> m_RoleName;
    /** ロール名の別名リスト */
    gs2::optional<List<StringHolder>> m_RoleAliases;
    /** 募集人数 */
    gs2::optional<Int32> m_Capacity;
    /** 参加者のプレイヤー情報リスト */
    gs2::optional<List<EzPlayer>> m_Participants;

public:
    EzCapacityOfRole() = default;

    EzCapacityOfRole(gs2::matchmaking::CapacityOfRole capacityOfRole) :
        m_RoleName(capacityOfRole.getRoleName()),
        m_RoleAliases(capacityOfRole.getRoleAliases()),
        m_Capacity(capacityOfRole.getCapacity() ? *capacityOfRole.getCapacity() : 0)
    {
        m_Participants.emplace();
        if (capacityOfRole.getParticipants())
        {
            for (int i = 0; i < capacityOfRole.getParticipants()->getCount(); ++i)
            {
                *m_Participants += EzPlayer((*capacityOfRole.getParticipants())[i]);
            }
        }
    }

    gs2::matchmaking::CapacityOfRole ToModel() const
    {
        gs2::matchmaking::CapacityOfRole capacityOfRole;
        capacityOfRole.setRoleName(*m_RoleName);
        capacityOfRole.setRoleAliases(*m_RoleAliases);
        capacityOfRole.setCapacity(*m_Capacity);
        {
            gs2::List<gs2::matchmaking::Player> list;
            auto& participants = *m_Participants;
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

    const gs2::StringHolder& getRoleName() const
    {
        return *m_RoleName;
    }

    gs2::StringHolder& getRoleName()
    {
        return *m_RoleName;
    }

    const List<StringHolder>& getRoleAliases() const
    {
        return *m_RoleAliases;
    }

    List<StringHolder>& getRoleAliases()
    {
        return *m_RoleAliases;
    }

    Int32 getCapacity() const
    {
        return *m_Capacity;
    }

    const List<EzPlayer>& getParticipants() const
    {
        return *m_Participants;
    }

    List<EzPlayer>& getParticipants()
    {
        return *m_Participants;
    }

    // ========================================
    //   Setters
    // ========================================

    void setRoleName(Char* roleName)
    {
        m_RoleName.emplace(roleName);
    }

    void setRoleAliases(const List<StringHolder>& roleAliases)
    {
        m_RoleAliases = roleAliases;
    }

    void setRoleAliases(List<StringHolder>&& roleAliases)
    {
        m_RoleAliases = std::move(roleAliases);
    }

    void setCapacity(Int32 capacity)
    {
        m_Capacity = capacity;
    }

    void setParticipants(const List<EzPlayer>& participants)
    {
        m_Participants = participants;
    }

    void setParticipants(List<EzPlayer>&& participants)
    {
        m_Participants = std::move(participants);
    }

    EzCapacityOfRole& withRoleName(Char* roleName)
    {
        setRoleName(roleName);
        return *this;
    }

    EzCapacityOfRole& withRoleAliases(const List<StringHolder>& roleAliases)
    {
        setRoleAliases(roleAliases);
        return *this;
    }

    EzCapacityOfRole& withRoleAliases(List<StringHolder>&& roleAliases)
    {
        setRoleAliases(std::move(roleAliases));
        return *this;
    }

    EzCapacityOfRole& withCapacity(Int32 capacity)
    {
        setCapacity(capacity);
        return *this;
    }

    EzCapacityOfRole& withParticipants(const List<EzPlayer>& participants)
    {
        setParticipants(participants);
        return *this;
    }

    EzCapacityOfRole& withParticipants(List<EzPlayer>&& participants)
    {
        setParticipants(std::move(participants));
        return *this;
    }
};

}}}

#endif //GS2_EZ_MATCHMAKING_EZCAPACITYOFROLE_HPP_