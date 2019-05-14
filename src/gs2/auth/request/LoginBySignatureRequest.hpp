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

#ifndef GS2_AUTH_CONTROL_LOGINBYSIGNATUREREQUEST_HPP_
#define GS2_AUTH_CONTROL_LOGINBYSIGNATUREREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2AuthConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace auth
{

/**
 * 指定したユーザIDでGS2にログインし、アクセストークンを取得します のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class LoginBySignatureRequest : public Gs2BasicRequest, public Gs2Auth
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** ユーザーID */
        optional<StringHolder> userId;
        /** 署名の作成に使用した暗号鍵 のGRN */
        optional<StringHolder> keyId;
        /** アカウント認証情報の署名対象 */
        optional<StringHolder> body;
        /** 署名 */
        optional<StringHolder> signature;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            userId(data.userId),
            keyId(data.keyId),
            body(data.body),
            signature(data.signature),
            duplicationAvoider(data.duplicationAvoider)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            userId(std::move(data.userId)),
            keyId(std::move(data.keyId)),
            body(std::move(data.body)),
            signature(std::move(data.signature)),
            duplicationAvoider(std::move(data.duplicationAvoider))
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
    LoginBySignatureRequest() :
        m_pData(nullptr)
    {}

    LoginBySignatureRequest(const LoginBySignatureRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Auth(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    LoginBySignatureRequest(LoginBySignatureRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Auth(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~LoginBySignatureRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    LoginBySignatureRequest& operator=(const LoginBySignatureRequest& loginBySignatureRequest)
    {
        Gs2BasicRequest::operator=(loginBySignatureRequest);
        Gs2Auth::operator=(loginBySignatureRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*loginBySignatureRequest.m_pData);

        return *this;
    }

    LoginBySignatureRequest& operator=(LoginBySignatureRequest&& loginBySignatureRequest)
    {
        Gs2BasicRequest::operator=(std::move(loginBySignatureRequest));
        Gs2Auth::operator=(std::move(loginBySignatureRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = loginBySignatureRequest.m_pData;
        loginBySignatureRequest.m_pData = nullptr;

        return *this;
    }

    const LoginBySignatureRequest* operator->() const
    {
        return this;
    }

    LoginBySignatureRequest* operator->()
    {
        return this;
    }
    /**
     * ユーザーIDを取得
     *
     * @return ユーザーID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    LoginBySignatureRequest& withUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
        return *this;
    }

    /**
     * 署名の作成に使用した暗号鍵 のGRNを取得
     *
     * @return 署名の作成に使用した暗号鍵 のGRN
     */
    const optional<StringHolder>& getKeyId() const
    {
        return ensureData().keyId;
    }

    /**
     * 署名の作成に使用した暗号鍵 のGRNを設定
     *
     * @param keyId 署名の作成に使用した暗号鍵 のGRN
     */
    void setKeyId(const Char* keyId)
    {
        ensureData().keyId.emplace(keyId);
    }

    /**
     * 署名の作成に使用した暗号鍵 のGRNを設定
     *
     * @param keyId 署名の作成に使用した暗号鍵 のGRN
     */
    LoginBySignatureRequest& withKeyId(const Char* keyId)
    {
        ensureData().keyId.emplace(keyId);
        return *this;
    }

    /**
     * アカウント認証情報の署名対象を取得
     *
     * @return アカウント認証情報の署名対象
     */
    const optional<StringHolder>& getBody() const
    {
        return ensureData().body;
    }

    /**
     * アカウント認証情報の署名対象を設定
     *
     * @param body アカウント認証情報の署名対象
     */
    void setBody(const Char* body)
    {
        ensureData().body.emplace(body);
    }

    /**
     * アカウント認証情報の署名対象を設定
     *
     * @param body アカウント認証情報の署名対象
     */
    LoginBySignatureRequest& withBody(const Char* body)
    {
        ensureData().body.emplace(body);
        return *this;
    }

    /**
     * 署名を取得
     *
     * @return 署名
     */
    const optional<StringHolder>& getSignature() const
    {
        return ensureData().signature;
    }

    /**
     * 署名を設定
     *
     * @param signature 署名
     */
    void setSignature(const Char* signature)
    {
        ensureData().signature.emplace(signature);
    }

    /**
     * 署名を設定
     *
     * @param signature 署名
     */
    LoginBySignatureRequest& withSignature(const Char* signature)
    {
        ensureData().signature.emplace(signature);
        return *this;
    }

    /**
     * 重複実行回避機能に使用するIDを取得
     *
     * @return 重複実行回避機能に使用するID
     */
    const optional<StringHolder>& getDuplicationAvoider() const
    {
        return ensureData().duplicationAvoider;
    }

    /**
     * 重複実行回避機能に使用するIDを設定
     *
     * @param duplicationAvoider 重複実行回避機能に使用するID
     */
    void setDuplicationAvoider(const Char* duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(duplicationAvoider);
    }

    /**
     * 重複実行回避機能に使用するIDを設定
     *
     * @param duplicationAvoider 重複実行回避機能に使用するID
     */
    LoginBySignatureRequest& withDuplicationAvoider(const Char* duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(duplicationAvoider);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    LoginBySignatureRequest& withGs2ClientId(const Char* gs2ClientId)
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
    LoginBySignatureRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    LoginBySignatureRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    LoginBySignatureRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_AUTH_CONTROL_LOGINBYSIGNATUREREQUEST_HPP_