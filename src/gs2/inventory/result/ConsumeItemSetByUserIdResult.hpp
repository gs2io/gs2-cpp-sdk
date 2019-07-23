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

#ifndef GS2_INVENTORY_CONTROL_CONSUMEITEMSETBYUSERIDRESULT_HPP_
#define GS2_INVENTORY_CONTROL_CONSUMEITEMSETBYUSERIDRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace inventory
{

/**
 * インベントリのアイテムを消費 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class ConsumeItemSetByUserIdResult : public Gs2Object
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

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            items(data.items),
            itemModel(data.itemModel),
            inventory(data.inventory)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            items(std::move(data.items)),
            itemModel(std::move(data.itemModel)),
            inventory(std::move(data.inventory))
        {}

        virtual ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "items") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->items.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        ItemSet item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(json->GetObject()));
                        detail::addToList(*this->items, std::move(item));
                    }
                }
            }
            else if (std::strcmp(name, "itemModel") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = jsonValue.GetObject();
                    this->itemModel.emplace();
                    detail::json::JsonParser::parse(&this->itemModel->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name, "inventory") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = jsonValue.GetObject();
                    this->inventory.emplace();
                    detail::json::JsonParser::parse(&this->inventory->getModel(), jsonObject);
                }
            }
        }
    };

    Data* m_pData;

    Data& ensureData() {
        if (m_pData == nullptr) {
            m_pData = new Data();
        }
        return *m_pData;
    }

    const Data& ensureData() const {
        if (m_pData == nullptr) {
            *const_cast<Data**>(&m_pData) = new Data();
        }
        return *m_pData;
    }

public:
    ConsumeItemSetByUserIdResult() :
        m_pData(nullptr)
    {}

    ConsumeItemSetByUserIdResult(const ConsumeItemSetByUserIdResult& consumeItemSetByUserIdResult) :
        Gs2Object(consumeItemSetByUserIdResult),
        m_pData(consumeItemSetByUserIdResult.m_pData != nullptr ? new Data(*consumeItemSetByUserIdResult.m_pData) : nullptr)
    {}

    ConsumeItemSetByUserIdResult(ConsumeItemSetByUserIdResult&& consumeItemSetByUserIdResult) :
        Gs2Object(std::move(consumeItemSetByUserIdResult)),
        m_pData(consumeItemSetByUserIdResult.m_pData)
    {
        consumeItemSetByUserIdResult.m_pData = nullptr;
    }

    ~ConsumeItemSetByUserIdResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    ConsumeItemSetByUserIdResult& operator=(const ConsumeItemSetByUserIdResult& consumeItemSetByUserIdResult)
    {
        Gs2Object::operator=(consumeItemSetByUserIdResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*consumeItemSetByUserIdResult.m_pData);

        return *this;
    }

    ConsumeItemSetByUserIdResult& operator=(ConsumeItemSetByUserIdResult&& consumeItemSetByUserIdResult)
    {
        Gs2Object::operator=(std::move(consumeItemSetByUserIdResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = consumeItemSetByUserIdResult.m_pData;
        consumeItemSetByUserIdResult.m_pData = nullptr;

        return *this;
    }

    const ConsumeItemSetByUserIdResult* operator->() const
    {
        return this;
    }

    ConsumeItemSetByUserIdResult* operator->()
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
    void setItems(const List<ItemSet>& items)
    {
        ensureData().items.emplace(items);
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
    void setItemModel(const ItemModel& itemModel)
    {
        ensureData().itemModel.emplace(itemModel);
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
    void setInventory(const Inventory& inventory)
    {
        ensureData().inventory.emplace(inventory);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_INVENTORY_CONTROL_CONSUMEITEMSETBYUSERIDRESULT_HPP_