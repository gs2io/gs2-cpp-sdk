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

#ifndef GS2_EZ_INVENTORY_EZCONSUMERESULT_HPP_
#define GS2_EZ_INVENTORY_EZCONSUMERESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/inventory/result/ConsumeItemSetResult.hpp>


namespace gs2 { namespace ez { namespace inventory {

class EzConsumeResult : public gs2::Gs2Object
{
private:
    /** 消費後の有効期限ごとのアイテム所持数量のリスト */
    List<EzItemSet> m_Items;
    /** アイテムモデル */
    EzItemModel m_ItemModel;
    /** インベントリ */
    EzInventory m_Inventory;

public:
    EzConsumeResult(const gs2::inventory::ConsumeItemSetResult& result) :
        m_ItemModel(*result.getItemModel()),
        m_Inventory(*result.getInventory())
    {
        {
            auto& list = *result.getItems();
            for (int i = 0; i < list.getCount(); ++i)
            {
                m_Items += EzItemSet(list[i]);
            }
        }
    }

    static bool isConvertible(const gs2::inventory::ConsumeItemSetResult& result)
    {
        return
            result.getItems().has_value() &&
            result.getItemModel().has_value() &&
            result.getInventory().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const List<EzItemSet>& getItems() const
    {
        return m_Items;
    }

    List<EzItemSet>& getItems()
    {
        return m_Items;
    }

    const EzItemModel& getItemModel() const
    {
        return m_ItemModel;
    }

    EzItemModel& getItemModel()
    {
        return m_ItemModel;
    }

    const EzInventory& getInventory() const
    {
        return m_Inventory;
    }

    EzInventory& getInventory()
    {
        return m_Inventory;
    }
};

typedef gs2::AsyncResult<EzConsumeResult> AsyncEzConsumeResult;

}}}

#endif //GS2_EZ_INVENTORY_EZCONSUMERESULT_HPP_