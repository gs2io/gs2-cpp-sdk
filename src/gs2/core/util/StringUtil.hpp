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

#ifndef GS2_CORE_UTIL_STRINGUTIL_HPP_
#define GS2_CORE_UTIL_STRINGUTIL_HPP_

#include "../common.hpp"
#include "../external/optional/optional.hpp"
#include "StringHolder.hpp"

GS2_START_OF_NAMESPACE

namespace detail { namespace StringUtil {

const char* toStr(char buffer[], const optional<Int8>& value);
const char* toStr(char buffer[], const optional<Int16>& value);
const char* toStr(char buffer[], const optional<Int32>& value);
const char* toStr(char buffer[], const optional<Int64>& value);
const char* toStr(char buffer[], const optional<UInt8>& value);
const char* toStr(char buffer[], const optional<UInt16>& value);
const char* toStr(char buffer[], const optional<UInt32>& value);
const char* toStr(char buffer[], const optional<UInt64>& value);
// value が有効な場合はその内部バッファが返り、 buffer は使われないことに注意
const char* toStr(char buffer[], const optional<StringHolder>& value);

} }

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_UTIL_STRINGUTIL_HPP_
