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

#ifndef GS2_MISSION_GS2MISSIONWEBSOCKETCLIENT_HPP_
#define GS2_MISSION_GS2MISSIONWEBSOCKETCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2WebSocketSessionTask.hpp>
#include <gs2/core/network/Gs2WebSocketSession.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include "model/model.hpp"
#include "request/DescribeCounterModelsRequest.hpp"
#include "request/GetCounterModelRequest.hpp"
#include "request/DescribeCompletesRequest.hpp"
#include "request/DescribeCompletesByUserIdRequest.hpp"
#include "request/CompleteRequest.hpp"
#include "request/CompleteByUserIdRequest.hpp"
#include "request/ReceiveByUserIdRequest.hpp"
#include "request/GetCompleteRequest.hpp"
#include "request/GetCompleteByUserIdRequest.hpp"
#include "request/DeleteCompleteByUserIdRequest.hpp"
#include "request/ReceiveByStampTaskRequest.hpp"
#include "request/DescribeMissionTaskModelsRequest.hpp"
#include "request/GetMissionTaskModelRequest.hpp"
#include "request/DescribeMissionTaskModelMastersRequest.hpp"
#include "request/CreateMissionTaskModelMasterRequest.hpp"
#include "request/GetMissionTaskModelMasterRequest.hpp"
#include "request/UpdateMissionTaskModelMasterRequest.hpp"
#include "request/DeleteMissionTaskModelMasterRequest.hpp"
#include "request/DescribeCountersRequest.hpp"
#include "request/DescribeCountersByUserIdRequest.hpp"
#include "request/IncreaseCounterByUserIdRequest.hpp"
#include "request/GetCounterRequest.hpp"
#include "request/GetCounterByUserIdRequest.hpp"
#include "request/DeleteCounterByUserIdRequest.hpp"
#include "request/IncreaseByStampSheetRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentMissionMasterRequest.hpp"
#include "request/UpdateCurrentMissionMasterRequest.hpp"
#include "request/UpdateCurrentMissionMasterFromGitHubRequest.hpp"
#include "request/DescribeCounterModelMastersRequest.hpp"
#include "request/CreateCounterModelMasterRequest.hpp"
#include "request/GetCounterModelMasterRequest.hpp"
#include "request/UpdateCounterModelMasterRequest.hpp"
#include "request/DeleteCounterModelMasterRequest.hpp"
#include "request/DescribeNamespacesRequest.hpp"
#include "request/CreateNamespaceRequest.hpp"
#include "request/GetNamespaceStatusRequest.hpp"
#include "request/GetNamespaceRequest.hpp"
#include "request/UpdateNamespaceRequest.hpp"
#include "request/DeleteNamespaceRequest.hpp"
#include "request/DescribeMissionGroupModelMastersRequest.hpp"
#include "request/CreateMissionGroupModelMasterRequest.hpp"
#include "request/GetMissionGroupModelMasterRequest.hpp"
#include "request/UpdateMissionGroupModelMasterRequest.hpp"
#include "request/DeleteMissionGroupModelMasterRequest.hpp"
#include "request/DescribeMissionGroupModelsRequest.hpp"
#include "request/GetMissionGroupModelRequest.hpp"
#include "result/DescribeCounterModelsResult.hpp"
#include "result/GetCounterModelResult.hpp"
#include "result/DescribeCompletesResult.hpp"
#include "result/DescribeCompletesByUserIdResult.hpp"
#include "result/CompleteResult.hpp"
#include "result/CompleteByUserIdResult.hpp"
#include "result/ReceiveByUserIdResult.hpp"
#include "result/GetCompleteResult.hpp"
#include "result/GetCompleteByUserIdResult.hpp"
#include "result/DeleteCompleteByUserIdResult.hpp"
#include "result/ReceiveByStampTaskResult.hpp"
#include "result/DescribeMissionTaskModelsResult.hpp"
#include "result/GetMissionTaskModelResult.hpp"
#include "result/DescribeMissionTaskModelMastersResult.hpp"
#include "result/CreateMissionTaskModelMasterResult.hpp"
#include "result/GetMissionTaskModelMasterResult.hpp"
#include "result/UpdateMissionTaskModelMasterResult.hpp"
#include "result/DeleteMissionTaskModelMasterResult.hpp"
#include "result/DescribeCountersResult.hpp"
#include "result/DescribeCountersByUserIdResult.hpp"
#include "result/IncreaseCounterByUserIdResult.hpp"
#include "result/GetCounterResult.hpp"
#include "result/GetCounterByUserIdResult.hpp"
#include "result/DeleteCounterByUserIdResult.hpp"
#include "result/IncreaseByStampSheetResult.hpp"
#include "result/ExportMasterResult.hpp"
#include "result/GetCurrentMissionMasterResult.hpp"
#include "result/UpdateCurrentMissionMasterResult.hpp"
#include "result/UpdateCurrentMissionMasterFromGitHubResult.hpp"
#include "result/DescribeCounterModelMastersResult.hpp"
#include "result/CreateCounterModelMasterResult.hpp"
#include "result/GetCounterModelMasterResult.hpp"
#include "result/UpdateCounterModelMasterResult.hpp"
#include "result/DeleteCounterModelMasterResult.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeMissionGroupModelMastersResult.hpp"
#include "result/CreateMissionGroupModelMasterResult.hpp"
#include "result/GetMissionGroupModelMasterResult.hpp"
#include "result/UpdateMissionGroupModelMasterResult.hpp"
#include "result/DeleteMissionGroupModelMasterResult.hpp"
#include "result/DescribeMissionGroupModelsResult.hpp"
#include "result/GetMissionGroupModelResult.hpp"
#include <cstring>

namespace gs2 { namespace mission {

/**
 * GS2 Mission API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2MissionWebSocketClient : public AbstractGs2ClientBase
{
private:

    class DescribeCounterModelsTask : public detail::Gs2WebSocketSessionTask<DescribeCounterModelsResult>
    {
    private:
        DescribeCounterModelsRequest& m_Request;

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
            writer.writeCharArray("mission");
            writer.writePropertyName("component");
            writer.writeCharArray("counterModel");
            writer.writePropertyName("function");
            writer.writeCharArray("describeCounterModels");
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
        DescribeCounterModelsTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeCounterModelsRequest& request,
            Gs2WebSocketSessionTask<DescribeCounterModelsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeCounterModelsResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeCounterModelsTask() GS2_OVERRIDE = default;
    };

    class GetCounterModelTask : public detail::Gs2WebSocketSessionTask<GetCounterModelResult>
    {
    private:
        GetCounterModelRequest& m_Request;

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
            if (m_Request.getCounterName())
            {
                writer.writePropertyName("counterName");
                writer.writeCharArray(*m_Request.getCounterName());
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
            writer.writeCharArray("mission");
            writer.writePropertyName("component");
            writer.writeCharArray("counterModel");
            writer.writePropertyName("function");
            writer.writeCharArray("getCounterModel");
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
        GetCounterModelTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetCounterModelRequest& request,
            Gs2WebSocketSessionTask<GetCounterModelResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetCounterModelResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetCounterModelTask() GS2_OVERRIDE = default;
    };

    class DescribeCompletesTask : public detail::Gs2WebSocketSessionTask<DescribeCompletesResult>
    {
    private:
        DescribeCompletesRequest& m_Request;

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
            writer.writeCharArray("mission");
            writer.writePropertyName("component");
            writer.writeCharArray("complete");
            writer.writePropertyName("function");
            writer.writeCharArray("describeCompletes");
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
        DescribeCompletesTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeCompletesRequest& request,
            Gs2WebSocketSessionTask<DescribeCompletesResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeCompletesResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeCompletesTask() GS2_OVERRIDE = default;
    };

    class DescribeCompletesByUserIdTask : public detail::Gs2WebSocketSessionTask<DescribeCompletesByUserIdResult>
    {
    private:
        DescribeCompletesByUserIdRequest& m_Request;

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
            writer.writeCharArray("mission");
            writer.writePropertyName("component");
            writer.writeCharArray("complete");
            writer.writePropertyName("function");
            writer.writeCharArray("describeCompletesByUserId");
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
        DescribeCompletesByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeCompletesByUserIdRequest& request,
            Gs2WebSocketSessionTask<DescribeCompletesByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeCompletesByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeCompletesByUserIdTask() GS2_OVERRIDE = default;
    };

    class CompleteTask : public detail::Gs2WebSocketSessionTask<CompleteResult>
    {
    private:
        CompleteRequest& m_Request;

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
            if (m_Request.getMissionGroupName())
            {
                writer.writePropertyName("missionGroupName");
                writer.writeCharArray(*m_Request.getMissionGroupName());
            }
            if (m_Request.getMissionTaskName())
            {
                writer.writePropertyName("missionTaskName");
                writer.writeCharArray(*m_Request.getMissionTaskName());
            }
            if (m_Request.getConfig())
            {
                writer.writePropertyName("config");
                writer.writeArrayStart();
                auto& list = *m_Request.getConfig();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(writer, list[i]);
                }
                writer.writeArrayEnd();
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
            writer.writeCharArray("mission");
            writer.writePropertyName("component");
            writer.writeCharArray("complete");
            writer.writePropertyName("function");
            writer.writeCharArray("complete");
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
        CompleteTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            CompleteRequest& request,
            Gs2WebSocketSessionTask<CompleteResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CompleteResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~CompleteTask() GS2_OVERRIDE = default;
    };

    class CompleteByUserIdTask : public detail::Gs2WebSocketSessionTask<CompleteByUserIdResult>
    {
    private:
        CompleteByUserIdRequest& m_Request;

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
            if (m_Request.getMissionGroupName())
            {
                writer.writePropertyName("missionGroupName");
                writer.writeCharArray(*m_Request.getMissionGroupName());
            }
            if (m_Request.getMissionTaskName())
            {
                writer.writePropertyName("missionTaskName");
                writer.writeCharArray(*m_Request.getMissionTaskName());
            }
            if (m_Request.getUserId())
            {
                writer.writePropertyName("userId");
                writer.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getConfig())
            {
                writer.writePropertyName("config");
                writer.writeArrayStart();
                auto& list = *m_Request.getConfig();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(writer, list[i]);
                }
                writer.writeArrayEnd();
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
            writer.writeCharArray("mission");
            writer.writePropertyName("component");
            writer.writeCharArray("complete");
            writer.writePropertyName("function");
            writer.writeCharArray("completeByUserId");
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
        CompleteByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            CompleteByUserIdRequest& request,
            Gs2WebSocketSessionTask<CompleteByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CompleteByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~CompleteByUserIdTask() GS2_OVERRIDE = default;
    };

    class ReceiveByUserIdTask : public detail::Gs2WebSocketSessionTask<ReceiveByUserIdResult>
    {
    private:
        ReceiveByUserIdRequest& m_Request;

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
            if (m_Request.getMissionGroupName())
            {
                writer.writePropertyName("missionGroupName");
                writer.writeCharArray(*m_Request.getMissionGroupName());
            }
            if (m_Request.getMissionTaskName())
            {
                writer.writePropertyName("missionTaskName");
                writer.writeCharArray(*m_Request.getMissionTaskName());
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
            writer.writeCharArray("mission");
            writer.writePropertyName("component");
            writer.writeCharArray("complete");
            writer.writePropertyName("function");
            writer.writeCharArray("receiveByUserId");
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
        ReceiveByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            ReceiveByUserIdRequest& request,
            Gs2WebSocketSessionTask<ReceiveByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<ReceiveByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~ReceiveByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetCompleteTask : public detail::Gs2WebSocketSessionTask<GetCompleteResult>
    {
    private:
        GetCompleteRequest& m_Request;

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
            if (m_Request.getMissionGroupName())
            {
                writer.writePropertyName("missionGroupName");
                writer.writeCharArray(*m_Request.getMissionGroupName());
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
            writer.writeCharArray("mission");
            writer.writePropertyName("component");
            writer.writeCharArray("complete");
            writer.writePropertyName("function");
            writer.writeCharArray("getComplete");
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
        GetCompleteTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetCompleteRequest& request,
            Gs2WebSocketSessionTask<GetCompleteResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetCompleteResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetCompleteTask() GS2_OVERRIDE = default;
    };

    class GetCompleteByUserIdTask : public detail::Gs2WebSocketSessionTask<GetCompleteByUserIdResult>
    {
    private:
        GetCompleteByUserIdRequest& m_Request;

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
            if (m_Request.getMissionGroupName())
            {
                writer.writePropertyName("missionGroupName");
                writer.writeCharArray(*m_Request.getMissionGroupName());
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
            writer.writeCharArray("mission");
            writer.writePropertyName("component");
            writer.writeCharArray("complete");
            writer.writePropertyName("function");
            writer.writeCharArray("getCompleteByUserId");
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
        GetCompleteByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetCompleteByUserIdRequest& request,
            Gs2WebSocketSessionTask<GetCompleteByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetCompleteByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetCompleteByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteCompleteByUserIdTask : public detail::Gs2WebSocketSessionTask<DeleteCompleteByUserIdResult>
    {
    private:
        DeleteCompleteByUserIdRequest& m_Request;

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
            if (m_Request.getMissionGroupName())
            {
                writer.writePropertyName("missionGroupName");
                writer.writeCharArray(*m_Request.getMissionGroupName());
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
            writer.writeCharArray("mission");
            writer.writePropertyName("component");
            writer.writeCharArray("complete");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteCompleteByUserId");
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
        DeleteCompleteByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteCompleteByUserIdRequest& request,
            Gs2WebSocketSessionTask<DeleteCompleteByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteCompleteByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteCompleteByUserIdTask() GS2_OVERRIDE = default;
    };

    class ReceiveByStampTaskTask : public detail::Gs2WebSocketSessionTask<ReceiveByStampTaskResult>
    {
    private:
        ReceiveByStampTaskRequest& m_Request;

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
            writer.writeCharArray("mission");
            writer.writePropertyName("component");
            writer.writeCharArray("complete");
            writer.writePropertyName("function");
            writer.writeCharArray("receiveByStampTask");
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
        ReceiveByStampTaskTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            ReceiveByStampTaskRequest& request,
            Gs2WebSocketSessionTask<ReceiveByStampTaskResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<ReceiveByStampTaskResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~ReceiveByStampTaskTask() GS2_OVERRIDE = default;
    };

    class DescribeMissionTaskModelsTask : public detail::Gs2WebSocketSessionTask<DescribeMissionTaskModelsResult>
    {
    private:
        DescribeMissionTaskModelsRequest& m_Request;

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
            if (m_Request.getMissionGroupName())
            {
                writer.writePropertyName("missionGroupName");
                writer.writeCharArray(*m_Request.getMissionGroupName());
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
            writer.writeCharArray("mission");
            writer.writePropertyName("component");
            writer.writeCharArray("missionTaskModel");
            writer.writePropertyName("function");
            writer.writeCharArray("describeMissionTaskModels");
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
        DescribeMissionTaskModelsTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeMissionTaskModelsRequest& request,
            Gs2WebSocketSessionTask<DescribeMissionTaskModelsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeMissionTaskModelsResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeMissionTaskModelsTask() GS2_OVERRIDE = default;
    };

    class GetMissionTaskModelTask : public detail::Gs2WebSocketSessionTask<GetMissionTaskModelResult>
    {
    private:
        GetMissionTaskModelRequest& m_Request;

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
            if (m_Request.getMissionGroupName())
            {
                writer.writePropertyName("missionGroupName");
                writer.writeCharArray(*m_Request.getMissionGroupName());
            }
            if (m_Request.getMissionTaskName())
            {
                writer.writePropertyName("missionTaskName");
                writer.writeCharArray(*m_Request.getMissionTaskName());
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
            writer.writeCharArray("mission");
            writer.writePropertyName("component");
            writer.writeCharArray("missionTaskModel");
            writer.writePropertyName("function");
            writer.writeCharArray("getMissionTaskModel");
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
        GetMissionTaskModelTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetMissionTaskModelRequest& request,
            Gs2WebSocketSessionTask<GetMissionTaskModelResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetMissionTaskModelResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetMissionTaskModelTask() GS2_OVERRIDE = default;
    };

    class DescribeMissionTaskModelMastersTask : public detail::Gs2WebSocketSessionTask<DescribeMissionTaskModelMastersResult>
    {
    private:
        DescribeMissionTaskModelMastersRequest& m_Request;

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
            if (m_Request.getMissionGroupName())
            {
                writer.writePropertyName("missionGroupName");
                writer.writeCharArray(*m_Request.getMissionGroupName());
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
            writer.writeCharArray("mission");
            writer.writePropertyName("component");
            writer.writeCharArray("missionTaskModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("describeMissionTaskModelMasters");
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
        DescribeMissionTaskModelMastersTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeMissionTaskModelMastersRequest& request,
            Gs2WebSocketSessionTask<DescribeMissionTaskModelMastersResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeMissionTaskModelMastersResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeMissionTaskModelMastersTask() GS2_OVERRIDE = default;
    };

    class CreateMissionTaskModelMasterTask : public detail::Gs2WebSocketSessionTask<CreateMissionTaskModelMasterResult>
    {
    private:
        CreateMissionTaskModelMasterRequest& m_Request;

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
            if (m_Request.getMissionGroupName())
            {
                writer.writePropertyName("missionGroupName");
                writer.writeCharArray(*m_Request.getMissionGroupName());
            }
            if (m_Request.getName())
            {
                writer.writePropertyName("name");
                writer.writeCharArray(*m_Request.getName());
            }
            if (m_Request.getMetadata())
            {
                writer.writePropertyName("metadata");
                writer.writeCharArray(*m_Request.getMetadata());
            }
            if (m_Request.getDescription())
            {
                writer.writePropertyName("description");
                writer.writeCharArray(*m_Request.getDescription());
            }
            if (m_Request.getCounterName())
            {
                writer.writePropertyName("counterName");
                writer.writeCharArray(*m_Request.getCounterName());
            }
            if (m_Request.getResetType())
            {
                writer.writePropertyName("resetType");
                writer.writeCharArray(*m_Request.getResetType());
            }
            if (m_Request.getTargetValue())
            {
                writer.writePropertyName("targetValue");
                writer.writeInt64(*m_Request.getTargetValue());
            }
            if (m_Request.getCompleteAcquireActions())
            {
                writer.writePropertyName("completeAcquireActions");
                writer.writeArrayStart();
                auto& list = *m_Request.getCompleteAcquireActions();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(writer, list[i]);
                }
                writer.writeArrayEnd();
            }
            if (m_Request.getChallengePeriodEventId())
            {
                writer.writePropertyName("challengePeriodEventId");
                writer.writeCharArray(*m_Request.getChallengePeriodEventId());
            }
            if (m_Request.getPremiseMissionTaskName())
            {
                writer.writePropertyName("premiseMissionTaskName");
                writer.writeCharArray(*m_Request.getPremiseMissionTaskName());
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
            writer.writeCharArray("mission");
            writer.writePropertyName("component");
            writer.writeCharArray("missionTaskModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("createMissionTaskModelMaster");
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
        CreateMissionTaskModelMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            CreateMissionTaskModelMasterRequest& request,
            Gs2WebSocketSessionTask<CreateMissionTaskModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateMissionTaskModelMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~CreateMissionTaskModelMasterTask() GS2_OVERRIDE = default;
    };

    class GetMissionTaskModelMasterTask : public detail::Gs2WebSocketSessionTask<GetMissionTaskModelMasterResult>
    {
    private:
        GetMissionTaskModelMasterRequest& m_Request;

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
            if (m_Request.getMissionGroupName())
            {
                writer.writePropertyName("missionGroupName");
                writer.writeCharArray(*m_Request.getMissionGroupName());
            }
            if (m_Request.getMissionTaskName())
            {
                writer.writePropertyName("missionTaskName");
                writer.writeCharArray(*m_Request.getMissionTaskName());
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
            writer.writeCharArray("mission");
            writer.writePropertyName("component");
            writer.writeCharArray("missionTaskModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("getMissionTaskModelMaster");
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
        GetMissionTaskModelMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetMissionTaskModelMasterRequest& request,
            Gs2WebSocketSessionTask<GetMissionTaskModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetMissionTaskModelMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetMissionTaskModelMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateMissionTaskModelMasterTask : public detail::Gs2WebSocketSessionTask<UpdateMissionTaskModelMasterResult>
    {
    private:
        UpdateMissionTaskModelMasterRequest& m_Request;

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
            if (m_Request.getMissionGroupName())
            {
                writer.writePropertyName("missionGroupName");
                writer.writeCharArray(*m_Request.getMissionGroupName());
            }
            if (m_Request.getMissionTaskName())
            {
                writer.writePropertyName("missionTaskName");
                writer.writeCharArray(*m_Request.getMissionTaskName());
            }
            if (m_Request.getMetadata())
            {
                writer.writePropertyName("metadata");
                writer.writeCharArray(*m_Request.getMetadata());
            }
            if (m_Request.getDescription())
            {
                writer.writePropertyName("description");
                writer.writeCharArray(*m_Request.getDescription());
            }
            if (m_Request.getCounterName())
            {
                writer.writePropertyName("counterName");
                writer.writeCharArray(*m_Request.getCounterName());
            }
            if (m_Request.getResetType())
            {
                writer.writePropertyName("resetType");
                writer.writeCharArray(*m_Request.getResetType());
            }
            if (m_Request.getTargetValue())
            {
                writer.writePropertyName("targetValue");
                writer.writeInt64(*m_Request.getTargetValue());
            }
            if (m_Request.getCompleteAcquireActions())
            {
                writer.writePropertyName("completeAcquireActions");
                writer.writeArrayStart();
                auto& list = *m_Request.getCompleteAcquireActions();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(writer, list[i]);
                }
                writer.writeArrayEnd();
            }
            if (m_Request.getChallengePeriodEventId())
            {
                writer.writePropertyName("challengePeriodEventId");
                writer.writeCharArray(*m_Request.getChallengePeriodEventId());
            }
            if (m_Request.getPremiseMissionTaskName())
            {
                writer.writePropertyName("premiseMissionTaskName");
                writer.writeCharArray(*m_Request.getPremiseMissionTaskName());
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
            writer.writeCharArray("mission");
            writer.writePropertyName("component");
            writer.writeCharArray("missionTaskModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("updateMissionTaskModelMaster");
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
        UpdateMissionTaskModelMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateMissionTaskModelMasterRequest& request,
            Gs2WebSocketSessionTask<UpdateMissionTaskModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateMissionTaskModelMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateMissionTaskModelMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteMissionTaskModelMasterTask : public detail::Gs2WebSocketSessionTask<DeleteMissionTaskModelMasterResult>
    {
    private:
        DeleteMissionTaskModelMasterRequest& m_Request;

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
            if (m_Request.getMissionGroupName())
            {
                writer.writePropertyName("missionGroupName");
                writer.writeCharArray(*m_Request.getMissionGroupName());
            }
            if (m_Request.getMissionTaskName())
            {
                writer.writePropertyName("missionTaskName");
                writer.writeCharArray(*m_Request.getMissionTaskName());
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
            writer.writeCharArray("mission");
            writer.writePropertyName("component");
            writer.writeCharArray("missionTaskModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteMissionTaskModelMaster");
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
        DeleteMissionTaskModelMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteMissionTaskModelMasterRequest& request,
            Gs2WebSocketSessionTask<DeleteMissionTaskModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteMissionTaskModelMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteMissionTaskModelMasterTask() GS2_OVERRIDE = default;
    };

    class DescribeCountersTask : public detail::Gs2WebSocketSessionTask<DescribeCountersResult>
    {
    private:
        DescribeCountersRequest& m_Request;

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
            writer.writeCharArray("mission");
            writer.writePropertyName("component");
            writer.writeCharArray("counter");
            writer.writePropertyName("function");
            writer.writeCharArray("describeCounters");
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
        DescribeCountersTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeCountersRequest& request,
            Gs2WebSocketSessionTask<DescribeCountersResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeCountersResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeCountersTask() GS2_OVERRIDE = default;
    };

    class DescribeCountersByUserIdTask : public detail::Gs2WebSocketSessionTask<DescribeCountersByUserIdResult>
    {
    private:
        DescribeCountersByUserIdRequest& m_Request;

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
            writer.writeCharArray("mission");
            writer.writePropertyName("component");
            writer.writeCharArray("counter");
            writer.writePropertyName("function");
            writer.writeCharArray("describeCountersByUserId");
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
        DescribeCountersByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeCountersByUserIdRequest& request,
            Gs2WebSocketSessionTask<DescribeCountersByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeCountersByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeCountersByUserIdTask() GS2_OVERRIDE = default;
    };

    class IncreaseCounterByUserIdTask : public detail::Gs2WebSocketSessionTask<IncreaseCounterByUserIdResult>
    {
    private:
        IncreaseCounterByUserIdRequest& m_Request;

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
            if (m_Request.getCounterName())
            {
                writer.writePropertyName("counterName");
                writer.writeCharArray(*m_Request.getCounterName());
            }
            if (m_Request.getUserId())
            {
                writer.writePropertyName("userId");
                writer.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getValue())
            {
                writer.writePropertyName("value");
                writer.writeInt64(*m_Request.getValue());
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
            writer.writeCharArray("mission");
            writer.writePropertyName("component");
            writer.writeCharArray("counter");
            writer.writePropertyName("function");
            writer.writeCharArray("increaseCounterByUserId");
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
        IncreaseCounterByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            IncreaseCounterByUserIdRequest& request,
            Gs2WebSocketSessionTask<IncreaseCounterByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<IncreaseCounterByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~IncreaseCounterByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetCounterTask : public detail::Gs2WebSocketSessionTask<GetCounterResult>
    {
    private:
        GetCounterRequest& m_Request;

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
            if (m_Request.getCounterName())
            {
                writer.writePropertyName("counterName");
                writer.writeCharArray(*m_Request.getCounterName());
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
            writer.writeCharArray("mission");
            writer.writePropertyName("component");
            writer.writeCharArray("counter");
            writer.writePropertyName("function");
            writer.writeCharArray("getCounter");
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
        GetCounterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetCounterRequest& request,
            Gs2WebSocketSessionTask<GetCounterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetCounterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetCounterTask() GS2_OVERRIDE = default;
    };

    class GetCounterByUserIdTask : public detail::Gs2WebSocketSessionTask<GetCounterByUserIdResult>
    {
    private:
        GetCounterByUserIdRequest& m_Request;

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
            if (m_Request.getCounterName())
            {
                writer.writePropertyName("counterName");
                writer.writeCharArray(*m_Request.getCounterName());
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
            writer.writeCharArray("mission");
            writer.writePropertyName("component");
            writer.writeCharArray("counter");
            writer.writePropertyName("function");
            writer.writeCharArray("getCounterByUserId");
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
        GetCounterByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetCounterByUserIdRequest& request,
            Gs2WebSocketSessionTask<GetCounterByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetCounterByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetCounterByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteCounterByUserIdTask : public detail::Gs2WebSocketSessionTask<DeleteCounterByUserIdResult>
    {
    private:
        DeleteCounterByUserIdRequest& m_Request;

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
            if (m_Request.getCounterName())
            {
                writer.writePropertyName("counterName");
                writer.writeCharArray(*m_Request.getCounterName());
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
            writer.writeCharArray("mission");
            writer.writePropertyName("component");
            writer.writeCharArray("counter");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteCounterByUserId");
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
        DeleteCounterByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteCounterByUserIdRequest& request,
            Gs2WebSocketSessionTask<DeleteCounterByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteCounterByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteCounterByUserIdTask() GS2_OVERRIDE = default;
    };

    class IncreaseByStampSheetTask : public detail::Gs2WebSocketSessionTask<IncreaseByStampSheetResult>
    {
    private:
        IncreaseByStampSheetRequest& m_Request;

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
            writer.writeCharArray("mission");
            writer.writePropertyName("component");
            writer.writeCharArray("counter");
            writer.writePropertyName("function");
            writer.writeCharArray("increaseByStampSheet");
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
        IncreaseByStampSheetTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            IncreaseByStampSheetRequest& request,
            Gs2WebSocketSessionTask<IncreaseByStampSheetResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<IncreaseByStampSheetResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~IncreaseByStampSheetTask() GS2_OVERRIDE = default;
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
            writer.writeCharArray("mission");
            writer.writePropertyName("component");
            writer.writeCharArray("currentMissionMaster");
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

    class GetCurrentMissionMasterTask : public detail::Gs2WebSocketSessionTask<GetCurrentMissionMasterResult>
    {
    private:
        GetCurrentMissionMasterRequest& m_Request;

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
            writer.writeCharArray("mission");
            writer.writePropertyName("component");
            writer.writeCharArray("currentMissionMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("getCurrentMissionMaster");
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
        GetCurrentMissionMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetCurrentMissionMasterRequest& request,
            Gs2WebSocketSessionTask<GetCurrentMissionMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetCurrentMissionMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetCurrentMissionMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentMissionMasterTask : public detail::Gs2WebSocketSessionTask<UpdateCurrentMissionMasterResult>
    {
    private:
        UpdateCurrentMissionMasterRequest& m_Request;

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
            writer.writeCharArray("mission");
            writer.writePropertyName("component");
            writer.writeCharArray("currentMissionMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("updateCurrentMissionMaster");
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
        UpdateCurrentMissionMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateCurrentMissionMasterRequest& request,
            Gs2WebSocketSessionTask<UpdateCurrentMissionMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateCurrentMissionMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateCurrentMissionMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentMissionMasterFromGitHubTask : public detail::Gs2WebSocketSessionTask<UpdateCurrentMissionMasterFromGitHubResult>
    {
    private:
        UpdateCurrentMissionMasterFromGitHubRequest& m_Request;

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
            writer.writeCharArray("mission");
            writer.writePropertyName("component");
            writer.writeCharArray("currentMissionMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("updateCurrentMissionMasterFromGitHub");
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
        UpdateCurrentMissionMasterFromGitHubTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateCurrentMissionMasterFromGitHubRequest& request,
            Gs2WebSocketSessionTask<UpdateCurrentMissionMasterFromGitHubResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateCurrentMissionMasterFromGitHubResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateCurrentMissionMasterFromGitHubTask() GS2_OVERRIDE = default;
    };

    class DescribeCounterModelMastersTask : public detail::Gs2WebSocketSessionTask<DescribeCounterModelMastersResult>
    {
    private:
        DescribeCounterModelMastersRequest& m_Request;

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
            writer.writeCharArray("mission");
            writer.writePropertyName("component");
            writer.writeCharArray("counterModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("describeCounterModelMasters");
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
        DescribeCounterModelMastersTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeCounterModelMastersRequest& request,
            Gs2WebSocketSessionTask<DescribeCounterModelMastersResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeCounterModelMastersResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeCounterModelMastersTask() GS2_OVERRIDE = default;
    };

    class CreateCounterModelMasterTask : public detail::Gs2WebSocketSessionTask<CreateCounterModelMasterResult>
    {
    private:
        CreateCounterModelMasterRequest& m_Request;

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
            if (m_Request.getMetadata())
            {
                writer.writePropertyName("metadata");
                writer.writeCharArray(*m_Request.getMetadata());
            }
            if (m_Request.getDescription())
            {
                writer.writePropertyName("description");
                writer.writeCharArray(*m_Request.getDescription());
            }
            if (m_Request.getScopes())
            {
                writer.writePropertyName("scopes");
                writer.writeArrayStart();
                auto& list = *m_Request.getScopes();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(writer, list[i]);
                }
                writer.writeArrayEnd();
            }
            if (m_Request.getChallengePeriodEventId())
            {
                writer.writePropertyName("challengePeriodEventId");
                writer.writeCharArray(*m_Request.getChallengePeriodEventId());
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
            writer.writeCharArray("mission");
            writer.writePropertyName("component");
            writer.writeCharArray("counterModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("createCounterModelMaster");
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
        CreateCounterModelMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            CreateCounterModelMasterRequest& request,
            Gs2WebSocketSessionTask<CreateCounterModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateCounterModelMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~CreateCounterModelMasterTask() GS2_OVERRIDE = default;
    };

    class GetCounterModelMasterTask : public detail::Gs2WebSocketSessionTask<GetCounterModelMasterResult>
    {
    private:
        GetCounterModelMasterRequest& m_Request;

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
            if (m_Request.getCounterName())
            {
                writer.writePropertyName("counterName");
                writer.writeCharArray(*m_Request.getCounterName());
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
            writer.writeCharArray("mission");
            writer.writePropertyName("component");
            writer.writeCharArray("counterModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("getCounterModelMaster");
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
        GetCounterModelMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetCounterModelMasterRequest& request,
            Gs2WebSocketSessionTask<GetCounterModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetCounterModelMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetCounterModelMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCounterModelMasterTask : public detail::Gs2WebSocketSessionTask<UpdateCounterModelMasterResult>
    {
    private:
        UpdateCounterModelMasterRequest& m_Request;

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
            if (m_Request.getCounterName())
            {
                writer.writePropertyName("counterName");
                writer.writeCharArray(*m_Request.getCounterName());
            }
            if (m_Request.getMetadata())
            {
                writer.writePropertyName("metadata");
                writer.writeCharArray(*m_Request.getMetadata());
            }
            if (m_Request.getDescription())
            {
                writer.writePropertyName("description");
                writer.writeCharArray(*m_Request.getDescription());
            }
            if (m_Request.getScopes())
            {
                writer.writePropertyName("scopes");
                writer.writeArrayStart();
                auto& list = *m_Request.getScopes();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(writer, list[i]);
                }
                writer.writeArrayEnd();
            }
            if (m_Request.getChallengePeriodEventId())
            {
                writer.writePropertyName("challengePeriodEventId");
                writer.writeCharArray(*m_Request.getChallengePeriodEventId());
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
            writer.writeCharArray("mission");
            writer.writePropertyName("component");
            writer.writeCharArray("counterModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("updateCounterModelMaster");
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
        UpdateCounterModelMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateCounterModelMasterRequest& request,
            Gs2WebSocketSessionTask<UpdateCounterModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateCounterModelMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateCounterModelMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteCounterModelMasterTask : public detail::Gs2WebSocketSessionTask<DeleteCounterModelMasterResult>
    {
    private:
        DeleteCounterModelMasterRequest& m_Request;

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
            if (m_Request.getCounterName())
            {
                writer.writePropertyName("counterName");
                writer.writeCharArray(*m_Request.getCounterName());
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
            writer.writeCharArray("mission");
            writer.writePropertyName("component");
            writer.writeCharArray("counterModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteCounterModelMaster");
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
        DeleteCounterModelMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteCounterModelMasterRequest& request,
            Gs2WebSocketSessionTask<DeleteCounterModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteCounterModelMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteCounterModelMasterTask() GS2_OVERRIDE = default;
    };

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
            writer.writeCharArray("mission");
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
            if (m_Request.getMissionCompleteTriggerScriptId())
            {
                writer.writePropertyName("missionCompleteTriggerScriptId");
                writer.writeCharArray(*m_Request.getMissionCompleteTriggerScriptId());
            }
            if (m_Request.getMissionCompleteDoneTriggerScriptId())
            {
                writer.writePropertyName("missionCompleteDoneTriggerScriptId");
                writer.writeCharArray(*m_Request.getMissionCompleteDoneTriggerScriptId());
            }
            if (m_Request.getMissionCompleteDoneTriggerQueueNamespaceId())
            {
                writer.writePropertyName("missionCompleteDoneTriggerQueueNamespaceId");
                writer.writeCharArray(*m_Request.getMissionCompleteDoneTriggerQueueNamespaceId());
            }
            if (m_Request.getCounterIncrementTriggerScriptId())
            {
                writer.writePropertyName("counterIncrementTriggerScriptId");
                writer.writeCharArray(*m_Request.getCounterIncrementTriggerScriptId());
            }
            if (m_Request.getCounterIncrementDoneTriggerScriptId())
            {
                writer.writePropertyName("counterIncrementDoneTriggerScriptId");
                writer.writeCharArray(*m_Request.getCounterIncrementDoneTriggerScriptId());
            }
            if (m_Request.getCounterIncrementDoneTriggerQueueNamespaceId())
            {
                writer.writePropertyName("counterIncrementDoneTriggerQueueNamespaceId");
                writer.writeCharArray(*m_Request.getCounterIncrementDoneTriggerQueueNamespaceId());
            }
            if (m_Request.getReceiveRewardsTriggerScriptId())
            {
                writer.writePropertyName("receiveRewardsTriggerScriptId");
                writer.writeCharArray(*m_Request.getReceiveRewardsTriggerScriptId());
            }
            if (m_Request.getReceiveRewardsDoneTriggerScriptId())
            {
                writer.writePropertyName("receiveRewardsDoneTriggerScriptId");
                writer.writeCharArray(*m_Request.getReceiveRewardsDoneTriggerScriptId());
            }
            if (m_Request.getReceiveRewardsDoneTriggerQueueNamespaceId())
            {
                writer.writePropertyName("receiveRewardsDoneTriggerQueueNamespaceId");
                writer.writeCharArray(*m_Request.getReceiveRewardsDoneTriggerQueueNamespaceId());
            }
            if (m_Request.getQueueNamespaceId())
            {
                writer.writePropertyName("queueNamespaceId");
                writer.writeCharArray(*m_Request.getQueueNamespaceId());
            }
            if (m_Request.getKeyId())
            {
                writer.writePropertyName("keyId");
                writer.writeCharArray(*m_Request.getKeyId());
            }
            if (m_Request.getCompleteNotification())
            {
                writer.writePropertyName("completeNotification");
                write(writer, *m_Request.getCompleteNotification());
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
            writer.writeCharArray("mission");
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
            writer.writeCharArray("mission");
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
            writer.writeCharArray("mission");
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
            if (m_Request.getMissionCompleteTriggerScriptId())
            {
                writer.writePropertyName("missionCompleteTriggerScriptId");
                writer.writeCharArray(*m_Request.getMissionCompleteTriggerScriptId());
            }
            if (m_Request.getMissionCompleteDoneTriggerScriptId())
            {
                writer.writePropertyName("missionCompleteDoneTriggerScriptId");
                writer.writeCharArray(*m_Request.getMissionCompleteDoneTriggerScriptId());
            }
            if (m_Request.getMissionCompleteDoneTriggerQueueNamespaceId())
            {
                writer.writePropertyName("missionCompleteDoneTriggerQueueNamespaceId");
                writer.writeCharArray(*m_Request.getMissionCompleteDoneTriggerQueueNamespaceId());
            }
            if (m_Request.getCounterIncrementTriggerScriptId())
            {
                writer.writePropertyName("counterIncrementTriggerScriptId");
                writer.writeCharArray(*m_Request.getCounterIncrementTriggerScriptId());
            }
            if (m_Request.getCounterIncrementDoneTriggerScriptId())
            {
                writer.writePropertyName("counterIncrementDoneTriggerScriptId");
                writer.writeCharArray(*m_Request.getCounterIncrementDoneTriggerScriptId());
            }
            if (m_Request.getCounterIncrementDoneTriggerQueueNamespaceId())
            {
                writer.writePropertyName("counterIncrementDoneTriggerQueueNamespaceId");
                writer.writeCharArray(*m_Request.getCounterIncrementDoneTriggerQueueNamespaceId());
            }
            if (m_Request.getReceiveRewardsTriggerScriptId())
            {
                writer.writePropertyName("receiveRewardsTriggerScriptId");
                writer.writeCharArray(*m_Request.getReceiveRewardsTriggerScriptId());
            }
            if (m_Request.getReceiveRewardsDoneTriggerScriptId())
            {
                writer.writePropertyName("receiveRewardsDoneTriggerScriptId");
                writer.writeCharArray(*m_Request.getReceiveRewardsDoneTriggerScriptId());
            }
            if (m_Request.getReceiveRewardsDoneTriggerQueueNamespaceId())
            {
                writer.writePropertyName("receiveRewardsDoneTriggerQueueNamespaceId");
                writer.writeCharArray(*m_Request.getReceiveRewardsDoneTriggerQueueNamespaceId());
            }
            if (m_Request.getQueueNamespaceId())
            {
                writer.writePropertyName("queueNamespaceId");
                writer.writeCharArray(*m_Request.getQueueNamespaceId());
            }
            if (m_Request.getKeyId())
            {
                writer.writePropertyName("keyId");
                writer.writeCharArray(*m_Request.getKeyId());
            }
            if (m_Request.getCompleteNotification())
            {
                writer.writePropertyName("completeNotification");
                write(writer, *m_Request.getCompleteNotification());
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
            writer.writeCharArray("mission");
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
            writer.writeCharArray("mission");
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

    class DescribeMissionGroupModelMastersTask : public detail::Gs2WebSocketSessionTask<DescribeMissionGroupModelMastersResult>
    {
    private:
        DescribeMissionGroupModelMastersRequest& m_Request;

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
            writer.writeCharArray("mission");
            writer.writePropertyName("component");
            writer.writeCharArray("missionGroupModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("describeMissionGroupModelMasters");
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
        DescribeMissionGroupModelMastersTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeMissionGroupModelMastersRequest& request,
            Gs2WebSocketSessionTask<DescribeMissionGroupModelMastersResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeMissionGroupModelMastersResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeMissionGroupModelMastersTask() GS2_OVERRIDE = default;
    };

    class CreateMissionGroupModelMasterTask : public detail::Gs2WebSocketSessionTask<CreateMissionGroupModelMasterResult>
    {
    private:
        CreateMissionGroupModelMasterRequest& m_Request;

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
            if (m_Request.getMetadata())
            {
                writer.writePropertyName("metadata");
                writer.writeCharArray(*m_Request.getMetadata());
            }
            if (m_Request.getDescription())
            {
                writer.writePropertyName("description");
                writer.writeCharArray(*m_Request.getDescription());
            }
            if (m_Request.getCompleteNotificationNamespaceId())
            {
                writer.writePropertyName("completeNotificationNamespaceId");
                writer.writeCharArray(*m_Request.getCompleteNotificationNamespaceId());
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
            writer.writeCharArray("mission");
            writer.writePropertyName("component");
            writer.writeCharArray("missionGroupModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("createMissionGroupModelMaster");
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
        CreateMissionGroupModelMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            CreateMissionGroupModelMasterRequest& request,
            Gs2WebSocketSessionTask<CreateMissionGroupModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateMissionGroupModelMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~CreateMissionGroupModelMasterTask() GS2_OVERRIDE = default;
    };

    class GetMissionGroupModelMasterTask : public detail::Gs2WebSocketSessionTask<GetMissionGroupModelMasterResult>
    {
    private:
        GetMissionGroupModelMasterRequest& m_Request;

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
            if (m_Request.getMissionGroupName())
            {
                writer.writePropertyName("missionGroupName");
                writer.writeCharArray(*m_Request.getMissionGroupName());
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
            writer.writeCharArray("mission");
            writer.writePropertyName("component");
            writer.writeCharArray("missionGroupModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("getMissionGroupModelMaster");
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
        GetMissionGroupModelMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetMissionGroupModelMasterRequest& request,
            Gs2WebSocketSessionTask<GetMissionGroupModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetMissionGroupModelMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetMissionGroupModelMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateMissionGroupModelMasterTask : public detail::Gs2WebSocketSessionTask<UpdateMissionGroupModelMasterResult>
    {
    private:
        UpdateMissionGroupModelMasterRequest& m_Request;

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
            if (m_Request.getMissionGroupName())
            {
                writer.writePropertyName("missionGroupName");
                writer.writeCharArray(*m_Request.getMissionGroupName());
            }
            if (m_Request.getMetadata())
            {
                writer.writePropertyName("metadata");
                writer.writeCharArray(*m_Request.getMetadata());
            }
            if (m_Request.getDescription())
            {
                writer.writePropertyName("description");
                writer.writeCharArray(*m_Request.getDescription());
            }
            if (m_Request.getCompleteNotificationNamespaceId())
            {
                writer.writePropertyName("completeNotificationNamespaceId");
                writer.writeCharArray(*m_Request.getCompleteNotificationNamespaceId());
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
            writer.writeCharArray("mission");
            writer.writePropertyName("component");
            writer.writeCharArray("missionGroupModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("updateMissionGroupModelMaster");
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
        UpdateMissionGroupModelMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateMissionGroupModelMasterRequest& request,
            Gs2WebSocketSessionTask<UpdateMissionGroupModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateMissionGroupModelMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateMissionGroupModelMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteMissionGroupModelMasterTask : public detail::Gs2WebSocketSessionTask<DeleteMissionGroupModelMasterResult>
    {
    private:
        DeleteMissionGroupModelMasterRequest& m_Request;

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
            if (m_Request.getMissionGroupName())
            {
                writer.writePropertyName("missionGroupName");
                writer.writeCharArray(*m_Request.getMissionGroupName());
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
            writer.writeCharArray("mission");
            writer.writePropertyName("component");
            writer.writeCharArray("missionGroupModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteMissionGroupModelMaster");
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
        DeleteMissionGroupModelMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteMissionGroupModelMasterRequest& request,
            Gs2WebSocketSessionTask<DeleteMissionGroupModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteMissionGroupModelMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteMissionGroupModelMasterTask() GS2_OVERRIDE = default;
    };

    class DescribeMissionGroupModelsTask : public detail::Gs2WebSocketSessionTask<DescribeMissionGroupModelsResult>
    {
    private:
        DescribeMissionGroupModelsRequest& m_Request;

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
            writer.writeCharArray("mission");
            writer.writePropertyName("component");
            writer.writeCharArray("missionGroupModel");
            writer.writePropertyName("function");
            writer.writeCharArray("describeMissionGroupModels");
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
        DescribeMissionGroupModelsTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeMissionGroupModelsRequest& request,
            Gs2WebSocketSessionTask<DescribeMissionGroupModelsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeMissionGroupModelsResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeMissionGroupModelsTask() GS2_OVERRIDE = default;
    };

    class GetMissionGroupModelTask : public detail::Gs2WebSocketSessionTask<GetMissionGroupModelResult>
    {
    private:
        GetMissionGroupModelRequest& m_Request;

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
            if (m_Request.getMissionGroupName())
            {
                writer.writePropertyName("missionGroupName");
                writer.writeCharArray(*m_Request.getMissionGroupName());
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
            writer.writeCharArray("mission");
            writer.writePropertyName("component");
            writer.writeCharArray("missionGroupModel");
            writer.writePropertyName("function");
            writer.writeCharArray("getMissionGroupModel");
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
        GetMissionGroupModelTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetMissionGroupModelRequest& request,
            Gs2WebSocketSessionTask<GetMissionGroupModelResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetMissionGroupModelResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetMissionGroupModelTask() GS2_OVERRIDE = default;
    };

private:
    static void write(detail::json::JsonWriter& writer, const CounterModel& obj)
    {
        writer.writeObjectStart();
        if (obj.getCounterId())
        {
            writer.writePropertyName("counterId");
            writer.writeCharArray(*obj.getCounterId());
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
        if (obj.getScopes())
        {
            writer.writePropertyName("scopes");
            writer.writeArrayStart();
            auto& list = *obj.getScopes();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getChallengePeriodEventId())
        {
            writer.writePropertyName("challengePeriodEventId");
            writer.writeCharArray(*obj.getChallengePeriodEventId());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const Complete& obj)
    {
        writer.writeObjectStart();
        if (obj.getCompleteId())
        {
            writer.writePropertyName("completeId");
            writer.writeCharArray(*obj.getCompleteId());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.writeCharArray(*obj.getUserId());
        }
        if (obj.getMissionGroupName())
        {
            writer.writePropertyName("missionGroupName");
            writer.writeCharArray(*obj.getMissionGroupName());
        }
        if (obj.getCompletedMissionTaskNames())
        {
            writer.writePropertyName("completedMissionTaskNames");
            writer.writeArrayStart();
            auto& list = *obj.getCompletedMissionTaskNames();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                writer.writeCharArray(list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getReceivedMissionTaskNames())
        {
            writer.writePropertyName("receivedMissionTaskNames");
            writer.writeArrayStart();
            auto& list = *obj.getReceivedMissionTaskNames();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                writer.writeCharArray(list[i]);
            }
            writer.writeArrayEnd();
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

    static void write(detail::json::JsonWriter& writer, const NotificationSetting& obj)
    {
        writer.writeObjectStart();
        if (obj.getGatewayNamespaceId())
        {
            writer.writePropertyName("gatewayNamespaceId");
            writer.writeCharArray(*obj.getGatewayNamespaceId());
        }
        if (obj.getEnableTransferMobileNotification())
        {
            writer.writePropertyName("enableTransferMobileNotification");
            writer.writeBool(*obj.getEnableTransferMobileNotification());
        }
        if (obj.getSound())
        {
            writer.writePropertyName("sound");
            writer.writeCharArray(*obj.getSound());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const CounterScopeModel& obj)
    {
        writer.writeObjectStart();
        if (obj.getResetType())
        {
            writer.writePropertyName("resetType");
            writer.writeCharArray(*obj.getResetType());
        }
        if (obj.getResetDayOfMonth())
        {
            writer.writePropertyName("resetDayOfMonth");
            writer.writeInt32(*obj.getResetDayOfMonth());
        }
        if (obj.getResetDayOfWeek())
        {
            writer.writePropertyName("resetDayOfWeek");
            writer.writeCharArray(*obj.getResetDayOfWeek());
        }
        if (obj.getResetHour())
        {
            writer.writePropertyName("resetHour");
            writer.writeInt32(*obj.getResetHour());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const MissionTaskModel& obj)
    {
        writer.writeObjectStart();
        if (obj.getMissionTaskId())
        {
            writer.writePropertyName("missionTaskId");
            writer.writeCharArray(*obj.getMissionTaskId());
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
        if (obj.getCounterName())
        {
            writer.writePropertyName("counterName");
            writer.writeCharArray(*obj.getCounterName());
        }
        if (obj.getResetType())
        {
            writer.writePropertyName("resetType");
            writer.writeCharArray(*obj.getResetType());
        }
        if (obj.getTargetValue())
        {
            writer.writePropertyName("targetValue");
            writer.writeInt64(*obj.getTargetValue());
        }
        if (obj.getCompleteAcquireActions())
        {
            writer.writePropertyName("completeAcquireActions");
            writer.writeArrayStart();
            auto& list = *obj.getCompleteAcquireActions();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getChallengePeriodEventId())
        {
            writer.writePropertyName("challengePeriodEventId");
            writer.writeCharArray(*obj.getChallengePeriodEventId());
        }
        if (obj.getPremiseMissionTaskName())
        {
            writer.writePropertyName("premiseMissionTaskName");
            writer.writeCharArray(*obj.getPremiseMissionTaskName());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const ScopedValue& obj)
    {
        writer.writeObjectStart();
        if (obj.getResetType())
        {
            writer.writePropertyName("resetType");
            writer.writeCharArray(*obj.getResetType());
        }
        if (obj.getValue())
        {
            writer.writePropertyName("value");
            writer.writeInt64(*obj.getValue());
        }
        if (obj.getUpdatedAt())
        {
            writer.writePropertyName("updatedAt");
            writer.writeInt64(*obj.getUpdatedAt());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const MissionTaskModelMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getMissionTaskId())
        {
            writer.writePropertyName("missionTaskId");
            writer.writeCharArray(*obj.getMissionTaskId());
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
        if (obj.getCounterName())
        {
            writer.writePropertyName("counterName");
            writer.writeCharArray(*obj.getCounterName());
        }
        if (obj.getResetType())
        {
            writer.writePropertyName("resetType");
            writer.writeCharArray(*obj.getResetType());
        }
        if (obj.getTargetValue())
        {
            writer.writePropertyName("targetValue");
            writer.writeInt64(*obj.getTargetValue());
        }
        if (obj.getCompleteAcquireActions())
        {
            writer.writePropertyName("completeAcquireActions");
            writer.writeArrayStart();
            auto& list = *obj.getCompleteAcquireActions();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getChallengePeriodEventId())
        {
            writer.writePropertyName("challengePeriodEventId");
            writer.writeCharArray(*obj.getChallengePeriodEventId());
        }
        if (obj.getPremiseMissionTaskName())
        {
            writer.writePropertyName("premiseMissionTaskName");
            writer.writeCharArray(*obj.getPremiseMissionTaskName());
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

    static void write(detail::json::JsonWriter& writer, const Counter& obj)
    {
        writer.writeObjectStart();
        if (obj.getCounterId())
        {
            writer.writePropertyName("counterId");
            writer.writeCharArray(*obj.getCounterId());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.writeCharArray(*obj.getUserId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*obj.getName());
        }
        if (obj.getValues())
        {
            writer.writePropertyName("values");
            writer.writeArrayStart();
            auto& list = *obj.getValues();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
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

    static void write(detail::json::JsonWriter& writer, const Config& obj)
    {
        writer.writeObjectStart();
        if (obj.getKey())
        {
            writer.writePropertyName("key");
            writer.writeCharArray(*obj.getKey());
        }
        if (obj.getValue())
        {
            writer.writePropertyName("value");
            writer.writeCharArray(*obj.getValue());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const CurrentMissionMaster& obj)
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

    static void write(detail::json::JsonWriter& writer, const CounterModelMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getCounterId())
        {
            writer.writePropertyName("counterId");
            writer.writeCharArray(*obj.getCounterId());
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
        if (obj.getScopes())
        {
            writer.writePropertyName("scopes");
            writer.writeArrayStart();
            auto& list = *obj.getScopes();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getChallengePeriodEventId())
        {
            writer.writePropertyName("challengePeriodEventId");
            writer.writeCharArray(*obj.getChallengePeriodEventId());
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
        if (obj.getMissionCompleteTriggerScriptId())
        {
            writer.writePropertyName("missionCompleteTriggerScriptId");
            writer.writeCharArray(*obj.getMissionCompleteTriggerScriptId());
        }
        if (obj.getMissionCompleteDoneTriggerScriptId())
        {
            writer.writePropertyName("missionCompleteDoneTriggerScriptId");
            writer.writeCharArray(*obj.getMissionCompleteDoneTriggerScriptId());
        }
        if (obj.getMissionCompleteDoneTriggerQueueNamespaceId())
        {
            writer.writePropertyName("missionCompleteDoneTriggerQueueNamespaceId");
            writer.writeCharArray(*obj.getMissionCompleteDoneTriggerQueueNamespaceId());
        }
        if (obj.getCounterIncrementTriggerScriptId())
        {
            writer.writePropertyName("counterIncrementTriggerScriptId");
            writer.writeCharArray(*obj.getCounterIncrementTriggerScriptId());
        }
        if (obj.getCounterIncrementDoneTriggerScriptId())
        {
            writer.writePropertyName("counterIncrementDoneTriggerScriptId");
            writer.writeCharArray(*obj.getCounterIncrementDoneTriggerScriptId());
        }
        if (obj.getCounterIncrementDoneTriggerQueueNamespaceId())
        {
            writer.writePropertyName("counterIncrementDoneTriggerQueueNamespaceId");
            writer.writeCharArray(*obj.getCounterIncrementDoneTriggerQueueNamespaceId());
        }
        if (obj.getReceiveRewardsTriggerScriptId())
        {
            writer.writePropertyName("receiveRewardsTriggerScriptId");
            writer.writeCharArray(*obj.getReceiveRewardsTriggerScriptId());
        }
        if (obj.getReceiveRewardsDoneTriggerScriptId())
        {
            writer.writePropertyName("receiveRewardsDoneTriggerScriptId");
            writer.writeCharArray(*obj.getReceiveRewardsDoneTriggerScriptId());
        }
        if (obj.getReceiveRewardsDoneTriggerQueueNamespaceId())
        {
            writer.writePropertyName("receiveRewardsDoneTriggerQueueNamespaceId");
            writer.writeCharArray(*obj.getReceiveRewardsDoneTriggerQueueNamespaceId());
        }
        if (obj.getQueueNamespaceId())
        {
            writer.writePropertyName("queueNamespaceId");
            writer.writeCharArray(*obj.getQueueNamespaceId());
        }
        if (obj.getKeyId())
        {
            writer.writePropertyName("keyId");
            writer.writeCharArray(*obj.getKeyId());
        }
        if (obj.getCompleteNotification())
        {
            writer.writePropertyName("completeNotification");
            write(writer, *obj.getCompleteNotification());
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

    static void write(detail::json::JsonWriter& writer, const AcquireAction& obj)
    {
        writer.writeObjectStart();
        if (obj.getAction())
        {
            writer.writePropertyName("action");
            writer.writeCharArray(*obj.getAction());
        }
        if (obj.getRequest())
        {
            writer.writePropertyName("request");
            writer.writeCharArray(*obj.getRequest());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const MissionGroupModelMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getMissionGroupId())
        {
            writer.writePropertyName("missionGroupId");
            writer.writeCharArray(*obj.getMissionGroupId());
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
        if (obj.getCompleteNotificationNamespaceId())
        {
            writer.writePropertyName("completeNotificationNamespaceId");
            writer.writeCharArray(*obj.getCompleteNotificationNamespaceId());
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

    static void write(detail::json::JsonWriter& writer, const MissionGroupModel& obj)
    {
        writer.writeObjectStart();
        if (obj.getMissionGroupId())
        {
            writer.writePropertyName("missionGroupId");
            writer.writeCharArray(*obj.getMissionGroupId());
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
        if (obj.getTasks())
        {
            writer.writePropertyName("tasks");
            writer.writeArrayStart();
            auto& list = *obj.getTasks();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getCompleteNotificationNamespaceId())
        {
            writer.writePropertyName("completeNotificationNamespaceId");
            writer.writeCharArray(*obj.getCompleteNotificationNamespaceId());
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
    explicit Gs2MissionWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
        AbstractGs2ClientBase(gs2WebSocketSession)
    {
    }

	/**
	 * カウンターの種類の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCounterModels(DescribeCounterModelsRequest& request, std::function<void(AsyncDescribeCounterModelsResult&)> callback)
    {
        DescribeCounterModelsTask& task = *new DescribeCounterModelsTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * カウンターの種類を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCounterModel(GetCounterModelRequest& request, std::function<void(AsyncGetCounterModelResult&)> callback)
    {
        GetCounterModelTask& task = *new GetCounterModelTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 達成状況の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCompletes(DescribeCompletesRequest& request, std::function<void(AsyncDescribeCompletesResult&)> callback)
    {
        DescribeCompletesTask& task = *new DescribeCompletesTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザIDを指定して達成状況の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCompletesByUserId(DescribeCompletesByUserIdRequest& request, std::function<void(AsyncDescribeCompletesByUserIdResult&)> callback)
    {
        DescribeCompletesByUserIdTask& task = *new DescribeCompletesByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ミッション達成報酬を受領するためのスタンプシートを発行<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void complete(CompleteRequest& request, std::function<void(AsyncCompleteResult&)> callback)
    {
        CompleteTask& task = *new CompleteTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 達成状況を新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void completeByUserId(CompleteByUserIdRequest& request, std::function<void(AsyncCompleteByUserIdResult&)> callback)
    {
        CompleteByUserIdTask& task = *new CompleteByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ミッション達成報酬を受領する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void receiveByUserId(ReceiveByUserIdRequest& request, std::function<void(AsyncReceiveByUserIdResult&)> callback)
    {
        ReceiveByUserIdTask& task = *new ReceiveByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 達成状況を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getComplete(GetCompleteRequest& request, std::function<void(AsyncGetCompleteResult&)> callback)
    {
        GetCompleteTask& task = *new GetCompleteTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザIDを指定して達成状況を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCompleteByUserId(GetCompleteByUserIdRequest& request, std::function<void(AsyncGetCompleteByUserIdResult&)> callback)
    {
        GetCompleteByUserIdTask& task = *new GetCompleteByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 達成状況を削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteCompleteByUserId(DeleteCompleteByUserIdRequest& request, std::function<void(AsyncDeleteCompleteByUserIdResult&)> callback)
    {
        DeleteCompleteByUserIdTask& task = *new DeleteCompleteByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 達成状況を作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void receiveByStampTask(ReceiveByStampTaskRequest& request, std::function<void(AsyncReceiveByStampTaskResult&)> callback)
    {
        ReceiveByStampTaskTask& task = *new ReceiveByStampTaskTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ミッションタスクの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeMissionTaskModels(DescribeMissionTaskModelsRequest& request, std::function<void(AsyncDescribeMissionTaskModelsResult&)> callback)
    {
        DescribeMissionTaskModelsTask& task = *new DescribeMissionTaskModelsTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ミッションタスクを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMissionTaskModel(GetMissionTaskModelRequest& request, std::function<void(AsyncGetMissionTaskModelResult&)> callback)
    {
        GetMissionTaskModelTask& task = *new GetMissionTaskModelTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ミッションタスクマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeMissionTaskModelMasters(DescribeMissionTaskModelMastersRequest& request, std::function<void(AsyncDescribeMissionTaskModelMastersResult&)> callback)
    {
        DescribeMissionTaskModelMastersTask& task = *new DescribeMissionTaskModelMastersTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ミッションタスクマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createMissionTaskModelMaster(CreateMissionTaskModelMasterRequest& request, std::function<void(AsyncCreateMissionTaskModelMasterResult&)> callback)
    {
        CreateMissionTaskModelMasterTask& task = *new CreateMissionTaskModelMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ミッションタスクマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMissionTaskModelMaster(GetMissionTaskModelMasterRequest& request, std::function<void(AsyncGetMissionTaskModelMasterResult&)> callback)
    {
        GetMissionTaskModelMasterTask& task = *new GetMissionTaskModelMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ミッションタスクマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateMissionTaskModelMaster(UpdateMissionTaskModelMasterRequest& request, std::function<void(AsyncUpdateMissionTaskModelMasterResult&)> callback)
    {
        UpdateMissionTaskModelMasterTask& task = *new UpdateMissionTaskModelMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ミッションタスクマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteMissionTaskModelMaster(DeleteMissionTaskModelMasterRequest& request, std::function<void(AsyncDeleteMissionTaskModelMasterResult&)> callback)
    {
        DeleteMissionTaskModelMasterTask& task = *new DeleteMissionTaskModelMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * カウンターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCounters(DescribeCountersRequest& request, std::function<void(AsyncDescribeCountersResult&)> callback)
    {
        DescribeCountersTask& task = *new DescribeCountersTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザIDを指定してカウンターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCountersByUserId(DescribeCountersByUserIdRequest& request, std::function<void(AsyncDescribeCountersByUserIdResult&)> callback)
    {
        DescribeCountersByUserIdTask& task = *new DescribeCountersByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * カウンターに加算<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void increaseCounterByUserId(IncreaseCounterByUserIdRequest& request, std::function<void(AsyncIncreaseCounterByUserIdResult&)> callback)
    {
        IncreaseCounterByUserIdTask& task = *new IncreaseCounterByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * カウンターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCounter(GetCounterRequest& request, std::function<void(AsyncGetCounterResult&)> callback)
    {
        GetCounterTask& task = *new GetCounterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザIDを指定してカウンターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCounterByUserId(GetCounterByUserIdRequest& request, std::function<void(AsyncGetCounterByUserIdResult&)> callback)
    {
        GetCounterByUserIdTask& task = *new GetCounterByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * カウンターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteCounterByUserId(DeleteCounterByUserIdRequest& request, std::function<void(AsyncDeleteCounterByUserIdResult&)> callback)
    {
        DeleteCounterByUserIdTask& task = *new DeleteCounterByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * カウンター加算<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void increaseByStampSheet(IncreaseByStampSheetRequest& request, std::function<void(AsyncIncreaseByStampSheetResult&)> callback)
    {
        IncreaseByStampSheetTask& task = *new IncreaseByStampSheetTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 現在有効なミッションのマスターデータをエクスポートします<br>
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
	 * 現在有効な現在有効なミッションを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentMissionMaster(GetCurrentMissionMasterRequest& request, std::function<void(AsyncGetCurrentMissionMasterResult&)> callback)
    {
        GetCurrentMissionMasterTask& task = *new GetCurrentMissionMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 現在有効な現在有効なミッションを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentMissionMaster(UpdateCurrentMissionMasterRequest& request, std::function<void(AsyncUpdateCurrentMissionMasterResult&)> callback)
    {
        UpdateCurrentMissionMasterTask& task = *new UpdateCurrentMissionMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 現在有効な現在有効なミッションを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentMissionMasterFromGitHub(UpdateCurrentMissionMasterFromGitHubRequest& request, std::function<void(AsyncUpdateCurrentMissionMasterFromGitHubResult&)> callback)
    {
        UpdateCurrentMissionMasterFromGitHubTask& task = *new UpdateCurrentMissionMasterFromGitHubTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * カウンターの種類マスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCounterModelMasters(DescribeCounterModelMastersRequest& request, std::function<void(AsyncDescribeCounterModelMastersResult&)> callback)
    {
        DescribeCounterModelMastersTask& task = *new DescribeCounterModelMastersTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * カウンターの種類マスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createCounterModelMaster(CreateCounterModelMasterRequest& request, std::function<void(AsyncCreateCounterModelMasterResult&)> callback)
    {
        CreateCounterModelMasterTask& task = *new CreateCounterModelMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * カウンターの種類マスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCounterModelMaster(GetCounterModelMasterRequest& request, std::function<void(AsyncGetCounterModelMasterResult&)> callback)
    {
        GetCounterModelMasterTask& task = *new GetCounterModelMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * カウンターの種類マスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCounterModelMaster(UpdateCounterModelMasterRequest& request, std::function<void(AsyncUpdateCounterModelMasterResult&)> callback)
    {
        UpdateCounterModelMasterTask& task = *new UpdateCounterModelMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * カウンターの種類マスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteCounterModelMaster(DeleteCounterModelMasterRequest& request, std::function<void(AsyncDeleteCounterModelMasterResult&)> callback)
    {
        DeleteCounterModelMasterTask& task = *new DeleteCounterModelMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
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
	 * ミッショングループマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeMissionGroupModelMasters(DescribeMissionGroupModelMastersRequest& request, std::function<void(AsyncDescribeMissionGroupModelMastersResult&)> callback)
    {
        DescribeMissionGroupModelMastersTask& task = *new DescribeMissionGroupModelMastersTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ミッショングループマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createMissionGroupModelMaster(CreateMissionGroupModelMasterRequest& request, std::function<void(AsyncCreateMissionGroupModelMasterResult&)> callback)
    {
        CreateMissionGroupModelMasterTask& task = *new CreateMissionGroupModelMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ミッショングループマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMissionGroupModelMaster(GetMissionGroupModelMasterRequest& request, std::function<void(AsyncGetMissionGroupModelMasterResult&)> callback)
    {
        GetMissionGroupModelMasterTask& task = *new GetMissionGroupModelMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ミッショングループマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateMissionGroupModelMaster(UpdateMissionGroupModelMasterRequest& request, std::function<void(AsyncUpdateMissionGroupModelMasterResult&)> callback)
    {
        UpdateMissionGroupModelMasterTask& task = *new UpdateMissionGroupModelMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ミッショングループマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteMissionGroupModelMaster(DeleteMissionGroupModelMasterRequest& request, std::function<void(AsyncDeleteMissionGroupModelMasterResult&)> callback)
    {
        DeleteMissionGroupModelMasterTask& task = *new DeleteMissionGroupModelMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ミッショングループの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeMissionGroupModels(DescribeMissionGroupModelsRequest& request, std::function<void(AsyncDescribeMissionGroupModelsResult&)> callback)
    {
        DescribeMissionGroupModelsTask& task = *new DescribeMissionGroupModelsTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ミッショングループを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMissionGroupModel(GetMissionGroupModelRequest& request, std::function<void(AsyncGetMissionGroupModelResult&)> callback)
    {
        GetMissionGroupModelTask& task = *new GetMissionGroupModelTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_MISSION_GS2MISSIONWEBSOCKETCLIENT_HPP_