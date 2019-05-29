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
#include "../network/Gs2LoginTask.hpp"
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
    m_ClientSecret(clientSecret),
    m_pGs2LoginTask(nullptr)
{
}

BasicGs2Credential::~BasicGs2Credential()
{
    if (m_pGs2LoginTask)
    {
        delete m_pGs2LoginTask;
    }
}

/**
 * プロジェクトトークンを取得。
 *
 * @return プロジェクトトークン
 */
optional<StringHolder> BasicGs2Credential::getProjectToken() const
{
    std::lock_guard<std::mutex> lock(m_Mutex);

    return m_ProjectToken;
}

void BasicGs2Credential::authorizeAndExecuteImpl(detail::Gs2StandardHttpTaskBase& gs2StandardHttpTaskBase)
{
    assert(!m_Mutex.try_lock());

    if (m_ProjectToken)
    {
        auto headers = gs2StandardHttpTaskBase.getHttpRequest().getHeaders();

        detail::HttpTask::addHeaderEntry(headers, "X-GS2-CLIENT-ID", getClientId());
        detail::HttpTask::addHeaderEntry(headers, "X-GS2-PROJECT-TOKEN", *m_ProjectToken);

        gs2StandardHttpTaskBase.getHttpRequest().setHeaders(headers);
        gs2StandardHttpTaskBase.send();
    }
    else
    {
        if (m_pGs2LoginTask == nullptr)
        {
            m_pGs2LoginTask = new detail::Gs2LoginTask(*this);
            m_pGs2LoginTask->pushGs2HttpStandardHttpTask(gs2StandardHttpTaskBase);
            m_pGs2LoginTask->send();
        }
        else
        {
            m_pGs2LoginTask->pushGs2HttpStandardHttpTask(gs2StandardHttpTaskBase);
        }
    }
}

void BasicGs2Credential::authorizeAndExecute(detail::Gs2StandardHttpTaskBase& gs2StandardHttpTaskBase)
{
    std::lock_guard<std::mutex> lock(m_Mutex);
    authorizeAndExecuteImpl(gs2StandardHttpTaskBase);
}

GS2_END_OF_NAMESPACE
