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

#include "Profile.hpp"
#include "Reopener.hpp"
#include "Authenticator.hpp"

namespace gs2 { namespace ez {

Profile::Profile(IReopener* pReopener, StringHolder&& clientId, StringHolder&& clientSecret) :
    m_pReopener(pReopener),
    m_Gs2Session(BasicGs2Credential(std::move(clientId), std::move(clientSecret)))
{
}

void Profile::initialize(InitializeCallbackType callback)
{
    m_pReopener->reopen(callback, m_Gs2Session);
}

void Profile::finalize(FinalizeCallbackType callback)
{
    m_Gs2Session.close(callback);
}

void Profile::login(LoginCallbackType callback, IAuthenticator& authenticator)
{
    authenticator.authentication(
        [callback](gs2::AsyncResult<gs2::auth::AccessToken> r)
        {
            if (r.getError())
            {
                callback(gs2::AsyncResult<GameSession>(*r.getError()));
            }
            else if (r.getResult())
            {
                callback(gs2::AsyncResult<GameSession>(*r.getResult()));
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);   // TODO
                callback(gs2::AsyncResult<GameSession>(std::move(gs2ClientException)));
            }
        }
    );
}

}}
