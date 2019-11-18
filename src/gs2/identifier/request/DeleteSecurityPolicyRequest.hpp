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

#ifndef GS2_IDENTIFIER_CONTROL_DELETESECURITYPOLICYREQUEST_HPP_
#define GS2_IDENTIFIER_CONTROL_DELETESECURITYPOLICYREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/identifier/Gs2IdentifierConst.hpp>
#include <gs2/identifier/model/model.hpp>
#include <memory>

namespace gs2 { namespace identifier
{

/**
 * セキュリティポリシーを削除します のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class DeleteSecurityPolicyRequest : public Gs2BasicRequest, public Gs2Identifier
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
    DeleteSecurityPolicyRequest() = default;
    DeleteSecurityPolicyRequest(const DeleteSecurityPolicyRequest& deleteSecurityPolicyRequest) = default;
    DeleteSecurityPolicyRequest(DeleteSecurityPolicyRequest&& deleteSecurityPolicyRequest) = default;
    ~DeleteSecurityPolicyRequest() GS2_OVERRIDE = default;

    DeleteSecurityPolicyRequest& operator=(const DeleteSecurityPolicyRequest& deleteSecurityPolicyRequest) = default;
    DeleteSecurityPolicyRequest& operator=(DeleteSecurityPolicyRequest&& deleteSecurityPolicyRequest) = default;

    DeleteSecurityPolicyRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DeleteSecurityPolicyRequest);
    }

    const DeleteSecurityPolicyRequest* operator->() const
    {
        return this;
    }

    DeleteSecurityPolicyRequest* operator->()
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
    DeleteSecurityPolicyRequest& withSecurityPolicyName(StringHolder securityPolicyName)
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
    DeleteSecurityPolicyRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DeleteSecurityPolicyRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_IDENTIFIER_CONTROL_DELETESECURITYPOLICYREQUEST_HPP_