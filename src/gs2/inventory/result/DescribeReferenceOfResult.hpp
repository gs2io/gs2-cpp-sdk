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

#ifndef GS2_INVENTORY_CONTROL_DESCRIBEREFERENCEOFRESULT_HPP_
#define GS2_INVENTORY_CONTROL_DESCRIBEREFERENCEOFRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/inventory/model/model.hpp>
#include <memory>

namespace gs2 { namespace inventory
{

/**
 * 参照元の一覧を取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DescribeReferenceOfResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** この所持品の参照元リスト */
        optional<List<StringHolder>> items;
        /** 有効期限ごとのアイテム所持数量 */
        optional<ItemSet> itemSet;
        /** アイテムモデル */
        optional<ItemModel> itemModel;
        /** インベントリ */
        optional<Inventory> inventory;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data)
        {
            if (data.items)
            {
                items = data.items->deepCopy();
            }
            if (data.itemSet)
            {
                itemSet = data.itemSet->deepCopy();
            }
            if (data.itemModel)
            {
                itemModel = data.itemModel->deepCopy();
            }
            if (data.inventory)
            {
                inventory = data.inventory->deepCopy();
            }
        }

        Data(Data&& data) = default;

        virtual ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "items") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->items.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        auto valueStr = json->GetString();
                        StringHolder stringHolder(valueStr);
                        *this->items += std::move(stringHolder);
                    }
                }
            }
            else if (std::strcmp(name_, "itemSet") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->itemSet.emplace();
                    detail::json::JsonParser::parse(&this->itemSet->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "itemModel") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->itemModel.emplace();
                    detail::json::JsonParser::parse(&this->itemModel->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "inventory") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->inventory.emplace();
                    detail::json::JsonParser::parse(&this->inventory->getModel(), jsonObject);
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    DescribeReferenceOfResult() = default;
    DescribeReferenceOfResult(const DescribeReferenceOfResult& describeReferenceOfResult) = default;
    DescribeReferenceOfResult(DescribeReferenceOfResult&& describeReferenceOfResult) = default;
    ~DescribeReferenceOfResult() = default;

    DescribeReferenceOfResult& operator=(const DescribeReferenceOfResult& describeReferenceOfResult) = default;
    DescribeReferenceOfResult& operator=(DescribeReferenceOfResult&& describeReferenceOfResult) = default;

    DescribeReferenceOfResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DescribeReferenceOfResult);
    }

    const DescribeReferenceOfResult* operator->() const
    {
        return this;
    }

    DescribeReferenceOfResult* operator->()
    {
        return this;
    }
    /**
     * この所持品の参照元リストを取得
     *
     * @return この所持品の参照元リスト
     */
    const optional<List<StringHolder>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * この所持品の参照元リストを設定
     *
     * @param items この所持品の参照元リスト
     */
    void setItems(List<StringHolder> items)
    {
        ensureData().items.emplace(std::move(items));
    }

    /**
     * 有効期限ごとのアイテム所持数量を取得
     *
     * @return 有効期限ごとのアイテム所持数量
     */
    const optional<ItemSet>& getItemSet() const
    {
        return ensureData().itemSet;
    }

    /**
     * 有効期限ごとのアイテム所持数量を設定
     *
     * @param itemSet 有効期限ごとのアイテム所持数量
     */
    void setItemSet(ItemSet itemSet)
    {
        ensureData().itemSet.emplace(std::move(itemSet));
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


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<DescribeReferenceOfResult> AsyncDescribeReferenceOfResult;

} }

#endif //GS2_INVENTORY_CONTROL_DESCRIBEREFERENCEOFRESULT_HPP_