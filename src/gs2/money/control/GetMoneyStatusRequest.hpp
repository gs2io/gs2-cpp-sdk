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

#ifndef GS2_MONEY_CONTROL_GETMONEYSTATUSREQUEST_HPP_
#define GS2_MONEY_CONTROL_GETMONEYSTATUSREQUEST_HPP_

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
class GetMoneyStatusRequest : public Gs2BasicRequest, public Gs2Money
{
public:
    constexpr static const Char* const FUNCTION = "GetMoneyStatus";

private:
    class Data : public Gs2Object
    {
    public:
        /** 取得する課金通貨の名前 */
        optional<StringHolder> moneyName;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            moneyName(data.moneyName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            moneyName(std::move(data.moneyName))
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
    GetMoneyStatusRequest() :
        m_pData(nullptr)
    {}

    GetMoneyStatusRequest(const GetMoneyStatusRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Money(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    GetMoneyStatusRequest(GetMoneyStatusRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Money(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~GetMoneyStatusRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetMoneyStatusRequest& operator=(const GetMoneyStatusRequest& getMoneyStatusRequest)
    {
        Gs2BasicRequest::operator=(getMoneyStatusRequest);
        Gs2Money::operator=(getMoneyStatusRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getMoneyStatusRequest.m_pData);

        return *this;
    }

    GetMoneyStatusRequest& operator=(GetMoneyStatusRequest&& getMoneyStatusRequest)
    {
        Gs2BasicRequest::operator=(std::move(getMoneyStatusRequest));
        Gs2Money::operator=(std::move(getMoneyStatusRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getMoneyStatusRequest.m_pData;
        getMoneyStatusRequest.m_pData = nullptr;

        return *this;
    }

    const GetMoneyStatusRequest* operator->() const
    {
        return this;
    }

    GetMoneyStatusRequest* operator->()
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
    GetMoneyStatusRequest& withMoneyName(const Char* moneyName)
    {
        ensureData().moneyName.emplace(moneyName);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    GetMoneyStatusRequest& withGs2ClientId(const Char* gs2ClientId)
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
    GetMoneyStatusRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    GetMoneyStatusRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetMoneyStatusRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_MONEY_CONTROL_GETMONEYSTATUSREQUEST_HPP_