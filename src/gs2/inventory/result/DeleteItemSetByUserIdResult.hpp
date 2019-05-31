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

#ifndef GS2_INVENTORY_CONTROL_DELETEITEMSETBYUSERIDRESULT_HPP_
#define GS2_INVENTORY_CONTROL_DELETEITEMSETBYUSERIDRESULT_HPP_

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
 * アイテムセットを削除 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DeleteItemSetByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 削除したアイテムセットのリスト */
        optional<List<ItemSet>> items;
        /** アイテムマスター */
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
    DeleteItemSetByUserIdResult() :
        m_pData(nullptr)
    {}

    DeleteItemSetByUserIdResult(const DeleteItemSetByUserIdResult& deleteItemSetByUserIdResult) :
        Gs2Object(deleteItemSetByUserIdResult),
        m_pData(deleteItemSetByUserIdResult.m_pData != nullptr ? new Data(*deleteItemSetByUserIdResult.m_pData) : nullptr)
    {}

    DeleteItemSetByUserIdResult(DeleteItemSetByUserIdResult&& deleteItemSetByUserIdResult) :
        Gs2Object(std::move(deleteItemSetByUserIdResult)),
        m_pData(deleteItemSetByUserIdResult.m_pData)
    {
        deleteItemSetByUserIdResult.m_pData = nullptr;
    }

    ~DeleteItemSetByUserIdResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DeleteItemSetByUserIdResult& operator=(const DeleteItemSetByUserIdResult& deleteItemSetByUserIdResult)
    {
        Gs2Object::operator=(deleteItemSetByUserIdResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*deleteItemSetByUserIdResult.m_pData);

        return *this;
    }

    DeleteItemSetByUserIdResult& operator=(DeleteItemSetByUserIdResult&& deleteItemSetByUserIdResult)
    {
        Gs2Object::operator=(std::move(deleteItemSetByUserIdResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = deleteItemSetByUserIdResult.m_pData;
        deleteItemSetByUserIdResult.m_pData = nullptr;

        return *this;
    }

    const DeleteItemSetByUserIdResult* operator->() const
    {
        return this;
    }

    DeleteItemSetByUserIdResult* operator->()
    {
        return this;
    }
    /**
     * 削除したアイテムセットのリストを取得
     *
     * @return 削除したアイテムセットのリスト
     */
    const optional<List<ItemSet>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * 削除したアイテムセットのリストを設定
     *
     * @param items 削除したアイテムセットのリスト
     */
    void setItems(const List<ItemSet>& items)
    {
        ensureData().items.emplace(items);
    }

    /**
     * アイテムマスターを取得
     *
     * @return アイテムマスター
     */
    const optional<ItemModel>& getItemModel() const
    {
        return ensureData().itemModel;
    }

    /**
     * アイテムマスターを設定
     *
     * @param itemModel アイテムマスター
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

#endif //GS2_INVENTORY_CONTROL_DELETEITEMSETBYUSERIDRESULT_HPP_