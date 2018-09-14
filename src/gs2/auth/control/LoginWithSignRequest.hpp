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

#ifndef GS2_AUTH_CONTROL_LOGINWITHSIGNREQUEST_HPP_
#define GS2_AUTH_CONTROL_LOGINWITHSIGNREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2AuthConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace auth
{

/**
 * @author Game Server Services, Inc.
 */
class LoginWithSignRequest : public Gs2BasicRequest, public Gs2Auth
{
public:
    constexpr static const Char* const FUNCTION = "LoginWithSign";

private:
    class Data : public Gs2Object
    {
    public:
        /** ログインするサービスID */
        optional<StringHolder> serviceId;
        /** ログインするユーザのIDを指定してください */
        optional<StringHolder> userId;
        /** GS2-Accountの認証署名の作成に使用した GS2-Key の暗号鍵名 */
        optional<StringHolder> keyName;
        /** GS2-Accountの認証署名 */
        optional<StringHolder> sign;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            serviceId(data.serviceId),
            userId(data.userId),
            keyName(data.keyName),
            sign(data.sign)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            serviceId(std::move(data.serviceId)),
            userId(std::move(data.userId)),
            keyName(std::move(data.keyName)),
            sign(std::move(data.sign))
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
    LoginWithSignRequest() :
        m_pData(nullptr)
    {}

    LoginWithSignRequest(const LoginWithSignRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Auth(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    LoginWithSignRequest(LoginWithSignRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Auth(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~LoginWithSignRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    LoginWithSignRequest& operator=(const LoginWithSignRequest& loginWithSignRequest)
    {
        Gs2BasicRequest::operator=(loginWithSignRequest);
        Gs2Auth::operator=(loginWithSignRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*loginWithSignRequest.m_pData);

        return *this;
    }

    LoginWithSignRequest& operator=(LoginWithSignRequest&& loginWithSignRequest)
    {
        Gs2BasicRequest::operator=(std::move(loginWithSignRequest));
        Gs2Auth::operator=(std::move(loginWithSignRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = loginWithSignRequest.m_pData;
        loginWithSignRequest.m_pData = nullptr;

        return *this;
    }

    const LoginWithSignRequest* operator->() const
    {
        return this;
    }

    LoginWithSignRequest* operator->()
    {
        return this;
    }

    /**
     * ログインするサービスIDを取得
     *
     * @return ログインするサービスID
     */
    const optional<StringHolder>& getServiceId() const
    {
        return ensureData().serviceId;
    }

    /**
     * ログインするサービスIDを設定
     *
     * @param serviceId ログインするサービスID
     */
    void setServiceId(const Char* serviceId)
    {
        ensureData().serviceId.emplace(serviceId);
    }

    /**
     * ログインするサービスIDを設定
     *
     * @param serviceId ログインするサービスID
     */
    LoginWithSignRequest& withServiceId(const Char* serviceId)
    {
        ensureData().serviceId.emplace(serviceId);
        return *this;
    }

    /**
     * ログインするユーザのIDを指定してくださいを取得
     *
     * @return ログインするユーザのIDを指定してください
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ログインするユーザのIDを指定してくださいを設定
     *
     * @param userId ログインするユーザのIDを指定してください
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * ログインするユーザのIDを指定してくださいを設定
     *
     * @param userId ログインするユーザのIDを指定してください
     */
    LoginWithSignRequest& withUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
        return *this;
    }

    /**
     * GS2-Accountの認証署名の作成に使用した GS2-Key の暗号鍵名を取得
     *
     * @return GS2-Accountの認証署名の作成に使用した GS2-Key の暗号鍵名
     */
    const optional<StringHolder>& getKeyName() const
    {
        return ensureData().keyName;
    }

    /**
     * GS2-Accountの認証署名の作成に使用した GS2-Key の暗号鍵名を設定
     *
     * @param keyName GS2-Accountの認証署名の作成に使用した GS2-Key の暗号鍵名
     */
    void setKeyName(const Char* keyName)
    {
        ensureData().keyName.emplace(keyName);
    }

    /**
     * GS2-Accountの認証署名の作成に使用した GS2-Key の暗号鍵名を設定
     *
     * @param keyName GS2-Accountの認証署名の作成に使用した GS2-Key の暗号鍵名
     */
    LoginWithSignRequest& withKeyName(const Char* keyName)
    {
        ensureData().keyName.emplace(keyName);
        return *this;
    }

    /**
     * GS2-Accountの認証署名を取得
     *
     * @return GS2-Accountの認証署名
     */
    const optional<StringHolder>& getSign() const
    {
        return ensureData().sign;
    }

    /**
     * GS2-Accountの認証署名を設定
     *
     * @param sign GS2-Accountの認証署名
     */
    void setSign(const Char* sign)
    {
        ensureData().sign.emplace(sign);
    }

    /**
     * GS2-Accountの認証署名を設定
     *
     * @param sign GS2-Accountの認証署名
     */
    LoginWithSignRequest& withSign(const Char* sign)
    {
        ensureData().sign.emplace(sign);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    LoginWithSignRequest& withGs2ClientId(const Char* gs2ClientId)
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
    LoginWithSignRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    LoginWithSignRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    LoginWithSignRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_AUTH_CONTROL_LOGINWITHSIGNREQUEST_HPP_