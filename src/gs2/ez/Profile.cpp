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

Profile::Profile(const Char clientId[], const Char clientSecret[], IReopener& reopener) :
    m_Reopener(reopener),
    m_Credential(clientId, clientSecret),
    m_Gs2Session(m_Credential)
{
}

void Profile::initialize(InitializeCallbackType callback)
{
    m_Reopener.reopen(callback, m_Gs2Session);
}

void Profile::finalize(FinalizeCallbackType callback)
{
    m_Gs2Session.close(callback);
}

void Profile::login(LoginCallbackType callback, IAuthenticator& authenticator)
{
    authenticator.authentication(callback);
}

}}
