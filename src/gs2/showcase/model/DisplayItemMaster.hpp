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
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
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

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            displayItemId(data.displayItemId),
            type(data.type),
            salesItemName(data.salesItemName),
            salesItemGroupName(data.salesItemGroupName),
            salesPeriodEventId(data.salesPeriodEventId)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "displayItemId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->displayItemId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "type") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->type.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "salesItemName") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->salesItemName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "salesItemGroupName") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->salesItemGroupName.emplace(jsonValue.GetString());
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
    DisplayItemMaster() = default;
    DisplayItemMaster(const DisplayItemMaster& displayItemMaster) = default;
    DisplayItemMaster(DisplayItemMaster&& displayItemMaster) = default;
    ~DisplayItemMaster() = default;

    DisplayItemMaster& operator=(const DisplayItemMaster& displayItemMaster) = default;
    DisplayItemMaster& operator=(DisplayItemMaster&& displayItemMaster) = default;

    DisplayItemMaster deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DisplayItemMaster);
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
    void setDisplayItemId(StringHolder displayItemId)
    {
        ensureData().displayItemId.emplace(std::move(displayItemId));
    }

    /**
     * 陳列商品IDを設定
     *
     * @param displayItemId 陳列商品ID
     */
    DisplayItemMaster& withDisplayItemId(StringHolder displayItemId)
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
    DisplayItemMaster& withType(StringHolder type)
    {
        setType(std::move(type));
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
    void setSalesItemName(StringHolder salesItemName)
    {
        ensureData().salesItemName.emplace(std::move(salesItemName));
    }

    /**
     * 陳列する商品の名前を設定
     *
     * @param salesItemName 陳列する商品の名前
     */
    DisplayItemMaster& withSalesItemName(StringHolder salesItemName)
    {
        setSalesItemName(std::move(salesItemName));
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
    void setSalesItemGroupName(StringHolder salesItemGroupName)
    {
        ensureData().salesItemGroupName.emplace(std::move(salesItemGroupName));
    }

    /**
     * 陳列する商品グループの名前を設定
     *
     * @param salesItemGroupName 陳列する商品グループの名前
     */
    DisplayItemMaster& withSalesItemGroupName(StringHolder salesItemGroupName)
    {
        setSalesItemGroupName(std::move(salesItemGroupName));
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
    DisplayItemMaster& withSalesPeriodEventId(StringHolder salesPeriodEventId)
    {
        setSalesPeriodEventId(std::move(salesPeriodEventId));
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
        if (!lhs.m_pData || !lhr.m_pData)
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