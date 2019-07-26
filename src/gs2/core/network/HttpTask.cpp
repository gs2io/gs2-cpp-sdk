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

void HttpTask::send()
{
    m_pHttpRequest->OnProcessRequestComplete().BindRaw(this, &HttpTask::callback);
    m_pHttpRequest->ProcessRequest();
    FHttpModule::Get().GetHttpManager().AddRequest(m_pHttpRequest);
}

void HttpTask::addHeaderEntry(std::vector<std::string>& headers, const Char key[], const Char value[])
{
    std::string entry(key);
    entry.append(": ");
    entry.append(value);

    headers.push_back(entry);
}


void Gs2HttpTask::callback(FHttpRequestPtr pHttpRequest, FHttpResponsePtr pHttpResponse, bool isSuccessful)
{
    GS2_NOT_USED(pHttpRequest);
    GS2_NOT_USED(isSuccessful);

    size_t responseLength = pHttpResponse->GetContentLength();
    auto responseBody = new char[responseLength + 1];
    std::memcpy(responseBody, pHttpResponse->GetContent().GetData(), responseLength);
    responseBody[responseLength] = '\0';

    Gs2RestResponse gs2RestResponse(responseBody, static_cast<Int32>(pHttpResponse->GetResponseCode()));
    callback(gs2RestResponse);

    delete[] responseBody;
}

}

GS2_END_OF_NAMESPACE
