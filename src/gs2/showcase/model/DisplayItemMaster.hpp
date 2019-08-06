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

#ifndef GS2_SHOWCASE_MODEL_DISPLAYITEMMASTER_HPP_
#define GS2_SHOWCASE_MODEL_DISPLAYITEMMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace showcase {

/**
 * None
 *
 * @author Game Server Services, Inc.
 *
 */
class DisplayItemMaster : public Gs2Object
{
    friend bool operator!=(const DisplayItemMaster& lhs, const DisplayItemMaster& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 陳列商品ID */
        optional<StringHolder> displayItemId;
        /** 種類 */
        optional<StringHolder> type;
        /** 陳列する商品の名前 */
        optional<StringHolder> salesItemName;
        /** 陳列する商品グループの名前 */
        optional<StringHolder> salesItemGroupName;
        /** 販売期間とするイベントマスター のGRN */
        optional<StringHolder> salesPeriodEventId;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            displayItemId(data.displayItemId),
            type(data.type),
            salesItemName(data.salesItemName),
            salesItemGroupName(data.salesItemGroupName),
            salesPeriodEventId(data.salesPeriodEventId)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            displayItemId(std::move(data.displayItemId)),
            type(std::move(data.type)),
            salesItemName(std::move(data.salesItemName)),
            salesItemGroupName(std::move(data.salesItemGroupName)),
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
            else if (std::strcmp(name_, "salesItemName") == 0) {
                if (jsonValue.IsString())
                {
                    this->salesItemName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "salesItemGroupName") == 0) {
                if (jsonValue.IsString())
                {
                    this->salesItemGroupName.emplace(jsonValue.GetString());
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
    DisplayItemMaster() :
        m_pData(nullptr)
    {}

    DisplayItemMaster(const DisplayItemMaster& displayItemMaster) :
        Gs2Object(displayItemMaster),
        m_pData(displayItemMaster.m_pData != nullptr ? new Data(*displayItemMaster.m_pData) : nullptr)
    {}

    DisplayItemMaster(DisplayItemMaster&& displayItemMaster) :
        Gs2Object(std::move(displayItemMaster)),
        m_pData(displayItemMaster.m_pData)
    {
        displayItemMaster.m_pData = nullptr;
    }

    ~DisplayItemMaster()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DisplayItemMaster& operator=(const DisplayItemMaster& displayItemMaster)
    {
        Gs2Object::operator=(displayItemMaster);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*displayItemMaster.m_pData);

        return *this;
    }

    DisplayItemMaster& operator=(DisplayItemMaster&& displayItemMaster)
    {
        Gs2Object::operator=(std::move(displayItemMaster));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = displayItemMaster.m_pData;
        displayItemMaster.m_pData = nullptr;

        return *this;
    }

    const DisplayItemMaster* operator->() const
    {
        return this;
    }

    DisplayItemMaster* operator->()
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
    DisplayItemMaster& withDisplayItemId(const Char* displayItemId)
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
    DisplayItemMaster& withType(const Char* type)
    {
        setType(type);
        return *this;
    }

    /**
     * 陳列する商品の名前を取得
     *
     * @return 陳列する商品の名前
     */
    const optional<StringHolder>& getSalesItemName() const
    {
        return ensureData().salesItemName;
    }

    /**
     * 陳列する商品の名前を設定
     *
     * @param salesItemName 陳列する商品の名前
     */
    void setSalesItemName(const Char* salesItemName)
    {
        ensureData().salesItemName.emplace(salesItemName);
    }

    /**
     * 陳列する商品の名前を設定
     *
     * @param salesItemName 陳列する商品の名前
     */
    DisplayItemMaster& withSalesItemName(const Char* salesItemName)
    {
        setSalesItemName(salesItemName);
        return *this;
    }

    /**
     * 陳列する商品グループの名前を取得
     *
     * @return 陳列する商品グループの名前
     */
    const optional<StringHolder>& getSalesItemGroupName() const
    {
        return ensureData().salesItemGroupName;
    }

    /**
     * 陳列する商品グループの名前を設定
     *
     * @param salesItemGroupName 陳列する商品グループの名前
     */
    void setSalesItemGroupName(const Char* salesItemGroupName)
    {
        ensureData().salesItemGroupName.emplace(salesItemGroupName);
    }

    /**
     * 陳列する商品グループの名前を設定
     *
     * @param salesItemGroupName 陳列する商品グループの名前
     */
    DisplayItemMaster& withSalesItemGroupName(const Char* salesItemGroupName)
    {
        setSalesItemGroupName(salesItemGroupName);
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
    DisplayItemMaster& withSalesPeriodEventId(const Char* salesPeriodEventId)
    {
        setSalesPeriodEventId(salesPeriodEventId);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const DisplayItemMaster& lhs, const DisplayItemMaster& lhr)
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
        if (lhs.m_pData->salesItemName != lhr.m_pData->salesItemName)
        {
            return true;
        }
        if (lhs.m_pData->salesItemGroupName != lhr.m_pData->salesItemGroupName)
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

inline bool operator==(const DisplayItemMaster& lhs, const DisplayItemMaster& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_SHOWCASE_MODEL_DISPLAYITEMMASTER_HPP_