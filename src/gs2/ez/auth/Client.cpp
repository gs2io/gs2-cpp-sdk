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
#include <gs2/auth/Gs2AuthWebSocketClient.hpp>


namespace gs2 { namespace ez { namespace auth {

Client::Client(gs2::ez::Profile& profile) :
    m_Profile(profile),
    m_pClient(new gs2::auth::Gs2AuthWebSocketClient(profile.getGs2Session()))
{
}

Client::~Client()
{
    delete m_pClient;
}

void Client::login(
    std::function<void(AsyncEzLoginResult)> callback,
    StringHolder userId,
    StringHolder keyId,
    StringHolder body,
    StringHolder signature
)
{
    gs2::auth::LoginBySignatureRequest request;
    request.setUserId(userId);
    request.setKeyId(keyId);
    request.setBody(body);
    request.setSignature(signature);
    m_pClient->loginBySignature(
        request,
        [callback](gs2::auth::AsyncLoginBySignatureResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzLoginResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzLoginResult::isConvertible(*r.getResult()))
            {
                EzLoginResult ezResult(*r.getResult());
                AsyncEzLoginResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzLoginResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

}}}