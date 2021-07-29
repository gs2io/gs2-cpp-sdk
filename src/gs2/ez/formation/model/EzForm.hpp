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

#ifndef GS2_EZ_FORMATION_MODEL_EZFORM_HPP_
#define GS2_EZ_FORMATION_MODEL_EZFORM_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "EzSlot.hpp"
#include <memory>


namespace gs2 {

namespace formation {

class Form;

}

namespace ez { namespace formation {

class EzForm : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** フォームの保存領域の名前 */
        StringHolder name;
        /** 保存領域のインデックス */
        Int32 index;
        /** スロットリスト */
        List<EzSlot> slots;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::formation::Form& form);
        Data(const gs2::optional<gs2::formation::Form>& form);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzForm() = default;
    EzForm(const EzForm& ezForm) = default;
    EzForm(EzForm&& ezForm) = default;
    ~EzForm() = default;

    EzForm(gs2::formation::Form form);
    EzForm(gs2::optional<gs2::formation::Form> form);

    EzForm& operator=(const EzForm& ezForm) = default;
    EzForm& operator=(EzForm&& ezForm) = default;

    EzForm deepCopy() const;

    gs2::formation::Form ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getName() const
    {
        return ensureData().name;
    }

    Int32 getIndex() const
    {
        return ensureData().index;
    }

    const List<EzSlot>& getSlots() const
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

    void setIndex(Int32 index)
    {
        ensureData().index = index;
    }

    void setSlots(List<EzSlot> slots)
    {
        ensureData().slots = std::move(slots);
    }

    EzForm& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    EzForm& withIndex(Int32 index)
    {
        setIndex(index);
        return *this;
    }

    EzForm& withSlots(List<EzSlot> slots)
    {
        setSlots(std::move(slots));
        return *this;
    }
};

}}}

#endif //GS2_EZ_FORMATION_EZFORM_HPP_