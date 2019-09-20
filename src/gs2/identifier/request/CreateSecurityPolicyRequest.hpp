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

#ifndef GS2_IDENTIFIER_CONTROL_CREATESECURITYPOLICYREQUEST_HPP_
#define GS2_IDENTIFIER_CONTROL_CREATESECURITYPOLICYREQUEST_HPP_

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
 * セキュリティポリシーを新規作成します のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateSecurityPolicyRequest : public Gs2BasicRequest, public Gs2Identifier
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** セキュリティポリシー名 */
        optional<StringHolder> name;
        /** セキュリティポリシーの説明 */
        optional<StringHolder> description;
        /** ポリシードキュメント */
        optional<StringHolder> policy;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            name(data.name),
            description(data.description),
            policy(data.policy)
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
    CreateSecurityPolicyRequest() = default;
    CreateSecurityPolicyRequest(const CreateSecurityPolicyRequest& createSecurityPolicyRequest) = default;
    CreateSecurityPolicyRequest(CreateSecurityPolicyRequest&& createSecurityPolicyRequest) = default;
    ~CreateSecurityPolicyRequest() GS2_OVERRIDE = default;

    CreateSecurityPolicyRequest& operator=(const CreateSecurityPolicyRequest& createSecurityPolicyRequest) = default;
    CreateSecurityPolicyRequest& operator=(CreateSecurityPolicyRequest&& createSecurityPolicyRequest) = default;

    CreateSecurityPolicyRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CreateSecurityPolicyRequest);
    }

    const CreateSecurityPolicyRequest* operator->() const
    {
        return this;
    }

    CreateSecurityPolicyRequest* operator->()
    {
        return this;
    }

    /**
     * セキュリティポリシー名を取得
     *
     * @return セキュリティポリシー名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * セキュリティポリシー名を設定
     *
     * @param name セキュリティポリシー名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * セキュリティポリシー名を設定
     *
     * @param name セキュリティポリシー名
     */
    CreateSecurityPolicyRequest& withName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
        return *this;
    }

    /**
     * セキュリティポリシーの説明を取得
     *
     * @return セキュリティポリシーの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * セキュリティポリシーの説明を設定
     *
     * @param description セキュリティポリシーの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * セキュリティポリシーの説明を設定
     *
     * @param description セキュリティポリシーの説明
     */
    CreateSecurityPolicyRequest& withDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
        return *this;
    }

    /**
     * ポリシードキュメントを取得
     *
     * @return ポリシードキュメント
     */
    const optional<StringHolder>& getPolicy() const
    {
        return ensureData().policy;
    }

    /**
     * ポリシードキュメントを設定
     *
     * @param policy ポリシードキュメント
     */
    void setPolicy(StringHolder policy)
    {
        ensureData().policy.emplace(std::move(policy));
    }

    /**
     * ポリシードキュメントを設定
     *
     * @param policy ポリシードキュメント
     */
    CreateSecurityPolicyRequest& withPolicy(StringHolder policy)
    {
        ensureData().policy.emplace(std::move(policy));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreateSecurityPolicyRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateSecurityPolicyRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_IDENTIFIER_CONTROL_CREATESECURITYPOLICYREQUEST_HPP_