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

#ifndef GS2_CORE_UTIL_STRINGVARIABLE_HPP_
#define GS2_CORE_UTIL_STRINGVARIABLE_HPP_

#include "../Gs2Object.hpp"
#include "StandardAllocator.hpp"
#include <string>

GS2_START_OF_NAMESPACE

namespace detail {

typedef std::basic_string<Char, std::char_traits<Char>, StandardAllocator<Char>> BasicString;

class StringVariable : public BasicString, public Gs2Object
{
public:
    explicit StringVariable(const Char string[])
            : BasicString(string)
    {
    }

    explicit StringVariable(Int32 number)
    {
        char buffer[32];
        std::sprintf(buffer, "%d", number);
        assign(buffer);
    }

    explicit StringVariable(Int64 number)
    {
        char buffer[32];
        std::sprintf(buffer, "%ld", number);
        assign(buffer);
    }

    explicit StringVariable(Float number)
    {
        char buffer[32];
        std::sprintf(buffer, "%f", number);
        assign(buffer);
    }

    explicit StringVariable(Double number)
    {
        char buffer[32];
        std::sprintf(buffer, "%lf", number);
        assign(buffer);
    }

    explicit StringVariable(Bool number)
            : BasicString(number ? "true" : "false")
    {
    }

    StringVariable& replace(const Char pattern[], const Char replacement[]);
    StringVariable& replace(const StringVariable& pattern, const Char replacement[]);
    StringVariable& replace(const Char pattern[], const StringVariable& replacement);
    StringVariable& replace(const StringVariable& pattern, const StringVariable& replacement);
    
    bool endsWith(const Char suffix[]);
    bool endsWith(const StringVariable& suffix);
};

}

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_UTIL_STRINGVARIABLE_HPP_
