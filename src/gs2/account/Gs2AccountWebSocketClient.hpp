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

#ifndef GS2_ACCOUNT_GS2ACCOUNTWEBSOCKETCLIENT_HPP_
#define GS2_ACCOUNT_GS2ACCOUNTWEBSOCKETCLIENT_HPP_

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
#include "request/DescribeAccountsRequest.hpp"
#include "request/CreateAccountRequest.hpp"
#include "request/UpdateTimeOffsetRequest.hpp"
#include "request/GetAccountRequest.hpp"
#include "request/DeleteAccountRequest.hpp"
#include "request/AuthenticationRequest.hpp"
#include "request/DescribeTakeOversRequest.hpp"
#include "request/DescribeTakeOversByUserIdRequest.hpp"
#include "request/CreateTakeOverRequest.hpp"
#include "request/CreateTakeOverByUserIdRequest.hpp"
#include "request/GetTakeOverRequest.hpp"
#include "request/GetTakeOverByUserIdRequest.hpp"
#include "request/UpdateTakeOverRequest.hpp"
#include "request/UpdateTakeOverByUserIdRequest.hpp"
#include "request/DeleteTakeOverRequest.hpp"
#include "request/DeleteTakeOverByUserIdentifierRequest.hpp"
#include "request/DoTakeOverRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeAccountsResult.hpp"
#include "result/CreateAccountResult.hpp"
#include "result/UpdateTimeOffsetResult.hpp"
#include "result/GetAccountResult.hpp"
#include "result/DeleteAccountResult.hpp"
#include "result/AuthenticationResult.hpp"
#include "result/DescribeTakeOversResult.hpp"
#include "result/DescribeTakeOversByUserIdResult.hpp"
#include "result/CreateTakeOverResult.hpp"
#include "result/CreateTakeOverByUserIdResult.hpp"
#include "result/GetTakeOverResult.hpp"
#include "result/GetTakeOverByUserIdResult.hpp"
#include "result/UpdateTakeOverResult.hpp"
#include "result/UpdateTakeOverByUserIdResult.hpp"
#include "result/DeleteTakeOverResult.hpp"
#include "result/DeleteTakeOverByUserIdentifierResult.hpp"
#include "result/DoTakeOverResult.hpp"
#include <cstring>

namespace gs2 { namespace account {

/**
 * GS2 Account API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2AccountWebSocketClient : public AbstractGs2ClientBase
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
            writer.writeCharArray("account");
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
            if (m_Request.getChangePasswordIfTakeOver())
            {
                writer.writePropertyName("changePasswordIfTakeOver");
                writer.writeBool(*m_Request.getChangePasswordIfTakeOver());
            }
            if (m_Request.getCreateAccountScript())
            {
                writer.writePropertyName("createAccountScript");
                write(writer, *m_Request.getCreateAccountScript());
            }
            if (m_Request.getAuthenticationScript())
            {
                writer.writePropertyName("authenticationScript");
                write(writer, *m_Request.getAuthenticationScript());
            }
            if (m_Request.getCreateTakeOverScript())
            {
                writer.writePropertyName("createTakeOverScript");
                write(writer, *m_Request.getCreateTakeOverScript());
            }
            if (m_Request.getDoTakeOverScript())
            {
                writer.writePropertyName("doTakeOverScript");
                write(writer, *m_Request.getDoTakeOverScript());
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
            writer.writeCharArray("account");
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
            writer.writeCharArray("account");
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
            writer.writeCharArray("account");
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
            if (m_Request.getChangePasswordIfTakeOver())
            {
                writer.writePropertyName("changePasswordIfTakeOver");
                writer.writeBool(*m_Request.getChangePasswordIfTakeOver());
            }
            if (m_Request.getCreateAccountScript())
            {
                writer.writePropertyName("createAccountScript");
                write(writer, *m_Request.getCreateAccountScript());
            }
            if (m_Request.getAuthenticationScript())
            {
                writer.writePropertyName("authenticationScript");
                write(writer, *m_Request.getAuthenticationScript());
            }
            if (m_Request.getCreateTakeOverScript())
            {
                writer.writePropertyName("createTakeOverScript");
                write(writer, *m_Request.getCreateTakeOverScript());
            }
            if (m_Request.getDoTakeOverScript())
            {
                writer.writePropertyName("doTakeOverScript");
                write(writer, *m_Request.getDoTakeOverScript());
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
            writer.writeCharArray("account");
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
            writer.writeCharArray("account");
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

    class DescribeAccountsTask : public detail::Gs2WebSocketSessionTask<DescribeAccountsResult>
    {
    private:
        DescribeAccountsRequest& m_Request;

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
            writer.writeCharArray("account");
            writer.writePropertyName("component");
            writer.writeCharArray("account");
            writer.writePropertyName("function");
            writer.writeCharArray("describeAccounts");
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
        DescribeAccountsTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeAccountsRequest& request,
            Gs2WebSocketSessionTask<DescribeAccountsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeAccountsResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeAccountsTask() GS2_OVERRIDE = default;
    };

    class CreateAccountTask : public detail::Gs2WebSocketSessionTask<CreateAccountResult>
    {
    private:
        CreateAccountRequest& m_Request;

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
            writer.writeCharArray("account");
            writer.writePropertyName("component");
            writer.writeCharArray("account");
            writer.writePropertyName("function");
            writer.writeCharArray("createAccount");
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
        CreateAccountTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            CreateAccountRequest& request,
            Gs2WebSocketSessionTask<CreateAccountResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateAccountResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~CreateAccountTask() GS2_OVERRIDE = default;
    };

    class UpdateTimeOffsetTask : public detail::Gs2WebSocketSessionTask<UpdateTimeOffsetResult>
    {
    private:
        UpdateTimeOffsetRequest& m_Request;

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
            if (m_Request.getTimeOffset())
            {
                writer.writePropertyName("timeOffset");
                writer.writeInt32(*m_Request.getTimeOffset());
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
            writer.writeCharArray("account");
            writer.writePropertyName("component");
            writer.writeCharArray("account");
            writer.writePropertyName("function");
            writer.writeCharArray("updateTimeOffset");
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
        UpdateTimeOffsetTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateTimeOffsetRequest& request,
            Gs2WebSocketSessionTask<UpdateTimeOffsetResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateTimeOffsetResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateTimeOffsetTask() GS2_OVERRIDE = default;
    };

    class GetAccountTask : public detail::Gs2WebSocketSessionTask<GetAccountResult>
    {
    private:
        GetAccountRequest& m_Request;

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
            writer.writeCharArray("account");
            writer.writePropertyName("component");
            writer.writeCharArray("account");
            writer.writePropertyName("function");
            writer.writeCharArray("getAccount");
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
        GetAccountTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetAccountRequest& request,
            Gs2WebSocketSessionTask<GetAccountResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetAccountResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetAccountTask() GS2_OVERRIDE = default;
    };

    class DeleteAccountTask : public detail::Gs2WebSocketSessionTask<void>
    {
    private:
        DeleteAccountRequest& m_Request;

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
            writer.writeCharArray("account");
            writer.writePropertyName("component");
            writer.writeCharArray("account");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteAccount");
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
        DeleteAccountTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteAccountRequest& request,
            Gs2WebSocketSessionTask<void>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<void>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteAccountTask() GS2_OVERRIDE = default;
    };

    class AuthenticationTask : public detail::Gs2WebSocketSessionTask<AuthenticationResult>
    {
    private:
        AuthenticationRequest& m_Request;

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
            if (m_Request.getKeyId())
            {
                writer.writePropertyName("keyId");
                writer.writeCharArray(*m_Request.getKeyId());
            }
            if (m_Request.getPassword())
            {
                writer.writePropertyName("password");
                writer.writeCharArray(*m_Request.getPassword());
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
            writer.writeCharArray("account");
            writer.writePropertyName("component");
            writer.writeCharArray("account");
            writer.writePropertyName("function");
            writer.writeCharArray("authentication");
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
        AuthenticationTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            AuthenticationRequest& request,
            Gs2WebSocketSessionTask<AuthenticationResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<AuthenticationResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~AuthenticationTask() GS2_OVERRIDE = default;
    };

    class DescribeTakeOversTask : public detail::Gs2WebSocketSessionTask<DescribeTakeOversResult>
    {
    private:
        DescribeTakeOversRequest& m_Request;

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
            writer.writeCharArray("account");
            writer.writePropertyName("component");
            writer.writeCharArray("takeOver");
            writer.writePropertyName("function");
            writer.writeCharArray("describeTakeOvers");
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
        DescribeTakeOversTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeTakeOversRequest& request,
            Gs2WebSocketSessionTask<DescribeTakeOversResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeTakeOversResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeTakeOversTask() GS2_OVERRIDE = default;
    };

    class DescribeTakeOversByUserIdTask : public detail::Gs2WebSocketSessionTask<DescribeTakeOversByUserIdResult>
    {
    private:
        DescribeTakeOversByUserIdRequest& m_Request;

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
            writer.writeCharArray("account");
            writer.writePropertyName("component");
            writer.writeCharArray("takeOver");
            writer.writePropertyName("function");
            writer.writeCharArray("describeTakeOversByUserId");
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
        DescribeTakeOversByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeTakeOversByUserIdRequest& request,
            Gs2WebSocketSessionTask<DescribeTakeOversByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeTakeOversByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeTakeOversByUserIdTask() GS2_OVERRIDE = default;
    };

    class CreateTakeOverTask : public detail::Gs2WebSocketSessionTask<CreateTakeOverResult>
    {
    private:
        CreateTakeOverRequest& m_Request;

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
            if (m_Request.getType())
            {
                writer.writePropertyName("type");
                writer.writeInt32(*m_Request.getType());
            }
            if (m_Request.getUserIdentifier())
            {
                writer.writePropertyName("userIdentifier");
                writer.writeCharArray(*m_Request.getUserIdentifier());
            }
            if (m_Request.getPassword())
            {
                writer.writePropertyName("password");
                writer.writeCharArray(*m_Request.getPassword());
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
            writer.writeCharArray("account");
            writer.writePropertyName("component");
            writer.writeCharArray("takeOver");
            writer.writePropertyName("function");
            writer.writeCharArray("createTakeOver");
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
        CreateTakeOverTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            CreateTakeOverRequest& request,
            Gs2WebSocketSessionTask<CreateTakeOverResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateTakeOverResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~CreateTakeOverTask() GS2_OVERRIDE = default;
    };

    class CreateTakeOverByUserIdTask : public detail::Gs2WebSocketSessionTask<CreateTakeOverByUserIdResult>
    {
    private:
        CreateTakeOverByUserIdRequest& m_Request;

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
            if (m_Request.getType())
            {
                writer.writePropertyName("type");
                writer.writeInt32(*m_Request.getType());
            }
            if (m_Request.getUserIdentifier())
            {
                writer.writePropertyName("userIdentifier");
                writer.writeCharArray(*m_Request.getUserIdentifier());
            }
            if (m_Request.getPassword())
            {
                writer.writePropertyName("password");
                writer.writeCharArray(*m_Request.getPassword());
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
            writer.writeCharArray("account");
            writer.writePropertyName("component");
            writer.writeCharArray("takeOver");
            writer.writePropertyName("function");
            writer.writeCharArray("createTakeOverByUserId");
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
        CreateTakeOverByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            CreateTakeOverByUserIdRequest& request,
            Gs2WebSocketSessionTask<CreateTakeOverByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateTakeOverByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~CreateTakeOverByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetTakeOverTask : public detail::Gs2WebSocketSessionTask<GetTakeOverResult>
    {
    private:
        GetTakeOverRequest& m_Request;

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
            if (m_Request.getType())
            {
                writer.writePropertyName("type");
                writer.writeInt32(*m_Request.getType());
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
            writer.writeCharArray("account");
            writer.writePropertyName("component");
            writer.writeCharArray("takeOver");
            writer.writePropertyName("function");
            writer.writeCharArray("getTakeOver");
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
        GetTakeOverTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetTakeOverRequest& request,
            Gs2WebSocketSessionTask<GetTakeOverResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetTakeOverResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetTakeOverTask() GS2_OVERRIDE = default;
    };

    class GetTakeOverByUserIdTask : public detail::Gs2WebSocketSessionTask<GetTakeOverByUserIdResult>
    {
    private:
        GetTakeOverByUserIdRequest& m_Request;

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
            if (m_Request.getType())
            {
                writer.writePropertyName("type");
                writer.writeInt32(*m_Request.getType());
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
            writer.writeCharArray("account");
            writer.writePropertyName("component");
            writer.writeCharArray("takeOver");
            writer.writePropertyName("function");
            writer.writeCharArray("getTakeOverByUserId");
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
        GetTakeOverByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetTakeOverByUserIdRequest& request,
            Gs2WebSocketSessionTask<GetTakeOverByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetTakeOverByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetTakeOverByUserIdTask() GS2_OVERRIDE = default;
    };

    class UpdateTakeOverTask : public detail::Gs2WebSocketSessionTask<UpdateTakeOverResult>
    {
    private:
        UpdateTakeOverRequest& m_Request;

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
            if (m_Request.getType())
            {
                writer.writePropertyName("type");
                writer.writeInt32(*m_Request.getType());
            }
            if (m_Request.getOldPassword())
            {
                writer.writePropertyName("oldPassword");
                writer.writeCharArray(*m_Request.getOldPassword());
            }
            if (m_Request.getPassword())
            {
                writer.writePropertyName("password");
                writer.writeCharArray(*m_Request.getPassword());
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
            writer.writeCharArray("account");
            writer.writePropertyName("component");
            writer.writeCharArray("takeOver");
            writer.writePropertyName("function");
            writer.writeCharArray("updateTakeOver");
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
        UpdateTakeOverTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateTakeOverRequest& request,
            Gs2WebSocketSessionTask<UpdateTakeOverResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateTakeOverResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateTakeOverTask() GS2_OVERRIDE = default;
    };

    class UpdateTakeOverByUserIdTask : public detail::Gs2WebSocketSessionTask<UpdateTakeOverByUserIdResult>
    {
    private:
        UpdateTakeOverByUserIdRequest& m_Request;

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
            if (m_Request.getType())
            {
                writer.writePropertyName("type");
                writer.writeInt32(*m_Request.getType());
            }
            if (m_Request.getOldPassword())
            {
                writer.writePropertyName("oldPassword");
                writer.writeCharArray(*m_Request.getOldPassword());
            }
            if (m_Request.getPassword())
            {
                writer.writePropertyName("password");
                writer.writeCharArray(*m_Request.getPassword());
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
            writer.writeCharArray("account");
            writer.writePropertyName("component");
            writer.writeCharArray("takeOver");
            writer.writePropertyName("function");
            writer.writeCharArray("updateTakeOverByUserId");
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
        UpdateTakeOverByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateTakeOverByUserIdRequest& request,
            Gs2WebSocketSessionTask<UpdateTakeOverByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateTakeOverByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateTakeOverByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteTakeOverTask : public detail::Gs2WebSocketSessionTask<void>
    {
    private:
        DeleteTakeOverRequest& m_Request;

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
            if (m_Request.getType())
            {
                writer.writePropertyName("type");
                writer.writeInt32(*m_Request.getType());
            }
            if (m_Request.getUserIdentifier())
            {
                writer.writePropertyName("userIdentifier");
                writer.writeCharArray(*m_Request.getUserIdentifier());
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
            writer.writeCharArray("account");
            writer.writePropertyName("component");
            writer.writeCharArray("takeOver");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteTakeOver");
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
        DeleteTakeOverTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteTakeOverRequest& request,
            Gs2WebSocketSessionTask<void>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<void>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteTakeOverTask() GS2_OVERRIDE = default;
    };

    class DeleteTakeOverByUserIdentifierTask : public detail::Gs2WebSocketSessionTask<void>
    {
    private:
        DeleteTakeOverByUserIdentifierRequest& m_Request;

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
            if (m_Request.getType())
            {
                writer.writePropertyName("type");
                writer.writeInt32(*m_Request.getType());
            }
            if (m_Request.getUserIdentifier())
            {
                writer.writePropertyName("userIdentifier");
                writer.writeCharArray(*m_Request.getUserIdentifier());
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
            writer.writeCharArray("account");
            writer.writePropertyName("component");
            writer.writeCharArray("takeOver");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteTakeOverByUserIdentifier");
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
        DeleteTakeOverByUserIdentifierTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteTakeOverByUserIdentifierRequest& request,
            Gs2WebSocketSessionTask<void>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<void>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteTakeOverByUserIdentifierTask() GS2_OVERRIDE = default;
    };

    class DoTakeOverTask : public detail::Gs2WebSocketSessionTask<DoTakeOverResult>
    {
    private:
        DoTakeOverRequest& m_Request;

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
            if (m_Request.getType())
            {
                writer.writePropertyName("type");
                writer.writeInt32(*m_Request.getType());
            }
            if (m_Request.getUserIdentifier())
            {
                writer.writePropertyName("userIdentifier");
                writer.writeCharArray(*m_Request.getUserIdentifier());
            }
            if (m_Request.getPassword())
            {
                writer.writePropertyName("password");
                writer.writeCharArray(*m_Request.getPassword());
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
            writer.writeCharArray("account");
            writer.writePropertyName("component");
            writer.writeCharArray("takeOver");
            writer.writePropertyName("function");
            writer.writeCharArray("doTakeOver");
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
        DoTakeOverTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DoTakeOverRequest& request,
            Gs2WebSocketSessionTask<DoTakeOverResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DoTakeOverResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DoTakeOverTask() GS2_OVERRIDE = default;
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
        if (obj.getChangePasswordIfTakeOver())
        {
            writer.writePropertyName("changePasswordIfTakeOver");
            writer.writeBool(*obj.getChangePasswordIfTakeOver());
        }
        if (obj.getCreateAccountScript())
        {
            writer.writePropertyName("createAccountScript");
            write(writer, *obj.getCreateAccountScript());
        }
        if (obj.getAuthenticationScript())
        {
            writer.writePropertyName("authenticationScript");
            write(writer, *obj.getAuthenticationScript());
        }
        if (obj.getCreateTakeOverScript())
        {
            writer.writePropertyName("createTakeOverScript");
            write(writer, *obj.getCreateTakeOverScript());
        }
        if (obj.getDoTakeOverScript())
        {
            writer.writePropertyName("doTakeOverScript");
            write(writer, *obj.getDoTakeOverScript());
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

    static void write(detail::json::JsonWriter& writer, const Account& obj)
    {
        writer.writeObjectStart();
        if (obj.getAccountId())
        {
            writer.writePropertyName("accountId");
            writer.writeCharArray(*obj.getAccountId());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.writeCharArray(*obj.getUserId());
        }
        if (obj.getPassword())
        {
            writer.writePropertyName("password");
            writer.writeCharArray(*obj.getPassword());
        }
        if (obj.getTimeOffset())
        {
            writer.writePropertyName("timeOffset");
            writer.writeInt32(*obj.getTimeOffset());
        }
        if (obj.getCreatedAt())
        {
            writer.writePropertyName("createdAt");
            writer.writeInt64(*obj.getCreatedAt());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const TakeOver& obj)
    {
        writer.writeObjectStart();
        if (obj.getTakeOverId())
        {
            writer.writePropertyName("takeOverId");
            writer.writeCharArray(*obj.getTakeOverId());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.writeCharArray(*obj.getUserId());
        }
        if (obj.getType())
        {
            writer.writePropertyName("type");
            writer.writeInt32(*obj.getType());
        }
        if (obj.getUserIdentifier())
        {
            writer.writePropertyName("userIdentifier");
            writer.writeCharArray(*obj.getUserIdentifier());
        }
        if (obj.getPassword())
        {
            writer.writePropertyName("password");
            writer.writeCharArray(*obj.getPassword());
        }
        if (obj.getCreatedAt())
        {
            writer.writePropertyName("createdAt");
            writer.writeInt64(*obj.getCreatedAt());
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

    static void write(detail::json::JsonWriter& writer, const ScriptSetting& obj)
    {
        writer.writeObjectStart();
        if (obj.getTriggerScriptId())
        {
            writer.writePropertyName("triggerScriptId");
            writer.writeCharArray(*obj.getTriggerScriptId());
        }
        if (obj.getDoneTriggerScriptId())
        {
            writer.writePropertyName("doneTriggerScriptId");
            writer.writeCharArray(*obj.getDoneTriggerScriptId());
        }
        if (obj.getDoneTriggerQueueNamespaceId())
        {
            writer.writePropertyName("doneTriggerQueueNamespaceId");
            writer.writeCharArray(*obj.getDoneTriggerQueueNamespaceId());
        }
        writer.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param gs2WebSocketSession WebSocket API 用セッション
     */
    explicit Gs2AccountWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
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
	 * ネームスペースを取得<br>
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
	 * ゲームプレイヤーアカウントの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeAccounts(DescribeAccountsRequest& request, std::function<void(AsyncDescribeAccountsResult&)> callback)
    {
        DescribeAccountsTask& task = *new DescribeAccountsTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ゲームプレイヤーアカウントを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createAccount(CreateAccountRequest& request, std::function<void(AsyncCreateAccountResult&)> callback)
    {
        CreateAccountTask& task = *new CreateAccountTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ゲームプレイヤーアカウントの現在時刻に対する補正値を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateTimeOffset(UpdateTimeOffsetRequest& request, std::function<void(AsyncUpdateTimeOffsetResult&)> callback)
    {
        UpdateTimeOffsetTask& task = *new UpdateTimeOffsetTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ゲームプレイヤーアカウントを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getAccount(GetAccountRequest& request, std::function<void(AsyncGetAccountResult&)> callback)
    {
        GetAccountTask& task = *new GetAccountTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ゲームプレイヤーアカウントを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteAccount(DeleteAccountRequest& request, std::function<void(AsyncDeleteAccountResult&)> callback)
    {
        DeleteAccountTask& task = *new DeleteAccountTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ゲームプレイヤーアカウントを認証<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void authentication(AuthenticationRequest& request, std::function<void(AsyncAuthenticationResult&)> callback)
    {
        AuthenticationTask& task = *new AuthenticationTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 引き継ぎ設定の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeTakeOvers(DescribeTakeOversRequest& request, std::function<void(AsyncDescribeTakeOversResult&)> callback)
    {
        DescribeTakeOversTask& task = *new DescribeTakeOversTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザーIDを指定して引き継ぎ設定の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeTakeOversByUserId(DescribeTakeOversByUserIdRequest& request, std::function<void(AsyncDescribeTakeOversByUserIdResult&)> callback)
    {
        DescribeTakeOversByUserIdTask& task = *new DescribeTakeOversByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 引き継ぎ設定を新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createTakeOver(CreateTakeOverRequest& request, std::function<void(AsyncCreateTakeOverResult&)> callback)
    {
        CreateTakeOverTask& task = *new CreateTakeOverTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザーIDを指定して引き継ぎ設定を新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createTakeOverByUserId(CreateTakeOverByUserIdRequest& request, std::function<void(AsyncCreateTakeOverByUserIdResult&)> callback)
    {
        CreateTakeOverByUserIdTask& task = *new CreateTakeOverByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 引き継ぎ設定を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getTakeOver(GetTakeOverRequest& request, std::function<void(AsyncGetTakeOverResult&)> callback)
    {
        GetTakeOverTask& task = *new GetTakeOverTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザーIDを指定して引き継ぎ設定を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getTakeOverByUserId(GetTakeOverByUserIdRequest& request, std::function<void(AsyncGetTakeOverByUserIdResult&)> callback)
    {
        GetTakeOverByUserIdTask& task = *new GetTakeOverByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 引き継ぎ設定を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateTakeOver(UpdateTakeOverRequest& request, std::function<void(AsyncUpdateTakeOverResult&)> callback)
    {
        UpdateTakeOverTask& task = *new UpdateTakeOverTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 引き継ぎ設定を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateTakeOverByUserId(UpdateTakeOverByUserIdRequest& request, std::function<void(AsyncUpdateTakeOverByUserIdResult&)> callback)
    {
        UpdateTakeOverByUserIdTask& task = *new UpdateTakeOverByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 引き継ぎ設定を削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteTakeOver(DeleteTakeOverRequest& request, std::function<void(AsyncDeleteTakeOverResult&)> callback)
    {
        DeleteTakeOverTask& task = *new DeleteTakeOverTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 引き継ぎ設定を削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteTakeOverByUserIdentifier(DeleteTakeOverByUserIdentifierRequest& request, std::function<void(AsyncDeleteTakeOverByUserIdentifierResult&)> callback)
    {
        DeleteTakeOverByUserIdentifierTask& task = *new DeleteTakeOverByUserIdentifierTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 引き継ぎ設定を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void doTakeOver(DoTakeOverRequest& request, std::function<void(AsyncDoTakeOverResult&)> callback)
    {
        DoTakeOverTask& task = *new DoTakeOverTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_ACCOUNT_GS2ACCOUNTWEBSOCKETCLIENT_HPP_