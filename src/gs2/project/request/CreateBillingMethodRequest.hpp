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

#ifndef GS2_PROJECT_CONTROL_CREATEBILLINGMETHODREQUEST_HPP_
#define GS2_PROJECT_CONTROL_CREATEBILLINGMETHODREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/project/Gs2ProjectConst.hpp>
#include <gs2/project/model/model.hpp>
#include <memory>

namespace gs2 { namespace project
{

/**
 * 支払い方法を新規作成 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateBillingMethodRequest : public Gs2BasicRequest, public Gs2Project
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** GS2アカウントトークン */
        optional<StringHolder> accountToken;
        /** 名前 */
        optional<StringHolder> description;
        /** 支払い方法 */
        optional<StringHolder> methodType;
        /** クレジットカードカスタマーID */
        optional<StringHolder> cardCustomerId;
        /** パートナーID */
        optional<StringHolder> partnerId;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            accountToken(data.accountToken),
            description(data.description),
            methodType(data.methodType),
            cardCustomerId(data.cardCustomerId),
            partnerId(data.partnerId)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

    Gs2BasicRequest::Data& getData_() GS2_OVERRIDE
    {
        return ensureData();
    }

    const Gs2BasicRequest::Data& getData_() const GS2_OVERRIDE
    {
        return ensureData();
    }

public:
    CreateBillingMethodRequest() = default;
    CreateBillingMethodRequest(const CreateBillingMethodRequest& createBillingMethodRequest) = default;
    CreateBillingMethodRequest(CreateBillingMethodRequest&& createBillingMethodRequest) = default;
    ~CreateBillingMethodRequest() GS2_OVERRIDE = default;

    CreateBillingMethodRequest& operator=(const CreateBillingMethodRequest& createBillingMethodRequest) = default;
    CreateBillingMethodRequest& operator=(CreateBillingMethodRequest&& createBillingMethodRequest) = default;

    CreateBillingMethodRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CreateBillingMethodRequest);
    }

    const CreateBillingMethodRequest* operator->() const
    {
        return this;
    }

    CreateBillingMethodRequest* operator->()
    {
        return this;
    }

    /**
     * GS2アカウントトークンを取得
     *
     * @return GS2アカウントトークン
     */
    const optional<StringHolder>& getAccountToken() const
    {
        return ensureData().accountToken;
    }

    /**
     * GS2アカウントトークンを設定
     *
     * @param accountToken GS2アカウントトークン
     */
    void setAccountToken(StringHolder accountToken)
    {
        ensureData().accountToken.emplace(std::move(accountToken));
    }

    /**
     * GS2アカウントトークンを設定
     *
     * @param accountToken GS2アカウントトークン
     */
    CreateBillingMethodRequest& withAccountToken(StringHolder accountToken)
    {
        ensureData().accountToken.emplace(std::move(accountToken));
        return *this;
    }

    /**
     * 名前を取得
     *
     * @return 名前
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 名前を設定
     *
     * @param description 名前
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * 名前を設定
     *
     * @param description 名前
     */
    CreateBillingMethodRequest& withDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
        return *this;
    }

    /**
     * 支払い方法を取得
     *
     * @return 支払い方法
     */
    const optional<StringHolder>& getMethodType() const
    {
        return ensureData().methodType;
    }

    /**
     * 支払い方法を設定
     *
     * @param methodType 支払い方法
     */
    void setMethodType(StringHolder methodType)
    {
        ensureData().methodType.emplace(std::move(methodType));
    }

    /**
     * 支払い方法を設定
     *
     * @param methodType 支払い方法
     */
    CreateBillingMethodRequest& withMethodType(StringHolder methodType)
    {
        ensureData().methodType.emplace(std::move(methodType));
        return *this;
    }

    /**
     * クレジットカードカスタマーIDを取得
     *
     * @return クレジットカードカスタマーID
     */
    const optional<StringHolder>& getCardCustomerId() const
    {
        return ensureData().cardCustomerId;
    }

    /**
     * クレジットカードカスタマーIDを設定
     *
     * @param cardCustomerId クレジットカードカスタマーID
     */
    void setCardCustomerId(StringHolder cardCustomerId)
    {
        ensureData().cardCustomerId.emplace(std::move(cardCustomerId));
    }

    /**
     * クレジットカードカスタマーIDを設定
     *
     * @param cardCustomerId クレジットカードカスタマーID
     */
    CreateBillingMethodRequest& withCardCustomerId(StringHolder cardCustomerId)
    {
        ensureData().cardCustomerId.emplace(std::move(cardCustomerId));
        return *this;
    }

    /**
     * パートナーIDを取得
     *
     * @return パートナーID
     */
    const optional<StringHolder>& getPartnerId() const
    {
        return ensureData().partnerId;
    }

    /**
     * パートナーIDを設定
     *
     * @param partnerId パートナーID
     */
    void setPartnerId(StringHolder partnerId)
    {
        ensureData().partnerId.emplace(std::move(partnerId));
    }

    /**
     * パートナーIDを設定
     *
     * @param partnerId パートナーID
     */
    CreateBillingMethodRequest& withPartnerId(StringHolder partnerId)
    {
        ensureData().partnerId.emplace(std::move(partnerId));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreateBillingMethodRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateBillingMethodRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_PROJECT_CONTROL_CREATEBILLINGMETHODREQUEST_HPP_