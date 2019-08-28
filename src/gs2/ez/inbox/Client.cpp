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


namespace gs2 { namespace ez { namespace inbox {

Client::Client(gs2::ez::Profile& profile) :
    m_Profile(profile),
    m_Client(profile.getGs2Session())
{
}

void Client::List(
    std::function<void(AsyncEzListResult&)> callback,
    GameSession& session,
    const Char* namespaceName,
    const Char* pageToken,
    gs2::optional<Int64> limit
)
{
    gs2::inbox::DescribeMessagesRequest request;
    request.setNamespaceName(namespaceName);
    if (pageToken)
    {
        request.setPageToken(pageToken);
    }
    if (limit)
    {
        request.setLimit(*limit);
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.describeMessages(
        request,
        [callback](gs2::inbox::AsyncDescribeMessagesResult& r)
        {
            if (r.getError())
            {
                EzListResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzListResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzListResult::isConvertible(*r.getResult()))
                {
                    EzListResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzListResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzListResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzListResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

void Client::Read(
    std::function<void(AsyncEzReadResult&)> callback,
    GameSession& session,
    const Char* namespaceName,
    const Char* messageName
)
{
    gs2::inbox::ReadMessageRequest request;
    request.setNamespaceName(namespaceName);
    if (messageName)
    {
        request.setMessageName(messageName);
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.readMessage(
        request,
        [callback](gs2::inbox::AsyncReadMessageResult& r)
        {
            if (r.getError())
            {
                EzReadResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzReadResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzReadResult::isConvertible(*r.getResult()))
                {
                    EzReadResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzReadResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzReadResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzReadResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

void Client::Delete(
    std::function<void(AsyncEzDeleteResult&)> callback,
    GameSession& session,
    const Char* namespaceName,
    const Char* messageName
)
{
    gs2::inbox::DeleteMessageRequest request;
    request.setNamespaceName(namespaceName);
    request.setMessageName(messageName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.deleteMessage(
        request,
        [callback](gs2::inbox::AsyncDeleteMessageResult& r)
        {
            if (r.getError())
            {
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<void> asyncResult(gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                gs2::AsyncResult<void> asyncResult(gs2ClientException);
                callback(asyncResult);
            }
        }
    );
}

}}}