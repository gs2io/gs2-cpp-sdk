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

#ifndef GS2_EZ_LOTTERY_MODEL_EZBOXITEMS_HPP_
#define GS2_EZ_LOTTERY_MODEL_EZBOXITEMS_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "EzBoxItem.hpp"
#include <memory>


namespace gs2 {

namespace lottery {

class BoxItems;

}

namespace ez { namespace lottery {

class EzBoxItems : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** ボックス */
        gs2::optional<StringHolder> boxId;
        /** 排出確率テーブル名 */
        gs2::optional<StringHolder> prizeTableName;
        /** ボックスから取り出したアイテムのリスト */
        gs2::optional<List<EzBoxItem>> items;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::lottery::BoxItems& boxItems);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzBoxItems() = default;
    EzBoxItems(const EzBoxItems& ezBoxItems) = default;
    EzBoxItems(EzBoxItems&& ezBoxItems) = default;
    ~EzBoxItems() = default;

    EzBoxItems(gs2::lottery::BoxItems boxItems);

    EzBoxItems& operator=(const EzBoxItems& ezBoxItems) = default;
    EzBoxItems& operator=(EzBoxItems&& ezBoxItems) = default;

    EzBoxItems deepCopy() const;

    gs2::lottery::BoxItems ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getBoxId() const
    {
        return *ensureData().boxId;
    }

    const StringHolder& getPrizeTableName() const
    {
        return *ensureData().prizeTableName;
    }

    const List<EzBoxItem>& getItems() const
    {
        return *ensureData().items;
    }

    // ========================================
    //   Setters
    // ========================================

    void setBoxId(StringHolder boxId)
    {
        ensureData().boxId = std::move(boxId);
    }

    void setPrizeTableName(StringHolder prizeTableName)
    {
        ensureData().prizeTableName = std::move(prizeTableName);
    }

    void setItems(List<EzBoxItem> items)
    {
        ensureData().items = std::move(items);
    }

    EzBoxItems& withBoxId(StringHolder boxId)
    {
        setBoxId(std::move(boxId));
        return *this;
    }

    EzBoxItems& withPrizeTableName(StringHolder prizeTableName)
    {
        setPrizeTableName(std::move(prizeTableName));
        return *this;
    }

    EzBoxItems& withItems(List<EzBoxItem> items)
    {
        setItems(std::move(items));
        return *this;
    }
};

}}}

#endif //GS2_EZ_LOTTERY_EZBOXITEMS_HPP_