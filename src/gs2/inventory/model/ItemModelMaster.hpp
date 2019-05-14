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

namespace gs2 { namespace  {

/**
 * アイテムマスター
 *
 * @author Game Server Services, Inc.
 *
 */
class ItemModelMaster : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** アイテムマスター のGRN */
        optional<StringHolder> itemModelId;
        /** インベントリの種類名 */
        optional<StringHolder> inventoryModelName;
        /** アイテムモデルの種類名 */
        optional<StringHolder> name;
        /** アイテムマスターの説明 */
        optional<StringHolder> description;
        /** アイテムモデルの種類のメタデータ */
        optional<StringHolder> metadata;
        /** 所有可能な最大数量 */
        
        optional<Int64> maxCount;
        /** 表示順番 */
        
        optional<Int32> sortValue;
        /** 作成日時 */
        
        optional<Int64> createAt;
        /** 最終更新日時 */
        
        optional<Int64> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            itemModelId(data.itemModelId),
            inventoryModelName(data.inventoryModelName),
            name(data.name),
            description(data.description),
            metadata(data.metadata),
            maxCount(data.maxCount),
            sortValue(data.sortValue),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            itemModelId(std::move(data.itemModelId)),
            inventoryModelName(std::move(data.inventoryModelName)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            metadata(std::move(data.metadata)),
            maxCount(std::move(data.maxCount)),
            sortValue(std::move(data.sortValue)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
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
            else if (std::strcmp(name, "inventoryModelName") == 0) {
                if (jsonValue.IsString())
                {
                    this->inventoryModelName.emplace(jsonValue.GetString());
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
     * アイテムマスター のGRNを取得
     *
     * @return アイテムマスター のGRN
     */
    const optional<StringHolder>& getItemModelId() const
    {
        return ensureData().itemModelId;
    }

    /**
     * アイテムマスター のGRNを設定
     *
     * @param itemModelId アイテムマスター のGRN
     */
    void setItemModelId(const Char* itemModelId)
    {
        ensureData().itemModelId.emplace(itemModelId);
    }

    /**
     * インベントリの種類名を取得
     *
     * @return インベントリの種類名
     */
    const optional<StringHolder>& getInventoryModelName() const
    {
        return ensureData().inventoryModelName;
    }

    /**
     * インベントリの種類名を設定
     *
     * @param inventoryModelName インベントリの種類名
     */
    void setInventoryModelName(const Char* inventoryModelName)
    {
        ensureData().inventoryModelName.emplace(inventoryModelName);
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
     * アイテムマスターの説明を取得
     *
     * @return アイテムマスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * アイテムマスターの説明を設定
     *
     * @param description アイテムマスターの説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
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

#endif //GS2_INVENTORY_MODEL_ITEMMODELMASTER_HPP_