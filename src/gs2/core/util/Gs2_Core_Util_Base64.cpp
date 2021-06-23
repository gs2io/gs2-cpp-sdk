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

#include "Base64.hpp"

GS2_START_OF_NAMESPACE

namespace {

const char EncodeTable[] =
        "ABCDEFGHIJKLMNOP"
        "QRSTUVWXYZabcdef"
        "ghijklmnopqrstuv"
        "wxyz0123456789+/";

const unsigned char NA = 255;

const unsigned char DecodeTable[] = {
        NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, // ................
        NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, // ................
        NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, 62, NA, NA, NA, 63, // ...........+.../
        52, 53, 54, 55, 56, 57, 58, 59, 60, 61, NA, NA, NA, NA, NA, NA, // 0123456789......
        NA,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, // .ABCDEFGHIJKLMNO
        15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, NA, NA, NA, NA, NA, // PQRSTUVWXYZ.....
        NA, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, // .abcdefghijklmno
        41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, NA, NA, NA, NA, NA, // pqrstuvwxyz.....
        NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, // ................
        NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, // ................
        NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, // ................
        NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, // ................
        NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, // ................
        NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, // ................
        NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, // ................
        NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, NA, // ................
};

}

namespace detail {

void encodeBase64(char dst[], const void* src, std::size_t size)
{
    unsigned char* pDst = reinterpret_cast<unsigned char*>(dst);
    const unsigned char* pSrc = reinterpret_cast<const unsigned char*>(src);

    while (true)
    {
        if (size == 0)
        {
            pDst[0] = '\0';
            break;
        }
        else
        {
            pDst[0] = EncodeTable[ (pSrc[0] & 0xfc) >> 2];
            --size;
        }

        if (size == 0)
        {
            pDst[1] = EncodeTable[ (pSrc[0] & 0x03) << 4];
            pDst[2] = '=';
            pDst[3] = '=';
            pDst[4] = '\0';
            break;
        }
        else
        {
            pDst[1] = EncodeTable[((pSrc[0] & 0x03) << 4) + ((pSrc[1] & 0xf0) >> 4)];
            --size;
        }

        if (size == 0)
        {
            pDst[2] = EncodeTable[ (pSrc[1] & 0x0f) << 2];
            pDst[3] = '=';
            pDst[4] = '\0';
            break;
        }
        else
        {
            pDst[2] = EncodeTable[((pSrc[1] & 0x0f) << 2) + ((pSrc[2] & 0xc0) >> 6)];
            pDst[3] = EncodeTable[  pSrc[2] & 0x3f];
            --size;
        }

        pDst += 4;
        pSrc += 3;
    }
}

std::size_t decodeBase64(void* dst, const char src[])
{
    unsigned char* pDst = reinterpret_cast<unsigned char*>(dst);
    const char* pSrc = src;
    unsigned char in[4];
    std::size_t decodedSize = 0;

    while (true)
    {
        // 末尾の = の存在は検証しない
        // '\0' 以外の想定外の文字が現れても無言でデコード終了する
        if ((in[0] = DecodeTable[pSrc[0]]) == NA)
        {
            break;
        }

        if ((in[1] = DecodeTable[pSrc[1]]) == NA)
        {
            break;
        }

        ++decodedSize;
        pDst[0] =  (in[0]         << 2) + ((in[1] & 0x30) >> 4);

        if ((in[2] = DecodeTable[pSrc[2]]) == NA)
        {
            break;
        }

        ++decodedSize;
        pDst[1] = ((in[1] & 0x0f) << 4) + ((in[2] & 0x3c) >> 2);

        if ((in[3] = DecodeTable[pSrc[3]]) == NA)
        {
            break;
        }

        ++decodedSize;
        pDst[2] = ((in[2] & 0x03) << 6) +   in[3];

        pDst += 3;
        pSrc += 4;
    }

    return decodedSize;
}

}

GS2_END_OF_NAMESPACE
