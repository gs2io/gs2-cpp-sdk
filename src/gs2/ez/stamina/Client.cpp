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
#include <gs2/stamina/Gs2StaminaWebSocketClient.hpp>


namespace gs2 { namespace ez { namespace stamina {

Client::Client(gs2::ez::Profile& profile) :
    m_Profile(profile),
    m_pClient(new gs2::stamina::Gs2StaminaWebSocketClient(profile.getGs2Session()))
{
}

Client::~Client()
{
    delete m_pClient;
}

void Client::listStaminaModels(
    std::function<void(AsyncEzListStaminaModelsResult)> callback,
    StringHolder namespaceName
)
{
    gs2::stamina::DescribeStaminaModelsRequest request;
    request.setNamespaceName(namespaceName);
    m_pClient->describeStaminaModels(
        request,
        [callback](gs2::stamina::AsyncDescribeStaminaModelsResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListStaminaModelsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzListStaminaModelsResult::isConvertible(*r.getResult()))
            {
                EzListStaminaModelsResult ezResult(*r.getResult());
                AsyncEzListStaminaModelsResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzListStaminaModelsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getStaminaModel(
    std::function<void(AsyncEzGetStaminaModelResult)> callback,
    StringHolder namespaceName,
    StringHolder staminaName
)
{
    gs2::stamina::GetStaminaModelRequest request;
    request.setNamespaceName(namespaceName);
    request.setStaminaName(staminaName);
    m_pClient->getStaminaModel(
        request,
        [callback](gs2::stamina::AsyncGetStaminaModelResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetStaminaModelResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetStaminaModelResult::isConvertible(*r.getResult()))
            {
                EzGetStaminaModelResult ezResult(*r.getResult());
                AsyncEzGetStaminaModelResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetStaminaModelResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getStamina(
    std::function<void(AsyncEzGetStaminaResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder staminaName
)
{
    gs2::stamina::GetStaminaRequest request;
    request.setNamespaceName(namespaceName);
    request.setStaminaName(staminaName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pClient->getStamina(
        request,
        [callback](gs2::stamina::AsyncGetStaminaResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetStaminaResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetStaminaResult::isConvertible(*r.getResult()))
            {
                EzGetStaminaResult ezResult(*r.getResult());
                AsyncEzGetStaminaResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetStaminaResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::consume(
    std::function<void(AsyncEzConsumeResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder staminaName,
    Int32 consumeValue
)
{
    gs2::stamina::ConsumeStaminaRequest request;
    request.setNamespaceName(namespaceName);
    request.setStaminaName(staminaName);
    request.setConsumeValue(consumeValue);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pClient->consumeStamina(
        request,
        [callback](gs2::stamina::AsyncConsumeStaminaResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzConsumeResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzConsumeResult::isConvertible(*r.getResult()))
            {
                EzConsumeResult ezResult(*r.getResult());
                AsyncEzConsumeResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzConsumeResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

}}}