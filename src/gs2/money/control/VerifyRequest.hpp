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

#ifndef GS2_MONEY_CONTROL_VERIFYREQUEST_HPP_
#define GS2_MONEY_CONTROL_VERIFYREQUEST_HPP_

#include <gs2/core/control/Gs2UserRequest.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2MoneyConst.hpp"

namespace gs2 { namespace money {

/**
 * @author Game Server Services, Inc.
 */
class VerifyRequest : public Gs2UserRequest, public Gs2Money
{
public:
    constexpr static const Char* const FUNCTION = "Verify";

private:
    class Data : public Gs2Object
    {
    public:
        /** 課金通貨の名前 */
        optional<StringHolder> moneyName;
        /** スロット番号 */
        optional<Int32> slot;
        /** レシートデータ */
        optional<StringHolder> receipt;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            moneyName(data.moneyName),
            slot(data.slot),
            receipt(data.receipt)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            moneyName(std::move(data.moneyName)),
            slot(std::move(data.slot)),
            receipt(std::move(data.receipt))
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
    VerifyRequest() :
        m_pData(nullptr)
    {}

    VerifyRequest(const VerifyRequest& obj) :
        Gs2UserRequest(obj),
        Gs2Money(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    VerifyRequest(VerifyRequest&& obj) :
        Gs2UserRequest(std::move(obj)),
        Gs2Money(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~VerifyRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    VerifyRequest& operator=(const VerifyRequest& verifyRequest)
    {
        Gs2UserRequest::operator=(verifyRequest);
        Gs2Money::operator=(verifyRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*verifyRequest.m_pData);

        return *this;
    }

    VerifyRequest& operator=(VerifyRequest&& verifyRequest)
    {
        Gs2UserRequest::operator=(std::move(verifyRequest));
        Gs2Money::operator=(std::move(verifyRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = verifyRequest.m_pData;
        verifyRequest.m_pData = nullptr;

        return *this;
    }

    /**
     * 課金通貨の名前を取得
     *
     * @return 課金通貨の名前
     */
    const optional<StringHolder>& getMoneyName() const
    {
        return ensureData().moneyName;
    }

    /**
     * 課金通貨の名前を設定
     *
     * @param moneyName 課金通貨の名前
     */
    void setMoneyName(const Char* moneyName)
    {
        ensureData().moneyName.emplace(moneyName);
    }

    /**
     * 課金通貨の名前を設定
     *
     * @param moneyName 課金通貨の名前
     */
    VerifyRequest& withMoneyName(const Char* moneyName)
    {
        ensureData().moneyName.emplace(moneyName);
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
    VerifyRequest& withSlot(Int32 slot)
    {
        ensureData().slot.emplace(slot);
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
    VerifyRequest& withReceipt(const Char* receipt)
    {
        ensureData().receipt.emplace(receipt);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    VerifyRequest& withGs2ClientId(const Char* gs2ClientId)
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
    VerifyRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    VerifyRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    VerifyRequest& withRequestId(const Char* gs2RequestId)
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
    VerifyRequest& withAccessToken(const Char* accessToken) {
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

#endif //GS2_MONEY_CONTROL_VERIFYREQUEST_HPP_