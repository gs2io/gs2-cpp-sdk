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

#ifndef GS2_CORE_UTIL_SIGNUTIL_HPP_
#define GS2_CORE_UTIL_SIGNUTIL_HPP_

#include "../common.hpp"

GS2_START_OF_NAMESPACE

class StringHolder;

namespace detail {

class SignUtil {
public:
    struct HmacSha256 {
        unsigned char data[32];     // TODO: typename
    };

    static void sign(HmacSha256& hash, const void *clientSecret, std::size_t clientSecretSize, const void* body, std::size_t bodySize);
};

}

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_UTIL_SIGNUTIL_HPP_
