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

void Client::ListMissionGroupModels(
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
                EzListMissionGroupModelsResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzListMissionGroupModelsResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzListMissionGroupModelsResult::isConvertible(*r.getResult()))
                {
                    EzListMissionGroupModelsResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzListMissionGroupModelsResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzListMissionGroupModelsResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzListMissionGroupModelsResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

void Client::GetMissionGroupModel(
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
                EzGetMissionGroupModelResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzGetMissionGroupModelResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzGetMissionGroupModelResult::isConvertible(*r.getResult()))
                {
                    EzGetMissionGroupModelResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzGetMissionGroupModelResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzGetMissionGroupModelResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzGetMissionGroupModelResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

void Client::ListCounterModels(
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
                EzListCounterModelsResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzListCounterModelsResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzListCounterModelsResult::isConvertible(*r.getResult()))
                {
                    EzListCounterModelsResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzListCounterModelsResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzListCounterModelsResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzListCounterModelsResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

void Client::GetCounterModel(
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
                EzGetCounterModelResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzGetCounterModelResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzGetCounterModelResult::isConvertible(*r.getResult()))
                {
                    EzGetCounterModelResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzGetCounterModelResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzGetCounterModelResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzGetCounterModelResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

void Client::ListCompletes(
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
                EzListCompletesResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzListCompletesResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzListCompletesResult::isConvertible(*r.getResult()))
                {
                    EzListCompletesResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzListCompletesResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzListCompletesResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzListCompletesResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

void Client::GetComplete(
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
                EzGetCompleteResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzGetCompleteResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzGetCompleteResult::isConvertible(*r.getResult()))
                {
                    EzGetCompleteResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzGetCompleteResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzGetCompleteResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzGetCompleteResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

void Client::ReceiveRewards(
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
                EzReceiveRewardsResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzReceiveRewardsResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzReceiveRewardsResult::isConvertible(*r.getResult()))
                {
                    EzReceiveRewardsResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzReceiveRewardsResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzReceiveRewardsResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzReceiveRewardsResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

void Client::ListMissionTaskModels(
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
                EzListMissionTaskModelsResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzListMissionTaskModelsResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzListMissionTaskModelsResult::isConvertible(*r.getResult()))
                {
                    EzListMissionTaskModelsResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzListMissionTaskModelsResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzListMissionTaskModelsResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzListMissionTaskModelsResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

void Client::GetMissionTaskModel(
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
                EzGetMissionTaskModelResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzGetMissionTaskModelResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzGetMissionTaskModelResult::isConvertible(*r.getResult()))
                {
                    EzGetMissionTaskModelResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzGetMissionTaskModelResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzGetMissionTaskModelResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzGetMissionTaskModelResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

}}}