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

#ifndef GS2_IDENTIFIER_CONTROL_GETSECURITYPOLICYREQUEST_HPP_
#define GS2_IDENTIFIER_CONTROL_GETSECURITYPOLICYREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2IdentifierConst.hpp"
#include "../model/model.hpp"
#include <memory>

namespace gs2 { namespace identifier
{

/**
 * セキュリティポリシーを取得します のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class GetSecurityPolicyRequest : public Gs2BasicRequest, public Gs2Identifier
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** セキュリティポリシー名 */
        optional<StringHolder> securityPolicyName;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            securityPolicyName(data.securityPolicyName)
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
    GetSecurityPolicyRequest() = default;
    GetSecurityPolicyRequest(const GetSecurityPolicyRequest& getSecurityPolicyRequest) = default;
    GetSecurityPolicyRequest(GetSecurityPolicyRequest&& getSecurityPolicyRequest) = default;
    ~GetSecurityPolicyRequest() GS2_OVERRIDE = default;

    GetSecurityPolicyRequest& operator=(const GetSecurityPolicyRequest& getSecurityPolicyRequest) = default;
    GetSecurityPolicyRequest& operator=(GetSecurityPolicyRequest&& getSecurityPolicyRequest) = default;

    GetSecurityPolicyRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(GetSecurityPolicyRequest);
    }

    const GetSecurityPolicyRequest* operator->() const
    {
        return this;
    }

    GetSecurityPolicyRequest* operator->()
    {
        return this;
    }

    /**
     * セキュリティポリシー名を取得
     *
     * @return セキュリティポリシー名
     */
    const optional<StringHolder>& getSecurityPolicyName() const
    {
        return ensureData().securityPolicyName;
    }

    /**
     * セキュリティポリシー名を設定
     *
     * @param securityPolicyName セキュリティポリシー名
     */
    void setSecurityPolicyName(StringHolder securityPolicyName)
    {
        ensureData().securityPolicyName.emplace(std::move(securityPolicyName));
    }

    /**
     * セキュリティポリシー名を設定
     *
     * @param securityPolicyName セキュリティポリシー名
     */
    GetSecurityPolicyRequest& withSecurityPolicyName(StringHolder securityPolicyName)
    {
        ensureData().securityPolicyName.emplace(std::move(securityPolicyName));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    GetSecurityPolicyRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetSecurityPolicyRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_IDENTIFIER_CONTROL_GETSECURITYPOLICYREQUEST_HPP_