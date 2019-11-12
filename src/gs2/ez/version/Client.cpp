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


namespace gs2 { namespace ez { namespace version {

Client::Client(gs2::ez::Profile& profile) :
    m_Profile(profile),
    m_Client(profile.getGs2Session())
{
}

void Client::listVersionModels(
    std::function<void(AsyncEzListVersionModelsResult)> callback,
    StringHolder namespaceName
)
{
    gs2::version::DescribeVersionModelsRequest request;
    request.setNamespaceName(namespaceName);
    m_Client.describeVersionModels(
        request,
        [callback](gs2::version::AsyncDescribeVersionModelsResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListVersionModelsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzListVersionModelsResult::isConvertible(*r.getResult()))
            {
                EzListVersionModelsResult ezResult(*r.getResult());
                AsyncEzListVersionModelsResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzListVersionModelsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getVersionModel(
    std::function<void(AsyncEzGetVersionModelResult)> callback,
    StringHolder namespaceName,
    StringHolder versionName
)
{
    gs2::version::GetVersionModelRequest request;
    request.setNamespaceName(namespaceName);
    request.setVersionName(versionName);
    m_Client.getVersionModel(
        request,
        [callback](gs2::version::AsyncGetVersionModelResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetVersionModelResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetVersionModelResult::isConvertible(*r.getResult()))
            {
                EzGetVersionModelResult ezResult(*r.getResult());
                AsyncEzGetVersionModelResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetVersionModelResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::list(
    std::function<void(AsyncEzListResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    gs2::optional<StringHolder> pageToken,
    gs2::optional<Int64> limit
)
{
    gs2::version::DescribeAcceptVersionsRequest request;
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
    m_Client.describeAcceptVersions(
        request,
        [callback](gs2::version::AsyncDescribeAcceptVersionsResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzListResult::isConvertible(*r.getResult()))
            {
                EzListResult ezResult(*r.getResult());
                AsyncEzListResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzListResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::delete_(
    std::function<void(AsyncEzDeleteResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder versionName
)
{
    gs2::version::DeleteAcceptVersionRequest request;
    request.setNamespaceName(namespaceName);
    request.setVersionName(versionName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.deleteAcceptVersion(
        request,
        [callback](gs2::version::AsyncDeleteAcceptVersionResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzDeleteResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else
            {
                AsyncEzDeleteResult asyncResult;
                callback(asyncResult);
            }
        }
    );
}

void Client::checkVersion(
    std::function<void(AsyncEzCheckVersionResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    gs2::optional<List<EzTargetVersion>> targetVersions
)
{
    gs2::version::CheckVersionRequest request;
    request.setNamespaceName(namespaceName);
    if (targetVersions)
    {
        gs2::List<gs2::version::TargetVersion> list;
        for (int i = 0; i < targetVersions->getCount(); ++i)
        {
            list += (*targetVersions)[i].ToModel();
        }
        request.setTargetVersions(list);
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.checkVersion(
        request,
        [callback](gs2::version::AsyncCheckVersionResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzCheckVersionResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzCheckVersionResult::isConvertible(*r.getResult()))
            {
                EzCheckVersionResult ezResult(*r.getResult());
                AsyncEzCheckVersionResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzCheckVersionResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

}}}