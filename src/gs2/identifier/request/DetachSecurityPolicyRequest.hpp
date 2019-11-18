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

#ifndef GS2_IDENTIFIER_CONTROL_DETACHSECURITYPOLICYREQUEST_HPP_
#define GS2_IDENTIFIER_CONTROL_DETACHSECURITYPOLICYREQUEST_HPP_

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
 * 割り当てられたセキュリティポリシーをユーザーから外します のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class DetachSecurityPolicyRequest : public Gs2BasicRequest, public Gs2Identifier
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ユーザー名 */
        optional<StringHolder> userName;
        /** 剥奪するセキュリティポリシーのGRN */
        optional<StringHolder> securityPolicyId;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            userName(data.userName),
            securityPolicyId(data.securityPolicyId)
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
    DetachSecurityPolicyRequest() = default;
    DetachSecurityPolicyRequest(const DetachSecurityPolicyRequest& detachSecurityPolicyRequest) = default;
    DetachSecurityPolicyRequest(DetachSecurityPolicyRequest&& detachSecurityPolicyRequest) = default;
    ~DetachSecurityPolicyRequest() GS2_OVERRIDE = default;

    DetachSecurityPolicyRequest& operator=(const DetachSecurityPolicyRequest& detachSecurityPolicyRequest) = default;
    DetachSecurityPolicyRequest& operator=(DetachSecurityPolicyRequest&& detachSecurityPolicyRequest) = default;

    DetachSecurityPolicyRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DetachSecurityPolicyRequest);
    }

    const DetachSecurityPolicyRequest* operator->() const
    {
        return this;
    }

    DetachSecurityPolicyRequest* operator->()
    {
        return this;
    }

    /**
     * ユーザー名を取得
     *
     * @return ユーザー名
     */
    const optional<StringHolder>& getUserName() const
    {
        return ensureData().userName;
    }

    /**
     * ユーザー名を設定
     *
     * @param userName ユーザー名
     */
    void setUserName(StringHolder userName)
    {
        ensureData().userName.emplace(std::move(userName));
    }

    /**
     * ユーザー名を設定
     *
     * @param userName ユーザー名
     */
    DetachSecurityPolicyRequest& withUserName(StringHolder userName)
    {
        ensureData().userName.emplace(std::move(userName));
        return *this;
    }

    /**
     * 剥奪するセキュリティポリシーのGRNを取得
     *
     * @return 剥奪するセキュリティポリシーのGRN
     */
    const optional<StringHolder>& getSecurityPolicyId() const
    {
        return ensureData().securityPolicyId;
    }

    /**
     * 剥奪するセキュリティポリシーのGRNを設定
     *
     * @param securityPolicyId 剥奪するセキュリティポリシーのGRN
     */
    void setSecurityPolicyId(StringHolder securityPolicyId)
    {
        ensureData().securityPolicyId.emplace(std::move(securityPolicyId));
    }

    /**
     * 剥奪するセキュリティポリシーのGRNを設定
     *
     * @param securityPolicyId 剥奪するセキュリティポリシーのGRN
     */
    DetachSecurityPolicyRequest& withSecurityPolicyId(StringHolder securityPolicyId)
    {
        ensureData().securityPolicyId.emplace(std::move(securityPolicyId));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DetachSecurityPolicyRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DetachSecurityPolicyRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_IDENTIFIER_CONTROL_DETACHSECURITYPOLICYREQUEST_HPP_