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

#ifndef GS2_INVENTORY_MODEL_ITEMMODELMASTER_HPP_
#define GS2_INVENTORY_MODEL_ITEMMODELMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace inventory {

/**
 * アイテムモデルマスター
 *
 * @author Game Server Services, Inc.
 *
 */
class ItemModelMaster : public Gs2Object
{
    friend bool operator!=(const ItemModelMaster& lhs, const ItemModelMaster& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** アイテムモデルマスター */
        optional<StringHolder> itemModelId;
        /** アイテムの種類名 */
        optional<StringHolder> inventoryName;
        /** アイテムモデルの種類名 */
        optional<StringHolder> name;
        /** アイテムモデルマスターの説明 */
        optional<StringHolder> description;
        /** アイテムモデルの種類のメタデータ */
        optional<StringHolder> metadata;
        /** 所有可能な最大数量 */
        optional<Int64> maxCount;
        /** 表示順番 */
        optional<Int32> sortValue;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            itemModelId(data.itemModelId),
            inventoryName(data.inventoryName),
            name(data.name),
            description(data.description),
            metadata(data.metadata),
            maxCount(data.maxCount),
            sortValue(data.sortValue),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            itemModelId(std::move(data.itemModelId)),
            inventoryName(std::move(data.inventoryName)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            metadata(std::move(data.metadata)),
            maxCount(std::move(data.maxCount)),
            sortValue(std::move(data.sortValue)),
            createdAt(std::move(data.createdAt)),
            updatedAt(std::move(data.updatedAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "itemModelId") == 0) {
                if (jsonValue.IsString())
                {
                    this->itemModelId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "inventoryName") == 0) {
                if (jsonValue.IsString())
                {
                    this->inventoryName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "description") == 0) {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "metadata") == 0) {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "maxCount") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->maxCount = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "sortValue") == 0) {
                if (jsonValue.IsInt())
                {
                    this->sortValue = jsonValue.GetInt();
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
    ItemModelMaster() :
        m_pData(nullptr)
    {}

    ItemModelMaster(const ItemModelMaster& itemModelMaster) :
        Gs2Object(itemModelMaster),
        m_pData(itemModelMaster.m_pData != nullptr ? new Data(*itemModelMaster.m_pData) : nullptr)
    {}

    ItemModelMaster(ItemModelMaster&& itemModelMaster) :
        Gs2Object(std::move(itemModelMaster)),
        m_pData(itemModelMaster.m_pData)
    {
        itemModelMaster.m_pData = nullptr;
    }

    ~ItemModelMaster()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    ItemModelMaster& operator=(const ItemModelMaster& itemModelMaster)
    {
        Gs2Object::operator=(itemModelMaster);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*itemModelMaster.m_pData);

        return *this;
    }

    ItemModelMaster& operator=(ItemModelMaster&& itemModelMaster)
    {
        Gs2Object::operator=(std::move(itemModelMaster));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = itemModelMaster.m_pData;
        itemModelMaster.m_pData = nullptr;

        return *this;
    }

    const ItemModelMaster* operator->() const
    {
        return this;
    }

    ItemModelMaster* operator->()
    {
        return this;
    }
    /**
     * アイテムモデルマスターを取得
     *
     * @return アイテムモデルマスター
     */
    const optional<StringHolder>& getItemModelId() const
    {
        return ensureData().itemModelId;
    }

    /**
     * アイテムモデルマスターを設定
     *
     * @param itemModelId アイテムモデルマスター
     */
    void setItemModelId(const Char* itemModelId)
    {
        ensureData().itemModelId.emplace(itemModelId);
    }

    /**
     * アイテムモデルマスターを設定
     *
     * @param itemModelId アイテムモデルマスター
     */
    ItemModelMaster& withItemModelId(const Char* itemModelId)
    {
        setItemModelId(itemModelId);
        return *this;
    }

    /**
     * アイテムの種類名を取得
     *
     * @return アイテムの種類名
     */
    const optional<StringHolder>& getInventoryName() const
    {
        return ensureData().inventoryName;
    }

    /**
     * アイテムの種類名を設定
     *
     * @param inventoryName アイテムの種類名
     */
    void setInventoryName(const Char* inventoryName)
    {
        ensureData().inventoryName.emplace(inventoryName);
    }

    /**
     * アイテムの種類名を設定
     *
     * @param inventoryName アイテムの種類名
     */
    ItemModelMaster& withInventoryName(const Char* inventoryName)
    {
        setInventoryName(inventoryName);
        return *this;
    }

    /**
     * アイテムモデルの種類名を取得
     *
     * @return アイテムモデルの種類名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * アイテムモデルの種類名を設定
     *
     * @param name アイテムモデルの種類名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * アイテムモデルの種類名を設定
     *
     * @param name アイテムモデルの種類名
     */
    ItemModelMaster& withName(const Char* name)
    {
        setName(name);
        return *this;
    }

    /**
     * アイテムモデルマスターの説明を取得
     *
     * @return アイテムモデルマスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * アイテムモデルマスターの説明を設定
     *
     * @param description アイテムモデルマスターの説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * アイテムモデルマスターの説明を設定
     *
     * @param description アイテムモデルマスターの説明
     */
    ItemModelMaster& withDescription(const Char* description)
    {
        setDescription(description);
        return *this;
    }

    /**
     * アイテムモデルの種類のメタデータを取得
     *
     * @return アイテムモデルの種類のメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * アイテムモデルの種類のメタデータを設定
     *
     * @param metadata アイテムモデルの種類のメタデータ
     */
    void setMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
    }

    /**
     * アイテムモデルの種類のメタデータを設定
     *
     * @param metadata アイテムモデルの種類のメタデータ
     */
    ItemModelMaster& withMetadata(const Char* metadata)
    {
        setMetadata(metadata);
        return *this;
    }

    /**
     * 所有可能な最大数量を取得
     *
     * @return 所有可能な最大数量
     */
    const optional<Int64>& getMaxCount() const
    {
        return ensureData().maxCount;
    }

    /**
     * 所有可能な最大数量を設定
     *
     * @param maxCount 所有可能な最大数量
     */
    void setMaxCount(Int64 maxCount)
    {
        ensureData().maxCount.emplace(maxCount);
    }

    /**
     * 所有可能な最大数量を設定
     *
     * @param maxCount 所有可能な最大数量
     */
    ItemModelMaster& withMaxCount(Int64 maxCount)
    {
        setMaxCount(maxCount);
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
    ItemModelMaster& withSortValue(Int32 sortValue)
    {
        setSortValue(sortValue);
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
    ItemModelMaster& withCreatedAt(Int64 createdAt)
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
    ItemModelMaster& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const ItemModelMaster& lhs, const ItemModelMaster& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->itemModelId != lhr.m_pData->itemModelId)
        {
            return true;
        }
        if (lhs.m_pData->inventoryName != lhr.m_pData->inventoryName)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->description != lhr.m_pData->description)
        {
            return true;
        }
        if (lhs.m_pData->metadata != lhr.m_pData->metadata)
        {
            return true;
        }
        if (lhs.m_pData->maxCount != lhr.m_pData->maxCount)
        {
            return true;
        }
        if (lhs.m_pData->sortValue != lhr.m_pData->sortValue)
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

bool operator==(const ItemModelMaster& lhs, const ItemModelMaster& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_INVENTORY_MODEL_ITEMMODELMASTER_HPP_