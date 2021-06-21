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
#include <gs2/money/Gs2MoneyWebSocketClient.hpp>
#include <gs2/money/Gs2MoneyRestClient.hpp>


namespace gs2 { namespace ez { namespace money {

Client::Client(gs2::ez::Profile& profile) :
    m_Profile(profile),
    m_pWebSocketClient(new gs2::money::Gs2MoneyWebSocketClient(profile.getGs2WebSocketSession())),
    m_pRestClient(new gs2::money::Gs2MoneyRestClient(profile.getGs2RestSession()))
{
}

Client::~Client()
{
    delete m_pWebSocketClient;
    delete m_pRestClient;
}

void Client::get(
    std::function<void(AsyncEzGetResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    Int32 slot
)
{
    gs2::money::GetWalletRequest request;
    request.setNamespaceName(namespaceName);
    request.setSlot(slot);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pWebSocketClient->getWallet(
        request,
        [callback](gs2::money::AsyncGetWalletResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetResult::isConvertible(*r.getResult()))
            {
                EzGetResult ezResult(*r.getResult());
                AsyncEzGetResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::withdraw(
    std::function<void(AsyncEzWithdrawResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    Int32 slot,
    Int32 count,
    Bool paidOnly
)
{
    gs2::money::WithdrawRequest request;
    request.setNamespaceName(namespaceName);
    request.setSlot(slot);
    request.setCount(count);
    request.setPaidOnly(paidOnly);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pWebSocketClient->withdraw(
        request,
        [callback](gs2::money::AsyncWithdrawResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzWithdrawResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzWithdrawResult::isConvertible(*r.getResult()))
            {
                EzWithdrawResult ezResult(*r.getResult());
                AsyncEzWithdrawResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzWithdrawResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

}}}