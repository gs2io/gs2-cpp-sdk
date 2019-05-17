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

#include "Gs2LoginTask.hpp"
#include "../model/BasicGs2Credential.hpp"

GS2_START_OF_NAMESPACE

namespace detail {

Gs2LoginTask::Gs2LoginTask(BasicGs2Credential& basicGs2Credential) :
    Gs2HttpTask(),
    m_BasicGs2Credential(basicGs2Credential),
    m_pGs2StandardHttpTaskHead(nullptr)
{

}

Gs2LoginTask::~Gs2LoginTask()
{
    Gs2ClientException gs2ClientException;
    gs2ClientException.setType(Gs2ClientException::UnknownException);
    while (auto* pGs2StandardHttpTaskHead = popGs2HttpStandardHttpTask())
    {
        pGs2StandardHttpTaskHead->callbackGs2Response("", &gs2ClientException);
    }
}

void Gs2LoginTask::callbackGs2Response(const Char responseBody[], Gs2ClientException* pClientException)
{
    std::lock_guard<std::mutex> lock(m_BasicGs2Credential.m_Mutex);

    if (pClientException == nullptr)
    {
        // TODO: m_BasicGs2Credential.m_ProjectToken = hogehoge;

        while (auto* pGs2StandardHttpTask = popGs2HttpStandardHttpTask())
        {
            m_BasicGs2Credential.authorizeAndExecute(*pGs2StandardHttpTask);
        }
    }
    else
    {
        while (auto* pGs2StandardHttpTaskHead = popGs2HttpStandardHttpTask())
        {
            pGs2StandardHttpTaskHead->callbackGs2Response(responseBody, pClientException);
        }
    }

    m_BasicGs2Credential.m_pGs2LoginTask = nullptr;
}

}

GS2_END_OF_NAMESPACE
