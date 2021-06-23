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

#include "EzCapacityOfRole.hpp"
#include <gs2/matchmaking/model/CapacityOfRole.hpp>


namespace gs2 { namespace ez { namespace matchmaking {

EzCapacityOfRole::Data::Data(const Data& data) :
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

EzCapacityOfRole::Data::Data(const gs2::matchmaking::CapacityOfRole& capacityOfRole) :
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

EzCapacityOfRole::EzCapacityOfRole(gs2::matchmaking::CapacityOfRole capacityOfRole) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(capacityOfRole)
{
}

EzCapacityOfRole EzCapacityOfRole::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzCapacityOfRole);
}

gs2::matchmaking::CapacityOfRole EzCapacityOfRole::ToModel() const
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

}}}