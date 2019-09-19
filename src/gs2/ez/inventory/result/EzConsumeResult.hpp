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
    class Data : public gs2::Gs2Object
    {
    public:
        /** 消費後の有効期限ごとのアイテム所持数量のリスト */
        List<EzItemSet> items;
        /** アイテムモデル */
        EzItemModel itemModel;
        /** インベントリ */
        EzInventory inventory;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data)
        {
            items = data.items.deepCopy();
            itemModel = data.itemModel.deepCopy();
            inventory = data.inventory.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::inventory::ConsumeItemSetResult& consumeItemSetResult) :
            itemModel(*consumeItemSetResult.getItemModel()),
            inventory(*consumeItemSetResult.getInventory())
        {
            {
                auto& list = *consumeItemSetResult.getItems();
                for (int i = 0; i < list.getCount(); ++i)
                {
                    items += EzItemSet(list[i]);
                }
            }
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzConsumeResult() = default;
    EzConsumeResult(const EzConsumeResult& result) = default;
    EzConsumeResult(EzConsumeResult&& result) = default;
    ~EzConsumeResult() = default;

    EzConsumeResult(gs2::inventory::ConsumeItemSetResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzConsumeResult& operator=(const EzConsumeResult& result) = default;
    EzConsumeResult& operator=(EzConsumeResult&& result) = default;

    EzConsumeResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzConsumeResult);
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
        return ensureData().items;
    }

    const EzItemModel& getItemModel() const
    {
        return ensureData().itemModel;
    }

    const EzInventory& getInventory() const
    {
        return ensureData().inventory;
    }
};

typedef gs2::AsyncResult<EzConsumeResult> AsyncEzConsumeResult;

}}}

#endif //GS2_EZ_INVENTORY_EZCONSUMERESULT_HPP_