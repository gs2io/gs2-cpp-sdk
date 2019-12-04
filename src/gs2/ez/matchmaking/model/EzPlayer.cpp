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

#include "EzPlayer.hpp"
#include <gs2/matchmaking/model/Player.hpp>


namespace gs2 { namespace ez { namespace matchmaking {

EzPlayer::Data::Data(const Data& data) :
    Gs2Object(data),
    userId(data.userId),
    roleName(data.roleName)
{
    if (data.attributes)
    {
        attributes = data.attributes->deepCopy();
    }
}

EzPlayer::Data::Data(const gs2::matchmaking::Player& player) :
    userId(player.getUserId()),
    roleName(player.getRoleName())
{
    attributes.emplace();
    if (player.getAttributes())
    {
        for (int i = 0; i < player.getAttributes()->getCount(); ++i)
        {
            *attributes += EzAttribute((*player.getAttributes())[i]);
        }
    }
}

EzPlayer::EzPlayer(gs2::matchmaking::Player player) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(player)
{
}

EzPlayer EzPlayer::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzPlayer);
}

gs2::matchmaking::Player EzPlayer::ToModel() const
{
    gs2::matchmaking::Player player;
    player.setUserId(getUserId());
    {
        gs2::List<gs2::matchmaking::Attribute> list;
        auto& attributes = getAttributes();
        for (int i = 0; i < attributes.getCount(); ++i)
        {
            list += attributes[i].ToModel();
        }
        player.setAttributes(list);
    }
    player.setRoleName(getRoleName());
    return player;
}

}}}