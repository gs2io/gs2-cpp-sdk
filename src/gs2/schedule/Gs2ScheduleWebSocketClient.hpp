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

/**
 * GS2 Schedule API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2ScheduleWebSocketClient : public AbstractGs2ClientBase
{
private:

    class CreateNamespaceTask : public detail::Gs2WebSocketSessionTask<CreateNamespaceResult>
    {
    private:
        CreateNamespaceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "schedule";
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
            return "schedule";
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
            return "schedule";
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
            return "schedule";
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
            return "schedule";
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

    class CreateEventMasterTask : public detail::Gs2WebSocketSessionTask<CreateEventMasterResult>
    {
    private:
        CreateEventMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "schedule";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "eventMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "createEventMaster";
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
            if (m_Request.getScheduleType())
            {
                jsonWriter.writePropertyName("scheduleType");
                jsonWriter.writeCharArray(*m_Request.getScheduleType());
            }
            if (m_Request.getAbsoluteBegin())
            {
                jsonWriter.writePropertyName("absoluteBegin");
                jsonWriter.writeInt64(*m_Request.getAbsoluteBegin());
            }
            if (m_Request.getAbsoluteEnd())
            {
                jsonWriter.writePropertyName("absoluteEnd");
                jsonWriter.writeInt64(*m_Request.getAbsoluteEnd());
            }
            if (m_Request.getRepeatType())
            {
                jsonWriter.writePropertyName("repeatType");
                jsonWriter.writeCharArray(*m_Request.getRepeatType());
            }
            if (m_Request.getRepeatBeginDayOfMonth())
            {
                jsonWriter.writePropertyName("repeatBeginDayOfMonth");
                jsonWriter.writeInt32(*m_Request.getRepeatBeginDayOfMonth());
            }
            if (m_Request.getRepeatEndDayOfMonth())
            {
                jsonWriter.writePropertyName("repeatEndDayOfMonth");
                jsonWriter.writeInt32(*m_Request.getRepeatEndDayOfMonth());
            }
            if (m_Request.getRepeatBeginDayOfWeek())
            {
                jsonWriter.writePropertyName("repeatBeginDayOfWeek");
                jsonWriter.writeCharArray(*m_Request.getRepeatBeginDayOfWeek());
            }
            if (m_Request.getRepeatEndDayOfWeek())
            {
                jsonWriter.writePropertyName("repeatEndDayOfWeek");
                jsonWriter.writeCharArray(*m_Request.getRepeatEndDayOfWeek());
            }
            if (m_Request.getRepeatBeginHour())
            {
                jsonWriter.writePropertyName("repeatBeginHour");
                jsonWriter.writeInt32(*m_Request.getRepeatBeginHour());
            }
            if (m_Request.getRepeatEndHour())
            {
                jsonWriter.writePropertyName("repeatEndHour");
                jsonWriter.writeInt32(*m_Request.getRepeatEndHour());
            }
            if (m_Request.getRelativeTriggerName())
            {
                jsonWriter.writePropertyName("relativeTriggerName");
                jsonWriter.writeCharArray(*m_Request.getRelativeTriggerName());
            }
            if (m_Request.getRelativeDuration())
            {
                jsonWriter.writePropertyName("relativeDuration");
                jsonWriter.writeInt32(*m_Request.getRelativeDuration());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        CreateEventMasterTask(
            CreateEventMasterRequest request,
            Gs2WebSocketSessionTask<CreateEventMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateEventMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateEventMasterTask() GS2_OVERRIDE = default;
    };

    class GetEventMasterTask : public detail::Gs2WebSocketSessionTask<GetEventMasterResult>
    {
    private:
        GetEventMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "schedule";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "eventMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getEventMaster";
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
            if (m_Request.getEventName())
            {
                jsonWriter.writePropertyName("eventName");
                jsonWriter.writeCharArray(*m_Request.getEventName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetEventMasterTask(
            GetEventMasterRequest request,
            Gs2WebSocketSessionTask<GetEventMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetEventMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetEventMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateEventMasterTask : public detail::Gs2WebSocketSessionTask<UpdateEventMasterResult>
    {
    private:
        UpdateEventMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "schedule";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "eventMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateEventMaster";
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
            if (m_Request.getEventName())
            {
                jsonWriter.writePropertyName("eventName");
                jsonWriter.writeCharArray(*m_Request.getEventName());
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
            if (m_Request.getScheduleType())
            {
                jsonWriter.writePropertyName("scheduleType");
                jsonWriter.writeCharArray(*m_Request.getScheduleType());
            }
            if (m_Request.getAbsoluteBegin())
            {
                jsonWriter.writePropertyName("absoluteBegin");
                jsonWriter.writeInt64(*m_Request.getAbsoluteBegin());
            }
            if (m_Request.getAbsoluteEnd())
            {
                jsonWriter.writePropertyName("absoluteEnd");
                jsonWriter.writeInt64(*m_Request.getAbsoluteEnd());
            }
            if (m_Request.getRepeatType())
            {
                jsonWriter.writePropertyName("repeatType");
                jsonWriter.writeCharArray(*m_Request.getRepeatType());
            }
            if (m_Request.getRepeatBeginDayOfMonth())
            {
                jsonWriter.writePropertyName("repeatBeginDayOfMonth");
                jsonWriter.writeInt32(*m_Request.getRepeatBeginDayOfMonth());
            }
            if (m_Request.getRepeatEndDayOfMonth())
            {
                jsonWriter.writePropertyName("repeatEndDayOfMonth");
                jsonWriter.writeInt32(*m_Request.getRepeatEndDayOfMonth());
            }
            if (m_Request.getRepeatBeginDayOfWeek())
            {
                jsonWriter.writePropertyName("repeatBeginDayOfWeek");
                jsonWriter.writeCharArray(*m_Request.getRepeatBeginDayOfWeek());
            }
            if (m_Request.getRepeatEndDayOfWeek())
            {
                jsonWriter.writePropertyName("repeatEndDayOfWeek");
                jsonWriter.writeCharArray(*m_Request.getRepeatEndDayOfWeek());
            }
            if (m_Request.getRepeatBeginHour())
            {
                jsonWriter.writePropertyName("repeatBeginHour");
                jsonWriter.writeInt32(*m_Request.getRepeatBeginHour());
            }
            if (m_Request.getRepeatEndHour())
            {
                jsonWriter.writePropertyName("repeatEndHour");
                jsonWriter.writeInt32(*m_Request.getRepeatEndHour());
            }
            if (m_Request.getRelativeTriggerName())
            {
                jsonWriter.writePropertyName("relativeTriggerName");
                jsonWriter.writeCharArray(*m_Request.getRelativeTriggerName());
            }
            if (m_Request.getRelativeDuration())
            {
                jsonWriter.writePropertyName("relativeDuration");
                jsonWriter.writeInt32(*m_Request.getRelativeDuration());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        UpdateEventMasterTask(
            UpdateEventMasterRequest request,
            Gs2WebSocketSessionTask<UpdateEventMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateEventMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateEventMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteEventMasterTask : public detail::Gs2WebSocketSessionTask<DeleteEventMasterResult>
    {
    private:
        DeleteEventMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "schedule";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "eventMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteEventMaster";
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
            if (m_Request.getEventName())
            {
                jsonWriter.writePropertyName("eventName");
                jsonWriter.writeCharArray(*m_Request.getEventName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        DeleteEventMasterTask(
            DeleteEventMasterRequest request,
            Gs2WebSocketSessionTask<DeleteEventMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteEventMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteEventMasterTask() GS2_OVERRIDE = default;
    };

    class GetTriggerTask : public detail::Gs2WebSocketSessionTask<GetTriggerResult>
    {
    private:
        GetTriggerRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "schedule";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "trigger";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getTrigger";
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
            if (m_Request.getTriggerName())
            {
                jsonWriter.writePropertyName("triggerName");
                jsonWriter.writeCharArray(*m_Request.getTriggerName());
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
        GetTriggerTask(
            GetTriggerRequest request,
            Gs2WebSocketSessionTask<GetTriggerResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetTriggerResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetTriggerTask() GS2_OVERRIDE = default;
    };

    class GetTriggerByUserIdTask : public detail::Gs2WebSocketSessionTask<GetTriggerByUserIdResult>
    {
    private:
        GetTriggerByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "schedule";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "trigger";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getTriggerByUserId";
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
            if (m_Request.getTriggerName())
            {
                jsonWriter.writePropertyName("triggerName");
                jsonWriter.writeCharArray(*m_Request.getTriggerName());
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
        GetTriggerByUserIdTask(
            GetTriggerByUserIdRequest request,
            Gs2WebSocketSessionTask<GetTriggerByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetTriggerByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetTriggerByUserIdTask() GS2_OVERRIDE = default;
    };

    class TriggerByUserIdTask : public detail::Gs2WebSocketSessionTask<TriggerByUserIdResult>
    {
    private:
        TriggerByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "schedule";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "trigger";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "triggerByUserId";
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
            if (m_Request.getTriggerName())
            {
                jsonWriter.writePropertyName("triggerName");
                jsonWriter.writeCharArray(*m_Request.getTriggerName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getTriggerStrategy())
            {
                jsonWriter.writePropertyName("triggerStrategy");
                jsonWriter.writeCharArray(*m_Request.getTriggerStrategy());
            }
            if (m_Request.getTtl())
            {
                jsonWriter.writePropertyName("ttl");
                jsonWriter.writeInt32(*m_Request.getTtl());
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
        TriggerByUserIdTask(
            TriggerByUserIdRequest request,
            Gs2WebSocketSessionTask<TriggerByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<TriggerByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~TriggerByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteTriggerTask : public detail::Gs2WebSocketSessionTask<DeleteTriggerResult>
    {
    private:
        DeleteTriggerRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "schedule";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "trigger";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteTrigger";
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
            if (m_Request.getTriggerName())
            {
                jsonWriter.writePropertyName("triggerName");
                jsonWriter.writeCharArray(*m_Request.getTriggerName());
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
        DeleteTriggerTask(
            DeleteTriggerRequest request,
            Gs2WebSocketSessionTask<DeleteTriggerResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteTriggerResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteTriggerTask() GS2_OVERRIDE = default;
    };

    class DeleteTriggerByUserIdTask : public detail::Gs2WebSocketSessionTask<DeleteTriggerByUserIdResult>
    {
    private:
        DeleteTriggerByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "schedule";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "trigger";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteTriggerByUserId";
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
            if (m_Request.getTriggerName())
            {
                jsonWriter.writePropertyName("triggerName");
                jsonWriter.writeCharArray(*m_Request.getTriggerName());
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
        DeleteTriggerByUserIdTask(
            DeleteTriggerByUserIdRequest request,
            Gs2WebSocketSessionTask<DeleteTriggerByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteTriggerByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteTriggerByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetEventTask : public detail::Gs2WebSocketSessionTask<GetEventResult>
    {
    private:
        GetEventRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "schedule";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "event";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getEvent";
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
            if (m_Request.getEventName())
            {
                jsonWriter.writePropertyName("eventName");
                jsonWriter.writeCharArray(*m_Request.getEventName());
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
        GetEventTask(
            GetEventRequest request,
            Gs2WebSocketSessionTask<GetEventResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetEventResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetEventTask() GS2_OVERRIDE = default;
    };

    class GetEventByUserIdTask : public detail::Gs2WebSocketSessionTask<GetEventByUserIdResult>
    {
    private:
        GetEventByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "schedule";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "event";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getEventByUserId";
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
            if (m_Request.getEventName())
            {
                jsonWriter.writePropertyName("eventName");
                jsonWriter.writeCharArray(*m_Request.getEventName());
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
        GetEventByUserIdTask(
            GetEventByUserIdRequest request,
            Gs2WebSocketSessionTask<GetEventByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetEventByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetEventByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetRawEventTask : public detail::Gs2WebSocketSessionTask<GetRawEventResult>
    {
    private:
        GetRawEventRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "schedule";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "event";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getRawEvent";
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
            if (m_Request.getEventName())
            {
                jsonWriter.writePropertyName("eventName");
                jsonWriter.writeCharArray(*m_Request.getEventName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetRawEventTask(
            GetRawEventRequest request,
            Gs2WebSocketSessionTask<GetRawEventResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetRawEventResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetRawEventTask() GS2_OVERRIDE = default;
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

    static void write(detail::json::JsonWriter& jsonWriter, const EventMaster& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getEventId())
        {
            jsonWriter.writePropertyName("eventId");
            jsonWriter.writeCharArray(*obj.getEventId());
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
        if (obj.getScheduleType())
        {
            jsonWriter.writePropertyName("scheduleType");
            jsonWriter.writeCharArray(*obj.getScheduleType());
        }
        if (obj.getRepeatType())
        {
            jsonWriter.writePropertyName("repeatType");
            jsonWriter.writeCharArray(*obj.getRepeatType());
        }
        if (obj.getAbsoluteBegin())
        {
            jsonWriter.writePropertyName("absoluteBegin");
            jsonWriter.writeInt64(*obj.getAbsoluteBegin());
        }
        if (obj.getAbsoluteEnd())
        {
            jsonWriter.writePropertyName("absoluteEnd");
            jsonWriter.writeInt64(*obj.getAbsoluteEnd());
        }
        if (obj.getRepeatBeginDayOfMonth())
        {
            jsonWriter.writePropertyName("repeatBeginDayOfMonth");
            jsonWriter.writeInt32(*obj.getRepeatBeginDayOfMonth());
        }
        if (obj.getRepeatEndDayOfMonth())
        {
            jsonWriter.writePropertyName("repeatEndDayOfMonth");
            jsonWriter.writeInt32(*obj.getRepeatEndDayOfMonth());
        }
        if (obj.getRepeatBeginDayOfWeek())
        {
            jsonWriter.writePropertyName("repeatBeginDayOfWeek");
            jsonWriter.writeCharArray(*obj.getRepeatBeginDayOfWeek());
        }
        if (obj.getRepeatEndDayOfWeek())
        {
            jsonWriter.writePropertyName("repeatEndDayOfWeek");
            jsonWriter.writeCharArray(*obj.getRepeatEndDayOfWeek());
        }
        if (obj.getRepeatBeginHour())
        {
            jsonWriter.writePropertyName("repeatBeginHour");
            jsonWriter.writeInt32(*obj.getRepeatBeginHour());
        }
        if (obj.getRepeatEndHour())
        {
            jsonWriter.writePropertyName("repeatEndHour");
            jsonWriter.writeInt32(*obj.getRepeatEndHour());
        }
        if (obj.getRelativeTriggerName())
        {
            jsonWriter.writePropertyName("relativeTriggerName");
            jsonWriter.writeCharArray(*obj.getRelativeTriggerName());
        }
        if (obj.getRelativeDuration())
        {
            jsonWriter.writePropertyName("relativeDuration");
            jsonWriter.writeInt32(*obj.getRelativeDuration());
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

    static void write(detail::json::JsonWriter& jsonWriter, const Trigger& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getTriggerId())
        {
            jsonWriter.writePropertyName("triggerId");
            jsonWriter.writeCharArray(*obj.getTriggerId());
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
        if (obj.getCreatedAt())
        {
            jsonWriter.writePropertyName("createdAt");
            jsonWriter.writeInt64(*obj.getCreatedAt());
        }
        if (obj.getExpiresAt())
        {
            jsonWriter.writePropertyName("expiresAt");
            jsonWriter.writeInt64(*obj.getExpiresAt());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const Event& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getEventId())
        {
            jsonWriter.writePropertyName("eventId");
            jsonWriter.writeCharArray(*obj.getEventId());
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
        if (obj.getScheduleType())
        {
            jsonWriter.writePropertyName("scheduleType");
            jsonWriter.writeCharArray(*obj.getScheduleType());
        }
        if (obj.getRepeatType())
        {
            jsonWriter.writePropertyName("repeatType");
            jsonWriter.writeCharArray(*obj.getRepeatType());
        }
        if (obj.getAbsoluteBegin())
        {
            jsonWriter.writePropertyName("absoluteBegin");
            jsonWriter.writeInt64(*obj.getAbsoluteBegin());
        }
        if (obj.getAbsoluteEnd())
        {
            jsonWriter.writePropertyName("absoluteEnd");
            jsonWriter.writeInt64(*obj.getAbsoluteEnd());
        }
        if (obj.getRepeatBeginDayOfMonth())
        {
            jsonWriter.writePropertyName("repeatBeginDayOfMonth");
            jsonWriter.writeInt32(*obj.getRepeatBeginDayOfMonth());
        }
        if (obj.getRepeatEndDayOfMonth())
        {
            jsonWriter.writePropertyName("repeatEndDayOfMonth");
            jsonWriter.writeInt32(*obj.getRepeatEndDayOfMonth());
        }
        if (obj.getRepeatBeginDayOfWeek())
        {
            jsonWriter.writePropertyName("repeatBeginDayOfWeek");
            jsonWriter.writeCharArray(*obj.getRepeatBeginDayOfWeek());
        }
        if (obj.getRepeatEndDayOfWeek())
        {
            jsonWriter.writePropertyName("repeatEndDayOfWeek");
            jsonWriter.writeCharArray(*obj.getRepeatEndDayOfWeek());
        }
        if (obj.getRepeatBeginHour())
        {
            jsonWriter.writePropertyName("repeatBeginHour");
            jsonWriter.writeInt32(*obj.getRepeatBeginHour());
        }
        if (obj.getRepeatEndHour())
        {
            jsonWriter.writePropertyName("repeatEndHour");
            jsonWriter.writeInt32(*obj.getRepeatEndHour());
        }
        if (obj.getRelativeTriggerName())
        {
            jsonWriter.writePropertyName("relativeTriggerName");
            jsonWriter.writeCharArray(*obj.getRelativeTriggerName());
        }
        if (obj.getRelativeDuration())
        {
            jsonWriter.writePropertyName("relativeDuration");
            jsonWriter.writeInt32(*obj.getRelativeDuration());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const CurrentEventMaster& obj)
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
    explicit Gs2ScheduleWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
        AbstractGs2ClientBase(gs2WebSocketSession)
    {
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
	 * イベントマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createEventMaster(CreateEventMasterRequest request, std::function<void(AsyncCreateEventMasterResult)> callback)
    {
        CreateEventMasterTask& task = *new CreateEventMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * イベントマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getEventMaster(GetEventMasterRequest request, std::function<void(AsyncGetEventMasterResult)> callback)
    {
        GetEventMasterTask& task = *new GetEventMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * イベントマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateEventMaster(UpdateEventMasterRequest request, std::function<void(AsyncUpdateEventMasterResult)> callback)
    {
        UpdateEventMasterTask& task = *new UpdateEventMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * イベントマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteEventMaster(DeleteEventMasterRequest request, std::function<void(AsyncDeleteEventMasterResult)> callback)
    {
        DeleteEventMasterTask& task = *new DeleteEventMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * トリガーを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getTrigger(GetTriggerRequest request, std::function<void(AsyncGetTriggerResult)> callback)
    {
        GetTriggerTask& task = *new GetTriggerTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザIDを指定してトリガーを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getTriggerByUserId(GetTriggerByUserIdRequest request, std::function<void(AsyncGetTriggerByUserIdResult)> callback)
    {
        GetTriggerByUserIdTask& task = *new GetTriggerByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザIDを指定してトリガーを登録<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void triggerByUserId(TriggerByUserIdRequest request, std::function<void(AsyncTriggerByUserIdResult)> callback)
    {
        TriggerByUserIdTask& task = *new TriggerByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * トリガーを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteTrigger(DeleteTriggerRequest request, std::function<void(AsyncDeleteTriggerResult)> callback)
    {
        DeleteTriggerTask& task = *new DeleteTriggerTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザIDを指定してトリガーを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteTriggerByUserId(DeleteTriggerByUserIdRequest request, std::function<void(AsyncDeleteTriggerByUserIdResult)> callback)
    {
        DeleteTriggerByUserIdTask& task = *new DeleteTriggerByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * イベントを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getEvent(GetEventRequest request, std::function<void(AsyncGetEventResult)> callback)
    {
        GetEventTask& task = *new GetEventTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザIDを指定してイベントを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getEventByUserId(GetEventByUserIdRequest request, std::function<void(AsyncGetEventByUserIdResult)> callback)
    {
        GetEventByUserIdTask& task = *new GetEventByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * イベントを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getRawEvent(GetRawEventRequest request, std::function<void(AsyncGetRawEventResult)> callback)
    {
        GetRawEventTask& task = *new GetRawEventTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_SCHEDULE_GS2SCHEDULEWEBSOCKETCLIENT_HPP_