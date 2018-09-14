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

#ifndef GS2_ACCOUNT_MODEL_GAME_HPP_
#define GS2_ACCOUNT_MODEL_GAME_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace account {

/**
 * ゲーム
 *
 * @author Game Server Services, Inc.
 *
 */
class Game : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ゲームGRN */
        optional<StringHolder> gameId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** ゲーム名 */
        optional<StringHolder> name;
        /** 説明文 */
        optional<StringHolder> description;
        /** サービスクラス */
        optional<StringHolder> serviceClass;
        /** アカウント引き継ぎ時にパスワードを変更するか */
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
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;
        /** 最終更新日時(エポック秒) */
        optional<Int32> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            gameId(data.gameId),
            ownerId(data.ownerId),
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
            doTakeOverDoneTriggerScript(data.doTakeOverDoneTriggerScript),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            gameId(std::move(data.gameId)),
            ownerId(std::move(data.ownerId)),
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
            doTakeOverDoneTriggerScript(std::move(data.doTakeOverDoneTriggerScript)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "gameId") == 0) {
                if (jsonValue.IsString())
                {
                    this->gameId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "ownerId") == 0) {
                if (jsonValue.IsString())
                {
                    this->ownerId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "description") == 0) {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "serviceClass") == 0) {
                if (jsonValue.IsString())
                {
                    this->serviceClass.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "changePasswordIfTakeOver") == 0) {
                if (jsonValue.IsBool())
                {
                    this->changePasswordIfTakeOver = jsonValue.GetBool();
                }
            }
            else if (std::strcmp(name, "createAccountTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->createAccountTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createAccountDoneTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->createAccountDoneTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "authenticationTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->authenticationTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "authenticationDoneTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->authenticationDoneTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createTakeOverTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->createTakeOverTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createTakeOverDoneTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->createTakeOverDoneTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "doTakeOverTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->doTakeOverTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "doTakeOverDoneTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->doTakeOverDoneTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->createAt = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "updateAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->updateAt = jsonValue.GetInt();
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
    Game() :
        m_pData(nullptr)
    {}

    Game(const Game& game) :
        Gs2Object(game),
        m_pData(game.m_pData != nullptr ? new Data(*game.m_pData) : nullptr)
    {}

    Game(Game&& game) :
        Gs2Object(std::move(game)),
        m_pData(game.m_pData)
    {
        game.m_pData = nullptr;
    }

    ~Game()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Game& operator=(const Game& game)
    {
        Gs2Object::operator=(game);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*game.m_pData);

        return *this;
    }

    Game& operator=(Game&& game)
    {
        Gs2Object::operator=(std::move(game));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = game.m_pData;
        game.m_pData = nullptr;

        return *this;
    }

    const Game* operator->() const
    {
        return this;
    }

    Game* operator->()
    {
        return this;
    }


    /**
     * ゲームGRNを取得
     *
     * @return ゲームGRN
     */
    const optional<StringHolder>& getGameId() const
    {
        return ensureData().gameId;
    }

    /**
     * ゲームGRNを設定
     *
     * @param gameId ゲームGRN
     */
    void setGameId(const Char* gameId)
    {
        ensureData().gameId.emplace(gameId);
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
     * ゲーム名を取得
     *
     * @return ゲーム名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * ゲーム名を設定
     *
     * @param name ゲーム名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
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
     * サービスクラスを取得
     *
     * @return サービスクラス
     */
    const optional<StringHolder>& getServiceClass() const
    {
        return ensureData().serviceClass;
    }

    /**
     * サービスクラスを設定
     *
     * @param serviceClass サービスクラス
     */
    void setServiceClass(const Char* serviceClass)
    {
        ensureData().serviceClass.emplace(serviceClass);
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
     * 作成日時(エポック秒)を取得
     *
     * @return 作成日時(エポック秒)
     */
    const optional<Int32>& getCreateAt() const
    {
        return ensureData().createAt;
    }

    /**
     * 作成日時(エポック秒)を設定
     *
     * @param createAt 作成日時(エポック秒)
     */
    void setCreateAt(Int32 createAt)
    {
        ensureData().createAt.emplace(createAt);
    }

    /**
     * 最終更新日時(エポック秒)を取得
     *
     * @return 最終更新日時(エポック秒)
     */
    const optional<Int32>& getUpdateAt() const
    {
        return ensureData().updateAt;
    }

    /**
     * 最終更新日時(エポック秒)を設定
     *
     * @param updateAt 最終更新日時(エポック秒)
     */
    void setUpdateAt(Int32 updateAt)
    {
        ensureData().updateAt.emplace(updateAt);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_ACCOUNT_MODEL_GAME_HPP_