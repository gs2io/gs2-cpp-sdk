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

#ifndef GS2_MONEY_CONTROL_GETWALLETREQUEST_HPP_
#define GS2_MONEY_CONTROL_GETWALLETREQUEST_HPP_

#include <gs2/core/control/Gs2UserRequest.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2MoneyConst.hpp"

namespace gs2 { namespace money {

/**
 * @author Game Server Services, Inc.
 */
class GetWalletRequest : public Gs2UserRequest, public Gs2Money
{
public:
    constexpr static const Char* const FUNCTION = "GetWallet";

private:
    class Data : public Gs2Object
    {
    public:
        /** 課金通貨の名前 */
        optional<StringHolder> moneyName;
        /** ウォレットのスロット番号 */
        optional<Int32> slot;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            moneyName(data.moneyName),
            slot(data.slot)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            moneyName(std::move(data.moneyName)),
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
    GetWalletRequest() :
        m_pData(nullptr)
    {}

    GetWalletRequest(const GetWalletRequest& obj) :
        Gs2UserRequest(obj),
        Gs2Money(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    GetWalletRequest(GetWalletRequest&& obj) :
        Gs2UserRequest(std::move(obj)),
        Gs2Money(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~GetWalletRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetWalletRequest& operator=(const GetWalletRequest& getWalletRequest)
    {
        Gs2UserRequest::operator=(getWalletRequest);
        Gs2Money::operator=(getWalletRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getWalletRequest.m_pData);

        return *this;
    }

    GetWalletRequest& operator=(GetWalletRequest&& getWalletRequest)
    {
        Gs2UserRequest::operator=(std::move(getWalletRequest));
        Gs2Money::operator=(std::move(getWalletRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getWalletRequest.m_pData;
        getWalletRequest.m_pData = nullptr;

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
    GetWalletRequest& withMoneyName(const Char* moneyName)
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
    GetWalletRequest& withSlot(Int32 slot)
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
    GetWalletRequest& withGs2ClientId(const Char* gs2ClientId)
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
    GetWalletRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    GetWalletRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetWalletRequest& withRequestId(const Char* gs2RequestId)
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
    GetWalletRequest& withAccessToken(const Char* accessToken) {
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

#endif //GS2_MONEY_CONTROL_GETWALLETREQUEST_HPP_