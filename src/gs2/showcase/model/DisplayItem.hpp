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
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "SalesItem.hpp"
#include "SalesItemGroup.hpp"
#include <cstring>

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

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            displayItemId(data.displayItemId),
            type(data.type),
            salesItem(data.salesItem),
            salesItemGroup(data.salesItemGroup),
            salesPeriodEventId(data.salesPeriodEventId)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            displayItemId(std::move(data.displayItemId)),
            type(std::move(data.type)),
            salesItem(std::move(data.salesItem)),
            salesItemGroup(std::move(data.salesItemGroup)),
            salesPeriodEventId(std::move(data.salesPeriodEventId))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "displayItemId") == 0) {
                if (jsonValue.IsString())
                {
                    this->displayItemId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "type") == 0) {
                if (jsonValue.IsString())
                {
                    this->type.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "salesItem") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->salesItem.emplace();
                    detail::json::JsonParser::parse(&this->salesItem->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "salesItemGroup") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->salesItemGroup.emplace();
                    detail::json::JsonParser::parse(&this->salesItemGroup->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "salesPeriodEventId") == 0) {
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
    DisplayItem() :
        m_pData(nullptr)
    {}

    DisplayItem(const DisplayItem& displayItem) :
        Gs2Object(displayItem),
        m_pData(displayItem.m_pData != nullptr ? new Data(*displayItem.m_pData) : nullptr)
    {}

    DisplayItem(DisplayItem&& displayItem) :
        Gs2Object(std::move(displayItem)),
        m_pData(displayItem.m_pData)
    {
        displayItem.m_pData = nullptr;
    }

    ~DisplayItem()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DisplayItem& operator=(const DisplayItem& displayItem)
    {
        Gs2Object::operator=(displayItem);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*displayItem.m_pData);

        return *this;
    }

    DisplayItem& operator=(DisplayItem&& displayItem)
    {
        Gs2Object::operator=(std::move(displayItem));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = displayItem.m_pData;
        displayItem.m_pData = nullptr;

        return *this;
    }

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
    void setDisplayItemId(const Char* displayItemId)
    {
        ensureData().displayItemId.emplace(displayItemId);
    }

    /**
     * 陳列商品IDを設定
     *
     * @param displayItemId 陳列商品ID
     */
    DisplayItem& withDisplayItemId(const Char* displayItemId)
    {
        setDisplayItemId(displayItemId);
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
    void setType(const Char* type)
    {
        ensureData().type.emplace(type);
    }

    /**
     * 種類を設定
     *
     * @param type 種類
     */
    DisplayItem& withType(const Char* type)
    {
        setType(type);
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
    void setSalesItem(const SalesItem& salesItem)
    {
        ensureData().salesItem.emplace(salesItem);
    }

    /**
     * 陳列する商品を設定
     *
     * @param salesItem 陳列する商品
     */
    DisplayItem& withSalesItem(const SalesItem& salesItem)
    {
        setSalesItem(salesItem);
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
    void setSalesItemGroup(const SalesItemGroup& salesItemGroup)
    {
        ensureData().salesItemGroup.emplace(salesItemGroup);
    }

    /**
     * 陳列する商品グループを設定
     *
     * @param salesItemGroup 陳列する商品グループ
     */
    DisplayItem& withSalesItemGroup(const SalesItemGroup& salesItemGroup)
    {
        setSalesItemGroup(salesItemGroup);
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
    DisplayItem& withSalesPeriodEventId(const Char* salesPeriodEventId)
    {
        setSalesPeriodEventId(salesPeriodEventId);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const DisplayItem& lhs, const DisplayItem& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->displayItemId != lhr.m_pData->displayItemId)
        {
            return true;
        }
        if (lhs.m_pData->type != lhr.m_pData->type)
        {
            return true;
        }
        if (lhs.m_pData->salesItem != lhr.m_pData->salesItem)
        {
            return true;
        }
        if (lhs.m_pData->salesItemGroup != lhr.m_pData->salesItemGroup)
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

inline bool operator==(const DisplayItem& lhs, const DisplayItem& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_SHOWCASE_MODEL_DISPLAYITEM_HPP_