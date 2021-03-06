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

#ifndef GS2_EZ_FORMATION_MODEL_EZSLOT_HPP_
#define GS2_EZ_FORMATION_MODEL_EZSLOT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace formation {

class Slot;

}

namespace ez { namespace formation {

class EzSlot : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** スロットモデル名 */
        gs2::optional<StringHolder> name;
        /** プロパティID */
        gs2::optional<StringHolder> propertyId;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::formation::Slot& slot);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzSlot() = default;
    EzSlot(const EzSlot& ezSlot) = default;
    EzSlot(EzSlot&& ezSlot) = default;
    ~EzSlot() = default;

    EzSlot(gs2::formation::Slot slot);

    EzSlot& operator=(const EzSlot& ezSlot) = default;
    EzSlot& operator=(EzSlot&& ezSlot) = default;

    EzSlot deepCopy() const;

    gs2::formation::Slot ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getName() const
    {
        return *ensureData().name;
    }

    const StringHolder& getPropertyId() const
    {
        return *ensureData().propertyId;
    }

    // ========================================
    //   Setters
    // ========================================

    void setName(StringHolder name)
    {
        ensureData().name = std::move(name);
    }

    void setPropertyId(StringHolder propertyId)
    {
        ensureData().propertyId = std::move(propertyId);
    }

    EzSlot& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    EzSlot& withPropertyId(StringHolder propertyId)
    {
        setPropertyId(std::move(propertyId));
        return *this;
    }
};

}}}

#endif //GS2_EZ_FORMATION_EZSLOT_HPP_