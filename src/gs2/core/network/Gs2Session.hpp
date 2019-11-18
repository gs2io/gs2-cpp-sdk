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

#ifndef GS2_CORE_NETWORK_GS2SESSION_HPP_
#define GS2_CORE_NETWORK_GS2SESSION_HPP_

#include "../Gs2Object.hpp"
#include "../AsyncResult.hpp"
#include "../external/optional/optional.hpp"
#include "../model/BasicGs2Credential.hpp"
#include "../model/Region.hpp"
#include "../model/NotificationMessage.hpp"
#include "../util/IntrusiveList.hpp"
#include "../util/StringHolder.hpp"
#include "Gs2SessionTask.hpp"
#include "Gs2SessionTaskId.hpp"
#include <functional>
#include <mutex>

GS2_START_OF_NAMESPACE

namespace detail {
    class Gs2Response;
}

class Gs2Session : public Gs2Object
{
    friend class detail::Gs2SessionTask;

public:
    typedef AsyncResult<void> AsyncOpenResult;
    typedef std::function<void(AsyncOpenResult)> OpenCallbackType;
    typedef std::function<void()> CloseCallbackType;
    typedef std::function<void(NotificationMessage)> NotificationMessageCallbackType;

private:
    enum class State {
        Idle,
        Opening,
        CancellingOpen,
        Available,
        CancellingTasks,
        Closing,
    };

    class Lock
    {
    private:
        Gs2Session& m_Gs2Session;
        bool m_IsLockedByMe;

    public:
        Lock(Gs2Session& gs2Session, bool defer = false) :
            m_Gs2Session(gs2Session),
            m_IsLockedByMe(!defer)
        {
            if (!defer)
            {
                m_Gs2Session.m_Mutex.lock();
            }
        }

        ~Lock()
        {
            if (m_IsLockedByMe)
            {
                unlock();
            }
        }

        void lock()
        {
            m_Gs2Session.m_Mutex.lock();
            m_IsLockedByMe = true;
        }

        void unlock();
    };

    class OpenTask : public detail::Gs2Task
    {
    private:
        OpenCallbackType m_Callback;
        AsyncOpenResult m_AsyncOpenResult;

    public:
        OpenTask(OpenCallbackType&& callback) :
            m_Callback(std::move(callback))
        {}

        ~OpenTask() GS2_OVERRIDE = default;

        void triggerCallback() GS2_OVERRIDE
        {
            m_Callback(std::move(m_AsyncOpenResult));
        }

        void setResult(AsyncOpenResult asyncOpenResult)
        {
            m_AsyncOpenResult = std::move(asyncOpenResult);
        }
    };

    class CloseTask : public detail::Gs2Task
    {
    private:
        CloseCallbackType m_Callback;

    public:
        CloseTask(CloseCallbackType&& callback) :
            m_Callback(std::move(callback))
        {}

        ~CloseTask() GS2_OVERRIDE = default;

        void triggerCallback() GS2_OVERRIDE
        {
            m_Callback();
        }
    };

private:
    mutable std::mutex m_Mutex;

    State m_State;

    BasicGs2Credential m_Gs2Credential;
    Region m_Region;

    optional<StringHolder> m_ProjectToken;

    detail::IntrusiveList<OpenTask> m_OpenTaskList;
    detail::IntrusiveList<CloseTask> m_CloseTaskList;
    detail::IntrusiveList<detail::Gs2Task> m_Gs2SessionTaskList;

    detail::IntrusiveList<detail::Gs2Task> m_CompleteTaskList;

    CloseCallbackType m_OnClose;

    detail::Gs2SessionTaskId::Generator m_Gs2SessionIdTaskGenerator;

    void completeOpenTasks(AsyncOpenResult asyncOpenResult);
    void completeCloseTasks();
    void completeSessionTasks(Gs2ClientException gs2ClientException);

    detail::Gs2SessionTask* removeGs2SessionTask(const detail::Gs2SessionTaskId& gs2SessionTaskId);

    void changeStateToIdle();
    void changeStateToOpening();
    void changeStateToCancellingOpen();
    void changeStateToAvailable(StringHolder&& projectToken);
    void changeStateToCancellingTasks();
    void changeStateToClosing();

protected:
    const optional<StringHolder>& getProjectToken() const
    {
        return m_ProjectToken;
    }

    // openImpl(), cancelOpenImpl(), closeImpl() の実装から呼び出す場合は isAlreadyLocked に true を指定すること
    void openCallback(StringHolder* pProjectToken, Gs2ClientException* pClientException, bool isAlreadyLocked = false);
    void closeCallback(Gs2ClientException& gs2ClientException, bool isAlreadyLocked = false);
    void cancelTasksCallback(Gs2ClientException& gs2ClientException, bool isAlreadyLocked = false);

    void execute(detail::Gs2SessionTask& gs2SessionTask);

    // Gs2SessionTask からも利用
    void onResponse(const detail::Gs2SessionTaskId& gs2SessionTaskId, detail::Gs2Response& gs2Resoponse);

public:
    explicit Gs2Session(BasicGs2Credential gs2Credential) :
        m_State(State::Idle),
        m_Gs2Credential(gs2Credential),
        m_Region(Region::AP_NORTHEAST_1)
    {}

    Gs2Session(BasicGs2Credential gs2Credential, Region region) :
        m_State(State::Idle),
        m_Gs2Credential(gs2Credential),
        m_Region(region)
    {}

    Gs2Session(BasicGs2Credential gs2Credential, StringHolder region) :
        m_State(State::Idle),
        m_Gs2Credential(gs2Credential),
        m_Region(region)
    {}

    virtual ~Gs2Session() = default;

    const BasicGs2Credential& getGs2Credential() const
    {
        return m_Gs2Credential;
    }

    const Region& getRegion() const
    {
        return m_Region;
    }

    void open(OpenCallbackType callback);

    void close(CloseCallbackType callback);

    void setOnClose(CloseCallbackType callback);

private:
    // 以下の関数は m_Mutex のロック内から呼ばれます
    virtual void openImpl() = 0;
    virtual void cancelOpenImpl() {}
    virtual void closeImpl() = 0;
};


GS2_END_OF_NAMESPACE

#endif //GS2_CORE_NETWORK_GS2SESSION_HPP_
