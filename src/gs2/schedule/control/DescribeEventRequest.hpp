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

#ifndef GS2_SCHEDULE_CONTROL_DESCRIBEEVENTREQUEST_HPP_
#define GS2_SCHEDULE_CONTROL_DESCRIBEEVENTREQUEST_HPP_

#include <gs2/core/control/Gs2UserRequest.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ScheduleConst.hpp"

namespace gs2 { namespace schedule {

/**
 * @author Game Server Services, Inc.
 */
class DescribeEventRequest : public Gs2UserRequest, public Gs2Schedule
{
public:
    constexpr static const Char* const FUNCTION = "DescribeEvent";

private:
    class Data : public Gs2Object
    {
    public:
        /** スケジュールの名前を指定します。 */
        optional<StringHolder> scheduleName;
        /** 取得するイベント名のリスト */
        optional<List<StringHolder>> eventNames;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            scheduleName(data.scheduleName),
            eventNames(data.eventNames)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            scheduleName(std::move(data.scheduleName)),
            eventNames(std::move(data.eventNames))
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
    DescribeEventRequest() :
        m_pData(nullptr)
    {}

    DescribeEventRequest(const DescribeEventRequest& obj) :
        Gs2UserRequest(obj),
        Gs2Schedule(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    DescribeEventRequest(DescribeEventRequest&& obj) :
        Gs2UserRequest(std::move(obj)),
        Gs2Schedule(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~DescribeEventRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DescribeEventRequest& operator=(const DescribeEventRequest& describeEventRequest)
    {
        Gs2UserRequest::operator=(describeEventRequest);
        Gs2Schedule::operator=(describeEventRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*describeEventRequest.m_pData);

        return *this;
    }

    DescribeEventRequest& operator=(DescribeEventRequest&& describeEventRequest)
    {
        Gs2UserRequest::operator=(std::move(describeEventRequest));
        Gs2Schedule::operator=(std::move(describeEventRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = describeEventRequest.m_pData;
        describeEventRequest.m_pData = nullptr;

        return *this;
    }

    /**
     * スケジュールの名前を指定します。を取得
     *
     * @return スケジュールの名前を指定します。
     */
    const optional<StringHolder>& getScheduleName() const
    {
        return ensureData().scheduleName;
    }

    /**
     * スケジュールの名前を指定します。を設定
     *
     * @param scheduleName スケジュールの名前を指定します。
     */
    void setScheduleName(const Char* scheduleName)
    {
        ensureData().scheduleName.emplace(scheduleName);
    }

    /**
     * スケジュールの名前を指定します。を設定
     *
     * @param scheduleName スケジュールの名前を指定します。
     */
    DescribeEventRequest& withScheduleName(const Char* scheduleName)
    {
        ensureData().scheduleName.emplace(scheduleName);
        return *this;
    }

    /**
     * 取得するイベント名のリストを取得
     *
     * @return 取得するイベント名のリスト
     */
    const optional<List<StringHolder>>& getEventNames() const
    {
        return ensureData().eventNames;
    }

    /**
     * 取得するイベント名のリストを設定
     *
     * @param eventNames 取得するイベント名のリスト
     */
    void setEventNames(const List<StringHolder>& eventNames)
    {
        ensureData().eventNames.emplace(eventNames);
    }

    /**
     * 取得するイベント名のリストを設定
     *
     * @param eventNames 取得するイベント名のリスト
     */
    DescribeEventRequest& withEventNames(const List<StringHolder>& eventNames)
    {
        ensureData().eventNames.emplace(eventNames);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DescribeEventRequest& withGs2ClientId(const Char* gs2ClientId)
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
    DescribeEventRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    DescribeEventRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DescribeEventRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }

    /**
     * アクセストークンを設定。
     *
     * @param accessToken アクセストークン
     * @return this
     */
    DescribeEventRequest& withAccessToken(const Char* accessToken) {
        setAccessToken(accessToken);
        return *this;
    }

    virtual const Char* getModuleName() const
    {
        return MODULE;
    }

    const Char* getFunctionName() const
    {
        return FUNCTION;
    }
};

} }

#endif //GS2_SCHEDULE_CONTROL_DESCRIBEEVENTREQUEST_HPP_