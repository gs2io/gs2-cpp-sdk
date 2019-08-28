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


namespace gs2 { namespace ez { namespace lock {

Client::Client(gs2::ez::Profile& profile) :
    m_Profile(profile),
    m_Client(profile.getGs2Session())
{
}

void Client::Lock(
    std::function<void(AsyncEzLockResult&)> callback,
    GameSession& session,
    const Char* namespaceName,
    const Char* propertyId,
    const Char* transactionId,
    Int64 ttl
)
{
    gs2::lock::LockRequest request;
    request.setNamespaceName(namespaceName);
    request.setPropertyId(propertyId);
    request.setTransactionId(transactionId);
    request.setTtl(ttl);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.lock(
        request,
        [callback](gs2::lock::AsyncLockResult& r)
        {
            if (r.getError())
            {
                EzLockResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzLockResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzLockResult::isConvertible(*r.getResult()))
                {
                    EzLockResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzLockResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzLockResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzLockResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

void Client::Unlock(
    std::function<void(AsyncEzUnlockResult&)> callback,
    GameSession& session,
    const Char* namespaceName,
    const Char* propertyId,
    const Char* transactionId
)
{
    gs2::lock::UnlockRequest request;
    request.setNamespaceName(namespaceName);
    request.setPropertyId(propertyId);
    request.setTransactionId(transactionId);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.unlock(
        request,
        [callback](gs2::lock::AsyncUnlockResult& r)
        {
            if (r.getError())
            {
                EzUnlockResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzUnlockResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzUnlockResult::isConvertible(*r.getResult()))
                {
                    EzUnlockResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzUnlockResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzUnlockResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzUnlockResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

}}}