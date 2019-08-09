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
        /** アカウント新規作成時 に実行されるスクリプト のGRN */
        optional<StringHolder> createAccountTriggerScriptId;
        /** アカウント新規作成完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> createAccountDoneTriggerScriptId;
        /** アカウント新規作成完了時 にジョブが登録されるネームスペース のGRN */
        optional<StringHolder> createAccountDoneTriggerQueueNamespaceId;
        /** 認証時 に実行されるスクリプト のGRN */
        optional<StringHolder> authenticationTriggerScriptId;
        /** 認証完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> authenticationDoneTriggerScriptId;
        /** 認証完了時 にジョブが登録されるネームスペース のGRN */
        optional<StringHolder> authenticationDoneTriggerQueueNamespaceId;
        /** 引き継ぎ情報登録時 に実行されるスクリプト のGRN */
        optional<StringHolder> createTakeOverTriggerScriptId;
        /** 引き継ぎ情報登録完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> createTakeOverDoneTriggerScriptId;
        /** 引き継ぎ情報登録完了時 にジョブが登録されるネームスペース のGRN */
        optional<StringHolder> createTakeOverDoneTriggerQueueNamespaceId;
        /** 引き継ぎ実行時 に実行されるスクリプト のGRN */
        optional<StringHolder> doTakeOverTriggerScriptId;
        /** 引き継ぎ実行完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> doTakeOverDoneTriggerScriptId;
        /** 引き継ぎ実行完了時 にジョブが登録されるネームスペース のGRN */
        optional<StringHolder> doTakeOverDoneTriggerQueueNamespaceId;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
            description(data.description),
            changePasswordIfTakeOver(data.changePasswordIfTakeOver),
            createAccountTriggerScriptId(data.createAccountTriggerScriptId),
            createAccountDoneTriggerScriptId(data.createAccountDoneTriggerScriptId),
            createAccountDoneTriggerQueueNamespaceId(data.createAccountDoneTriggerQueueNamespaceId),
            authenticationTriggerScriptId(data.authenticationTriggerScriptId),
            authenticationDoneTriggerScriptId(data.authenticationDoneTriggerScriptId),
            authenticationDoneTriggerQueueNamespaceId(data.authenticationDoneTriggerQueueNamespaceId),
            createTakeOverTriggerScriptId(data.createTakeOverTriggerScriptId),
            createTakeOverDoneTriggerScriptId(data.createTakeOverDoneTriggerScriptId),
            createTakeOverDoneTriggerQueueNamespaceId(data.createTakeOverDoneTriggerQueueNamespaceId),
            doTakeOverTriggerScriptId(data.doTakeOverTriggerScriptId),
            doTakeOverDoneTriggerScriptId(data.doTakeOverDoneTriggerScriptId),
            doTakeOverDoneTriggerQueueNamespaceId(data.doTakeOverDoneTriggerQueueNamespaceId)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
            description(std::move(data.description)),
            changePasswordIfTakeOver(std::move(data.changePasswordIfTakeOver)),
            createAccountTriggerScriptId(std::move(data.createAccountTriggerScriptId)),
            createAccountDoneTriggerScriptId(std::move(data.createAccountDoneTriggerScriptId)),
            createAccountDoneTriggerQueueNamespaceId(std::move(data.createAccountDoneTriggerQueueNamespaceId)),
            authenticationTriggerScriptId(std::move(data.authenticationTriggerScriptId)),
            authenticationDoneTriggerScriptId(std::move(data.authenticationDoneTriggerScriptId)),
            authenticationDoneTriggerQueueNamespaceId(std::move(data.authenticationDoneTriggerQueueNamespaceId)),
            createTakeOverTriggerScriptId(std::move(data.createTakeOverTriggerScriptId)),
            createTakeOverDoneTriggerScriptId(std::move(data.createTakeOverDoneTriggerScriptId)),
            createTakeOverDoneTriggerQueueNamespaceId(std::move(data.createTakeOverDoneTriggerQueueNamespaceId)),
            doTakeOverTriggerScriptId(std::move(data.doTakeOverTriggerScriptId)),
            doTakeOverDoneTriggerScriptId(std::move(data.doTakeOverDoneTriggerScriptId)),
            doTakeOverDoneTriggerQueueNamespaceId(std::move(data.doTakeOverDoneTriggerQueueNamespaceId))
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
    UpdateNamespaceRequest& withCreateAccountTriggerScriptId(const Char* createAccountTriggerScriptId)
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
    UpdateNamespaceRequest& withCreateAccountDoneTriggerScriptId(const Char* createAccountDoneTriggerScriptId)
    {
        ensureData().createAccountDoneTriggerScriptId.emplace(createAccountDoneTriggerScriptId);
        return *this;
    }

    /**
     * アカウント新規作成完了時 にジョブが登録されるネームスペース のGRNを取得
     *
     * @return アカウント新規作成完了時 にジョブが登録されるネームスペース のGRN
     */
    const optional<StringHolder>& getCreateAccountDoneTriggerQueueNamespaceId() const
    {
        return ensureData().createAccountDoneTriggerQueueNamespaceId;
    }

    /**
     * アカウント新規作成完了時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param createAccountDoneTriggerQueueNamespaceId アカウント新規作成完了時 にジョブが登録されるネームスペース のGRN
     */
    void setCreateAccountDoneTriggerQueueNamespaceId(const Char* createAccountDoneTriggerQueueNamespaceId)
    {
        ensureData().createAccountDoneTriggerQueueNamespaceId.emplace(createAccountDoneTriggerQueueNamespaceId);
    }

    /**
     * アカウント新規作成完了時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param createAccountDoneTriggerQueueNamespaceId アカウント新規作成完了時 にジョブが登録されるネームスペース のGRN
     */
    UpdateNamespaceRequest& withCreateAccountDoneTriggerQueueNamespaceId(const Char* createAccountDoneTriggerQueueNamespaceId)
    {
        ensureData().createAccountDoneTriggerQueueNamespaceId.emplace(createAccountDoneTriggerQueueNamespaceId);
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
    UpdateNamespaceRequest& withAuthenticationTriggerScriptId(const Char* authenticationTriggerScriptId)
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
    UpdateNamespaceRequest& withAuthenticationDoneTriggerScriptId(const Char* authenticationDoneTriggerScriptId)
    {
        ensureData().authenticationDoneTriggerScriptId.emplace(authenticationDoneTriggerScriptId);
        return *this;
    }

    /**
     * 認証完了時 にジョブが登録されるネームスペース のGRNを取得
     *
     * @return 認証完了時 にジョブが登録されるネームスペース のGRN
     */
    const optional<StringHolder>& getAuthenticationDoneTriggerQueueNamespaceId() const
    {
        return ensureData().authenticationDoneTriggerQueueNamespaceId;
    }

    /**
     * 認証完了時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param authenticationDoneTriggerQueueNamespaceId 認証完了時 にジョブが登録されるネームスペース のGRN
     */
    void setAuthenticationDoneTriggerQueueNamespaceId(const Char* authenticationDoneTriggerQueueNamespaceId)
    {
        ensureData().authenticationDoneTriggerQueueNamespaceId.emplace(authenticationDoneTriggerQueueNamespaceId);
    }

    /**
     * 認証完了時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param authenticationDoneTriggerQueueNamespaceId 認証完了時 にジョブが登録されるネームスペース のGRN
     */
    UpdateNamespaceRequest& withAuthenticationDoneTriggerQueueNamespaceId(const Char* authenticationDoneTriggerQueueNamespaceId)
    {
        ensureData().authenticationDoneTriggerQueueNamespaceId.emplace(authenticationDoneTriggerQueueNamespaceId);
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
    UpdateNamespaceRequest& withCreateTakeOverTriggerScriptId(const Char* createTakeOverTriggerScriptId)
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
    UpdateNamespaceRequest& withCreateTakeOverDoneTriggerScriptId(const Char* createTakeOverDoneTriggerScriptId)
    {
        ensureData().createTakeOverDoneTriggerScriptId.emplace(createTakeOverDoneTriggerScriptId);
        return *this;
    }

    /**
     * 引き継ぎ情報登録完了時 にジョブが登録されるネームスペース のGRNを取得
     *
     * @return 引き継ぎ情報登録完了時 にジョブが登録されるネームスペース のGRN
     */
    const optional<StringHolder>& getCreateTakeOverDoneTriggerQueueNamespaceId() const
    {
        return ensureData().createTakeOverDoneTriggerQueueNamespaceId;
    }

    /**
     * 引き継ぎ情報登録完了時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param createTakeOverDoneTriggerQueueNamespaceId 引き継ぎ情報登録完了時 にジョブが登録されるネームスペース のGRN
     */
    void setCreateTakeOverDoneTriggerQueueNamespaceId(const Char* createTakeOverDoneTriggerQueueNamespaceId)
    {
        ensureData().createTakeOverDoneTriggerQueueNamespaceId.emplace(createTakeOverDoneTriggerQueueNamespaceId);
    }

    /**
     * 引き継ぎ情報登録完了時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param createTakeOverDoneTriggerQueueNamespaceId 引き継ぎ情報登録完了時 にジョブが登録されるネームスペース のGRN
     */
    UpdateNamespaceRequest& withCreateTakeOverDoneTriggerQueueNamespaceId(const Char* createTakeOverDoneTriggerQueueNamespaceId)
    {
        ensureData().createTakeOverDoneTriggerQueueNamespaceId.emplace(createTakeOverDoneTriggerQueueNamespaceId);
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
    UpdateNamespaceRequest& withDoTakeOverTriggerScriptId(const Char* doTakeOverTriggerScriptId)
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
    UpdateNamespaceRequest& withDoTakeOverDoneTriggerScriptId(const Char* doTakeOverDoneTriggerScriptId)
    {
        ensureData().doTakeOverDoneTriggerScriptId.emplace(doTakeOverDoneTriggerScriptId);
        return *this;
    }

    /**
     * 引き継ぎ実行完了時 にジョブが登録されるネームスペース のGRNを取得
     *
     * @return 引き継ぎ実行完了時 にジョブが登録されるネームスペース のGRN
     */
    const optional<StringHolder>& getDoTakeOverDoneTriggerQueueNamespaceId() const
    {
        return ensureData().doTakeOverDoneTriggerQueueNamespaceId;
    }

    /**
     * 引き継ぎ実行完了時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param doTakeOverDoneTriggerQueueNamespaceId 引き継ぎ実行完了時 にジョブが登録されるネームスペース のGRN
     */
    void setDoTakeOverDoneTriggerQueueNamespaceId(const Char* doTakeOverDoneTriggerQueueNamespaceId)
    {
        ensureData().doTakeOverDoneTriggerQueueNamespaceId.emplace(doTakeOverDoneTriggerQueueNamespaceId);
    }

    /**
     * 引き継ぎ実行完了時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param doTakeOverDoneTriggerQueueNamespaceId 引き継ぎ実行完了時 にジョブが登録されるネームスペース のGRN
     */
    UpdateNamespaceRequest& withDoTakeOverDoneTriggerQueueNamespaceId(const Char* doTakeOverDoneTriggerQueueNamespaceId)
    {
        ensureData().doTakeOverDoneTriggerQueueNamespaceId.emplace(doTakeOverDoneTriggerQueueNamespaceId);
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