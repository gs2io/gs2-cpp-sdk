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

#include "Gs2SessionTaskId.hpp"
#include <cstdio>
#include <cstdlib>

GS2_START_OF_NAMESPACE

namespace detail {

int Gs2SessionTaskId::exportTo(char s[], size_t n) const
{
    auto i = std::snprintf(s, n, "%d", m_Value);
    s[n - 1] = '\0';
    return i;
}

bool Gs2SessionTaskId::importFrom(const char s[])
{
    char* pEnd;
    long value = std::strtol(s, &pEnd, 10);

    if (*pEnd != '\0')
    {
        return false;
    }

    m_Value = static_cast<ValueType>(value);

    return true;
}

}

GS2_END_OF_NAMESPACE
