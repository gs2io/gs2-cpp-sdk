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

#ifndef GS2_SHOWCASE_MODEL_DISPLAYITEM_HPP_
#define GS2_SHOWCASE_MODEL_DISPLAYITEM_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "SalesItem.hpp"
#include "SalesItemGroup.hpp"
#include <memory>

namespace gs2 { namespace showcase {

/**
 * 陳列された商品
 *
 * @author Game Server Services, Inc.
 *
 */
class DisplayItem : public Gs2Object
{
    friend bool operator!=(const DisplayItem& lhs, const DisplayItem& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 陳列商品ID */
        optional<StringHolder> displayItemId;
        /** 種類 */
        optional<StringHolder> type;
        /** 陳列する商品 */
        optional<SalesItem> salesItem;
        /** 陳列する商品グループ */
        optional<SalesItemGroup> salesItemGroup;
        /** 販売期間とするイベントマスター のGRN */
        optional<StringHolder> salesPeriodEventId;

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
    DisplayItem() = default;
    DisplayItem(const DisplayItem& displayItem) = default;
    DisplayItem(DisplayItem&& displayItem) = default;
    ~DisplayItem() = default;

    DisplayItem& operator=(const DisplayItem& displayItem) = default;
    DisplayItem& operator=(DisplayItem&& displayItem) = default;

    DisplayItem deepCopy() const;

    const DisplayItem* operator->() const
    {
        return this;
    }

    DisplayItem* operator->()
    {
        return this;
    }
    /**
     * 陳列商品IDを取得
     *
     * @return 陳列商品ID
     */
    const optional<StringHolder>& getDisplayItemId() const
    {
        return ensureData().displayItemId;
    }

    /**
     * 陳列商品IDを設定
     *
     * @param displayItemId 陳列商品ID
     */
    void setDisplayItemId(StringHolder displayItemId)
    {
        ensureData().displayItemId.emplace(std::move(displayItemId));
    }

    /**
     * 陳列商品IDを設定
     *
     * @param displayItemId 陳列商品ID
     */
    DisplayItem& withDisplayItemId(StringHolder displayItemId)
    {
        setDisplayItemId(std::move(displayItemId));
        return *this;
    }

    /**
     * 種類を取得
     *
     * @return 種類
     */
    const optional<StringHolder>& getType() const
    {
        return ensureData().type;
    }

    /**
     * 種類を設定
     *
     * @param type 種類
     */
    void setType(StringHolder type)
    {
        ensureData().type.emplace(std::move(type));
    }

    /**
     * 種類を設定
     *
     * @param type 種類
     */
    DisplayItem& withType(StringHolder type)
    {
        setType(std::move(type));
        return *this;
    }

    /**
     * 陳列する商品を取得
     *
     * @return 陳列する商品
     */
    const optional<SalesItem>& getSalesItem() const
    {
        return ensureData().salesItem;
    }

    /**
     * 陳列する商品を設定
     *
     * @param salesItem 陳列する商品
     */
    void setSalesItem(SalesItem salesItem)
    {
        ensureData().salesItem.emplace(std::move(salesItem));
    }

    /**
     * 陳列する商品を設定
     *
     * @param salesItem 陳列する商品
     */
    DisplayItem& withSalesItem(SalesItem salesItem)
    {
        setSalesItem(std::move(salesItem));
        return *this;
    }

    /**
     * 陳列する商品グループを取得
     *
     * @return 陳列する商品グループ
     */
    const optional<SalesItemGroup>& getSalesItemGroup() const
    {
        return ensureData().salesItemGroup;
    }

    /**
     * 陳列する商品グループを設定
     *
     * @param salesItemGroup 陳列する商品グループ
     */
    void setSalesItemGroup(SalesItemGroup salesItemGroup)
    {
        ensureData().salesItemGroup.emplace(std::move(salesItemGroup));
    }

    /**
     * 陳列する商品グループを設定
     *
     * @param salesItemGroup 陳列する商品グループ
     */
    DisplayItem& withSalesItemGroup(SalesItemGroup salesItemGroup)
    {
        setSalesItemGroup(std::move(salesItemGroup));
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
    DisplayItem& withSalesPeriodEventId(StringHolder salesPeriodEventId)
    {
        setSalesPeriodEventId(std::move(salesPeriodEventId));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const DisplayItem& lhs, const DisplayItem& lhr);

inline bool operator==(const DisplayItem& lhs, const DisplayItem& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_SHOWCASE_MODEL_DISPLAYITEM_HPP_