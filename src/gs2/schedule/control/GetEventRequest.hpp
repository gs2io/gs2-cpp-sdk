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

#ifndef GS2_SCHEDULE_CONTROL_GETEVENTREQUEST_HPP_
#define GS2_SCHEDULE_CONTROL_GETEVENTREQUEST_HPP_

#include <gs2/core/control/Gs2UserRequest.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ScheduleConst.hpp"

namespace gs2 { namespace schedule {

/**
 * @author Game Server Services, Inc.
 */
class GetEventRequest : public Gs2UserRequest, public Gs2Schedule
{
public:
    constexpr static const Char* const FUNCTION = "GetEvent";

private:
    class Data : public Gs2Object
    {
    public:
        /** スケジュールの名前を指定します。 */
        optional<StringHolder> scheduleName;
        /** イベント名を指定します。 */
        optional<StringHolder> eventName;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            scheduleName(data.scheduleName),
            eventName(data.eventName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            scheduleName(std::move(data.scheduleName)),
            eventName(std::move(data.eventName))
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
    GetEventRequest() :
        m_pData(nullptr)
    {}

    GetEventRequest(const GetEventRequest& obj) :
        Gs2UserRequest(obj),
        Gs2Schedule(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    GetEventRequest(GetEventRequest&& obj) :
        Gs2UserRequest(std::move(obj)),
        Gs2Schedule(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~GetEventRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetEventRequest& operator=(const GetEventRequest& getEventRequest)
    {
        Gs2UserRequest::operator=(getEventRequest);
        Gs2Schedule::operator=(getEventRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getEventRequest.m_pData);

        return *this;
    }

    GetEventRequest& operator=(GetEventRequest&& getEventRequest)
    {
        Gs2UserRequest::operator=(std::move(getEventRequest));
        Gs2Schedule::operator=(std::move(getEventRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getEventRequest.m_pData;
        getEventRequest.m_pData = nullptr;

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
    GetEventRequest& withScheduleName(const Char* scheduleName)
    {
        ensureData().scheduleName.emplace(scheduleName);
        return *this;
    }

    /**
     * イベント名を指定します。を取得
     *
     * @return イベント名を指定します。
     */
    const optional<StringHolder>& getEventName() const
    {
        return ensureData().eventName;
    }

    /**
     * イベント名を指定します。を設定
     *
     * @param eventName イベント名を指定します。
     */
    void setEventName(const Char* eventName)
    {
        ensureData().eventName.emplace(eventName);
    }

    /**
     * イベント名を指定します。を設定
     *
     * @param eventName イベント名を指定します。
     */
    GetEventRequest& withEventName(const Char* eventName)
    {
        ensureData().eventName.emplace(eventName);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    GetEventRequest& withGs2ClientId(const Char* gs2ClientId)
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
    GetEventRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    GetEventRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetEventRequest& withRequestId(const Char* gs2RequestId)
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
    GetEventRequest& withAccessToken(const Char* accessToken) {
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

#endif //GS2_SCHEDULE_CONTROL_GETEVENTREQUEST_HPP_