/*
 * Copyright 2016 Game Server Services, Inc. or its affiliates. All Rights
 * Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
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

#ifndef GS2_DATASTORE_GS2DATASTOREWEBSOCKETCLIENT_HPP_
#define GS2_DATASTORE_GS2DATASTOREWEBSOCKETCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2WebSocketSessionTask.hpp>
#include <gs2/core/network/Gs2WebSocketSession.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include "model/model.hpp"
#include "request/DescribeNamespacesRequest.hpp"
#include "request/CreateNamespaceRequest.hpp"
#include "request/GetNamespaceStatusRequest.hpp"
#include "request/GetNamespaceRequest.hpp"
#include "request/UpdateNamespaceRequest.hpp"
#include "request/DeleteNamespaceRequest.hpp"
#include "request/DescribeDataObjectsRequest.hpp"
#include "request/DescribeDataObjectsByUserIdRequest.hpp"
#include "request/PrepareUploadRequest.hpp"
#include "request/PrepareUploadByUserIdRequest.hpp"
#include "request/UpdateDataObjectRequest.hpp"
#include "request/UpdateDataObjectByUserIdRequest.hpp"
#include "request/PrepareReUploadRequest.hpp"
#include "request/PrepareReUploadByUserIdRequest.hpp"
#include "request/DoneUploadRequest.hpp"
#include "request/DoneUploadByUserIdRequest.hpp"
#include "request/DeleteDataObjectRequest.hpp"
#include "request/DeleteDataObjectByUserIdRequest.hpp"
#include "request/PrepareDownloadRequest.hpp"
#include "request/PrepareDownloadByUserIdRequest.hpp"
#include "request/PrepareDownloadByGenerationRequest.hpp"
#include "request/PrepareDownloadByGenerationAndUserIdRequest.hpp"
#include "request/PrepareDownloadOwnDataRequest.hpp"
#include "request/PrepareDownloadOwnDataByGenerationRequest.hpp"
#include "request/PrepareDownloadOwnDataByGenerationAndUserIdRequest.hpp"
#include "request/DescribeDataObjectHistoriesRequest.hpp"
#include "request/DescribeDataObjectHistoriesByUserIdRequest.hpp"
#include "request/GetDataObjectHistoryRequest.hpp"
#include "request/GetDataObjectHistoryByUserIdRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeDataObjectsResult.hpp"
#include "result/DescribeDataObjectsByUserIdResult.hpp"
#include "result/PrepareUploadResult.hpp"
#include "result/PrepareUploadByUserIdResult.hpp"
#include "result/UpdateDataObjectResult.hpp"
#include "result/UpdateDataObjectByUserIdResult.hpp"
#include "result/PrepareReUploadResult.hpp"
#include "result/PrepareReUploadByUserIdResult.hpp"
#include "result/DoneUploadResult.hpp"
#include "result/DoneUploadByUserIdResult.hpp"
#include "result/DeleteDataObjectResult.hpp"
#include "result/DeleteDataObjectByUserIdResult.hpp"
#include "result/PrepareDownloadResult.hpp"
#include "result/PrepareDownloadByUserIdResult.hpp"
#include "result/PrepareDownloadByGenerationResult.hpp"
#include "result/PrepareDownloadByGenerationAndUserIdResult.hpp"
#include "result/PrepareDownloadOwnDataResult.hpp"
#include "result/PrepareDownloadOwnDataByGenerationResult.hpp"
#include "result/PrepareDownloadOwnDataByGenerationAndUserIdResult.hpp"
#include "result/DescribeDataObjectHistoriesResult.hpp"
#include "result/DescribeDataObjectHistoriesByUserIdResult.hpp"
#include "result/GetDataObjectHistoryResult.hpp"
#include "result/GetDataObjectHistoryByUserIdResult.hpp"
#include <cstring>

namespace gs2 { namespace datastore {

/**
 * GS2 Datastore API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2DatastoreWebSocketClient : public AbstractGs2ClientBase
{
private:

    class DescribeNamespacesTask : public detail::Gs2WebSocketSessionTask<DescribeNamespacesResult>
    {
    private:
        DescribeNamespacesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "namespace";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeNamespaces";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getPageToken())
            {
                jsonWriter.writePropertyName("pageToken");
                jsonWriter.writeCharArray(*m_Request.getPageToken());
            }
            if (m_Request.getLimit())
            {
                jsonWriter.writePropertyName("limit");
                jsonWriter.writeInt64(*m_Request.getLimit());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        DescribeNamespacesTask(
            DescribeNamespacesRequest request,
            Gs2WebSocketSessionTask<DescribeNamespacesResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeNamespacesResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeNamespacesTask() GS2_OVERRIDE = default;
    };

    class CreateNamespaceTask : public detail::Gs2WebSocketSessionTask<CreateNamespaceResult>
    {
    private:
        CreateNamespaceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "namespace";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "createNamespace";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getName())
            {
                jsonWriter.writePropertyName("name");
                jsonWriter.writeCharArray(*m_Request.getName());
            }
            if (m_Request.getDescription())
            {
                jsonWriter.writePropertyName("description");
                jsonWriter.writeCharArray(*m_Request.getDescription());
            }
            if (m_Request.getLogSetting())
            {
                jsonWriter.writePropertyName("logSetting");
                write(jsonWriter, *m_Request.getLogSetting());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        CreateNamespaceTask(
            CreateNamespaceRequest request,
            Gs2WebSocketSessionTask<CreateNamespaceResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateNamespaceResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateNamespaceTask() GS2_OVERRIDE = default;
    };

    class GetNamespaceStatusTask : public detail::Gs2WebSocketSessionTask<GetNamespaceStatusResult>
    {
    private:
        GetNamespaceStatusRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "namespace";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getNamespaceStatus";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetNamespaceStatusTask(
            GetNamespaceStatusRequest request,
            Gs2WebSocketSessionTask<GetNamespaceStatusResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetNamespaceStatusResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetNamespaceStatusTask() GS2_OVERRIDE = default;
    };

    class GetNamespaceTask : public detail::Gs2WebSocketSessionTask<GetNamespaceResult>
    {
    private:
        GetNamespaceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "namespace";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getNamespace";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetNamespaceTask(
            GetNamespaceRequest request,
            Gs2WebSocketSessionTask<GetNamespaceResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetNamespaceResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetNamespaceTask() GS2_OVERRIDE = default;
    };

    class UpdateNamespaceTask : public detail::Gs2WebSocketSessionTask<UpdateNamespaceResult>
    {
    private:
        UpdateNamespaceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "namespace";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateNamespace";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getDescription())
            {
                jsonWriter.writePropertyName("description");
                jsonWriter.writeCharArray(*m_Request.getDescription());
            }
            if (m_Request.getLogSetting())
            {
                jsonWriter.writePropertyName("logSetting");
                write(jsonWriter, *m_Request.getLogSetting());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        UpdateNamespaceTask(
            UpdateNamespaceRequest request,
            Gs2WebSocketSessionTask<UpdateNamespaceResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateNamespaceResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateNamespaceTask() GS2_OVERRIDE = default;
    };

    class DeleteNamespaceTask : public detail::Gs2WebSocketSessionTask<DeleteNamespaceResult>
    {
    private:
        DeleteNamespaceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "namespace";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteNamespace";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        DeleteNamespaceTask(
            DeleteNamespaceRequest request,
            Gs2WebSocketSessionTask<DeleteNamespaceResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteNamespaceResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteNamespaceTask() GS2_OVERRIDE = default;
    };

    class DescribeDataObjectsTask : public detail::Gs2WebSocketSessionTask<DescribeDataObjectsResult>
    {
    private:
        DescribeDataObjectsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "dataObject";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeDataObjects";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getStatus())
            {
                jsonWriter.writePropertyName("status");
                jsonWriter.writeCharArray(*m_Request.getStatus());
            }
            if (m_Request.getPageToken())
            {
                jsonWriter.writePropertyName("pageToken");
                jsonWriter.writeCharArray(*m_Request.getPageToken());
            }
            if (m_Request.getLimit())
            {
                jsonWriter.writePropertyName("limit");
                jsonWriter.writeInt64(*m_Request.getLimit());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                jsonWriter.writePropertyName("xGs2AccessToken");
                jsonWriter.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        DescribeDataObjectsTask(
            DescribeDataObjectsRequest request,
            Gs2WebSocketSessionTask<DescribeDataObjectsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeDataObjectsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeDataObjectsTask() GS2_OVERRIDE = default;
    };

    class DescribeDataObjectsByUserIdTask : public detail::Gs2WebSocketSessionTask<DescribeDataObjectsByUserIdResult>
    {
    private:
        DescribeDataObjectsByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "dataObject";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeDataObjectsByUserId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getStatus())
            {
                jsonWriter.writePropertyName("status");
                jsonWriter.writeCharArray(*m_Request.getStatus());
            }
            if (m_Request.getPageToken())
            {
                jsonWriter.writePropertyName("pageToken");
                jsonWriter.writeCharArray(*m_Request.getPageToken());
            }
            if (m_Request.getLimit())
            {
                jsonWriter.writePropertyName("limit");
                jsonWriter.writeInt64(*m_Request.getLimit());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        DescribeDataObjectsByUserIdTask(
            DescribeDataObjectsByUserIdRequest request,
            Gs2WebSocketSessionTask<DescribeDataObjectsByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeDataObjectsByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeDataObjectsByUserIdTask() GS2_OVERRIDE = default;
    };

    class PrepareUploadTask : public detail::Gs2WebSocketSessionTask<PrepareUploadResult>
    {
    private:
        PrepareUploadRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "dataObject";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "prepareUpload";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getName())
            {
                jsonWriter.writePropertyName("name");
                jsonWriter.writeCharArray(*m_Request.getName());
            }
            if (m_Request.getContentType())
            {
                jsonWriter.writePropertyName("contentType");
                jsonWriter.writeCharArray(*m_Request.getContentType());
            }
            if (m_Request.getScope())
            {
                jsonWriter.writePropertyName("scope");
                jsonWriter.writeCharArray(*m_Request.getScope());
            }
            if (m_Request.getAllowUserIds())
            {
                jsonWriter.writePropertyName("allowUserIds");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getAllowUserIds();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    jsonWriter.writeCharArray(list[i]);
                }
                jsonWriter.writeArrayEnd();
            }
            if (m_Request.getUpdateIfExists())
            {
                jsonWriter.writePropertyName("updateIfExists");
                jsonWriter.writeBool(*m_Request.getUpdateIfExists());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                jsonWriter.writePropertyName("xGs2AccessToken");
                jsonWriter.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        PrepareUploadTask(
            PrepareUploadRequest request,
            Gs2WebSocketSessionTask<PrepareUploadResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<PrepareUploadResult>(callback),
            m_Request(std::move(request))
        {}

        ~PrepareUploadTask() GS2_OVERRIDE = default;
    };

    class PrepareUploadByUserIdTask : public detail::Gs2WebSocketSessionTask<PrepareUploadByUserIdResult>
    {
    private:
        PrepareUploadByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "dataObject";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "prepareUploadByUserId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getName())
            {
                jsonWriter.writePropertyName("name");
                jsonWriter.writeCharArray(*m_Request.getName());
            }
            if (m_Request.getContentType())
            {
                jsonWriter.writePropertyName("contentType");
                jsonWriter.writeCharArray(*m_Request.getContentType());
            }
            if (m_Request.getScope())
            {
                jsonWriter.writePropertyName("scope");
                jsonWriter.writeCharArray(*m_Request.getScope());
            }
            if (m_Request.getAllowUserIds())
            {
                jsonWriter.writePropertyName("allowUserIds");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getAllowUserIds();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    jsonWriter.writeCharArray(list[i]);
                }
                jsonWriter.writeArrayEnd();
            }
            if (m_Request.getUpdateIfExists())
            {
                jsonWriter.writePropertyName("updateIfExists");
                jsonWriter.writeBool(*m_Request.getUpdateIfExists());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        PrepareUploadByUserIdTask(
            PrepareUploadByUserIdRequest request,
            Gs2WebSocketSessionTask<PrepareUploadByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<PrepareUploadByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~PrepareUploadByUserIdTask() GS2_OVERRIDE = default;
    };

    class UpdateDataObjectTask : public detail::Gs2WebSocketSessionTask<UpdateDataObjectResult>
    {
    private:
        UpdateDataObjectRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "dataObject";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateDataObject";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getDataObjectName())
            {
                jsonWriter.writePropertyName("dataObjectName");
                jsonWriter.writeCharArray(*m_Request.getDataObjectName());
            }
            if (m_Request.getScope())
            {
                jsonWriter.writePropertyName("scope");
                jsonWriter.writeCharArray(*m_Request.getScope());
            }
            if (m_Request.getAllowUserIds())
            {
                jsonWriter.writePropertyName("allowUserIds");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getAllowUserIds();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    jsonWriter.writeCharArray(list[i]);
                }
                jsonWriter.writeArrayEnd();
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                jsonWriter.writePropertyName("xGs2AccessToken");
                jsonWriter.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        UpdateDataObjectTask(
            UpdateDataObjectRequest request,
            Gs2WebSocketSessionTask<UpdateDataObjectResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateDataObjectResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateDataObjectTask() GS2_OVERRIDE = default;
    };

    class UpdateDataObjectByUserIdTask : public detail::Gs2WebSocketSessionTask<UpdateDataObjectByUserIdResult>
    {
    private:
        UpdateDataObjectByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "dataObject";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateDataObjectByUserId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getDataObjectName())
            {
                jsonWriter.writePropertyName("dataObjectName");
                jsonWriter.writeCharArray(*m_Request.getDataObjectName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getScope())
            {
                jsonWriter.writePropertyName("scope");
                jsonWriter.writeCharArray(*m_Request.getScope());
            }
            if (m_Request.getAllowUserIds())
            {
                jsonWriter.writePropertyName("allowUserIds");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getAllowUserIds();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    jsonWriter.writeCharArray(list[i]);
                }
                jsonWriter.writeArrayEnd();
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        UpdateDataObjectByUserIdTask(
            UpdateDataObjectByUserIdRequest request,
            Gs2WebSocketSessionTask<UpdateDataObjectByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateDataObjectByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateDataObjectByUserIdTask() GS2_OVERRIDE = default;
    };

    class PrepareReUploadTask : public detail::Gs2WebSocketSessionTask<PrepareReUploadResult>
    {
    private:
        PrepareReUploadRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "dataObject";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "prepareReUpload";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getDataObjectName())
            {
                jsonWriter.writePropertyName("dataObjectName");
                jsonWriter.writeCharArray(*m_Request.getDataObjectName());
            }
            if (m_Request.getContentType())
            {
                jsonWriter.writePropertyName("contentType");
                jsonWriter.writeCharArray(*m_Request.getContentType());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                jsonWriter.writePropertyName("xGs2AccessToken");
                jsonWriter.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        PrepareReUploadTask(
            PrepareReUploadRequest request,
            Gs2WebSocketSessionTask<PrepareReUploadResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<PrepareReUploadResult>(callback),
            m_Request(std::move(request))
        {}

        ~PrepareReUploadTask() GS2_OVERRIDE = default;
    };

    class PrepareReUploadByUserIdTask : public detail::Gs2WebSocketSessionTask<PrepareReUploadByUserIdResult>
    {
    private:
        PrepareReUploadByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "dataObject";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "prepareReUploadByUserId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getDataObjectName())
            {
                jsonWriter.writePropertyName("dataObjectName");
                jsonWriter.writeCharArray(*m_Request.getDataObjectName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getContentType())
            {
                jsonWriter.writePropertyName("contentType");
                jsonWriter.writeCharArray(*m_Request.getContentType());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        PrepareReUploadByUserIdTask(
            PrepareReUploadByUserIdRequest request,
            Gs2WebSocketSessionTask<PrepareReUploadByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<PrepareReUploadByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~PrepareReUploadByUserIdTask() GS2_OVERRIDE = default;
    };

    class DoneUploadTask : public detail::Gs2WebSocketSessionTask<DoneUploadResult>
    {
    private:
        DoneUploadRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "dataObject";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "doneUpload";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getDataObjectName())
            {
                jsonWriter.writePropertyName("dataObjectName");
                jsonWriter.writeCharArray(*m_Request.getDataObjectName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                jsonWriter.writePropertyName("xGs2AccessToken");
                jsonWriter.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        DoneUploadTask(
            DoneUploadRequest request,
            Gs2WebSocketSessionTask<DoneUploadResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DoneUploadResult>(callback),
            m_Request(std::move(request))
        {}

        ~DoneUploadTask() GS2_OVERRIDE = default;
    };

    class DoneUploadByUserIdTask : public detail::Gs2WebSocketSessionTask<DoneUploadByUserIdResult>
    {
    private:
        DoneUploadByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "dataObject";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "doneUploadByUserId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getDataObjectName())
            {
                jsonWriter.writePropertyName("dataObjectName");
                jsonWriter.writeCharArray(*m_Request.getDataObjectName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        DoneUploadByUserIdTask(
            DoneUploadByUserIdRequest request,
            Gs2WebSocketSessionTask<DoneUploadByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DoneUploadByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DoneUploadByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteDataObjectTask : public detail::Gs2WebSocketSessionTask<DeleteDataObjectResult>
    {
    private:
        DeleteDataObjectRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "dataObject";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteDataObject";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getDataObjectName())
            {
                jsonWriter.writePropertyName("dataObjectName");
                jsonWriter.writeCharArray(*m_Request.getDataObjectName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                jsonWriter.writePropertyName("xGs2AccessToken");
                jsonWriter.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        DeleteDataObjectTask(
            DeleteDataObjectRequest request,
            Gs2WebSocketSessionTask<DeleteDataObjectResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteDataObjectResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteDataObjectTask() GS2_OVERRIDE = default;
    };

    class DeleteDataObjectByUserIdTask : public detail::Gs2WebSocketSessionTask<DeleteDataObjectByUserIdResult>
    {
    private:
        DeleteDataObjectByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "dataObject";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteDataObjectByUserId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getDataObjectName())
            {
                jsonWriter.writePropertyName("dataObjectName");
                jsonWriter.writeCharArray(*m_Request.getDataObjectName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        DeleteDataObjectByUserIdTask(
            DeleteDataObjectByUserIdRequest request,
            Gs2WebSocketSessionTask<DeleteDataObjectByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteDataObjectByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteDataObjectByUserIdTask() GS2_OVERRIDE = default;
    };

    class PrepareDownloadTask : public detail::Gs2WebSocketSessionTask<PrepareDownloadResult>
    {
    private:
        PrepareDownloadRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "dataObject";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "prepareDownload";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getDataObjectId())
            {
                jsonWriter.writePropertyName("dataObjectId");
                jsonWriter.writeCharArray(*m_Request.getDataObjectId());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                jsonWriter.writePropertyName("xGs2AccessToken");
                jsonWriter.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        PrepareDownloadTask(
            PrepareDownloadRequest request,
            Gs2WebSocketSessionTask<PrepareDownloadResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<PrepareDownloadResult>(callback),
            m_Request(std::move(request))
        {}

        ~PrepareDownloadTask() GS2_OVERRIDE = default;
    };

    class PrepareDownloadByUserIdTask : public detail::Gs2WebSocketSessionTask<PrepareDownloadByUserIdResult>
    {
    private:
        PrepareDownloadByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "dataObject";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "prepareDownloadByUserId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getDataObjectId())
            {
                jsonWriter.writePropertyName("dataObjectId");
                jsonWriter.writeCharArray(*m_Request.getDataObjectId());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        PrepareDownloadByUserIdTask(
            PrepareDownloadByUserIdRequest request,
            Gs2WebSocketSessionTask<PrepareDownloadByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<PrepareDownloadByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~PrepareDownloadByUserIdTask() GS2_OVERRIDE = default;
    };

    class PrepareDownloadByGenerationTask : public detail::Gs2WebSocketSessionTask<PrepareDownloadByGenerationResult>
    {
    private:
        PrepareDownloadByGenerationRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "dataObject";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "prepareDownloadByGeneration";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getDataObjectId())
            {
                jsonWriter.writePropertyName("dataObjectId");
                jsonWriter.writeCharArray(*m_Request.getDataObjectId());
            }
            if (m_Request.getGeneration())
            {
                jsonWriter.writePropertyName("generation");
                jsonWriter.writeCharArray(*m_Request.getGeneration());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                jsonWriter.writePropertyName("xGs2AccessToken");
                jsonWriter.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        PrepareDownloadByGenerationTask(
            PrepareDownloadByGenerationRequest request,
            Gs2WebSocketSessionTask<PrepareDownloadByGenerationResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<PrepareDownloadByGenerationResult>(callback),
            m_Request(std::move(request))
        {}

        ~PrepareDownloadByGenerationTask() GS2_OVERRIDE = default;
    };

    class PrepareDownloadByGenerationAndUserIdTask : public detail::Gs2WebSocketSessionTask<PrepareDownloadByGenerationAndUserIdResult>
    {
    private:
        PrepareDownloadByGenerationAndUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "dataObject";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "prepareDownloadByGenerationAndUserId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getDataObjectId())
            {
                jsonWriter.writePropertyName("dataObjectId");
                jsonWriter.writeCharArray(*m_Request.getDataObjectId());
            }
            if (m_Request.getGeneration())
            {
                jsonWriter.writePropertyName("generation");
                jsonWriter.writeCharArray(*m_Request.getGeneration());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        PrepareDownloadByGenerationAndUserIdTask(
            PrepareDownloadByGenerationAndUserIdRequest request,
            Gs2WebSocketSessionTask<PrepareDownloadByGenerationAndUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<PrepareDownloadByGenerationAndUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~PrepareDownloadByGenerationAndUserIdTask() GS2_OVERRIDE = default;
    };

    class PrepareDownloadOwnDataTask : public detail::Gs2WebSocketSessionTask<PrepareDownloadOwnDataResult>
    {
    private:
        PrepareDownloadOwnDataRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "dataObject";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "prepareDownloadOwnData";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getDataObjectName())
            {
                jsonWriter.writePropertyName("dataObjectName");
                jsonWriter.writeCharArray(*m_Request.getDataObjectName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                jsonWriter.writePropertyName("xGs2AccessToken");
                jsonWriter.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        PrepareDownloadOwnDataTask(
            PrepareDownloadOwnDataRequest request,
            Gs2WebSocketSessionTask<PrepareDownloadOwnDataResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<PrepareDownloadOwnDataResult>(callback),
            m_Request(std::move(request))
        {}

        ~PrepareDownloadOwnDataTask() GS2_OVERRIDE = default;
    };

    class PrepareDownloadOwnDataByGenerationTask : public detail::Gs2WebSocketSessionTask<PrepareDownloadOwnDataByGenerationResult>
    {
    private:
        PrepareDownloadOwnDataByGenerationRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "dataObject";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "prepareDownloadOwnDataByGeneration";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getDataObjectName())
            {
                jsonWriter.writePropertyName("dataObjectName");
                jsonWriter.writeCharArray(*m_Request.getDataObjectName());
            }
            if (m_Request.getGeneration())
            {
                jsonWriter.writePropertyName("generation");
                jsonWriter.writeCharArray(*m_Request.getGeneration());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                jsonWriter.writePropertyName("xGs2AccessToken");
                jsonWriter.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        PrepareDownloadOwnDataByGenerationTask(
            PrepareDownloadOwnDataByGenerationRequest request,
            Gs2WebSocketSessionTask<PrepareDownloadOwnDataByGenerationResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<PrepareDownloadOwnDataByGenerationResult>(callback),
            m_Request(std::move(request))
        {}

        ~PrepareDownloadOwnDataByGenerationTask() GS2_OVERRIDE = default;
    };

    class PrepareDownloadOwnDataByGenerationAndUserIdTask : public detail::Gs2WebSocketSessionTask<PrepareDownloadOwnDataByGenerationAndUserIdResult>
    {
    private:
        PrepareDownloadOwnDataByGenerationAndUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "dataObject";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "prepareDownloadOwnDataByGenerationAndUserId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getDataObjectName())
            {
                jsonWriter.writePropertyName("dataObjectName");
                jsonWriter.writeCharArray(*m_Request.getDataObjectName());
            }
            if (m_Request.getGeneration())
            {
                jsonWriter.writePropertyName("generation");
                jsonWriter.writeCharArray(*m_Request.getGeneration());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        PrepareDownloadOwnDataByGenerationAndUserIdTask(
            PrepareDownloadOwnDataByGenerationAndUserIdRequest request,
            Gs2WebSocketSessionTask<PrepareDownloadOwnDataByGenerationAndUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<PrepareDownloadOwnDataByGenerationAndUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~PrepareDownloadOwnDataByGenerationAndUserIdTask() GS2_OVERRIDE = default;
    };

    class DescribeDataObjectHistoriesTask : public detail::Gs2WebSocketSessionTask<DescribeDataObjectHistoriesResult>
    {
    private:
        DescribeDataObjectHistoriesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "dataObjectHistory";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeDataObjectHistories";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getDataObjectName())
            {
                jsonWriter.writePropertyName("dataObjectName");
                jsonWriter.writeCharArray(*m_Request.getDataObjectName());
            }
            if (m_Request.getPageToken())
            {
                jsonWriter.writePropertyName("pageToken");
                jsonWriter.writeCharArray(*m_Request.getPageToken());
            }
            if (m_Request.getLimit())
            {
                jsonWriter.writePropertyName("limit");
                jsonWriter.writeInt64(*m_Request.getLimit());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                jsonWriter.writePropertyName("xGs2AccessToken");
                jsonWriter.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        DescribeDataObjectHistoriesTask(
            DescribeDataObjectHistoriesRequest request,
            Gs2WebSocketSessionTask<DescribeDataObjectHistoriesResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeDataObjectHistoriesResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeDataObjectHistoriesTask() GS2_OVERRIDE = default;
    };

    class DescribeDataObjectHistoriesByUserIdTask : public detail::Gs2WebSocketSessionTask<DescribeDataObjectHistoriesByUserIdResult>
    {
    private:
        DescribeDataObjectHistoriesByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "dataObjectHistory";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeDataObjectHistoriesByUserId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getDataObjectName())
            {
                jsonWriter.writePropertyName("dataObjectName");
                jsonWriter.writeCharArray(*m_Request.getDataObjectName());
            }
            if (m_Request.getPageToken())
            {
                jsonWriter.writePropertyName("pageToken");
                jsonWriter.writeCharArray(*m_Request.getPageToken());
            }
            if (m_Request.getLimit())
            {
                jsonWriter.writePropertyName("limit");
                jsonWriter.writeInt64(*m_Request.getLimit());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        DescribeDataObjectHistoriesByUserIdTask(
            DescribeDataObjectHistoriesByUserIdRequest request,
            Gs2WebSocketSessionTask<DescribeDataObjectHistoriesByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeDataObjectHistoriesByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeDataObjectHistoriesByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetDataObjectHistoryTask : public detail::Gs2WebSocketSessionTask<GetDataObjectHistoryResult>
    {
    private:
        GetDataObjectHistoryRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "dataObjectHistory";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getDataObjectHistory";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getDataObjectName())
            {
                jsonWriter.writePropertyName("dataObjectName");
                jsonWriter.writeCharArray(*m_Request.getDataObjectName());
            }
            if (m_Request.getGeneration())
            {
                jsonWriter.writePropertyName("generation");
                jsonWriter.writeCharArray(*m_Request.getGeneration());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                jsonWriter.writePropertyName("xGs2AccessToken");
                jsonWriter.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        GetDataObjectHistoryTask(
            GetDataObjectHistoryRequest request,
            Gs2WebSocketSessionTask<GetDataObjectHistoryResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetDataObjectHistoryResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetDataObjectHistoryTask() GS2_OVERRIDE = default;
    };

    class GetDataObjectHistoryByUserIdTask : public detail::Gs2WebSocketSessionTask<GetDataObjectHistoryByUserIdResult>
    {
    private:
        GetDataObjectHistoryByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "dataObjectHistory";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getDataObjectHistoryByUserId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getDataObjectName())
            {
                jsonWriter.writePropertyName("dataObjectName");
                jsonWriter.writeCharArray(*m_Request.getDataObjectName());
            }
            if (m_Request.getGeneration())
            {
                jsonWriter.writePropertyName("generation");
                jsonWriter.writeCharArray(*m_Request.getGeneration());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        GetDataObjectHistoryByUserIdTask(
            GetDataObjectHistoryByUserIdRequest request,
            Gs2WebSocketSessionTask<GetDataObjectHistoryByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetDataObjectHistoryByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetDataObjectHistoryByUserIdTask() GS2_OVERRIDE = default;
    };

protected:
    static void write(detail::json::JsonWriter& jsonWriter, const Namespace& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getNamespaceId())
        {
            jsonWriter.writePropertyName("namespaceId");
            jsonWriter.writeCharArray(*obj.getNamespaceId());
        }
        if (obj.getOwnerId())
        {
            jsonWriter.writePropertyName("ownerId");
            jsonWriter.writeCharArray(*obj.getOwnerId());
        }
        if (obj.getName())
        {
            jsonWriter.writePropertyName("name");
            jsonWriter.writeCharArray(*obj.getName());
        }
        if (obj.getDescription())
        {
            jsonWriter.writePropertyName("description");
            jsonWriter.writeCharArray(*obj.getDescription());
        }
        if (obj.getLogSetting())
        {
            jsonWriter.writePropertyName("logSetting");
            write(jsonWriter, *obj.getLogSetting());
        }
        if (obj.getCreatedAt())
        {
            jsonWriter.writePropertyName("createdAt");
            jsonWriter.writeInt64(*obj.getCreatedAt());
        }
        if (obj.getUpdatedAt())
        {
            jsonWriter.writePropertyName("updatedAt");
            jsonWriter.writeInt64(*obj.getUpdatedAt());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const DataObject& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getDataObjectId())
        {
            jsonWriter.writePropertyName("dataObjectId");
            jsonWriter.writeCharArray(*obj.getDataObjectId());
        }
        if (obj.getName())
        {
            jsonWriter.writePropertyName("name");
            jsonWriter.writeCharArray(*obj.getName());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getScope())
        {
            jsonWriter.writePropertyName("scope");
            jsonWriter.writeCharArray(*obj.getScope());
        }
        if (obj.getAllowUserIds())
        {
            jsonWriter.writePropertyName("allowUserIds");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getAllowUserIds();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                jsonWriter.writeCharArray(list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (obj.getPlatform())
        {
            jsonWriter.writePropertyName("platform");
            jsonWriter.writeCharArray(*obj.getPlatform());
        }
        if (obj.getStatus())
        {
            jsonWriter.writePropertyName("status");
            jsonWriter.writeCharArray(*obj.getStatus());
        }
        if (obj.getGeneration())
        {
            jsonWriter.writePropertyName("generation");
            jsonWriter.writeCharArray(*obj.getGeneration());
        }
        if (obj.getPreviousGeneration())
        {
            jsonWriter.writePropertyName("previousGeneration");
            jsonWriter.writeCharArray(*obj.getPreviousGeneration());
        }
        if (obj.getCreatedAt())
        {
            jsonWriter.writePropertyName("createdAt");
            jsonWriter.writeInt64(*obj.getCreatedAt());
        }
        if (obj.getUpdatedAt())
        {
            jsonWriter.writePropertyName("updatedAt");
            jsonWriter.writeInt64(*obj.getUpdatedAt());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const DataObjectHistory& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getDataObjectHistoryId())
        {
            jsonWriter.writePropertyName("dataObjectHistoryId");
            jsonWriter.writeCharArray(*obj.getDataObjectHistoryId());
        }
        if (obj.getDataObjectName())
        {
            jsonWriter.writePropertyName("dataObjectName");
            jsonWriter.writeCharArray(*obj.getDataObjectName());
        }
        if (obj.getGeneration())
        {
            jsonWriter.writePropertyName("generation");
            jsonWriter.writeCharArray(*obj.getGeneration());
        }
        if (obj.getContentLength())
        {
            jsonWriter.writePropertyName("contentLength");
            jsonWriter.writeInt64(*obj.getContentLength());
        }
        if (obj.getCreatedAt())
        {
            jsonWriter.writePropertyName("createdAt");
            jsonWriter.writeInt64(*obj.getCreatedAt());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const ResponseCache& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getRegion())
        {
            jsonWriter.writePropertyName("region");
            jsonWriter.writeCharArray(*obj.getRegion());
        }
        if (obj.getOwnerId())
        {
            jsonWriter.writePropertyName("ownerId");
            jsonWriter.writeCharArray(*obj.getOwnerId());
        }
        if (obj.getResponseCacheId())
        {
            jsonWriter.writePropertyName("responseCacheId");
            jsonWriter.writeCharArray(*obj.getResponseCacheId());
        }
        if (obj.getRequestHash())
        {
            jsonWriter.writePropertyName("requestHash");
            jsonWriter.writeCharArray(*obj.getRequestHash());
        }
        if (obj.getResult())
        {
            jsonWriter.writePropertyName("result");
            jsonWriter.writeCharArray(*obj.getResult());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const LogSetting& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getLoggingNamespaceId())
        {
            jsonWriter.writePropertyName("loggingNamespaceId");
            jsonWriter.writeCharArray(*obj.getLoggingNamespaceId());
        }
        jsonWriter.writeObjectEnd();
    }


public:
    /**
     * コンストラクタ。
     *
     * @param gs2WebSocketSession WebSocket API 用セッション
     */
    explicit Gs2DatastoreWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
        AbstractGs2ClientBase(gs2WebSocketSession)
    {
    }

	/**
	 * ネームスペースの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeNamespaces(DescribeNamespacesRequest request, std::function<void(AsyncDescribeNamespacesResult)> callback)
    {
        DescribeNamespacesTask& task = *new DescribeNamespacesTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ネームスペースを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createNamespace(CreateNamespaceRequest request, std::function<void(AsyncCreateNamespaceResult)> callback)
    {
        CreateNamespaceTask& task = *new CreateNamespaceTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ネームスペースを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getNamespaceStatus(GetNamespaceStatusRequest request, std::function<void(AsyncGetNamespaceStatusResult)> callback)
    {
        GetNamespaceStatusTask& task = *new GetNamespaceStatusTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ネームスペースを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getNamespace(GetNamespaceRequest request, std::function<void(AsyncGetNamespaceResult)> callback)
    {
        GetNamespaceTask& task = *new GetNamespaceTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ネームスペースを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateNamespace(UpdateNamespaceRequest request, std::function<void(AsyncUpdateNamespaceResult)> callback)
    {
        UpdateNamespaceTask& task = *new UpdateNamespaceTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ネームスペースを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteNamespace(DeleteNamespaceRequest request, std::function<void(AsyncDeleteNamespaceResult)> callback)
    {
        DeleteNamespaceTask& task = *new DeleteNamespaceTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * データオブジェクトの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeDataObjects(DescribeDataObjectsRequest request, std::function<void(AsyncDescribeDataObjectsResult)> callback)
    {
        DescribeDataObjectsTask& task = *new DescribeDataObjectsTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * オーナーIDを指定してデータオブジェクトの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeDataObjectsByUserId(DescribeDataObjectsByUserIdRequest request, std::function<void(AsyncDescribeDataObjectsByUserIdResult)> callback)
    {
        DescribeDataObjectsByUserIdTask& task = *new DescribeDataObjectsByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * データオブジェクトをアップロード準備する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void prepareUpload(PrepareUploadRequest request, std::function<void(AsyncPrepareUploadResult)> callback)
    {
        PrepareUploadTask& task = *new PrepareUploadTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザIDを指定してデータオブジェクトをアップロード準備する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void prepareUploadByUserId(PrepareUploadByUserIdRequest request, std::function<void(AsyncPrepareUploadByUserIdResult)> callback)
    {
        PrepareUploadByUserIdTask& task = *new PrepareUploadByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * データオブジェクトを更新する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateDataObject(UpdateDataObjectRequest request, std::function<void(AsyncUpdateDataObjectResult)> callback)
    {
        UpdateDataObjectTask& task = *new UpdateDataObjectTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザIDを指定してデータオブジェクトを更新する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateDataObjectByUserId(UpdateDataObjectByUserIdRequest request, std::function<void(AsyncUpdateDataObjectByUserIdResult)> callback)
    {
        UpdateDataObjectByUserIdTask& task = *new UpdateDataObjectByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * データオブジェクトを再アップロード準備する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void prepareReUpload(PrepareReUploadRequest request, std::function<void(AsyncPrepareReUploadResult)> callback)
    {
        PrepareReUploadTask& task = *new PrepareReUploadTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザIDを指定してデータオブジェクトを再アップロード準備する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void prepareReUploadByUserId(PrepareReUploadByUserIdRequest request, std::function<void(AsyncPrepareReUploadByUserIdResult)> callback)
    {
        PrepareReUploadByUserIdTask& task = *new PrepareReUploadByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * データオブジェクトのアップロード完了を報告する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void doneUpload(DoneUploadRequest request, std::function<void(AsyncDoneUploadResult)> callback)
    {
        DoneUploadTask& task = *new DoneUploadTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザIDを指定してデータオブジェクトのアップロード完了を報告する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void doneUploadByUserId(DoneUploadByUserIdRequest request, std::function<void(AsyncDoneUploadByUserIdResult)> callback)
    {
        DoneUploadByUserIdTask& task = *new DoneUploadByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * データオブジェクトを削除する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteDataObject(DeleteDataObjectRequest request, std::function<void(AsyncDeleteDataObjectResult)> callback)
    {
        DeleteDataObjectTask& task = *new DeleteDataObjectTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザIDを指定してデータオブジェクトを削除する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteDataObjectByUserId(DeleteDataObjectByUserIdRequest request, std::function<void(AsyncDeleteDataObjectByUserIdResult)> callback)
    {
        DeleteDataObjectByUserIdTask& task = *new DeleteDataObjectByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * データオブジェクトをダウンロード準備する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void prepareDownload(PrepareDownloadRequest request, std::function<void(AsyncPrepareDownloadResult)> callback)
    {
        PrepareDownloadTask& task = *new PrepareDownloadTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザIDを指定してデータオブジェクトをダウンロード準備する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void prepareDownloadByUserId(PrepareDownloadByUserIdRequest request, std::function<void(AsyncPrepareDownloadByUserIdResult)> callback)
    {
        PrepareDownloadByUserIdTask& task = *new PrepareDownloadByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * データオブジェクトを世代を指定してダウンロード準備する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void prepareDownloadByGeneration(PrepareDownloadByGenerationRequest request, std::function<void(AsyncPrepareDownloadByGenerationResult)> callback)
    {
        PrepareDownloadByGenerationTask& task = *new PrepareDownloadByGenerationTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザIDを指定してデータオブジェクトを世代を指定してダウンロード準備する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void prepareDownloadByGenerationAndUserId(PrepareDownloadByGenerationAndUserIdRequest request, std::function<void(AsyncPrepareDownloadByGenerationAndUserIdResult)> callback)
    {
        PrepareDownloadByGenerationAndUserIdTask& task = *new PrepareDownloadByGenerationAndUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * データオブジェクトをダウンロード準備する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void prepareDownloadOwnData(PrepareDownloadOwnDataRequest request, std::function<void(AsyncPrepareDownloadOwnDataResult)> callback)
    {
        PrepareDownloadOwnDataTask& task = *new PrepareDownloadOwnDataTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * データオブジェクトを世代を指定してダウンロード準備する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void prepareDownloadOwnDataByGeneration(PrepareDownloadOwnDataByGenerationRequest request, std::function<void(AsyncPrepareDownloadOwnDataByGenerationResult)> callback)
    {
        PrepareDownloadOwnDataByGenerationTask& task = *new PrepareDownloadOwnDataByGenerationTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザIDを指定してデータオブジェクトを世代を指定してダウンロード準備する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void prepareDownloadOwnDataByGenerationAndUserId(PrepareDownloadOwnDataByGenerationAndUserIdRequest request, std::function<void(AsyncPrepareDownloadOwnDataByGenerationAndUserIdResult)> callback)
    {
        PrepareDownloadOwnDataByGenerationAndUserIdTask& task = *new PrepareDownloadOwnDataByGenerationAndUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * データオブジェクト履歴の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeDataObjectHistories(DescribeDataObjectHistoriesRequest request, std::function<void(AsyncDescribeDataObjectHistoriesResult)> callback)
    {
        DescribeDataObjectHistoriesTask& task = *new DescribeDataObjectHistoriesTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザIDを指定してデータオブジェクト履歴の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeDataObjectHistoriesByUserId(DescribeDataObjectHistoriesByUserIdRequest request, std::function<void(AsyncDescribeDataObjectHistoriesByUserIdResult)> callback)
    {
        DescribeDataObjectHistoriesByUserIdTask& task = *new DescribeDataObjectHistoriesByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * データオブジェクト履歴を取得する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getDataObjectHistory(GetDataObjectHistoryRequest request, std::function<void(AsyncGetDataObjectHistoryResult)> callback)
    {
        GetDataObjectHistoryTask& task = *new GetDataObjectHistoryTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザIDを指定してデータオブジェクト履歴を取得する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getDataObjectHistoryByUserId(GetDataObjectHistoryByUserIdRequest request, std::function<void(AsyncGetDataObjectHistoryByUserIdResult)> callback)
    {
        GetDataObjectHistoryByUserIdTask& task = *new GetDataObjectHistoryByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_DATASTORE_GS2DATASTOREWEBSOCKETCLIENT_HPP_