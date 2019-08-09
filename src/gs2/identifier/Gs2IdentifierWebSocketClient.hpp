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

#ifndef GS2_IDENTIFIER_GS2IDENTIFIERWEBSOCKETCLIENT_HPP_
#define GS2_IDENTIFIER_GS2IDENTIFIERWEBSOCKETCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2WebSocketSessionTask.hpp>
#include <gs2/core/network/Gs2WebSocketSession.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "model/model.hpp"
#include "request/DescribeUsersRequest.hpp"
#include "request/CreateUserRequest.hpp"
#include "request/UpdateUserRequest.hpp"
#include "request/GetUserRequest.hpp"
#include "request/DeleteUserRequest.hpp"
#include "request/DescribeSecurityPoliciesRequest.hpp"
#include "request/DescribeCommonSecurityPoliciesRequest.hpp"
#include "request/CreateSecurityPolicyRequest.hpp"
#include "request/UpdateSecurityPolicyRequest.hpp"
#include "request/GetSecurityPolicyRequest.hpp"
#include "request/DeleteSecurityPolicyRequest.hpp"
#include "request/DescribeIdentifiersRequest.hpp"
#include "request/CreateIdentifierRequest.hpp"
#include "request/GetIdentifierRequest.hpp"
#include "request/DeleteIdentifierRequest.hpp"
#include "request/GetHasSecurityPolicyRequest.hpp"
#include "request/AttachSecurityPolicyRequest.hpp"
#include "request/DetachSecurityPolicyRequest.hpp"
#include "request/LoginRequest.hpp"
#include "result/DescribeUsersResult.hpp"
#include "result/CreateUserResult.hpp"
#include "result/UpdateUserResult.hpp"
#include "result/GetUserResult.hpp"
#include "result/DeleteUserResult.hpp"
#include "result/DescribeSecurityPoliciesResult.hpp"
#include "result/DescribeCommonSecurityPoliciesResult.hpp"
#include "result/CreateSecurityPolicyResult.hpp"
#include "result/UpdateSecurityPolicyResult.hpp"
#include "result/GetSecurityPolicyResult.hpp"
#include "result/DeleteSecurityPolicyResult.hpp"
#include "result/DescribeIdentifiersResult.hpp"
#include "result/CreateIdentifierResult.hpp"
#include "result/GetIdentifierResult.hpp"
#include "result/DeleteIdentifierResult.hpp"
#include "result/GetHasSecurityPolicyResult.hpp"
#include "result/AttachSecurityPolicyResult.hpp"
#include "result/DetachSecurityPolicyResult.hpp"
#include "result/LoginResult.hpp"
#include <cstring>

namespace gs2 { namespace identifier {

typedef AsyncResult<DescribeUsersResult> AsyncDescribeUsersResult;
typedef AsyncResult<CreateUserResult> AsyncCreateUserResult;
typedef AsyncResult<UpdateUserResult> AsyncUpdateUserResult;
typedef AsyncResult<GetUserResult> AsyncGetUserResult;
typedef AsyncResult<void> AsyncDeleteUserResult;
typedef AsyncResult<DescribeSecurityPoliciesResult> AsyncDescribeSecurityPoliciesResult;
typedef AsyncResult<DescribeCommonSecurityPoliciesResult> AsyncDescribeCommonSecurityPoliciesResult;
typedef AsyncResult<CreateSecurityPolicyResult> AsyncCreateSecurityPolicyResult;
typedef AsyncResult<UpdateSecurityPolicyResult> AsyncUpdateSecurityPolicyResult;
typedef AsyncResult<GetSecurityPolicyResult> AsyncGetSecurityPolicyResult;
typedef AsyncResult<void> AsyncDeleteSecurityPolicyResult;
typedef AsyncResult<DescribeIdentifiersResult> AsyncDescribeIdentifiersResult;
typedef AsyncResult<CreateIdentifierResult> AsyncCreateIdentifierResult;
typedef AsyncResult<GetIdentifierResult> AsyncGetIdentifierResult;
typedef AsyncResult<void> AsyncDeleteIdentifierResult;
typedef AsyncResult<GetHasSecurityPolicyResult> AsyncGetHasSecurityPolicyResult;
typedef AsyncResult<AttachSecurityPolicyResult> AsyncAttachSecurityPolicyResult;
typedef AsyncResult<DetachSecurityPolicyResult> AsyncDetachSecurityPolicyResult;
typedef AsyncResult<LoginResult> AsyncLoginResult;

/**
 * GS2 Identifier API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2IdentifierWebSocketClient : public AbstractGs2ClientBase
{
private:

    class DescribeUsersTask : public detail::Gs2WebSocketSessionTask<DescribeUsersResult>
    {
    private:
        DescribeUsersRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

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
            writer.writeCharArray("identifier");
            writer.writePropertyName("component");
            writer.writeCharArray("user");
            writer.writePropertyName("function");
            writer.writeCharArray("describeUsers");
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
        DescribeUsersTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeUsersRequest& request,
            Gs2WebSocketSessionTask<DescribeUsersResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeUsersResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeUsersTask() GS2_OVERRIDE = default;
    };

    class CreateUserTask : public detail::Gs2WebSocketSessionTask<CreateUserResult>
    {
    private:
        CreateUserRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

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
            writer.writeCharArray("identifier");
            writer.writePropertyName("component");
            writer.writeCharArray("user");
            writer.writePropertyName("function");
            writer.writeCharArray("createUser");
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
        CreateUserTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            CreateUserRequest& request,
            Gs2WebSocketSessionTask<CreateUserResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateUserResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~CreateUserTask() GS2_OVERRIDE = default;
    };

    class UpdateUserTask : public detail::Gs2WebSocketSessionTask<UpdateUserResult>
    {
    private:
        UpdateUserRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getUserName())
            {
                writer.writePropertyName("userName");
                writer.writeCharArray(*m_Request.getUserName());
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
            writer.writeCharArray("identifier");
            writer.writePropertyName("component");
            writer.writeCharArray("user");
            writer.writePropertyName("function");
            writer.writeCharArray("updateUser");
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
        UpdateUserTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateUserRequest& request,
            Gs2WebSocketSessionTask<UpdateUserResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateUserResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateUserTask() GS2_OVERRIDE = default;
    };

    class GetUserTask : public detail::Gs2WebSocketSessionTask<GetUserResult>
    {
    private:
        GetUserRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getUserName())
            {
                writer.writePropertyName("userName");
                writer.writeCharArray(*m_Request.getUserName());
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
            writer.writeCharArray("identifier");
            writer.writePropertyName("component");
            writer.writeCharArray("user");
            writer.writePropertyName("function");
            writer.writeCharArray("getUser");
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
        GetUserTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetUserRequest& request,
            Gs2WebSocketSessionTask<GetUserResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetUserResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetUserTask() GS2_OVERRIDE = default;
    };

    class DeleteUserTask : public detail::Gs2WebSocketSessionTask<void>
    {
    private:
        DeleteUserRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getUserName())
            {
                writer.writePropertyName("userName");
                writer.writeCharArray(*m_Request.getUserName());
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
            writer.writeCharArray("identifier");
            writer.writePropertyName("component");
            writer.writeCharArray("user");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteUser");
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
        DeleteUserTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteUserRequest& request,
            Gs2WebSocketSessionTask<void>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<void>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteUserTask() GS2_OVERRIDE = default;
    };

    class DescribeSecurityPoliciesTask : public detail::Gs2WebSocketSessionTask<DescribeSecurityPoliciesResult>
    {
    private:
        DescribeSecurityPoliciesRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

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
            writer.writeCharArray("identifier");
            writer.writePropertyName("component");
            writer.writeCharArray("securityPolicy");
            writer.writePropertyName("function");
            writer.writeCharArray("describeSecurityPolicies");
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
        DescribeSecurityPoliciesTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeSecurityPoliciesRequest& request,
            Gs2WebSocketSessionTask<DescribeSecurityPoliciesResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeSecurityPoliciesResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeSecurityPoliciesTask() GS2_OVERRIDE = default;
    };

    class DescribeCommonSecurityPoliciesTask : public detail::Gs2WebSocketSessionTask<DescribeCommonSecurityPoliciesResult>
    {
    private:
        DescribeCommonSecurityPoliciesRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

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
            writer.writeCharArray("identifier");
            writer.writePropertyName("component");
            writer.writeCharArray("securityPolicy");
            writer.writePropertyName("function");
            writer.writeCharArray("describeCommonSecurityPolicies");
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
        DescribeCommonSecurityPoliciesTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeCommonSecurityPoliciesRequest& request,
            Gs2WebSocketSessionTask<DescribeCommonSecurityPoliciesResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeCommonSecurityPoliciesResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeCommonSecurityPoliciesTask() GS2_OVERRIDE = default;
    };

    class CreateSecurityPolicyTask : public detail::Gs2WebSocketSessionTask<CreateSecurityPolicyResult>
    {
    private:
        CreateSecurityPolicyRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

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
            if (m_Request.getPolicy())
            {
                writer.writePropertyName("policy");
                writer.writeCharArray(*m_Request.getPolicy());
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
            writer.writeCharArray("identifier");
            writer.writePropertyName("component");
            writer.writeCharArray("securityPolicy");
            writer.writePropertyName("function");
            writer.writeCharArray("createSecurityPolicy");
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
        CreateSecurityPolicyTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            CreateSecurityPolicyRequest& request,
            Gs2WebSocketSessionTask<CreateSecurityPolicyResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateSecurityPolicyResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~CreateSecurityPolicyTask() GS2_OVERRIDE = default;
    };

    class UpdateSecurityPolicyTask : public detail::Gs2WebSocketSessionTask<UpdateSecurityPolicyResult>
    {
    private:
        UpdateSecurityPolicyRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getSecurityPolicyName())
            {
                writer.writePropertyName("securityPolicyName");
                writer.writeCharArray(*m_Request.getSecurityPolicyName());
            }
            if (m_Request.getDescription())
            {
                writer.writePropertyName("description");
                writer.writeCharArray(*m_Request.getDescription());
            }
            if (m_Request.getPolicy())
            {
                writer.writePropertyName("policy");
                writer.writeCharArray(*m_Request.getPolicy());
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
            writer.writeCharArray("identifier");
            writer.writePropertyName("component");
            writer.writeCharArray("securityPolicy");
            writer.writePropertyName("function");
            writer.writeCharArray("updateSecurityPolicy");
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
        UpdateSecurityPolicyTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateSecurityPolicyRequest& request,
            Gs2WebSocketSessionTask<UpdateSecurityPolicyResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateSecurityPolicyResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateSecurityPolicyTask() GS2_OVERRIDE = default;
    };

    class GetSecurityPolicyTask : public detail::Gs2WebSocketSessionTask<GetSecurityPolicyResult>
    {
    private:
        GetSecurityPolicyRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getSecurityPolicyName())
            {
                writer.writePropertyName("securityPolicyName");
                writer.writeCharArray(*m_Request.getSecurityPolicyName());
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
            writer.writeCharArray("identifier");
            writer.writePropertyName("component");
            writer.writeCharArray("securityPolicy");
            writer.writePropertyName("function");
            writer.writeCharArray("getSecurityPolicy");
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
        GetSecurityPolicyTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetSecurityPolicyRequest& request,
            Gs2WebSocketSessionTask<GetSecurityPolicyResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetSecurityPolicyResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetSecurityPolicyTask() GS2_OVERRIDE = default;
    };

    class DeleteSecurityPolicyTask : public detail::Gs2WebSocketSessionTask<void>
    {
    private:
        DeleteSecurityPolicyRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getSecurityPolicyName())
            {
                writer.writePropertyName("securityPolicyName");
                writer.writeCharArray(*m_Request.getSecurityPolicyName());
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
            writer.writeCharArray("identifier");
            writer.writePropertyName("component");
            writer.writeCharArray("securityPolicy");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteSecurityPolicy");
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
        DeleteSecurityPolicyTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteSecurityPolicyRequest& request,
            Gs2WebSocketSessionTask<void>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<void>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteSecurityPolicyTask() GS2_OVERRIDE = default;
    };

    class DescribeIdentifiersTask : public detail::Gs2WebSocketSessionTask<DescribeIdentifiersResult>
    {
    private:
        DescribeIdentifiersRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getUserName())
            {
                writer.writePropertyName("userName");
                writer.writeCharArray(*m_Request.getUserName());
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
            writer.writeCharArray("identifier");
            writer.writePropertyName("component");
            writer.writeCharArray("identifier");
            writer.writePropertyName("function");
            writer.writeCharArray("describeIdentifiers");
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
        DescribeIdentifiersTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeIdentifiersRequest& request,
            Gs2WebSocketSessionTask<DescribeIdentifiersResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeIdentifiersResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeIdentifiersTask() GS2_OVERRIDE = default;
    };

    class CreateIdentifierTask : public detail::Gs2WebSocketSessionTask<CreateIdentifierResult>
    {
    private:
        CreateIdentifierRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getUserName())
            {
                writer.writePropertyName("userName");
                writer.writeCharArray(*m_Request.getUserName());
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
            writer.writeCharArray("identifier");
            writer.writePropertyName("component");
            writer.writeCharArray("identifier");
            writer.writePropertyName("function");
            writer.writeCharArray("createIdentifier");
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
        CreateIdentifierTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            CreateIdentifierRequest& request,
            Gs2WebSocketSessionTask<CreateIdentifierResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateIdentifierResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~CreateIdentifierTask() GS2_OVERRIDE = default;
    };

    class GetIdentifierTask : public detail::Gs2WebSocketSessionTask<GetIdentifierResult>
    {
    private:
        GetIdentifierRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getUserName())
            {
                writer.writePropertyName("userName");
                writer.writeCharArray(*m_Request.getUserName());
            }
            if (m_Request.getClientId())
            {
                writer.writePropertyName("clientId");
                writer.writeCharArray(*m_Request.getClientId());
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
            writer.writeCharArray("identifier");
            writer.writePropertyName("component");
            writer.writeCharArray("identifier");
            writer.writePropertyName("function");
            writer.writeCharArray("getIdentifier");
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
        GetIdentifierTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetIdentifierRequest& request,
            Gs2WebSocketSessionTask<GetIdentifierResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetIdentifierResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetIdentifierTask() GS2_OVERRIDE = default;
    };

    class DeleteIdentifierTask : public detail::Gs2WebSocketSessionTask<void>
    {
    private:
        DeleteIdentifierRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getUserName())
            {
                writer.writePropertyName("userName");
                writer.writeCharArray(*m_Request.getUserName());
            }
            if (m_Request.getClientId())
            {
                writer.writePropertyName("clientId");
                writer.writeCharArray(*m_Request.getClientId());
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
            writer.writeCharArray("identifier");
            writer.writePropertyName("component");
            writer.writeCharArray("identifier");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteIdentifier");
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
        DeleteIdentifierTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteIdentifierRequest& request,
            Gs2WebSocketSessionTask<void>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<void>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteIdentifierTask() GS2_OVERRIDE = default;
    };

    class GetHasSecurityPolicyTask : public detail::Gs2WebSocketSessionTask<GetHasSecurityPolicyResult>
    {
    private:
        GetHasSecurityPolicyRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getUserName())
            {
                writer.writePropertyName("userName");
                writer.writeCharArray(*m_Request.getUserName());
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
            writer.writeCharArray("identifier");
            writer.writePropertyName("component");
            writer.writeCharArray("attachSecurityPolicy");
            writer.writePropertyName("function");
            writer.writeCharArray("getHasSecurityPolicy");
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
        GetHasSecurityPolicyTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetHasSecurityPolicyRequest& request,
            Gs2WebSocketSessionTask<GetHasSecurityPolicyResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetHasSecurityPolicyResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetHasSecurityPolicyTask() GS2_OVERRIDE = default;
    };

    class AttachSecurityPolicyTask : public detail::Gs2WebSocketSessionTask<AttachSecurityPolicyResult>
    {
    private:
        AttachSecurityPolicyRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getUserName())
            {
                writer.writePropertyName("userName");
                writer.writeCharArray(*m_Request.getUserName());
            }
            if (m_Request.getSecurityPolicyId())
            {
                writer.writePropertyName("securityPolicyId");
                writer.writeCharArray(*m_Request.getSecurityPolicyId());
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
            writer.writeCharArray("identifier");
            writer.writePropertyName("component");
            writer.writeCharArray("attachSecurityPolicy");
            writer.writePropertyName("function");
            writer.writeCharArray("attachSecurityPolicy");
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
        AttachSecurityPolicyTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            AttachSecurityPolicyRequest& request,
            Gs2WebSocketSessionTask<AttachSecurityPolicyResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<AttachSecurityPolicyResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~AttachSecurityPolicyTask() GS2_OVERRIDE = default;
    };

    class DetachSecurityPolicyTask : public detail::Gs2WebSocketSessionTask<DetachSecurityPolicyResult>
    {
    private:
        DetachSecurityPolicyRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getUserName())
            {
                writer.writePropertyName("userName");
                writer.writeCharArray(*m_Request.getUserName());
            }
            if (m_Request.getSecurityPolicyId())
            {
                writer.writePropertyName("securityPolicyId");
                writer.writeCharArray(*m_Request.getSecurityPolicyId());
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
            writer.writeCharArray("identifier");
            writer.writePropertyName("component");
            writer.writeCharArray("attachSecurityPolicy");
            writer.writePropertyName("function");
            writer.writeCharArray("detachSecurityPolicy");
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
        DetachSecurityPolicyTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DetachSecurityPolicyRequest& request,
            Gs2WebSocketSessionTask<DetachSecurityPolicyResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DetachSecurityPolicyResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DetachSecurityPolicyTask() GS2_OVERRIDE = default;
    };

    class LoginTask : public detail::Gs2WebSocketSessionTask<LoginResult>
    {
    private:
        LoginRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getClientId())
            {
                writer.writePropertyName("clientId");
                writer.writeCharArray(*m_Request.getClientId());
            }
            if (m_Request.getClientSecret())
            {
                writer.writePropertyName("clientSecret");
                writer.writeCharArray(*m_Request.getClientSecret());
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
            writer.writeCharArray("identifier");
            writer.writePropertyName("component");
            writer.writeCharArray("projectToken");
            writer.writePropertyName("function");
            writer.writeCharArray("login");
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
        LoginTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            LoginRequest& request,
            Gs2WebSocketSessionTask<LoginResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<LoginResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~LoginTask() GS2_OVERRIDE = default;
    };

private:
    static void write(detail::json::JsonWriter& writer, const User& obj)
    {
        writer.writeObjectStart();
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.writeCharArray(*obj.getUserId());
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

    static void write(detail::json::JsonWriter& writer, const SecurityPolicy& obj)
    {
        writer.writeObjectStart();
        if (obj.getSecurityPolicyId())
        {
            writer.writePropertyName("securityPolicyId");
            writer.writeCharArray(*obj.getSecurityPolicyId());
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
        if (obj.getPolicy())
        {
            writer.writePropertyName("policy");
            writer.writeCharArray(*obj.getPolicy());
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

    static void write(detail::json::JsonWriter& writer, const Identifier& obj)
    {
        writer.writeObjectStart();
        if (obj.getOwnerId())
        {
            writer.writePropertyName("ownerId");
            writer.writeCharArray(*obj.getOwnerId());
        }
        if (obj.getClientId())
        {
            writer.writePropertyName("clientId");
            writer.writeCharArray(*obj.getClientId());
        }
        if (obj.getUserName())
        {
            writer.writePropertyName("userName");
            writer.writeCharArray(*obj.getUserName());
        }
        if (obj.getClientSecret())
        {
            writer.writePropertyName("clientSecret");
            writer.writeCharArray(*obj.getClientSecret());
        }
        if (obj.getCreatedAt())
        {
            writer.writePropertyName("createdAt");
            writer.writeInt64(*obj.getCreatedAt());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const AttachSecurityPolicy& obj)
    {
        writer.writeObjectStart();
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.writeCharArray(*obj.getUserId());
        }
        if (obj.getSecurityPolicyIds())
        {
            writer.writePropertyName("securityPolicyIds");
            writer.writeArrayStart();
            auto& list = *obj.getSecurityPolicyIds();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                writer.writeCharArray(list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getAttachedAt())
        {
            writer.writePropertyName("attachedAt");
            writer.writeInt64(*obj.getAttachedAt());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const ProjectToken& obj)
    {
        writer.writeObjectStart();
        if (obj.getToken())
        {
            writer.writePropertyName("token");
            writer.writeCharArray(*obj.getToken());
        }
        writer.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param gs2WebSocketSession WebSocket API 用セッション
     */
    explicit Gs2IdentifierWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
        AbstractGs2ClientBase(gs2WebSocketSession)
    {
    }

	/**
	 * ユーザの一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeUsers(std::function<void(AsyncDescribeUsersResult&)> callback, DescribeUsersRequest& request)
    {
        DescribeUsersTask& task = *new DescribeUsersTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザを新規作成します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createUser(std::function<void(AsyncCreateUserResult&)> callback, CreateUserRequest& request)
    {
        CreateUserTask& task = *new CreateUserTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateUser(std::function<void(AsyncUpdateUserResult&)> callback, UpdateUserRequest& request)
    {
        UpdateUserTask& task = *new UpdateUserTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getUser(std::function<void(AsyncGetUserResult&)> callback, GetUserRequest& request)
    {
        GetUserTask& task = *new GetUserTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザを削除します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteUser(std::function<void(AsyncDeleteUserResult&)> callback, DeleteUserRequest& request)
    {
        DeleteUserTask& task = *new DeleteUserTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * セキュリティポリシーの一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeSecurityPolicies(std::function<void(AsyncDescribeSecurityPoliciesResult&)> callback, DescribeSecurityPoliciesRequest& request)
    {
        DescribeSecurityPoliciesTask& task = *new DescribeSecurityPoliciesTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * オーナーIDを指定してセキュリティポリシーの一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCommonSecurityPolicies(std::function<void(AsyncDescribeCommonSecurityPoliciesResult&)> callback, DescribeCommonSecurityPoliciesRequest& request)
    {
        DescribeCommonSecurityPoliciesTask& task = *new DescribeCommonSecurityPoliciesTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * セキュリティポリシーを新規作成します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createSecurityPolicy(std::function<void(AsyncCreateSecurityPolicyResult&)> callback, CreateSecurityPolicyRequest& request)
    {
        CreateSecurityPolicyTask& task = *new CreateSecurityPolicyTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * セキュリティポリシーを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateSecurityPolicy(std::function<void(AsyncUpdateSecurityPolicyResult&)> callback, UpdateSecurityPolicyRequest& request)
    {
        UpdateSecurityPolicyTask& task = *new UpdateSecurityPolicyTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * セキュリティポリシーを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getSecurityPolicy(std::function<void(AsyncGetSecurityPolicyResult&)> callback, GetSecurityPolicyRequest& request)
    {
        GetSecurityPolicyTask& task = *new GetSecurityPolicyTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * セキュリティポリシーを削除します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteSecurityPolicy(std::function<void(AsyncDeleteSecurityPolicyResult&)> callback, DeleteSecurityPolicyRequest& request)
    {
        DeleteSecurityPolicyTask& task = *new DeleteSecurityPolicyTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * クレデンシャルの一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeIdentifiers(std::function<void(AsyncDescribeIdentifiersResult&)> callback, DescribeIdentifiersRequest& request)
    {
        DescribeIdentifiersTask& task = *new DescribeIdentifiersTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * クレデンシャルを新規作成します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createIdentifier(std::function<void(AsyncCreateIdentifierResult&)> callback, CreateIdentifierRequest& request)
    {
        CreateIdentifierTask& task = *new CreateIdentifierTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * クレデンシャルを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getIdentifier(std::function<void(AsyncGetIdentifierResult&)> callback, GetIdentifierRequest& request)
    {
        GetIdentifierTask& task = *new GetIdentifierTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * クレデンシャルを削除します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteIdentifier(std::function<void(AsyncDeleteIdentifierResult&)> callback, DeleteIdentifierRequest& request)
    {
        DeleteIdentifierTask& task = *new DeleteIdentifierTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 割り当てられたセキュリティポリシーの一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getHasSecurityPolicy(std::function<void(AsyncGetHasSecurityPolicyResult&)> callback, GetHasSecurityPolicyRequest& request)
    {
        GetHasSecurityPolicyTask& task = *new GetHasSecurityPolicyTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 割り当てられたセキュリティポリシーを新しくユーザーに割り当てます<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void attachSecurityPolicy(std::function<void(AsyncAttachSecurityPolicyResult&)> callback, AttachSecurityPolicyRequest& request)
    {
        AttachSecurityPolicyTask& task = *new AttachSecurityPolicyTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 割り当てられたセキュリティポリシーをユーザーから外します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void detachSecurityPolicy(std::function<void(AsyncDetachSecurityPolicyResult&)> callback, DetachSecurityPolicyRequest& request)
    {
        DetachSecurityPolicyTask& task = *new DetachSecurityPolicyTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * プロジェクトトークン を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void login(std::function<void(AsyncLoginResult&)> callback, LoginRequest& request)
    {
        LoginTask& task = *new LoginTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_IDENTIFIER_GS2IDENTIFIERWEBSOCKETCLIENT_HPP_