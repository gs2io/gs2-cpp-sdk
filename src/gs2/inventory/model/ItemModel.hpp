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
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace inventory {

/**
 * アイテムマスター
 *
 * @author Game Server Services, Inc.
 *
 */
class ItemModel : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** アイテムマスター のGRN */
        optional<StringHolder> itemModelId;
        /** アイテムモデルの種類名 */
        optional<StringHolder> name;
        /** アイテムモデルの種類のメタデータ */
        optional<StringHolder> metadata;
        /** 所有可能な最大数量 */
        optional<Int64> maxCount;
        /** 表示順番 */
        optional<Int32> sortValue;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            itemModelId(data.itemModelId),
            name(data.name),
            metadata(data.metadata),
            maxCount(data.maxCount),
            sortValue(data.sortValue)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            itemModelId(std::move(data.itemModelId)),
            name(std::move(data.name)),
            metadata(std::move(data.metadata)),
            maxCount(std::move(data.maxCount)),
            sortValue(std::move(data.sortValue))
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
    ItemModel() :
        m_pData(nullptr)
    {}

    ItemModel(const ItemModel& itemModel) :
        Gs2Object(itemModel),
        m_pData(itemModel.m_pData != nullptr ? new Data(*itemModel.m_pData) : nullptr)
    {}

    ItemModel(ItemModel&& itemModel) :
        Gs2Object(std::move(itemModel)),
        m_pData(itemModel.m_pData)
    {
        itemModel.m_pData = nullptr;
    }

    ~ItemModel()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    ItemModel& operator=(const ItemModel& itemModel)
    {
        Gs2Object::operator=(itemModel);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*itemModel.m_pData);

        return *this;
    }

    ItemModel& operator=(ItemModel&& itemModel)
    {
        Gs2Object::operator=(std::move(itemModel));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = itemModel.m_pData;
        itemModel.m_pData = nullptr;

        return *this;
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


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_INVENTORY_MODEL_ITEMMODEL_HPP_