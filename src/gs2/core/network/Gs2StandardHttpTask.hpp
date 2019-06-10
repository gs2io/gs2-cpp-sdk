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
    friend class gs2::Gs2RestSession;

private:
    void callbackGs2Response(const Char responseBody[], Gs2ClientException* pClientException) GS2_OVERRIDE = 0;

public:
    Gs2StandardHttpTaskBase() = default;
    ~Gs2StandardHttpTaskBase() GS2_OVERRIDE = default;
};

template <class T>
class Gs2StandardHttpTask : public Gs2StandardHttpTaskBase
{
public:
    typedef std::function<void(AsyncResult<T>&)> CallbackType;

private:
    CallbackType m_Callback;

    void callbackGs2Response(const Char responseBody[], Gs2ClientException* pClientException) GS2_OVERRIDE
    {
        T result;
        if (responseBody != nullptr && pClientException == nullptr)
        {
            json::JsonParser::parse(&result.getModel(), responseBody);
        }
        AsyncResult<T> asyncResult(&result, pClientException);
        m_Callback(asyncResult);
    }

public:
    explicit Gs2StandardHttpTask(CallbackType& callback) :
        Gs2StandardHttpTaskBase(),
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

    void callbackGs2Response(const Char responseBody[], Gs2ClientException* pClientException) GS2_OVERRIDE
    {
        AsyncResult<void> asyncResult(pClientException);
        m_Callback(asyncResult);
    }

public:
    explicit Gs2StandardHttpTask(CallbackType& callback) :
        Gs2StandardHttpTaskBase(),
        m_Callback(callback)
    {
    }
};

}

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_NETWORK_GS2STANDARDHTTPTASK_HPP_
