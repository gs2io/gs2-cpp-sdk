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

#ifndef GS2_INGAMEPUSHNOTIFICATION_CONTROL_PUBLISHREQUEST_HPP_
#define GS2_INGAMEPUSHNOTIFICATION_CONTROL_PUBLISHREQUEST_HPP_

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
class PublishRequest : public Gs2BasicRequest, public Gs2InGamePushNotification
{
public:
    constexpr static const Char* const FUNCTION = "Publish";

private:
    class Data : public Gs2Object
    {
    public:
        /** ゲームの名前 */
        optional<StringHolder> gameName;
        /** 通知の送信先ユーザID */
        optional<StringHolder> userId;
        /** 件名 */
        optional<StringHolder> subject;
        /** 本文 */
        optional<StringHolder> body;
        /** 対象ユーザがオフラインの場合に転送を実行するか */
        optional<Bool> enableOfflineTransfer;
        /** Firebaseへの転送時に使用する通知音ファイル名 */
        optional<StringHolder> offlineTransferSound;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            gameName(data.gameName),
            userId(data.userId),
            subject(data.subject),
            body(data.body),
            enableOfflineTransfer(data.enableOfflineTransfer),
            offlineTransferSound(data.offlineTransferSound)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            gameName(std::move(data.gameName)),
            userId(std::move(data.userId)),
            subject(std::move(data.subject)),
            body(std::move(data.body)),
            enableOfflineTransfer(std::move(data.enableOfflineTransfer)),
            offlineTransferSound(std::move(data.offlineTransferSound))
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
    PublishRequest() :
        m_pData(nullptr)
    {}

    PublishRequest(const PublishRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2InGamePushNotification(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    PublishRequest(PublishRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2InGamePushNotification(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~PublishRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    PublishRequest& operator=(const PublishRequest& publishRequest)
    {
        Gs2BasicRequest::operator=(publishRequest);
        Gs2InGamePushNotification::operator=(publishRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*publishRequest.m_pData);

        return *this;
    }

    PublishRequest& operator=(PublishRequest&& publishRequest)
    {
        Gs2BasicRequest::operator=(std::move(publishRequest));
        Gs2InGamePushNotification::operator=(std::move(publishRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = publishRequest.m_pData;
        publishRequest.m_pData = nullptr;

        return *this;
    }

    const PublishRequest* operator->() const
    {
        return this;
    }

    PublishRequest* operator->()
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
    PublishRequest& withGameName(const Char* gameName)
    {
        ensureData().gameName.emplace(gameName);
        return *this;
    }

    /**
     * 通知の送信先ユーザIDを取得
     *
     * @return 通知の送信先ユーザID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * 通知の送信先ユーザIDを設定
     *
     * @param userId 通知の送信先ユーザID
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * 通知の送信先ユーザIDを設定
     *
     * @param userId 通知の送信先ユーザID
     */
    PublishRequest& withUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
        return *this;
    }

    /**
     * 件名を取得
     *
     * @return 件名
     */
    const optional<StringHolder>& getSubject() const
    {
        return ensureData().subject;
    }

    /**
     * 件名を設定
     *
     * @param subject 件名
     */
    void setSubject(const Char* subject)
    {
        ensureData().subject.emplace(subject);
    }

    /**
     * 件名を設定
     *
     * @param subject 件名
     */
    PublishRequest& withSubject(const Char* subject)
    {
        ensureData().subject.emplace(subject);
        return *this;
    }

    /**
     * 本文を取得
     *
     * @return 本文
     */
    const optional<StringHolder>& getBody() const
    {
        return ensureData().body;
    }

    /**
     * 本文を設定
     *
     * @param body 本文
     */
    void setBody(const Char* body)
    {
        ensureData().body.emplace(body);
    }

    /**
     * 本文を設定
     *
     * @param body 本文
     */
    PublishRequest& withBody(const Char* body)
    {
        ensureData().body.emplace(body);
        return *this;
    }

    /**
     * 対象ユーザがオフラインの場合に転送を実行するかを取得
     *
     * @return 対象ユーザがオフラインの場合に転送を実行するか
     */
    const optional<Bool>& getEnableOfflineTransfer() const
    {
        return ensureData().enableOfflineTransfer;
    }

    /**
     * 対象ユーザがオフラインの場合に転送を実行するかを設定
     *
     * @param enableOfflineTransfer 対象ユーザがオフラインの場合に転送を実行するか
     */
    void setEnableOfflineTransfer(Bool enableOfflineTransfer)
    {
        ensureData().enableOfflineTransfer.emplace(enableOfflineTransfer);
    }

    /**
     * 対象ユーザがオフラインの場合に転送を実行するかを設定
     *
     * @param enableOfflineTransfer 対象ユーザがオフラインの場合に転送を実行するか
     */
    PublishRequest& withEnableOfflineTransfer(Bool enableOfflineTransfer)
    {
        ensureData().enableOfflineTransfer.emplace(enableOfflineTransfer);
        return *this;
    }

    /**
     * Firebaseへの転送時に使用する通知音ファイル名を取得
     *
     * @return Firebaseへの転送時に使用する通知音ファイル名
     */
    const optional<StringHolder>& getOfflineTransferSound() const
    {
        return ensureData().offlineTransferSound;
    }

    /**
     * Firebaseへの転送時に使用する通知音ファイル名を設定
     *
     * @param offlineTransferSound Firebaseへの転送時に使用する通知音ファイル名
     */
    void setOfflineTransferSound(const Char* offlineTransferSound)
    {
        ensureData().offlineTransferSound.emplace(offlineTransferSound);
    }

    /**
     * Firebaseへの転送時に使用する通知音ファイル名を設定
     *
     * @param offlineTransferSound Firebaseへの転送時に使用する通知音ファイル名
     */
    PublishRequest& withOfflineTransferSound(const Char* offlineTransferSound)
    {
        ensureData().offlineTransferSound.emplace(offlineTransferSound);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    PublishRequest& withGs2ClientId(const Char* gs2ClientId)
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
    PublishRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    PublishRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    PublishRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_INGAMEPUSHNOTIFICATION_CONTROL_PUBLISHREQUEST_HPP_