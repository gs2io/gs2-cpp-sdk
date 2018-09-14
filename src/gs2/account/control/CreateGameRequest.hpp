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

#ifndef GS2_ACCOUNT_CONTROL_CREATEGAMEREQUEST_HPP_
#define GS2_ACCOUNT_CONTROL_CREATEGAMEREQUEST_HPP_

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
class CreateGameRequest : public Gs2BasicRequest, public Gs2Account
{
public:
    constexpr static const Char* const FUNCTION = "CreateGame";

private:
    class Data : public Gs2Object
    {
    public:
        /** ゲームの名前 */
        optional<StringHolder> name;
        /** ゲームの説明 */
        optional<StringHolder> description;
        /** ゲームのサービスクラス */
        optional<StringHolder> serviceClass;
        /** 引き継ぎ時にアカウントのパスワードを変更するか */
        optional<Bool> changePasswordIfTakeOver;
        /** アカウント新規作成時 に実行されるGS2-Script */
        optional<StringHolder> createAccountTriggerScript;
        /** アカウント新規作成完了時 に実行されるGS2-Script */
        optional<StringHolder> createAccountDoneTriggerScript;
        /** 認証時 に実行されるGS2-Script */
        optional<StringHolder> authenticationTriggerScript;
        /** 認証完了時 に実行されるGS2-Script */
        optional<StringHolder> authenticationDoneTriggerScript;
        /** 引き継ぎ情報登録時 に実行されるGS2-Script */
        optional<StringHolder> createTakeOverTriggerScript;
        /** 引き継ぎ情報登録完了時 に実行されるGS2-Script */
        optional<StringHolder> createTakeOverDoneTriggerScript;
        /** 引き継ぎ実行時 に実行されるGS2-Script */
        optional<StringHolder> doTakeOverTriggerScript;
        /** 引き継ぎ実行完了時 に実行されるGS2-Script */
        optional<StringHolder> doTakeOverDoneTriggerScript;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            name(data.name),
            description(data.description),
            serviceClass(data.serviceClass),
            changePasswordIfTakeOver(data.changePasswordIfTakeOver),
            createAccountTriggerScript(data.createAccountTriggerScript),
            createAccountDoneTriggerScript(data.createAccountDoneTriggerScript),
            authenticationTriggerScript(data.authenticationTriggerScript),
            authenticationDoneTriggerScript(data.authenticationDoneTriggerScript),
            createTakeOverTriggerScript(data.createTakeOverTriggerScript),
            createTakeOverDoneTriggerScript(data.createTakeOverDoneTriggerScript),
            doTakeOverTriggerScript(data.doTakeOverTriggerScript),
            doTakeOverDoneTriggerScript(data.doTakeOverDoneTriggerScript)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            serviceClass(std::move(data.serviceClass)),
            changePasswordIfTakeOver(std::move(data.changePasswordIfTakeOver)),
            createAccountTriggerScript(std::move(data.createAccountTriggerScript)),
            createAccountDoneTriggerScript(std::move(data.createAccountDoneTriggerScript)),
            authenticationTriggerScript(std::move(data.authenticationTriggerScript)),
            authenticationDoneTriggerScript(std::move(data.authenticationDoneTriggerScript)),
            createTakeOverTriggerScript(std::move(data.createTakeOverTriggerScript)),
            createTakeOverDoneTriggerScript(std::move(data.createTakeOverDoneTriggerScript)),
            doTakeOverTriggerScript(std::move(data.doTakeOverTriggerScript)),
            doTakeOverDoneTriggerScript(std::move(data.doTakeOverDoneTriggerScript))
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
    CreateGameRequest() :
        m_pData(nullptr)
    {}

    CreateGameRequest(const CreateGameRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Account(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CreateGameRequest(CreateGameRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Account(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CreateGameRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateGameRequest& operator=(const CreateGameRequest& createGameRequest)
    {
        Gs2BasicRequest::operator=(createGameRequest);
        Gs2Account::operator=(createGameRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createGameRequest.m_pData);

        return *this;
    }

    CreateGameRequest& operator=(CreateGameRequest&& createGameRequest)
    {
        Gs2BasicRequest::operator=(std::move(createGameRequest));
        Gs2Account::operator=(std::move(createGameRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createGameRequest.m_pData;
        createGameRequest.m_pData = nullptr;

        return *this;
    }

    const CreateGameRequest* operator->() const
    {
        return this;
    }

    CreateGameRequest* operator->()
    {
        return this;
    }

    /**
     * ゲームの名前を取得
     *
     * @return ゲームの名前
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * ゲームの名前を設定
     *
     * @param name ゲームの名前
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * ゲームの名前を設定
     *
     * @param name ゲームの名前
     */
    CreateGameRequest& withName(const Char* name)
    {
        ensureData().name.emplace(name);
        return *this;
    }

    /**
     * ゲームの説明を取得
     *
     * @return ゲームの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * ゲームの説明を設定
     *
     * @param description ゲームの説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * ゲームの説明を設定
     *
     * @param description ゲームの説明
     */
    CreateGameRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
        return *this;
    }

    /**
     * ゲームのサービスクラスを取得
     *
     * @return ゲームのサービスクラス
     */
    const optional<StringHolder>& getServiceClass() const
    {
        return ensureData().serviceClass;
    }

    /**
     * ゲームのサービスクラスを設定
     *
     * @param serviceClass ゲームのサービスクラス
     */
    void setServiceClass(const Char* serviceClass)
    {
        ensureData().serviceClass.emplace(serviceClass);
    }

    /**
     * ゲームのサービスクラスを設定
     *
     * @param serviceClass ゲームのサービスクラス
     */
    CreateGameRequest& withServiceClass(const Char* serviceClass)
    {
        ensureData().serviceClass.emplace(serviceClass);
        return *this;
    }

    /**
     * 引き継ぎ時にアカウントのパスワードを変更するかを取得
     *
     * @return 引き継ぎ時にアカウントのパスワードを変更するか
     */
    const optional<Bool>& getChangePasswordIfTakeOver() const
    {
        return ensureData().changePasswordIfTakeOver;
    }

    /**
     * 引き継ぎ時にアカウントのパスワードを変更するかを設定
     *
     * @param changePasswordIfTakeOver 引き継ぎ時にアカウントのパスワードを変更するか
     */
    void setChangePasswordIfTakeOver(Bool changePasswordIfTakeOver)
    {
        ensureData().changePasswordIfTakeOver.emplace(changePasswordIfTakeOver);
    }

    /**
     * 引き継ぎ時にアカウントのパスワードを変更するかを設定
     *
     * @param changePasswordIfTakeOver 引き継ぎ時にアカウントのパスワードを変更するか
     */
    CreateGameRequest& withChangePasswordIfTakeOver(Bool changePasswordIfTakeOver)
    {
        ensureData().changePasswordIfTakeOver.emplace(changePasswordIfTakeOver);
        return *this;
    }

    /**
     * アカウント新規作成時 に実行されるGS2-Scriptを取得
     *
     * @return アカウント新規作成時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getCreateAccountTriggerScript() const
    {
        return ensureData().createAccountTriggerScript;
    }

    /**
     * アカウント新規作成時 に実行されるGS2-Scriptを設定
     *
     * @param createAccountTriggerScript アカウント新規作成時 に実行されるGS2-Script
     */
    void setCreateAccountTriggerScript(const Char* createAccountTriggerScript)
    {
        ensureData().createAccountTriggerScript.emplace(createAccountTriggerScript);
    }

    /**
     * アカウント新規作成時 に実行されるGS2-Scriptを設定
     *
     * @param createAccountTriggerScript アカウント新規作成時 に実行されるGS2-Script
     */
    CreateGameRequest& withCreateAccountTriggerScript(const Char* createAccountTriggerScript)
    {
        ensureData().createAccountTriggerScript.emplace(createAccountTriggerScript);
        return *this;
    }

    /**
     * アカウント新規作成完了時 に実行されるGS2-Scriptを取得
     *
     * @return アカウント新規作成完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getCreateAccountDoneTriggerScript() const
    {
        return ensureData().createAccountDoneTriggerScript;
    }

    /**
     * アカウント新規作成完了時 に実行されるGS2-Scriptを設定
     *
     * @param createAccountDoneTriggerScript アカウント新規作成完了時 に実行されるGS2-Script
     */
    void setCreateAccountDoneTriggerScript(const Char* createAccountDoneTriggerScript)
    {
        ensureData().createAccountDoneTriggerScript.emplace(createAccountDoneTriggerScript);
    }

    /**
     * アカウント新規作成完了時 に実行されるGS2-Scriptを設定
     *
     * @param createAccountDoneTriggerScript アカウント新規作成完了時 に実行されるGS2-Script
     */
    CreateGameRequest& withCreateAccountDoneTriggerScript(const Char* createAccountDoneTriggerScript)
    {
        ensureData().createAccountDoneTriggerScript.emplace(createAccountDoneTriggerScript);
        return *this;
    }

    /**
     * 認証時 に実行されるGS2-Scriptを取得
     *
     * @return 認証時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getAuthenticationTriggerScript() const
    {
        return ensureData().authenticationTriggerScript;
    }

    /**
     * 認証時 に実行されるGS2-Scriptを設定
     *
     * @param authenticationTriggerScript 認証時 に実行されるGS2-Script
     */
    void setAuthenticationTriggerScript(const Char* authenticationTriggerScript)
    {
        ensureData().authenticationTriggerScript.emplace(authenticationTriggerScript);
    }

    /**
     * 認証時 に実行されるGS2-Scriptを設定
     *
     * @param authenticationTriggerScript 認証時 に実行されるGS2-Script
     */
    CreateGameRequest& withAuthenticationTriggerScript(const Char* authenticationTriggerScript)
    {
        ensureData().authenticationTriggerScript.emplace(authenticationTriggerScript);
        return *this;
    }

    /**
     * 認証完了時 に実行されるGS2-Scriptを取得
     *
     * @return 認証完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getAuthenticationDoneTriggerScript() const
    {
        return ensureData().authenticationDoneTriggerScript;
    }

    /**
     * 認証完了時 に実行されるGS2-Scriptを設定
     *
     * @param authenticationDoneTriggerScript 認証完了時 に実行されるGS2-Script
     */
    void setAuthenticationDoneTriggerScript(const Char* authenticationDoneTriggerScript)
    {
        ensureData().authenticationDoneTriggerScript.emplace(authenticationDoneTriggerScript);
    }

    /**
     * 認証完了時 に実行されるGS2-Scriptを設定
     *
     * @param authenticationDoneTriggerScript 認証完了時 に実行されるGS2-Script
     */
    CreateGameRequest& withAuthenticationDoneTriggerScript(const Char* authenticationDoneTriggerScript)
    {
        ensureData().authenticationDoneTriggerScript.emplace(authenticationDoneTriggerScript);
        return *this;
    }

    /**
     * 引き継ぎ情報登録時 に実行されるGS2-Scriptを取得
     *
     * @return 引き継ぎ情報登録時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getCreateTakeOverTriggerScript() const
    {
        return ensureData().createTakeOverTriggerScript;
    }

    /**
     * 引き継ぎ情報登録時 に実行されるGS2-Scriptを設定
     *
     * @param createTakeOverTriggerScript 引き継ぎ情報登録時 に実行されるGS2-Script
     */
    void setCreateTakeOverTriggerScript(const Char* createTakeOverTriggerScript)
    {
        ensureData().createTakeOverTriggerScript.emplace(createTakeOverTriggerScript);
    }

    /**
     * 引き継ぎ情報登録時 に実行されるGS2-Scriptを設定
     *
     * @param createTakeOverTriggerScript 引き継ぎ情報登録時 に実行されるGS2-Script
     */
    CreateGameRequest& withCreateTakeOverTriggerScript(const Char* createTakeOverTriggerScript)
    {
        ensureData().createTakeOverTriggerScript.emplace(createTakeOverTriggerScript);
        return *this;
    }

    /**
     * 引き継ぎ情報登録完了時 に実行されるGS2-Scriptを取得
     *
     * @return 引き継ぎ情報登録完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getCreateTakeOverDoneTriggerScript() const
    {
        return ensureData().createTakeOverDoneTriggerScript;
    }

    /**
     * 引き継ぎ情報登録完了時 に実行されるGS2-Scriptを設定
     *
     * @param createTakeOverDoneTriggerScript 引き継ぎ情報登録完了時 に実行されるGS2-Script
     */
    void setCreateTakeOverDoneTriggerScript(const Char* createTakeOverDoneTriggerScript)
    {
        ensureData().createTakeOverDoneTriggerScript.emplace(createTakeOverDoneTriggerScript);
    }

    /**
     * 引き継ぎ情報登録完了時 に実行されるGS2-Scriptを設定
     *
     * @param createTakeOverDoneTriggerScript 引き継ぎ情報登録完了時 に実行されるGS2-Script
     */
    CreateGameRequest& withCreateTakeOverDoneTriggerScript(const Char* createTakeOverDoneTriggerScript)
    {
        ensureData().createTakeOverDoneTriggerScript.emplace(createTakeOverDoneTriggerScript);
        return *this;
    }

    /**
     * 引き継ぎ実行時 に実行されるGS2-Scriptを取得
     *
     * @return 引き継ぎ実行時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getDoTakeOverTriggerScript() const
    {
        return ensureData().doTakeOverTriggerScript;
    }

    /**
     * 引き継ぎ実行時 に実行されるGS2-Scriptを設定
     *
     * @param doTakeOverTriggerScript 引き継ぎ実行時 に実行されるGS2-Script
     */
    void setDoTakeOverTriggerScript(const Char* doTakeOverTriggerScript)
    {
        ensureData().doTakeOverTriggerScript.emplace(doTakeOverTriggerScript);
    }

    /**
     * 引き継ぎ実行時 に実行されるGS2-Scriptを設定
     *
     * @param doTakeOverTriggerScript 引き継ぎ実行時 に実行されるGS2-Script
     */
    CreateGameRequest& withDoTakeOverTriggerScript(const Char* doTakeOverTriggerScript)
    {
        ensureData().doTakeOverTriggerScript.emplace(doTakeOverTriggerScript);
        return *this;
    }

    /**
     * 引き継ぎ実行完了時 に実行されるGS2-Scriptを取得
     *
     * @return 引き継ぎ実行完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getDoTakeOverDoneTriggerScript() const
    {
        return ensureData().doTakeOverDoneTriggerScript;
    }

    /**
     * 引き継ぎ実行完了時 に実行されるGS2-Scriptを設定
     *
     * @param doTakeOverDoneTriggerScript 引き継ぎ実行完了時 に実行されるGS2-Script
     */
    void setDoTakeOverDoneTriggerScript(const Char* doTakeOverDoneTriggerScript)
    {
        ensureData().doTakeOverDoneTriggerScript.emplace(doTakeOverDoneTriggerScript);
    }

    /**
     * 引き継ぎ実行完了時 に実行されるGS2-Scriptを設定
     *
     * @param doTakeOverDoneTriggerScript 引き継ぎ実行完了時 に実行されるGS2-Script
     */
    CreateGameRequest& withDoTakeOverDoneTriggerScript(const Char* doTakeOverDoneTriggerScript)
    {
        ensureData().doTakeOverDoneTriggerScript.emplace(doTakeOverDoneTriggerScript);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreateGameRequest& withGs2ClientId(const Char* gs2ClientId)
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
    CreateGameRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    CreateGameRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateGameRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_ACCOUNT_CONTROL_CREATEGAMEREQUEST_HPP_