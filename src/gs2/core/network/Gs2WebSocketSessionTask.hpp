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

#ifndef GS2_CORE_NETWORK_GS2WEBSOCKETSESSIONTASK_HPP_
#define GS2_CORE_NETWORK_GS2WEBSOCKETSESSIONTASK_HPP_

#include "Gs2SessionTask.hpp"
#include "Gs2WebSocketSession.hpp"
#include "Gs2Response.hpp"
#include "../AsyncResult.hpp"

GS2_START_OF_NAMESPACE

namespace detail {

class Gs2WebSocketSessionTaskBase : public Gs2SessionTask
{
private:
    void prepareImpl() GS2_OVERRIDE;
    void executeImpl() GS2_OVERRIDE;

    virtual void sendImpl(const StringHolder& clientId, const StringHolder& projectToken, const Gs2SessionTaskId& gs2SessionTaskId) = 0;

protected:
    void send(const Char message[]);

public:
    Gs2WebSocketSessionTaskBase(Gs2WebSocketSession& gs2WebSocketSession) :
        Gs2SessionTask(gs2WebSocketSession)
    {}

    ~Gs2WebSocketSessionTaskBase() GS2_OVERRIDE = default;
};

template <class T>
class Gs2WebSocketSessionTask : public Gs2WebSocketSessionTaskBase
{
public:
    typedef std::function<void(AsyncResult<T>&)> CallbackType;

private:
    CallbackType m_Callback;

    void triggerUserCallback(Gs2Response& gs2Response) GS2_OVERRIDE
    {
        T result;
        gs2Response.exportTo(result.getModel());
        AsyncResult<T> asyncResult(result, gs2Response.getGs2ClientException());
        m_Callback(asyncResult);
    }

public:
    Gs2WebSocketSessionTask(Gs2WebSocketSession& gs2WebSocketSession, CallbackType& callback) :
        Gs2WebSocketSessionTaskBase(gs2WebSocketSession),
        m_Callback(callback)
    {
    }
};


template<>
class Gs2WebSocketSessionTask<void> : public Gs2WebSocketSessionTaskBase
{
public:
    typedef std::function<void(AsyncResult<void>&)> CallbackType;

private:
    CallbackType m_Callback;

    void triggerUserCallback(Gs2Response& gs2Response) GS2_OVERRIDE
    {
        AsyncResult<void> asyncResult(gs2Response.getGs2ClientException());
        m_Callback(asyncResult);
    }

public:
    Gs2WebSocketSessionTask(Gs2WebSocketSession& gs2WebSocketSession, CallbackType& callback) :
        Gs2WebSocketSessionTaskBase(gs2WebSocketSession),
        m_Callback(callback)
    {
    }
};

}

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_NETWORK_GS2WEBSOCKETSESSIONTASK_HPP_
