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

#include "FollowUser.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace friend_ {

FollowUser::Data::Data(const Data& data) :
    detail::json::IModel(data),
    userId(data.userId),
    publicProfile(data.publicProfile),
    followerProfile(data.followerProfile)
{
}

void FollowUser::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "userId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->userId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "publicProfile") == 0)
    {
        if (jsonValue.IsString())
        {
            this->publicProfile.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "followerProfile") == 0)
    {
        if (jsonValue.IsString())
        {
            this->followerProfile.emplace(jsonValue.GetString());
        }
    }
}

FollowUser FollowUser::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(FollowUser);
}

bool operator!=(const FollowUser& lhs, const FollowUser& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->publicProfile != lhr.m_pData->publicProfile)
        {
            return true;
        }
        if (lhs.m_pData->followerProfile != lhr.m_pData->followerProfile)
        {
            return true;
        }
    }
    return false;
}

} }