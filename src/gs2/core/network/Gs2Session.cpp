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

#include "Gs2Session.hpp"
#include "Gs2SessionTask.hpp"
#include "../json/JsonWriter.hpp"
#include "../json/JsonParser.hpp"
#include "Gs2Response.hpp"

GS2_START_OF_NAMESPACE

void Gs2Session::Lock::unlock()
{
    auto completeTaskList = std::move(m_Gs2Session.m_CompleteTaskList);

    m_Gs2Session.m_Mutex.unlock();
    m_IsLockedByMe = false;

    while (auto* pCompleteTask = completeTaskList.dequeue())
    {
        pCompleteTask->triggerCallback();
        delete pCompleteTask;
    }
}

void Gs2Session::completeOpenTasks(AsyncOpenResult asyncOpenResult)
{
    while (auto* pOpenTask = m_OpenTaskList.dequeue())
    {
        pOpenTask->setResult(asyncOpenResult);
        m_CompleteTaskList.enqueue(*pOpenTask);
    }
}

void Gs2Session::completeCloseTasks()
{
    while (auto* pCloseTask = m_CloseTaskList.dequeue())
    {
        m_CompleteTaskList.enqueue(*pCloseTask);
    }
}

void Gs2Session::completeSessionTasks(Gs2ClientException gs2ClientException)
{
    while (auto* pGs2SessionTask = static_cast<detail::Gs2SessionTask*>(m_Gs2SessionTaskList.dequeue()))
    {
        pGs2SessionTask->setResult(gs2ClientException);
        m_CompleteTaskList.enqueue(*pGs2SessionTask);
    }
}

detail::Gs2SessionTask* Gs2Session::removeGs2SessionTask(const detail::Gs2SessionTaskId& gs2SessionTaskId)
{
    for (auto* p = m_Gs2SessionTaskList.getHead(); p != nullptr; p = p->getNext())
    {
        auto* pGs2SessionTask = static_cast<detail::Gs2SessionTask*>(p);
        if (pGs2SessionTask->m_Gs2SessionTaskId == gs2SessionTaskId)
        {
            m_Gs2SessionTaskList.remove(*p);
            return pGs2SessionTask;
        }
    }

    return nullptr;
}

void Gs2Session::changeStateToIdle()
{
    // 外部要因による切断がありうるので、どの状態からでも遷移しうる

    assert(m_OpenTaskList.isEmpty());     // すべてコールバックされ（るために取り出され）ているべき
    assert(m_CloseTaskList.isEmpty());    // すべてコールバックされ（るために取り出され）ているべき
    assert(m_Gs2SessionTaskList.isEmpty());         // Available になる前に登録はできない

    m_State = State::Idle;
}

void Gs2Session::changeStateToOpening()
{
    assert(m_State == State::Idle || m_State == State::Closing);

    assert(!m_OpenTaskList.isEmpty());    // open() タスクが登録されているときのみ遷移する
    assert(m_CloseTaskList.isEmpty());    // すべてコールバックされ（るために取り出され）ているべき
    assert(m_Gs2SessionTaskList.isEmpty());         // Available になる前に登録はできない

    m_State = State::Opening;

    openImpl();
}

void Gs2Session::changeStateToCancellingOpen()
{
    assert(m_State == State::Opening);

    assert(!m_OpenTaskList.isEmpty());    // Opening は open() タスクが必ず存在する
    assert(!m_CloseTaskList.isEmpty());   // 接続処理中の close() によってのみ遷移する
    assert(m_Gs2SessionTaskList.isEmpty());         // Available になる前に登録はできない

    m_State = State::CancellingOpen;

    cancelOpenImpl();
}

void Gs2Session::changeStateToAvailable(StringHolder&& projectToken)
{
    assert(m_State == State::Opening);

    assert(m_OpenTaskList.isEmpty());     // すべてコールバックされ（るために取り出され）ているべき
    assert(m_CloseTaskList.isEmpty());    // close() が呼ばれている場合は Closing に遷移しなければならない
    assert(m_Gs2SessionTaskList.isEmpty());         // Available になる前に登録はできない

    m_ProjectToken = std::move(projectToken);

    m_State = State::Available;
}

void Gs2Session::changeStateToCancellingTasks()
{
    assert(m_State == State::Available);

    assert(m_OpenTaskList.isEmpty());     // Available のあいだの open() は即時返却される
    // 外部要因による切断の場合に close() を呼ばなくても遷移することがある
    assert(!m_Gs2SessionTaskList.isEmpty());        // キャンセルしたいタスクがあるから遷移するのである

    m_State = State::CancellingTasks;
}

void Gs2Session::changeStateToClosing()
{
    assert(m_State == State::Opening || m_State == State::CancellingOpen || m_State == State::Available || m_State == State::CancellingTasks);

    // CancellingTasks のあいだには次の open() が積まれることがある
    // 外部要因による切断の場合に close() を呼ばなくても遷移することがある
    assert(m_Gs2SessionTaskList.isEmpty());         // タスクがなくなったときに遷移する

    m_ProjectToken.reset();

    m_State = State::Closing;

    closeImpl();
}

void Gs2Session::open(OpenCallbackType callback)
{
    Lock lock(*this);

    switch (m_State)
    {
    case State::Idle:
        m_OpenTaskList.enqueue(*new OpenTask(std::move(callback)));
        changeStateToOpening();
        break;

    case State::Opening:
    case State::CancellingOpen:
    case State::CancellingTasks:    // 切断処理が終わってから実行される
    case State::Closing:            // 切断処理が終わってから実行される
        m_OpenTaskList.enqueue(*new OpenTask(std::move(callback)));
        break;

    case State::Available:
        lock.unlock();
        AsyncResult<void> result;
        callback(result);
        break;
    }
}

void Gs2Session::openCallback(StringHolder* pProjectToken, Gs2ClientException* pClientException, bool isAlreadyLocked)
{
    // 接続完了コールバック

    Lock lock(*this, isAlreadyLocked);

    if (pClientException == nullptr)
    {
        // ログイン処理がエラーなく応答された場合

        if (pProjectToken != nullptr)
        {
            completeOpenTasks(AsyncOpenResult());

            if (m_CloseTaskList.isEmpty())
            {
                changeStateToAvailable(std::move(*pProjectToken));
            }
            else
            {
                changeStateToClosing();
            }
        }
        else
        {
            // 応答からプロジェクトトークンが取得できなかった場合
            // ただし、ここには来ないように派生クラスを実装しなければならない

            Gs2ClientException gs2ClientException;
            gs2ClientException.setType(Gs2ClientException::UnknownException);   // TODO

            Gs2Session::completeOpenTasks(AsyncOpenResult(std::move(gs2ClientException)));
            Gs2Session::completeCloseTasks();

            changeStateToIdle();
        }
    }
    else
    {
        // ログイン処理がエラーになった場合

        Gs2Session::completeOpenTasks(AsyncOpenResult(*pClientException));
        Gs2Session::completeCloseTasks();

        changeStateToIdle();
    }
}

void Gs2Session::close(CloseCallbackType callback)
{
    Lock lock(*this);

    if (m_State == State::Idle)
    {
        // 即コールバック
        lock.unlock();

        callback();
    }
    else
    {
        m_CloseTaskList.enqueue(*new CloseTask(std::move(callback)));

        switch(m_State)
        {
        case State::Opening:
            changeStateToCancellingOpen();
            break;

        case State::Available:
            if (m_Gs2SessionTaskList.isEmpty())
            {
                changeStateToClosing();
            }
            else
            {
                changeStateToCancellingTasks();
            }
            break;

        case State::Idle:   // ここには来ない
        case State::CancellingOpen:
        case State::CancellingTasks:
        case State::Closing:
            break;
        }
    }
}

void Gs2Session::setOnClose(CloseCallbackType callback)
{
    Lock lock(*this);

    m_OnClose = callback;
}

void Gs2Session::closeCallback(Gs2ClientException& gs2ClientException, bool isAlreadyLocked)
{
    Lock lock(*this, isAlreadyLocked);

    completeSessionTasks(gs2ClientException);
    completeCloseTasks();

    if (m_OnClose)
    {
        auto onClose = m_OnClose;
        m_CompleteTaskList.enqueue(*new CloseTask(std::move(onClose)));
    }

    if (m_OpenTaskList.isEmpty())
    {
        changeStateToIdle();
    }
    else
    {
        changeStateToOpening();
    }
}

void Gs2Session::cancelTasksCallback(Gs2ClientException& gs2ClientException, bool isAlreadyLocked)
{
    Lock lock(*this, isAlreadyLocked);

    completeSessionTasks(gs2ClientException);
}

void Gs2Session::execute(detail::Gs2SessionTask &gs2SessionTask)
{
    Lock lock(*this);

    if (m_State == State::Available)
    {
        gs2SessionTask.m_Gs2SessionTaskId = m_Gs2SessionIdTaskGenerator.issue();

        gs2SessionTask.prepareImpl();

        m_Gs2SessionTaskList.enqueue(gs2SessionTask);

        lock.unlock();

        gs2SessionTask.executeImpl();
    }
    else
    {
        lock.unlock();

        Gs2ClientException gs2ClientException;
        gs2ClientException.setType(Gs2ClientException::SessionNotOpenException);
        gs2SessionTask.setResult(std::move(gs2ClientException));
        gs2SessionTask.triggerCallback();
    }
}

void Gs2Session::onResponse(const detail::Gs2SessionTaskId& gs2SessionTaskId, detail::Gs2Response& gs2Response)
{
    Lock lock(*this);

    auto* pGs2SessionTask = removeGs2SessionTask(gs2SessionTaskId);
    if (pGs2SessionTask != nullptr)
    {
        // API 応答
        pGs2SessionTask->setResult(gs2Response);
        m_CompleteTaskList.enqueue(*pGs2SessionTask);

        if (m_State == State::CancellingTasks && m_Gs2SessionTaskList.isEmpty())
        {
            changeStateToClosing();
        }
    }
    else
    {
        // このようなメッセージは届かないはず
    }
}

GS2_END_OF_NAMESPACE
