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
#include <gs2/distributor/Gs2DistributorWebSocketClient.hpp>
#include <gs2/distributor/Gs2DistributorRestClient.hpp>


namespace gs2 { namespace ez { namespace distributor {

Client::Client(gs2::ez::Profile& profile) :
    m_Profile(profile),
    m_pWebSocketClient(new gs2::distributor::Gs2DistributorWebSocketClient(profile.getGs2WebSocketSession())),
    m_pRestClient(new gs2::distributor::Gs2DistributorRestClient(profile.getGs2RestSession()))
{
}

Client::~Client()
{
    delete m_pWebSocketClient;
    delete m_pRestClient;
}

void Client::listDistributorModels(
    std::function<void(AsyncEzListDistributorModelsResult)> callback,
    StringHolder namespaceName
)
{
    gs2::distributor::DescribeDistributorModelsRequest request;
    request.setNamespaceName(namespaceName);
    m_pRestClient->describeDistributorModels(
        request,
        [callback](gs2::distributor::AsyncDescribeDistributorModelsResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListDistributorModelsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
            {
                EzListDistributorModelsResult ezResult(*r.getResult());
                AsyncEzListDistributorModelsResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzListDistributorModelsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getDistributorModel(
    std::function<void(AsyncEzGetDistributorModelResult)> callback,
    StringHolder namespaceName,
    StringHolder distributorName
)
{
    gs2::distributor::GetDistributorModelRequest request;
    request.setNamespaceName(namespaceName);
    request.setDistributorName(distributorName);
    m_pWebSocketClient->getDistributorModel(
        request,
        [callback](gs2::distributor::AsyncGetDistributorModelResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetDistributorModelResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
            {
                EzGetDistributorModelResult ezResult(*r.getResult());
                AsyncEzGetDistributorModelResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetDistributorModelResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::runStampTask(
    std::function<void(AsyncEzRunStampTaskResult)> callback,
    StringHolder namespaceName,
    StringHolder stampTask,
    StringHolder keyId,
    gs2::optional<StringHolder> contextStack
)
{
    gs2::distributor::RunStampTaskRequest request;
    request.setNamespaceName(namespaceName);
    request.setStampTask(stampTask);
    request.setKeyId(keyId);
    if (contextStack)
    {
        request.setContextStack(std::move(*contextStack));
    }
    m_pRestClient->runStampTask(
        request,
        [callback](gs2::distributor::AsyncRunStampTaskResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzRunStampTaskResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
            {
                EzRunStampTaskResult ezResult(*r.getResult());
                AsyncEzRunStampTaskResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzRunStampTaskResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::runStampSheet(
    std::function<void(AsyncEzRunStampSheetResult)> callback,
    StringHolder namespaceName,
    StringHolder stampSheet,
    StringHolder keyId,
    gs2::optional<StringHolder> contextStack
)
{
    gs2::distributor::RunStampSheetRequest request;
    request.setNamespaceName(namespaceName);
    request.setStampSheet(stampSheet);
    request.setKeyId(keyId);
    if (contextStack)
    {
        request.setContextStack(std::move(*contextStack));
    }
    m_pRestClient->runStampSheet(
        request,
        [callback](gs2::distributor::AsyncRunStampSheetResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzRunStampSheetResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
            {
                EzRunStampSheetResult ezResult(*r.getResult());
                AsyncEzRunStampSheetResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzRunStampSheetResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::runStampSheetExpress(
    std::function<void(AsyncEzRunStampSheetExpressResult)> callback,
    StringHolder namespaceName,
    StringHolder stampSheet,
    StringHolder keyId
)
{
    gs2::distributor::RunStampSheetExpressRequest request;
    request.setNamespaceName(namespaceName);
    request.setStampSheet(stampSheet);
    request.setKeyId(keyId);
    m_pRestClient->runStampSheetExpress(
        request,
        [callback](gs2::distributor::AsyncRunStampSheetExpressResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzRunStampSheetExpressResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
            {
                EzRunStampSheetExpressResult ezResult(*r.getResult());
                AsyncEzRunStampSheetExpressResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzRunStampSheetExpressResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::runStampTaskWithoutNamespace(
    std::function<void(AsyncEzRunStampTaskWithoutNamespaceResult)> callback,
    StringHolder stampTask,
    StringHolder keyId,
    gs2::optional<StringHolder> contextStack
)
{
    gs2::distributor::RunStampTaskWithoutNamespaceRequest request;
    request.setStampTask(stampTask);
    request.setKeyId(keyId);
    if (contextStack)
    {
        request.setContextStack(std::move(*contextStack));
    }
    m_pRestClient->runStampTaskWithoutNamespace(
        request,
        [callback](gs2::distributor::AsyncRunStampTaskWithoutNamespaceResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzRunStampTaskWithoutNamespaceResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
            {
                EzRunStampTaskWithoutNamespaceResult ezResult(*r.getResult());
                AsyncEzRunStampTaskWithoutNamespaceResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzRunStampTaskWithoutNamespaceResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::runStampSheetWithoutNamespace(
    std::function<void(AsyncEzRunStampSheetWithoutNamespaceResult)> callback,
    StringHolder stampSheet,
    StringHolder keyId,
    gs2::optional<StringHolder> contextStack
)
{
    gs2::distributor::RunStampSheetWithoutNamespaceRequest request;
    request.setStampSheet(stampSheet);
    request.setKeyId(keyId);
    if (contextStack)
    {
        request.setContextStack(std::move(*contextStack));
    }
    m_pRestClient->runStampSheetWithoutNamespace(
        request,
        [callback](gs2::distributor::AsyncRunStampSheetWithoutNamespaceResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzRunStampSheetWithoutNamespaceResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
            {
                EzRunStampSheetWithoutNamespaceResult ezResult(*r.getResult());
                AsyncEzRunStampSheetWithoutNamespaceResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzRunStampSheetWithoutNamespaceResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::runStampSheetExpressWithoutNamespace(
    std::function<void(AsyncEzRunStampSheetExpressWithoutNamespaceResult)> callback,
    StringHolder stampSheet,
    StringHolder keyId
)
{
    gs2::distributor::RunStampSheetExpressWithoutNamespaceRequest request;
    request.setStampSheet(stampSheet);
    request.setKeyId(keyId);
    m_pRestClient->runStampSheetExpressWithoutNamespace(
        request,
        [callback](gs2::distributor::AsyncRunStampSheetExpressWithoutNamespaceResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzRunStampSheetExpressWithoutNamespaceResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
            {
                EzRunStampSheetExpressWithoutNamespaceResult ezResult(*r.getResult());
                AsyncEzRunStampSheetExpressWithoutNamespaceResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzRunStampSheetExpressWithoutNamespaceResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

}}}