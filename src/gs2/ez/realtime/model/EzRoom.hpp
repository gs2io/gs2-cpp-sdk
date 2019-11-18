

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

#ifndef GS2_EZ_REALTIME_MODEL_EZROOM_HPP_
#define GS2_EZ_REALTIME_MODEL_EZROOM_HPP_

#include <gs2/realtime/model/Room.hpp>


namespace gs2 { namespace ez { namespace realtime {

class EzRoom : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** ルーム名 */
        gs2::optional<StringHolder> name;
        /** IPアドレス */
        gs2::optional<StringHolder> ipAddress;
        /** 待受ポート */
        gs2::optional<Int32> port;
        /** 暗号鍵 */
        gs2::optional<StringHolder> encryptionKey;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            name(data.name),
            ipAddress(data.ipAddress),
            port(data.port),
            encryptionKey(data.encryptionKey)
        {
        }

        Data(Data&& data) = default;

        Data(const gs2::realtime::Room& room) :
            name(room.getName()),
            ipAddress(room.getIpAddress()),
            port(room.getPort() ? *room.getPort() : 0),
            encryptionKey(room.getEncryptionKey())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzRoom() = default;
    EzRoom(const EzRoom& ezRoom) = default;
    EzRoom(EzRoom&& ezRoom) = default;
    ~EzRoom() = default;

    EzRoom(gs2::realtime::Room room) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(room)
    {}

    EzRoom& operator=(const EzRoom& ezRoom) = default;
    EzRoom& operator=(EzRoom&& ezRoom) = default;

    EzRoom deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzRoom);
    }

    gs2::realtime::Room ToModel() const
    {
        gs2::realtime::Room room;
        room.setName(getName());
        room.setIpAddress(getIpAddress());
        room.setPort(getPort());
        room.setEncryptionKey(getEncryptionKey());
        return room;
    }

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getName() const
    {
        return *ensureData().name;
    }

    const StringHolder& getIpAddress() const
    {
        return *ensureData().ipAddress;
    }

    Int32 getPort() const
    {
        return *ensureData().port;
    }

    const StringHolder& getEncryptionKey() const
    {
        return *ensureData().encryptionKey;
    }

    // ========================================
    //   Setters
    // ========================================

    void setName(StringHolder name)
    {
        ensureData().name = std::move(name);
    }

    void setIpAddress(StringHolder ipAddress)
    {
        ensureData().ipAddress = std::move(ipAddress);
    }

    void setPort(Int32 port)
    {
        ensureData().port = port;
    }

    void setEncryptionKey(StringHolder encryptionKey)
    {
        ensureData().encryptionKey = std::move(encryptionKey);
    }

    EzRoom& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    EzRoom& withIpAddress(StringHolder ipAddress)
    {
        setIpAddress(std::move(ipAddress));
        return *this;
    }

    EzRoom& withPort(Int32 port)
    {
        setPort(port);
        return *this;
    }

    EzRoom& withEncryptionKey(StringHolder encryptionKey)
    {
        setEncryptionKey(std::move(encryptionKey));
        return *this;
    }
};

}}}

#endif //GS2_EZ_REALTIME_EZROOM_HPP_