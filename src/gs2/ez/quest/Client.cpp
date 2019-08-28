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
                EzStartResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzStartResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzStartResult::isConvertible(*r.getResult()))
                {
                    EzStartResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzStartResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzStartResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzStartResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
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
                EzEndResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzEndResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzEndResult::isConvertible(*r.getResult()))
                {
                    EzEndResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzEndResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzEndResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzEndResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
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
                EzDeleteResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzDeleteResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzDeleteResult::isConvertible(*r.getResult()))
                {
                    EzDeleteResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzDeleteResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzDeleteResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzDeleteResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
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
                EzDescribeCompletedQuestListsResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzDescribeCompletedQuestListsResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzDescribeCompletedQuestListsResult::isConvertible(*r.getResult()))
                {
                    EzDescribeCompletedQuestListsResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzDescribeCompletedQuestListsResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzDescribeCompletedQuestListsResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzDescribeCompletedQuestListsResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
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
                EzGetCompletedQuestListResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzGetCompletedQuestListResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzGetCompletedQuestListResult::isConvertible(*r.getResult()))
                {
                    EzGetCompletedQuestListResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzGetCompletedQuestListResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzGetCompletedQuestListResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzGetCompletedQuestListResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
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
                EzListQuestGroupsResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzListQuestGroupsResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzListQuestGroupsResult::isConvertible(*r.getResult()))
                {
                    EzListQuestGroupsResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzListQuestGroupsResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzListQuestGroupsResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzListQuestGroupsResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
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
                EzGetQuestGroupResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzGetQuestGroupResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzGetQuestGroupResult::isConvertible(*r.getResult()))
                {
                    EzGetQuestGroupResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzGetQuestGroupResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzGetQuestGroupResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzGetQuestGroupResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
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
                EzListQuestsResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzListQuestsResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzListQuestsResult::isConvertible(*r.getResult()))
                {
                    EzListQuestsResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzListQuestsResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzListQuestsResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzListQuestsResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
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
                EzGetQuestResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzGetQuestResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzGetQuestResult::isConvertible(*r.getResult()))
                {
                    EzGetQuestResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzGetQuestResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzGetQuestResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzGetQuestResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

}}}