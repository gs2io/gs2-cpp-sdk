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

#ifndef GS2_ACCOUNT_CONTROL_UPDATENAMESPACEREQUEST_HPP_
#define GS2_ACCOUNT_CONTROL_UPDATENAMESPACEREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2AccountConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace account
{

/**
 * ネームスペースを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateNamespaceRequest : public Gs2BasicRequest, public Gs2Account
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** 説明文 */
        optional<StringHolder> description;
        /** アカウント引き継ぎ時にパスワードを変更するか */
        optional<Bool> changePasswordIfTakeOver;
        /** アカウント新規作成したときに実行するスクリプト */
        optional<ScriptSetting> createAccountScript;
        /** 認証したときに実行するスクリプト */
        optional<ScriptSetting> authenticationScript;
        /** 引き継ぎ情報登録したときに実行するスクリプト */
        optional<ScriptSetting> createTakeOverScript;
        /** 引き継ぎ実行したときに実行するスクリプト */
        optional<ScriptSetting> doTakeOverScript;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
            description(data.description),
            changePasswordIfTakeOver(data.changePasswordIfTakeOver),
            createAccountScript(data.createAccountScript),
            authenticationScript(data.authenticationScript),
            createTakeOverScript(data.createTakeOverScript),
            doTakeOverScript(data.doTakeOverScript)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
            description(std::move(data.description)),
            changePasswordIfTakeOver(std::move(data.changePasswordIfTakeOver)),
            createAccountScript(std::move(data.createAccountScript)),
            authenticationScript(std::move(data.authenticationScript)),
            createTakeOverScript(std::move(data.createTakeOverScript)),
            doTakeOverScript(std::move(data.doTakeOverScript))
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
    UpdateNamespaceRequest() :
        m_pData(nullptr)
    {}

    UpdateNamespaceRequest(const UpdateNamespaceRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Account(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateNamespaceRequest(UpdateNamespaceRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Account(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateNamespaceRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateNamespaceRequest& operator=(const UpdateNamespaceRequest& updateNamespaceRequest)
    {
        Gs2BasicRequest::operator=(updateNamespaceRequest);
        Gs2Account::operator=(updateNamespaceRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateNamespaceRequest.m_pData);

        return *this;
    }

    UpdateNamespaceRequest& operator=(UpdateNamespaceRequest&& updateNamespaceRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateNamespaceRequest));
        Gs2Account::operator=(std::move(updateNamespaceRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateNamespaceRequest.m_pData;
        updateNamespaceRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateNamespaceRequest* operator->() const
    {
        return this;
    }

    UpdateNamespaceRequest* operator->()
    {
        return this;
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
    UpdateNamespaceRequest& withNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
        return *this;
    }

    /**
     * 説明文を取得
     *
     * @return 説明文
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 説明文を設定
     *
     * @param description 説明文
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * 説明文を設定
     *
     * @param description 説明文
     */
    UpdateNamespaceRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
        return *this;
    }

    /**
     * アカウント引き継ぎ時にパスワードを変更するかを取得
     *
     * @return アカウント引き継ぎ時にパスワードを変更するか
     */
    const optional<Bool>& getChangePasswordIfTakeOver() const
    {
        return ensureData().changePasswordIfTakeOver;
    }

    /**
     * アカウント引き継ぎ時にパスワードを変更するかを設定
     *
     * @param changePasswordIfTakeOver アカウント引き継ぎ時にパスワードを変更するか
     */
    void setChangePasswordIfTakeOver(Bool changePasswordIfTakeOver)
    {
        ensureData().changePasswordIfTakeOver.emplace(changePasswordIfTakeOver);
    }

    /**
     * アカウント引き継ぎ時にパスワードを変更するかを設定
     *
     * @param changePasswordIfTakeOver アカウント引き継ぎ時にパスワードを変更するか
     */
    UpdateNamespaceRequest& withChangePasswordIfTakeOver(Bool changePasswordIfTakeOver)
    {
        ensureData().changePasswordIfTakeOver.emplace(changePasswordIfTakeOver);
        return *this;
    }

    /**
     * アカウント新規作成したときに実行するスクリプトを取得
     *
     * @return アカウント新規作成したときに実行するスクリプト
     */
    const optional<ScriptSetting>& getCreateAccountScript() const
    {
        return ensureData().createAccountScript;
    }

    /**
     * アカウント新規作成したときに実行するスクリプトを設定
     *
     * @param createAccountScript アカウント新規作成したときに実行するスクリプト
     */
    void setCreateAccountScript(const ScriptSetting& createAccountScript)
    {
        ensureData().createAccountScript.emplace(createAccountScript);
    }

    /**
     * アカウント新規作成したときに実行するスクリプトを設定
     *
     * @param createAccountScript アカウント新規作成したときに実行するスクリプト
     */
    UpdateNamespaceRequest& withCreateAccountScript(const ScriptSetting& createAccountScript)
    {
        ensureData().createAccountScript.emplace(createAccountScript);
        return *this;
    }

    /**
     * 認証したときに実行するスクリプトを取得
     *
     * @return 認証したときに実行するスクリプト
     */
    const optional<ScriptSetting>& getAuthenticationScript() const
    {
        return ensureData().authenticationScript;
    }

    /**
     * 認証したときに実行するスクリプトを設定
     *
     * @param authenticationScript 認証したときに実行するスクリプト
     */
    void setAuthenticationScript(const ScriptSetting& authenticationScript)
    {
        ensureData().authenticationScript.emplace(authenticationScript);
    }

    /**
     * 認証したときに実行するスクリプトを設定
     *
     * @param authenticationScript 認証したときに実行するスクリプト
     */
    UpdateNamespaceRequest& withAuthenticationScript(const ScriptSetting& authenticationScript)
    {
        ensureData().authenticationScript.emplace(authenticationScript);
        return *this;
    }

    /**
     * 引き継ぎ情報登録したときに実行するスクリプトを取得
     *
     * @return 引き継ぎ情報登録したときに実行するスクリプト
     */
    const optional<ScriptSetting>& getCreateTakeOverScript() const
    {
        return ensureData().createTakeOverScript;
    }

    /**
     * 引き継ぎ情報登録したときに実行するスクリプトを設定
     *
     * @param createTakeOverScript 引き継ぎ情報登録したときに実行するスクリプト
     */
    void setCreateTakeOverScript(const ScriptSetting& createTakeOverScript)
    {
        ensureData().createTakeOverScript.emplace(createTakeOverScript);
    }

    /**
     * 引き継ぎ情報登録したときに実行するスクリプトを設定
     *
     * @param createTakeOverScript 引き継ぎ情報登録したときに実行するスクリプト
     */
    UpdateNamespaceRequest& withCreateTakeOverScript(const ScriptSetting& createTakeOverScript)
    {
        ensureData().createTakeOverScript.emplace(createTakeOverScript);
        return *this;
    }

    /**
     * 引き継ぎ実行したときに実行するスクリプトを取得
     *
     * @return 引き継ぎ実行したときに実行するスクリプト
     */
    const optional<ScriptSetting>& getDoTakeOverScript() const
    {
        return ensureData().doTakeOverScript;
    }

    /**
     * 引き継ぎ実行したときに実行するスクリプトを設定
     *
     * @param doTakeOverScript 引き継ぎ実行したときに実行するスクリプト
     */
    void setDoTakeOverScript(const ScriptSetting& doTakeOverScript)
    {
        ensureData().doTakeOverScript.emplace(doTakeOverScript);
    }

    /**
     * 引き継ぎ実行したときに実行するスクリプトを設定
     *
     * @param doTakeOverScript 引き継ぎ実行したときに実行するスクリプト
     */
    UpdateNamespaceRequest& withDoTakeOverScript(const ScriptSetting& doTakeOverScript)
    {
        ensureData().doTakeOverScript.emplace(doTakeOverScript);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateNamespaceRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateNamespaceRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateNamespaceRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateNamespaceRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_ACCOUNT_CONTROL_UPDATENAMESPACEREQUEST_HPP_