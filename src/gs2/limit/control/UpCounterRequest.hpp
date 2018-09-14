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

#ifndef GS2_LIMIT_CONTROL_UPCOUNTERREQUEST_HPP_
#define GS2_LIMIT_CONTROL_UPCOUNTERREQUEST_HPP_

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
class UpCounterRequest : public Gs2BasicRequest, public Gs2Limit
{
public:
    constexpr static const Char* const FUNCTION = "UpCounter";

private:
    class Data : public Gs2Object
    {
    public:
        /** 回数制限の名前を指定します。 */
        optional<StringHolder> limitName;
        /** ユーザIDを指定します。 */
        optional<StringHolder> userId;
        /** カウンターの名前を指定します。 */
        optional<StringHolder> counterName;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            limitName(data.limitName),
            userId(data.userId),
            counterName(data.counterName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            limitName(std::move(data.limitName)),
            userId(std::move(data.userId)),
            counterName(std::move(data.counterName))
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
    UpCounterRequest() :
        m_pData(nullptr)
    {}

    UpCounterRequest(const UpCounterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Limit(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpCounterRequest(UpCounterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Limit(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpCounterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpCounterRequest& operator=(const UpCounterRequest& upCounterRequest)
    {
        Gs2BasicRequest::operator=(upCounterRequest);
        Gs2Limit::operator=(upCounterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*upCounterRequest.m_pData);

        return *this;
    }

    UpCounterRequest& operator=(UpCounterRequest&& upCounterRequest)
    {
        Gs2BasicRequest::operator=(std::move(upCounterRequest));
        Gs2Limit::operator=(std::move(upCounterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = upCounterRequest.m_pData;
        upCounterRequest.m_pData = nullptr;

        return *this;
    }

    const UpCounterRequest* operator->() const
    {
        return this;
    }

    UpCounterRequest* operator->()
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
    UpCounterRequest& withLimitName(const Char* limitName)
    {
        ensureData().limitName.emplace(limitName);
        return *this;
    }

    /**
     * ユーザIDを指定します。を取得
     *
     * @return ユーザIDを指定します。
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザIDを指定します。を設定
     *
     * @param userId ユーザIDを指定します。
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * ユーザIDを指定します。を設定
     *
     * @param userId ユーザIDを指定します。
     */
    UpCounterRequest& withUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
        return *this;
    }

    /**
     * カウンターの名前を指定します。を取得
     *
     * @return カウンターの名前を指定します。
     */
    const optional<StringHolder>& getCounterName() const
    {
        return ensureData().counterName;
    }

    /**
     * カウンターの名前を指定します。を設定
     *
     * @param counterName カウンターの名前を指定します。
     */
    void setCounterName(const Char* counterName)
    {
        ensureData().counterName.emplace(counterName);
    }

    /**
     * カウンターの名前を指定します。を設定
     *
     * @param counterName カウンターの名前を指定します。
     */
    UpCounterRequest& withCounterName(const Char* counterName)
    {
        ensureData().counterName.emplace(counterName);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpCounterRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpCounterRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpCounterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpCounterRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_LIMIT_CONTROL_UPCOUNTERREQUEST_HPP_