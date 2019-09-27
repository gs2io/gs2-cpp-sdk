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


namespace gs2 { namespace ez { namespace exchange {

Client::Client(gs2::ez::Profile& profile) :
    m_Profile(profile),
    m_Client(profile.getGs2Session())
{
}

void Client::listRateModels(
    std::function<void(AsyncEzListRateModelsResult)> callback,
    StringHolder namespaceName
)
{
    gs2::exchange::DescribeRateModelsRequest request;
    request.setNamespaceName(namespaceName);
    m_Client.describeRateModels(
        request,
        [callback](gs2::exchange::AsyncDescribeRateModelsResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListRateModelsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzListRateModelsResult::isConvertible(*r.getResult()))
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
    m_Client.getRateModel(
        request,
        [callback](gs2::exchange::AsyncGetRateModelResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetRateModelResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetRateModelResult::isConvertible(*r.getResult()))
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
    StringHolder rateName
)
{
    gs2::exchange::ExchangeRequest request;
    request.setNamespaceName(namespaceName);
    request.setRateName(rateName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.exchange(
        request,
        [callback](gs2::exchange::AsyncExchangeResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzExchangeResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzExchangeResult::isConvertible(*r.getResult()))
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

}}}