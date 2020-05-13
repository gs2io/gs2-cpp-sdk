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
#include <gs2/dictionary/Gs2DictionaryWebSocketClient.hpp>


namespace gs2 { namespace ez { namespace dictionary {

Client::Client(gs2::ez::Profile& profile) :
    m_Profile(profile),
    m_pClient(new gs2::dictionary::Gs2DictionaryWebSocketClient(profile.getGs2Session()))
{
}

Client::~Client()
{
    delete m_pClient;
}

void Client::listEntryModels(
    std::function<void(AsyncEzListEntryModelsResult)> callback,
    StringHolder namespaceName
)
{
    gs2::dictionary::DescribeEntryModelsRequest request;
    request.setNamespaceName(namespaceName);
    m_pClient->describeEntryModels(
        request,
        [callback](gs2::dictionary::AsyncDescribeEntryModelsResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListEntryModelsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzListEntryModelsResult::isConvertible(*r.getResult()))
            {
                EzListEntryModelsResult ezResult(*r.getResult());
                AsyncEzListEntryModelsResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzListEntryModelsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getEntryModel(
    std::function<void(AsyncEzGetEntryModelResult)> callback,
    StringHolder namespaceName,
    StringHolder entryName
)
{
    gs2::dictionary::GetEntryModelRequest request;
    request.setNamespaceName(namespaceName);
    request.setEntryName(entryName);
    m_pClient->getEntryModel(
        request,
        [callback](gs2::dictionary::AsyncGetEntryModelResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetEntryModelResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetEntryModelResult::isConvertible(*r.getResult()))
            {
                EzGetEntryModelResult ezResult(*r.getResult());
                AsyncEzGetEntryModelResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetEntryModelResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::listEntries(
    std::function<void(AsyncEzListEntriesResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    gs2::optional<Int64> limit,
    gs2::optional<StringHolder> pageToken
)
{
    gs2::dictionary::DescribeEntriesRequest request;
    request.setNamespaceName(namespaceName);
    if (limit)
    {
        request.setLimit(std::move(*limit));
    }
    if (pageToken)
    {
        request.setPageToken(std::move(*pageToken));
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pClient->describeEntries(
        request,
        [callback](gs2::dictionary::AsyncDescribeEntriesResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListEntriesResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzListEntriesResult::isConvertible(*r.getResult()))
            {
                EzListEntriesResult ezResult(*r.getResult());
                AsyncEzListEntriesResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzListEntriesResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getEntry(
    std::function<void(AsyncEzGetEntryResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder entryModelName
)
{
    gs2::dictionary::GetEntryRequest request;
    request.setNamespaceName(namespaceName);
    request.setEntryModelName(entryModelName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pClient->getEntry(
        request,
        [callback](gs2::dictionary::AsyncGetEntryResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetEntryResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetEntryResult::isConvertible(*r.getResult()))
            {
                EzGetEntryResult ezResult(*r.getResult());
                AsyncEzGetEntryResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetEntryResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

}}}