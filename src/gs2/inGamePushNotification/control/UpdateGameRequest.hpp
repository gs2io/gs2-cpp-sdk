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

#ifndef GS2_INGAMEPUSHNOTIFICATION_CONTROL_UPDATEGAMEREQUEST_HPP_
#define GS2_INGAMEPUSHNOTIFICATION_CONTROL_UPDATEGAMEREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2InGamePushNotificationConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace inGamePushNotification
{

/**
 * @author Game Server Services, Inc.
 */
class UpdateGameRequest : public Gs2BasicRequest, public Gs2InGamePushNotification
{
public:
    constexpr static const Char* const FUNCTION = "UpdateGame";

private:
    class Data : public Gs2Object
    {
    public:
        /** ゲームの名前 */
        optional<StringHolder> gameName;
        /** 説明文 */
        optional<StringHolder> description;
        /** サービスクラス */
        optional<StringHolder> serviceClass;
        /** オフライン転送方式 */
        optional<StringHolder> offlineTransfer;
        /** オフライン転送先URL */
        optional<StringHolder> notificationUrl;
        /** Firebaseのサーバーキー */
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

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            gameName(data.gameName),
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
            setFirebaseTokenDoneTriggerScript(data.setFirebaseTokenDoneTriggerScript)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            gameName(std::move(data.gameName)),
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
            setFirebaseTokenDoneTriggerScript(std::move(data.setFirebaseTokenDoneTriggerScript))
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
        Gs2InGamePushNotification(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateGameRequest(UpdateGameRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2InGamePushNotification(std::move(obj)),
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
        Gs2InGamePushNotification::operator=(updateGameRequest);

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
        Gs2InGamePushNotification::operator=(std::move(updateGameRequest));

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
     * ゲームの名前を取得
     *
     * @return ゲームの名前
     */
    const optional<StringHolder>& getGameName() const
    {
        return ensureData().gameName;
    }

    /**
     * ゲームの名前を設定
     *
     * @param gameName ゲームの名前
     */
    void setGameName(const Char* gameName)
    {
        ensureData().gameName.emplace(gameName);
    }

    /**
     * ゲームの名前を設定
     *
     * @param gameName ゲームの名前
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
    UpdateGameRequest& withServiceClass(const Char* serviceClass)
    {
        ensureData().serviceClass.emplace(serviceClass);
        return *this;
    }

    /**
     * オフライン転送方式を取得
     *
     * @return オフライン転送方式
     */
    const optional<StringHolder>& getOfflineTransfer() const
    {
        return ensureData().offlineTransfer;
    }

    /**
     * オフライン転送方式を設定
     *
     * @param offlineTransfer オフライン転送方式
     */
    void setOfflineTransfer(const Char* offlineTransfer)
    {
        ensureData().offlineTransfer.emplace(offlineTransfer);
    }

    /**
     * オフライン転送方式を設定
     *
     * @param offlineTransfer オフライン転送方式
     */
    UpdateGameRequest& withOfflineTransfer(const Char* offlineTransfer)
    {
        ensureData().offlineTransfer.emplace(offlineTransfer);
        return *this;
    }

    /**
     * オフライン転送先URLを取得
     *
     * @return オフライン転送先URL
     */
    const optional<StringHolder>& getNotificationUrl() const
    {
        return ensureData().notificationUrl;
    }

    /**
     * オフライン転送先URLを設定
     *
     * @param notificationUrl オフライン転送先URL
     */
    void setNotificationUrl(const Char* notificationUrl)
    {
        ensureData().notificationUrl.emplace(notificationUrl);
    }

    /**
     * オフライン転送先URLを設定
     *
     * @param notificationUrl オフライン転送先URL
     */
    UpdateGameRequest& withNotificationUrl(const Char* notificationUrl)
    {
        ensureData().notificationUrl.emplace(notificationUrl);
        return *this;
    }

    /**
     * Firebaseのサーバーキーを取得
     *
     * @return Firebaseのサーバーキー
     */
    const optional<StringHolder>& getNotificationFirebaseServerKey() const
    {
        return ensureData().notificationFirebaseServerKey;
    }

    /**
     * Firebaseのサーバーキーを設定
     *
     * @param notificationFirebaseServerKey Firebaseのサーバーキー
     */
    void setNotificationFirebaseServerKey(const Char* notificationFirebaseServerKey)
    {
        ensureData().notificationFirebaseServerKey.emplace(notificationFirebaseServerKey);
    }

    /**
     * Firebaseのサーバーキーを設定
     *
     * @param notificationFirebaseServerKey Firebaseのサーバーキー
     */
    UpdateGameRequest& withNotificationFirebaseServerKey(const Char* notificationFirebaseServerKey)
    {
        ensureData().notificationFirebaseServerKey.emplace(notificationFirebaseServerKey);
        return *this;
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
     * クライアント証明書発行時 に実行されるGS2-Scriptを設定
     *
     * @param createCertificateTriggerScript クライアント証明書発行時 に実行されるGS2-Script
     */
    UpdateGameRequest& withCreateCertificateTriggerScript(const Char* createCertificateTriggerScript)
    {
        ensureData().createCertificateTriggerScript.emplace(createCertificateTriggerScript);
        return *this;
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
     * クライアント証明書発行完了時 に実行されるGS2-Scriptを設定
     *
     * @param createCertificateDoneTriggerScript クライアント証明書発行完了時 に実行されるGS2-Script
     */
    UpdateGameRequest& withCreateCertificateDoneTriggerScript(const Char* createCertificateDoneTriggerScript)
    {
        ensureData().createCertificateDoneTriggerScript.emplace(createCertificateDoneTriggerScript);
        return *this;
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
     * クライアント証明書削除時 に実行されるGS2-Scriptを設定
     *
     * @param deleteCertificateTriggerScript クライアント証明書削除時 に実行されるGS2-Script
     */
    UpdateGameRequest& withDeleteCertificateTriggerScript(const Char* deleteCertificateTriggerScript)
    {
        ensureData().deleteCertificateTriggerScript.emplace(deleteCertificateTriggerScript);
        return *this;
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
     * クライアント証明書削除完了時 に実行されるGS2-Scriptを設定
     *
     * @param deleteCertificateDoneTriggerScript クライアント証明書削除完了時 に実行されるGS2-Script
     */
    UpdateGameRequest& withDeleteCertificateDoneTriggerScript(const Char* deleteCertificateDoneTriggerScript)
    {
        ensureData().deleteCertificateDoneTriggerScript.emplace(deleteCertificateDoneTriggerScript);
        return *this;
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
     * 通知送信時 に実行されるGS2-Scriptを設定
     *
     * @param publishTriggerScript 通知送信時 に実行されるGS2-Script
     */
    UpdateGameRequest& withPublishTriggerScript(const Char* publishTriggerScript)
    {
        ensureData().publishTriggerScript.emplace(publishTriggerScript);
        return *this;
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
     * 通知送信完了時 に実行されるGS2-Scriptを設定
     *
     * @param publishDoneTriggerScript 通知送信完了時 に実行されるGS2-Script
     */
    UpdateGameRequest& withPublishDoneTriggerScript(const Char* publishDoneTriggerScript)
    {
        ensureData().publishDoneTriggerScript.emplace(publishDoneTriggerScript);
        return *this;
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
     * Firebaseデバイストークン登録時 に実行されるGS2-Scriptを設定
     *
     * @param setFirebaseTokenTriggerScript Firebaseデバイストークン登録時 に実行されるGS2-Script
     */
    UpdateGameRequest& withSetFirebaseTokenTriggerScript(const Char* setFirebaseTokenTriggerScript)
    {
        ensureData().setFirebaseTokenTriggerScript.emplace(setFirebaseTokenTriggerScript);
        return *this;
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
     * Firebaseデバイストークン登録完了時 に実行されるGS2-Scriptを設定
     *
     * @param setFirebaseTokenDoneTriggerScript Firebaseデバイストークン登録完了時 に実行されるGS2-Script
     */
    UpdateGameRequest& withSetFirebaseTokenDoneTriggerScript(const Char* setFirebaseTokenDoneTriggerScript)
    {
        ensureData().setFirebaseTokenDoneTriggerScript.emplace(setFirebaseTokenDoneTriggerScript);
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

#endif //GS2_INGAMEPUSHNOTIFICATION_CONTROL_UPDATEGAMEREQUEST_HPP_