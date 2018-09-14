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

#ifndef GS2_MONEY_MODEL_ITEM_HPP_
#define GS2_MONEY_MODEL_ITEM_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace money {

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
        /** 商品GRN */
        optional<StringHolder> itemId;
        /** 課金通貨GRN */
        optional<StringHolder> moneyId;
        /** 商品名 */
        optional<StringHolder> name;
        /** 付与する課金通貨の数 */
        optional<Int32> count;
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;
        /** 最終更新日時(エポック秒) */
        optional<Int32> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            itemId(data.itemId),
            moneyId(data.moneyId),
            name(data.name),
            count(data.count),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            itemId(std::move(data.itemId)),
            moneyId(std::move(data.moneyId)),
            name(std::move(data.name)),
            count(std::move(data.count)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "itemId") == 0) {
                if (jsonValue.IsString())
                {
                    this->itemId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "moneyId") == 0) {
                if (jsonValue.IsString())
                {
                    this->moneyId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "count") == 0) {
                if (jsonValue.IsInt())
                {
                    this->count = jsonValue.GetInt();
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
     * 付与する課金通貨の数を取得
     *
     * @return 付与する課金通貨の数
     */
    const optional<Int32>& getCount() const
    {
        return ensureData().count;
    }

    /**
     * 付与する課金通貨の数を設定
     *
     * @param count 付与する課金通貨の数
     */
    void setCount(Int32 count)
    {
        ensureData().count.emplace(count);
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

#endif //GS2_MONEY_MODEL_ITEM_HPP_