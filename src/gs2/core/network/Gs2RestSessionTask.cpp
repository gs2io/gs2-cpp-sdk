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
#include "Gs2RestSession.hpp"

GS2_START_OF_NAMESPACE

namespace detail {

void Gs2RestSessionTaskBase::Gs2RestTask::callback(Gs2RestResponse& gs2RestResponse)
{
    m_Gs2StandardHttpTaskBase.onResponse(*m_Gs2StandardHttpTaskBase.m_pGs2RestSession, gs2RestResponse);
}

void Gs2RestSessionTaskBase::prepareImpl(Gs2Session& gs2Session, const StringHolder& projectToken)
{
    m_pGs2RestSession = static_cast<Gs2RestSession*>(&gs2Session);

    StringVariable url(Gs2RestSession::EndpointHost);
    url.replace("{service}", getServiceName());
    url.replace("{region}", gs2Session.getRegion().getName());

    auto verb = constructRequestImpl(url, m_Gs2RestTask);

    m_Gs2RestTask.setVerb(verb);
    m_Gs2RestTask.setUrl(url.c_str());

    m_Gs2RestTask.addHeaderEntry("X-GS2-CLIENT-ID", gs2Session.getGs2Credential().getClientId());
    m_Gs2RestTask.addHeaderEntry("Authorization", projectToken);
}

void Gs2RestSessionTaskBase::executeImpl(Gs2Session& gs2Session)
{
    m_Gs2RestTask.send();
}

}

GS2_END_OF_NAMESPACE
