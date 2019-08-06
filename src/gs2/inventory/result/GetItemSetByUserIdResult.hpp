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

#ifndef GS2_INVENTORY_CONTROL_GETITEMSETBYUSERIDRESULT_HPP_
#define GS2_INVENTORY_CONTROL_GETITEMSETBYUSERIDRESULT_HPP_

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
 * 有効期限ごとのアイテム所持数量を取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class GetItemSetByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 有効期限毎の{model_name} */
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

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "items") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->items.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        ItemSet item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        detail::addToList(*this->items, std::move(item));
                    }
                }
            }
            else if (std::strcmp(name_, "itemModel") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->itemModel.emplace();
                    detail::json::JsonParser::parse(&this->itemModel->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "inventory") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
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
    GetItemSetByUserIdResult() :
        m_pData(nullptr)
    {}

    GetItemSetByUserIdResult(const GetItemSetByUserIdResult& getItemSetByUserIdResult) :
        Gs2Object(getItemSetByUserIdResult),
        m_pData(getItemSetByUserIdResult.m_pData != nullptr ? new Data(*getItemSetByUserIdResult.m_pData) : nullptr)
    {}

    GetItemSetByUserIdResult(GetItemSetByUserIdResult&& getItemSetByUserIdResult) :
        Gs2Object(std::move(getItemSetByUserIdResult)),
        m_pData(getItemSetByUserIdResult.m_pData)
    {
        getItemSetByUserIdResult.m_pData = nullptr;
    }

    ~GetItemSetByUserIdResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetItemSetByUserIdResult& operator=(const GetItemSetByUserIdResult& getItemSetByUserIdResult)
    {
        Gs2Object::operator=(getItemSetByUserIdResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getItemSetByUserIdResult.m_pData);

        return *this;
    }

    GetItemSetByUserIdResult& operator=(GetItemSetByUserIdResult&& getItemSetByUserIdResult)
    {
        Gs2Object::operator=(std::move(getItemSetByUserIdResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getItemSetByUserIdResult.m_pData;
        getItemSetByUserIdResult.m_pData = nullptr;

        return *this;
    }

    const GetItemSetByUserIdResult* operator->() const
    {
        return this;
    }

    GetItemSetByUserIdResult* operator->()
    {
        return this;
    }
    /**
     * 有効期限毎の{model_name}を取得
     *
     * @return 有効期限毎の{model_name}
     */
    const optional<List<ItemSet>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * 有効期限毎の{model_name}を設定
     *
     * @param items 有効期限毎の{model_name}
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

#endif //GS2_INVENTORY_CONTROL_GETITEMSETBYUSERIDRESULT_HPP_