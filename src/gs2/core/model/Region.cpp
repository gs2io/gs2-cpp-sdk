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

#include "Region.hpp"
#include <cstring>

GS2_START_OF_NAMESPACE

namespace
{

const Char* Names[] = {
    "ap-northeast-1",
};

const Region::Enum nameToEnum(const Char name[])
{
    if (name != nullptr)
    {
        for (int i = 0; i < GS2_COUNT_OF(Names); ++i)
        {
            if (std::strcmp(name, Names[i]) == 0)
            {
                return static_cast<Region::Enum>(Region::AP_NORTHEAST_1 + i);
            }
        }
    }

    return Region::AP_NORTHEAST_1;
}

const Char* enumToName(Region::Enum e)
{
    return Names[e - Region::AP_NORTHEAST_1];
}

}

Region::Region(Enum region) :
    m_Enum(region)
{
}

Region::Region(const Char name[]) :
    m_Enum(nameToEnum(name))
{
}

const Char* Region::getName() const
{
    return enumToName(m_Enum);
}

GS2_END_OF_NAMESPACE