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

#ifndef GS2_CORE_NETWORK_GS2RESTSESSION_HPP_
#define GS2_CORE_NETWORK_GS2RESTSESSION_HPP_

#include "../Gs2Object.hpp"
#include "../AsyncResult.hpp"
#include "../external/optional/optional.hpp"
#include "../model/BasicGs2Credential.hpp"
#include "../util/IntrusiveList.hpp"
#include "../util/StringHolder.hpp"
#include "HttpTask.hpp"
#include <functional>
#include <mutex>

GS2_START_OF_NAMESPACE

namespace detail {
    class Gs2StandardHttpTaskBase;
}

class Gs2RestSession : public Gs2Object
{
    friend class detail::Gs2StandardHttpTaskBase;

public:
    typedef std::function<void(AsyncResult<void>&)> ConnectCallbackType;
    typedef std::function<void()> DisconnectCallbackType;

private:
    template <typename T>
    class CallbackHolder : public detail::IntrusiveListItem<CallbackHolder<T>>
    {
    private:
        T m_Callback;

    public:
        explicit CallbackHolder(T&& callback) :
            m_Callback(callback)
        {}

        ~CallbackHolder() = default;

        const T& callback() const
        {
            return m_Callback;
        }
    };

    typedef CallbackHolder<ConnectCallbackType> ConnectCallbackHolder;
    typedef CallbackHolder<DisconnectCallbackType> DisconnectCallbackHolder;

    class Gs2LoginTask : public detail::Gs2HttpTask
    {
    private:
        Gs2RestSession& m_Gs2RestSession;

    private:
        void callback(const Char responseBody[], Gs2ClientException* pClientException) GS2_OVERRIDE;

    public:
        explicit Gs2LoginTask(Gs2RestSession& gs2RestSession);
        ~Gs2LoginTask() GS2_OVERRIDE = default;
    };

private:
    const BasicGs2Credential& m_Gs2Credential;
    optional<StringHolder> m_ProjectToken;

    detail::IntrusiveList<ConnectCallbackHolder> m_ConnectCallbackHolderList;
    detail::IntrusiveList<DisconnectCallbackHolder> m_DisconnectCallbackHolderList;
    detail::IntrusiveList<detail::Gs2StandardHttpTaskBase> m_Gs2StandardHttpTaskBaseList;

    std::mutex m_Mutex;

    bool isAvailable() const
    {
        return !!m_ProjectToken;
    };

    bool isConnecting() const
    {
        return !m_ConnectCallbackHolderList.isEmpty();
    }

    bool isDisconnecting() const
    {
        return !m_DisconnectCallbackHolderList.isEmpty();
    }

    bool isUsed() const
    {
        return !m_Gs2StandardHttpTaskBaseList.isEmpty();
    }

    static void triggerConnectCallback(detail::IntrusiveList<ConnectCallbackHolder>& connectCallbackHolderList, AsyncResult<void>& result);
    static void triggerDisconnectCallback(detail::IntrusiveList<DisconnectCallbackHolder>& disconnectCallbackHolderList);

public:
    explicit Gs2RestSession(const BasicGs2Credential& gs2Credential) :
        m_Gs2Credential(gs2Credential)
    {}

    ~Gs2RestSession();

    const BasicGs2Credential& getGs2Credential() const
    {
        return m_Gs2Credential;
    }

    const optional<StringHolder>& getProjectToken() const
    {
        return m_ProjectToken;
    }

    void connect(ConnectCallbackType callback);

    void disconnect(DisconnectCallbackType callback);

private:
    void authorizeAndExecute(detail::Gs2StandardHttpTaskBase& gs2StandardHttpTaskBase);

    void notifyComplete(detail::Gs2StandardHttpTaskBase& gs2StandardHttpTaskBase);
};

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_NETWORK_GS2RESTSESSION_HPP_
