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
#include "../core/network/Gs2WebSocketSession.hpp"
#include "../core/network/Gs2RestSession.hpp"
#include "GameSession.hpp"
#include <memory>

namespace gs2 { namespace ez {

class IReopener;
class IAuthenticator;

class Profile : public gs2::Gs2Object
{
private:
    std::unique_ptr<IReopener> m_pReopener;
    Gs2WebSocketSession m_Gs2WebSocketSession;
    Gs2RestSession m_Gs2RestSession;

public:
    typedef gs2::AsyncResult<void> AsyncInitializeResult;
    typedef gs2::AsyncResult<GameSession> AsyncLoginResult;

    typedef std::function<void(AsyncInitializeResult)> InitializeCallbackType;
    typedef std::function<void()> FinalizeCallbackType;
    typedef std::function<void(AsyncLoginResult)> LoginCallbackType;

private:
    Profile(IReopener* pReopener, StringHolder&& clientId, StringHolder&& clientSecret);

    void login(IAuthenticator& authenticator, LoginCallbackType callback);

public:
    template<class Reopener>
    Profile(StringHolder clientId, StringHolder clientSecret, Reopener reopener) :
        Profile(new Reopener(std::move(reopener)), std::move(clientId), std::move(clientSecret))
    {}

    void initialize(InitializeCallbackType callback);

    void finalize(FinalizeCallbackType callback);

    template<class Authenticator>
    void login(LoginCallbackType callback, Authenticator authenticator)
    {
        login(authenticator, std::move(callback));
    }

    const Gs2WebSocketSession& getGs2Session() const
    {
        return m_Gs2WebSocketSession;
    }

    Gs2WebSocketSession& getGs2Session()
    {
        return m_Gs2WebSocketSession;
    }

    const Gs2WebSocketSession& getGs2WebSocketSession() const
    {
        return m_Gs2WebSocketSession;
    }

    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return m_Gs2WebSocketSession;
    }

    const Gs2RestSession& getGs2RestSession() const
    {
        return m_Gs2RestSession;
    }

    Gs2RestSession& getGs2RestSession()
    {
        return m_Gs2RestSession;
    }
};

}}

#endif //GS2_EZ_PROFILE_HPP_
