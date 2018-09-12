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

#ifndef GS2_CORE_UTIL_BASE64_HPP_
#define GS2_CORE_UTIL_BASE64_HPP_

#include "../common.hpp"

GS2_START_OF_NAMESPACE

namespace detail {

void encodeBase64(char dst[], const void* src, std::size_t size);
std::size_t decodeBase64(void* dst, const char src[]);

constexpr std::size_t getBase64EncodedLength(std::size_t decodedSize)
{
    return (decodedSize + 2) / 3 * 4;
}

constexpr std::size_t getBase64DecodedLengthMax(std::size_t decodedSize)
{
    return (decodedSize) / 4 * 3;
}

}

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_UTIL_BASE64_HPP_
