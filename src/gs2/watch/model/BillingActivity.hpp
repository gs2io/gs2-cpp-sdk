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

#ifndef GS2_WATCH_MODEL_BILLINGACTIVITY_HPP_
#define GS2_WATCH_MODEL_BILLINGACTIVITY_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace watch {

/**
 * 請求にまつわるアクティビティ
 *
 * @author Game Server Services, Inc.
 *
 */
class BillingActivity : public Gs2Object
{
    friend bool operator!=(const BillingActivity& lhs, const BillingActivity& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 請求にまつわるアクティビティ */
        optional<StringHolder> billingActivityId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** イベントの発生年 */
        optional<Int32> year;
        /** イベントの発生月 */
        optional<Int32> month;
        /** サービスの種類 */
        optional<StringHolder> service;
        /** イベントの種類 */
        optional<StringHolder> activityType;
        /** イベントの値 */
        optional<Int64> value;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            billingActivityId(data.billingActivityId),
            ownerId(data.ownerId),
            year(data.year),
            month(data.month),
            service(data.service),
            activityType(data.activityType),
            value(data.value)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "billingActivityId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->billingActivityId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "ownerId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->ownerId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name_, "value") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->value = jsonValue.GetInt64();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    BillingActivity() = default;
    BillingActivity(const BillingActivity& billingActivity) = default;
    BillingActivity(BillingActivity&& billingActivity) = default;
    ~BillingActivity() = default;

    BillingActivity& operator=(const BillingActivity& billingActivity) = default;
    BillingActivity& operator=(BillingActivity&& billingActivity) = default;

    BillingActivity deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(BillingActivity);
    }

    const BillingActivity* operator->() const
    {
        return this;
    }

    BillingActivity* operator->()
    {
        return this;
    }
    /**
     * 請求にまつわるアクティビティを取得
     *
     * @return 請求にまつわるアクティビティ
     */
    const optional<StringHolder>& getBillingActivityId() const
    {
        return ensureData().billingActivityId;
    }

    /**
     * 請求にまつわるアクティビティを設定
     *
     * @param billingActivityId 請求にまつわるアクティビティ
     */
    void setBillingActivityId(StringHolder billingActivityId)
    {
        ensureData().billingActivityId.emplace(std::move(billingActivityId));
    }

    /**
     * 請求にまつわるアクティビティを設定
     *
     * @param billingActivityId 請求にまつわるアクティビティ
     */
    BillingActivity& withBillingActivityId(StringHolder billingActivityId)
    {
        setBillingActivityId(std::move(billingActivityId));
        return *this;
    }

    /**
     * オーナーIDを取得
     *
     * @return オーナーID
     */
    const optional<StringHolder>& getOwnerId() const
    {
        return ensureData().ownerId;
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    void setOwnerId(StringHolder ownerId)
    {
        ensureData().ownerId.emplace(std::move(ownerId));
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    BillingActivity& withOwnerId(StringHolder ownerId)
    {
        setOwnerId(std::move(ownerId));
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
    BillingActivity& withYear(Int32 year)
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
    BillingActivity& withMonth(Int32 month)
    {
        setMonth(month);
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
    BillingActivity& withService(StringHolder service)
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
    BillingActivity& withActivityType(StringHolder activityType)
    {
        setActivityType(std::move(activityType));
        return *this;
    }

    /**
     * イベントの値を取得
     *
     * @return イベントの値
     */
    const optional<Int64>& getValue() const
    {
        return ensureData().value;
    }

    /**
     * イベントの値を設定
     *
     * @param value イベントの値
     */
    void setValue(Int64 value)
    {
        ensureData().value.emplace(value);
    }

    /**
     * イベントの値を設定
     *
     * @param value イベントの値
     */
    BillingActivity& withValue(Int64 value)
    {
        setValue(value);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const BillingActivity& lhs, const BillingActivity& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->billingActivityId != lhr.m_pData->billingActivityId)
        {
            return true;
        }
        if (lhs.m_pData->ownerId != lhr.m_pData->ownerId)
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
        if (lhs.m_pData->service != lhr.m_pData->service)
        {
            return true;
        }
        if (lhs.m_pData->activityType != lhr.m_pData->activityType)
        {
            return true;
        }
        if (lhs.m_pData->value != lhr.m_pData->value)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const BillingActivity& lhs, const BillingActivity& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_WATCH_MODEL_BILLINGACTIVITY_HPP_