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

#ifndef GS2_ACCOUNT_CONTROL_AUTHENTICATIONREQUEST_HPP_
#define GS2_ACCOUNT_CONTROL_AUTHENTICATIONREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2AccountConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace account
{

/**
 * @author Game Server Services, Inc.
 */
class AuthenticationRequest : public Gs2BasicRequest, public Gs2Account
{
public:
    constexpr static const Char* const FUNCTION = "Authentication";

private:
    class Data : public Gs2Object
    {
    public:
        /** ゲームの名前を指定します。 */
        optional<StringHolder> gameName;
        /** 認証する対象アカウントのユーザIDを指定します。 */
        optional<StringHolder> userId;
        /** 認証結果の暗号化に利用する GS2-Key の暗号鍵名 */
        optional<StringHolder> keyName;
        /** 認証に利用するパスワード */
        optional<StringHolder> password;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            gameName(data.gameName),
            userId(data.userId),
            keyName(data.keyName),
            password(data.password)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            gameName(std::move(data.gameName)),
            userId(std::move(data.userId)),
            keyName(std::move(data.keyName)),
            password(std::move(data.password))
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
    AuthenticationRequest() :
        m_pData(nullptr)
    {}

    AuthenticationRequest(const AuthenticationRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Account(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    AuthenticationRequest(AuthenticationRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Account(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~AuthenticationRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    AuthenticationRequest& operator=(const AuthenticationRequest& authenticationRequest)
    {
        Gs2BasicRequest::operator=(authenticationRequest);
        Gs2Account::operator=(authenticationRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*authenticationRequest.m_pData);

        return *this;
    }

    AuthenticationRequest& operator=(AuthenticationRequest&& authenticationRequest)
    {
        Gs2BasicRequest::operator=(std::move(authenticationRequest));
        Gs2Account::operator=(std::move(authenticationRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = authenticationRequest.m_pData;
        authenticationRequest.m_pData = nullptr;

        return *this;
    }

    const AuthenticationRequest* operator->() const
    {
        return this;
    }

    AuthenticationRequest* operator->()
    {
        return this;
    }

    /**
     * ゲームの名前を指定します。を取得
     *
     * @return ゲームの名前を指定します。
     */
    const optional<StringHolder>& getGameName() const
    {
        return ensureData().gameName;
    }

    /**
     * ゲームの名前を指定します。を設定
     *
     * @param gameName ゲームの名前を指定します。
     */
    void setGameName(const Char* gameName)
    {
        ensureData().gameName.emplace(gameName);
    }

    /**
     * ゲームの名前を指定します。を設定
     *
     * @param gameName ゲームの名前を指定します。
     */
    AuthenticationRequest& withGameName(const Char* gameName)
    {
        ensureData().gameName.emplace(gameName);
        return *this;
    }

    /**
     * 認証する対象アカウントのユーザIDを指定します。を取得
     *
     * @return 認証する対象アカウントのユーザIDを指定します。
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * 認証する対象アカウントのユーザIDを指定します。を設定
     *
     * @param userId 認証する対象アカウントのユーザIDを指定します。
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * 認証する対象アカウントのユーザIDを指定します。を設定
     *
     * @param userId 認証する対象アカウントのユーザIDを指定します。
     */
    AuthenticationRequest& withUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
        return *this;
    }

    /**
     * 認証結果の暗号化に利用する GS2-Key の暗号鍵名を取得
     *
     * @return 認証結果の暗号化に利用する GS2-Key の暗号鍵名
     */
    const optional<StringHolder>& getKeyName() const
    {
        return ensureData().keyName;
    }

    /**
     * 認証結果の暗号化に利用する GS2-Key の暗号鍵名を設定
     *
     * @param keyName 認証結果の暗号化に利用する GS2-Key の暗号鍵名
     */
    void setKeyName(const Char* keyName)
    {
        ensureData().keyName.emplace(keyName);
    }

    /**
     * 認証結果の暗号化に利用する GS2-Key の暗号鍵名を設定
     *
     * @param keyName 認証結果の暗号化に利用する GS2-Key の暗号鍵名
     */
    AuthenticationRequest& withKeyName(const Char* keyName)
    {
        ensureData().keyName.emplace(keyName);
        return *this;
    }

    /**
     * 認証に利用するパスワードを取得
     *
     * @return 認証に利用するパスワード
     */
    const optional<StringHolder>& getPassword() const
    {
        return ensureData().password;
    }

    /**
     * 認証に利用するパスワードを設定
     *
     * @param password 認証に利用するパスワード
     */
    void setPassword(const Char* password)
    {
        ensureData().password.emplace(password);
    }

    /**
     * 認証に利用するパスワードを設定
     *
     * @param password 認証に利用するパスワード
     */
    AuthenticationRequest& withPassword(const Char* password)
    {
        ensureData().password.emplace(password);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    AuthenticationRequest& withGs2ClientId(const Char* gs2ClientId)
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
    AuthenticationRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    AuthenticationRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    AuthenticationRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_ACCOUNT_CONTROL_AUTHENTICATIONREQUEST_HPP_