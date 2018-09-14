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

#ifndef GS2_CONSUMABLEITEM_MODEL_INVENTORY_HPP_
#define GS2_CONSUMABLEITEM_MODEL_INVENTORY_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace consumableItem {

/**
 * 所持品
 *
 * @author Game Server Services, Inc.
 *
 */
class Inventory : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 所持品ID */
        optional<StringHolder> inventoryId;
        /** ユーザID */
        optional<StringHolder> userId;
        /** 消費型アイテム名 */
        optional<StringHolder> itemName;
        /** 所持数量 */
        optional<Int32> count;
        /** 最大所持可能数量 */
        optional<Int32> max;
        /** 有効期限(エポック秒) */
        optional<Int32> expireAt;
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;
        /** 最終更新日時(エポック秒) */
        optional<Int32> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            inventoryId(data.inventoryId),
            userId(data.userId),
            itemName(data.itemName),
            count(data.count),
            max(data.max),
            expireAt(data.expireAt),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            inventoryId(std::move(data.inventoryId)),
            userId(std::move(data.userId)),
            itemName(std::move(data.itemName)),
            count(std::move(data.count)),
            max(std::move(data.max)),
            expireAt(std::move(data.expireAt)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "inventoryId") == 0) {
                if (jsonValue.IsString())
                {
                    this->inventoryId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "userId") == 0) {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "itemName") == 0) {
                if (jsonValue.IsString())
                {
                    this->itemName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "count") == 0) {
                if (jsonValue.IsInt())
                {
                    this->count = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "max") == 0) {
                if (jsonValue.IsInt())
                {
                    this->max = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "expireAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->expireAt = jsonValue.GetInt();
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
    Inventory() :
        m_pData(nullptr)
    {}

    Inventory(const Inventory& inventory) :
        Gs2Object(inventory),
        m_pData(inventory.m_pData != nullptr ? new Data(*inventory.m_pData) : nullptr)
    {}

    Inventory(Inventory&& inventory) :
        Gs2Object(std::move(inventory)),
        m_pData(inventory.m_pData)
    {
        inventory.m_pData = nullptr;
    }

    ~Inventory()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Inventory& operator=(const Inventory& inventory)
    {
        Gs2Object::operator=(inventory);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*inventory.m_pData);

        return *this;
    }

    Inventory& operator=(Inventory&& inventory)
    {
        Gs2Object::operator=(std::move(inventory));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = inventory.m_pData;
        inventory.m_pData = nullptr;

        return *this;
    }

    const Inventory* operator->() const
    {
        return this;
    }

    Inventory* operator->()
    {
        return this;
    }


    /**
     * 所持品IDを取得
     *
     * @return 所持品ID
     */
    const optional<StringHolder>& getInventoryId() const
    {
        return ensureData().inventoryId;
    }

    /**
     * 所持品IDを設定
     *
     * @param inventoryId 所持品ID
     */
    void setInventoryId(const Char* inventoryId)
    {
        ensureData().inventoryId.emplace(inventoryId);
    }

    /**
     * ユーザIDを取得
     *
     * @return ユーザID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザIDを設定
     *
     * @param userId ユーザID
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * 消費型アイテム名を取得
     *
     * @return 消費型アイテム名
     */
    const optional<StringHolder>& getItemName() const
    {
        return ensureData().itemName;
    }

    /**
     * 消費型アイテム名を設定
     *
     * @param itemName 消費型アイテム名
     */
    void setItemName(const Char* itemName)
    {
        ensureData().itemName.emplace(itemName);
    }

    /**
     * 所持数量を取得
     *
     * @return 所持数量
     */
    const optional<Int32>& getCount() const
    {
        return ensureData().count;
    }

    /**
     * 所持数量を設定
     *
     * @param count 所持数量
     */
    void setCount(Int32 count)
    {
        ensureData().count.emplace(count);
    }

    /**
     * 最大所持可能数量を取得
     *
     * @return 最大所持可能数量
     */
    const optional<Int32>& getMax() const
    {
        return ensureData().max;
    }

    /**
     * 最大所持可能数量を設定
     *
     * @param max 最大所持可能数量
     */
    void setMax(Int32 max)
    {
        ensureData().max.emplace(max);
    }

    /**
     * 有効期限(エポック秒)を取得
     *
     * @return 有効期限(エポック秒)
     */
    const optional<Int32>& getExpireAt() const
    {
        return ensureData().expireAt;
    }

    /**
     * 有効期限(エポック秒)を設定
     *
     * @param expireAt 有効期限(エポック秒)
     */
    void setExpireAt(Int32 expireAt)
    {
        ensureData().expireAt.emplace(expireAt);
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

#endif //GS2_CONSUMABLEITEM_MODEL_INVENTORY_HPP_