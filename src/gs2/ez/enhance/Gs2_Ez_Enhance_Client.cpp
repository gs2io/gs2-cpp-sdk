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
#include <gs2/enhance/Gs2EnhanceWebSocketClient.hpp>
#include <gs2/enhance/Gs2EnhanceRestClient.hpp>


namespace gs2 { namespace ez { namespace enhance {

Client::Client(gs2::ez::Profile& profile) :
    m_Profile(profile),
    m_pWebSocketClient(new gs2::enhance::Gs2EnhanceWebSocketClient(profile.getGs2WebSocketSession())),
    m_pRestClient(new gs2::enhance::Gs2EnhanceRestClient(profile.getGs2RestSession()))
{
}

Client::~Client()
{
    delete m_pWebSocketClient;
    delete m_pRestClient;
}

void Client::listRateModels(
    std::function<void(AsyncEzListRateModelsResult)> callback,
    StringHolder namespaceName
)
{
    gs2::enhance::DescribeRateModelsRequest request;
    request.setNamespaceName(namespaceName);
    m_pRestClient->describeRateModels(
        request,
        [callback](gs2::enhance::AsyncDescribeRateModelsResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListRateModelsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzListRateModelsResult::isConvertible(*r.getResult()))
            {
                EzListRateModelsResult ezResult(*r.getResult());
                AsyncEzListRateModelsResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzListRateModelsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getRateModel(
    std::function<void(AsyncEzGetRateModelResult)> callback,
    StringHolder namespaceName,
    StringHolder rateName
)
{
    gs2::enhance::GetRateModelRequest request;
    request.setNamespaceName(namespaceName);
    request.setRateName(rateName);
    m_pWebSocketClient->getRateModel(
        request,
        [callback](gs2::enhance::AsyncGetRateModelResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetRateModelResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetRateModelResult::isConvertible(*r.getResult()))
            {
                EzGetRateModelResult ezResult(*r.getResult());
                AsyncEzGetRateModelResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetRateModelResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::enhance(
    std::function<void(AsyncEzEnhanceResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder rateName,
    StringHolder targetItemSetId,
    List<EzMaterial> materials,
    gs2::optional<List<EzConfig>> config
)
{
    gs2::enhance::DirectEnhanceRequest request;
    request.setNamespaceName(namespaceName);
    request.setRateName(rateName);
    request.setTargetItemSetId(targetItemSetId);
    {
        gs2::List<gs2::enhance::Material> list;
        for (int i = 0; i < materials.getCount(); ++i)
        {
            list += materials[i].ToModel();
        }
        request.setMaterials(list);
    }
    if (config)
    {
        gs2::List<gs2::enhance::Config> list;
        for (int i = 0; i < config->getCount(); ++i)
        {
            list += (*config)[i].ToModel();
        }
        request.setConfig(list);
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pRestClient->directEnhance(
        request,
        [callback](gs2::enhance::AsyncDirectEnhanceResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzEnhanceResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzEnhanceResult::isConvertible(*r.getResult()))
            {
                EzEnhanceResult ezResult(*r.getResult());
                AsyncEzEnhanceResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzEnhanceResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::start(
    std::function<void(AsyncEzStartResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder rateName,
    StringHolder targetItemSetId,
    List<EzMaterial> materials,
    gs2::optional<Bool> force,
    gs2::optional<List<EzConfig>> config
)
{
    gs2::enhance::StartRequest request;
    request.setNamespaceName(namespaceName);
    request.setRateName(rateName);
    request.setTargetItemSetId(targetItemSetId);
    {
        gs2::List<gs2::enhance::Material> list;
        for (int i = 0; i < materials.getCount(); ++i)
        {
            list += materials[i].ToModel();
        }
        request.setMaterials(list);
    }
    if (force)
    {
        request.setForce(std::move(*force));
    }
    if (config)
    {
        gs2::List<gs2::enhance::Config> list;
        for (int i = 0; i < config->getCount(); ++i)
        {
            list += (*config)[i].ToModel();
        }
        request.setConfig(list);
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pRestClient->start(
        request,
        [callback](gs2::enhance::AsyncStartResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzStartResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzStartResult::isConvertible(*r.getResult()))
            {
                EzStartResult ezResult(*r.getResult());
                AsyncEzStartResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzStartResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::end(
    std::function<void(AsyncEzEndResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    gs2::optional<List<EzConfig>> config
)
{
    gs2::enhance::EndRequest request;
    request.setNamespaceName(namespaceName);
    if (config)
    {
        gs2::List<gs2::enhance::Config> list;
        for (int i = 0; i < config->getCount(); ++i)
        {
            list += (*config)[i].ToModel();
        }
        request.setConfig(list);
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pRestClient->end(
        request,
        [callback](gs2::enhance::AsyncEndResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzEndResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzEndResult::isConvertible(*r.getResult()))
            {
                EzEndResult ezResult(*r.getResult());
                AsyncEzEndResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzEndResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getProgress(
    std::function<void(AsyncEzGetProgressResult)> callback,
    GameSession& session,
    StringHolder namespaceName
)
{
    gs2::enhance::GetProgressRequest request;
    request.setNamespaceName(namespaceName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pWebSocketClient->getProgress(
        request,
        [callback](gs2::enhance::AsyncGetProgressResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetProgressResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetProgressResult::isConvertible(*r.getResult()))
            {
                EzGetProgressResult ezResult(*r.getResult());
                AsyncEzGetProgressResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetProgressResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::deleteProgress(
    std::function<void(AsyncEzDeleteProgressResult)> callback,
    GameSession& session,
    StringHolder namespaceName
)
{
    gs2::enhance::DeleteProgressRequest request;
    request.setNamespaceName(namespaceName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pWebSocketClient->deleteProgress(
        request,
        [callback](gs2::enhance::AsyncDeleteProgressResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzDeleteProgressResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzDeleteProgressResult::isConvertible(*r.getResult()))
            {
                EzDeleteProgressResult ezResult(*r.getResult());
                AsyncEzDeleteProgressResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzDeleteProgressResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

}}}