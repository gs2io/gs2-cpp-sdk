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

#ifndef GS2_EZ_FORMATION_MODEL_EZFORMMODEL_HPP_
#define GS2_EZ_FORMATION_MODEL_EZFORMMODEL_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "EzSlotModel.hpp"
#include <memory>


namespace gs2 {

namespace formation {

class FormModel;

}

namespace ez { namespace formation {

class EzFormModel : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** フォームの種類名 */
        StringHolder name;
        /** フォームの種類のメタデータ */
        StringHolder metadata;
        /** スリットリスト */
        List<EzSlotModel> slots;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::formation::FormModel& formModel);
        Data(const gs2::optional<gs2::formation::FormModel>& formModel);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzFormModel() = default;
    EzFormModel(const EzFormModel& ezFormModel) = default;
    EzFormModel(EzFormModel&& ezFormModel) = default;
    ~EzFormModel() = default;

    EzFormModel(gs2::formation::FormModel formModel);
    EzFormModel(gs2::optional<gs2::formation::FormModel> formModel);

    EzFormModel& operator=(const EzFormModel& ezFormModel) = default;
    EzFormModel& operator=(EzFormModel&& ezFormModel) = default;

    EzFormModel deepCopy() const;

    gs2::formation::FormModel ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getName() const
    {
        return ensureData().name;
    }

    const StringHolder& getMetadata() const
    {
        return ensureData().metadata;
    }

    const List<EzSlotModel>& getSlots() const
    {
        return ensureData().slots;
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

    void setSlots(List<EzSlotModel> slots)
    {
        ensureData().slots = std::move(slots);
    }

    EzFormModel& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    EzFormModel& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    EzFormModel& withSlots(List<EzSlotModel> slots)
    {
        setSlots(std::move(slots));
        return *this;
    }
};

}}}

#endif //GS2_EZ_FORMATION_EZFORMMODEL_HPP_