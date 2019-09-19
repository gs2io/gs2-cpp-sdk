

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

#include <gs2/lottery/model/BoxItems.hpp>
#include "EzBoxItem.hpp"


namespace gs2 { namespace ez { namespace lottery {

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

        Data(const Data& data) :
            Gs2Object(data),
            boxId(data.boxId),
            prizeTableName(data.prizeTableName)
        {
            if (data.items)
            {
                items = data.items->deepCopy();
            }
        }

        Data(Data&& data) = default;

        Data(const gs2::lottery::BoxItems& boxItems) :
            boxId(boxItems.getBoxId()),
            prizeTableName(boxItems.getPrizeTableName())
        {
            items.emplace();
            if (boxItems.getItems())
            {
                for (int i = 0; i < boxItems.getItems()->getCount(); ++i)
                {
                    *items += EzBoxItem((*boxItems.getItems())[i]);
                }
            }
        }

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

    EzBoxItems(gs2::lottery::BoxItems boxItems) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(boxItems)
    {}

    EzBoxItems& operator=(const EzBoxItems& ezBoxItems) = default;
    EzBoxItems& operator=(EzBoxItems&& ezBoxItems) = default;

    EzBoxItems deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzBoxItems);
    }

    gs2::lottery::BoxItems ToModel() const
    {
        gs2::lottery::BoxItems boxItems;
        boxItems.setBoxId(getBoxId());
        boxItems.setPrizeTableName(getPrizeTableName());
        {
            gs2::List<gs2::lottery::BoxItem> list;
            auto& items = getItems();
            for (int i = 0; i < items.getCount(); ++i)
            {
                list += items[i].ToModel();
            }
            boxItems.setItems(list);
        }
        return boxItems;
    }

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