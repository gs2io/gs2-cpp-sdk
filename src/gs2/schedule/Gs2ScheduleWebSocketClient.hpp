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

#ifndef GS2_SCHEDULE_GS2SCHEDULEWEBSOCKETCLIENT_HPP_
#define GS2_SCHEDULE_GS2SCHEDULEWEBSOCKETCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2WebSocketSessionTask.hpp>
#include <gs2/core/network/Gs2WebSocketSession.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "model/model.hpp"
#include "request/DescribeNamespacesRequest.hpp"
#include "request/CreateNamespaceRequest.hpp"
#include "request/GetNamespaceStatusRequest.hpp"
#include "request/GetNamespaceRequest.hpp"
#include "request/UpdateNamespaceRequest.hpp"
#include "request/DeleteNamespaceRequest.hpp"
#include "request/DescribeEventMastersRequest.hpp"
#include "request/CreateEventMasterRequest.hpp"
#include "request/GetEventMasterRequest.hpp"
#include "request/UpdateEventMasterRequest.hpp"
#include "request/DeleteEventMasterRequest.hpp"
#include "request/DescribeTriggersRequest.hpp"
#include "request/DescribeTriggersByUserIdRequest.hpp"
#include "request/GetTriggerRequest.hpp"
#include "request/GetTriggerByUserIdRequest.hpp"
#include "request/TriggerByUserIdRequest.hpp"
#include "request/DeleteTriggerRequest.hpp"
#include "request/DeleteTriggerByUserIdRequest.hpp"
#include "request/DescribeEventsRequest.hpp"
#include "request/DescribeEventsByUserIdRequest.hpp"
#include "request/DescribeRawEventsRequest.hpp"
#include "request/GetEventRequest.hpp"
#include "request/GetEventByUserIdRequest.hpp"
#include "request/GetRawEventRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentEventMasterRequest.hpp"
#include "request/UpdateCurrentEventMasterRequest.hpp"
#include "request/UpdateCurrentEventMasterFromGitHubRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeEventMastersResult.hpp"
#include "result/CreateEventMasterResult.hpp"
#include "result/GetEventMasterResult.hpp"
#include "result/UpdateEventMasterResult.hpp"
#include "result/DeleteEventMasterResult.hpp"
#include "result/DescribeTriggersResult.hpp"
#include "result/DescribeTriggersByUserIdResult.hpp"
#include "result/GetTriggerResult.hpp"
#include "result/GetTriggerByUserIdResult.hpp"
#include "result/TriggerByUserIdResult.hpp"
#include "result/DeleteTriggerResult.hpp"
#include "result/DeleteTriggerByUserIdResult.hpp"
#include "result/DescribeEventsResult.hpp"
#include "result/DescribeEventsByUserIdResult.hpp"
#include "result/DescribeRawEventsResult.hpp"
#include "result/GetEventResult.hpp"
#include "result/GetEventByUserIdResult.hpp"
#include "result/GetRawEventResult.hpp"
#include "result/ExportMasterResult.hpp"
#include "result/GetCurrentEventMasterResult.hpp"
#include "result/UpdateCurrentEventMasterResult.hpp"
#include "result/UpdateCurrentEventMasterFromGitHubResult.hpp"
#include <cstring>

namespace gs2 { namespace schedule {

typedef AsyncResult<DescribeNamespacesResult> AsyncDescribeNamespacesResult;
typedef AsyncResult<CreateNamespaceResult> AsyncCreateNamespaceResult;
typedef AsyncResult<GetNamespaceStatusResult> AsyncGetNamespaceStatusResult;
typedef AsyncResult<GetNamespaceResult> AsyncGetNamespaceResult;
typedef AsyncResult<UpdateNamespaceResult> AsyncUpdateNamespaceResult;
typedef AsyncResult<DeleteNamespaceResult> AsyncDeleteNamespaceResult;
typedef AsyncResult<DescribeEventMastersResult> AsyncDescribeEventMastersResult;
typedef AsyncResult<CreateEventMasterResult> AsyncCreateEventMasterResult;
typedef AsyncResult<GetEventMasterResult> AsyncGetEventMasterResult;
typedef AsyncResult<UpdateEventMasterResult> AsyncUpdateEventMasterResult;
typedef AsyncResult<DeleteEventMasterResult> AsyncDeleteEventMasterResult;
typedef AsyncResult<DescribeTriggersResult> AsyncDescribeTriggersResult;
typedef AsyncResult<DescribeTriggersByUserIdResult> AsyncDescribeTriggersByUserIdResult;
typedef AsyncResult<GetTriggerResult> AsyncGetTriggerResult;
typedef AsyncResult<GetTriggerByUserIdResult> AsyncGetTriggerByUserIdResult;
typedef AsyncResult<TriggerByUserIdResult> AsyncTriggerByUserIdResult;
typedef AsyncResult<DeleteTriggerResult> AsyncDeleteTriggerResult;
typedef AsyncResult<DeleteTriggerByUserIdResult> AsyncDeleteTriggerByUserIdResult;
typedef AsyncResult<DescribeEventsResult> AsyncDescribeEventsResult;
typedef AsyncResult<DescribeEventsByUserIdResult> AsyncDescribeEventsByUserIdResult;
typedef AsyncResult<DescribeRawEventsResult> AsyncDescribeRawEventsResult;
typedef AsyncResult<GetEventResult> AsyncGetEventResult;
typedef AsyncResult<GetEventByUserIdResult> AsyncGetEventByUserIdResult;
typedef AsyncResult<GetRawEventResult> AsyncGetRawEventResult;
typedef AsyncResult<ExportMasterResult> AsyncExportMasterResult;
typedef AsyncResult<GetCurrentEventMasterResult> AsyncGetCurrentEventMasterResult;
typedef AsyncResult<UpdateCurrentEventMasterResult> AsyncUpdateCurrentEventMasterResult;
typedef AsyncResult<UpdateCurrentEventMasterFromGitHubResult> AsyncUpdateCurrentEventMasterFromGitHubResult;

/**
 * GS2 Schedule API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2ScheduleWebSocketClient : public AbstractGs2ClientBase
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
            writer.writeCharArray("schedule");
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
            writer.writeCharArray("schedule");
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
            writer.writeCharArray("schedule");
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
            writer.writeCharArray("schedule");
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
            writer.writeCharArray("schedule");
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
            writer.writeCharArray("schedule");
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

    class DescribeEventMastersTask : public detail::Gs2WebSocketSessionTask<DescribeEventMastersResult>
    {
    private:
        DescribeEventMastersRequest& m_Request;

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
            writer.writeCharArray("schedule");
            writer.writePropertyName("component");
            writer.writeCharArray("eventMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("describeEventMasters");
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
        DescribeEventMastersTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeEventMastersRequest& request,
            Gs2WebSocketSessionTask<DescribeEventMastersResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeEventMastersResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeEventMastersTask() GS2_OVERRIDE = default;
    };

    class CreateEventMasterTask : public detail::Gs2WebSocketSessionTask<CreateEventMasterResult>
    {
    private:
        CreateEventMasterRequest& m_Request;

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
            if (m_Request.getScheduleType())
            {
                writer.writePropertyName("scheduleType");
                writer.writeCharArray(*m_Request.getScheduleType());
            }
            if (m_Request.getAbsoluteBegin())
            {
                writer.writePropertyName("absoluteBegin");
                writer.writeInt64(*m_Request.getAbsoluteBegin());
            }
            if (m_Request.getAbsoluteEnd())
            {
                writer.writePropertyName("absoluteEnd");
                writer.writeInt64(*m_Request.getAbsoluteEnd());
            }
            if (m_Request.getRelativeTriggerName())
            {
                writer.writePropertyName("relativeTriggerName");
                writer.writeCharArray(*m_Request.getRelativeTriggerName());
            }
            if (m_Request.getRelativeDuration())
            {
                writer.writePropertyName("relativeDuration");
                writer.writeInt32(*m_Request.getRelativeDuration());
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
            writer.writeCharArray("schedule");
            writer.writePropertyName("component");
            writer.writeCharArray("eventMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("createEventMaster");
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
        CreateEventMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            CreateEventMasterRequest& request,
            Gs2WebSocketSessionTask<CreateEventMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateEventMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~CreateEventMasterTask() GS2_OVERRIDE = default;
    };

    class GetEventMasterTask : public detail::Gs2WebSocketSessionTask<GetEventMasterResult>
    {
    private:
        GetEventMasterRequest& m_Request;

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
            if (m_Request.getEventName())
            {
                writer.writePropertyName("eventName");
                writer.writeCharArray(*m_Request.getEventName());
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
            writer.writeCharArray("schedule");
            writer.writePropertyName("component");
            writer.writeCharArray("eventMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("getEventMaster");
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
        GetEventMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetEventMasterRequest& request,
            Gs2WebSocketSessionTask<GetEventMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetEventMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetEventMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateEventMasterTask : public detail::Gs2WebSocketSessionTask<UpdateEventMasterResult>
    {
    private:
        UpdateEventMasterRequest& m_Request;

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
            if (m_Request.getEventName())
            {
                writer.writePropertyName("eventName");
                writer.writeCharArray(*m_Request.getEventName());
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
            if (m_Request.getScheduleType())
            {
                writer.writePropertyName("scheduleType");
                writer.writeCharArray(*m_Request.getScheduleType());
            }
            if (m_Request.getAbsoluteBegin())
            {
                writer.writePropertyName("absoluteBegin");
                writer.writeInt64(*m_Request.getAbsoluteBegin());
            }
            if (m_Request.getAbsoluteEnd())
            {
                writer.writePropertyName("absoluteEnd");
                writer.writeInt64(*m_Request.getAbsoluteEnd());
            }
            if (m_Request.getRelativeTriggerName())
            {
                writer.writePropertyName("relativeTriggerName");
                writer.writeCharArray(*m_Request.getRelativeTriggerName());
            }
            if (m_Request.getRelativeDuration())
            {
                writer.writePropertyName("relativeDuration");
                writer.writeInt32(*m_Request.getRelativeDuration());
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
            writer.writeCharArray("schedule");
            writer.writePropertyName("component");
            writer.writeCharArray("eventMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("updateEventMaster");
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
        UpdateEventMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateEventMasterRequest& request,
            Gs2WebSocketSessionTask<UpdateEventMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateEventMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateEventMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteEventMasterTask : public detail::Gs2WebSocketSessionTask<DeleteEventMasterResult>
    {
    private:
        DeleteEventMasterRequest& m_Request;

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
            if (m_Request.getEventName())
            {
                writer.writePropertyName("eventName");
                writer.writeCharArray(*m_Request.getEventName());
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
            writer.writeCharArray("schedule");
            writer.writePropertyName("component");
            writer.writeCharArray("eventMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteEventMaster");
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
        DeleteEventMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteEventMasterRequest& request,
            Gs2WebSocketSessionTask<DeleteEventMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteEventMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteEventMasterTask() GS2_OVERRIDE = default;
    };

    class DescribeTriggersTask : public detail::Gs2WebSocketSessionTask<DescribeTriggersResult>
    {
    private:
        DescribeTriggersRequest& m_Request;

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
            writer.writeCharArray("schedule");
            writer.writePropertyName("component");
            writer.writeCharArray("trigger");
            writer.writePropertyName("function");
            writer.writeCharArray("describeTriggers");
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
        DescribeTriggersTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeTriggersRequest& request,
            Gs2WebSocketSessionTask<DescribeTriggersResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeTriggersResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeTriggersTask() GS2_OVERRIDE = default;
    };

    class DescribeTriggersByUserIdTask : public detail::Gs2WebSocketSessionTask<DescribeTriggersByUserIdResult>
    {
    private:
        DescribeTriggersByUserIdRequest& m_Request;

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
            writer.writeCharArray("schedule");
            writer.writePropertyName("component");
            writer.writeCharArray("trigger");
            writer.writePropertyName("function");
            writer.writeCharArray("describeTriggersByUserId");
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
        DescribeTriggersByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeTriggersByUserIdRequest& request,
            Gs2WebSocketSessionTask<DescribeTriggersByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeTriggersByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeTriggersByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetTriggerTask : public detail::Gs2WebSocketSessionTask<GetTriggerResult>
    {
    private:
        GetTriggerRequest& m_Request;

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
            if (m_Request.getTriggerName())
            {
                writer.writePropertyName("triggerName");
                writer.writeCharArray(*m_Request.getTriggerName());
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
            writer.writeCharArray("schedule");
            writer.writePropertyName("component");
            writer.writeCharArray("trigger");
            writer.writePropertyName("function");
            writer.writeCharArray("getTrigger");
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
        GetTriggerTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetTriggerRequest& request,
            Gs2WebSocketSessionTask<GetTriggerResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetTriggerResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetTriggerTask() GS2_OVERRIDE = default;
    };

    class GetTriggerByUserIdTask : public detail::Gs2WebSocketSessionTask<GetTriggerByUserIdResult>
    {
    private:
        GetTriggerByUserIdRequest& m_Request;

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
            if (m_Request.getTriggerName())
            {
                writer.writePropertyName("triggerName");
                writer.writeCharArray(*m_Request.getTriggerName());
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
            writer.writeCharArray("schedule");
            writer.writePropertyName("component");
            writer.writeCharArray("trigger");
            writer.writePropertyName("function");
            writer.writeCharArray("getTriggerByUserId");
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
        GetTriggerByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetTriggerByUserIdRequest& request,
            Gs2WebSocketSessionTask<GetTriggerByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetTriggerByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetTriggerByUserIdTask() GS2_OVERRIDE = default;
    };

    class TriggerByUserIdTask : public detail::Gs2WebSocketSessionTask<TriggerByUserIdResult>
    {
    private:
        TriggerByUserIdRequest& m_Request;

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
            if (m_Request.getTriggerName())
            {
                writer.writePropertyName("triggerName");
                writer.writeCharArray(*m_Request.getTriggerName());
            }
            if (m_Request.getUserId())
            {
                writer.writePropertyName("userId");
                writer.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getTriggerStrategy())
            {
                writer.writePropertyName("triggerStrategy");
                writer.writeCharArray(*m_Request.getTriggerStrategy());
            }
            if (m_Request.getTtl())
            {
                writer.writePropertyName("ttl");
                writer.writeInt32(*m_Request.getTtl());
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
            writer.writeCharArray("schedule");
            writer.writePropertyName("component");
            writer.writeCharArray("trigger");
            writer.writePropertyName("function");
            writer.writeCharArray("triggerByUserId");
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
        TriggerByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            TriggerByUserIdRequest& request,
            Gs2WebSocketSessionTask<TriggerByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<TriggerByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~TriggerByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteTriggerTask : public detail::Gs2WebSocketSessionTask<DeleteTriggerResult>
    {
    private:
        DeleteTriggerRequest& m_Request;

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
            if (m_Request.getTriggerName())
            {
                writer.writePropertyName("triggerName");
                writer.writeCharArray(*m_Request.getTriggerName());
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
            writer.writeCharArray("schedule");
            writer.writePropertyName("component");
            writer.writeCharArray("trigger");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteTrigger");
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
        DeleteTriggerTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteTriggerRequest& request,
            Gs2WebSocketSessionTask<DeleteTriggerResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteTriggerResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteTriggerTask() GS2_OVERRIDE = default;
    };

    class DeleteTriggerByUserIdTask : public detail::Gs2WebSocketSessionTask<DeleteTriggerByUserIdResult>
    {
    private:
        DeleteTriggerByUserIdRequest& m_Request;

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
            if (m_Request.getTriggerName())
            {
                writer.writePropertyName("triggerName");
                writer.writeCharArray(*m_Request.getTriggerName());
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
            writer.writeCharArray("schedule");
            writer.writePropertyName("component");
            writer.writeCharArray("trigger");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteTriggerByUserId");
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
        DeleteTriggerByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteTriggerByUserIdRequest& request,
            Gs2WebSocketSessionTask<DeleteTriggerByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteTriggerByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteTriggerByUserIdTask() GS2_OVERRIDE = default;
    };

    class DescribeEventsTask : public detail::Gs2WebSocketSessionTask<DescribeEventsResult>
    {
    private:
        DescribeEventsRequest& m_Request;

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
            writer.writeCharArray("schedule");
            writer.writePropertyName("component");
            writer.writeCharArray("event");
            writer.writePropertyName("function");
            writer.writeCharArray("describeEvents");
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
        DescribeEventsTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeEventsRequest& request,
            Gs2WebSocketSessionTask<DescribeEventsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeEventsResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeEventsTask() GS2_OVERRIDE = default;
    };

    class DescribeEventsByUserIdTask : public detail::Gs2WebSocketSessionTask<DescribeEventsByUserIdResult>
    {
    private:
        DescribeEventsByUserIdRequest& m_Request;

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
            writer.writeCharArray("schedule");
            writer.writePropertyName("component");
            writer.writeCharArray("event");
            writer.writePropertyName("function");
            writer.writeCharArray("describeEventsByUserId");
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
        DescribeEventsByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeEventsByUserIdRequest& request,
            Gs2WebSocketSessionTask<DescribeEventsByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeEventsByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeEventsByUserIdTask() GS2_OVERRIDE = default;
    };

    class DescribeRawEventsTask : public detail::Gs2WebSocketSessionTask<DescribeRawEventsResult>
    {
    private:
        DescribeRawEventsRequest& m_Request;

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
            writer.writeCharArray("schedule");
            writer.writePropertyName("component");
            writer.writeCharArray("event");
            writer.writePropertyName("function");
            writer.writeCharArray("describeRawEvents");
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
        DescribeRawEventsTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeRawEventsRequest& request,
            Gs2WebSocketSessionTask<DescribeRawEventsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeRawEventsResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeRawEventsTask() GS2_OVERRIDE = default;
    };

    class GetEventTask : public detail::Gs2WebSocketSessionTask<GetEventResult>
    {
    private:
        GetEventRequest& m_Request;

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
            if (m_Request.getEventName())
            {
                writer.writePropertyName("eventName");
                writer.writeCharArray(*m_Request.getEventName());
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
            writer.writeCharArray("schedule");
            writer.writePropertyName("component");
            writer.writeCharArray("event");
            writer.writePropertyName("function");
            writer.writeCharArray("getEvent");
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
        GetEventTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetEventRequest& request,
            Gs2WebSocketSessionTask<GetEventResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetEventResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetEventTask() GS2_OVERRIDE = default;
    };

    class GetEventByUserIdTask : public detail::Gs2WebSocketSessionTask<GetEventByUserIdResult>
    {
    private:
        GetEventByUserIdRequest& m_Request;

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
            if (m_Request.getEventName())
            {
                writer.writePropertyName("eventName");
                writer.writeCharArray(*m_Request.getEventName());
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
            writer.writeCharArray("schedule");
            writer.writePropertyName("component");
            writer.writeCharArray("event");
            writer.writePropertyName("function");
            writer.writeCharArray("getEventByUserId");
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
        GetEventByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetEventByUserIdRequest& request,
            Gs2WebSocketSessionTask<GetEventByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetEventByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetEventByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetRawEventTask : public detail::Gs2WebSocketSessionTask<GetRawEventResult>
    {
    private:
        GetRawEventRequest& m_Request;

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
            if (m_Request.getEventName())
            {
                writer.writePropertyName("eventName");
                writer.writeCharArray(*m_Request.getEventName());
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
            writer.writeCharArray("schedule");
            writer.writePropertyName("component");
            writer.writeCharArray("event");
            writer.writePropertyName("function");
            writer.writeCharArray("getRawEvent");
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
        GetRawEventTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetRawEventRequest& request,
            Gs2WebSocketSessionTask<GetRawEventResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetRawEventResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetRawEventTask() GS2_OVERRIDE = default;
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
            writer.writeCharArray("schedule");
            writer.writePropertyName("component");
            writer.writeCharArray("currentEventMaster");
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

    class GetCurrentEventMasterTask : public detail::Gs2WebSocketSessionTask<GetCurrentEventMasterResult>
    {
    private:
        GetCurrentEventMasterRequest& m_Request;

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
            writer.writeCharArray("schedule");
            writer.writePropertyName("component");
            writer.writeCharArray("currentEventMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("getCurrentEventMaster");
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
        GetCurrentEventMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetCurrentEventMasterRequest& request,
            Gs2WebSocketSessionTask<GetCurrentEventMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetCurrentEventMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetCurrentEventMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentEventMasterTask : public detail::Gs2WebSocketSessionTask<UpdateCurrentEventMasterResult>
    {
    private:
        UpdateCurrentEventMasterRequest& m_Request;

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
            writer.writeCharArray("schedule");
            writer.writePropertyName("component");
            writer.writeCharArray("currentEventMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("updateCurrentEventMaster");
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
        UpdateCurrentEventMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateCurrentEventMasterRequest& request,
            Gs2WebSocketSessionTask<UpdateCurrentEventMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateCurrentEventMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateCurrentEventMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentEventMasterFromGitHubTask : public detail::Gs2WebSocketSessionTask<UpdateCurrentEventMasterFromGitHubResult>
    {
    private:
        UpdateCurrentEventMasterFromGitHubRequest& m_Request;

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
            writer.writeCharArray("schedule");
            writer.writePropertyName("component");
            writer.writeCharArray("currentEventMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("updateCurrentEventMasterFromGitHub");
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
        UpdateCurrentEventMasterFromGitHubTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateCurrentEventMasterFromGitHubRequest& request,
            Gs2WebSocketSessionTask<UpdateCurrentEventMasterFromGitHubResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateCurrentEventMasterFromGitHubResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateCurrentEventMasterFromGitHubTask() GS2_OVERRIDE = default;
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

    static void write(detail::json::JsonWriter& writer, const EventMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getEventId())
        {
            writer.writePropertyName("eventId");
            writer.writeCharArray(*obj.getEventId());
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
        if (obj.getScheduleType())
        {
            writer.writePropertyName("scheduleType");
            writer.writeCharArray(*obj.getScheduleType());
        }
        if (obj.getAbsoluteBegin())
        {
            writer.writePropertyName("absoluteBegin");
            writer.writeInt64(*obj.getAbsoluteBegin());
        }
        if (obj.getAbsoluteEnd())
        {
            writer.writePropertyName("absoluteEnd");
            writer.writeInt64(*obj.getAbsoluteEnd());
        }
        if (obj.getRelativeTriggerName())
        {
            writer.writePropertyName("relativeTriggerName");
            writer.writeCharArray(*obj.getRelativeTriggerName());
        }
        if (obj.getRelativeDuration())
        {
            writer.writePropertyName("relativeDuration");
            writer.writeInt32(*obj.getRelativeDuration());
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

    static void write(detail::json::JsonWriter& writer, const Trigger& obj)
    {
        writer.writeObjectStart();
        if (obj.getTriggerId())
        {
            writer.writePropertyName("triggerId");
            writer.writeCharArray(*obj.getTriggerId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*obj.getName());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.writeCharArray(*obj.getUserId());
        }
        if (obj.getCreatedAt())
        {
            writer.writePropertyName("createdAt");
            writer.writeInt64(*obj.getCreatedAt());
        }
        if (obj.getExpiresAt())
        {
            writer.writePropertyName("expiresAt");
            writer.writeInt64(*obj.getExpiresAt());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const Event& obj)
    {
        writer.writeObjectStart();
        if (obj.getEventId())
        {
            writer.writePropertyName("eventId");
            writer.writeCharArray(*obj.getEventId());
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
        if (obj.getScheduleType())
        {
            writer.writePropertyName("scheduleType");
            writer.writeCharArray(*obj.getScheduleType());
        }
        if (obj.getAbsoluteBegin())
        {
            writer.writePropertyName("absoluteBegin");
            writer.writeInt64(*obj.getAbsoluteBegin());
        }
        if (obj.getAbsoluteEnd())
        {
            writer.writePropertyName("absoluteEnd");
            writer.writeInt64(*obj.getAbsoluteEnd());
        }
        if (obj.getRelativeTriggerName())
        {
            writer.writePropertyName("relativeTriggerName");
            writer.writeCharArray(*obj.getRelativeTriggerName());
        }
        if (obj.getRelativeDuration())
        {
            writer.writePropertyName("relativeDuration");
            writer.writeInt32(*obj.getRelativeDuration());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const CurrentEventMaster& obj)
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
    explicit Gs2ScheduleWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
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
	 * イベントマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeEventMasters(std::function<void(AsyncDescribeEventMastersResult&)> callback, DescribeEventMastersRequest& request)
    {
        DescribeEventMastersTask& task = *new DescribeEventMastersTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * イベントマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createEventMaster(std::function<void(AsyncCreateEventMasterResult&)> callback, CreateEventMasterRequest& request)
    {
        CreateEventMasterTask& task = *new CreateEventMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * イベントマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getEventMaster(std::function<void(AsyncGetEventMasterResult&)> callback, GetEventMasterRequest& request)
    {
        GetEventMasterTask& task = *new GetEventMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * イベントマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateEventMaster(std::function<void(AsyncUpdateEventMasterResult&)> callback, UpdateEventMasterRequest& request)
    {
        UpdateEventMasterTask& task = *new UpdateEventMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * イベントマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteEventMaster(std::function<void(AsyncDeleteEventMasterResult&)> callback, DeleteEventMasterRequest& request)
    {
        DeleteEventMasterTask& task = *new DeleteEventMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * トリガーの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeTriggers(std::function<void(AsyncDescribeTriggersResult&)> callback, DescribeTriggersRequest& request)
    {
        DescribeTriggersTask& task = *new DescribeTriggersTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザIDを指定してトリガーの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeTriggersByUserId(std::function<void(AsyncDescribeTriggersByUserIdResult&)> callback, DescribeTriggersByUserIdRequest& request)
    {
        DescribeTriggersByUserIdTask& task = *new DescribeTriggersByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * トリガーを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getTrigger(std::function<void(AsyncGetTriggerResult&)> callback, GetTriggerRequest& request)
    {
        GetTriggerTask& task = *new GetTriggerTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザIDを指定してトリガーを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getTriggerByUserId(std::function<void(AsyncGetTriggerByUserIdResult&)> callback, GetTriggerByUserIdRequest& request)
    {
        GetTriggerByUserIdTask& task = *new GetTriggerByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザIDを指定してトリガーを登録<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void triggerByUserId(std::function<void(AsyncTriggerByUserIdResult&)> callback, TriggerByUserIdRequest& request)
    {
        TriggerByUserIdTask& task = *new TriggerByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * トリガーを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteTrigger(std::function<void(AsyncDeleteTriggerResult&)> callback, DeleteTriggerRequest& request)
    {
        DeleteTriggerTask& task = *new DeleteTriggerTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザIDを指定してトリガーを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteTriggerByUserId(std::function<void(AsyncDeleteTriggerByUserIdResult&)> callback, DeleteTriggerByUserIdRequest& request)
    {
        DeleteTriggerByUserIdTask& task = *new DeleteTriggerByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * イベントの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeEvents(std::function<void(AsyncDescribeEventsResult&)> callback, DescribeEventsRequest& request)
    {
        DescribeEventsTask& task = *new DescribeEventsTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザIDを指定してイベントの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeEventsByUserId(std::function<void(AsyncDescribeEventsByUserIdResult&)> callback, DescribeEventsByUserIdRequest& request)
    {
        DescribeEventsByUserIdTask& task = *new DescribeEventsByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * イベントの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeRawEvents(std::function<void(AsyncDescribeRawEventsResult&)> callback, DescribeRawEventsRequest& request)
    {
        DescribeRawEventsTask& task = *new DescribeRawEventsTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * イベントを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getEvent(std::function<void(AsyncGetEventResult&)> callback, GetEventRequest& request)
    {
        GetEventTask& task = *new GetEventTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザIDを指定してイベントを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getEventByUserId(std::function<void(AsyncGetEventByUserIdResult&)> callback, GetEventByUserIdRequest& request)
    {
        GetEventByUserIdTask& task = *new GetEventByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * イベントを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getRawEvent(std::function<void(AsyncGetRawEventResult&)> callback, GetRawEventRequest& request)
    {
        GetRawEventTask& task = *new GetRawEventTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 現在有効なイベントスケジュールマスターのマスターデータをエクスポートします<br>
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
	 * 現在有効な現在有効なイベントスケジュールマスターを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentEventMaster(std::function<void(AsyncGetCurrentEventMasterResult&)> callback, GetCurrentEventMasterRequest& request)
    {
        GetCurrentEventMasterTask& task = *new GetCurrentEventMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 現在有効な現在有効なイベントスケジュールマスターを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentEventMaster(std::function<void(AsyncUpdateCurrentEventMasterResult&)> callback, UpdateCurrentEventMasterRequest& request)
    {
        UpdateCurrentEventMasterTask& task = *new UpdateCurrentEventMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 現在有効な現在有効なイベントスケジュールマスターを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentEventMasterFromGitHub(std::function<void(AsyncUpdateCurrentEventMasterFromGitHubResult&)> callback, UpdateCurrentEventMasterFromGitHubRequest& request)
    {
        UpdateCurrentEventMasterFromGitHubTask& task = *new UpdateCurrentEventMasterFromGitHubTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_SCHEDULE_GS2SCHEDULEWEBSOCKETCLIENT_HPP_