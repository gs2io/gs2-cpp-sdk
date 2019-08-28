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


namespace gs2 { namespace ez { namespace quest {

Client::Client(gs2::ez::Profile& profile) :
    m_Profile(profile),
    m_Client(profile.getGs2Session())
{
}

void Client::Start(
    std::function<void(AsyncEzStartResult&)> callback,
    GameSession& session,
    const Char* namespaceName,
    const Char* questGroupName,
    const Char* questName,
    gs2::optional<Bool> force
)
{
    gs2::quest::StartRequest request;
    request.setNamespaceName(namespaceName);
    request.setQuestGroupName(questGroupName);
    request.setQuestName(questName);
    if (force)
    {
        request.setForce(*force);
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.start(
        request,
        [callback](gs2::quest::AsyncStartResult& r)
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

void Client::End(
    std::function<void(AsyncEzEndResult&)> callback,
    GameSession& session,
    const Char* namespaceName,
    const Char* transactionId,
    gs2::optional<List<EzReward>> rewards,
    gs2::optional<Bool> isComplete
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
        request.setIsComplete(*isComplete);
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.end(
        request,
        [callback](gs2::quest::AsyncEndResult& r)
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

void Client::Delete(
    std::function<void(AsyncEzDeleteResult&)> callback,
    GameSession& session,
    const Char* namespaceName
)
{
    gs2::quest::DeleteProgressRequest request;
    request.setNamespaceName(namespaceName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.deleteProgress(
        request,
        [callback](gs2::quest::AsyncDeleteProgressResult& r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzDeleteResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzDeleteResult::isConvertible(*r.getResult()))
            {
                EzDeleteResult ezResult(*r.getResult());
                AsyncEzDeleteResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzDeleteResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::DescribeCompletedQuestLists(
    std::function<void(AsyncEzDescribeCompletedQuestListsResult&)> callback,
    GameSession& session,
    const Char* namespaceName,
    const Char* pageToken,
    gs2::optional<Int64> limit
)
{
    gs2::quest::DescribeCompletedQuestListsRequest request;
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
    m_Client.describeCompletedQuestLists(
        request,
        [callback](gs2::quest::AsyncDescribeCompletedQuestListsResult& r)
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

void Client::GetCompletedQuestList(
    std::function<void(AsyncEzGetCompletedQuestListResult&)> callback,
    GameSession& session,
    const Char* namespaceName,
    const Char* questGroupName
)
{
    gs2::quest::GetCompletedQuestListRequest request;
    request.setNamespaceName(namespaceName);
    request.setQuestGroupName(questGroupName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.getCompletedQuestList(
        request,
        [callback](gs2::quest::AsyncGetCompletedQuestListResult& r)
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

void Client::ListQuestGroups(
    std::function<void(AsyncEzListQuestGroupsResult&)> callback,
    const Char* namespaceName
)
{
    gs2::quest::DescribeQuestGroupModelsRequest request;
    request.setNamespaceName(namespaceName);
    m_Client.describeQuestGroupModels(
        request,
        [callback](gs2::quest::AsyncDescribeQuestGroupModelsResult& r)
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

void Client::GetQuestGroup(
    std::function<void(AsyncEzGetQuestGroupResult&)> callback,
    const Char* namespaceName,
    const Char* questGroupName
)
{
    gs2::quest::GetQuestGroupModelRequest request;
    request.setNamespaceName(namespaceName);
    request.setQuestGroupName(questGroupName);
    m_Client.getQuestGroupModel(
        request,
        [callback](gs2::quest::AsyncGetQuestGroupModelResult& r)
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

void Client::ListQuests(
    std::function<void(AsyncEzListQuestsResult&)> callback,
    const Char* namespaceName,
    const Char* questGroupName
)
{
    gs2::quest::DescribeQuestModelsRequest request;
    request.setNamespaceName(namespaceName);
    request.setQuestGroupName(questGroupName);
    m_Client.describeQuestModels(
        request,
        [callback](gs2::quest::AsyncDescribeQuestModelsResult& r)
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

void Client::GetQuest(
    std::function<void(AsyncEzGetQuestResult&)> callback,
    const Char* namespaceName,
    const Char* questGroupName,
    const Char* questName
)
{
    gs2::quest::GetQuestModelRequest request;
    request.setNamespaceName(namespaceName);
    request.setQuestGroupName(questGroupName);
    request.setQuestName(questName);
    m_Client.getQuestModel(
        request,
        [callback](gs2::quest::AsyncGetQuestModelResult& r)
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