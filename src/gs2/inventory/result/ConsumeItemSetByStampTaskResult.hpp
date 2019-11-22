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

#ifndef GS2_INVENTORY_CONTROL_CONSUMEITEMSETBYSTAMPTASKRESULT_HPP_
#define GS2_INVENTORY_CONTROL_CONSUMEITEMSETBYSTAMPTASKRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/inventory/model/model.hpp>
#include <memory>

namespace gs2 { namespace inventory
{

/**
 * スタンプシートでインベントリのアイテムを消費 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class ConsumeItemSetByStampTaskResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 消費後の有効期限ごとのアイテム所持数量のリスト */
        optional<List<ItemSet>> items;
        /** アイテムモデル */
        optional<ItemModel> itemModel;
        /** インベントリ */
        optional<Inventory> inventory;
        /** スタンプタスクの実行結果を記録したコンテキスト */
        optional<StringHolder> newContextStack;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        ~Data() GS2_OVERRIDE = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        void set(const Char name_[], const detail::json::JsonConstValue& jsonValue) GS2_OVERRIDE;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    ConsumeItemSetByStampTaskResult() = default;
    ConsumeItemSetByStampTaskResult(const ConsumeItemSetByStampTaskResult& consumeItemSetByStampTaskResult) = default;
    ConsumeItemSetByStampTaskResult(ConsumeItemSetByStampTaskResult&& consumeItemSetByStampTaskResult) = default;
    ~ConsumeItemSetByStampTaskResult() = default;

    ConsumeItemSetByStampTaskResult& operator=(const ConsumeItemSetByStampTaskResult& consumeItemSetByStampTaskResult) = default;
    ConsumeItemSetByStampTaskResult& operator=(ConsumeItemSetByStampTaskResult&& consumeItemSetByStampTaskResult) = default;

    ConsumeItemSetByStampTaskResult deepCopy() const;

    const ConsumeItemSetByStampTaskResult* operator->() const
    {
        return this;
    }

    ConsumeItemSetByStampTaskResult* operator->()
    {
        return this;
    }
    /**
     * 消費後の有効期限ごとのアイテム所持数量のリストを取得
     *
     * @return 消費後の有効期限ごとのアイテム所持数量のリスト
     */
    const optional<List<ItemSet>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * 消費後の有効期限ごとのアイテム所持数量のリストを設定
     *
     * @param items 消費後の有効期限ごとのアイテム所持数量のリスト
     */
    void setItems(List<ItemSet> items)
    {
        ensureData().items.emplace(std::move(items));
    }

    /**
     * アイテムモデルを取得
     *
     * @return アイテムモデル
     */
    const optional<ItemModel>& getItemModel() const
    {
        return ensureData().itemModel;
    }

    /**
     * アイテムモデルを設定
     *
     * @param itemModel アイテムモデル
     */
    void setItemModel(ItemModel itemModel)
    {
        ensureData().itemModel.emplace(std::move(itemModel));
    }

    /**
     * インベントリを取得
     *
     * @return インベントリ
     */
    const optional<Inventory>& getInventory() const
    {
        return ensureData().inventory;
    }

    /**
     * インベントリを設定
     *
     * @param inventory インベントリ
     */
    void setInventory(Inventory inventory)
    {
        ensureData().inventory.emplace(std::move(inventory));
    }

    /**
     * スタンプタスクの実行結果を記録したコンテキストを取得
     *
     * @return スタンプタスクの実行結果を記録したコンテキスト
     */
    const optional<StringHolder>& getNewContextStack() const
    {
        return ensureData().newContextStack;
    }

    /**
     * スタンプタスクの実行結果を記録したコンテキストを設定
     *
     * @param newContextStack スタンプタスクの実行結果を記録したコンテキスト
     */
    void setNewContextStack(StringHolder newContextStack)
    {
        ensureData().newContextStack.emplace(std::move(newContextStack));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<ConsumeItemSetByStampTaskResult> AsyncConsumeItemSetByStampTaskResult;

} }

#endif //GS2_INVENTORY_CONTROL_CONSUMEITEMSETBYSTAMPTASKRESULT_HPP_