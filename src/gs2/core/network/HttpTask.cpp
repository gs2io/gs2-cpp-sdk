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
#include "../model/ErrorResponse.hpp"
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

void HttpTask::callbackHandler(::cocos2d::network::HttpClient *pClient, ::cocos2d::network::HttpResponse *pResponse)
{
    HttpTask* pHttpTask = reinterpret_cast<HttpTask*>(pResponse->getHttpRequest()->getUserData());
    pHttpTask->callback(pClient, pResponse);
}

void HttpTask::send()
{
    m_HttpRequest.setUserData(this);
    m_HttpRequest.setResponseCallback(callbackHandler);

    ::cocos2d::network::HttpClient::getInstance()->send(&m_HttpRequest);
}

void HttpTask::addHeaderEntry(std::vector<std::string>& headers, const Char key[], const Char value[])
{
    std::string entry(key);
    entry.append(": ");
    entry.append(value);

    headers.push_back(entry);
}


void Gs2HttpTask::callback(::cocos2d::network::HttpClient *pClient, ::cocos2d::network::HttpResponse *pResponse)
{
    auto responseCode = pResponse->getResponseCode();
    CCLOG("Response code: %i", responseCode);

    const char* responseBody = "";
    {
        auto pResponseData = pResponse->getResponseData();
        if (pResponseData != nullptr)
        {
            pResponseData->push_back('\0');
            responseBody = pResponseData->data();
        }
    }
    CCLOG("Response body: %s", responseBody);

    Gs2ClientException gs2ClientException;
    Gs2ClientException* pGs2ClientException = nullptr;

    // [NOTE] iOS では応答が 200 以外でも isSucceed() が true になる模様 (@Cocos2d-x v3.16)
    if (pResponse->isSucceed() && responseCode == 200)
    {
    }
    else
    {
        Gs2ClientException::Type type;
        switch(responseCode) {
            case -1: type = Gs2ClientException::UnreachableException; break;
            case 400: type = Gs2ClientException::BadRequestException; break;
            case 401: type = Gs2ClientException::UnauthorizedException; break;
            case 402: type = Gs2ClientException::QuotaExceedException; break;
            case 404: type = Gs2ClientException::NotFoundException; break;
            case 409: type = Gs2ClientException::ConflictException; break;
            case 500: type = Gs2ClientException::InternalServerErrorException; break;
            case 502: type = Gs2ClientException::BadGatewayException; break;
            case 503: type = Gs2ClientException::ServiceUnavailableException; break;
            case 504: type = Gs2ClientException::RequestTimeoutException; break;
            default: type = Gs2ClientException::UnknownException; break;
        }
        gs2ClientException.setType(type);

        detail::ErrorResponse errorResponse;
        detail::json::JsonParser::parse(&errorResponse.getModel(), responseBody);
        if (errorResponse.getMessage())
        {
            detail::json::JsonParser::parse(&gs2ClientException.getModel(), *errorResponse.getMessage());
        }

        pGs2ClientException = &gs2ClientException;
    }

    callback(responseBody, pGs2ClientException);
}

}

GS2_END_OF_NAMESPACE
