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

#ifndef GS2_EZ_FORMATION_MODEL_EZSLOTWITHSIGNATURE_HPP_
#define GS2_EZ_FORMATION_MODEL_EZSLOTWITHSIGNATURE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace formation {

class SlotWithSignature;

}

namespace ez { namespace formation {

class EzSlotWithSignature : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** スロットモデル名 */
        gs2::optional<StringHolder> name;
        /** プロパティの種類 */
        gs2::optional<StringHolder> propertyType;
        /** ペイロード */
        gs2::optional<StringHolder> body;
        /** プロパティIDのリソースを所有していることを証明する署名 */
        gs2::optional<StringHolder> signature;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::formation::SlotWithSignature& slotWithSignature);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzSlotWithSignature() = default;
    EzSlotWithSignature(const EzSlotWithSignature& ezSlotWithSignature) = default;
    EzSlotWithSignature(EzSlotWithSignature&& ezSlotWithSignature) = default;
    ~EzSlotWithSignature() = default;

    EzSlotWithSignature(gs2::formation::SlotWithSignature slotWithSignature);

    EzSlotWithSignature& operator=(const EzSlotWithSignature& ezSlotWithSignature) = default;
    EzSlotWithSignature& operator=(EzSlotWithSignature&& ezSlotWithSignature) = default;

    EzSlotWithSignature deepCopy() const;

    gs2::formation::SlotWithSignature ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getName() const
    {
        return *ensureData().name;
    }

    const StringHolder& getPropertyType() const
    {
        return *ensureData().propertyType;
    }

    const StringHolder& getBody() const
    {
        return *ensureData().body;
    }

    const StringHolder& getSignature() const
    {
        return *ensureData().signature;
    }

    // ========================================
    //   Setters
    // ========================================

    void setName(StringHolder name)
    {
        ensureData().name = std::move(name);
    }

    void setPropertyType(StringHolder propertyType)
    {
        ensureData().propertyType = std::move(propertyType);
    }

    void setBody(StringHolder body)
    {
        ensureData().body = std::move(body);
    }

    void setSignature(StringHolder signature)
    {
        ensureData().signature = std::move(signature);
    }

    EzSlotWithSignature& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    EzSlotWithSignature& withPropertyType(StringHolder propertyType)
    {
        setPropertyType(std::move(propertyType));
        return *this;
    }

    EzSlotWithSignature& withBody(StringHolder body)
    {
        setBody(std::move(body));
        return *this;
    }

    EzSlotWithSignature& withSignature(StringHolder signature)
    {
        setSignature(std::move(signature));
        return *this;
    }
};

}}}

#endif //GS2_EZ_FORMATION_EZSLOTWITHSIGNATURE_HPP_