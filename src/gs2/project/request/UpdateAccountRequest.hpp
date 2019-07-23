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

#ifndef GS2_PROJECT_CONTROL_UPDATEACCOUNTREQUEST_HPP_
#define GS2_PROJECT_CONTROL_UPDATEACCOUNTREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ProjectConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace project
{

/**
 * GS2アカウントを更新します のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateAccountRequest : public Gs2BasicRequest, public Gs2Project
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** メールアドレス */
        optional<StringHolder> email;
        /** フルネーム */
        optional<StringHolder> fullName;
        /** 会社名 */
        optional<StringHolder> companyName;
        /** パスワード */
        optional<StringHolder> password;
        /** GS2アカウントトークン */
        optional<StringHolder> accountToken;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            email(data.email),
            fullName(data.fullName),
            companyName(data.companyName),
            password(data.password),
            accountToken(data.accountToken)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            email(std::move(data.email)),
            fullName(std::move(data.fullName)),
            companyName(std::move(data.companyName)),
            password(std::move(data.password)),
            accountToken(std::move(data.accountToken))
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
    UpdateAccountRequest() :
        m_pData(nullptr)
    {}

    UpdateAccountRequest(const UpdateAccountRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Project(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateAccountRequest(UpdateAccountRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Project(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateAccountRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateAccountRequest& operator=(const UpdateAccountRequest& updateAccountRequest)
    {
        Gs2BasicRequest::operator=(updateAccountRequest);
        Gs2Project::operator=(updateAccountRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateAccountRequest.m_pData);

        return *this;
    }

    UpdateAccountRequest& operator=(UpdateAccountRequest&& updateAccountRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateAccountRequest));
        Gs2Project::operator=(std::move(updateAccountRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateAccountRequest.m_pData;
        updateAccountRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateAccountRequest* operator->() const
    {
        return this;
    }

    UpdateAccountRequest* operator->()
    {
        return this;
    }
    /**
     * メールアドレスを取得
     *
     * @return メールアドレス
     */
    const optional<StringHolder>& getEmail() const
    {
        return ensureData().email;
    }

    /**
     * メールアドレスを設定
     *
     * @param email メールアドレス
     */
    void setEmail(const Char* email)
    {
        ensureData().email.emplace(email);
    }

    /**
     * メールアドレスを設定
     *
     * @param email メールアドレス
     */
    UpdateAccountRequest& withEmail(const Char* email)
    {
        ensureData().email.emplace(email);
        return *this;
    }

    /**
     * フルネームを取得
     *
     * @return フルネーム
     */
    const optional<StringHolder>& getFullName() const
    {
        return ensureData().fullName;
    }

    /**
     * フルネームを設定
     *
     * @param fullName フルネーム
     */
    void setFullName(const Char* fullName)
    {
        ensureData().fullName.emplace(fullName);
    }

    /**
     * フルネームを設定
     *
     * @param fullName フルネーム
     */
    UpdateAccountRequest& withFullName(const Char* fullName)
    {
        ensureData().fullName.emplace(fullName);
        return *this;
    }

    /**
     * 会社名を取得
     *
     * @return 会社名
     */
    const optional<StringHolder>& getCompanyName() const
    {
        return ensureData().companyName;
    }

    /**
     * 会社名を設定
     *
     * @param companyName 会社名
     */
    void setCompanyName(const Char* companyName)
    {
        ensureData().companyName.emplace(companyName);
    }

    /**
     * 会社名を設定
     *
     * @param companyName 会社名
     */
    UpdateAccountRequest& withCompanyName(const Char* companyName)
    {
        ensureData().companyName.emplace(companyName);
        return *this;
    }

    /**
     * パスワードを取得
     *
     * @return パスワード
     */
    const optional<StringHolder>& getPassword() const
    {
        return ensureData().password;
    }

    /**
     * パスワードを設定
     *
     * @param password パスワード
     */
    void setPassword(const Char* password)
    {
        ensureData().password.emplace(password);
    }

    /**
     * パスワードを設定
     *
     * @param password パスワード
     */
    UpdateAccountRequest& withPassword(const Char* password)
    {
        ensureData().password.emplace(password);
        return *this;
    }

    /**
     * GS2アカウントトークンを取得
     *
     * @return GS2アカウントトークン
     */
    const optional<StringHolder>& getAccountToken() const
    {
        return ensureData().accountToken;
    }

    /**
     * GS2アカウントトークンを設定
     *
     * @param accountToken GS2アカウントトークン
     */
    void setAccountToken(const Char* accountToken)
    {
        ensureData().accountToken.emplace(accountToken);
    }

    /**
     * GS2アカウントトークンを設定
     *
     * @param accountToken GS2アカウントトークン
     */
    UpdateAccountRequest& withAccountToken(const Char* accountToken)
    {
        ensureData().accountToken.emplace(accountToken);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateAccountRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateAccountRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateAccountRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateAccountRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_PROJECT_CONTROL_UPDATEACCOUNTREQUEST_HPP_