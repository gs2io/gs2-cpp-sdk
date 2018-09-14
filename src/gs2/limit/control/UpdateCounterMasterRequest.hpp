/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
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

#ifndef GS2_LIMIT_CONTROL_UPDATECOUNTERMASTERREQUEST_HPP_
#define GS2_LIMIT_CONTROL_UPDATECOUNTERMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2LimitConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace limit
{

/**
 * @author Game Server Services, Inc.
 */
class UpdateCounterMasterRequest : public Gs2BasicRequest, public Gs2Limit
{
public:
    constexpr static const Char* const FUNCTION = "UpdateCounterMaster";

private:
    class Data : public Gs2Object
    {
    public:
        /** 回数制限の名前を指定します。 */
        optional<StringHolder> limitName;
        /** カウンター名を指定します。 */
        optional<StringHolder> counterName;
        /** カウンターの最大値 */
        optional<Int32> max;
        /** リセット周期 */
        optional<StringHolder> resetType;
        /** 期間内の取得量をリセットする日にち */
        optional<Int32> resetDayOfMonth;
        /** 期間内の取得量をリセットする曜日 */
        optional<StringHolder> resetDayOfWeek;
        /** 期間内の取得量をリセットする時 */
        optional<Int32> resetHour;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            limitName(data.limitName),
            counterName(data.counterName),
            max(data.max),
            resetType(data.resetType),
            resetDayOfMonth(data.resetDayOfMonth),
            resetDayOfWeek(data.resetDayOfWeek),
            resetHour(data.resetHour)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            limitName(std::move(data.limitName)),
            counterName(std::move(data.counterName)),
            max(std::move(data.max)),
            resetType(std::move(data.resetType)),
            resetDayOfMonth(std::move(data.resetDayOfMonth)),
            resetDayOfWeek(std::move(data.resetDayOfWeek)),
            resetHour(std::move(data.resetHour))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
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
    UpdateCounterMasterRequest() :
        m_pData(nullptr)
    {}

    UpdateCounterMasterRequest(const UpdateCounterMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Limit(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateCounterMasterRequest(UpdateCounterMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Limit(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateCounterMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateCounterMasterRequest& operator=(const UpdateCounterMasterRequest& updateCounterMasterRequest)
    {
        Gs2BasicRequest::operator=(updateCounterMasterRequest);
        Gs2Limit::operator=(updateCounterMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateCounterMasterRequest.m_pData);

        return *this;
    }

    UpdateCounterMasterRequest& operator=(UpdateCounterMasterRequest&& updateCounterMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateCounterMasterRequest));
        Gs2Limit::operator=(std::move(updateCounterMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateCounterMasterRequest.m_pData;
        updateCounterMasterRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateCounterMasterRequest* operator->() const
    {
        return this;
    }

    UpdateCounterMasterRequest* operator->()
    {
        return this;
    }

    /**
     * 回数制限の名前を指定します。を取得
     *
     * @return 回数制限の名前を指定します。
     */
    const optional<StringHolder>& getLimitName() const
    {
        return ensureData().limitName;
    }

    /**
     * 回数制限の名前を指定します。を設定
     *
     * @param limitName 回数制限の名前を指定します。
     */
    void setLimitName(const Char* limitName)
    {
        ensureData().limitName.emplace(limitName);
    }

    /**
     * 回数制限の名前を指定します。を設定
     *
     * @param limitName 回数制限の名前を指定します。
     */
    UpdateCounterMasterRequest& withLimitName(const Char* limitName)
    {
        ensureData().limitName.emplace(limitName);
        return *this;
    }

    /**
     * カウンター名を指定します。を取得
     *
     * @return カウンター名を指定します。
     */
    const optional<StringHolder>& getCounterName() const
    {
        return ensureData().counterName;
    }

    /**
     * カウンター名を指定します。を設定
     *
     * @param counterName カウンター名を指定します。
     */
    void setCounterName(const Char* counterName)
    {
        ensureData().counterName.emplace(counterName);
    }

    /**
     * カウンター名を指定します。を設定
     *
     * @param counterName カウンター名を指定します。
     */
    UpdateCounterMasterRequest& withCounterName(const Char* counterName)
    {
        ensureData().counterName.emplace(counterName);
        return *this;
    }

    /**
     * カウンターの最大値を取得
     *
     * @return カウンターの最大値
     */
    const optional<Int32>& getMax() const
    {
        return ensureData().max;
    }

    /**
     * カウンターの最大値を設定
     *
     * @param max カウンターの最大値
     */
    void setMax(Int32 max)
    {
        ensureData().max.emplace(max);
    }

    /**
     * カウンターの最大値を設定
     *
     * @param max カウンターの最大値
     */
    UpdateCounterMasterRequest& withMax(Int32 max)
    {
        ensureData().max.emplace(max);
        return *this;
    }

    /**
     * リセット周期を取得
     *
     * @return リセット周期
     */
    const optional<StringHolder>& getResetType() const
    {
        return ensureData().resetType;
    }

    /**
     * リセット周期を設定
     *
     * @param resetType リセット周期
     */
    void setResetType(const Char* resetType)
    {
        ensureData().resetType.emplace(resetType);
    }

    /**
     * リセット周期を設定
     *
     * @param resetType リセット周期
     */
    UpdateCounterMasterRequest& withResetType(const Char* resetType)
    {
        ensureData().resetType.emplace(resetType);
        return *this;
    }

    /**
     * 期間内の取得量をリセットする日にちを取得
     *
     * @return 期間内の取得量をリセットする日にち
     */
    const optional<Int32>& getResetDayOfMonth() const
    {
        return ensureData().resetDayOfMonth;
    }

    /**
     * 期間内の取得量をリセットする日にちを設定
     *
     * @param resetDayOfMonth 期間内の取得量をリセットする日にち
     */
    void setResetDayOfMonth(Int32 resetDayOfMonth)
    {
        ensureData().resetDayOfMonth.emplace(resetDayOfMonth);
    }

    /**
     * 期間内の取得量をリセットする日にちを設定
     *
     * @param resetDayOfMonth 期間内の取得量をリセットする日にち
     */
    UpdateCounterMasterRequest& withResetDayOfMonth(Int32 resetDayOfMonth)
    {
        ensureData().resetDayOfMonth.emplace(resetDayOfMonth);
        return *this;
    }

    /**
     * 期間内の取得量をリセットする曜日を取得
     *
     * @return 期間内の取得量をリセットする曜日
     */
    const optional<StringHolder>& getResetDayOfWeek() const
    {
        return ensureData().resetDayOfWeek;
    }

    /**
     * 期間内の取得量をリセットする曜日を設定
     *
     * @param resetDayOfWeek 期間内の取得量をリセットする曜日
     */
    void setResetDayOfWeek(const Char* resetDayOfWeek)
    {
        ensureData().resetDayOfWeek.emplace(resetDayOfWeek);
    }

    /**
     * 期間内の取得量をリセットする曜日を設定
     *
     * @param resetDayOfWeek 期間内の取得量をリセットする曜日
     */
    UpdateCounterMasterRequest& withResetDayOfWeek(const Char* resetDayOfWeek)
    {
        ensureData().resetDayOfWeek.emplace(resetDayOfWeek);
        return *this;
    }

    /**
     * 期間内の取得量をリセットする時を取得
     *
     * @return 期間内の取得量をリセットする時
     */
    const optional<Int32>& getResetHour() const
    {
        return ensureData().resetHour;
    }

    /**
     * 期間内の取得量をリセットする時を設定
     *
     * @param resetHour 期間内の取得量をリセットする時
     */
    void setResetHour(Int32 resetHour)
    {
        ensureData().resetHour.emplace(resetHour);
    }

    /**
     * 期間内の取得量をリセットする時を設定
     *
     * @param resetHour 期間内の取得量をリセットする時
     */
    UpdateCounterMasterRequest& withResetHour(Int32 resetHour)
    {
        ensureData().resetHour.emplace(resetHour);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateCounterMasterRequest& withGs2ClientId(const Char* gs2ClientId)
    {
        setGs2ClientId(gs2ClientId);
        return *this;
    }

    /**
     * タイムスタンプを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2Timestamp タイムスタンプ
     */
    UpdateCounterMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
    {
        setGs2Timestamp(gs2Timestamp);
        return *this;
    }

    /**
     * GS2認証署名を設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2RequestSign GS2認証署名
     */
    UpdateCounterMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateCounterMasterRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }

    virtual const Char* getModuleName() const
    {
        return MODULE;
    }

    virtual const Char* getFunctionName() const
    {
        return FUNCTION;
    }
};

} }

#endif //GS2_LIMIT_CONTROL_UPDATECOUNTERMASTERREQUEST_HPP_