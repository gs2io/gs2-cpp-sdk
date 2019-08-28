/*
 * Copyright 2016 Game Server Services, Inc. or its affiliates. All Rights
 * Reserved.
 *
 * Licensed under the Apache License, Version 2.0(the "License").
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

#include "Client.hpp"
#include "../Profile.hpp"
#include "../GameSession.hpp"


namespace gs2 { namespace ez { namespace schedule {

Client::Client(gs2::ez::Profile& profile) :
    m_Profile(profile),
    m_Client(profile.getGs2Session())
{
}

void Client::ListTriggers(
    std::function<void(AsyncEzListTriggersResult&)> callback,
    GameSession& session,
    const Char* namespaceName
)
{
    gs2::schedule::DescribeTriggersRequest request;
    request.setNamespaceName(namespaceName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.describeTriggers(
        request,
        [callback](gs2::schedule::AsyncDescribeTriggersResult& r)
        {
            if (r.getError())
            {
                EzListTriggersResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzListTriggersResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzListTriggersResult::isConvertible(*r.getResult()))
                {
                    EzListTriggersResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzListTriggersResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzListTriggersResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzListTriggersResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

void Client::GetTrigger(
    std::function<void(AsyncEzGetTriggerResult&)> callback,
    GameSession& session,
    const Char* namespaceName,
    const Char* triggerName
)
{
    gs2::schedule::GetTriggerRequest request;
    request.setNamespaceName(namespaceName);
    request.setTriggerName(triggerName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.getTrigger(
        request,
        [callback](gs2::schedule::AsyncGetTriggerResult& r)
        {
            if (r.getError())
            {
                EzGetTriggerResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzGetTriggerResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzGetTriggerResult::isConvertible(*r.getResult()))
                {
                    EzGetTriggerResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzGetTriggerResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzGetTriggerResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzGetTriggerResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

void Client::ListEvents(
    std::function<void(AsyncEzListEventsResult&)> callback,
    GameSession& session,
    const Char* namespaceName
)
{
    gs2::schedule::DescribeEventsRequest request;
    request.setNamespaceName(namespaceName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.describeEvents(
        request,
        [callback](gs2::schedule::AsyncDescribeEventsResult& r)
        {
            if (r.getError())
            {
                EzListEventsResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzListEventsResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzListEventsResult::isConvertible(*r.getResult()))
                {
                    EzListEventsResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzListEventsResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzListEventsResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzListEventsResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

void Client::GetEvent(
    std::function<void(AsyncEzGetEventResult&)> callback,
    GameSession& session,
    const Char* namespaceName,
    const Char* eventName
)
{
    gs2::schedule::GetEventRequest request;
    request.setNamespaceName(namespaceName);
    request.setEventName(eventName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.getEvent(
        request,
        [callback](gs2::schedule::AsyncGetEventResult& r)
        {
            if (r.getError())
            {
                EzGetEventResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzGetEventResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzGetEventResult::isConvertible(*r.getResult()))
                {
                    EzGetEventResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzGetEventResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzGetEventResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzGetEventResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

}}}