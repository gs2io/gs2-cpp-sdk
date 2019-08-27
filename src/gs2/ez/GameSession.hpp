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

#ifndef GS2_EZ_GAMESESSION_HPP_
#define GS2_EZ_GAMESESSION_HPP_

#include "../core/Gs2Object.hpp"
#include "../auth/model/AccessToken.hpp"

namespace gs2 { namespace ez {

class GameSession : public gs2::Gs2Object
{
private:
    gs2::auth::AccessToken m_AccessToken;

public:
    GameSession(const gs2::auth::AccessToken& accessToken) :
        m_AccessToken(accessToken)
    {}

    const gs2::auth::AccessToken& getAccessToken() const
    {
        return m_AccessToken;
    }
};

}}

#endif //GS2_EZ_GAMESESSION_HPP_
