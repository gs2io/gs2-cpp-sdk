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

#ifndef GS2_INVENTORY_MODEL_ITEMSET_HPP_
#define GS2_INVENTORY_MODEL_ITEMSET_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace inventory {

/**
 * 有効期限ごとのアイテム所持数量
 *
 * @author Game Server Services, Inc.
 *
 */
class ItemSet : public Gs2Object
{
    friend bool operator!=(const ItemSet& lhs, const ItemSet& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 有効期限ごとのアイテム所持数量 */
        optional<StringHolder> itemSetId;
        /** インベントリの名前 */
        optional<StringHolder> inventoryName;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** アイテムマスターの名前 */
        optional<StringHolder> itemName;
        /** 所持数量 */
        optional<Int64> count;
        /** 表示順番 */
        optional<Int32> sortValue;
        /** 有効期限 */
        optional<Int64> expiresAt;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            itemSetId(data.itemSetId),
            inventoryName(data.inventoryName),
            userId(data.userId),
            itemName(data.itemName),
            count(data.count),
            sortValue(data.sortValue),
            expiresAt(data.expiresAt),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            itemSetId(std::move(data.itemSetId)),
            inventoryName(std::move(data.inventoryName)),
            userId(std::move(data.userId)),
            itemName(std::move(data.itemName)),
            count(std::move(data.count)),
            sortValue(std::move(data.sortValue)),
            expiresAt(std::move(data.expiresAt)),
            createdAt(std::move(data.createdAt)),
            updatedAt(std::move(data.updatedAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "itemSetId") == 0) {
                if (jsonValue.IsString())
                {
                    this->itemSetId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name, "itemName") == 0) {
                if (jsonValue.IsString())
                {
                    this->itemName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "count") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->count = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "sortValue") == 0) {
                if (jsonValue.IsInt())
                {
                    this->sortValue = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "expiresAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->expiresAt = jsonValue.GetInt64();
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
    ItemSet() :
        m_pData(nullptr)
    {}

    ItemSet(const ItemSet& itemSet) :
        Gs2Object(itemSet),
        m_pData(itemSet.m_pData != nullptr ? new Data(*itemSet.m_pData) : nullptr)
    {}

    ItemSet(ItemSet&& itemSet) :
        Gs2Object(std::move(itemSet)),
        m_pData(itemSet.m_pData)
    {
        itemSet.m_pData = nullptr;
    }

    ~ItemSet()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    ItemSet& operator=(const ItemSet& itemSet)
    {
        Gs2Object::operator=(itemSet);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*itemSet.m_pData);

        return *this;
    }

    ItemSet& operator=(ItemSet&& itemSet)
    {
        Gs2Object::operator=(std::move(itemSet));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = itemSet.m_pData;
        itemSet.m_pData = nullptr;

        return *this;
    }

    const ItemSet* operator->() const
    {
        return this;
    }

    ItemSet* operator->()
    {
        return this;
    }
    /**
     * 有効期限ごとのアイテム所持数量を取得
     *
     * @return 有効期限ごとのアイテム所持数量
     */
    const optional<StringHolder>& getItemSetId() const
    {
        return ensureData().itemSetId;
    }

    /**
     * 有効期限ごとのアイテム所持数量を設定
     *
     * @param itemSetId 有効期限ごとのアイテム所持数量
     */
    void setItemSetId(const Char* itemSetId)
    {
        ensureData().itemSetId.emplace(itemSetId);
    }

    /**
     * 有効期限ごとのアイテム所持数量を設定
     *
     * @param itemSetId 有効期限ごとのアイテム所持数量
     */
    ItemSet& withItemSetId(const Char* itemSetId)
    {
        setItemSetId(itemSetId);
        return *this;
    }

    /**
     * インベントリの名前を取得
     *
     * @return インベントリの名前
     */
    const optional<StringHolder>& getInventoryName() const
    {
        return ensureData().inventoryName;
    }

    /**
     * インベントリの名前を設定
     *
     * @param inventoryName インベントリの名前
     */
    void setInventoryName(const Char* inventoryName)
    {
        ensureData().inventoryName.emplace(inventoryName);
    }

    /**
     * インベントリの名前を設定
     *
     * @param inventoryName インベントリの名前
     */
    ItemSet& withInventoryName(const Char* inventoryName)
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
    ItemSet& withUserId(const Char* userId)
    {
        setUserId(userId);
        return *this;
    }

    /**
     * アイテムマスターの名前を取得
     *
     * @return アイテムマスターの名前
     */
    const optional<StringHolder>& getItemName() const
    {
        return ensureData().itemName;
    }

    /**
     * アイテムマスターの名前を設定
     *
     * @param itemName アイテムマスターの名前
     */
    void setItemName(const Char* itemName)
    {
        ensureData().itemName.emplace(itemName);
    }

    /**
     * アイテムマスターの名前を設定
     *
     * @param itemName アイテムマスターの名前
     */
    ItemSet& withItemName(const Char* itemName)
    {
        setItemName(itemName);
        return *this;
    }

    /**
     * 所持数量を取得
     *
     * @return 所持数量
     */
    const optional<Int64>& getCount() const
    {
        return ensureData().count;
    }

    /**
     * 所持数量を設定
     *
     * @param count 所持数量
     */
    void setCount(Int64 count)
    {
        ensureData().count.emplace(count);
    }

    /**
     * 所持数量を設定
     *
     * @param count 所持数量
     */
    ItemSet& withCount(Int64 count)
    {
        setCount(count);
        return *this;
    }

    /**
     * 表示順番を取得
     *
     * @return 表示順番
     */
    const optional<Int32>& getSortValue() const
    {
        return ensureData().sortValue;
    }

    /**
     * 表示順番を設定
     *
     * @param sortValue 表示順番
     */
    void setSortValue(Int32 sortValue)
    {
        ensureData().sortValue.emplace(sortValue);
    }

    /**
     * 表示順番を設定
     *
     * @param sortValue 表示順番
     */
    ItemSet& withSortValue(Int32 sortValue)
    {
        setSortValue(sortValue);
        return *this;
    }

    /**
     * 有効期限を取得
     *
     * @return 有効期限
     */
    const optional<Int64>& getExpiresAt() const
    {
        return ensureData().expiresAt;
    }

    /**
     * 有効期限を設定
     *
     * @param expiresAt 有効期限
     */
    void setExpiresAt(Int64 expiresAt)
    {
        ensureData().expiresAt.emplace(expiresAt);
    }

    /**
     * 有効期限を設定
     *
     * @param expiresAt 有効期限
     */
    ItemSet& withExpiresAt(Int64 expiresAt)
    {
        setExpiresAt(expiresAt);
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
    ItemSet& withCreatedAt(Int64 createdAt)
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
    ItemSet& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const ItemSet& lhs, const ItemSet& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->itemSetId != lhr.m_pData->itemSetId)
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
        if (lhs.m_pData->itemName != lhr.m_pData->itemName)
        {
            return true;
        }
        if (lhs.m_pData->count != lhr.m_pData->count)
        {
            return true;
        }
        if (lhs.m_pData->sortValue != lhr.m_pData->sortValue)
        {
            return true;
        }
        if (lhs.m_pData->expiresAt != lhr.m_pData->expiresAt)
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

inline bool operator==(const ItemSet& lhs, const ItemSet& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_INVENTORY_MODEL_ITEMSET_HPP_