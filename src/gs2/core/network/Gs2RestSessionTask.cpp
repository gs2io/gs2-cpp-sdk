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

#include "Gs2RestSessionTask.hpp"

GS2_START_OF_NAMESPACE

namespace detail {

void Gs2RestSessionTaskBase::prepareImpl()
{
    auto headers = getGs2HttpTask().getHttpRequest().getHeaders();

    detail::HttpTask::addHeaderEntry(headers, "X-GS2-CLIENT-ID", getGs2Session().getGs2Credential().getClientId());
    detail::HttpTask::addHeaderEntry(headers, "X-GS2-PROJECT-TOKEN", *getGs2Session().getProjectToken());

    getGs2HttpTask().getHttpRequest().setHeaders(headers);
}

void Gs2RestSessionTaskBase::executeImpl()
{
    m_Gs2RestTask.send();
}

}

GS2_END_OF_NAMESPACE
