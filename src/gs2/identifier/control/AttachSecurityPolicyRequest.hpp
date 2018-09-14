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

#ifndef GS2_IDENTIFIER_CONTROL_ATTACHSECURITYPOLICYREQUEST_HPP_
#define GS2_IDENTIFIER_CONTROL_ATTACHSECURITYPOLICYREQUEST_HPP_

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
class AttachSecurityPolicyRequest : public Gs2BasicRequest, public Gs2Identifier
{
public:
    constexpr static const Char* const FUNCTION = "AttachSecurityPolicy";

private:
    class Data : public Gs2Object
    {
    public:
        /** ユーザの名前を指定します。 */
        optional<StringHolder> userName;
        /** セキュリティポリシーのGRN */
        optional<StringHolder> securityPolicyId;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            userName(data.userName),
            securityPolicyId(data.securityPolicyId)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            userName(std::move(data.userName)),
            securityPolicyId(std::move(data.securityPolicyId))
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
    AttachSecurityPolicyRequest() :
        m_pData(nullptr)
    {}

    AttachSecurityPolicyRequest(const AttachSecurityPolicyRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Identifier(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    AttachSecurityPolicyRequest(AttachSecurityPolicyRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Identifier(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~AttachSecurityPolicyRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    AttachSecurityPolicyRequest& operator=(const AttachSecurityPolicyRequest& attachSecurityPolicyRequest)
    {
        Gs2BasicRequest::operator=(attachSecurityPolicyRequest);
        Gs2Identifier::operator=(attachSecurityPolicyRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*attachSecurityPolicyRequest.m_pData);

        return *this;
    }

    AttachSecurityPolicyRequest& operator=(AttachSecurityPolicyRequest&& attachSecurityPolicyRequest)
    {
        Gs2BasicRequest::operator=(std::move(attachSecurityPolicyRequest));
        Gs2Identifier::operator=(std::move(attachSecurityPolicyRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = attachSecurityPolicyRequest.m_pData;
        attachSecurityPolicyRequest.m_pData = nullptr;

        return *this;
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
     * ユーザの名前を指定します。を取得
     *
     * @return ユーザの名前を指定します。
     */
    const optional<StringHolder>& getUserName() const
    {
        return ensureData().userName;
    }

    /**
     * ユーザの名前を指定します。を設定
     *
     * @param userName ユーザの名前を指定します。
     */
    void setUserName(const Char* userName)
    {
        ensureData().userName.emplace(userName);
    }

    /**
     * ユーザの名前を指定します。を設定
     *
     * @param userName ユーザの名前を指定します。
     */
    AttachSecurityPolicyRequest& withUserName(const Char* userName)
    {
        ensureData().userName.emplace(userName);
        return *this;
    }

    /**
     * セキュリティポリシーのGRNを取得
     *
     * @return セキュリティポリシーのGRN
     */
    const optional<StringHolder>& getSecurityPolicyId() const
    {
        return ensureData().securityPolicyId;
    }

    /**
     * セキュリティポリシーのGRNを設定
     *
     * @param securityPolicyId セキュリティポリシーのGRN
     */
    void setSecurityPolicyId(const Char* securityPolicyId)
    {
        ensureData().securityPolicyId.emplace(securityPolicyId);
    }

    /**
     * セキュリティポリシーのGRNを設定
     *
     * @param securityPolicyId セキュリティポリシーのGRN
     */
    AttachSecurityPolicyRequest& withSecurityPolicyId(const Char* securityPolicyId)
    {
        ensureData().securityPolicyId.emplace(securityPolicyId);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    AttachSecurityPolicyRequest& withGs2ClientId(const Char* gs2ClientId)
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
    AttachSecurityPolicyRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    AttachSecurityPolicyRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    AttachSecurityPolicyRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_IDENTIFIER_CONTROL_ATTACHSECURITYPOLICYREQUEST_HPP_