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
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
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

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            inventoryId(data.inventoryId),
            inventoryName(data.inventoryName),
            userId(data.userId),
            currentInventoryCapacityUsage(data.currentInventoryCapacityUsage),
            currentInventoryMaxCapacity(data.currentInventoryMaxCapacity),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "inventoryId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->inventoryId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "inventoryName") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->inventoryName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "userId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "currentInventoryCapacityUsage") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->currentInventoryCapacityUsage = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "currentInventoryMaxCapacity") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->currentInventoryMaxCapacity = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "createdAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "updatedAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Inventory() = default;
    Inventory(const Inventory& inventory) = default;
    Inventory(Inventory&& inventory) = default;
    ~Inventory() = default;

    Inventory& operator=(const Inventory& inventory) = default;
    Inventory& operator=(Inventory&& inventory) = default;

    Inventory deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Inventory);
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
    void setInventoryId(StringHolder inventoryId)
    {
        ensureData().inventoryId.emplace(std::move(inventoryId));
    }

    /**
     * インベントリを設定
     *
     * @param inventoryId インベントリ
     */
    Inventory& withInventoryId(StringHolder inventoryId)
    {
        setInventoryId(std::move(inventoryId));
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
    void setInventoryName(StringHolder inventoryName)
    {
        ensureData().inventoryName.emplace(std::move(inventoryName));
    }

    /**
     * インベントリモデル名を設定
     *
     * @param inventoryName インベントリモデル名
     */
    Inventory& withInventoryName(StringHolder inventoryName)
    {
        setInventoryName(std::move(inventoryName));
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
    void setUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    Inventory& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
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

inline bool operator!=(const Inventory& lhs, const Inventory& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
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

inline bool operator==(const Inventory& lhs, const Inventory& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_INVENTORY_MODEL_INVENTORY_HPP_