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

#ifndef GS2_EZ_SHOWCASE_MODEL_EZSALESITEMGROUP_HPP_
#define GS2_EZ_SHOWCASE_MODEL_EZSALESITEMGROUP_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "EzSalesItem.hpp"
#include <memory>


namespace gs2 {

namespace showcase {

class SalesItemGroup;

}

namespace ez { namespace showcase {

class EzSalesItemGroup : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 商品グループ名 */
        StringHolder name;
        /** メタデータ */
        StringHolder metadata;
        /** 商品リスト */
        List<EzSalesItem> salesItems;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::showcase::SalesItemGroup& salesItemGroup);
        Data(const gs2::optional<gs2::showcase::SalesItemGroup>& salesItemGroup);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzSalesItemGroup() = default;
    EzSalesItemGroup(const EzSalesItemGroup& ezSalesItemGroup) = default;
    EzSalesItemGroup(EzSalesItemGroup&& ezSalesItemGroup) = default;
    ~EzSalesItemGroup() = default;

    EzSalesItemGroup(gs2::showcase::SalesItemGroup salesItemGroup);
    EzSalesItemGroup(gs2::optional<gs2::showcase::SalesItemGroup> salesItemGroup);

    EzSalesItemGroup& operator=(const EzSalesItemGroup& ezSalesItemGroup) = default;
    EzSalesItemGroup& operator=(EzSalesItemGroup&& ezSalesItemGroup) = default;

    EzSalesItemGroup deepCopy() const;

    gs2::showcase::SalesItemGroup ToModel() const;

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

    const List<EzSalesItem>& getSalesItems() const
    {
        return ensureData().salesItems;
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

    void setSalesItems(List<EzSalesItem> salesItems)
    {
        ensureData().salesItems = std::move(salesItems);
    }

    EzSalesItemGroup& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    EzSalesItemGroup& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    EzSalesItemGroup& withSalesItems(List<EzSalesItem> salesItems)
    {
        setSalesItems(std::move(salesItems));
        return *this;
    }
};

}}}

#endif //GS2_EZ_SHOWCASE_EZSALESITEMGROUP_HPP_