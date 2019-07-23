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

#ifndef GS2_INVENTORY_MODEL_INVENTORY_HPP_
#define GS2_INVENTORY_MODEL_INVENTORY_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace inventory {

/**
 * インベントリ
 *
 * @author Game Server Services, Inc.
 *
 */
class Inventory : public Gs2Object
{
    friend bool operator!=(const Inventory& lhs, const Inventory& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** インベントリ */
        optional<StringHolder> inventoryId;
        /** インベントリモデル名 */
        optional<StringHolder> inventoryName;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** 現在のインベントリのキャパシティ使用量 */
        optional<Int32> currentInventoryCapacityUsage;
        /** 現在のインベントリの最大キャパシティ */
        optional<Int32> currentInventoryMaxCapacity;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            inventoryId(data.inventoryId),
            inventoryName(data.inventoryName),
            userId(data.userId),
            currentInventoryCapacityUsage(data.currentInventoryCapacityUsage),
            currentInventoryMaxCapacity(data.currentInventoryMaxCapacity),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            inventoryId(std::move(data.inventoryId)),
            inventoryName(std::move(data.inventoryName)),
            userId(std::move(data.userId)),
            currentInventoryCapacityUsage(std::move(data.currentInventoryCapacityUsage)),
            currentInventoryMaxCapacity(std::move(data.currentInventoryMaxCapacity)),
            createdAt(std::move(data.createdAt)),
            updatedAt(std::move(data.updatedAt))
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
            else if (std::strcmp(name, "inventoryName") == 0) {
                if (jsonValue.IsString())
                {
                    this->inventoryName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "userId") == 0) {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "currentInventoryCapacityUsage") == 0) {
                if (jsonValue.IsInt())
                {
                    this->currentInventoryCapacityUsage = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "currentInventoryMaxCapacity") == 0) {
                if (jsonValue.IsInt())
                {
                    this->currentInventoryMaxCapacity = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "createdAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "updatedAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
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
     * インベントリを取得
     *
     * @return インベントリ
     */
    const optional<StringHolder>& getInventoryId() const
    {
        return ensureData().inventoryId;
    }

    /**
     * インベントリを設定
     *
     * @param inventoryId インベントリ
     */
    void setInventoryId(const Char* inventoryId)
    {
        ensureData().inventoryId.emplace(inventoryId);
    }

    /**
     * インベントリを設定
     *
     * @param inventoryId インベントリ
     */
    Inventory& withInventoryId(const Char* inventoryId)
    {
        setInventoryId(inventoryId);
        return *this;
    }

    /**
     * インベントリモデル名を取得
     *
     * @return インベントリモデル名
     */
    const optional<StringHolder>& getInventoryName() const
    {
        return ensureData().inventoryName;
    }

    /**
     * インベントリモデル名を設定
     *
     * @param inventoryName インベントリモデル名
     */
    void setInventoryName(const Char* inventoryName)
    {
        ensureData().inventoryName.emplace(inventoryName);
    }

    /**
     * インベントリモデル名を設定
     *
     * @param inventoryName インベントリモデル名
     */
    Inventory& withInventoryName(const Char* inventoryName)
    {
        setInventoryName(inventoryName);
        return *this;
    }

    /**
     * ユーザーIDを取得
     *
     * @return ユーザーID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    Inventory& withUserId(const Char* userId)
    {
        setUserId(userId);
        return *this;
    }

    /**
     * 現在のインベントリのキャパシティ使用量を取得
     *
     * @return 現在のインベントリのキャパシティ使用量
     */
    const optional<Int32>& getCurrentInventoryCapacityUsage() const
    {
        return ensureData().currentInventoryCapacityUsage;
    }

    /**
     * 現在のインベントリのキャパシティ使用量を設定
     *
     * @param currentInventoryCapacityUsage 現在のインベントリのキャパシティ使用量
     */
    void setCurrentInventoryCapacityUsage(Int32 currentInventoryCapacityUsage)
    {
        ensureData().currentInventoryCapacityUsage.emplace(currentInventoryCapacityUsage);
    }

    /**
     * 現在のインベントリのキャパシティ使用量を設定
     *
     * @param currentInventoryCapacityUsage 現在のインベントリのキャパシティ使用量
     */
    Inventory& withCurrentInventoryCapacityUsage(Int32 currentInventoryCapacityUsage)
    {
        setCurrentInventoryCapacityUsage(currentInventoryCapacityUsage);
        return *this;
    }

    /**
     * 現在のインベントリの最大キャパシティを取得
     *
     * @return 現在のインベントリの最大キャパシティ
     */
    const optional<Int32>& getCurrentInventoryMaxCapacity() const
    {
        return ensureData().currentInventoryMaxCapacity;
    }

    /**
     * 現在のインベントリの最大キャパシティを設定
     *
     * @param currentInventoryMaxCapacity 現在のインベントリの最大キャパシティ
     */
    void setCurrentInventoryMaxCapacity(Int32 currentInventoryMaxCapacity)
    {
        ensureData().currentInventoryMaxCapacity.emplace(currentInventoryMaxCapacity);
    }

    /**
     * 現在のインベントリの最大キャパシティを設定
     *
     * @param currentInventoryMaxCapacity 現在のインベントリの最大キャパシティ
     */
    Inventory& withCurrentInventoryMaxCapacity(Int32 currentInventoryMaxCapacity)
    {
        setCurrentInventoryMaxCapacity(currentInventoryMaxCapacity);
        return *this;
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getCreatedAt() const
    {
        return ensureData().createdAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    void setCreatedAt(Int64 createdAt)
    {
        ensureData().createdAt.emplace(createdAt);
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    Inventory& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }

    /**
     * 最終更新日時を取得
     *
     * @return 最終更新日時
     */
    const optional<Int64>& getUpdatedAt() const
    {
        return ensureData().updatedAt;
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    void setUpdatedAt(Int64 updatedAt)
    {
        ensureData().updatedAt.emplace(updatedAt);
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    Inventory& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const Inventory& lhs, const Inventory& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->inventoryId != lhr.m_pData->inventoryId)
        {
            return true;
        }
        if (lhs.m_pData->inventoryName != lhr.m_pData->inventoryName)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->currentInventoryCapacityUsage != lhr.m_pData->currentInventoryCapacityUsage)
        {
            return true;
        }
        if (lhs.m_pData->currentInventoryMaxCapacity != lhr.m_pData->currentInventoryMaxCapacity)
        {
            return true;
        }
        if (lhs.m_pData->createdAt != lhr.m_pData->createdAt)
        {
            return true;
        }
        if (lhs.m_pData->updatedAt != lhr.m_pData->updatedAt)
        {
            return true;
        }
    }
    return false;
}

bool operator==(const Inventory& lhs, const Inventory& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_INVENTORY_MODEL_INVENTORY_HPP_