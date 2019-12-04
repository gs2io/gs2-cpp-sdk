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

#ifndef GS2_EZ_FORMATION_MODEL_EZSLOTMODEL_HPP_
#define GS2_EZ_FORMATION_MODEL_EZSLOTMODEL_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace formation {

class SlotModel;

}

namespace ez { namespace formation {

class EzSlotModel : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** スロットモデル名 */
        gs2::optional<StringHolder> name;
        /** プロパティとして設定可能な値の正規表現 */
        gs2::optional<StringHolder> propertyRegex;
        /** メタデータ */
        gs2::optional<StringHolder> metadata;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::formation::SlotModel& slotModel);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzSlotModel() = default;
    EzSlotModel(const EzSlotModel& ezSlotModel) = default;
    EzSlotModel(EzSlotModel&& ezSlotModel) = default;
    ~EzSlotModel() = default;

    EzSlotModel(gs2::formation::SlotModel slotModel);

    EzSlotModel& operator=(const EzSlotModel& ezSlotModel) = default;
    EzSlotModel& operator=(EzSlotModel&& ezSlotModel) = default;

    EzSlotModel deepCopy() const;

    gs2::formation::SlotModel ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getName() const
    {
        return *ensureData().name;
    }

    const StringHolder& getPropertyRegex() const
    {
        return *ensureData().propertyRegex;
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

    void setPropertyRegex(StringHolder propertyRegex)
    {
        ensureData().propertyRegex = std::move(propertyRegex);
    }

    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata = std::move(metadata);
    }

    EzSlotModel& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    EzSlotModel& withPropertyRegex(StringHolder propertyRegex)
    {
        setPropertyRegex(std::move(propertyRegex));
        return *this;
    }

    EzSlotModel& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }
};

}}}

#endif //GS2_EZ_FORMATION_EZSLOTMODEL_HPP_