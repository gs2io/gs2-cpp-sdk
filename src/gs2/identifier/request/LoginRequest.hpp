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

#ifndef GS2_IDENTIFIER_CONTROL_LOGINREQUEST_HPP_
#define GS2_IDENTIFIER_CONTROL_LOGINREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2IdentifierConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace identifier
{

/**
 * プロジェクトトークン を取得します のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class LoginRequest : public Gs2BasicRequest, public Gs2Identifier
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** クライアントID */
        optional<StringHolder> clientId;
        /** クライアントシークレット */
        optional<StringHolder> clientSecret;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            clientId(data.clientId),
            clientSecret(data.clientSecret)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            clientId(std::move(data.clientId)),
            clientSecret(std::move(data.clientSecret))
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
    LoginRequest() :
        m_pData(nullptr)
    {}

    LoginRequest(const LoginRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Identifier(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    LoginRequest(LoginRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Identifier(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~LoginRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    LoginRequest& operator=(const LoginRequest& loginRequest)
    {
        Gs2BasicRequest::operator=(loginRequest);
        Gs2Identifier::operator=(loginRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*loginRequest.m_pData);

        return *this;
    }

    LoginRequest& operator=(LoginRequest&& loginRequest)
    {
        Gs2BasicRequest::operator=(std::move(loginRequest));
        Gs2Identifier::operator=(std::move(loginRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = loginRequest.m_pData;
        loginRequest.m_pData = nullptr;

        return *this;
    }

    const LoginRequest* operator->() const
    {
        return this;
    }

    LoginRequest* operator->()
    {
        return this;
    }

    /**
     * クライアントIDを取得
     *
     * @return クライアントID
     */
    const optional<StringHolder>& getClientId() const
    {
        return ensureData().clientId;
    }

    /**
     * クライアントIDを設定
     *
     * @param clientId クライアントID
     */
    void setClientId(const Char* clientId)
    {
        ensureData().clientId.emplace(clientId);
    }

    /**
     * クライアントIDを設定
     *
     * @param clientId クライアントID
     */
    LoginRequest& withClientId(const Char* clientId)
    {
        ensureData().clientId.emplace(clientId);
        return *this;
    }

    /**
     * クライアントシークレットを取得
     *
     * @return クライアントシークレット
     */
    const optional<StringHolder>& getClientSecret() const
    {
        return ensureData().clientSecret;
    }

    /**
     * クライアントシークレットを設定
     *
     * @param clientSecret クライアントシークレット
     */
    void setClientSecret(const Char* clientSecret)
    {
        ensureData().clientSecret.emplace(clientSecret);
    }

    /**
     * クライアントシークレットを設定
     *
     * @param clientSecret クライアントシークレット
     */
    LoginRequest& withClientSecret(const Char* clientSecret)
    {
        ensureData().clientSecret.emplace(clientSecret);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    LoginRequest& withGs2ClientId(const Char* gs2ClientId)
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
    LoginRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    LoginRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    LoginRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_IDENTIFIER_CONTROL_LOGINREQUEST_HPP_