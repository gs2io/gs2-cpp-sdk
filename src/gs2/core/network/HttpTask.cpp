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
#include <HttpModule.h>
#include <HttpManager.h>
#include <vector>

GS2_START_OF_NAMESPACE

namespace detail {

HttpTask::HttpTask() :
    m_pHttpRequest(FHttpModule::Get().CreateRequest()) 
{
}

HttpTask::~HttpTask()
{
}

void HttpTask::setUrl(const char url[])
{
    m_pHttpRequest->SetURL(url);
}

void HttpTask::setVerb(Verb verb)
{
    const char* verbString = "invalid";
    switch (verb)
    {
    case Verb::Get:
        verbString = "GET";
        break;
    case Verb::Post:
        verbString = "POST";
        break;
    case Verb::Delete:
        verbString = "DELETE";
        break;
    case Verb::Put:
        verbString = "PUT";
        break;
    }
    m_pHttpRequest->SetVerb(verbString);
}

void HttpTask::addHeaderEntry(const char key[], const char value[])
{
    m_pHttpRequest->SetHeader(key, value);
}

void HttpTask::setBody(const char body[])
{
    TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
    m_pHttpRequest->SetContent(content);
}

void HttpTask::send()
{
    m_pHttpRequest->OnProcessRequestComplete().BindRaw(this, &HttpTask::callback);
    m_pHttpRequest->ProcessRequest();
    FHttpModule::Get().GetHttpManager().AddRequest(m_pHttpRequest);
}


void Gs2HttpTask::callback(FHttpRequestPtr pHttpRequest, FHttpResponsePtr pHttpResponse, bool isSuccessful)
{
    GS2_NOT_USED(pHttpRequest);
    GS2_NOT_USED(isSuccessful);

    if (pHttpResponse.IsValid())
    {
        size_t responseLength = pHttpResponse->GetContentLength();
        auto responseBody = new char[responseLength + 1];
        std::memcpy(responseBody, pHttpResponse->GetContent().GetData(), responseLength);
        responseBody[responseLength] = '\0';

        Gs2RestResponse gs2RestResponse(responseBody, static_cast<Int32>(pHttpResponse->GetResponseCode()));
        callback(gs2RestResponse);

        delete[] responseBody;
    }
    else
    {
        Gs2RestResponse gs2RestResponse("Client system error.", 0);     // TODO
        callback(gs2RestResponse);
    }
}

}

GS2_END_OF_NAMESPACE
