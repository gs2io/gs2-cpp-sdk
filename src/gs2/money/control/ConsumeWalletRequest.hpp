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

#ifndef GS2_MONEY_CONTROL_CONSUMEWALLETREQUEST_HPP_
#define GS2_MONEY_CONTROL_CONSUMEWALLETREQUEST_HPP_

#include <gs2/core/control/Gs2UserRequest.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2MoneyConst.hpp"

namespace gs2 { namespace money {

/**
 * @author Game Server Services, Inc.
 */
class ConsumeWalletRequest : public Gs2UserRequest, public Gs2Money
{
public:
    constexpr static const Char* const FUNCTION = "ConsumeWallet";

private:
    class Data : public Gs2Object
    {
    public:
        /** 取得する課金通貨の名前 */
        optional<StringHolder> moneyName;
        /** 取得するウォレットのスロット番号 */
        optional<Int32> slot;
        /** 課金通貨消費量 */
        optional<Int32> count;
        /** 用途ID */
        optional<Int32> use;
        /** 有償課金通貨のみ消費対象としたい場合に true を指定します */
        optional<Bool> paidOnly;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            moneyName(data.moneyName),
            slot(data.slot),
            count(data.count),
            use(data.use),
            paidOnly(data.paidOnly)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            moneyName(std::move(data.moneyName)),
            slot(std::move(data.slot)),
            count(std::move(data.count)),
            use(std::move(data.use)),
            paidOnly(std::move(data.paidOnly))
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
    ConsumeWalletRequest() :
        m_pData(nullptr)
    {}

    ConsumeWalletRequest(const ConsumeWalletRequest& obj) :
        Gs2UserRequest(obj),
        Gs2Money(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    ConsumeWalletRequest(ConsumeWalletRequest&& obj) :
        Gs2UserRequest(std::move(obj)),
        Gs2Money(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~ConsumeWalletRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    ConsumeWalletRequest& operator=(const ConsumeWalletRequest& consumeWalletRequest)
    {
        Gs2UserRequest::operator=(consumeWalletRequest);
        Gs2Money::operator=(consumeWalletRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*consumeWalletRequest.m_pData);

        return *this;
    }

    ConsumeWalletRequest& operator=(ConsumeWalletRequest&& consumeWalletRequest)
    {
        Gs2UserRequest::operator=(std::move(consumeWalletRequest));
        Gs2Money::operator=(std::move(consumeWalletRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = consumeWalletRequest.m_pData;
        consumeWalletRequest.m_pData = nullptr;

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
    ConsumeWalletRequest& withMoneyName(const Char* moneyName)
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
    ConsumeWalletRequest& withSlot(Int32 slot)
    {
        ensureData().slot.emplace(slot);
        return *this;
    }

    /**
     * 課金通貨消費量を取得
     *
     * @return 課金通貨消費量
     */
    const optional<Int32>& getCount() const
    {
        return ensureData().count;
    }

    /**
     * 課金通貨消費量を設定
     *
     * @param count 課金通貨消費量
     */
    void setCount(Int32 count)
    {
        ensureData().count.emplace(count);
    }

    /**
     * 課金通貨消費量を設定
     *
     * @param count 課金通貨消費量
     */
    ConsumeWalletRequest& withCount(Int32 count)
    {
        ensureData().count.emplace(count);
        return *this;
    }

    /**
     * 用途IDを取得
     *
     * @return 用途ID
     */
    const optional<Int32>& getUse() const
    {
        return ensureData().use;
    }

    /**
     * 用途IDを設定
     *
     * @param use 用途ID
     */
    void setUse(Int32 use)
    {
        ensureData().use.emplace(use);
    }

    /**
     * 用途IDを設定
     *
     * @param use 用途ID
     */
    ConsumeWalletRequest& withUse(Int32 use)
    {
        ensureData().use.emplace(use);
        return *this;
    }

    /**
     * 有償課金通貨のみ消費対象としたい場合に true を指定しますを取得
     *
     * @return 有償課金通貨のみ消費対象としたい場合に true を指定します
     */
    const optional<Bool>& getPaidOnly() const
    {
        return ensureData().paidOnly;
    }

    /**
     * 有償課金通貨のみ消費対象としたい場合に true を指定しますを設定
     *
     * @param paidOnly 有償課金通貨のみ消費対象としたい場合に true を指定します
     */
    void setPaidOnly(Bool paidOnly)
    {
        ensureData().paidOnly.emplace(paidOnly);
    }

    /**
     * 有償課金通貨のみ消費対象としたい場合に true を指定しますを設定
     *
     * @param paidOnly 有償課金通貨のみ消費対象としたい場合に true を指定します
     */
    ConsumeWalletRequest& withPaidOnly(Bool paidOnly)
    {
        ensureData().paidOnly.emplace(paidOnly);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    ConsumeWalletRequest& withGs2ClientId(const Char* gs2ClientId)
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
    ConsumeWalletRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    ConsumeWalletRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    ConsumeWalletRequest& withRequestId(const Char* gs2RequestId)
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
    ConsumeWalletRequest& withAccessToken(const Char* accessToken) {
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

#endif //GS2_MONEY_CONTROL_CONSUMEWALLETREQUEST_HPP_