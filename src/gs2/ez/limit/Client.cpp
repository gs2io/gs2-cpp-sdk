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


namespace gs2 { namespace ez { namespace limit {

Client::Client(gs2::ez::Profile& profile) :
    m_Profile(profile),
    m_Client(profile.getGs2Session())
{
}

void Client::listCounters(
    std::function<void(AsyncEzListCountersResult&)> callback,
    GameSession& session,
    const Char* namespaceName,
    const Char* limitName
)
{
    gs2::limit::DescribeCountersRequest request;
    request.setNamespaceName(namespaceName);
    if (limitName)
    {
        request.setLimitName(limitName);
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.describeCounters(
        request,
        [callback](gs2::limit::AsyncDescribeCountersResult& r)
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
    std::function<void(AsyncEzGetCounterResult&)> callback,
    GameSession& session,
    const Char* namespaceName,
    const Char* limitName,
    const Char* counterName
)
{
    gs2::limit::GetCounterRequest request;
    request.setNamespaceName(namespaceName);
    request.setLimitName(limitName);
    request.setCounterName(counterName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.getCounter(
        request,
        [callback](gs2::limit::AsyncGetCounterResult& r)
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

void Client::listLimitModels(
    std::function<void(AsyncEzListLimitModelsResult&)> callback,
    const Char* namespaceName
)
{
    gs2::limit::DescribeLimitModelsRequest request;
    request.setNamespaceName(namespaceName);
    m_Client.describeLimitModels(
        request,
        [callback](gs2::limit::AsyncDescribeLimitModelsResult& r)
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
    std::function<void(AsyncEzGetLimitModelResult&)> callback,
    const Char* namespaceName,
    const Char* limitName
)
{
    gs2::limit::GetLimitModelRequest request;
    request.setNamespaceName(namespaceName);
    request.setLimitName(limitName);
    m_Client.getLimitModel(
        request,
        [callback](gs2::limit::AsyncGetLimitModelResult& r)
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