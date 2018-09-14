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

#ifndef GS2_CHAT_CONTROL_GETLOBBYREQUEST_HPP_
#define GS2_CHAT_CONTROL_GETLOBBYREQUEST_HPP_

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
class GetLobbyRequest : public Gs2BasicRequest, public Gs2Chat
{
public:
    constexpr static const Char* const FUNCTION = "GetLobby";

private:
    class Data : public Gs2Object
    {
    public:
        /** ロビーの名前 */
        optional<StringHolder> lobbyName;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            lobbyName(data.lobbyName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            lobbyName(std::move(data.lobbyName))
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
    GetLobbyRequest() :
        m_pData(nullptr)
    {}

    GetLobbyRequest(const GetLobbyRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Chat(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    GetLobbyRequest(GetLobbyRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Chat(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~GetLobbyRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetLobbyRequest& operator=(const GetLobbyRequest& getLobbyRequest)
    {
        Gs2BasicRequest::operator=(getLobbyRequest);
        Gs2Chat::operator=(getLobbyRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getLobbyRequest.m_pData);

        return *this;
    }

    GetLobbyRequest& operator=(GetLobbyRequest&& getLobbyRequest)
    {
        Gs2BasicRequest::operator=(std::move(getLobbyRequest));
        Gs2Chat::operator=(std::move(getLobbyRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getLobbyRequest.m_pData;
        getLobbyRequest.m_pData = nullptr;

        return *this;
    }

    const GetLobbyRequest* operator->() const
    {
        return this;
    }

    GetLobbyRequest* operator->()
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
    GetLobbyRequest& withLobbyName(const Char* lobbyName)
    {
        ensureData().lobbyName.emplace(lobbyName);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    GetLobbyRequest& withGs2ClientId(const Char* gs2ClientId)
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
    GetLobbyRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    GetLobbyRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetLobbyRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_CHAT_CONTROL_GETLOBBYREQUEST_HPP_