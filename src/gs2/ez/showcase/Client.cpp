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


namespace gs2 { namespace ez { namespace showcase {

Client::Client(gs2::ez::Profile& profile) :
    m_Profile(profile),
    m_Client(profile.getGs2Session())
{
}

void Client::getShowcase(
    std::function<void(AsyncEzGetShowcaseResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder showcaseName
)
{
    gs2::showcase::GetShowcaseRequest request;
    request.setNamespaceName(namespaceName);
    request.setShowcaseName(showcaseName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.getShowcase(
        request,
        [callback](gs2::showcase::AsyncGetShowcaseResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetShowcaseResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetShowcaseResult::isConvertible(*r.getResult()))
            {
                EzGetShowcaseResult ezResult(*r.getResult());
                AsyncEzGetShowcaseResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetShowcaseResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::buy(
    std::function<void(AsyncEzBuyResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder showcaseName,
    StringHolder displayItemId,
    gs2::optional<List<EzConfig>> config
)
{
    gs2::showcase::BuyRequest request;
    request.setNamespaceName(namespaceName);
    request.setShowcaseName(showcaseName);
    request.setDisplayItemId(displayItemId);
    if (config)
    {
        gs2::List<gs2::showcase::Config> list;
        for (int i = 0; i < config->getCount(); ++i)
        {
            list += (*config)[i].ToModel();
        }
        request.setConfig(list);
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.buy(
        request,
        [callback](gs2::showcase::AsyncBuyResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzBuyResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzBuyResult::isConvertible(*r.getResult()))
            {
                EzBuyResult ezResult(*r.getResult());
                AsyncEzBuyResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzBuyResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

}}}