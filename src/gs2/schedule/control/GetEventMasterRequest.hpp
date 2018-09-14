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

#ifndef GS2_SCHEDULE_CONTROL_GETEVENTMASTERREQUEST_HPP_
#define GS2_SCHEDULE_CONTROL_GETEVENTMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ScheduleConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace schedule
{

/**
 * @author Game Server Services, Inc.
 */
class GetEventMasterRequest : public Gs2BasicRequest, public Gs2Schedule
{
public:
    constexpr static const Char* const FUNCTION = "GetEventMaster";

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
    GetEventMasterRequest() :
        m_pData(nullptr)
    {}

    GetEventMasterRequest(const GetEventMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Schedule(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    GetEventMasterRequest(GetEventMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Schedule(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~GetEventMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetEventMasterRequest& operator=(const GetEventMasterRequest& getEventMasterRequest)
    {
        Gs2BasicRequest::operator=(getEventMasterRequest);
        Gs2Schedule::operator=(getEventMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getEventMasterRequest.m_pData);

        return *this;
    }

    GetEventMasterRequest& operator=(GetEventMasterRequest&& getEventMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(getEventMasterRequest));
        Gs2Schedule::operator=(std::move(getEventMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getEventMasterRequest.m_pData;
        getEventMasterRequest.m_pData = nullptr;

        return *this;
    }

    const GetEventMasterRequest* operator->() const
    {
        return this;
    }

    GetEventMasterRequest* operator->()
    {
        return this;
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
    GetEventMasterRequest& withScheduleName(const Char* scheduleName)
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
    GetEventMasterRequest& withEventName(const Char* eventName)
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
    GetEventMasterRequest& withGs2ClientId(const Char* gs2ClientId)
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
    GetEventMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    GetEventMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetEventMasterRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_SCHEDULE_CONTROL_GETEVENTMASTERREQUEST_HPP_