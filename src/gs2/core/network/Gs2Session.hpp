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
#include "../util/IntrusiveList.hpp"
#include "../util/StringHolder.hpp"
#include <functional>
#include <mutex>

GS2_START_OF_NAMESPACE

namespace detail {
    class Gs2SessionTask;
}

class Gs2Session : public Gs2Object
{
    friend class detail::Gs2SessionTask;

public:
    typedef std::function<void(AsyncResult<void>&)> ConnectCallbackType;
    typedef std::function<void()> DisconnectCallbackType;

private:
    template <typename T>
    class CallbackHolder : public Gs2Object, public detail::IntrusiveListItem<CallbackHolder<T>>
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

private:
    const BasicGs2Credential& m_Gs2Credential;
    optional<StringHolder> m_ProjectToken;

    detail::IntrusiveList<ConnectCallbackHolder> m_ConnectCallbackHolderList;
    detail::IntrusiveList<DisconnectCallbackHolder> m_DisconnectCallbackHolderList;
    detail::IntrusiveList<detail::Gs2SessionTask> m_Gs2SessionTaskList;

    std::mutex m_Mutex;

    static void triggerConnectCallback(detail::IntrusiveList<ConnectCallbackHolder>& connectCallbackHolderList, AsyncResult<void>& result);
    static void triggerDisconnectCallback(detail::IntrusiveList<DisconnectCallbackHolder>& disconnectCallbackHolderList);

protected:
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
        return !m_Gs2SessionTaskList.isEmpty();
    }

    bool startDisconnect();
    void connectCallback(optional<StringHolder>& projectToken, Gs2ClientException* pClientException);
    void disconnectCallback(bool isDisconnectInstant);

    // Gs2SessionTask から利用
    void execute(detail::Gs2SessionTask &gs2SessionTask);
    void notifyComplete(detail::Gs2SessionTask& gs2SessionTask);

public:
    explicit Gs2Session(const BasicGs2Credential& gs2Credential) :
        m_Gs2Credential(gs2Credential)
    {}

    virtual ~Gs2Session();

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
    virtual void connectImpl() = 0;
    virtual bool disconnectImpl() = 0;  // 中で disconnectCallback() を呼んだ場合は true を返すこと
    virtual void prepareImpl(detail::Gs2SessionTask &gs2SessionTask) = 0;
};

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_NETWORK_GS2SESSION_HPP_
