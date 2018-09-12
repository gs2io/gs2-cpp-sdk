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

#include "BasicGs2Credential.hpp"
#include "../network/HttpRequest.hpp"
#include "../control/Gs2BasicRequest.hpp"
#include "../util/StringVariable.hpp"
#include "../util/SignUtil.hpp"
#include "../util/Base64.hpp"
#include <chrono>

GS2_START_OF_NAMESPACE

/**
 * コンストラクタ。
 *
 * @param clientId クライアントID
 * @param clientSecret クライアントシークレット
 */
BasicGs2Credential::BasicGs2Credential(const Char clientId[], const Char clientSecret[])
: m_ClientId(clientId),
  m_ClientSecret(clientSecret)
{
//    if(clientId == null || clientSecret == null) {
//        throw new IllegalArgumentException("invalid credential");
//    }
}

/**
 * クライアントIDを取得。
 *
 * @return クライアントID
 */
const StringHolder& BasicGs2Credential::getClientId() const
{
    return m_ClientId;
}

/**
 * クライアントシークレットを取得。
 *
 * @return クライアントシークレット
 */
const StringHolder& BasicGs2Credential::getClientSecret() const
{
    return m_ClientSecret;
}

void BasicGs2Credential::authorize(detail::HttpRequestBase& httpRequest, const Gs2BasicRequest& basicRequest) const
{
    auto timestamp = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    char timestampString[21];
    std::sprintf(timestampString, "%ld", timestamp);

    auto decodedClientSecret = Gs2Object::getAllocator().malloc(detail::getBase64DecodedLengthMax(m_ClientSecret.getSize() - 1));
    auto decodedSize = detail::decodeBase64(decodedClientSecret, m_ClientSecret);

    detail::StringVariable body(basicRequest.getModuleName());
    body.append(":");
    body.append(basicRequest.getFunctionName());
    body.append(":");
    body.append(timestampString);

    detail::SignUtil::HmacSha256 hmac;
    detail::SignUtil::sign(hmac, decodedClientSecret, decodedSize, body.c_str(), body.size());
    Gs2Object::getAllocator().free(decodedClientSecret);

    char base64EncodedSignature[detail::getBase64EncodedLength(sizeof(hmac.data)) + 1];
    detail::encodeBase64(base64EncodedSignature, hmac.data, sizeof(hmac.data));

    httpRequest.addHeader("X-GS2-CLIENT-ID", getClientId());
    httpRequest.addHeader("X-GS2-REQUEST-TIMESTAMP", timestampString);
    httpRequest.addHeader("X-GS2-REQUEST-SIGN", base64EncodedSignature);
}

GS2_END_OF_NAMESPACE
