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

#ifndef GS2_CHAT_MODEL_LOBBY_HPP_
#define GS2_CHAT_MODEL_LOBBY_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace chat {

/**
 * ロビー
 *
 * @author Game Server Services, Inc.
 *
 */
class Lobby : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ロビーGRN */
        optional<StringHolder> lobbyId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** ゲーム名 */
        optional<StringHolder> name;
        /** 説明文 */
        optional<StringHolder> description;
        /** サービスクラス */
        optional<StringHolder> serviceClass;
        /** 通知方式 */
        optional<StringHolder> notificationType;
        /** http/https を選択した際の通知先URL */
        optional<StringHolder> notificationUrl;
        /** gs2-in-game-push-notification を選択した際の GS2-InGamePushNotification のゲーム名 */
        optional<StringHolder> notificationGameName;
        /** ログを記録するか */
        optional<Bool> logging;
        /** ログを記録する日数 */
        optional<Int32> loggingDate;
        /** ルーム作成時 に実行されるGS2-Script */
        optional<StringHolder> createRoomTriggerScript;
        /** ルーム作成完了時 に実行されるGS2-Script */
        optional<StringHolder> createRoomDoneTriggerScript;
        /** ルーム削除時 に実行されるGS2-Script */
        optional<StringHolder> deleteRoomTriggerScript;
        /** ルーム削除完了時 に実行されるGS2-Script */
        optional<StringHolder> deleteRoomDoneTriggerScript;
        /** ルーム購読時 に実行されるGS2-Script */
        optional<StringHolder> createSubscribeTriggerScript;
        /** ルーム購読完了時 に実行されるGS2-Script */
        optional<StringHolder> createSubscribeDoneTriggerScript;
        /** ルーム購読解除時 に実行されるGS2-Script */
        optional<StringHolder> deleteSubscribeTriggerScript;
        /** ルーム購読解除完了時 に実行されるGS2-Script */
        optional<StringHolder> deleteSubscribeDoneTriggerScript;
        /** メッセージ送信時 に実行されるGS2-Script */
        optional<StringHolder> sendMessageTriggerScript;
        /** メッセージ送信完了時 に実行されるGS2-Script */
        optional<StringHolder> sendMessageDoneTriggerScript;
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;
        /** 最終更新日時(エポック秒) */
        optional<Int32> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            lobbyId(data.lobbyId),
            ownerId(data.ownerId),
            name(data.name),
            description(data.description),
            serviceClass(data.serviceClass),
            notificationType(data.notificationType),
            notificationUrl(data.notificationUrl),
            notificationGameName(data.notificationGameName),
            logging(data.logging),
            loggingDate(data.loggingDate),
            createRoomTriggerScript(data.createRoomTriggerScript),
            createRoomDoneTriggerScript(data.createRoomDoneTriggerScript),
            deleteRoomTriggerScript(data.deleteRoomTriggerScript),
            deleteRoomDoneTriggerScript(data.deleteRoomDoneTriggerScript),
            createSubscribeTriggerScript(data.createSubscribeTriggerScript),
            createSubscribeDoneTriggerScript(data.createSubscribeDoneTriggerScript),
            deleteSubscribeTriggerScript(data.deleteSubscribeTriggerScript),
            deleteSubscribeDoneTriggerScript(data.deleteSubscribeDoneTriggerScript),
            sendMessageTriggerScript(data.sendMessageTriggerScript),
            sendMessageDoneTriggerScript(data.sendMessageDoneTriggerScript),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            lobbyId(std::move(data.lobbyId)),
            ownerId(std::move(data.ownerId)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            serviceClass(std::move(data.serviceClass)),
            notificationType(std::move(data.notificationType)),
            notificationUrl(std::move(data.notificationUrl)),
            notificationGameName(std::move(data.notificationGameName)),
            logging(std::move(data.logging)),
            loggingDate(std::move(data.loggingDate)),
            createRoomTriggerScript(std::move(data.createRoomTriggerScript)),
            createRoomDoneTriggerScript(std::move(data.createRoomDoneTriggerScript)),
            deleteRoomTriggerScript(std::move(data.deleteRoomTriggerScript)),
            deleteRoomDoneTriggerScript(std::move(data.deleteRoomDoneTriggerScript)),
            createSubscribeTriggerScript(std::move(data.createSubscribeTriggerScript)),
            createSubscribeDoneTriggerScript(std::move(data.createSubscribeDoneTriggerScript)),
            deleteSubscribeTriggerScript(std::move(data.deleteSubscribeTriggerScript)),
            deleteSubscribeDoneTriggerScript(std::move(data.deleteSubscribeDoneTriggerScript)),
            sendMessageTriggerScript(std::move(data.sendMessageTriggerScript)),
            sendMessageDoneTriggerScript(std::move(data.sendMessageDoneTriggerScript)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "lobbyId") == 0) {
                if (jsonValue.IsString())
                {
                    this->lobbyId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name, "notificationType") == 0) {
                if (jsonValue.IsString())
                {
                    this->notificationType.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "notificationUrl") == 0) {
                if (jsonValue.IsString())
                {
                    this->notificationUrl.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "notificationGameName") == 0) {
                if (jsonValue.IsString())
                {
                    this->notificationGameName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "logging") == 0) {
                if (jsonValue.IsBool())
                {
                    this->logging = jsonValue.GetBool();
                }
            }
            else if (std::strcmp(name, "loggingDate") == 0) {
                if (jsonValue.IsInt())
                {
                    this->loggingDate = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "createRoomTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->createRoomTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createRoomDoneTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->createRoomDoneTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "deleteRoomTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->deleteRoomTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "deleteRoomDoneTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->deleteRoomDoneTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createSubscribeTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->createSubscribeTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createSubscribeDoneTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->createSubscribeDoneTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "deleteSubscribeTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->deleteSubscribeTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "deleteSubscribeDoneTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->deleteSubscribeDoneTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "sendMessageTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->sendMessageTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "sendMessageDoneTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->sendMessageDoneTriggerScript.emplace(jsonValue.GetString());
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
    Lobby() :
        m_pData(nullptr)
    {}

    Lobby(const Lobby& lobby) :
        Gs2Object(lobby),
        m_pData(lobby.m_pData != nullptr ? new Data(*lobby.m_pData) : nullptr)
    {}

    Lobby(Lobby&& lobby) :
        Gs2Object(std::move(lobby)),
        m_pData(lobby.m_pData)
    {
        lobby.m_pData = nullptr;
    }

    ~Lobby()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Lobby& operator=(const Lobby& lobby)
    {
        Gs2Object::operator=(lobby);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*lobby.m_pData);

        return *this;
    }

    Lobby& operator=(Lobby&& lobby)
    {
        Gs2Object::operator=(std::move(lobby));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = lobby.m_pData;
        lobby.m_pData = nullptr;

        return *this;
    }

    const Lobby* operator->() const
    {
        return this;
    }

    Lobby* operator->()
    {
        return this;
    }


    /**
     * ロビーGRNを取得
     *
     * @return ロビーGRN
     */
    const optional<StringHolder>& getLobbyId() const
    {
        return ensureData().lobbyId;
    }

    /**
     * ロビーGRNを設定
     *
     * @param lobbyId ロビーGRN
     */
    void setLobbyId(const Char* lobbyId)
    {
        ensureData().lobbyId.emplace(lobbyId);
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
     * 通知方式を取得
     *
     * @return 通知方式
     */
    const optional<StringHolder>& getNotificationType() const
    {
        return ensureData().notificationType;
    }

    /**
     * 通知方式を設定
     *
     * @param notificationType 通知方式
     */
    void setNotificationType(const Char* notificationType)
    {
        ensureData().notificationType.emplace(notificationType);
    }

    /**
     * http/https を選択した際の通知先URLを取得
     *
     * @return http/https を選択した際の通知先URL
     */
    const optional<StringHolder>& getNotificationUrl() const
    {
        return ensureData().notificationUrl;
    }

    /**
     * http/https を選択した際の通知先URLを設定
     *
     * @param notificationUrl http/https を選択した際の通知先URL
     */
    void setNotificationUrl(const Char* notificationUrl)
    {
        ensureData().notificationUrl.emplace(notificationUrl);
    }

    /**
     * gs2-in-game-push-notification を選択した際の GS2-InGamePushNotification のゲーム名を取得
     *
     * @return gs2-in-game-push-notification を選択した際の GS2-InGamePushNotification のゲーム名
     */
    const optional<StringHolder>& getNotificationGameName() const
    {
        return ensureData().notificationGameName;
    }

    /**
     * gs2-in-game-push-notification を選択した際の GS2-InGamePushNotification のゲーム名を設定
     *
     * @param notificationGameName gs2-in-game-push-notification を選択した際の GS2-InGamePushNotification のゲーム名
     */
    void setNotificationGameName(const Char* notificationGameName)
    {
        ensureData().notificationGameName.emplace(notificationGameName);
    }

    /**
     * ログを記録するかを取得
     *
     * @return ログを記録するか
     */
    const optional<Bool>& getLogging() const
    {
        return ensureData().logging;
    }

    /**
     * ログを記録するかを設定
     *
     * @param logging ログを記録するか
     */
    void setLogging(Bool logging)
    {
        ensureData().logging.emplace(logging);
    }

    /**
     * ログを記録する日数を取得
     *
     * @return ログを記録する日数
     */
    const optional<Int32>& getLoggingDate() const
    {
        return ensureData().loggingDate;
    }

    /**
     * ログを記録する日数を設定
     *
     * @param loggingDate ログを記録する日数
     */
    void setLoggingDate(Int32 loggingDate)
    {
        ensureData().loggingDate.emplace(loggingDate);
    }

    /**
     * ルーム作成時 に実行されるGS2-Scriptを取得
     *
     * @return ルーム作成時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getCreateRoomTriggerScript() const
    {
        return ensureData().createRoomTriggerScript;
    }

    /**
     * ルーム作成時 に実行されるGS2-Scriptを設定
     *
     * @param createRoomTriggerScript ルーム作成時 に実行されるGS2-Script
     */
    void setCreateRoomTriggerScript(const Char* createRoomTriggerScript)
    {
        ensureData().createRoomTriggerScript.emplace(createRoomTriggerScript);
    }

    /**
     * ルーム作成完了時 に実行されるGS2-Scriptを取得
     *
     * @return ルーム作成完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getCreateRoomDoneTriggerScript() const
    {
        return ensureData().createRoomDoneTriggerScript;
    }

    /**
     * ルーム作成完了時 に実行されるGS2-Scriptを設定
     *
     * @param createRoomDoneTriggerScript ルーム作成完了時 に実行されるGS2-Script
     */
    void setCreateRoomDoneTriggerScript(const Char* createRoomDoneTriggerScript)
    {
        ensureData().createRoomDoneTriggerScript.emplace(createRoomDoneTriggerScript);
    }

    /**
     * ルーム削除時 に実行されるGS2-Scriptを取得
     *
     * @return ルーム削除時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getDeleteRoomTriggerScript() const
    {
        return ensureData().deleteRoomTriggerScript;
    }

    /**
     * ルーム削除時 に実行されるGS2-Scriptを設定
     *
     * @param deleteRoomTriggerScript ルーム削除時 に実行されるGS2-Script
     */
    void setDeleteRoomTriggerScript(const Char* deleteRoomTriggerScript)
    {
        ensureData().deleteRoomTriggerScript.emplace(deleteRoomTriggerScript);
    }

    /**
     * ルーム削除完了時 に実行されるGS2-Scriptを取得
     *
     * @return ルーム削除完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getDeleteRoomDoneTriggerScript() const
    {
        return ensureData().deleteRoomDoneTriggerScript;
    }

    /**
     * ルーム削除完了時 に実行されるGS2-Scriptを設定
     *
     * @param deleteRoomDoneTriggerScript ルーム削除完了時 に実行されるGS2-Script
     */
    void setDeleteRoomDoneTriggerScript(const Char* deleteRoomDoneTriggerScript)
    {
        ensureData().deleteRoomDoneTriggerScript.emplace(deleteRoomDoneTriggerScript);
    }

    /**
     * ルーム購読時 に実行されるGS2-Scriptを取得
     *
     * @return ルーム購読時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getCreateSubscribeTriggerScript() const
    {
        return ensureData().createSubscribeTriggerScript;
    }

    /**
     * ルーム購読時 に実行されるGS2-Scriptを設定
     *
     * @param createSubscribeTriggerScript ルーム購読時 に実行されるGS2-Script
     */
    void setCreateSubscribeTriggerScript(const Char* createSubscribeTriggerScript)
    {
        ensureData().createSubscribeTriggerScript.emplace(createSubscribeTriggerScript);
    }

    /**
     * ルーム購読完了時 に実行されるGS2-Scriptを取得
     *
     * @return ルーム購読完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getCreateSubscribeDoneTriggerScript() const
    {
        return ensureData().createSubscribeDoneTriggerScript;
    }

    /**
     * ルーム購読完了時 に実行されるGS2-Scriptを設定
     *
     * @param createSubscribeDoneTriggerScript ルーム購読完了時 に実行されるGS2-Script
     */
    void setCreateSubscribeDoneTriggerScript(const Char* createSubscribeDoneTriggerScript)
    {
        ensureData().createSubscribeDoneTriggerScript.emplace(createSubscribeDoneTriggerScript);
    }

    /**
     * ルーム購読解除時 に実行されるGS2-Scriptを取得
     *
     * @return ルーム購読解除時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getDeleteSubscribeTriggerScript() const
    {
        return ensureData().deleteSubscribeTriggerScript;
    }

    /**
     * ルーム購読解除時 に実行されるGS2-Scriptを設定
     *
     * @param deleteSubscribeTriggerScript ルーム購読解除時 に実行されるGS2-Script
     */
    void setDeleteSubscribeTriggerScript(const Char* deleteSubscribeTriggerScript)
    {
        ensureData().deleteSubscribeTriggerScript.emplace(deleteSubscribeTriggerScript);
    }

    /**
     * ルーム購読解除完了時 に実行されるGS2-Scriptを取得
     *
     * @return ルーム購読解除完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getDeleteSubscribeDoneTriggerScript() const
    {
        return ensureData().deleteSubscribeDoneTriggerScript;
    }

    /**
     * ルーム購読解除完了時 に実行されるGS2-Scriptを設定
     *
     * @param deleteSubscribeDoneTriggerScript ルーム購読解除完了時 に実行されるGS2-Script
     */
    void setDeleteSubscribeDoneTriggerScript(const Char* deleteSubscribeDoneTriggerScript)
    {
        ensureData().deleteSubscribeDoneTriggerScript.emplace(deleteSubscribeDoneTriggerScript);
    }

    /**
     * メッセージ送信時 に実行されるGS2-Scriptを取得
     *
     * @return メッセージ送信時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getSendMessageTriggerScript() const
    {
        return ensureData().sendMessageTriggerScript;
    }

    /**
     * メッセージ送信時 に実行されるGS2-Scriptを設定
     *
     * @param sendMessageTriggerScript メッセージ送信時 に実行されるGS2-Script
     */
    void setSendMessageTriggerScript(const Char* sendMessageTriggerScript)
    {
        ensureData().sendMessageTriggerScript.emplace(sendMessageTriggerScript);
    }

    /**
     * メッセージ送信完了時 に実行されるGS2-Scriptを取得
     *
     * @return メッセージ送信完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getSendMessageDoneTriggerScript() const
    {
        return ensureData().sendMessageDoneTriggerScript;
    }

    /**
     * メッセージ送信完了時 に実行されるGS2-Scriptを設定
     *
     * @param sendMessageDoneTriggerScript メッセージ送信完了時 に実行されるGS2-Script
     */
    void setSendMessageDoneTriggerScript(const Char* sendMessageDoneTriggerScript)
    {
        ensureData().sendMessageDoneTriggerScript.emplace(sendMessageDoneTriggerScript);
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

#endif //GS2_CHAT_MODEL_LOBBY_HPP_