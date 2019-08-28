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
                auto gs2ClientException = *r.getError();
                AsyncEzListTriggersResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzListTriggersResult::isConvertible(*r.getResult()))
            {
                EzListTriggersResult ezResult(*r.getResult());
                AsyncEzListTriggersResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzListTriggersResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
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
                auto gs2ClientException = *r.getError();
                AsyncEzGetTriggerResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetTriggerResult::isConvertible(*r.getResult()))
            {
                EzGetTriggerResult ezResult(*r.getResult());
                AsyncEzGetTriggerResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetTriggerResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
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
                auto gs2ClientException = *r.getError();
                AsyncEzListEventsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzListEventsResult::isConvertible(*r.getResult()))
            {
                EzListEventsResult ezResult(*r.getResult());
                AsyncEzListEventsResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzListEventsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
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
                auto gs2ClientException = *r.getError();
                AsyncEzGetEventResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetEventResult::isConvertible(*r.getResult()))
            {
                EzGetEventResult ezResult(*r.getResult());
                AsyncEzGetEventResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetEventResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

}}}