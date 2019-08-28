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


namespace gs2 { namespace ez { namespace auth {

Client::Client(gs2::ez::Profile& profile) :
    m_Profile(profile),
    m_Client(profile.getGs2Session())
{
}

void Client::Login(
    std::function<void(AsyncEzLoginResult&)> callback,
    const Char* userId,
    const Char* keyId,
    const Char* body,
    const Char* signature
)
{
    gs2::auth::LoginBySignatureRequest request;
    request.setUserId(userId);
    request.setKeyId(keyId);
    request.setBody(body);
    request.setSignature(signature);
    m_Client.loginBySignature(
        request,
        [callback](gs2::auth::AsyncLoginBySignatureResult& r)
        {
            if (r.getError())
            {
                EzLoginResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzLoginResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzLoginResult::isConvertible(*r.getResult()))
                {
                    EzLoginResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzLoginResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzLoginResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzLoginResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

}}}