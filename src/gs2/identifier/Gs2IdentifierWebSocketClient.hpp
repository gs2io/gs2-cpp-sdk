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
#include "request/DescribePasswordsRequest.hpp"
#include "request/CreatePasswordRequest.hpp"
#include "request/GetPasswordRequest.hpp"
#include "request/DeletePasswordRequest.hpp"
#include "request/GetHasSecurityPolicyRequest.hpp"
#include "request/AttachSecurityPolicyRequest.hpp"
#include "request/DetachSecurityPolicyRequest.hpp"
#include "request/LoginRequest.hpp"
#include "request/LoginByUserRequest.hpp"
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
#include "result/DescribePasswordsResult.hpp"
#include "result/CreatePasswordResult.hpp"
#include "result/GetPasswordResult.hpp"
#include "result/DeletePasswordResult.hpp"
#include "result/GetHasSecurityPolicyResult.hpp"
#include "result/AttachSecurityPolicyResult.hpp"
#include "result/DetachSecurityPolicyResult.hpp"
#include "result/LoginResult.hpp"
#include "result/LoginByUserResult.hpp"
#include <cstring>

namespace gs2 { namespace identifier {

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
        DescribeUsersRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "user";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeUsers";
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
        DescribeUsersTask(
            DescribeUsersRequest request,
            Gs2WebSocketSessionTask<DescribeUsersResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeUsersResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeUsersTask() GS2_OVERRIDE = default;
    };

    class CreateUserTask : public detail::Gs2WebSocketSessionTask<CreateUserResult>
    {
    private:
        CreateUserRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "user";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "createUser";
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
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        CreateUserTask(
            CreateUserRequest request,
            Gs2WebSocketSessionTask<CreateUserResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateUserResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateUserTask() GS2_OVERRIDE = default;
    };

    class UpdateUserTask : public detail::Gs2WebSocketSessionTask<UpdateUserResult>
    {
    private:
        UpdateUserRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "user";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateUser";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getUserName())
            {
                jsonWriter.writePropertyName("userName");
                jsonWriter.writeCharArray(*m_Request.getUserName());
            }
            if (m_Request.getDescription())
            {
                jsonWriter.writePropertyName("description");
                jsonWriter.writeCharArray(*m_Request.getDescription());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        UpdateUserTask(
            UpdateUserRequest request,
            Gs2WebSocketSessionTask<UpdateUserResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateUserResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateUserTask() GS2_OVERRIDE = default;
    };

    class GetUserTask : public detail::Gs2WebSocketSessionTask<GetUserResult>
    {
    private:
        GetUserRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "user";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getUser";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getUserName())
            {
                jsonWriter.writePropertyName("userName");
                jsonWriter.writeCharArray(*m_Request.getUserName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetUserTask(
            GetUserRequest request,
            Gs2WebSocketSessionTask<GetUserResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetUserResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetUserTask() GS2_OVERRIDE = default;
    };

    class DeleteUserTask : public detail::Gs2WebSocketSessionTask<void>
    {
    private:
        DeleteUserRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "user";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteUser";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getUserName())
            {
                jsonWriter.writePropertyName("userName");
                jsonWriter.writeCharArray(*m_Request.getUserName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        DeleteUserTask(
            DeleteUserRequest request,
            Gs2WebSocketSessionTask<void>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<void>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteUserTask() GS2_OVERRIDE = default;
    };

    class DescribeSecurityPoliciesTask : public detail::Gs2WebSocketSessionTask<DescribeSecurityPoliciesResult>
    {
    private:
        DescribeSecurityPoliciesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "securityPolicy";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeSecurityPolicies";
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
        DescribeSecurityPoliciesTask(
            DescribeSecurityPoliciesRequest request,
            Gs2WebSocketSessionTask<DescribeSecurityPoliciesResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeSecurityPoliciesResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeSecurityPoliciesTask() GS2_OVERRIDE = default;
    };

    class DescribeCommonSecurityPoliciesTask : public detail::Gs2WebSocketSessionTask<DescribeCommonSecurityPoliciesResult>
    {
    private:
        DescribeCommonSecurityPoliciesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "securityPolicy";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeCommonSecurityPolicies";
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
        DescribeCommonSecurityPoliciesTask(
            DescribeCommonSecurityPoliciesRequest request,
            Gs2WebSocketSessionTask<DescribeCommonSecurityPoliciesResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeCommonSecurityPoliciesResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeCommonSecurityPoliciesTask() GS2_OVERRIDE = default;
    };

    class CreateSecurityPolicyTask : public detail::Gs2WebSocketSessionTask<CreateSecurityPolicyResult>
    {
    private:
        CreateSecurityPolicyRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "securityPolicy";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "createSecurityPolicy";
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
            if (m_Request.getPolicy())
            {
                jsonWriter.writePropertyName("policy");
                jsonWriter.writeCharArray(*m_Request.getPolicy());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        CreateSecurityPolicyTask(
            CreateSecurityPolicyRequest request,
            Gs2WebSocketSessionTask<CreateSecurityPolicyResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateSecurityPolicyResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateSecurityPolicyTask() GS2_OVERRIDE = default;
    };

    class UpdateSecurityPolicyTask : public detail::Gs2WebSocketSessionTask<UpdateSecurityPolicyResult>
    {
    private:
        UpdateSecurityPolicyRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "securityPolicy";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateSecurityPolicy";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getSecurityPolicyName())
            {
                jsonWriter.writePropertyName("securityPolicyName");
                jsonWriter.writeCharArray(*m_Request.getSecurityPolicyName());
            }
            if (m_Request.getDescription())
            {
                jsonWriter.writePropertyName("description");
                jsonWriter.writeCharArray(*m_Request.getDescription());
            }
            if (m_Request.getPolicy())
            {
                jsonWriter.writePropertyName("policy");
                jsonWriter.writeCharArray(*m_Request.getPolicy());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        UpdateSecurityPolicyTask(
            UpdateSecurityPolicyRequest request,
            Gs2WebSocketSessionTask<UpdateSecurityPolicyResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateSecurityPolicyResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateSecurityPolicyTask() GS2_OVERRIDE = default;
    };

    class GetSecurityPolicyTask : public detail::Gs2WebSocketSessionTask<GetSecurityPolicyResult>
    {
    private:
        GetSecurityPolicyRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "securityPolicy";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getSecurityPolicy";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getSecurityPolicyName())
            {
                jsonWriter.writePropertyName("securityPolicyName");
                jsonWriter.writeCharArray(*m_Request.getSecurityPolicyName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetSecurityPolicyTask(
            GetSecurityPolicyRequest request,
            Gs2WebSocketSessionTask<GetSecurityPolicyResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetSecurityPolicyResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetSecurityPolicyTask() GS2_OVERRIDE = default;
    };

    class DeleteSecurityPolicyTask : public detail::Gs2WebSocketSessionTask<void>
    {
    private:
        DeleteSecurityPolicyRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "securityPolicy";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteSecurityPolicy";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getSecurityPolicyName())
            {
                jsonWriter.writePropertyName("securityPolicyName");
                jsonWriter.writeCharArray(*m_Request.getSecurityPolicyName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        DeleteSecurityPolicyTask(
            DeleteSecurityPolicyRequest request,
            Gs2WebSocketSessionTask<void>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<void>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteSecurityPolicyTask() GS2_OVERRIDE = default;
    };

    class DescribeIdentifiersTask : public detail::Gs2WebSocketSessionTask<DescribeIdentifiersResult>
    {
    private:
        DescribeIdentifiersRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeIdentifiers";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getUserName())
            {
                jsonWriter.writePropertyName("userName");
                jsonWriter.writeCharArray(*m_Request.getUserName());
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
        DescribeIdentifiersTask(
            DescribeIdentifiersRequest request,
            Gs2WebSocketSessionTask<DescribeIdentifiersResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeIdentifiersResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeIdentifiersTask() GS2_OVERRIDE = default;
    };

    class CreateIdentifierTask : public detail::Gs2WebSocketSessionTask<CreateIdentifierResult>
    {
    private:
        CreateIdentifierRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "createIdentifier";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getUserName())
            {
                jsonWriter.writePropertyName("userName");
                jsonWriter.writeCharArray(*m_Request.getUserName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        CreateIdentifierTask(
            CreateIdentifierRequest request,
            Gs2WebSocketSessionTask<CreateIdentifierResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateIdentifierResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateIdentifierTask() GS2_OVERRIDE = default;
    };

    class GetIdentifierTask : public detail::Gs2WebSocketSessionTask<GetIdentifierResult>
    {
    private:
        GetIdentifierRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getIdentifier";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getUserName())
            {
                jsonWriter.writePropertyName("userName");
                jsonWriter.writeCharArray(*m_Request.getUserName());
            }
            if (m_Request.getClientId())
            {
                jsonWriter.writePropertyName("clientId");
                jsonWriter.writeCharArray(*m_Request.getClientId());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetIdentifierTask(
            GetIdentifierRequest request,
            Gs2WebSocketSessionTask<GetIdentifierResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetIdentifierResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetIdentifierTask() GS2_OVERRIDE = default;
    };

    class DeleteIdentifierTask : public detail::Gs2WebSocketSessionTask<void>
    {
    private:
        DeleteIdentifierRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteIdentifier";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getUserName())
            {
                jsonWriter.writePropertyName("userName");
                jsonWriter.writeCharArray(*m_Request.getUserName());
            }
            if (m_Request.getClientId())
            {
                jsonWriter.writePropertyName("clientId");
                jsonWriter.writeCharArray(*m_Request.getClientId());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        DeleteIdentifierTask(
            DeleteIdentifierRequest request,
            Gs2WebSocketSessionTask<void>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<void>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteIdentifierTask() GS2_OVERRIDE = default;
    };

    class DescribePasswordsTask : public detail::Gs2WebSocketSessionTask<DescribePasswordsResult>
    {
    private:
        DescribePasswordsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "password";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describePasswords";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getUserName())
            {
                jsonWriter.writePropertyName("userName");
                jsonWriter.writeCharArray(*m_Request.getUserName());
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
        DescribePasswordsTask(
            DescribePasswordsRequest request,
            Gs2WebSocketSessionTask<DescribePasswordsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribePasswordsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribePasswordsTask() GS2_OVERRIDE = default;
    };

    class CreatePasswordTask : public detail::Gs2WebSocketSessionTask<CreatePasswordResult>
    {
    private:
        CreatePasswordRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "password";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "createPassword";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getUserName())
            {
                jsonWriter.writePropertyName("userName");
                jsonWriter.writeCharArray(*m_Request.getUserName());
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
        CreatePasswordTask(
            CreatePasswordRequest request,
            Gs2WebSocketSessionTask<CreatePasswordResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreatePasswordResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreatePasswordTask() GS2_OVERRIDE = default;
    };

    class GetPasswordTask : public detail::Gs2WebSocketSessionTask<GetPasswordResult>
    {
    private:
        GetPasswordRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "password";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getPassword";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getUserName())
            {
                jsonWriter.writePropertyName("userName");
                jsonWriter.writeCharArray(*m_Request.getUserName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetPasswordTask(
            GetPasswordRequest request,
            Gs2WebSocketSessionTask<GetPasswordResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetPasswordResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetPasswordTask() GS2_OVERRIDE = default;
    };

    class DeletePasswordTask : public detail::Gs2WebSocketSessionTask<void>
    {
    private:
        DeletePasswordRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "password";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deletePassword";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getUserName())
            {
                jsonWriter.writePropertyName("userName");
                jsonWriter.writeCharArray(*m_Request.getUserName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        DeletePasswordTask(
            DeletePasswordRequest request,
            Gs2WebSocketSessionTask<void>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<void>(callback),
            m_Request(std::move(request))
        {}

        ~DeletePasswordTask() GS2_OVERRIDE = default;
    };

    class GetHasSecurityPolicyTask : public detail::Gs2WebSocketSessionTask<GetHasSecurityPolicyResult>
    {
    private:
        GetHasSecurityPolicyRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "attachSecurityPolicy";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getHasSecurityPolicy";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getUserName())
            {
                jsonWriter.writePropertyName("userName");
                jsonWriter.writeCharArray(*m_Request.getUserName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetHasSecurityPolicyTask(
            GetHasSecurityPolicyRequest request,
            Gs2WebSocketSessionTask<GetHasSecurityPolicyResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetHasSecurityPolicyResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetHasSecurityPolicyTask() GS2_OVERRIDE = default;
    };

    class AttachSecurityPolicyTask : public detail::Gs2WebSocketSessionTask<AttachSecurityPolicyResult>
    {
    private:
        AttachSecurityPolicyRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "attachSecurityPolicy";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "attachSecurityPolicy";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getUserName())
            {
                jsonWriter.writePropertyName("userName");
                jsonWriter.writeCharArray(*m_Request.getUserName());
            }
            if (m_Request.getSecurityPolicyId())
            {
                jsonWriter.writePropertyName("securityPolicyId");
                jsonWriter.writeCharArray(*m_Request.getSecurityPolicyId());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        AttachSecurityPolicyTask(
            AttachSecurityPolicyRequest request,
            Gs2WebSocketSessionTask<AttachSecurityPolicyResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<AttachSecurityPolicyResult>(callback),
            m_Request(std::move(request))
        {}

        ~AttachSecurityPolicyTask() GS2_OVERRIDE = default;
    };

    class DetachSecurityPolicyTask : public detail::Gs2WebSocketSessionTask<DetachSecurityPolicyResult>
    {
    private:
        DetachSecurityPolicyRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "attachSecurityPolicy";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "detachSecurityPolicy";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getUserName())
            {
                jsonWriter.writePropertyName("userName");
                jsonWriter.writeCharArray(*m_Request.getUserName());
            }
            if (m_Request.getSecurityPolicyId())
            {
                jsonWriter.writePropertyName("securityPolicyId");
                jsonWriter.writeCharArray(*m_Request.getSecurityPolicyId());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        DetachSecurityPolicyTask(
            DetachSecurityPolicyRequest request,
            Gs2WebSocketSessionTask<DetachSecurityPolicyResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DetachSecurityPolicyResult>(callback),
            m_Request(std::move(request))
        {}

        ~DetachSecurityPolicyTask() GS2_OVERRIDE = default;
    };

    class LoginTask : public detail::Gs2WebSocketSessionTask<LoginResult>
    {
    private:
        LoginRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "projectToken";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "login";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getClientId())
            {
                jsonWriter.writePropertyName("clientId");
                jsonWriter.writeCharArray(*m_Request.getClientId());
            }
            if (m_Request.getClientSecret())
            {
                jsonWriter.writePropertyName("clientSecret");
                jsonWriter.writeCharArray(*m_Request.getClientSecret());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        LoginTask(
            LoginRequest request,
            Gs2WebSocketSessionTask<LoginResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<LoginResult>(callback),
            m_Request(std::move(request))
        {}

        ~LoginTask() GS2_OVERRIDE = default;
    };

    class LoginByUserTask : public detail::Gs2WebSocketSessionTask<LoginByUserResult>
    {
    private:
        LoginByUserRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "projectToken";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "loginByUser";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getUserName())
            {
                jsonWriter.writePropertyName("userName");
                jsonWriter.writeCharArray(*m_Request.getUserName());
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
        LoginByUserTask(
            LoginByUserRequest request,
            Gs2WebSocketSessionTask<LoginByUserResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<LoginByUserResult>(callback),
            m_Request(std::move(request))
        {}

        ~LoginByUserTask() GS2_OVERRIDE = default;
    };

protected:
    static void write(detail::json::JsonWriter& jsonWriter, const User& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
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

    static void write(detail::json::JsonWriter& jsonWriter, const SecurityPolicy& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getSecurityPolicyId())
        {
            jsonWriter.writePropertyName("securityPolicyId");
            jsonWriter.writeCharArray(*obj.getSecurityPolicyId());
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
        if (obj.getPolicy())
        {
            jsonWriter.writePropertyName("policy");
            jsonWriter.writeCharArray(*obj.getPolicy());
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

    static void write(detail::json::JsonWriter& jsonWriter, const Identifier& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getOwnerId())
        {
            jsonWriter.writePropertyName("ownerId");
            jsonWriter.writeCharArray(*obj.getOwnerId());
        }
        if (obj.getClientId())
        {
            jsonWriter.writePropertyName("clientId");
            jsonWriter.writeCharArray(*obj.getClientId());
        }
        if (obj.getUserName())
        {
            jsonWriter.writePropertyName("userName");
            jsonWriter.writeCharArray(*obj.getUserName());
        }
        if (obj.getClientSecret())
        {
            jsonWriter.writePropertyName("clientSecret");
            jsonWriter.writeCharArray(*obj.getClientSecret());
        }
        if (obj.getCreatedAt())
        {
            jsonWriter.writePropertyName("createdAt");
            jsonWriter.writeInt64(*obj.getCreatedAt());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const Password& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getOwnerId())
        {
            jsonWriter.writePropertyName("ownerId");
            jsonWriter.writeCharArray(*obj.getOwnerId());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getUserName())
        {
            jsonWriter.writePropertyName("userName");
            jsonWriter.writeCharArray(*obj.getUserName());
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

    static void write(detail::json::JsonWriter& jsonWriter, const AttachSecurityPolicy& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getSecurityPolicyIds())
        {
            jsonWriter.writePropertyName("securityPolicyIds");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getSecurityPolicyIds();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                jsonWriter.writeCharArray(list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (obj.getAttachedAt())
        {
            jsonWriter.writePropertyName("attachedAt");
            jsonWriter.writeInt64(*obj.getAttachedAt());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const ProjectToken& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getToken())
        {
            jsonWriter.writePropertyName("token");
            jsonWriter.writeCharArray(*obj.getToken());
        }
        jsonWriter.writeObjectEnd();
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
    void describeUsers(DescribeUsersRequest request, std::function<void(AsyncDescribeUsersResult)> callback)
    {
        DescribeUsersTask& task = *new DescribeUsersTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザを新規作成します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createUser(CreateUserRequest request, std::function<void(AsyncCreateUserResult)> callback)
    {
        CreateUserTask& task = *new CreateUserTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateUser(UpdateUserRequest request, std::function<void(AsyncUpdateUserResult)> callback)
    {
        UpdateUserTask& task = *new UpdateUserTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getUser(GetUserRequest request, std::function<void(AsyncGetUserResult)> callback)
    {
        GetUserTask& task = *new GetUserTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザを削除します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteUser(DeleteUserRequest request, std::function<void(AsyncDeleteUserResult)> callback)
    {
        DeleteUserTask& task = *new DeleteUserTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * セキュリティポリシーの一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeSecurityPolicies(DescribeSecurityPoliciesRequest request, std::function<void(AsyncDescribeSecurityPoliciesResult)> callback)
    {
        DescribeSecurityPoliciesTask& task = *new DescribeSecurityPoliciesTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * オーナーIDを指定してセキュリティポリシーの一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCommonSecurityPolicies(DescribeCommonSecurityPoliciesRequest request, std::function<void(AsyncDescribeCommonSecurityPoliciesResult)> callback)
    {
        DescribeCommonSecurityPoliciesTask& task = *new DescribeCommonSecurityPoliciesTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * セキュリティポリシーを新規作成します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createSecurityPolicy(CreateSecurityPolicyRequest request, std::function<void(AsyncCreateSecurityPolicyResult)> callback)
    {
        CreateSecurityPolicyTask& task = *new CreateSecurityPolicyTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * セキュリティポリシーを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateSecurityPolicy(UpdateSecurityPolicyRequest request, std::function<void(AsyncUpdateSecurityPolicyResult)> callback)
    {
        UpdateSecurityPolicyTask& task = *new UpdateSecurityPolicyTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * セキュリティポリシーを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getSecurityPolicy(GetSecurityPolicyRequest request, std::function<void(AsyncGetSecurityPolicyResult)> callback)
    {
        GetSecurityPolicyTask& task = *new GetSecurityPolicyTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * セキュリティポリシーを削除します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteSecurityPolicy(DeleteSecurityPolicyRequest request, std::function<void(AsyncDeleteSecurityPolicyResult)> callback)
    {
        DeleteSecurityPolicyTask& task = *new DeleteSecurityPolicyTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * クレデンシャルの一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeIdentifiers(DescribeIdentifiersRequest request, std::function<void(AsyncDescribeIdentifiersResult)> callback)
    {
        DescribeIdentifiersTask& task = *new DescribeIdentifiersTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * クレデンシャルを新規作成します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createIdentifier(CreateIdentifierRequest request, std::function<void(AsyncCreateIdentifierResult)> callback)
    {
        CreateIdentifierTask& task = *new CreateIdentifierTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * クレデンシャルを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getIdentifier(GetIdentifierRequest request, std::function<void(AsyncGetIdentifierResult)> callback)
    {
        GetIdentifierTask& task = *new GetIdentifierTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * クレデンシャルを削除します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteIdentifier(DeleteIdentifierRequest request, std::function<void(AsyncDeleteIdentifierResult)> callback)
    {
        DeleteIdentifierTask& task = *new DeleteIdentifierTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * パスワードの一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describePasswords(DescribePasswordsRequest request, std::function<void(AsyncDescribePasswordsResult)> callback)
    {
        DescribePasswordsTask& task = *new DescribePasswordsTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * パスワードを新規作成します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createPassword(CreatePasswordRequest request, std::function<void(AsyncCreatePasswordResult)> callback)
    {
        CreatePasswordTask& task = *new CreatePasswordTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * パスワードを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getPassword(GetPasswordRequest request, std::function<void(AsyncGetPasswordResult)> callback)
    {
        GetPasswordTask& task = *new GetPasswordTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * パスワードを削除します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deletePassword(DeletePasswordRequest request, std::function<void(AsyncDeletePasswordResult)> callback)
    {
        DeletePasswordTask& task = *new DeletePasswordTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 割り当てられたセキュリティポリシーの一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getHasSecurityPolicy(GetHasSecurityPolicyRequest request, std::function<void(AsyncGetHasSecurityPolicyResult)> callback)
    {
        GetHasSecurityPolicyTask& task = *new GetHasSecurityPolicyTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 割り当てられたセキュリティポリシーを新しくユーザーに割り当てます<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void attachSecurityPolicy(AttachSecurityPolicyRequest request, std::function<void(AsyncAttachSecurityPolicyResult)> callback)
    {
        AttachSecurityPolicyTask& task = *new AttachSecurityPolicyTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 割り当てられたセキュリティポリシーをユーザーから外します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void detachSecurityPolicy(DetachSecurityPolicyRequest request, std::function<void(AsyncDetachSecurityPolicyResult)> callback)
    {
        DetachSecurityPolicyTask& task = *new DetachSecurityPolicyTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * プロジェクトトークン を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void login(LoginRequest request, std::function<void(AsyncLoginResult)> callback)
    {
        LoginTask& task = *new LoginTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * プロジェクトトークン を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void loginByUser(LoginByUserRequest request, std::function<void(AsyncLoginByUserResult)> callback)
    {
        LoginByUserTask& task = *new LoginByUserTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_IDENTIFIER_GS2IDENTIFIERWEBSOCKETCLIENT_HPP_