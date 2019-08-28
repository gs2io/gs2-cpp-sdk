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


namespace gs2 { namespace ez { namespace experience {

Client::Client(gs2::ez::Profile& profile) :
    m_Profile(profile),
    m_Client(profile.getGs2Session())
{
}

void Client::ListExperienceModels(
    std::function<void(AsyncEzListExperienceModelsResult&)> callback,
    const Char* namespaceName
)
{
    gs2::experience::DescribeExperienceModelsRequest request;
    request.setNamespaceName(namespaceName);
    m_Client.describeExperienceModels(
        request,
        [callback](gs2::experience::AsyncDescribeExperienceModelsResult& r)
        {
            if (r.getError())
            {
                EzListExperienceModelsResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzListExperienceModelsResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzListExperienceModelsResult::isConvertible(*r.getResult()))
                {
                    EzListExperienceModelsResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzListExperienceModelsResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzListExperienceModelsResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzListExperienceModelsResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

void Client::GetExperienceModel(
    std::function<void(AsyncEzGetExperienceModelResult&)> callback,
    const Char* namespaceName,
    const Char* experienceName
)
{
    gs2::experience::GetExperienceModelRequest request;
    request.setNamespaceName(namespaceName);
    request.setExperienceName(experienceName);
    m_Client.getExperienceModel(
        request,
        [callback](gs2::experience::AsyncGetExperienceModelResult& r)
        {
            if (r.getError())
            {
                EzGetExperienceModelResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzGetExperienceModelResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzGetExperienceModelResult::isConvertible(*r.getResult()))
                {
                    EzGetExperienceModelResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzGetExperienceModelResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzGetExperienceModelResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzGetExperienceModelResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

void Client::ListStatuses(
    std::function<void(AsyncEzListStatusesResult&)> callback,
    GameSession& session,
    const Char* namespaceName,
    const Char* experienceName,
    const Char* pageToken,
    gs2::optional<Int64> limit
)
{
    gs2::experience::DescribeStatusesRequest request;
    request.setNamespaceName(namespaceName);
    if (experienceName)
    {
        request.setExperienceName(experienceName);
    }
    if (pageToken)
    {
        request.setPageToken(pageToken);
    }
    if (limit)
    {
        request.setLimit(*limit);
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.describeStatuses(
        request,
        [callback](gs2::experience::AsyncDescribeStatusesResult& r)
        {
            if (r.getError())
            {
                EzListStatusesResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzListStatusesResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzListStatusesResult::isConvertible(*r.getResult()))
                {
                    EzListStatusesResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzListStatusesResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzListStatusesResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzListStatusesResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

void Client::GetStatus(
    std::function<void(AsyncEzGetStatusResult&)> callback,
    GameSession& session,
    const Char* namespaceName,
    const Char* experienceName,
    const Char* propertyId
)
{
    gs2::experience::GetStatusRequest request;
    request.setNamespaceName(namespaceName);
    request.setExperienceName(experienceName);
    request.setPropertyId(propertyId);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.getStatus(
        request,
        [callback](gs2::experience::AsyncGetStatusResult& r)
        {
            if (r.getError())
            {
                EzGetStatusResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzGetStatusResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzGetStatusResult::isConvertible(*r.getResult()))
                {
                    EzGetStatusResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzGetStatusResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzGetStatusResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzGetStatusResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

}}}