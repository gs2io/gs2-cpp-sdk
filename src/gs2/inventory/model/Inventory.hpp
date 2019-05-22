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
private:
    class Data : public detail::json::IModel
    {
    public:
        /** インベントリ のGRN */
        optional<StringHolder> inventoryId;
        /** インベントリモデル名 */
        optional<StringHolder> inventoryModelName;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** 現在のインベントリのキャパシティ使用量 */
        optional<Int32> currentInventoryCapacityUsage;
        /** 現在のインベントリの最大キャパシティ */
        optional<Int32> currentInventoryMaxCapacity;
        /** 作成日時 */
        optional<Int64> createAt;
        /** 最終更新日時 */
        optional<Int64> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            inventoryId(data.inventoryId),
            inventoryModelName(data.inventoryModelName),
            userId(data.userId),
            currentInventoryCapacityUsage(data.currentInventoryCapacityUsage),
            currentInventoryMaxCapacity(data.currentInventoryMaxCapacity),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            inventoryId(std::move(data.inventoryId)),
            inventoryModelName(std::move(data.inventoryModelName)),
            userId(std::move(data.userId)),
            currentInventoryCapacityUsage(std::move(data.currentInventoryCapacityUsage)),
            currentInventoryMaxCapacity(std::move(data.currentInventoryMaxCapacity)),
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
            else if (std::strcmp(name, "inventoryModelName") == 0) {
                if (jsonValue.IsString())
                {
                    this->inventoryModelName.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name, "createAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "updateAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->updateAt = jsonValue.GetInt64();
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
     * インベントリ のGRNを取得
     *
     * @return インベントリ のGRN
     */
    const optional<StringHolder>& getInventoryId() const
    {
        return ensureData().inventoryId;
    }

    /**
     * インベントリ のGRNを設定
     *
     * @param inventoryId インベントリ のGRN
     */
    void setInventoryId(const Char* inventoryId)
    {
        ensureData().inventoryId.emplace(inventoryId);
    }

    /**
     * インベントリモデル名を取得
     *
     * @return インベントリモデル名
     */
    const optional<StringHolder>& getInventoryModelName() const
    {
        return ensureData().inventoryModelName;
    }

    /**
     * インベントリモデル名を設定
     *
     * @param inventoryModelName インベントリモデル名
     */
    void setInventoryModelName(const Char* inventoryModelName)
    {
        ensureData().inventoryModelName.emplace(inventoryModelName);
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
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getCreateAt() const
    {
        return ensureData().createAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createAt 作成日時
     */
    void setCreateAt(Int64 createAt)
    {
        ensureData().createAt.emplace(createAt);
    }

    /**
     * 最終更新日時を取得
     *
     * @return 最終更新日時
     */
    const optional<Int64>& getUpdateAt() const
    {
        return ensureData().updateAt;
    }

    /**
     * 最終更新日時を設定
     *
     * @param updateAt 最終更新日時
     */
    void setUpdateAt(Int64 updateAt)
    {
        ensureData().updateAt.emplace(updateAt);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_INVENTORY_MODEL_INVENTORY_HPP_