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

void Client::List(
    std::function<void(AsyncEzListResult&)> callback,
    GameSession& session,
    const Char* namespaceName
)
{
    gs2::showcase::DescribeShowcasesRequest request;
    request.setNamespaceName(namespaceName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.describeShowcases(
        request,
        [callback](gs2::showcase::AsyncDescribeShowcasesResult& r)
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

void Client::Buy(
    std::function<void(AsyncEzBuyResult&)> callback,
    GameSession& session,
    const Char* namespaceName,
    const Char* displayItemId
)
{
    gs2::showcase::BuyRequest request;
    request.setNamespaceName(namespaceName);
    if (displayItemId)
    {
        request.setDisplayItemId(displayItemId);
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.buy(
        request,
        [callback](gs2::showcase::AsyncBuyResult& r)
        {
            if (r.getError())
            {
                EzBuyResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzBuyResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzBuyResult::isConvertible(*r.getResult()))
                {
                    EzBuyResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzBuyResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzBuyResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzBuyResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

}}}