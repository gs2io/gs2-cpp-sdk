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

#ifndef GS2_TIMER_CONTROL_DELETETIMERREQUEST_HPP_
#define GS2_TIMER_CONTROL_DELETETIMERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2TimerConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace timer
{

/**
 * @author Game Server Services, Inc.
 */
class DeleteTimerRequest : public Gs2BasicRequest, public Gs2Timer
{
public:
    constexpr static const Char* const FUNCTION = "DeleteTimer";

private:
    class Data : public Gs2Object
    {
    public:
        /** タイマープールの名前を指定します。 */
        optional<StringHolder> timerPoolName;
        /** タイマーIDを指定します。 */
        optional<StringHolder> timerId;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            timerPoolName(data.timerPoolName),
            timerId(data.timerId)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            timerPoolName(std::move(data.timerPoolName)),
            timerId(std::move(data.timerId))
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
    DeleteTimerRequest() :
        m_pData(nullptr)
    {}

    DeleteTimerRequest(const DeleteTimerRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Timer(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    DeleteTimerRequest(DeleteTimerRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Timer(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~DeleteTimerRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DeleteTimerRequest& operator=(const DeleteTimerRequest& deleteTimerRequest)
    {
        Gs2BasicRequest::operator=(deleteTimerRequest);
        Gs2Timer::operator=(deleteTimerRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*deleteTimerRequest.m_pData);

        return *this;
    }

    DeleteTimerRequest& operator=(DeleteTimerRequest&& deleteTimerRequest)
    {
        Gs2BasicRequest::operator=(std::move(deleteTimerRequest));
        Gs2Timer::operator=(std::move(deleteTimerRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = deleteTimerRequest.m_pData;
        deleteTimerRequest.m_pData = nullptr;

        return *this;
    }

    const DeleteTimerRequest* operator->() const
    {
        return this;
    }

    DeleteTimerRequest* operator->()
    {
        return this;
    }

    /**
     * タイマープールの名前を指定します。を取得
     *
     * @return タイマープールの名前を指定します。
     */
    const optional<StringHolder>& getTimerPoolName() const
    {
        return ensureData().timerPoolName;
    }

    /**
     * タイマープールの名前を指定します。を設定
     *
     * @param timerPoolName タイマープールの名前を指定します。
     */
    void setTimerPoolName(const Char* timerPoolName)
    {
        ensureData().timerPoolName.emplace(timerPoolName);
    }

    /**
     * タイマープールの名前を指定します。を設定
     *
     * @param timerPoolName タイマープールの名前を指定します。
     */
    DeleteTimerRequest& withTimerPoolName(const Char* timerPoolName)
    {
        ensureData().timerPoolName.emplace(timerPoolName);
        return *this;
    }

    /**
     * タイマーIDを指定します。を取得
     *
     * @return タイマーIDを指定します。
     */
    const optional<StringHolder>& getTimerId() const
    {
        return ensureData().timerId;
    }

    /**
     * タイマーIDを指定します。を設定
     *
     * @param timerId タイマーIDを指定します。
     */
    void setTimerId(const Char* timerId)
    {
        ensureData().timerId.emplace(timerId);
    }

    /**
     * タイマーIDを指定します。を設定
     *
     * @param timerId タイマーIDを指定します。
     */
    DeleteTimerRequest& withTimerId(const Char* timerId)
    {
        ensureData().timerId.emplace(timerId);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DeleteTimerRequest& withGs2ClientId(const Char* gs2ClientId)
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
    DeleteTimerRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    DeleteTimerRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DeleteTimerRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_TIMER_CONTROL_DELETETIMERREQUEST_HPP_