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
#include <gs2/account/Gs2AccountWebSocketClient.hpp>


namespace gs2 { namespace ez { namespace account {

Client::Client(gs2::ez::Profile& profile) :
    m_Profile(profile),
    m_pClient(new gs2::account::Gs2AccountWebSocketClient(profile.getGs2Session()))
{
}

Client::~Client()
{
    delete m_pClient;
}

void Client::create(
    std::function<void(AsyncEzCreateResult)> callback,
    StringHolder namespaceName
)
{
    gs2::account::CreateAccountRequest request;
    request.setNamespaceName(namespaceName);
    m_pClient->createAccount(
        request,
        [callback](gs2::account::AsyncCreateAccountResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzCreateResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzCreateResult::isConvertible(*r.getResult()))
            {
                EzCreateResult ezResult(*r.getResult());
                AsyncEzCreateResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzCreateResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::authentication(
    std::function<void(AsyncEzAuthenticationResult)> callback,
    StringHolder namespaceName,
    StringHolder userId,
    StringHolder keyId,
    StringHolder password
)
{
    gs2::account::AuthenticationRequest request;
    request.setNamespaceName(namespaceName);
    request.setUserId(userId);
    request.setKeyId(keyId);
    request.setPassword(password);
    m_pClient->authentication(
        request,
        [callback](gs2::account::AsyncAuthenticationResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzAuthenticationResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzAuthenticationResult::isConvertible(*r.getResult()))
            {
                EzAuthenticationResult ezResult(*r.getResult());
                AsyncEzAuthenticationResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzAuthenticationResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::addTakeOverSetting(
    std::function<void(AsyncEzAddTakeOverSettingResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    Int32 type,
    StringHolder userIdentifier,
    StringHolder password
)
{
    gs2::account::CreateTakeOverRequest request;
    request.setNamespaceName(namespaceName);
    request.setType(type);
    request.setUserIdentifier(userIdentifier);
    request.setPassword(password);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pClient->createTakeOver(
        request,
        [callback](gs2::account::AsyncCreateTakeOverResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzAddTakeOverSettingResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzAddTakeOverSettingResult::isConvertible(*r.getResult()))
            {
                EzAddTakeOverSettingResult ezResult(*r.getResult());
                AsyncEzAddTakeOverSettingResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzAddTakeOverSettingResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::listTakeOverSettings(
    std::function<void(AsyncEzListTakeOverSettingsResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    gs2::optional<StringHolder> pageToken,
    gs2::optional<Int64> limit
)
{
    gs2::account::DescribeTakeOversRequest request;
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
    m_pClient->describeTakeOvers(
        request,
        [callback](gs2::account::AsyncDescribeTakeOversResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListTakeOverSettingsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzListTakeOverSettingsResult::isConvertible(*r.getResult()))
            {
                EzListTakeOverSettingsResult ezResult(*r.getResult());
                AsyncEzListTakeOverSettingsResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzListTakeOverSettingsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::updateTakeOverSetting(
    std::function<void(AsyncEzUpdateTakeOverSettingResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    Int32 type,
    StringHolder oldPassword,
    StringHolder password
)
{
    gs2::account::UpdateTakeOverRequest request;
    request.setNamespaceName(namespaceName);
    request.setType(type);
    request.setOldPassword(oldPassword);
    request.setPassword(password);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pClient->updateTakeOver(
        request,
        [callback](gs2::account::AsyncUpdateTakeOverResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzUpdateTakeOverSettingResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzUpdateTakeOverSettingResult::isConvertible(*r.getResult()))
            {
                EzUpdateTakeOverSettingResult ezResult(*r.getResult());
                AsyncEzUpdateTakeOverSettingResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzUpdateTakeOverSettingResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::deleteTakeOverSetting(
    std::function<void(AsyncEzDeleteTakeOverSettingResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    Int32 type
)
{
    gs2::account::DeleteTakeOverRequest request;
    request.setNamespaceName(namespaceName);
    request.setType(type);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pClient->deleteTakeOver(
        request,
        [callback](gs2::account::AsyncDeleteTakeOverResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzDeleteTakeOverSettingResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else
            {
                AsyncEzDeleteTakeOverSettingResult asyncResult;
                callback(asyncResult);
            }
        }
    );
}

void Client::doTakeOver(
    std::function<void(AsyncEzDoTakeOverResult)> callback,
    StringHolder namespaceName,
    Int32 type,
    StringHolder userIdentifier,
    StringHolder password
)
{
    gs2::account::DoTakeOverRequest request;
    request.setNamespaceName(namespaceName);
    request.setType(type);
    request.setUserIdentifier(userIdentifier);
    request.setPassword(password);
    m_pClient->doTakeOver(
        request,
        [callback](gs2::account::AsyncDoTakeOverResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzDoTakeOverResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzDoTakeOverResult::isConvertible(*r.getResult()))
            {
                EzDoTakeOverResult ezResult(*r.getResult());
                AsyncEzDoTakeOverResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzDoTakeOverResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

}}}