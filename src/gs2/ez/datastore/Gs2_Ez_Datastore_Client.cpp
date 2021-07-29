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
#include <gs2/datastore/Gs2DatastoreWebSocketClient.hpp>
#include <gs2/datastore/Gs2DatastoreRestClient.hpp>


namespace gs2 { namespace ez { namespace datastore {

Client::Client(gs2::ez::Profile& profile) :
    m_Profile(profile),
    m_pWebSocketClient(new gs2::datastore::Gs2DatastoreWebSocketClient(profile.getGs2WebSocketSession())),
    m_pRestClient(new gs2::datastore::Gs2DatastoreRestClient(profile.getGs2RestSession()))
{
}

Client::~Client()
{
    delete m_pWebSocketClient;
    delete m_pRestClient;
}

void Client::listMyDataObjects(
    std::function<void(AsyncEzListMyDataObjectsResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    gs2::optional<StringHolder> status,
    gs2::optional<StringHolder> pageToken,
    gs2::optional<Int64> limit
)
{
    gs2::datastore::DescribeDataObjectsRequest request;
    request.setNamespaceName(namespaceName);
    if (status)
    {
        request.setStatus(std::move(*status));
    }
    if (pageToken)
    {
        request.setPageToken(std::move(*pageToken));
    }
    if (limit)
    {
        request.setLimit(std::move(*limit));
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pRestClient->describeDataObjects(
        request,
        [callback](gs2::datastore::AsyncDescribeDataObjectsResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListMyDataObjectsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
            {
                EzListMyDataObjectsResult ezResult(*r.getResult());
                AsyncEzListMyDataObjectsResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzListMyDataObjectsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::updateDataObject(
    std::function<void(AsyncEzUpdateDataObjectResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder scope,
    List<StringHolder> allowUserIds
)
{
    gs2::datastore::UpdateDataObjectRequest request;
    request.setNamespaceName(namespaceName);
    request.setScope(scope);
    request.setAllowUserIds(allowUserIds);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pWebSocketClient->updateDataObject(
        request,
        [callback](gs2::datastore::AsyncUpdateDataObjectResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzUpdateDataObjectResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
            {
                EzUpdateDataObjectResult ezResult(*r.getResult());
                AsyncEzUpdateDataObjectResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzUpdateDataObjectResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::prepareUpload(
    std::function<void(AsyncEzPrepareUploadResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder scope,
    List<StringHolder> allowUserIds,
    gs2::optional<StringHolder> name,
    gs2::optional<Bool> updateIfExists
)
{
    gs2::datastore::PrepareUploadRequest request;
    request.setNamespaceName(namespaceName);
    request.setScope(scope);
    request.setAllowUserIds(allowUserIds);
    if (name)
    {
        request.setName(std::move(*name));
    }
    if (updateIfExists)
    {
        request.setUpdateIfExists(std::move(*updateIfExists));
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pWebSocketClient->prepareUpload(
        request,
        [callback](gs2::datastore::AsyncPrepareUploadResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzPrepareUploadResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
            {
                EzPrepareUploadResult ezResult(*r.getResult());
                AsyncEzPrepareUploadResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzPrepareUploadResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::prepareReUpload(
    std::function<void(AsyncEzPrepareReUploadResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder dataObjectName
)
{
    gs2::datastore::PrepareReUploadRequest request;
    request.setNamespaceName(namespaceName);
    request.setDataObjectName(dataObjectName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pWebSocketClient->prepareReUpload(
        request,
        [callback](gs2::datastore::AsyncPrepareReUploadResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzPrepareReUploadResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
            {
                EzPrepareReUploadResult ezResult(*r.getResult());
                AsyncEzPrepareReUploadResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzPrepareReUploadResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::doneUpload(
    std::function<void(AsyncEzDoneUploadResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder dataObjectName
)
{
    gs2::datastore::DoneUploadRequest request;
    request.setNamespaceName(namespaceName);
    request.setDataObjectName(dataObjectName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pWebSocketClient->doneUpload(
        request,
        [callback](gs2::datastore::AsyncDoneUploadResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzDoneUploadResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
            {
                EzDoneUploadResult ezResult(*r.getResult());
                AsyncEzDoneUploadResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzDoneUploadResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::prepareDownload(
    std::function<void(AsyncEzPrepareDownloadResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder dataObjectId
)
{
    gs2::datastore::PrepareDownloadRequest request;
    request.setNamespaceName(namespaceName);
    request.setDataObjectId(dataObjectId);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pWebSocketClient->prepareDownload(
        request,
        [callback](gs2::datastore::AsyncPrepareDownloadResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzPrepareDownloadResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
            {
                EzPrepareDownloadResult ezResult(*r.getResult());
                AsyncEzPrepareDownloadResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzPrepareDownloadResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::prepareDownloadOwnData(
    std::function<void(AsyncEzPrepareDownloadOwnDataResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder dataObjectName
)
{
    gs2::datastore::PrepareDownloadOwnDataRequest request;
    request.setNamespaceName(namespaceName);
    request.setDataObjectName(dataObjectName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pWebSocketClient->prepareDownloadOwnData(
        request,
        [callback](gs2::datastore::AsyncPrepareDownloadOwnDataResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzPrepareDownloadOwnDataResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
            {
                EzPrepareDownloadOwnDataResult ezResult(*r.getResult());
                AsyncEzPrepareDownloadOwnDataResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzPrepareDownloadOwnDataResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::prepareDownloadByUserIdAndDataObjectName(
    std::function<void(AsyncEzPrepareDownloadByUserIdAndDataObjectNameResult)> callback,
    StringHolder namespaceName,
    StringHolder userId,
    StringHolder dataObjectName
)
{
    gs2::datastore::PrepareDownloadByUserIdAndDataObjectNameRequest request;
    request.setNamespaceName(namespaceName);
    request.setUserId(userId);
    request.setDataObjectName(dataObjectName);
    m_pWebSocketClient->prepareDownloadByUserIdAndDataObjectName(
        request,
        [callback](gs2::datastore::AsyncPrepareDownloadByUserIdAndDataObjectNameResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzPrepareDownloadByUserIdAndDataObjectNameResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
            {
                EzPrepareDownloadByUserIdAndDataObjectNameResult ezResult(*r.getResult());
                AsyncEzPrepareDownloadByUserIdAndDataObjectNameResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzPrepareDownloadByUserIdAndDataObjectNameResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::deleteDataObject(
    std::function<void(AsyncEzDeleteDataObjectResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder dataObjectName
)
{
    gs2::datastore::DeleteDataObjectRequest request;
    request.setNamespaceName(namespaceName);
    request.setDataObjectName(dataObjectName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pWebSocketClient->deleteDataObject(
        request,
        [callback](gs2::datastore::AsyncDeleteDataObjectResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzDeleteDataObjectResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
            {
                EzDeleteDataObjectResult ezResult(*r.getResult());
                AsyncEzDeleteDataObjectResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzDeleteDataObjectResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::restoreDataObject(
    std::function<void(AsyncEzRestoreDataObjectResult)> callback,
    StringHolder namespaceName,
    StringHolder dataObjectId
)
{
    gs2::datastore::RestoreDataObjectRequest request;
    request.setNamespaceName(namespaceName);
    request.setDataObjectId(dataObjectId);
    m_pWebSocketClient->restoreDataObject(
        request,
        [callback](gs2::datastore::AsyncRestoreDataObjectResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzRestoreDataObjectResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
            {
                EzRestoreDataObjectResult ezResult(*r.getResult());
                AsyncEzRestoreDataObjectResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzRestoreDataObjectResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::listDataObhectHistories(
    std::function<void(AsyncEzListDataObhectHistoriesResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder dataObjectName,
    gs2::optional<StringHolder> pageToken,
    gs2::optional<Int64> limit
)
{
    gs2::datastore::DescribeDataObjectHistoriesRequest request;
    request.setNamespaceName(namespaceName);
    request.setDataObjectName(dataObjectName);
    if (pageToken)
    {
        request.setPageToken(std::move(*pageToken));
    }
    if (limit)
    {
        request.setLimit(std::move(*limit));
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pRestClient->describeDataObjectHistories(
        request,
        [callback](gs2::datastore::AsyncDescribeDataObjectHistoriesResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListDataObhectHistoriesResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult())
            {
                EzListDataObhectHistoriesResult ezResult(*r.getResult());
                AsyncEzListDataObhectHistoriesResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzListDataObhectHistoriesResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

}}}