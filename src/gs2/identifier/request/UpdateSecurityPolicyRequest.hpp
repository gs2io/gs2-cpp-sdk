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

#ifndef GS2_IDENTIFIER_CONTROL_UPDATESECURITYPOLICYREQUEST_HPP_
#define GS2_IDENTIFIER_CONTROL_UPDATESECURITYPOLICYREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2IdentifierConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace identifier
{

/**
 * セキュリティポリシーを更新します のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateSecurityPolicyRequest : public Gs2BasicRequest, public Gs2Identifier
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** セキュリティポリシー名 */
        optional<StringHolder> securityPolicyName;
        /** セキュリティポリシーの説明 */
        optional<StringHolder> description;
        /** ポリシードキュメント */
        optional<StringHolder> policy;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            securityPolicyName(data.securityPolicyName),
            description(data.description),
            policy(data.policy)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            securityPolicyName(std::move(data.securityPolicyName)),
            description(std::move(data.description)),
            policy(std::move(data.policy))
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
    UpdateSecurityPolicyRequest() :
        m_pData(nullptr)
    {}

    UpdateSecurityPolicyRequest(const UpdateSecurityPolicyRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Identifier(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateSecurityPolicyRequest(UpdateSecurityPolicyRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Identifier(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateSecurityPolicyRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateSecurityPolicyRequest& operator=(const UpdateSecurityPolicyRequest& updateSecurityPolicyRequest)
    {
        Gs2BasicRequest::operator=(updateSecurityPolicyRequest);
        Gs2Identifier::operator=(updateSecurityPolicyRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateSecurityPolicyRequest.m_pData);

        return *this;
    }

    UpdateSecurityPolicyRequest& operator=(UpdateSecurityPolicyRequest&& updateSecurityPolicyRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateSecurityPolicyRequest));
        Gs2Identifier::operator=(std::move(updateSecurityPolicyRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateSecurityPolicyRequest.m_pData;
        updateSecurityPolicyRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateSecurityPolicyRequest* operator->() const
    {
        return this;
    }

    UpdateSecurityPolicyRequest* operator->()
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
    void setSecurityPolicyName(const Char* securityPolicyName)
    {
        ensureData().securityPolicyName.emplace(securityPolicyName);
    }

    /**
     * セキュリティポリシー名を設定
     *
     * @param securityPolicyName セキュリティポリシー名
     */
    UpdateSecurityPolicyRequest& withSecurityPolicyName(const Char* securityPolicyName)
    {
        ensureData().securityPolicyName.emplace(securityPolicyName);
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
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * セキュリティポリシーの説明を設定
     *
     * @param description セキュリティポリシーの説明
     */
    UpdateSecurityPolicyRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
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
    void setPolicy(const Char* policy)
    {
        ensureData().policy.emplace(policy);
    }

    /**
     * ポリシードキュメントを設定
     *
     * @param policy ポリシードキュメント
     */
    UpdateSecurityPolicyRequest& withPolicy(const Char* policy)
    {
        ensureData().policy.emplace(policy);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateSecurityPolicyRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateSecurityPolicyRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateSecurityPolicyRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateSecurityPolicyRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_IDENTIFIER_CONTROL_UPDATESECURITYPOLICYREQUEST_HPP_