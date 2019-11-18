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

#ifndef GS2_INVENTORY_MODEL_ITEMMODEL_HPP_
#define GS2_INVENTORY_MODEL_ITEMMODEL_HPP_

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
 * アイテムモデル
 *
 * @author Game Server Services, Inc.
 *
 */
class ItemModel : public Gs2Object
{
    friend bool operator!=(const ItemModel& lhs, const ItemModel& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** アイテムモデルマスター */
        optional<StringHolder> itemModelId;
        /** アイテムモデルの種類名 */
        optional<StringHolder> name;
        /** アイテムモデルの種類のメタデータ */
        optional<StringHolder> metadata;
        /** スタック可能な最大数量 */
        optional<Int64> stackingLimit;
        /** スタック可能な最大数量を超えた時複数枠にアイテムを保管することを許すか */
        optional<Bool> allowMultipleStacks;
        /** 表示順番 */
        optional<Int32> sortValue;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            itemModelId(data.itemModelId),
            name(data.name),
            metadata(data.metadata),
            stackingLimit(data.stackingLimit),
            allowMultipleStacks(data.allowMultipleStacks),
            sortValue(data.sortValue)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "itemModelId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->itemModelId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name_, "stackingLimit") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->stackingLimit = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "allowMultipleStacks") == 0)
            {
                if (jsonValue.IsBool())
                {
                    this->allowMultipleStacks = jsonValue.GetBool();
                }
            }
            else if (std::strcmp(name_, "sortValue") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->sortValue = jsonValue.GetInt();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    ItemModel() = default;
    ItemModel(const ItemModel& itemModel) = default;
    ItemModel(ItemModel&& itemModel) = default;
    ~ItemModel() = default;

    ItemModel& operator=(const ItemModel& itemModel) = default;
    ItemModel& operator=(ItemModel&& itemModel) = default;

    ItemModel deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(ItemModel);
    }

    const ItemModel* operator->() const
    {
        return this;
    }

    ItemModel* operator->()
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
    void setItemModelId(StringHolder itemModelId)
    {
        ensureData().itemModelId.emplace(std::move(itemModelId));
    }

    /**
     * アイテムモデルマスターを設定
     *
     * @param itemModelId アイテムモデルマスター
     */
    ItemModel& withItemModelId(StringHolder itemModelId)
    {
        setItemModelId(std::move(itemModelId));
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
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * アイテムモデルの種類名を設定
     *
     * @param name アイテムモデルの種類名
     */
    ItemModel& withName(StringHolder name)
    {
        setName(std::move(name));
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
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * アイテムモデルの種類のメタデータを設定
     *
     * @param metadata アイテムモデルの種類のメタデータ
     */
    ItemModel& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    /**
     * スタック可能な最大数量を取得
     *
     * @return スタック可能な最大数量
     */
    const optional<Int64>& getStackingLimit() const
    {
        return ensureData().stackingLimit;
    }

    /**
     * スタック可能な最大数量を設定
     *
     * @param stackingLimit スタック可能な最大数量
     */
    void setStackingLimit(Int64 stackingLimit)
    {
        ensureData().stackingLimit.emplace(stackingLimit);
    }

    /**
     * スタック可能な最大数量を設定
     *
     * @param stackingLimit スタック可能な最大数量
     */
    ItemModel& withStackingLimit(Int64 stackingLimit)
    {
        setStackingLimit(stackingLimit);
        return *this;
    }

    /**
     * スタック可能な最大数量を超えた時複数枠にアイテムを保管することを許すかを取得
     *
     * @return スタック可能な最大数量を超えた時複数枠にアイテムを保管することを許すか
     */
    const optional<Bool>& getAllowMultipleStacks() const
    {
        return ensureData().allowMultipleStacks;
    }

    /**
     * スタック可能な最大数量を超えた時複数枠にアイテムを保管することを許すかを設定
     *
     * @param allowMultipleStacks スタック可能な最大数量を超えた時複数枠にアイテムを保管することを許すか
     */
    void setAllowMultipleStacks(Bool allowMultipleStacks)
    {
        ensureData().allowMultipleStacks.emplace(allowMultipleStacks);
    }

    /**
     * スタック可能な最大数量を超えた時複数枠にアイテムを保管することを許すかを設定
     *
     * @param allowMultipleStacks スタック可能な最大数量を超えた時複数枠にアイテムを保管することを許すか
     */
    ItemModel& withAllowMultipleStacks(Bool allowMultipleStacks)
    {
        setAllowMultipleStacks(allowMultipleStacks);
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
    ItemModel& withSortValue(Int32 sortValue)
    {
        setSortValue(sortValue);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const ItemModel& lhs, const ItemModel& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->itemModelId != lhr.m_pData->itemModelId)
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
        if (lhs.m_pData->stackingLimit != lhr.m_pData->stackingLimit)
        {
            return true;
        }
        if (lhs.m_pData->allowMultipleStacks != lhr.m_pData->allowMultipleStacks)
        {
            return true;
        }
        if (lhs.m_pData->sortValue != lhr.m_pData->sortValue)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const ItemModel& lhs, const ItemModel& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_INVENTORY_MODEL_ITEMMODEL_HPP_