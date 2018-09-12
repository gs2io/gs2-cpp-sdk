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

#include "StringUtil.hpp"
#include <cstring>

GS2_START_OF_NAMESPACE

namespace detail { namespace StringUtil {

namespace {

const char* toStr(char buffer[], Int32 value)
{
    std::sprintf(buffer, "%d", value);
    return buffer;
}

const char* toStr(char buffer[], Int64 value)
{
    std::sprintf(buffer, "%ld", value);
    return buffer;
}

const char* toStr(char buffer[], UInt32 value)
{
    std::sprintf(buffer, "%u", value);
    return buffer;
}

const char* toStr(char buffer[], UInt64 value)
{
    std::sprintf(buffer, "%lu", value);
    return buffer;
}

const char* setNullStr(char buffer[])
{
    std::strcpy(buffer, "null");
    return buffer;
}

}

const char* toStr(char buffer[], const optional<Int8>& value)
{
    return value ? toStr(buffer, static_cast<Int32>(*value)) : setNullStr(buffer);
}

const char* toStr(char buffer[], const optional<Int16>& value)
{
    return value ? toStr(buffer, static_cast<Int32>(*value)) : setNullStr(buffer);
}

const char* toStr(char buffer[], const optional<Int32>& value)
{
    return value ? toStr(buffer, *value) : setNullStr(buffer);
}

const char* toStr(char buffer[], const optional<Int64>& value)
{
    return value ? toStr(buffer, *value) : setNullStr(buffer);
}

const char* toStr(char buffer[], const optional<UInt8>& value)
{
    return value ? toStr(buffer, static_cast<UInt32>(*value)) : setNullStr(buffer);
}

const char* toStr(char buffer[], const optional<UInt16>& value)
{
    return value ? toStr(buffer, static_cast<UInt32>(*value)) : setNullStr(buffer);
}

const char* toStr(char buffer[], const optional<UInt32>& value)
{
    return value ? toStr(buffer, *value) : setNullStr(buffer);
}

const char* toStr(char buffer[], const optional<UInt64>& value)
{
    return value ? toStr(buffer, *value) : setNullStr(buffer);
}

const char* toStr(char buffer[], const optional<StringHolder>& value)
{
    const char* pStr;
    if (value && *value != "")
    {
        return *value;
    }
    else
    {
        pStr = "null";
    }
    std::strcpy(buffer,  pStr);
    return buffer;
}

} }

GS2_END_OF_NAMESPACE
