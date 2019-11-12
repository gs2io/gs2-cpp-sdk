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

#include "StampSheetStateMachine.hpp"

namespace gs2 { namespace ez {

StampSheetStateMachine::StampSheetStateMachine(
    StringHolder stampSheetString,
    Client& client,
    StringHolder distributorNamespaceName,
    StringHolder stampSheetEncryptKeyId,
    EzStampSheetCallback ezStampSheetCallback,
    EzStampTaskCallback ezStampTaskCallback
) :
    m_EzStampSheet(std::move(stampSheetString)),
    m_Client(client),
    m_DistributorNamespaceName(std::move(distributorNamespaceName)),
    m_StampSheetEncryptKeyId(std::move(stampSheetEncryptKeyId)),
    m_EzStampSheetCallback(std::move(ezStampSheetCallback)),
    m_EzStampTaskCallback(std::move(ezStampTaskCallback)),
    m_State(State::Idle),
    m_Step(0),
    m_StackContext("")
{
}

StampSheetStateMachine::StampSheetStateMachine(
    EzStampSheet ezStampSheet,
    Client& client,
    StringHolder distributorNamespaceName,
    StringHolder stampSheetEncryptKeyId,
    EzStampSheetCallback ezStampSheetCallback,
    EzStampTaskCallback ezStampTaskCallback
) :
    m_EzStampSheet(std::move(ezStampSheet)),
    m_Client(client),
    m_DistributorNamespaceName(std::move(distributorNamespaceName)),
    m_StampSheetEncryptKeyId(std::move(stampSheetEncryptKeyId)),
    m_EzStampSheetCallback(std::move(ezStampSheetCallback)),
    m_EzStampTaskCallback(std::move(ezStampTaskCallback)),
    m_State(State::Idle),
    m_Step(0),
    m_StackContext("")
{
}

void StampSheetStateMachine::executeStep(Int32 step)
{
    auto& ezStampTasks = m_EzStampSheet.getEzStampTasks();
    auto ezStampTaskCount = ezStampTasks.getCount();

    if (step < ezStampTaskCount)
    {
        auto ezStampTask = ezStampTasks[step];
        ezStampTask.execute(
            [this, step](distributor::AsyncEzRunStampTaskResult asyncEzRunStampTaskResult)
            {
                std::unique_lock<std::mutex> lock(m_Mutex);

                if (asyncEzRunStampTaskResult.getError())
                {
                    m_State = State::Idle;

                    lock.unlock();

                    if (m_EzStampTaskCallback)
                    {
                        m_EzStampTaskCallback(m_EzStampSheet.getEzStampTasks()[step], asyncEzRunStampTaskResult);
                    }

                    if (m_EzStampSheetCallback)
                    {
                        distributor::AsyncEzRunStampSheetResult asyncEzRunStampSheetResult(*asyncEzRunStampTaskResult.getError());
                        m_EzStampSheetCallback(m_EzStampSheet, asyncEzRunStampSheetResult);
                    }
                }
                else
                {
                    auto nextStep = ++m_Step;
                    m_StackContext = asyncEzRunStampTaskResult.getResult()->getContextStack();

                    lock.unlock();

                    if (m_EzStampTaskCallback)
                    {
                        m_EzStampTaskCallback(m_EzStampSheet.getEzStampTasks()[step], asyncEzRunStampTaskResult);
                    }

                    executeStep(nextStep);
                }
            },
            m_StackContext,
            m_Client,
            m_DistributorNamespaceName,
            m_StampSheetEncryptKeyId
        );
    }
    else if (step == ezStampTaskCount)
    {
        auto ezStampSheet = m_EzStampSheet;
        ezStampSheet.execute(
            [this](distributor::AsyncEzRunStampSheetResult asyncEzRunStampSheetResult)
            {
                {
                    std::lock_guard<std::mutex> lock(m_Mutex);

                    if (!asyncEzRunStampSheetResult.getError())
                    {
                        m_AsyncEzRunStampSheetResult = asyncEzRunStampSheetResult;
                        ++m_Step;
                    }

                    m_State = State::Idle;
                }

                if (m_EzStampSheetCallback)
                {
                    m_EzStampSheetCallback(m_EzStampSheet, asyncEzRunStampSheetResult);
                }
            },
            m_StackContext,
            m_Client,
            m_DistributorNamespaceName,
            m_StampSheetEncryptKeyId
        );
    }
    else
    {
        {
            std::lock_guard<std::mutex> lock(m_Mutex);

            m_State = State::Idle;
        }

        if (m_EzStampSheetCallback)
        {
            // これ以上ステート遷移しないので、ロックを取らずに結果にアクセスしてよい
            m_EzStampSheetCallback(m_EzStampSheet, m_AsyncEzRunStampSheetResult);
        }
    }
}

void StampSheetStateMachine::execute()
{
    std::unique_lock<std::mutex> lock(m_Mutex);

    switch (m_State)
    {
    case State::Idle:
        {
            m_State = State::Running;
            auto step = m_Step;

            lock.unlock();

            executeStep(step);
        }
        break;

    case State::Running:
        // do nothing
        break;
    }
}

}}
