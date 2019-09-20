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
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/identifier/Gs2IdentifierConst.hpp>
#include <gs2/identifier/model/model.hpp>
#include <memory>

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
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** クライアントID */
        optional<StringHolder> clientId;
        /** クライアントシークレット */
        optional<StringHolder> clientSecret;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            clientId(data.clientId),
            clientSecret(data.clientSecret)
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
    LoginRequest() = default;
    LoginRequest(const LoginRequest& loginRequest) = default;
    LoginRequest(LoginRequest&& loginRequest) = default;
    ~LoginRequest() GS2_OVERRIDE = default;

    LoginRequest& operator=(const LoginRequest& loginRequest) = default;
    LoginRequest& operator=(LoginRequest&& loginRequest) = default;

    LoginRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(LoginRequest);
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
    void setClientId(StringHolder clientId)
    {
        ensureData().clientId.emplace(std::move(clientId));
    }

    /**
     * クライアントIDを設定
     *
     * @param clientId クライアントID
     */
    LoginRequest& withClientId(StringHolder clientId)
    {
        ensureData().clientId.emplace(std::move(clientId));
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
    void setClientSecret(StringHolder clientSecret)
    {
        ensureData().clientSecret.emplace(std::move(clientSecret));
    }

    /**
     * クライアントシークレットを設定
     *
     * @param clientSecret クライアントシークレット
     */
    LoginRequest& withClientSecret(StringHolder clientSecret)
    {
        ensureData().clientSecret.emplace(std::move(clientSecret));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    LoginRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    LoginRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_IDENTIFIER_CONTROL_LOGINREQUEST_HPP_