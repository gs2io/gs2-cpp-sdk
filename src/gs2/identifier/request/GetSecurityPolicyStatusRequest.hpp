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

#ifndef GS2_IDENTIFIER_CONTROL_GETSECURITYPOLICYSTATUSREQUEST_HPP_
#define GS2_IDENTIFIER_CONTROL_GETSECURITYPOLICYSTATUSREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2IdentifierConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace identifier
{

/**
 * セキュリティポリシーを取得します のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class GetSecurityPolicyStatusRequest : public Gs2BasicRequest, public Gs2Identifier
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** セキュリティポリシー名 */
        optional<StringHolder> securityPolicyName;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            securityPolicyName(data.securityPolicyName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            securityPolicyName(std::move(data.securityPolicyName))
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
    GetSecurityPolicyStatusRequest() :
        m_pData(nullptr)
    {}

    GetSecurityPolicyStatusRequest(const GetSecurityPolicyStatusRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Identifier(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    GetSecurityPolicyStatusRequest(GetSecurityPolicyStatusRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Identifier(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~GetSecurityPolicyStatusRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetSecurityPolicyStatusRequest& operator=(const GetSecurityPolicyStatusRequest& getSecurityPolicyStatusRequest)
    {
        Gs2BasicRequest::operator=(getSecurityPolicyStatusRequest);
        Gs2Identifier::operator=(getSecurityPolicyStatusRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getSecurityPolicyStatusRequest.m_pData);

        return *this;
    }

    GetSecurityPolicyStatusRequest& operator=(GetSecurityPolicyStatusRequest&& getSecurityPolicyStatusRequest)
    {
        Gs2BasicRequest::operator=(std::move(getSecurityPolicyStatusRequest));
        Gs2Identifier::operator=(std::move(getSecurityPolicyStatusRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getSecurityPolicyStatusRequest.m_pData;
        getSecurityPolicyStatusRequest.m_pData = nullptr;

        return *this;
    }

    const GetSecurityPolicyStatusRequest* operator->() const
    {
        return this;
    }

    GetSecurityPolicyStatusRequest* operator->()
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
    GetSecurityPolicyStatusRequest& withSecurityPolicyName(const Char* securityPolicyName)
    {
        ensureData().securityPolicyName.emplace(securityPolicyName);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    GetSecurityPolicyStatusRequest& withGs2ClientId(const Char* gs2ClientId)
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
    GetSecurityPolicyStatusRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    GetSecurityPolicyStatusRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetSecurityPolicyStatusRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_IDENTIFIER_CONTROL_GETSECURITYPOLICYSTATUSREQUEST_HPP_