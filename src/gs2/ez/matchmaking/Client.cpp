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

void Client::CreateGathering(
    std::function<void(AsyncEzCreateGatheringResult&)> callback,
    GameSession& session,
    const Char* namespaceName,
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
        [callback](gs2::matchmaking::AsyncCreateGatheringResult& r)
        {
            if (r.getError())
            {
                EzCreateGatheringResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzCreateGatheringResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzCreateGatheringResult::isConvertible(*r.getResult()))
                {
                    EzCreateGatheringResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzCreateGatheringResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzCreateGatheringResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzCreateGatheringResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

void Client::UpdateGathering(
    std::function<void(AsyncEzUpdateGatheringResult&)> callback,
    GameSession& session,
    const Char* namespaceName,
    const Char* gatheringName,
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
        [callback](gs2::matchmaking::AsyncUpdateGatheringResult& r)
        {
            if (r.getError())
            {
                EzUpdateGatheringResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzUpdateGatheringResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzUpdateGatheringResult::isConvertible(*r.getResult()))
                {
                    EzUpdateGatheringResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzUpdateGatheringResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzUpdateGatheringResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzUpdateGatheringResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

void Client::DoMatchmaking(
    std::function<void(AsyncEzDoMatchmakingResult&)> callback,
    GameSession& session,
    const Char* namespaceName,
    EzPlayer player,
    const Char* matchmakingContextToken
)
{
    gs2::matchmaking::DoMatchmakingRequest request;
    request.setNamespaceName(namespaceName);
    request.setPlayer(player.ToModel());
    if (matchmakingContextToken)
    {
        request.setMatchmakingContextToken(matchmakingContextToken);
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.doMatchmaking(
        request,
        [callback](gs2::matchmaking::AsyncDoMatchmakingResult& r)
        {
            if (r.getError())
            {
                EzDoMatchmakingResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzDoMatchmakingResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzDoMatchmakingResult::isConvertible(*r.getResult()))
                {
                    EzDoMatchmakingResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzDoMatchmakingResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzDoMatchmakingResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzDoMatchmakingResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

void Client::GetGathering(
    std::function<void(AsyncEzGetGatheringResult&)> callback,
    const Char* namespaceName,
    const Char* gatheringName
)
{
    gs2::matchmaking::GetGatheringRequest request;
    request.setNamespaceName(namespaceName);
    request.setGatheringName(gatheringName);
    m_Client.getGathering(
        request,
        [callback](gs2::matchmaking::AsyncGetGatheringResult& r)
        {
            if (r.getError())
            {
                EzGetGatheringResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzGetGatheringResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzGetGatheringResult::isConvertible(*r.getResult()))
                {
                    EzGetGatheringResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzGetGatheringResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzGetGatheringResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzGetGatheringResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

void Client::CancelMatchmaking(
    std::function<void(AsyncEzCancelMatchmakingResult&)> callback,
    GameSession& session,
    const Char* namespaceName,
    const Char* gatheringName
)
{
    gs2::matchmaking::CancelMatchmakingRequest request;
    request.setNamespaceName(namespaceName);
    request.setGatheringName(gatheringName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.cancelMatchmaking(
        request,
        [callback](gs2::matchmaking::AsyncCancelMatchmakingResult& r)
        {
            if (r.getError())
            {
                EzCancelMatchmakingResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzCancelMatchmakingResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzCancelMatchmakingResult::isConvertible(*r.getResult()))
                {
                    EzCancelMatchmakingResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzCancelMatchmakingResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzCancelMatchmakingResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzCancelMatchmakingResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

}}}