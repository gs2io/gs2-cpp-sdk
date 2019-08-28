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


namespace gs2 { namespace ez { namespace stamina {

Client::Client(gs2::ez::Profile& profile) :
    m_Profile(profile),
    m_Client(profile.getGs2Session())
{
}

void Client::ListStaminaModels(
    std::function<void(AsyncEzListStaminaModelsResult&)> callback,
    const Char* namespaceName
)
{
    gs2::stamina::DescribeStaminaModelsRequest request;
    request.setNamespaceName(namespaceName);
    m_Client.describeStaminaModels(
        request,
        [callback](gs2::stamina::AsyncDescribeStaminaModelsResult& r)
        {
            if (r.getError())
            {
                EzListStaminaModelsResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzListStaminaModelsResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzListStaminaModelsResult::isConvertible(*r.getResult()))
                {
                    EzListStaminaModelsResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzListStaminaModelsResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzListStaminaModelsResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzListStaminaModelsResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

void Client::GetStaminaModel(
    std::function<void(AsyncEzGetStaminaModelResult&)> callback,
    const Char* namespaceName,
    const Char* staminaName
)
{
    gs2::stamina::GetStaminaModelRequest request;
    request.setNamespaceName(namespaceName);
    request.setStaminaName(staminaName);
    m_Client.getStaminaModel(
        request,
        [callback](gs2::stamina::AsyncGetStaminaModelResult& r)
        {
            if (r.getError())
            {
                EzGetStaminaModelResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzGetStaminaModelResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzGetStaminaModelResult::isConvertible(*r.getResult()))
                {
                    EzGetStaminaModelResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzGetStaminaModelResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzGetStaminaModelResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzGetStaminaModelResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

void Client::GetStamina(
    std::function<void(AsyncEzGetStaminaResult&)> callback,
    GameSession& session,
    const Char* namespaceName,
    const Char* staminaName
)
{
    gs2::stamina::GetStaminaRequest request;
    request.setNamespaceName(namespaceName);
    request.setStaminaName(staminaName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.getStamina(
        request,
        [callback](gs2::stamina::AsyncGetStaminaResult& r)
        {
            if (r.getError())
            {
                EzGetStaminaResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzGetStaminaResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzGetStaminaResult::isConvertible(*r.getResult()))
                {
                    EzGetStaminaResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzGetStaminaResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzGetStaminaResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzGetStaminaResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

void Client::Consume(
    std::function<void(AsyncEzConsumeResult&)> callback,
    GameSession& session,
    const Char* namespaceName,
    const Char* staminaName,
    Int32 consumeValue
)
{
    gs2::stamina::ConsumeStaminaRequest request;
    request.setNamespaceName(namespaceName);
    request.setStaminaName(staminaName);
    request.setConsumeValue(consumeValue);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.consumeStamina(
        request,
        [callback](gs2::stamina::AsyncConsumeStaminaResult& r)
        {
            if (r.getError())
            {
                EzConsumeResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzConsumeResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzConsumeResult::isConvertible(*r.getResult()))
                {
                    EzConsumeResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzConsumeResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzConsumeResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzConsumeResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

}}}