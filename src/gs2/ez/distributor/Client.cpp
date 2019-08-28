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


namespace gs2 { namespace ez { namespace distributor {

Client::Client(gs2::ez::Profile& profile) :
    m_Profile(profile),
    m_Client(profile.getGs2Session())
{
}

void Client::ListDistributorModels(
    std::function<void(AsyncEzListDistributorModelsResult&)> callback,
    const Char* namespaceName
)
{
    gs2::distributor::DescribeDistributorModelsRequest request;
    request.setNamespaceName(namespaceName);
    m_Client.describeDistributorModels(
        request,
        [callback](gs2::distributor::AsyncDescribeDistributorModelsResult& r)
        {
            if (r.getError())
            {
                EzListDistributorModelsResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzListDistributorModelsResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzListDistributorModelsResult::isConvertible(*r.getResult()))
                {
                    EzListDistributorModelsResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzListDistributorModelsResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzListDistributorModelsResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzListDistributorModelsResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

void Client::GetDistributorModel(
    std::function<void(AsyncEzGetDistributorModelResult&)> callback,
    const Char* namespaceName,
    const Char* distributorName
)
{
    gs2::distributor::GetDistributorModelRequest request;
    request.setNamespaceName(namespaceName);
    request.setDistributorName(distributorName);
    m_Client.getDistributorModel(
        request,
        [callback](gs2::distributor::AsyncGetDistributorModelResult& r)
        {
            if (r.getError())
            {
                EzGetDistributorModelResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzGetDistributorModelResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzGetDistributorModelResult::isConvertible(*r.getResult()))
                {
                    EzGetDistributorModelResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzGetDistributorModelResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzGetDistributorModelResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzGetDistributorModelResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

void Client::RunStampTask(
    std::function<void(AsyncEzRunStampTaskResult&)> callback,
    const Char* namespaceName,
    const Char* distributorName,
    const Char* stampTask,
    const Char* keyId,
    const Char* contextStack
)
{
    gs2::distributor::RunStampTaskRequest request;
    request.setNamespaceName(namespaceName);
    request.setDistributorName(distributorName);
    request.setStampTask(stampTask);
    request.setKeyId(keyId);
    if (contextStack)
    {
        request.setContextStack(contextStack);
    }
    m_Client.runStampTask(
        request,
        [callback](gs2::distributor::AsyncRunStampTaskResult& r)
        {
            if (r.getError())
            {
                EzRunStampTaskResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzRunStampTaskResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzRunStampTaskResult::isConvertible(*r.getResult()))
                {
                    EzRunStampTaskResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzRunStampTaskResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzRunStampTaskResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzRunStampTaskResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

void Client::RunStampSheet(
    std::function<void(AsyncEzRunStampSheetResult&)> callback,
    const Char* namespaceName,
    const Char* distributorName,
    const Char* stampSheet,
    const Char* keyId,
    const Char* contextStack
)
{
    gs2::distributor::RunStampSheetRequest request;
    request.setNamespaceName(namespaceName);
    request.setDistributorName(distributorName);
    request.setStampSheet(stampSheet);
    request.setKeyId(keyId);
    if (contextStack)
    {
        request.setContextStack(contextStack);
    }
    m_Client.runStampSheet(
        request,
        [callback](gs2::distributor::AsyncRunStampSheetResult& r)
        {
            if (r.getError())
            {
                EzRunStampSheetResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzRunStampSheetResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzRunStampSheetResult::isConvertible(*r.getResult()))
                {
                    EzRunStampSheetResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzRunStampSheetResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzRunStampSheetResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzRunStampSheetResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

}}}