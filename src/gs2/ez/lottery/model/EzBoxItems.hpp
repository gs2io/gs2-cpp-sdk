

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
    /** ボックス */
    gs2::optional<StringHolder> m_BoxId;
    /** 排出確率テーブル名 */
    gs2::optional<StringHolder> m_PrizeTableName;
    /** ボックスから取り出したアイテムのリスト */
    gs2::optional<List<EzBoxItem>> m_Items;

public:
    EzBoxItems() = default;

    EzBoxItems(gs2::lottery::BoxItems boxItems) :
        m_BoxId(boxItems.getBoxId()),
        m_PrizeTableName(boxItems.getPrizeTableName())
    {
        m_Items.emplace();
        if (boxItems.getItems())
        {
            for (int i = 0; i < boxItems.getItems()->getCount(); ++i)
            {
                *m_Items += EzBoxItem((*boxItems.getItems())[i]);
            }
        }
    }

    gs2::lottery::BoxItems ToModel() const
    {
        gs2::lottery::BoxItems boxItems;
        boxItems.setBoxId(*m_BoxId);
        boxItems.setPrizeTableName(*m_PrizeTableName);
        {
            gs2::List<gs2::lottery::BoxItem> list;
            auto& items = *m_Items;
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

    const gs2::StringHolder& getBoxId() const
    {
        return *m_BoxId;
    }

    gs2::StringHolder& getBoxId()
    {
        return *m_BoxId;
    }

    const gs2::StringHolder& getPrizeTableName() const
    {
        return *m_PrizeTableName;
    }

    gs2::StringHolder& getPrizeTableName()
    {
        return *m_PrizeTableName;
    }

    const List<EzBoxItem>& getItems() const
    {
        return *m_Items;
    }

    List<EzBoxItem>& getItems()
    {
        return *m_Items;
    }

    // ========================================
    //   Setters
    // ========================================

    void setBoxId(Char* boxId)
    {
        m_BoxId.emplace(boxId);
    }

    void setPrizeTableName(Char* prizeTableName)
    {
        m_PrizeTableName.emplace(prizeTableName);
    }

    void setItems(const List<EzBoxItem>& items)
    {
        m_Items = items;
    }

    void setItems(List<EzBoxItem>&& items)
    {
        m_Items = std::move(items);
    }

    EzBoxItems& withBoxId(Char* boxId)
    {
        setBoxId(boxId);
        return *this;
    }

    EzBoxItems& withPrizeTableName(Char* prizeTableName)
    {
        setPrizeTableName(prizeTableName);
        return *this;
    }

    EzBoxItems& withItems(const List<EzBoxItem>& items)
    {
        setItems(items);
        return *this;
    }

    EzBoxItems& withItems(List<EzBoxItem>&& items)
    {
        setItems(std::move(items));
        return *this;
    }
};

}}}

#endif //GS2_EZ_LOTTERY_EZBOXITEMS_HPP_