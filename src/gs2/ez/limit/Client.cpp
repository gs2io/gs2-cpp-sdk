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
#include <gs2/limit/Gs2LimitWebSocketClient.hpp>
#include <gs2/limit/Gs2LimitRestClient.hpp>


namespace gs2 { namespace ez { namespace limit {

Client::Client(gs2::ez::Profile& profile) :
    m_Profile(profile),
    m_pWebSocketClient(new gs2::limit::Gs2LimitWebSocketClient(profile.getGs2WebSocketSession())),
    m_pRestClient(new gs2::limit::Gs2LimitRestClient(profile.getGs2RestSession()))
{
}

Client::~Client()
{
    delete m_pWebSocketClient;
    delete m_pRestClient;
}

void Client::listCounters(
    std::function<void(AsyncEzListCountersResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    gs2::optional<StringHolder> limitName,
    gs2::optional<StringHolder> pageToken,
    gs2::optional<Int64> limit
)
{
    gs2::limit::DescribeCountersRequest request;
    request.setNamespaceName(namespaceName);
    if (limitName)
    {
        request.setLimitName(std::move(*limitName));
    }
    if (pageToken)
    {
        request.setPageToken(std::move(*pageToken));
    }
    if (limit)
    {
        request.setLimit(std::move(*limit));
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pRestClient->describeCounters(
        request,
        [callback](gs2::limit::AsyncDescribeCountersResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListCountersResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzListCountersResult::isConvertible(*r.getResult()))
            {
                EzListCountersResult ezResult(*r.getResult());
                AsyncEzListCountersResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzListCountersResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getCounter(
    std::function<void(AsyncEzGetCounterResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder limitName,
    StringHolder counterName
)
{
    gs2::limit::GetCounterRequest request;
    request.setNamespaceName(namespaceName);
    request.setLimitName(limitName);
    request.setCounterName(counterName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pWebSocketClient->getCounter(
        request,
        [callback](gs2::limit::AsyncGetCounterResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetCounterResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetCounterResult::isConvertible(*r.getResult()))
            {
                EzGetCounterResult ezResult(*r.getResult());
                AsyncEzGetCounterResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetCounterResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::countUp(
    std::function<void(AsyncEzCountUpResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder limitName,
    StringHolder counterName,
    gs2::optional<Int32> countUpValue,
    gs2::optional<Int32> maxValue
)
{
    gs2::limit::CountUpRequest request;
    request.setNamespaceName(namespaceName);
    request.setLimitName(limitName);
    request.setCounterName(counterName);
    if (countUpValue)
    {
        request.setCountUpValue(std::move(*countUpValue));
    }
    if (maxValue)
    {
        request.setMaxValue(std::move(*maxValue));
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pWebSocketClient->countUp(
        request,
        [callback](gs2::limit::AsyncCountUpResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzCountUpResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzCountUpResult::isConvertible(*r.getResult()))
            {
                EzCountUpResult ezResult(*r.getResult());
                AsyncEzCountUpResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzCountUpResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::listLimitModels(
    std::function<void(AsyncEzListLimitModelsResult)> callback,
    StringHolder namespaceName
)
{
    gs2::limit::DescribeLimitModelsRequest request;
    request.setNamespaceName(namespaceName);
    m_pRestClient->describeLimitModels(
        request,
        [callback](gs2::limit::AsyncDescribeLimitModelsResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListLimitModelsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzListLimitModelsResult::isConvertible(*r.getResult()))
            {
                EzListLimitModelsResult ezResult(*r.getResult());
                AsyncEzListLimitModelsResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzListLimitModelsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getLimitModel(
    std::function<void(AsyncEzGetLimitModelResult)> callback,
    StringHolder namespaceName,
    StringHolder limitName
)
{
    gs2::limit::GetLimitModelRequest request;
    request.setNamespaceName(namespaceName);
    request.setLimitName(limitName);
    m_pWebSocketClient->getLimitModel(
        request,
        [callback](gs2::limit::AsyncGetLimitModelResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetLimitModelResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetLimitModelResult::isConvertible(*r.getResult()))
            {
                EzGetLimitModelResult ezResult(*r.getResult());
                AsyncEzGetLimitModelResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetLimitModelResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

}}}