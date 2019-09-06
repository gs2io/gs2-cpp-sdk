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
#include "ScriptSetting.hpp"
#include "ScriptSetting.hpp"
#include "ScriptSetting.hpp"
#include "ScriptSetting.hpp"
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
        /** アカウント新規作成したときに実行するスクリプト */
        optional<ScriptSetting> createAccountScript;
        /** 認証したときに実行するスクリプト */
        optional<ScriptSetting> authenticationScript;
        /** 引き継ぎ情報登録したときに実行するスクリプト */
        optional<ScriptSetting> createTakeOverScript;
        /** 引き継ぎ実行したときに実行するスクリプト */
        optional<ScriptSetting> doTakeOverScript;
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
            createAccountScript(data.createAccountScript),
            authenticationScript(data.authenticationScript),
            createTakeOverScript(data.createTakeOverScript),
            doTakeOverScript(data.doTakeOverScript),
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
            createAccountScript(std::move(data.createAccountScript)),
            authenticationScript(std::move(data.authenticationScript)),
            createTakeOverScript(std::move(data.createTakeOverScript)),
            doTakeOverScript(std::move(data.doTakeOverScript)),
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
            else if (std::strcmp(name_, "createAccountScript") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->createAccountScript.emplace();
                    detail::json::JsonParser::parse(&this->createAccountScript->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "authenticationScript") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->authenticationScript.emplace();
                    detail::json::JsonParser::parse(&this->authenticationScript->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "createTakeOverScript") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->createTakeOverScript.emplace();
                    detail::json::JsonParser::parse(&this->createTakeOverScript->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "doTakeOverScript") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->doTakeOverScript.emplace();
                    detail::json::JsonParser::parse(&this->doTakeOverScript->getModel(), jsonObject);
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
    Namespace& withCreateAccountScript(const ScriptSetting& createAccountScript)
    {
        setCreateAccountScript(createAccountScript);
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
    Namespace& withAuthenticationScript(const ScriptSetting& authenticationScript)
    {
        setAuthenticationScript(authenticationScript);
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
    Namespace& withCreateTakeOverScript(const ScriptSetting& createTakeOverScript)
    {
        setCreateTakeOverScript(createTakeOverScript);
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
    Namespace& withDoTakeOverScript(const ScriptSetting& doTakeOverScript)
    {
        setDoTakeOverScript(doTakeOverScript);
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
        if (lhs.m_pData->createAccountScript != lhr.m_pData->createAccountScript)
        {
            return true;
        }
        if (lhs.m_pData->authenticationScript != lhr.m_pData->authenticationScript)
        {
            return true;
        }
        if (lhs.m_pData->createTakeOverScript != lhr.m_pData->createTakeOverScript)
        {
            return true;
        }
        if (lhs.m_pData->doTakeOverScript != lhr.m_pData->doTakeOverScript)
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