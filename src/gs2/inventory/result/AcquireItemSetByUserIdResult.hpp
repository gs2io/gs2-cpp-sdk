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

#ifndef GS2_INVENTORY_CONTROL_ACQUIREITEMSETBYUSERIDRESULT_HPP_
#define GS2_INVENTORY_CONTROL_ACQUIREITEMSETBYUSERIDRESULT_HPP_

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
 * アイテムをインベントリに追加 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class AcquireItemSetByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 加算後の有効期限ごとのアイテム所持数量のリスト */
        optional<List<ItemSet>> items;
        /** アイテムモデル */
        optional<ItemModel> itemModel;
        /** インベントリ */
        optional<Inventory> inventory;
        /** 所持数量の上限を超えて受け取れずに GS2-Inbox に転送したアイテムの数量 */
        optional<Int64> overflowCount;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            items(data.items),
            itemModel(data.itemModel),
            inventory(data.inventory),
            overflowCount(data.overflowCount)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            items(std::move(data.items)),
            itemModel(std::move(data.itemModel)),
            inventory(std::move(data.inventory)),
            overflowCount(std::move(data.overflowCount))
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
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        detail::addToList(*this->items, std::move(item));
                    }
                }
            }
            else if (std::strcmp(name, "itemModel") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->itemModel.emplace();
                    detail::json::JsonParser::parse(&this->itemModel->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name, "inventory") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->inventory.emplace();
                    detail::json::JsonParser::parse(&this->inventory->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name, "overflowCount") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->overflowCount = jsonValue.GetInt64();
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
    AcquireItemSetByUserIdResult() :
        m_pData(nullptr)
    {}

    AcquireItemSetByUserIdResult(const AcquireItemSetByUserIdResult& acquireItemSetByUserIdResult) :
        Gs2Object(acquireItemSetByUserIdResult),
        m_pData(acquireItemSetByUserIdResult.m_pData != nullptr ? new Data(*acquireItemSetByUserIdResult.m_pData) : nullptr)
    {}

    AcquireItemSetByUserIdResult(AcquireItemSetByUserIdResult&& acquireItemSetByUserIdResult) :
        Gs2Object(std::move(acquireItemSetByUserIdResult)),
        m_pData(acquireItemSetByUserIdResult.m_pData)
    {
        acquireItemSetByUserIdResult.m_pData = nullptr;
    }

    ~AcquireItemSetByUserIdResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    AcquireItemSetByUserIdResult& operator=(const AcquireItemSetByUserIdResult& acquireItemSetByUserIdResult)
    {
        Gs2Object::operator=(acquireItemSetByUserIdResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*acquireItemSetByUserIdResult.m_pData);

        return *this;
    }

    AcquireItemSetByUserIdResult& operator=(AcquireItemSetByUserIdResult&& acquireItemSetByUserIdResult)
    {
        Gs2Object::operator=(std::move(acquireItemSetByUserIdResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = acquireItemSetByUserIdResult.m_pData;
        acquireItemSetByUserIdResult.m_pData = nullptr;

        return *this;
    }

    const AcquireItemSetByUserIdResult* operator->() const
    {
        return this;
    }

    AcquireItemSetByUserIdResult* operator->()
    {
        return this;
    }
    /**
     * 加算後の有効期限ごとのアイテム所持数量のリストを取得
     *
     * @return 加算後の有効期限ごとのアイテム所持数量のリスト
     */
    const optional<List<ItemSet>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * 加算後の有効期限ごとのアイテム所持数量のリストを設定
     *
     * @param items 加算後の有効期限ごとのアイテム所持数量のリスト
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

    /**
     * 所持数量の上限を超えて受け取れずに GS2-Inbox に転送したアイテムの数量を取得
     *
     * @return 所持数量の上限を超えて受け取れずに GS2-Inbox に転送したアイテムの数量
     */
    const optional<Int64>& getOverflowCount() const
    {
        return ensureData().overflowCount;
    }

    /**
     * 所持数量の上限を超えて受け取れずに GS2-Inbox に転送したアイテムの数量を設定
     *
     * @param overflowCount 所持数量の上限を超えて受け取れずに GS2-Inbox に転送したアイテムの数量
     */
    void setOverflowCount(Int64 overflowCount)
    {
        ensureData().overflowCount.emplace(overflowCount);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_INVENTORY_CONTROL_ACQUIREITEMSETBYUSERIDRESULT_HPP_