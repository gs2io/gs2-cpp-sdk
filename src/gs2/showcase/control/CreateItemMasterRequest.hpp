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

#ifndef GS2_SHOWCASE_CONTROL_CREATEITEMMASTERREQUEST_HPP_
#define GS2_SHOWCASE_CONTROL_CREATEITEMMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ShowcaseConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace showcase
{

/**
 * @author Game Server Services, Inc.
 */
class CreateItemMasterRequest : public Gs2BasicRequest, public Gs2Showcase
{
public:
    constexpr static const Char* const FUNCTION = "CreateItemMaster";

private:
    class Data : public Gs2Object
    {
    public:
        /** ショーケースの名前 */
        optional<StringHolder> showcaseName;
        /** 商品名 */
        optional<StringHolder> name;
        /** メタデータ */
        optional<StringHolder> meta;
        /** 販売通貨 */
        optional<StringHolder> currencyType;
        /** GS2-Money 課金通貨名 */
        optional<StringHolder> currencyMoneyName;
        /** GS2-Gold 通貨名 */
        optional<StringHolder> currencyGoldName;
        /** GS2-Gold 通貨プール名 */
        optional<StringHolder> currencyGoldPoolName;
        /** GS2-ConsumableItem アイテムプール名 */
        optional<StringHolder> currencyConsumableItemItemPoolName;
        /** GS2-ConsumableItem アイテム名 */
        optional<StringHolder> currencyConsumableItemItemName;
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
        /** 購入許可判定の種類 */
        optional<StringHolder> openConditionType;
        /** 購入許可判定 に実行されるGS2-Limit */
        optional<StringHolder> openConditionLimitName;
        /** 購入許可判定 に実行されるGS2-Limit のカウンター */
        optional<StringHolder> openConditionLimitCounterName;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            showcaseName(data.showcaseName),
            name(data.name),
            meta(data.meta),
            currencyType(data.currencyType),
            currencyMoneyName(data.currencyMoneyName),
            currencyGoldName(data.currencyGoldName),
            currencyGoldPoolName(data.currencyGoldPoolName),
            currencyConsumableItemItemPoolName(data.currencyConsumableItemItemPoolName),
            currencyConsumableItemItemName(data.currencyConsumableItemItemName),
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
            openConditionType(data.openConditionType),
            openConditionLimitName(data.openConditionLimitName),
            openConditionLimitCounterName(data.openConditionLimitCounterName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            showcaseName(std::move(data.showcaseName)),
            name(std::move(data.name)),
            meta(std::move(data.meta)),
            currencyType(std::move(data.currencyType)),
            currencyMoneyName(std::move(data.currencyMoneyName)),
            currencyGoldName(std::move(data.currencyGoldName)),
            currencyGoldPoolName(std::move(data.currencyGoldPoolName)),
            currencyConsumableItemItemPoolName(std::move(data.currencyConsumableItemItemPoolName)),
            currencyConsumableItemItemName(std::move(data.currencyConsumableItemItemName)),
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
            openConditionType(std::move(data.openConditionType)),
            openConditionLimitName(std::move(data.openConditionLimitName)),
            openConditionLimitCounterName(std::move(data.openConditionLimitCounterName))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
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
    CreateItemMasterRequest() :
        m_pData(nullptr)
    {}

    CreateItemMasterRequest(const CreateItemMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Showcase(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CreateItemMasterRequest(CreateItemMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Showcase(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CreateItemMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateItemMasterRequest& operator=(const CreateItemMasterRequest& createItemMasterRequest)
    {
        Gs2BasicRequest::operator=(createItemMasterRequest);
        Gs2Showcase::operator=(createItemMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createItemMasterRequest.m_pData);

        return *this;
    }

    CreateItemMasterRequest& operator=(CreateItemMasterRequest&& createItemMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(createItemMasterRequest));
        Gs2Showcase::operator=(std::move(createItemMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createItemMasterRequest.m_pData;
        createItemMasterRequest.m_pData = nullptr;

        return *this;
    }

    const CreateItemMasterRequest* operator->() const
    {
        return this;
    }

    CreateItemMasterRequest* operator->()
    {
        return this;
    }

    /**
     * ショーケースの名前を取得
     *
     * @return ショーケースの名前
     */
    const optional<StringHolder>& getShowcaseName() const
    {
        return ensureData().showcaseName;
    }

    /**
     * ショーケースの名前を設定
     *
     * @param showcaseName ショーケースの名前
     */
    void setShowcaseName(const Char* showcaseName)
    {
        ensureData().showcaseName.emplace(showcaseName);
    }

    /**
     * ショーケースの名前を設定
     *
     * @param showcaseName ショーケースの名前
     */
    CreateItemMasterRequest& withShowcaseName(const Char* showcaseName)
    {
        ensureData().showcaseName.emplace(showcaseName);
        return *this;
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
     * 商品名を設定
     *
     * @param name 商品名
     */
    CreateItemMasterRequest& withName(const Char* name)
    {
        ensureData().name.emplace(name);
        return *this;
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
     * メタデータを設定
     *
     * @param meta メタデータ
     */
    CreateItemMasterRequest& withMeta(const Char* meta)
    {
        ensureData().meta.emplace(meta);
        return *this;
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
     * 販売通貨を設定
     *
     * @param currencyType 販売通貨
     */
    CreateItemMasterRequest& withCurrencyType(const Char* currencyType)
    {
        ensureData().currencyType.emplace(currencyType);
        return *this;
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
     * GS2-Money 課金通貨名を設定
     *
     * @param currencyMoneyName GS2-Money 課金通貨名
     */
    CreateItemMasterRequest& withCurrencyMoneyName(const Char* currencyMoneyName)
    {
        ensureData().currencyMoneyName.emplace(currencyMoneyName);
        return *this;
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
     * GS2-Gold 通貨名を設定
     *
     * @param currencyGoldName GS2-Gold 通貨名
     */
    CreateItemMasterRequest& withCurrencyGoldName(const Char* currencyGoldName)
    {
        ensureData().currencyGoldName.emplace(currencyGoldName);
        return *this;
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
     * GS2-Gold 通貨プール名を設定
     *
     * @param currencyGoldPoolName GS2-Gold 通貨プール名
     */
    CreateItemMasterRequest& withCurrencyGoldPoolName(const Char* currencyGoldPoolName)
    {
        ensureData().currencyGoldPoolName.emplace(currencyGoldPoolName);
        return *this;
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
     * GS2-ConsumableItem アイテムプール名を設定
     *
     * @param currencyConsumableItemItemPoolName GS2-ConsumableItem アイテムプール名
     */
    CreateItemMasterRequest& withCurrencyConsumableItemItemPoolName(const Char* currencyConsumableItemItemPoolName)
    {
        ensureData().currencyConsumableItemItemPoolName.emplace(currencyConsumableItemItemPoolName);
        return *this;
    }

    /**
     * GS2-ConsumableItem アイテム名を取得
     *
     * @return GS2-ConsumableItem アイテム名
     */
    const optional<StringHolder>& getCurrencyConsumableItemItemName() const
    {
        return ensureData().currencyConsumableItemItemName;
    }

    /**
     * GS2-ConsumableItem アイテム名を設定
     *
     * @param currencyConsumableItemItemName GS2-ConsumableItem アイテム名
     */
    void setCurrencyConsumableItemItemName(const Char* currencyConsumableItemItemName)
    {
        ensureData().currencyConsumableItemItemName.emplace(currencyConsumableItemItemName);
    }

    /**
     * GS2-ConsumableItem アイテム名を設定
     *
     * @param currencyConsumableItemItemName GS2-ConsumableItem アイテム名
     */
    CreateItemMasterRequest& withCurrencyConsumableItemItemName(const Char* currencyConsumableItemItemName)
    {
        ensureData().currencyConsumableItemItemName.emplace(currencyConsumableItemItemName);
        return *this;
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
     * 対価消費処理にまつわるオプション値を設定
     *
     * @param currencyOption 対価消費処理にまつわるオプション値
     */
    CreateItemMasterRequest& withCurrencyOption(const Char* currencyOption)
    {
        ensureData().currencyOption.emplace(currencyOption);
        return *this;
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
     * 販売価格を設定
     *
     * @param price 販売価格
     */
    CreateItemMasterRequest& withPrice(Float price)
    {
        ensureData().price.emplace(price);
        return *this;
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
     * 入手アイテムの種類を設定
     *
     * @param itemType 入手アイテムの種類
     */
    CreateItemMasterRequest& withItemType(const Char* itemType)
    {
        ensureData().itemType.emplace(itemType);
        return *this;
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
     * GS2-Money 課金通貨名を設定
     *
     * @param itemMoneyName GS2-Money 課金通貨名
     */
    CreateItemMasterRequest& withItemMoneyName(const Char* itemMoneyName)
    {
        ensureData().itemMoneyName.emplace(itemMoneyName);
        return *this;
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
     * GS2-Gold 通貨プール名を設定
     *
     * @param itemGoldPoolName GS2-Gold 通貨プール名
     */
    CreateItemMasterRequest& withItemGoldPoolName(const Char* itemGoldPoolName)
    {
        ensureData().itemGoldPoolName.emplace(itemGoldPoolName);
        return *this;
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
     * GS2-Gold 通貨名を設定
     *
     * @param itemGoldName GS2-Gold 通貨名
     */
    CreateItemMasterRequest& withItemGoldName(const Char* itemGoldName)
    {
        ensureData().itemGoldName.emplace(itemGoldName);
        return *this;
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
     * GS2-Stamina スタミナプール名を設定
     *
     * @param itemStaminaStaminaPoolName GS2-Stamina スタミナプール名
     */
    CreateItemMasterRequest& withItemStaminaStaminaPoolName(const Char* itemStaminaStaminaPoolName)
    {
        ensureData().itemStaminaStaminaPoolName.emplace(itemStaminaStaminaPoolName);
        return *this;
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
     * GS2-ConsumableItem アイテムプール名を設定
     *
     * @param itemConsumableItemItemPoolName GS2-ConsumableItem アイテムプール名
     */
    CreateItemMasterRequest& withItemConsumableItemItemPoolName(const Char* itemConsumableItemItemPoolName)
    {
        ensureData().itemConsumableItemItemPoolName.emplace(itemConsumableItemItemPoolName);
        return *this;
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
     * GS2-ConsumableItem アイテム名を設定
     *
     * @param itemConsumableItemItemName GS2-ConsumableItem アイテム名
     */
    CreateItemMasterRequest& withItemConsumableItemItemName(const Char* itemConsumableItemItemName)
    {
        ensureData().itemConsumableItemItemName.emplace(itemConsumableItemItemName);
        return *this;
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
     * GS2-Gacha ガチャプール名を設定
     *
     * @param itemGachaGachaPoolName GS2-Gacha ガチャプール名
     */
    CreateItemMasterRequest& withItemGachaGachaPoolName(const Char* itemGachaGachaPoolName)
    {
        ensureData().itemGachaGachaPoolName.emplace(itemGachaGachaPoolName);
        return *this;
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
     * GS2-Gacha ガチャ名を設定
     *
     * @param itemGachaGachaName GS2-Gacha ガチャ名
     */
    CreateItemMasterRequest& withItemGachaGachaName(const Char* itemGachaGachaName)
    {
        ensureData().itemGachaGachaName.emplace(itemGachaGachaName);
        return *this;
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
     * 入手数量を設定
     *
     * @param itemAmount 入手数量
     */
    CreateItemMasterRequest& withItemAmount(Int32 itemAmount)
    {
        ensureData().itemAmount.emplace(itemAmount);
        return *this;
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
     * アイテムの入手処理にまつわるオプション値を設定
     *
     * @param itemOption アイテムの入手処理にまつわるオプション値
     */
    CreateItemMasterRequest& withItemOption(const Char* itemOption)
    {
        ensureData().itemOption.emplace(itemOption);
        return *this;
    }

    /**
     * 購入許可判定の種類を取得
     *
     * @return 購入許可判定の種類
     */
    const optional<StringHolder>& getOpenConditionType() const
    {
        return ensureData().openConditionType;
    }

    /**
     * 購入許可判定の種類を設定
     *
     * @param openConditionType 購入許可判定の種類
     */
    void setOpenConditionType(const Char* openConditionType)
    {
        ensureData().openConditionType.emplace(openConditionType);
    }

    /**
     * 購入許可判定の種類を設定
     *
     * @param openConditionType 購入許可判定の種類
     */
    CreateItemMasterRequest& withOpenConditionType(const Char* openConditionType)
    {
        ensureData().openConditionType.emplace(openConditionType);
        return *this;
    }

    /**
     * 購入許可判定 に実行されるGS2-Limitを取得
     *
     * @return 購入許可判定 に実行されるGS2-Limit
     */
    const optional<StringHolder>& getOpenConditionLimitName() const
    {
        return ensureData().openConditionLimitName;
    }

    /**
     * 購入許可判定 に実行されるGS2-Limitを設定
     *
     * @param openConditionLimitName 購入許可判定 に実行されるGS2-Limit
     */
    void setOpenConditionLimitName(const Char* openConditionLimitName)
    {
        ensureData().openConditionLimitName.emplace(openConditionLimitName);
    }

    /**
     * 購入許可判定 に実行されるGS2-Limitを設定
     *
     * @param openConditionLimitName 購入許可判定 に実行されるGS2-Limit
     */
    CreateItemMasterRequest& withOpenConditionLimitName(const Char* openConditionLimitName)
    {
        ensureData().openConditionLimitName.emplace(openConditionLimitName);
        return *this;
    }

    /**
     * 購入許可判定 に実行されるGS2-Limit のカウンターを取得
     *
     * @return 購入許可判定 に実行されるGS2-Limit のカウンター
     */
    const optional<StringHolder>& getOpenConditionLimitCounterName() const
    {
        return ensureData().openConditionLimitCounterName;
    }

    /**
     * 購入許可判定 に実行されるGS2-Limit のカウンターを設定
     *
     * @param openConditionLimitCounterName 購入許可判定 に実行されるGS2-Limit のカウンター
     */
    void setOpenConditionLimitCounterName(const Char* openConditionLimitCounterName)
    {
        ensureData().openConditionLimitCounterName.emplace(openConditionLimitCounterName);
    }

    /**
     * 購入許可判定 に実行されるGS2-Limit のカウンターを設定
     *
     * @param openConditionLimitCounterName 購入許可判定 に実行されるGS2-Limit のカウンター
     */
    CreateItemMasterRequest& withOpenConditionLimitCounterName(const Char* openConditionLimitCounterName)
    {
        ensureData().openConditionLimitCounterName.emplace(openConditionLimitCounterName);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreateItemMasterRequest& withGs2ClientId(const Char* gs2ClientId)
    {
        setGs2ClientId(gs2ClientId);
        return *this;
    }

    /**
     * タイムスタンプを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2Timestamp タイムスタンプ
     */
    CreateItemMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
    {
        setGs2Timestamp(gs2Timestamp);
        return *this;
    }

    /**
     * GS2認証署名を設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2RequestSign GS2認証署名
     */
    CreateItemMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateItemMasterRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }

    virtual const Char* getModuleName() const
    {
        return MODULE;
    }

    virtual const Char* getFunctionName() const
    {
        return FUNCTION;
    }
};

} }

#endif //GS2_SHOWCASE_CONTROL_CREATEITEMMASTERREQUEST_HPP_