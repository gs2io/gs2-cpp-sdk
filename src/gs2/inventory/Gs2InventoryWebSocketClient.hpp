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

#ifndef GS2_INVENTORY_GS2INVENTORYWEBSOCKETCLIENT_HPP_
#define GS2_INVENTORY_GS2INVENTORYWEBSOCKETCLIENT_HPP_

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
#include "request/DescribeInventoryModelMastersRequest.hpp"
#include "request/CreateInventoryModelMasterRequest.hpp"
#include "request/GetInventoryModelMasterRequest.hpp"
#include "request/UpdateInventoryModelMasterRequest.hpp"
#include "request/DeleteInventoryModelMasterRequest.hpp"
#include "request/DescribeInventoryModelsRequest.hpp"
#include "request/GetInventoryModelRequest.hpp"
#include "request/DescribeItemModelMastersRequest.hpp"
#include "request/CreateItemModelMasterRequest.hpp"
#include "request/GetItemModelMasterRequest.hpp"
#include "request/UpdateItemModelMasterRequest.hpp"
#include "request/DeleteItemModelMasterRequest.hpp"
#include "request/DescribeItemModelsRequest.hpp"
#include "request/GetItemModelRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentItemModelMasterRequest.hpp"
#include "request/UpdateCurrentItemModelMasterRequest.hpp"
#include "request/UpdateCurrentItemModelMasterFromGitHubRequest.hpp"
#include "request/DescribeInventoriesRequest.hpp"
#include "request/DescribeInventoriesByUserIdRequest.hpp"
#include "request/GetInventoryRequest.hpp"
#include "request/GetInventoryByUserIdRequest.hpp"
#include "request/AddCapacityByUserIdRequest.hpp"
#include "request/SetCapacityByUserIdRequest.hpp"
#include "request/DeleteInventoryByUserIdRequest.hpp"
#include "request/AddCapacityByStampSheetRequest.hpp"
#include "request/SetCapacityByStampSheetRequest.hpp"
#include "request/DescribeItemSetsRequest.hpp"
#include "request/DescribeItemSetsByUserIdRequest.hpp"
#include "request/GetItemSetRequest.hpp"
#include "request/GetItemSetByUserIdRequest.hpp"
#include "request/GetItemWithSignatureRequest.hpp"
#include "request/GetItemWithSignatureByUserIdRequest.hpp"
#include "request/AcquireItemSetByUserIdRequest.hpp"
#include "request/ConsumeItemSetRequest.hpp"
#include "request/ConsumeItemSetByUserIdRequest.hpp"
#include "request/DescribeReferenceOfRequest.hpp"
#include "request/DescribeReferenceOfByUserIdRequest.hpp"
#include "request/GetReferenceOfRequest.hpp"
#include "request/GetReferenceOfByUserIdRequest.hpp"
#include "request/VerifyReferenceOfRequest.hpp"
#include "request/VerifyReferenceOfByUserIdRequest.hpp"
#include "request/AddReferenceOfRequest.hpp"
#include "request/AddReferenceOfByUserIdRequest.hpp"
#include "request/DeleteReferenceOfRequest.hpp"
#include "request/DeleteReferenceOfByUserIdRequest.hpp"
#include "request/DeleteItemSetByUserIdRequest.hpp"
#include "request/AcquireItemSetByStampSheetRequest.hpp"
#include "request/AddReferenceOfItemSetByStampSheetRequest.hpp"
#include "request/DeleteReferenceOfItemSetByStampSheetRequest.hpp"
#include "request/ConsumeItemSetByStampTaskRequest.hpp"
#include "request/VerifyReferenceOfByStampTaskRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeInventoryModelMastersResult.hpp"
#include "result/CreateInventoryModelMasterResult.hpp"
#include "result/GetInventoryModelMasterResult.hpp"
#include "result/UpdateInventoryModelMasterResult.hpp"
#include "result/DeleteInventoryModelMasterResult.hpp"
#include "result/DescribeInventoryModelsResult.hpp"
#include "result/GetInventoryModelResult.hpp"
#include "result/DescribeItemModelMastersResult.hpp"
#include "result/CreateItemModelMasterResult.hpp"
#include "result/GetItemModelMasterResult.hpp"
#include "result/UpdateItemModelMasterResult.hpp"
#include "result/DeleteItemModelMasterResult.hpp"
#include "result/DescribeItemModelsResult.hpp"
#include "result/GetItemModelResult.hpp"
#include "result/ExportMasterResult.hpp"
#include "result/GetCurrentItemModelMasterResult.hpp"
#include "result/UpdateCurrentItemModelMasterResult.hpp"
#include "result/UpdateCurrentItemModelMasterFromGitHubResult.hpp"
#include "result/DescribeInventoriesResult.hpp"
#include "result/DescribeInventoriesByUserIdResult.hpp"
#include "result/GetInventoryResult.hpp"
#include "result/GetInventoryByUserIdResult.hpp"
#include "result/AddCapacityByUserIdResult.hpp"
#include "result/SetCapacityByUserIdResult.hpp"
#include "result/DeleteInventoryByUserIdResult.hpp"
#include "result/AddCapacityByStampSheetResult.hpp"
#include "result/SetCapacityByStampSheetResult.hpp"
#include "result/DescribeItemSetsResult.hpp"
#include "result/DescribeItemSetsByUserIdResult.hpp"
#include "result/GetItemSetResult.hpp"
#include "result/GetItemSetByUserIdResult.hpp"
#include "result/GetItemWithSignatureResult.hpp"
#include "result/GetItemWithSignatureByUserIdResult.hpp"
#include "result/AcquireItemSetByUserIdResult.hpp"
#include "result/ConsumeItemSetResult.hpp"
#include "result/ConsumeItemSetByUserIdResult.hpp"
#include "result/DescribeReferenceOfResult.hpp"
#include "result/DescribeReferenceOfByUserIdResult.hpp"
#include "result/GetReferenceOfResult.hpp"
#include "result/GetReferenceOfByUserIdResult.hpp"
#include "result/VerifyReferenceOfResult.hpp"
#include "result/VerifyReferenceOfByUserIdResult.hpp"
#include "result/AddReferenceOfResult.hpp"
#include "result/AddReferenceOfByUserIdResult.hpp"
#include "result/DeleteReferenceOfResult.hpp"
#include "result/DeleteReferenceOfByUserIdResult.hpp"
#include "result/DeleteItemSetByUserIdResult.hpp"
#include "result/AcquireItemSetByStampSheetResult.hpp"
#include "result/AddReferenceOfItemSetByStampSheetResult.hpp"
#include "result/DeleteReferenceOfItemSetByStampSheetResult.hpp"
#include "result/ConsumeItemSetByStampTaskResult.hpp"
#include "result/VerifyReferenceOfByStampTaskResult.hpp"
#include <cstring>

namespace gs2 { namespace inventory {

/**
 * GS2 Inventory API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2InventoryWebSocketClient : public AbstractGs2ClientBase
{
private:

    class DescribeNamespacesTask : public detail::Gs2WebSocketSessionTask<DescribeNamespacesResult>
    {
    private:
        DescribeNamespacesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
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
            return "inventory";
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
            if (m_Request.getAcquireScript())
            {
                jsonWriter.writePropertyName("acquireScript");
                write(jsonWriter, *m_Request.getAcquireScript());
            }
            if (m_Request.getOverflowScript())
            {
                jsonWriter.writePropertyName("overflowScript");
                write(jsonWriter, *m_Request.getOverflowScript());
            }
            if (m_Request.getConsumeScript())
            {
                jsonWriter.writePropertyName("consumeScript");
                write(jsonWriter, *m_Request.getConsumeScript());
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
            return "inventory";
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
            return "inventory";
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
            return "inventory";
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
            if (m_Request.getAcquireScript())
            {
                jsonWriter.writePropertyName("acquireScript");
                write(jsonWriter, *m_Request.getAcquireScript());
            }
            if (m_Request.getOverflowScript())
            {
                jsonWriter.writePropertyName("overflowScript");
                write(jsonWriter, *m_Request.getOverflowScript());
            }
            if (m_Request.getConsumeScript())
            {
                jsonWriter.writePropertyName("consumeScript");
                write(jsonWriter, *m_Request.getConsumeScript());
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
            return "inventory";
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

    class DescribeInventoryModelMastersTask : public detail::Gs2WebSocketSessionTask<DescribeInventoryModelMastersResult>
    {
    private:
        DescribeInventoryModelMastersRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "inventoryModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeInventoryModelMasters";
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
        DescribeInventoryModelMastersTask(
            DescribeInventoryModelMastersRequest request,
            Gs2WebSocketSessionTask<DescribeInventoryModelMastersResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeInventoryModelMastersResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeInventoryModelMastersTask() GS2_OVERRIDE = default;
    };

    class CreateInventoryModelMasterTask : public detail::Gs2WebSocketSessionTask<CreateInventoryModelMasterResult>
    {
    private:
        CreateInventoryModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "inventoryModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "createInventoryModelMaster";
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
            if (m_Request.getInitialCapacity())
            {
                jsonWriter.writePropertyName("initialCapacity");
                jsonWriter.writeInt32(*m_Request.getInitialCapacity());
            }
            if (m_Request.getMaxCapacity())
            {
                jsonWriter.writePropertyName("maxCapacity");
                jsonWriter.writeInt32(*m_Request.getMaxCapacity());
            }
            if (m_Request.getProtectReferencedItem())
            {
                jsonWriter.writePropertyName("protectReferencedItem");
                jsonWriter.writeBool(*m_Request.getProtectReferencedItem());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        CreateInventoryModelMasterTask(
            CreateInventoryModelMasterRequest request,
            Gs2WebSocketSessionTask<CreateInventoryModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateInventoryModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateInventoryModelMasterTask() GS2_OVERRIDE = default;
    };

    class GetInventoryModelMasterTask : public detail::Gs2WebSocketSessionTask<GetInventoryModelMasterResult>
    {
    private:
        GetInventoryModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "inventoryModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getInventoryModelMaster";
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
            if (m_Request.getInventoryName())
            {
                jsonWriter.writePropertyName("inventoryName");
                jsonWriter.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetInventoryModelMasterTask(
            GetInventoryModelMasterRequest request,
            Gs2WebSocketSessionTask<GetInventoryModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetInventoryModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetInventoryModelMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateInventoryModelMasterTask : public detail::Gs2WebSocketSessionTask<UpdateInventoryModelMasterResult>
    {
    private:
        UpdateInventoryModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "inventoryModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateInventoryModelMaster";
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
            if (m_Request.getInventoryName())
            {
                jsonWriter.writePropertyName("inventoryName");
                jsonWriter.writeCharArray(*m_Request.getInventoryName());
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
            if (m_Request.getInitialCapacity())
            {
                jsonWriter.writePropertyName("initialCapacity");
                jsonWriter.writeInt32(*m_Request.getInitialCapacity());
            }
            if (m_Request.getMaxCapacity())
            {
                jsonWriter.writePropertyName("maxCapacity");
                jsonWriter.writeInt32(*m_Request.getMaxCapacity());
            }
            if (m_Request.getProtectReferencedItem())
            {
                jsonWriter.writePropertyName("protectReferencedItem");
                jsonWriter.writeBool(*m_Request.getProtectReferencedItem());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        UpdateInventoryModelMasterTask(
            UpdateInventoryModelMasterRequest request,
            Gs2WebSocketSessionTask<UpdateInventoryModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateInventoryModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateInventoryModelMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteInventoryModelMasterTask : public detail::Gs2WebSocketSessionTask<DeleteInventoryModelMasterResult>
    {
    private:
        DeleteInventoryModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "inventoryModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteInventoryModelMaster";
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
            if (m_Request.getInventoryName())
            {
                jsonWriter.writePropertyName("inventoryName");
                jsonWriter.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        DeleteInventoryModelMasterTask(
            DeleteInventoryModelMasterRequest request,
            Gs2WebSocketSessionTask<DeleteInventoryModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteInventoryModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteInventoryModelMasterTask() GS2_OVERRIDE = default;
    };

    class DescribeInventoryModelsTask : public detail::Gs2WebSocketSessionTask<DescribeInventoryModelsResult>
    {
    private:
        DescribeInventoryModelsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "inventoryModel";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeInventoryModels";
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
        DescribeInventoryModelsTask(
            DescribeInventoryModelsRequest request,
            Gs2WebSocketSessionTask<DescribeInventoryModelsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeInventoryModelsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeInventoryModelsTask() GS2_OVERRIDE = default;
    };

    class GetInventoryModelTask : public detail::Gs2WebSocketSessionTask<GetInventoryModelResult>
    {
    private:
        GetInventoryModelRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "inventoryModel";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getInventoryModel";
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
            if (m_Request.getInventoryName())
            {
                jsonWriter.writePropertyName("inventoryName");
                jsonWriter.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetInventoryModelTask(
            GetInventoryModelRequest request,
            Gs2WebSocketSessionTask<GetInventoryModelResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetInventoryModelResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetInventoryModelTask() GS2_OVERRIDE = default;
    };

    class DescribeItemModelMastersTask : public detail::Gs2WebSocketSessionTask<DescribeItemModelMastersResult>
    {
    private:
        DescribeItemModelMastersRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "itemModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeItemModelMasters";
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
            if (m_Request.getInventoryName())
            {
                jsonWriter.writePropertyName("inventoryName");
                jsonWriter.writeCharArray(*m_Request.getInventoryName());
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
        DescribeItemModelMastersTask(
            DescribeItemModelMastersRequest request,
            Gs2WebSocketSessionTask<DescribeItemModelMastersResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeItemModelMastersResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeItemModelMastersTask() GS2_OVERRIDE = default;
    };

    class CreateItemModelMasterTask : public detail::Gs2WebSocketSessionTask<CreateItemModelMasterResult>
    {
    private:
        CreateItemModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "itemModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "createItemModelMaster";
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
            if (m_Request.getInventoryName())
            {
                jsonWriter.writePropertyName("inventoryName");
                jsonWriter.writeCharArray(*m_Request.getInventoryName());
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
            if (m_Request.getStackingLimit())
            {
                jsonWriter.writePropertyName("stackingLimit");
                jsonWriter.writeInt64(*m_Request.getStackingLimit());
            }
            if (m_Request.getAllowMultipleStacks())
            {
                jsonWriter.writePropertyName("allowMultipleStacks");
                jsonWriter.writeBool(*m_Request.getAllowMultipleStacks());
            }
            if (m_Request.getSortValue())
            {
                jsonWriter.writePropertyName("sortValue");
                jsonWriter.writeInt32(*m_Request.getSortValue());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        CreateItemModelMasterTask(
            CreateItemModelMasterRequest request,
            Gs2WebSocketSessionTask<CreateItemModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateItemModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateItemModelMasterTask() GS2_OVERRIDE = default;
    };

    class GetItemModelMasterTask : public detail::Gs2WebSocketSessionTask<GetItemModelMasterResult>
    {
    private:
        GetItemModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "itemModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getItemModelMaster";
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
            if (m_Request.getInventoryName())
            {
                jsonWriter.writePropertyName("inventoryName");
                jsonWriter.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getItemName())
            {
                jsonWriter.writePropertyName("itemName");
                jsonWriter.writeCharArray(*m_Request.getItemName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetItemModelMasterTask(
            GetItemModelMasterRequest request,
            Gs2WebSocketSessionTask<GetItemModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetItemModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetItemModelMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateItemModelMasterTask : public detail::Gs2WebSocketSessionTask<UpdateItemModelMasterResult>
    {
    private:
        UpdateItemModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "itemModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateItemModelMaster";
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
            if (m_Request.getInventoryName())
            {
                jsonWriter.writePropertyName("inventoryName");
                jsonWriter.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getItemName())
            {
                jsonWriter.writePropertyName("itemName");
                jsonWriter.writeCharArray(*m_Request.getItemName());
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
            if (m_Request.getStackingLimit())
            {
                jsonWriter.writePropertyName("stackingLimit");
                jsonWriter.writeInt64(*m_Request.getStackingLimit());
            }
            if (m_Request.getAllowMultipleStacks())
            {
                jsonWriter.writePropertyName("allowMultipleStacks");
                jsonWriter.writeBool(*m_Request.getAllowMultipleStacks());
            }
            if (m_Request.getSortValue())
            {
                jsonWriter.writePropertyName("sortValue");
                jsonWriter.writeInt32(*m_Request.getSortValue());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        UpdateItemModelMasterTask(
            UpdateItemModelMasterRequest request,
            Gs2WebSocketSessionTask<UpdateItemModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateItemModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateItemModelMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteItemModelMasterTask : public detail::Gs2WebSocketSessionTask<DeleteItemModelMasterResult>
    {
    private:
        DeleteItemModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "itemModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteItemModelMaster";
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
            if (m_Request.getInventoryName())
            {
                jsonWriter.writePropertyName("inventoryName");
                jsonWriter.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getItemName())
            {
                jsonWriter.writePropertyName("itemName");
                jsonWriter.writeCharArray(*m_Request.getItemName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        DeleteItemModelMasterTask(
            DeleteItemModelMasterRequest request,
            Gs2WebSocketSessionTask<DeleteItemModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteItemModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteItemModelMasterTask() GS2_OVERRIDE = default;
    };

    class DescribeItemModelsTask : public detail::Gs2WebSocketSessionTask<DescribeItemModelsResult>
    {
    private:
        DescribeItemModelsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "itemModel";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeItemModels";
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
            if (m_Request.getInventoryName())
            {
                jsonWriter.writePropertyName("inventoryName");
                jsonWriter.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        DescribeItemModelsTask(
            DescribeItemModelsRequest request,
            Gs2WebSocketSessionTask<DescribeItemModelsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeItemModelsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeItemModelsTask() GS2_OVERRIDE = default;
    };

    class GetItemModelTask : public detail::Gs2WebSocketSessionTask<GetItemModelResult>
    {
    private:
        GetItemModelRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "itemModel";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getItemModel";
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
            if (m_Request.getInventoryName())
            {
                jsonWriter.writePropertyName("inventoryName");
                jsonWriter.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getItemName())
            {
                jsonWriter.writePropertyName("itemName");
                jsonWriter.writeCharArray(*m_Request.getItemName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetItemModelTask(
            GetItemModelRequest request,
            Gs2WebSocketSessionTask<GetItemModelResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetItemModelResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetItemModelTask() GS2_OVERRIDE = default;
    };

    class ExportMasterTask : public detail::Gs2WebSocketSessionTask<ExportMasterResult>
    {
    private:
        ExportMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "currentItemModelMaster";
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

    class GetCurrentItemModelMasterTask : public detail::Gs2WebSocketSessionTask<GetCurrentItemModelMasterResult>
    {
    private:
        GetCurrentItemModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "currentItemModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getCurrentItemModelMaster";
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
        GetCurrentItemModelMasterTask(
            GetCurrentItemModelMasterRequest request,
            Gs2WebSocketSessionTask<GetCurrentItemModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetCurrentItemModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetCurrentItemModelMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentItemModelMasterTask : public detail::Gs2WebSocketSessionTask<UpdateCurrentItemModelMasterResult>
    {
    private:
        UpdateCurrentItemModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "currentItemModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateCurrentItemModelMaster";
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
        UpdateCurrentItemModelMasterTask(
            UpdateCurrentItemModelMasterRequest request,
            Gs2WebSocketSessionTask<UpdateCurrentItemModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateCurrentItemModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateCurrentItemModelMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentItemModelMasterFromGitHubTask : public detail::Gs2WebSocketSessionTask<UpdateCurrentItemModelMasterFromGitHubResult>
    {
    private:
        UpdateCurrentItemModelMasterFromGitHubRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "currentItemModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateCurrentItemModelMasterFromGitHub";
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
        UpdateCurrentItemModelMasterFromGitHubTask(
            UpdateCurrentItemModelMasterFromGitHubRequest request,
            Gs2WebSocketSessionTask<UpdateCurrentItemModelMasterFromGitHubResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateCurrentItemModelMasterFromGitHubResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateCurrentItemModelMasterFromGitHubTask() GS2_OVERRIDE = default;
    };

    class DescribeInventoriesTask : public detail::Gs2WebSocketSessionTask<DescribeInventoriesResult>
    {
    private:
        DescribeInventoriesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeInventories";
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
        DescribeInventoriesTask(
            DescribeInventoriesRequest request,
            Gs2WebSocketSessionTask<DescribeInventoriesResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeInventoriesResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeInventoriesTask() GS2_OVERRIDE = default;
    };

    class DescribeInventoriesByUserIdTask : public detail::Gs2WebSocketSessionTask<DescribeInventoriesByUserIdResult>
    {
    private:
        DescribeInventoriesByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeInventoriesByUserId";
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
        DescribeInventoriesByUserIdTask(
            DescribeInventoriesByUserIdRequest request,
            Gs2WebSocketSessionTask<DescribeInventoriesByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeInventoriesByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeInventoriesByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetInventoryTask : public detail::Gs2WebSocketSessionTask<GetInventoryResult>
    {
    private:
        GetInventoryRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getInventory";
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
            if (m_Request.getInventoryName())
            {
                jsonWriter.writePropertyName("inventoryName");
                jsonWriter.writeCharArray(*m_Request.getInventoryName());
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
        GetInventoryTask(
            GetInventoryRequest request,
            Gs2WebSocketSessionTask<GetInventoryResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetInventoryResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetInventoryTask() GS2_OVERRIDE = default;
    };

    class GetInventoryByUserIdTask : public detail::Gs2WebSocketSessionTask<GetInventoryByUserIdResult>
    {
    private:
        GetInventoryByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getInventoryByUserId";
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
            if (m_Request.getInventoryName())
            {
                jsonWriter.writePropertyName("inventoryName");
                jsonWriter.writeCharArray(*m_Request.getInventoryName());
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
        GetInventoryByUserIdTask(
            GetInventoryByUserIdRequest request,
            Gs2WebSocketSessionTask<GetInventoryByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetInventoryByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetInventoryByUserIdTask() GS2_OVERRIDE = default;
    };

    class AddCapacityByUserIdTask : public detail::Gs2WebSocketSessionTask<AddCapacityByUserIdResult>
    {
    private:
        AddCapacityByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "addCapacityByUserId";
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
            if (m_Request.getInventoryName())
            {
                jsonWriter.writePropertyName("inventoryName");
                jsonWriter.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getAddCapacityValue())
            {
                jsonWriter.writePropertyName("addCapacityValue");
                jsonWriter.writeInt32(*m_Request.getAddCapacityValue());
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
        AddCapacityByUserIdTask(
            AddCapacityByUserIdRequest request,
            Gs2WebSocketSessionTask<AddCapacityByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<AddCapacityByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~AddCapacityByUserIdTask() GS2_OVERRIDE = default;
    };

    class SetCapacityByUserIdTask : public detail::Gs2WebSocketSessionTask<SetCapacityByUserIdResult>
    {
    private:
        SetCapacityByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "setCapacityByUserId";
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
            if (m_Request.getInventoryName())
            {
                jsonWriter.writePropertyName("inventoryName");
                jsonWriter.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getNewCapacityValue())
            {
                jsonWriter.writePropertyName("newCapacityValue");
                jsonWriter.writeInt32(*m_Request.getNewCapacityValue());
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
        SetCapacityByUserIdTask(
            SetCapacityByUserIdRequest request,
            Gs2WebSocketSessionTask<SetCapacityByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<SetCapacityByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~SetCapacityByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteInventoryByUserIdTask : public detail::Gs2WebSocketSessionTask<DeleteInventoryByUserIdResult>
    {
    private:
        DeleteInventoryByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteInventoryByUserId";
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
            if (m_Request.getInventoryName())
            {
                jsonWriter.writePropertyName("inventoryName");
                jsonWriter.writeCharArray(*m_Request.getInventoryName());
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
        DeleteInventoryByUserIdTask(
            DeleteInventoryByUserIdRequest request,
            Gs2WebSocketSessionTask<DeleteInventoryByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteInventoryByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteInventoryByUserIdTask() GS2_OVERRIDE = default;
    };

    class AddCapacityByStampSheetTask : public detail::Gs2WebSocketSessionTask<AddCapacityByStampSheetResult>
    {
    private:
        AddCapacityByStampSheetRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "addCapacityByStampSheet";
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
        AddCapacityByStampSheetTask(
            AddCapacityByStampSheetRequest request,
            Gs2WebSocketSessionTask<AddCapacityByStampSheetResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<AddCapacityByStampSheetResult>(callback),
            m_Request(std::move(request))
        {}

        ~AddCapacityByStampSheetTask() GS2_OVERRIDE = default;
    };

    class SetCapacityByStampSheetTask : public detail::Gs2WebSocketSessionTask<SetCapacityByStampSheetResult>
    {
    private:
        SetCapacityByStampSheetRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "setCapacityByStampSheet";
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
        SetCapacityByStampSheetTask(
            SetCapacityByStampSheetRequest request,
            Gs2WebSocketSessionTask<SetCapacityByStampSheetResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<SetCapacityByStampSheetResult>(callback),
            m_Request(std::move(request))
        {}

        ~SetCapacityByStampSheetTask() GS2_OVERRIDE = default;
    };

    class DescribeItemSetsTask : public detail::Gs2WebSocketSessionTask<DescribeItemSetsResult>
    {
    private:
        DescribeItemSetsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "itemSet";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeItemSets";
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
            if (m_Request.getInventoryName())
            {
                jsonWriter.writePropertyName("inventoryName");
                jsonWriter.writeCharArray(*m_Request.getInventoryName());
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
        DescribeItemSetsTask(
            DescribeItemSetsRequest request,
            Gs2WebSocketSessionTask<DescribeItemSetsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeItemSetsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeItemSetsTask() GS2_OVERRIDE = default;
    };

    class DescribeItemSetsByUserIdTask : public detail::Gs2WebSocketSessionTask<DescribeItemSetsByUserIdResult>
    {
    private:
        DescribeItemSetsByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "itemSet";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeItemSetsByUserId";
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
            if (m_Request.getInventoryName())
            {
                jsonWriter.writePropertyName("inventoryName");
                jsonWriter.writeCharArray(*m_Request.getInventoryName());
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
        DescribeItemSetsByUserIdTask(
            DescribeItemSetsByUserIdRequest request,
            Gs2WebSocketSessionTask<DescribeItemSetsByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeItemSetsByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeItemSetsByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetItemSetTask : public detail::Gs2WebSocketSessionTask<GetItemSetResult>
    {
    private:
        GetItemSetRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "itemSet";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getItemSet";
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
            if (m_Request.getInventoryName())
            {
                jsonWriter.writePropertyName("inventoryName");
                jsonWriter.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getItemName())
            {
                jsonWriter.writePropertyName("itemName");
                jsonWriter.writeCharArray(*m_Request.getItemName());
            }
            if (m_Request.getItemSetName())
            {
                jsonWriter.writePropertyName("itemSetName");
                jsonWriter.writeCharArray(*m_Request.getItemSetName());
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
        GetItemSetTask(
            GetItemSetRequest request,
            Gs2WebSocketSessionTask<GetItemSetResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetItemSetResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetItemSetTask() GS2_OVERRIDE = default;
    };

    class GetItemSetByUserIdTask : public detail::Gs2WebSocketSessionTask<GetItemSetByUserIdResult>
    {
    private:
        GetItemSetByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "itemSet";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getItemSetByUserId";
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
            if (m_Request.getInventoryName())
            {
                jsonWriter.writePropertyName("inventoryName");
                jsonWriter.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getItemName())
            {
                jsonWriter.writePropertyName("itemName");
                jsonWriter.writeCharArray(*m_Request.getItemName());
            }
            if (m_Request.getItemSetName())
            {
                jsonWriter.writePropertyName("itemSetName");
                jsonWriter.writeCharArray(*m_Request.getItemSetName());
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
        GetItemSetByUserIdTask(
            GetItemSetByUserIdRequest request,
            Gs2WebSocketSessionTask<GetItemSetByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetItemSetByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetItemSetByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetItemWithSignatureTask : public detail::Gs2WebSocketSessionTask<GetItemWithSignatureResult>
    {
    private:
        GetItemWithSignatureRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "itemSet";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getItemWithSignature";
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
            if (m_Request.getInventoryName())
            {
                jsonWriter.writePropertyName("inventoryName");
                jsonWriter.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getItemName())
            {
                jsonWriter.writePropertyName("itemName");
                jsonWriter.writeCharArray(*m_Request.getItemName());
            }
            if (m_Request.getItemSetName())
            {
                jsonWriter.writePropertyName("itemSetName");
                jsonWriter.writeCharArray(*m_Request.getItemSetName());
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
        GetItemWithSignatureTask(
            GetItemWithSignatureRequest request,
            Gs2WebSocketSessionTask<GetItemWithSignatureResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetItemWithSignatureResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetItemWithSignatureTask() GS2_OVERRIDE = default;
    };

    class GetItemWithSignatureByUserIdTask : public detail::Gs2WebSocketSessionTask<GetItemWithSignatureByUserIdResult>
    {
    private:
        GetItemWithSignatureByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "itemSet";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getItemWithSignatureByUserId";
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
            if (m_Request.getInventoryName())
            {
                jsonWriter.writePropertyName("inventoryName");
                jsonWriter.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getItemName())
            {
                jsonWriter.writePropertyName("itemName");
                jsonWriter.writeCharArray(*m_Request.getItemName());
            }
            if (m_Request.getItemSetName())
            {
                jsonWriter.writePropertyName("itemSetName");
                jsonWriter.writeCharArray(*m_Request.getItemSetName());
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
        GetItemWithSignatureByUserIdTask(
            GetItemWithSignatureByUserIdRequest request,
            Gs2WebSocketSessionTask<GetItemWithSignatureByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetItemWithSignatureByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetItemWithSignatureByUserIdTask() GS2_OVERRIDE = default;
    };

    class AcquireItemSetByUserIdTask : public detail::Gs2WebSocketSessionTask<AcquireItemSetByUserIdResult>
    {
    private:
        AcquireItemSetByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "itemSet";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "acquireItemSetByUserId";
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
            if (m_Request.getInventoryName())
            {
                jsonWriter.writePropertyName("inventoryName");
                jsonWriter.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getItemName())
            {
                jsonWriter.writePropertyName("itemName");
                jsonWriter.writeCharArray(*m_Request.getItemName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getAcquireCount())
            {
                jsonWriter.writePropertyName("acquireCount");
                jsonWriter.writeInt64(*m_Request.getAcquireCount());
            }
            if (m_Request.getExpiresAt())
            {
                jsonWriter.writePropertyName("expiresAt");
                jsonWriter.writeInt64(*m_Request.getExpiresAt());
            }
            if (m_Request.getCreateNewItemSet())
            {
                jsonWriter.writePropertyName("createNewItemSet");
                jsonWriter.writeBool(*m_Request.getCreateNewItemSet());
            }
            if (m_Request.getItemSetName())
            {
                jsonWriter.writePropertyName("itemSetName");
                jsonWriter.writeCharArray(*m_Request.getItemSetName());
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
        AcquireItemSetByUserIdTask(
            AcquireItemSetByUserIdRequest request,
            Gs2WebSocketSessionTask<AcquireItemSetByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<AcquireItemSetByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~AcquireItemSetByUserIdTask() GS2_OVERRIDE = default;
    };

    class ConsumeItemSetTask : public detail::Gs2WebSocketSessionTask<ConsumeItemSetResult>
    {
    private:
        ConsumeItemSetRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "itemSet";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "consumeItemSet";
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
            if (m_Request.getInventoryName())
            {
                jsonWriter.writePropertyName("inventoryName");
                jsonWriter.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getItemName())
            {
                jsonWriter.writePropertyName("itemName");
                jsonWriter.writeCharArray(*m_Request.getItemName());
            }
            if (m_Request.getConsumeCount())
            {
                jsonWriter.writePropertyName("consumeCount");
                jsonWriter.writeInt64(*m_Request.getConsumeCount());
            }
            if (m_Request.getItemSetName())
            {
                jsonWriter.writePropertyName("itemSetName");
                jsonWriter.writeCharArray(*m_Request.getItemSetName());
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
        ConsumeItemSetTask(
            ConsumeItemSetRequest request,
            Gs2WebSocketSessionTask<ConsumeItemSetResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<ConsumeItemSetResult>(callback),
            m_Request(std::move(request))
        {}

        ~ConsumeItemSetTask() GS2_OVERRIDE = default;
    };

    class ConsumeItemSetByUserIdTask : public detail::Gs2WebSocketSessionTask<ConsumeItemSetByUserIdResult>
    {
    private:
        ConsumeItemSetByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "itemSet";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "consumeItemSetByUserId";
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
            if (m_Request.getInventoryName())
            {
                jsonWriter.writePropertyName("inventoryName");
                jsonWriter.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getItemName())
            {
                jsonWriter.writePropertyName("itemName");
                jsonWriter.writeCharArray(*m_Request.getItemName());
            }
            if (m_Request.getConsumeCount())
            {
                jsonWriter.writePropertyName("consumeCount");
                jsonWriter.writeInt64(*m_Request.getConsumeCount());
            }
            if (m_Request.getItemSetName())
            {
                jsonWriter.writePropertyName("itemSetName");
                jsonWriter.writeCharArray(*m_Request.getItemSetName());
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
        ConsumeItemSetByUserIdTask(
            ConsumeItemSetByUserIdRequest request,
            Gs2WebSocketSessionTask<ConsumeItemSetByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<ConsumeItemSetByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~ConsumeItemSetByUserIdTask() GS2_OVERRIDE = default;
    };

    class DescribeReferenceOfTask : public detail::Gs2WebSocketSessionTask<DescribeReferenceOfResult>
    {
    private:
        DescribeReferenceOfRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "itemSet";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeReferenceOf";
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
            if (m_Request.getInventoryName())
            {
                jsonWriter.writePropertyName("inventoryName");
                jsonWriter.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getItemName())
            {
                jsonWriter.writePropertyName("itemName");
                jsonWriter.writeCharArray(*m_Request.getItemName());
            }
            if (m_Request.getItemSetName())
            {
                jsonWriter.writePropertyName("itemSetName");
                jsonWriter.writeCharArray(*m_Request.getItemSetName());
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
        DescribeReferenceOfTask(
            DescribeReferenceOfRequest request,
            Gs2WebSocketSessionTask<DescribeReferenceOfResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeReferenceOfResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeReferenceOfTask() GS2_OVERRIDE = default;
    };

    class DescribeReferenceOfByUserIdTask : public detail::Gs2WebSocketSessionTask<DescribeReferenceOfByUserIdResult>
    {
    private:
        DescribeReferenceOfByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "itemSet";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeReferenceOfByUserId";
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
            if (m_Request.getInventoryName())
            {
                jsonWriter.writePropertyName("inventoryName");
                jsonWriter.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getItemName())
            {
                jsonWriter.writePropertyName("itemName");
                jsonWriter.writeCharArray(*m_Request.getItemName());
            }
            if (m_Request.getItemSetName())
            {
                jsonWriter.writePropertyName("itemSetName");
                jsonWriter.writeCharArray(*m_Request.getItemSetName());
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
        DescribeReferenceOfByUserIdTask(
            DescribeReferenceOfByUserIdRequest request,
            Gs2WebSocketSessionTask<DescribeReferenceOfByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeReferenceOfByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeReferenceOfByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetReferenceOfTask : public detail::Gs2WebSocketSessionTask<GetReferenceOfResult>
    {
    private:
        GetReferenceOfRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "itemSet";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getReferenceOf";
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
            if (m_Request.getInventoryName())
            {
                jsonWriter.writePropertyName("inventoryName");
                jsonWriter.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getItemName())
            {
                jsonWriter.writePropertyName("itemName");
                jsonWriter.writeCharArray(*m_Request.getItemName());
            }
            if (m_Request.getItemSetName())
            {
                jsonWriter.writePropertyName("itemSetName");
                jsonWriter.writeCharArray(*m_Request.getItemSetName());
            }
            if (m_Request.getReferenceOf())
            {
                jsonWriter.writePropertyName("referenceOf");
                jsonWriter.writeCharArray(*m_Request.getReferenceOf());
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
        GetReferenceOfTask(
            GetReferenceOfRequest request,
            Gs2WebSocketSessionTask<GetReferenceOfResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetReferenceOfResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetReferenceOfTask() GS2_OVERRIDE = default;
    };

    class GetReferenceOfByUserIdTask : public detail::Gs2WebSocketSessionTask<GetReferenceOfByUserIdResult>
    {
    private:
        GetReferenceOfByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "itemSet";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getReferenceOfByUserId";
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
            if (m_Request.getInventoryName())
            {
                jsonWriter.writePropertyName("inventoryName");
                jsonWriter.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getItemName())
            {
                jsonWriter.writePropertyName("itemName");
                jsonWriter.writeCharArray(*m_Request.getItemName());
            }
            if (m_Request.getItemSetName())
            {
                jsonWriter.writePropertyName("itemSetName");
                jsonWriter.writeCharArray(*m_Request.getItemSetName());
            }
            if (m_Request.getReferenceOf())
            {
                jsonWriter.writePropertyName("referenceOf");
                jsonWriter.writeCharArray(*m_Request.getReferenceOf());
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
        GetReferenceOfByUserIdTask(
            GetReferenceOfByUserIdRequest request,
            Gs2WebSocketSessionTask<GetReferenceOfByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetReferenceOfByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetReferenceOfByUserIdTask() GS2_OVERRIDE = default;
    };

    class VerifyReferenceOfTask : public detail::Gs2WebSocketSessionTask<VerifyReferenceOfResult>
    {
    private:
        VerifyReferenceOfRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "itemSet";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "verifyReferenceOf";
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
            if (m_Request.getInventoryName())
            {
                jsonWriter.writePropertyName("inventoryName");
                jsonWriter.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getItemName())
            {
                jsonWriter.writePropertyName("itemName");
                jsonWriter.writeCharArray(*m_Request.getItemName());
            }
            if (m_Request.getItemSetName())
            {
                jsonWriter.writePropertyName("itemSetName");
                jsonWriter.writeCharArray(*m_Request.getItemSetName());
            }
            if (m_Request.getReferenceOf())
            {
                jsonWriter.writePropertyName("referenceOf");
                jsonWriter.writeCharArray(*m_Request.getReferenceOf());
            }
            if (m_Request.getVerifyType())
            {
                jsonWriter.writePropertyName("verifyType");
                jsonWriter.writeCharArray(*m_Request.getVerifyType());
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
        VerifyReferenceOfTask(
            VerifyReferenceOfRequest request,
            Gs2WebSocketSessionTask<VerifyReferenceOfResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<VerifyReferenceOfResult>(callback),
            m_Request(std::move(request))
        {}

        ~VerifyReferenceOfTask() GS2_OVERRIDE = default;
    };

    class VerifyReferenceOfByUserIdTask : public detail::Gs2WebSocketSessionTask<VerifyReferenceOfByUserIdResult>
    {
    private:
        VerifyReferenceOfByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "itemSet";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "verifyReferenceOfByUserId";
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
            if (m_Request.getInventoryName())
            {
                jsonWriter.writePropertyName("inventoryName");
                jsonWriter.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getItemName())
            {
                jsonWriter.writePropertyName("itemName");
                jsonWriter.writeCharArray(*m_Request.getItemName());
            }
            if (m_Request.getItemSetName())
            {
                jsonWriter.writePropertyName("itemSetName");
                jsonWriter.writeCharArray(*m_Request.getItemSetName());
            }
            if (m_Request.getReferenceOf())
            {
                jsonWriter.writePropertyName("referenceOf");
                jsonWriter.writeCharArray(*m_Request.getReferenceOf());
            }
            if (m_Request.getVerifyType())
            {
                jsonWriter.writePropertyName("verifyType");
                jsonWriter.writeCharArray(*m_Request.getVerifyType());
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
        VerifyReferenceOfByUserIdTask(
            VerifyReferenceOfByUserIdRequest request,
            Gs2WebSocketSessionTask<VerifyReferenceOfByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<VerifyReferenceOfByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~VerifyReferenceOfByUserIdTask() GS2_OVERRIDE = default;
    };

    class AddReferenceOfTask : public detail::Gs2WebSocketSessionTask<AddReferenceOfResult>
    {
    private:
        AddReferenceOfRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "itemSet";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "addReferenceOf";
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
            if (m_Request.getInventoryName())
            {
                jsonWriter.writePropertyName("inventoryName");
                jsonWriter.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getItemName())
            {
                jsonWriter.writePropertyName("itemName");
                jsonWriter.writeCharArray(*m_Request.getItemName());
            }
            if (m_Request.getItemSetName())
            {
                jsonWriter.writePropertyName("itemSetName");
                jsonWriter.writeCharArray(*m_Request.getItemSetName());
            }
            if (m_Request.getReferenceOf())
            {
                jsonWriter.writePropertyName("referenceOf");
                jsonWriter.writeCharArray(*m_Request.getReferenceOf());
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
        AddReferenceOfTask(
            AddReferenceOfRequest request,
            Gs2WebSocketSessionTask<AddReferenceOfResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<AddReferenceOfResult>(callback),
            m_Request(std::move(request))
        {}

        ~AddReferenceOfTask() GS2_OVERRIDE = default;
    };

    class AddReferenceOfByUserIdTask : public detail::Gs2WebSocketSessionTask<AddReferenceOfByUserIdResult>
    {
    private:
        AddReferenceOfByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "itemSet";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "addReferenceOfByUserId";
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
            if (m_Request.getInventoryName())
            {
                jsonWriter.writePropertyName("inventoryName");
                jsonWriter.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getItemName())
            {
                jsonWriter.writePropertyName("itemName");
                jsonWriter.writeCharArray(*m_Request.getItemName());
            }
            if (m_Request.getItemSetName())
            {
                jsonWriter.writePropertyName("itemSetName");
                jsonWriter.writeCharArray(*m_Request.getItemSetName());
            }
            if (m_Request.getReferenceOf())
            {
                jsonWriter.writePropertyName("referenceOf");
                jsonWriter.writeCharArray(*m_Request.getReferenceOf());
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
        AddReferenceOfByUserIdTask(
            AddReferenceOfByUserIdRequest request,
            Gs2WebSocketSessionTask<AddReferenceOfByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<AddReferenceOfByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~AddReferenceOfByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteReferenceOfTask : public detail::Gs2WebSocketSessionTask<DeleteReferenceOfResult>
    {
    private:
        DeleteReferenceOfRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "itemSet";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteReferenceOf";
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
            if (m_Request.getInventoryName())
            {
                jsonWriter.writePropertyName("inventoryName");
                jsonWriter.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getItemName())
            {
                jsonWriter.writePropertyName("itemName");
                jsonWriter.writeCharArray(*m_Request.getItemName());
            }
            if (m_Request.getItemSetName())
            {
                jsonWriter.writePropertyName("itemSetName");
                jsonWriter.writeCharArray(*m_Request.getItemSetName());
            }
            if (m_Request.getReferenceOf())
            {
                jsonWriter.writePropertyName("referenceOf");
                jsonWriter.writeCharArray(*m_Request.getReferenceOf());
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
        DeleteReferenceOfTask(
            DeleteReferenceOfRequest request,
            Gs2WebSocketSessionTask<DeleteReferenceOfResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteReferenceOfResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteReferenceOfTask() GS2_OVERRIDE = default;
    };

    class DeleteReferenceOfByUserIdTask : public detail::Gs2WebSocketSessionTask<DeleteReferenceOfByUserIdResult>
    {
    private:
        DeleteReferenceOfByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "itemSet";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteReferenceOfByUserId";
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
            if (m_Request.getInventoryName())
            {
                jsonWriter.writePropertyName("inventoryName");
                jsonWriter.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getItemName())
            {
                jsonWriter.writePropertyName("itemName");
                jsonWriter.writeCharArray(*m_Request.getItemName());
            }
            if (m_Request.getItemSetName())
            {
                jsonWriter.writePropertyName("itemSetName");
                jsonWriter.writeCharArray(*m_Request.getItemSetName());
            }
            if (m_Request.getReferenceOf())
            {
                jsonWriter.writePropertyName("referenceOf");
                jsonWriter.writeCharArray(*m_Request.getReferenceOf());
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
        DeleteReferenceOfByUserIdTask(
            DeleteReferenceOfByUserIdRequest request,
            Gs2WebSocketSessionTask<DeleteReferenceOfByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteReferenceOfByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteReferenceOfByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteItemSetByUserIdTask : public detail::Gs2WebSocketSessionTask<DeleteItemSetByUserIdResult>
    {
    private:
        DeleteItemSetByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "itemSet";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteItemSetByUserId";
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
            if (m_Request.getInventoryName())
            {
                jsonWriter.writePropertyName("inventoryName");
                jsonWriter.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getItemName())
            {
                jsonWriter.writePropertyName("itemName");
                jsonWriter.writeCharArray(*m_Request.getItemName());
            }
            if (m_Request.getItemSetName())
            {
                jsonWriter.writePropertyName("itemSetName");
                jsonWriter.writeCharArray(*m_Request.getItemSetName());
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
        DeleteItemSetByUserIdTask(
            DeleteItemSetByUserIdRequest request,
            Gs2WebSocketSessionTask<DeleteItemSetByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteItemSetByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteItemSetByUserIdTask() GS2_OVERRIDE = default;
    };

    class AcquireItemSetByStampSheetTask : public detail::Gs2WebSocketSessionTask<AcquireItemSetByStampSheetResult>
    {
    private:
        AcquireItemSetByStampSheetRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "itemSet";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "acquireItemSetByStampSheet";
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
        AcquireItemSetByStampSheetTask(
            AcquireItemSetByStampSheetRequest request,
            Gs2WebSocketSessionTask<AcquireItemSetByStampSheetResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<AcquireItemSetByStampSheetResult>(callback),
            m_Request(std::move(request))
        {}

        ~AcquireItemSetByStampSheetTask() GS2_OVERRIDE = default;
    };

    class AddReferenceOfItemSetByStampSheetTask : public detail::Gs2WebSocketSessionTask<AddReferenceOfItemSetByStampSheetResult>
    {
    private:
        AddReferenceOfItemSetByStampSheetRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "itemSet";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "addReferenceOfItemSetByStampSheet";
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
        AddReferenceOfItemSetByStampSheetTask(
            AddReferenceOfItemSetByStampSheetRequest request,
            Gs2WebSocketSessionTask<AddReferenceOfItemSetByStampSheetResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<AddReferenceOfItemSetByStampSheetResult>(callback),
            m_Request(std::move(request))
        {}

        ~AddReferenceOfItemSetByStampSheetTask() GS2_OVERRIDE = default;
    };

    class DeleteReferenceOfItemSetByStampSheetTask : public detail::Gs2WebSocketSessionTask<DeleteReferenceOfItemSetByStampSheetResult>
    {
    private:
        DeleteReferenceOfItemSetByStampSheetRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "itemSet";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteReferenceOfItemSetByStampSheet";
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
        DeleteReferenceOfItemSetByStampSheetTask(
            DeleteReferenceOfItemSetByStampSheetRequest request,
            Gs2WebSocketSessionTask<DeleteReferenceOfItemSetByStampSheetResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteReferenceOfItemSetByStampSheetResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteReferenceOfItemSetByStampSheetTask() GS2_OVERRIDE = default;
    };

    class ConsumeItemSetByStampTaskTask : public detail::Gs2WebSocketSessionTask<ConsumeItemSetByStampTaskResult>
    {
    private:
        ConsumeItemSetByStampTaskRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "itemSet";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "consumeItemSetByStampTask";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getStampTask())
            {
                jsonWriter.writePropertyName("stampTask");
                jsonWriter.writeCharArray(*m_Request.getStampTask());
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
        ConsumeItemSetByStampTaskTask(
            ConsumeItemSetByStampTaskRequest request,
            Gs2WebSocketSessionTask<ConsumeItemSetByStampTaskResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<ConsumeItemSetByStampTaskResult>(callback),
            m_Request(std::move(request))
        {}

        ~ConsumeItemSetByStampTaskTask() GS2_OVERRIDE = default;
    };

    class VerifyReferenceOfByStampTaskTask : public detail::Gs2WebSocketSessionTask<VerifyReferenceOfByStampTaskResult>
    {
    private:
        VerifyReferenceOfByStampTaskRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "itemSet";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "verifyReferenceOfByStampTask";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getStampTask())
            {
                jsonWriter.writePropertyName("stampTask");
                jsonWriter.writeCharArray(*m_Request.getStampTask());
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
        VerifyReferenceOfByStampTaskTask(
            VerifyReferenceOfByStampTaskRequest request,
            Gs2WebSocketSessionTask<VerifyReferenceOfByStampTaskResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<VerifyReferenceOfByStampTaskResult>(callback),
            m_Request(std::move(request))
        {}

        ~VerifyReferenceOfByStampTaskTask() GS2_OVERRIDE = default;
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
        if (obj.getAcquireScript())
        {
            jsonWriter.writePropertyName("acquireScript");
            write(jsonWriter, *obj.getAcquireScript());
        }
        if (obj.getOverflowScript())
        {
            jsonWriter.writePropertyName("overflowScript");
            write(jsonWriter, *obj.getOverflowScript());
        }
        if (obj.getConsumeScript())
        {
            jsonWriter.writePropertyName("consumeScript");
            write(jsonWriter, *obj.getConsumeScript());
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

    static void write(detail::json::JsonWriter& jsonWriter, const InventoryModelMaster& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getInventoryModelId())
        {
            jsonWriter.writePropertyName("inventoryModelId");
            jsonWriter.writeCharArray(*obj.getInventoryModelId());
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
        if (obj.getDescription())
        {
            jsonWriter.writePropertyName("description");
            jsonWriter.writeCharArray(*obj.getDescription());
        }
        if (obj.getInitialCapacity())
        {
            jsonWriter.writePropertyName("initialCapacity");
            jsonWriter.writeInt32(*obj.getInitialCapacity());
        }
        if (obj.getMaxCapacity())
        {
            jsonWriter.writePropertyName("maxCapacity");
            jsonWriter.writeInt32(*obj.getMaxCapacity());
        }
        if (obj.getProtectReferencedItem())
        {
            jsonWriter.writePropertyName("protectReferencedItem");
            jsonWriter.writeBool(*obj.getProtectReferencedItem());
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

    static void write(detail::json::JsonWriter& jsonWriter, const InventoryModel& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getInventoryModelId())
        {
            jsonWriter.writePropertyName("inventoryModelId");
            jsonWriter.writeCharArray(*obj.getInventoryModelId());
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
        if (obj.getInitialCapacity())
        {
            jsonWriter.writePropertyName("initialCapacity");
            jsonWriter.writeInt32(*obj.getInitialCapacity());
        }
        if (obj.getMaxCapacity())
        {
            jsonWriter.writePropertyName("maxCapacity");
            jsonWriter.writeInt32(*obj.getMaxCapacity());
        }
        if (obj.getProtectReferencedItem())
        {
            jsonWriter.writePropertyName("protectReferencedItem");
            jsonWriter.writeBool(*obj.getProtectReferencedItem());
        }
        if (obj.getItemModels())
        {
            jsonWriter.writePropertyName("itemModels");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getItemModels();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const ItemModelMaster& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getItemModelId())
        {
            jsonWriter.writePropertyName("itemModelId");
            jsonWriter.writeCharArray(*obj.getItemModelId());
        }
        if (obj.getInventoryName())
        {
            jsonWriter.writePropertyName("inventoryName");
            jsonWriter.writeCharArray(*obj.getInventoryName());
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
        if (obj.getStackingLimit())
        {
            jsonWriter.writePropertyName("stackingLimit");
            jsonWriter.writeInt64(*obj.getStackingLimit());
        }
        if (obj.getAllowMultipleStacks())
        {
            jsonWriter.writePropertyName("allowMultipleStacks");
            jsonWriter.writeBool(*obj.getAllowMultipleStacks());
        }
        if (obj.getSortValue())
        {
            jsonWriter.writePropertyName("sortValue");
            jsonWriter.writeInt32(*obj.getSortValue());
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

    static void write(detail::json::JsonWriter& jsonWriter, const ItemModel& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getItemModelId())
        {
            jsonWriter.writePropertyName("itemModelId");
            jsonWriter.writeCharArray(*obj.getItemModelId());
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
        if (obj.getStackingLimit())
        {
            jsonWriter.writePropertyName("stackingLimit");
            jsonWriter.writeInt64(*obj.getStackingLimit());
        }
        if (obj.getAllowMultipleStacks())
        {
            jsonWriter.writePropertyName("allowMultipleStacks");
            jsonWriter.writeBool(*obj.getAllowMultipleStacks());
        }
        if (obj.getSortValue())
        {
            jsonWriter.writePropertyName("sortValue");
            jsonWriter.writeInt32(*obj.getSortValue());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const CurrentItemModelMaster& obj)
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

    static void write(detail::json::JsonWriter& jsonWriter, const Inventory& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getInventoryId())
        {
            jsonWriter.writePropertyName("inventoryId");
            jsonWriter.writeCharArray(*obj.getInventoryId());
        }
        if (obj.getInventoryName())
        {
            jsonWriter.writePropertyName("inventoryName");
            jsonWriter.writeCharArray(*obj.getInventoryName());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getCurrentInventoryCapacityUsage())
        {
            jsonWriter.writePropertyName("currentInventoryCapacityUsage");
            jsonWriter.writeInt32(*obj.getCurrentInventoryCapacityUsage());
        }
        if (obj.getCurrentInventoryMaxCapacity())
        {
            jsonWriter.writePropertyName("currentInventoryMaxCapacity");
            jsonWriter.writeInt32(*obj.getCurrentInventoryMaxCapacity());
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

    static void write(detail::json::JsonWriter& jsonWriter, const ItemSet& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getItemSetId())
        {
            jsonWriter.writePropertyName("itemSetId");
            jsonWriter.writeCharArray(*obj.getItemSetId());
        }
        if (obj.getName())
        {
            jsonWriter.writePropertyName("name");
            jsonWriter.writeCharArray(*obj.getName());
        }
        if (obj.getInventoryName())
        {
            jsonWriter.writePropertyName("inventoryName");
            jsonWriter.writeCharArray(*obj.getInventoryName());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getItemName())
        {
            jsonWriter.writePropertyName("itemName");
            jsonWriter.writeCharArray(*obj.getItemName());
        }
        if (obj.getCount())
        {
            jsonWriter.writePropertyName("count");
            jsonWriter.writeInt64(*obj.getCount());
        }
        if (obj.getReferenceOf())
        {
            jsonWriter.writePropertyName("referenceOf");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getReferenceOf();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                jsonWriter.writeCharArray(list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (obj.getSortValue())
        {
            jsonWriter.writePropertyName("sortValue");
            jsonWriter.writeInt32(*obj.getSortValue());
        }
        if (obj.getExpiresAt())
        {
            jsonWriter.writePropertyName("expiresAt");
            jsonWriter.writeInt64(*obj.getExpiresAt());
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

    static void write(detail::json::JsonWriter& jsonWriter, const ItemSetGroup& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getItemSetGroupId())
        {
            jsonWriter.writePropertyName("itemSetGroupId");
            jsonWriter.writeCharArray(*obj.getItemSetGroupId());
        }
        if (obj.getInventoryName())
        {
            jsonWriter.writePropertyName("inventoryName");
            jsonWriter.writeCharArray(*obj.getInventoryName());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getItemName())
        {
            jsonWriter.writePropertyName("itemName");
            jsonWriter.writeCharArray(*obj.getItemName());
        }
        if (obj.getSortValue())
        {
            jsonWriter.writePropertyName("sortValue");
            jsonWriter.writeInt32(*obj.getSortValue());
        }
        if (obj.getItemSetItemSetIdList())
        {
            jsonWriter.writePropertyName("itemSetItemSetIdList");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getItemSetItemSetIdList();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                jsonWriter.writeCharArray(list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (obj.getItemSetNameList())
        {
            jsonWriter.writePropertyName("itemSetNameList");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getItemSetNameList();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                jsonWriter.writeCharArray(list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (obj.getItemSetCountList())
        {
            jsonWriter.writePropertyName("itemSetCountList");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getItemSetCountList();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                jsonWriter.writeInt64(list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (obj.getItemSetReferenceOfList())
        {
            jsonWriter.writePropertyName("itemSetReferenceOfList");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getItemSetReferenceOfList();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                jsonWriter.writeInt32(list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (obj.getItemSetExpiresAtList())
        {
            jsonWriter.writePropertyName("itemSetExpiresAtList");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getItemSetExpiresAtList();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                jsonWriter.writeInt64(list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (obj.getItemSetCreatedAtList())
        {
            jsonWriter.writePropertyName("itemSetCreatedAtList");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getItemSetCreatedAtList();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                jsonWriter.writeInt64(list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (obj.getItemSetUpdatedAtList())
        {
            jsonWriter.writePropertyName("itemSetUpdatedAtList");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getItemSetUpdatedAtList();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                jsonWriter.writeInt64(list[i]);
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

    static void write(detail::json::JsonWriter& jsonWriter, const ScriptSetting& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getTriggerScriptId())
        {
            jsonWriter.writePropertyName("triggerScriptId");
            jsonWriter.writeCharArray(*obj.getTriggerScriptId());
        }
        if (obj.getDoneTriggerTargetType())
        {
            jsonWriter.writePropertyName("doneTriggerTargetType");
            jsonWriter.writeCharArray(*obj.getDoneTriggerTargetType());
        }
        if (obj.getDoneTriggerScriptId())
        {
            jsonWriter.writePropertyName("doneTriggerScriptId");
            jsonWriter.writeCharArray(*obj.getDoneTriggerScriptId());
        }
        if (obj.getDoneTriggerQueueNamespaceId())
        {
            jsonWriter.writePropertyName("doneTriggerQueueNamespaceId");
            jsonWriter.writeCharArray(*obj.getDoneTriggerQueueNamespaceId());
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
    explicit Gs2InventoryWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
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
	 * ネームスペースの状態を取得<br>
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
	 * インベントリモデルマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeInventoryModelMasters(DescribeInventoryModelMastersRequest request, std::function<void(AsyncDescribeInventoryModelMastersResult)> callback)
    {
        DescribeInventoryModelMastersTask& task = *new DescribeInventoryModelMastersTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * インベントリモデルマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createInventoryModelMaster(CreateInventoryModelMasterRequest request, std::function<void(AsyncCreateInventoryModelMasterResult)> callback)
    {
        CreateInventoryModelMasterTask& task = *new CreateInventoryModelMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * インベントリモデルマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getInventoryModelMaster(GetInventoryModelMasterRequest request, std::function<void(AsyncGetInventoryModelMasterResult)> callback)
    {
        GetInventoryModelMasterTask& task = *new GetInventoryModelMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * インベントリモデルマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateInventoryModelMaster(UpdateInventoryModelMasterRequest request, std::function<void(AsyncUpdateInventoryModelMasterResult)> callback)
    {
        UpdateInventoryModelMasterTask& task = *new UpdateInventoryModelMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * インベントリモデルマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteInventoryModelMaster(DeleteInventoryModelMasterRequest request, std::function<void(AsyncDeleteInventoryModelMasterResult)> callback)
    {
        DeleteInventoryModelMasterTask& task = *new DeleteInventoryModelMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * インベントリモデルの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeInventoryModels(DescribeInventoryModelsRequest request, std::function<void(AsyncDescribeInventoryModelsResult)> callback)
    {
        DescribeInventoryModelsTask& task = *new DescribeInventoryModelsTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * インベントリモデルを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getInventoryModel(GetInventoryModelRequest request, std::function<void(AsyncGetInventoryModelResult)> callback)
    {
        GetInventoryModelTask& task = *new GetInventoryModelTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * アイテムモデルマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeItemModelMasters(DescribeItemModelMastersRequest request, std::function<void(AsyncDescribeItemModelMastersResult)> callback)
    {
        DescribeItemModelMastersTask& task = *new DescribeItemModelMastersTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * アイテムモデルマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createItemModelMaster(CreateItemModelMasterRequest request, std::function<void(AsyncCreateItemModelMasterResult)> callback)
    {
        CreateItemModelMasterTask& task = *new CreateItemModelMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * アイテムモデルマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getItemModelMaster(GetItemModelMasterRequest request, std::function<void(AsyncGetItemModelMasterResult)> callback)
    {
        GetItemModelMasterTask& task = *new GetItemModelMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * アイテムモデルマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateItemModelMaster(UpdateItemModelMasterRequest request, std::function<void(AsyncUpdateItemModelMasterResult)> callback)
    {
        UpdateItemModelMasterTask& task = *new UpdateItemModelMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * アイテムモデルマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteItemModelMaster(DeleteItemModelMasterRequest request, std::function<void(AsyncDeleteItemModelMasterResult)> callback)
    {
        DeleteItemModelMasterTask& task = *new DeleteItemModelMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * Noneの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeItemModels(DescribeItemModelsRequest request, std::function<void(AsyncDescribeItemModelsResult)> callback)
    {
        DescribeItemModelsTask& task = *new DescribeItemModelsTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * Noneを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getItemModel(GetItemModelRequest request, std::function<void(AsyncGetItemModelResult)> callback)
    {
        GetItemModelTask& task = *new GetItemModelTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 現在有効な所持品マスターのマスターデータをエクスポートします<br>
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
	 * 現在有効な所持品マスターを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentItemModelMaster(GetCurrentItemModelMasterRequest request, std::function<void(AsyncGetCurrentItemModelMasterResult)> callback)
    {
        GetCurrentItemModelMasterTask& task = *new GetCurrentItemModelMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 現在有効な所持品マスターを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentItemModelMaster(UpdateCurrentItemModelMasterRequest request, std::function<void(AsyncUpdateCurrentItemModelMasterResult)> callback)
    {
        UpdateCurrentItemModelMasterTask& task = *new UpdateCurrentItemModelMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 現在有効な所持品マスターを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentItemModelMasterFromGitHub(UpdateCurrentItemModelMasterFromGitHubRequest request, std::function<void(AsyncUpdateCurrentItemModelMasterFromGitHubResult)> callback)
    {
        UpdateCurrentItemModelMasterFromGitHubTask& task = *new UpdateCurrentItemModelMasterFromGitHubTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * インベントリの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeInventories(DescribeInventoriesRequest request, std::function<void(AsyncDescribeInventoriesResult)> callback)
    {
        DescribeInventoriesTask& task = *new DescribeInventoriesTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * インベントリの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeInventoriesByUserId(DescribeInventoriesByUserIdRequest request, std::function<void(AsyncDescribeInventoriesByUserIdResult)> callback)
    {
        DescribeInventoriesByUserIdTask& task = *new DescribeInventoriesByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * インベントリを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getInventory(GetInventoryRequest request, std::function<void(AsyncGetInventoryResult)> callback)
    {
        GetInventoryTask& task = *new GetInventoryTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * インベントリを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getInventoryByUserId(GetInventoryByUserIdRequest request, std::function<void(AsyncGetInventoryByUserIdResult)> callback)
    {
        GetInventoryByUserIdTask& task = *new GetInventoryByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * キャパシティサイズを加算<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void addCapacityByUserId(AddCapacityByUserIdRequest request, std::function<void(AsyncAddCapacityByUserIdResult)> callback)
    {
        AddCapacityByUserIdTask& task = *new AddCapacityByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * キャパシティサイズを設定<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setCapacityByUserId(SetCapacityByUserIdRequest request, std::function<void(AsyncSetCapacityByUserIdResult)> callback)
    {
        SetCapacityByUserIdTask& task = *new SetCapacityByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * インベントリを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteInventoryByUserId(DeleteInventoryByUserIdRequest request, std::function<void(AsyncDeleteInventoryByUserIdResult)> callback)
    {
        DeleteInventoryByUserIdTask& task = *new DeleteInventoryByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * スタンプシートでキャパシティサイズを加算<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void addCapacityByStampSheet(AddCapacityByStampSheetRequest request, std::function<void(AsyncAddCapacityByStampSheetResult)> callback)
    {
        AddCapacityByStampSheetTask& task = *new AddCapacityByStampSheetTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * スタンプシートでキャパシティサイズを設定<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setCapacityByStampSheet(SetCapacityByStampSheetRequest request, std::function<void(AsyncSetCapacityByStampSheetResult)> callback)
    {
        SetCapacityByStampSheetTask& task = *new SetCapacityByStampSheetTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 有効期限ごとのアイテム所持数量の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeItemSets(DescribeItemSetsRequest request, std::function<void(AsyncDescribeItemSetsResult)> callback)
    {
        DescribeItemSetsTask& task = *new DescribeItemSetsTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 有効期限ごとのアイテム所持数量の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeItemSetsByUserId(DescribeItemSetsByUserIdRequest request, std::function<void(AsyncDescribeItemSetsByUserIdResult)> callback)
    {
        DescribeItemSetsByUserIdTask& task = *new DescribeItemSetsByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 有効期限ごとのアイテム所持数量を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getItemSet(GetItemSetRequest request, std::function<void(AsyncGetItemSetResult)> callback)
    {
        GetItemSetTask& task = *new GetItemSetTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 有効期限ごとのアイテム所持数量を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getItemSetByUserId(GetItemSetByUserIdRequest request, std::function<void(AsyncGetItemSetByUserIdResult)> callback)
    {
        GetItemSetByUserIdTask& task = *new GetItemSetByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 有効期限ごとのアイテム所持数量を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getItemWithSignature(GetItemWithSignatureRequest request, std::function<void(AsyncGetItemWithSignatureResult)> callback)
    {
        GetItemWithSignatureTask& task = *new GetItemWithSignatureTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 有効期限ごとのアイテム所持数量を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getItemWithSignatureByUserId(GetItemWithSignatureByUserIdRequest request, std::function<void(AsyncGetItemWithSignatureByUserIdResult)> callback)
    {
        GetItemWithSignatureByUserIdTask& task = *new GetItemWithSignatureByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * アイテムをインベントリに追加<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void acquireItemSetByUserId(AcquireItemSetByUserIdRequest request, std::function<void(AsyncAcquireItemSetByUserIdResult)> callback)
    {
        AcquireItemSetByUserIdTask& task = *new AcquireItemSetByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * インベントリのアイテムを消費<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void consumeItemSet(ConsumeItemSetRequest request, std::function<void(AsyncConsumeItemSetResult)> callback)
    {
        ConsumeItemSetTask& task = *new ConsumeItemSetTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * インベントリのアイテムを消費<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void consumeItemSetByUserId(ConsumeItemSetByUserIdRequest request, std::function<void(AsyncConsumeItemSetByUserIdResult)> callback)
    {
        ConsumeItemSetByUserIdTask& task = *new ConsumeItemSetByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 参照元の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeReferenceOf(DescribeReferenceOfRequest request, std::function<void(AsyncDescribeReferenceOfResult)> callback)
    {
        DescribeReferenceOfTask& task = *new DescribeReferenceOfTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 参照元の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeReferenceOfByUserId(DescribeReferenceOfByUserIdRequest request, std::function<void(AsyncDescribeReferenceOfByUserIdResult)> callback)
    {
        DescribeReferenceOfByUserIdTask& task = *new DescribeReferenceOfByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 参照元を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getReferenceOf(GetReferenceOfRequest request, std::function<void(AsyncGetReferenceOfResult)> callback)
    {
        GetReferenceOfTask& task = *new GetReferenceOfTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 参照元を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getReferenceOfByUserId(GetReferenceOfByUserIdRequest request, std::function<void(AsyncGetReferenceOfByUserIdResult)> callback)
    {
        GetReferenceOfByUserIdTask& task = *new GetReferenceOfByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 参照元に関する検証<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void verifyReferenceOf(VerifyReferenceOfRequest request, std::function<void(AsyncVerifyReferenceOfResult)> callback)
    {
        VerifyReferenceOfTask& task = *new VerifyReferenceOfTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 参照元に関する検証<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void verifyReferenceOfByUserId(VerifyReferenceOfByUserIdRequest request, std::function<void(AsyncVerifyReferenceOfByUserIdResult)> callback)
    {
        VerifyReferenceOfByUserIdTask& task = *new VerifyReferenceOfByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 参照元を追加<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void addReferenceOf(AddReferenceOfRequest request, std::function<void(AsyncAddReferenceOfResult)> callback)
    {
        AddReferenceOfTask& task = *new AddReferenceOfTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 参照元を追加<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void addReferenceOfByUserId(AddReferenceOfByUserIdRequest request, std::function<void(AsyncAddReferenceOfByUserIdResult)> callback)
    {
        AddReferenceOfByUserIdTask& task = *new AddReferenceOfByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 参照元を削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteReferenceOf(DeleteReferenceOfRequest request, std::function<void(AsyncDeleteReferenceOfResult)> callback)
    {
        DeleteReferenceOfTask& task = *new DeleteReferenceOfTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 参照元を削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteReferenceOfByUserId(DeleteReferenceOfByUserIdRequest request, std::function<void(AsyncDeleteReferenceOfByUserIdResult)> callback)
    {
        DeleteReferenceOfByUserIdTask& task = *new DeleteReferenceOfByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 有効期限ごとのアイテム所持数量を削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteItemSetByUserId(DeleteItemSetByUserIdRequest request, std::function<void(AsyncDeleteItemSetByUserIdResult)> callback)
    {
        DeleteItemSetByUserIdTask& task = *new DeleteItemSetByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * スタンプシートでアイテムをインベントリに追加<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void acquireItemSetByStampSheet(AcquireItemSetByStampSheetRequest request, std::function<void(AsyncAcquireItemSetByStampSheetResult)> callback)
    {
        AcquireItemSetByStampSheetTask& task = *new AcquireItemSetByStampSheetTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * スタンプシートでアイテムに参照元を追加<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void addReferenceOfItemSetByStampSheet(AddReferenceOfItemSetByStampSheetRequest request, std::function<void(AsyncAddReferenceOfItemSetByStampSheetResult)> callback)
    {
        AddReferenceOfItemSetByStampSheetTask& task = *new AddReferenceOfItemSetByStampSheetTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * スタンプシートでアイテムの参照元を削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteReferenceOfItemSetByStampSheet(DeleteReferenceOfItemSetByStampSheetRequest request, std::function<void(AsyncDeleteReferenceOfItemSetByStampSheetResult)> callback)
    {
        DeleteReferenceOfItemSetByStampSheetTask& task = *new DeleteReferenceOfItemSetByStampSheetTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * スタンプシートでインベントリのアイテムを消費<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void consumeItemSetByStampTask(ConsumeItemSetByStampTaskRequest request, std::function<void(AsyncConsumeItemSetByStampTaskResult)> callback)
    {
        ConsumeItemSetByStampTaskTask& task = *new ConsumeItemSetByStampTaskTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * スタンプシートでインベントリのアイテムを検証<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void verifyReferenceOfByStampTask(VerifyReferenceOfByStampTaskRequest request, std::function<void(AsyncVerifyReferenceOfByStampTaskResult)> callback)
    {
        VerifyReferenceOfByStampTaskTask& task = *new VerifyReferenceOfByStampTaskTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_INVENTORY_GS2INVENTORYWEBSOCKETCLIENT_HPP_