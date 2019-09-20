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
        DescribeNamespacesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "account";
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
            return "account";
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
            if (m_Request.getChangePasswordIfTakeOver())
            {
                jsonWriter.writePropertyName("changePasswordIfTakeOver");
                jsonWriter.writeBool(*m_Request.getChangePasswordIfTakeOver());
            }
            if (m_Request.getCreateAccountScript())
            {
                jsonWriter.writePropertyName("createAccountScript");
                write(jsonWriter, *m_Request.getCreateAccountScript());
            }
            if (m_Request.getAuthenticationScript())
            {
                jsonWriter.writePropertyName("authenticationScript");
                write(jsonWriter, *m_Request.getAuthenticationScript());
            }
            if (m_Request.getCreateTakeOverScript())
            {
                jsonWriter.writePropertyName("createTakeOverScript");
                write(jsonWriter, *m_Request.getCreateTakeOverScript());
            }
            if (m_Request.getDoTakeOverScript())
            {
                jsonWriter.writePropertyName("doTakeOverScript");
                write(jsonWriter, *m_Request.getDoTakeOverScript());
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
            return "account";
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
            return "account";
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
            return "account";
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
            if (m_Request.getChangePasswordIfTakeOver())
            {
                jsonWriter.writePropertyName("changePasswordIfTakeOver");
                jsonWriter.writeBool(*m_Request.getChangePasswordIfTakeOver());
            }
            if (m_Request.getCreateAccountScript())
            {
                jsonWriter.writePropertyName("createAccountScript");
                write(jsonWriter, *m_Request.getCreateAccountScript());
            }
            if (m_Request.getAuthenticationScript())
            {
                jsonWriter.writePropertyName("authenticationScript");
                write(jsonWriter, *m_Request.getAuthenticationScript());
            }
            if (m_Request.getCreateTakeOverScript())
            {
                jsonWriter.writePropertyName("createTakeOverScript");
                write(jsonWriter, *m_Request.getCreateTakeOverScript());
            }
            if (m_Request.getDoTakeOverScript())
            {
                jsonWriter.writePropertyName("doTakeOverScript");
                write(jsonWriter, *m_Request.getDoTakeOverScript());
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

    class DeleteNamespaceTask : public detail::Gs2WebSocketSessionTask<void>
    {
    private:
        DeleteNamespaceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "account";
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
            Gs2WebSocketSessionTask<void>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<void>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteNamespaceTask() GS2_OVERRIDE = default;
    };

    class DescribeAccountsTask : public detail::Gs2WebSocketSessionTask<DescribeAccountsResult>
    {
    private:
        DescribeAccountsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "account";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "account";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeAccounts";
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
        DescribeAccountsTask(
            DescribeAccountsRequest request,
            Gs2WebSocketSessionTask<DescribeAccountsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeAccountsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeAccountsTask() GS2_OVERRIDE = default;
    };

    class CreateAccountTask : public detail::Gs2WebSocketSessionTask<CreateAccountResult>
    {
    private:
        CreateAccountRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "account";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "account";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "createAccount";
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
        CreateAccountTask(
            CreateAccountRequest request,
            Gs2WebSocketSessionTask<CreateAccountResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateAccountResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateAccountTask() GS2_OVERRIDE = default;
    };

    class UpdateTimeOffsetTask : public detail::Gs2WebSocketSessionTask<UpdateTimeOffsetResult>
    {
    private:
        UpdateTimeOffsetRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "account";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "account";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateTimeOffset";
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
            if (m_Request.getTimeOffset())
            {
                jsonWriter.writePropertyName("timeOffset");
                jsonWriter.writeInt32(*m_Request.getTimeOffset());
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
        UpdateTimeOffsetTask(
            UpdateTimeOffsetRequest request,
            Gs2WebSocketSessionTask<UpdateTimeOffsetResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateTimeOffsetResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateTimeOffsetTask() GS2_OVERRIDE = default;
    };

    class GetAccountTask : public detail::Gs2WebSocketSessionTask<GetAccountResult>
    {
    private:
        GetAccountRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "account";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "account";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getAccount";
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
        GetAccountTask(
            GetAccountRequest request,
            Gs2WebSocketSessionTask<GetAccountResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetAccountResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetAccountTask() GS2_OVERRIDE = default;
    };

    class DeleteAccountTask : public detail::Gs2WebSocketSessionTask<void>
    {
    private:
        DeleteAccountRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "account";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "account";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteAccount";
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
        DeleteAccountTask(
            DeleteAccountRequest request,
            Gs2WebSocketSessionTask<void>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<void>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteAccountTask() GS2_OVERRIDE = default;
    };

    class AuthenticationTask : public detail::Gs2WebSocketSessionTask<AuthenticationResult>
    {
    private:
        AuthenticationRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "account";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "account";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "authentication";
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
            if (m_Request.getKeyId())
            {
                jsonWriter.writePropertyName("keyId");
                jsonWriter.writeCharArray(*m_Request.getKeyId());
            }
            if (m_Request.getPassword())
            {
                jsonWriter.writePropertyName("password");
                jsonWriter.writeCharArray(*m_Request.getPassword());
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
        AuthenticationTask(
            AuthenticationRequest request,
            Gs2WebSocketSessionTask<AuthenticationResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<AuthenticationResult>(callback),
            m_Request(std::move(request))
        {}

        ~AuthenticationTask() GS2_OVERRIDE = default;
    };

    class DescribeTakeOversTask : public detail::Gs2WebSocketSessionTask<DescribeTakeOversResult>
    {
    private:
        DescribeTakeOversRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "account";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "takeOver";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeTakeOvers";
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
        DescribeTakeOversTask(
            DescribeTakeOversRequest request,
            Gs2WebSocketSessionTask<DescribeTakeOversResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeTakeOversResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeTakeOversTask() GS2_OVERRIDE = default;
    };

    class DescribeTakeOversByUserIdTask : public detail::Gs2WebSocketSessionTask<DescribeTakeOversByUserIdResult>
    {
    private:
        DescribeTakeOversByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "account";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "takeOver";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeTakeOversByUserId";
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
        DescribeTakeOversByUserIdTask(
            DescribeTakeOversByUserIdRequest request,
            Gs2WebSocketSessionTask<DescribeTakeOversByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeTakeOversByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeTakeOversByUserIdTask() GS2_OVERRIDE = default;
    };

    class CreateTakeOverTask : public detail::Gs2WebSocketSessionTask<CreateTakeOverResult>
    {
    private:
        CreateTakeOverRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "account";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "takeOver";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "createTakeOver";
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
            if (m_Request.getType())
            {
                jsonWriter.writePropertyName("type");
                jsonWriter.writeInt32(*m_Request.getType());
            }
            if (m_Request.getUserIdentifier())
            {
                jsonWriter.writePropertyName("userIdentifier");
                jsonWriter.writeCharArray(*m_Request.getUserIdentifier());
            }
            if (m_Request.getPassword())
            {
                jsonWriter.writePropertyName("password");
                jsonWriter.writeCharArray(*m_Request.getPassword());
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
        CreateTakeOverTask(
            CreateTakeOverRequest request,
            Gs2WebSocketSessionTask<CreateTakeOverResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateTakeOverResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateTakeOverTask() GS2_OVERRIDE = default;
    };

    class CreateTakeOverByUserIdTask : public detail::Gs2WebSocketSessionTask<CreateTakeOverByUserIdResult>
    {
    private:
        CreateTakeOverByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "account";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "takeOver";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "createTakeOverByUserId";
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
            if (m_Request.getType())
            {
                jsonWriter.writePropertyName("type");
                jsonWriter.writeInt32(*m_Request.getType());
            }
            if (m_Request.getUserIdentifier())
            {
                jsonWriter.writePropertyName("userIdentifier");
                jsonWriter.writeCharArray(*m_Request.getUserIdentifier());
            }
            if (m_Request.getPassword())
            {
                jsonWriter.writePropertyName("password");
                jsonWriter.writeCharArray(*m_Request.getPassword());
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
        CreateTakeOverByUserIdTask(
            CreateTakeOverByUserIdRequest request,
            Gs2WebSocketSessionTask<CreateTakeOverByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateTakeOverByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateTakeOverByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetTakeOverTask : public detail::Gs2WebSocketSessionTask<GetTakeOverResult>
    {
    private:
        GetTakeOverRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "account";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "takeOver";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getTakeOver";
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
            if (m_Request.getType())
            {
                jsonWriter.writePropertyName("type");
                jsonWriter.writeInt32(*m_Request.getType());
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
        GetTakeOverTask(
            GetTakeOverRequest request,
            Gs2WebSocketSessionTask<GetTakeOverResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetTakeOverResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetTakeOverTask() GS2_OVERRIDE = default;
    };

    class GetTakeOverByUserIdTask : public detail::Gs2WebSocketSessionTask<GetTakeOverByUserIdResult>
    {
    private:
        GetTakeOverByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "account";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "takeOver";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getTakeOverByUserId";
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
            if (m_Request.getType())
            {
                jsonWriter.writePropertyName("type");
                jsonWriter.writeInt32(*m_Request.getType());
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
        GetTakeOverByUserIdTask(
            GetTakeOverByUserIdRequest request,
            Gs2WebSocketSessionTask<GetTakeOverByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetTakeOverByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetTakeOverByUserIdTask() GS2_OVERRIDE = default;
    };

    class UpdateTakeOverTask : public detail::Gs2WebSocketSessionTask<UpdateTakeOverResult>
    {
    private:
        UpdateTakeOverRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "account";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "takeOver";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateTakeOver";
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
            if (m_Request.getType())
            {
                jsonWriter.writePropertyName("type");
                jsonWriter.writeInt32(*m_Request.getType());
            }
            if (m_Request.getOldPassword())
            {
                jsonWriter.writePropertyName("oldPassword");
                jsonWriter.writeCharArray(*m_Request.getOldPassword());
            }
            if (m_Request.getPassword())
            {
                jsonWriter.writePropertyName("password");
                jsonWriter.writeCharArray(*m_Request.getPassword());
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
        UpdateTakeOverTask(
            UpdateTakeOverRequest request,
            Gs2WebSocketSessionTask<UpdateTakeOverResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateTakeOverResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateTakeOverTask() GS2_OVERRIDE = default;
    };

    class UpdateTakeOverByUserIdTask : public detail::Gs2WebSocketSessionTask<UpdateTakeOverByUserIdResult>
    {
    private:
        UpdateTakeOverByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "account";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "takeOver";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateTakeOverByUserId";
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
            if (m_Request.getType())
            {
                jsonWriter.writePropertyName("type");
                jsonWriter.writeInt32(*m_Request.getType());
            }
            if (m_Request.getOldPassword())
            {
                jsonWriter.writePropertyName("oldPassword");
                jsonWriter.writeCharArray(*m_Request.getOldPassword());
            }
            if (m_Request.getPassword())
            {
                jsonWriter.writePropertyName("password");
                jsonWriter.writeCharArray(*m_Request.getPassword());
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
        UpdateTakeOverByUserIdTask(
            UpdateTakeOverByUserIdRequest request,
            Gs2WebSocketSessionTask<UpdateTakeOverByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateTakeOverByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateTakeOverByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteTakeOverTask : public detail::Gs2WebSocketSessionTask<void>
    {
    private:
        DeleteTakeOverRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "account";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "takeOver";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteTakeOver";
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
            if (m_Request.getType())
            {
                jsonWriter.writePropertyName("type");
                jsonWriter.writeInt32(*m_Request.getType());
            }
            if (m_Request.getUserIdentifier())
            {
                jsonWriter.writePropertyName("userIdentifier");
                jsonWriter.writeCharArray(*m_Request.getUserIdentifier());
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
        DeleteTakeOverTask(
            DeleteTakeOverRequest request,
            Gs2WebSocketSessionTask<void>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<void>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteTakeOverTask() GS2_OVERRIDE = default;
    };

    class DeleteTakeOverByUserIdentifierTask : public detail::Gs2WebSocketSessionTask<void>
    {
    private:
        DeleteTakeOverByUserIdentifierRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "account";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "takeOver";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteTakeOverByUserIdentifier";
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
            if (m_Request.getType())
            {
                jsonWriter.writePropertyName("type");
                jsonWriter.writeInt32(*m_Request.getType());
            }
            if (m_Request.getUserIdentifier())
            {
                jsonWriter.writePropertyName("userIdentifier");
                jsonWriter.writeCharArray(*m_Request.getUserIdentifier());
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
        DeleteTakeOverByUserIdentifierTask(
            DeleteTakeOverByUserIdentifierRequest request,
            Gs2WebSocketSessionTask<void>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<void>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteTakeOverByUserIdentifierTask() GS2_OVERRIDE = default;
    };

    class DoTakeOverTask : public detail::Gs2WebSocketSessionTask<DoTakeOverResult>
    {
    private:
        DoTakeOverRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "account";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "takeOver";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "doTakeOver";
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
            if (m_Request.getType())
            {
                jsonWriter.writePropertyName("type");
                jsonWriter.writeInt32(*m_Request.getType());
            }
            if (m_Request.getUserIdentifier())
            {
                jsonWriter.writePropertyName("userIdentifier");
                jsonWriter.writeCharArray(*m_Request.getUserIdentifier());
            }
            if (m_Request.getPassword())
            {
                jsonWriter.writePropertyName("password");
                jsonWriter.writeCharArray(*m_Request.getPassword());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        DoTakeOverTask(
            DoTakeOverRequest request,
            Gs2WebSocketSessionTask<DoTakeOverResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DoTakeOverResult>(callback),
            m_Request(std::move(request))
        {}

        ~DoTakeOverTask() GS2_OVERRIDE = default;
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
        if (obj.getChangePasswordIfTakeOver())
        {
            jsonWriter.writePropertyName("changePasswordIfTakeOver");
            jsonWriter.writeBool(*obj.getChangePasswordIfTakeOver());
        }
        if (obj.getCreateAccountScript())
        {
            jsonWriter.writePropertyName("createAccountScript");
            write(jsonWriter, *obj.getCreateAccountScript());
        }
        if (obj.getAuthenticationScript())
        {
            jsonWriter.writePropertyName("authenticationScript");
            write(jsonWriter, *obj.getAuthenticationScript());
        }
        if (obj.getCreateTakeOverScript())
        {
            jsonWriter.writePropertyName("createTakeOverScript");
            write(jsonWriter, *obj.getCreateTakeOverScript());
        }
        if (obj.getDoTakeOverScript())
        {
            jsonWriter.writePropertyName("doTakeOverScript");
            write(jsonWriter, *obj.getDoTakeOverScript());
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

    static void write(detail::json::JsonWriter& jsonWriter, const Account& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getAccountId())
        {
            jsonWriter.writePropertyName("accountId");
            jsonWriter.writeCharArray(*obj.getAccountId());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getPassword())
        {
            jsonWriter.writePropertyName("password");
            jsonWriter.writeCharArray(*obj.getPassword());
        }
        if (obj.getTimeOffset())
        {
            jsonWriter.writePropertyName("timeOffset");
            jsonWriter.writeInt32(*obj.getTimeOffset());
        }
        if (obj.getCreatedAt())
        {
            jsonWriter.writePropertyName("createdAt");
            jsonWriter.writeInt64(*obj.getCreatedAt());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const TakeOver& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getTakeOverId())
        {
            jsonWriter.writePropertyName("takeOverId");
            jsonWriter.writeCharArray(*obj.getTakeOverId());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getType())
        {
            jsonWriter.writePropertyName("type");
            jsonWriter.writeInt32(*obj.getType());
        }
        if (obj.getUserIdentifier())
        {
            jsonWriter.writePropertyName("userIdentifier");
            jsonWriter.writeCharArray(*obj.getUserIdentifier());
        }
        if (obj.getPassword())
        {
            jsonWriter.writePropertyName("password");
            jsonWriter.writeCharArray(*obj.getPassword());
        }
        if (obj.getCreatedAt())
        {
            jsonWriter.writePropertyName("createdAt");
            jsonWriter.writeInt64(*obj.getCreatedAt());
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

    static void write(detail::json::JsonWriter& jsonWriter, const ScriptSetting& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getTriggerScriptId())
        {
            jsonWriter.writePropertyName("triggerScriptId");
            jsonWriter.writeCharArray(*obj.getTriggerScriptId());
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
	 * ネームスペースを取得<br>
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
	 * ゲームプレイヤーアカウントの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeAccounts(DescribeAccountsRequest request, std::function<void(AsyncDescribeAccountsResult)> callback)
    {
        DescribeAccountsTask& task = *new DescribeAccountsTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ゲームプレイヤーアカウントを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createAccount(CreateAccountRequest request, std::function<void(AsyncCreateAccountResult)> callback)
    {
        CreateAccountTask& task = *new CreateAccountTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ゲームプレイヤーアカウントの現在時刻に対する補正値を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateTimeOffset(UpdateTimeOffsetRequest request, std::function<void(AsyncUpdateTimeOffsetResult)> callback)
    {
        UpdateTimeOffsetTask& task = *new UpdateTimeOffsetTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ゲームプレイヤーアカウントを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getAccount(GetAccountRequest request, std::function<void(AsyncGetAccountResult)> callback)
    {
        GetAccountTask& task = *new GetAccountTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ゲームプレイヤーアカウントを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteAccount(DeleteAccountRequest request, std::function<void(AsyncDeleteAccountResult)> callback)
    {
        DeleteAccountTask& task = *new DeleteAccountTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ゲームプレイヤーアカウントを認証<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void authentication(AuthenticationRequest request, std::function<void(AsyncAuthenticationResult)> callback)
    {
        AuthenticationTask& task = *new AuthenticationTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 引き継ぎ設定の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeTakeOvers(DescribeTakeOversRequest request, std::function<void(AsyncDescribeTakeOversResult)> callback)
    {
        DescribeTakeOversTask& task = *new DescribeTakeOversTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザーIDを指定して引き継ぎ設定の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeTakeOversByUserId(DescribeTakeOversByUserIdRequest request, std::function<void(AsyncDescribeTakeOversByUserIdResult)> callback)
    {
        DescribeTakeOversByUserIdTask& task = *new DescribeTakeOversByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 引き継ぎ設定を新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createTakeOver(CreateTakeOverRequest request, std::function<void(AsyncCreateTakeOverResult)> callback)
    {
        CreateTakeOverTask& task = *new CreateTakeOverTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザーIDを指定して引き継ぎ設定を新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createTakeOverByUserId(CreateTakeOverByUserIdRequest request, std::function<void(AsyncCreateTakeOverByUserIdResult)> callback)
    {
        CreateTakeOverByUserIdTask& task = *new CreateTakeOverByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 引き継ぎ設定を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getTakeOver(GetTakeOverRequest request, std::function<void(AsyncGetTakeOverResult)> callback)
    {
        GetTakeOverTask& task = *new GetTakeOverTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザーIDを指定して引き継ぎ設定を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getTakeOverByUserId(GetTakeOverByUserIdRequest request, std::function<void(AsyncGetTakeOverByUserIdResult)> callback)
    {
        GetTakeOverByUserIdTask& task = *new GetTakeOverByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 引き継ぎ設定を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateTakeOver(UpdateTakeOverRequest request, std::function<void(AsyncUpdateTakeOverResult)> callback)
    {
        UpdateTakeOverTask& task = *new UpdateTakeOverTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 引き継ぎ設定を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateTakeOverByUserId(UpdateTakeOverByUserIdRequest request, std::function<void(AsyncUpdateTakeOverByUserIdResult)> callback)
    {
        UpdateTakeOverByUserIdTask& task = *new UpdateTakeOverByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 引き継ぎ設定を削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteTakeOver(DeleteTakeOverRequest request, std::function<void(AsyncDeleteTakeOverResult)> callback)
    {
        DeleteTakeOverTask& task = *new DeleteTakeOverTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 引き継ぎ設定を削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteTakeOverByUserIdentifier(DeleteTakeOverByUserIdentifierRequest request, std::function<void(AsyncDeleteTakeOverByUserIdentifierResult)> callback)
    {
        DeleteTakeOverByUserIdentifierTask& task = *new DeleteTakeOverByUserIdentifierTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 引き継ぎ設定を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void doTakeOver(DoTakeOverRequest request, std::function<void(AsyncDoTakeOverResult)> callback)
    {
        DoTakeOverTask& task = *new DoTakeOverTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_ACCOUNT_GS2ACCOUNTWEBSOCKETCLIENT_HPP_