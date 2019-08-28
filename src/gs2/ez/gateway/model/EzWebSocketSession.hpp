

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

#ifndef GS2_EZ_GATEWAY_MODEL_EZWEBSOCKETSESSION_HPP_
#define GS2_EZ_GATEWAY_MODEL_EZWEBSOCKETSESSION_HPP_

#include <gs2/gateway/model/WebSocketSession.hpp>


namespace gs2 { namespace ez { namespace gateway {

class EzWebSocketSession : public gs2::Gs2Object
{
private:
    /** コネクションID */
    gs2::optional<StringHolder> m_ConnectionId;
    /** ネームスペース名 */
    gs2::optional<StringHolder> m_NamespaceName;
    /** ユーザーID */
    gs2::optional<StringHolder> m_UserId;

public:
    EzWebSocketSession() = default;

    EzWebSocketSession(gs2::gateway::WebSocketSession webSocketSession) :
        m_ConnectionId(webSocketSession.getConnectionId()),
        m_NamespaceName(webSocketSession.getNamespaceName()),
        m_UserId(webSocketSession.getUserId())
    {
    }

    gs2::gateway::WebSocketSession ToModel() const
    {
        gs2::gateway::WebSocketSession webSocketSession;
        webSocketSession.setConnectionId(*m_ConnectionId);
        webSocketSession.setNamespaceName(*m_NamespaceName);
        webSocketSession.setUserId(*m_UserId);
        return webSocketSession;
    }

    // ========================================
    //   Getters
    // ========================================

    const gs2::StringHolder& getConnectionId() const
    {
        return *m_ConnectionId;
    }

    gs2::StringHolder& getConnectionId()
    {
        return *m_ConnectionId;
    }

    const gs2::StringHolder& getNamespaceName() const
    {
        return *m_NamespaceName;
    }

    gs2::StringHolder& getNamespaceName()
    {
        return *m_NamespaceName;
    }

    const gs2::StringHolder& getUserId() const
    {
        return *m_UserId;
    }

    gs2::StringHolder& getUserId()
    {
        return *m_UserId;
    }

    // ========================================
    //   Setters
    // ========================================

    void setConnectionId(Char* connectionId)
    {
        m_ConnectionId.emplace(connectionId);
    }

    void setNamespaceName(Char* namespaceName)
    {
        m_NamespaceName.emplace(namespaceName);
    }

    void setUserId(Char* userId)
    {
        m_UserId.emplace(userId);
    }

    EzWebSocketSession& withConnectionId(Char* connectionId)
    {
        setConnectionId(connectionId);
        return *this;
    }

    EzWebSocketSession& withNamespaceName(Char* namespaceName)
    {
        setNamespaceName(namespaceName);
        return *this;
    }

    EzWebSocketSession& withUserId(Char* userId)
    {
        setUserId(userId);
        return *this;
    }
};

}}}

#endif //GS2_EZ_GATEWAY_EZWEBSOCKETSESSION_HPP_