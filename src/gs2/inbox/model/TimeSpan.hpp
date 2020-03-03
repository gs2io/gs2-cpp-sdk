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

#ifndef GS2_INBOX_MODEL_TIMESPAN_HPP_
#define GS2_INBOX_MODEL_TIMESPAN_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace inbox {

/**
 * 差分時間設定
 *
 * @author Game Server Services, Inc.
 *
 */
class TimeSpan : public Gs2Object
{
    friend bool operator!=(const TimeSpan& lhs, const TimeSpan& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 現在時刻からの日数 */
        optional<Int32> days;
        /** 現在時刻からの時間 */
        optional<Int32> hours;
        /** 現在時刻からの分 */
        optional<Int32> minutes;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            days(data.days),
            hours(data.hours),
            minutes(data.minutes)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "days") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->days = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "hours") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->hours = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "minutes") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->minutes = jsonValue.GetInt();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    TimeSpan() = default;
    TimeSpan(const TimeSpan& timeSpan) = default;
    TimeSpan(TimeSpan&& timeSpan) = default;
    ~TimeSpan() = default;

    TimeSpan& operator=(const TimeSpan& timeSpan) = default;
    TimeSpan& operator=(TimeSpan&& timeSpan) = default;

    TimeSpan deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(TimeSpan);
    }

    const TimeSpan* operator->() const
    {
        return this;
    }

    TimeSpan* operator->()
    {
        return this;
    }
    /**
     * 現在時刻からの日数を取得
     *
     * @return 現在時刻からの日数
     */
    const optional<Int32>& getDays() const
    {
        return ensureData().days;
    }

    /**
     * 現在時刻からの日数を設定
     *
     * @param days 現在時刻からの日数
     */
    void setDays(Int32 days)
    {
        ensureData().days.emplace(days);
    }

    /**
     * 現在時刻からの日数を設定
     *
     * @param days 現在時刻からの日数
     */
    TimeSpan& withDays(Int32 days)
    {
        setDays(days);
        return *this;
    }

    /**
     * 現在時刻からの時間を取得
     *
     * @return 現在時刻からの時間
     */
    const optional<Int32>& getHours() const
    {
        return ensureData().hours;
    }

    /**
     * 現在時刻からの時間を設定
     *
     * @param hours 現在時刻からの時間
     */
    void setHours(Int32 hours)
    {
        ensureData().hours.emplace(hours);
    }

    /**
     * 現在時刻からの時間を設定
     *
     * @param hours 現在時刻からの時間
     */
    TimeSpan& withHours(Int32 hours)
    {
        setHours(hours);
        return *this;
    }

    /**
     * 現在時刻からの分を取得
     *
     * @return 現在時刻からの分
     */
    const optional<Int32>& getMinutes() const
    {
        return ensureData().minutes;
    }

    /**
     * 現在時刻からの分を設定
     *
     * @param minutes 現在時刻からの分
     */
    void setMinutes(Int32 minutes)
    {
        ensureData().minutes.emplace(minutes);
    }

    /**
     * 現在時刻からの分を設定
     *
     * @param minutes 現在時刻からの分
     */
    TimeSpan& withMinutes(Int32 minutes)
    {
        setMinutes(minutes);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const TimeSpan& lhs, const TimeSpan& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->days != lhr.m_pData->days)
        {
            return true;
        }
        if (lhs.m_pData->hours != lhr.m_pData->hours)
        {
            return true;
        }
        if (lhs.m_pData->minutes != lhr.m_pData->minutes)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const TimeSpan& lhs, const TimeSpan& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_INBOX_MODEL_TIMESPAN_HPP_