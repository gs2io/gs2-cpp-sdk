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

#ifndef GS2_CORE_NETWORK_GS2RESTSESSIONTASK_HPP_
#define GS2_CORE_NETWORK_GS2RESTSESSIONTASK_HPP_

#include "Gs2SessionTask.hpp"
#include "HttpTask.hpp"
#include "Gs2Response.hpp"
#include "../AsyncResult.hpp"

GS2_START_OF_NAMESPACE

class Gs2RestSession;

namespace detail {

class Gs2RestSessionTaskBase : public Gs2SessionTask
{
private:
    class Gs2RestTask : public Gs2HttpTask
    {
    private:
        Gs2RestSessionTaskBase& m_Gs2StandardHttpTaskBase;

        void callback(Gs2RestResponse& gs2RestResponse) GS2_OVERRIDE;

    public:
        Gs2RestTask(Gs2RestSessionTaskBase& gs2StandardHttpTaskBase) :
            m_Gs2StandardHttpTaskBase(gs2StandardHttpTaskBase)
        {}

        ~Gs2RestTask() GS2_OVERRIDE = default;
    };

private:
    Gs2RestTask m_Gs2RestTask;
    Gs2RestSession* m_pGs2RestSession;

    void prepareImpl(Gs2Session& gs2Session, const StringHolder& projectToken) GS2_OVERRIDE;
    void executeImpl(Gs2Session& gs2Session) GS2_OVERRIDE;

    virtual const char* getServiceName() const = 0;
    virtual Gs2HttpTask::Verb constructRequestImpl(StringVariable& url, Gs2HttpTask& gs2HttpTask) = 0;

public:
    explicit Gs2RestSessionTaskBase() :
        m_Gs2RestTask(*this),
        m_pGs2RestSession(nullptr)
    {}

    ~Gs2RestSessionTaskBase() GS2_OVERRIDE = default;
};

template <class T>
class Gs2RestSessionTask : public Gs2RestSessionTaskBase
{
public:
    typedef std::function<void(AsyncResult<T>)> CallbackType;

private:
    CallbackType m_Callback;
    AsyncResult<T> m_AsyncResult;

public:
    Gs2RestSessionTask(CallbackType callback) :
        m_Callback(std::move(callback))
    {
    }

    void triggerCallback() GS2_OVERRIDE
    {
        m_Callback(std::move(m_AsyncResult));
    }

    void setResult(Gs2Response& gs2Response) GS2_OVERRIDE
    {
        T result;
        gs2Response.exportTo(result.getModel());
        m_AsyncResult = AsyncResult<T>(std::move(result), std::move(gs2Response.getGs2ClientException()));
    }

    void setResult(Gs2ClientException gs2ClientException) GS2_OVERRIDE
    {
        m_AsyncResult = AsyncResult<T>(std::move(gs2ClientException));
    }
};


template<>
class Gs2RestSessionTask<void> : public Gs2RestSessionTaskBase
{
public:
    typedef std::function<void(AsyncResult<void>)> CallbackType;

private:
    CallbackType m_Callback;
    AsyncResult<void> m_AsyncResult;

public:
    Gs2RestSessionTask(CallbackType callback) :
        m_Callback(std::move(callback))
    {
    }

    void triggerCallback() GS2_OVERRIDE
    {
        m_Callback(std::move(m_AsyncResult));
    }

    void setResult(Gs2Response& gs2Response) GS2_OVERRIDE
    {
        m_AsyncResult = AsyncResult<void>(std::move(gs2Response.getGs2ClientException()));
    }

    void setResult(Gs2ClientException gs2ClientException) GS2_OVERRIDE
    {
        m_AsyncResult = AsyncResult<void>(std::move(gs2ClientException));
    }
};

}

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_NETWORK_GS2RESTSESSIONTASK_HPP_
