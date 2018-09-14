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

#ifndef GS2_LIMIT_CONTROL_UPCOUNTERBYSTAMPTASKREQUEST_HPP_
#define GS2_LIMIT_CONTROL_UPCOUNTERBYSTAMPTASKREQUEST_HPP_

#include <gs2/core/control/Gs2UserRequest.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2LimitConst.hpp"

namespace gs2 { namespace limit {

/**
 * @author Game Server Services, Inc.
 */
class UpCounterByStampTaskRequest : public Gs2UserRequest, public Gs2Limit
{
public:
    constexpr static const Char* const FUNCTION = "UpCounterByStampTask";

private:
    class Data : public Gs2Object
    {
    public:
        /** スタンプタスク */
        optional<StringHolder> task;
        /** スタンプの暗号鍵 */
        optional<StringHolder> keyName;
        /** トランザクションID */
        optional<StringHolder> transactionId;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            task(data.task),
            keyName(data.keyName),
            transactionId(data.transactionId)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            task(std::move(data.task)),
            keyName(std::move(data.keyName)),
            transactionId(std::move(data.transactionId))
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
    UpCounterByStampTaskRequest() :
        m_pData(nullptr)
    {}

    UpCounterByStampTaskRequest(const UpCounterByStampTaskRequest& obj) :
        Gs2UserRequest(obj),
        Gs2Limit(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpCounterByStampTaskRequest(UpCounterByStampTaskRequest&& obj) :
        Gs2UserRequest(std::move(obj)),
        Gs2Limit(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpCounterByStampTaskRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpCounterByStampTaskRequest& operator=(const UpCounterByStampTaskRequest& upCounterByStampTaskRequest)
    {
        Gs2UserRequest::operator=(upCounterByStampTaskRequest);
        Gs2Limit::operator=(upCounterByStampTaskRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*upCounterByStampTaskRequest.m_pData);

        return *this;
    }

    UpCounterByStampTaskRequest& operator=(UpCounterByStampTaskRequest&& upCounterByStampTaskRequest)
    {
        Gs2UserRequest::operator=(std::move(upCounterByStampTaskRequest));
        Gs2Limit::operator=(std::move(upCounterByStampTaskRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = upCounterByStampTaskRequest.m_pData;
        upCounterByStampTaskRequest.m_pData = nullptr;

        return *this;
    }

    /**
     * スタンプタスクを取得
     *
     * @return スタンプタスク
     */
    const optional<StringHolder>& getTask() const
    {
        return ensureData().task;
    }

    /**
     * スタンプタスクを設定
     *
     * @param task スタンプタスク
     */
    void setTask(const Char* task)
    {
        ensureData().task.emplace(task);
    }

    /**
     * スタンプタスクを設定
     *
     * @param task スタンプタスク
     */
    UpCounterByStampTaskRequest& withTask(const Char* task)
    {
        ensureData().task.emplace(task);
        return *this;
    }

    /**
     * スタンプの暗号鍵を取得
     *
     * @return スタンプの暗号鍵
     */
    const optional<StringHolder>& getKeyName() const
    {
        return ensureData().keyName;
    }

    /**
     * スタンプの暗号鍵を設定
     *
     * @param keyName スタンプの暗号鍵
     */
    void setKeyName(const Char* keyName)
    {
        ensureData().keyName.emplace(keyName);
    }

    /**
     * スタンプの暗号鍵を設定
     *
     * @param keyName スタンプの暗号鍵
     */
    UpCounterByStampTaskRequest& withKeyName(const Char* keyName)
    {
        ensureData().keyName.emplace(keyName);
        return *this;
    }

    /**
     * トランザクションIDを取得
     *
     * @return トランザクションID
     */
    const optional<StringHolder>& getTransactionId() const
    {
        return ensureData().transactionId;
    }

    /**
     * トランザクションIDを設定
     *
     * @param transactionId トランザクションID
     */
    void setTransactionId(const Char* transactionId)
    {
        ensureData().transactionId.emplace(transactionId);
    }

    /**
     * トランザクションIDを設定
     *
     * @param transactionId トランザクションID
     */
    UpCounterByStampTaskRequest& withTransactionId(const Char* transactionId)
    {
        ensureData().transactionId.emplace(transactionId);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpCounterByStampTaskRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpCounterByStampTaskRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpCounterByStampTaskRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpCounterByStampTaskRequest& withRequestId(const Char* gs2RequestId)
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
    UpCounterByStampTaskRequest& withAccessToken(const Char* accessToken) {
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

#endif //GS2_LIMIT_CONTROL_UPCOUNTERBYSTAMPTASKREQUEST_HPP_