/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All
 * Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
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

#include "Gs2AccountAuthenticator.hpp"
#include "../account/Gs2AccountRestClient.hpp"
#include "../auth/Gs2AuthRestClient.hpp"

namespace gs2 { namespace ez {

Gs2AccountAuthenticator::Gs2AccountAuthenticator(
    Gs2RestSession& gs2RestSession,
    const Char accountNamespace[],
    const Char keyId[],
    const Char userId[],
    const Char password[]
) :
    m_Gs2Session(gs2RestSession),
    m_AccountNamespace(accountNamespace),
    m_KeyId(keyId),
    m_UserId(userId),
    m_Password(password)
{
}

void Gs2AccountAuthenticator::authentication(std::function<void(gs2::AsyncResult<gs2::auth::AccessToken>)> callback)
{
    gs2::account::Gs2AccountRestClient accountClient(m_Gs2Session);
    gs2::account::AuthenticationRequest authenticationRequest;
    authenticationRequest.setNamespaceName(m_AccountNamespace);
    authenticationRequest.setUserId(m_UserId);
    authenticationRequest.setPassword(m_Password);
    authenticationRequest.setKeyId(m_KeyId);
    accountClient.authentication(
        authenticationRequest,
        [this, callback](gs2::account::AsyncAuthenticationResult& asyncAuthenticationResult)
        {
            if (asyncAuthenticationResult.getError())
            {
                // TODO
                gs2::auth::AccessToken accessToken;
                gs2::optional<gs2::Gs2ClientException> gs2ClientException = asyncAuthenticationResult.getError();
                callback(gs2::AsyncResult<gs2::auth::AccessToken>(accessToken, gs2ClientException));
            }
            else
            {
                auto& authenticationResult = *asyncAuthenticationResult.getResult();
                if (!authenticationResult.getBody() || !authenticationResult.getSignature())
                {
                    // TODO:
                }

                gs2::auth::Gs2AuthRestClient authClient(m_Gs2Session);
                gs2::auth::LoginBySignatureRequest loginBySignatureRequest;
                loginBySignatureRequest.setUserId(m_UserId);
                loginBySignatureRequest.setKeyId(m_KeyId);
                loginBySignatureRequest.setBody(*authenticationResult.getBody());
                loginBySignatureRequest.setSignature(*authenticationResult.getSignature());
                authClient.loginBySignature(
                    loginBySignatureRequest,
                    [callback](gs2::auth::AsyncLoginBySignatureResult asyncLoginBySignatureResult)
                    {
                        if (asyncLoginBySignatureResult.getError())
                        {
                            // TODO
                            gs2::auth::AccessToken accessToken;
                            gs2::optional<gs2::Gs2ClientException> gs2ClientException = asyncLoginBySignatureResult.getError();
                            callback(gs2::AsyncResult<gs2::auth::AccessToken>(accessToken, gs2ClientException));
                        }
                        else
                        {
                            auto& loginBySignatureResult = *asyncLoginBySignatureResult.getResult();
                            if (
                                !loginBySignatureResult.getToken() ||
                                !loginBySignatureResult.getExpire() ||
                                !loginBySignatureResult.getUserId()
                            )
                            {
                                // TODO:
                            }

                            gs2::auth::AccessToken accessToken;
                            accessToken.setToken(*loginBySignatureResult.getToken());
                            accessToken.setExpire(*loginBySignatureResult.getExpire());
                            accessToken.setUserId(*loginBySignatureResult.getUserId());
                            // TODO
                            gs2::optional<gs2::Gs2ClientException> gs2ClientException;
                            callback(gs2::AsyncResult<gs2::auth::AccessToken>(accessToken, gs2ClientException));
                        }
                    }
                );
            }
        }
    );
}

}}
