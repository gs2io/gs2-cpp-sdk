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
#include <gs2/gateway/Gs2GatewayWebSocketClient.hpp>
#include <gs2/gateway/Gs2GatewayRestClient.hpp>


namespace gs2 { namespace ez { namespace gateway {

Client::Client(gs2::ez::Profile& profile) :
    m_Profile(profile),
    m_pWebSocketClient(new gs2::gateway::Gs2GatewayWebSocketClient(profile.getGs2WebSocketSession())),
    m_pRestClient(new gs2::gateway::Gs2GatewayRestClient(profile.getGs2RestSession()))
{
}

Client::~Client()
{
    delete m_pWebSocketClient;
    delete m_pRestClient;
}

void Client::setUserId(
    std::function<void(AsyncEzSetUserIdResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    Bool allowConcurrentAccess
)
{
    gs2::gateway::SetUserIdRequest request;
    request.setNamespaceName(namespaceName);
    request.setAllowConcurrentAccess(allowConcurrentAccess);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pWebSocketClient->setUserId(
        request,
        [callback](gs2::gateway::AsyncSetUserIdResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzSetUserIdResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
            {
                EzSetUserIdResult ezResult(*r.getResult());
                AsyncEzSetUserIdResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzSetUserIdResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

}}}