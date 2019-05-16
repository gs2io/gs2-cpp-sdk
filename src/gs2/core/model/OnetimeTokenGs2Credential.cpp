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

#include "OnetimeTokenGs2Credential.hpp"
#include "../network/HttpRequest.hpp"
#include "../control/Gs2BasicRequest.hpp"
#include <chrono>

GS2_START_OF_NAMESPACE

/**
 * コンストラクタ。
 *
 * @param token ワンタイムトークン
 */
OnetimeTokenGs2Credential::OnetimeTokenGs2Credential(const Char token[])
: m_Token(token)
{
//    if(clientId == null || clientSecret == null) {
//        throw new IllegalArgumentException("invalid credential");
//    }
}

void OnetimeTokenGs2Credential::authorize(std::vector<std::string>& headerEntries, const Gs2BasicRequest& basicRequest) const
{
    auto timestamp = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    char timestampString[21];
    std::sprintf(timestampString, "%ld", timestamp);

    detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-TIMESTAMP", timestampString);
    detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ONETIME-TOKEN", m_Token);
}

GS2_END_OF_NAMESPACE
