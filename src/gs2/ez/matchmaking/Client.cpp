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
#include <gs2/matchmaking/Gs2MatchmakingWebSocketClient.hpp>


namespace gs2 { namespace ez { namespace matchmaking {

Client::Client(gs2::ez::Profile& profile) :
    m_Profile(profile),
    m_pClient(new gs2::matchmaking::Gs2MatchmakingWebSocketClient(profile.getGs2Session()))
{
}

Client::~Client()
{
    delete m_pClient;
}

void Client::createGathering(
    std::function<void(AsyncEzCreateGatheringResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    EzPlayer player,
    List<EzCapacityOfRole> capacityOfRoles,
    List<StringHolder> allowUserIds,
    gs2::optional<List<EzAttributeRange>> attributeRanges,
    gs2::optional<Int64> expiresAt
)
{
    gs2::matchmaking::CreateGatheringRequest request;
    request.setNamespaceName(namespaceName);
    request.setPlayer(player.ToModel());
    {
        gs2::List<gs2::matchmaking::CapacityOfRole> list;
        for (int i = 0; i < capacityOfRoles.getCount(); ++i)
        {
            list += capacityOfRoles[i].ToModel();
        }
        request.setCapacityOfRoles(list);
    }
    request.setAllowUserIds(allowUserIds);
    if (attributeRanges)
    {
        gs2::List<gs2::matchmaking::AttributeRange> list;
        for (int i = 0; i < attributeRanges->getCount(); ++i)
        {
            list += (*attributeRanges)[i].ToModel();
        }
        request.setAttributeRanges(list);
    }
    if (expiresAt)
    {
        request.setExpiresAt(std::move(*expiresAt));
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pClient->createGathering(
        request,
        [callback](gs2::matchmaking::AsyncCreateGatheringResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzCreateGatheringResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzCreateGatheringResult::isConvertible(*r.getResult()))
            {
                EzCreateGatheringResult ezResult(*r.getResult());
                AsyncEzCreateGatheringResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzCreateGatheringResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::updateGathering(
    std::function<void(AsyncEzUpdateGatheringResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder gatheringName,
    gs2::optional<List<EzAttributeRange>> attributeRanges
)
{
    gs2::matchmaking::UpdateGatheringRequest request;
    request.setNamespaceName(namespaceName);
    request.setGatheringName(gatheringName);
    if (attributeRanges)
    {
        gs2::List<gs2::matchmaking::AttributeRange> list;
        for (int i = 0; i < attributeRanges->getCount(); ++i)
        {
            list += (*attributeRanges)[i].ToModel();
        }
        request.setAttributeRanges(list);
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pClient->updateGathering(
        request,
        [callback](gs2::matchmaking::AsyncUpdateGatheringResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzUpdateGatheringResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzUpdateGatheringResult::isConvertible(*r.getResult()))
            {
                EzUpdateGatheringResult ezResult(*r.getResult());
                AsyncEzUpdateGatheringResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzUpdateGatheringResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::doMatchmaking(
    std::function<void(AsyncEzDoMatchmakingResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    EzPlayer player,
    gs2::optional<StringHolder> matchmakingContextToken
)
{
    gs2::matchmaking::DoMatchmakingRequest request;
    request.setNamespaceName(namespaceName);
    request.setPlayer(player.ToModel());
    if (matchmakingContextToken)
    {
        request.setMatchmakingContextToken(std::move(*matchmakingContextToken));
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pClient->doMatchmaking(
        request,
        [callback](gs2::matchmaking::AsyncDoMatchmakingResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzDoMatchmakingResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzDoMatchmakingResult::isConvertible(*r.getResult()))
            {
                EzDoMatchmakingResult ezResult(*r.getResult());
                AsyncEzDoMatchmakingResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzDoMatchmakingResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getGathering(
    std::function<void(AsyncEzGetGatheringResult)> callback,
    StringHolder namespaceName,
    StringHolder gatheringName
)
{
    gs2::matchmaking::GetGatheringRequest request;
    request.setNamespaceName(namespaceName);
    request.setGatheringName(gatheringName);
    m_pClient->getGathering(
        request,
        [callback](gs2::matchmaking::AsyncGetGatheringResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetGatheringResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetGatheringResult::isConvertible(*r.getResult()))
            {
                EzGetGatheringResult ezResult(*r.getResult());
                AsyncEzGetGatheringResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetGatheringResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::cancelMatchmaking(
    std::function<void(AsyncEzCancelMatchmakingResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder gatheringName
)
{
    gs2::matchmaking::CancelMatchmakingRequest request;
    request.setNamespaceName(namespaceName);
    request.setGatheringName(gatheringName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pClient->cancelMatchmaking(
        request,
        [callback](gs2::matchmaking::AsyncCancelMatchmakingResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzCancelMatchmakingResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzCancelMatchmakingResult::isConvertible(*r.getResult()))
            {
                EzCancelMatchmakingResult ezResult(*r.getResult());
                AsyncEzCancelMatchmakingResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzCancelMatchmakingResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::listRatingModels(
    std::function<void(AsyncEzListRatingModelsResult)> callback,
    StringHolder namespaceName
)
{
    gs2::matchmaking::DescribeRatingModelsRequest request;
    request.setNamespaceName(namespaceName);
    m_pClient->describeRatingModels(
        request,
        [callback](gs2::matchmaking::AsyncDescribeRatingModelsResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListRatingModelsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzListRatingModelsResult::isConvertible(*r.getResult()))
            {
                EzListRatingModelsResult ezResult(*r.getResult());
                AsyncEzListRatingModelsResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzListRatingModelsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getRatingModel(
    std::function<void(AsyncEzGetRatingModelResult)> callback,
    StringHolder namespaceName,
    StringHolder ratingName
)
{
    gs2::matchmaking::GetRatingModelRequest request;
    request.setNamespaceName(namespaceName);
    request.setRatingName(ratingName);
    m_pClient->getRatingModel(
        request,
        [callback](gs2::matchmaking::AsyncGetRatingModelResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetRatingModelResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetRatingModelResult::isConvertible(*r.getResult()))
            {
                EzGetRatingModelResult ezResult(*r.getResult());
                AsyncEzGetRatingModelResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetRatingModelResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::listRatings(
    std::function<void(AsyncEzListRatingsResult)> callback,
    StringHolder namespaceName,
    gs2::optional<StringHolder> pageToken,
    gs2::optional<Int64> limit
)
{
    gs2::matchmaking::DescribeRatingsRequest request;
    request.setNamespaceName(namespaceName);
    if (pageToken)
    {
        request.setPageToken(std::move(*pageToken));
    }
    if (limit)
    {
        request.setLimit(std::move(*limit));
    }
    m_pClient->describeRatings(
        request,
        [callback](gs2::matchmaking::AsyncDescribeRatingsResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListRatingsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzListRatingsResult::isConvertible(*r.getResult()))
            {
                EzListRatingsResult ezResult(*r.getResult());
                AsyncEzListRatingsResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzListRatingsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getRating(
    std::function<void(AsyncEzGetRatingResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder ratingName
)
{
    gs2::matchmaking::GetRatingRequest request;
    request.setNamespaceName(namespaceName);
    request.setRatingName(ratingName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pClient->getRating(
        request,
        [callback](gs2::matchmaking::AsyncGetRatingResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetRatingResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetRatingResult::isConvertible(*r.getResult()))
            {
                EzGetRatingResult ezResult(*r.getResult());
                AsyncEzGetRatingResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetRatingResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::createVote(
    std::function<void(AsyncEzCreateVoteResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder ratingName,
    StringHolder gatheringName
)
{
    gs2::matchmaking::GetBallotRequest request;
    request.setNamespaceName(namespaceName);
    request.setRatingName(ratingName);
    request.setGatheringName(gatheringName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pClient->getBallot(
        request,
        [callback](gs2::matchmaking::AsyncGetBallotResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzCreateVoteResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzCreateVoteResult::isConvertible(*r.getResult()))
            {
                EzCreateVoteResult ezResult(*r.getResult());
                AsyncEzCreateVoteResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzCreateVoteResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::vote(
    std::function<void(AsyncEzVoteResult)> callback,
    StringHolder namespaceName,
    StringHolder ballotBody,
    StringHolder ballotSignature,
    gs2::optional<List<EzGameResult>> gameResults
)
{
    gs2::matchmaking::VoteRequest request;
    request.setNamespaceName(namespaceName);
    request.setBallotBody(ballotBody);
    request.setBallotSignature(ballotSignature);
    if (gameResults)
    {
        gs2::List<gs2::matchmaking::GameResult> list;
        for (int i = 0; i < gameResults->getCount(); ++i)
        {
            list += (*gameResults)[i].ToModel();
        }
        request.setGameResults(list);
    }
    m_pClient->vote(
        request,
        [callback](gs2::matchmaking::AsyncVoteResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzVoteResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzVoteResult::isConvertible(*r.getResult()))
            {
                EzVoteResult ezResult(*r.getResult());
                AsyncEzVoteResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzVoteResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::voteMultiple(
    std::function<void(AsyncEzVoteMultipleResult)> callback,
    StringHolder namespaceName,
    List<EzSignedBallot> signedBallots,
    gs2::optional<List<EzGameResult>> gameResults
)
{
    gs2::matchmaking::VoteMultipleRequest request;
    request.setNamespaceName(namespaceName);
    {
        gs2::List<gs2::matchmaking::SignedBallot> list;
        for (int i = 0; i < signedBallots.getCount(); ++i)
        {
            list += signedBallots[i].ToModel();
        }
        request.setSignedBallots(list);
    }
    if (gameResults)
    {
        gs2::List<gs2::matchmaking::GameResult> list;
        for (int i = 0; i < gameResults->getCount(); ++i)
        {
            list += (*gameResults)[i].ToModel();
        }
        request.setGameResults(list);
    }
    m_pClient->voteMultiple(
        request,
        [callback](gs2::matchmaking::AsyncVoteMultipleResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzVoteMultipleResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzVoteMultipleResult::isConvertible(*r.getResult()))
            {
                EzVoteMultipleResult ezResult(*r.getResult());
                AsyncEzVoteMultipleResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzVoteMultipleResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

}}}