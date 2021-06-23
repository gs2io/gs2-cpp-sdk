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
#include <gs2/ranking/Gs2RankingWebSocketClient.hpp>
#include <gs2/ranking/Gs2RankingRestClient.hpp>


namespace gs2 { namespace ez { namespace ranking {

Client::Client(gs2::ez::Profile& profile) :
    m_Profile(profile),
    m_pWebSocketClient(new gs2::ranking::Gs2RankingWebSocketClient(profile.getGs2WebSocketSession())),
    m_pRestClient(new gs2::ranking::Gs2RankingRestClient(profile.getGs2RestSession()))
{
}

Client::~Client()
{
    delete m_pWebSocketClient;
    delete m_pRestClient;
}

void Client::listCategories(
    std::function<void(AsyncEzListCategoriesResult)> callback,
    StringHolder namespaceName
)
{
    gs2::ranking::DescribeCategoryModelsRequest request;
    request.setNamespaceName(namespaceName);
    m_pRestClient->describeCategoryModels(
        request,
        [callback](gs2::ranking::AsyncDescribeCategoryModelsResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListCategoriesResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzListCategoriesResult::isConvertible(*r.getResult()))
            {
                EzListCategoriesResult ezResult(*r.getResult());
                AsyncEzListCategoriesResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzListCategoriesResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getCategory(
    std::function<void(AsyncEzGetCategoryResult)> callback,
    StringHolder namespaceName,
    StringHolder categoryName
)
{
    gs2::ranking::GetCategoryModelRequest request;
    request.setNamespaceName(namespaceName);
    request.setCategoryName(categoryName);
    m_pWebSocketClient->getCategoryModel(
        request,
        [callback](gs2::ranking::AsyncGetCategoryModelResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetCategoryResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetCategoryResult::isConvertible(*r.getResult()))
            {
                EzGetCategoryResult ezResult(*r.getResult());
                AsyncEzGetCategoryResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetCategoryResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::listSubscribes(
    std::function<void(AsyncEzListSubscribesResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder categoryName
)
{
    gs2::ranking::DescribeSubscribesByCategoryNameRequest request;
    request.setNamespaceName(namespaceName);
    request.setCategoryName(categoryName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pRestClient->describeSubscribesByCategoryName(
        request,
        [callback](gs2::ranking::AsyncDescribeSubscribesByCategoryNameResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListSubscribesResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzListSubscribesResult::isConvertible(*r.getResult()))
            {
                EzListSubscribesResult ezResult(*r.getResult());
                AsyncEzListSubscribesResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzListSubscribesResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::subscribe(
    std::function<void(AsyncEzSubscribeResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder categoryName,
    StringHolder targetUserId
)
{
    gs2::ranking::SubscribeRequest request;
    request.setNamespaceName(namespaceName);
    request.setCategoryName(categoryName);
    request.setTargetUserId(targetUserId);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pWebSocketClient->subscribe(
        request,
        [callback](gs2::ranking::AsyncSubscribeResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzSubscribeResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzSubscribeResult::isConvertible(*r.getResult()))
            {
                EzSubscribeResult ezResult(*r.getResult());
                AsyncEzSubscribeResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzSubscribeResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::unsubscribe(
    std::function<void(AsyncEzUnsubscribeResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder categoryName,
    StringHolder targetUserId
)
{
    gs2::ranking::UnsubscribeRequest request;
    request.setNamespaceName(namespaceName);
    request.setCategoryName(categoryName);
    request.setTargetUserId(targetUserId);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pWebSocketClient->unsubscribe(
        request,
        [callback](gs2::ranking::AsyncUnsubscribeResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzUnsubscribeResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzUnsubscribeResult::isConvertible(*r.getResult()))
            {
                EzUnsubscribeResult ezResult(*r.getResult());
                AsyncEzUnsubscribeResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzUnsubscribeResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::listScores(
    std::function<void(AsyncEzListScoresResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder categoryName,
    StringHolder scorerUserId,
    gs2::optional<StringHolder> pageToken,
    gs2::optional<Int64> limit
)
{
    gs2::ranking::DescribeScoresRequest request;
    request.setNamespaceName(namespaceName);
    request.setCategoryName(categoryName);
    request.setScorerUserId(scorerUserId);
    if (pageToken)
    {
        request.setPageToken(std::move(*pageToken));
    }
    if (limit)
    {
        request.setLimit(std::move(*limit));
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pRestClient->describeScores(
        request,
        [callback](gs2::ranking::AsyncDescribeScoresResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListScoresResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzListScoresResult::isConvertible(*r.getResult()))
            {
                EzListScoresResult ezResult(*r.getResult());
                AsyncEzListScoresResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzListScoresResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getScore(
    std::function<void(AsyncEzGetScoreResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder categoryName,
    StringHolder scorerUserId,
    gs2::optional<StringHolder> uniqueId
)
{
    gs2::ranking::GetScoreRequest request;
    request.setNamespaceName(namespaceName);
    request.setCategoryName(categoryName);
    request.setScorerUserId(scorerUserId);
    if (uniqueId)
    {
        request.setUniqueId(std::move(*uniqueId));
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pWebSocketClient->getScore(
        request,
        [callback](gs2::ranking::AsyncGetScoreResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetScoreResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetScoreResult::isConvertible(*r.getResult()))
            {
                EzGetScoreResult ezResult(*r.getResult());
                AsyncEzGetScoreResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetScoreResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::putScore(
    std::function<void(AsyncEzPutScoreResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder categoryName,
    Int64 score,
    gs2::optional<StringHolder> metadata
)
{
    gs2::ranking::PutScoreRequest request;
    request.setNamespaceName(namespaceName);
    request.setCategoryName(categoryName);
    request.setScore(score);
    if (metadata)
    {
        request.setMetadata(std::move(*metadata));
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pWebSocketClient->putScore(
        request,
        [callback](gs2::ranking::AsyncPutScoreResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzPutScoreResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzPutScoreResult::isConvertible(*r.getResult()))
            {
                EzPutScoreResult ezResult(*r.getResult());
                AsyncEzPutScoreResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzPutScoreResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getRanking(
    std::function<void(AsyncEzGetRankingResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder categoryName,
    gs2::optional<StringHolder> pageToken,
    gs2::optional<Int64> limit,
    gs2::optional<Int64> startIndex
)
{
    gs2::ranking::DescribeRankingsRequest request;
    request.setNamespaceName(namespaceName);
    request.setCategoryName(categoryName);
    if (pageToken)
    {
        request.setPageToken(std::move(*pageToken));
    }
    if (limit)
    {
        request.setLimit(std::move(*limit));
    }
    if (startIndex)
    {
        request.setStartIndex(std::move(*startIndex));
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pRestClient->describeRankings(
        request,
        [callback](gs2::ranking::AsyncDescribeRankingsResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetRankingResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetRankingResult::isConvertible(*r.getResult()))
            {
                EzGetRankingResult ezResult(*r.getResult());
                AsyncEzGetRankingResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetRankingResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getNearRanking(
    std::function<void(AsyncEzGetNearRankingResult)> callback,
    StringHolder namespaceName,
    StringHolder categoryName,
    Int64 score
)
{
    gs2::ranking::DescribeNearRankingsRequest request;
    request.setNamespaceName(namespaceName);
    request.setCategoryName(categoryName);
    request.setScore(score);
    m_pRestClient->describeNearRankings(
        request,
        [callback](gs2::ranking::AsyncDescribeNearRankingsResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetNearRankingResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetNearRankingResult::isConvertible(*r.getResult()))
            {
                EzGetNearRankingResult ezResult(*r.getResult());
                AsyncEzGetNearRankingResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetNearRankingResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getRank(
    std::function<void(AsyncEzGetRankResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder categoryName,
    StringHolder scorerUserId,
    gs2::optional<StringHolder> uniqueId
)
{
    gs2::ranking::GetRankingRequest request;
    request.setNamespaceName(namespaceName);
    request.setCategoryName(categoryName);
    request.setScorerUserId(scorerUserId);
    if (uniqueId)
    {
        request.setUniqueId(std::move(*uniqueId));
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pWebSocketClient->getRanking(
        request,
        [callback](gs2::ranking::AsyncGetRankingResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetRankResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetRankResult::isConvertible(*r.getResult()))
            {
                EzGetRankResult ezResult(*r.getResult());
                AsyncEzGetRankResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetRankResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

}}}