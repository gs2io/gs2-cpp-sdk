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
#include <gs2/exchange/Gs2ExchangeWebSocketClient.hpp>
#include <gs2/exchange/Gs2ExchangeRestClient.hpp>


namespace gs2 { namespace ez { namespace exchange {

Client::Client(gs2::ez::Profile& profile) :
    m_Profile(profile),
    m_pWebSocketClient(new gs2::exchange::Gs2ExchangeWebSocketClient(profile.getGs2WebSocketSession())),
    m_pRestClient(new gs2::exchange::Gs2ExchangeRestClient(profile.getGs2RestSession()))
{
}

Client::~Client()
{
    delete m_pWebSocketClient;
    delete m_pRestClient;
}

void Client::listRateModels(
    std::function<void(AsyncEzListRateModelsResult)> callback,
    StringHolder namespaceName
)
{
    gs2::exchange::DescribeRateModelsRequest request;
    request.setNamespaceName(namespaceName);
    m_pRestClient->describeRateModels(
        request,
        [callback](gs2::exchange::AsyncDescribeRateModelsResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListRateModelsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
            {
                EzListRateModelsResult ezResult(*r.getResult());
                AsyncEzListRateModelsResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzListRateModelsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getRateModel(
    std::function<void(AsyncEzGetRateModelResult)> callback,
    StringHolder namespaceName,
    StringHolder rateName
)
{
    gs2::exchange::GetRateModelRequest request;
    request.setNamespaceName(namespaceName);
    request.setRateName(rateName);
    m_pWebSocketClient->getRateModel(
        request,
        [callback](gs2::exchange::AsyncGetRateModelResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetRateModelResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
            {
                EzGetRateModelResult ezResult(*r.getResult());
                AsyncEzGetRateModelResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetRateModelResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::exchange(
    std::function<void(AsyncEzExchangeResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder rateName,
    Int32 count,
    gs2::optional<List<EzConfig>> config
)
{
    gs2::exchange::ExchangeRequest request;
    request.setNamespaceName(namespaceName);
    request.setRateName(rateName);
    request.setCount(count);
    if (config)
    {
        gs2::List<gs2::exchange::Config> list;
        for (int i = 0; i < config->getCount(); ++i)
        {
            list += (*config)[i].ToModel();
        }
        request.setConfig(list);
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pRestClient->exchange(
        request,
        [callback](gs2::exchange::AsyncExchangeResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzExchangeResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
            {
                EzExchangeResult ezResult(*r.getResult());
                AsyncEzExchangeResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzExchangeResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::listAwaits(
    std::function<void(AsyncEzListAwaitsResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    gs2::optional<StringHolder> rateName,
    gs2::optional<StringHolder> pageToken
)
{
    gs2::exchange::DescribeAwaitsRequest request;
    request.setNamespaceName(namespaceName);
    if (rateName)
    {
        request.setRateName(std::move(*rateName));
    }
    if (pageToken)
    {
        request.setPageToken(std::move(*pageToken));
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pRestClient->describeAwaits(
        request,
        [callback](gs2::exchange::AsyncDescribeAwaitsResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListAwaitsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
            {
                EzListAwaitsResult ezResult(*r.getResult());
                AsyncEzListAwaitsResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzListAwaitsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getAwait(
    std::function<void(AsyncEzGetAwaitResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder rateName,
    StringHolder awaitName
)
{
    gs2::exchange::GetAwaitRequest request;
    request.setNamespaceName(namespaceName);
    request.setRateName(rateName);
    request.setAwaitName(awaitName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pWebSocketClient->getAwait(
        request,
        [callback](gs2::exchange::AsyncGetAwaitResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetAwaitResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
            {
                EzGetAwaitResult ezResult(*r.getResult());
                AsyncEzGetAwaitResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetAwaitResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::acquire(
    std::function<void(AsyncEzAcquireResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder rateName,
    StringHolder awaitName
)
{
    gs2::exchange::AcquireRequest request;
    request.setNamespaceName(namespaceName);
    request.setRateName(rateName);
    request.setAwaitName(awaitName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pWebSocketClient->acquire(
        request,
        [callback](gs2::exchange::AsyncAcquireResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzAcquireResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
            {
                EzAcquireResult ezResult(*r.getResult());
                AsyncEzAcquireResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzAcquireResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::skip(
    std::function<void(AsyncEzSkipResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder rateName,
    StringHolder awaitName
)
{
    gs2::exchange::SkipRequest request;
    request.setNamespaceName(namespaceName);
    request.setRateName(rateName);
    request.setAwaitName(awaitName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pWebSocketClient->skip(
        request,
        [callback](gs2::exchange::AsyncSkipResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzSkipResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
            {
                EzSkipResult ezResult(*r.getResult());
                AsyncEzSkipResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzSkipResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::deleteAwait(
    std::function<void(AsyncEzDeleteAwaitResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder rateName,
    StringHolder awaitName
)
{
    gs2::exchange::DeleteAwaitRequest request;
    request.setNamespaceName(namespaceName);
    request.setRateName(rateName);
    request.setAwaitName(awaitName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pWebSocketClient->deleteAwait(
        request,
        [callback](gs2::exchange::AsyncDeleteAwaitResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzDeleteAwaitResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
            {
                EzDeleteAwaitResult ezResult(*r.getResult());
                AsyncEzDeleteAwaitResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzDeleteAwaitResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

}}}