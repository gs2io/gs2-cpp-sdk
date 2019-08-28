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


namespace gs2 { namespace ez { namespace account {

Client::Client(gs2::ez::Profile& profile) :
    m_Profile(profile),
    m_Client(profile.getGs2Session())
{
}

void Client::Create(
    std::function<void(AsyncEzCreateResult&)> callback,
    const Char* namespaceName
)
{
    gs2::account::CreateAccountRequest request;
    request.setNamespaceName(namespaceName);
    m_Client.createAccount(
        request,
        [callback](gs2::account::AsyncCreateAccountResult& r)
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

void Client::Authentication(
    std::function<void(AsyncEzAuthenticationResult&)> callback,
    const Char* namespaceName,
    const Char* userId,
    const Char* keyId,
    const Char* password
)
{
    gs2::account::AuthenticationRequest request;
    request.setNamespaceName(namespaceName);
    request.setUserId(userId);
    request.setKeyId(keyId);
    request.setPassword(password);
    m_Client.authentication(
        request,
        [callback](gs2::account::AsyncAuthenticationResult& r)
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

void Client::AddTakeOverSetting(
    std::function<void(AsyncEzAddTakeOverSettingResult&)> callback,
    GameSession& session,
    const Char* namespaceName,
    Int32 type,
    const Char* userIdentifier,
    const Char* password
)
{
    gs2::account::CreateTakeOverRequest request;
    request.setNamespaceName(namespaceName);
    request.setType(type);
    request.setUserIdentifier(userIdentifier);
    request.setPassword(password);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.createTakeOver(
        request,
        [callback](gs2::account::AsyncCreateTakeOverResult& r)
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

void Client::ListTakeOverSettings(
    std::function<void(AsyncEzListTakeOverSettingsResult&)> callback,
    GameSession& session,
    const Char* namespaceName,
    const Char* pageToken,
    gs2::optional<Int64> limit
)
{
    gs2::account::DescribeTakeOversRequest request;
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
    m_Client.describeTakeOvers(
        request,
        [callback](gs2::account::AsyncDescribeTakeOversResult& r)
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

void Client::UpdateTakeOverSetting(
    std::function<void(AsyncEzUpdateTakeOverSettingResult&)> callback,
    GameSession& session,
    const Char* namespaceName,
    Int32 type,
    const Char* oldPassword,
    const Char* password
)
{
    gs2::account::UpdateTakeOverRequest request;
    request.setNamespaceName(namespaceName);
    request.setType(type);
    request.setOldPassword(oldPassword);
    request.setPassword(password);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.updateTakeOver(
        request,
        [callback](gs2::account::AsyncUpdateTakeOverResult& r)
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

void Client::DeleteTakeOverSetting(
    std::function<void(AsyncEzDeleteTakeOverSettingResult&)> callback,
    GameSession& session,
    const Char* namespaceName,
    Int32 type
)
{
    gs2::account::DeleteTakeOverRequest request;
    request.setNamespaceName(namespaceName);
    request.setType(type);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.deleteTakeOver(
        request,
        [callback](gs2::account::AsyncDeleteTakeOverResult& r)
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

void Client::DoTakeOver(
    std::function<void(AsyncEzDoTakeOverResult&)> callback,
    const Char* namespaceName,
    Int32 type,
    const Char* userIdentifier,
    const Char* password
)
{
    gs2::account::DoTakeOverRequest request;
    request.setNamespaceName(namespaceName);
    request.setType(type);
    request.setUserIdentifier(userIdentifier);
    request.setPassword(password);
    m_Client.doTakeOver(
        request,
        [callback](gs2::account::AsyncDoTakeOverResult& r)
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