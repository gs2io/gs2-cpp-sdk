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

#ifndef GS2_GOLD_CONTROL_WITHDRAWFROMWALLETBYSTAMPTASKREQUEST_HPP_
#define GS2_GOLD_CONTROL_WITHDRAWFROMWALLETBYSTAMPTASKREQUEST_HPP_

#include <gs2/core/control/Gs2UserRequest.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2GoldConst.hpp"

namespace gs2 { namespace gold {

/**
 * @author Game Server Services, Inc.
 */
class WithdrawFromWalletByStampTaskRequest : public Gs2UserRequest, public Gs2Gold
{
public:
    constexpr static const Char* const FUNCTION = "WithdrawFromWalletByStampTask";

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
    WithdrawFromWalletByStampTaskRequest() :
        m_pData(nullptr)
    {}

    WithdrawFromWalletByStampTaskRequest(const WithdrawFromWalletByStampTaskRequest& obj) :
        Gs2UserRequest(obj),
        Gs2Gold(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    WithdrawFromWalletByStampTaskRequest(WithdrawFromWalletByStampTaskRequest&& obj) :
        Gs2UserRequest(std::move(obj)),
        Gs2Gold(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~WithdrawFromWalletByStampTaskRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    WithdrawFromWalletByStampTaskRequest& operator=(const WithdrawFromWalletByStampTaskRequest& withdrawFromWalletByStampTaskRequest)
    {
        Gs2UserRequest::operator=(withdrawFromWalletByStampTaskRequest);
        Gs2Gold::operator=(withdrawFromWalletByStampTaskRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*withdrawFromWalletByStampTaskRequest.m_pData);

        return *this;
    }

    WithdrawFromWalletByStampTaskRequest& operator=(WithdrawFromWalletByStampTaskRequest&& withdrawFromWalletByStampTaskRequest)
    {
        Gs2UserRequest::operator=(std::move(withdrawFromWalletByStampTaskRequest));
        Gs2Gold::operator=(std::move(withdrawFromWalletByStampTaskRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = withdrawFromWalletByStampTaskRequest.m_pData;
        withdrawFromWalletByStampTaskRequest.m_pData = nullptr;

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
    WithdrawFromWalletByStampTaskRequest& withTask(const Char* task)
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
    WithdrawFromWalletByStampTaskRequest& withKeyName(const Char* keyName)
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
    WithdrawFromWalletByStampTaskRequest& withTransactionId(const Char* transactionId)
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
    WithdrawFromWalletByStampTaskRequest& withGs2ClientId(const Char* gs2ClientId)
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
    WithdrawFromWalletByStampTaskRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    WithdrawFromWalletByStampTaskRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    WithdrawFromWalletByStampTaskRequest& withRequestId(const Char* gs2RequestId)
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
    WithdrawFromWalletByStampTaskRequest& withAccessToken(const Char* accessToken) {
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

#endif //GS2_GOLD_CONTROL_WITHDRAWFROMWALLETBYSTAMPTASKREQUEST_HPP_