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

#ifndef GS2_EZ_SHOWCASE_MODEL_EZSHOWCASE_HPP_
#define GS2_EZ_SHOWCASE_MODEL_EZSHOWCASE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "EzDisplayItem.hpp"
#include <memory>


namespace gs2 {

namespace showcase {

class Showcase;

}

namespace ez { namespace showcase {

class EzShowcase : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 商品名 */
        StringHolder name;
        /** 商品のメタデータ */
        StringHolder metadata;
        /** インベントリに格納可能なアイテムモデル一覧 */
        List<EzDisplayItem> displayItems;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::showcase::Showcase& showcase);
        Data(const gs2::optional<gs2::showcase::Showcase>& showcase);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzShowcase() = default;
    EzShowcase(const EzShowcase& ezShowcase) = default;
    EzShowcase(EzShowcase&& ezShowcase) = default;
    ~EzShowcase() = default;

    EzShowcase(gs2::showcase::Showcase showcase);
    EzShowcase(gs2::optional<gs2::showcase::Showcase> showcase);

    EzShowcase& operator=(const EzShowcase& ezShowcase) = default;
    EzShowcase& operator=(EzShowcase&& ezShowcase) = default;

    EzShowcase deepCopy() const;

    gs2::showcase::Showcase ToModel() const;

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

    const List<EzDisplayItem>& getDisplayItems() const
    {
        return ensureData().displayItems;
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

    void setDisplayItems(List<EzDisplayItem> displayItems)
    {
        ensureData().displayItems = std::move(displayItems);
    }

    EzShowcase& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    EzShowcase& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    EzShowcase& withDisplayItems(List<EzDisplayItem> displayItems)
    {
        setDisplayItems(std::move(displayItems));
        return *this;
    }
};

}}}

#endif //GS2_EZ_SHOWCASE_EZSHOWCASE_HPP_