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
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2IdentifierConst.hpp"
#include "../model/model.hpp"

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
    class Data : public Gs2Object
    {
    public:
        /** ユーザー名 */
        optional<StringHolder> userName;
        /** 剥奪するセキュリティポリシーのGRN */
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
    DetachSecurityPolicyRequest() :
        m_pData(nullptr)
    {}

    DetachSecurityPolicyRequest(const DetachSecurityPolicyRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Identifier(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    DetachSecurityPolicyRequest(DetachSecurityPolicyRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Identifier(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~DetachSecurityPolicyRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DetachSecurityPolicyRequest& operator=(const DetachSecurityPolicyRequest& detachSecurityPolicyRequest)
    {
        Gs2BasicRequest::operator=(detachSecurityPolicyRequest);
        Gs2Identifier::operator=(detachSecurityPolicyRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*detachSecurityPolicyRequest.m_pData);

        return *this;
    }

    DetachSecurityPolicyRequest& operator=(DetachSecurityPolicyRequest&& detachSecurityPolicyRequest)
    {
        Gs2BasicRequest::operator=(std::move(detachSecurityPolicyRequest));
        Gs2Identifier::operator=(std::move(detachSecurityPolicyRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = detachSecurityPolicyRequest.m_pData;
        detachSecurityPolicyRequest.m_pData = nullptr;

        return *this;
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
    void setUserName(const Char* userName)
    {
        ensureData().userName.emplace(userName);
    }

    /**
     * ユーザー名を設定
     *
     * @param userName ユーザー名
     */
    DetachSecurityPolicyRequest& withUserName(const Char* userName)
    {
        ensureData().userName.emplace(userName);
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
    void setSecurityPolicyId(const Char* securityPolicyId)
    {
        ensureData().securityPolicyId.emplace(securityPolicyId);
    }

    /**
     * 剥奪するセキュリティポリシーのGRNを設定
     *
     * @param securityPolicyId 剥奪するセキュリティポリシーのGRN
     */
    DetachSecurityPolicyRequest& withSecurityPolicyId(const Char* securityPolicyId)
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
    DetachSecurityPolicyRequest& withGs2ClientId(const Char* gs2ClientId)
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
    DetachSecurityPolicyRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    DetachSecurityPolicyRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DetachSecurityPolicyRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_IDENTIFIER_CONTROL_DETACHSECURITYPOLICYREQUEST_HPP_