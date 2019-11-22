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

#include "EzWebSocketSession.hpp"
#include <gs2/gateway/model/WebSocketSession.hpp>


namespace gs2 { namespace ez { namespace gateway {

EzWebSocketSession::Data::Data(const Data& data) :
    Gs2Object(data),
    connectionId(data.connectionId),
    namespaceName(data.namespaceName),
    userId(data.userId)
{
}

EzWebSocketSession::Data::Data(const gs2::gateway::WebSocketSession& webSocketSession) :
    connectionId(webSocketSession.getConnectionId()),
    namespaceName(webSocketSession.getNamespaceName()),
    userId(webSocketSession.getUserId())
{
}

EzWebSocketSession::EzWebSocketSession(gs2::gateway::WebSocketSession webSocketSession) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(webSocketSession)
{
}

EzWebSocketSession EzWebSocketSession::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzWebSocketSession);
}

gs2::gateway::WebSocketSession EzWebSocketSession::ToModel() const
{
    gs2::gateway::WebSocketSession webSocketSession;
    webSocketSession.setConnectionId(getConnectionId());
    webSocketSession.setNamespaceName(getNamespaceName());
    webSocketSession.setUserId(getUserId());
    return webSocketSession;
}

}}}