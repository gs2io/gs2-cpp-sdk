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
#include <gs2/quest/Gs2QuestWebSocketClient.hpp>


namespace gs2 { namespace ez { namespace quest {

Client::Client(gs2::ez::Profile& profile) :
    m_Profile(profile),
    m_pClient(new gs2::quest::Gs2QuestWebSocketClient(profile.getGs2Session()))
{
}

Client::~Client()
{
    delete m_pClient;
}

void Client::start(
    std::function<void(AsyncEzStartResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder questGroupName,
    StringHolder questName,
    gs2::optional<Bool> force,
    gs2::optional<List<EzConfig>> config
)
{
    gs2::quest::StartRequest request;
    request.setNamespaceName(namespaceName);
    request.setQuestGroupName(questGroupName);
    request.setQuestName(questName);
    if (force)
    {
        request.setForce(std::move(*force));
    }
    if (config)
    {
        gs2::List<gs2::quest::Config> list;
        for (int i = 0; i < config->getCount(); ++i)
        {
            list += (*config)[i].ToModel();
        }
        request.setConfig(list);
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pClient->start(
        request,
        [callback](gs2::quest::AsyncStartResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzStartResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzStartResult::isConvertible(*r.getResult()))
            {
                EzStartResult ezResult(*r.getResult());
                AsyncEzStartResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzStartResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::end(
    std::function<void(AsyncEzEndResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder transactionId,
    gs2::optional<List<EzReward>> rewards,
    gs2::optional<Bool> isComplete,
    gs2::optional<List<EzConfig>> config
)
{
    gs2::quest::EndRequest request;
    request.setNamespaceName(namespaceName);
    request.setTransactionId(transactionId);
    if (rewards)
    {
        gs2::List<gs2::quest::Reward> list;
        for (int i = 0; i < rewards->getCount(); ++i)
        {
            list += (*rewards)[i].ToModel();
        }
        request.setRewards(list);
    }
    if (isComplete)
    {
        request.setIsComplete(std::move(*isComplete));
    }
    if (config)
    {
        gs2::List<gs2::quest::Config> list;
        for (int i = 0; i < config->getCount(); ++i)
        {
            list += (*config)[i].ToModel();
        }
        request.setConfig(list);
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pClient->end(
        request,
        [callback](gs2::quest::AsyncEndResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzEndResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzEndResult::isConvertible(*r.getResult()))
            {
                EzEndResult ezResult(*r.getResult());
                AsyncEzEndResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzEndResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getProgress(
    std::function<void(AsyncEzGetProgressResult)> callback,
    GameSession& session,
    StringHolder namespaceName
)
{
    gs2::quest::GetProgressRequest request;
    request.setNamespaceName(namespaceName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pClient->getProgress(
        request,
        [callback](gs2::quest::AsyncGetProgressResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetProgressResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetProgressResult::isConvertible(*r.getResult()))
            {
                EzGetProgressResult ezResult(*r.getResult());
                AsyncEzGetProgressResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetProgressResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::deleteProgress(
    std::function<void(AsyncEzDeleteProgressResult)> callback,
    GameSession& session,
    StringHolder namespaceName
)
{
    gs2::quest::DeleteProgressRequest request;
    request.setNamespaceName(namespaceName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pClient->deleteProgress(
        request,
        [callback](gs2::quest::AsyncDeleteProgressResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzDeleteProgressResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzDeleteProgressResult::isConvertible(*r.getResult()))
            {
                EzDeleteProgressResult ezResult(*r.getResult());
                AsyncEzDeleteProgressResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzDeleteProgressResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::describeCompletedQuestLists(
    std::function<void(AsyncEzDescribeCompletedQuestListsResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    gs2::optional<StringHolder> pageToken,
    gs2::optional<Int64> limit
)
{
    gs2::quest::DescribeCompletedQuestListsRequest request;
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
    m_pClient->describeCompletedQuestLists(
        request,
        [callback](gs2::quest::AsyncDescribeCompletedQuestListsResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzDescribeCompletedQuestListsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzDescribeCompletedQuestListsResult::isConvertible(*r.getResult()))
            {
                EzDescribeCompletedQuestListsResult ezResult(*r.getResult());
                AsyncEzDescribeCompletedQuestListsResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzDescribeCompletedQuestListsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getCompletedQuestList(
    std::function<void(AsyncEzGetCompletedQuestListResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder questGroupName
)
{
    gs2::quest::GetCompletedQuestListRequest request;
    request.setNamespaceName(namespaceName);
    request.setQuestGroupName(questGroupName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pClient->getCompletedQuestList(
        request,
        [callback](gs2::quest::AsyncGetCompletedQuestListResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetCompletedQuestListResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetCompletedQuestListResult::isConvertible(*r.getResult()))
            {
                EzGetCompletedQuestListResult ezResult(*r.getResult());
                AsyncEzGetCompletedQuestListResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetCompletedQuestListResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::listQuestGroups(
    std::function<void(AsyncEzListQuestGroupsResult)> callback,
    StringHolder namespaceName
)
{
    gs2::quest::DescribeQuestGroupModelsRequest request;
    request.setNamespaceName(namespaceName);
    m_pClient->describeQuestGroupModels(
        request,
        [callback](gs2::quest::AsyncDescribeQuestGroupModelsResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListQuestGroupsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzListQuestGroupsResult::isConvertible(*r.getResult()))
            {
                EzListQuestGroupsResult ezResult(*r.getResult());
                AsyncEzListQuestGroupsResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzListQuestGroupsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getQuestGroup(
    std::function<void(AsyncEzGetQuestGroupResult)> callback,
    StringHolder namespaceName,
    StringHolder questGroupName
)
{
    gs2::quest::GetQuestGroupModelRequest request;
    request.setNamespaceName(namespaceName);
    request.setQuestGroupName(questGroupName);
    m_pClient->getQuestGroupModel(
        request,
        [callback](gs2::quest::AsyncGetQuestGroupModelResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetQuestGroupResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetQuestGroupResult::isConvertible(*r.getResult()))
            {
                EzGetQuestGroupResult ezResult(*r.getResult());
                AsyncEzGetQuestGroupResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetQuestGroupResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::listQuests(
    std::function<void(AsyncEzListQuestsResult)> callback,
    StringHolder namespaceName,
    StringHolder questGroupName
)
{
    gs2::quest::DescribeQuestModelsRequest request;
    request.setNamespaceName(namespaceName);
    request.setQuestGroupName(questGroupName);
    m_pClient->describeQuestModels(
        request,
        [callback](gs2::quest::AsyncDescribeQuestModelsResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListQuestsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzListQuestsResult::isConvertible(*r.getResult()))
            {
                EzListQuestsResult ezResult(*r.getResult());
                AsyncEzListQuestsResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzListQuestsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getQuest(
    std::function<void(AsyncEzGetQuestResult)> callback,
    StringHolder namespaceName,
    StringHolder questGroupName,
    StringHolder questName
)
{
    gs2::quest::GetQuestModelRequest request;
    request.setNamespaceName(namespaceName);
    request.setQuestGroupName(questGroupName);
    request.setQuestName(questName);
    m_pClient->getQuestModel(
        request,
        [callback](gs2::quest::AsyncGetQuestModelResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetQuestResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetQuestResult::isConvertible(*r.getResult()))
            {
                EzGetQuestResult ezResult(*r.getResult());
                AsyncEzGetQuestResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetQuestResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

}}}