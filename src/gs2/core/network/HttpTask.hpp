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

#ifndef GS2_CORE_NETWORK_HTTPTASK_HPP_
#define GS2_CORE_NETWORK_HTTPTASK_HPP_

#include "../Gs2Object.hpp"
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

class Gs2RestResponse;

class HttpTask : public Gs2Object
{
public:
    enum class Verb
    {
        Get,
        Post,
        Delete,
        Put,
    };

private:
    ::cocos2d::network::HttpRequest &m_HttpRequest;
    std::vector<std::string> m_Headers;

    static void callbackHandler(::cocos2d::network::HttpClient *pClient, ::cocos2d::network::HttpResponse *pResponse);
    virtual void callback(::cocos2d::network::HttpClient *pClient, ::cocos2d::network::HttpResponse *pResponse) = 0;

public:
    HttpTask();
    virtual ~HttpTask();

    void setUrl(const char url[]);
    void setVerb(Verb verb);
    void addHeaderEntry(const char key[], const char value[]);
    void setBody(const char body[]);

    // 最大1回までしか呼べません
    void send();
};


class Gs2HttpTask : public HttpTask
{
private:
    void callback(::cocos2d::network::HttpClient *pClient, ::cocos2d::network::HttpResponse *pResponse) GS2_OVERRIDE;
    virtual void callback(Gs2RestResponse& gs2RestResponse) = 0;

public:
    Gs2HttpTask() = default;
    ~Gs2HttpTask() GS2_OVERRIDE = default;
};

}

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_NETWORK_HTTPTASK_HPP_
