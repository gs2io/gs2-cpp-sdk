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

#ifndef GS2_MONEY_CONTROL_CREATEPLATFORMEDITEMREQUEST_HPP_
#define GS2_MONEY_CONTROL_CREATEPLATFORMEDITEMREQUEST_HPP_

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
class CreatePlatformedItemRequest : public Gs2BasicRequest, public Gs2Money
{
public:
    constexpr static const Char* const FUNCTION = "CreatePlatformedItem";

private:
    class Data : public Gs2Object
    {
    public:
        /** 課金通貨の名前 */
        optional<StringHolder> moneyName;
        /** 商品の名前 */
        optional<StringHolder> itemName;
        /** 販売プラットフォーム */
        optional<StringHolder> platform;
        /** アプリ内課金ID */
        optional<StringHolder> name;
        /** 販売価格 */
        optional<Double> price;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            moneyName(data.moneyName),
            itemName(data.itemName),
            platform(data.platform),
            name(data.name),
            price(data.price)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            moneyName(std::move(data.moneyName)),
            itemName(std::move(data.itemName)),
            platform(std::move(data.platform)),
            name(std::move(data.name)),
            price(std::move(data.price))
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
    CreatePlatformedItemRequest() :
        m_pData(nullptr)
    {}

    CreatePlatformedItemRequest(const CreatePlatformedItemRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Money(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CreatePlatformedItemRequest(CreatePlatformedItemRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Money(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CreatePlatformedItemRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreatePlatformedItemRequest& operator=(const CreatePlatformedItemRequest& createPlatformedItemRequest)
    {
        Gs2BasicRequest::operator=(createPlatformedItemRequest);
        Gs2Money::operator=(createPlatformedItemRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createPlatformedItemRequest.m_pData);

        return *this;
    }

    CreatePlatformedItemRequest& operator=(CreatePlatformedItemRequest&& createPlatformedItemRequest)
    {
        Gs2BasicRequest::operator=(std::move(createPlatformedItemRequest));
        Gs2Money::operator=(std::move(createPlatformedItemRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createPlatformedItemRequest.m_pData;
        createPlatformedItemRequest.m_pData = nullptr;

        return *this;
    }

    const CreatePlatformedItemRequest* operator->() const
    {
        return this;
    }

    CreatePlatformedItemRequest* operator->()
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
    CreatePlatformedItemRequest& withMoneyName(const Char* moneyName)
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
    CreatePlatformedItemRequest& withItemName(const Char* itemName)
    {
        ensureData().itemName.emplace(itemName);
        return *this;
    }

    /**
     * 販売プラットフォームを取得
     *
     * @return 販売プラットフォーム
     */
    const optional<StringHolder>& getPlatform() const
    {
        return ensureData().platform;
    }

    /**
     * 販売プラットフォームを設定
     *
     * @param platform 販売プラットフォーム
     */
    void setPlatform(const Char* platform)
    {
        ensureData().platform.emplace(platform);
    }

    /**
     * 販売プラットフォームを設定
     *
     * @param platform 販売プラットフォーム
     */
    CreatePlatformedItemRequest& withPlatform(const Char* platform)
    {
        ensureData().platform.emplace(platform);
        return *this;
    }

    /**
     * アプリ内課金IDを取得
     *
     * @return アプリ内課金ID
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * アプリ内課金IDを設定
     *
     * @param name アプリ内課金ID
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * アプリ内課金IDを設定
     *
     * @param name アプリ内課金ID
     */
    CreatePlatformedItemRequest& withName(const Char* name)
    {
        ensureData().name.emplace(name);
        return *this;
    }

    /**
     * 販売価格を取得
     *
     * @return 販売価格
     */
    const optional<Double>& getPrice() const
    {
        return ensureData().price;
    }

    /**
     * 販売価格を設定
     *
     * @param price 販売価格
     */
    void setPrice(Double price)
    {
        ensureData().price.emplace(price);
    }

    /**
     * 販売価格を設定
     *
     * @param price 販売価格
     */
    CreatePlatformedItemRequest& withPrice(Double price)
    {
        ensureData().price.emplace(price);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreatePlatformedItemRequest& withGs2ClientId(const Char* gs2ClientId)
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
    CreatePlatformedItemRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    CreatePlatformedItemRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreatePlatformedItemRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_MONEY_CONTROL_CREATEPLATFORMEDITEMREQUEST_HPP_