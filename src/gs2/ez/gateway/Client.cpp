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


namespace gs2 { namespace ez { namespace gateway {

Client::Client(gs2::ez::Profile& profile) :
    m_Profile(profile),
    m_Client(profile.getGs2Session())
{
}

void Client::SetUserId(
    std::function<void(AsyncEzSetUserIdResult&)> callback,
    GameSession& session,
    const Char* namespaceName,
    Bool allowConcurrentAccess
)
{
    gs2::gateway::SetUserIdRequest request;
    request.setNamespaceName(namespaceName);
    request.setAllowConcurrentAccess(allowConcurrentAccess);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.setUserId(
        request,
        [callback](gs2::gateway::AsyncSetUserIdResult& r)
        {
            if (r.getError())
            {
                EzSetUserIdResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzSetUserIdResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzSetUserIdResult::isConvertible(*r.getResult()))
                {
                    EzSetUserIdResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzSetUserIdResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzSetUserIdResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzSetUserIdResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

}}}