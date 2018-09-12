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

#include "SignUtil.hpp"
#include "../Gs2Object.hpp"
#include "../external/cryptopp/hmac.h"
#include "../external/cryptopp/sha.h"
#include "../external/cryptopp/filters.h"

GS2_START_OF_NAMESPACE

namespace {

// new を置き換えるための自前サブクラス
class HashFilter : public detail::CryptoPP::HashFilter, public Gs2Object
{
public:
    HashFilter(detail::CryptoPP::HashTransformation &hm, detail::CryptoPP::BufferedTransformation *attachment = NULLPTR) :
            detail::CryptoPP::HashFilter(hm, attachment)
    {}
};

// new を置き換えるための自前サブクラス
class ArraySink : public detail::CryptoPP::ArraySink, public Gs2Object
{
public:
    ArraySink(detail::CryptoPP::byte *buf, size_t size) :
            detail::CryptoPP::ArraySink(buf, size)
    {}
};

}

namespace detail {

void SignUtil::sign(HmacSha256& hmac, const void *rawClientSecret, std::size_t rawClientSecretSize, const void* body, size_t bodySize)
{
    detail::CryptoPP::HMAC<detail::CryptoPP::SHA256> algorithm(reinterpret_cast<const detail::CryptoPP::byte*>(rawClientSecret), rawClientSecretSize);
    detail::CryptoPP::StringSource(reinterpret_cast<const detail::CryptoPP::byte*>(body), bodySize, true, new HashFilter(algorithm, new ArraySink(hmac.data, sizeof(hmac.data))));
}

}

GS2_END_OF_NAMESPACE
