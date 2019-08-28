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

#ifndef GS2_QUEST_GS2QUESTWEBSOCKETCLIENT_HPP_
#define GS2_QUEST_GS2QUESTWEBSOCKETCLIENT_HPP_

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
#include "request/DescribeQuestGroupModelMastersRequest.hpp"
#include "request/CreateQuestGroupModelMasterRequest.hpp"
#include "request/GetQuestGroupModelMasterRequest.hpp"
#include "request/UpdateQuestGroupModelMasterRequest.hpp"
#include "request/DeleteQuestGroupModelMasterRequest.hpp"
#include "request/DescribeQuestModelMastersRequest.hpp"
#include "request/CreateQuestModelMasterRequest.hpp"
#include "request/GetQuestModelMasterRequest.hpp"
#include "request/UpdateQuestModelMasterRequest.hpp"
#include "request/DeleteQuestModelMasterRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentQuestMasterRequest.hpp"
#include "request/UpdateCurrentQuestMasterRequest.hpp"
#include "request/UpdateCurrentQuestMasterFromGitHubRequest.hpp"
#include "request/DescribeProgressesByUserIdRequest.hpp"
#include "request/CreateProgressByUserIdRequest.hpp"
#include "request/GetProgressRequest.hpp"
#include "request/GetProgressByUserIdRequest.hpp"
#include "request/StartRequest.hpp"
#include "request/StartByUserIdRequest.hpp"
#include "request/EndRequest.hpp"
#include "request/EndByUserIdRequest.hpp"
#include "request/DeleteProgressRequest.hpp"
#include "request/DeleteProgressByUserIdRequest.hpp"
#include "request/CreateProgressByStampSheetRequest.hpp"
#include "request/DescribeCompletedQuestListsRequest.hpp"
#include "request/DescribeCompletedQuestListsByUserIdRequest.hpp"
#include "request/GetCompletedQuestListRequest.hpp"
#include "request/GetCompletedQuestListByUserIdRequest.hpp"
#include "request/DeleteCompletedQuestListByUserIdRequest.hpp"
#include "request/DescribeQuestGroupModelsRequest.hpp"
#include "request/GetQuestGroupModelRequest.hpp"
#include "request/DescribeQuestModelsRequest.hpp"
#include "request/GetQuestModelRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeQuestGroupModelMastersResult.hpp"
#include "result/CreateQuestGroupModelMasterResult.hpp"
#include "result/GetQuestGroupModelMasterResult.hpp"
#include "result/UpdateQuestGroupModelMasterResult.hpp"
#include "result/DeleteQuestGroupModelMasterResult.hpp"
#include "result/DescribeQuestModelMastersResult.hpp"
#include "result/CreateQuestModelMasterResult.hpp"
#include "result/GetQuestModelMasterResult.hpp"
#include "result/UpdateQuestModelMasterResult.hpp"
#include "result/DeleteQuestModelMasterResult.hpp"
#include "result/ExportMasterResult.hpp"
#include "result/GetCurrentQuestMasterResult.hpp"
#include "result/UpdateCurrentQuestMasterResult.hpp"
#include "result/UpdateCurrentQuestMasterFromGitHubResult.hpp"
#include "result/DescribeProgressesByUserIdResult.hpp"
#include "result/CreateProgressByUserIdResult.hpp"
#include "result/GetProgressResult.hpp"
#include "result/GetProgressByUserIdResult.hpp"
#include "result/StartResult.hpp"
#include "result/StartByUserIdResult.hpp"
#include "result/EndResult.hpp"
#include "result/EndByUserIdResult.hpp"
#include "result/DeleteProgressResult.hpp"
#include "result/DeleteProgressByUserIdResult.hpp"
#include "result/CreateProgressByStampSheetResult.hpp"
#include "result/DescribeCompletedQuestListsResult.hpp"
#include "result/DescribeCompletedQuestListsByUserIdResult.hpp"
#include "result/GetCompletedQuestListResult.hpp"
#include "result/GetCompletedQuestListByUserIdResult.hpp"
#include "result/DeleteCompletedQuestListByUserIdResult.hpp"
#include "result/DescribeQuestGroupModelsResult.hpp"
#include "result/GetQuestGroupModelResult.hpp"
#include "result/DescribeQuestModelsResult.hpp"
#include "result/GetQuestModelResult.hpp"
#include <cstring>

namespace gs2 { namespace quest {

/**
 * GS2 Quest API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2QuestWebSocketClient : public AbstractGs2ClientBase
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
            writer.writeCharArray("quest");
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
            if (m_Request.getStartQuestTriggerScriptId())
            {
                writer.writePropertyName("startQuestTriggerScriptId");
                writer.writeCharArray(*m_Request.getStartQuestTriggerScriptId());
            }
            if (m_Request.getStartQuestDoneTriggerScriptId())
            {
                writer.writePropertyName("startQuestDoneTriggerScriptId");
                writer.writeCharArray(*m_Request.getStartQuestDoneTriggerScriptId());
            }
            if (m_Request.getStartQuestDoneTriggerQueueNamespaceId())
            {
                writer.writePropertyName("startQuestDoneTriggerQueueNamespaceId");
                writer.writeCharArray(*m_Request.getStartQuestDoneTriggerQueueNamespaceId());
            }
            if (m_Request.getCompleteQuestTriggerScriptId())
            {
                writer.writePropertyName("completeQuestTriggerScriptId");
                writer.writeCharArray(*m_Request.getCompleteQuestTriggerScriptId());
            }
            if (m_Request.getCompleteQuestDoneTriggerScriptId())
            {
                writer.writePropertyName("completeQuestDoneTriggerScriptId");
                writer.writeCharArray(*m_Request.getCompleteQuestDoneTriggerScriptId());
            }
            if (m_Request.getCompleteQuestDoneTriggerQueueNamespaceId())
            {
                writer.writePropertyName("completeQuestDoneTriggerQueueNamespaceId");
                writer.writeCharArray(*m_Request.getCompleteQuestDoneTriggerQueueNamespaceId());
            }
            if (m_Request.getFailedQuestTriggerScriptId())
            {
                writer.writePropertyName("failedQuestTriggerScriptId");
                writer.writeCharArray(*m_Request.getFailedQuestTriggerScriptId());
            }
            if (m_Request.getFailedQuestDoneTriggerScriptId())
            {
                writer.writePropertyName("failedQuestDoneTriggerScriptId");
                writer.writeCharArray(*m_Request.getFailedQuestDoneTriggerScriptId());
            }
            if (m_Request.getFailedQuestDoneTriggerQueueNamespaceId())
            {
                writer.writePropertyName("failedQuestDoneTriggerQueueNamespaceId");
                writer.writeCharArray(*m_Request.getFailedQuestDoneTriggerQueueNamespaceId());
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
            writer.writeCharArray("quest");
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
            writer.writeCharArray("quest");
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
            writer.writeCharArray("quest");
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
            if (m_Request.getStartQuestTriggerScriptId())
            {
                writer.writePropertyName("startQuestTriggerScriptId");
                writer.writeCharArray(*m_Request.getStartQuestTriggerScriptId());
            }
            if (m_Request.getStartQuestDoneTriggerScriptId())
            {
                writer.writePropertyName("startQuestDoneTriggerScriptId");
                writer.writeCharArray(*m_Request.getStartQuestDoneTriggerScriptId());
            }
            if (m_Request.getStartQuestDoneTriggerQueueNamespaceId())
            {
                writer.writePropertyName("startQuestDoneTriggerQueueNamespaceId");
                writer.writeCharArray(*m_Request.getStartQuestDoneTriggerQueueNamespaceId());
            }
            if (m_Request.getCompleteQuestTriggerScriptId())
            {
                writer.writePropertyName("completeQuestTriggerScriptId");
                writer.writeCharArray(*m_Request.getCompleteQuestTriggerScriptId());
            }
            if (m_Request.getCompleteQuestDoneTriggerScriptId())
            {
                writer.writePropertyName("completeQuestDoneTriggerScriptId");
                writer.writeCharArray(*m_Request.getCompleteQuestDoneTriggerScriptId());
            }
            if (m_Request.getCompleteQuestDoneTriggerQueueNamespaceId())
            {
                writer.writePropertyName("completeQuestDoneTriggerQueueNamespaceId");
                writer.writeCharArray(*m_Request.getCompleteQuestDoneTriggerQueueNamespaceId());
            }
            if (m_Request.getFailedQuestTriggerScriptId())
            {
                writer.writePropertyName("failedQuestTriggerScriptId");
                writer.writeCharArray(*m_Request.getFailedQuestTriggerScriptId());
            }
            if (m_Request.getFailedQuestDoneTriggerScriptId())
            {
                writer.writePropertyName("failedQuestDoneTriggerScriptId");
                writer.writeCharArray(*m_Request.getFailedQuestDoneTriggerScriptId());
            }
            if (m_Request.getFailedQuestDoneTriggerQueueNamespaceId())
            {
                writer.writePropertyName("failedQuestDoneTriggerQueueNamespaceId");
                writer.writeCharArray(*m_Request.getFailedQuestDoneTriggerQueueNamespaceId());
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
            writer.writeCharArray("quest");
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
            writer.writeCharArray("quest");
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

    class DescribeQuestGroupModelMastersTask : public detail::Gs2WebSocketSessionTask<DescribeQuestGroupModelMastersResult>
    {
    private:
        DescribeQuestGroupModelMastersRequest& m_Request;

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
            writer.writeCharArray("quest");
            writer.writePropertyName("component");
            writer.writeCharArray("questGroupModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("describeQuestGroupModelMasters");
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
        DescribeQuestGroupModelMastersTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeQuestGroupModelMastersRequest& request,
            Gs2WebSocketSessionTask<DescribeQuestGroupModelMastersResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeQuestGroupModelMastersResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeQuestGroupModelMastersTask() GS2_OVERRIDE = default;
    };

    class CreateQuestGroupModelMasterTask : public detail::Gs2WebSocketSessionTask<CreateQuestGroupModelMasterResult>
    {
    private:
        CreateQuestGroupModelMasterRequest& m_Request;

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
            writer.writeCharArray("quest");
            writer.writePropertyName("component");
            writer.writeCharArray("questGroupModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("createQuestGroupModelMaster");
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
        CreateQuestGroupModelMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            CreateQuestGroupModelMasterRequest& request,
            Gs2WebSocketSessionTask<CreateQuestGroupModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateQuestGroupModelMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~CreateQuestGroupModelMasterTask() GS2_OVERRIDE = default;
    };

    class GetQuestGroupModelMasterTask : public detail::Gs2WebSocketSessionTask<GetQuestGroupModelMasterResult>
    {
    private:
        GetQuestGroupModelMasterRequest& m_Request;

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
            if (m_Request.getQuestGroupName())
            {
                writer.writePropertyName("questGroupName");
                writer.writeCharArray(*m_Request.getQuestGroupName());
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
            writer.writeCharArray("quest");
            writer.writePropertyName("component");
            writer.writeCharArray("questGroupModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("getQuestGroupModelMaster");
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
        GetQuestGroupModelMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetQuestGroupModelMasterRequest& request,
            Gs2WebSocketSessionTask<GetQuestGroupModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetQuestGroupModelMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetQuestGroupModelMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateQuestGroupModelMasterTask : public detail::Gs2WebSocketSessionTask<UpdateQuestGroupModelMasterResult>
    {
    private:
        UpdateQuestGroupModelMasterRequest& m_Request;

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
            if (m_Request.getQuestGroupName())
            {
                writer.writePropertyName("questGroupName");
                writer.writeCharArray(*m_Request.getQuestGroupName());
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
            writer.writeCharArray("quest");
            writer.writePropertyName("component");
            writer.writeCharArray("questGroupModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("updateQuestGroupModelMaster");
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
        UpdateQuestGroupModelMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateQuestGroupModelMasterRequest& request,
            Gs2WebSocketSessionTask<UpdateQuestGroupModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateQuestGroupModelMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateQuestGroupModelMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteQuestGroupModelMasterTask : public detail::Gs2WebSocketSessionTask<DeleteQuestGroupModelMasterResult>
    {
    private:
        DeleteQuestGroupModelMasterRequest& m_Request;

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
            if (m_Request.getQuestGroupName())
            {
                writer.writePropertyName("questGroupName");
                writer.writeCharArray(*m_Request.getQuestGroupName());
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
            writer.writeCharArray("quest");
            writer.writePropertyName("component");
            writer.writeCharArray("questGroupModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteQuestGroupModelMaster");
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
        DeleteQuestGroupModelMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteQuestGroupModelMasterRequest& request,
            Gs2WebSocketSessionTask<DeleteQuestGroupModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteQuestGroupModelMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteQuestGroupModelMasterTask() GS2_OVERRIDE = default;
    };

    class DescribeQuestModelMastersTask : public detail::Gs2WebSocketSessionTask<DescribeQuestModelMastersResult>
    {
    private:
        DescribeQuestModelMastersRequest& m_Request;

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
            if (m_Request.getQuestGroupName())
            {
                writer.writePropertyName("questGroupName");
                writer.writeCharArray(*m_Request.getQuestGroupName());
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
            writer.writeCharArray("quest");
            writer.writePropertyName("component");
            writer.writeCharArray("questModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("describeQuestModelMasters");
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
        DescribeQuestModelMastersTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeQuestModelMastersRequest& request,
            Gs2WebSocketSessionTask<DescribeQuestModelMastersResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeQuestModelMastersResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeQuestModelMastersTask() GS2_OVERRIDE = default;
    };

    class CreateQuestModelMasterTask : public detail::Gs2WebSocketSessionTask<CreateQuestModelMasterResult>
    {
    private:
        CreateQuestModelMasterRequest& m_Request;

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
            if (m_Request.getQuestGroupName())
            {
                writer.writePropertyName("questGroupName");
                writer.writeCharArray(*m_Request.getQuestGroupName());
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
            if (m_Request.getContents())
            {
                writer.writePropertyName("contents");
                writer.writeArrayStart();
                auto& list = *m_Request.getContents();
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
            if (m_Request.getConsumeActions())
            {
                writer.writePropertyName("consumeActions");
                writer.writeArrayStart();
                auto& list = *m_Request.getConsumeActions();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(writer, list[i]);
                }
                writer.writeArrayEnd();
            }
            if (m_Request.getFailedAcquireActions())
            {
                writer.writePropertyName("failedAcquireActions");
                writer.writeArrayStart();
                auto& list = *m_Request.getFailedAcquireActions();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(writer, list[i]);
                }
                writer.writeArrayEnd();
            }
            if (m_Request.getPremiseQuestNames())
            {
                writer.writePropertyName("premiseQuestNames");
                writer.writeArrayStart();
                auto& list = *m_Request.getPremiseQuestNames();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    writer.writeCharArray(list[i]);
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
            writer.writeCharArray("quest");
            writer.writePropertyName("component");
            writer.writeCharArray("questModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("createQuestModelMaster");
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
        CreateQuestModelMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            CreateQuestModelMasterRequest& request,
            Gs2WebSocketSessionTask<CreateQuestModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateQuestModelMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~CreateQuestModelMasterTask() GS2_OVERRIDE = default;
    };

    class GetQuestModelMasterTask : public detail::Gs2WebSocketSessionTask<GetQuestModelMasterResult>
    {
    private:
        GetQuestModelMasterRequest& m_Request;

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
            if (m_Request.getQuestGroupName())
            {
                writer.writePropertyName("questGroupName");
                writer.writeCharArray(*m_Request.getQuestGroupName());
            }
            if (m_Request.getQuestName())
            {
                writer.writePropertyName("questName");
                writer.writeCharArray(*m_Request.getQuestName());
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
            writer.writeCharArray("quest");
            writer.writePropertyName("component");
            writer.writeCharArray("questModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("getQuestModelMaster");
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
        GetQuestModelMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetQuestModelMasterRequest& request,
            Gs2WebSocketSessionTask<GetQuestModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetQuestModelMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetQuestModelMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateQuestModelMasterTask : public detail::Gs2WebSocketSessionTask<UpdateQuestModelMasterResult>
    {
    private:
        UpdateQuestModelMasterRequest& m_Request;

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
            if (m_Request.getQuestGroupName())
            {
                writer.writePropertyName("questGroupName");
                writer.writeCharArray(*m_Request.getQuestGroupName());
            }
            if (m_Request.getQuestName())
            {
                writer.writePropertyName("questName");
                writer.writeCharArray(*m_Request.getQuestName());
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
            if (m_Request.getContents())
            {
                writer.writePropertyName("contents");
                writer.writeArrayStart();
                auto& list = *m_Request.getContents();
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
            if (m_Request.getConsumeActions())
            {
                writer.writePropertyName("consumeActions");
                writer.writeArrayStart();
                auto& list = *m_Request.getConsumeActions();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(writer, list[i]);
                }
                writer.writeArrayEnd();
            }
            if (m_Request.getFailedAcquireActions())
            {
                writer.writePropertyName("failedAcquireActions");
                writer.writeArrayStart();
                auto& list = *m_Request.getFailedAcquireActions();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(writer, list[i]);
                }
                writer.writeArrayEnd();
            }
            if (m_Request.getPremiseQuestNames())
            {
                writer.writePropertyName("premiseQuestNames");
                writer.writeArrayStart();
                auto& list = *m_Request.getPremiseQuestNames();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    writer.writeCharArray(list[i]);
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
            writer.writeCharArray("quest");
            writer.writePropertyName("component");
            writer.writeCharArray("questModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("updateQuestModelMaster");
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
        UpdateQuestModelMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateQuestModelMasterRequest& request,
            Gs2WebSocketSessionTask<UpdateQuestModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateQuestModelMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateQuestModelMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteQuestModelMasterTask : public detail::Gs2WebSocketSessionTask<DeleteQuestModelMasterResult>
    {
    private:
        DeleteQuestModelMasterRequest& m_Request;

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
            if (m_Request.getQuestGroupName())
            {
                writer.writePropertyName("questGroupName");
                writer.writeCharArray(*m_Request.getQuestGroupName());
            }
            if (m_Request.getQuestName())
            {
                writer.writePropertyName("questName");
                writer.writeCharArray(*m_Request.getQuestName());
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
            writer.writeCharArray("quest");
            writer.writePropertyName("component");
            writer.writeCharArray("questModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteQuestModelMaster");
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
        DeleteQuestModelMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteQuestModelMasterRequest& request,
            Gs2WebSocketSessionTask<DeleteQuestModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteQuestModelMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteQuestModelMasterTask() GS2_OVERRIDE = default;
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
            writer.writeCharArray("quest");
            writer.writePropertyName("component");
            writer.writeCharArray("currentQuestMaster");
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

    class GetCurrentQuestMasterTask : public detail::Gs2WebSocketSessionTask<GetCurrentQuestMasterResult>
    {
    private:
        GetCurrentQuestMasterRequest& m_Request;

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
            writer.writeCharArray("quest");
            writer.writePropertyName("component");
            writer.writeCharArray("currentQuestMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("getCurrentQuestMaster");
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
        GetCurrentQuestMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetCurrentQuestMasterRequest& request,
            Gs2WebSocketSessionTask<GetCurrentQuestMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetCurrentQuestMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetCurrentQuestMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentQuestMasterTask : public detail::Gs2WebSocketSessionTask<UpdateCurrentQuestMasterResult>
    {
    private:
        UpdateCurrentQuestMasterRequest& m_Request;

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
            writer.writeCharArray("quest");
            writer.writePropertyName("component");
            writer.writeCharArray("currentQuestMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("updateCurrentQuestMaster");
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
        UpdateCurrentQuestMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateCurrentQuestMasterRequest& request,
            Gs2WebSocketSessionTask<UpdateCurrentQuestMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateCurrentQuestMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateCurrentQuestMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentQuestMasterFromGitHubTask : public detail::Gs2WebSocketSessionTask<UpdateCurrentQuestMasterFromGitHubResult>
    {
    private:
        UpdateCurrentQuestMasterFromGitHubRequest& m_Request;

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
            writer.writeCharArray("quest");
            writer.writePropertyName("component");
            writer.writeCharArray("currentQuestMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("updateCurrentQuestMasterFromGitHub");
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
        UpdateCurrentQuestMasterFromGitHubTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateCurrentQuestMasterFromGitHubRequest& request,
            Gs2WebSocketSessionTask<UpdateCurrentQuestMasterFromGitHubResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateCurrentQuestMasterFromGitHubResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateCurrentQuestMasterFromGitHubTask() GS2_OVERRIDE = default;
    };

    class DescribeProgressesByUserIdTask : public detail::Gs2WebSocketSessionTask<DescribeProgressesByUserIdResult>
    {
    private:
        DescribeProgressesByUserIdRequest& m_Request;

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
            writer.writeCharArray("quest");
            writer.writePropertyName("component");
            writer.writeCharArray("progress");
            writer.writePropertyName("function");
            writer.writeCharArray("describeProgressesByUserId");
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
        DescribeProgressesByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeProgressesByUserIdRequest& request,
            Gs2WebSocketSessionTask<DescribeProgressesByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeProgressesByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeProgressesByUserIdTask() GS2_OVERRIDE = default;
    };

    class CreateProgressByUserIdTask : public detail::Gs2WebSocketSessionTask<CreateProgressByUserIdResult>
    {
    private:
        CreateProgressByUserIdRequest& m_Request;

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
            if (m_Request.getQuestModelId())
            {
                writer.writePropertyName("questModelId");
                writer.writeCharArray(*m_Request.getQuestModelId());
            }
            if (m_Request.getForce())
            {
                writer.writePropertyName("force");
                writer.writeBool(*m_Request.getForce());
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
            writer.writeCharArray("quest");
            writer.writePropertyName("component");
            writer.writeCharArray("progress");
            writer.writePropertyName("function");
            writer.writeCharArray("createProgressByUserId");
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
        CreateProgressByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            CreateProgressByUserIdRequest& request,
            Gs2WebSocketSessionTask<CreateProgressByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateProgressByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~CreateProgressByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetProgressTask : public detail::Gs2WebSocketSessionTask<GetProgressResult>
    {
    private:
        GetProgressRequest& m_Request;

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
            writer.writeCharArray("quest");
            writer.writePropertyName("component");
            writer.writeCharArray("progress");
            writer.writePropertyName("function");
            writer.writeCharArray("getProgress");
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
        GetProgressTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetProgressRequest& request,
            Gs2WebSocketSessionTask<GetProgressResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetProgressResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetProgressTask() GS2_OVERRIDE = default;
    };

    class GetProgressByUserIdTask : public detail::Gs2WebSocketSessionTask<GetProgressByUserIdResult>
    {
    private:
        GetProgressByUserIdRequest& m_Request;

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
            writer.writeCharArray("quest");
            writer.writePropertyName("component");
            writer.writeCharArray("progress");
            writer.writePropertyName("function");
            writer.writeCharArray("getProgressByUserId");
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
        GetProgressByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetProgressByUserIdRequest& request,
            Gs2WebSocketSessionTask<GetProgressByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetProgressByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetProgressByUserIdTask() GS2_OVERRIDE = default;
    };

    class StartTask : public detail::Gs2WebSocketSessionTask<StartResult>
    {
    private:
        StartRequest& m_Request;

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
            if (m_Request.getQuestGroupName())
            {
                writer.writePropertyName("questGroupName");
                writer.writeCharArray(*m_Request.getQuestGroupName());
            }
            if (m_Request.getQuestName())
            {
                writer.writePropertyName("questName");
                writer.writeCharArray(*m_Request.getQuestName());
            }
            if (m_Request.getForce())
            {
                writer.writePropertyName("force");
                writer.writeBool(*m_Request.getForce());
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
            writer.writeCharArray("quest");
            writer.writePropertyName("component");
            writer.writeCharArray("progress");
            writer.writePropertyName("function");
            writer.writeCharArray("start");
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
        StartTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            StartRequest& request,
            Gs2WebSocketSessionTask<StartResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<StartResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~StartTask() GS2_OVERRIDE = default;
    };

    class StartByUserIdTask : public detail::Gs2WebSocketSessionTask<StartByUserIdResult>
    {
    private:
        StartByUserIdRequest& m_Request;

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
            if (m_Request.getQuestGroupName())
            {
                writer.writePropertyName("questGroupName");
                writer.writeCharArray(*m_Request.getQuestGroupName());
            }
            if (m_Request.getQuestName())
            {
                writer.writePropertyName("questName");
                writer.writeCharArray(*m_Request.getQuestName());
            }
            if (m_Request.getUserId())
            {
                writer.writePropertyName("userId");
                writer.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getForce())
            {
                writer.writePropertyName("force");
                writer.writeBool(*m_Request.getForce());
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
            writer.writeCharArray("quest");
            writer.writePropertyName("component");
            writer.writeCharArray("progress");
            writer.writePropertyName("function");
            writer.writeCharArray("startByUserId");
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
        StartByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            StartByUserIdRequest& request,
            Gs2WebSocketSessionTask<StartByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<StartByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~StartByUserIdTask() GS2_OVERRIDE = default;
    };

    class EndTask : public detail::Gs2WebSocketSessionTask<EndResult>
    {
    private:
        EndRequest& m_Request;

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
            if (m_Request.getTransactionId())
            {
                writer.writePropertyName("transactionId");
                writer.writeCharArray(*m_Request.getTransactionId());
            }
            if (m_Request.getRewards())
            {
                writer.writePropertyName("rewards");
                writer.writeArrayStart();
                auto& list = *m_Request.getRewards();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(writer, list[i]);
                }
                writer.writeArrayEnd();
            }
            if (m_Request.getIsComplete())
            {
                writer.writePropertyName("isComplete");
                writer.writeBool(*m_Request.getIsComplete());
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
            writer.writeCharArray("quest");
            writer.writePropertyName("component");
            writer.writeCharArray("progress");
            writer.writePropertyName("function");
            writer.writeCharArray("end");
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
        EndTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            EndRequest& request,
            Gs2WebSocketSessionTask<EndResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<EndResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~EndTask() GS2_OVERRIDE = default;
    };

    class EndByUserIdTask : public detail::Gs2WebSocketSessionTask<EndByUserIdResult>
    {
    private:
        EndByUserIdRequest& m_Request;

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
            if (m_Request.getTransactionId())
            {
                writer.writePropertyName("transactionId");
                writer.writeCharArray(*m_Request.getTransactionId());
            }
            if (m_Request.getRewards())
            {
                writer.writePropertyName("rewards");
                writer.writeArrayStart();
                auto& list = *m_Request.getRewards();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(writer, list[i]);
                }
                writer.writeArrayEnd();
            }
            if (m_Request.getIsComplete())
            {
                writer.writePropertyName("isComplete");
                writer.writeBool(*m_Request.getIsComplete());
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
            writer.writeCharArray("quest");
            writer.writePropertyName("component");
            writer.writeCharArray("progress");
            writer.writePropertyName("function");
            writer.writeCharArray("endByUserId");
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
        EndByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            EndByUserIdRequest& request,
            Gs2WebSocketSessionTask<EndByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<EndByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~EndByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteProgressTask : public detail::Gs2WebSocketSessionTask<DeleteProgressResult>
    {
    private:
        DeleteProgressRequest& m_Request;

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
            writer.writeCharArray("quest");
            writer.writePropertyName("component");
            writer.writeCharArray("progress");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteProgress");
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
        DeleteProgressTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteProgressRequest& request,
            Gs2WebSocketSessionTask<DeleteProgressResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteProgressResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteProgressTask() GS2_OVERRIDE = default;
    };

    class DeleteProgressByUserIdTask : public detail::Gs2WebSocketSessionTask<DeleteProgressByUserIdResult>
    {
    private:
        DeleteProgressByUserIdRequest& m_Request;

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
            writer.writeCharArray("quest");
            writer.writePropertyName("component");
            writer.writeCharArray("progress");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteProgressByUserId");
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
        DeleteProgressByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteProgressByUserIdRequest& request,
            Gs2WebSocketSessionTask<DeleteProgressByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteProgressByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteProgressByUserIdTask() GS2_OVERRIDE = default;
    };

    class CreateProgressByStampSheetTask : public detail::Gs2WebSocketSessionTask<CreateProgressByStampSheetResult>
    {
    private:
        CreateProgressByStampSheetRequest& m_Request;

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
            writer.writeCharArray("quest");
            writer.writePropertyName("component");
            writer.writeCharArray("progress");
            writer.writePropertyName("function");
            writer.writeCharArray("createProgressByStampSheet");
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
        CreateProgressByStampSheetTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            CreateProgressByStampSheetRequest& request,
            Gs2WebSocketSessionTask<CreateProgressByStampSheetResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateProgressByStampSheetResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~CreateProgressByStampSheetTask() GS2_OVERRIDE = default;
    };

    class DescribeCompletedQuestListsTask : public detail::Gs2WebSocketSessionTask<DescribeCompletedQuestListsResult>
    {
    private:
        DescribeCompletedQuestListsRequest& m_Request;

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
            writer.writeCharArray("quest");
            writer.writePropertyName("component");
            writer.writeCharArray("completedQuestList");
            writer.writePropertyName("function");
            writer.writeCharArray("describeCompletedQuestLists");
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
        DescribeCompletedQuestListsTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeCompletedQuestListsRequest& request,
            Gs2WebSocketSessionTask<DescribeCompletedQuestListsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeCompletedQuestListsResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeCompletedQuestListsTask() GS2_OVERRIDE = default;
    };

    class DescribeCompletedQuestListsByUserIdTask : public detail::Gs2WebSocketSessionTask<DescribeCompletedQuestListsByUserIdResult>
    {
    private:
        DescribeCompletedQuestListsByUserIdRequest& m_Request;

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
            writer.writeCharArray("quest");
            writer.writePropertyName("component");
            writer.writeCharArray("completedQuestList");
            writer.writePropertyName("function");
            writer.writeCharArray("describeCompletedQuestListsByUserId");
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
        DescribeCompletedQuestListsByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeCompletedQuestListsByUserIdRequest& request,
            Gs2WebSocketSessionTask<DescribeCompletedQuestListsByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeCompletedQuestListsByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeCompletedQuestListsByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetCompletedQuestListTask : public detail::Gs2WebSocketSessionTask<GetCompletedQuestListResult>
    {
    private:
        GetCompletedQuestListRequest& m_Request;

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
            if (m_Request.getQuestGroupName())
            {
                writer.writePropertyName("questGroupName");
                writer.writeCharArray(*m_Request.getQuestGroupName());
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
            writer.writeCharArray("quest");
            writer.writePropertyName("component");
            writer.writeCharArray("completedQuestList");
            writer.writePropertyName("function");
            writer.writeCharArray("getCompletedQuestList");
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
        GetCompletedQuestListTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetCompletedQuestListRequest& request,
            Gs2WebSocketSessionTask<GetCompletedQuestListResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetCompletedQuestListResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetCompletedQuestListTask() GS2_OVERRIDE = default;
    };

    class GetCompletedQuestListByUserIdTask : public detail::Gs2WebSocketSessionTask<GetCompletedQuestListByUserIdResult>
    {
    private:
        GetCompletedQuestListByUserIdRequest& m_Request;

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
            if (m_Request.getQuestGroupName())
            {
                writer.writePropertyName("questGroupName");
                writer.writeCharArray(*m_Request.getQuestGroupName());
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
            writer.writeCharArray("quest");
            writer.writePropertyName("component");
            writer.writeCharArray("completedQuestList");
            writer.writePropertyName("function");
            writer.writeCharArray("getCompletedQuestListByUserId");
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
        GetCompletedQuestListByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetCompletedQuestListByUserIdRequest& request,
            Gs2WebSocketSessionTask<GetCompletedQuestListByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetCompletedQuestListByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetCompletedQuestListByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteCompletedQuestListByUserIdTask : public detail::Gs2WebSocketSessionTask<DeleteCompletedQuestListByUserIdResult>
    {
    private:
        DeleteCompletedQuestListByUserIdRequest& m_Request;

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
            if (m_Request.getQuestGroupName())
            {
                writer.writePropertyName("questGroupName");
                writer.writeCharArray(*m_Request.getQuestGroupName());
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
            writer.writeCharArray("quest");
            writer.writePropertyName("component");
            writer.writeCharArray("completedQuestList");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteCompletedQuestListByUserId");
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
        DeleteCompletedQuestListByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteCompletedQuestListByUserIdRequest& request,
            Gs2WebSocketSessionTask<DeleteCompletedQuestListByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteCompletedQuestListByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteCompletedQuestListByUserIdTask() GS2_OVERRIDE = default;
    };

    class DescribeQuestGroupModelsTask : public detail::Gs2WebSocketSessionTask<DescribeQuestGroupModelsResult>
    {
    private:
        DescribeQuestGroupModelsRequest& m_Request;

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
            writer.writeCharArray("quest");
            writer.writePropertyName("component");
            writer.writeCharArray("questGroupModel");
            writer.writePropertyName("function");
            writer.writeCharArray("describeQuestGroupModels");
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
        DescribeQuestGroupModelsTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeQuestGroupModelsRequest& request,
            Gs2WebSocketSessionTask<DescribeQuestGroupModelsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeQuestGroupModelsResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeQuestGroupModelsTask() GS2_OVERRIDE = default;
    };

    class GetQuestGroupModelTask : public detail::Gs2WebSocketSessionTask<GetQuestGroupModelResult>
    {
    private:
        GetQuestGroupModelRequest& m_Request;

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
            if (m_Request.getQuestGroupName())
            {
                writer.writePropertyName("questGroupName");
                writer.writeCharArray(*m_Request.getQuestGroupName());
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
            writer.writeCharArray("quest");
            writer.writePropertyName("component");
            writer.writeCharArray("questGroupModel");
            writer.writePropertyName("function");
            writer.writeCharArray("getQuestGroupModel");
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
        GetQuestGroupModelTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetQuestGroupModelRequest& request,
            Gs2WebSocketSessionTask<GetQuestGroupModelResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetQuestGroupModelResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetQuestGroupModelTask() GS2_OVERRIDE = default;
    };

    class DescribeQuestModelsTask : public detail::Gs2WebSocketSessionTask<DescribeQuestModelsResult>
    {
    private:
        DescribeQuestModelsRequest& m_Request;

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
            if (m_Request.getQuestGroupName())
            {
                writer.writePropertyName("questGroupName");
                writer.writeCharArray(*m_Request.getQuestGroupName());
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
            writer.writeCharArray("quest");
            writer.writePropertyName("component");
            writer.writeCharArray("questModel");
            writer.writePropertyName("function");
            writer.writeCharArray("describeQuestModels");
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
        DescribeQuestModelsTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeQuestModelsRequest& request,
            Gs2WebSocketSessionTask<DescribeQuestModelsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeQuestModelsResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeQuestModelsTask() GS2_OVERRIDE = default;
    };

    class GetQuestModelTask : public detail::Gs2WebSocketSessionTask<GetQuestModelResult>
    {
    private:
        GetQuestModelRequest& m_Request;

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
            if (m_Request.getQuestGroupName())
            {
                writer.writePropertyName("questGroupName");
                writer.writeCharArray(*m_Request.getQuestGroupName());
            }
            if (m_Request.getQuestName())
            {
                writer.writePropertyName("questName");
                writer.writeCharArray(*m_Request.getQuestName());
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
            writer.writeCharArray("quest");
            writer.writePropertyName("component");
            writer.writeCharArray("questModel");
            writer.writePropertyName("function");
            writer.writeCharArray("getQuestModel");
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
        GetQuestModelTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetQuestModelRequest& request,
            Gs2WebSocketSessionTask<GetQuestModelResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetQuestModelResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetQuestModelTask() GS2_OVERRIDE = default;
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
        if (obj.getStartQuestTriggerScriptId())
        {
            writer.writePropertyName("startQuestTriggerScriptId");
            writer.writeCharArray(*obj.getStartQuestTriggerScriptId());
        }
        if (obj.getStartQuestDoneTriggerScriptId())
        {
            writer.writePropertyName("startQuestDoneTriggerScriptId");
            writer.writeCharArray(*obj.getStartQuestDoneTriggerScriptId());
        }
        if (obj.getStartQuestDoneTriggerQueueNamespaceId())
        {
            writer.writePropertyName("startQuestDoneTriggerQueueNamespaceId");
            writer.writeCharArray(*obj.getStartQuestDoneTriggerQueueNamespaceId());
        }
        if (obj.getCompleteQuestTriggerScriptId())
        {
            writer.writePropertyName("completeQuestTriggerScriptId");
            writer.writeCharArray(*obj.getCompleteQuestTriggerScriptId());
        }
        if (obj.getCompleteQuestDoneTriggerScriptId())
        {
            writer.writePropertyName("completeQuestDoneTriggerScriptId");
            writer.writeCharArray(*obj.getCompleteQuestDoneTriggerScriptId());
        }
        if (obj.getCompleteQuestDoneTriggerQueueNamespaceId())
        {
            writer.writePropertyName("completeQuestDoneTriggerQueueNamespaceId");
            writer.writeCharArray(*obj.getCompleteQuestDoneTriggerQueueNamespaceId());
        }
        if (obj.getFailedQuestTriggerScriptId())
        {
            writer.writePropertyName("failedQuestTriggerScriptId");
            writer.writeCharArray(*obj.getFailedQuestTriggerScriptId());
        }
        if (obj.getFailedQuestDoneTriggerScriptId())
        {
            writer.writePropertyName("failedQuestDoneTriggerScriptId");
            writer.writeCharArray(*obj.getFailedQuestDoneTriggerScriptId());
        }
        if (obj.getFailedQuestDoneTriggerQueueNamespaceId())
        {
            writer.writePropertyName("failedQuestDoneTriggerQueueNamespaceId");
            writer.writeCharArray(*obj.getFailedQuestDoneTriggerQueueNamespaceId());
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

    static void write(detail::json::JsonWriter& writer, const QuestGroupModelMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getQuestGroupModelId())
        {
            writer.writePropertyName("questGroupModelId");
            writer.writeCharArray(*obj.getQuestGroupModelId());
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

    static void write(detail::json::JsonWriter& writer, const QuestModelMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getQuestModelId())
        {
            writer.writePropertyName("questModelId");
            writer.writeCharArray(*obj.getQuestModelId());
        }
        if (obj.getQuestGroupName())
        {
            writer.writePropertyName("questGroupName");
            writer.writeCharArray(*obj.getQuestGroupName());
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
        if (obj.getContents())
        {
            writer.writePropertyName("contents");
            writer.writeArrayStart();
            auto& list = *obj.getContents();
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
        if (obj.getConsumeActions())
        {
            writer.writePropertyName("consumeActions");
            writer.writeArrayStart();
            auto& list = *obj.getConsumeActions();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getFailedAcquireActions())
        {
            writer.writePropertyName("failedAcquireActions");
            writer.writeArrayStart();
            auto& list = *obj.getFailedAcquireActions();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getPremiseQuestNames())
        {
            writer.writePropertyName("premiseQuestNames");
            writer.writeArrayStart();
            auto& list = *obj.getPremiseQuestNames();
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

    static void write(detail::json::JsonWriter& writer, const CurrentQuestMaster& obj)
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

    static void write(detail::json::JsonWriter& writer, const Contents& obj)
    {
        writer.writeObjectStart();
        if (obj.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.writeCharArray(*obj.getMetadata());
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
        if (obj.getWeight())
        {
            writer.writePropertyName("weight");
            writer.writeInt32(*obj.getWeight());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const ConsumeAction& obj)
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

    static void write(detail::json::JsonWriter& writer, const Reward& obj)
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
        if (obj.getItemId())
        {
            writer.writePropertyName("itemId");
            writer.writeCharArray(*obj.getItemId());
        }
        if (obj.getValue())
        {
            writer.writePropertyName("value");
            writer.writeInt32(*obj.getValue());
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

    static void write(detail::json::JsonWriter& writer, const Progress& obj)
    {
        writer.writeObjectStart();
        if (obj.getProgressId())
        {
            writer.writePropertyName("progressId");
            writer.writeCharArray(*obj.getProgressId());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.writeCharArray(*obj.getUserId());
        }
        if (obj.getTransactionId())
        {
            writer.writePropertyName("transactionId");
            writer.writeCharArray(*obj.getTransactionId());
        }
        if (obj.getQuestModelId())
        {
            writer.writePropertyName("questModelId");
            writer.writeCharArray(*obj.getQuestModelId());
        }
        if (obj.getRandomSeed())
        {
            writer.writePropertyName("randomSeed");
            writer.writeInt64(*obj.getRandomSeed());
        }
        if (obj.getRewards())
        {
            writer.writePropertyName("rewards");
            writer.writeArrayStart();
            auto& list = *obj.getRewards();
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

    static void write(detail::json::JsonWriter& writer, const CompletedQuestList& obj)
    {
        writer.writeObjectStart();
        if (obj.getCompletedQuestListId())
        {
            writer.writePropertyName("completedQuestListId");
            writer.writeCharArray(*obj.getCompletedQuestListId());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.writeCharArray(*obj.getUserId());
        }
        if (obj.getQuestGroupName())
        {
            writer.writePropertyName("questGroupName");
            writer.writeCharArray(*obj.getQuestGroupName());
        }
        if (obj.getCompleteQuestNames())
        {
            writer.writePropertyName("completeQuestNames");
            writer.writeArrayStart();
            auto& list = *obj.getCompleteQuestNames();
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

    static void write(detail::json::JsonWriter& writer, const QuestGroupModel& obj)
    {
        writer.writeObjectStart();
        if (obj.getQuestGroupModelId())
        {
            writer.writePropertyName("questGroupModelId");
            writer.writeCharArray(*obj.getQuestGroupModelId());
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
        if (obj.getQuests())
        {
            writer.writePropertyName("quests");
            writer.writeArrayStart();
            auto& list = *obj.getQuests();
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

    static void write(detail::json::JsonWriter& writer, const QuestModel& obj)
    {
        writer.writeObjectStart();
        if (obj.getQuestModelId())
        {
            writer.writePropertyName("questModelId");
            writer.writeCharArray(*obj.getQuestModelId());
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
        if (obj.getContents())
        {
            writer.writePropertyName("contents");
            writer.writeArrayStart();
            auto& list = *obj.getContents();
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
        if (obj.getConsumeActions())
        {
            writer.writePropertyName("consumeActions");
            writer.writeArrayStart();
            auto& list = *obj.getConsumeActions();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getFailedAcquireActions())
        {
            writer.writePropertyName("failedAcquireActions");
            writer.writeArrayStart();
            auto& list = *obj.getFailedAcquireActions();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getPremiseQuestNames())
        {
            writer.writePropertyName("premiseQuestNames");
            writer.writeArrayStart();
            auto& list = *obj.getPremiseQuestNames();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                writer.writeCharArray(list[i]);
            }
            writer.writeArrayEnd();
        }
        writer.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param gs2WebSocketSession WebSocket API 用セッション
     */
    explicit Gs2QuestWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
        AbstractGs2ClientBase(gs2WebSocketSession)
    {
    }

	/**
	 * クエストを分類するカテゴリーの一覧を取得<br>
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
	 * クエストを分類するカテゴリーを新規作成<br>
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
	 * クエストを分類するカテゴリーの状態を取得<br>
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
	 * クエストを分類するカテゴリーを取得<br>
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
	 * クエストを分類するカテゴリーを更新<br>
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
	 * クエストを分類するカテゴリーを削除<br>
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
	 * クエストグループマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeQuestGroupModelMasters(DescribeQuestGroupModelMastersRequest& request, std::function<void(AsyncDescribeQuestGroupModelMastersResult&)> callback)
    {
        DescribeQuestGroupModelMastersTask& task = *new DescribeQuestGroupModelMastersTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * クエストグループマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createQuestGroupModelMaster(CreateQuestGroupModelMasterRequest& request, std::function<void(AsyncCreateQuestGroupModelMasterResult&)> callback)
    {
        CreateQuestGroupModelMasterTask& task = *new CreateQuestGroupModelMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * クエストグループマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getQuestGroupModelMaster(GetQuestGroupModelMasterRequest& request, std::function<void(AsyncGetQuestGroupModelMasterResult&)> callback)
    {
        GetQuestGroupModelMasterTask& task = *new GetQuestGroupModelMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * クエストグループマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateQuestGroupModelMaster(UpdateQuestGroupModelMasterRequest& request, std::function<void(AsyncUpdateQuestGroupModelMasterResult&)> callback)
    {
        UpdateQuestGroupModelMasterTask& task = *new UpdateQuestGroupModelMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * クエストグループマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteQuestGroupModelMaster(DeleteQuestGroupModelMasterRequest& request, std::function<void(AsyncDeleteQuestGroupModelMasterResult&)> callback)
    {
        DeleteQuestGroupModelMasterTask& task = *new DeleteQuestGroupModelMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * クエストモデルマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeQuestModelMasters(DescribeQuestModelMastersRequest& request, std::function<void(AsyncDescribeQuestModelMastersResult&)> callback)
    {
        DescribeQuestModelMastersTask& task = *new DescribeQuestModelMastersTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * クエストモデルマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createQuestModelMaster(CreateQuestModelMasterRequest& request, std::function<void(AsyncCreateQuestModelMasterResult&)> callback)
    {
        CreateQuestModelMasterTask& task = *new CreateQuestModelMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * クエストモデルマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getQuestModelMaster(GetQuestModelMasterRequest& request, std::function<void(AsyncGetQuestModelMasterResult&)> callback)
    {
        GetQuestModelMasterTask& task = *new GetQuestModelMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * クエストモデルマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateQuestModelMaster(UpdateQuestModelMasterRequest& request, std::function<void(AsyncUpdateQuestModelMasterResult&)> callback)
    {
        UpdateQuestModelMasterTask& task = *new UpdateQuestModelMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * クエストモデルマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteQuestModelMaster(DeleteQuestModelMasterRequest& request, std::function<void(AsyncDeleteQuestModelMasterResult&)> callback)
    {
        DeleteQuestModelMasterTask& task = *new DeleteQuestModelMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 現在有効なクエストマスターのマスターデータをエクスポートします<br>
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
	 * 現在有効な現在有効なクエストマスターを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentQuestMaster(GetCurrentQuestMasterRequest& request, std::function<void(AsyncGetCurrentQuestMasterResult&)> callback)
    {
        GetCurrentQuestMasterTask& task = *new GetCurrentQuestMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 現在有効な現在有効なクエストマスターを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentQuestMaster(UpdateCurrentQuestMasterRequest& request, std::function<void(AsyncUpdateCurrentQuestMasterResult&)> callback)
    {
        UpdateCurrentQuestMasterTask& task = *new UpdateCurrentQuestMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 現在有効な現在有効なクエストマスターを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentQuestMasterFromGitHub(UpdateCurrentQuestMasterFromGitHubRequest& request, std::function<void(AsyncUpdateCurrentQuestMasterFromGitHubResult&)> callback)
    {
        UpdateCurrentQuestMasterFromGitHubTask& task = *new UpdateCurrentQuestMasterFromGitHubTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * クエスト挑戦の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeProgressesByUserId(DescribeProgressesByUserIdRequest& request, std::function<void(AsyncDescribeProgressesByUserIdResult&)> callback)
    {
        DescribeProgressesByUserIdTask& task = *new DescribeProgressesByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザIDを指定してクエスト挑戦を作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createProgressByUserId(CreateProgressByUserIdRequest& request, std::function<void(AsyncCreateProgressByUserIdResult&)> callback)
    {
        CreateProgressByUserIdTask& task = *new CreateProgressByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * クエスト挑戦を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getProgress(GetProgressRequest& request, std::function<void(AsyncGetProgressResult&)> callback)
    {
        GetProgressTask& task = *new GetProgressTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザIDを指定してクエスト挑戦を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getProgressByUserId(GetProgressByUserIdRequest& request, std::function<void(AsyncGetProgressByUserIdResult&)> callback)
    {
        GetProgressByUserIdTask& task = *new GetProgressByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * クエストを開始<br>
	 *   <br>
	 *   同一カテゴリ内でゲームプレイヤーは同時に1つのクエストを実行できます。<br>
	 *   すでに同一カテゴリ内で実行中のクエストがある場合、このAPIはエラーを返します。<br>
	 *   進行中のクエストを取得するAPIを呼び出すことで、クエストを再開するために必要な情報を得ることができます。<br>
	 *   強制的にクエストを開始するには force パラメータに true を指定することで強制的にクエストを開始できます。<br>
	 *   <br>
	 *   クエストが正常に開始できた場合、Progress オブジェクトを応答します。<br>
	 *   Progress オブジェクトはクエストを実行するために必要ないくつかの情報を応答します。<br>
	 *   <br>
	 *   transactionId は実行中のクエスト固有のIDです。<br>
	 *   クエストの完了報告にはこのIDを指定する必要があります。<br>
	 *   <br>
	 *   randomSeed はクエストの内容を決定するために使用できる乱数シードです。<br>
	 *   クエストを開始するたびに異なる乱数が払い出されますので、この値をシード値としてゲームを進行させることで<br>
	 *   クエスト中にアプリケーションを強制終了したとしても同一条件で再開することができます。<br>
	 *   <br>
	 *   rewards にはこのクエストにおいて入手可能な報酬とその数量の"最大値"が得られます。<br>
	 *   クエストの完了報告にも rewards を渡すことができ、そこでクエスト中に実際に入手したアイテムの数量を指定します。<br>
	 *   詳細はクエストの完了報告APIのドキュメントを参照してください。<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void start(StartRequest& request, std::function<void(AsyncStartResult&)> callback)
    {
        StartTask& task = *new StartTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザIDを指定してクエストを開始<br>
	 *   <br>
	 *   同一カテゴリ内でゲームプレイヤーは同時に1つのクエストを実行できます。<br>
	 *   すでに同一カテゴリ内で実行中のクエストがある場合、このAPIはエラーを返します。<br>
	 *   進行中のクエストを取得するAPIを呼び出すことで、クエストを再開するために必要な情報を得ることができます。<br>
	 *   強制的にクエストを開始するには force パラメータに true を指定することで強制的にクエストを開始できます。<br>
	 *   <br>
	 *   クエストが正常に開始できた場合、Progress オブジェクトを応答します。<br>
	 *   Progress オブジェクトはクエストを実行するために必要ないくつかの情報を応答します。<br>
	 *   <br>
	 *   transactionId は実行中のクエスト固有のIDです。<br>
	 *   クエストの完了報告にはこのIDを指定する必要があります。<br>
	 *   <br>
	 *   randomSeed はクエストの内容を決定するために使用できる乱数シードです。<br>
	 *   クエストを開®®始するたびに異なる乱数が払い出されますので、この値をシード値としてゲームを進行させることで<br>
	 *   クエスト中にアプリケーションを強制終了したとしても同一条件で再開することができます。<br>
	 *   <br>
	 *   rewards にはこのクエストにおいて入手可能な報酬とその数量の"最大値"が得られます。<br>
	 *   クエストの完了報告にも rewards を渡すことができ、そこでクエスト中に実際に入手したアイテムの数量を指定します。<br>
	 *   詳細はクエストの完了報告APIのドキュメントを参照してください。<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void startByUserId(StartByUserIdRequest& request, std::function<void(AsyncStartByUserIdResult&)> callback)
    {
        StartByUserIdTask& task = *new StartByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * クエストを完了<br>
	 *   <br>
	 *   開始時に受け取ったクエストにおいて入手可能な報酬とその数量の"最大値"のうち、クエスト内で実際に入手した報酬を rewards で報告します。<br>
	 *   isComplete にはクエストをクリアできたかを報告します。クエストに失敗した場合、rewards の値は無視してクエストに設定された失敗した場合の報酬が付与されます。<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void end(EndRequest& request, std::function<void(AsyncEndResult&)> callback)
    {
        EndTask& task = *new EndTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザIDを指定してクエストを完了<br>
	 *   <br>
	 *   開始時に受け取ったクエストにおいて入手可能な報酬とその数量の"最大値"のうち、クエスト内で実際に入手した報酬を rewards で報告します。<br>
	 *   isComplete にはクエストをクリアできたかを報告します。クエストに失敗した場合、rewards の値は無視してクエストに設定された失敗した場合の報酬が付与されます。<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void endByUserId(EndByUserIdRequest& request, std::function<void(AsyncEndByUserIdResult&)> callback)
    {
        EndByUserIdTask& task = *new EndByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * クエスト挑戦を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteProgress(DeleteProgressRequest& request, std::function<void(AsyncDeleteProgressResult&)> callback)
    {
        DeleteProgressTask& task = *new DeleteProgressTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザIDを指定してクエスト挑戦を削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteProgressByUserId(DeleteProgressByUserIdRequest& request, std::function<void(AsyncDeleteProgressByUserIdResult&)> callback)
    {
        DeleteProgressByUserIdTask& task = *new DeleteProgressByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * スタンプシートでクエストを開始<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createProgressByStampSheet(CreateProgressByStampSheetRequest& request, std::function<void(AsyncCreateProgressByStampSheetResult&)> callback)
    {
        CreateProgressByStampSheetTask& task = *new CreateProgressByStampSheetTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * クエスト進行の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCompletedQuestLists(DescribeCompletedQuestListsRequest& request, std::function<void(AsyncDescribeCompletedQuestListsResult&)> callback)
    {
        DescribeCompletedQuestListsTask& task = *new DescribeCompletedQuestListsTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザIDを指定してクエスト進行の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCompletedQuestListsByUserId(DescribeCompletedQuestListsByUserIdRequest& request, std::function<void(AsyncDescribeCompletedQuestListsByUserIdResult&)> callback)
    {
        DescribeCompletedQuestListsByUserIdTask& task = *new DescribeCompletedQuestListsByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * クエスト進行を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCompletedQuestList(GetCompletedQuestListRequest& request, std::function<void(AsyncGetCompletedQuestListResult&)> callback)
    {
        GetCompletedQuestListTask& task = *new GetCompletedQuestListTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザIDを指定してクエスト進行を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCompletedQuestListByUserId(GetCompletedQuestListByUserIdRequest& request, std::function<void(AsyncGetCompletedQuestListByUserIdResult&)> callback)
    {
        GetCompletedQuestListByUserIdTask& task = *new GetCompletedQuestListByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザIDを指定してクエスト進行を削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteCompletedQuestListByUserId(DeleteCompletedQuestListByUserIdRequest& request, std::function<void(AsyncDeleteCompletedQuestListByUserIdResult&)> callback)
    {
        DeleteCompletedQuestListByUserIdTask& task = *new DeleteCompletedQuestListByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * クエストグループの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeQuestGroupModels(DescribeQuestGroupModelsRequest& request, std::function<void(AsyncDescribeQuestGroupModelsResult&)> callback)
    {
        DescribeQuestGroupModelsTask& task = *new DescribeQuestGroupModelsTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * クエストグループを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getQuestGroupModel(GetQuestGroupModelRequest& request, std::function<void(AsyncGetQuestGroupModelResult&)> callback)
    {
        GetQuestGroupModelTask& task = *new GetQuestGroupModelTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * クエストモデルの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeQuestModels(DescribeQuestModelsRequest& request, std::function<void(AsyncDescribeQuestModelsResult&)> callback)
    {
        DescribeQuestModelsTask& task = *new DescribeQuestModelsTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * クエストモデルを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getQuestModel(GetQuestModelRequest& request, std::function<void(AsyncGetQuestModelResult&)> callback)
    {
        GetQuestModelTask& task = *new GetQuestModelTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_QUEST_GS2QUESTWEBSOCKETCLIENT_HPP_