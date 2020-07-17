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

#ifndef GS2_DICTIONARY_GS2DICTIONARYWEBSOCKETCLIENT_HPP_
#define GS2_DICTIONARY_GS2DICTIONARYWEBSOCKETCLIENT_HPP_

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
#include "request/DescribeEntryModelsRequest.hpp"
#include "request/GetEntryModelRequest.hpp"
#include "request/DescribeEntryModelMastersRequest.hpp"
#include "request/CreateEntryModelMasterRequest.hpp"
#include "request/GetEntryModelMasterRequest.hpp"
#include "request/UpdateEntryModelMasterRequest.hpp"
#include "request/DeleteEntryModelMasterRequest.hpp"
#include "request/DescribeEntriesRequest.hpp"
#include "request/DescribeEntriesByUserIdRequest.hpp"
#include "request/AddEntriesByUserIdRequest.hpp"
#include "request/GetEntryRequest.hpp"
#include "request/GetEntryByUserIdRequest.hpp"
#include "request/GetEntryWithSignatureRequest.hpp"
#include "request/GetEntryWithSignatureByUserIdRequest.hpp"
#include "request/ResetByUserIdRequest.hpp"
#include "request/AddEntriesByStampSheetRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentEntryMasterRequest.hpp"
#include "request/UpdateCurrentEntryMasterRequest.hpp"
#include "request/UpdateCurrentEntryMasterFromGitHubRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeEntryModelsResult.hpp"
#include "result/GetEntryModelResult.hpp"
#include "result/DescribeEntryModelMastersResult.hpp"
#include "result/CreateEntryModelMasterResult.hpp"
#include "result/GetEntryModelMasterResult.hpp"
#include "result/UpdateEntryModelMasterResult.hpp"
#include "result/DeleteEntryModelMasterResult.hpp"
#include "result/DescribeEntriesResult.hpp"
#include "result/DescribeEntriesByUserIdResult.hpp"
#include "result/AddEntriesByUserIdResult.hpp"
#include "result/GetEntryResult.hpp"
#include "result/GetEntryByUserIdResult.hpp"
#include "result/GetEntryWithSignatureResult.hpp"
#include "result/GetEntryWithSignatureByUserIdResult.hpp"
#include "result/ResetByUserIdResult.hpp"
#include "result/AddEntriesByStampSheetResult.hpp"
#include "result/ExportMasterResult.hpp"
#include "result/GetCurrentEntryMasterResult.hpp"
#include "result/UpdateCurrentEntryMasterResult.hpp"
#include "result/UpdateCurrentEntryMasterFromGitHubResult.hpp"
#include <cstring>

namespace gs2 { namespace dictionary {

/**
 * GS2 Dictionary API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2DictionaryWebSocketClient : public AbstractGs2ClientBase
{
private:

    class DescribeNamespacesTask : public detail::Gs2WebSocketSessionTask<DescribeNamespacesResult>
    {
    private:
        DescribeNamespacesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "dictionary";
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
            return "dictionary";
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
            return "dictionary";
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
            return "dictionary";
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
            return "dictionary";
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
            return "dictionary";
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

    class DescribeEntryModelsTask : public detail::Gs2WebSocketSessionTask<DescribeEntryModelsResult>
    {
    private:
        DescribeEntryModelsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "dictionary";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "entryModel";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeEntryModels";
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
        DescribeEntryModelsTask(
            DescribeEntryModelsRequest request,
            Gs2WebSocketSessionTask<DescribeEntryModelsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeEntryModelsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeEntryModelsTask() GS2_OVERRIDE = default;
    };

    class GetEntryModelTask : public detail::Gs2WebSocketSessionTask<GetEntryModelResult>
    {
    private:
        GetEntryModelRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "dictionary";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "entryModel";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getEntryModel";
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
            if (m_Request.getEntryName())
            {
                jsonWriter.writePropertyName("entryName");
                jsonWriter.writeCharArray(*m_Request.getEntryName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetEntryModelTask(
            GetEntryModelRequest request,
            Gs2WebSocketSessionTask<GetEntryModelResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetEntryModelResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetEntryModelTask() GS2_OVERRIDE = default;
    };

    class DescribeEntryModelMastersTask : public detail::Gs2WebSocketSessionTask<DescribeEntryModelMastersResult>
    {
    private:
        DescribeEntryModelMastersRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "dictionary";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "entryModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeEntryModelMasters";
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
        DescribeEntryModelMastersTask(
            DescribeEntryModelMastersRequest request,
            Gs2WebSocketSessionTask<DescribeEntryModelMastersResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeEntryModelMastersResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeEntryModelMastersTask() GS2_OVERRIDE = default;
    };

    class CreateEntryModelMasterTask : public detail::Gs2WebSocketSessionTask<CreateEntryModelMasterResult>
    {
    private:
        CreateEntryModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "dictionary";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "entryModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "createEntryModelMaster";
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
            if (m_Request.getDescription())
            {
                jsonWriter.writePropertyName("description");
                jsonWriter.writeCharArray(*m_Request.getDescription());
            }
            if (m_Request.getMetadata())
            {
                jsonWriter.writePropertyName("metadata");
                jsonWriter.writeCharArray(*m_Request.getMetadata());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        CreateEntryModelMasterTask(
            CreateEntryModelMasterRequest request,
            Gs2WebSocketSessionTask<CreateEntryModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateEntryModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateEntryModelMasterTask() GS2_OVERRIDE = default;
    };

    class GetEntryModelMasterTask : public detail::Gs2WebSocketSessionTask<GetEntryModelMasterResult>
    {
    private:
        GetEntryModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "dictionary";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "entryModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getEntryModelMaster";
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
            if (m_Request.getEntryName())
            {
                jsonWriter.writePropertyName("entryName");
                jsonWriter.writeCharArray(*m_Request.getEntryName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetEntryModelMasterTask(
            GetEntryModelMasterRequest request,
            Gs2WebSocketSessionTask<GetEntryModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetEntryModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetEntryModelMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateEntryModelMasterTask : public detail::Gs2WebSocketSessionTask<UpdateEntryModelMasterResult>
    {
    private:
        UpdateEntryModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "dictionary";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "entryModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateEntryModelMaster";
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
            if (m_Request.getEntryName())
            {
                jsonWriter.writePropertyName("entryName");
                jsonWriter.writeCharArray(*m_Request.getEntryName());
            }
            if (m_Request.getDescription())
            {
                jsonWriter.writePropertyName("description");
                jsonWriter.writeCharArray(*m_Request.getDescription());
            }
            if (m_Request.getMetadata())
            {
                jsonWriter.writePropertyName("metadata");
                jsonWriter.writeCharArray(*m_Request.getMetadata());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        UpdateEntryModelMasterTask(
            UpdateEntryModelMasterRequest request,
            Gs2WebSocketSessionTask<UpdateEntryModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateEntryModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateEntryModelMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteEntryModelMasterTask : public detail::Gs2WebSocketSessionTask<DeleteEntryModelMasterResult>
    {
    private:
        DeleteEntryModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "dictionary";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "entryModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteEntryModelMaster";
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
            if (m_Request.getEntryName())
            {
                jsonWriter.writePropertyName("entryName");
                jsonWriter.writeCharArray(*m_Request.getEntryName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        DeleteEntryModelMasterTask(
            DeleteEntryModelMasterRequest request,
            Gs2WebSocketSessionTask<DeleteEntryModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteEntryModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteEntryModelMasterTask() GS2_OVERRIDE = default;
    };

    class DescribeEntriesTask : public detail::Gs2WebSocketSessionTask<DescribeEntriesResult>
    {
    private:
        DescribeEntriesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "dictionary";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "entry";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeEntries";
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
        DescribeEntriesTask(
            DescribeEntriesRequest request,
            Gs2WebSocketSessionTask<DescribeEntriesResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeEntriesResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeEntriesTask() GS2_OVERRIDE = default;
    };

    class DescribeEntriesByUserIdTask : public detail::Gs2WebSocketSessionTask<DescribeEntriesByUserIdResult>
    {
    private:
        DescribeEntriesByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "dictionary";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "entry";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeEntriesByUserId";
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
        DescribeEntriesByUserIdTask(
            DescribeEntriesByUserIdRequest request,
            Gs2WebSocketSessionTask<DescribeEntriesByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeEntriesByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeEntriesByUserIdTask() GS2_OVERRIDE = default;
    };

    class AddEntriesByUserIdTask : public detail::Gs2WebSocketSessionTask<AddEntriesByUserIdResult>
    {
    private:
        AddEntriesByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "dictionary";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "entry";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "addEntriesByUserId";
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
            if (m_Request.getEntryModelNames())
            {
                jsonWriter.writePropertyName("entryModelNames");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getEntryModelNames();
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
        AddEntriesByUserIdTask(
            AddEntriesByUserIdRequest request,
            Gs2WebSocketSessionTask<AddEntriesByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<AddEntriesByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~AddEntriesByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetEntryTask : public detail::Gs2WebSocketSessionTask<GetEntryResult>
    {
    private:
        GetEntryRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "dictionary";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "entry";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getEntry";
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
            if (m_Request.getEntryModelName())
            {
                jsonWriter.writePropertyName("entryModelName");
                jsonWriter.writeCharArray(*m_Request.getEntryModelName());
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
        GetEntryTask(
            GetEntryRequest request,
            Gs2WebSocketSessionTask<GetEntryResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetEntryResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetEntryTask() GS2_OVERRIDE = default;
    };

    class GetEntryByUserIdTask : public detail::Gs2WebSocketSessionTask<GetEntryByUserIdResult>
    {
    private:
        GetEntryByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "dictionary";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "entry";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getEntryByUserId";
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
            if (m_Request.getEntryModelName())
            {
                jsonWriter.writePropertyName("entryModelName");
                jsonWriter.writeCharArray(*m_Request.getEntryModelName());
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
        GetEntryByUserIdTask(
            GetEntryByUserIdRequest request,
            Gs2WebSocketSessionTask<GetEntryByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetEntryByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetEntryByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetEntryWithSignatureTask : public detail::Gs2WebSocketSessionTask<GetEntryWithSignatureResult>
    {
    private:
        GetEntryWithSignatureRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "dictionary";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "entry";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getEntryWithSignature";
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
            if (m_Request.getEntryModelName())
            {
                jsonWriter.writePropertyName("entryModelName");
                jsonWriter.writeCharArray(*m_Request.getEntryModelName());
            }
            if (m_Request.getKeyId())
            {
                jsonWriter.writePropertyName("keyId");
                jsonWriter.writeCharArray(*m_Request.getKeyId());
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
        GetEntryWithSignatureTask(
            GetEntryWithSignatureRequest request,
            Gs2WebSocketSessionTask<GetEntryWithSignatureResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetEntryWithSignatureResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetEntryWithSignatureTask() GS2_OVERRIDE = default;
    };

    class GetEntryWithSignatureByUserIdTask : public detail::Gs2WebSocketSessionTask<GetEntryWithSignatureByUserIdResult>
    {
    private:
        GetEntryWithSignatureByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "dictionary";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "entry";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getEntryWithSignatureByUserId";
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
            if (m_Request.getEntryModelName())
            {
                jsonWriter.writePropertyName("entryModelName");
                jsonWriter.writeCharArray(*m_Request.getEntryModelName());
            }
            if (m_Request.getKeyId())
            {
                jsonWriter.writePropertyName("keyId");
                jsonWriter.writeCharArray(*m_Request.getKeyId());
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
        GetEntryWithSignatureByUserIdTask(
            GetEntryWithSignatureByUserIdRequest request,
            Gs2WebSocketSessionTask<GetEntryWithSignatureByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetEntryWithSignatureByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetEntryWithSignatureByUserIdTask() GS2_OVERRIDE = default;
    };

    class ResetByUserIdTask : public detail::Gs2WebSocketSessionTask<void>
    {
    private:
        ResetByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "dictionary";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "entry";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "resetByUserId";
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
        ResetByUserIdTask(
            ResetByUserIdRequest request,
            Gs2WebSocketSessionTask<void>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<void>(callback),
            m_Request(std::move(request))
        {}

        ~ResetByUserIdTask() GS2_OVERRIDE = default;
    };

    class AddEntriesByStampSheetTask : public detail::Gs2WebSocketSessionTask<AddEntriesByStampSheetResult>
    {
    private:
        AddEntriesByStampSheetRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "dictionary";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "entry";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "addEntriesByStampSheet";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getStampSheet())
            {
                jsonWriter.writePropertyName("stampSheet");
                jsonWriter.writeCharArray(*m_Request.getStampSheet());
            }
            if (m_Request.getKeyId())
            {
                jsonWriter.writePropertyName("keyId");
                jsonWriter.writeCharArray(*m_Request.getKeyId());
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
        AddEntriesByStampSheetTask(
            AddEntriesByStampSheetRequest request,
            Gs2WebSocketSessionTask<AddEntriesByStampSheetResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<AddEntriesByStampSheetResult>(callback),
            m_Request(std::move(request))
        {}

        ~AddEntriesByStampSheetTask() GS2_OVERRIDE = default;
    };

    class ExportMasterTask : public detail::Gs2WebSocketSessionTask<ExportMasterResult>
    {
    private:
        ExportMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "dictionary";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "currentEntryMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "exportMaster";
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
        ExportMasterTask(
            ExportMasterRequest request,
            Gs2WebSocketSessionTask<ExportMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<ExportMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~ExportMasterTask() GS2_OVERRIDE = default;
    };

    class GetCurrentEntryMasterTask : public detail::Gs2WebSocketSessionTask<GetCurrentEntryMasterResult>
    {
    private:
        GetCurrentEntryMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "dictionary";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "currentEntryMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getCurrentEntryMaster";
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
        GetCurrentEntryMasterTask(
            GetCurrentEntryMasterRequest request,
            Gs2WebSocketSessionTask<GetCurrentEntryMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetCurrentEntryMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetCurrentEntryMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentEntryMasterTask : public detail::Gs2WebSocketSessionTask<UpdateCurrentEntryMasterResult>
    {
    private:
        UpdateCurrentEntryMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "dictionary";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "currentEntryMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateCurrentEntryMaster";
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
            if (m_Request.getSettings())
            {
                jsonWriter.writePropertyName("settings");
                jsonWriter.writeCharArray(*m_Request.getSettings());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        UpdateCurrentEntryMasterTask(
            UpdateCurrentEntryMasterRequest request,
            Gs2WebSocketSessionTask<UpdateCurrentEntryMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateCurrentEntryMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateCurrentEntryMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentEntryMasterFromGitHubTask : public detail::Gs2WebSocketSessionTask<UpdateCurrentEntryMasterFromGitHubResult>
    {
    private:
        UpdateCurrentEntryMasterFromGitHubRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "dictionary";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "currentEntryMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateCurrentEntryMasterFromGitHub";
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
            if (m_Request.getCheckoutSetting())
            {
                jsonWriter.writePropertyName("checkoutSetting");
                write(jsonWriter, *m_Request.getCheckoutSetting());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        UpdateCurrentEntryMasterFromGitHubTask(
            UpdateCurrentEntryMasterFromGitHubRequest request,
            Gs2WebSocketSessionTask<UpdateCurrentEntryMasterFromGitHubResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateCurrentEntryMasterFromGitHubResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateCurrentEntryMasterFromGitHubTask() GS2_OVERRIDE = default;
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
        if (obj.getStatus())
        {
            jsonWriter.writePropertyName("status");
            jsonWriter.writeCharArray(*obj.getStatus());
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

    static void write(detail::json::JsonWriter& jsonWriter, const EntryModel& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getEntryModelId())
        {
            jsonWriter.writePropertyName("entryModelId");
            jsonWriter.writeCharArray(*obj.getEntryModelId());
        }
        if (obj.getName())
        {
            jsonWriter.writePropertyName("name");
            jsonWriter.writeCharArray(*obj.getName());
        }
        if (obj.getMetadata())
        {
            jsonWriter.writePropertyName("metadata");
            jsonWriter.writeCharArray(*obj.getMetadata());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const EntryModelMaster& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getEntryModelId())
        {
            jsonWriter.writePropertyName("entryModelId");
            jsonWriter.writeCharArray(*obj.getEntryModelId());
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
        if (obj.getMetadata())
        {
            jsonWriter.writePropertyName("metadata");
            jsonWriter.writeCharArray(*obj.getMetadata());
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

    static void write(detail::json::JsonWriter& jsonWriter, const Entry& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getEntryId())
        {
            jsonWriter.writePropertyName("entryId");
            jsonWriter.writeCharArray(*obj.getEntryId());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getName())
        {
            jsonWriter.writePropertyName("name");
            jsonWriter.writeCharArray(*obj.getName());
        }
        if (obj.getAcquiredAt())
        {
            jsonWriter.writePropertyName("acquiredAt");
            jsonWriter.writeInt64(*obj.getAcquiredAt());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const Toc& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getTocId())
        {
            jsonWriter.writePropertyName("tocId");
            jsonWriter.writeCharArray(*obj.getTocId());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getIndex())
        {
            jsonWriter.writePropertyName("index");
            jsonWriter.writeInt32(*obj.getIndex());
        }
        if (obj.getEntries())
        {
            jsonWriter.writePropertyName("entries");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getEntries();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
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

    static void write(detail::json::JsonWriter& jsonWriter, const CurrentEntryMaster& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getNamespaceName())
        {
            jsonWriter.writePropertyName("namespaceName");
            jsonWriter.writeCharArray(*obj.getNamespaceName());
        }
        if (obj.getSettings())
        {
            jsonWriter.writePropertyName("settings");
            jsonWriter.writeCharArray(*obj.getSettings());
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

    static void write(detail::json::JsonWriter& jsonWriter, const Config& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getKey())
        {
            jsonWriter.writePropertyName("key");
            jsonWriter.writeCharArray(*obj.getKey());
        }
        if (obj.getValue())
        {
            jsonWriter.writePropertyName("value");
            jsonWriter.writeCharArray(*obj.getValue());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const GitHubCheckoutSetting& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getGitHubApiKeyId())
        {
            jsonWriter.writePropertyName("gitHubApiKeyId");
            jsonWriter.writeCharArray(*obj.getGitHubApiKeyId());
        }
        if (obj.getRepositoryName())
        {
            jsonWriter.writePropertyName("repositoryName");
            jsonWriter.writeCharArray(*obj.getRepositoryName());
        }
        if (obj.getSourcePath())
        {
            jsonWriter.writePropertyName("sourcePath");
            jsonWriter.writeCharArray(*obj.getSourcePath());
        }
        if (obj.getReferenceType())
        {
            jsonWriter.writePropertyName("referenceType");
            jsonWriter.writeCharArray(*obj.getReferenceType());
        }
        if (obj.getCommitHash())
        {
            jsonWriter.writePropertyName("commitHash");
            jsonWriter.writeCharArray(*obj.getCommitHash());
        }
        if (obj.getBranchName())
        {
            jsonWriter.writePropertyName("branchName");
            jsonWriter.writeCharArray(*obj.getBranchName());
        }
        if (obj.getTagName())
        {
            jsonWriter.writePropertyName("tagName");
            jsonWriter.writeCharArray(*obj.getTagName());
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
    explicit Gs2DictionaryWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
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
	 * エントリーモデルの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeEntryModels(DescribeEntryModelsRequest request, std::function<void(AsyncDescribeEntryModelsResult)> callback)
    {
        DescribeEntryModelsTask& task = *new DescribeEntryModelsTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * エントリーモデルを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getEntryModel(GetEntryModelRequest request, std::function<void(AsyncGetEntryModelResult)> callback)
    {
        GetEntryModelTask& task = *new GetEntryModelTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * エントリーモデルマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeEntryModelMasters(DescribeEntryModelMastersRequest request, std::function<void(AsyncDescribeEntryModelMastersResult)> callback)
    {
        DescribeEntryModelMastersTask& task = *new DescribeEntryModelMastersTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * エントリーモデルマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createEntryModelMaster(CreateEntryModelMasterRequest request, std::function<void(AsyncCreateEntryModelMasterResult)> callback)
    {
        CreateEntryModelMasterTask& task = *new CreateEntryModelMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * エントリーモデルマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getEntryModelMaster(GetEntryModelMasterRequest request, std::function<void(AsyncGetEntryModelMasterResult)> callback)
    {
        GetEntryModelMasterTask& task = *new GetEntryModelMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * エントリーモデルマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateEntryModelMaster(UpdateEntryModelMasterRequest request, std::function<void(AsyncUpdateEntryModelMasterResult)> callback)
    {
        UpdateEntryModelMasterTask& task = *new UpdateEntryModelMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * エントリーモデルマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteEntryModelMaster(DeleteEntryModelMasterRequest request, std::function<void(AsyncDeleteEntryModelMasterResult)> callback)
    {
        DeleteEntryModelMasterTask& task = *new DeleteEntryModelMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * エントリーの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeEntries(DescribeEntriesRequest request, std::function<void(AsyncDescribeEntriesResult)> callback)
    {
        DescribeEntriesTask& task = *new DescribeEntriesTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザIDを指定してエントリーの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeEntriesByUserId(DescribeEntriesByUserIdRequest request, std::function<void(AsyncDescribeEntriesByUserIdResult)> callback)
    {
        DescribeEntriesByUserIdTask& task = *new DescribeEntriesByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザIDを指定してエントリーを入手済みとして登録<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void addEntriesByUserId(AddEntriesByUserIdRequest request, std::function<void(AsyncAddEntriesByUserIdResult)> callback)
    {
        AddEntriesByUserIdTask& task = *new AddEntriesByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * エントリーを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getEntry(GetEntryRequest request, std::function<void(AsyncGetEntryResult)> callback)
    {
        GetEntryTask& task = *new GetEntryTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザIDを指定してエントリーを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getEntryByUserId(GetEntryByUserIdRequest request, std::function<void(AsyncGetEntryByUserIdResult)> callback)
    {
        GetEntryByUserIdTask& task = *new GetEntryByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * エントリーを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getEntryWithSignature(GetEntryWithSignatureRequest request, std::function<void(AsyncGetEntryWithSignatureResult)> callback)
    {
        GetEntryWithSignatureTask& task = *new GetEntryWithSignatureTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザIDを指定してエントリーを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getEntryWithSignatureByUserId(GetEntryWithSignatureByUserIdRequest request, std::function<void(AsyncGetEntryWithSignatureByUserIdResult)> callback)
    {
        GetEntryWithSignatureByUserIdTask& task = *new GetEntryWithSignatureByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * エントリーをリセット<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void resetByUserId(ResetByUserIdRequest request, std::function<void(AsyncResetByUserIdResult)> callback)
    {
        ResetByUserIdTask& task = *new ResetByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * スタンプシートでエントリーを追加<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void addEntriesByStampSheet(AddEntriesByStampSheetRequest request, std::function<void(AsyncAddEntriesByStampSheetResult)> callback)
    {
        AddEntriesByStampSheetTask& task = *new AddEntriesByStampSheetTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 現在有効なエントリー設定のマスターデータをエクスポートします<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void exportMaster(ExportMasterRequest request, std::function<void(AsyncExportMasterResult)> callback)
    {
        ExportMasterTask& task = *new ExportMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 現在有効なエントリー設定を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentEntryMaster(GetCurrentEntryMasterRequest request, std::function<void(AsyncGetCurrentEntryMasterResult)> callback)
    {
        GetCurrentEntryMasterTask& task = *new GetCurrentEntryMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 現在有効なエントリー設定を更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentEntryMaster(UpdateCurrentEntryMasterRequest request, std::function<void(AsyncUpdateCurrentEntryMasterResult)> callback)
    {
        UpdateCurrentEntryMasterTask& task = *new UpdateCurrentEntryMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 現在有効なエントリー設定を更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentEntryMasterFromGitHub(UpdateCurrentEntryMasterFromGitHubRequest request, std::function<void(AsyncUpdateCurrentEntryMasterFromGitHubResult)> callback)
    {
        UpdateCurrentEntryMasterFromGitHubTask& task = *new UpdateCurrentEntryMasterFromGitHubTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_DICTIONARY_GS2DICTIONARYWEBSOCKETCLIENT_HPP_