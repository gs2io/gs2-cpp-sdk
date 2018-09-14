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

#ifndef GS2_CHAT_CONTROL_UPDATELOBBYREQUEST_HPP_
#define GS2_CHAT_CONTROL_UPDATELOBBYREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ChatConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace chat
{

/**
 * @author Game Server Services, Inc.
 */
class UpdateLobbyRequest : public Gs2BasicRequest, public Gs2Chat
{
public:
    constexpr static const Char* const FUNCTION = "UpdateLobby";

private:
    class Data : public Gs2Object
    {
    public:
        /** ロビーの名前 */
        optional<StringHolder> lobbyName;
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

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            lobbyName(data.lobbyName),
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
            sendMessageDoneTriggerScript(data.sendMessageDoneTriggerScript)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            lobbyName(std::move(data.lobbyName)),
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
            sendMessageDoneTriggerScript(std::move(data.sendMessageDoneTriggerScript))
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
    UpdateLobbyRequest() :
        m_pData(nullptr)
    {}

    UpdateLobbyRequest(const UpdateLobbyRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Chat(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateLobbyRequest(UpdateLobbyRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Chat(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateLobbyRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateLobbyRequest& operator=(const UpdateLobbyRequest& updateLobbyRequest)
    {
        Gs2BasicRequest::operator=(updateLobbyRequest);
        Gs2Chat::operator=(updateLobbyRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateLobbyRequest.m_pData);

        return *this;
    }

    UpdateLobbyRequest& operator=(UpdateLobbyRequest&& updateLobbyRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateLobbyRequest));
        Gs2Chat::operator=(std::move(updateLobbyRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateLobbyRequest.m_pData;
        updateLobbyRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateLobbyRequest* operator->() const
    {
        return this;
    }

    UpdateLobbyRequest* operator->()
    {
        return this;
    }

    /**
     * ロビーの名前を取得
     *
     * @return ロビーの名前
     */
    const optional<StringHolder>& getLobbyName() const
    {
        return ensureData().lobbyName;
    }

    /**
     * ロビーの名前を設定
     *
     * @param lobbyName ロビーの名前
     */
    void setLobbyName(const Char* lobbyName)
    {
        ensureData().lobbyName.emplace(lobbyName);
    }

    /**
     * ロビーの名前を設定
     *
     * @param lobbyName ロビーの名前
     */
    UpdateLobbyRequest& withLobbyName(const Char* lobbyName)
    {
        ensureData().lobbyName.emplace(lobbyName);
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
    UpdateLobbyRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
        return *this;
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
     * サービスクラスを設定
     *
     * @param serviceClass サービスクラス
     */
    UpdateLobbyRequest& withServiceClass(const Char* serviceClass)
    {
        ensureData().serviceClass.emplace(serviceClass);
        return *this;
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
     * 通知方式を設定
     *
     * @param notificationType 通知方式
     */
    UpdateLobbyRequest& withNotificationType(const Char* notificationType)
    {
        ensureData().notificationType.emplace(notificationType);
        return *this;
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
     * http/https を選択した際の通知先URLを設定
     *
     * @param notificationUrl http/https を選択した際の通知先URL
     */
    UpdateLobbyRequest& withNotificationUrl(const Char* notificationUrl)
    {
        ensureData().notificationUrl.emplace(notificationUrl);
        return *this;
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
     * gs2-in-game-push-notification を選択した際の GS2-InGamePushNotification のゲーム名を設定
     *
     * @param notificationGameName gs2-in-game-push-notification を選択した際の GS2-InGamePushNotification のゲーム名
     */
    UpdateLobbyRequest& withNotificationGameName(const Char* notificationGameName)
    {
        ensureData().notificationGameName.emplace(notificationGameName);
        return *this;
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
     * ログを記録するかを設定
     *
     * @param logging ログを記録するか
     */
    UpdateLobbyRequest& withLogging(Bool logging)
    {
        ensureData().logging.emplace(logging);
        return *this;
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
     * ログを記録する日数を設定
     *
     * @param loggingDate ログを記録する日数
     */
    UpdateLobbyRequest& withLoggingDate(Int32 loggingDate)
    {
        ensureData().loggingDate.emplace(loggingDate);
        return *this;
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
     * ルーム作成時 に実行されるGS2-Scriptを設定
     *
     * @param createRoomTriggerScript ルーム作成時 に実行されるGS2-Script
     */
    UpdateLobbyRequest& withCreateRoomTriggerScript(const Char* createRoomTriggerScript)
    {
        ensureData().createRoomTriggerScript.emplace(createRoomTriggerScript);
        return *this;
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
     * ルーム作成完了時 に実行されるGS2-Scriptを設定
     *
     * @param createRoomDoneTriggerScript ルーム作成完了時 に実行されるGS2-Script
     */
    UpdateLobbyRequest& withCreateRoomDoneTriggerScript(const Char* createRoomDoneTriggerScript)
    {
        ensureData().createRoomDoneTriggerScript.emplace(createRoomDoneTriggerScript);
        return *this;
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
     * ルーム削除時 に実行されるGS2-Scriptを設定
     *
     * @param deleteRoomTriggerScript ルーム削除時 に実行されるGS2-Script
     */
    UpdateLobbyRequest& withDeleteRoomTriggerScript(const Char* deleteRoomTriggerScript)
    {
        ensureData().deleteRoomTriggerScript.emplace(deleteRoomTriggerScript);
        return *this;
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
     * ルーム削除完了時 に実行されるGS2-Scriptを設定
     *
     * @param deleteRoomDoneTriggerScript ルーム削除完了時 に実行されるGS2-Script
     */
    UpdateLobbyRequest& withDeleteRoomDoneTriggerScript(const Char* deleteRoomDoneTriggerScript)
    {
        ensureData().deleteRoomDoneTriggerScript.emplace(deleteRoomDoneTriggerScript);
        return *this;
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
     * ルーム購読時 に実行されるGS2-Scriptを設定
     *
     * @param createSubscribeTriggerScript ルーム購読時 に実行されるGS2-Script
     */
    UpdateLobbyRequest& withCreateSubscribeTriggerScript(const Char* createSubscribeTriggerScript)
    {
        ensureData().createSubscribeTriggerScript.emplace(createSubscribeTriggerScript);
        return *this;
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
     * ルーム購読完了時 に実行されるGS2-Scriptを設定
     *
     * @param createSubscribeDoneTriggerScript ルーム購読完了時 に実行されるGS2-Script
     */
    UpdateLobbyRequest& withCreateSubscribeDoneTriggerScript(const Char* createSubscribeDoneTriggerScript)
    {
        ensureData().createSubscribeDoneTriggerScript.emplace(createSubscribeDoneTriggerScript);
        return *this;
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
     * ルーム購読解除時 に実行されるGS2-Scriptを設定
     *
     * @param deleteSubscribeTriggerScript ルーム購読解除時 に実行されるGS2-Script
     */
    UpdateLobbyRequest& withDeleteSubscribeTriggerScript(const Char* deleteSubscribeTriggerScript)
    {
        ensureData().deleteSubscribeTriggerScript.emplace(deleteSubscribeTriggerScript);
        return *this;
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
     * ルーム購読解除完了時 に実行されるGS2-Scriptを設定
     *
     * @param deleteSubscribeDoneTriggerScript ルーム購読解除完了時 に実行されるGS2-Script
     */
    UpdateLobbyRequest& withDeleteSubscribeDoneTriggerScript(const Char* deleteSubscribeDoneTriggerScript)
    {
        ensureData().deleteSubscribeDoneTriggerScript.emplace(deleteSubscribeDoneTriggerScript);
        return *this;
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
     * メッセージ送信時 に実行されるGS2-Scriptを設定
     *
     * @param sendMessageTriggerScript メッセージ送信時 に実行されるGS2-Script
     */
    UpdateLobbyRequest& withSendMessageTriggerScript(const Char* sendMessageTriggerScript)
    {
        ensureData().sendMessageTriggerScript.emplace(sendMessageTriggerScript);
        return *this;
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
     * メッセージ送信完了時 に実行されるGS2-Scriptを設定
     *
     * @param sendMessageDoneTriggerScript メッセージ送信完了時 に実行されるGS2-Script
     */
    UpdateLobbyRequest& withSendMessageDoneTriggerScript(const Char* sendMessageDoneTriggerScript)
    {
        ensureData().sendMessageDoneTriggerScript.emplace(sendMessageDoneTriggerScript);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateLobbyRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateLobbyRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateLobbyRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateLobbyRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_CHAT_CONTROL_UPDATELOBBYREQUEST_HPP_