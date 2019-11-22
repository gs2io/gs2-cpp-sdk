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

#include "Version.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace version {

Version::Data::Data(const Data& data) :
    detail::json::IModel(data),
    major_(data.major_),
    minor_(data.minor_),
    micro(data.micro)
{
}

void Version::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "major") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->major_ = jsonValue.GetInt();
        }
    }
    else if (std::strcmp(name_, "minor") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->minor_ = jsonValue.GetInt();
        }
    }
    else if (std::strcmp(name_, "micro") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->micro = jsonValue.GetInt();
        }
    }
}

Version Version::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Version);
}

bool operator!=(const Version& lhs, const Version& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->major_ != lhr.m_pData->major_)
        {
            return true;
        }
        if (lhs.m_pData->minor_ != lhr.m_pData->minor_)
        {
            return true;
        }
        if (lhs.m_pData->micro != lhr.m_pData->micro)
        {
            return true;
        }
    }
    return false;
}

} }