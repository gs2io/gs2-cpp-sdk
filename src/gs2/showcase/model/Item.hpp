/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
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

#ifndef GS2_SHOWCASE_MODEL_ITEM_HPP_
#define GS2_SHOWCASE_MODEL_ITEM_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace showcase {

/**
 * 商品
 *
 * @author Game Server Services, Inc.
 *
 */
class Item : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 陳列商品ID */
        optional<StringHolder> showcaseItemId;
        /** 商品名 */
        optional<StringHolder> name;
        /** メタデータ */
        optional<StringHolder> meta;
        /** 販売通貨 */
        optional<StringHolder> currencyType;
        /** GS2-Money 課金通貨名 */
        optional<StringHolder> currencyMoneyName;
        /** GS2-Gold 通貨プール名 */
        optional<StringHolder> currencyGoldPoolName;
        /** GS2-Gold 通貨名 */
        optional<StringHolder> currencyGoldName;
        /** GS2-ConsumableItem アイテムプール名 */
        optional<StringHolder> currencyConsumableItemItemPoolName;
        /** GS2-ConsumableItem アイテム名 */
        optional<StringHolder> currencyConsumableItemName;
        /** 対価消費処理にまつわるオプション値 */
        optional<StringHolder> currencyOption;
        /** 販売価格 */
        optional<Float> price;
        /** 入手アイテムの種類 */
        optional<StringHolder> itemType;
        /** GS2-Money 課金通貨名 */
        optional<StringHolder> itemMoneyName;
        /** GS2-Gold 通貨プール名 */
        optional<StringHolder> itemGoldPoolName;
        /** GS2-Gold 通貨名 */
        optional<StringHolder> itemGoldName;
        /** GS2-Stamina スタミナプール名 */
        optional<StringHolder> itemStaminaStaminaPoolName;
        /** GS2-ConsumableItem アイテムプール名 */
        optional<StringHolder> itemConsumableItemItemPoolName;
        /** GS2-ConsumableItem アイテム名 */
        optional<StringHolder> itemConsumableItemItemName;
        /** GS2-Gacha ガチャプール名 */
        optional<StringHolder> itemGachaGachaPoolName;
        /** GS2-Gacha ガチャ名 */
        optional<StringHolder> itemGachaGachaName;
        /** 入手数量 */
        optional<Int32> itemAmount;
        /** アイテムの入手処理にまつわるオプション値 */
        optional<StringHolder> itemOption;
        /** 購入可能か */
        optional<Bool> canBuy;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            showcaseItemId(data.showcaseItemId),
            name(data.name),
            meta(data.meta),
            currencyType(data.currencyType),
            currencyMoneyName(data.currencyMoneyName),
            currencyGoldPoolName(data.currencyGoldPoolName),
            currencyGoldName(data.currencyGoldName),
            currencyConsumableItemItemPoolName(data.currencyConsumableItemItemPoolName),
            currencyConsumableItemName(data.currencyConsumableItemName),
            currencyOption(data.currencyOption),
            price(data.price),
            itemType(data.itemType),
            itemMoneyName(data.itemMoneyName),
            itemGoldPoolName(data.itemGoldPoolName),
            itemGoldName(data.itemGoldName),
            itemStaminaStaminaPoolName(data.itemStaminaStaminaPoolName),
            itemConsumableItemItemPoolName(data.itemConsumableItemItemPoolName),
            itemConsumableItemItemName(data.itemConsumableItemItemName),
            itemGachaGachaPoolName(data.itemGachaGachaPoolName),
            itemGachaGachaName(data.itemGachaGachaName),
            itemAmount(data.itemAmount),
            itemOption(data.itemOption),
            canBuy(data.canBuy)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            showcaseItemId(std::move(data.showcaseItemId)),
            name(std::move(data.name)),
            meta(std::move(data.meta)),
            currencyType(std::move(data.currencyType)),
            currencyMoneyName(std::move(data.currencyMoneyName)),
            currencyGoldPoolName(std::move(data.currencyGoldPoolName)),
            currencyGoldName(std::move(data.currencyGoldName)),
            currencyConsumableItemItemPoolName(std::move(data.currencyConsumableItemItemPoolName)),
            currencyConsumableItemName(std::move(data.currencyConsumableItemName)),
            currencyOption(std::move(data.currencyOption)),
            price(std::move(data.price)),
            itemType(std::move(data.itemType)),
            itemMoneyName(std::move(data.itemMoneyName)),
            itemGoldPoolName(std::move(data.itemGoldPoolName)),
            itemGoldName(std::move(data.itemGoldName)),
            itemStaminaStaminaPoolName(std::move(data.itemStaminaStaminaPoolName)),
            itemConsumableItemItemPoolName(std::move(data.itemConsumableItemItemPoolName)),
            itemConsumableItemItemName(std::move(data.itemConsumableItemItemName)),
            itemGachaGachaPoolName(std::move(data.itemGachaGachaPoolName)),
            itemGachaGachaName(std::move(data.itemGachaGachaName)),
            itemAmount(std::move(data.itemAmount)),
            itemOption(std::move(data.itemOption)),
            canBuy(std::move(data.canBuy))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "showcaseItemId") == 0) {
                if (jsonValue.IsString())
                {
                    this->showcaseItemId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "meta") == 0) {
                if (jsonValue.IsString())
                {
                    this->meta.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "currencyType") == 0) {
                if (jsonValue.IsString())
                {
                    this->currencyType.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "currencyMoneyName") == 0) {
                if (jsonValue.IsString())
                {
                    this->currencyMoneyName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "currencyGoldPoolName") == 0) {
                if (jsonValue.IsString())
                {
                    this->currencyGoldPoolName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "currencyGoldName") == 0) {
                if (jsonValue.IsString())
                {
                    this->currencyGoldName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "currencyConsumableItemItemPoolName") == 0) {
                if (jsonValue.IsString())
                {
                    this->currencyConsumableItemItemPoolName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "currencyConsumableItemName") == 0) {
                if (jsonValue.IsString())
                {
                    this->currencyConsumableItemName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "currencyOption") == 0) {
                if (jsonValue.IsString())
                {
                    this->currencyOption.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "price") == 0) {
                if (jsonValue.IsFloat())
                {
                    this->price = jsonValue.GetFloat();
                }
            }
            else if (std::strcmp(name, "itemType") == 0) {
                if (jsonValue.IsString())
                {
                    this->itemType.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "itemMoneyName") == 0) {
                if (jsonValue.IsString())
                {
                    this->itemMoneyName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "itemGoldPoolName") == 0) {
                if (jsonValue.IsString())
                {
                    this->itemGoldPoolName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "itemGoldName") == 0) {
                if (jsonValue.IsString())
                {
                    this->itemGoldName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "itemStaminaStaminaPoolName") == 0) {
                if (jsonValue.IsString())
                {
                    this->itemStaminaStaminaPoolName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "itemConsumableItemItemPoolName") == 0) {
                if (jsonValue.IsString())
                {
                    this->itemConsumableItemItemPoolName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "itemConsumableItemItemName") == 0) {
                if (jsonValue.IsString())
                {
                    this->itemConsumableItemItemName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "itemGachaGachaPoolName") == 0) {
                if (jsonValue.IsString())
                {
                    this->itemGachaGachaPoolName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "itemGachaGachaName") == 0) {
                if (jsonValue.IsString())
                {
                    this->itemGachaGachaName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "itemAmount") == 0) {
                if (jsonValue.IsInt())
                {
                    this->itemAmount = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "itemOption") == 0) {
                if (jsonValue.IsString())
                {
                    this->itemOption.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "canBuy") == 0) {
                if (jsonValue.IsBool())
                {
                    this->canBuy = jsonValue.GetBool();
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
    Item() :
        m_pData(nullptr)
    {}

    Item(const Item& item) :
        Gs2Object(item),
        m_pData(item.m_pData != nullptr ? new Data(*item.m_pData) : nullptr)
    {}

    Item(Item&& item) :
        Gs2Object(std::move(item)),
        m_pData(item.m_pData)
    {
        item.m_pData = nullptr;
    }

    ~Item()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Item& operator=(const Item& item)
    {
        Gs2Object::operator=(item);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*item.m_pData);

        return *this;
    }

    Item& operator=(Item&& item)
    {
        Gs2Object::operator=(std::move(item));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = item.m_pData;
        item.m_pData = nullptr;

        return *this;
    }

    const Item* operator->() const
    {
        return this;
    }

    Item* operator->()
    {
        return this;
    }


    /**
     * 陳列商品IDを取得
     *
     * @return 陳列商品ID
     */
    const optional<StringHolder>& getShowcaseItemId() const
    {
        return ensureData().showcaseItemId;
    }

    /**
     * 陳列商品IDを設定
     *
     * @param showcaseItemId 陳列商品ID
     */
    void setShowcaseItemId(const Char* showcaseItemId)
    {
        ensureData().showcaseItemId.emplace(showcaseItemId);
    }

    /**
     * 商品名を取得
     *
     * @return 商品名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 商品名を設定
     *
     * @param name 商品名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * メタデータを取得
     *
     * @return メタデータ
     */
    const optional<StringHolder>& getMeta() const
    {
        return ensureData().meta;
    }

    /**
     * メタデータを設定
     *
     * @param meta メタデータ
     */
    void setMeta(const Char* meta)
    {
        ensureData().meta.emplace(meta);
    }

    /**
     * 販売通貨を取得
     *
     * @return 販売通貨
     */
    const optional<StringHolder>& getCurrencyType() const
    {
        return ensureData().currencyType;
    }

    /**
     * 販売通貨を設定
     *
     * @param currencyType 販売通貨
     */
    void setCurrencyType(const Char* currencyType)
    {
        ensureData().currencyType.emplace(currencyType);
    }

    /**
     * GS2-Money 課金通貨名を取得
     *
     * @return GS2-Money 課金通貨名
     */
    const optional<StringHolder>& getCurrencyMoneyName() const
    {
        return ensureData().currencyMoneyName;
    }

    /**
     * GS2-Money 課金通貨名を設定
     *
     * @param currencyMoneyName GS2-Money 課金通貨名
     */
    void setCurrencyMoneyName(const Char* currencyMoneyName)
    {
        ensureData().currencyMoneyName.emplace(currencyMoneyName);
    }

    /**
     * GS2-Gold 通貨プール名を取得
     *
     * @return GS2-Gold 通貨プール名
     */
    const optional<StringHolder>& getCurrencyGoldPoolName() const
    {
        return ensureData().currencyGoldPoolName;
    }

    /**
     * GS2-Gold 通貨プール名を設定
     *
     * @param currencyGoldPoolName GS2-Gold 通貨プール名
     */
    void setCurrencyGoldPoolName(const Char* currencyGoldPoolName)
    {
        ensureData().currencyGoldPoolName.emplace(currencyGoldPoolName);
    }

    /**
     * GS2-Gold 通貨名を取得
     *
     * @return GS2-Gold 通貨名
     */
    const optional<StringHolder>& getCurrencyGoldName() const
    {
        return ensureData().currencyGoldName;
    }

    /**
     * GS2-Gold 通貨名を設定
     *
     * @param currencyGoldName GS2-Gold 通貨名
     */
    void setCurrencyGoldName(const Char* currencyGoldName)
    {
        ensureData().currencyGoldName.emplace(currencyGoldName);
    }

    /**
     * GS2-ConsumableItem アイテムプール名を取得
     *
     * @return GS2-ConsumableItem アイテムプール名
     */
    const optional<StringHolder>& getCurrencyConsumableItemItemPoolName() const
    {
        return ensureData().currencyConsumableItemItemPoolName;
    }

    /**
     * GS2-ConsumableItem アイテムプール名を設定
     *
     * @param currencyConsumableItemItemPoolName GS2-ConsumableItem アイテムプール名
     */
    void setCurrencyConsumableItemItemPoolName(const Char* currencyConsumableItemItemPoolName)
    {
        ensureData().currencyConsumableItemItemPoolName.emplace(currencyConsumableItemItemPoolName);
    }

    /**
     * GS2-ConsumableItem アイテム名を取得
     *
     * @return GS2-ConsumableItem アイテム名
     */
    const optional<StringHolder>& getCurrencyConsumableItemName() const
    {
        return ensureData().currencyConsumableItemName;
    }

    /**
     * GS2-ConsumableItem アイテム名を設定
     *
     * @param currencyConsumableItemName GS2-ConsumableItem アイテム名
     */
    void setCurrencyConsumableItemName(const Char* currencyConsumableItemName)
    {
        ensureData().currencyConsumableItemName.emplace(currencyConsumableItemName);
    }

    /**
     * 対価消費処理にまつわるオプション値を取得
     *
     * @return 対価消費処理にまつわるオプション値
     */
    const optional<StringHolder>& getCurrencyOption() const
    {
        return ensureData().currencyOption;
    }

    /**
     * 対価消費処理にまつわるオプション値を設定
     *
     * @param currencyOption 対価消費処理にまつわるオプション値
     */
    void setCurrencyOption(const Char* currencyOption)
    {
        ensureData().currencyOption.emplace(currencyOption);
    }

    /**
     * 販売価格を取得
     *
     * @return 販売価格
     */
    const optional<Float>& getPrice() const
    {
        return ensureData().price;
    }

    /**
     * 販売価格を設定
     *
     * @param price 販売価格
     */
    void setPrice(Float price)
    {
        ensureData().price.emplace(price);
    }

    /**
     * 入手アイテムの種類を取得
     *
     * @return 入手アイテムの種類
     */
    const optional<StringHolder>& getItemType() const
    {
        return ensureData().itemType;
    }

    /**
     * 入手アイテムの種類を設定
     *
     * @param itemType 入手アイテムの種類
     */
    void setItemType(const Char* itemType)
    {
        ensureData().itemType.emplace(itemType);
    }

    /**
     * GS2-Money 課金通貨名を取得
     *
     * @return GS2-Money 課金通貨名
     */
    const optional<StringHolder>& getItemMoneyName() const
    {
        return ensureData().itemMoneyName;
    }

    /**
     * GS2-Money 課金通貨名を設定
     *
     * @param itemMoneyName GS2-Money 課金通貨名
     */
    void setItemMoneyName(const Char* itemMoneyName)
    {
        ensureData().itemMoneyName.emplace(itemMoneyName);
    }

    /**
     * GS2-Gold 通貨プール名を取得
     *
     * @return GS2-Gold 通貨プール名
     */
    const optional<StringHolder>& getItemGoldPoolName() const
    {
        return ensureData().itemGoldPoolName;
    }

    /**
     * GS2-Gold 通貨プール名を設定
     *
     * @param itemGoldPoolName GS2-Gold 通貨プール名
     */
    void setItemGoldPoolName(const Char* itemGoldPoolName)
    {
        ensureData().itemGoldPoolName.emplace(itemGoldPoolName);
    }

    /**
     * GS2-Gold 通貨名を取得
     *
     * @return GS2-Gold 通貨名
     */
    const optional<StringHolder>& getItemGoldName() const
    {
        return ensureData().itemGoldName;
    }

    /**
     * GS2-Gold 通貨名を設定
     *
     * @param itemGoldName GS2-Gold 通貨名
     */
    void setItemGoldName(const Char* itemGoldName)
    {
        ensureData().itemGoldName.emplace(itemGoldName);
    }

    /**
     * GS2-Stamina スタミナプール名を取得
     *
     * @return GS2-Stamina スタミナプール名
     */
    const optional<StringHolder>& getItemStaminaStaminaPoolName() const
    {
        return ensureData().itemStaminaStaminaPoolName;
    }

    /**
     * GS2-Stamina スタミナプール名を設定
     *
     * @param itemStaminaStaminaPoolName GS2-Stamina スタミナプール名
     */
    void setItemStaminaStaminaPoolName(const Char* itemStaminaStaminaPoolName)
    {
        ensureData().itemStaminaStaminaPoolName.emplace(itemStaminaStaminaPoolName);
    }

    /**
     * GS2-ConsumableItem アイテムプール名を取得
     *
     * @return GS2-ConsumableItem アイテムプール名
     */
    const optional<StringHolder>& getItemConsumableItemItemPoolName() const
    {
        return ensureData().itemConsumableItemItemPoolName;
    }

    /**
     * GS2-ConsumableItem アイテムプール名を設定
     *
     * @param itemConsumableItemItemPoolName GS2-ConsumableItem アイテムプール名
     */
    void setItemConsumableItemItemPoolName(const Char* itemConsumableItemItemPoolName)
    {
        ensureData().itemConsumableItemItemPoolName.emplace(itemConsumableItemItemPoolName);
    }

    /**
     * GS2-ConsumableItem アイテム名を取得
     *
     * @return GS2-ConsumableItem アイテム名
     */
    const optional<StringHolder>& getItemConsumableItemItemName() const
    {
        return ensureData().itemConsumableItemItemName;
    }

    /**
     * GS2-ConsumableItem アイテム名を設定
     *
     * @param itemConsumableItemItemName GS2-ConsumableItem アイテム名
     */
    void setItemConsumableItemItemName(const Char* itemConsumableItemItemName)
    {
        ensureData().itemConsumableItemItemName.emplace(itemConsumableItemItemName);
    }

    /**
     * GS2-Gacha ガチャプール名を取得
     *
     * @return GS2-Gacha ガチャプール名
     */
    const optional<StringHolder>& getItemGachaGachaPoolName() const
    {
        return ensureData().itemGachaGachaPoolName;
    }

    /**
     * GS2-Gacha ガチャプール名を設定
     *
     * @param itemGachaGachaPoolName GS2-Gacha ガチャプール名
     */
    void setItemGachaGachaPoolName(const Char* itemGachaGachaPoolName)
    {
        ensureData().itemGachaGachaPoolName.emplace(itemGachaGachaPoolName);
    }

    /**
     * GS2-Gacha ガチャ名を取得
     *
     * @return GS2-Gacha ガチャ名
     */
    const optional<StringHolder>& getItemGachaGachaName() const
    {
        return ensureData().itemGachaGachaName;
    }

    /**
     * GS2-Gacha ガチャ名を設定
     *
     * @param itemGachaGachaName GS2-Gacha ガチャ名
     */
    void setItemGachaGachaName(const Char* itemGachaGachaName)
    {
        ensureData().itemGachaGachaName.emplace(itemGachaGachaName);
    }

    /**
     * 入手数量を取得
     *
     * @return 入手数量
     */
    const optional<Int32>& getItemAmount() const
    {
        return ensureData().itemAmount;
    }

    /**
     * 入手数量を設定
     *
     * @param itemAmount 入手数量
     */
    void setItemAmount(Int32 itemAmount)
    {
        ensureData().itemAmount.emplace(itemAmount);
    }

    /**
     * アイテムの入手処理にまつわるオプション値を取得
     *
     * @return アイテムの入手処理にまつわるオプション値
     */
    const optional<StringHolder>& getItemOption() const
    {
        return ensureData().itemOption;
    }

    /**
     * アイテムの入手処理にまつわるオプション値を設定
     *
     * @param itemOption アイテムの入手処理にまつわるオプション値
     */
    void setItemOption(const Char* itemOption)
    {
        ensureData().itemOption.emplace(itemOption);
    }

    /**
     * 購入可能かを取得
     *
     * @return 購入可能か
     */
    const optional<Bool>& getCanBuy() const
    {
        return ensureData().canBuy;
    }

    /**
     * 購入可能かを設定
     *
     * @param canBuy 購入可能か
     */
    void setCanBuy(Bool canBuy)
    {
        ensureData().canBuy.emplace(canBuy);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_SHOWCASE_MODEL_ITEM_HPP_