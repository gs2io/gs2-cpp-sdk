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

#ifndef GS2_PROJECT_MODEL_BILLING_HPP_
#define GS2_PROJECT_MODEL_BILLING_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace project {

/**
 * 利用状況
 *
 * @author Game Server Services, Inc.
 *
 */
class Billing : public Gs2Object
{
    friend bool operator!=(const Billing& lhs, const Billing& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 利用状況 */
        optional<StringHolder> billingId;
        /** プロジェクト名 */
        optional<StringHolder> projectName;
        /** イベントの発生年 */
        optional<Int32> year;
        /** イベントの発生月 */
        optional<Int32> month;
        /** リージョン */
        optional<StringHolder> region;
        /** サービスの種類 */
        optional<StringHolder> service;
        /** イベントの種類 */
        optional<StringHolder> activityType;
        /** 回数 */
        optional<Int64> unit;
        /** 単位 */
        optional<StringHolder> unitName;
        /** 料金 */
        optional<Int64> price;
        /** 通貨 */
        optional<StringHolder> currency;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            billingId(data.billingId),
            projectName(data.projectName),
            year(data.year),
            month(data.month),
            region(data.region),
            service(data.service),
            activityType(data.activityType),
            unit(data.unit),
            unitName(data.unitName),
            price(data.price),
            currency(data.currency),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "billingId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->billingId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "projectName") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->projectName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "year") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->year = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "month") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->month = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "region") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->region.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "service") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->service.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "activityType") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->activityType.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "unit") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->unit = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "unitName") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->unitName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "price") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->price = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "currency") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->currency.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "createdAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "updatedAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Billing() = default;
    Billing(const Billing& billing) = default;
    Billing(Billing&& billing) = default;
    ~Billing() = default;

    Billing& operator=(const Billing& billing) = default;
    Billing& operator=(Billing&& billing) = default;

    Billing deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Billing);
    }

    const Billing* operator->() const
    {
        return this;
    }

    Billing* operator->()
    {
        return this;
    }
    /**
     * 利用状況を取得
     *
     * @return 利用状況
     */
    const optional<StringHolder>& getBillingId() const
    {
        return ensureData().billingId;
    }

    /**
     * 利用状況を設定
     *
     * @param billingId 利用状況
     */
    void setBillingId(StringHolder billingId)
    {
        ensureData().billingId.emplace(std::move(billingId));
    }

    /**
     * 利用状況を設定
     *
     * @param billingId 利用状況
     */
    Billing& withBillingId(StringHolder billingId)
    {
        setBillingId(std::move(billingId));
        return *this;
    }

    /**
     * プロジェクト名を取得
     *
     * @return プロジェクト名
     */
    const optional<StringHolder>& getProjectName() const
    {
        return ensureData().projectName;
    }

    /**
     * プロジェクト名を設定
     *
     * @param projectName プロジェクト名
     */
    void setProjectName(StringHolder projectName)
    {
        ensureData().projectName.emplace(std::move(projectName));
    }

    /**
     * プロジェクト名を設定
     *
     * @param projectName プロジェクト名
     */
    Billing& withProjectName(StringHolder projectName)
    {
        setProjectName(std::move(projectName));
        return *this;
    }

    /**
     * イベントの発生年を取得
     *
     * @return イベントの発生年
     */
    const optional<Int32>& getYear() const
    {
        return ensureData().year;
    }

    /**
     * イベントの発生年を設定
     *
     * @param year イベントの発生年
     */
    void setYear(Int32 year)
    {
        ensureData().year.emplace(year);
    }

    /**
     * イベントの発生年を設定
     *
     * @param year イベントの発生年
     */
    Billing& withYear(Int32 year)
    {
        setYear(year);
        return *this;
    }

    /**
     * イベントの発生月を取得
     *
     * @return イベントの発生月
     */
    const optional<Int32>& getMonth() const
    {
        return ensureData().month;
    }

    /**
     * イベントの発生月を設定
     *
     * @param month イベントの発生月
     */
    void setMonth(Int32 month)
    {
        ensureData().month.emplace(month);
    }

    /**
     * イベントの発生月を設定
     *
     * @param month イベントの発生月
     */
    Billing& withMonth(Int32 month)
    {
        setMonth(month);
        return *this;
    }

    /**
     * リージョンを取得
     *
     * @return リージョン
     */
    const optional<StringHolder>& getRegion() const
    {
        return ensureData().region;
    }

    /**
     * リージョンを設定
     *
     * @param region リージョン
     */
    void setRegion(StringHolder region)
    {
        ensureData().region.emplace(std::move(region));
    }

    /**
     * リージョンを設定
     *
     * @param region リージョン
     */
    Billing& withRegion(StringHolder region)
    {
        setRegion(std::move(region));
        return *this;
    }

    /**
     * サービスの種類を取得
     *
     * @return サービスの種類
     */
    const optional<StringHolder>& getService() const
    {
        return ensureData().service;
    }

    /**
     * サービスの種類を設定
     *
     * @param service サービスの種類
     */
    void setService(StringHolder service)
    {
        ensureData().service.emplace(std::move(service));
    }

    /**
     * サービスの種類を設定
     *
     * @param service サービスの種類
     */
    Billing& withService(StringHolder service)
    {
        setService(std::move(service));
        return *this;
    }

    /**
     * イベントの種類を取得
     *
     * @return イベントの種類
     */
    const optional<StringHolder>& getActivityType() const
    {
        return ensureData().activityType;
    }

    /**
     * イベントの種類を設定
     *
     * @param activityType イベントの種類
     */
    void setActivityType(StringHolder activityType)
    {
        ensureData().activityType.emplace(std::move(activityType));
    }

    /**
     * イベントの種類を設定
     *
     * @param activityType イベントの種類
     */
    Billing& withActivityType(StringHolder activityType)
    {
        setActivityType(std::move(activityType));
        return *this;
    }

    /**
     * 回数を取得
     *
     * @return 回数
     */
    const optional<Int64>& getUnit() const
    {
        return ensureData().unit;
    }

    /**
     * 回数を設定
     *
     * @param unit 回数
     */
    void setUnit(Int64 unit)
    {
        ensureData().unit.emplace(unit);
    }

    /**
     * 回数を設定
     *
     * @param unit 回数
     */
    Billing& withUnit(Int64 unit)
    {
        setUnit(unit);
        return *this;
    }

    /**
     * 単位を取得
     *
     * @return 単位
     */
    const optional<StringHolder>& getUnitName() const
    {
        return ensureData().unitName;
    }

    /**
     * 単位を設定
     *
     * @param unitName 単位
     */
    void setUnitName(StringHolder unitName)
    {
        ensureData().unitName.emplace(std::move(unitName));
    }

    /**
     * 単位を設定
     *
     * @param unitName 単位
     */
    Billing& withUnitName(StringHolder unitName)
    {
        setUnitName(std::move(unitName));
        return *this;
    }

    /**
     * 料金を取得
     *
     * @return 料金
     */
    const optional<Int64>& getPrice() const
    {
        return ensureData().price;
    }

    /**
     * 料金を設定
     *
     * @param price 料金
     */
    void setPrice(Int64 price)
    {
        ensureData().price.emplace(price);
    }

    /**
     * 料金を設定
     *
     * @param price 料金
     */
    Billing& withPrice(Int64 price)
    {
        setPrice(price);
        return *this;
    }

    /**
     * 通貨を取得
     *
     * @return 通貨
     */
    const optional<StringHolder>& getCurrency() const
    {
        return ensureData().currency;
    }

    /**
     * 通貨を設定
     *
     * @param currency 通貨
     */
    void setCurrency(StringHolder currency)
    {
        ensureData().currency.emplace(std::move(currency));
    }

    /**
     * 通貨を設定
     *
     * @param currency 通貨
     */
    Billing& withCurrency(StringHolder currency)
    {
        setCurrency(std::move(currency));
        return *this;
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getCreatedAt() const
    {
        return ensureData().createdAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    void setCreatedAt(Int64 createdAt)
    {
        ensureData().createdAt.emplace(createdAt);
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    Billing& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }

    /**
     * 最終更新日時を取得
     *
     * @return 最終更新日時
     */
    const optional<Int64>& getUpdatedAt() const
    {
        return ensureData().updatedAt;
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    void setUpdatedAt(Int64 updatedAt)
    {
        ensureData().updatedAt.emplace(updatedAt);
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    Billing& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Billing& lhs, const Billing& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->billingId != lhr.m_pData->billingId)
        {
            return true;
        }
        if (lhs.m_pData->projectName != lhr.m_pData->projectName)
        {
            return true;
        }
        if (lhs.m_pData->year != lhr.m_pData->year)
        {
            return true;
        }
        if (lhs.m_pData->month != lhr.m_pData->month)
        {
            return true;
        }
        if (lhs.m_pData->region != lhr.m_pData->region)
        {
            return true;
        }
        if (lhs.m_pData->service != lhr.m_pData->service)
        {
            return true;
        }
        if (lhs.m_pData->activityType != lhr.m_pData->activityType)
        {
            return true;
        }
        if (lhs.m_pData->unit != lhr.m_pData->unit)
        {
            return true;
        }
        if (lhs.m_pData->unitName != lhr.m_pData->unitName)
        {
            return true;
        }
        if (lhs.m_pData->price != lhr.m_pData->price)
        {
            return true;
        }
        if (lhs.m_pData->currency != lhr.m_pData->currency)
        {
            return true;
        }
        if (lhs.m_pData->createdAt != lhr.m_pData->createdAt)
        {
            return true;
        }
        if (lhs.m_pData->updatedAt != lhr.m_pData->updatedAt)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const Billing& lhs, const Billing& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_PROJECT_MODEL_BILLING_HPP_