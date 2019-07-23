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

#ifndef GS2_GATEWAY_GS2GATEWAYWEBSOCKETCLIENT_HPP_
#define GS2_GATEWAY_GS2GATEWAYWEBSOCKETCLIENT_HPP_

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
#include "request/DescribeWebsocketSessionsRequest.hpp"
#include "request/DescribeWebsocketSessionsByOwnerIdRequest.hpp"
#include "request/DescribeWebsocketSessionsByUserIdRequest.hpp"
#include "request/DescribeWebsocketSessionsByOwnerIdAndUserIdRequest.hpp"
#include "request/SetUserIdRequest.hpp"
#include "request/GetSessionRequest.hpp"
#include "request/DeleteUserIdRequest.hpp"
#include "request/SendNotificationRequest.hpp"
#include "request/SendNotificationBySystemRequest.hpp"
#include "request/DescribeFirebaseTokensRequest.hpp"
#include "request/DescribeFirebaseTokensByOwnerIdRequest.hpp"
#include "request/SetFirebaseTokenRequest.hpp"
#include "request/SetFirebaseTokenByUserIdRequest.hpp"
#include "request/GetFirebaseTokenRequest.hpp"
#include "request/GetFirebaseTokenByUserIdRequest.hpp"
#include "request/DeleteFirebaseTokenRequest.hpp"
#include "request/DeleteFirebaseTokenByUserIdRequest.hpp"
#include "request/SendMobileNotificationByUserIdRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeWebsocketSessionsResult.hpp"
#include "result/DescribeWebsocketSessionsByOwnerIdResult.hpp"
#include "result/DescribeWebsocketSessionsByUserIdResult.hpp"
#include "result/DescribeWebsocketSessionsByOwnerIdAndUserIdResult.hpp"
#include "result/SetUserIdResult.hpp"
#include "result/GetSessionResult.hpp"
#include "result/DeleteUserIdResult.hpp"
#include "result/SendNotificationResult.hpp"
#include "result/SendNotificationBySystemResult.hpp"
#include "result/DescribeFirebaseTokensResult.hpp"
#include "result/DescribeFirebaseTokensByOwnerIdResult.hpp"
#include "result/SetFirebaseTokenResult.hpp"
#include "result/SetFirebaseTokenByUserIdResult.hpp"
#include "result/GetFirebaseTokenResult.hpp"
#include "result/GetFirebaseTokenByUserIdResult.hpp"
#include "result/DeleteFirebaseTokenResult.hpp"
#include "result/DeleteFirebaseTokenByUserIdResult.hpp"
#include "result/SendMobileNotificationByUserIdResult.hpp"
#include <cstring>
#include <network/HttpRequest.h>

namespace gs2 { namespace gateway {

typedef AsyncResult<DescribeNamespacesResult> AsyncDescribeNamespacesResult;
typedef AsyncResult<CreateNamespaceResult> AsyncCreateNamespaceResult;
typedef AsyncResult<GetNamespaceStatusResult> AsyncGetNamespaceStatusResult;
typedef AsyncResult<GetNamespaceResult> AsyncGetNamespaceResult;
typedef AsyncResult<UpdateNamespaceResult> AsyncUpdateNamespaceResult;
typedef AsyncResult<void> AsyncDeleteNamespaceResult;
typedef AsyncResult<DescribeWebsocketSessionsResult> AsyncDescribeWebsocketSessionsResult;
typedef AsyncResult<DescribeWebsocketSessionsByOwnerIdResult> AsyncDescribeWebsocketSessionsByOwnerIdResult;
typedef AsyncResult<DescribeWebsocketSessionsByUserIdResult> AsyncDescribeWebsocketSessionsByUserIdResult;
typedef AsyncResult<DescribeWebsocketSessionsByOwnerIdAndUserIdResult> AsyncDescribeWebsocketSessionsByOwnerIdAndUserIdResult;
typedef AsyncResult<SetUserIdResult> AsyncSetUserIdResult;
typedef AsyncResult<GetSessionResult> AsyncGetSessionResult;
typedef AsyncResult<DeleteUserIdResult> AsyncDeleteUserIdResult;
typedef AsyncResult<SendNotificationResult> AsyncSendNotificationResult;
typedef AsyncResult<SendNotificationBySystemResult> AsyncSendNotificationBySystemResult;
typedef AsyncResult<DescribeFirebaseTokensResult> AsyncDescribeFirebaseTokensResult;
typedef AsyncResult<DescribeFirebaseTokensByOwnerIdResult> AsyncDescribeFirebaseTokensByOwnerIdResult;
typedef AsyncResult<SetFirebaseTokenResult> AsyncSetFirebaseTokenResult;
typedef AsyncResult<SetFirebaseTokenByUserIdResult> AsyncSetFirebaseTokenByUserIdResult;
typedef AsyncResult<GetFirebaseTokenResult> AsyncGetFirebaseTokenResult;
typedef AsyncResult<GetFirebaseTokenByUserIdResult> AsyncGetFirebaseTokenByUserIdResult;
typedef AsyncResult<DeleteFirebaseTokenResult> AsyncDeleteFirebaseTokenResult;
typedef AsyncResult<DeleteFirebaseTokenByUserIdResult> AsyncDeleteFirebaseTokenByUserIdResult;
typedef AsyncResult<SendMobileNotificationByUserIdResult> AsyncSendMobileNotificationByUserIdResult;

/**
 * GS2 Gateway API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2GatewayWebSocketClient : public AbstractGs2ClientBase
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
            writer.writeCharArray("gateway");
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
            if (m_Request.getFirebaseSecret())
            {
                writer.writePropertyName("firebaseSecret");
                writer.writeCharArray(*m_Request.getFirebaseSecret());
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
            writer.writeCharArray("gateway");
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
            writer.writeCharArray("gateway");
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
            writer.writeCharArray("gateway");
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
            if (m_Request.getFirebaseSecret())
            {
                writer.writePropertyName("firebaseSecret");
                writer.writeCharArray(*m_Request.getFirebaseSecret());
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
            writer.writeCharArray("gateway");
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
            writer.writeCharArray("gateway");
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

    class DescribeWebsocketSessionsTask : public detail::Gs2WebSocketSessionTask<DescribeWebsocketSessionsResult>
    {
    private:
        DescribeWebsocketSessionsRequest& m_Request;

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
            writer.writeCharArray("gateway");
            writer.writePropertyName("component");
            writer.writeCharArray("websocketSession");
            writer.writePropertyName("function");
            writer.writeCharArray("describeWebsocketSessions");
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
        DescribeWebsocketSessionsTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeWebsocketSessionsRequest& request,
            Gs2WebSocketSessionTask<DescribeWebsocketSessionsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeWebsocketSessionsResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeWebsocketSessionsTask() GS2_OVERRIDE = default;
    };

    class DescribeWebsocketSessionsByOwnerIdTask : public detail::Gs2WebSocketSessionTask<DescribeWebsocketSessionsByOwnerIdResult>
    {
    private:
        DescribeWebsocketSessionsByOwnerIdRequest& m_Request;

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
            if (m_Request.getOwnerId())
            {
                writer.writePropertyName("ownerId");
                writer.writeCharArray(*m_Request.getOwnerId());
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
            writer.writeCharArray("gateway");
            writer.writePropertyName("component");
            writer.writeCharArray("websocketSession");
            writer.writePropertyName("function");
            writer.writeCharArray("describeWebsocketSessionsByOwnerId");
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
        DescribeWebsocketSessionsByOwnerIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeWebsocketSessionsByOwnerIdRequest& request,
            Gs2WebSocketSessionTask<DescribeWebsocketSessionsByOwnerIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeWebsocketSessionsByOwnerIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeWebsocketSessionsByOwnerIdTask() GS2_OVERRIDE = default;
    };

    class DescribeWebsocketSessionsByUserIdTask : public detail::Gs2WebSocketSessionTask<DescribeWebsocketSessionsByUserIdResult>
    {
    private:
        DescribeWebsocketSessionsByUserIdRequest& m_Request;

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
            writer.writeCharArray("gateway");
            writer.writePropertyName("component");
            writer.writeCharArray("websocketSession");
            writer.writePropertyName("function");
            writer.writeCharArray("describeWebsocketSessionsByUserId");
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
        DescribeWebsocketSessionsByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeWebsocketSessionsByUserIdRequest& request,
            Gs2WebSocketSessionTask<DescribeWebsocketSessionsByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeWebsocketSessionsByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeWebsocketSessionsByUserIdTask() GS2_OVERRIDE = default;
    };

    class DescribeWebsocketSessionsByOwnerIdAndUserIdTask : public detail::Gs2WebSocketSessionTask<DescribeWebsocketSessionsByOwnerIdAndUserIdResult>
    {
    private:
        DescribeWebsocketSessionsByOwnerIdAndUserIdRequest& m_Request;

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
            writer.writeCharArray("gateway");
            writer.writePropertyName("component");
            writer.writeCharArray("websocketSession");
            writer.writePropertyName("function");
            writer.writeCharArray("describeWebsocketSessionsByOwnerIdAndUserId");
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
        DescribeWebsocketSessionsByOwnerIdAndUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeWebsocketSessionsByOwnerIdAndUserIdRequest& request,
            Gs2WebSocketSessionTask<DescribeWebsocketSessionsByOwnerIdAndUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeWebsocketSessionsByOwnerIdAndUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeWebsocketSessionsByOwnerIdAndUserIdTask() GS2_OVERRIDE = default;
    };

    class SetUserIdTask : public detail::Gs2WebSocketSessionTask<SetUserIdResult>
    {
    private:
        SetUserIdRequest& m_Request;

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
            if (m_Request.getAllowConcurrentAccess())
            {
                writer.writePropertyName("allowConcurrentAccess");
                writer.writeBool(*m_Request.getAllowConcurrentAccess());
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
            writer.writeCharArray("gateway");
            writer.writePropertyName("component");
            writer.writeCharArray("websocketSession");
            writer.writePropertyName("function");
            writer.writeCharArray("setUserId");
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
        SetUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            SetUserIdRequest& request,
            Gs2WebSocketSessionTask<SetUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<SetUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~SetUserIdTask() GS2_OVERRIDE = default;
    };

    class GetSessionTask : public detail::Gs2WebSocketSessionTask<GetSessionResult>
    {
    private:
        GetSessionRequest& m_Request;

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
            writer.writeCharArray("gateway");
            writer.writePropertyName("component");
            writer.writeCharArray("websocketSession");
            writer.writePropertyName("function");
            writer.writeCharArray("getSession");
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
        GetSessionTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetSessionRequest& request,
            Gs2WebSocketSessionTask<GetSessionResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetSessionResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetSessionTask() GS2_OVERRIDE = default;
    };

    class DeleteUserIdTask : public detail::Gs2WebSocketSessionTask<DeleteUserIdResult>
    {
    private:
        DeleteUserIdRequest& m_Request;

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
            writer.writeCharArray("gateway");
            writer.writePropertyName("component");
            writer.writeCharArray("websocketSession");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteUserId");
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
        DeleteUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteUserIdRequest& request,
            Gs2WebSocketSessionTask<DeleteUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteUserIdTask() GS2_OVERRIDE = default;
    };

    class SendNotificationTask : public detail::Gs2WebSocketSessionTask<SendNotificationResult>
    {
    private:
        SendNotificationRequest& m_Request;

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
            if (m_Request.getSubject())
            {
                writer.writePropertyName("subject");
                writer.writeCharArray(*m_Request.getSubject());
            }
            if (m_Request.getPayload())
            {
                writer.writePropertyName("payload");
                writer.writeCharArray(*m_Request.getPayload());
            }
            if (m_Request.getEnableTransferMobileNotification())
            {
                writer.writePropertyName("enableTransferMobileNotification");
                writer.writeBool(*m_Request.getEnableTransferMobileNotification());
            }
            if (m_Request.getSound())
            {
                writer.writePropertyName("sound");
                writer.writeCharArray(*m_Request.getSound());
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
            writer.writeCharArray("gateway");
            writer.writePropertyName("component");
            writer.writeCharArray("websocketSession");
            writer.writePropertyName("function");
            writer.writeCharArray("sendNotification");
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
        SendNotificationTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            SendNotificationRequest& request,
            Gs2WebSocketSessionTask<SendNotificationResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<SendNotificationResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~SendNotificationTask() GS2_OVERRIDE = default;
    };

    class SendNotificationBySystemTask : public detail::Gs2WebSocketSessionTask<SendNotificationBySystemResult>
    {
    private:
        SendNotificationBySystemRequest& m_Request;

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
            if (m_Request.getIssuer())
            {
                writer.writePropertyName("issuer");
                writer.writeCharArray(*m_Request.getIssuer());
            }
            if (m_Request.getSubject())
            {
                writer.writePropertyName("subject");
                writer.writeCharArray(*m_Request.getSubject());
            }
            if (m_Request.getPayload())
            {
                writer.writePropertyName("payload");
                writer.writeCharArray(*m_Request.getPayload());
            }
            if (m_Request.getEnableTransferMobileNotification())
            {
                writer.writePropertyName("enableTransferMobileNotification");
                writer.writeBool(*m_Request.getEnableTransferMobileNotification());
            }
            if (m_Request.getSound())
            {
                writer.writePropertyName("sound");
                writer.writeCharArray(*m_Request.getSound());
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
            writer.writeCharArray("gateway");
            writer.writePropertyName("component");
            writer.writeCharArray("websocketSession");
            writer.writePropertyName("function");
            writer.writeCharArray("sendNotificationBySystem");
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
        SendNotificationBySystemTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            SendNotificationBySystemRequest& request,
            Gs2WebSocketSessionTask<SendNotificationBySystemResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<SendNotificationBySystemResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~SendNotificationBySystemTask() GS2_OVERRIDE = default;
    };

    class DescribeFirebaseTokensTask : public detail::Gs2WebSocketSessionTask<DescribeFirebaseTokensResult>
    {
    private:
        DescribeFirebaseTokensRequest& m_Request;

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
            writer.writeCharArray("gateway");
            writer.writePropertyName("component");
            writer.writeCharArray("firebaseToken");
            writer.writePropertyName("function");
            writer.writeCharArray("describeFirebaseTokens");
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
        DescribeFirebaseTokensTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeFirebaseTokensRequest& request,
            Gs2WebSocketSessionTask<DescribeFirebaseTokensResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeFirebaseTokensResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeFirebaseTokensTask() GS2_OVERRIDE = default;
    };

    class DescribeFirebaseTokensByOwnerIdTask : public detail::Gs2WebSocketSessionTask<DescribeFirebaseTokensByOwnerIdResult>
    {
    private:
        DescribeFirebaseTokensByOwnerIdRequest& m_Request;

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
            if (m_Request.getOwnerId())
            {
                writer.writePropertyName("ownerId");
                writer.writeCharArray(*m_Request.getOwnerId());
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
            writer.writeCharArray("gateway");
            writer.writePropertyName("component");
            writer.writeCharArray("firebaseToken");
            writer.writePropertyName("function");
            writer.writeCharArray("describeFirebaseTokensByOwnerId");
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
        DescribeFirebaseTokensByOwnerIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeFirebaseTokensByOwnerIdRequest& request,
            Gs2WebSocketSessionTask<DescribeFirebaseTokensByOwnerIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeFirebaseTokensByOwnerIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeFirebaseTokensByOwnerIdTask() GS2_OVERRIDE = default;
    };

    class SetFirebaseTokenTask : public detail::Gs2WebSocketSessionTask<SetFirebaseTokenResult>
    {
    private:
        SetFirebaseTokenRequest& m_Request;

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
            if (m_Request.getToken())
            {
                writer.writePropertyName("token");
                writer.writeCharArray(*m_Request.getToken());
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
            writer.writeCharArray("gateway");
            writer.writePropertyName("component");
            writer.writeCharArray("firebaseToken");
            writer.writePropertyName("function");
            writer.writeCharArray("setFirebaseToken");
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
        SetFirebaseTokenTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            SetFirebaseTokenRequest& request,
            Gs2WebSocketSessionTask<SetFirebaseTokenResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<SetFirebaseTokenResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~SetFirebaseTokenTask() GS2_OVERRIDE = default;
    };

    class SetFirebaseTokenByUserIdTask : public detail::Gs2WebSocketSessionTask<SetFirebaseTokenByUserIdResult>
    {
    private:
        SetFirebaseTokenByUserIdRequest& m_Request;

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
            if (m_Request.getToken())
            {
                writer.writePropertyName("token");
                writer.writeCharArray(*m_Request.getToken());
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
            writer.writeCharArray("gateway");
            writer.writePropertyName("component");
            writer.writeCharArray("firebaseToken");
            writer.writePropertyName("function");
            writer.writeCharArray("setFirebaseTokenByUserId");
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
        SetFirebaseTokenByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            SetFirebaseTokenByUserIdRequest& request,
            Gs2WebSocketSessionTask<SetFirebaseTokenByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<SetFirebaseTokenByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~SetFirebaseTokenByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetFirebaseTokenTask : public detail::Gs2WebSocketSessionTask<GetFirebaseTokenResult>
    {
    private:
        GetFirebaseTokenRequest& m_Request;

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
            writer.writeCharArray("gateway");
            writer.writePropertyName("component");
            writer.writeCharArray("firebaseToken");
            writer.writePropertyName("function");
            writer.writeCharArray("getFirebaseToken");
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
        GetFirebaseTokenTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetFirebaseTokenRequest& request,
            Gs2WebSocketSessionTask<GetFirebaseTokenResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetFirebaseTokenResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetFirebaseTokenTask() GS2_OVERRIDE = default;
    };

    class GetFirebaseTokenByUserIdTask : public detail::Gs2WebSocketSessionTask<GetFirebaseTokenByUserIdResult>
    {
    private:
        GetFirebaseTokenByUserIdRequest& m_Request;

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
            writer.writeCharArray("gateway");
            writer.writePropertyName("component");
            writer.writeCharArray("firebaseToken");
            writer.writePropertyName("function");
            writer.writeCharArray("getFirebaseTokenByUserId");
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
        GetFirebaseTokenByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetFirebaseTokenByUserIdRequest& request,
            Gs2WebSocketSessionTask<GetFirebaseTokenByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetFirebaseTokenByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetFirebaseTokenByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteFirebaseTokenTask : public detail::Gs2WebSocketSessionTask<DeleteFirebaseTokenResult>
    {
    private:
        DeleteFirebaseTokenRequest& m_Request;

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
            writer.writeCharArray("gateway");
            writer.writePropertyName("component");
            writer.writeCharArray("firebaseToken");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteFirebaseToken");
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
        DeleteFirebaseTokenTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteFirebaseTokenRequest& request,
            Gs2WebSocketSessionTask<DeleteFirebaseTokenResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteFirebaseTokenResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteFirebaseTokenTask() GS2_OVERRIDE = default;
    };

    class DeleteFirebaseTokenByUserIdTask : public detail::Gs2WebSocketSessionTask<DeleteFirebaseTokenByUserIdResult>
    {
    private:
        DeleteFirebaseTokenByUserIdRequest& m_Request;

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
            writer.writeCharArray("gateway");
            writer.writePropertyName("component");
            writer.writeCharArray("firebaseToken");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteFirebaseTokenByUserId");
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
        DeleteFirebaseTokenByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteFirebaseTokenByUserIdRequest& request,
            Gs2WebSocketSessionTask<DeleteFirebaseTokenByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteFirebaseTokenByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteFirebaseTokenByUserIdTask() GS2_OVERRIDE = default;
    };

    class SendMobileNotificationByUserIdTask : public detail::Gs2WebSocketSessionTask<SendMobileNotificationByUserIdResult>
    {
    private:
        SendMobileNotificationByUserIdRequest& m_Request;

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
            if (m_Request.getSubject())
            {
                writer.writePropertyName("subject");
                writer.writeCharArray(*m_Request.getSubject());
            }
            if (m_Request.getMetadata())
            {
                writer.writePropertyName("metadata");
                writer.writeCharArray(*m_Request.getMetadata());
            }
            if (m_Request.getSound())
            {
                writer.writePropertyName("sound");
                writer.writeCharArray(*m_Request.getSound());
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
            writer.writeCharArray("gateway");
            writer.writePropertyName("component");
            writer.writeCharArray("firebaseToken");
            writer.writePropertyName("function");
            writer.writeCharArray("sendMobileNotificationByUserId");
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
        SendMobileNotificationByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            SendMobileNotificationByUserIdRequest& request,
            Gs2WebSocketSessionTask<SendMobileNotificationByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<SendMobileNotificationByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~SendMobileNotificationByUserIdTask() GS2_OVERRIDE = default;
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
        if (obj.getFirebaseSecret())
        {
            writer.writePropertyName("firebaseSecret");
            writer.writeCharArray(*obj.getFirebaseSecret());
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

    static void write(detail::json::JsonWriter& writer, const WebsocketSession& obj)
    {
        writer.writeObjectStart();
        if (obj.getWebsocketSessionId())
        {
            writer.writePropertyName("websocketSessionId");
            writer.writeCharArray(*obj.getWebsocketSessionId());
        }
        if (obj.getOwnerId())
        {
            writer.writePropertyName("ownerId");
            writer.writeCharArray(*obj.getOwnerId());
        }
        if (obj.getConnectionId())
        {
            writer.writePropertyName("connectionId");
            writer.writeCharArray(*obj.getConnectionId());
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
        if (obj.getUpdatedAt())
        {
            writer.writePropertyName("updatedAt");
            writer.writeInt64(*obj.getUpdatedAt());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const FirebaseToken& obj)
    {
        writer.writeObjectStart();
        if (obj.getFirebaseTokenId())
        {
            writer.writePropertyName("firebaseTokenId");
            writer.writeCharArray(*obj.getFirebaseTokenId());
        }
        if (obj.getOwnerId())
        {
            writer.writePropertyName("ownerId");
            writer.writeCharArray(*obj.getOwnerId());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.writeCharArray(*obj.getUserId());
        }
        if (obj.getToken())
        {
            writer.writePropertyName("token");
            writer.writeCharArray(*obj.getToken());
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
    explicit Gs2GatewayWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
        AbstractGs2ClientBase(gs2WebSocketSession)
    {
    }

	/**
	 * ゲームの一覧を取得<br>
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
	 * ゲームを新規作成<br>
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
	 * ゲームを取得<br>
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
	 * ゲームを取得<br>
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
	 * ゲームを更新<br>
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
	 * ゲームを削除<br>
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
	 * Websocketセッションを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeWebsocketSessions(std::function<void(AsyncDescribeWebsocketSessionsResult&)> callback, DescribeWebsocketSessionsRequest& request)
    {
        DescribeWebsocketSessionsTask& task = *new DescribeWebsocketSessionsTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * Websocketセッションを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeWebsocketSessionsByOwnerId(std::function<void(AsyncDescribeWebsocketSessionsByOwnerIdResult&)> callback, DescribeWebsocketSessionsByOwnerIdRequest& request)
    {
        DescribeWebsocketSessionsByOwnerIdTask& task = *new DescribeWebsocketSessionsByOwnerIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * Websocketセッションを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeWebsocketSessionsByUserId(std::function<void(AsyncDescribeWebsocketSessionsByUserIdResult&)> callback, DescribeWebsocketSessionsByUserIdRequest& request)
    {
        DescribeWebsocketSessionsByUserIdTask& task = *new DescribeWebsocketSessionsByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * Websocketセッションを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeWebsocketSessionsByOwnerIdAndUserId(std::function<void(AsyncDescribeWebsocketSessionsByOwnerIdAndUserIdResult&)> callback, DescribeWebsocketSessionsByOwnerIdAndUserIdRequest& request)
    {
        DescribeWebsocketSessionsByOwnerIdAndUserIdTask& task = *new DescribeWebsocketSessionsByOwnerIdAndUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * Websocketセッションを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setUserId(std::function<void(AsyncSetUserIdResult&)> callback, SetUserIdRequest& request)
    {
        SetUserIdTask& task = *new SetUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * Websocketセッションを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getSession(std::function<void(AsyncGetSessionResult&)> callback, GetSessionRequest& request)
    {
        GetSessionTask& task = *new GetSessionTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * Websocketセッションを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteUserId(std::function<void(AsyncDeleteUserIdResult&)> callback, DeleteUserIdRequest& request)
    {
        DeleteUserIdTask& task = *new DeleteUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * Websocketセッションを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void sendNotification(std::function<void(AsyncSendNotificationResult&)> callback, SendNotificationRequest& request)
    {
        SendNotificationTask& task = *new SendNotificationTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * Websocketセッションを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void sendNotificationBySystem(std::function<void(AsyncSendNotificationBySystemResult&)> callback, SendNotificationBySystemRequest& request)
    {
        SendNotificationBySystemTask& task = *new SendNotificationBySystemTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * Firebaseデバイストークンを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeFirebaseTokens(std::function<void(AsyncDescribeFirebaseTokensResult&)> callback, DescribeFirebaseTokensRequest& request)
    {
        DescribeFirebaseTokensTask& task = *new DescribeFirebaseTokensTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * Firebaseデバイストークンを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeFirebaseTokensByOwnerId(std::function<void(AsyncDescribeFirebaseTokensByOwnerIdResult&)> callback, DescribeFirebaseTokensByOwnerIdRequest& request)
    {
        DescribeFirebaseTokensByOwnerIdTask& task = *new DescribeFirebaseTokensByOwnerIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * Firebaseデバイストークンを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setFirebaseToken(std::function<void(AsyncSetFirebaseTokenResult&)> callback, SetFirebaseTokenRequest& request)
    {
        SetFirebaseTokenTask& task = *new SetFirebaseTokenTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * Firebaseデバイストークンを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setFirebaseTokenByUserId(std::function<void(AsyncSetFirebaseTokenByUserIdResult&)> callback, SetFirebaseTokenByUserIdRequest& request)
    {
        SetFirebaseTokenByUserIdTask& task = *new SetFirebaseTokenByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * Firebaseデバイストークンを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getFirebaseToken(std::function<void(AsyncGetFirebaseTokenResult&)> callback, GetFirebaseTokenRequest& request)
    {
        GetFirebaseTokenTask& task = *new GetFirebaseTokenTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * Firebaseデバイストークンを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getFirebaseTokenByUserId(std::function<void(AsyncGetFirebaseTokenByUserIdResult&)> callback, GetFirebaseTokenByUserIdRequest& request)
    {
        GetFirebaseTokenByUserIdTask& task = *new GetFirebaseTokenByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * Firebaseデバイストークンを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteFirebaseToken(std::function<void(AsyncDeleteFirebaseTokenResult&)> callback, DeleteFirebaseTokenRequest& request)
    {
        DeleteFirebaseTokenTask& task = *new DeleteFirebaseTokenTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * Firebaseデバイストークンを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteFirebaseTokenByUserId(std::function<void(AsyncDeleteFirebaseTokenByUserIdResult&)> callback, DeleteFirebaseTokenByUserIdRequest& request)
    {
        DeleteFirebaseTokenByUserIdTask& task = *new DeleteFirebaseTokenByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * Firebaseデバイストークンを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void sendMobileNotificationByUserId(std::function<void(AsyncSendMobileNotificationByUserIdResult&)> callback, SendMobileNotificationByUserIdRequest& request)
    {
        SendMobileNotificationByUserIdTask& task = *new SendMobileNotificationByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_GATEWAY_GS2GATEWAYWEBSOCKETCLIENT_HPP_