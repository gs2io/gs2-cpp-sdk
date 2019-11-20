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
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "DisplayItem.hpp"
#include <memory>
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
        /** 陳列棚 */
        optional<StringHolder> showcaseId;
        /** 商品名 */
        optional<StringHolder> name;
        /** 商品のメタデータ */
        optional<StringHolder> metadata;
        /** インベントリに格納可能なアイテムモデル一覧 */
        optional<List<DisplayItem>> displayItems;
        /** 販売期間とするイベントマスター のGRN */
        optional<StringHolder> salesPeriodEventId;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            showcaseId(data.showcaseId),
            name(data.name),
            metadata(data.metadata),
            salesPeriodEventId(data.salesPeriodEventId)
        {
            if (data.displayItems)
            {
                displayItems = data.displayItems->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "showcaseId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->showcaseId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name_, "displayItems") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->displayItems.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        DisplayItem item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        *this->displayItems += std::move(item);
                    }
                }
            }
            else if (std::strcmp(name_, "salesPeriodEventId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->salesPeriodEventId.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Showcase() = default;
    Showcase(const Showcase& showcase) = default;
    Showcase(Showcase&& showcase) = default;
    ~Showcase() = default;

    Showcase& operator=(const Showcase& showcase) = default;
    Showcase& operator=(Showcase&& showcase) = default;

    Showcase deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Showcase);
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
     * 陳列棚を取得
     *
     * @return 陳列棚
     */
    const optional<StringHolder>& getShowcaseId() const
    {
        return ensureData().showcaseId;
    }

    /**
     * 陳列棚を設定
     *
     * @param showcaseId 陳列棚
     */
    void setShowcaseId(StringHolder showcaseId)
    {
        ensureData().showcaseId.emplace(std::move(showcaseId));
    }

    /**
     * 陳列棚を設定
     *
     * @param showcaseId 陳列棚
     */
    Showcase& withShowcaseId(StringHolder showcaseId)
    {
        setShowcaseId(std::move(showcaseId));
        return *this;
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
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * 商品名を設定
     *
     * @param name 商品名
     */
    Showcase& withName(StringHolder name)
    {
        setName(std::move(name));
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
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * 商品のメタデータを設定
     *
     * @param metadata 商品のメタデータ
     */
    Showcase& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
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
    void setDisplayItems(List<DisplayItem> displayItems)
    {
        ensureData().displayItems.emplace(std::move(displayItems));
    }

    /**
     * インベントリに格納可能なアイテムモデル一覧を設定
     *
     * @param displayItems インベントリに格納可能なアイテムモデル一覧
     */
    Showcase& withDisplayItems(List<DisplayItem> displayItems)
    {
        setDisplayItems(std::move(displayItems));
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
    void setSalesPeriodEventId(StringHolder salesPeriodEventId)
    {
        ensureData().salesPeriodEventId.emplace(std::move(salesPeriodEventId));
    }

    /**
     * 販売期間とするイベントマスター のGRNを設定
     *
     * @param salesPeriodEventId 販売期間とするイベントマスター のGRN
     */
    Showcase& withSalesPeriodEventId(StringHolder salesPeriodEventId)
    {
        setSalesPeriodEventId(std::move(salesPeriodEventId));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Showcase& lhs, const Showcase& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->showcaseId != lhr.m_pData->showcaseId)
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

inline bool operator==(const Showcase& lhs, const Showcase& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_SHOWCASE_MODEL_SHOWCASE_HPP_