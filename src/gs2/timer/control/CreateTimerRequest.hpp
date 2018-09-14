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

#ifndef GS2_TIMER_CONTROL_CREATETIMERREQUEST_HPP_
#define GS2_TIMER_CONTROL_CREATETIMERREQUEST_HPP_

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
class CreateTimerRequest : public Gs2BasicRequest, public Gs2Timer
{
public:
    constexpr static const Char* const FUNCTION = "CreateTimer";

private:
    class Data : public Gs2Object
    {
    public:
        /** タイマープールの名前を指定します。 */
        optional<StringHolder> timerPoolName;
        /** コールバックHTTPメソッド */
        optional<StringHolder> callbackMethod;
        /** コールバックURL */
        optional<StringHolder> callbackUrl;
        /** コールバックボディ(PUT/POSTのときのみ有効) */
        optional<StringHolder> callbackBody;
        /** コールバック時間(エポック秒) */
        optional<Int32> executeTime;
        /** 最大リトライ回数 */
        optional<Int32> retryMax;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            timerPoolName(data.timerPoolName),
            callbackMethod(data.callbackMethod),
            callbackUrl(data.callbackUrl),
            callbackBody(data.callbackBody),
            executeTime(data.executeTime),
            retryMax(data.retryMax)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            timerPoolName(std::move(data.timerPoolName)),
            callbackMethod(std::move(data.callbackMethod)),
            callbackUrl(std::move(data.callbackUrl)),
            callbackBody(std::move(data.callbackBody)),
            executeTime(std::move(data.executeTime)),
            retryMax(std::move(data.retryMax))
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
    CreateTimerRequest() :
        m_pData(nullptr)
    {}

    CreateTimerRequest(const CreateTimerRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Timer(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CreateTimerRequest(CreateTimerRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Timer(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CreateTimerRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateTimerRequest& operator=(const CreateTimerRequest& createTimerRequest)
    {
        Gs2BasicRequest::operator=(createTimerRequest);
        Gs2Timer::operator=(createTimerRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createTimerRequest.m_pData);

        return *this;
    }

    CreateTimerRequest& operator=(CreateTimerRequest&& createTimerRequest)
    {
        Gs2BasicRequest::operator=(std::move(createTimerRequest));
        Gs2Timer::operator=(std::move(createTimerRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createTimerRequest.m_pData;
        createTimerRequest.m_pData = nullptr;

        return *this;
    }

    const CreateTimerRequest* operator->() const
    {
        return this;
    }

    CreateTimerRequest* operator->()
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
    CreateTimerRequest& withTimerPoolName(const Char* timerPoolName)
    {
        ensureData().timerPoolName.emplace(timerPoolName);
        return *this;
    }

    /**
     * コールバックHTTPメソッドを取得
     *
     * @return コールバックHTTPメソッド
     */
    const optional<StringHolder>& getCallbackMethod() const
    {
        return ensureData().callbackMethod;
    }

    /**
     * コールバックHTTPメソッドを設定
     *
     * @param callbackMethod コールバックHTTPメソッド
     */
    void setCallbackMethod(const Char* callbackMethod)
    {
        ensureData().callbackMethod.emplace(callbackMethod);
    }

    /**
     * コールバックHTTPメソッドを設定
     *
     * @param callbackMethod コールバックHTTPメソッド
     */
    CreateTimerRequest& withCallbackMethod(const Char* callbackMethod)
    {
        ensureData().callbackMethod.emplace(callbackMethod);
        return *this;
    }

    /**
     * コールバックURLを取得
     *
     * @return コールバックURL
     */
    const optional<StringHolder>& getCallbackUrl() const
    {
        return ensureData().callbackUrl;
    }

    /**
     * コールバックURLを設定
     *
     * @param callbackUrl コールバックURL
     */
    void setCallbackUrl(const Char* callbackUrl)
    {
        ensureData().callbackUrl.emplace(callbackUrl);
    }

    /**
     * コールバックURLを設定
     *
     * @param callbackUrl コールバックURL
     */
    CreateTimerRequest& withCallbackUrl(const Char* callbackUrl)
    {
        ensureData().callbackUrl.emplace(callbackUrl);
        return *this;
    }

    /**
     * コールバックボディ(PUT/POSTのときのみ有効)を取得
     *
     * @return コールバックボディ(PUT/POSTのときのみ有効)
     */
    const optional<StringHolder>& getCallbackBody() const
    {
        return ensureData().callbackBody;
    }

    /**
     * コールバックボディ(PUT/POSTのときのみ有効)を設定
     *
     * @param callbackBody コールバックボディ(PUT/POSTのときのみ有効)
     */
    void setCallbackBody(const Char* callbackBody)
    {
        ensureData().callbackBody.emplace(callbackBody);
    }

    /**
     * コールバックボディ(PUT/POSTのときのみ有効)を設定
     *
     * @param callbackBody コールバックボディ(PUT/POSTのときのみ有効)
     */
    CreateTimerRequest& withCallbackBody(const Char* callbackBody)
    {
        ensureData().callbackBody.emplace(callbackBody);
        return *this;
    }

    /**
     * コールバック時間(エポック秒)を取得
     *
     * @return コールバック時間(エポック秒)
     */
    const optional<Int32>& getExecuteTime() const
    {
        return ensureData().executeTime;
    }

    /**
     * コールバック時間(エポック秒)を設定
     *
     * @param executeTime コールバック時間(エポック秒)
     */
    void setExecuteTime(Int32 executeTime)
    {
        ensureData().executeTime.emplace(executeTime);
    }

    /**
     * コールバック時間(エポック秒)を設定
     *
     * @param executeTime コールバック時間(エポック秒)
     */
    CreateTimerRequest& withExecuteTime(Int32 executeTime)
    {
        ensureData().executeTime.emplace(executeTime);
        return *this;
    }

    /**
     * 最大リトライ回数を取得
     *
     * @return 最大リトライ回数
     */
    const optional<Int32>& getRetryMax() const
    {
        return ensureData().retryMax;
    }

    /**
     * 最大リトライ回数を設定
     *
     * @param retryMax 最大リトライ回数
     */
    void setRetryMax(Int32 retryMax)
    {
        ensureData().retryMax.emplace(retryMax);
    }

    /**
     * 最大リトライ回数を設定
     *
     * @param retryMax 最大リトライ回数
     */
    CreateTimerRequest& withRetryMax(Int32 retryMax)
    {
        ensureData().retryMax.emplace(retryMax);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreateTimerRequest& withGs2ClientId(const Char* gs2ClientId)
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
    CreateTimerRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    CreateTimerRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateTimerRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_TIMER_CONTROL_CREATETIMERREQUEST_HPP_