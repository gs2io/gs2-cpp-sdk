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
#include <gs2/experience/Gs2ExperienceWebSocketClient.hpp>


namespace gs2 { namespace ez { namespace experience {

Client::Client(gs2::ez::Profile& profile) :
    m_Profile(profile),
    m_pClient(new gs2::experience::Gs2ExperienceWebSocketClient(profile.getGs2Session()))
{
}

Client::~Client()
{
    delete m_pClient;
}

void Client::listExperienceModels(
    std::function<void(AsyncEzListExperienceModelsResult)> callback,
    StringHolder namespaceName
)
{
    gs2::experience::DescribeExperienceModelsRequest request;
    request.setNamespaceName(namespaceName);
    m_pClient->describeExperienceModels(
        request,
        [callback](gs2::experience::AsyncDescribeExperienceModelsResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListExperienceModelsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzListExperienceModelsResult::isConvertible(*r.getResult()))
            {
                EzListExperienceModelsResult ezResult(*r.getResult());
                AsyncEzListExperienceModelsResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzListExperienceModelsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getExperienceModel(
    std::function<void(AsyncEzGetExperienceModelResult)> callback,
    StringHolder namespaceName,
    StringHolder experienceName
)
{
    gs2::experience::GetExperienceModelRequest request;
    request.setNamespaceName(namespaceName);
    request.setExperienceName(experienceName);
    m_pClient->getExperienceModel(
        request,
        [callback](gs2::experience::AsyncGetExperienceModelResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetExperienceModelResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetExperienceModelResult::isConvertible(*r.getResult()))
            {
                EzGetExperienceModelResult ezResult(*r.getResult());
                AsyncEzGetExperienceModelResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetExperienceModelResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::listStatuses(
    std::function<void(AsyncEzListStatusesResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    gs2::optional<StringHolder> experienceName,
    gs2::optional<StringHolder> pageToken,
    gs2::optional<Int64> limit
)
{
    gs2::experience::DescribeStatusesRequest request;
    request.setNamespaceName(namespaceName);
    if (experienceName)
    {
        request.setExperienceName(std::move(*experienceName));
    }
    if (pageToken)
    {
        request.setPageToken(std::move(*pageToken));
    }
    if (limit)
    {
        request.setLimit(std::move(*limit));
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pClient->describeStatuses(
        request,
        [callback](gs2::experience::AsyncDescribeStatusesResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListStatusesResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzListStatusesResult::isConvertible(*r.getResult()))
            {
                EzListStatusesResult ezResult(*r.getResult());
                AsyncEzListStatusesResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzListStatusesResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getStatus(
    std::function<void(AsyncEzGetStatusResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder experienceName,
    StringHolder propertyId
)
{
    gs2::experience::GetStatusRequest request;
    request.setNamespaceName(namespaceName);
    request.setExperienceName(experienceName);
    request.setPropertyId(propertyId);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pClient->getStatus(
        request,
        [callback](gs2::experience::AsyncGetStatusResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetStatusResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetStatusResult::isConvertible(*r.getResult()))
            {
                EzGetStatusResult ezResult(*r.getResult());
                AsyncEzGetStatusResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetStatusResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

}}}