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
#include <string>
#include <vector>
#include <network/HttpRequest.h>

namespace cocos2d { namespace network {
    class HttpClient;
    class HttpRequest;
    class HttpResponse;
}}

GS2_START_OF_NAMESPACE

namespace detail {

// HTTP リクエストを実行して、コールバック呼出後に自殺する
class HttpTask : public Gs2Object
{
private:
    ::cocos2d::network::HttpRequest &m_HttpRequest;

    static void callbackHandler(::cocos2d::network::HttpClient *pClient, ::cocos2d::network::HttpResponse *pResponse);
    virtual void callback(::cocos2d::network::HttpClient *pClient, ::cocos2d::network::HttpResponse *pResponse) = 0;

public:
    HttpTask();
    virtual ~HttpTask();

    // 最大1回までしか呼べません
    void send();

    // ユーザデータは設定しても send 時に上書きされます
    ::cocos2d::network::HttpRequest &getHttpRequest()
    {
        return m_HttpRequest;
    }

    // ユーティリティ
    static void addHeaderEntry(std::vector<std::string>& headers, const Char key[], const Char value[]);
};


class Gs2HttpTaskBase : public HttpTask
{
private:
    virtual void callback(::cocos2d::network::HttpClient *pClient, ::cocos2d::network::HttpResponse *pResponse);
    virtual void invokeUserCallback(const Char responseBody[], Gs2ClientException* pClientException) const = 0;

public:
    Gs2HttpTaskBase() = default;
    ~Gs2HttpTaskBase() = default;
};


template <class T>
class Gs2HttpTask : public Gs2HttpTaskBase
{
public:
    typedef std::function<void(AsyncResult<T>&)> CallbackType;

private:
    CallbackType m_Callback;

    virtual void invokeUserCallback(const Char responseBody[], Gs2ClientException* pClientException) const
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
    Gs2HttpTask() :
        Gs2HttpTaskBase(),
        m_Callback(nullptr)
    {
    }

    void setCallback(CallbackType callback)
    {
        this->m_Callback = callback;
    }
};


template<>
class Gs2HttpTask<void> : public Gs2HttpTaskBase
{
public:
    typedef std::function<void(AsyncResult<void>&)> CallbackType;

private:
    CallbackType m_Callback;

    virtual void invokeUserCallback(const Char responseBody[], Gs2ClientException* pClientException) const
    {
        AsyncResult<void> asyncResult(pClientException);
        m_Callback(asyncResult);
    }

public:
    Gs2HttpTask() :
        Gs2HttpTaskBase(),
        m_Callback(nullptr)
    {
    }

    void setCallback(CallbackType callback)
    {
        this->m_Callback = callback;
    }
};

}

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_NETWORK_HTTPREQUEST_HPP_
