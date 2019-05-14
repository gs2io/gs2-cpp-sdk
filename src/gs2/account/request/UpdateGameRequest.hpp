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

#ifndef GS2_ACCOUNT_CONTROL_UPDATEGAMEREQUEST_HPP_
#define GS2_ACCOUNT_CONTROL_UPDATEGAMEREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2AccountConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace account
{

/**
 * ゲームを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateGameRequest : public Gs2BasicRequest, public Gs2Account
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** ゲーム名 */
        optional<StringHolder> gameName;
        /** 説明文 */
        optional<StringHolder> description;
        /** アカウント引き継ぎ時にパスワードを変更するか */
        optional<Bool> changePasswordIfTakeOver;
        /** アカウント新規作成時 に実行されるスクリプト のGRN */
        optional<StringHolder> createAccountTriggerScriptId;
        /** アカウント新規作成完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> createAccountDoneTriggerScriptId;
        /** アカウント新規作成完了時 にジョブが登録されるキュー のGRN */
        optional<StringHolder> createAccountDoneTriggerQueueId;
        /** 認証時 に実行されるスクリプト のGRN */
        optional<StringHolder> authenticationTriggerScriptId;
        /** 認証完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> authenticationDoneTriggerScriptId;
        /** 認証完了時 にジョブが登録されるキュー のGRN */
        optional<StringHolder> authenticationDoneTriggerQueueId;
        /** 引き継ぎ情報登録時 に実行されるスクリプト のGRN */
        optional<StringHolder> createTakeOverTriggerScriptId;
        /** 引き継ぎ情報登録完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> createTakeOverDoneTriggerScriptId;
        /** 引き継ぎ情報登録完了時 にジョブが登録されるキュー のGRN */
        optional<StringHolder> createTakeOverDoneTriggerQueueId;
        /** 引き継ぎ実行時 に実行されるスクリプト のGRN */
        optional<StringHolder> doTakeOverTriggerScriptId;
        /** 引き継ぎ実行完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> doTakeOverDoneTriggerScriptId;
        /** 引き継ぎ実行完了時 にジョブが登録されるキュー のGRN */
        optional<StringHolder> doTakeOverDoneTriggerQueueId;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            gameName(data.gameName),
            description(data.description),
            changePasswordIfTakeOver(data.changePasswordIfTakeOver),
            createAccountTriggerScriptId(data.createAccountTriggerScriptId),
            createAccountDoneTriggerScriptId(data.createAccountDoneTriggerScriptId),
            createAccountDoneTriggerQueueId(data.createAccountDoneTriggerQueueId),
            authenticationTriggerScriptId(data.authenticationTriggerScriptId),
            authenticationDoneTriggerScriptId(data.authenticationDoneTriggerScriptId),
            authenticationDoneTriggerQueueId(data.authenticationDoneTriggerQueueId),
            createTakeOverTriggerScriptId(data.createTakeOverTriggerScriptId),
            createTakeOverDoneTriggerScriptId(data.createTakeOverDoneTriggerScriptId),
            createTakeOverDoneTriggerQueueId(data.createTakeOverDoneTriggerQueueId),
            doTakeOverTriggerScriptId(data.doTakeOverTriggerScriptId),
            doTakeOverDoneTriggerScriptId(data.doTakeOverDoneTriggerScriptId),
            doTakeOverDoneTriggerQueueId(data.doTakeOverDoneTriggerQueueId)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            gameName(std::move(data.gameName)),
            description(std::move(data.description)),
            changePasswordIfTakeOver(std::move(data.changePasswordIfTakeOver)),
            createAccountTriggerScriptId(std::move(data.createAccountTriggerScriptId)),
            createAccountDoneTriggerScriptId(std::move(data.createAccountDoneTriggerScriptId)),
            createAccountDoneTriggerQueueId(std::move(data.createAccountDoneTriggerQueueId)),
            authenticationTriggerScriptId(std::move(data.authenticationTriggerScriptId)),
            authenticationDoneTriggerScriptId(std::move(data.authenticationDoneTriggerScriptId)),
            authenticationDoneTriggerQueueId(std::move(data.authenticationDoneTriggerQueueId)),
            createTakeOverTriggerScriptId(std::move(data.createTakeOverTriggerScriptId)),
            createTakeOverDoneTriggerScriptId(std::move(data.createTakeOverDoneTriggerScriptId)),
            createTakeOverDoneTriggerQueueId(std::move(data.createTakeOverDoneTriggerQueueId)),
            doTakeOverTriggerScriptId(std::move(data.doTakeOverTriggerScriptId)),
            doTakeOverDoneTriggerScriptId(std::move(data.doTakeOverDoneTriggerScriptId)),
            doTakeOverDoneTriggerQueueId(std::move(data.doTakeOverDoneTriggerQueueId))
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
    UpdateGameRequest() :
        m_pData(nullptr)
    {}

    UpdateGameRequest(const UpdateGameRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Account(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateGameRequest(UpdateGameRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Account(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateGameRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateGameRequest& operator=(const UpdateGameRequest& updateGameRequest)
    {
        Gs2BasicRequest::operator=(updateGameRequest);
        Gs2Account::operator=(updateGameRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateGameRequest.m_pData);

        return *this;
    }

    UpdateGameRequest& operator=(UpdateGameRequest&& updateGameRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateGameRequest));
        Gs2Account::operator=(std::move(updateGameRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateGameRequest.m_pData;
        updateGameRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateGameRequest* operator->() const
    {
        return this;
    }

    UpdateGameRequest* operator->()
    {
        return this;
    }
    /**
     * ゲーム名を取得
     *
     * @return ゲーム名
     */
    const optional<StringHolder>& getGameName() const
    {
        return ensureData().gameName;
    }

    /**
     * ゲーム名を設定
     *
     * @param gameName ゲーム名
     */
    void setGameName(const Char* gameName)
    {
        ensureData().gameName.emplace(gameName);
    }

    /**
     * ゲーム名を設定
     *
     * @param gameName ゲーム名
     */
    UpdateGameRequest& withGameName(const Char* gameName)
    {
        ensureData().gameName.emplace(gameName);
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
    UpdateGameRequest& withDescription(const Char* description)
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
    UpdateGameRequest& withChangePasswordIfTakeOver(Bool changePasswordIfTakeOver)
    {
        ensureData().changePasswordIfTakeOver.emplace(changePasswordIfTakeOver);
        return *this;
    }

    /**
     * アカウント新規作成時 に実行されるスクリプト のGRNを取得
     *
     * @return アカウント新規作成時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getCreateAccountTriggerScriptId() const
    {
        return ensureData().createAccountTriggerScriptId;
    }

    /**
     * アカウント新規作成時 に実行されるスクリプト のGRNを設定
     *
     * @param createAccountTriggerScriptId アカウント新規作成時 に実行されるスクリプト のGRN
     */
    void setCreateAccountTriggerScriptId(const Char* createAccountTriggerScriptId)
    {
        ensureData().createAccountTriggerScriptId.emplace(createAccountTriggerScriptId);
    }

    /**
     * アカウント新規作成時 に実行されるスクリプト のGRNを設定
     *
     * @param createAccountTriggerScriptId アカウント新規作成時 に実行されるスクリプト のGRN
     */
    UpdateGameRequest& withCreateAccountTriggerScriptId(const Char* createAccountTriggerScriptId)
    {
        ensureData().createAccountTriggerScriptId.emplace(createAccountTriggerScriptId);
        return *this;
    }

    /**
     * アカウント新規作成完了時 に実行されるスクリプト のGRNを取得
     *
     * @return アカウント新規作成完了時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getCreateAccountDoneTriggerScriptId() const
    {
        return ensureData().createAccountDoneTriggerScriptId;
    }

    /**
     * アカウント新規作成完了時 に実行されるスクリプト のGRNを設定
     *
     * @param createAccountDoneTriggerScriptId アカウント新規作成完了時 に実行されるスクリプト のGRN
     */
    void setCreateAccountDoneTriggerScriptId(const Char* createAccountDoneTriggerScriptId)
    {
        ensureData().createAccountDoneTriggerScriptId.emplace(createAccountDoneTriggerScriptId);
    }

    /**
     * アカウント新規作成完了時 に実行されるスクリプト のGRNを設定
     *
     * @param createAccountDoneTriggerScriptId アカウント新規作成完了時 に実行されるスクリプト のGRN
     */
    UpdateGameRequest& withCreateAccountDoneTriggerScriptId(const Char* createAccountDoneTriggerScriptId)
    {
        ensureData().createAccountDoneTriggerScriptId.emplace(createAccountDoneTriggerScriptId);
        return *this;
    }

    /**
     * アカウント新規作成完了時 にジョブが登録されるキュー のGRNを取得
     *
     * @return アカウント新規作成完了時 にジョブが登録されるキュー のGRN
     */
    const optional<StringHolder>& getCreateAccountDoneTriggerQueueId() const
    {
        return ensureData().createAccountDoneTriggerQueueId;
    }

    /**
     * アカウント新規作成完了時 にジョブが登録されるキュー のGRNを設定
     *
     * @param createAccountDoneTriggerQueueId アカウント新規作成完了時 にジョブが登録されるキュー のGRN
     */
    void setCreateAccountDoneTriggerQueueId(const Char* createAccountDoneTriggerQueueId)
    {
        ensureData().createAccountDoneTriggerQueueId.emplace(createAccountDoneTriggerQueueId);
    }

    /**
     * アカウント新規作成完了時 にジョブが登録されるキュー のGRNを設定
     *
     * @param createAccountDoneTriggerQueueId アカウント新規作成完了時 にジョブが登録されるキュー のGRN
     */
    UpdateGameRequest& withCreateAccountDoneTriggerQueueId(const Char* createAccountDoneTriggerQueueId)
    {
        ensureData().createAccountDoneTriggerQueueId.emplace(createAccountDoneTriggerQueueId);
        return *this;
    }

    /**
     * 認証時 に実行されるスクリプト のGRNを取得
     *
     * @return 認証時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getAuthenticationTriggerScriptId() const
    {
        return ensureData().authenticationTriggerScriptId;
    }

    /**
     * 認証時 に実行されるスクリプト のGRNを設定
     *
     * @param authenticationTriggerScriptId 認証時 に実行されるスクリプト のGRN
     */
    void setAuthenticationTriggerScriptId(const Char* authenticationTriggerScriptId)
    {
        ensureData().authenticationTriggerScriptId.emplace(authenticationTriggerScriptId);
    }

    /**
     * 認証時 に実行されるスクリプト のGRNを設定
     *
     * @param authenticationTriggerScriptId 認証時 に実行されるスクリプト のGRN
     */
    UpdateGameRequest& withAuthenticationTriggerScriptId(const Char* authenticationTriggerScriptId)
    {
        ensureData().authenticationTriggerScriptId.emplace(authenticationTriggerScriptId);
        return *this;
    }

    /**
     * 認証完了時 に実行されるスクリプト のGRNを取得
     *
     * @return 認証完了時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getAuthenticationDoneTriggerScriptId() const
    {
        return ensureData().authenticationDoneTriggerScriptId;
    }

    /**
     * 認証完了時 に実行されるスクリプト のGRNを設定
     *
     * @param authenticationDoneTriggerScriptId 認証完了時 に実行されるスクリプト のGRN
     */
    void setAuthenticationDoneTriggerScriptId(const Char* authenticationDoneTriggerScriptId)
    {
        ensureData().authenticationDoneTriggerScriptId.emplace(authenticationDoneTriggerScriptId);
    }

    /**
     * 認証完了時 に実行されるスクリプト のGRNを設定
     *
     * @param authenticationDoneTriggerScriptId 認証完了時 に実行されるスクリプト のGRN
     */
    UpdateGameRequest& withAuthenticationDoneTriggerScriptId(const Char* authenticationDoneTriggerScriptId)
    {
        ensureData().authenticationDoneTriggerScriptId.emplace(authenticationDoneTriggerScriptId);
        return *this;
    }

    /**
     * 認証完了時 にジョブが登録されるキュー のGRNを取得
     *
     * @return 認証完了時 にジョブが登録されるキュー のGRN
     */
    const optional<StringHolder>& getAuthenticationDoneTriggerQueueId() const
    {
        return ensureData().authenticationDoneTriggerQueueId;
    }

    /**
     * 認証完了時 にジョブが登録されるキュー のGRNを設定
     *
     * @param authenticationDoneTriggerQueueId 認証完了時 にジョブが登録されるキュー のGRN
     */
    void setAuthenticationDoneTriggerQueueId(const Char* authenticationDoneTriggerQueueId)
    {
        ensureData().authenticationDoneTriggerQueueId.emplace(authenticationDoneTriggerQueueId);
    }

    /**
     * 認証完了時 にジョブが登録されるキュー のGRNを設定
     *
     * @param authenticationDoneTriggerQueueId 認証完了時 にジョブが登録されるキュー のGRN
     */
    UpdateGameRequest& withAuthenticationDoneTriggerQueueId(const Char* authenticationDoneTriggerQueueId)
    {
        ensureData().authenticationDoneTriggerQueueId.emplace(authenticationDoneTriggerQueueId);
        return *this;
    }

    /**
     * 引き継ぎ情報登録時 に実行されるスクリプト のGRNを取得
     *
     * @return 引き継ぎ情報登録時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getCreateTakeOverTriggerScriptId() const
    {
        return ensureData().createTakeOverTriggerScriptId;
    }

    /**
     * 引き継ぎ情報登録時 に実行されるスクリプト のGRNを設定
     *
     * @param createTakeOverTriggerScriptId 引き継ぎ情報登録時 に実行されるスクリプト のGRN
     */
    void setCreateTakeOverTriggerScriptId(const Char* createTakeOverTriggerScriptId)
    {
        ensureData().createTakeOverTriggerScriptId.emplace(createTakeOverTriggerScriptId);
    }

    /**
     * 引き継ぎ情報登録時 に実行されるスクリプト のGRNを設定
     *
     * @param createTakeOverTriggerScriptId 引き継ぎ情報登録時 に実行されるスクリプト のGRN
     */
    UpdateGameRequest& withCreateTakeOverTriggerScriptId(const Char* createTakeOverTriggerScriptId)
    {
        ensureData().createTakeOverTriggerScriptId.emplace(createTakeOverTriggerScriptId);
        return *this;
    }

    /**
     * 引き継ぎ情報登録完了時 に実行されるスクリプト のGRNを取得
     *
     * @return 引き継ぎ情報登録完了時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getCreateTakeOverDoneTriggerScriptId() const
    {
        return ensureData().createTakeOverDoneTriggerScriptId;
    }

    /**
     * 引き継ぎ情報登録完了時 に実行されるスクリプト のGRNを設定
     *
     * @param createTakeOverDoneTriggerScriptId 引き継ぎ情報登録完了時 に実行されるスクリプト のGRN
     */
    void setCreateTakeOverDoneTriggerScriptId(const Char* createTakeOverDoneTriggerScriptId)
    {
        ensureData().createTakeOverDoneTriggerScriptId.emplace(createTakeOverDoneTriggerScriptId);
    }

    /**
     * 引き継ぎ情報登録完了時 に実行されるスクリプト のGRNを設定
     *
     * @param createTakeOverDoneTriggerScriptId 引き継ぎ情報登録完了時 に実行されるスクリプト のGRN
     */
    UpdateGameRequest& withCreateTakeOverDoneTriggerScriptId(const Char* createTakeOverDoneTriggerScriptId)
    {
        ensureData().createTakeOverDoneTriggerScriptId.emplace(createTakeOverDoneTriggerScriptId);
        return *this;
    }

    /**
     * 引き継ぎ情報登録完了時 にジョブが登録されるキュー のGRNを取得
     *
     * @return 引き継ぎ情報登録完了時 にジョブが登録されるキュー のGRN
     */
    const optional<StringHolder>& getCreateTakeOverDoneTriggerQueueId() const
    {
        return ensureData().createTakeOverDoneTriggerQueueId;
    }

    /**
     * 引き継ぎ情報登録完了時 にジョブが登録されるキュー のGRNを設定
     *
     * @param createTakeOverDoneTriggerQueueId 引き継ぎ情報登録完了時 にジョブが登録されるキュー のGRN
     */
    void setCreateTakeOverDoneTriggerQueueId(const Char* createTakeOverDoneTriggerQueueId)
    {
        ensureData().createTakeOverDoneTriggerQueueId.emplace(createTakeOverDoneTriggerQueueId);
    }

    /**
     * 引き継ぎ情報登録完了時 にジョブが登録されるキュー のGRNを設定
     *
     * @param createTakeOverDoneTriggerQueueId 引き継ぎ情報登録完了時 にジョブが登録されるキュー のGRN
     */
    UpdateGameRequest& withCreateTakeOverDoneTriggerQueueId(const Char* createTakeOverDoneTriggerQueueId)
    {
        ensureData().createTakeOverDoneTriggerQueueId.emplace(createTakeOverDoneTriggerQueueId);
        return *this;
    }

    /**
     * 引き継ぎ実行時 に実行されるスクリプト のGRNを取得
     *
     * @return 引き継ぎ実行時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getDoTakeOverTriggerScriptId() const
    {
        return ensureData().doTakeOverTriggerScriptId;
    }

    /**
     * 引き継ぎ実行時 に実行されるスクリプト のGRNを設定
     *
     * @param doTakeOverTriggerScriptId 引き継ぎ実行時 に実行されるスクリプト のGRN
     */
    void setDoTakeOverTriggerScriptId(const Char* doTakeOverTriggerScriptId)
    {
        ensureData().doTakeOverTriggerScriptId.emplace(doTakeOverTriggerScriptId);
    }

    /**
     * 引き継ぎ実行時 に実行されるスクリプト のGRNを設定
     *
     * @param doTakeOverTriggerScriptId 引き継ぎ実行時 に実行されるスクリプト のGRN
     */
    UpdateGameRequest& withDoTakeOverTriggerScriptId(const Char* doTakeOverTriggerScriptId)
    {
        ensureData().doTakeOverTriggerScriptId.emplace(doTakeOverTriggerScriptId);
        return *this;
    }

    /**
     * 引き継ぎ実行完了時 に実行されるスクリプト のGRNを取得
     *
     * @return 引き継ぎ実行完了時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getDoTakeOverDoneTriggerScriptId() const
    {
        return ensureData().doTakeOverDoneTriggerScriptId;
    }

    /**
     * 引き継ぎ実行完了時 に実行されるスクリプト のGRNを設定
     *
     * @param doTakeOverDoneTriggerScriptId 引き継ぎ実行完了時 に実行されるスクリプト のGRN
     */
    void setDoTakeOverDoneTriggerScriptId(const Char* doTakeOverDoneTriggerScriptId)
    {
        ensureData().doTakeOverDoneTriggerScriptId.emplace(doTakeOverDoneTriggerScriptId);
    }

    /**
     * 引き継ぎ実行完了時 に実行されるスクリプト のGRNを設定
     *
     * @param doTakeOverDoneTriggerScriptId 引き継ぎ実行完了時 に実行されるスクリプト のGRN
     */
    UpdateGameRequest& withDoTakeOverDoneTriggerScriptId(const Char* doTakeOverDoneTriggerScriptId)
    {
        ensureData().doTakeOverDoneTriggerScriptId.emplace(doTakeOverDoneTriggerScriptId);
        return *this;
    }

    /**
     * 引き継ぎ実行完了時 にジョブが登録されるキュー のGRNを取得
     *
     * @return 引き継ぎ実行完了時 にジョブが登録されるキュー のGRN
     */
    const optional<StringHolder>& getDoTakeOverDoneTriggerQueueId() const
    {
        return ensureData().doTakeOverDoneTriggerQueueId;
    }

    /**
     * 引き継ぎ実行完了時 にジョブが登録されるキュー のGRNを設定
     *
     * @param doTakeOverDoneTriggerQueueId 引き継ぎ実行完了時 にジョブが登録されるキュー のGRN
     */
    void setDoTakeOverDoneTriggerQueueId(const Char* doTakeOverDoneTriggerQueueId)
    {
        ensureData().doTakeOverDoneTriggerQueueId.emplace(doTakeOverDoneTriggerQueueId);
    }

    /**
     * 引き継ぎ実行完了時 にジョブが登録されるキュー のGRNを設定
     *
     * @param doTakeOverDoneTriggerQueueId 引き継ぎ実行完了時 にジョブが登録されるキュー のGRN
     */
    UpdateGameRequest& withDoTakeOverDoneTriggerQueueId(const Char* doTakeOverDoneTriggerQueueId)
    {
        ensureData().doTakeOverDoneTriggerQueueId.emplace(doTakeOverDoneTriggerQueueId);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateGameRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateGameRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateGameRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateGameRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_ACCOUNT_CONTROL_UPDATEGAMEREQUEST_HPP_