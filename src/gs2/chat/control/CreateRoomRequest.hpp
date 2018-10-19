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

#ifndef GS2_CHAT_CONTROL_CREATEROOMREQUEST_HPP_
#define GS2_CHAT_CONTROL_CREATEROOMREQUEST_HPP_

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
class CreateRoomRequest : public Gs2BasicRequest, public Gs2Chat
{
public:
    constexpr static const Char* const FUNCTION = "CreateRoom";

private:
    class Data : public Gs2Object
    {
    public:
        /** ロビーの名前 */
        optional<StringHolder> lobbyName;
        /** ルームID（指定しない場合は自動的に採番されます） */
        optional<StringHolder> roomId;
        /** ルームへのアクセスを許可するユーザIDリストを指定 */
        optional<List<StringHolder>> allowUserIds;
        /** ルームにアクセスする際にパスワードを要求する場合は文字列を指定 */
        optional<StringHolder> password;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            lobbyName(data.lobbyName),
            roomId(data.roomId),
            allowUserIds(data.allowUserIds),
            password(data.password)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            lobbyName(std::move(data.lobbyName)),
            roomId(std::move(data.roomId)),
            allowUserIds(std::move(data.allowUserIds)),
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
    CreateRoomRequest() :
        m_pData(nullptr)
    {}

    CreateRoomRequest(const CreateRoomRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Chat(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CreateRoomRequest(CreateRoomRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Chat(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CreateRoomRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateRoomRequest& operator=(const CreateRoomRequest& createRoomRequest)
    {
        Gs2BasicRequest::operator=(createRoomRequest);
        Gs2Chat::operator=(createRoomRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createRoomRequest.m_pData);

        return *this;
    }

    CreateRoomRequest& operator=(CreateRoomRequest&& createRoomRequest)
    {
        Gs2BasicRequest::operator=(std::move(createRoomRequest));
        Gs2Chat::operator=(std::move(createRoomRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createRoomRequest.m_pData;
        createRoomRequest.m_pData = nullptr;

        return *this;
    }

    const CreateRoomRequest* operator->() const
    {
        return this;
    }

    CreateRoomRequest* operator->()
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
    CreateRoomRequest& withLobbyName(const Char* lobbyName)
    {
        ensureData().lobbyName.emplace(lobbyName);
        return *this;
    }

    /**
     * ルームID（指定しない場合は自動的に採番されます）を取得
     *
     * @return ルームID（指定しない場合は自動的に採番されます）
     */
    const optional<StringHolder>& getRoomId() const
    {
        return ensureData().roomId;
    }

    /**
     * ルームID（指定しない場合は自動的に採番されます）を設定
     *
     * @param roomId ルームID（指定しない場合は自動的に採番されます）
     */
    void setRoomId(const Char* roomId)
    {
        ensureData().roomId.emplace(roomId);
    }

    /**
     * ルームID（指定しない場合は自動的に採番されます）を設定
     *
     * @param roomId ルームID（指定しない場合は自動的に採番されます）
     */
    CreateRoomRequest& withRoomId(const Char* roomId)
    {
        ensureData().roomId.emplace(roomId);
        return *this;
    }

    /**
     * ルームへのアクセスを許可するユーザIDリストを指定を取得
     *
     * @return ルームへのアクセスを許可するユーザIDリストを指定
     */
    const optional<List<StringHolder>>& getAllowUserIds() const
    {
        return ensureData().allowUserIds;
    }

    /**
     * ルームへのアクセスを許可するユーザIDリストを指定を設定
     *
     * @param allowUserIds ルームへのアクセスを許可するユーザIDリストを指定
     */
    void setAllowUserIds(const List<StringHolder>& allowUserIds)
    {
        ensureData().allowUserIds.emplace(allowUserIds);
    }

    /**
     * ルームへのアクセスを許可するユーザIDリストを指定を設定
     *
     * @param allowUserIds ルームへのアクセスを許可するユーザIDリストを指定
     */
    CreateRoomRequest& withAllowUserIds(const List<StringHolder>& allowUserIds)
    {
        ensureData().allowUserIds.emplace(allowUserIds);
        return *this;
    }

    /**
     * ルームにアクセスする際にパスワードを要求する場合は文字列を指定を取得
     *
     * @return ルームにアクセスする際にパスワードを要求する場合は文字列を指定
     */
    const optional<StringHolder>& getPassword() const
    {
        return ensureData().password;
    }

    /**
     * ルームにアクセスする際にパスワードを要求する場合は文字列を指定を設定
     *
     * @param password ルームにアクセスする際にパスワードを要求する場合は文字列を指定
     */
    void setPassword(const Char* password)
    {
        ensureData().password.emplace(password);
    }

    /**
     * ルームにアクセスする際にパスワードを要求する場合は文字列を指定を設定
     *
     * @param password ルームにアクセスする際にパスワードを要求する場合は文字列を指定
     */
    CreateRoomRequest& withPassword(const Char* password)
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
    CreateRoomRequest& withGs2ClientId(const Char* gs2ClientId)
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
    CreateRoomRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    CreateRoomRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateRoomRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_CHAT_CONTROL_CREATEROOMREQUEST_HPP_