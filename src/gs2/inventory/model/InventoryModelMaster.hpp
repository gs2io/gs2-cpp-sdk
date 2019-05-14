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

#ifndef GS2_INVENTORY_MODEL_INVENTORYMODELMASTER_HPP_
#define GS2_INVENTORY_MODEL_INVENTORYMODELMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace  {

/**
 * インベントリマスター
 *
 * @author Game Server Services, Inc.
 *
 */
class InventoryModelMaster : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** インベントリマスター のGRN */
        optional<StringHolder> inventoryModelId;
        /** インベントリの種類名 */
        optional<StringHolder> name;
        /** インベントリの種類のメタデータ */
        optional<StringHolder> metadata;
        /** インベントリマスターの説明 */
        optional<StringHolder> description;
        /** インベントリの初期サイズ */
        
        optional<Int32> initialCapacity;
        /** インベントリの最大サイズ */
        
        optional<Int32> maxCapacity;
        /** 作成日時 */
        
        optional<Int64> createAt;
        /** 最終更新日時 */
        
        optional<Int64> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            inventoryModelId(data.inventoryModelId),
            name(data.name),
            metadata(data.metadata),
            description(data.description),
            initialCapacity(data.initialCapacity),
            maxCapacity(data.maxCapacity),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            inventoryModelId(std::move(data.inventoryModelId)),
            name(std::move(data.name)),
            metadata(std::move(data.metadata)),
            description(std::move(data.description)),
            initialCapacity(std::move(data.initialCapacity)),
            maxCapacity(std::move(data.maxCapacity)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "inventoryModelId") == 0) {
                if (jsonValue.IsString())
                {
                    this->inventoryModelId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "metadata") == 0) {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "description") == 0) {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "initialCapacity") == 0) {
                if (jsonValue.IsInt())
                {
                    this->initialCapacity = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "maxCapacity") == 0) {
                if (jsonValue.IsInt())
                {
                    this->maxCapacity = jsonValue.GetInt();
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
    InventoryModelMaster() :
        m_pData(nullptr)
    {}

    InventoryModelMaster(const InventoryModelMaster& inventoryModelMaster) :
        Gs2Object(inventoryModelMaster),
        m_pData(inventoryModelMaster.m_pData != nullptr ? new Data(*inventoryModelMaster.m_pData) : nullptr)
    {}

    InventoryModelMaster(InventoryModelMaster&& inventoryModelMaster) :
        Gs2Object(std::move(inventoryModelMaster)),
        m_pData(inventoryModelMaster.m_pData)
    {
        inventoryModelMaster.m_pData = nullptr;
    }

    ~InventoryModelMaster()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    InventoryModelMaster& operator=(const InventoryModelMaster& inventoryModelMaster)
    {
        Gs2Object::operator=(inventoryModelMaster);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*inventoryModelMaster.m_pData);

        return *this;
    }

    InventoryModelMaster& operator=(InventoryModelMaster&& inventoryModelMaster)
    {
        Gs2Object::operator=(std::move(inventoryModelMaster));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = inventoryModelMaster.m_pData;
        inventoryModelMaster.m_pData = nullptr;

        return *this;
    }

    const InventoryModelMaster* operator->() const
    {
        return this;
    }

    InventoryModelMaster* operator->()
    {
        return this;
    }
    /**
     * インベントリマスター のGRNを取得
     *
     * @return インベントリマスター のGRN
     */
    const optional<StringHolder>& getInventoryModelId() const
    {
        return ensureData().inventoryModelId;
    }

    /**
     * インベントリマスター のGRNを設定
     *
     * @param inventoryModelId インベントリマスター のGRN
     */
    void setInventoryModelId(const Char* inventoryModelId)
    {
        ensureData().inventoryModelId.emplace(inventoryModelId);
    }

    /**
     * インベントリの種類名を取得
     *
     * @return インベントリの種類名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * インベントリの種類名を設定
     *
     * @param name インベントリの種類名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * インベントリの種類のメタデータを取得
     *
     * @return インベントリの種類のメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * インベントリの種類のメタデータを設定
     *
     * @param metadata インベントリの種類のメタデータ
     */
    void setMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
    }

    /**
     * インベントリマスターの説明を取得
     *
     * @return インベントリマスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * インベントリマスターの説明を設定
     *
     * @param description インベントリマスターの説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * インベントリの初期サイズを取得
     *
     * @return インベントリの初期サイズ
     */
    const optional<Int32>& getInitialCapacity() const
    {
        return ensureData().initialCapacity;
    }

    /**
     * インベントリの初期サイズを設定
     *
     * @param initialCapacity インベントリの初期サイズ
     */
    void setInitialCapacity(Int32 initialCapacity)
    {
        ensureData().initialCapacity.emplace(initialCapacity);
    }

    /**
     * インベントリの最大サイズを取得
     *
     * @return インベントリの最大サイズ
     */
    const optional<Int32>& getMaxCapacity() const
    {
        return ensureData().maxCapacity;
    }

    /**
     * インベントリの最大サイズを設定
     *
     * @param maxCapacity インベントリの最大サイズ
     */
    void setMaxCapacity(Int32 maxCapacity)
    {
        ensureData().maxCapacity.emplace(maxCapacity);
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

#endif //GS2_INVENTORY_MODEL_INVENTORYMODELMASTER_HPP_