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
#include <Http.h>

GS2_START_OF_NAMESPACE

namespace detail {

class Gs2RestResponse;

class HttpTask : public Gs2Object
{
private:
    TSharedRef<IHttpRequest> m_pHttpRequest;

    virtual void callback(FHttpRequestPtr pHttpRequest, FHttpResponsePtr pHttpResponse, bool isSuccessful) = 0;

public:
    HttpTask();
    virtual ~HttpTask();

    // 最大1回までしか呼べません
    void send();

    // ユーザデータは設定しても send 時に上書きされます
    IHttpRequest& getHttpRequest()
    {
        return *m_pHttpRequest;
    }

    // ユーティリティ
    static void addHeaderEntry(std::vector<std::string>& headers, const Char key[], const Char value[]);
};


class Gs2HttpTask : public HttpTask
{
private:
    void callback(FHttpRequestPtr pHttpRequest, FHttpResponsePtr pHttpResponse, bool isSuccessful) GS2_OVERRIDE;
    virtual void callback(Gs2RestResponse& gs2RestResponse) = 0;

public:
    Gs2HttpTask() = default;
    ~Gs2HttpTask() GS2_OVERRIDE = default;
};

}

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_NETWORK_HTTPTASK_HPP_
