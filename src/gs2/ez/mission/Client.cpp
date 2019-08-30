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


namespace gs2 { namespace ez { namespace mission {

Client::Client(gs2::ez::Profile& profile) :
    m_Profile(profile),
    m_Client(profile.getGs2Session())
{
}

void Client::listMissionGroupModels(
    std::function<void(AsyncEzListMissionGroupModelsResult&)> callback,
    const Char* namespaceName
)
{
    gs2::mission::DescribeMissionGroupModelsRequest request;
    request.setNamespaceName(namespaceName);
    m_Client.describeMissionGroupModels(
        request,
        [callback](gs2::mission::AsyncDescribeMissionGroupModelsResult& r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListMissionGroupModelsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzListMissionGroupModelsResult::isConvertible(*r.getResult()))
            {
                EzListMissionGroupModelsResult ezResult(*r.getResult());
                AsyncEzListMissionGroupModelsResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzListMissionGroupModelsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getMissionGroupModel(
    std::function<void(AsyncEzGetMissionGroupModelResult&)> callback,
    const Char* namespaceName,
    const Char* missionGroupName
)
{
    gs2::mission::GetMissionGroupModelRequest request;
    request.setNamespaceName(namespaceName);
    request.setMissionGroupName(missionGroupName);
    m_Client.getMissionGroupModel(
        request,
        [callback](gs2::mission::AsyncGetMissionGroupModelResult& r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetMissionGroupModelResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetMissionGroupModelResult::isConvertible(*r.getResult()))
            {
                EzGetMissionGroupModelResult ezResult(*r.getResult());
                AsyncEzGetMissionGroupModelResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetMissionGroupModelResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::listCounterModels(
    std::function<void(AsyncEzListCounterModelsResult&)> callback,
    const Char* namespaceName
)
{
    gs2::mission::DescribeCounterModelsRequest request;
    request.setNamespaceName(namespaceName);
    m_Client.describeCounterModels(
        request,
        [callback](gs2::mission::AsyncDescribeCounterModelsResult& r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListCounterModelsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzListCounterModelsResult::isConvertible(*r.getResult()))
            {
                EzListCounterModelsResult ezResult(*r.getResult());
                AsyncEzListCounterModelsResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzListCounterModelsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getCounterModel(
    std::function<void(AsyncEzGetCounterModelResult&)> callback,
    const Char* namespaceName,
    const Char* counterName
)
{
    gs2::mission::GetCounterModelRequest request;
    request.setNamespaceName(namespaceName);
    request.setCounterName(counterName);
    m_Client.getCounterModel(
        request,
        [callback](gs2::mission::AsyncGetCounterModelResult& r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetCounterModelResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetCounterModelResult::isConvertible(*r.getResult()))
            {
                EzGetCounterModelResult ezResult(*r.getResult());
                AsyncEzGetCounterModelResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetCounterModelResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::listCompletes(
    std::function<void(AsyncEzListCompletesResult&)> callback,
    GameSession& session,
    const Char* namespaceName,
    const Char* pageToken,
    gs2::optional<Int64> limit
)
{
    gs2::mission::DescribeCompletesRequest request;
    request.setNamespaceName(namespaceName);
    if (pageToken)
    {
        request.setPageToken(pageToken);
    }
    if (limit)
    {
        request.setLimit(*limit);
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.describeCompletes(
        request,
        [callback](gs2::mission::AsyncDescribeCompletesResult& r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListCompletesResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzListCompletesResult::isConvertible(*r.getResult()))
            {
                EzListCompletesResult ezResult(*r.getResult());
                AsyncEzListCompletesResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzListCompletesResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getComplete(
    std::function<void(AsyncEzGetCompleteResult&)> callback,
    GameSession& session,
    const Char* namespaceName,
    const Char* missionGroupName
)
{
    gs2::mission::GetCompleteRequest request;
    request.setNamespaceName(namespaceName);
    request.setMissionGroupName(missionGroupName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.getComplete(
        request,
        [callback](gs2::mission::AsyncGetCompleteResult& r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetCompleteResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetCompleteResult::isConvertible(*r.getResult()))
            {
                EzGetCompleteResult ezResult(*r.getResult());
                AsyncEzGetCompleteResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetCompleteResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::receiveRewards(
    std::function<void(AsyncEzReceiveRewardsResult&)> callback,
    GameSession& session,
    const Char* namespaceName,
    const Char* missionGroupName,
    const Char* missionTaskName
)
{
    gs2::mission::CompleteRequest request;
    request.setNamespaceName(namespaceName);
    request.setMissionGroupName(missionGroupName);
    request.setMissionTaskName(missionTaskName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.complete(
        request,
        [callback](gs2::mission::AsyncCompleteResult& r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzReceiveRewardsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzReceiveRewardsResult::isConvertible(*r.getResult()))
            {
                EzReceiveRewardsResult ezResult(*r.getResult());
                AsyncEzReceiveRewardsResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzReceiveRewardsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::listMissionTaskModels(
    std::function<void(AsyncEzListMissionTaskModelsResult&)> callback,
    const Char* namespaceName,
    const Char* missionGroupName
)
{
    gs2::mission::DescribeMissionTaskModelsRequest request;
    request.setNamespaceName(namespaceName);
    request.setMissionGroupName(missionGroupName);
    m_Client.describeMissionTaskModels(
        request,
        [callback](gs2::mission::AsyncDescribeMissionTaskModelsResult& r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListMissionTaskModelsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzListMissionTaskModelsResult::isConvertible(*r.getResult()))
            {
                EzListMissionTaskModelsResult ezResult(*r.getResult());
                AsyncEzListMissionTaskModelsResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzListMissionTaskModelsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getMissionTaskModel(
    std::function<void(AsyncEzGetMissionTaskModelResult&)> callback,
    const Char* namespaceName,
    const Char* missionGroupName,
    const Char* missionTaskName
)
{
    gs2::mission::GetMissionTaskModelRequest request;
    request.setNamespaceName(namespaceName);
    request.setMissionGroupName(missionGroupName);
    request.setMissionTaskName(missionTaskName);
    m_Client.getMissionTaskModel(
        request,
        [callback](gs2::mission::AsyncGetMissionTaskModelResult& r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetMissionTaskModelResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetMissionTaskModelResult::isConvertible(*r.getResult()))
            {
                EzGetMissionTaskModelResult ezResult(*r.getResult());
                AsyncEzGetMissionTaskModelResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetMissionTaskModelResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

}}}