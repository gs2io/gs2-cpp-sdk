/*
 * Copyright 2016 Game Server Services, Inc. or its affiliates. All Rights
 * Reserved.
 *
 * Licensed under the Apache License, Version 2.0(the "License").
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

#include "Client.hpp"
#include "../Profile.hpp"
#include "../GameSession.hpp"
#include <gs2/realtime/Gs2RealtimeWebSocketClient.hpp>
#include <gs2/realtime/Gs2RealtimeRestClient.hpp>


namespace gs2 { namespace ez { namespace realtime {

Client::Client(gs2::ez::Profile& profile) :
    m_Profile(profile),
    m_pWebSocketClient(new gs2::realtime::Gs2RealtimeWebSocketClient(profile.getGs2WebSocketSession())),
    m_pRestClient(new gs2::realtime::Gs2RealtimeRestClient(profile.getGs2RestSession()))
{
}

Client::~Client()
{
    delete m_pWebSocketClient;
    delete m_pRestClient;
}

void Client::getRoom(
    std::function<void(AsyncEzGetRoomResult)> callback,
    StringHolder namespaceName,
    StringHolder roomName
)
{
    gs2::realtime::GetRoomRequest request;
    request.setNamespaceName(namespaceName);
    request.setRoomName(roomName);
    m_pWebSocketClient->getRoom(
        request,
        [callback](gs2::realtime::AsyncGetRoomResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetRoomResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
            {
                EzGetRoomResult ezResult(*r.getResult());
                AsyncEzGetRoomResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetRoomResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

}}}