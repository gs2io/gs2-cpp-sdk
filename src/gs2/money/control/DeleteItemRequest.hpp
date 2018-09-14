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

#ifndef GS2_MONEY_CONTROL_DELETEITEMREQUEST_HPP_
#define GS2_MONEY_CONTROL_DELETEITEMREQUEST_HPP_

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
class DeleteItemRequest : public Gs2BasicRequest, public Gs2Money
{
public:
    constexpr static const Char* const FUNCTION = "DeleteItem";

private:
    class Data : public Gs2Object
    {
    public:
        /** 課金通貨の名前 */
        optional<StringHolder> moneyName;
        /** 商品の名前 */
        optional<StringHolder> itemName;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            moneyName(data.moneyName),
            itemName(data.itemName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            moneyName(std::move(data.moneyName)),
            itemName(std::move(data.itemName))
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
    DeleteItemRequest() :
        m_pData(nullptr)
    {}

    DeleteItemRequest(const DeleteItemRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Money(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    DeleteItemRequest(DeleteItemRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Money(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~DeleteItemRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DeleteItemRequest& operator=(const DeleteItemRequest& deleteItemRequest)
    {
        Gs2BasicRequest::operator=(deleteItemRequest);
        Gs2Money::operator=(deleteItemRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*deleteItemRequest.m_pData);

        return *this;
    }

    DeleteItemRequest& operator=(DeleteItemRequest&& deleteItemRequest)
    {
        Gs2BasicRequest::operator=(std::move(deleteItemRequest));
        Gs2Money::operator=(std::move(deleteItemRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = deleteItemRequest.m_pData;
        deleteItemRequest.m_pData = nullptr;

        return *this;
    }

    const DeleteItemRequest* operator->() const
    {
        return this;
    }

    DeleteItemRequest* operator->()
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
    DeleteItemRequest& withMoneyName(const Char* moneyName)
    {
        ensureData().moneyName.emplace(moneyName);
        return *this;
    }

    /**
     * 商品の名前を取得
     *
     * @return 商品の名前
     */
    const optional<StringHolder>& getItemName() const
    {
        return ensureData().itemName;
    }

    /**
     * 商品の名前を設定
     *
     * @param itemName 商品の名前
     */
    void setItemName(const Char* itemName)
    {
        ensureData().itemName.emplace(itemName);
    }

    /**
     * 商品の名前を設定
     *
     * @param itemName 商品の名前
     */
    DeleteItemRequest& withItemName(const Char* itemName)
    {
        ensureData().itemName.emplace(itemName);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DeleteItemRequest& withGs2ClientId(const Char* gs2ClientId)
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
    DeleteItemRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    DeleteItemRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DeleteItemRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_MONEY_CONTROL_DELETEITEMREQUEST_HPP_