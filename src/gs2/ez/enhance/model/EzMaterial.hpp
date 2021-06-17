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

#ifndef GS2_EZ_ENHANCE_MODEL_EZMATERIAL_HPP_
#define GS2_EZ_ENHANCE_MODEL_EZMATERIAL_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace enhance {

class Material;

}

namespace ez { namespace enhance {

class EzMaterial : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 強化対象の GS2-Inventory アイテムセットGRN */
        gs2::optional<StringHolder> materialItemSetId;
        /** 消費数量 */
        gs2::optional<Int32> count;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::enhance::Material& material);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzMaterial() = default;
    EzMaterial(const EzMaterial& ezMaterial) = default;
    EzMaterial(EzMaterial&& ezMaterial) = default;
    ~EzMaterial() = default;

    EzMaterial(gs2::enhance::Material material);

    EzMaterial& operator=(const EzMaterial& ezMaterial) = default;
    EzMaterial& operator=(EzMaterial&& ezMaterial) = default;

    EzMaterial deepCopy() const;

    gs2::enhance::Material ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getMaterialItemSetId() const
    {
        return *ensureData().materialItemSetId;
    }

    Int32 getCount() const
    {
        return *ensureData().count;
    }

    // ========================================
    //   Setters
    // ========================================

    void setMaterialItemSetId(StringHolder materialItemSetId)
    {
        ensureData().materialItemSetId = std::move(materialItemSetId);
    }

    void setCount(Int32 count)
    {
        ensureData().count = count;
    }

    EzMaterial& withMaterialItemSetId(StringHolder materialItemSetId)
    {
        setMaterialItemSetId(std::move(materialItemSetId));
        return *this;
    }

    EzMaterial& withCount(Int32 count)
    {
        setCount(count);
        return *this;
    }
};

}}}

#endif //GS2_EZ_ENHANCE_EZMATERIAL_HPP_