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

#ifndef GS2_MONEY_CONTROL_DELETEPLATFORMEDITEMREQUEST_HPP_
#define GS2_MONEY_CONTROL_DELETEPLATFORMEDITEMREQUEST_HPP_

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
class DeletePlatformedItemRequest : public Gs2BasicRequest, public Gs2Money
{
public:
    constexpr static const Char* const FUNCTION = "DeletePlatformedItem";

private:
    class Data : public Gs2Object
    {
    public:
        /** 課金通貨の名前 */
        optional<StringHolder> moneyName;
        /** 商品の名前 */
        optional<StringHolder> itemName;
        /** プラットフォームの名前 */
        optional<StringHolder> platform;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            moneyName(data.moneyName),
            itemName(data.itemName),
            platform(data.platform)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            moneyName(std::move(data.moneyName)),
            itemName(std::move(data.itemName)),
            platform(std::move(data.platform))
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
    DeletePlatformedItemRequest() :
        m_pData(nullptr)
    {}

    DeletePlatformedItemRequest(const DeletePlatformedItemRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Money(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    DeletePlatformedItemRequest(DeletePlatformedItemRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Money(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~DeletePlatformedItemRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DeletePlatformedItemRequest& operator=(const DeletePlatformedItemRequest& deletePlatformedItemRequest)
    {
        Gs2BasicRequest::operator=(deletePlatformedItemRequest);
        Gs2Money::operator=(deletePlatformedItemRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*deletePlatformedItemRequest.m_pData);

        return *this;
    }

    DeletePlatformedItemRequest& operator=(DeletePlatformedItemRequest&& deletePlatformedItemRequest)
    {
        Gs2BasicRequest::operator=(std::move(deletePlatformedItemRequest));
        Gs2Money::operator=(std::move(deletePlatformedItemRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = deletePlatformedItemRequest.m_pData;
        deletePlatformedItemRequest.m_pData = nullptr;

        return *this;
    }

    const DeletePlatformedItemRequest* operator->() const
    {
        return this;
    }

    DeletePlatformedItemRequest* operator->()
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
    DeletePlatformedItemRequest& withMoneyName(const Char* moneyName)
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
    DeletePlatformedItemRequest& withItemName(const Char* itemName)
    {
        ensureData().itemName.emplace(itemName);
        return *this;
    }

    /**
     * プラットフォームの名前を取得
     *
     * @return プラットフォームの名前
     */
    const optional<StringHolder>& getPlatform() const
    {
        return ensureData().platform;
    }

    /**
     * プラットフォームの名前を設定
     *
     * @param platform プラットフォームの名前
     */
    void setPlatform(const Char* platform)
    {
        ensureData().platform.emplace(platform);
    }

    /**
     * プラットフォームの名前を設定
     *
     * @param platform プラットフォームの名前
     */
    DeletePlatformedItemRequest& withPlatform(const Char* platform)
    {
        ensureData().platform.emplace(platform);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DeletePlatformedItemRequest& withGs2ClientId(const Char* gs2ClientId)
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
    DeletePlatformedItemRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    DeletePlatformedItemRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DeletePlatformedItemRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_MONEY_CONTROL_DELETEPLATFORMEDITEMREQUEST_HPP_