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

#ifndef GS2_CHAT_CONTROL_SENDMESSAGENOAUTHREQUEST_HPP_
#define GS2_CHAT_CONTROL_SENDMESSAGENOAUTHREQUEST_HPP_

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
class SendMessageNoAuthRequest : public Gs2BasicRequest, public Gs2Chat
{
public:
    constexpr static const Char* const FUNCTION = "SendMessageNoAuth";

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
        /** メッセージテキスト */
        optional<StringHolder> message;
        /** メッセージメタデータ */
        optional<StringHolder> meta;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            lobbyName(data.lobbyName),
            roomId(data.roomId),
            userId(data.userId),
            message(data.message),
            meta(data.meta)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            lobbyName(std::move(data.lobbyName)),
            roomId(std::move(data.roomId)),
            userId(std::move(data.userId)),
            message(std::move(data.message)),
            meta(std::move(data.meta))
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
    SendMessageNoAuthRequest() :
        m_pData(nullptr)
    {}

    SendMessageNoAuthRequest(const SendMessageNoAuthRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Chat(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    SendMessageNoAuthRequest(SendMessageNoAuthRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Chat(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~SendMessageNoAuthRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    SendMessageNoAuthRequest& operator=(const SendMessageNoAuthRequest& sendMessageNoAuthRequest)
    {
        Gs2BasicRequest::operator=(sendMessageNoAuthRequest);
        Gs2Chat::operator=(sendMessageNoAuthRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*sendMessageNoAuthRequest.m_pData);

        return *this;
    }

    SendMessageNoAuthRequest& operator=(SendMessageNoAuthRequest&& sendMessageNoAuthRequest)
    {
        Gs2BasicRequest::operator=(std::move(sendMessageNoAuthRequest));
        Gs2Chat::operator=(std::move(sendMessageNoAuthRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = sendMessageNoAuthRequest.m_pData;
        sendMessageNoAuthRequest.m_pData = nullptr;

        return *this;
    }

    const SendMessageNoAuthRequest* operator->() const
    {
        return this;
    }

    SendMessageNoAuthRequest* operator->()
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
    SendMessageNoAuthRequest& withLobbyName(const Char* lobbyName)
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
    SendMessageNoAuthRequest& withRoomId(const Char* roomId)
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
    SendMessageNoAuthRequest& withUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
        return *this;
    }

    /**
     * メッセージテキストを取得
     *
     * @return メッセージテキスト
     */
    const optional<StringHolder>& getMessage() const
    {
        return ensureData().message;
    }

    /**
     * メッセージテキストを設定
     *
     * @param message メッセージテキスト
     */
    void setMessage(const Char* message)
    {
        ensureData().message.emplace(message);
    }

    /**
     * メッセージテキストを設定
     *
     * @param message メッセージテキスト
     */
    SendMessageNoAuthRequest& withMessage(const Char* message)
    {
        ensureData().message.emplace(message);
        return *this;
    }

    /**
     * メッセージメタデータを取得
     *
     * @return メッセージメタデータ
     */
    const optional<StringHolder>& getMeta() const
    {
        return ensureData().meta;
    }

    /**
     * メッセージメタデータを設定
     *
     * @param meta メッセージメタデータ
     */
    void setMeta(const Char* meta)
    {
        ensureData().meta.emplace(meta);
    }

    /**
     * メッセージメタデータを設定
     *
     * @param meta メッセージメタデータ
     */
    SendMessageNoAuthRequest& withMeta(const Char* meta)
    {
        ensureData().meta.emplace(meta);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    SendMessageNoAuthRequest& withGs2ClientId(const Char* gs2ClientId)
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
    SendMessageNoAuthRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    SendMessageNoAuthRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    SendMessageNoAuthRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_CHAT_CONTROL_SENDMESSAGENOAUTHREQUEST_HPP_