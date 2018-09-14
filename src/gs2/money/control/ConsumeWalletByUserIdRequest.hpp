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

#ifndef GS2_MONEY_CONTROL_CONSUMEWALLETBYUSERIDREQUEST_HPP_
#define GS2_MONEY_CONTROL_CONSUMEWALLETBYUSERIDREQUEST_HPP_

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
class ConsumeWalletByUserIdRequest : public Gs2BasicRequest, public Gs2Money
{
public:
    constexpr static const Char* const FUNCTION = "ConsumeWalletByUserId";

private:
    class Data : public Gs2Object
    {
    public:
        /** 取得する課金通貨の名前 */
        optional<StringHolder> moneyName;
        /** 取得するウォレットのスロット番号 */
        optional<Int32> slot;
        /** ウォレットのユーザID */
        optional<StringHolder> userId;
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
            userId(data.userId),
            count(data.count),
            use(data.use),
            paidOnly(data.paidOnly)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            moneyName(std::move(data.moneyName)),
            slot(std::move(data.slot)),
            userId(std::move(data.userId)),
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
    ConsumeWalletByUserIdRequest() :
        m_pData(nullptr)
    {}

    ConsumeWalletByUserIdRequest(const ConsumeWalletByUserIdRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Money(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    ConsumeWalletByUserIdRequest(ConsumeWalletByUserIdRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Money(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~ConsumeWalletByUserIdRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    ConsumeWalletByUserIdRequest& operator=(const ConsumeWalletByUserIdRequest& consumeWalletByUserIdRequest)
    {
        Gs2BasicRequest::operator=(consumeWalletByUserIdRequest);
        Gs2Money::operator=(consumeWalletByUserIdRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*consumeWalletByUserIdRequest.m_pData);

        return *this;
    }

    ConsumeWalletByUserIdRequest& operator=(ConsumeWalletByUserIdRequest&& consumeWalletByUserIdRequest)
    {
        Gs2BasicRequest::operator=(std::move(consumeWalletByUserIdRequest));
        Gs2Money::operator=(std::move(consumeWalletByUserIdRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = consumeWalletByUserIdRequest.m_pData;
        consumeWalletByUserIdRequest.m_pData = nullptr;

        return *this;
    }

    const ConsumeWalletByUserIdRequest* operator->() const
    {
        return this;
    }

    ConsumeWalletByUserIdRequest* operator->()
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
    ConsumeWalletByUserIdRequest& withMoneyName(const Char* moneyName)
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
    ConsumeWalletByUserIdRequest& withSlot(Int32 slot)
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
    ConsumeWalletByUserIdRequest& withUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
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
    ConsumeWalletByUserIdRequest& withCount(Int32 count)
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
    ConsumeWalletByUserIdRequest& withUse(Int32 use)
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
    ConsumeWalletByUserIdRequest& withPaidOnly(Bool paidOnly)
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
    ConsumeWalletByUserIdRequest& withGs2ClientId(const Char* gs2ClientId)
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
    ConsumeWalletByUserIdRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    ConsumeWalletByUserIdRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    ConsumeWalletByUserIdRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_MONEY_CONTROL_CONSUMEWALLETBYUSERIDREQUEST_HPP_