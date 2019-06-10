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
#include "../network/Gs2StandardHttpTask.hpp"
#include "../control/Gs2BasicRequest.hpp"
#include "../util/StringVariable.hpp"
#include "../util/Base64.hpp"
#include <chrono>

GS2_START_OF_NAMESPACE

/**
 * コンストラクタ。
 *
 * @param clientId クライアントID
 * @param clientSecret クライアントシークレット
 */
BasicGs2Credential::BasicGs2Credential(const Char clientId[], const Char clientSecret[]) :
    IGs2Credential(),
    m_ClientId(clientId), 
    m_ClientSecret(clientSecret)
{
}

GS2_END_OF_NAMESPACE
