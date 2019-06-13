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

#ifndef GS2_CORE_NETWORK_GS2STANDARDHTTPTASK_HPP_
#define GS2_CORE_NETWORK_GS2STANDARDHTTPTASK_HPP_

#include "Gs2SessionTask.hpp"
#include "Gs2RestSession.hpp"
#include "HttpTask.hpp"

GS2_START_OF_NAMESPACE

namespace detail {

class Gs2StandardHttpTaskBase : public Gs2SessionTask
{
private:
    class Gs2RestTask : public Gs2HttpTask
    {
    private:
        Gs2StandardHttpTaskBase& m_Gs2StandardHttpTaskBase;
        void callback(const Char responseBody[], Gs2ClientException* pGs2ClientException) GS2_OVERRIDE
        {
            m_Gs2StandardHttpTaskBase.callback(responseBody, pGs2ClientException);
        }

    public:
        Gs2RestTask(Gs2StandardHttpTaskBase& gs2StandardHttpTaskBase) :
            m_Gs2StandardHttpTaskBase(gs2StandardHttpTaskBase)
        {}

        ~Gs2RestTask() GS2_OVERRIDE = default;
    };

private:
    Gs2RestTask m_Gs2RestTask;

    void executeImpl() GS2_OVERRIDE;

public:
    explicit Gs2StandardHttpTaskBase(Gs2RestSession& gs2RestSession) :
        Gs2SessionTask(gs2RestSession),
        m_Gs2RestTask(*this)
    {}

    ~Gs2StandardHttpTaskBase() GS2_OVERRIDE = default;

    Gs2HttpTask& getGs2HttpTask()
    {
        return m_Gs2RestTask;
    }
};

template <class T>
class Gs2StandardHttpTask : public Gs2StandardHttpTaskBase
{
public:
    typedef std::function<void(AsyncResult<T>&)> CallbackType;

private:
    CallbackType m_Callback;

    void triggerUserCallback(const Char responseBody[], Gs2ClientException* pGs2ClientException) GS2_OVERRIDE
    {
        T result;
        if (responseBody != nullptr && pGs2ClientException == nullptr)
        {
            json::JsonParser::parse(&result.getModel(), responseBody);
        }
        AsyncResult<T> asyncResult(&result, pGs2ClientException);
        m_Callback(asyncResult);
    }

public:
    explicit Gs2StandardHttpTask(Gs2RestSession& gs2RestSession, CallbackType& callback) :
        Gs2StandardHttpTaskBase(gs2RestSession),
        m_Callback(callback)
    {
    }
};


template<>
class Gs2StandardHttpTask<void> : public Gs2StandardHttpTaskBase
{
public:
    typedef std::function<void(AsyncResult<void>&)> CallbackType;

private:
    CallbackType m_Callback;

    void triggerUserCallback(const Char responseBody[], Gs2ClientException* pGs2ClientException) GS2_OVERRIDE
    {
        AsyncResult<void> asyncResult(pGs2ClientException);
        m_Callback(asyncResult);
    }

public:
    explicit Gs2StandardHttpTask(Gs2RestSession& gs2RestSession, CallbackType& callback) :
        Gs2StandardHttpTaskBase(gs2RestSession),
        m_Callback(callback)
    {
    }
};

}

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_NETWORK_GS2STANDARDHTTPTASK_HPP_
