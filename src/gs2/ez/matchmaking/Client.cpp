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


namespace gs2 { namespace ez { namespace matchmaking {

Client::Client(gs2::ez::Profile& profile) :
    m_Profile(profile),
    m_Client(profile.getGs2Session())
{
}

void Client::createGathering(
    std::function<void(AsyncEzCreateGatheringResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    EzPlayer player,
    List<EzCapacityOfRole> capacityOfRoles,
    List<StringHolder> allowUserIds,
    gs2::optional<List<EzAttributeRange>> attributeRanges
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
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.createGathering(
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
    m_Client.updateGathering(
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
    m_Client.doMatchmaking(
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
    m_Client.getGathering(
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
    m_Client.cancelMatchmaking(
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

}}}