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
#include <gs2/lottery/Gs2LotteryWebSocketClient.hpp>
#include <gs2/lottery/Gs2LotteryRestClient.hpp>


namespace gs2 { namespace ez { namespace lottery {

Client::Client(gs2::ez::Profile& profile) :
    m_Profile(profile),
    m_pWebSocketClient(new gs2::lottery::Gs2LotteryWebSocketClient(profile.getGs2WebSocketSession())),
    m_pRestClient(new gs2::lottery::Gs2LotteryRestClient(profile.getGs2RestSession()))
{
}

Client::~Client()
{
    delete m_pWebSocketClient;
    delete m_pRestClient;
}

void Client::describeBoxes(
    std::function<void(AsyncEzDescribeBoxesResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    gs2::optional<StringHolder> pageToken,
    gs2::optional<Int64> limit
)
{
    gs2::lottery::DescribeBoxesRequest request;
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
    m_pRestClient->describeBoxes(
        request,
        [callback](gs2::lottery::AsyncDescribeBoxesResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzDescribeBoxesResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
            {
                EzDescribeBoxesResult ezResult(*r.getResult());
                AsyncEzDescribeBoxesResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzDescribeBoxesResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getBox(
    std::function<void(AsyncEzGetBoxResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder prizeTableName
)
{
    gs2::lottery::GetBoxRequest request;
    request.setNamespaceName(namespaceName);
    request.setPrizeTableName(prizeTableName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pWebSocketClient->getBox(
        request,
        [callback](gs2::lottery::AsyncGetBoxResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetBoxResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
            {
                EzGetBoxResult ezResult(*r.getResult());
                AsyncEzGetBoxResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetBoxResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::resetBox(
    std::function<void(AsyncEzResetBoxResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder prizeTableName
)
{
    gs2::lottery::ResetBoxRequest request;
    request.setNamespaceName(namespaceName);
    request.setPrizeTableName(prizeTableName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pWebSocketClient->resetBox(
        request,
        [callback](gs2::lottery::AsyncResetBoxResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzResetBoxResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else
            {
                AsyncEzResetBoxResult asyncResult;
                callback(asyncResult);
            }
        }
    );
}

void Client::listProbabilities(
    std::function<void(AsyncEzListProbabilitiesResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder lotteryName
)
{
    gs2::lottery::DescribeProbabilitiesRequest request;
    request.setNamespaceName(namespaceName);
    request.setLotteryName(lotteryName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pWebSocketClient->describeProbabilities(
        request,
        [callback](gs2::lottery::AsyncDescribeProbabilitiesResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListProbabilitiesResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
            {
                EzListProbabilitiesResult ezResult(*r.getResult());
                AsyncEzListProbabilitiesResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzListProbabilitiesResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

}}}