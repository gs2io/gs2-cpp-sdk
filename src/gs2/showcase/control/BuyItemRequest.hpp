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

#ifndef GS2_SHOWCASE_CONTROL_BUYITEMREQUEST_HPP_
#define GS2_SHOWCASE_CONTROL_BUYITEMREQUEST_HPP_

#include <gs2/core/control/Gs2UserRequest.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ShowcaseConst.hpp"

namespace gs2 { namespace showcase {

/**
 * @author Game Server Services, Inc.
 */
class BuyItemRequest : public Gs2UserRequest, public Gs2Showcase
{
public:
    constexpr static const Char* const FUNCTION = "BuyItem";

private:
    class Data : public Gs2Object
    {
    public:
        /** ショーケースの名前 */
        optional<StringHolder> showcaseName;
        /** 陳列商品のID */
        optional<StringHolder> showcaseItemId;
        /** スタンプシートの暗号化に使う GS2-Key 暗号鍵名 */
        optional<StringHolder> keyName;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            showcaseName(data.showcaseName),
            showcaseItemId(data.showcaseItemId),
            keyName(data.keyName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            showcaseName(std::move(data.showcaseName)),
            showcaseItemId(std::move(data.showcaseItemId)),
            keyName(std::move(data.keyName))
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
    BuyItemRequest() :
        m_pData(nullptr)
    {}

    BuyItemRequest(const BuyItemRequest& obj) :
        Gs2UserRequest(obj),
        Gs2Showcase(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    BuyItemRequest(BuyItemRequest&& obj) :
        Gs2UserRequest(std::move(obj)),
        Gs2Showcase(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~BuyItemRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    BuyItemRequest& operator=(const BuyItemRequest& buyItemRequest)
    {
        Gs2UserRequest::operator=(buyItemRequest);
        Gs2Showcase::operator=(buyItemRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*buyItemRequest.m_pData);

        return *this;
    }

    BuyItemRequest& operator=(BuyItemRequest&& buyItemRequest)
    {
        Gs2UserRequest::operator=(std::move(buyItemRequest));
        Gs2Showcase::operator=(std::move(buyItemRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = buyItemRequest.m_pData;
        buyItemRequest.m_pData = nullptr;

        return *this;
    }

    /**
     * ショーケースの名前を取得
     *
     * @return ショーケースの名前
     */
    const optional<StringHolder>& getShowcaseName() const
    {
        return ensureData().showcaseName;
    }

    /**
     * ショーケースの名前を設定
     *
     * @param showcaseName ショーケースの名前
     */
    void setShowcaseName(const Char* showcaseName)
    {
        ensureData().showcaseName.emplace(showcaseName);
    }

    /**
     * ショーケースの名前を設定
     *
     * @param showcaseName ショーケースの名前
     */
    BuyItemRequest& withShowcaseName(const Char* showcaseName)
    {
        ensureData().showcaseName.emplace(showcaseName);
        return *this;
    }

    /**
     * 陳列商品のIDを取得
     *
     * @return 陳列商品のID
     */
    const optional<StringHolder>& getShowcaseItemId() const
    {
        return ensureData().showcaseItemId;
    }

    /**
     * 陳列商品のIDを設定
     *
     * @param showcaseItemId 陳列商品のID
     */
    void setShowcaseItemId(const Char* showcaseItemId)
    {
        ensureData().showcaseItemId.emplace(showcaseItemId);
    }

    /**
     * 陳列商品のIDを設定
     *
     * @param showcaseItemId 陳列商品のID
     */
    BuyItemRequest& withShowcaseItemId(const Char* showcaseItemId)
    {
        ensureData().showcaseItemId.emplace(showcaseItemId);
        return *this;
    }

    /**
     * スタンプシートの暗号化に使う GS2-Key 暗号鍵名を取得
     *
     * @return スタンプシートの暗号化に使う GS2-Key 暗号鍵名
     */
    const optional<StringHolder>& getKeyName() const
    {
        return ensureData().keyName;
    }

    /**
     * スタンプシートの暗号化に使う GS2-Key 暗号鍵名を設定
     *
     * @param keyName スタンプシートの暗号化に使う GS2-Key 暗号鍵名
     */
    void setKeyName(const Char* keyName)
    {
        ensureData().keyName.emplace(keyName);
    }

    /**
     * スタンプシートの暗号化に使う GS2-Key 暗号鍵名を設定
     *
     * @param keyName スタンプシートの暗号化に使う GS2-Key 暗号鍵名
     */
    BuyItemRequest& withKeyName(const Char* keyName)
    {
        ensureData().keyName.emplace(keyName);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    BuyItemRequest& withGs2ClientId(const Char* gs2ClientId)
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
    BuyItemRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    BuyItemRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    BuyItemRequest& withRequestId(const Char* gs2RequestId)
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
    BuyItemRequest& withAccessToken(const Char* accessToken) {
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

#endif //GS2_SHOWCASE_CONTROL_BUYITEMREQUEST_HPP_