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

#ifndef GS2_EZ_PROFILE_HPP_
#define GS2_EZ_PROFILE_HPP_

#include "../core/Gs2Object.hpp"
#include "../core/AsyncResult.hpp"
#include "../core/model/BasicGs2Credential.hpp"
#include "../core/network/Gs2RestSession.hpp"
#include "GameSession.hpp"

namespace gs2 { namespace ez {

class IReopener;
class IAuthenticator;

class Profile : public gs2::Gs2Object
{
private:
    IReopener& m_Reopener;
    BasicGs2Credential m_Credential;
    Gs2RestSession m_Gs2Session;

public:
    typedef std::function<void(gs2::AsyncResult<void>&)> InitializeCallbackType;
    typedef std::function<void()> FinalizeCallbackType;
    typedef std::function<void(gs2::AsyncResult<GameSession>&)> LoginCallbackType;

public:
    Profile(const Char clientId[], const Char clientSecret[], IReopener& reopener);

    void initialize(InitializeCallbackType callback);

    void finalize(FinalizeCallbackType callback);

    void login(LoginCallbackType callback, IAuthenticator& authenticator);

    const Gs2RestSession& getGs2Session() const
    {
        return m_Gs2Session;
    }

    Gs2RestSession& getGs2Session()
    {
        return m_Gs2Session;
    }
};

}}

#endif //GS2_EZ_PROFILE_HPP_
