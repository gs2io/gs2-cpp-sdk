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
        /** ゲーム のGRN */
        optional<StringHolder> gameId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** ゲーム名 */
        optional<StringHolder> name;
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
        /** 作成日時 */
        optional<Int64> createAt;
        /** 最終更新日時 */
        optional<Int64> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            gameId(data.gameId),
            ownerId(data.ownerId),
            name(data.name),
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
            doTakeOverDoneTriggerQueueId(data.doTakeOverDoneTriggerQueueId),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            gameId(std::move(data.gameId)),
            ownerId(std::move(data.ownerId)),
            name(std::move(data.name)),
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
            doTakeOverDoneTriggerQueueId(std::move(data.doTakeOverDoneTriggerQueueId)),
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
            else if (std::strcmp(name, "changePasswordIfTakeOver") == 0) {
                if (jsonValue.IsBool())
                {
                    this->changePasswordIfTakeOver = jsonValue.GetBool();
                }
            }
            else if (std::strcmp(name, "createAccountTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->createAccountTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createAccountDoneTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->createAccountDoneTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createAccountDoneTriggerQueueId") == 0) {
                if (jsonValue.IsString())
                {
                    this->createAccountDoneTriggerQueueId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "authenticationTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->authenticationTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "authenticationDoneTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->authenticationDoneTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "authenticationDoneTriggerQueueId") == 0) {
                if (jsonValue.IsString())
                {
                    this->authenticationDoneTriggerQueueId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createTakeOverTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->createTakeOverTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createTakeOverDoneTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->createTakeOverDoneTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createTakeOverDoneTriggerQueueId") == 0) {
                if (jsonValue.IsString())
                {
                    this->createTakeOverDoneTriggerQueueId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "doTakeOverTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->doTakeOverTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "doTakeOverDoneTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->doTakeOverDoneTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "doTakeOverDoneTriggerQueueId") == 0) {
                if (jsonValue.IsString())
                {
                    this->doTakeOverDoneTriggerQueueId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "updateAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->updateAt = jsonValue.GetInt64();
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
     * ゲーム のGRNを取得
     *
     * @return ゲーム のGRN
     */
    const optional<StringHolder>& getGameId() const
    {
        return ensureData().gameId;
    }

    /**
     * ゲーム のGRNを設定
     *
     * @param gameId ゲーム のGRN
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
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getCreateAt() const
    {
        return ensureData().createAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createAt 作成日時
     */
    void setCreateAt(Int64 createAt)
    {
        ensureData().createAt.emplace(createAt);
    }

    /**
     * 最終更新日時を取得
     *
     * @return 最終更新日時
     */
    const optional<Int64>& getUpdateAt() const
    {
        return ensureData().updateAt;
    }

    /**
     * 最終更新日時を設定
     *
     * @param updateAt 最終更新日時
     */
    void setUpdateAt(Int64 updateAt)
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