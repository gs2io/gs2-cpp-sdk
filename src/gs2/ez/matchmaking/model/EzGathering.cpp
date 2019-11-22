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

#include "EzGathering.hpp"
#include <gs2/matchmaking/model/Gathering.hpp>


namespace gs2 { namespace ez { namespace matchmaking {

EzGathering::Data::Data(const Data& data) :
    Gs2Object(data),
    gatheringId(data.gatheringId),
    name(data.name),
    metadata(data.metadata),
    createdAt(data.createdAt),
    updatedAt(data.updatedAt)
{
    if (data.attributeRanges)
    {
        attributeRanges = data.attributeRanges->deepCopy();
    }
    if (data.capacityOfRoles)
    {
        capacityOfRoles = data.capacityOfRoles->deepCopy();
    }
    if (data.allowUserIds)
    {
        allowUserIds = data.allowUserIds->deepCopy();
    }
}

EzGathering::Data::Data(const gs2::matchmaking::Gathering& gathering) :
    gatheringId(gathering.getGatheringId()),
    name(gathering.getName()),
    allowUserIds(gathering.getAllowUserIds()),
    metadata(gathering.getMetadata()),
    createdAt(gathering.getCreatedAt() ? *gathering.getCreatedAt() : 0),
    updatedAt(gathering.getUpdatedAt() ? *gathering.getUpdatedAt() : 0)
{
    attributeRanges.emplace();
    if (gathering.getAttributeRanges())
    {
        for (int i = 0; i < gathering.getAttributeRanges()->getCount(); ++i)
        {
            *attributeRanges += EzAttributeRange((*gathering.getAttributeRanges())[i]);
        }
    }
    capacityOfRoles.emplace();
    if (gathering.getCapacityOfRoles())
    {
        for (int i = 0; i < gathering.getCapacityOfRoles()->getCount(); ++i)
        {
            *capacityOfRoles += EzCapacityOfRole((*gathering.getCapacityOfRoles())[i]);
        }
    }
}

EzGathering::EzGathering(gs2::matchmaking::Gathering gathering) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(gathering)
{
}

EzGathering EzGathering::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzGathering);
}

gs2::matchmaking::Gathering EzGathering::ToModel() const
{
    gs2::matchmaking::Gathering gathering;
    gathering.setGatheringId(getGatheringId());
    gathering.setName(getName());
    {
        gs2::List<gs2::matchmaking::AttributeRange> list;
        auto& attributeRanges = getAttributeRanges();
        for (int i = 0; i < attributeRanges.getCount(); ++i)
        {
            list += attributeRanges[i].ToModel();
        }
        gathering.setAttributeRanges(list);
    }
    {
        gs2::List<gs2::matchmaking::CapacityOfRole> list;
        auto& capacityOfRoles = getCapacityOfRoles();
        for (int i = 0; i < capacityOfRoles.getCount(); ++i)
        {
            list += capacityOfRoles[i].ToModel();
        }
        gathering.setCapacityOfRoles(list);
    }
    gathering.setAllowUserIds(getAllowUserIds());
    gathering.setMetadata(getMetadata());
    gathering.setCreatedAt(getCreatedAt());
    gathering.setUpdatedAt(getUpdatedAt());
    return gathering;
}

}}}