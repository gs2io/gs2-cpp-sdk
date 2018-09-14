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

#ifndef GS2_TIMER_CONTROL_GETTIMERPOOLREQUEST_HPP_
#define GS2_TIMER_CONTROL_GETTIMERPOOLREQUEST_HPP_

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
class GetTimerPoolRequest : public Gs2BasicRequest, public Gs2Timer
{
public:
    constexpr static const Char* const FUNCTION = "GetTimerPool";

private:
    class Data : public Gs2Object
    {
    public:
        /** タイマープールの名前を指定します。 */
        optional<StringHolder> timerPoolName;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            timerPoolName(data.timerPoolName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            timerPoolName(std::move(data.timerPoolName))
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
    GetTimerPoolRequest() :
        m_pData(nullptr)
    {}

    GetTimerPoolRequest(const GetTimerPoolRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Timer(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    GetTimerPoolRequest(GetTimerPoolRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Timer(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~GetTimerPoolRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetTimerPoolRequest& operator=(const GetTimerPoolRequest& getTimerPoolRequest)
    {
        Gs2BasicRequest::operator=(getTimerPoolRequest);
        Gs2Timer::operator=(getTimerPoolRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getTimerPoolRequest.m_pData);

        return *this;
    }

    GetTimerPoolRequest& operator=(GetTimerPoolRequest&& getTimerPoolRequest)
    {
        Gs2BasicRequest::operator=(std::move(getTimerPoolRequest));
        Gs2Timer::operator=(std::move(getTimerPoolRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getTimerPoolRequest.m_pData;
        getTimerPoolRequest.m_pData = nullptr;

        return *this;
    }

    const GetTimerPoolRequest* operator->() const
    {
        return this;
    }

    GetTimerPoolRequest* operator->()
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
    GetTimerPoolRequest& withTimerPoolName(const Char* timerPoolName)
    {
        ensureData().timerPoolName.emplace(timerPoolName);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    GetTimerPoolRequest& withGs2ClientId(const Char* gs2ClientId)
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
    GetTimerPoolRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    GetTimerPoolRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetTimerPoolRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_TIMER_CONTROL_GETTIMERPOOLREQUEST_HPP_