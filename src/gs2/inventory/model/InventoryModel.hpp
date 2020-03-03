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

#ifndef GS2_INVENTORY_MODEL_INVENTORYMODEL_HPP_
#define GS2_INVENTORY_MODEL_INVENTORYMODEL_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "ItemModel.hpp"
#include <memory>
#include <cstring>

namespace gs2 { namespace inventory {

/**
 * インベントリモデル
 *
 * @author Game Server Services, Inc.
 *
 */
class InventoryModel : public Gs2Object
{
    friend bool operator!=(const InventoryModel& lhs, const InventoryModel& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** インベントリモデル */
        optional<StringHolder> inventoryModelId;
        /** インベントリの種類名 */
        optional<StringHolder> name;
        /** インベントリの種類のメタデータ */
        optional<StringHolder> metadata;
        /** インベントリの初期サイズ */
        optional<Int32> initialCapacity;
        /** インベントリの最大サイズ */
        optional<Int32> maxCapacity;
        /** インベントリに格納可能なアイテムモデル一覧 */
        optional<List<ItemModel>> itemModels;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            inventoryModelId(data.inventoryModelId),
            name(data.name),
            metadata(data.metadata),
            initialCapacity(data.initialCapacity),
            maxCapacity(data.maxCapacity)
        {
            if (data.itemModels)
            {
                itemModels = data.itemModels->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "inventoryModelId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->inventoryModelId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "metadata") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "initialCapacity") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->initialCapacity = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "maxCapacity") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->maxCapacity = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "itemModels") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->itemModels.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        ItemModel item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        *this->itemModels += std::move(item);
                    }
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    InventoryModel() = default;
    InventoryModel(const InventoryModel& inventoryModel) = default;
    InventoryModel(InventoryModel&& inventoryModel) = default;
    ~InventoryModel() = default;

    InventoryModel& operator=(const InventoryModel& inventoryModel) = default;
    InventoryModel& operator=(InventoryModel&& inventoryModel) = default;

    InventoryModel deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(InventoryModel);
    }

    const InventoryModel* operator->() const
    {
        return this;
    }

    InventoryModel* operator->()
    {
        return this;
    }
    /**
     * インベントリモデルを取得
     *
     * @return インベントリモデル
     */
    const optional<StringHolder>& getInventoryModelId() const
    {
        return ensureData().inventoryModelId;
    }

    /**
     * インベントリモデルを設定
     *
     * @param inventoryModelId インベントリモデル
     */
    void setInventoryModelId(StringHolder inventoryModelId)
    {
        ensureData().inventoryModelId.emplace(std::move(inventoryModelId));
    }

    /**
     * インベントリモデルを設定
     *
     * @param inventoryModelId インベントリモデル
     */
    InventoryModel& withInventoryModelId(StringHolder inventoryModelId)
    {
        setInventoryModelId(std::move(inventoryModelId));
        return *this;
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
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * インベントリの種類名を設定
     *
     * @param name インベントリの種類名
     */
    InventoryModel& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
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
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * インベントリの種類のメタデータを設定
     *
     * @param metadata インベントリの種類のメタデータ
     */
    InventoryModel& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
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
     * インベントリの初期サイズを設定
     *
     * @param initialCapacity インベントリの初期サイズ
     */
    InventoryModel& withInitialCapacity(Int32 initialCapacity)
    {
        setInitialCapacity(initialCapacity);
        return *this;
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
     * インベントリの最大サイズを設定
     *
     * @param maxCapacity インベントリの最大サイズ
     */
    InventoryModel& withMaxCapacity(Int32 maxCapacity)
    {
        setMaxCapacity(maxCapacity);
        return *this;
    }

    /**
     * インベントリに格納可能なアイテムモデル一覧を取得
     *
     * @return インベントリに格納可能なアイテムモデル一覧
     */
    const optional<List<ItemModel>>& getItemModels() const
    {
        return ensureData().itemModels;
    }

    /**
     * インベントリに格納可能なアイテムモデル一覧を設定
     *
     * @param itemModels インベントリに格納可能なアイテムモデル一覧
     */
    void setItemModels(List<ItemModel> itemModels)
    {
        ensureData().itemModels.emplace(std::move(itemModels));
    }

    /**
     * インベントリに格納可能なアイテムモデル一覧を設定
     *
     * @param itemModels インベントリに格納可能なアイテムモデル一覧
     */
    InventoryModel& withItemModels(List<ItemModel> itemModels)
    {
        setItemModels(std::move(itemModels));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const InventoryModel& lhs, const InventoryModel& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->inventoryModelId != lhr.m_pData->inventoryModelId)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->metadata != lhr.m_pData->metadata)
        {
            return true;
        }
        if (lhs.m_pData->initialCapacity != lhr.m_pData->initialCapacity)
        {
            return true;
        }
        if (lhs.m_pData->maxCapacity != lhr.m_pData->maxCapacity)
        {
            return true;
        }
        if (lhs.m_pData->itemModels != lhr.m_pData->itemModels)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const InventoryModel& lhs, const InventoryModel& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_INVENTORY_MODEL_INVENTORYMODEL_HPP_