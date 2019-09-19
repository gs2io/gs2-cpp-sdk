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

#ifndef GS2_EZ_INVENTORY_EZGETITEMRESULT_HPP_
#define GS2_EZ_INVENTORY_EZGETITEMRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/inventory/result/GetItemSetResult.hpp>


namespace gs2 { namespace ez { namespace inventory {

class EzGetItemResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 有効期限毎の{model_name} */
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

        Data(const gs2::inventory::GetItemSetResult& getItemSetResult) :
            itemModel(*getItemSetResult.getItemModel()),
            inventory(*getItemSetResult.getInventory())
        {
            {
                auto& list = *getItemSetResult.getItems();
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
    EzGetItemResult() = default;
    EzGetItemResult(const EzGetItemResult& result) = default;
    EzGetItemResult(EzGetItemResult&& result) = default;
    ~EzGetItemResult() = default;

    EzGetItemResult(gs2::inventory::GetItemSetResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzGetItemResult& operator=(const EzGetItemResult& result) = default;
    EzGetItemResult& operator=(EzGetItemResult&& result) = default;

    EzGetItemResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzGetItemResult);
    }

    static bool isConvertible(const gs2::inventory::GetItemSetResult& result)
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

typedef gs2::AsyncResult<EzGetItemResult> AsyncEzGetItemResult;

}}}

#endif //GS2_EZ_INVENTORY_EZGETITEMRESULT_HPP_