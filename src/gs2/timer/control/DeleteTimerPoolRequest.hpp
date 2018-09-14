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

#ifndef GS2_TIMER_CONTROL_DELETETIMERPOOLREQUEST_HPP_
#define GS2_TIMER_CONTROL_DELETETIMERPOOLREQUEST_HPP_

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
class DeleteTimerPoolRequest : public Gs2BasicRequest, public Gs2Timer
{
public:
    constexpr static const Char* const FUNCTION = "DeleteTimerPool";

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
    DeleteTimerPoolRequest() :
        m_pData(nullptr)
    {}

    DeleteTimerPoolRequest(const DeleteTimerPoolRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Timer(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    DeleteTimerPoolRequest(DeleteTimerPoolRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Timer(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~DeleteTimerPoolRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DeleteTimerPoolRequest& operator=(const DeleteTimerPoolRequest& deleteTimerPoolRequest)
    {
        Gs2BasicRequest::operator=(deleteTimerPoolRequest);
        Gs2Timer::operator=(deleteTimerPoolRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*deleteTimerPoolRequest.m_pData);

        return *this;
    }

    DeleteTimerPoolRequest& operator=(DeleteTimerPoolRequest&& deleteTimerPoolRequest)
    {
        Gs2BasicRequest::operator=(std::move(deleteTimerPoolRequest));
        Gs2Timer::operator=(std::move(deleteTimerPoolRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = deleteTimerPoolRequest.m_pData;
        deleteTimerPoolRequest.m_pData = nullptr;

        return *this;
    }

    const DeleteTimerPoolRequest* operator->() const
    {
        return this;
    }

    DeleteTimerPoolRequest* operator->()
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
    DeleteTimerPoolRequest& withTimerPoolName(const Char* timerPoolName)
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
    DeleteTimerPoolRequest& withGs2ClientId(const Char* gs2ClientId)
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
    DeleteTimerPoolRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    DeleteTimerPoolRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DeleteTimerPoolRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_TIMER_CONTROL_DELETETIMERPOOLREQUEST_HPP_