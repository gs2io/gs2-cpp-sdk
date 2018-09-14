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

#ifndef GS2_CHAT_CONTROL_CREATESUBSCRIBEREQUEST_HPP_
#define GS2_CHAT_CONTROL_CREATESUBSCRIBEREQUEST_HPP_

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
class CreateSubscribeRequest : public Gs2BasicRequest, public Gs2Chat
{
public:
    constexpr static const Char* const FUNCTION = "CreateSubscribe";

private:
    class Data : public Gs2Object
    {
    public:
        /** ロビーの名前 */
        optional<StringHolder> lobbyName;
        /** ルームID */
        optional<StringHolder> roomId;
        /** ユーザID */
        optional<StringHolder> userId;
        /** GS2-InGamePushNotification 使用時にオフライン転送を使用するか */
        optional<Bool> enableOfflineTransfer;
        /** GS2-InGamePushNotification 使用時のモバイルプッシュ通知で使用する通知音 */
        optional<StringHolder> offlineTransferSound;
        /** パスワード */
        optional<StringHolder> password;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            lobbyName(data.lobbyName),
            roomId(data.roomId),
            userId(data.userId),
            enableOfflineTransfer(data.enableOfflineTransfer),
            offlineTransferSound(data.offlineTransferSound),
            password(data.password)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            lobbyName(std::move(data.lobbyName)),
            roomId(std::move(data.roomId)),
            userId(std::move(data.userId)),
            enableOfflineTransfer(std::move(data.enableOfflineTransfer)),
            offlineTransferSound(std::move(data.offlineTransferSound)),
            password(std::move(data.password))
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
    CreateSubscribeRequest() :
        m_pData(nullptr)
    {}

    CreateSubscribeRequest(const CreateSubscribeRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Chat(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CreateSubscribeRequest(CreateSubscribeRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Chat(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CreateSubscribeRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateSubscribeRequest& operator=(const CreateSubscribeRequest& createSubscribeRequest)
    {
        Gs2BasicRequest::operator=(createSubscribeRequest);
        Gs2Chat::operator=(createSubscribeRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createSubscribeRequest.m_pData);

        return *this;
    }

    CreateSubscribeRequest& operator=(CreateSubscribeRequest&& createSubscribeRequest)
    {
        Gs2BasicRequest::operator=(std::move(createSubscribeRequest));
        Gs2Chat::operator=(std::move(createSubscribeRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createSubscribeRequest.m_pData;
        createSubscribeRequest.m_pData = nullptr;

        return *this;
    }

    const CreateSubscribeRequest* operator->() const
    {
        return this;
    }

    CreateSubscribeRequest* operator->()
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
    CreateSubscribeRequest& withLobbyName(const Char* lobbyName)
    {
        ensureData().lobbyName.emplace(lobbyName);
        return *this;
    }

    /**
     * ルームIDを取得
     *
     * @return ルームID
     */
    const optional<StringHolder>& getRoomId() const
    {
        return ensureData().roomId;
    }

    /**
     * ルームIDを設定
     *
     * @param roomId ルームID
     */
    void setRoomId(const Char* roomId)
    {
        ensureData().roomId.emplace(roomId);
    }

    /**
     * ルームIDを設定
     *
     * @param roomId ルームID
     */
    CreateSubscribeRequest& withRoomId(const Char* roomId)
    {
        ensureData().roomId.emplace(roomId);
        return *this;
    }

    /**
     * ユーザIDを取得
     *
     * @return ユーザID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザIDを設定
     *
     * @param userId ユーザID
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * ユーザIDを設定
     *
     * @param userId ユーザID
     */
    CreateSubscribeRequest& withUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
        return *this;
    }

    /**
     * GS2-InGamePushNotification 使用時にオフライン転送を使用するかを取得
     *
     * @return GS2-InGamePushNotification 使用時にオフライン転送を使用するか
     */
    const optional<Bool>& getEnableOfflineTransfer() const
    {
        return ensureData().enableOfflineTransfer;
    }

    /**
     * GS2-InGamePushNotification 使用時にオフライン転送を使用するかを設定
     *
     * @param enableOfflineTransfer GS2-InGamePushNotification 使用時にオフライン転送を使用するか
     */
    void setEnableOfflineTransfer(Bool enableOfflineTransfer)
    {
        ensureData().enableOfflineTransfer.emplace(enableOfflineTransfer);
    }

    /**
     * GS2-InGamePushNotification 使用時にオフライン転送を使用するかを設定
     *
     * @param enableOfflineTransfer GS2-InGamePushNotification 使用時にオフライン転送を使用するか
     */
    CreateSubscribeRequest& withEnableOfflineTransfer(Bool enableOfflineTransfer)
    {
        ensureData().enableOfflineTransfer.emplace(enableOfflineTransfer);
        return *this;
    }

    /**
     * GS2-InGamePushNotification 使用時のモバイルプッシュ通知で使用する通知音を取得
     *
     * @return GS2-InGamePushNotification 使用時のモバイルプッシュ通知で使用する通知音
     */
    const optional<StringHolder>& getOfflineTransferSound() const
    {
        return ensureData().offlineTransferSound;
    }

    /**
     * GS2-InGamePushNotification 使用時のモバイルプッシュ通知で使用する通知音を設定
     *
     * @param offlineTransferSound GS2-InGamePushNotification 使用時のモバイルプッシュ通知で使用する通知音
     */
    void setOfflineTransferSound(const Char* offlineTransferSound)
    {
        ensureData().offlineTransferSound.emplace(offlineTransferSound);
    }

    /**
     * GS2-InGamePushNotification 使用時のモバイルプッシュ通知で使用する通知音を設定
     *
     * @param offlineTransferSound GS2-InGamePushNotification 使用時のモバイルプッシュ通知で使用する通知音
     */
    CreateSubscribeRequest& withOfflineTransferSound(const Char* offlineTransferSound)
    {
        ensureData().offlineTransferSound.emplace(offlineTransferSound);
        return *this;
    }

    /**
     * パスワードを取得
     *
     * @return パスワード
     */
    const optional<StringHolder>& getPassword() const
    {
        return ensureData().password;
    }

    /**
     * パスワードを設定
     *
     * @param password パスワード
     */
    void setPassword(const Char* password)
    {
        ensureData().password.emplace(password);
    }

    /**
     * パスワードを設定
     *
     * @param password パスワード
     */
    CreateSubscribeRequest& withPassword(const Char* password)
    {
        ensureData().password.emplace(password);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreateSubscribeRequest& withGs2ClientId(const Char* gs2ClientId)
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
    CreateSubscribeRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    CreateSubscribeRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateSubscribeRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_CHAT_CONTROL_CREATESUBSCRIBEREQUEST_HPP_