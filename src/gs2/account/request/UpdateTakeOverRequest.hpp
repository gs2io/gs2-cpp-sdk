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

#ifndef GS2_ACCOUNT_CONTROL_UPDATETAKEOVERREQUEST_HPP_
#define GS2_ACCOUNT_CONTROL_UPDATETAKEOVERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2AccountConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace account
{

/**
 * 引き継ぎ設定を更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateTakeOverRequest : public Gs2BasicRequest, public Gs2Account
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** アクセストークン */
        optional<StringHolder> accessToken;
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** スロット番号 */
        optional<Int32> type;
        /** 古いパスワード */
        optional<StringHolder> oldPassword;
        /** 新しいパスワード */
        optional<StringHolder> password;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            accessToken(data.accessToken),
            namespaceName(data.namespaceName),
            type(data.type),
            oldPassword(data.oldPassword),
            password(data.password),
            duplicationAvoider(data.duplicationAvoider)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            accessToken(std::move(data.accessToken)),
            namespaceName(std::move(data.namespaceName)),
            type(std::move(data.type)),
            oldPassword(std::move(data.oldPassword)),
            password(std::move(data.password)),
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
    UpdateTakeOverRequest() :
        m_pData(nullptr)
    {}

    UpdateTakeOverRequest(const UpdateTakeOverRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Account(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateTakeOverRequest(UpdateTakeOverRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Account(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateTakeOverRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateTakeOverRequest& operator=(const UpdateTakeOverRequest& updateTakeOverRequest)
    {
        Gs2BasicRequest::operator=(updateTakeOverRequest);
        Gs2Account::operator=(updateTakeOverRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateTakeOverRequest.m_pData);

        return *this;
    }

    UpdateTakeOverRequest& operator=(UpdateTakeOverRequest&& updateTakeOverRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateTakeOverRequest));
        Gs2Account::operator=(std::move(updateTakeOverRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateTakeOverRequest.m_pData;
        updateTakeOverRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateTakeOverRequest* operator->() const
    {
        return this;
    }

    UpdateTakeOverRequest* operator->()
    {
        return this;
    }

    /**
     * アクセストークンを取得。
     *
     * @return アクセストークン
     */
    const gs2::optional<StringHolder>& getAccessToken() const {
        return ensureData().accessToken;
    }

    /**
     * アクセストークンを設定。
     *
     * @param accessToken アクセストークン
     */
    void setAccessToken(const Char* accessToken) {
        ensureData().accessToken.emplace(accessToken);
    }

    /**
     * アクセストークンを設定。
     *
     * @param accessToken アクセストークン
     * @return this
     */
    UpdateTakeOverRequest& withAccessToken(const Char* accessToken) {
        setAccessToken(accessToken);
        return *this;
    }

    /**
     * ネームスペース名を取得
     *
     * @return ネームスペース名
     */
    const optional<StringHolder>& getNamespaceName() const
    {
        return ensureData().namespaceName;
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    void setNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    UpdateTakeOverRequest& withNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
        return *this;
    }

    /**
     * スロット番号を取得
     *
     * @return スロット番号
     */
    const optional<Int32>& getType() const
    {
        return ensureData().type;
    }

    /**
     * スロット番号を設定
     *
     * @param type スロット番号
     */
    void setType(Int32 type)
    {
        ensureData().type.emplace(type);
    }

    /**
     * スロット番号を設定
     *
     * @param type スロット番号
     */
    UpdateTakeOverRequest& withType(Int32 type)
    {
        ensureData().type.emplace(type);
        return *this;
    }

    /**
     * 古いパスワードを取得
     *
     * @return 古いパスワード
     */
    const optional<StringHolder>& getOldPassword() const
    {
        return ensureData().oldPassword;
    }

    /**
     * 古いパスワードを設定
     *
     * @param oldPassword 古いパスワード
     */
    void setOldPassword(const Char* oldPassword)
    {
        ensureData().oldPassword.emplace(oldPassword);
    }

    /**
     * 古いパスワードを設定
     *
     * @param oldPassword 古いパスワード
     */
    UpdateTakeOverRequest& withOldPassword(const Char* oldPassword)
    {
        ensureData().oldPassword.emplace(oldPassword);
        return *this;
    }

    /**
     * 新しいパスワードを取得
     *
     * @return 新しいパスワード
     */
    const optional<StringHolder>& getPassword() const
    {
        return ensureData().password;
    }

    /**
     * 新しいパスワードを設定
     *
     * @param password 新しいパスワード
     */
    void setPassword(const Char* password)
    {
        ensureData().password.emplace(password);
    }

    /**
     * 新しいパスワードを設定
     *
     * @param password 新しいパスワード
     */
    UpdateTakeOverRequest& withPassword(const Char* password)
    {
        ensureData().password.emplace(password);
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
    UpdateTakeOverRequest& withDuplicationAvoider(const Char* duplicationAvoider)
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
    UpdateTakeOverRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateTakeOverRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateTakeOverRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateTakeOverRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_ACCOUNT_CONTROL_UPDATETAKEOVERREQUEST_HPP_