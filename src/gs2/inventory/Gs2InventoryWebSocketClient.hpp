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
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
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
#include "request/AcquireItemSetByUserIdRequest.hpp"
#include "request/ConsumeItemSetRequest.hpp"
#include "request/ConsumeItemSetByUserIdRequest.hpp"
#include "request/DeleteItemSetByUserIdRequest.hpp"
#include "request/AcquireItemSetByStampSheetRequest.hpp"
#include "request/ConsumeItemSetByStampTaskRequest.hpp"
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
#include "result/AcquireItemSetByUserIdResult.hpp"
#include "result/ConsumeItemSetResult.hpp"
#include "result/ConsumeItemSetByUserIdResult.hpp"
#include "result/DeleteItemSetByUserIdResult.hpp"
#include "result/AcquireItemSetByStampSheetResult.hpp"
#include "result/ConsumeItemSetByStampTaskResult.hpp"
#include <cstring>

namespace gs2 { namespace inventory {

typedef AsyncResult<DescribeNamespacesResult> AsyncDescribeNamespacesResult;
typedef AsyncResult<CreateNamespaceResult> AsyncCreateNamespaceResult;
typedef AsyncResult<GetNamespaceStatusResult> AsyncGetNamespaceStatusResult;
typedef AsyncResult<GetNamespaceResult> AsyncGetNamespaceResult;
typedef AsyncResult<UpdateNamespaceResult> AsyncUpdateNamespaceResult;
typedef AsyncResult<DeleteNamespaceResult> AsyncDeleteNamespaceResult;
typedef AsyncResult<DescribeInventoryModelMastersResult> AsyncDescribeInventoryModelMastersResult;
typedef AsyncResult<CreateInventoryModelMasterResult> AsyncCreateInventoryModelMasterResult;
typedef AsyncResult<GetInventoryModelMasterResult> AsyncGetInventoryModelMasterResult;
typedef AsyncResult<UpdateInventoryModelMasterResult> AsyncUpdateInventoryModelMasterResult;
typedef AsyncResult<DeleteInventoryModelMasterResult> AsyncDeleteInventoryModelMasterResult;
typedef AsyncResult<DescribeInventoryModelsResult> AsyncDescribeInventoryModelsResult;
typedef AsyncResult<GetInventoryModelResult> AsyncGetInventoryModelResult;
typedef AsyncResult<DescribeItemModelMastersResult> AsyncDescribeItemModelMastersResult;
typedef AsyncResult<CreateItemModelMasterResult> AsyncCreateItemModelMasterResult;
typedef AsyncResult<GetItemModelMasterResult> AsyncGetItemModelMasterResult;
typedef AsyncResult<UpdateItemModelMasterResult> AsyncUpdateItemModelMasterResult;
typedef AsyncResult<DeleteItemModelMasterResult> AsyncDeleteItemModelMasterResult;
typedef AsyncResult<DescribeItemModelsResult> AsyncDescribeItemModelsResult;
typedef AsyncResult<GetItemModelResult> AsyncGetItemModelResult;
typedef AsyncResult<ExportMasterResult> AsyncExportMasterResult;
typedef AsyncResult<GetCurrentItemModelMasterResult> AsyncGetCurrentItemModelMasterResult;
typedef AsyncResult<UpdateCurrentItemModelMasterResult> AsyncUpdateCurrentItemModelMasterResult;
typedef AsyncResult<DescribeInventoriesResult> AsyncDescribeInventoriesResult;
typedef AsyncResult<DescribeInventoriesByUserIdResult> AsyncDescribeInventoriesByUserIdResult;
typedef AsyncResult<GetInventoryResult> AsyncGetInventoryResult;
typedef AsyncResult<GetInventoryByUserIdResult> AsyncGetInventoryByUserIdResult;
typedef AsyncResult<AddCapacityByUserIdResult> AsyncAddCapacityByUserIdResult;
typedef AsyncResult<SetCapacityByUserIdResult> AsyncSetCapacityByUserIdResult;
typedef AsyncResult<DeleteInventoryByUserIdResult> AsyncDeleteInventoryByUserIdResult;
typedef AsyncResult<AddCapacityByStampSheetResult> AsyncAddCapacityByStampSheetResult;
typedef AsyncResult<SetCapacityByStampSheetResult> AsyncSetCapacityByStampSheetResult;
typedef AsyncResult<DescribeItemSetsResult> AsyncDescribeItemSetsResult;
typedef AsyncResult<DescribeItemSetsByUserIdResult> AsyncDescribeItemSetsByUserIdResult;
typedef AsyncResult<GetItemSetResult> AsyncGetItemSetResult;
typedef AsyncResult<GetItemSetByUserIdResult> AsyncGetItemSetByUserIdResult;
typedef AsyncResult<AcquireItemSetByUserIdResult> AsyncAcquireItemSetByUserIdResult;
typedef AsyncResult<ConsumeItemSetResult> AsyncConsumeItemSetResult;
typedef AsyncResult<ConsumeItemSetByUserIdResult> AsyncConsumeItemSetByUserIdResult;
typedef AsyncResult<DeleteItemSetByUserIdResult> AsyncDeleteItemSetByUserIdResult;
typedef AsyncResult<AcquireItemSetByStampSheetResult> AsyncAcquireItemSetByStampSheetResult;
typedef AsyncResult<ConsumeItemSetByStampTaskResult> AsyncConsumeItemSetByStampTaskResult;

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
        DescribeNamespacesRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getPageToken())
            {
                writer.writePropertyName("pageToken");
                writer.writeCharArray(*m_Request.getPageToken());
            }
            if (m_Request.getLimit())
            {
                writer.writePropertyName("limit");
                writer.writeInt64(*m_Request.getLimit());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("inventory");
            writer.writePropertyName("component");
            writer.writeCharArray("namespace");
            writer.writePropertyName("function");
            writer.writeCharArray("describeNamespaces");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        DescribeNamespacesTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeNamespacesRequest& request,
            Gs2WebSocketSessionTask<DescribeNamespacesResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeNamespacesResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeNamespacesTask() GS2_OVERRIDE = default;
    };

    class CreateNamespaceTask : public detail::Gs2WebSocketSessionTask<CreateNamespaceResult>
    {
    private:
        CreateNamespaceRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getName())
            {
                writer.writePropertyName("name");
                writer.writeCharArray(*m_Request.getName());
            }
            if (m_Request.getDescription())
            {
                writer.writePropertyName("description");
                writer.writeCharArray(*m_Request.getDescription());
            }
            if (m_Request.getAcquireTriggerScriptId())
            {
                writer.writePropertyName("acquireTriggerScriptId");
                writer.writeCharArray(*m_Request.getAcquireTriggerScriptId());
            }
            if (m_Request.getAcquireDoneTriggerScriptId())
            {
                writer.writePropertyName("acquireDoneTriggerScriptId");
                writer.writeCharArray(*m_Request.getAcquireDoneTriggerScriptId());
            }
            if (m_Request.getAcquireDoneTriggerQueueNamespaceId())
            {
                writer.writePropertyName("acquireDoneTriggerQueueNamespaceId");
                writer.writeCharArray(*m_Request.getAcquireDoneTriggerQueueNamespaceId());
            }
            if (m_Request.getOverflowTriggerScriptId())
            {
                writer.writePropertyName("overflowTriggerScriptId");
                writer.writeCharArray(*m_Request.getOverflowTriggerScriptId());
            }
            if (m_Request.getOverflowTriggerQueueNamespaceId())
            {
                writer.writePropertyName("overflowTriggerQueueNamespaceId");
                writer.writeCharArray(*m_Request.getOverflowTriggerQueueNamespaceId());
            }
            if (m_Request.getConsumeTriggerScriptId())
            {
                writer.writePropertyName("consumeTriggerScriptId");
                writer.writeCharArray(*m_Request.getConsumeTriggerScriptId());
            }
            if (m_Request.getConsumeDoneTriggerScriptId())
            {
                writer.writePropertyName("consumeDoneTriggerScriptId");
                writer.writeCharArray(*m_Request.getConsumeDoneTriggerScriptId());
            }
            if (m_Request.getConsumeDoneTriggerQueueNamespaceId())
            {
                writer.writePropertyName("consumeDoneTriggerQueueNamespaceId");
                writer.writeCharArray(*m_Request.getConsumeDoneTriggerQueueNamespaceId());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("inventory");
            writer.writePropertyName("component");
            writer.writeCharArray("namespace");
            writer.writePropertyName("function");
            writer.writeCharArray("createNamespace");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        CreateNamespaceTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            CreateNamespaceRequest& request,
            Gs2WebSocketSessionTask<CreateNamespaceResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateNamespaceResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~CreateNamespaceTask() GS2_OVERRIDE = default;
    };

    class GetNamespaceStatusTask : public detail::Gs2WebSocketSessionTask<GetNamespaceStatusResult>
    {
    private:
        GetNamespaceStatusRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("inventory");
            writer.writePropertyName("component");
            writer.writeCharArray("namespace");
            writer.writePropertyName("function");
            writer.writeCharArray("getNamespaceStatus");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        GetNamespaceStatusTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetNamespaceStatusRequest& request,
            Gs2WebSocketSessionTask<GetNamespaceStatusResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetNamespaceStatusResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetNamespaceStatusTask() GS2_OVERRIDE = default;
    };

    class GetNamespaceTask : public detail::Gs2WebSocketSessionTask<GetNamespaceResult>
    {
    private:
        GetNamespaceRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("inventory");
            writer.writePropertyName("component");
            writer.writeCharArray("namespace");
            writer.writePropertyName("function");
            writer.writeCharArray("getNamespace");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        GetNamespaceTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetNamespaceRequest& request,
            Gs2WebSocketSessionTask<GetNamespaceResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetNamespaceResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetNamespaceTask() GS2_OVERRIDE = default;
    };

    class UpdateNamespaceTask : public detail::Gs2WebSocketSessionTask<UpdateNamespaceResult>
    {
    private:
        UpdateNamespaceRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getDescription())
            {
                writer.writePropertyName("description");
                writer.writeCharArray(*m_Request.getDescription());
            }
            if (m_Request.getAcquireTriggerScriptId())
            {
                writer.writePropertyName("acquireTriggerScriptId");
                writer.writeCharArray(*m_Request.getAcquireTriggerScriptId());
            }
            if (m_Request.getAcquireDoneTriggerScriptId())
            {
                writer.writePropertyName("acquireDoneTriggerScriptId");
                writer.writeCharArray(*m_Request.getAcquireDoneTriggerScriptId());
            }
            if (m_Request.getAcquireDoneTriggerQueueNamespaceId())
            {
                writer.writePropertyName("acquireDoneTriggerQueueNamespaceId");
                writer.writeCharArray(*m_Request.getAcquireDoneTriggerQueueNamespaceId());
            }
            if (m_Request.getOverflowTriggerScriptId())
            {
                writer.writePropertyName("overflowTriggerScriptId");
                writer.writeCharArray(*m_Request.getOverflowTriggerScriptId());
            }
            if (m_Request.getOverflowTriggerQueueNamespaceId())
            {
                writer.writePropertyName("overflowTriggerQueueNamespaceId");
                writer.writeCharArray(*m_Request.getOverflowTriggerQueueNamespaceId());
            }
            if (m_Request.getConsumeTriggerScriptId())
            {
                writer.writePropertyName("consumeTriggerScriptId");
                writer.writeCharArray(*m_Request.getConsumeTriggerScriptId());
            }
            if (m_Request.getConsumeDoneTriggerScriptId())
            {
                writer.writePropertyName("consumeDoneTriggerScriptId");
                writer.writeCharArray(*m_Request.getConsumeDoneTriggerScriptId());
            }
            if (m_Request.getConsumeDoneTriggerQueueNamespaceId())
            {
                writer.writePropertyName("consumeDoneTriggerQueueNamespaceId");
                writer.writeCharArray(*m_Request.getConsumeDoneTriggerQueueNamespaceId());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("inventory");
            writer.writePropertyName("component");
            writer.writeCharArray("namespace");
            writer.writePropertyName("function");
            writer.writeCharArray("updateNamespace");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        UpdateNamespaceTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateNamespaceRequest& request,
            Gs2WebSocketSessionTask<UpdateNamespaceResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateNamespaceResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateNamespaceTask() GS2_OVERRIDE = default;
    };

    class DeleteNamespaceTask : public detail::Gs2WebSocketSessionTask<DeleteNamespaceResult>
    {
    private:
        DeleteNamespaceRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("inventory");
            writer.writePropertyName("component");
            writer.writeCharArray("namespace");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteNamespace");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        DeleteNamespaceTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteNamespaceRequest& request,
            Gs2WebSocketSessionTask<DeleteNamespaceResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteNamespaceResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteNamespaceTask() GS2_OVERRIDE = default;
    };

    class DescribeInventoryModelMastersTask : public detail::Gs2WebSocketSessionTask<DescribeInventoryModelMastersResult>
    {
    private:
        DescribeInventoryModelMastersRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getPageToken())
            {
                writer.writePropertyName("pageToken");
                writer.writeCharArray(*m_Request.getPageToken());
            }
            if (m_Request.getLimit())
            {
                writer.writePropertyName("limit");
                writer.writeInt64(*m_Request.getLimit());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("inventory");
            writer.writePropertyName("component");
            writer.writeCharArray("inventoryModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("describeInventoryModelMasters");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        DescribeInventoryModelMastersTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeInventoryModelMastersRequest& request,
            Gs2WebSocketSessionTask<DescribeInventoryModelMastersResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeInventoryModelMastersResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeInventoryModelMastersTask() GS2_OVERRIDE = default;
    };

    class CreateInventoryModelMasterTask : public detail::Gs2WebSocketSessionTask<CreateInventoryModelMasterResult>
    {
    private:
        CreateInventoryModelMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getName())
            {
                writer.writePropertyName("name");
                writer.writeCharArray(*m_Request.getName());
            }
            if (m_Request.getDescription())
            {
                writer.writePropertyName("description");
                writer.writeCharArray(*m_Request.getDescription());
            }
            if (m_Request.getMetadata())
            {
                writer.writePropertyName("metadata");
                writer.writeCharArray(*m_Request.getMetadata());
            }
            if (m_Request.getInitialCapacity())
            {
                writer.writePropertyName("initialCapacity");
                writer.writeInt32(*m_Request.getInitialCapacity());
            }
            if (m_Request.getMaxCapacity())
            {
                writer.writePropertyName("maxCapacity");
                writer.writeInt32(*m_Request.getMaxCapacity());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("inventory");
            writer.writePropertyName("component");
            writer.writeCharArray("inventoryModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("createInventoryModelMaster");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        CreateInventoryModelMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            CreateInventoryModelMasterRequest& request,
            Gs2WebSocketSessionTask<CreateInventoryModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateInventoryModelMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~CreateInventoryModelMasterTask() GS2_OVERRIDE = default;
    };

    class GetInventoryModelMasterTask : public detail::Gs2WebSocketSessionTask<GetInventoryModelMasterResult>
    {
    private:
        GetInventoryModelMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getInventoryName())
            {
                writer.writePropertyName("inventoryName");
                writer.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("inventory");
            writer.writePropertyName("component");
            writer.writeCharArray("inventoryModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("getInventoryModelMaster");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        GetInventoryModelMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetInventoryModelMasterRequest& request,
            Gs2WebSocketSessionTask<GetInventoryModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetInventoryModelMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetInventoryModelMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateInventoryModelMasterTask : public detail::Gs2WebSocketSessionTask<UpdateInventoryModelMasterResult>
    {
    private:
        UpdateInventoryModelMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getInventoryName())
            {
                writer.writePropertyName("inventoryName");
                writer.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getDescription())
            {
                writer.writePropertyName("description");
                writer.writeCharArray(*m_Request.getDescription());
            }
            if (m_Request.getMetadata())
            {
                writer.writePropertyName("metadata");
                writer.writeCharArray(*m_Request.getMetadata());
            }
            if (m_Request.getInitialCapacity())
            {
                writer.writePropertyName("initialCapacity");
                writer.writeInt32(*m_Request.getInitialCapacity());
            }
            if (m_Request.getMaxCapacity())
            {
                writer.writePropertyName("maxCapacity");
                writer.writeInt32(*m_Request.getMaxCapacity());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("inventory");
            writer.writePropertyName("component");
            writer.writeCharArray("inventoryModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("updateInventoryModelMaster");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        UpdateInventoryModelMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateInventoryModelMasterRequest& request,
            Gs2WebSocketSessionTask<UpdateInventoryModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateInventoryModelMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateInventoryModelMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteInventoryModelMasterTask : public detail::Gs2WebSocketSessionTask<DeleteInventoryModelMasterResult>
    {
    private:
        DeleteInventoryModelMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getInventoryName())
            {
                writer.writePropertyName("inventoryName");
                writer.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("inventory");
            writer.writePropertyName("component");
            writer.writeCharArray("inventoryModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteInventoryModelMaster");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        DeleteInventoryModelMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteInventoryModelMasterRequest& request,
            Gs2WebSocketSessionTask<DeleteInventoryModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteInventoryModelMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteInventoryModelMasterTask() GS2_OVERRIDE = default;
    };

    class DescribeInventoryModelsTask : public detail::Gs2WebSocketSessionTask<DescribeInventoryModelsResult>
    {
    private:
        DescribeInventoryModelsRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("inventory");
            writer.writePropertyName("component");
            writer.writeCharArray("inventoryModel");
            writer.writePropertyName("function");
            writer.writeCharArray("describeInventoryModels");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        DescribeInventoryModelsTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeInventoryModelsRequest& request,
            Gs2WebSocketSessionTask<DescribeInventoryModelsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeInventoryModelsResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeInventoryModelsTask() GS2_OVERRIDE = default;
    };

    class GetInventoryModelTask : public detail::Gs2WebSocketSessionTask<GetInventoryModelResult>
    {
    private:
        GetInventoryModelRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getInventoryName())
            {
                writer.writePropertyName("inventoryName");
                writer.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("inventory");
            writer.writePropertyName("component");
            writer.writeCharArray("inventoryModel");
            writer.writePropertyName("function");
            writer.writeCharArray("getInventoryModel");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        GetInventoryModelTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetInventoryModelRequest& request,
            Gs2WebSocketSessionTask<GetInventoryModelResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetInventoryModelResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetInventoryModelTask() GS2_OVERRIDE = default;
    };

    class DescribeItemModelMastersTask : public detail::Gs2WebSocketSessionTask<DescribeItemModelMastersResult>
    {
    private:
        DescribeItemModelMastersRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getInventoryName())
            {
                writer.writePropertyName("inventoryName");
                writer.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getPageToken())
            {
                writer.writePropertyName("pageToken");
                writer.writeCharArray(*m_Request.getPageToken());
            }
            if (m_Request.getLimit())
            {
                writer.writePropertyName("limit");
                writer.writeInt64(*m_Request.getLimit());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("inventory");
            writer.writePropertyName("component");
            writer.writeCharArray("itemModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("describeItemModelMasters");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        DescribeItemModelMastersTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeItemModelMastersRequest& request,
            Gs2WebSocketSessionTask<DescribeItemModelMastersResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeItemModelMastersResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeItemModelMastersTask() GS2_OVERRIDE = default;
    };

    class CreateItemModelMasterTask : public detail::Gs2WebSocketSessionTask<CreateItemModelMasterResult>
    {
    private:
        CreateItemModelMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getInventoryName())
            {
                writer.writePropertyName("inventoryName");
                writer.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getName())
            {
                writer.writePropertyName("name");
                writer.writeCharArray(*m_Request.getName());
            }
            if (m_Request.getDescription())
            {
                writer.writePropertyName("description");
                writer.writeCharArray(*m_Request.getDescription());
            }
            if (m_Request.getMetadata())
            {
                writer.writePropertyName("metadata");
                writer.writeCharArray(*m_Request.getMetadata());
            }
            if (m_Request.getMaxCount())
            {
                writer.writePropertyName("maxCount");
                writer.writeInt64(*m_Request.getMaxCount());
            }
            if (m_Request.getSortValue())
            {
                writer.writePropertyName("sortValue");
                writer.writeInt32(*m_Request.getSortValue());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("inventory");
            writer.writePropertyName("component");
            writer.writeCharArray("itemModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("createItemModelMaster");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        CreateItemModelMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            CreateItemModelMasterRequest& request,
            Gs2WebSocketSessionTask<CreateItemModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateItemModelMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~CreateItemModelMasterTask() GS2_OVERRIDE = default;
    };

    class GetItemModelMasterTask : public detail::Gs2WebSocketSessionTask<GetItemModelMasterResult>
    {
    private:
        GetItemModelMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getInventoryName())
            {
                writer.writePropertyName("inventoryName");
                writer.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getItemName())
            {
                writer.writePropertyName("itemName");
                writer.writeCharArray(*m_Request.getItemName());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("inventory");
            writer.writePropertyName("component");
            writer.writeCharArray("itemModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("getItemModelMaster");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        GetItemModelMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetItemModelMasterRequest& request,
            Gs2WebSocketSessionTask<GetItemModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetItemModelMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetItemModelMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateItemModelMasterTask : public detail::Gs2WebSocketSessionTask<UpdateItemModelMasterResult>
    {
    private:
        UpdateItemModelMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getInventoryName())
            {
                writer.writePropertyName("inventoryName");
                writer.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getItemName())
            {
                writer.writePropertyName("itemName");
                writer.writeCharArray(*m_Request.getItemName());
            }
            if (m_Request.getDescription())
            {
                writer.writePropertyName("description");
                writer.writeCharArray(*m_Request.getDescription());
            }
            if (m_Request.getMetadata())
            {
                writer.writePropertyName("metadata");
                writer.writeCharArray(*m_Request.getMetadata());
            }
            if (m_Request.getMaxCount())
            {
                writer.writePropertyName("maxCount");
                writer.writeInt64(*m_Request.getMaxCount());
            }
            if (m_Request.getSortValue())
            {
                writer.writePropertyName("sortValue");
                writer.writeInt32(*m_Request.getSortValue());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("inventory");
            writer.writePropertyName("component");
            writer.writeCharArray("itemModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("updateItemModelMaster");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        UpdateItemModelMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateItemModelMasterRequest& request,
            Gs2WebSocketSessionTask<UpdateItemModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateItemModelMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateItemModelMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteItemModelMasterTask : public detail::Gs2WebSocketSessionTask<DeleteItemModelMasterResult>
    {
    private:
        DeleteItemModelMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getInventoryName())
            {
                writer.writePropertyName("inventoryName");
                writer.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getItemName())
            {
                writer.writePropertyName("itemName");
                writer.writeCharArray(*m_Request.getItemName());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("inventory");
            writer.writePropertyName("component");
            writer.writeCharArray("itemModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteItemModelMaster");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        DeleteItemModelMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteItemModelMasterRequest& request,
            Gs2WebSocketSessionTask<DeleteItemModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteItemModelMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteItemModelMasterTask() GS2_OVERRIDE = default;
    };

    class DescribeItemModelsTask : public detail::Gs2WebSocketSessionTask<DescribeItemModelsResult>
    {
    private:
        DescribeItemModelsRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getInventoryName())
            {
                writer.writePropertyName("inventoryName");
                writer.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("inventory");
            writer.writePropertyName("component");
            writer.writeCharArray("itemModel");
            writer.writePropertyName("function");
            writer.writeCharArray("describeItemModels");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        DescribeItemModelsTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeItemModelsRequest& request,
            Gs2WebSocketSessionTask<DescribeItemModelsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeItemModelsResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeItemModelsTask() GS2_OVERRIDE = default;
    };

    class GetItemModelTask : public detail::Gs2WebSocketSessionTask<GetItemModelResult>
    {
    private:
        GetItemModelRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getInventoryName())
            {
                writer.writePropertyName("inventoryName");
                writer.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getItemName())
            {
                writer.writePropertyName("itemName");
                writer.writeCharArray(*m_Request.getItemName());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("inventory");
            writer.writePropertyName("component");
            writer.writeCharArray("itemModel");
            writer.writePropertyName("function");
            writer.writeCharArray("getItemModel");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        GetItemModelTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetItemModelRequest& request,
            Gs2WebSocketSessionTask<GetItemModelResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetItemModelResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetItemModelTask() GS2_OVERRIDE = default;
    };

    class ExportMasterTask : public detail::Gs2WebSocketSessionTask<ExportMasterResult>
    {
    private:
        ExportMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("inventory");
            writer.writePropertyName("component");
            writer.writeCharArray("currentItemModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("exportMaster");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        ExportMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            ExportMasterRequest& request,
            Gs2WebSocketSessionTask<ExportMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<ExportMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~ExportMasterTask() GS2_OVERRIDE = default;
    };

    class GetCurrentItemModelMasterTask : public detail::Gs2WebSocketSessionTask<GetCurrentItemModelMasterResult>
    {
    private:
        GetCurrentItemModelMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("inventory");
            writer.writePropertyName("component");
            writer.writeCharArray("currentItemModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("getCurrentItemModelMaster");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        GetCurrentItemModelMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetCurrentItemModelMasterRequest& request,
            Gs2WebSocketSessionTask<GetCurrentItemModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetCurrentItemModelMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetCurrentItemModelMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentItemModelMasterTask : public detail::Gs2WebSocketSessionTask<UpdateCurrentItemModelMasterResult>
    {
    private:
        UpdateCurrentItemModelMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getSettings())
            {
                writer.writePropertyName("settings");
                writer.writeCharArray(*m_Request.getSettings());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("inventory");
            writer.writePropertyName("component");
            writer.writeCharArray("currentItemModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("updateCurrentItemModelMaster");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        UpdateCurrentItemModelMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateCurrentItemModelMasterRequest& request,
            Gs2WebSocketSessionTask<UpdateCurrentItemModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateCurrentItemModelMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateCurrentItemModelMasterTask() GS2_OVERRIDE = default;
    };

    class DescribeInventoriesTask : public detail::Gs2WebSocketSessionTask<DescribeInventoriesResult>
    {
    private:
        DescribeInventoriesRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getPageToken())
            {
                writer.writePropertyName("pageToken");
                writer.writeCharArray(*m_Request.getPageToken());
            }
            if (m_Request.getLimit())
            {
                writer.writePropertyName("limit");
                writer.writeInt64(*m_Request.getLimit());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("inventory");
            writer.writePropertyName("component");
            writer.writeCharArray("inventory");
            writer.writePropertyName("function");
            writer.writeCharArray("describeInventories");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        DescribeInventoriesTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeInventoriesRequest& request,
            Gs2WebSocketSessionTask<DescribeInventoriesResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeInventoriesResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeInventoriesTask() GS2_OVERRIDE = default;
    };

    class DescribeInventoriesByUserIdTask : public detail::Gs2WebSocketSessionTask<DescribeInventoriesByUserIdResult>
    {
    private:
        DescribeInventoriesByUserIdRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                writer.writePropertyName("userId");
                writer.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getPageToken())
            {
                writer.writePropertyName("pageToken");
                writer.writeCharArray(*m_Request.getPageToken());
            }
            if (m_Request.getLimit())
            {
                writer.writePropertyName("limit");
                writer.writeInt64(*m_Request.getLimit());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("inventory");
            writer.writePropertyName("component");
            writer.writeCharArray("inventory");
            writer.writePropertyName("function");
            writer.writeCharArray("describeInventoriesByUserId");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        DescribeInventoriesByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeInventoriesByUserIdRequest& request,
            Gs2WebSocketSessionTask<DescribeInventoriesByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeInventoriesByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeInventoriesByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetInventoryTask : public detail::Gs2WebSocketSessionTask<GetInventoryResult>
    {
    private:
        GetInventoryRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getInventoryName())
            {
                writer.writePropertyName("inventoryName");
                writer.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("inventory");
            writer.writePropertyName("component");
            writer.writeCharArray("inventory");
            writer.writePropertyName("function");
            writer.writeCharArray("getInventory");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        GetInventoryTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetInventoryRequest& request,
            Gs2WebSocketSessionTask<GetInventoryResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetInventoryResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetInventoryTask() GS2_OVERRIDE = default;
    };

    class GetInventoryByUserIdTask : public detail::Gs2WebSocketSessionTask<GetInventoryByUserIdResult>
    {
    private:
        GetInventoryByUserIdRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getInventoryName())
            {
                writer.writePropertyName("inventoryName");
                writer.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getUserId())
            {
                writer.writePropertyName("userId");
                writer.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("inventory");
            writer.writePropertyName("component");
            writer.writeCharArray("inventory");
            writer.writePropertyName("function");
            writer.writeCharArray("getInventoryByUserId");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        GetInventoryByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetInventoryByUserIdRequest& request,
            Gs2WebSocketSessionTask<GetInventoryByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetInventoryByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetInventoryByUserIdTask() GS2_OVERRIDE = default;
    };

    class AddCapacityByUserIdTask : public detail::Gs2WebSocketSessionTask<AddCapacityByUserIdResult>
    {
    private:
        AddCapacityByUserIdRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getInventoryName())
            {
                writer.writePropertyName("inventoryName");
                writer.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getUserId())
            {
                writer.writePropertyName("userId");
                writer.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getAddCapacityValue())
            {
                writer.writePropertyName("addCapacityValue");
                writer.writeInt32(*m_Request.getAddCapacityValue());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("inventory");
            writer.writePropertyName("component");
            writer.writeCharArray("inventory");
            writer.writePropertyName("function");
            writer.writeCharArray("addCapacityByUserId");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        AddCapacityByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            AddCapacityByUserIdRequest& request,
            Gs2WebSocketSessionTask<AddCapacityByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<AddCapacityByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~AddCapacityByUserIdTask() GS2_OVERRIDE = default;
    };

    class SetCapacityByUserIdTask : public detail::Gs2WebSocketSessionTask<SetCapacityByUserIdResult>
    {
    private:
        SetCapacityByUserIdRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getInventoryName())
            {
                writer.writePropertyName("inventoryName");
                writer.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getUserId())
            {
                writer.writePropertyName("userId");
                writer.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getNewCapacityValue())
            {
                writer.writePropertyName("newCapacityValue");
                writer.writeInt32(*m_Request.getNewCapacityValue());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("inventory");
            writer.writePropertyName("component");
            writer.writeCharArray("inventory");
            writer.writePropertyName("function");
            writer.writeCharArray("setCapacityByUserId");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        SetCapacityByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            SetCapacityByUserIdRequest& request,
            Gs2WebSocketSessionTask<SetCapacityByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<SetCapacityByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~SetCapacityByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteInventoryByUserIdTask : public detail::Gs2WebSocketSessionTask<DeleteInventoryByUserIdResult>
    {
    private:
        DeleteInventoryByUserIdRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getInventoryName())
            {
                writer.writePropertyName("inventoryName");
                writer.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getUserId())
            {
                writer.writePropertyName("userId");
                writer.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("inventory");
            writer.writePropertyName("component");
            writer.writeCharArray("inventory");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteInventoryByUserId");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        DeleteInventoryByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteInventoryByUserIdRequest& request,
            Gs2WebSocketSessionTask<DeleteInventoryByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteInventoryByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteInventoryByUserIdTask() GS2_OVERRIDE = default;
    };

    class AddCapacityByStampSheetTask : public detail::Gs2WebSocketSessionTask<AddCapacityByStampSheetResult>
    {
    private:
        AddCapacityByStampSheetRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getStampSheet())
            {
                writer.writePropertyName("stampSheet");
                writer.writeCharArray(*m_Request.getStampSheet());
            }
            if (m_Request.getKeyId())
            {
                writer.writePropertyName("keyId");
                writer.writeCharArray(*m_Request.getKeyId());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("inventory");
            writer.writePropertyName("component");
            writer.writeCharArray("inventory");
            writer.writePropertyName("function");
            writer.writeCharArray("addCapacityByStampSheet");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        AddCapacityByStampSheetTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            AddCapacityByStampSheetRequest& request,
            Gs2WebSocketSessionTask<AddCapacityByStampSheetResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<AddCapacityByStampSheetResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~AddCapacityByStampSheetTask() GS2_OVERRIDE = default;
    };

    class SetCapacityByStampSheetTask : public detail::Gs2WebSocketSessionTask<SetCapacityByStampSheetResult>
    {
    private:
        SetCapacityByStampSheetRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getStampSheet())
            {
                writer.writePropertyName("stampSheet");
                writer.writeCharArray(*m_Request.getStampSheet());
            }
            if (m_Request.getKeyId())
            {
                writer.writePropertyName("keyId");
                writer.writeCharArray(*m_Request.getKeyId());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("inventory");
            writer.writePropertyName("component");
            writer.writeCharArray("inventory");
            writer.writePropertyName("function");
            writer.writeCharArray("setCapacityByStampSheet");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        SetCapacityByStampSheetTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            SetCapacityByStampSheetRequest& request,
            Gs2WebSocketSessionTask<SetCapacityByStampSheetResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<SetCapacityByStampSheetResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~SetCapacityByStampSheetTask() GS2_OVERRIDE = default;
    };

    class DescribeItemSetsTask : public detail::Gs2WebSocketSessionTask<DescribeItemSetsResult>
    {
    private:
        DescribeItemSetsRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getInventoryName())
            {
                writer.writePropertyName("inventoryName");
                writer.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getPageToken())
            {
                writer.writePropertyName("pageToken");
                writer.writeCharArray(*m_Request.getPageToken());
            }
            if (m_Request.getLimit())
            {
                writer.writePropertyName("limit");
                writer.writeInt64(*m_Request.getLimit());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("inventory");
            writer.writePropertyName("component");
            writer.writeCharArray("itemSet");
            writer.writePropertyName("function");
            writer.writeCharArray("describeItemSets");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        DescribeItemSetsTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeItemSetsRequest& request,
            Gs2WebSocketSessionTask<DescribeItemSetsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeItemSetsResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeItemSetsTask() GS2_OVERRIDE = default;
    };

    class DescribeItemSetsByUserIdTask : public detail::Gs2WebSocketSessionTask<DescribeItemSetsByUserIdResult>
    {
    private:
        DescribeItemSetsByUserIdRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getInventoryName())
            {
                writer.writePropertyName("inventoryName");
                writer.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getUserId())
            {
                writer.writePropertyName("userId");
                writer.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getPageToken())
            {
                writer.writePropertyName("pageToken");
                writer.writeCharArray(*m_Request.getPageToken());
            }
            if (m_Request.getLimit())
            {
                writer.writePropertyName("limit");
                writer.writeInt64(*m_Request.getLimit());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("inventory");
            writer.writePropertyName("component");
            writer.writeCharArray("itemSet");
            writer.writePropertyName("function");
            writer.writeCharArray("describeItemSetsByUserId");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        DescribeItemSetsByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeItemSetsByUserIdRequest& request,
            Gs2WebSocketSessionTask<DescribeItemSetsByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeItemSetsByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeItemSetsByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetItemSetTask : public detail::Gs2WebSocketSessionTask<GetItemSetResult>
    {
    private:
        GetItemSetRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getInventoryName())
            {
                writer.writePropertyName("inventoryName");
                writer.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getItemName())
            {
                writer.writePropertyName("itemName");
                writer.writeCharArray(*m_Request.getItemName());
            }
            if (m_Request.getExpiresAt())
            {
                writer.writePropertyName("expiresAt");
                writer.writeInt64(*m_Request.getExpiresAt());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("inventory");
            writer.writePropertyName("component");
            writer.writeCharArray("itemSet");
            writer.writePropertyName("function");
            writer.writeCharArray("getItemSet");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        GetItemSetTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetItemSetRequest& request,
            Gs2WebSocketSessionTask<GetItemSetResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetItemSetResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetItemSetTask() GS2_OVERRIDE = default;
    };

    class GetItemSetByUserIdTask : public detail::Gs2WebSocketSessionTask<GetItemSetByUserIdResult>
    {
    private:
        GetItemSetByUserIdRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getInventoryName())
            {
                writer.writePropertyName("inventoryName");
                writer.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getUserId())
            {
                writer.writePropertyName("userId");
                writer.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getItemName())
            {
                writer.writePropertyName("itemName");
                writer.writeCharArray(*m_Request.getItemName());
            }
            if (m_Request.getExpiresAt())
            {
                writer.writePropertyName("expiresAt");
                writer.writeInt64(*m_Request.getExpiresAt());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("inventory");
            writer.writePropertyName("component");
            writer.writeCharArray("itemSet");
            writer.writePropertyName("function");
            writer.writeCharArray("getItemSetByUserId");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        GetItemSetByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetItemSetByUserIdRequest& request,
            Gs2WebSocketSessionTask<GetItemSetByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetItemSetByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetItemSetByUserIdTask() GS2_OVERRIDE = default;
    };

    class AcquireItemSetByUserIdTask : public detail::Gs2WebSocketSessionTask<AcquireItemSetByUserIdResult>
    {
    private:
        AcquireItemSetByUserIdRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getInventoryName())
            {
                writer.writePropertyName("inventoryName");
                writer.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getItemName())
            {
                writer.writePropertyName("itemName");
                writer.writeCharArray(*m_Request.getItemName());
            }
            if (m_Request.getUserId())
            {
                writer.writePropertyName("userId");
                writer.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getAcquireCount())
            {
                writer.writePropertyName("acquireCount");
                writer.writeInt64(*m_Request.getAcquireCount());
            }
            if (m_Request.getExpiresAt())
            {
                writer.writePropertyName("expiresAt");
                writer.writeInt64(*m_Request.getExpiresAt());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("inventory");
            writer.writePropertyName("component");
            writer.writeCharArray("itemSet");
            writer.writePropertyName("function");
            writer.writeCharArray("acquireItemSetByUserId");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        AcquireItemSetByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            AcquireItemSetByUserIdRequest& request,
            Gs2WebSocketSessionTask<AcquireItemSetByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<AcquireItemSetByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~AcquireItemSetByUserIdTask() GS2_OVERRIDE = default;
    };

    class ConsumeItemSetTask : public detail::Gs2WebSocketSessionTask<ConsumeItemSetResult>
    {
    private:
        ConsumeItemSetRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getInventoryName())
            {
                writer.writePropertyName("inventoryName");
                writer.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getItemName())
            {
                writer.writePropertyName("itemName");
                writer.writeCharArray(*m_Request.getItemName());
            }
            if (m_Request.getConsumeCount())
            {
                writer.writePropertyName("consumeCount");
                writer.writeInt64(*m_Request.getConsumeCount());
            }
            if (m_Request.getExpiresAt())
            {
                writer.writePropertyName("expiresAt");
                writer.writeInt64(*m_Request.getExpiresAt());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("inventory");
            writer.writePropertyName("component");
            writer.writeCharArray("itemSet");
            writer.writePropertyName("function");
            writer.writeCharArray("consumeItemSet");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        ConsumeItemSetTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            ConsumeItemSetRequest& request,
            Gs2WebSocketSessionTask<ConsumeItemSetResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<ConsumeItemSetResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~ConsumeItemSetTask() GS2_OVERRIDE = default;
    };

    class ConsumeItemSetByUserIdTask : public detail::Gs2WebSocketSessionTask<ConsumeItemSetByUserIdResult>
    {
    private:
        ConsumeItemSetByUserIdRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getInventoryName())
            {
                writer.writePropertyName("inventoryName");
                writer.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getUserId())
            {
                writer.writePropertyName("userId");
                writer.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getItemName())
            {
                writer.writePropertyName("itemName");
                writer.writeCharArray(*m_Request.getItemName());
            }
            if (m_Request.getConsumeCount())
            {
                writer.writePropertyName("consumeCount");
                writer.writeInt64(*m_Request.getConsumeCount());
            }
            if (m_Request.getExpiresAt())
            {
                writer.writePropertyName("expiresAt");
                writer.writeInt64(*m_Request.getExpiresAt());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("inventory");
            writer.writePropertyName("component");
            writer.writeCharArray("itemSet");
            writer.writePropertyName("function");
            writer.writeCharArray("consumeItemSetByUserId");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        ConsumeItemSetByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            ConsumeItemSetByUserIdRequest& request,
            Gs2WebSocketSessionTask<ConsumeItemSetByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<ConsumeItemSetByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~ConsumeItemSetByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteItemSetByUserIdTask : public detail::Gs2WebSocketSessionTask<DeleteItemSetByUserIdResult>
    {
    private:
        DeleteItemSetByUserIdRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getInventoryName())
            {
                writer.writePropertyName("inventoryName");
                writer.writeCharArray(*m_Request.getInventoryName());
            }
            if (m_Request.getUserId())
            {
                writer.writePropertyName("userId");
                writer.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getItemName())
            {
                writer.writePropertyName("itemName");
                writer.writeCharArray(*m_Request.getItemName());
            }
            if (m_Request.getExpiresAt())
            {
                writer.writePropertyName("expiresAt");
                writer.writeInt64(*m_Request.getExpiresAt());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("inventory");
            writer.writePropertyName("component");
            writer.writeCharArray("itemSet");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteItemSetByUserId");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        DeleteItemSetByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteItemSetByUserIdRequest& request,
            Gs2WebSocketSessionTask<DeleteItemSetByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteItemSetByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteItemSetByUserIdTask() GS2_OVERRIDE = default;
    };

    class AcquireItemSetByStampSheetTask : public detail::Gs2WebSocketSessionTask<AcquireItemSetByStampSheetResult>
    {
    private:
        AcquireItemSetByStampSheetRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getStampSheet())
            {
                writer.writePropertyName("stampSheet");
                writer.writeCharArray(*m_Request.getStampSheet());
            }
            if (m_Request.getKeyId())
            {
                writer.writePropertyName("keyId");
                writer.writeCharArray(*m_Request.getKeyId());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("inventory");
            writer.writePropertyName("component");
            writer.writeCharArray("itemSet");
            writer.writePropertyName("function");
            writer.writeCharArray("acquireItemSetByStampSheet");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        AcquireItemSetByStampSheetTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            AcquireItemSetByStampSheetRequest& request,
            Gs2WebSocketSessionTask<AcquireItemSetByStampSheetResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<AcquireItemSetByStampSheetResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~AcquireItemSetByStampSheetTask() GS2_OVERRIDE = default;
    };

    class ConsumeItemSetByStampTaskTask : public detail::Gs2WebSocketSessionTask<ConsumeItemSetByStampTaskResult>
    {
    private:
        ConsumeItemSetByStampTaskRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getStampTask())
            {
                writer.writePropertyName("stampTask");
                writer.writeCharArray(*m_Request.getStampTask());
            }
            if (m_Request.getKeyId())
            {
                writer.writePropertyName("keyId");
                writer.writeCharArray(*m_Request.getKeyId());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("inventory");
            writer.writePropertyName("component");
            writer.writeCharArray("itemSet");
            writer.writePropertyName("function");
            writer.writeCharArray("consumeItemSetByStampTask");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        ConsumeItemSetByStampTaskTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            ConsumeItemSetByStampTaskRequest& request,
            Gs2WebSocketSessionTask<ConsumeItemSetByStampTaskResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<ConsumeItemSetByStampTaskResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~ConsumeItemSetByStampTaskTask() GS2_OVERRIDE = default;
    };

private:
    static void write(detail::json::JsonWriter& writer, const Namespace& obj)
    {
        writer.writeObjectStart();
        if (obj.getNamespaceId())
        {
            writer.writePropertyName("namespaceId");
            writer.writeCharArray(*obj.getNamespaceId());
        }
        if (obj.getOwnerId())
        {
            writer.writePropertyName("ownerId");
            writer.writeCharArray(*obj.getOwnerId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*obj.getName());
        }
        if (obj.getDescription())
        {
            writer.writePropertyName("description");
            writer.writeCharArray(*obj.getDescription());
        }
        if (obj.getAcquireTriggerScriptId())
        {
            writer.writePropertyName("acquireTriggerScriptId");
            writer.writeCharArray(*obj.getAcquireTriggerScriptId());
        }
        if (obj.getAcquireDoneTriggerScriptId())
        {
            writer.writePropertyName("acquireDoneTriggerScriptId");
            writer.writeCharArray(*obj.getAcquireDoneTriggerScriptId());
        }
        if (obj.getAcquireDoneTriggerQueueNamespaceId())
        {
            writer.writePropertyName("acquireDoneTriggerQueueNamespaceId");
            writer.writeCharArray(*obj.getAcquireDoneTriggerQueueNamespaceId());
        }
        if (obj.getOverflowTriggerScriptId())
        {
            writer.writePropertyName("overflowTriggerScriptId");
            writer.writeCharArray(*obj.getOverflowTriggerScriptId());
        }
        if (obj.getOverflowTriggerQueueNamespaceId())
        {
            writer.writePropertyName("overflowTriggerQueueNamespaceId");
            writer.writeCharArray(*obj.getOverflowTriggerQueueNamespaceId());
        }
        if (obj.getConsumeTriggerScriptId())
        {
            writer.writePropertyName("consumeTriggerScriptId");
            writer.writeCharArray(*obj.getConsumeTriggerScriptId());
        }
        if (obj.getConsumeDoneTriggerScriptId())
        {
            writer.writePropertyName("consumeDoneTriggerScriptId");
            writer.writeCharArray(*obj.getConsumeDoneTriggerScriptId());
        }
        if (obj.getConsumeDoneTriggerQueueNamespaceId())
        {
            writer.writePropertyName("consumeDoneTriggerQueueNamespaceId");
            writer.writeCharArray(*obj.getConsumeDoneTriggerQueueNamespaceId());
        }
        if (obj.getCreatedAt())
        {
            writer.writePropertyName("createdAt");
            writer.writeInt64(*obj.getCreatedAt());
        }
        if (obj.getUpdatedAt())
        {
            writer.writePropertyName("updatedAt");
            writer.writeInt64(*obj.getUpdatedAt());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const InventoryModelMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getInventoryModelId())
        {
            writer.writePropertyName("inventoryModelId");
            writer.writeCharArray(*obj.getInventoryModelId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*obj.getName());
        }
        if (obj.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.writeCharArray(*obj.getMetadata());
        }
        if (obj.getDescription())
        {
            writer.writePropertyName("description");
            writer.writeCharArray(*obj.getDescription());
        }
        if (obj.getInitialCapacity())
        {
            writer.writePropertyName("initialCapacity");
            writer.writeInt32(*obj.getInitialCapacity());
        }
        if (obj.getMaxCapacity())
        {
            writer.writePropertyName("maxCapacity");
            writer.writeInt32(*obj.getMaxCapacity());
        }
        if (obj.getCreatedAt())
        {
            writer.writePropertyName("createdAt");
            writer.writeInt64(*obj.getCreatedAt());
        }
        if (obj.getUpdatedAt())
        {
            writer.writePropertyName("updatedAt");
            writer.writeInt64(*obj.getUpdatedAt());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const InventoryModel& obj)
    {
        writer.writeObjectStart();
        if (obj.getInventoryModelId())
        {
            writer.writePropertyName("inventoryModelId");
            writer.writeCharArray(*obj.getInventoryModelId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*obj.getName());
        }
        if (obj.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.writeCharArray(*obj.getMetadata());
        }
        if (obj.getInitialCapacity())
        {
            writer.writePropertyName("initialCapacity");
            writer.writeInt32(*obj.getInitialCapacity());
        }
        if (obj.getMaxCapacity())
        {
            writer.writePropertyName("maxCapacity");
            writer.writeInt32(*obj.getMaxCapacity());
        }
        if (obj.getItemModels())
        {
            writer.writePropertyName("itemModels");
            writer.writeArrayStart();
            auto& list = *obj.getItemModels();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const ItemModelMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getItemModelId())
        {
            writer.writePropertyName("itemModelId");
            writer.writeCharArray(*obj.getItemModelId());
        }
        if (obj.getInventoryName())
        {
            writer.writePropertyName("inventoryName");
            writer.writeCharArray(*obj.getInventoryName());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*obj.getName());
        }
        if (obj.getDescription())
        {
            writer.writePropertyName("description");
            writer.writeCharArray(*obj.getDescription());
        }
        if (obj.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.writeCharArray(*obj.getMetadata());
        }
        if (obj.getMaxCount())
        {
            writer.writePropertyName("maxCount");
            writer.writeInt64(*obj.getMaxCount());
        }
        if (obj.getSortValue())
        {
            writer.writePropertyName("sortValue");
            writer.writeInt32(*obj.getSortValue());
        }
        if (obj.getCreatedAt())
        {
            writer.writePropertyName("createdAt");
            writer.writeInt64(*obj.getCreatedAt());
        }
        if (obj.getUpdatedAt())
        {
            writer.writePropertyName("updatedAt");
            writer.writeInt64(*obj.getUpdatedAt());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const ItemModel& obj)
    {
        writer.writeObjectStart();
        if (obj.getItemModelId())
        {
            writer.writePropertyName("itemModelId");
            writer.writeCharArray(*obj.getItemModelId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*obj.getName());
        }
        if (obj.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.writeCharArray(*obj.getMetadata());
        }
        if (obj.getMaxCount())
        {
            writer.writePropertyName("maxCount");
            writer.writeInt64(*obj.getMaxCount());
        }
        if (obj.getSortValue())
        {
            writer.writePropertyName("sortValue");
            writer.writeInt32(*obj.getSortValue());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const CurrentItemModelMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getNamespaceName())
        {
            writer.writePropertyName("namespaceName");
            writer.writeCharArray(*obj.getNamespaceName());
        }
        if (obj.getSettings())
        {
            writer.writePropertyName("settings");
            writer.writeCharArray(*obj.getSettings());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const Inventory& obj)
    {
        writer.writeObjectStart();
        if (obj.getInventoryId())
        {
            writer.writePropertyName("inventoryId");
            writer.writeCharArray(*obj.getInventoryId());
        }
        if (obj.getInventoryName())
        {
            writer.writePropertyName("inventoryName");
            writer.writeCharArray(*obj.getInventoryName());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.writeCharArray(*obj.getUserId());
        }
        if (obj.getCurrentInventoryCapacityUsage())
        {
            writer.writePropertyName("currentInventoryCapacityUsage");
            writer.writeInt32(*obj.getCurrentInventoryCapacityUsage());
        }
        if (obj.getCurrentInventoryMaxCapacity())
        {
            writer.writePropertyName("currentInventoryMaxCapacity");
            writer.writeInt32(*obj.getCurrentInventoryMaxCapacity());
        }
        if (obj.getCreatedAt())
        {
            writer.writePropertyName("createdAt");
            writer.writeInt64(*obj.getCreatedAt());
        }
        if (obj.getUpdatedAt())
        {
            writer.writePropertyName("updatedAt");
            writer.writeInt64(*obj.getUpdatedAt());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const ItemSet& obj)
    {
        writer.writeObjectStart();
        if (obj.getItemSetId())
        {
            writer.writePropertyName("itemSetId");
            writer.writeCharArray(*obj.getItemSetId());
        }
        if (obj.getInventoryName())
        {
            writer.writePropertyName("inventoryName");
            writer.writeCharArray(*obj.getInventoryName());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.writeCharArray(*obj.getUserId());
        }
        if (obj.getItemName())
        {
            writer.writePropertyName("itemName");
            writer.writeCharArray(*obj.getItemName());
        }
        if (obj.getCount())
        {
            writer.writePropertyName("count");
            writer.writeInt64(*obj.getCount());
        }
        if (obj.getSortValue())
        {
            writer.writePropertyName("sortValue");
            writer.writeInt32(*obj.getSortValue());
        }
        if (obj.getExpiresAt())
        {
            writer.writePropertyName("expiresAt");
            writer.writeInt64(*obj.getExpiresAt());
        }
        if (obj.getCreatedAt())
        {
            writer.writePropertyName("createdAt");
            writer.writeInt64(*obj.getCreatedAt());
        }
        if (obj.getUpdatedAt())
        {
            writer.writePropertyName("updatedAt");
            writer.writeInt64(*obj.getUpdatedAt());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const ResponseCache& obj)
    {
        writer.writeObjectStart();
        if (obj.getRegion())
        {
            writer.writePropertyName("region");
            writer.writeCharArray(*obj.getRegion());
        }
        if (obj.getOwnerId())
        {
            writer.writePropertyName("ownerId");
            writer.writeCharArray(*obj.getOwnerId());
        }
        if (obj.getResponseCacheId())
        {
            writer.writePropertyName("responseCacheId");
            writer.writeCharArray(*obj.getResponseCacheId());
        }
        if (obj.getRequestHash())
        {
            writer.writePropertyName("requestHash");
            writer.writeCharArray(*obj.getRequestHash());
        }
        if (obj.getResult())
        {
            writer.writePropertyName("result");
            writer.writeCharArray(*obj.getResult());
        }
        writer.writeObjectEnd();
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
    void describeNamespaces(std::function<void(AsyncDescribeNamespacesResult&)> callback, DescribeNamespacesRequest& request)
    {
        DescribeNamespacesTask& task = *new DescribeNamespacesTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ネームスペースを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createNamespace(std::function<void(AsyncCreateNamespaceResult&)> callback, CreateNamespaceRequest& request)
    {
        CreateNamespaceTask& task = *new CreateNamespaceTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ネームスペースの状態を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getNamespaceStatus(std::function<void(AsyncGetNamespaceStatusResult&)> callback, GetNamespaceStatusRequest& request)
    {
        GetNamespaceStatusTask& task = *new GetNamespaceStatusTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ネームスペースを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getNamespace(std::function<void(AsyncGetNamespaceResult&)> callback, GetNamespaceRequest& request)
    {
        GetNamespaceTask& task = *new GetNamespaceTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ネームスペースを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateNamespace(std::function<void(AsyncUpdateNamespaceResult&)> callback, UpdateNamespaceRequest& request)
    {
        UpdateNamespaceTask& task = *new UpdateNamespaceTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ネームスペースを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteNamespace(std::function<void(AsyncDeleteNamespaceResult&)> callback, DeleteNamespaceRequest& request)
    {
        DeleteNamespaceTask& task = *new DeleteNamespaceTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * インベントリモデルマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeInventoryModelMasters(std::function<void(AsyncDescribeInventoryModelMastersResult&)> callback, DescribeInventoryModelMastersRequest& request)
    {
        DescribeInventoryModelMastersTask& task = *new DescribeInventoryModelMastersTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * インベントリモデルマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createInventoryModelMaster(std::function<void(AsyncCreateInventoryModelMasterResult&)> callback, CreateInventoryModelMasterRequest& request)
    {
        CreateInventoryModelMasterTask& task = *new CreateInventoryModelMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * インベントリモデルマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getInventoryModelMaster(std::function<void(AsyncGetInventoryModelMasterResult&)> callback, GetInventoryModelMasterRequest& request)
    {
        GetInventoryModelMasterTask& task = *new GetInventoryModelMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * インベントリモデルマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateInventoryModelMaster(std::function<void(AsyncUpdateInventoryModelMasterResult&)> callback, UpdateInventoryModelMasterRequest& request)
    {
        UpdateInventoryModelMasterTask& task = *new UpdateInventoryModelMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * インベントリモデルマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteInventoryModelMaster(std::function<void(AsyncDeleteInventoryModelMasterResult&)> callback, DeleteInventoryModelMasterRequest& request)
    {
        DeleteInventoryModelMasterTask& task = *new DeleteInventoryModelMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * インベントリモデルの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeInventoryModels(std::function<void(AsyncDescribeInventoryModelsResult&)> callback, DescribeInventoryModelsRequest& request)
    {
        DescribeInventoryModelsTask& task = *new DescribeInventoryModelsTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * インベントリモデルを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getInventoryModel(std::function<void(AsyncGetInventoryModelResult&)> callback, GetInventoryModelRequest& request)
    {
        GetInventoryModelTask& task = *new GetInventoryModelTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * アイテムモデルマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeItemModelMasters(std::function<void(AsyncDescribeItemModelMastersResult&)> callback, DescribeItemModelMastersRequest& request)
    {
        DescribeItemModelMastersTask& task = *new DescribeItemModelMastersTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * アイテムモデルマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createItemModelMaster(std::function<void(AsyncCreateItemModelMasterResult&)> callback, CreateItemModelMasterRequest& request)
    {
        CreateItemModelMasterTask& task = *new CreateItemModelMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * アイテムモデルマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getItemModelMaster(std::function<void(AsyncGetItemModelMasterResult&)> callback, GetItemModelMasterRequest& request)
    {
        GetItemModelMasterTask& task = *new GetItemModelMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * アイテムモデルマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateItemModelMaster(std::function<void(AsyncUpdateItemModelMasterResult&)> callback, UpdateItemModelMasterRequest& request)
    {
        UpdateItemModelMasterTask& task = *new UpdateItemModelMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * アイテムモデルマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteItemModelMaster(std::function<void(AsyncDeleteItemModelMasterResult&)> callback, DeleteItemModelMasterRequest& request)
    {
        DeleteItemModelMasterTask& task = *new DeleteItemModelMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * Noneの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeItemModels(std::function<void(AsyncDescribeItemModelsResult&)> callback, DescribeItemModelsRequest& request)
    {
        DescribeItemModelsTask& task = *new DescribeItemModelsTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * Noneを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getItemModel(std::function<void(AsyncGetItemModelResult&)> callback, GetItemModelRequest& request)
    {
        GetItemModelTask& task = *new GetItemModelTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 現在有効な所持品マスターのマスターデータをエクスポートします<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void exportMaster(std::function<void(AsyncExportMasterResult&)> callback, ExportMasterRequest& request)
    {
        ExportMasterTask& task = *new ExportMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 現在有効な現在有効な所持品マスターを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentItemModelMaster(std::function<void(AsyncGetCurrentItemModelMasterResult&)> callback, GetCurrentItemModelMasterRequest& request)
    {
        GetCurrentItemModelMasterTask& task = *new GetCurrentItemModelMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 現在有効な現在有効な所持品マスターを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentItemModelMaster(std::function<void(AsyncUpdateCurrentItemModelMasterResult&)> callback, UpdateCurrentItemModelMasterRequest& request)
    {
        UpdateCurrentItemModelMasterTask& task = *new UpdateCurrentItemModelMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * インベントリの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeInventories(std::function<void(AsyncDescribeInventoriesResult&)> callback, DescribeInventoriesRequest& request)
    {
        DescribeInventoriesTask& task = *new DescribeInventoriesTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * インベントリの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeInventoriesByUserId(std::function<void(AsyncDescribeInventoriesByUserIdResult&)> callback, DescribeInventoriesByUserIdRequest& request)
    {
        DescribeInventoriesByUserIdTask& task = *new DescribeInventoriesByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * インベントリを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getInventory(std::function<void(AsyncGetInventoryResult&)> callback, GetInventoryRequest& request)
    {
        GetInventoryTask& task = *new GetInventoryTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * インベントリを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getInventoryByUserId(std::function<void(AsyncGetInventoryByUserIdResult&)> callback, GetInventoryByUserIdRequest& request)
    {
        GetInventoryByUserIdTask& task = *new GetInventoryByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * キャパシティサイズを加算<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void addCapacityByUserId(std::function<void(AsyncAddCapacityByUserIdResult&)> callback, AddCapacityByUserIdRequest& request)
    {
        AddCapacityByUserIdTask& task = *new AddCapacityByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * キャパシティサイズを設定<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setCapacityByUserId(std::function<void(AsyncSetCapacityByUserIdResult&)> callback, SetCapacityByUserIdRequest& request)
    {
        SetCapacityByUserIdTask& task = *new SetCapacityByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * インベントリを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteInventoryByUserId(std::function<void(AsyncDeleteInventoryByUserIdResult&)> callback, DeleteInventoryByUserIdRequest& request)
    {
        DeleteInventoryByUserIdTask& task = *new DeleteInventoryByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * スタンプシートでキャパシティサイズを加算<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void addCapacityByStampSheet(std::function<void(AsyncAddCapacityByStampSheetResult&)> callback, AddCapacityByStampSheetRequest& request)
    {
        AddCapacityByStampSheetTask& task = *new AddCapacityByStampSheetTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * スタンプシートでキャパシティサイズを設定<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setCapacityByStampSheet(std::function<void(AsyncSetCapacityByStampSheetResult&)> callback, SetCapacityByStampSheetRequest& request)
    {
        SetCapacityByStampSheetTask& task = *new SetCapacityByStampSheetTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 有効期限ごとのアイテム所持数量の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeItemSets(std::function<void(AsyncDescribeItemSetsResult&)> callback, DescribeItemSetsRequest& request)
    {
        DescribeItemSetsTask& task = *new DescribeItemSetsTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 有効期限ごとのアイテム所持数量の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeItemSetsByUserId(std::function<void(AsyncDescribeItemSetsByUserIdResult&)> callback, DescribeItemSetsByUserIdRequest& request)
    {
        DescribeItemSetsByUserIdTask& task = *new DescribeItemSetsByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 有効期限ごとのアイテム所持数量を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getItemSet(std::function<void(AsyncGetItemSetResult&)> callback, GetItemSetRequest& request)
    {
        GetItemSetTask& task = *new GetItemSetTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 有効期限ごとのアイテム所持数量を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getItemSetByUserId(std::function<void(AsyncGetItemSetByUserIdResult&)> callback, GetItemSetByUserIdRequest& request)
    {
        GetItemSetByUserIdTask& task = *new GetItemSetByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * アイテムをインベントリに追加<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void acquireItemSetByUserId(std::function<void(AsyncAcquireItemSetByUserIdResult&)> callback, AcquireItemSetByUserIdRequest& request)
    {
        AcquireItemSetByUserIdTask& task = *new AcquireItemSetByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * インベントリのアイテムを消費<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void consumeItemSet(std::function<void(AsyncConsumeItemSetResult&)> callback, ConsumeItemSetRequest& request)
    {
        ConsumeItemSetTask& task = *new ConsumeItemSetTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * インベントリのアイテムを消費<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void consumeItemSetByUserId(std::function<void(AsyncConsumeItemSetByUserIdResult&)> callback, ConsumeItemSetByUserIdRequest& request)
    {
        ConsumeItemSetByUserIdTask& task = *new ConsumeItemSetByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 有効期限ごとのアイテム所持数量を削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteItemSetByUserId(std::function<void(AsyncDeleteItemSetByUserIdResult&)> callback, DeleteItemSetByUserIdRequest& request)
    {
        DeleteItemSetByUserIdTask& task = *new DeleteItemSetByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * スタンプシートでアイテムをインベントリに追加<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void acquireItemSetByStampSheet(std::function<void(AsyncAcquireItemSetByStampSheetResult&)> callback, AcquireItemSetByStampSheetRequest& request)
    {
        AcquireItemSetByStampSheetTask& task = *new AcquireItemSetByStampSheetTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * スタンプシートでインベントリのアイテムを消費<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void consumeItemSetByStampTask(std::function<void(AsyncConsumeItemSetByStampTaskResult&)> callback, ConsumeItemSetByStampTaskRequest& request)
    {
        ConsumeItemSetByStampTaskTask& task = *new ConsumeItemSetByStampTaskTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_INVENTORY_GS2INVENTORYWEBSOCKETCLIENT_HPP_