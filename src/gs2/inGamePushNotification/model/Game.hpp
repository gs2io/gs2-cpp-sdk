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

#ifndef GS2_INGAMEPUSHNOTIFICATION_MODEL_GAME_HPP_
#define GS2_INGAMEPUSHNOTIFICATION_MODEL_GAME_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace inGamePushNotification {

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
        /** ゲームID */
        optional<StringHolder> gameId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** ゲーム名 */
        optional<StringHolder> name;
        /** 説明文 */
        optional<StringHolder> description;
        /** サービスクラス */
        optional<StringHolder> serviceClass;
        /** 対象がオフライン時使用する転送方式 */
        optional<StringHolder> offlineTransfer;
        /** http/https を選択した際の転送先URL */
        optional<StringHolder> notificationUrl;
        /** fcm を選択した際の Firebase サーバーキー */
        optional<StringHolder> notificationFirebaseServerKey;
        /** クライアント証明書発行時 に実行されるGS2-Script */
        optional<StringHolder> createCertificateTriggerScript;
        /** クライアント証明書発行完了時 に実行されるGS2-Script */
        optional<StringHolder> createCertificateDoneTriggerScript;
        /** クライアント証明書削除時 に実行されるGS2-Script */
        optional<StringHolder> deleteCertificateTriggerScript;
        /** クライアント証明書削除完了時 に実行されるGS2-Script */
        optional<StringHolder> deleteCertificateDoneTriggerScript;
        /** 通知送信時 に実行されるGS2-Script */
        optional<StringHolder> publishTriggerScript;
        /** 通知送信完了時 に実行されるGS2-Script */
        optional<StringHolder> publishDoneTriggerScript;
        /** Firebaseデバイストークン登録時 に実行されるGS2-Script */
        optional<StringHolder> setFirebaseTokenTriggerScript;
        /** Firebaseデバイストークン登録完了時 に実行されるGS2-Script */
        optional<StringHolder> setFirebaseTokenDoneTriggerScript;
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
            offlineTransfer(data.offlineTransfer),
            notificationUrl(data.notificationUrl),
            notificationFirebaseServerKey(data.notificationFirebaseServerKey),
            createCertificateTriggerScript(data.createCertificateTriggerScript),
            createCertificateDoneTriggerScript(data.createCertificateDoneTriggerScript),
            deleteCertificateTriggerScript(data.deleteCertificateTriggerScript),
            deleteCertificateDoneTriggerScript(data.deleteCertificateDoneTriggerScript),
            publishTriggerScript(data.publishTriggerScript),
            publishDoneTriggerScript(data.publishDoneTriggerScript),
            setFirebaseTokenTriggerScript(data.setFirebaseTokenTriggerScript),
            setFirebaseTokenDoneTriggerScript(data.setFirebaseTokenDoneTriggerScript),
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
            offlineTransfer(std::move(data.offlineTransfer)),
            notificationUrl(std::move(data.notificationUrl)),
            notificationFirebaseServerKey(std::move(data.notificationFirebaseServerKey)),
            createCertificateTriggerScript(std::move(data.createCertificateTriggerScript)),
            createCertificateDoneTriggerScript(std::move(data.createCertificateDoneTriggerScript)),
            deleteCertificateTriggerScript(std::move(data.deleteCertificateTriggerScript)),
            deleteCertificateDoneTriggerScript(std::move(data.deleteCertificateDoneTriggerScript)),
            publishTriggerScript(std::move(data.publishTriggerScript)),
            publishDoneTriggerScript(std::move(data.publishDoneTriggerScript)),
            setFirebaseTokenTriggerScript(std::move(data.setFirebaseTokenTriggerScript)),
            setFirebaseTokenDoneTriggerScript(std::move(data.setFirebaseTokenDoneTriggerScript)),
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
            else if (std::strcmp(name, "offlineTransfer") == 0) {
                if (jsonValue.IsString())
                {
                    this->offlineTransfer.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "notificationUrl") == 0) {
                if (jsonValue.IsString())
                {
                    this->notificationUrl.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "notificationFirebaseServerKey") == 0) {
                if (jsonValue.IsString())
                {
                    this->notificationFirebaseServerKey.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createCertificateTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->createCertificateTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createCertificateDoneTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->createCertificateDoneTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "deleteCertificateTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->deleteCertificateTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "deleteCertificateDoneTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->deleteCertificateDoneTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "publishTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->publishTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "publishDoneTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->publishDoneTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "setFirebaseTokenTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->setFirebaseTokenTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "setFirebaseTokenDoneTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->setFirebaseTokenDoneTriggerScript.emplace(jsonValue.GetString());
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
     * ゲームIDを取得
     *
     * @return ゲームID
     */
    const optional<StringHolder>& getGameId() const
    {
        return ensureData().gameId;
    }

    /**
     * ゲームIDを設定
     *
     * @param gameId ゲームID
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
     * 対象がオフライン時使用する転送方式を取得
     *
     * @return 対象がオフライン時使用する転送方式
     */
    const optional<StringHolder>& getOfflineTransfer() const
    {
        return ensureData().offlineTransfer;
    }

    /**
     * 対象がオフライン時使用する転送方式を設定
     *
     * @param offlineTransfer 対象がオフライン時使用する転送方式
     */
    void setOfflineTransfer(const Char* offlineTransfer)
    {
        ensureData().offlineTransfer.emplace(offlineTransfer);
    }

    /**
     * http/https を選択した際の転送先URLを取得
     *
     * @return http/https を選択した際の転送先URL
     */
    const optional<StringHolder>& getNotificationUrl() const
    {
        return ensureData().notificationUrl;
    }

    /**
     * http/https を選択した際の転送先URLを設定
     *
     * @param notificationUrl http/https を選択した際の転送先URL
     */
    void setNotificationUrl(const Char* notificationUrl)
    {
        ensureData().notificationUrl.emplace(notificationUrl);
    }

    /**
     * fcm を選択した際の Firebase サーバーキーを取得
     *
     * @return fcm を選択した際の Firebase サーバーキー
     */
    const optional<StringHolder>& getNotificationFirebaseServerKey() const
    {
        return ensureData().notificationFirebaseServerKey;
    }

    /**
     * fcm を選択した際の Firebase サーバーキーを設定
     *
     * @param notificationFirebaseServerKey fcm を選択した際の Firebase サーバーキー
     */
    void setNotificationFirebaseServerKey(const Char* notificationFirebaseServerKey)
    {
        ensureData().notificationFirebaseServerKey.emplace(notificationFirebaseServerKey);
    }

    /**
     * クライアント証明書発行時 に実行されるGS2-Scriptを取得
     *
     * @return クライアント証明書発行時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getCreateCertificateTriggerScript() const
    {
        return ensureData().createCertificateTriggerScript;
    }

    /**
     * クライアント証明書発行時 に実行されるGS2-Scriptを設定
     *
     * @param createCertificateTriggerScript クライアント証明書発行時 に実行されるGS2-Script
     */
    void setCreateCertificateTriggerScript(const Char* createCertificateTriggerScript)
    {
        ensureData().createCertificateTriggerScript.emplace(createCertificateTriggerScript);
    }

    /**
     * クライアント証明書発行完了時 に実行されるGS2-Scriptを取得
     *
     * @return クライアント証明書発行完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getCreateCertificateDoneTriggerScript() const
    {
        return ensureData().createCertificateDoneTriggerScript;
    }

    /**
     * クライアント証明書発行完了時 に実行されるGS2-Scriptを設定
     *
     * @param createCertificateDoneTriggerScript クライアント証明書発行完了時 に実行されるGS2-Script
     */
    void setCreateCertificateDoneTriggerScript(const Char* createCertificateDoneTriggerScript)
    {
        ensureData().createCertificateDoneTriggerScript.emplace(createCertificateDoneTriggerScript);
    }

    /**
     * クライアント証明書削除時 に実行されるGS2-Scriptを取得
     *
     * @return クライアント証明書削除時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getDeleteCertificateTriggerScript() const
    {
        return ensureData().deleteCertificateTriggerScript;
    }

    /**
     * クライアント証明書削除時 に実行されるGS2-Scriptを設定
     *
     * @param deleteCertificateTriggerScript クライアント証明書削除時 に実行されるGS2-Script
     */
    void setDeleteCertificateTriggerScript(const Char* deleteCertificateTriggerScript)
    {
        ensureData().deleteCertificateTriggerScript.emplace(deleteCertificateTriggerScript);
    }

    /**
     * クライアント証明書削除完了時 に実行されるGS2-Scriptを取得
     *
     * @return クライアント証明書削除完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getDeleteCertificateDoneTriggerScript() const
    {
        return ensureData().deleteCertificateDoneTriggerScript;
    }

    /**
     * クライアント証明書削除完了時 に実行されるGS2-Scriptを設定
     *
     * @param deleteCertificateDoneTriggerScript クライアント証明書削除完了時 に実行されるGS2-Script
     */
    void setDeleteCertificateDoneTriggerScript(const Char* deleteCertificateDoneTriggerScript)
    {
        ensureData().deleteCertificateDoneTriggerScript.emplace(deleteCertificateDoneTriggerScript);
    }

    /**
     * 通知送信時 に実行されるGS2-Scriptを取得
     *
     * @return 通知送信時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getPublishTriggerScript() const
    {
        return ensureData().publishTriggerScript;
    }

    /**
     * 通知送信時 に実行されるGS2-Scriptを設定
     *
     * @param publishTriggerScript 通知送信時 に実行されるGS2-Script
     */
    void setPublishTriggerScript(const Char* publishTriggerScript)
    {
        ensureData().publishTriggerScript.emplace(publishTriggerScript);
    }

    /**
     * 通知送信完了時 に実行されるGS2-Scriptを取得
     *
     * @return 通知送信完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getPublishDoneTriggerScript() const
    {
        return ensureData().publishDoneTriggerScript;
    }

    /**
     * 通知送信完了時 に実行されるGS2-Scriptを設定
     *
     * @param publishDoneTriggerScript 通知送信完了時 に実行されるGS2-Script
     */
    void setPublishDoneTriggerScript(const Char* publishDoneTriggerScript)
    {
        ensureData().publishDoneTriggerScript.emplace(publishDoneTriggerScript);
    }

    /**
     * Firebaseデバイストークン登録時 に実行されるGS2-Scriptを取得
     *
     * @return Firebaseデバイストークン登録時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getSetFirebaseTokenTriggerScript() const
    {
        return ensureData().setFirebaseTokenTriggerScript;
    }

    /**
     * Firebaseデバイストークン登録時 に実行されるGS2-Scriptを設定
     *
     * @param setFirebaseTokenTriggerScript Firebaseデバイストークン登録時 に実行されるGS2-Script
     */
    void setSetFirebaseTokenTriggerScript(const Char* setFirebaseTokenTriggerScript)
    {
        ensureData().setFirebaseTokenTriggerScript.emplace(setFirebaseTokenTriggerScript);
    }

    /**
     * Firebaseデバイストークン登録完了時 に実行されるGS2-Scriptを取得
     *
     * @return Firebaseデバイストークン登録完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getSetFirebaseTokenDoneTriggerScript() const
    {
        return ensureData().setFirebaseTokenDoneTriggerScript;
    }

    /**
     * Firebaseデバイストークン登録完了時 に実行されるGS2-Scriptを設定
     *
     * @param setFirebaseTokenDoneTriggerScript Firebaseデバイストークン登録完了時 に実行されるGS2-Script
     */
    void setSetFirebaseTokenDoneTriggerScript(const Char* setFirebaseTokenDoneTriggerScript)
    {
        ensureData().setFirebaseTokenDoneTriggerScript.emplace(setFirebaseTokenDoneTriggerScript);
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

#endif //GS2_INGAMEPUSHNOTIFICATION_MODEL_GAME_HPP_