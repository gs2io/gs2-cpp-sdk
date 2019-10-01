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

#include "HttpTask.hpp"
#include "../exception/Gs2ClientException.hpp"
#include "../json/JsonParser.hpp"
#include "../model/IGs2Credential.hpp"
#include "../network/Gs2RestResponse.hpp"
#include <network/HttpClient.h>
#include <network/HttpRequest.h>
#include <network/HttpResponse.h>
#include <vector>

GS2_START_OF_NAMESPACE

namespace detail {

HttpTask::HttpTask() :
    m_HttpRequest(*new ::cocos2d::network::HttpRequest())
{
}

HttpTask::~HttpTask()
{
    m_HttpRequest.release();
}

void HttpTask::setUrl(const char url[])
{
    std::string urlString = url;
    m_HttpRequest.setUrl(urlString);
}

void HttpTask::setVerb(Verb verb)
{
    auto httpRequestType = ::cocos2d::network::HttpRequest::Type::UNKNOWN;
    switch (verb)
    {
        case Verb::Get:
            httpRequestType = ::cocos2d::network::HttpRequest::Type::GET;
            break;
        case Verb::Post:
            httpRequestType = ::cocos2d::network::HttpRequest::Type::POST;
            break;
        case Verb::Delete:
            httpRequestType = ::cocos2d::network::HttpRequest::Type::DELETE;
            break;
        case Verb::Put:
            httpRequestType = ::cocos2d::network::HttpRequest::Type::PUT;
            break;
    }
    m_HttpRequest.setRequestType(httpRequestType);
}

void HttpTask::addHeaderEntry(const char key[], const char value[])
{
    std::string header = key;
    header.append(": ");
    header.append(value);
    m_Headers.push_back(header);
}

void HttpTask::setBody(const char body[])
{
    m_HttpRequest.setRequestData(body, std::strlen(body));
}

void HttpTask::callbackHandler(::cocos2d::network::HttpClient *pClient, ::cocos2d::network::HttpResponse *pResponse)
{
    HttpTask* pHttpTask = reinterpret_cast<HttpTask*>(pResponse->getHttpRequest()->getUserData());
    pHttpTask->callback(pClient, pResponse);
}

void HttpTask::send()
{
    m_HttpRequest.setHeaders(m_Headers);
    m_HttpRequest.setUserData(this);
    m_HttpRequest.setResponseCallback(callbackHandler);

    ::cocos2d::network::HttpClient::getInstance()->send(&m_HttpRequest);
}


void Gs2HttpTask::callback(::cocos2d::network::HttpClient *pClient, ::cocos2d::network::HttpResponse *pResponse)
{
    const char* responseBody = "";
    {
        auto pResponseData = pResponse->getResponseData();
        if (pResponseData != nullptr)
        {
            pResponseData->push_back('\0');
            responseBody = pResponseData->data();
        }
    }

    Gs2RestResponse gs2RestResponse(responseBody, static_cast<Int32>(pResponse->getResponseCode()));
    callback(gs2RestResponse);
}

}

GS2_END_OF_NAMESPACE
