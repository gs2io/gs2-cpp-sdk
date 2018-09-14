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

#ifndef GS2_MONEY_CONTROL_CHARGEWALLETREQUEST_HPP_
#define GS2_MONEY_CONTROL_CHARGEWALLETREQUEST_HPP_

#include <gs2/core/control/Gs2UserRequest.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2MoneyConst.hpp"

namespace gs2 { namespace money {

/**
 * @author Game Server Services, Inc.
 */
class ChargeWalletRequest : public Gs2UserRequest, public Gs2Money
{
public:
    constexpr static const Char* const FUNCTION = "ChargeWallet";

private:
    class Data : public Gs2Object
    {
    public:
        /** 取得する課金通貨の名前 */
        optional<StringHolder> moneyName;
        /** 取得するウォレットのスロット番号 */
        optional<Int32> slot;
        /** 支払金額 */
        optional<Double> price;
        /** 課金通貨付与量 */
        optional<Int32> count;
        /** トランザクションID */
        optional<StringHolder> transactionId;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            moneyName(data.moneyName),
            slot(data.slot),
            price(data.price),
            count(data.count),
            transactionId(data.transactionId)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            moneyName(std::move(data.moneyName)),
            slot(std::move(data.slot)),
            price(std::move(data.price)),
            count(std::move(data.count)),
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
    ChargeWalletRequest() :
        m_pData(nullptr)
    {}

    ChargeWalletRequest(const ChargeWalletRequest& obj) :
        Gs2UserRequest(obj),
        Gs2Money(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    ChargeWalletRequest(ChargeWalletRequest&& obj) :
        Gs2UserRequest(std::move(obj)),
        Gs2Money(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~ChargeWalletRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    ChargeWalletRequest& operator=(const ChargeWalletRequest& chargeWalletRequest)
    {
        Gs2UserRequest::operator=(chargeWalletRequest);
        Gs2Money::operator=(chargeWalletRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*chargeWalletRequest.m_pData);

        return *this;
    }

    ChargeWalletRequest& operator=(ChargeWalletRequest&& chargeWalletRequest)
    {
        Gs2UserRequest::operator=(std::move(chargeWalletRequest));
        Gs2Money::operator=(std::move(chargeWalletRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = chargeWalletRequest.m_pData;
        chargeWalletRequest.m_pData = nullptr;

        return *this;
    }

    /**
     * 取得する課金通貨の名前を取得
     *
     * @return 取得する課金通貨の名前
     */
    const optional<StringHolder>& getMoneyName() const
    {
        return ensureData().moneyName;
    }

    /**
     * 取得する課金通貨の名前を設定
     *
     * @param moneyName 取得する課金通貨の名前
     */
    void setMoneyName(const Char* moneyName)
    {
        ensureData().moneyName.emplace(moneyName);
    }

    /**
     * 取得する課金通貨の名前を設定
     *
     * @param moneyName 取得する課金通貨の名前
     */
    ChargeWalletRequest& withMoneyName(const Char* moneyName)
    {
        ensureData().moneyName.emplace(moneyName);
        return *this;
    }

    /**
     * 取得するウォレットのスロット番号を取得
     *
     * @return 取得するウォレットのスロット番号
     */
    const optional<Int32>& getSlot() const
    {
        return ensureData().slot;
    }

    /**
     * 取得するウォレットのスロット番号を設定
     *
     * @param slot 取得するウォレットのスロット番号
     */
    void setSlot(Int32 slot)
    {
        ensureData().slot.emplace(slot);
    }

    /**
     * 取得するウォレットのスロット番号を設定
     *
     * @param slot 取得するウォレットのスロット番号
     */
    ChargeWalletRequest& withSlot(Int32 slot)
    {
        ensureData().slot.emplace(slot);
        return *this;
    }

    /**
     * 支払金額を取得
     *
     * @return 支払金額
     */
    const optional<Double>& getPrice() const
    {
        return ensureData().price;
    }

    /**
     * 支払金額を設定
     *
     * @param price 支払金額
     */
    void setPrice(Double price)
    {
        ensureData().price.emplace(price);
    }

    /**
     * 支払金額を設定
     *
     * @param price 支払金額
     */
    ChargeWalletRequest& withPrice(Double price)
    {
        ensureData().price.emplace(price);
        return *this;
    }

    /**
     * 課金通貨付与量を取得
     *
     * @return 課金通貨付与量
     */
    const optional<Int32>& getCount() const
    {
        return ensureData().count;
    }

    /**
     * 課金通貨付与量を設定
     *
     * @param count 課金通貨付与量
     */
    void setCount(Int32 count)
    {
        ensureData().count.emplace(count);
    }

    /**
     * 課金通貨付与量を設定
     *
     * @param count 課金通貨付与量
     */
    ChargeWalletRequest& withCount(Int32 count)
    {
        ensureData().count.emplace(count);
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
    ChargeWalletRequest& withTransactionId(const Char* transactionId)
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
    ChargeWalletRequest& withGs2ClientId(const Char* gs2ClientId)
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
    ChargeWalletRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    ChargeWalletRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    ChargeWalletRequest& withRequestId(const Char* gs2RequestId)
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
    ChargeWalletRequest& withAccessToken(const Char* accessToken) {
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

#endif //GS2_MONEY_CONTROL_CHARGEWALLETREQUEST_HPP_