/*
 * Copyright 2016 Game Server Services, Inc. or its affiliates. All Rights
 * Reserved.
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

#include "EzAccessToken.hpp"
#include <gs2/auth/model/AccessToken.hpp>


namespace gs2 { namespace ez { namespace auth {

EzAccessToken::Data::Data(const Data& data) :
    Gs2Object(data),
    token(data.token),
    userId(data.userId),
    expire(data.expire)
{
}

EzAccessToken::Data::Data(const gs2::auth::AccessToken& accessToken) :
    token(accessToken.getToken() ? *accessToken.getToken() : StringHolder()),
    userId(accessToken.getUserId() ? *accessToken.getUserId() : StringHolder()),
    expire(accessToken.getExpire() ? *accessToken.getExpire() : 0)
{
}

EzAccessToken::Data::Data(const gs2::optional<gs2::auth::AccessToken>& accessToken) :
    token(accessToken && accessToken->getToken() ? *accessToken->getToken() : StringHolder()),
    userId(accessToken && accessToken->getUserId() ? *accessToken->getUserId() : StringHolder()),
    expire(accessToken && accessToken->getExpire() ? *accessToken->getExpire() : 0)
{
}

EzAccessToken::EzAccessToken(gs2::auth::AccessToken accessToken) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(accessToken)
{
}

EzAccessToken::EzAccessToken(gs2::optional<gs2::auth::AccessToken> accessToken) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(accessToken)
{
}

EzAccessToken EzAccessToken::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzAccessToken);
}

gs2::auth::AccessToken EzAccessToken::ToModel() const
{
    gs2::auth::AccessToken accessToken;
    accessToken.setToken(getToken());
    accessToken.setUserId(getUserId());
    accessToken.setExpire(getExpire());
    return accessToken;
}

}}}