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
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2AccountConst.hpp"
#include "../model/model.hpp"
#include <memory>

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
    class Data : public Gs2BasicRequest::Data
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

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            description(data.description),
            changePasswordIfTakeOver(data.changePasswordIfTakeOver)
        {
            if (data.createAccountScript)
            {
                createAccountScript = data.createAccountScript->deepCopy();
            }
            if (data.authenticationScript)
            {
                authenticationScript = data.authenticationScript->deepCopy();
            }
            if (data.createTakeOverScript)
            {
                createTakeOverScript = data.createTakeOverScript->deepCopy();
            }
            if (data.doTakeOverScript)
            {
                doTakeOverScript = data.doTakeOverScript->deepCopy();
            }
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
    UpdateNamespaceRequest() = default;
    UpdateNamespaceRequest(const UpdateNamespaceRequest& updateNamespaceRequest) = default;
    UpdateNamespaceRequest(UpdateNamespaceRequest&& updateNamespaceRequest) = default;
    ~UpdateNamespaceRequest() GS2_OVERRIDE = default;

    UpdateNamespaceRequest& operator=(const UpdateNamespaceRequest& updateNamespaceRequest) = default;
    UpdateNamespaceRequest& operator=(UpdateNamespaceRequest&& updateNamespaceRequest) = default;

    UpdateNamespaceRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(UpdateNamespaceRequest);
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
    void setNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    UpdateNamespaceRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
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
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * 説明文を設定
     *
     * @param description 説明文
     */
    UpdateNamespaceRequest& withDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
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
    void setCreateAccountScript(ScriptSetting createAccountScript)
    {
        ensureData().createAccountScript.emplace(std::move(createAccountScript));
    }

    /**
     * アカウント新規作成したときに実行するスクリプトを設定
     *
     * @param createAccountScript アカウント新規作成したときに実行するスクリプト
     */
    UpdateNamespaceRequest& withCreateAccountScript(ScriptSetting createAccountScript)
    {
        ensureData().createAccountScript.emplace(std::move(createAccountScript));
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
    void setAuthenticationScript(ScriptSetting authenticationScript)
    {
        ensureData().authenticationScript.emplace(std::move(authenticationScript));
    }

    /**
     * 認証したときに実行するスクリプトを設定
     *
     * @param authenticationScript 認証したときに実行するスクリプト
     */
    UpdateNamespaceRequest& withAuthenticationScript(ScriptSetting authenticationScript)
    {
        ensureData().authenticationScript.emplace(std::move(authenticationScript));
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
    void setCreateTakeOverScript(ScriptSetting createTakeOverScript)
    {
        ensureData().createTakeOverScript.emplace(std::move(createTakeOverScript));
    }

    /**
     * 引き継ぎ情報登録したときに実行するスクリプトを設定
     *
     * @param createTakeOverScript 引き継ぎ情報登録したときに実行するスクリプト
     */
    UpdateNamespaceRequest& withCreateTakeOverScript(ScriptSetting createTakeOverScript)
    {
        ensureData().createTakeOverScript.emplace(std::move(createTakeOverScript));
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
    void setDoTakeOverScript(ScriptSetting doTakeOverScript)
    {
        ensureData().doTakeOverScript.emplace(std::move(doTakeOverScript));
    }

    /**
     * 引き継ぎ実行したときに実行するスクリプトを設定
     *
     * @param doTakeOverScript 引き継ぎ実行したときに実行するスクリプト
     */
    UpdateNamespaceRequest& withDoTakeOverScript(ScriptSetting doTakeOverScript)
    {
        ensureData().doTakeOverScript.emplace(std::move(doTakeOverScript));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateNamespaceRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateNamespaceRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_ACCOUNT_CONTROL_UPDATENAMESPACEREQUEST_HPP_