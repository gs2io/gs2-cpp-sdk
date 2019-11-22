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

#ifndef GS2_EZ_CHAT_MODEL_EZROOM_HPP_
#define GS2_EZ_CHAT_MODEL_EZROOM_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace chat {

class Room;

}

namespace ez { namespace chat {

class EzRoom : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** ルーム名 */
        gs2::optional<StringHolder> name;
        /** メタデータ */
        gs2::optional<StringHolder> metadata;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::chat::Room& room);
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

    EzRoom(gs2::chat::Room room);

    EzRoom& operator=(const EzRoom& ezRoom) = default;
    EzRoom& operator=(EzRoom&& ezRoom) = default;

    EzRoom deepCopy() const;

    gs2::chat::Room ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getName() const
    {
        return *ensureData().name;
    }

    const StringHolder& getMetadata() const
    {
        return *ensureData().metadata;
    }

    // ========================================
    //   Setters
    // ========================================

    void setName(StringHolder name)
    {
        ensureData().name = std::move(name);
    }

    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata = std::move(metadata);
    }

    EzRoom& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    EzRoom& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }
};

}}}

#endif //GS2_EZ_CHAT_EZROOM_HPP_