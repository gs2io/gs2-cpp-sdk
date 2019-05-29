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

#ifndef GS2_CORE_NETWORK_GS2LOGINTASK_HPP_
#define GS2_CORE_NETWORK_GS2LOGINTASK_HPP_

#include "HttpTask.hpp"
#include "Gs2StandardHttpTask.hpp"

GS2_START_OF_NAMESPACE

class BasicGs2Credential;

namespace detail {

class Gs2LoginTask : public Gs2HttpTask
{
    friend class gs2::BasicGs2Credential;

private:
    BasicGs2Credential& m_BasicGs2Credential;
    Gs2StandardHttpTaskBase* m_pGs2StandardHttpTaskHead;

    Gs2StandardHttpTaskBase* popGs2HttpStandardHttpTask()
    {
        auto* pGs2StandardHttpTask = m_pGs2StandardHttpTaskHead;
        if (pGs2StandardHttpTask != nullptr)
        {
            m_pGs2StandardHttpTaskHead = pGs2StandardHttpTask->m_pNext;
            pGs2StandardHttpTask->m_pNext = nullptr;
        }
        return pGs2StandardHttpTask;
    }

    void pushGs2HttpStandardHttpTask(Gs2StandardHttpTaskBase& gs2StandardHttpTask)
    {
        gs2StandardHttpTask.m_pNext = m_pGs2StandardHttpTaskHead;
        m_pGs2StandardHttpTaskHead = &gs2StandardHttpTask;
    }

    void callbackGs2Response(const Char responseBody[], Gs2ClientException* pClientException) GS2_OVERRIDE;

public:
    explicit Gs2LoginTask(BasicGs2Credential& basicGs2Credential);
    ~Gs2LoginTask() GS2_OVERRIDE;
};

}

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_NETWORK_GS2LOGINTASK_HPP_
