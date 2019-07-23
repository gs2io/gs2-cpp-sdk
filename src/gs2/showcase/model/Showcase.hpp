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

#ifndef GS2_SHOWCASE_MODEL_SHOWCASE_HPP_
#define GS2_SHOWCASE_MODEL_SHOWCASE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "DisplayItem.hpp"
#include <cstring>

namespace gs2 { namespace showcase {

/**
 * 陳列棚
 *
 * @author Game Server Services, Inc.
 *
 */
class Showcase : public Gs2Object
{
    friend bool operator!=(const Showcase& lhs, const Showcase& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 商品名 */
        optional<StringHolder> name;
        /** 商品のメタデータ */
        optional<StringHolder> metadata;
        /** インベントリに格納可能なアイテムモデル一覧 */
        optional<List<DisplayItem>> displayItems;
        /** 販売期間とするイベントマスター のGRN */
        optional<StringHolder> salesPeriodEventId;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            name(data.name),
            metadata(data.metadata),
            displayItems(data.displayItems),
            salesPeriodEventId(data.salesPeriodEventId)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            name(std::move(data.name)),
            metadata(std::move(data.metadata)),
            displayItems(std::move(data.displayItems)),
            salesPeriodEventId(std::move(data.salesPeriodEventId))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "name") == 0) {
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
            else if (std::strcmp(name, "displayItems") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->displayItems.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        DisplayItem item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(json->GetObject()));
                        detail::addToList(*this->displayItems, std::move(item));
                    }
                }
            }
            else if (std::strcmp(name, "salesPeriodEventId") == 0) {
                if (jsonValue.IsString())
                {
                    this->salesPeriodEventId.emplace(jsonValue.GetString());
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
    Showcase() :
        m_pData(nullptr)
    {}

    Showcase(const Showcase& showcase) :
        Gs2Object(showcase),
        m_pData(showcase.m_pData != nullptr ? new Data(*showcase.m_pData) : nullptr)
    {}

    Showcase(Showcase&& showcase) :
        Gs2Object(std::move(showcase)),
        m_pData(showcase.m_pData)
    {
        showcase.m_pData = nullptr;
    }

    ~Showcase()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Showcase& operator=(const Showcase& showcase)
    {
        Gs2Object::operator=(showcase);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*showcase.m_pData);

        return *this;
    }

    Showcase& operator=(Showcase&& showcase)
    {
        Gs2Object::operator=(std::move(showcase));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = showcase.m_pData;
        showcase.m_pData = nullptr;

        return *this;
    }

    const Showcase* operator->() const
    {
        return this;
    }

    Showcase* operator->()
    {
        return this;
    }
    /**
     * 商品名を取得
     *
     * @return 商品名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 商品名を設定
     *
     * @param name 商品名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * 商品名を設定
     *
     * @param name 商品名
     */
    Showcase& withName(const Char* name)
    {
        setName(name);
        return *this;
    }

    /**
     * 商品のメタデータを取得
     *
     * @return 商品のメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * 商品のメタデータを設定
     *
     * @param metadata 商品のメタデータ
     */
    void setMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
    }

    /**
     * 商品のメタデータを設定
     *
     * @param metadata 商品のメタデータ
     */
    Showcase& withMetadata(const Char* metadata)
    {
        setMetadata(metadata);
        return *this;
    }

    /**
     * インベントリに格納可能なアイテムモデル一覧を取得
     *
     * @return インベントリに格納可能なアイテムモデル一覧
     */
    const optional<List<DisplayItem>>& getDisplayItems() const
    {
        return ensureData().displayItems;
    }

    /**
     * インベントリに格納可能なアイテムモデル一覧を設定
     *
     * @param displayItems インベントリに格納可能なアイテムモデル一覧
     */
    void setDisplayItems(const List<DisplayItem>& displayItems)
    {
        ensureData().displayItems.emplace(displayItems);
    }

    /**
     * インベントリに格納可能なアイテムモデル一覧を設定
     *
     * @param displayItems インベントリに格納可能なアイテムモデル一覧
     */
    Showcase& withDisplayItems(const List<DisplayItem>& displayItems)
    {
        setDisplayItems(displayItems);
        return *this;
    }

    /**
     * 販売期間とするイベントマスター のGRNを取得
     *
     * @return 販売期間とするイベントマスター のGRN
     */
    const optional<StringHolder>& getSalesPeriodEventId() const
    {
        return ensureData().salesPeriodEventId;
    }

    /**
     * 販売期間とするイベントマスター のGRNを設定
     *
     * @param salesPeriodEventId 販売期間とするイベントマスター のGRN
     */
    void setSalesPeriodEventId(const Char* salesPeriodEventId)
    {
        ensureData().salesPeriodEventId.emplace(salesPeriodEventId);
    }

    /**
     * 販売期間とするイベントマスター のGRNを設定
     *
     * @param salesPeriodEventId 販売期間とするイベントマスター のGRN
     */
    Showcase& withSalesPeriodEventId(const Char* salesPeriodEventId)
    {
        setSalesPeriodEventId(salesPeriodEventId);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const Showcase& lhs, const Showcase& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
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
        if (lhs.m_pData->displayItems != lhr.m_pData->displayItems)
        {
            return true;
        }
        if (lhs.m_pData->salesPeriodEventId != lhr.m_pData->salesPeriodEventId)
        {
            return true;
        }
    }
    return false;
}

bool operator==(const Showcase& lhs, const Showcase& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_SHOWCASE_MODEL_SHOWCASE_HPP_