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
#include <gs2/news/Gs2NewsWebSocketClient.hpp>
#include <gs2/news/Gs2NewsRestClient.hpp>


namespace gs2 { namespace ez { namespace news {

Client::Client(gs2::ez::Profile& profile) :
    m_Profile(profile),
    m_pWebSocketClient(new gs2::news::Gs2NewsWebSocketClient(profile.getGs2WebSocketSession())),
    m_pRestClient(new gs2::news::Gs2NewsRestClient(profile.getGs2RestSession()))
{
}

Client::~Client()
{
    delete m_pWebSocketClient;
    delete m_pRestClient;
}

void Client::listNewses(
    std::function<void(AsyncEzListNewsesResult)> callback,
    GameSession& session,
    StringHolder namespaceName
)
{
    gs2::news::DescribeNewsRequest request;
    request.setNamespaceName(namespaceName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pRestClient->describeNews(
        request,
        [callback](gs2::news::AsyncDescribeNewsResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListNewsesResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzListNewsesResult::isConvertible(*r.getResult()))
            {
                EzListNewsesResult ezResult(*r.getResult());
                AsyncEzListNewsesResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzListNewsesResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getContentsUrl(
    std::function<void(AsyncEzGetContentsUrlResult)> callback,
    GameSession& session,
    StringHolder namespaceName
)
{
    gs2::news::WantGrantRequest request;
    request.setNamespaceName(namespaceName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pWebSocketClient->wantGrant(
        request,
        [callback](gs2::news::AsyncWantGrantResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetContentsUrlResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetContentsUrlResult::isConvertible(*r.getResult()))
            {
                EzGetContentsUrlResult ezResult(*r.getResult());
                AsyncEzGetContentsUrlResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetContentsUrlResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

}}}