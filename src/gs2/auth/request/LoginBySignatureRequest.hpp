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
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/auth/Gs2AuthConst.hpp>
#include <gs2/auth/model/model.hpp>
#include <memory>

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
    class Data : public Gs2BasicRequest::Data
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

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            userId(data.userId),
            keyId(data.keyId),
            body(data.body),
            signature(data.signature),
            duplicationAvoider(data.duplicationAvoider)
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
    LoginBySignatureRequest() = default;
    LoginBySignatureRequest(const LoginBySignatureRequest& loginBySignatureRequest) = default;
    LoginBySignatureRequest(LoginBySignatureRequest&& loginBySignatureRequest) = default;
    ~LoginBySignatureRequest() GS2_OVERRIDE = default;

    LoginBySignatureRequest& operator=(const LoginBySignatureRequest& loginBySignatureRequest) = default;
    LoginBySignatureRequest& operator=(LoginBySignatureRequest&& loginBySignatureRequest) = default;

    LoginBySignatureRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(LoginBySignatureRequest);
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
    void setUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    LoginBySignatureRequest& withUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
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
    void setKeyId(StringHolder keyId)
    {
        ensureData().keyId.emplace(std::move(keyId));
    }

    /**
     * 署名の作成に使用した暗号鍵 のGRNを設定
     *
     * @param keyId 署名の作成に使用した暗号鍵 のGRN
     */
    LoginBySignatureRequest& withKeyId(StringHolder keyId)
    {
        ensureData().keyId.emplace(std::move(keyId));
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
    void setBody(StringHolder body)
    {
        ensureData().body.emplace(std::move(body));
    }

    /**
     * アカウント認証情報の署名対象を設定
     *
     * @param body アカウント認証情報の署名対象
     */
    LoginBySignatureRequest& withBody(StringHolder body)
    {
        ensureData().body.emplace(std::move(body));
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
    void setSignature(StringHolder signature)
    {
        ensureData().signature.emplace(std::move(signature));
    }

    /**
     * 署名を設定
     *
     * @param signature 署名
     */
    LoginBySignatureRequest& withSignature(StringHolder signature)
    {
        ensureData().signature.emplace(std::move(signature));
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
    void setDuplicationAvoider(StringHolder duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(std::move(duplicationAvoider));
    }

    /**
     * 重複実行回避機能に使用するIDを設定
     *
     * @param duplicationAvoider 重複実行回避機能に使用するID
     */
    LoginBySignatureRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(std::move(duplicationAvoider));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    LoginBySignatureRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    LoginBySignatureRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_AUTH_CONTROL_LOGINBYSIGNATUREREQUEST_HPP_