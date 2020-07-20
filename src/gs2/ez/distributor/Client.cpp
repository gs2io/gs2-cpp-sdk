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


namespace gs2 { namespace ez { namespace distributor {

Client::Client(gs2::ez::Profile& profile) :
    m_Profile(profile),
    m_pClient(new gs2::distributor::Gs2DistributorWebSocketClient(profile.getGs2Session()))
{
}

Client::~Client()
{
    delete m_pClient;
}

void Client::listDistributorModels(
    std::function<void(AsyncEzListDistributorModelsResult)> callback,
    StringHolder namespaceName
)
{
    gs2::distributor::DescribeDistributorModelsRequest request;
    request.setNamespaceName(namespaceName);
    m_pClient->describeDistributorModels(
        request,
        [callback](gs2::distributor::AsyncDescribeDistributorModelsResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListDistributorModelsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzListDistributorModelsResult::isConvertible(*r.getResult()))
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
    m_pClient->getDistributorModel(
        request,
        [callback](gs2::distributor::AsyncGetDistributorModelResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetDistributorModelResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetDistributorModelResult::isConvertible(*r.getResult()))
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
    m_pClient->runStampTask(
        request,
        [callback](gs2::distributor::AsyncRunStampTaskResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzRunStampTaskResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzRunStampTaskResult::isConvertible(*r.getResult()))
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
    m_pClient->runStampSheet(
        request,
        [callback](gs2::distributor::AsyncRunStampSheetResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzRunStampSheetResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzRunStampSheetResult::isConvertible(*r.getResult()))
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

void Client::runOneShotStampSheet(
    std::function<void(AsyncEzRunOneShotStampSheetResult)> callback,
    StringHolder namespaceName,
    StringHolder stampSheet,
    StringHolder keyId
)
{
    gs2::distributor::RunRequest request;
    request.setNamespaceName(namespaceName);
    request.setStampSheet(stampSheet);
    request.setKeyId(keyId);
    m_pClient->run(
        request,
        [callback](gs2::distributor::AsyncRunResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzRunOneShotStampSheetResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzRunOneShotStampSheetResult::isConvertible(*r.getResult()))
            {
                EzRunOneShotStampSheetResult ezResult(*r.getResult());
                AsyncEzRunOneShotStampSheetResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzRunOneShotStampSheetResult asyncResult(std::move(gs2ClientException));
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
    m_pClient->runStampTaskWithoutNamespace(
        request,
        [callback](gs2::distributor::AsyncRunStampTaskWithoutNamespaceResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzRunStampTaskWithoutNamespaceResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzRunStampTaskWithoutNamespaceResult::isConvertible(*r.getResult()))
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
    m_pClient->runStampSheetWithoutNamespace(
        request,
        [callback](gs2::distributor::AsyncRunStampSheetWithoutNamespaceResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzRunStampSheetWithoutNamespaceResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzRunStampSheetWithoutNamespaceResult::isConvertible(*r.getResult()))
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

void Client::runOneShotStampSheetWithoutNamespace(
    std::function<void(AsyncEzRunOneShotStampSheetWithoutNamespaceResult)> callback,
    StringHolder stampSheet,
    StringHolder keyId
)
{
    gs2::distributor::RunWithoutNamespaceRequest request;
    request.setStampSheet(stampSheet);
    request.setKeyId(keyId);
    m_pClient->runWithoutNamespace(
        request,
        [callback](gs2::distributor::AsyncRunWithoutNamespaceResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzRunOneShotStampSheetWithoutNamespaceResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzRunOneShotStampSheetWithoutNamespaceResult::isConvertible(*r.getResult()))
            {
                EzRunOneShotStampSheetWithoutNamespaceResult ezResult(*r.getResult());
                AsyncEzRunOneShotStampSheetWithoutNamespaceResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzRunOneShotStampSheetWithoutNamespaceResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

}}}