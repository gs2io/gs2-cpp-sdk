/*
 * Copyright 2016 Game Server Services, Inc. or its affiliates. All Rights
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

#ifndef GS2_MONEY_CONTROL_WITHDRAWREQUEST_HPP_
#define GS2_MONEY_CONTROL_WITHDRAWREQUEST_HPP_

#include <gs2/core/control/Gs2UserRequest.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2MoneyConst.hpp"

namespace gs2 { namespace money
{

/**
 * ウォレットの概要から残高を消費します のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class WithdrawRequest : public Gs2UserRequest, public Gs2Money
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** 課金通貨の名前 */
        optional<StringHolder> moneyName;
        /** None */
        optional<Int32> slot;
        /** 消費する課金通貨の数量 */
        optional<Int32> count;
        /** 有償課金通貨のみを対象とするか */
        optional<Bool> paidOnly;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            moneyName(data.moneyName),
            slot(data.slot),
            count(data.count),
            paidOnly(data.paidOnly),
            duplicationAvoider(data.duplicationAvoider)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            moneyName(std::move(data.moneyName)),
            slot(std::move(data.slot)),
            count(std::move(data.count)),
            paidOnly(std::move(data.paidOnly)),
            duplicationAvoider(std::move(data.duplicationAvoider))
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
    WithdrawRequest() :
        m_pData(nullptr)
    {}

    WithdrawRequest(const WithdrawRequest& obj) :
        Gs2UserRequest(obj),
        Gs2Money(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    WithdrawRequest(WithdrawRequest&& obj) :
        Gs2UserRequest(std::move(obj)),
        Gs2Money(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~WithdrawRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    WithdrawRequest& operator=(const WithdrawRequest& withdrawRequest)
    {
        Gs2UserRequest::operator=(withdrawRequest);
        Gs2Money::operator=(withdrawRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*withdrawRequest.m_pData);

        return *this;
    }

    WithdrawRequest& operator=(WithdrawRequest&& withdrawRequest)
    {
        Gs2UserRequest::operator=(std::move(withdrawRequest));
        Gs2Money::operator=(std::move(withdrawRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = withdrawRequest.m_pData;
        withdrawRequest.m_pData = nullptr;

        return *this;
    }

    const WithdrawRequest* operator->() const
    {
        return this;
    }

    WithdrawRequest* operator->()
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
    WithdrawRequest& withMoneyName(const Char* moneyName)
    {
        ensureData().moneyName.emplace(moneyName);
        return *this;
    }

    /**
     * Noneを取得
     *
     * @return None
     */
    const optional<Int32>& getSlot() const
    {
        return ensureData().slot;
    }

    /**
     * Noneを設定
     *
     * @param slot None
     */
    void setSlot(Int32 slot)
    {
        ensureData().slot.emplace(slot);
    }

    /**
     * Noneを設定
     *
     * @param slot None
     */
    WithdrawRequest& withSlot(Int32 slot)
    {
        ensureData().slot.emplace(slot);
        return *this;
    }

    /**
     * 消費する課金通貨の数量を取得
     *
     * @return 消費する課金通貨の数量
     */
    const optional<Int32>& getCount() const
    {
        return ensureData().count;
    }

    /**
     * 消費する課金通貨の数量を設定
     *
     * @param count 消費する課金通貨の数量
     */
    void setCount(Int32 count)
    {
        ensureData().count.emplace(count);
    }

    /**
     * 消費する課金通貨の数量を設定
     *
     * @param count 消費する課金通貨の数量
     */
    WithdrawRequest& withCount(Int32 count)
    {
        ensureData().count.emplace(count);
        return *this;
    }

    /**
     * 有償課金通貨のみを対象とするかを取得
     *
     * @return 有償課金通貨のみを対象とするか
     */
    const optional<Bool>& getPaidOnly() const
    {
        return ensureData().paidOnly;
    }

    /**
     * 有償課金通貨のみを対象とするかを設定
     *
     * @param paidOnly 有償課金通貨のみを対象とするか
     */
    void setPaidOnly(Bool paidOnly)
    {
        ensureData().paidOnly.emplace(paidOnly);
    }

    /**
     * 有償課金通貨のみを対象とするかを設定
     *
     * @param paidOnly 有償課金通貨のみを対象とするか
     */
    WithdrawRequest& withPaidOnly(Bool paidOnly)
    {
        ensureData().paidOnly.emplace(paidOnly);
        return *this;
    }

    /**
     * 重複実行回避機能に使用するIDを取得
     *
     * @return 重複実行回避機能に使用するID
     */
    const optional<StringHolder>& getDuplicationAvoider() const
    {
        return ensureData().duplicationAvoider;
    }

    /**
     * 重複実行回避機能に使用するIDを設定
     *
     * @param duplicationAvoider 重複実行回避機能に使用するID
     */
    void setDuplicationAvoider(const Char* duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(duplicationAvoider);
    }

    /**
     * 重複実行回避機能に使用するIDを設定
     *
     * @param duplicationAvoider 重複実行回避機能に使用するID
     */
    WithdrawRequest& withDuplicationAvoider(const Char* duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(duplicationAvoider);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    WithdrawRequest& withGs2ClientId(const Char* gs2ClientId)
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
    WithdrawRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    WithdrawRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    WithdrawRequest& withRequestId(const Char* gs2RequestId)
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
    WithdrawRequest& withAccessToken(const Char* accessToken) {
        setAccessToken(accessToken);
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

#endif //GS2_MONEY_CONTROL_WITHDRAWREQUEST_HPP_