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
#include <gs2/core/util/StringVariable.hpp>
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
#include "request/ReceiveGlobalMessageRequest.hpp"
#include "request/ReceiveGlobalMessageByUserIdRequest.hpp"
#include "request/OpenMessageRequest.hpp"
#include "request/OpenMessageByUserIdRequest.hpp"
#include "request/ReadMessageRequest.hpp"
#include "request/ReadMessageByUserIdRequest.hpp"
#include "request/DeleteMessageRequest.hpp"
#include "request/DeleteMessageByUserIdRequest.hpp"
#include "request/OpenByStampTaskRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentMessageMasterRequest.hpp"
#include "request/UpdateCurrentMessageMasterRequest.hpp"
#include "request/UpdateCurrentMessageMasterFromGitHubRequest.hpp"
#include "request/DescribeGlobalMessageMastersRequest.hpp"
#include "request/CreateGlobalMessageMasterRequest.hpp"
#include "request/GetGlobalMessageMasterRequest.hpp"
#include "request/UpdateGlobalMessageMasterRequest.hpp"
#include "request/DeleteGlobalMessageMasterRequest.hpp"
#include "request/DescribeGlobalMessagesRequest.hpp"
#include "request/GetGlobalMessageRequest.hpp"
#include "request/GetReceivedByUserIdRequest.hpp"
#include "request/UpdateReceivedByUserIdRequest.hpp"
#include "request/DeleteReceivedByUserIdRequest.hpp"
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
#include "result/ReceiveGlobalMessageResult.hpp"
#include "result/ReceiveGlobalMessageByUserIdResult.hpp"
#include "result/OpenMessageResult.hpp"
#include "result/OpenMessageByUserIdResult.hpp"
#include "result/ReadMessageResult.hpp"
#include "result/ReadMessageByUserIdResult.hpp"
#include "result/DeleteMessageResult.hpp"
#include "result/DeleteMessageByUserIdResult.hpp"
#include "result/OpenByStampTaskResult.hpp"
#include "result/ExportMasterResult.hpp"
#include "result/GetCurrentMessageMasterResult.hpp"
#include "result/UpdateCurrentMessageMasterResult.hpp"
#include "result/UpdateCurrentMessageMasterFromGitHubResult.hpp"
#include "result/DescribeGlobalMessageMastersResult.hpp"
#include "result/CreateGlobalMessageMasterResult.hpp"
#include "result/GetGlobalMessageMasterResult.hpp"
#include "result/UpdateGlobalMessageMasterResult.hpp"
#include "result/DeleteGlobalMessageMasterResult.hpp"
#include "result/DescribeGlobalMessagesResult.hpp"
#include "result/GetGlobalMessageResult.hpp"
#include "result/GetReceivedByUserIdResult.hpp"
#include "result/UpdateReceivedByUserIdResult.hpp"
#include "result/DeleteReceivedByUserIdResult.hpp"
#include <cstring>

namespace gs2 { namespace inbox {

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
        DescribeNamespacesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
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
            return "inbox";
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
            if (m_Request.getIsAutomaticDeletingEnabled())
            {
                jsonWriter.writePropertyName("isAutomaticDeletingEnabled");
                jsonWriter.writeBool(*m_Request.getIsAutomaticDeletingEnabled());
            }
            if (m_Request.getReceiveMessageScript())
            {
                jsonWriter.writePropertyName("receiveMessageScript");
                write(jsonWriter, *m_Request.getReceiveMessageScript());
            }
            if (m_Request.getReadMessageScript())
            {
                jsonWriter.writePropertyName("readMessageScript");
                write(jsonWriter, *m_Request.getReadMessageScript());
            }
            if (m_Request.getDeleteMessageScript())
            {
                jsonWriter.writePropertyName("deleteMessageScript");
                write(jsonWriter, *m_Request.getDeleteMessageScript());
            }
            if (m_Request.getQueueNamespaceId())
            {
                jsonWriter.writePropertyName("queueNamespaceId");
                jsonWriter.writeCharArray(*m_Request.getQueueNamespaceId());
            }
            if (m_Request.getKeyId())
            {
                jsonWriter.writePropertyName("keyId");
                jsonWriter.writeCharArray(*m_Request.getKeyId());
            }
            if (m_Request.getReceiveNotification())
            {
                jsonWriter.writePropertyName("receiveNotification");
                write(jsonWriter, *m_Request.getReceiveNotification());
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
            return "inbox";
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
            return "inbox";
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
            return "inbox";
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
            if (m_Request.getIsAutomaticDeletingEnabled())
            {
                jsonWriter.writePropertyName("isAutomaticDeletingEnabled");
                jsonWriter.writeBool(*m_Request.getIsAutomaticDeletingEnabled());
            }
            if (m_Request.getReceiveMessageScript())
            {
                jsonWriter.writePropertyName("receiveMessageScript");
                write(jsonWriter, *m_Request.getReceiveMessageScript());
            }
            if (m_Request.getReadMessageScript())
            {
                jsonWriter.writePropertyName("readMessageScript");
                write(jsonWriter, *m_Request.getReadMessageScript());
            }
            if (m_Request.getDeleteMessageScript())
            {
                jsonWriter.writePropertyName("deleteMessageScript");
                write(jsonWriter, *m_Request.getDeleteMessageScript());
            }
            if (m_Request.getQueueNamespaceId())
            {
                jsonWriter.writePropertyName("queueNamespaceId");
                jsonWriter.writeCharArray(*m_Request.getQueueNamespaceId());
            }
            if (m_Request.getKeyId())
            {
                jsonWriter.writePropertyName("keyId");
                jsonWriter.writeCharArray(*m_Request.getKeyId());
            }
            if (m_Request.getReceiveNotification())
            {
                jsonWriter.writePropertyName("receiveNotification");
                write(jsonWriter, *m_Request.getReceiveNotification());
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
            return "inbox";
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

    class DescribeMessagesTask : public detail::Gs2WebSocketSessionTask<DescribeMessagesResult>
    {
    private:
        DescribeMessagesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "message";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeMessages";
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
        DescribeMessagesTask(
            DescribeMessagesRequest request,
            Gs2WebSocketSessionTask<DescribeMessagesResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeMessagesResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeMessagesTask() GS2_OVERRIDE = default;
    };

    class DescribeMessagesByUserIdTask : public detail::Gs2WebSocketSessionTask<DescribeMessagesByUserIdResult>
    {
    private:
        DescribeMessagesByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "message";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeMessagesByUserId";
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
        DescribeMessagesByUserIdTask(
            DescribeMessagesByUserIdRequest request,
            Gs2WebSocketSessionTask<DescribeMessagesByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeMessagesByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeMessagesByUserIdTask() GS2_OVERRIDE = default;
    };

    class SendMessageByUserIdTask : public detail::Gs2WebSocketSessionTask<SendMessageByUserIdResult>
    {
    private:
        SendMessageByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "message";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "sendMessageByUserId";
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
            if (m_Request.getMetadata())
            {
                jsonWriter.writePropertyName("metadata");
                jsonWriter.writeCharArray(*m_Request.getMetadata());
            }
            if (m_Request.getReadAcquireActions())
            {
                jsonWriter.writePropertyName("readAcquireActions");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getReadAcquireActions();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(jsonWriter, list[i]);
                }
                jsonWriter.writeArrayEnd();
            }
            if (m_Request.getExpiresAt())
            {
                jsonWriter.writePropertyName("expiresAt");
                jsonWriter.writeInt64(*m_Request.getExpiresAt());
            }
            if (m_Request.getExpiresTimeSpan())
            {
                jsonWriter.writePropertyName("expiresTimeSpan");
                write(jsonWriter, *m_Request.getExpiresTimeSpan());
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
        SendMessageByUserIdTask(
            SendMessageByUserIdRequest request,
            Gs2WebSocketSessionTask<SendMessageByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<SendMessageByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~SendMessageByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetMessageTask : public detail::Gs2WebSocketSessionTask<GetMessageResult>
    {
    private:
        GetMessageRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "message";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getMessage";
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
            if (m_Request.getMessageName())
            {
                jsonWriter.writePropertyName("messageName");
                jsonWriter.writeCharArray(*m_Request.getMessageName());
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
        GetMessageTask(
            GetMessageRequest request,
            Gs2WebSocketSessionTask<GetMessageResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetMessageResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetMessageTask() GS2_OVERRIDE = default;
    };

    class GetMessageByUserIdTask : public detail::Gs2WebSocketSessionTask<GetMessageByUserIdResult>
    {
    private:
        GetMessageByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "message";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getMessageByUserId";
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
            if (m_Request.getMessageName())
            {
                jsonWriter.writePropertyName("messageName");
                jsonWriter.writeCharArray(*m_Request.getMessageName());
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
        GetMessageByUserIdTask(
            GetMessageByUserIdRequest request,
            Gs2WebSocketSessionTask<GetMessageByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetMessageByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetMessageByUserIdTask() GS2_OVERRIDE = default;
    };

    class ReceiveGlobalMessageTask : public detail::Gs2WebSocketSessionTask<ReceiveGlobalMessageResult>
    {
    private:
        ReceiveGlobalMessageRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "message";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "receiveGlobalMessage";
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
        ReceiveGlobalMessageTask(
            ReceiveGlobalMessageRequest request,
            Gs2WebSocketSessionTask<ReceiveGlobalMessageResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<ReceiveGlobalMessageResult>(callback),
            m_Request(std::move(request))
        {}

        ~ReceiveGlobalMessageTask() GS2_OVERRIDE = default;
    };

    class ReceiveGlobalMessageByUserIdTask : public detail::Gs2WebSocketSessionTask<ReceiveGlobalMessageByUserIdResult>
    {
    private:
        ReceiveGlobalMessageByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "message";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "receiveGlobalMessageByUserId";
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
        ReceiveGlobalMessageByUserIdTask(
            ReceiveGlobalMessageByUserIdRequest request,
            Gs2WebSocketSessionTask<ReceiveGlobalMessageByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<ReceiveGlobalMessageByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~ReceiveGlobalMessageByUserIdTask() GS2_OVERRIDE = default;
    };

    class OpenMessageTask : public detail::Gs2WebSocketSessionTask<OpenMessageResult>
    {
    private:
        OpenMessageRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "message";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "openMessage";
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
            if (m_Request.getMessageName())
            {
                jsonWriter.writePropertyName("messageName");
                jsonWriter.writeCharArray(*m_Request.getMessageName());
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
        OpenMessageTask(
            OpenMessageRequest request,
            Gs2WebSocketSessionTask<OpenMessageResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<OpenMessageResult>(callback),
            m_Request(std::move(request))
        {}

        ~OpenMessageTask() GS2_OVERRIDE = default;
    };

    class OpenMessageByUserIdTask : public detail::Gs2WebSocketSessionTask<OpenMessageByUserIdResult>
    {
    private:
        OpenMessageByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "message";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "openMessageByUserId";
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
            if (m_Request.getMessageName())
            {
                jsonWriter.writePropertyName("messageName");
                jsonWriter.writeCharArray(*m_Request.getMessageName());
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
        OpenMessageByUserIdTask(
            OpenMessageByUserIdRequest request,
            Gs2WebSocketSessionTask<OpenMessageByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<OpenMessageByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~OpenMessageByUserIdTask() GS2_OVERRIDE = default;
    };

    class ReadMessageTask : public detail::Gs2WebSocketSessionTask<ReadMessageResult>
    {
    private:
        ReadMessageRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "message";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "readMessage";
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
            if (m_Request.getMessageName())
            {
                jsonWriter.writePropertyName("messageName");
                jsonWriter.writeCharArray(*m_Request.getMessageName());
            }
            if (m_Request.getConfig())
            {
                jsonWriter.writePropertyName("config");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getConfig();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(jsonWriter, list[i]);
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
        ReadMessageTask(
            ReadMessageRequest request,
            Gs2WebSocketSessionTask<ReadMessageResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<ReadMessageResult>(callback),
            m_Request(std::move(request))
        {}

        ~ReadMessageTask() GS2_OVERRIDE = default;
    };

    class ReadMessageByUserIdTask : public detail::Gs2WebSocketSessionTask<ReadMessageByUserIdResult>
    {
    private:
        ReadMessageByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "message";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "readMessageByUserId";
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
            if (m_Request.getMessageName())
            {
                jsonWriter.writePropertyName("messageName");
                jsonWriter.writeCharArray(*m_Request.getMessageName());
            }
            if (m_Request.getConfig())
            {
                jsonWriter.writePropertyName("config");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getConfig();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(jsonWriter, list[i]);
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
        ReadMessageByUserIdTask(
            ReadMessageByUserIdRequest request,
            Gs2WebSocketSessionTask<ReadMessageByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<ReadMessageByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~ReadMessageByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteMessageTask : public detail::Gs2WebSocketSessionTask<void>
    {
    private:
        DeleteMessageRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "message";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteMessage";
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
            if (m_Request.getMessageName())
            {
                jsonWriter.writePropertyName("messageName");
                jsonWriter.writeCharArray(*m_Request.getMessageName());
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
        DeleteMessageTask(
            DeleteMessageRequest request,
            Gs2WebSocketSessionTask<void>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<void>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteMessageTask() GS2_OVERRIDE = default;
    };

    class DeleteMessageByUserIdTask : public detail::Gs2WebSocketSessionTask<void>
    {
    private:
        DeleteMessageByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "message";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteMessageByUserId";
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
            if (m_Request.getMessageName())
            {
                jsonWriter.writePropertyName("messageName");
                jsonWriter.writeCharArray(*m_Request.getMessageName());
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
        DeleteMessageByUserIdTask(
            DeleteMessageByUserIdRequest request,
            Gs2WebSocketSessionTask<void>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<void>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteMessageByUserIdTask() GS2_OVERRIDE = default;
    };

    class OpenByStampTaskTask : public detail::Gs2WebSocketSessionTask<OpenByStampTaskResult>
    {
    private:
        OpenByStampTaskRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "message";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "openByStampTask";
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
        OpenByStampTaskTask(
            OpenByStampTaskRequest request,
            Gs2WebSocketSessionTask<OpenByStampTaskResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<OpenByStampTaskResult>(callback),
            m_Request(std::move(request))
        {}

        ~OpenByStampTaskTask() GS2_OVERRIDE = default;
    };

    class ExportMasterTask : public detail::Gs2WebSocketSessionTask<ExportMasterResult>
    {
    private:
        ExportMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "currentMessageMaster";
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

    class GetCurrentMessageMasterTask : public detail::Gs2WebSocketSessionTask<GetCurrentMessageMasterResult>
    {
    private:
        GetCurrentMessageMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "currentMessageMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getCurrentMessageMaster";
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
        GetCurrentMessageMasterTask(
            GetCurrentMessageMasterRequest request,
            Gs2WebSocketSessionTask<GetCurrentMessageMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetCurrentMessageMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetCurrentMessageMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentMessageMasterTask : public detail::Gs2WebSocketSessionTask<UpdateCurrentMessageMasterResult>
    {
    private:
        UpdateCurrentMessageMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "currentMessageMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateCurrentMessageMaster";
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
        UpdateCurrentMessageMasterTask(
            UpdateCurrentMessageMasterRequest request,
            Gs2WebSocketSessionTask<UpdateCurrentMessageMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateCurrentMessageMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateCurrentMessageMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentMessageMasterFromGitHubTask : public detail::Gs2WebSocketSessionTask<UpdateCurrentMessageMasterFromGitHubResult>
    {
    private:
        UpdateCurrentMessageMasterFromGitHubRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "currentMessageMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateCurrentMessageMasterFromGitHub";
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
        UpdateCurrentMessageMasterFromGitHubTask(
            UpdateCurrentMessageMasterFromGitHubRequest request,
            Gs2WebSocketSessionTask<UpdateCurrentMessageMasterFromGitHubResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateCurrentMessageMasterFromGitHubResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateCurrentMessageMasterFromGitHubTask() GS2_OVERRIDE = default;
    };

    class DescribeGlobalMessageMastersTask : public detail::Gs2WebSocketSessionTask<DescribeGlobalMessageMastersResult>
    {
    private:
        DescribeGlobalMessageMastersRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "globalMessageMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeGlobalMessageMasters";
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
        DescribeGlobalMessageMastersTask(
            DescribeGlobalMessageMastersRequest request,
            Gs2WebSocketSessionTask<DescribeGlobalMessageMastersResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeGlobalMessageMastersResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeGlobalMessageMastersTask() GS2_OVERRIDE = default;
    };

    class CreateGlobalMessageMasterTask : public detail::Gs2WebSocketSessionTask<CreateGlobalMessageMasterResult>
    {
    private:
        CreateGlobalMessageMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "globalMessageMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "createGlobalMessageMaster";
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
            if (m_Request.getMetadata())
            {
                jsonWriter.writePropertyName("metadata");
                jsonWriter.writeCharArray(*m_Request.getMetadata());
            }
            if (m_Request.getReadAcquireActions())
            {
                jsonWriter.writePropertyName("readAcquireActions");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getReadAcquireActions();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(jsonWriter, list[i]);
                }
                jsonWriter.writeArrayEnd();
            }
            if (m_Request.getExpiresTimeSpan())
            {
                jsonWriter.writePropertyName("expiresTimeSpan");
                write(jsonWriter, *m_Request.getExpiresTimeSpan());
            }
            if (m_Request.getExpiresAt())
            {
                jsonWriter.writePropertyName("expiresAt");
                jsonWriter.writeInt64(*m_Request.getExpiresAt());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        CreateGlobalMessageMasterTask(
            CreateGlobalMessageMasterRequest request,
            Gs2WebSocketSessionTask<CreateGlobalMessageMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateGlobalMessageMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateGlobalMessageMasterTask() GS2_OVERRIDE = default;
    };

    class GetGlobalMessageMasterTask : public detail::Gs2WebSocketSessionTask<GetGlobalMessageMasterResult>
    {
    private:
        GetGlobalMessageMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "globalMessageMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getGlobalMessageMaster";
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
            if (m_Request.getGlobalMessageName())
            {
                jsonWriter.writePropertyName("globalMessageName");
                jsonWriter.writeCharArray(*m_Request.getGlobalMessageName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetGlobalMessageMasterTask(
            GetGlobalMessageMasterRequest request,
            Gs2WebSocketSessionTask<GetGlobalMessageMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetGlobalMessageMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetGlobalMessageMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateGlobalMessageMasterTask : public detail::Gs2WebSocketSessionTask<UpdateGlobalMessageMasterResult>
    {
    private:
        UpdateGlobalMessageMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "globalMessageMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateGlobalMessageMaster";
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
            if (m_Request.getGlobalMessageName())
            {
                jsonWriter.writePropertyName("globalMessageName");
                jsonWriter.writeCharArray(*m_Request.getGlobalMessageName());
            }
            if (m_Request.getMetadata())
            {
                jsonWriter.writePropertyName("metadata");
                jsonWriter.writeCharArray(*m_Request.getMetadata());
            }
            if (m_Request.getReadAcquireActions())
            {
                jsonWriter.writePropertyName("readAcquireActions");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getReadAcquireActions();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(jsonWriter, list[i]);
                }
                jsonWriter.writeArrayEnd();
            }
            if (m_Request.getExpiresTimeSpan())
            {
                jsonWriter.writePropertyName("expiresTimeSpan");
                write(jsonWriter, *m_Request.getExpiresTimeSpan());
            }
            if (m_Request.getExpiresAt())
            {
                jsonWriter.writePropertyName("expiresAt");
                jsonWriter.writeInt64(*m_Request.getExpiresAt());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        UpdateGlobalMessageMasterTask(
            UpdateGlobalMessageMasterRequest request,
            Gs2WebSocketSessionTask<UpdateGlobalMessageMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateGlobalMessageMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateGlobalMessageMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteGlobalMessageMasterTask : public detail::Gs2WebSocketSessionTask<void>
    {
    private:
        DeleteGlobalMessageMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "globalMessageMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteGlobalMessageMaster";
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
            if (m_Request.getGlobalMessageName())
            {
                jsonWriter.writePropertyName("globalMessageName");
                jsonWriter.writeCharArray(*m_Request.getGlobalMessageName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        DeleteGlobalMessageMasterTask(
            DeleteGlobalMessageMasterRequest request,
            Gs2WebSocketSessionTask<void>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<void>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteGlobalMessageMasterTask() GS2_OVERRIDE = default;
    };

    class DescribeGlobalMessagesTask : public detail::Gs2WebSocketSessionTask<DescribeGlobalMessagesResult>
    {
    private:
        DescribeGlobalMessagesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "globalMessage";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeGlobalMessages";
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
        DescribeGlobalMessagesTask(
            DescribeGlobalMessagesRequest request,
            Gs2WebSocketSessionTask<DescribeGlobalMessagesResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeGlobalMessagesResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeGlobalMessagesTask() GS2_OVERRIDE = default;
    };

    class GetGlobalMessageTask : public detail::Gs2WebSocketSessionTask<GetGlobalMessageResult>
    {
    private:
        GetGlobalMessageRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "globalMessage";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getGlobalMessage";
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
            if (m_Request.getGlobalMessageName())
            {
                jsonWriter.writePropertyName("globalMessageName");
                jsonWriter.writeCharArray(*m_Request.getGlobalMessageName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetGlobalMessageTask(
            GetGlobalMessageRequest request,
            Gs2WebSocketSessionTask<GetGlobalMessageResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetGlobalMessageResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetGlobalMessageTask() GS2_OVERRIDE = default;
    };

    class GetReceivedByUserIdTask : public detail::Gs2WebSocketSessionTask<GetReceivedByUserIdResult>
    {
    private:
        GetReceivedByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "received";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getReceivedByUserId";
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
        GetReceivedByUserIdTask(
            GetReceivedByUserIdRequest request,
            Gs2WebSocketSessionTask<GetReceivedByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetReceivedByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetReceivedByUserIdTask() GS2_OVERRIDE = default;
    };

    class UpdateReceivedByUserIdTask : public detail::Gs2WebSocketSessionTask<void>
    {
    private:
        UpdateReceivedByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "received";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateReceivedByUserId";
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
            if (m_Request.getReceivedGlobalMessageNames())
            {
                jsonWriter.writePropertyName("receivedGlobalMessageNames");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getReceivedGlobalMessageNames();
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
        UpdateReceivedByUserIdTask(
            UpdateReceivedByUserIdRequest request,
            Gs2WebSocketSessionTask<void>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<void>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateReceivedByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteReceivedByUserIdTask : public detail::Gs2WebSocketSessionTask<void>
    {
    private:
        DeleteReceivedByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "received";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteReceivedByUserId";
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
        DeleteReceivedByUserIdTask(
            DeleteReceivedByUserIdRequest request,
            Gs2WebSocketSessionTask<void>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<void>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteReceivedByUserIdTask() GS2_OVERRIDE = default;
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
        if (obj.getIsAutomaticDeletingEnabled())
        {
            jsonWriter.writePropertyName("isAutomaticDeletingEnabled");
            jsonWriter.writeBool(*obj.getIsAutomaticDeletingEnabled());
        }
        if (obj.getReceiveMessageScript())
        {
            jsonWriter.writePropertyName("receiveMessageScript");
            write(jsonWriter, *obj.getReceiveMessageScript());
        }
        if (obj.getReadMessageScript())
        {
            jsonWriter.writePropertyName("readMessageScript");
            write(jsonWriter, *obj.getReadMessageScript());
        }
        if (obj.getDeleteMessageScript())
        {
            jsonWriter.writePropertyName("deleteMessageScript");
            write(jsonWriter, *obj.getDeleteMessageScript());
        }
        if (obj.getQueueNamespaceId())
        {
            jsonWriter.writePropertyName("queueNamespaceId");
            jsonWriter.writeCharArray(*obj.getQueueNamespaceId());
        }
        if (obj.getKeyId())
        {
            jsonWriter.writePropertyName("keyId");
            jsonWriter.writeCharArray(*obj.getKeyId());
        }
        if (obj.getReceiveNotification())
        {
            jsonWriter.writePropertyName("receiveNotification");
            write(jsonWriter, *obj.getReceiveNotification());
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

    static void write(detail::json::JsonWriter& jsonWriter, const Message& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getMessageId())
        {
            jsonWriter.writePropertyName("messageId");
            jsonWriter.writeCharArray(*obj.getMessageId());
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
        if (obj.getMetadata())
        {
            jsonWriter.writePropertyName("metadata");
            jsonWriter.writeCharArray(*obj.getMetadata());
        }
        if (obj.getIsRead())
        {
            jsonWriter.writePropertyName("isRead");
            jsonWriter.writeBool(*obj.getIsRead());
        }
        if (obj.getReadAcquireActions())
        {
            jsonWriter.writePropertyName("readAcquireActions");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getReadAcquireActions();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (obj.getReceivedAt())
        {
            jsonWriter.writePropertyName("receivedAt");
            jsonWriter.writeInt64(*obj.getReceivedAt());
        }
        if (obj.getReadAt())
        {
            jsonWriter.writePropertyName("readAt");
            jsonWriter.writeInt64(*obj.getReadAt());
        }
        if (obj.getExpiresAt())
        {
            jsonWriter.writePropertyName("expiresAt");
            jsonWriter.writeInt64(*obj.getExpiresAt());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const CurrentMessageMaster& obj)
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

    static void write(detail::json::JsonWriter& jsonWriter, const GlobalMessageMaster& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getGlobalMessageId())
        {
            jsonWriter.writePropertyName("globalMessageId");
            jsonWriter.writeCharArray(*obj.getGlobalMessageId());
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
        if (obj.getReadAcquireActions())
        {
            jsonWriter.writePropertyName("readAcquireActions");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getReadAcquireActions();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (obj.getExpiresTimeSpan())
        {
            jsonWriter.writePropertyName("expiresTimeSpan");
            write(jsonWriter, *obj.getExpiresTimeSpan());
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

    static void write(detail::json::JsonWriter& jsonWriter, const GlobalMessage& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getGlobalMessageId())
        {
            jsonWriter.writePropertyName("globalMessageId");
            jsonWriter.writeCharArray(*obj.getGlobalMessageId());
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
        if (obj.getReadAcquireActions())
        {
            jsonWriter.writePropertyName("readAcquireActions");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getReadAcquireActions();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (obj.getExpiresTimeSpan())
        {
            jsonWriter.writePropertyName("expiresTimeSpan");
            write(jsonWriter, *obj.getExpiresTimeSpan());
        }
        if (obj.getExpiresAt())
        {
            jsonWriter.writePropertyName("expiresAt");
            jsonWriter.writeInt64(*obj.getExpiresAt());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const Received& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getReceivedId())
        {
            jsonWriter.writePropertyName("receivedId");
            jsonWriter.writeCharArray(*obj.getReceivedId());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getReceivedGlobalMessageNames())
        {
            jsonWriter.writePropertyName("receivedGlobalMessageNames");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getReceivedGlobalMessageNames();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                jsonWriter.writeCharArray(list[i]);
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

    static void write(detail::json::JsonWriter& jsonWriter, const NotificationSetting& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getGatewayNamespaceId())
        {
            jsonWriter.writePropertyName("gatewayNamespaceId");
            jsonWriter.writeCharArray(*obj.getGatewayNamespaceId());
        }
        if (obj.getEnableTransferMobileNotification())
        {
            jsonWriter.writePropertyName("enableTransferMobileNotification");
            jsonWriter.writeBool(*obj.getEnableTransferMobileNotification());
        }
        if (obj.getSound())
        {
            jsonWriter.writePropertyName("sound");
            jsonWriter.writeCharArray(*obj.getSound());
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

    static void write(detail::json::JsonWriter& jsonWriter, const TimeSpan& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getDays())
        {
            jsonWriter.writePropertyName("days");
            jsonWriter.writeInt32(*obj.getDays());
        }
        if (obj.getHours())
        {
            jsonWriter.writePropertyName("hours");
            jsonWriter.writeInt32(*obj.getHours());
        }
        if (obj.getMinutes())
        {
            jsonWriter.writePropertyName("minutes");
            jsonWriter.writeInt32(*obj.getMinutes());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const AcquireAction& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getAction())
        {
            jsonWriter.writePropertyName("action");
            jsonWriter.writeCharArray(*obj.getAction());
        }
        if (obj.getRequest())
        {
            jsonWriter.writePropertyName("request");
            jsonWriter.writeCharArray(*obj.getRequest());
        }
        jsonWriter.writeObjectEnd();
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
	 * メッセージの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeMessages(DescribeMessagesRequest request, std::function<void(AsyncDescribeMessagesResult)> callback)
    {
        DescribeMessagesTask& task = *new DescribeMessagesTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * メッセージの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeMessagesByUserId(DescribeMessagesByUserIdRequest request, std::function<void(AsyncDescribeMessagesByUserIdResult)> callback)
    {
        DescribeMessagesByUserIdTask& task = *new DescribeMessagesByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * メッセージを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void sendMessageByUserId(SendMessageByUserIdRequest request, std::function<void(AsyncSendMessageByUserIdResult)> callback)
    {
        SendMessageByUserIdTask& task = *new SendMessageByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * メッセージを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMessage(GetMessageRequest request, std::function<void(AsyncGetMessageResult)> callback)
    {
        GetMessageTask& task = *new GetMessageTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザーIDを指定してメッセージを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMessageByUserId(GetMessageByUserIdRequest request, std::function<void(AsyncGetMessageByUserIdResult)> callback)
    {
        GetMessageByUserIdTask& task = *new GetMessageByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * グローバルメッセージのうちまだ受け取っていないメッセージを受信<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void receiveGlobalMessage(ReceiveGlobalMessageRequest request, std::function<void(AsyncReceiveGlobalMessageResult)> callback)
    {
        ReceiveGlobalMessageTask& task = *new ReceiveGlobalMessageTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザーIDを指定してグローバルメッセージのうちまだ受け取っていないメッセージを受信<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void receiveGlobalMessageByUserId(ReceiveGlobalMessageByUserIdRequest request, std::function<void(AsyncReceiveGlobalMessageByUserIdResult)> callback)
    {
        ReceiveGlobalMessageByUserIdTask& task = *new ReceiveGlobalMessageByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * メッセージを開封<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void openMessage(OpenMessageRequest request, std::function<void(AsyncOpenMessageResult)> callback)
    {
        OpenMessageTask& task = *new OpenMessageTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザーIDを指定してメッセージを開封<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void openMessageByUserId(OpenMessageByUserIdRequest request, std::function<void(AsyncOpenMessageByUserIdResult)> callback)
    {
        OpenMessageByUserIdTask& task = *new OpenMessageByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * メッセージを開封<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void readMessage(ReadMessageRequest request, std::function<void(AsyncReadMessageResult)> callback)
    {
        ReadMessageTask& task = *new ReadMessageTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザーIDを指定してメッセージを開封<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void readMessageByUserId(ReadMessageByUserIdRequest request, std::function<void(AsyncReadMessageByUserIdResult)> callback)
    {
        ReadMessageByUserIdTask& task = *new ReadMessageByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * メッセージを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteMessage(DeleteMessageRequest request, std::function<void(AsyncDeleteMessageResult)> callback)
    {
        DeleteMessageTask& task = *new DeleteMessageTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザーIDを指定してメッセージを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteMessageByUserId(DeleteMessageByUserIdRequest request, std::function<void(AsyncDeleteMessageByUserIdResult)> callback)
    {
        DeleteMessageByUserIdTask& task = *new DeleteMessageByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * メッセージを作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void openByStampTask(OpenByStampTaskRequest request, std::function<void(AsyncOpenByStampTaskResult)> callback)
    {
        OpenByStampTaskTask& task = *new OpenByStampTaskTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 現在有効なグローバルメッセージ設定のマスターデータをエクスポートします<br>
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
	 * 現在有効なグローバルメッセージ設定を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentMessageMaster(GetCurrentMessageMasterRequest request, std::function<void(AsyncGetCurrentMessageMasterResult)> callback)
    {
        GetCurrentMessageMasterTask& task = *new GetCurrentMessageMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 現在有効なグローバルメッセージ設定を更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentMessageMaster(UpdateCurrentMessageMasterRequest request, std::function<void(AsyncUpdateCurrentMessageMasterResult)> callback)
    {
        UpdateCurrentMessageMasterTask& task = *new UpdateCurrentMessageMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 現在有効なグローバルメッセージ設定を更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentMessageMasterFromGitHub(UpdateCurrentMessageMasterFromGitHubRequest request, std::function<void(AsyncUpdateCurrentMessageMasterFromGitHubResult)> callback)
    {
        UpdateCurrentMessageMasterFromGitHubTask& task = *new UpdateCurrentMessageMasterFromGitHubTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 全ユーザに向けたメッセージの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeGlobalMessageMasters(DescribeGlobalMessageMastersRequest request, std::function<void(AsyncDescribeGlobalMessageMastersResult)> callback)
    {
        DescribeGlobalMessageMastersTask& task = *new DescribeGlobalMessageMastersTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 全ユーザに向けたメッセージを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createGlobalMessageMaster(CreateGlobalMessageMasterRequest request, std::function<void(AsyncCreateGlobalMessageMasterResult)> callback)
    {
        CreateGlobalMessageMasterTask& task = *new CreateGlobalMessageMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 全ユーザに向けたメッセージを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getGlobalMessageMaster(GetGlobalMessageMasterRequest request, std::function<void(AsyncGetGlobalMessageMasterResult)> callback)
    {
        GetGlobalMessageMasterTask& task = *new GetGlobalMessageMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 全ユーザに向けたメッセージを開封<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateGlobalMessageMaster(UpdateGlobalMessageMasterRequest request, std::function<void(AsyncUpdateGlobalMessageMasterResult)> callback)
    {
        UpdateGlobalMessageMasterTask& task = *new UpdateGlobalMessageMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 全ユーザに向けたメッセージを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteGlobalMessageMaster(DeleteGlobalMessageMasterRequest request, std::function<void(AsyncDeleteGlobalMessageMasterResult)> callback)
    {
        DeleteGlobalMessageMasterTask& task = *new DeleteGlobalMessageMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 全ユーザに向けたメッセージの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeGlobalMessages(DescribeGlobalMessagesRequest request, std::function<void(AsyncDescribeGlobalMessagesResult)> callback)
    {
        DescribeGlobalMessagesTask& task = *new DescribeGlobalMessagesTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 全ユーザに向けたメッセージを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getGlobalMessage(GetGlobalMessageRequest request, std::function<void(AsyncGetGlobalMessageResult)> callback)
    {
        GetGlobalMessageTask& task = *new GetGlobalMessageTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザーIDを指定して受信済みグローバルメッセージ名を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getReceivedByUserId(GetReceivedByUserIdRequest request, std::function<void(AsyncGetReceivedByUserIdResult)> callback)
    {
        GetReceivedByUserIdTask& task = *new GetReceivedByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザーIDを指定して受信済みグローバルメッセージ名を削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateReceivedByUserId(UpdateReceivedByUserIdRequest request, std::function<void(AsyncUpdateReceivedByUserIdResult)> callback)
    {
        UpdateReceivedByUserIdTask& task = *new UpdateReceivedByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザーIDを指定して受信済みグローバルメッセージ名を削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteReceivedByUserId(DeleteReceivedByUserIdRequest request, std::function<void(AsyncDeleteReceivedByUserIdResult)> callback)
    {
        DeleteReceivedByUserIdTask& task = *new DeleteReceivedByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_INBOX_GS2INBOXWEBSOCKETCLIENT_HPP_