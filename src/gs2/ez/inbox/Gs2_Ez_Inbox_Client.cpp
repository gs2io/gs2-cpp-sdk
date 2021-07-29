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
#include <gs2/inbox/Gs2InboxWebSocketClient.hpp>
#include <gs2/inbox/Gs2InboxRestClient.hpp>


namespace gs2 { namespace ez { namespace inbox {

Client::Client(gs2::ez::Profile& profile) :
    m_Profile(profile),
    m_pWebSocketClient(new gs2::inbox::Gs2InboxWebSocketClient(profile.getGs2WebSocketSession())),
    m_pRestClient(new gs2::inbox::Gs2InboxRestClient(profile.getGs2RestSession()))
{
}

Client::~Client()
{
    delete m_pWebSocketClient;
    delete m_pRestClient;
}

void Client::list(
    std::function<void(AsyncEzListResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    gs2::optional<StringHolder> pageToken,
    gs2::optional<Int64> limit
)
{
    gs2::inbox::DescribeMessagesRequest request;
    request.setNamespaceName(namespaceName);
    if (pageToken)
    {
        request.setPageToken(std::move(*pageToken));
    }
    if (limit)
    {
        request.setLimit(std::move(*limit));
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pRestClient->describeMessages(
        request,
        [callback](gs2::inbox::AsyncDescribeMessagesResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
            {
                EzListResult ezResult(*r.getResult());
                AsyncEzListResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzListResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::receiveGlobalMessage(
    std::function<void(AsyncEzReceiveGlobalMessageResult)> callback,
    GameSession& session,
    StringHolder namespaceName
)
{
    gs2::inbox::ReceiveGlobalMessageRequest request;
    request.setNamespaceName(namespaceName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pWebSocketClient->receiveGlobalMessage(
        request,
        [callback](gs2::inbox::AsyncReceiveGlobalMessageResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzReceiveGlobalMessageResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
            {
                EzReceiveGlobalMessageResult ezResult(*r.getResult());
                AsyncEzReceiveGlobalMessageResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzReceiveGlobalMessageResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::read(
    std::function<void(AsyncEzReadResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    gs2::optional<StringHolder> messageName
)
{
    gs2::inbox::ReadMessageRequest request;
    request.setNamespaceName(namespaceName);
    if (messageName)
    {
        request.setMessageName(std::move(*messageName));
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pRestClient->readMessage(
        request,
        [callback](gs2::inbox::AsyncReadMessageResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzReadResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
            {
                EzReadResult ezResult(*r.getResult());
                AsyncEzReadResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzReadResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::delete_(
    std::function<void(AsyncEzDeleteResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder messageName
)
{
    gs2::inbox::DeleteMessageRequest request;
    request.setNamespaceName(namespaceName);
    request.setMessageName(messageName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pWebSocketClient->deleteMessage(
        request,
        [callback](gs2::inbox::AsyncDeleteMessageResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzDeleteResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else
            {
                AsyncEzDeleteResult asyncResult;
                callback(asyncResult);
            }
        }
    );
}

}}}