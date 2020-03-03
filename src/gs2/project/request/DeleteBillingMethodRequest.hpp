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

#ifndef GS2_PROJECT_CONTROL_DELETEBILLINGMETHODREQUEST_HPP_
#define GS2_PROJECT_CONTROL_DELETEBILLINGMETHODREQUEST_HPP_

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
 * 支払い方法を削除 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class DeleteBillingMethodRequest : public Gs2BasicRequest, public Gs2Project
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
        optional<StringHolder> billingMethodName;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            accountToken(data.accountToken),
            billingMethodName(data.billingMethodName)
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
    DeleteBillingMethodRequest() = default;
    DeleteBillingMethodRequest(const DeleteBillingMethodRequest& deleteBillingMethodRequest) = default;
    DeleteBillingMethodRequest(DeleteBillingMethodRequest&& deleteBillingMethodRequest) = default;
    ~DeleteBillingMethodRequest() GS2_OVERRIDE = default;

    DeleteBillingMethodRequest& operator=(const DeleteBillingMethodRequest& deleteBillingMethodRequest) = default;
    DeleteBillingMethodRequest& operator=(DeleteBillingMethodRequest&& deleteBillingMethodRequest) = default;

    DeleteBillingMethodRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DeleteBillingMethodRequest);
    }

    const DeleteBillingMethodRequest* operator->() const
    {
        return this;
    }

    DeleteBillingMethodRequest* operator->()
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
    DeleteBillingMethodRequest& withAccountToken(StringHolder accountToken)
    {
        ensureData().accountToken.emplace(std::move(accountToken));
        return *this;
    }

    /**
     * 名前を取得
     *
     * @return 名前
     */
    const optional<StringHolder>& getBillingMethodName() const
    {
        return ensureData().billingMethodName;
    }

    /**
     * 名前を設定
     *
     * @param billingMethodName 名前
     */
    void setBillingMethodName(StringHolder billingMethodName)
    {
        ensureData().billingMethodName.emplace(std::move(billingMethodName));
    }

    /**
     * 名前を設定
     *
     * @param billingMethodName 名前
     */
    DeleteBillingMethodRequest& withBillingMethodName(StringHolder billingMethodName)
    {
        ensureData().billingMethodName.emplace(std::move(billingMethodName));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DeleteBillingMethodRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DeleteBillingMethodRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_PROJECT_CONTROL_DELETEBILLINGMETHODREQUEST_HPP_