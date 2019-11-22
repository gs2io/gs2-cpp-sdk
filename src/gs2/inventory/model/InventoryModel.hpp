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
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "ItemModel.hpp"
#include <memory>

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
        /** インベントリモデルマスター */
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
        Data(const Data& data);
        Data(Data&& data) = default;
        ~Data() GS2_OVERRIDE = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        void set(const Char name_[], const detail::json::JsonConstValue& jsonValue) GS2_OVERRIDE;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    InventoryModel() = default;
    InventoryModel(const InventoryModel& inventoryModel) = default;
    InventoryModel(InventoryModel&& inventoryModel) = default;
    ~InventoryModel() = default;

    InventoryModel& operator=(const InventoryModel& inventoryModel) = default;
    InventoryModel& operator=(InventoryModel&& inventoryModel) = default;

    InventoryModel deepCopy() const;

    const InventoryModel* operator->() const
    {
        return this;
    }

    InventoryModel* operator->()
    {
        return this;
    }
    /**
     * インベントリモデルマスターを取得
     *
     * @return インベントリモデルマスター
     */
    const optional<StringHolder>& getInventoryModelId() const
    {
        return ensureData().inventoryModelId;
    }

    /**
     * インベントリモデルマスターを設定
     *
     * @param inventoryModelId インベントリモデルマスター
     */
    void setInventoryModelId(StringHolder inventoryModelId)
    {
        ensureData().inventoryModelId.emplace(std::move(inventoryModelId));
    }

    /**
     * インベントリモデルマスターを設定
     *
     * @param inventoryModelId インベントリモデルマスター
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

bool operator!=(const InventoryModel& lhs, const InventoryModel& lhr);

inline bool operator==(const InventoryModel& lhs, const InventoryModel& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_INVENTORY_MODEL_INVENTORYMODEL_HPP_