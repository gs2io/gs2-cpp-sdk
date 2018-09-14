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

#ifndef GS2_MONEY_MODEL_PLATFORMEDITEM_HPP_
#define GS2_MONEY_MODEL_PLATFORMEDITEM_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace money {

/**
 * プラットフォーム個別商品
 *
 * @author Game Server Services, Inc.
 *
 */
class PlatformedItem : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** プラットフォーム個別商品GRN */
        optional<StringHolder> platformedItemId;
        /** 課金通貨GRN */
        optional<StringHolder> moneyId;
        /** 商品GRN */
        optional<StringHolder> itemId;
        /** 販売プラットフォーム */
        optional<StringHolder> platform;
        /** アプリ内課金ID */
        optional<StringHolder> name;
        /** 販売価格 */
        optional<Double> price;
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;
        /** 最終更新日時(エポック秒) */
        optional<Int32> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            platformedItemId(data.platformedItemId),
            moneyId(data.moneyId),
            itemId(data.itemId),
            platform(data.platform),
            name(data.name),
            price(data.price),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            platformedItemId(std::move(data.platformedItemId)),
            moneyId(std::move(data.moneyId)),
            itemId(std::move(data.itemId)),
            platform(std::move(data.platform)),
            name(std::move(data.name)),
            price(std::move(data.price)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "platformedItemId") == 0) {
                if (jsonValue.IsString())
                {
                    this->platformedItemId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "moneyId") == 0) {
                if (jsonValue.IsString())
                {
                    this->moneyId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "itemId") == 0) {
                if (jsonValue.IsString())
                {
                    this->itemId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "platform") == 0) {
                if (jsonValue.IsString())
                {
                    this->platform.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "price") == 0) {
                if (jsonValue.IsDouble())
                {
                    this->price = jsonValue.GetDouble();
                }
            }
            else if (std::strcmp(name, "createAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->createAt = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "updateAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->updateAt = jsonValue.GetInt();
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
    PlatformedItem() :
        m_pData(nullptr)
    {}

    PlatformedItem(const PlatformedItem& platformedItem) :
        Gs2Object(platformedItem),
        m_pData(platformedItem.m_pData != nullptr ? new Data(*platformedItem.m_pData) : nullptr)
    {}

    PlatformedItem(PlatformedItem&& platformedItem) :
        Gs2Object(std::move(platformedItem)),
        m_pData(platformedItem.m_pData)
    {
        platformedItem.m_pData = nullptr;
    }

    ~PlatformedItem()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    PlatformedItem& operator=(const PlatformedItem& platformedItem)
    {
        Gs2Object::operator=(platformedItem);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*platformedItem.m_pData);

        return *this;
    }

    PlatformedItem& operator=(PlatformedItem&& platformedItem)
    {
        Gs2Object::operator=(std::move(platformedItem));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = platformedItem.m_pData;
        platformedItem.m_pData = nullptr;

        return *this;
    }

    const PlatformedItem* operator->() const
    {
        return this;
    }

    PlatformedItem* operator->()
    {
        return this;
    }


    /**
     * プラットフォーム個別商品GRNを取得
     *
     * @return プラットフォーム個別商品GRN
     */
    const optional<StringHolder>& getPlatformedItemId() const
    {
        return ensureData().platformedItemId;
    }

    /**
     * プラットフォーム個別商品GRNを設定
     *
     * @param platformedItemId プラットフォーム個別商品GRN
     */
    void setPlatformedItemId(const Char* platformedItemId)
    {
        ensureData().platformedItemId.emplace(platformedItemId);
    }

    /**
     * 課金通貨GRNを取得
     *
     * @return 課金通貨GRN
     */
    const optional<StringHolder>& getMoneyId() const
    {
        return ensureData().moneyId;
    }

    /**
     * 課金通貨GRNを設定
     *
     * @param moneyId 課金通貨GRN
     */
    void setMoneyId(const Char* moneyId)
    {
        ensureData().moneyId.emplace(moneyId);
    }

    /**
     * 商品GRNを取得
     *
     * @return 商品GRN
     */
    const optional<StringHolder>& getItemId() const
    {
        return ensureData().itemId;
    }

    /**
     * 商品GRNを設定
     *
     * @param itemId 商品GRN
     */
    void setItemId(const Char* itemId)
    {
        ensureData().itemId.emplace(itemId);
    }

    /**
     * 販売プラットフォームを取得
     *
     * @return 販売プラットフォーム
     */
    const optional<StringHolder>& getPlatform() const
    {
        return ensureData().platform;
    }

    /**
     * 販売プラットフォームを設定
     *
     * @param platform 販売プラットフォーム
     */
    void setPlatform(const Char* platform)
    {
        ensureData().platform.emplace(platform);
    }

    /**
     * アプリ内課金IDを取得
     *
     * @return アプリ内課金ID
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * アプリ内課金IDを設定
     *
     * @param name アプリ内課金ID
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * 販売価格を取得
     *
     * @return 販売価格
     */
    const optional<Double>& getPrice() const
    {
        return ensureData().price;
    }

    /**
     * 販売価格を設定
     *
     * @param price 販売価格
     */
    void setPrice(Double price)
    {
        ensureData().price.emplace(price);
    }

    /**
     * 作成日時(エポック秒)を取得
     *
     * @return 作成日時(エポック秒)
     */
    const optional<Int32>& getCreateAt() const
    {
        return ensureData().createAt;
    }

    /**
     * 作成日時(エポック秒)を設定
     *
     * @param createAt 作成日時(エポック秒)
     */
    void setCreateAt(Int32 createAt)
    {
        ensureData().createAt.emplace(createAt);
    }

    /**
     * 最終更新日時(エポック秒)を取得
     *
     * @return 最終更新日時(エポック秒)
     */
    const optional<Int32>& getUpdateAt() const
    {
        return ensureData().updateAt;
    }

    /**
     * 最終更新日時(エポック秒)を設定
     *
     * @param updateAt 最終更新日時(エポック秒)
     */
    void setUpdateAt(Int32 updateAt)
    {
        ensureData().updateAt.emplace(updateAt);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_MONEY_MODEL_PLATFORMEDITEM_HPP_