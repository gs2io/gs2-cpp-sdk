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
#include <gs2/realtime/model/Room.hpp>


namespace gs2 { namespace ez { namespace realtime {

EzRoom::Data::Data(const Data& data) :
    Gs2Object(data),
    name(data.name),
    ipAddress(data.ipAddress),
    port(data.port),
    encryptionKey(data.encryptionKey)
{
}

EzRoom::Data::Data(const gs2::realtime::Room& room) :
    name(room.getName() ? *room.getName() : StringHolder()),
    ipAddress(room.getIpAddress() ? *room.getIpAddress() : StringHolder()),
    port(room.getPort() ? *room.getPort() : 0),
    encryptionKey(room.getEncryptionKey() ? *room.getEncryptionKey() : StringHolder())
{
}

EzRoom::Data::Data(const gs2::optional<gs2::realtime::Room>& room) :
    name(room && room->getName() ? *room->getName() : StringHolder()),
    ipAddress(room && room->getIpAddress() ? *room->getIpAddress() : StringHolder()),
    port(room && room->getPort() ? *room->getPort() : 0),
    encryptionKey(room && room->getEncryptionKey() ? *room->getEncryptionKey() : StringHolder())
{
}

EzRoom::EzRoom(gs2::realtime::Room room) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(room)
{
}

EzRoom::EzRoom(gs2::optional<gs2::realtime::Room> room) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(room)
{
}

EzRoom EzRoom::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzRoom);
}

gs2::realtime::Room EzRoom::ToModel() const
{
    gs2::realtime::Room room;
    room.setName(getName());
    room.setIpAddress(getIpAddress());
    room.setPort(getPort());
    room.setEncryptionKey(getEncryptionKey());
    return room;
}

}}}