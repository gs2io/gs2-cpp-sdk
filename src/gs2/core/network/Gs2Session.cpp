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

Gs2Session::~Gs2Session()
{
}

void Gs2Session::triggerOpenCallback(detail::IntrusiveList<OpenCallbackHolder>& openCallbackHolderList, AsyncResult<void>& result)
{
    while (auto* pOpenCallbackHolder = openCallbackHolderList.pop())
    {
        pOpenCallbackHolder->callback()(result);
        delete pOpenCallbackHolder;
    }
}

void Gs2Session::triggerCloseCallback(detail::IntrusiveList<CloseCallbackHolder>& closeCallbackHolderList)
{
    while (auto* pCloseCallbackHolder = closeCallbackHolderList.pop())
    {
        pCloseCallbackHolder->callback()();
        delete pCloseCallbackHolder;
    }
}

void Gs2Session::triggerCancelTasksCallback(detail::IntrusiveList<detail::Gs2SessionTask>& gs2SessionTaskList, Gs2ClientException& gs2ClientException)
{
    detail::Gs2ClientErrorResponse clientErrorResponse;
    clientErrorResponse.getGs2ClientException() = gs2ClientException;   // TODO: move?

    while (auto* pGs2SessionTask = gs2SessionTaskList.pop())
    {
        pGs2SessionTask->triggerUserCallback(clientErrorResponse);  // notifyComplete() は不要なのでユーザコールバックのみ呼ぶ
        delete pGs2SessionTask;
    }
}

void Gs2Session::changeStateToIdle()
{
    // 外部要因による切断がありうるので、どの状態からでも遷移しうる

    assert(m_OpenCallbackHolderList.isEmpty());     // すべてコールバックされ（るために取り出され）ているべき
    assert(m_CloseCallbackHolderList.isEmpty());    // すべてコールバックされ（るために取り出され）ているべき
    assert(m_Gs2SessionTaskList.isEmpty());         // Available になる前に登録はできない

    m_State = State::Idle;

    exitStateLock();
}

void Gs2Session::changeStateToOpening()
{
    assert(m_State == State::Idle || m_State == State::Closing);

    assert(!m_OpenCallbackHolderList.isEmpty());    // open() タスクが登録されているときのみ遷移する
    assert(m_CloseCallbackHolderList.isEmpty());    // すべてコールバックされ（るために取り出され）ているべき
    assert(m_Gs2SessionTaskList.isEmpty());         // Available になる前に登録はできない

    m_State = State::Opening;

    auto isOpenInstant = openImpl();

    if (isOpenInstant)
    {
        // Idle か Available に遷移しているはずだけど、ロックから出てしまっているので検証はしない
    }
    else
    {
        exitStateLock();
    }
}

void Gs2Session::changeStateToCancellingOpen()
{
    assert(m_State == State::Opening);

    assert(!m_OpenCallbackHolderList.isEmpty());    // Opening は open() タスクが必ず存在する
    assert(!m_CloseCallbackHolderList.isEmpty());   // 接続処理中の close() によってのみ遷移する
    assert(m_Gs2SessionTaskList.isEmpty());         // Available になる前に登録はできない

    m_State = State::CancellingOpen;

    cancelOpenImpl();

    exitStateLock();
}

void Gs2Session::changeStateToAvailable(StringHolder&& projectToken)
{
    assert(m_State == State::Opening);

    assert(m_OpenCallbackHolderList.isEmpty());     // すべてコールバックされ（るために取り出され）ているべき
    assert(m_CloseCallbackHolderList.isEmpty());    // close() が呼ばれている場合は Closing に遷移しなければならない
    assert(m_Gs2SessionTaskList.isEmpty());         // Available になる前に登録はできない

    m_ProjectToken = std::move(projectToken);

    m_State = State::Available;

    exitStateLock();
}

void Gs2Session::changeStateToCancellingTasks()
{
    assert(m_State == State::Available);

    assert(m_OpenCallbackHolderList.isEmpty());     // Available のあいだの open() は即時返却される
    // 外部要因による切断の場合に close() を呼ばなくても遷移することがある
    assert(!m_Gs2SessionTaskList.isEmpty());        // キャンセルしたいタスクがあるから遷移するのである

    m_State = State::CancellingTasks;

    exitStateLock();
}

void Gs2Session::changeStateToClosing()
{
    assert(m_State == State::Opening || m_State == State::CancellingOpen || m_State == State::Available || m_State == State::CancellingTasks);

    // CancellingTasks のあいだには次の open() が積まれることがある
    // 外部要因による切断の場合に close() を呼ばなくても遷移することがある
    assert(m_Gs2SessionTaskList.isEmpty());         // タスクがなくなったときに遷移する

    m_ProjectToken.reset();

    m_State = State::Closing;

    bool isCloseInstant = closeImpl();

    if (isCloseInstant)
    {
        // Idle か Opening に遷移しているはずだけど、ロックから出てしまっているので検証はしない
    }
    else
    {
        exitStateLock();
    }
}

void Gs2Session::keepCurrentState()
{
    exitStateLock();
}

void Gs2Session::open(OpenCallbackType callback)
{
    enterStateLock();

    switch (m_State)
    {
    case State::Idle:
        m_OpenCallbackHolderList.push(*new OpenCallbackHolder(std::move(callback)));
        changeStateToOpening();
        break;

    case State::Opening:
    case State::CancellingOpen:
    case State::CancellingTasks:    // 切断処理が終わってから実行される
    case State::Closing:            // 切断処理が終わってから実行される
        m_OpenCallbackHolderList.push(*new OpenCallbackHolder(std::move(callback)));
        keepCurrentState();
        break;

    case State::Available:
        keepCurrentState();
        AsyncResult<void> result;
        callback(result);
        break;
    }
}

void Gs2Session::openCallback(StringHolder* pProjectToken, Gs2ClientException* pClientException, bool isOpenInstant)
{
    // 接続完了コールバック

    if (!isOpenInstant)
    {
        enterStateLock();
    }

    if (pClientException == nullptr)
    {
        // ログイン処理がエラーなく応答された場合

        if (pProjectToken != nullptr)
        {
            detail::IntrusiveList<OpenCallbackHolder> openCallbackHolderList(std::move(m_OpenCallbackHolderList));

            if (m_CloseCallbackHolderList.isEmpty())
            {
                changeStateToAvailable(std::move(*pProjectToken));
            }
            else
            {
                changeStateToClosing();
            }

            AsyncResult<void> result;
            Gs2Session::triggerOpenCallback(openCallbackHolderList, result);
        }
        else
        {
            // 応答からプロジェクトトークンが取得できなかった場合
            // ただし、ここには来ないように派生クラスを実装しなければならない

            detail::IntrusiveList<OpenCallbackHolder> openCallbackHolderList(std::move(m_OpenCallbackHolderList));
            detail::IntrusiveList<CloseCallbackHolder> closeCallbackHolderList(std::move(m_CloseCallbackHolderList));

            changeStateToIdle();

            Gs2ClientException gs2ClientException;
            gs2ClientException.setType(Gs2ClientException::UnknownException);   // TODO

            AsyncResult<void> result(gs2ClientException);
            Gs2Session::triggerOpenCallback(openCallbackHolderList, result);
            Gs2Session::triggerCloseCallback(closeCallbackHolderList);
        }
    }
    else
    {
        // ログイン処理がエラーになった場合

        detail::IntrusiveList<OpenCallbackHolder> openCallbackHolderList(std::move(m_OpenCallbackHolderList));
        detail::IntrusiveList<CloseCallbackHolder> closeCallbackHolderList(std::move(m_CloseCallbackHolderList));

        changeStateToIdle();

        AsyncResult<void> result(*pClientException);
        Gs2Session::triggerOpenCallback(openCallbackHolderList, result);
        Gs2Session::triggerCloseCallback(closeCallbackHolderList);
    }
}

void Gs2Session::close(CloseCallbackType callback)
{
    enterStateLock();

    if (m_State == State::Idle)
    {
        // 即コールバック
        keepCurrentState();

        callback();
    }
    else
    {
        m_CloseCallbackHolderList.push(*new CloseCallbackHolder(std::move(callback)));

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
            keepCurrentState();
            break;
        }
    }
}

void Gs2Session::setOnClose(CloseCallbackType callback)
{
    std::lock_guard<std::mutex> lock(m_Mutex);

    m_OnClose = callback;
}

void Gs2Session::closeCallback(Gs2ClientException& gs2ClientException, bool isCloseInstant)
{
    if (!isCloseInstant)
    {
        enterStateLock();
    }

    auto onClose = m_OnClose;
    detail::IntrusiveList<detail::Gs2SessionTask> gs2SessionTaskList(std::move(m_Gs2SessionTaskList));
    detail::IntrusiveList<CloseCallbackHolder> closeCallbackHolderList(std::move(m_CloseCallbackHolderList));

    if (m_OpenCallbackHolderList.isEmpty())
    {
        changeStateToIdle();
    }
    else
    {
        changeStateToOpening();
    }

    Gs2Session::triggerCancelTasksCallback(gs2SessionTaskList, gs2ClientException);

    if (onClose)
    {
        onClose();
    }
    Gs2Session::triggerCloseCallback(closeCallbackHolderList);
}

void Gs2Session::cancelTasksCallback(Gs2ClientException& gs2ClientException)
{
    enterStateLock();

    auto gs2SessionTaskList = std::move(m_Gs2SessionTaskList);

    keepCurrentState();

    triggerCancelTasksCallback(gs2SessionTaskList, gs2ClientException);
}

void Gs2Session::execute(detail::Gs2SessionTask &gs2SessionTask)
{
    enterStateLock();

    if (m_State == State::Available)
    {
        gs2SessionTask.m_Gs2SessionTaskId = m_Gs2SessionIdTaskGenerator.issue();

        gs2SessionTask.prepareImpl();

        m_Gs2SessionTaskList.push(gs2SessionTask);

        keepCurrentState();

        gs2SessionTask.executeImpl();
    }
    else
    {
        keepCurrentState();

        detail::Gs2ClientErrorResponse gs2ClientErrorResponse;
        auto& gs2ClientException = gs2ClientErrorResponse.getGs2ClientException();
        gs2ClientException.emplace();
        gs2ClientException->setType(Gs2ClientException::SessionNotOpenException);
        gs2SessionTask.callback(gs2ClientErrorResponse);
    }
}

void Gs2Session::notifyComplete(detail::Gs2SessionTask& gs2SessionTask)
{
    enterStateLock();

    m_Gs2SessionTaskList.remove(gs2SessionTask);

    if (m_State == State::CancellingTasks && m_Gs2SessionTaskList.isEmpty())
    {
        changeStateToClosing();
    }
    else
    {
        keepCurrentState();
    }
}

detail::Gs2SessionTask* Gs2Session::findGs2SessionTask(const detail::Gs2SessionTaskId& gs2SessionTaskId)
{
    std::lock_guard<std::mutex> lock(m_Mutex);

    for (auto p = m_Gs2SessionTaskList.getHead(); p != nullptr; p = p->getNext())
    {
        if (p->m_Gs2SessionTaskId == gs2SessionTaskId)
        {
            return p;
        }
    }

    return nullptr;
}

GS2_END_OF_NAMESPACE
