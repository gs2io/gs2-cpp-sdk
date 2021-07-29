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

#include "EzRoom.hpp"
#include <gs2/chat/model/Room.hpp>


namespace gs2 { namespace ez { namespace chat {

EzRoom::Data::Data(const Data& data) :
    Gs2Object(data),
    name(data.name),
    metadata(data.metadata)
{
}

EzRoom::Data::Data(const gs2::chat::Room& room) :
    name(room.getName() ? *room.getName() : StringHolder()),
    metadata(room.getMetadata() ? *room.getMetadata() : StringHolder())
{
}

EzRoom::Data::Data(const gs2::optional<gs2::chat::Room>& room) :
    name(room && room->getName() ? *room->getName() : StringHolder()),
    metadata(room && room->getMetadata() ? *room->getMetadata() : StringHolder())
{
}

EzRoom::EzRoom(gs2::chat::Room room) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(room)
{
}

EzRoom::EzRoom(gs2::optional<gs2::chat::Room> room) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(room)
{
}

EzRoom EzRoom::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzRoom);
}

gs2::chat::Room EzRoom::ToModel() const
{
    gs2::chat::Room room;
    room.setName(getName());
    room.setMetadata(getMetadata());
    return room;
}

}}}