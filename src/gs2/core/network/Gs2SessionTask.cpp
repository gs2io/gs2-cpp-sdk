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

void Gs2SessionTask::onResponse(Gs2Session& gs2Session, Gs2Response& gs2Response)
{
    gs2Session.onResponse(m_Gs2SessionTaskId, gs2Response);
}

void Gs2SessionTask::prepare(Gs2Session& gs2Session, Gs2SessionTaskId gs2SessionTaskId)
{
    m_Gs2SessionTaskId = gs2SessionTaskId;
    prepareImpl(gs2Session, *gs2Session.getProjectToken());
}

void Gs2SessionTask::execute(Gs2Session& gs2Session)
{
    executeImpl(gs2Session);
}

}

GS2_END_OF_NAMESPACE
