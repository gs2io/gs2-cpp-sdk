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

#ifndef GS2_EZ_GS2ACCOUNTAUTHENTICATOR_HPP_
#define GS2_EZ_GS2ACCOUNTAUTHENTICATOR_HPP_

#include "Authenticator.hpp"
#include "../core/util/StringHolder.hpp"

namespace gs2 {

class Gs2WebSocketSession;

namespace ez {

class Gs2AccountAuthenticator : public IAuthenticator, public gs2::Gs2Object
{
private:
    Gs2WebSocketSession& m_Gs2Session;
    StringHolder m_AccountNamespace;
    StringHolder m_KeyId;
    StringHolder m_UserId;
    StringHolder m_Password;

public:
    Gs2AccountAuthenticator(
        Gs2WebSocketSession& gs2WebSocketSession,
        StringHolder accountNamespace,
        StringHolder keyId,
        StringHolder userId,
        StringHolder password
    );

    Gs2AccountAuthenticator(const Gs2AccountAuthenticator&) = default;
    Gs2AccountAuthenticator(Gs2AccountAuthenticator&&) = default;

    ~Gs2AccountAuthenticator() GS2_OVERRIDE = default;

    void authentication(AuthenticationCallback callback) GS2_OVERRIDE;
};

}}

#endif //GS2_EZ_GS2ACCOUNTAUTHENTICATOR_HPP_
