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

#ifndef GS2_IDENTIFIER_CONTROL_CREATESECURITYPOLICYREQUEST_HPP_
#define GS2_IDENTIFIER_CONTROL_CREATESECURITYPOLICYREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2IdentifierConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace identifier
{

/**
 * @author Game Server Services, Inc.
 */
class CreateSecurityPolicyRequest : public Gs2BasicRequest, public Gs2Identifier
{
public:
    constexpr static const Char* const FUNCTION = "CreateSecurityPolicy";

private:
    class Data : public Gs2Object
    {
    public:
        /** 名前 */
        optional<StringHolder> name;
        /** ポリシードキュメント */
        optional<StringHolder> policy;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            name(data.name),
            policy(data.policy)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            name(std::move(data.name)),
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
    CreateSecurityPolicyRequest() :
        m_pData(nullptr)
    {}

    CreateSecurityPolicyRequest(const CreateSecurityPolicyRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Identifier(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CreateSecurityPolicyRequest(CreateSecurityPolicyRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Identifier(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CreateSecurityPolicyRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateSecurityPolicyRequest& operator=(const CreateSecurityPolicyRequest& createSecurityPolicyRequest)
    {
        Gs2BasicRequest::operator=(createSecurityPolicyRequest);
        Gs2Identifier::operator=(createSecurityPolicyRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createSecurityPolicyRequest.m_pData);

        return *this;
    }

    CreateSecurityPolicyRequest& operator=(CreateSecurityPolicyRequest&& createSecurityPolicyRequest)
    {
        Gs2BasicRequest::operator=(std::move(createSecurityPolicyRequest));
        Gs2Identifier::operator=(std::move(createSecurityPolicyRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createSecurityPolicyRequest.m_pData;
        createSecurityPolicyRequest.m_pData = nullptr;

        return *this;
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
     * 名前を取得
     *
     * @return 名前
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 名前を設定
     *
     * @param name 名前
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * 名前を設定
     *
     * @param name 名前
     */
    CreateSecurityPolicyRequest& withName(const Char* name)
    {
        ensureData().name.emplace(name);
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
    CreateSecurityPolicyRequest& withPolicy(const Char* policy)
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
    CreateSecurityPolicyRequest& withGs2ClientId(const Char* gs2ClientId)
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
    CreateSecurityPolicyRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    CreateSecurityPolicyRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateSecurityPolicyRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_IDENTIFIER_CONTROL_CREATESECURITYPOLICYREQUEST_HPP_