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

#ifndef GS2_CORE_NETWORK_HTTPREQUEST_HPP_
#define GS2_CORE_NETWORK_HTTPREQUEST_HPP_

#include "../Gs2Object.hpp"
#include "../AsyncResult.hpp"
#include <network/HttpRequest.h>
#include <vector>
#include <string>

GS2_START_OF_NAMESPACE

namespace detail {

class HttpRequestBase : public ::cocos2d::network::HttpRequest, public Gs2Object
{
private:
    std::vector<std::string> m_Headers;

    // cocos2d::network::HttpRequest::setHeaders() の呼び出しを防止
    void setHeaders() {}

protected:
    // cocos2d::network::HttpRequest::Ref::release() によって破棄する
    ~HttpRequestBase() = default;

public:
    HttpRequestBase() = default;

    void addHeader(const Char entry[])
    {
        m_Headers.push_back(entry);
    }

    void addHeader(const Char key[], const Char value[])
    {
        std::string entry(key);
        entry.append(": ");
        entry.append(value);

        m_Headers.push_back(entry);
    }

    void applyHeader()
    {
        cocos2d::network::HttpRequest::setHeaders(m_Headers);
    }

    virtual void invokeCallback(const Char response[], Gs2ClientException* exception) const = 0;
};

template <class T>
class HttpRequest : public HttpRequestBase
{
public:
    typedef std::function<void(AsyncResult<T>&)> CallbackType;

private:
    CallbackType m_Callback;

    ~HttpRequest()
    {
        //CCLOG("HttpRequest destructed.");
    }

public:
    HttpRequest()
            : HttpRequestBase(),
              m_Callback(nullptr)
    {
        //CCLOG("HttpRequest constructed.");
    }

    void setCallback(CallbackType callback)
    {
        this->m_Callback = callback;
    }

    virtual void invokeCallback(const Char responseBody[], Gs2ClientException* pClientException) const
    {
        T result;
        if (responseBody != nullptr && pClientException == nullptr)
        {
            json::JsonParser::parse(&result.getModel(), responseBody);
        }
        AsyncResult<T> asyncResult(&result, pClientException);
        m_Callback(asyncResult);
    }
};

template<>
class HttpRequest<void> : public HttpRequestBase
{
public:
    typedef std::function<void(AsyncResult<void>&)> CallbackType;

private:
    CallbackType m_Callback;

    ~HttpRequest()
    {
        //CCLOG("HttpRequest destructed.");
    }

public:
    HttpRequest()
            : HttpRequestBase(),
              m_Callback(nullptr)
    {
        //CCLOG("HttpRequest constructed.");
    }

    void setCallback(CallbackType callback)
    {
        this->m_Callback = callback;
    }

    virtual void invokeCallback(const Char responseBody[], Gs2ClientException* pClientException) const
    {
        AsyncResult<void> asyncResult(pClientException);
        m_Callback(asyncResult);
    }
};

}

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_NETWORK_HTTPREQUEST_HPP_
