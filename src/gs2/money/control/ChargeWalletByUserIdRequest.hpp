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

#ifndef GS2_MONEY_CONTROL_CHARGEWALLETBYUSERIDREQUEST_HPP_
#define GS2_MONEY_CONTROL_CHARGEWALLETBYUSERIDREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2MoneyConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace money
{

/**
 * @author Game Server Services, Inc.
 */
class ChargeWalletByUserIdRequest : public Gs2BasicRequest, public Gs2Money
{
public:
    constexpr static const Char* const FUNCTION = "ChargeWalletByUserId";

private:
    class Data : public Gs2Object
    {
    public:
        /** 課金通貨の名前 */
        optional<StringHolder> moneyName;
        /** ウォレットのスロット番号 */
        optional<Int32> slot;
        /** ウォレットのユーザID */
        optional<StringHolder> userId;
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
            userId(data.userId),
            price(data.price),
            count(data.count),
            transactionId(data.transactionId)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            moneyName(std::move(data.moneyName)),
            slot(std::move(data.slot)),
            userId(std::move(data.userId)),
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
    ChargeWalletByUserIdRequest() :
        m_pData(nullptr)
    {}

    ChargeWalletByUserIdRequest(const ChargeWalletByUserIdRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Money(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    ChargeWalletByUserIdRequest(ChargeWalletByUserIdRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Money(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~ChargeWalletByUserIdRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    ChargeWalletByUserIdRequest& operator=(const ChargeWalletByUserIdRequest& chargeWalletByUserIdRequest)
    {
        Gs2BasicRequest::operator=(chargeWalletByUserIdRequest);
        Gs2Money::operator=(chargeWalletByUserIdRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*chargeWalletByUserIdRequest.m_pData);

        return *this;
    }

    ChargeWalletByUserIdRequest& operator=(ChargeWalletByUserIdRequest&& chargeWalletByUserIdRequest)
    {
        Gs2BasicRequest::operator=(std::move(chargeWalletByUserIdRequest));
        Gs2Money::operator=(std::move(chargeWalletByUserIdRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = chargeWalletByUserIdRequest.m_pData;
        chargeWalletByUserIdRequest.m_pData = nullptr;

        return *this;
    }

    const ChargeWalletByUserIdRequest* operator->() const
    {
        return this;
    }

    ChargeWalletByUserIdRequest* operator->()
    {
        return this;
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
    ChargeWalletByUserIdRequest& withMoneyName(const Char* moneyName)
    {
        ensureData().moneyName.emplace(moneyName);
        return *this;
    }

    /**
     * ウォレットのスロット番号を取得
     *
     * @return ウォレットのスロット番号
     */
    const optional<Int32>& getSlot() const
    {
        return ensureData().slot;
    }

    /**
     * ウォレットのスロット番号を設定
     *
     * @param slot ウォレットのスロット番号
     */
    void setSlot(Int32 slot)
    {
        ensureData().slot.emplace(slot);
    }

    /**
     * ウォレットのスロット番号を設定
     *
     * @param slot ウォレットのスロット番号
     */
    ChargeWalletByUserIdRequest& withSlot(Int32 slot)
    {
        ensureData().slot.emplace(slot);
        return *this;
    }

    /**
     * ウォレットのユーザIDを取得
     *
     * @return ウォレットのユーザID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ウォレットのユーザIDを設定
     *
     * @param userId ウォレットのユーザID
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * ウォレットのユーザIDを設定
     *
     * @param userId ウォレットのユーザID
     */
    ChargeWalletByUserIdRequest& withUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
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
    ChargeWalletByUserIdRequest& withPrice(Double price)
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
    ChargeWalletByUserIdRequest& withCount(Int32 count)
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
    ChargeWalletByUserIdRequest& withTransactionId(const Char* transactionId)
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
    ChargeWalletByUserIdRequest& withGs2ClientId(const Char* gs2ClientId)
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
    ChargeWalletByUserIdRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    ChargeWalletByUserIdRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    ChargeWalletByUserIdRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_MONEY_CONTROL_CHARGEWALLETBYUSERIDREQUEST_HPP_