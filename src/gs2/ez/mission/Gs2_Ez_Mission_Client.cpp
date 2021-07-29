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
#include <gs2/mission/Gs2MissionWebSocketClient.hpp>
#include <gs2/mission/Gs2MissionRestClient.hpp>


namespace gs2 { namespace ez { namespace mission {

Client::Client(gs2::ez::Profile& profile) :
    m_Profile(profile),
    m_pWebSocketClient(new gs2::mission::Gs2MissionWebSocketClient(profile.getGs2WebSocketSession())),
    m_pRestClient(new gs2::mission::Gs2MissionRestClient(profile.getGs2RestSession()))
{
}

Client::~Client()
{
    delete m_pWebSocketClient;
    delete m_pRestClient;
}

void Client::listCounterModels(
    std::function<void(AsyncEzListCounterModelsResult)> callback,
    StringHolder namespaceName
)
{
    gs2::mission::DescribeCounterModelsRequest request;
    request.setNamespaceName(namespaceName);
    m_pRestClient->describeCounterModels(
        request,
        [callback](gs2::mission::AsyncDescribeCounterModelsResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListCounterModelsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
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
    std::function<void(AsyncEzGetCounterModelResult)> callback,
    StringHolder namespaceName,
    StringHolder counterName
)
{
    gs2::mission::GetCounterModelRequest request;
    request.setNamespaceName(namespaceName);
    request.setCounterName(counterName);
    m_pWebSocketClient->getCounterModel(
        request,
        [callback](gs2::mission::AsyncGetCounterModelResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetCounterModelResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
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

void Client::listCounters(
    std::function<void(AsyncEzListCountersResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    gs2::optional<StringHolder> pageToken,
    gs2::optional<Int64> limit
)
{
    gs2::mission::DescribeCountersRequest request;
    request.setNamespaceName(namespaceName);
    if (pageToken)
    {
        request.setPageToken(std::move(*pageToken));
    }
    if (limit)
    {
        request.setLimit(std::move(*limit));
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pRestClient->describeCounters(
        request,
        [callback](gs2::mission::AsyncDescribeCountersResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListCountersResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
            {
                EzListCountersResult ezResult(*r.getResult());
                AsyncEzListCountersResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzListCountersResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getCounter(
    std::function<void(AsyncEzGetCounterResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder counterName
)
{
    gs2::mission::GetCounterRequest request;
    request.setNamespaceName(namespaceName);
    request.setCounterName(counterName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pWebSocketClient->getCounter(
        request,
        [callback](gs2::mission::AsyncGetCounterResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetCounterResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
            {
                EzGetCounterResult ezResult(*r.getResult());
                AsyncEzGetCounterResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetCounterResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::listMissionTaskModels(
    std::function<void(AsyncEzListMissionTaskModelsResult)> callback,
    StringHolder namespaceName,
    StringHolder missionGroupName
)
{
    gs2::mission::DescribeMissionTaskModelsRequest request;
    request.setNamespaceName(namespaceName);
    request.setMissionGroupName(missionGroupName);
    m_pRestClient->describeMissionTaskModels(
        request,
        [callback](gs2::mission::AsyncDescribeMissionTaskModelsResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListMissionTaskModelsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
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
    std::function<void(AsyncEzGetMissionTaskModelResult)> callback,
    StringHolder namespaceName,
    StringHolder missionGroupName,
    StringHolder missionTaskName
)
{
    gs2::mission::GetMissionTaskModelRequest request;
    request.setNamespaceName(namespaceName);
    request.setMissionGroupName(missionGroupName);
    request.setMissionTaskName(missionTaskName);
    m_pWebSocketClient->getMissionTaskModel(
        request,
        [callback](gs2::mission::AsyncGetMissionTaskModelResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetMissionTaskModelResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
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

void Client::listMissionGroupModels(
    std::function<void(AsyncEzListMissionGroupModelsResult)> callback,
    StringHolder namespaceName
)
{
    gs2::mission::DescribeMissionGroupModelsRequest request;
    request.setNamespaceName(namespaceName);
    m_pRestClient->describeMissionGroupModels(
        request,
        [callback](gs2::mission::AsyncDescribeMissionGroupModelsResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListMissionGroupModelsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
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
    std::function<void(AsyncEzGetMissionGroupModelResult)> callback,
    StringHolder namespaceName,
    StringHolder missionGroupName
)
{
    gs2::mission::GetMissionGroupModelRequest request;
    request.setNamespaceName(namespaceName);
    request.setMissionGroupName(missionGroupName);
    m_pWebSocketClient->getMissionGroupModel(
        request,
        [callback](gs2::mission::AsyncGetMissionGroupModelResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetMissionGroupModelResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
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

void Client::listCompletes(
    std::function<void(AsyncEzListCompletesResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    gs2::optional<StringHolder> pageToken,
    gs2::optional<Int64> limit
)
{
    gs2::mission::DescribeCompletesRequest request;
    request.setNamespaceName(namespaceName);
    if (pageToken)
    {
        request.setPageToken(std::move(*pageToken));
    }
    if (limit)
    {
        request.setLimit(std::move(*limit));
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pRestClient->describeCompletes(
        request,
        [callback](gs2::mission::AsyncDescribeCompletesResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListCompletesResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
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
    std::function<void(AsyncEzGetCompleteResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder missionGroupName
)
{
    gs2::mission::GetCompleteRequest request;
    request.setNamespaceName(namespaceName);
    request.setMissionGroupName(missionGroupName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pWebSocketClient->getComplete(
        request,
        [callback](gs2::mission::AsyncGetCompleteResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetCompleteResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
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
    std::function<void(AsyncEzReceiveRewardsResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder missionGroupName,
    StringHolder missionTaskName
)
{
    gs2::mission::CompleteRequest request;
    request.setNamespaceName(namespaceName);
    request.setMissionGroupName(missionGroupName);
    request.setMissionTaskName(missionTaskName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pRestClient->complete(
        request,
        [callback](gs2::mission::AsyncCompleteResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzReceiveRewardsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
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

}}}