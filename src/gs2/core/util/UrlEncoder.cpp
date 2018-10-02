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

#include "UrlEncoder.hpp"
#include <cctype>
#include <cstring>

GS2_START_OF_NAMESPACE

namespace {

inline char toHex(char ch)
{
    return ch < 10 ? '0' + ch : 'A' + (ch - 10);
}

}

namespace detail {

std::size_t encodeUrl(char* dst, const char* src, std::size_t dstSize)
{
    std::size_t srcSize = std::strlen(src);
    std::size_t writeLen = 0;

    for(int i=0; i<srcSize&&writeLen<dstSize; i++){
        char ch = src[i];
        if (ch == ' ') {
            dst[writeLen++] = '+';
        } else if (std::isalnum(ch) || ch == '-' || ch == '_' || ch == '.' || ch == '~') {
            dst[writeLen++] = ch;
        } else {
            dst[writeLen++] = '%';
            dst[writeLen++] = toHex((ch >> 4) & 0xF);
            dst[writeLen++] = toHex((ch & 0xF));
        }
    }
    if(writeLen < dstSize) {
        dst[writeLen++] = '\0';
    }
    return writeLen;
}

}

GS2_END_OF_NAMESPACE
