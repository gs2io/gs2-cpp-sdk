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

#ifndef GS2_ACCOUNT_MODEL_NAMESPACE_HPP_
#define GS2_ACCOUNT_MODEL_NAMESPACE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace account {

/**
 * ネームスペース
 *
 * @author Game Server Services, Inc.
 *
 */
class Namespace : public Gs2Object
{
    friend bool operator!=(const Namespace& lhs, const Namespace& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** ネームスペース */
        optional<StringHolder> namespaceId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** ネームスペース名 */
        optional<StringHolder> name;
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
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            namespaceId(data.namespaceId),
            ownerId(data.ownerId),
            name(data.name),
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
            doTakeOverDoneTriggerQueueNamespaceId(data.doTakeOverDoneTriggerQueueNamespaceId),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            namespaceId(std::move(data.namespaceId)),
            ownerId(std::move(data.ownerId)),
            name(std::move(data.name)),
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
            doTakeOverDoneTriggerQueueNamespaceId(std::move(data.doTakeOverDoneTriggerQueueNamespaceId)),
            createdAt(std::move(data.createdAt)),
            updatedAt(std::move(data.updatedAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "namespaceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->namespaceId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "ownerId") == 0) {
                if (jsonValue.IsString())
                {
                    this->ownerId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "description") == 0) {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "changePasswordIfTakeOver") == 0) {
                if (jsonValue.IsBool())
                {
                    this->changePasswordIfTakeOver = jsonValue.GetBool();
                }
            }
            else if (std::strcmp(name_, "createAccountTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->createAccountTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "createAccountDoneTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->createAccountDoneTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "createAccountDoneTriggerQueueNamespaceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->createAccountDoneTriggerQueueNamespaceId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "authenticationTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->authenticationTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "authenticationDoneTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->authenticationDoneTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "authenticationDoneTriggerQueueNamespaceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->authenticationDoneTriggerQueueNamespaceId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "createTakeOverTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->createTakeOverTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "createTakeOverDoneTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->createTakeOverDoneTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "createTakeOverDoneTriggerQueueNamespaceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->createTakeOverDoneTriggerQueueNamespaceId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "doTakeOverTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->doTakeOverTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "doTakeOverDoneTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->doTakeOverDoneTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "doTakeOverDoneTriggerQueueNamespaceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->doTakeOverDoneTriggerQueueNamespaceId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "createdAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "updatedAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
                }
            }
        }
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
    Namespace() :
        m_pData(nullptr)
    {}

    Namespace(const Namespace& namespace_) :
        Gs2Object(namespace_),
        m_pData(namespace_.m_pData != nullptr ? new Data(*namespace_.m_pData) : nullptr)
    {}

    Namespace(Namespace&& namespace_) :
        Gs2Object(std::move(namespace_)),
        m_pData(namespace_.m_pData)
    {
        namespace_.m_pData = nullptr;
    }

    ~Namespace()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Namespace& operator=(const Namespace& namespace_)
    {
        Gs2Object::operator=(namespace_);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*namespace_.m_pData);

        return *this;
    }

    Namespace& operator=(Namespace&& namespace_)
    {
        Gs2Object::operator=(std::move(namespace_));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = namespace_.m_pData;
        namespace_.m_pData = nullptr;

        return *this;
    }

    const Namespace* operator->() const
    {
        return this;
    }

    Namespace* operator->()
    {
        return this;
    }
    /**
     * ネームスペースを取得
     *
     * @return ネームスペース
     */
    const optional<StringHolder>& getNamespaceId() const
    {
        return ensureData().namespaceId;
    }

    /**
     * ネームスペースを設定
     *
     * @param namespaceId ネームスペース
     */
    void setNamespaceId(const Char* namespaceId)
    {
        ensureData().namespaceId.emplace(namespaceId);
    }

    /**
     * ネームスペースを設定
     *
     * @param namespaceId ネームスペース
     */
    Namespace& withNamespaceId(const Char* namespaceId)
    {
        setNamespaceId(namespaceId);
        return *this;
    }

    /**
     * オーナーIDを取得
     *
     * @return オーナーID
     */
    const optional<StringHolder>& getOwnerId() const
    {
        return ensureData().ownerId;
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    void setOwnerId(const Char* ownerId)
    {
        ensureData().ownerId.emplace(ownerId);
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    Namespace& withOwnerId(const Char* ownerId)
    {
        setOwnerId(ownerId);
        return *this;
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
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * ネームスペース名を設定
     *
     * @param name ネームスペース名
     */
    Namespace& withName(const Char* name)
    {
        setName(name);
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
    Namespace& withDescription(const Char* description)
    {
        setDescription(description);
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
    Namespace& withChangePasswordIfTakeOver(Bool changePasswordIfTakeOver)
    {
        setChangePasswordIfTakeOver(changePasswordIfTakeOver);
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
    Namespace& withCreateAccountTriggerScriptId(const Char* createAccountTriggerScriptId)
    {
        setCreateAccountTriggerScriptId(createAccountTriggerScriptId);
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
    Namespace& withCreateAccountDoneTriggerScriptId(const Char* createAccountDoneTriggerScriptId)
    {
        setCreateAccountDoneTriggerScriptId(createAccountDoneTriggerScriptId);
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
    Namespace& withCreateAccountDoneTriggerQueueNamespaceId(const Char* createAccountDoneTriggerQueueNamespaceId)
    {
        setCreateAccountDoneTriggerQueueNamespaceId(createAccountDoneTriggerQueueNamespaceId);
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
    Namespace& withAuthenticationTriggerScriptId(const Char* authenticationTriggerScriptId)
    {
        setAuthenticationTriggerScriptId(authenticationTriggerScriptId);
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
    Namespace& withAuthenticationDoneTriggerScriptId(const Char* authenticationDoneTriggerScriptId)
    {
        setAuthenticationDoneTriggerScriptId(authenticationDoneTriggerScriptId);
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
    Namespace& withAuthenticationDoneTriggerQueueNamespaceId(const Char* authenticationDoneTriggerQueueNamespaceId)
    {
        setAuthenticationDoneTriggerQueueNamespaceId(authenticationDoneTriggerQueueNamespaceId);
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
    Namespace& withCreateTakeOverTriggerScriptId(const Char* createTakeOverTriggerScriptId)
    {
        setCreateTakeOverTriggerScriptId(createTakeOverTriggerScriptId);
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
    Namespace& withCreateTakeOverDoneTriggerScriptId(const Char* createTakeOverDoneTriggerScriptId)
    {
        setCreateTakeOverDoneTriggerScriptId(createTakeOverDoneTriggerScriptId);
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
    Namespace& withCreateTakeOverDoneTriggerQueueNamespaceId(const Char* createTakeOverDoneTriggerQueueNamespaceId)
    {
        setCreateTakeOverDoneTriggerQueueNamespaceId(createTakeOverDoneTriggerQueueNamespaceId);
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
    Namespace& withDoTakeOverTriggerScriptId(const Char* doTakeOverTriggerScriptId)
    {
        setDoTakeOverTriggerScriptId(doTakeOverTriggerScriptId);
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
    Namespace& withDoTakeOverDoneTriggerScriptId(const Char* doTakeOverDoneTriggerScriptId)
    {
        setDoTakeOverDoneTriggerScriptId(doTakeOverDoneTriggerScriptId);
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
    Namespace& withDoTakeOverDoneTriggerQueueNamespaceId(const Char* doTakeOverDoneTriggerQueueNamespaceId)
    {
        setDoTakeOverDoneTriggerQueueNamespaceId(doTakeOverDoneTriggerQueueNamespaceId);
        return *this;
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getCreatedAt() const
    {
        return ensureData().createdAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    void setCreatedAt(Int64 createdAt)
    {
        ensureData().createdAt.emplace(createdAt);
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    Namespace& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }

    /**
     * 最終更新日時を取得
     *
     * @return 最終更新日時
     */
    const optional<Int64>& getUpdatedAt() const
    {
        return ensureData().updatedAt;
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    void setUpdatedAt(Int64 updatedAt)
    {
        ensureData().updatedAt.emplace(updatedAt);
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    Namespace& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Namespace& lhs, const Namespace& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->namespaceId != lhr.m_pData->namespaceId)
        {
            return true;
        }
        if (lhs.m_pData->ownerId != lhr.m_pData->ownerId)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->description != lhr.m_pData->description)
        {
            return true;
        }
        if (lhs.m_pData->changePasswordIfTakeOver != lhr.m_pData->changePasswordIfTakeOver)
        {
            return true;
        }
        if (lhs.m_pData->createAccountTriggerScriptId != lhr.m_pData->createAccountTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->createAccountDoneTriggerScriptId != lhr.m_pData->createAccountDoneTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->createAccountDoneTriggerQueueNamespaceId != lhr.m_pData->createAccountDoneTriggerQueueNamespaceId)
        {
            return true;
        }
        if (lhs.m_pData->authenticationTriggerScriptId != lhr.m_pData->authenticationTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->authenticationDoneTriggerScriptId != lhr.m_pData->authenticationDoneTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->authenticationDoneTriggerQueueNamespaceId != lhr.m_pData->authenticationDoneTriggerQueueNamespaceId)
        {
            return true;
        }
        if (lhs.m_pData->createTakeOverTriggerScriptId != lhr.m_pData->createTakeOverTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->createTakeOverDoneTriggerScriptId != lhr.m_pData->createTakeOverDoneTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->createTakeOverDoneTriggerQueueNamespaceId != lhr.m_pData->createTakeOverDoneTriggerQueueNamespaceId)
        {
            return true;
        }
        if (lhs.m_pData->doTakeOverTriggerScriptId != lhr.m_pData->doTakeOverTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->doTakeOverDoneTriggerScriptId != lhr.m_pData->doTakeOverDoneTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->doTakeOverDoneTriggerQueueNamespaceId != lhr.m_pData->doTakeOverDoneTriggerQueueNamespaceId)
        {
            return true;
        }
        if (lhs.m_pData->createdAt != lhr.m_pData->createdAt)
        {
            return true;
        }
        if (lhs.m_pData->updatedAt != lhr.m_pData->updatedAt)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const Namespace& lhs, const Namespace& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_ACCOUNT_MODEL_NAMESPACE_HPP_