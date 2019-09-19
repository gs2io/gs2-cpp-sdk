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
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ProjectConst.hpp"
#include "../model/model.hpp"
#include <memory>

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
    class Data : public Gs2BasicRequest::Data
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

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            email(data.email),
            fullName(data.fullName),
            companyName(data.companyName),
            password(data.password),
            accountToken(data.accountToken)
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
    UpdateAccountRequest() = default;
    UpdateAccountRequest(const UpdateAccountRequest& updateAccountRequest) = default;
    UpdateAccountRequest(UpdateAccountRequest&& updateAccountRequest) = default;
    ~UpdateAccountRequest() GS2_OVERRIDE = default;

    UpdateAccountRequest& operator=(const UpdateAccountRequest& updateAccountRequest) = default;
    UpdateAccountRequest& operator=(UpdateAccountRequest&& updateAccountRequest) = default;

    UpdateAccountRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(UpdateAccountRequest);
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
    void setEmail(StringHolder email)
    {
        ensureData().email.emplace(std::move(email));
    }

    /**
     * メールアドレスを設定
     *
     * @param email メールアドレス
     */
    UpdateAccountRequest& withEmail(StringHolder email)
    {
        ensureData().email.emplace(std::move(email));
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
    void setFullName(StringHolder fullName)
    {
        ensureData().fullName.emplace(std::move(fullName));
    }

    /**
     * フルネームを設定
     *
     * @param fullName フルネーム
     */
    UpdateAccountRequest& withFullName(StringHolder fullName)
    {
        ensureData().fullName.emplace(std::move(fullName));
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
    void setCompanyName(StringHolder companyName)
    {
        ensureData().companyName.emplace(std::move(companyName));
    }

    /**
     * 会社名を設定
     *
     * @param companyName 会社名
     */
    UpdateAccountRequest& withCompanyName(StringHolder companyName)
    {
        ensureData().companyName.emplace(std::move(companyName));
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
    void setPassword(StringHolder password)
    {
        ensureData().password.emplace(std::move(password));
    }

    /**
     * パスワードを設定
     *
     * @param password パスワード
     */
    UpdateAccountRequest& withPassword(StringHolder password)
    {
        ensureData().password.emplace(std::move(password));
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
    void setAccountToken(StringHolder accountToken)
    {
        ensureData().accountToken.emplace(std::move(accountToken));
    }

    /**
     * GS2アカウントトークンを設定
     *
     * @param accountToken GS2アカウントトークン
     */
    UpdateAccountRequest& withAccountToken(StringHolder accountToken)
    {
        ensureData().accountToken.emplace(std::move(accountToken));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateAccountRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateAccountRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_PROJECT_CONTROL_UPDATEACCOUNTREQUEST_HPP_