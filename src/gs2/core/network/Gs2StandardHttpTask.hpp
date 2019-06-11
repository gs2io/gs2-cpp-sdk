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

#include "HttpTask.hpp"
#include "../util/IntrusiveList.hpp"

GS2_START_OF_NAMESPACE

class Gs2RestSession;

namespace detail {

class Gs2StandardHttpTaskBase : public Gs2HttpTask, public IntrusiveListItem<Gs2StandardHttpTaskBase>
{
private:
    Gs2RestSession& m_Gs2RestSession;

private:
    void callback(const Char responseBody[], Gs2ClientException* pGs2ClientException) GS2_OVERRIDE;
    virtual void callbackGs2Response(const Char responseBody[], Gs2ClientException* pGs2ClientException) = 0;

public:
    Gs2StandardHttpTaskBase(Gs2RestSession& gs2RestSession) :
        m_Gs2RestSession(gs2RestSession)
    {}

    ~Gs2StandardHttpTaskBase() GS2_OVERRIDE = default;

    void sendBySession();
};

template <class T>
class Gs2StandardHttpTask : public Gs2StandardHttpTaskBase
{
public:
    typedef std::function<void(AsyncResult<T>&)> CallbackType;

private:
    CallbackType m_Callback;

    void callbackGs2Response(const Char responseBody[], Gs2ClientException* pGs2ClientException) GS2_OVERRIDE
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

    void callbackGs2Response(const Char responseBody[], Gs2ClientException* pGs2ClientException) GS2_OVERRIDE
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
