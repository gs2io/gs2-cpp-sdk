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

#ifndef GS2_MONEY_CONTROL_GETWALLETDETAILREQUEST_HPP_
#define GS2_MONEY_CONTROL_GETWALLETDETAILREQUEST_HPP_

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
class GetWalletDetailRequest : public Gs2BasicRequest, public Gs2Money
{
public:
    constexpr static const Char* const FUNCTION = "GetWalletDetail";

private:
    class Data : public Gs2Object
    {
    public:
        /** 取得する課金通貨の名前 */
        optional<StringHolder> moneyName;
        /** 取得するウォレットのスロット番号 */
        optional<Int32> slot;
        /** ユーザID */
        optional<StringHolder> userId;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            moneyName(data.moneyName),
            slot(data.slot),
            userId(data.userId)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            moneyName(std::move(data.moneyName)),
            slot(std::move(data.slot)),
            userId(std::move(data.userId))
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
    GetWalletDetailRequest() :
        m_pData(nullptr)
    {}

    GetWalletDetailRequest(const GetWalletDetailRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Money(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    GetWalletDetailRequest(GetWalletDetailRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Money(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~GetWalletDetailRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetWalletDetailRequest& operator=(const GetWalletDetailRequest& getWalletDetailRequest)
    {
        Gs2BasicRequest::operator=(getWalletDetailRequest);
        Gs2Money::operator=(getWalletDetailRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getWalletDetailRequest.m_pData);

        return *this;
    }

    GetWalletDetailRequest& operator=(GetWalletDetailRequest&& getWalletDetailRequest)
    {
        Gs2BasicRequest::operator=(std::move(getWalletDetailRequest));
        Gs2Money::operator=(std::move(getWalletDetailRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getWalletDetailRequest.m_pData;
        getWalletDetailRequest.m_pData = nullptr;

        return *this;
    }

    const GetWalletDetailRequest* operator->() const
    {
        return this;
    }

    GetWalletDetailRequest* operator->()
    {
        return this;
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
    GetWalletDetailRequest& withMoneyName(const Char* moneyName)
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
    GetWalletDetailRequest& withSlot(Int32 slot)
    {
        ensureData().slot.emplace(slot);
        return *this;
    }

    /**
     * ユーザIDを取得
     *
     * @return ユーザID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザIDを設定
     *
     * @param userId ユーザID
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * ユーザIDを設定
     *
     * @param userId ユーザID
     */
    GetWalletDetailRequest& withUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    GetWalletDetailRequest& withGs2ClientId(const Char* gs2ClientId)
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
    GetWalletDetailRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    GetWalletDetailRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetWalletDetailRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_MONEY_CONTROL_GETWALLETDETAILREQUEST_HPP_