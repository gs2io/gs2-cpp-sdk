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

#ifndef GS2_IDENTIFIER_CONTROL_ATTACHSECURITYPOLICYREQUEST_HPP_
#define GS2_IDENTIFIER_CONTROL_ATTACHSECURITYPOLICYREQUEST_HPP_

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
 * 割り当てられたセキュリティポリシーを新しくユーザーに割り当てます のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class AttachSecurityPolicyRequest : public Gs2BasicRequest, public Gs2Identifier
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ユーザー名 */
        optional<StringHolder> userName;
        /** 割り当てるセキュリティポリシーのGRN */
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
    AttachSecurityPolicyRequest() = default;
    AttachSecurityPolicyRequest(const AttachSecurityPolicyRequest& attachSecurityPolicyRequest) = default;
    AttachSecurityPolicyRequest(AttachSecurityPolicyRequest&& attachSecurityPolicyRequest) = default;
    ~AttachSecurityPolicyRequest() GS2_OVERRIDE = default;

    AttachSecurityPolicyRequest& operator=(const AttachSecurityPolicyRequest& attachSecurityPolicyRequest) = default;
    AttachSecurityPolicyRequest& operator=(AttachSecurityPolicyRequest&& attachSecurityPolicyRequest) = default;

    AttachSecurityPolicyRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(AttachSecurityPolicyRequest);
    }

    const AttachSecurityPolicyRequest* operator->() const
    {
        return this;
    }

    AttachSecurityPolicyRequest* operator->()
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
    AttachSecurityPolicyRequest& withUserName(StringHolder userName)
    {
        ensureData().userName.emplace(std::move(userName));
        return *this;
    }

    /**
     * 割り当てるセキュリティポリシーのGRNを取得
     *
     * @return 割り当てるセキュリティポリシーのGRN
     */
    const optional<StringHolder>& getSecurityPolicyId() const
    {
        return ensureData().securityPolicyId;
    }

    /**
     * 割り当てるセキュリティポリシーのGRNを設定
     *
     * @param securityPolicyId 割り当てるセキュリティポリシーのGRN
     */
    void setSecurityPolicyId(StringHolder securityPolicyId)
    {
        ensureData().securityPolicyId.emplace(std::move(securityPolicyId));
    }

    /**
     * 割り当てるセキュリティポリシーのGRNを設定
     *
     * @param securityPolicyId 割り当てるセキュリティポリシーのGRN
     */
    AttachSecurityPolicyRequest& withSecurityPolicyId(StringHolder securityPolicyId)
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
    AttachSecurityPolicyRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    AttachSecurityPolicyRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_IDENTIFIER_CONTROL_ATTACHSECURITYPOLICYREQUEST_HPP_