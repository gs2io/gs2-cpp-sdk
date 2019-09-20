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

#ifndef GS2_ACCOUNT_CONTROL_CREATENAMESPACEREQUEST_HPP_
#define GS2_ACCOUNT_CONTROL_CREATENAMESPACEREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/account/Gs2AccountConst.hpp>
#include <gs2/account/model/model.hpp>
#include <memory>

namespace gs2 { namespace account
{

/**
 * ネームスペースを新規作成 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateNamespaceRequest : public Gs2BasicRequest, public Gs2Account
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> name;
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
            name(data.name),
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
    CreateNamespaceRequest() = default;
    CreateNamespaceRequest(const CreateNamespaceRequest& createNamespaceRequest) = default;
    CreateNamespaceRequest(CreateNamespaceRequest&& createNamespaceRequest) = default;
    ~CreateNamespaceRequest() GS2_OVERRIDE = default;

    CreateNamespaceRequest& operator=(const CreateNamespaceRequest& createNamespaceRequest) = default;
    CreateNamespaceRequest& operator=(CreateNamespaceRequest&& createNamespaceRequest) = default;

    CreateNamespaceRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CreateNamespaceRequest);
    }

    const CreateNamespaceRequest* operator->() const
    {
        return this;
    }

    CreateNamespaceRequest* operator->()
    {
        return this;
    }

    /**
     * ネームスペース名を取得
     *
     * @return ネームスペース名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * ネームスペース名を設定
     *
     * @param name ネームスペース名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * ネームスペース名を設定
     *
     * @param name ネームスペース名
     */
    CreateNamespaceRequest& withName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
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
    CreateNamespaceRequest& withDescription(StringHolder description)
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
    CreateNamespaceRequest& withChangePasswordIfTakeOver(Bool changePasswordIfTakeOver)
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
    CreateNamespaceRequest& withCreateAccountScript(ScriptSetting createAccountScript)
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
    CreateNamespaceRequest& withAuthenticationScript(ScriptSetting authenticationScript)
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
    CreateNamespaceRequest& withCreateTakeOverScript(ScriptSetting createTakeOverScript)
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
    CreateNamespaceRequest& withDoTakeOverScript(ScriptSetting doTakeOverScript)
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
    CreateNamespaceRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateNamespaceRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_ACCOUNT_CONTROL_CREATENAMESPACEREQUEST_HPP_