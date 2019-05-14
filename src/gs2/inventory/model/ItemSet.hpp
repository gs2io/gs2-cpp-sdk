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

namespace gs2 { namespace  {

/**
 * アイテムセット
 *
 * @author Game Server Services, Inc.
 *
 */
class ItemSet : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** アイテムセット のGRN */
        optional<StringHolder> itemSetId;
        /** インベントリモデル名 */
        optional<StringHolder> inventoryModelName;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** アイテムモデルの種類名 */
        optional<StringHolder> itemModelName;
        /** 所持数量 */
        
        optional<Int64> count;
        /** 表示順番 */
        
        optional<Int32> sortValue;
        /** 有効期限 */
        
        optional<Int64> expiresAt;
        /** 作成日時 */
        
        optional<Int64> createAt;
        /** 最終更新日時 */
        
        optional<Int64> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            itemSetId(data.itemSetId),
            inventoryModelName(data.inventoryModelName),
            userId(data.userId),
            itemModelName(data.itemModelName),
            count(data.count),
            sortValue(data.sortValue),
            expiresAt(data.expiresAt),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            itemSetId(std::move(data.itemSetId)),
            inventoryModelName(std::move(data.inventoryModelName)),
            userId(std::move(data.userId)),
            itemModelName(std::move(data.itemModelName)),
            count(std::move(data.count)),
            sortValue(std::move(data.sortValue)),
            expiresAt(std::move(data.expiresAt)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
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
            else if (std::strcmp(name, "itemModelName") == 0) {
                if (jsonValue.IsString())
                {
                    this->itemModelName.emplace(jsonValue.GetString());
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
     * アイテムセット のGRNを取得
     *
     * @return アイテムセット のGRN
     */
    const optional<StringHolder>& getItemSetId() const
    {
        return ensureData().itemSetId;
    }

    /**
     * アイテムセット のGRNを設定
     *
     * @param itemSetId アイテムセット のGRN
     */
    void setItemSetId(const Char* itemSetId)
    {
        ensureData().itemSetId.emplace(itemSetId);
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
     * アイテムモデルの種類名を取得
     *
     * @return アイテムモデルの種類名
     */
    const optional<StringHolder>& getItemModelName() const
    {
        return ensureData().itemModelName;
    }

    /**
     * アイテムモデルの種類名を設定
     *
     * @param itemModelName アイテムモデルの種類名
     */
    void setItemModelName(const Char* itemModelName)
    {
        ensureData().itemModelName.emplace(itemModelName);
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

#endif //GS2_INVENTORY_MODEL_ITEMSET_HPP_