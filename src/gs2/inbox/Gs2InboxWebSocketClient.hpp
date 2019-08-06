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

#ifndef GS2_INBOX_GS2INBOXWEBSOCKETCLIENT_HPP_
#define GS2_INBOX_GS2INBOXWEBSOCKETCLIENT_HPP_

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
#include "request/DescribeMessagesRequest.hpp"
#include "request/DescribeMessagesByUserIdRequest.hpp"
#include "request/SendMessageByUserIdRequest.hpp"
#include "request/GetMessageRequest.hpp"
#include "request/GetMessageByUserIdRequest.hpp"
#include "request/OpenMessageRequest.hpp"
#include "request/OpenMessageByUserIdRequest.hpp"
#include "request/ReadMessageRequest.hpp"
#include "request/ReadMessageByUserIdRequest.hpp"
#include "request/DeleteMessageRequest.hpp"
#include "request/DeleteMessageByUserIdRequest.hpp"
#include "request/OpenByStampTaskRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeMessagesResult.hpp"
#include "result/DescribeMessagesByUserIdResult.hpp"
#include "result/SendMessageByUserIdResult.hpp"
#include "result/GetMessageResult.hpp"
#include "result/GetMessageByUserIdResult.hpp"
#include "result/OpenMessageResult.hpp"
#include "result/OpenMessageByUserIdResult.hpp"
#include "result/ReadMessageResult.hpp"
#include "result/ReadMessageByUserIdResult.hpp"
#include "result/DeleteMessageResult.hpp"
#include "result/DeleteMessageByUserIdResult.hpp"
#include "result/OpenByStampTaskResult.hpp"
#include <cstring>

namespace gs2 { namespace inbox {

typedef AsyncResult<DescribeNamespacesResult> AsyncDescribeNamespacesResult;
typedef AsyncResult<CreateNamespaceResult> AsyncCreateNamespaceResult;
typedef AsyncResult<GetNamespaceStatusResult> AsyncGetNamespaceStatusResult;
typedef AsyncResult<GetNamespaceResult> AsyncGetNamespaceResult;
typedef AsyncResult<UpdateNamespaceResult> AsyncUpdateNamespaceResult;
typedef AsyncResult<void> AsyncDeleteNamespaceResult;
typedef AsyncResult<DescribeMessagesResult> AsyncDescribeMessagesResult;
typedef AsyncResult<DescribeMessagesByUserIdResult> AsyncDescribeMessagesByUserIdResult;
typedef AsyncResult<SendMessageByUserIdResult> AsyncSendMessageByUserIdResult;
typedef AsyncResult<GetMessageResult> AsyncGetMessageResult;
typedef AsyncResult<GetMessageByUserIdResult> AsyncGetMessageByUserIdResult;
typedef AsyncResult<OpenMessageResult> AsyncOpenMessageResult;
typedef AsyncResult<OpenMessageByUserIdResult> AsyncOpenMessageByUserIdResult;
typedef AsyncResult<ReadMessageResult> AsyncReadMessageResult;
typedef AsyncResult<ReadMessageByUserIdResult> AsyncReadMessageByUserIdResult;
typedef AsyncResult<void> AsyncDeleteMessageResult;
typedef AsyncResult<void> AsyncDeleteMessageByUserIdResult;
typedef AsyncResult<OpenByStampTaskResult> AsyncOpenByStampTaskResult;

/**
 * GS2 Inbox API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2InboxWebSocketClient : public AbstractGs2ClientBase
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
            writer.writeCharArray("inbox");
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
            if (m_Request.getIsAutomaticDeletingEnabled())
            {
                writer.writePropertyName("isAutomaticDeletingEnabled");
                writer.writeBool(*m_Request.getIsAutomaticDeletingEnabled());
            }
            if (m_Request.getReceiveMessageTriggerScriptId())
            {
                writer.writePropertyName("receiveMessageTriggerScriptId");
                writer.writeCharArray(*m_Request.getReceiveMessageTriggerScriptId());
            }
            if (m_Request.getReceiveMessageDoneTriggerScriptId())
            {
                writer.writePropertyName("receiveMessageDoneTriggerScriptId");
                writer.writeCharArray(*m_Request.getReceiveMessageDoneTriggerScriptId());
            }
            if (m_Request.getReceiveMessageDoneTriggerNamespaceId())
            {
                writer.writePropertyName("receiveMessageDoneTriggerNamespaceId");
                writer.writeCharArray(*m_Request.getReceiveMessageDoneTriggerNamespaceId());
            }
            if (m_Request.getReadMessageTriggerScriptId())
            {
                writer.writePropertyName("readMessageTriggerScriptId");
                writer.writeCharArray(*m_Request.getReadMessageTriggerScriptId());
            }
            if (m_Request.getReadMessageDoneTriggerScriptId())
            {
                writer.writePropertyName("readMessageDoneTriggerScriptId");
                writer.writeCharArray(*m_Request.getReadMessageDoneTriggerScriptId());
            }
            if (m_Request.getReadMessageDoneTriggerNamespaceId())
            {
                writer.writePropertyName("readMessageDoneTriggerNamespaceId");
                writer.writeCharArray(*m_Request.getReadMessageDoneTriggerNamespaceId());
            }
            if (m_Request.getDeleteMessageTriggerScriptId())
            {
                writer.writePropertyName("deleteMessageTriggerScriptId");
                writer.writeCharArray(*m_Request.getDeleteMessageTriggerScriptId());
            }
            if (m_Request.getDeleteMessageDoneTriggerScriptId())
            {
                writer.writePropertyName("deleteMessageDoneTriggerScriptId");
                writer.writeCharArray(*m_Request.getDeleteMessageDoneTriggerScriptId());
            }
            if (m_Request.getDeleteMessageDoneTriggerNamespaceId())
            {
                writer.writePropertyName("deleteMessageDoneTriggerNamespaceId");
                writer.writeCharArray(*m_Request.getDeleteMessageDoneTriggerNamespaceId());
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
            if (m_Request.getReceiveNotification())
            {
                writer.writePropertyName("receiveNotification");
                write(writer, *m_Request.getReceiveNotification());
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
            writer.writeCharArray("inbox");
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
            writer.writeCharArray("inbox");
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
            writer.writeCharArray("inbox");
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
            if (m_Request.getIsAutomaticDeletingEnabled())
            {
                writer.writePropertyName("isAutomaticDeletingEnabled");
                writer.writeBool(*m_Request.getIsAutomaticDeletingEnabled());
            }
            if (m_Request.getReceiveMessageTriggerScriptId())
            {
                writer.writePropertyName("receiveMessageTriggerScriptId");
                writer.writeCharArray(*m_Request.getReceiveMessageTriggerScriptId());
            }
            if (m_Request.getReceiveMessageDoneTriggerScriptId())
            {
                writer.writePropertyName("receiveMessageDoneTriggerScriptId");
                writer.writeCharArray(*m_Request.getReceiveMessageDoneTriggerScriptId());
            }
            if (m_Request.getReceiveMessageDoneTriggerNamespaceId())
            {
                writer.writePropertyName("receiveMessageDoneTriggerNamespaceId");
                writer.writeCharArray(*m_Request.getReceiveMessageDoneTriggerNamespaceId());
            }
            if (m_Request.getReadMessageTriggerScriptId())
            {
                writer.writePropertyName("readMessageTriggerScriptId");
                writer.writeCharArray(*m_Request.getReadMessageTriggerScriptId());
            }
            if (m_Request.getReadMessageDoneTriggerScriptId())
            {
                writer.writePropertyName("readMessageDoneTriggerScriptId");
                writer.writeCharArray(*m_Request.getReadMessageDoneTriggerScriptId());
            }
            if (m_Request.getReadMessageDoneTriggerNamespaceId())
            {
                writer.writePropertyName("readMessageDoneTriggerNamespaceId");
                writer.writeCharArray(*m_Request.getReadMessageDoneTriggerNamespaceId());
            }
            if (m_Request.getDeleteMessageTriggerScriptId())
            {
                writer.writePropertyName("deleteMessageTriggerScriptId");
                writer.writeCharArray(*m_Request.getDeleteMessageTriggerScriptId());
            }
            if (m_Request.getDeleteMessageDoneTriggerScriptId())
            {
                writer.writePropertyName("deleteMessageDoneTriggerScriptId");
                writer.writeCharArray(*m_Request.getDeleteMessageDoneTriggerScriptId());
            }
            if (m_Request.getDeleteMessageDoneTriggerNamespaceId())
            {
                writer.writePropertyName("deleteMessageDoneTriggerNamespaceId");
                writer.writeCharArray(*m_Request.getDeleteMessageDoneTriggerNamespaceId());
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
            if (m_Request.getReceiveNotification())
            {
                writer.writePropertyName("receiveNotification");
                write(writer, *m_Request.getReceiveNotification());
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
            writer.writeCharArray("inbox");
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

    class DeleteNamespaceTask : public detail::Gs2WebSocketSessionTask<void>
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
            writer.writeCharArray("inbox");
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
            Gs2WebSocketSessionTask<void>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<void>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteNamespaceTask() GS2_OVERRIDE = default;
    };

    class DescribeMessagesTask : public detail::Gs2WebSocketSessionTask<DescribeMessagesResult>
    {
    private:
        DescribeMessagesRequest& m_Request;

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
            writer.writeCharArray("inbox");
            writer.writePropertyName("component");
            writer.writeCharArray("message");
            writer.writePropertyName("function");
            writer.writeCharArray("describeMessages");
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
        DescribeMessagesTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeMessagesRequest& request,
            Gs2WebSocketSessionTask<DescribeMessagesResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeMessagesResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeMessagesTask() GS2_OVERRIDE = default;
    };

    class DescribeMessagesByUserIdTask : public detail::Gs2WebSocketSessionTask<DescribeMessagesByUserIdResult>
    {
    private:
        DescribeMessagesByUserIdRequest& m_Request;

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
            writer.writeCharArray("inbox");
            writer.writePropertyName("component");
            writer.writeCharArray("message");
            writer.writePropertyName("function");
            writer.writeCharArray("describeMessagesByUserId");
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
        DescribeMessagesByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeMessagesByUserIdRequest& request,
            Gs2WebSocketSessionTask<DescribeMessagesByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeMessagesByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeMessagesByUserIdTask() GS2_OVERRIDE = default;
    };

    class SendMessageByUserIdTask : public detail::Gs2WebSocketSessionTask<SendMessageByUserIdResult>
    {
    private:
        SendMessageByUserIdRequest& m_Request;

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
            if (m_Request.getMetadata())
            {
                writer.writePropertyName("metadata");
                writer.writeCharArray(*m_Request.getMetadata());
            }
            if (m_Request.getReadAcquireActions())
            {
                writer.writePropertyName("readAcquireActions");
                writer.writeArrayStart();
                auto& list = *m_Request.getReadAcquireActions();
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
            writer.writeCharArray("inbox");
            writer.writePropertyName("component");
            writer.writeCharArray("message");
            writer.writePropertyName("function");
            writer.writeCharArray("sendMessageByUserId");
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
        SendMessageByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            SendMessageByUserIdRequest& request,
            Gs2WebSocketSessionTask<SendMessageByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<SendMessageByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~SendMessageByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetMessageTask : public detail::Gs2WebSocketSessionTask<GetMessageResult>
    {
    private:
        GetMessageRequest& m_Request;

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
            if (m_Request.getMessageName())
            {
                writer.writePropertyName("messageName");
                writer.writeCharArray(*m_Request.getMessageName());
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
            writer.writeCharArray("inbox");
            writer.writePropertyName("component");
            writer.writeCharArray("message");
            writer.writePropertyName("function");
            writer.writeCharArray("getMessage");
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
        GetMessageTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetMessageRequest& request,
            Gs2WebSocketSessionTask<GetMessageResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetMessageResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetMessageTask() GS2_OVERRIDE = default;
    };

    class GetMessageByUserIdTask : public detail::Gs2WebSocketSessionTask<GetMessageByUserIdResult>
    {
    private:
        GetMessageByUserIdRequest& m_Request;

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
            if (m_Request.getMessageName())
            {
                writer.writePropertyName("messageName");
                writer.writeCharArray(*m_Request.getMessageName());
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
            writer.writeCharArray("inbox");
            writer.writePropertyName("component");
            writer.writeCharArray("message");
            writer.writePropertyName("function");
            writer.writeCharArray("getMessageByUserId");
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
        GetMessageByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetMessageByUserIdRequest& request,
            Gs2WebSocketSessionTask<GetMessageByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetMessageByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetMessageByUserIdTask() GS2_OVERRIDE = default;
    };

    class OpenMessageTask : public detail::Gs2WebSocketSessionTask<OpenMessageResult>
    {
    private:
        OpenMessageRequest& m_Request;

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
            if (m_Request.getMessageName())
            {
                writer.writePropertyName("messageName");
                writer.writeCharArray(*m_Request.getMessageName());
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
            writer.writeCharArray("inbox");
            writer.writePropertyName("component");
            writer.writeCharArray("message");
            writer.writePropertyName("function");
            writer.writeCharArray("openMessage");
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
        OpenMessageTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            OpenMessageRequest& request,
            Gs2WebSocketSessionTask<OpenMessageResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<OpenMessageResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~OpenMessageTask() GS2_OVERRIDE = default;
    };

    class OpenMessageByUserIdTask : public detail::Gs2WebSocketSessionTask<OpenMessageByUserIdResult>
    {
    private:
        OpenMessageByUserIdRequest& m_Request;

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
            if (m_Request.getMessageName())
            {
                writer.writePropertyName("messageName");
                writer.writeCharArray(*m_Request.getMessageName());
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
            writer.writeCharArray("inbox");
            writer.writePropertyName("component");
            writer.writeCharArray("message");
            writer.writePropertyName("function");
            writer.writeCharArray("openMessageByUserId");
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
        OpenMessageByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            OpenMessageByUserIdRequest& request,
            Gs2WebSocketSessionTask<OpenMessageByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<OpenMessageByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~OpenMessageByUserIdTask() GS2_OVERRIDE = default;
    };

    class ReadMessageTask : public detail::Gs2WebSocketSessionTask<ReadMessageResult>
    {
    private:
        ReadMessageRequest& m_Request;

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
            if (m_Request.getMessageName())
            {
                writer.writePropertyName("messageName");
                writer.writeCharArray(*m_Request.getMessageName());
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
            writer.writeCharArray("inbox");
            writer.writePropertyName("component");
            writer.writeCharArray("message");
            writer.writePropertyName("function");
            writer.writeCharArray("readMessage");
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
        ReadMessageTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            ReadMessageRequest& request,
            Gs2WebSocketSessionTask<ReadMessageResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<ReadMessageResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~ReadMessageTask() GS2_OVERRIDE = default;
    };

    class ReadMessageByUserIdTask : public detail::Gs2WebSocketSessionTask<ReadMessageByUserIdResult>
    {
    private:
        ReadMessageByUserIdRequest& m_Request;

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
            if (m_Request.getMessageName())
            {
                writer.writePropertyName("messageName");
                writer.writeCharArray(*m_Request.getMessageName());
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
            writer.writeCharArray("inbox");
            writer.writePropertyName("component");
            writer.writeCharArray("message");
            writer.writePropertyName("function");
            writer.writeCharArray("readMessageByUserId");
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
        ReadMessageByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            ReadMessageByUserIdRequest& request,
            Gs2WebSocketSessionTask<ReadMessageByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<ReadMessageByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~ReadMessageByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteMessageTask : public detail::Gs2WebSocketSessionTask<void>
    {
    private:
        DeleteMessageRequest& m_Request;

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
            if (m_Request.getMessageName())
            {
                writer.writePropertyName("messageName");
                writer.writeCharArray(*m_Request.getMessageName());
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
            writer.writeCharArray("inbox");
            writer.writePropertyName("component");
            writer.writeCharArray("message");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteMessage");
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
        DeleteMessageTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteMessageRequest& request,
            Gs2WebSocketSessionTask<void>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<void>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteMessageTask() GS2_OVERRIDE = default;
    };

    class DeleteMessageByUserIdTask : public detail::Gs2WebSocketSessionTask<void>
    {
    private:
        DeleteMessageByUserIdRequest& m_Request;

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
            if (m_Request.getMessageName())
            {
                writer.writePropertyName("messageName");
                writer.writeCharArray(*m_Request.getMessageName());
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
            writer.writeCharArray("inbox");
            writer.writePropertyName("component");
            writer.writeCharArray("message");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteMessageByUserId");
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
        DeleteMessageByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteMessageByUserIdRequest& request,
            Gs2WebSocketSessionTask<void>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<void>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteMessageByUserIdTask() GS2_OVERRIDE = default;
    };

    class OpenByStampTaskTask : public detail::Gs2WebSocketSessionTask<OpenByStampTaskResult>
    {
    private:
        OpenByStampTaskRequest& m_Request;

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
            writer.writeCharArray("inbox");
            writer.writePropertyName("component");
            writer.writeCharArray("message");
            writer.writePropertyName("function");
            writer.writeCharArray("openByStampTask");
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
        OpenByStampTaskTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            OpenByStampTaskRequest& request,
            Gs2WebSocketSessionTask<OpenByStampTaskResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<OpenByStampTaskResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~OpenByStampTaskTask() GS2_OVERRIDE = default;
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
        if (obj.getIsAutomaticDeletingEnabled())
        {
            writer.writePropertyName("isAutomaticDeletingEnabled");
            writer.writeBool(*obj.getIsAutomaticDeletingEnabled());
        }
        if (obj.getReceiveMessageTriggerScriptId())
        {
            writer.writePropertyName("receiveMessageTriggerScriptId");
            writer.writeCharArray(*obj.getReceiveMessageTriggerScriptId());
        }
        if (obj.getReceiveMessageDoneTriggerScriptId())
        {
            writer.writePropertyName("receiveMessageDoneTriggerScriptId");
            writer.writeCharArray(*obj.getReceiveMessageDoneTriggerScriptId());
        }
        if (obj.getReceiveMessageDoneTriggerNamespaceId())
        {
            writer.writePropertyName("receiveMessageDoneTriggerNamespaceId");
            writer.writeCharArray(*obj.getReceiveMessageDoneTriggerNamespaceId());
        }
        if (obj.getReadMessageTriggerScriptId())
        {
            writer.writePropertyName("readMessageTriggerScriptId");
            writer.writeCharArray(*obj.getReadMessageTriggerScriptId());
        }
        if (obj.getReadMessageDoneTriggerScriptId())
        {
            writer.writePropertyName("readMessageDoneTriggerScriptId");
            writer.writeCharArray(*obj.getReadMessageDoneTriggerScriptId());
        }
        if (obj.getReadMessageDoneTriggerNamespaceId())
        {
            writer.writePropertyName("readMessageDoneTriggerNamespaceId");
            writer.writeCharArray(*obj.getReadMessageDoneTriggerNamespaceId());
        }
        if (obj.getDeleteMessageTriggerScriptId())
        {
            writer.writePropertyName("deleteMessageTriggerScriptId");
            writer.writeCharArray(*obj.getDeleteMessageTriggerScriptId());
        }
        if (obj.getDeleteMessageDoneTriggerScriptId())
        {
            writer.writePropertyName("deleteMessageDoneTriggerScriptId");
            writer.writeCharArray(*obj.getDeleteMessageDoneTriggerScriptId());
        }
        if (obj.getDeleteMessageDoneTriggerNamespaceId())
        {
            writer.writePropertyName("deleteMessageDoneTriggerNamespaceId");
            writer.writeCharArray(*obj.getDeleteMessageDoneTriggerNamespaceId());
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
        if (obj.getReceiveNotification())
        {
            writer.writePropertyName("receiveNotification");
            write(writer, *obj.getReceiveNotification());
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

    static void write(detail::json::JsonWriter& writer, const Message& obj)
    {
        writer.writeObjectStart();
        if (obj.getMessageId())
        {
            writer.writePropertyName("messageId");
            writer.writeCharArray(*obj.getMessageId());
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
        if (obj.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.writeCharArray(*obj.getMetadata());
        }
        if (obj.getIsRead())
        {
            writer.writePropertyName("isRead");
            writer.writeBool(*obj.getIsRead());
        }
        if (obj.getReadAcquireActions())
        {
            writer.writePropertyName("readAcquireActions");
            writer.writeArrayStart();
            auto& list = *obj.getReadAcquireActions();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getReceivedAt())
        {
            writer.writePropertyName("receivedAt");
            writer.writeInt64(*obj.getReceivedAt());
        }
        if (obj.getReadAt())
        {
            writer.writePropertyName("readAt");
            writer.writeInt64(*obj.getReadAt());
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



public:
    /**
     * コンストラクタ。
     *
     * @param gs2WebSocketSession WebSocket API 用セッション
     */
    explicit Gs2InboxWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
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
	 * メッセージの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeMessages(std::function<void(AsyncDescribeMessagesResult&)> callback, DescribeMessagesRequest& request)
    {
        DescribeMessagesTask& task = *new DescribeMessagesTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * メッセージの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeMessagesByUserId(std::function<void(AsyncDescribeMessagesByUserIdResult&)> callback, DescribeMessagesByUserIdRequest& request)
    {
        DescribeMessagesByUserIdTask& task = *new DescribeMessagesByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * メッセージを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void sendMessageByUserId(std::function<void(AsyncSendMessageByUserIdResult&)> callback, SendMessageByUserIdRequest& request)
    {
        SendMessageByUserIdTask& task = *new SendMessageByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * メッセージを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMessage(std::function<void(AsyncGetMessageResult&)> callback, GetMessageRequest& request)
    {
        GetMessageTask& task = *new GetMessageTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザーIDを指定してメッセージを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMessageByUserId(std::function<void(AsyncGetMessageByUserIdResult&)> callback, GetMessageByUserIdRequest& request)
    {
        GetMessageByUserIdTask& task = *new GetMessageByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * メッセージを開封<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void openMessage(std::function<void(AsyncOpenMessageResult&)> callback, OpenMessageRequest& request)
    {
        OpenMessageTask& task = *new OpenMessageTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザーIDを指定してメッセージを開封<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void openMessageByUserId(std::function<void(AsyncOpenMessageByUserIdResult&)> callback, OpenMessageByUserIdRequest& request)
    {
        OpenMessageByUserIdTask& task = *new OpenMessageByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * メッセージを開封<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void readMessage(std::function<void(AsyncReadMessageResult&)> callback, ReadMessageRequest& request)
    {
        ReadMessageTask& task = *new ReadMessageTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザーIDを指定してメッセージを開封<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void readMessageByUserId(std::function<void(AsyncReadMessageByUserIdResult&)> callback, ReadMessageByUserIdRequest& request)
    {
        ReadMessageByUserIdTask& task = *new ReadMessageByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * メッセージを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteMessage(std::function<void(AsyncDeleteMessageResult&)> callback, DeleteMessageRequest& request)
    {
        DeleteMessageTask& task = *new DeleteMessageTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザーIDを指定してメッセージを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteMessageByUserId(std::function<void(AsyncDeleteMessageByUserIdResult&)> callback, DeleteMessageByUserIdRequest& request)
    {
        DeleteMessageByUserIdTask& task = *new DeleteMessageByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * メッセージを作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void openByStampTask(std::function<void(AsyncOpenByStampTaskResult&)> callback, OpenByStampTaskRequest& request)
    {
        OpenByStampTaskTask& task = *new OpenByStampTaskTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_INBOX_GS2INBOXWEBSOCKETCLIENT_HPP_