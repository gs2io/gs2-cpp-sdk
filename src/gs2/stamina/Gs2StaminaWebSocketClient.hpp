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

#ifndef GS2_STAMINA_GS2STAMINAWEBSOCKETCLIENT_HPP_
#define GS2_STAMINA_GS2STAMINAWEBSOCKETCLIENT_HPP_

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
#include "request/DescribeStaminaModelMastersRequest.hpp"
#include "request/CreateStaminaModelMasterRequest.hpp"
#include "request/GetStaminaModelMasterRequest.hpp"
#include "request/UpdateStaminaModelMasterRequest.hpp"
#include "request/DeleteStaminaModelMasterRequest.hpp"
#include "request/DescribeMaxStaminaTableMastersRequest.hpp"
#include "request/CreateMaxStaminaTableMasterRequest.hpp"
#include "request/GetMaxStaminaTableMasterRequest.hpp"
#include "request/UpdateMaxStaminaTableMasterRequest.hpp"
#include "request/DeleteMaxStaminaTableMasterRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentStaminaMasterRequest.hpp"
#include "request/UpdateCurrentStaminaMasterRequest.hpp"
#include "request/UpdateCurrentStaminaMasterFromGitHubRequest.hpp"
#include "request/DescribeStaminaModelsRequest.hpp"
#include "request/GetStaminaModelRequest.hpp"
#include "request/DescribeStaminasRequest.hpp"
#include "request/DescribeStaminasByUserIdRequest.hpp"
#include "request/GetStaminaRequest.hpp"
#include "request/GetStaminaByUserIdRequest.hpp"
#include "request/UpdateStaminaByUserIdRequest.hpp"
#include "request/ConsumeStaminaRequest.hpp"
#include "request/ConsumeStaminaByUserIdRequest.hpp"
#include "request/RecoverStaminaByUserIdRequest.hpp"
#include "request/RaiseMaxValueByUserIdRequest.hpp"
#include "request/SetMaxValueByUserIdRequest.hpp"
#include "request/SetMaxValueByStatusRequest.hpp"
#include "request/DeleteStaminaByUserIdRequest.hpp"
#include "request/RecoverStaminaByStampSheetRequest.hpp"
#include "request/RaiseMaxValueByStampSheetRequest.hpp"
#include "request/SetMaxValueByStampSheetRequest.hpp"
#include "request/ConsumeStaminaByStampTaskRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeStaminaModelMastersResult.hpp"
#include "result/CreateStaminaModelMasterResult.hpp"
#include "result/GetStaminaModelMasterResult.hpp"
#include "result/UpdateStaminaModelMasterResult.hpp"
#include "result/DeleteStaminaModelMasterResult.hpp"
#include "result/DescribeMaxStaminaTableMastersResult.hpp"
#include "result/CreateMaxStaminaTableMasterResult.hpp"
#include "result/GetMaxStaminaTableMasterResult.hpp"
#include "result/UpdateMaxStaminaTableMasterResult.hpp"
#include "result/DeleteMaxStaminaTableMasterResult.hpp"
#include "result/ExportMasterResult.hpp"
#include "result/GetCurrentStaminaMasterResult.hpp"
#include "result/UpdateCurrentStaminaMasterResult.hpp"
#include "result/UpdateCurrentStaminaMasterFromGitHubResult.hpp"
#include "result/DescribeStaminaModelsResult.hpp"
#include "result/GetStaminaModelResult.hpp"
#include "result/DescribeStaminasResult.hpp"
#include "result/DescribeStaminasByUserIdResult.hpp"
#include "result/GetStaminaResult.hpp"
#include "result/GetStaminaByUserIdResult.hpp"
#include "result/UpdateStaminaByUserIdResult.hpp"
#include "result/ConsumeStaminaResult.hpp"
#include "result/ConsumeStaminaByUserIdResult.hpp"
#include "result/RecoverStaminaByUserIdResult.hpp"
#include "result/RaiseMaxValueByUserIdResult.hpp"
#include "result/SetMaxValueByUserIdResult.hpp"
#include "result/SetMaxValueByStatusResult.hpp"
#include "result/DeleteStaminaByUserIdResult.hpp"
#include "result/RecoverStaminaByStampSheetResult.hpp"
#include "result/RaiseMaxValueByStampSheetResult.hpp"
#include "result/SetMaxValueByStampSheetResult.hpp"
#include "result/ConsumeStaminaByStampTaskResult.hpp"
#include <cstring>

namespace gs2 { namespace stamina {

/**
 * GS2 Stamina API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2StaminaWebSocketClient : public AbstractGs2ClientBase
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
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
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

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("stamina");
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
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
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
            if (m_Request.getOverflowTriggerScriptId())
            {
                writer.writePropertyName("overflowTriggerScriptId");
                writer.writeCharArray(*m_Request.getOverflowTriggerScriptId());
            }
            if (m_Request.getOverflowTriggerNamespaceId())
            {
                writer.writePropertyName("overflowTriggerNamespaceId");
                writer.writeCharArray(*m_Request.getOverflowTriggerNamespaceId());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("stamina");
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
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
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

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("stamina");
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
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
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

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("stamina");
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
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
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
            if (m_Request.getOverflowTriggerScriptId())
            {
                writer.writePropertyName("overflowTriggerScriptId");
                writer.writeCharArray(*m_Request.getOverflowTriggerScriptId());
            }
            if (m_Request.getOverflowTriggerNamespaceId())
            {
                writer.writePropertyName("overflowTriggerNamespaceId");
                writer.writeCharArray(*m_Request.getOverflowTriggerNamespaceId());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("stamina");
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
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
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

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("stamina");
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

    class DescribeStaminaModelMastersTask : public detail::Gs2WebSocketSessionTask<DescribeStaminaModelMastersResult>
    {
    private:
        DescribeStaminaModelMastersRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
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

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("stamina");
            writer.writePropertyName("component");
            writer.writeCharArray("staminaModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("describeStaminaModelMasters");
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
        DescribeStaminaModelMastersTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeStaminaModelMastersRequest& request,
            Gs2WebSocketSessionTask<DescribeStaminaModelMastersResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeStaminaModelMastersResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeStaminaModelMastersTask() GS2_OVERRIDE = default;
    };

    class CreateStaminaModelMasterTask : public detail::Gs2WebSocketSessionTask<CreateStaminaModelMasterResult>
    {
    private:
        CreateStaminaModelMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
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
            if (m_Request.getRecoverIntervalMinutes())
            {
                writer.writePropertyName("recoverIntervalMinutes");
                writer.writeInt32(*m_Request.getRecoverIntervalMinutes());
            }
            if (m_Request.getRecoverValue())
            {
                writer.writePropertyName("recoverValue");
                writer.writeInt32(*m_Request.getRecoverValue());
            }
            if (m_Request.getInitialCapacity())
            {
                writer.writePropertyName("initialCapacity");
                writer.writeInt32(*m_Request.getInitialCapacity());
            }
            if (m_Request.getIsOverflow())
            {
                writer.writePropertyName("isOverflow");
                writer.writeBool(*m_Request.getIsOverflow());
            }
            if (m_Request.getMaxCapacity())
            {
                writer.writePropertyName("maxCapacity");
                writer.writeInt32(*m_Request.getMaxCapacity());
            }
            if (m_Request.getMaxStaminaTableId())
            {
                writer.writePropertyName("maxStaminaTableId");
                writer.writeCharArray(*m_Request.getMaxStaminaTableId());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("stamina");
            writer.writePropertyName("component");
            writer.writeCharArray("staminaModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("createStaminaModelMaster");
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
        CreateStaminaModelMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            CreateStaminaModelMasterRequest& request,
            Gs2WebSocketSessionTask<CreateStaminaModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateStaminaModelMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~CreateStaminaModelMasterTask() GS2_OVERRIDE = default;
    };

    class GetStaminaModelMasterTask : public detail::Gs2WebSocketSessionTask<GetStaminaModelMasterResult>
    {
    private:
        GetStaminaModelMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getStaminaName())
            {
                writer.writePropertyName("staminaName");
                writer.writeCharArray(*m_Request.getStaminaName());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("stamina");
            writer.writePropertyName("component");
            writer.writeCharArray("staminaModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("getStaminaModelMaster");
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
        GetStaminaModelMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetStaminaModelMasterRequest& request,
            Gs2WebSocketSessionTask<GetStaminaModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetStaminaModelMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetStaminaModelMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateStaminaModelMasterTask : public detail::Gs2WebSocketSessionTask<UpdateStaminaModelMasterResult>
    {
    private:
        UpdateStaminaModelMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getStaminaName())
            {
                writer.writePropertyName("staminaName");
                writer.writeCharArray(*m_Request.getStaminaName());
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
            if (m_Request.getRecoverIntervalMinutes())
            {
                writer.writePropertyName("recoverIntervalMinutes");
                writer.writeInt32(*m_Request.getRecoverIntervalMinutes());
            }
            if (m_Request.getRecoverValue())
            {
                writer.writePropertyName("recoverValue");
                writer.writeInt32(*m_Request.getRecoverValue());
            }
            if (m_Request.getInitialCapacity())
            {
                writer.writePropertyName("initialCapacity");
                writer.writeInt32(*m_Request.getInitialCapacity());
            }
            if (m_Request.getIsOverflow())
            {
                writer.writePropertyName("isOverflow");
                writer.writeBool(*m_Request.getIsOverflow());
            }
            if (m_Request.getMaxCapacity())
            {
                writer.writePropertyName("maxCapacity");
                writer.writeInt32(*m_Request.getMaxCapacity());
            }
            if (m_Request.getMaxStaminaTableId())
            {
                writer.writePropertyName("maxStaminaTableId");
                writer.writeCharArray(*m_Request.getMaxStaminaTableId());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("stamina");
            writer.writePropertyName("component");
            writer.writeCharArray("staminaModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("updateStaminaModelMaster");
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
        UpdateStaminaModelMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateStaminaModelMasterRequest& request,
            Gs2WebSocketSessionTask<UpdateStaminaModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateStaminaModelMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateStaminaModelMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteStaminaModelMasterTask : public detail::Gs2WebSocketSessionTask<DeleteStaminaModelMasterResult>
    {
    private:
        DeleteStaminaModelMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getStaminaName())
            {
                writer.writePropertyName("staminaName");
                writer.writeCharArray(*m_Request.getStaminaName());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("stamina");
            writer.writePropertyName("component");
            writer.writeCharArray("staminaModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteStaminaModelMaster");
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
        DeleteStaminaModelMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteStaminaModelMasterRequest& request,
            Gs2WebSocketSessionTask<DeleteStaminaModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteStaminaModelMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteStaminaModelMasterTask() GS2_OVERRIDE = default;
    };

    class DescribeMaxStaminaTableMastersTask : public detail::Gs2WebSocketSessionTask<DescribeMaxStaminaTableMastersResult>
    {
    private:
        DescribeMaxStaminaTableMastersRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
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

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("stamina");
            writer.writePropertyName("component");
            writer.writeCharArray("maxStaminaTableMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("describeMaxStaminaTableMasters");
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
        DescribeMaxStaminaTableMastersTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeMaxStaminaTableMastersRequest& request,
            Gs2WebSocketSessionTask<DescribeMaxStaminaTableMastersResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeMaxStaminaTableMastersResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeMaxStaminaTableMastersTask() GS2_OVERRIDE = default;
    };

    class CreateMaxStaminaTableMasterTask : public detail::Gs2WebSocketSessionTask<CreateMaxStaminaTableMasterResult>
    {
    private:
        CreateMaxStaminaTableMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
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
            if (m_Request.getExperienceModelId())
            {
                writer.writePropertyName("experienceModelId");
                writer.writeCharArray(*m_Request.getExperienceModelId());
            }
            if (m_Request.getValues())
            {
                writer.writePropertyName("values");
                writer.writeArrayStart();
                auto& list = *m_Request.getValues();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    writer.writeInt32(list[i]);
                }
                writer.writeArrayEnd();
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("stamina");
            writer.writePropertyName("component");
            writer.writeCharArray("maxStaminaTableMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("createMaxStaminaTableMaster");
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
        CreateMaxStaminaTableMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            CreateMaxStaminaTableMasterRequest& request,
            Gs2WebSocketSessionTask<CreateMaxStaminaTableMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateMaxStaminaTableMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~CreateMaxStaminaTableMasterTask() GS2_OVERRIDE = default;
    };

    class GetMaxStaminaTableMasterTask : public detail::Gs2WebSocketSessionTask<GetMaxStaminaTableMasterResult>
    {
    private:
        GetMaxStaminaTableMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getMaxStaminaTableName())
            {
                writer.writePropertyName("maxStaminaTableName");
                writer.writeCharArray(*m_Request.getMaxStaminaTableName());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("stamina");
            writer.writePropertyName("component");
            writer.writeCharArray("maxStaminaTableMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("getMaxStaminaTableMaster");
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
        GetMaxStaminaTableMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetMaxStaminaTableMasterRequest& request,
            Gs2WebSocketSessionTask<GetMaxStaminaTableMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetMaxStaminaTableMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetMaxStaminaTableMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateMaxStaminaTableMasterTask : public detail::Gs2WebSocketSessionTask<UpdateMaxStaminaTableMasterResult>
    {
    private:
        UpdateMaxStaminaTableMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getMaxStaminaTableName())
            {
                writer.writePropertyName("maxStaminaTableName");
                writer.writeCharArray(*m_Request.getMaxStaminaTableName());
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
            if (m_Request.getExperienceModelId())
            {
                writer.writePropertyName("experienceModelId");
                writer.writeCharArray(*m_Request.getExperienceModelId());
            }
            if (m_Request.getValues())
            {
                writer.writePropertyName("values");
                writer.writeArrayStart();
                auto& list = *m_Request.getValues();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    writer.writeInt32(list[i]);
                }
                writer.writeArrayEnd();
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("stamina");
            writer.writePropertyName("component");
            writer.writeCharArray("maxStaminaTableMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("updateMaxStaminaTableMaster");
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
        UpdateMaxStaminaTableMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateMaxStaminaTableMasterRequest& request,
            Gs2WebSocketSessionTask<UpdateMaxStaminaTableMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateMaxStaminaTableMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateMaxStaminaTableMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteMaxStaminaTableMasterTask : public detail::Gs2WebSocketSessionTask<DeleteMaxStaminaTableMasterResult>
    {
    private:
        DeleteMaxStaminaTableMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getMaxStaminaTableName())
            {
                writer.writePropertyName("maxStaminaTableName");
                writer.writeCharArray(*m_Request.getMaxStaminaTableName());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("stamina");
            writer.writePropertyName("component");
            writer.writeCharArray("maxStaminaTableMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteMaxStaminaTableMaster");
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
        DeleteMaxStaminaTableMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteMaxStaminaTableMasterRequest& request,
            Gs2WebSocketSessionTask<DeleteMaxStaminaTableMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteMaxStaminaTableMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteMaxStaminaTableMasterTask() GS2_OVERRIDE = default;
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
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
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

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("stamina");
            writer.writePropertyName("component");
            writer.writeCharArray("currentStaminaMaster");
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

    class GetCurrentStaminaMasterTask : public detail::Gs2WebSocketSessionTask<GetCurrentStaminaMasterResult>
    {
    private:
        GetCurrentStaminaMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
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

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("stamina");
            writer.writePropertyName("component");
            writer.writeCharArray("currentStaminaMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("getCurrentStaminaMaster");
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
        GetCurrentStaminaMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetCurrentStaminaMasterRequest& request,
            Gs2WebSocketSessionTask<GetCurrentStaminaMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetCurrentStaminaMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetCurrentStaminaMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentStaminaMasterTask : public detail::Gs2WebSocketSessionTask<UpdateCurrentStaminaMasterResult>
    {
    private:
        UpdateCurrentStaminaMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
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

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("stamina");
            writer.writePropertyName("component");
            writer.writeCharArray("currentStaminaMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("updateCurrentStaminaMaster");
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
        UpdateCurrentStaminaMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateCurrentStaminaMasterRequest& request,
            Gs2WebSocketSessionTask<UpdateCurrentStaminaMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateCurrentStaminaMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateCurrentStaminaMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentStaminaMasterFromGitHubTask : public detail::Gs2WebSocketSessionTask<UpdateCurrentStaminaMasterFromGitHubResult>
    {
    private:
        UpdateCurrentStaminaMasterFromGitHubRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getCheckoutSetting())
            {
                writer.writePropertyName("checkoutSetting");
                write(writer, *m_Request.getCheckoutSetting());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("stamina");
            writer.writePropertyName("component");
            writer.writeCharArray("currentStaminaMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("updateCurrentStaminaMasterFromGitHub");
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
        UpdateCurrentStaminaMasterFromGitHubTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateCurrentStaminaMasterFromGitHubRequest& request,
            Gs2WebSocketSessionTask<UpdateCurrentStaminaMasterFromGitHubResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateCurrentStaminaMasterFromGitHubResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateCurrentStaminaMasterFromGitHubTask() GS2_OVERRIDE = default;
    };

    class DescribeStaminaModelsTask : public detail::Gs2WebSocketSessionTask<DescribeStaminaModelsResult>
    {
    private:
        DescribeStaminaModelsRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
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

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("stamina");
            writer.writePropertyName("component");
            writer.writeCharArray("staminaModel");
            writer.writePropertyName("function");
            writer.writeCharArray("describeStaminaModels");
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
        DescribeStaminaModelsTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeStaminaModelsRequest& request,
            Gs2WebSocketSessionTask<DescribeStaminaModelsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeStaminaModelsResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeStaminaModelsTask() GS2_OVERRIDE = default;
    };

    class GetStaminaModelTask : public detail::Gs2WebSocketSessionTask<GetStaminaModelResult>
    {
    private:
        GetStaminaModelRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getStaminaName())
            {
                writer.writePropertyName("staminaName");
                writer.writeCharArray(*m_Request.getStaminaName());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("stamina");
            writer.writePropertyName("component");
            writer.writeCharArray("staminaModel");
            writer.writePropertyName("function");
            writer.writeCharArray("getStaminaModel");
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
        GetStaminaModelTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetStaminaModelRequest& request,
            Gs2WebSocketSessionTask<GetStaminaModelResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetStaminaModelResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetStaminaModelTask() GS2_OVERRIDE = default;
    };

    class DescribeStaminasTask : public detail::Gs2WebSocketSessionTask<DescribeStaminasResult>
    {
    private:
        DescribeStaminasRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
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
            writer.writeCharArray("stamina");
            writer.writePropertyName("component");
            writer.writeCharArray("stamina");
            writer.writePropertyName("function");
            writer.writeCharArray("describeStaminas");
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
        DescribeStaminasTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeStaminasRequest& request,
            Gs2WebSocketSessionTask<DescribeStaminasResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeStaminasResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeStaminasTask() GS2_OVERRIDE = default;
    };

    class DescribeStaminasByUserIdTask : public detail::Gs2WebSocketSessionTask<DescribeStaminasByUserIdResult>
    {
    private:
        DescribeStaminasByUserIdRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
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
            writer.writeCharArray("stamina");
            writer.writePropertyName("component");
            writer.writeCharArray("stamina");
            writer.writePropertyName("function");
            writer.writeCharArray("describeStaminasByUserId");
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
        DescribeStaminasByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeStaminasByUserIdRequest& request,
            Gs2WebSocketSessionTask<DescribeStaminasByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeStaminasByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeStaminasByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetStaminaTask : public detail::Gs2WebSocketSessionTask<GetStaminaResult>
    {
    private:
        GetStaminaRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getStaminaName())
            {
                writer.writePropertyName("staminaName");
                writer.writeCharArray(*m_Request.getStaminaName());
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
            writer.writeCharArray("stamina");
            writer.writePropertyName("component");
            writer.writeCharArray("stamina");
            writer.writePropertyName("function");
            writer.writeCharArray("getStamina");
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
        GetStaminaTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetStaminaRequest& request,
            Gs2WebSocketSessionTask<GetStaminaResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetStaminaResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetStaminaTask() GS2_OVERRIDE = default;
    };

    class GetStaminaByUserIdTask : public detail::Gs2WebSocketSessionTask<GetStaminaByUserIdResult>
    {
    private:
        GetStaminaByUserIdRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getStaminaName())
            {
                writer.writePropertyName("staminaName");
                writer.writeCharArray(*m_Request.getStaminaName());
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
            writer.writeCharArray("stamina");
            writer.writePropertyName("component");
            writer.writeCharArray("stamina");
            writer.writePropertyName("function");
            writer.writeCharArray("getStaminaByUserId");
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
        GetStaminaByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetStaminaByUserIdRequest& request,
            Gs2WebSocketSessionTask<GetStaminaByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetStaminaByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetStaminaByUserIdTask() GS2_OVERRIDE = default;
    };

    class UpdateStaminaByUserIdTask : public detail::Gs2WebSocketSessionTask<UpdateStaminaByUserIdResult>
    {
    private:
        UpdateStaminaByUserIdRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getStaminaName())
            {
                writer.writePropertyName("staminaName");
                writer.writeCharArray(*m_Request.getStaminaName());
            }
            if (m_Request.getUserId())
            {
                writer.writePropertyName("userId");
                writer.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getValue())
            {
                writer.writePropertyName("value");
                writer.writeInt32(*m_Request.getValue());
            }
            if (m_Request.getMaxValue())
            {
                writer.writePropertyName("maxValue");
                writer.writeInt32(*m_Request.getMaxValue());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
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
            writer.writeCharArray("stamina");
            writer.writePropertyName("component");
            writer.writeCharArray("stamina");
            writer.writePropertyName("function");
            writer.writeCharArray("updateStaminaByUserId");
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
        UpdateStaminaByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateStaminaByUserIdRequest& request,
            Gs2WebSocketSessionTask<UpdateStaminaByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateStaminaByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateStaminaByUserIdTask() GS2_OVERRIDE = default;
    };

    class ConsumeStaminaTask : public detail::Gs2WebSocketSessionTask<ConsumeStaminaResult>
    {
    private:
        ConsumeStaminaRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getStaminaName())
            {
                writer.writePropertyName("staminaName");
                writer.writeCharArray(*m_Request.getStaminaName());
            }
            if (m_Request.getConsumeValue())
            {
                writer.writePropertyName("consumeValue");
                writer.writeInt32(*m_Request.getConsumeValue());
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
            writer.writeCharArray("stamina");
            writer.writePropertyName("component");
            writer.writeCharArray("stamina");
            writer.writePropertyName("function");
            writer.writeCharArray("consumeStamina");
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
        ConsumeStaminaTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            ConsumeStaminaRequest& request,
            Gs2WebSocketSessionTask<ConsumeStaminaResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<ConsumeStaminaResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~ConsumeStaminaTask() GS2_OVERRIDE = default;
    };

    class ConsumeStaminaByUserIdTask : public detail::Gs2WebSocketSessionTask<ConsumeStaminaByUserIdResult>
    {
    private:
        ConsumeStaminaByUserIdRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getStaminaName())
            {
                writer.writePropertyName("staminaName");
                writer.writeCharArray(*m_Request.getStaminaName());
            }
            if (m_Request.getUserId())
            {
                writer.writePropertyName("userId");
                writer.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getConsumeValue())
            {
                writer.writePropertyName("consumeValue");
                writer.writeInt32(*m_Request.getConsumeValue());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
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
            writer.writeCharArray("stamina");
            writer.writePropertyName("component");
            writer.writeCharArray("stamina");
            writer.writePropertyName("function");
            writer.writeCharArray("consumeStaminaByUserId");
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
        ConsumeStaminaByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            ConsumeStaminaByUserIdRequest& request,
            Gs2WebSocketSessionTask<ConsumeStaminaByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<ConsumeStaminaByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~ConsumeStaminaByUserIdTask() GS2_OVERRIDE = default;
    };

    class RecoverStaminaByUserIdTask : public detail::Gs2WebSocketSessionTask<RecoverStaminaByUserIdResult>
    {
    private:
        RecoverStaminaByUserIdRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getStaminaName())
            {
                writer.writePropertyName("staminaName");
                writer.writeCharArray(*m_Request.getStaminaName());
            }
            if (m_Request.getUserId())
            {
                writer.writePropertyName("userId");
                writer.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getRecoverValue())
            {
                writer.writePropertyName("recoverValue");
                writer.writeInt32(*m_Request.getRecoverValue());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
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
            writer.writeCharArray("stamina");
            writer.writePropertyName("component");
            writer.writeCharArray("stamina");
            writer.writePropertyName("function");
            writer.writeCharArray("recoverStaminaByUserId");
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
        RecoverStaminaByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            RecoverStaminaByUserIdRequest& request,
            Gs2WebSocketSessionTask<RecoverStaminaByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<RecoverStaminaByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~RecoverStaminaByUserIdTask() GS2_OVERRIDE = default;
    };

    class RaiseMaxValueByUserIdTask : public detail::Gs2WebSocketSessionTask<RaiseMaxValueByUserIdResult>
    {
    private:
        RaiseMaxValueByUserIdRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getStaminaName())
            {
                writer.writePropertyName("staminaName");
                writer.writeCharArray(*m_Request.getStaminaName());
            }
            if (m_Request.getUserId())
            {
                writer.writePropertyName("userId");
                writer.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getRaiseValue())
            {
                writer.writePropertyName("raiseValue");
                writer.writeInt32(*m_Request.getRaiseValue());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
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
            writer.writeCharArray("stamina");
            writer.writePropertyName("component");
            writer.writeCharArray("stamina");
            writer.writePropertyName("function");
            writer.writeCharArray("raiseMaxValueByUserId");
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
        RaiseMaxValueByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            RaiseMaxValueByUserIdRequest& request,
            Gs2WebSocketSessionTask<RaiseMaxValueByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<RaiseMaxValueByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~RaiseMaxValueByUserIdTask() GS2_OVERRIDE = default;
    };

    class SetMaxValueByUserIdTask : public detail::Gs2WebSocketSessionTask<SetMaxValueByUserIdResult>
    {
    private:
        SetMaxValueByUserIdRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getStaminaName())
            {
                writer.writePropertyName("staminaName");
                writer.writeCharArray(*m_Request.getStaminaName());
            }
            if (m_Request.getUserId())
            {
                writer.writePropertyName("userId");
                writer.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getMaxValue())
            {
                writer.writePropertyName("maxValue");
                writer.writeInt32(*m_Request.getMaxValue());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
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
            writer.writeCharArray("stamina");
            writer.writePropertyName("component");
            writer.writeCharArray("stamina");
            writer.writePropertyName("function");
            writer.writeCharArray("setMaxValueByUserId");
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
        SetMaxValueByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            SetMaxValueByUserIdRequest& request,
            Gs2WebSocketSessionTask<SetMaxValueByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<SetMaxValueByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~SetMaxValueByUserIdTask() GS2_OVERRIDE = default;
    };

    class SetMaxValueByStatusTask : public detail::Gs2WebSocketSessionTask<SetMaxValueByStatusResult>
    {
    private:
        SetMaxValueByStatusRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getStaminaName())
            {
                writer.writePropertyName("staminaName");
                writer.writeCharArray(*m_Request.getStaminaName());
            }
            if (m_Request.getKeyId())
            {
                writer.writePropertyName("keyId");
                writer.writeCharArray(*m_Request.getKeyId());
            }
            if (m_Request.getSignedStatusBody())
            {
                writer.writePropertyName("signedStatusBody");
                writer.writeCharArray(*m_Request.getSignedStatusBody());
            }
            if (m_Request.getSignedStatusSignature())
            {
                writer.writePropertyName("signedStatusSignature");
                writer.writeCharArray(*m_Request.getSignedStatusSignature());
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
            writer.writeCharArray("stamina");
            writer.writePropertyName("component");
            writer.writeCharArray("stamina");
            writer.writePropertyName("function");
            writer.writeCharArray("setMaxValueByStatus");
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
        SetMaxValueByStatusTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            SetMaxValueByStatusRequest& request,
            Gs2WebSocketSessionTask<SetMaxValueByStatusResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<SetMaxValueByStatusResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~SetMaxValueByStatusTask() GS2_OVERRIDE = default;
    };

    class DeleteStaminaByUserIdTask : public detail::Gs2WebSocketSessionTask<void>
    {
    private:
        DeleteStaminaByUserIdRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getStaminaName())
            {
                writer.writePropertyName("staminaName");
                writer.writeCharArray(*m_Request.getStaminaName());
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
            writer.writeCharArray("stamina");
            writer.writePropertyName("component");
            writer.writeCharArray("stamina");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteStaminaByUserId");
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
        DeleteStaminaByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteStaminaByUserIdRequest& request,
            Gs2WebSocketSessionTask<void>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<void>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteStaminaByUserIdTask() GS2_OVERRIDE = default;
    };

    class RecoverStaminaByStampSheetTask : public detail::Gs2WebSocketSessionTask<RecoverStaminaByStampSheetResult>
    {
    private:
        RecoverStaminaByStampSheetRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
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
            writer.writeCharArray("stamina");
            writer.writePropertyName("component");
            writer.writeCharArray("stamina");
            writer.writePropertyName("function");
            writer.writeCharArray("recoverStaminaByStampSheet");
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
        RecoverStaminaByStampSheetTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            RecoverStaminaByStampSheetRequest& request,
            Gs2WebSocketSessionTask<RecoverStaminaByStampSheetResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<RecoverStaminaByStampSheetResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~RecoverStaminaByStampSheetTask() GS2_OVERRIDE = default;
    };

    class RaiseMaxValueByStampSheetTask : public detail::Gs2WebSocketSessionTask<RaiseMaxValueByStampSheetResult>
    {
    private:
        RaiseMaxValueByStampSheetRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
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
            writer.writeCharArray("stamina");
            writer.writePropertyName("component");
            writer.writeCharArray("stamina");
            writer.writePropertyName("function");
            writer.writeCharArray("raiseMaxValueByStampSheet");
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
        RaiseMaxValueByStampSheetTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            RaiseMaxValueByStampSheetRequest& request,
            Gs2WebSocketSessionTask<RaiseMaxValueByStampSheetResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<RaiseMaxValueByStampSheetResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~RaiseMaxValueByStampSheetTask() GS2_OVERRIDE = default;
    };

    class SetMaxValueByStampSheetTask : public detail::Gs2WebSocketSessionTask<SetMaxValueByStampSheetResult>
    {
    private:
        SetMaxValueByStampSheetRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
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
            writer.writeCharArray("stamina");
            writer.writePropertyName("component");
            writer.writeCharArray("stamina");
            writer.writePropertyName("function");
            writer.writeCharArray("setMaxValueByStampSheet");
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
        SetMaxValueByStampSheetTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            SetMaxValueByStampSheetRequest& request,
            Gs2WebSocketSessionTask<SetMaxValueByStampSheetResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<SetMaxValueByStampSheetResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~SetMaxValueByStampSheetTask() GS2_OVERRIDE = default;
    };

    class ConsumeStaminaByStampTaskTask : public detail::Gs2WebSocketSessionTask<ConsumeStaminaByStampTaskResult>
    {
    private:
        ConsumeStaminaByStampTaskRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
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
            writer.writeCharArray("stamina");
            writer.writePropertyName("component");
            writer.writeCharArray("stamina");
            writer.writePropertyName("function");
            writer.writeCharArray("consumeStaminaByStampTask");
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
        ConsumeStaminaByStampTaskTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            ConsumeStaminaByStampTaskRequest& request,
            Gs2WebSocketSessionTask<ConsumeStaminaByStampTaskResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<ConsumeStaminaByStampTaskResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~ConsumeStaminaByStampTaskTask() GS2_OVERRIDE = default;
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
        if (obj.getOverflowTriggerScriptId())
        {
            writer.writePropertyName("overflowTriggerScriptId");
            writer.writeCharArray(*obj.getOverflowTriggerScriptId());
        }
        if (obj.getOverflowTriggerNamespaceId())
        {
            writer.writePropertyName("overflowTriggerNamespaceId");
            writer.writeCharArray(*obj.getOverflowTriggerNamespaceId());
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

    static void write(detail::json::JsonWriter& writer, const StaminaModelMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getStaminaModelId())
        {
            writer.writePropertyName("staminaModelId");
            writer.writeCharArray(*obj.getStaminaModelId());
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
        if (obj.getRecoverIntervalMinutes())
        {
            writer.writePropertyName("recoverIntervalMinutes");
            writer.writeInt32(*obj.getRecoverIntervalMinutes());
        }
        if (obj.getRecoverValue())
        {
            writer.writePropertyName("recoverValue");
            writer.writeInt32(*obj.getRecoverValue());
        }
        if (obj.getInitialCapacity())
        {
            writer.writePropertyName("initialCapacity");
            writer.writeInt32(*obj.getInitialCapacity());
        }
        if (obj.getIsOverflow())
        {
            writer.writePropertyName("isOverflow");
            writer.writeBool(*obj.getIsOverflow());
        }
        if (obj.getMaxCapacity())
        {
            writer.writePropertyName("maxCapacity");
            writer.writeInt32(*obj.getMaxCapacity());
        }
        if (obj.getMaxStaminaTableId())
        {
            writer.writePropertyName("maxStaminaTableId");
            writer.writeCharArray(*obj.getMaxStaminaTableId());
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

    static void write(detail::json::JsonWriter& writer, const MaxStaminaTableMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getMaxStaminaTableId())
        {
            writer.writePropertyName("maxStaminaTableId");
            writer.writeCharArray(*obj.getMaxStaminaTableId());
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
        if (obj.getExperienceModelId())
        {
            writer.writePropertyName("experienceModelId");
            writer.writeCharArray(*obj.getExperienceModelId());
        }
        if (obj.getValues())
        {
            writer.writePropertyName("values");
            writer.writeArrayStart();
            auto& list = *obj.getValues();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                writer.writeInt32(list[i]);
            }
            writer.writeArrayEnd();
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const CurrentStaminaMaster& obj)
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

    static void write(detail::json::JsonWriter& writer, const StaminaModel& obj)
    {
        writer.writeObjectStart();
        if (obj.getStaminaModelId())
        {
            writer.writePropertyName("staminaModelId");
            writer.writeCharArray(*obj.getStaminaModelId());
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
        if (obj.getRecoverIntervalMinutes())
        {
            writer.writePropertyName("recoverIntervalMinutes");
            writer.writeInt32(*obj.getRecoverIntervalMinutes());
        }
        if (obj.getRecoverValue())
        {
            writer.writePropertyName("recoverValue");
            writer.writeInt32(*obj.getRecoverValue());
        }
        if (obj.getInitialCapacity())
        {
            writer.writePropertyName("initialCapacity");
            writer.writeInt32(*obj.getInitialCapacity());
        }
        if (obj.getIsOverflow())
        {
            writer.writePropertyName("isOverflow");
            writer.writeBool(*obj.getIsOverflow());
        }
        if (obj.getMaxCapacity())
        {
            writer.writePropertyName("maxCapacity");
            writer.writeInt32(*obj.getMaxCapacity());
        }
        if (obj.getMaxStaminaTable())
        {
            writer.writePropertyName("maxStaminaTable");
            write(writer, *obj.getMaxStaminaTable());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const MaxStaminaTable& obj)
    {
        writer.writeObjectStart();
        if (obj.getMaxStaminaTableId())
        {
            writer.writePropertyName("maxStaminaTableId");
            writer.writeCharArray(*obj.getMaxStaminaTableId());
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
        if (obj.getExperienceModelId())
        {
            writer.writePropertyName("experienceModelId");
            writer.writeCharArray(*obj.getExperienceModelId());
        }
        if (obj.getValues())
        {
            writer.writePropertyName("values");
            writer.writeArrayStart();
            auto& list = *obj.getValues();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                writer.writeInt32(list[i]);
            }
            writer.writeArrayEnd();
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const Stamina& obj)
    {
        writer.writeObjectStart();
        if (obj.getStaminaId())
        {
            writer.writePropertyName("staminaId");
            writer.writeCharArray(*obj.getStaminaId());
        }
        if (obj.getStaminaName())
        {
            writer.writePropertyName("staminaName");
            writer.writeCharArray(*obj.getStaminaName());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.writeCharArray(*obj.getUserId());
        }
        if (obj.getValue())
        {
            writer.writePropertyName("value");
            writer.writeInt32(*obj.getValue());
        }
        if (obj.getMaxValue())
        {
            writer.writePropertyName("maxValue");
            writer.writeInt32(*obj.getMaxValue());
        }
        if (obj.getOverflowValue())
        {
            writer.writePropertyName("overflowValue");
            writer.writeInt32(*obj.getOverflowValue());
        }
        if (obj.getNextRecoverAt())
        {
            writer.writePropertyName("nextRecoverAt");
            writer.writeInt64(*obj.getNextRecoverAt());
        }
        if (obj.getLastRecoveredAt())
        {
            writer.writePropertyName("lastRecoveredAt");
            writer.writeInt64(*obj.getLastRecoveredAt());
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

    static void write(detail::json::JsonWriter& writer, const GitHubCheckoutSetting& obj)
    {
        writer.writeObjectStart();
        if (obj.getGitHubApiKeyId())
        {
            writer.writePropertyName("gitHubApiKeyId");
            writer.writeCharArray(*obj.getGitHubApiKeyId());
        }
        if (obj.getRepositoryName())
        {
            writer.writePropertyName("repositoryName");
            writer.writeCharArray(*obj.getRepositoryName());
        }
        if (obj.getSourcePath())
        {
            writer.writePropertyName("sourcePath");
            writer.writeCharArray(*obj.getSourcePath());
        }
        if (obj.getReferenceType())
        {
            writer.writePropertyName("referenceType");
            writer.writeCharArray(*obj.getReferenceType());
        }
        if (obj.getCommitHash())
        {
            writer.writePropertyName("commitHash");
            writer.writeCharArray(*obj.getCommitHash());
        }
        if (obj.getBranchName())
        {
            writer.writePropertyName("branchName");
            writer.writeCharArray(*obj.getBranchName());
        }
        if (obj.getTagName())
        {
            writer.writePropertyName("tagName");
            writer.writeCharArray(*obj.getTagName());
        }
        writer.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param gs2WebSocketSession WebSocket API 用セッション
     */
    explicit Gs2StaminaWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
        AbstractGs2ClientBase(gs2WebSocketSession)
    {
    }

	/**
	 * ネームスペースの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeNamespaces(DescribeNamespacesRequest& request, std::function<void(AsyncDescribeNamespacesResult&)> callback)
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
    void createNamespace(CreateNamespaceRequest& request, std::function<void(AsyncCreateNamespaceResult&)> callback)
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
    void getNamespaceStatus(GetNamespaceStatusRequest& request, std::function<void(AsyncGetNamespaceStatusResult&)> callback)
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
    void getNamespace(GetNamespaceRequest& request, std::function<void(AsyncGetNamespaceResult&)> callback)
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
    void updateNamespace(UpdateNamespaceRequest& request, std::function<void(AsyncUpdateNamespaceResult&)> callback)
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
    void deleteNamespace(DeleteNamespaceRequest& request, std::function<void(AsyncDeleteNamespaceResult&)> callback)
    {
        DeleteNamespaceTask& task = *new DeleteNamespaceTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * スタミナモデルマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeStaminaModelMasters(DescribeStaminaModelMastersRequest& request, std::function<void(AsyncDescribeStaminaModelMastersResult&)> callback)
    {
        DescribeStaminaModelMastersTask& task = *new DescribeStaminaModelMastersTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * スタミナモデルマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createStaminaModelMaster(CreateStaminaModelMasterRequest& request, std::function<void(AsyncCreateStaminaModelMasterResult&)> callback)
    {
        CreateStaminaModelMasterTask& task = *new CreateStaminaModelMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * スタミナモデルマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStaminaModelMaster(GetStaminaModelMasterRequest& request, std::function<void(AsyncGetStaminaModelMasterResult&)> callback)
    {
        GetStaminaModelMasterTask& task = *new GetStaminaModelMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * スタミナモデルマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateStaminaModelMaster(UpdateStaminaModelMasterRequest& request, std::function<void(AsyncUpdateStaminaModelMasterResult&)> callback)
    {
        UpdateStaminaModelMasterTask& task = *new UpdateStaminaModelMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * スタミナモデルマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteStaminaModelMaster(DeleteStaminaModelMasterRequest& request, std::function<void(AsyncDeleteStaminaModelMasterResult&)> callback)
    {
        DeleteStaminaModelMasterTask& task = *new DeleteStaminaModelMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * スタミナの最大値テーブルマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeMaxStaminaTableMasters(DescribeMaxStaminaTableMastersRequest& request, std::function<void(AsyncDescribeMaxStaminaTableMastersResult&)> callback)
    {
        DescribeMaxStaminaTableMastersTask& task = *new DescribeMaxStaminaTableMastersTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * スタミナの最大値テーブルマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createMaxStaminaTableMaster(CreateMaxStaminaTableMasterRequest& request, std::function<void(AsyncCreateMaxStaminaTableMasterResult&)> callback)
    {
        CreateMaxStaminaTableMasterTask& task = *new CreateMaxStaminaTableMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * スタミナの最大値テーブルマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMaxStaminaTableMaster(GetMaxStaminaTableMasterRequest& request, std::function<void(AsyncGetMaxStaminaTableMasterResult&)> callback)
    {
        GetMaxStaminaTableMasterTask& task = *new GetMaxStaminaTableMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * スタミナの最大値テーブルマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateMaxStaminaTableMaster(UpdateMaxStaminaTableMasterRequest& request, std::function<void(AsyncUpdateMaxStaminaTableMasterResult&)> callback)
    {
        UpdateMaxStaminaTableMasterTask& task = *new UpdateMaxStaminaTableMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * スタミナの最大値テーブルマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteMaxStaminaTableMaster(DeleteMaxStaminaTableMasterRequest& request, std::function<void(AsyncDeleteMaxStaminaTableMasterResult&)> callback)
    {
        DeleteMaxStaminaTableMasterTask& task = *new DeleteMaxStaminaTableMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 現在有効なスタミナマスターのマスターデータをエクスポートします<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void exportMaster(ExportMasterRequest& request, std::function<void(AsyncExportMasterResult&)> callback)
    {
        ExportMasterTask& task = *new ExportMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 現在有効な現在有効なスタミナマスターを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentStaminaMaster(GetCurrentStaminaMasterRequest& request, std::function<void(AsyncGetCurrentStaminaMasterResult&)> callback)
    {
        GetCurrentStaminaMasterTask& task = *new GetCurrentStaminaMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 現在有効な現在有効なスタミナマスターを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentStaminaMaster(UpdateCurrentStaminaMasterRequest& request, std::function<void(AsyncUpdateCurrentStaminaMasterResult&)> callback)
    {
        UpdateCurrentStaminaMasterTask& task = *new UpdateCurrentStaminaMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 現在有効な現在有効なスタミナマスターを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentStaminaMasterFromGitHub(UpdateCurrentStaminaMasterFromGitHubRequest& request, std::function<void(AsyncUpdateCurrentStaminaMasterFromGitHubResult&)> callback)
    {
        UpdateCurrentStaminaMasterFromGitHubTask& task = *new UpdateCurrentStaminaMasterFromGitHubTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * スタミナモデルの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeStaminaModels(DescribeStaminaModelsRequest& request, std::function<void(AsyncDescribeStaminaModelsResult&)> callback)
    {
        DescribeStaminaModelsTask& task = *new DescribeStaminaModelsTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * スタミナモデルを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStaminaModel(GetStaminaModelRequest& request, std::function<void(AsyncGetStaminaModelResult&)> callback)
    {
        GetStaminaModelTask& task = *new GetStaminaModelTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * スタミナを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeStaminas(DescribeStaminasRequest& request, std::function<void(AsyncDescribeStaminasResult&)> callback)
    {
        DescribeStaminasTask& task = *new DescribeStaminasTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザIDを指定してスタミナを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeStaminasByUserId(DescribeStaminasByUserIdRequest& request, std::function<void(AsyncDescribeStaminasByUserIdResult&)> callback)
    {
        DescribeStaminasByUserIdTask& task = *new DescribeStaminasByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * スタミナを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStamina(GetStaminaRequest& request, std::function<void(AsyncGetStaminaResult&)> callback)
    {
        GetStaminaTask& task = *new GetStaminaTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザIDを指定してスタミナを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStaminaByUserId(GetStaminaByUserIdRequest& request, std::function<void(AsyncGetStaminaByUserIdResult&)> callback)
    {
        GetStaminaByUserIdTask& task = *new GetStaminaByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザIDを指定してスタミナを作成・更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateStaminaByUserId(UpdateStaminaByUserIdRequest& request, std::function<void(AsyncUpdateStaminaByUserIdResult&)> callback)
    {
        UpdateStaminaByUserIdTask& task = *new UpdateStaminaByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * スタミナを消費<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void consumeStamina(ConsumeStaminaRequest& request, std::function<void(AsyncConsumeStaminaResult&)> callback)
    {
        ConsumeStaminaTask& task = *new ConsumeStaminaTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザIDを指定してスタミナを消費<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void consumeStaminaByUserId(ConsumeStaminaByUserIdRequest& request, std::function<void(AsyncConsumeStaminaByUserIdResult&)> callback)
    {
        ConsumeStaminaByUserIdTask& task = *new ConsumeStaminaByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザIDを指定してスタミナを回復<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void recoverStaminaByUserId(RecoverStaminaByUserIdRequest& request, std::function<void(AsyncRecoverStaminaByUserIdResult&)> callback)
    {
        RecoverStaminaByUserIdTask& task = *new RecoverStaminaByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザIDを指定してスタミナの最大値を加算<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void raiseMaxValueByUserId(RaiseMaxValueByUserIdRequest& request, std::function<void(AsyncRaiseMaxValueByUserIdResult&)> callback)
    {
        RaiseMaxValueByUserIdTask& task = *new RaiseMaxValueByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザIDを指定してスタミナの最大値を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setMaxValueByUserId(SetMaxValueByUserIdRequest& request, std::function<void(AsyncSetMaxValueByUserIdResult&)> callback)
    {
        SetMaxValueByUserIdTask& task = *new SetMaxValueByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * スタミナの最大値をGS2-Experienceのステータスを使用して更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setMaxValueByStatus(SetMaxValueByStatusRequest& request, std::function<void(AsyncSetMaxValueByStatusResult&)> callback)
    {
        SetMaxValueByStatusTask& task = *new SetMaxValueByStatusTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザIDを指定してスタミナを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteStaminaByUserId(DeleteStaminaByUserIdRequest& request, std::function<void(AsyncDeleteStaminaByUserIdResult&)> callback)
    {
        DeleteStaminaByUserIdTask& task = *new DeleteStaminaByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * スタンプシートを使用してスタミナを回復<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void recoverStaminaByStampSheet(RecoverStaminaByStampSheetRequest& request, std::function<void(AsyncRecoverStaminaByStampSheetResult&)> callback)
    {
        RecoverStaminaByStampSheetTask& task = *new RecoverStaminaByStampSheetTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * スタンプシートでスタミナの最大値を加算<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void raiseMaxValueByStampSheet(RaiseMaxValueByStampSheetRequest& request, std::function<void(AsyncRaiseMaxValueByStampSheetResult&)> callback)
    {
        RaiseMaxValueByStampSheetTask& task = *new RaiseMaxValueByStampSheetTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * スタンプシートでスタミナの最大値を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setMaxValueByStampSheet(SetMaxValueByStampSheetRequest& request, std::function<void(AsyncSetMaxValueByStampSheetResult&)> callback)
    {
        SetMaxValueByStampSheetTask& task = *new SetMaxValueByStampSheetTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * スタンプタスクを使用してスタミナを消費<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void consumeStaminaByStampTask(ConsumeStaminaByStampTaskRequest& request, std::function<void(AsyncConsumeStaminaByStampTaskResult&)> callback)
    {
        ConsumeStaminaByStampTaskTask& task = *new ConsumeStaminaByStampTaskTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_STAMINA_GS2STAMINAWEBSOCKETCLIENT_HPP_