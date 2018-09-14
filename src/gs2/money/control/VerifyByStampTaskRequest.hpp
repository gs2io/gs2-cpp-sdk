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

#ifndef GS2_MONEY_CONTROL_VERIFYBYSTAMPTASKREQUEST_HPP_
#define GS2_MONEY_CONTROL_VERIFYBYSTAMPTASKREQUEST_HPP_

#include <gs2/core/control/Gs2UserRequest.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2MoneyConst.hpp"

namespace gs2 { namespace money {

/**
 * @author Game Server Services, Inc.
 */
class VerifyByStampTaskRequest : public Gs2UserRequest, public Gs2Money
{
public:
    constexpr static const Char* const FUNCTION = "VerifyByStampTask";

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
        /** レシートデータ */
        optional<StringHolder> receipt;
        /** スロット番号 */
        optional<Int32> slot;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            task(data.task),
            keyName(data.keyName),
            transactionId(data.transactionId),
            receipt(data.receipt),
            slot(data.slot)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            task(std::move(data.task)),
            keyName(std::move(data.keyName)),
            transactionId(std::move(data.transactionId)),
            receipt(std::move(data.receipt)),
            slot(std::move(data.slot))
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
    VerifyByStampTaskRequest() :
        m_pData(nullptr)
    {}

    VerifyByStampTaskRequest(const VerifyByStampTaskRequest& obj) :
        Gs2UserRequest(obj),
        Gs2Money(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    VerifyByStampTaskRequest(VerifyByStampTaskRequest&& obj) :
        Gs2UserRequest(std::move(obj)),
        Gs2Money(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~VerifyByStampTaskRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    VerifyByStampTaskRequest& operator=(const VerifyByStampTaskRequest& verifyByStampTaskRequest)
    {
        Gs2UserRequest::operator=(verifyByStampTaskRequest);
        Gs2Money::operator=(verifyByStampTaskRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*verifyByStampTaskRequest.m_pData);

        return *this;
    }

    VerifyByStampTaskRequest& operator=(VerifyByStampTaskRequest&& verifyByStampTaskRequest)
    {
        Gs2UserRequest::operator=(std::move(verifyByStampTaskRequest));
        Gs2Money::operator=(std::move(verifyByStampTaskRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = verifyByStampTaskRequest.m_pData;
        verifyByStampTaskRequest.m_pData = nullptr;

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
    VerifyByStampTaskRequest& withTask(const Char* task)
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
    VerifyByStampTaskRequest& withKeyName(const Char* keyName)
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
    VerifyByStampTaskRequest& withTransactionId(const Char* transactionId)
    {
        ensureData().transactionId.emplace(transactionId);
        return *this;
    }

    /**
     * レシートデータを取得
     *
     * @return レシートデータ
     */
    const optional<StringHolder>& getReceipt() const
    {
        return ensureData().receipt;
    }

    /**
     * レシートデータを設定
     *
     * @param receipt レシートデータ
     */
    void setReceipt(const Char* receipt)
    {
        ensureData().receipt.emplace(receipt);
    }

    /**
     * レシートデータを設定
     *
     * @param receipt レシートデータ
     */
    VerifyByStampTaskRequest& withReceipt(const Char* receipt)
    {
        ensureData().receipt.emplace(receipt);
        return *this;
    }

    /**
     * スロット番号を取得
     *
     * @return スロット番号
     */
    const optional<Int32>& getSlot() const
    {
        return ensureData().slot;
    }

    /**
     * スロット番号を設定
     *
     * @param slot スロット番号
     */
    void setSlot(Int32 slot)
    {
        ensureData().slot.emplace(slot);
    }

    /**
     * スロット番号を設定
     *
     * @param slot スロット番号
     */
    VerifyByStampTaskRequest& withSlot(Int32 slot)
    {
        ensureData().slot.emplace(slot);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    VerifyByStampTaskRequest& withGs2ClientId(const Char* gs2ClientId)
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
    VerifyByStampTaskRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    VerifyByStampTaskRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    VerifyByStampTaskRequest& withRequestId(const Char* gs2RequestId)
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
    VerifyByStampTaskRequest& withAccessToken(const Char* accessToken) {
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

#endif //GS2_MONEY_CONTROL_VERIFYBYSTAMPTASKREQUEST_HPP_