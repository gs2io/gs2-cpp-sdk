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

#include "Gs2SessionTask.hpp"
#include "Gs2Session.hpp"

GS2_START_OF_NAMESPACE

namespace detail {

void Gs2SessionTask::callback(const Char responseBody[], Gs2ClientException* pGs2ClientException)
{
    triggerUserCallback(responseBody, pGs2ClientException);
    m_Gs2Session.notifyComplete(*this);
    delete this;
}

void Gs2SessionTask::execute()
{
    m_Gs2Session.execute(*this);
}

}

GS2_END_OF_NAMESPACE
