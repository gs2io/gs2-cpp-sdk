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

#ifndef GS2_PROJECT_GS2PROJECTWEBSOCKETCLIENT_HPP_
#define GS2_PROJECT_GS2PROJECTWEBSOCKETCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2WebSocketSessionTask.hpp>
#include <gs2/core/network/Gs2WebSocketSession.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include "model/model.hpp"
#include "request/CreateAccountRequest.hpp"
#include "request/VerifyRequest.hpp"
#include "request/SignInRequest.hpp"
#include "request/IssueAccountTokenRequest.hpp"
#include "request/ForgetRequest.hpp"
#include "request/IssuePasswordRequest.hpp"
#include "request/UpdateAccountRequest.hpp"
#include "request/DeleteAccountRequest.hpp"
#include "request/DescribeProjectsRequest.hpp"
#include "request/CreateProjectRequest.hpp"
#include "request/GetProjectRequest.hpp"
#include "request/GetProjectTokenRequest.hpp"
#include "request/UpdateProjectRequest.hpp"
#include "request/DeleteProjectRequest.hpp"
#include "request/DescribeBillingMethodsRequest.hpp"
#include "request/CreateBillingMethodRequest.hpp"
#include "request/GetBillingMethodRequest.hpp"
#include "request/UpdateBillingMethodRequest.hpp"
#include "request/DeleteBillingMethodRequest.hpp"
#include "request/DescribeReceiptsRequest.hpp"
#include "request/DescribeBillingsRequest.hpp"
#include "result/CreateAccountResult.hpp"
#include "result/VerifyResult.hpp"
#include "result/SignInResult.hpp"
#include "result/IssueAccountTokenResult.hpp"
#include "result/ForgetResult.hpp"
#include "result/IssuePasswordResult.hpp"
#include "result/UpdateAccountResult.hpp"
#include "result/DeleteAccountResult.hpp"
#include "result/DescribeProjectsResult.hpp"
#include "result/CreateProjectResult.hpp"
#include "result/GetProjectResult.hpp"
#include "result/GetProjectTokenResult.hpp"
#include "result/UpdateProjectResult.hpp"
#include "result/DeleteProjectResult.hpp"
#include "result/DescribeBillingMethodsResult.hpp"
#include "result/CreateBillingMethodResult.hpp"
#include "result/GetBillingMethodResult.hpp"
#include "result/UpdateBillingMethodResult.hpp"
#include "result/DeleteBillingMethodResult.hpp"
#include "result/DescribeReceiptsResult.hpp"
#include "result/DescribeBillingsResult.hpp"
#include <cstring>

namespace gs2 { namespace project {

/**
 * GS2 Project API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2ProjectWebSocketClient : public AbstractGs2ClientBase
{
private:

    class CreateAccountTask : public detail::Gs2WebSocketSessionTask<CreateAccountResult>
    {
    private:
        CreateAccountRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "project";
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
            if (m_Request.getEmail())
            {
                jsonWriter.writePropertyName("email");
                jsonWriter.writeCharArray(*m_Request.getEmail());
            }
            if (m_Request.getFullName())
            {
                jsonWriter.writePropertyName("fullName");
                jsonWriter.writeCharArray(*m_Request.getFullName());
            }
            if (m_Request.getCompanyName())
            {
                jsonWriter.writePropertyName("companyName");
                jsonWriter.writeCharArray(*m_Request.getCompanyName());
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
        CreateAccountTask(
            CreateAccountRequest request,
            Gs2WebSocketSessionTask<CreateAccountResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateAccountResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateAccountTask() GS2_OVERRIDE = default;
    };

    class VerifyTask : public detail::Gs2WebSocketSessionTask<VerifyResult>
    {
    private:
        VerifyRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "project";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "account";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "verify";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getVerifyToken())
            {
                jsonWriter.writePropertyName("verifyToken");
                jsonWriter.writeCharArray(*m_Request.getVerifyToken());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        VerifyTask(
            VerifyRequest request,
            Gs2WebSocketSessionTask<VerifyResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<VerifyResult>(callback),
            m_Request(std::move(request))
        {}

        ~VerifyTask() GS2_OVERRIDE = default;
    };

    class SignInTask : public detail::Gs2WebSocketSessionTask<SignInResult>
    {
    private:
        SignInRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "project";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "account";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "signIn";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getEmail())
            {
                jsonWriter.writePropertyName("email");
                jsonWriter.writeCharArray(*m_Request.getEmail());
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
        SignInTask(
            SignInRequest request,
            Gs2WebSocketSessionTask<SignInResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<SignInResult>(callback),
            m_Request(std::move(request))
        {}

        ~SignInTask() GS2_OVERRIDE = default;
    };

    class IssueAccountTokenTask : public detail::Gs2WebSocketSessionTask<IssueAccountTokenResult>
    {
    private:
        IssueAccountTokenRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "project";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "account";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "issueAccountToken";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getAccountName())
            {
                jsonWriter.writePropertyName("accountName");
                jsonWriter.writeCharArray(*m_Request.getAccountName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        IssueAccountTokenTask(
            IssueAccountTokenRequest request,
            Gs2WebSocketSessionTask<IssueAccountTokenResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<IssueAccountTokenResult>(callback),
            m_Request(std::move(request))
        {}

        ~IssueAccountTokenTask() GS2_OVERRIDE = default;
    };

    class ForgetTask : public detail::Gs2WebSocketSessionTask<ForgetResult>
    {
    private:
        ForgetRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "project";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "account";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "forget";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getEmail())
            {
                jsonWriter.writePropertyName("email");
                jsonWriter.writeCharArray(*m_Request.getEmail());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        ForgetTask(
            ForgetRequest request,
            Gs2WebSocketSessionTask<ForgetResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<ForgetResult>(callback),
            m_Request(std::move(request))
        {}

        ~ForgetTask() GS2_OVERRIDE = default;
    };

    class IssuePasswordTask : public detail::Gs2WebSocketSessionTask<IssuePasswordResult>
    {
    private:
        IssuePasswordRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "project";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "account";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "issuePassword";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getIssuePasswordToken())
            {
                jsonWriter.writePropertyName("issuePasswordToken");
                jsonWriter.writeCharArray(*m_Request.getIssuePasswordToken());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        IssuePasswordTask(
            IssuePasswordRequest request,
            Gs2WebSocketSessionTask<IssuePasswordResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<IssuePasswordResult>(callback),
            m_Request(std::move(request))
        {}

        ~IssuePasswordTask() GS2_OVERRIDE = default;
    };

    class UpdateAccountTask : public detail::Gs2WebSocketSessionTask<UpdateAccountResult>
    {
    private:
        UpdateAccountRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "project";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "account";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateAccount";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getEmail())
            {
                jsonWriter.writePropertyName("email");
                jsonWriter.writeCharArray(*m_Request.getEmail());
            }
            if (m_Request.getFullName())
            {
                jsonWriter.writePropertyName("fullName");
                jsonWriter.writeCharArray(*m_Request.getFullName());
            }
            if (m_Request.getCompanyName())
            {
                jsonWriter.writePropertyName("companyName");
                jsonWriter.writeCharArray(*m_Request.getCompanyName());
            }
            if (m_Request.getPassword())
            {
                jsonWriter.writePropertyName("password");
                jsonWriter.writeCharArray(*m_Request.getPassword());
            }
            if (m_Request.getAccountToken())
            {
                jsonWriter.writePropertyName("accountToken");
                jsonWriter.writeCharArray(*m_Request.getAccountToken());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        UpdateAccountTask(
            UpdateAccountRequest request,
            Gs2WebSocketSessionTask<UpdateAccountResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateAccountResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateAccountTask() GS2_OVERRIDE = default;
    };

    class DeleteAccountTask : public detail::Gs2WebSocketSessionTask<void>
    {
    private:
        DeleteAccountRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "project";
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
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
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

    class DescribeProjectsTask : public detail::Gs2WebSocketSessionTask<DescribeProjectsResult>
    {
    private:
        DescribeProjectsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "project";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "project";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeProjects";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getAccountToken())
            {
                jsonWriter.writePropertyName("accountToken");
                jsonWriter.writeCharArray(*m_Request.getAccountToken());
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
        DescribeProjectsTask(
            DescribeProjectsRequest request,
            Gs2WebSocketSessionTask<DescribeProjectsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeProjectsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeProjectsTask() GS2_OVERRIDE = default;
    };

    class CreateProjectTask : public detail::Gs2WebSocketSessionTask<CreateProjectResult>
    {
    private:
        CreateProjectRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "project";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "project";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "createProject";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getAccountToken())
            {
                jsonWriter.writePropertyName("accountToken");
                jsonWriter.writeCharArray(*m_Request.getAccountToken());
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
            if (m_Request.getPlan())
            {
                jsonWriter.writePropertyName("plan");
                jsonWriter.writeCharArray(*m_Request.getPlan());
            }
            if (m_Request.getBillingMethodName())
            {
                jsonWriter.writePropertyName("billingMethodName");
                jsonWriter.writeCharArray(*m_Request.getBillingMethodName());
            }
            if (m_Request.getEnableEventBridge())
            {
                jsonWriter.writePropertyName("enableEventBridge");
                jsonWriter.writeCharArray(*m_Request.getEnableEventBridge());
            }
            if (m_Request.getEventBridgeAwsAccountId())
            {
                jsonWriter.writePropertyName("eventBridgeAwsAccountId");
                jsonWriter.writeCharArray(*m_Request.getEventBridgeAwsAccountId());
            }
            if (m_Request.getEventBridgeAwsRegion())
            {
                jsonWriter.writePropertyName("eventBridgeAwsRegion");
                jsonWriter.writeCharArray(*m_Request.getEventBridgeAwsRegion());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        CreateProjectTask(
            CreateProjectRequest request,
            Gs2WebSocketSessionTask<CreateProjectResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateProjectResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateProjectTask() GS2_OVERRIDE = default;
    };

    class GetProjectTask : public detail::Gs2WebSocketSessionTask<GetProjectResult>
    {
    private:
        GetProjectRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "project";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "project";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getProject";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getAccountToken())
            {
                jsonWriter.writePropertyName("accountToken");
                jsonWriter.writeCharArray(*m_Request.getAccountToken());
            }
            if (m_Request.getProjectName())
            {
                jsonWriter.writePropertyName("projectName");
                jsonWriter.writeCharArray(*m_Request.getProjectName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetProjectTask(
            GetProjectRequest request,
            Gs2WebSocketSessionTask<GetProjectResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetProjectResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetProjectTask() GS2_OVERRIDE = default;
    };

    class GetProjectTokenTask : public detail::Gs2WebSocketSessionTask<GetProjectTokenResult>
    {
    private:
        GetProjectTokenRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "project";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "project";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getProjectToken";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getProjectName())
            {
                jsonWriter.writePropertyName("projectName");
                jsonWriter.writeCharArray(*m_Request.getProjectName());
            }
            if (m_Request.getAccountToken())
            {
                jsonWriter.writePropertyName("accountToken");
                jsonWriter.writeCharArray(*m_Request.getAccountToken());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetProjectTokenTask(
            GetProjectTokenRequest request,
            Gs2WebSocketSessionTask<GetProjectTokenResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetProjectTokenResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetProjectTokenTask() GS2_OVERRIDE = default;
    };

    class UpdateProjectTask : public detail::Gs2WebSocketSessionTask<UpdateProjectResult>
    {
    private:
        UpdateProjectRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "project";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "project";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateProject";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getAccountToken())
            {
                jsonWriter.writePropertyName("accountToken");
                jsonWriter.writeCharArray(*m_Request.getAccountToken());
            }
            if (m_Request.getProjectName())
            {
                jsonWriter.writePropertyName("projectName");
                jsonWriter.writeCharArray(*m_Request.getProjectName());
            }
            if (m_Request.getDescription())
            {
                jsonWriter.writePropertyName("description");
                jsonWriter.writeCharArray(*m_Request.getDescription());
            }
            if (m_Request.getPlan())
            {
                jsonWriter.writePropertyName("plan");
                jsonWriter.writeCharArray(*m_Request.getPlan());
            }
            if (m_Request.getBillingMethodName())
            {
                jsonWriter.writePropertyName("billingMethodName");
                jsonWriter.writeCharArray(*m_Request.getBillingMethodName());
            }
            if (m_Request.getEnableEventBridge())
            {
                jsonWriter.writePropertyName("enableEventBridge");
                jsonWriter.writeCharArray(*m_Request.getEnableEventBridge());
            }
            if (m_Request.getEventBridgeAwsAccountId())
            {
                jsonWriter.writePropertyName("eventBridgeAwsAccountId");
                jsonWriter.writeCharArray(*m_Request.getEventBridgeAwsAccountId());
            }
            if (m_Request.getEventBridgeAwsRegion())
            {
                jsonWriter.writePropertyName("eventBridgeAwsRegion");
                jsonWriter.writeCharArray(*m_Request.getEventBridgeAwsRegion());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        UpdateProjectTask(
            UpdateProjectRequest request,
            Gs2WebSocketSessionTask<UpdateProjectResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateProjectResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateProjectTask() GS2_OVERRIDE = default;
    };

    class DeleteProjectTask : public detail::Gs2WebSocketSessionTask<DeleteProjectResult>
    {
    private:
        DeleteProjectRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "project";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "project";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteProject";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getAccountToken())
            {
                jsonWriter.writePropertyName("accountToken");
                jsonWriter.writeCharArray(*m_Request.getAccountToken());
            }
            if (m_Request.getProjectName())
            {
                jsonWriter.writePropertyName("projectName");
                jsonWriter.writeCharArray(*m_Request.getProjectName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        DeleteProjectTask(
            DeleteProjectRequest request,
            Gs2WebSocketSessionTask<DeleteProjectResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteProjectResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteProjectTask() GS2_OVERRIDE = default;
    };

    class DescribeBillingMethodsTask : public detail::Gs2WebSocketSessionTask<DescribeBillingMethodsResult>
    {
    private:
        DescribeBillingMethodsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "project";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "billingMethod";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeBillingMethods";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getAccountToken())
            {
                jsonWriter.writePropertyName("accountToken");
                jsonWriter.writeCharArray(*m_Request.getAccountToken());
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
        DescribeBillingMethodsTask(
            DescribeBillingMethodsRequest request,
            Gs2WebSocketSessionTask<DescribeBillingMethodsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeBillingMethodsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeBillingMethodsTask() GS2_OVERRIDE = default;
    };

    class CreateBillingMethodTask : public detail::Gs2WebSocketSessionTask<CreateBillingMethodResult>
    {
    private:
        CreateBillingMethodRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "project";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "billingMethod";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "createBillingMethod";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getAccountToken())
            {
                jsonWriter.writePropertyName("accountToken");
                jsonWriter.writeCharArray(*m_Request.getAccountToken());
            }
            if (m_Request.getDescription())
            {
                jsonWriter.writePropertyName("description");
                jsonWriter.writeCharArray(*m_Request.getDescription());
            }
            if (m_Request.getMethodType())
            {
                jsonWriter.writePropertyName("methodType");
                jsonWriter.writeCharArray(*m_Request.getMethodType());
            }
            if (m_Request.getCardCustomerId())
            {
                jsonWriter.writePropertyName("cardCustomerId");
                jsonWriter.writeCharArray(*m_Request.getCardCustomerId());
            }
            if (m_Request.getPartnerId())
            {
                jsonWriter.writePropertyName("partnerId");
                jsonWriter.writeCharArray(*m_Request.getPartnerId());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        CreateBillingMethodTask(
            CreateBillingMethodRequest request,
            Gs2WebSocketSessionTask<CreateBillingMethodResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateBillingMethodResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateBillingMethodTask() GS2_OVERRIDE = default;
    };

    class GetBillingMethodTask : public detail::Gs2WebSocketSessionTask<GetBillingMethodResult>
    {
    private:
        GetBillingMethodRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "project";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "billingMethod";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getBillingMethod";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getAccountToken())
            {
                jsonWriter.writePropertyName("accountToken");
                jsonWriter.writeCharArray(*m_Request.getAccountToken());
            }
            if (m_Request.getBillingMethodName())
            {
                jsonWriter.writePropertyName("billingMethodName");
                jsonWriter.writeCharArray(*m_Request.getBillingMethodName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetBillingMethodTask(
            GetBillingMethodRequest request,
            Gs2WebSocketSessionTask<GetBillingMethodResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetBillingMethodResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetBillingMethodTask() GS2_OVERRIDE = default;
    };

    class UpdateBillingMethodTask : public detail::Gs2WebSocketSessionTask<UpdateBillingMethodResult>
    {
    private:
        UpdateBillingMethodRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "project";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "billingMethod";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateBillingMethod";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getAccountToken())
            {
                jsonWriter.writePropertyName("accountToken");
                jsonWriter.writeCharArray(*m_Request.getAccountToken());
            }
            if (m_Request.getBillingMethodName())
            {
                jsonWriter.writePropertyName("billingMethodName");
                jsonWriter.writeCharArray(*m_Request.getBillingMethodName());
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
        UpdateBillingMethodTask(
            UpdateBillingMethodRequest request,
            Gs2WebSocketSessionTask<UpdateBillingMethodResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateBillingMethodResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateBillingMethodTask() GS2_OVERRIDE = default;
    };

    class DeleteBillingMethodTask : public detail::Gs2WebSocketSessionTask<DeleteBillingMethodResult>
    {
    private:
        DeleteBillingMethodRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "project";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "billingMethod";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteBillingMethod";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getAccountToken())
            {
                jsonWriter.writePropertyName("accountToken");
                jsonWriter.writeCharArray(*m_Request.getAccountToken());
            }
            if (m_Request.getBillingMethodName())
            {
                jsonWriter.writePropertyName("billingMethodName");
                jsonWriter.writeCharArray(*m_Request.getBillingMethodName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        DeleteBillingMethodTask(
            DeleteBillingMethodRequest request,
            Gs2WebSocketSessionTask<DeleteBillingMethodResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteBillingMethodResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteBillingMethodTask() GS2_OVERRIDE = default;
    };

    class DescribeReceiptsTask : public detail::Gs2WebSocketSessionTask<DescribeReceiptsResult>
    {
    private:
        DescribeReceiptsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "project";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "receipt";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeReceipts";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getAccountToken())
            {
                jsonWriter.writePropertyName("accountToken");
                jsonWriter.writeCharArray(*m_Request.getAccountToken());
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
        DescribeReceiptsTask(
            DescribeReceiptsRequest request,
            Gs2WebSocketSessionTask<DescribeReceiptsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeReceiptsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeReceiptsTask() GS2_OVERRIDE = default;
    };

    class DescribeBillingsTask : public detail::Gs2WebSocketSessionTask<DescribeBillingsResult>
    {
    private:
        DescribeBillingsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "project";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "billing";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeBillings";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getAccountToken())
            {
                jsonWriter.writePropertyName("accountToken");
                jsonWriter.writeCharArray(*m_Request.getAccountToken());
            }
            if (m_Request.getProjectName())
            {
                jsonWriter.writePropertyName("projectName");
                jsonWriter.writeCharArray(*m_Request.getProjectName());
            }
            if (m_Request.getYear())
            {
                jsonWriter.writePropertyName("year");
                jsonWriter.writeInt32(*m_Request.getYear());
            }
            if (m_Request.getMonth())
            {
                jsonWriter.writePropertyName("month");
                jsonWriter.writeInt32(*m_Request.getMonth());
            }
            if (m_Request.getRegion())
            {
                jsonWriter.writePropertyName("region");
                jsonWriter.writeCharArray(*m_Request.getRegion());
            }
            if (m_Request.getService())
            {
                jsonWriter.writePropertyName("service");
                jsonWriter.writeCharArray(*m_Request.getService());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        DescribeBillingsTask(
            DescribeBillingsRequest request,
            Gs2WebSocketSessionTask<DescribeBillingsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeBillingsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeBillingsTask() GS2_OVERRIDE = default;
    };

protected:
    static void write(detail::json::JsonWriter& jsonWriter, const Account& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getAccountId())
        {
            jsonWriter.writePropertyName("accountId");
            jsonWriter.writeCharArray(*obj.getAccountId());
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
        if (obj.getEmail())
        {
            jsonWriter.writePropertyName("email");
            jsonWriter.writeCharArray(*obj.getEmail());
        }
        if (obj.getFullName())
        {
            jsonWriter.writePropertyName("fullName");
            jsonWriter.writeCharArray(*obj.getFullName());
        }
        if (obj.getCompanyName())
        {
            jsonWriter.writePropertyName("companyName");
            jsonWriter.writeCharArray(*obj.getCompanyName());
        }
        if (obj.getPassword())
        {
            jsonWriter.writePropertyName("password");
            jsonWriter.writeCharArray(*obj.getPassword());
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

    static void write(detail::json::JsonWriter& jsonWriter, const Project& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getProjectId())
        {
            jsonWriter.writePropertyName("projectId");
            jsonWriter.writeCharArray(*obj.getProjectId());
        }
        if (obj.getAccountName())
        {
            jsonWriter.writePropertyName("accountName");
            jsonWriter.writeCharArray(*obj.getAccountName());
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
        if (obj.getPlan())
        {
            jsonWriter.writePropertyName("plan");
            jsonWriter.writeCharArray(*obj.getPlan());
        }
        if (obj.getBillingMethodName())
        {
            jsonWriter.writePropertyName("billingMethodName");
            jsonWriter.writeCharArray(*obj.getBillingMethodName());
        }
        if (obj.getEnableEventBridge())
        {
            jsonWriter.writePropertyName("enableEventBridge");
            jsonWriter.writeCharArray(*obj.getEnableEventBridge());
        }
        if (obj.getEventBridgeAwsAccountId())
        {
            jsonWriter.writePropertyName("eventBridgeAwsAccountId");
            jsonWriter.writeCharArray(*obj.getEventBridgeAwsAccountId());
        }
        if (obj.getEventBridgeAwsRegion())
        {
            jsonWriter.writePropertyName("eventBridgeAwsRegion");
            jsonWriter.writeCharArray(*obj.getEventBridgeAwsRegion());
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

    static void write(detail::json::JsonWriter& jsonWriter, const BillingMethod& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getBillingMethodId())
        {
            jsonWriter.writePropertyName("billingMethodId");
            jsonWriter.writeCharArray(*obj.getBillingMethodId());
        }
        if (obj.getAccountName())
        {
            jsonWriter.writePropertyName("accountName");
            jsonWriter.writeCharArray(*obj.getAccountName());
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
        if (obj.getMethodType())
        {
            jsonWriter.writePropertyName("methodType");
            jsonWriter.writeCharArray(*obj.getMethodType());
        }
        if (obj.getCardCustomerId())
        {
            jsonWriter.writePropertyName("cardCustomerId");
            jsonWriter.writeCharArray(*obj.getCardCustomerId());
        }
        if (obj.getCardSignatureName())
        {
            jsonWriter.writePropertyName("cardSignatureName");
            jsonWriter.writeCharArray(*obj.getCardSignatureName());
        }
        if (obj.getCardBrand())
        {
            jsonWriter.writePropertyName("cardBrand");
            jsonWriter.writeCharArray(*obj.getCardBrand());
        }
        if (obj.getCardLast4())
        {
            jsonWriter.writePropertyName("cardLast4");
            jsonWriter.writeCharArray(*obj.getCardLast4());
        }
        if (obj.getPartnerId())
        {
            jsonWriter.writePropertyName("partnerId");
            jsonWriter.writeCharArray(*obj.getPartnerId());
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

    static void write(detail::json::JsonWriter& jsonWriter, const Receipt& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getReceiptId())
        {
            jsonWriter.writePropertyName("receiptId");
            jsonWriter.writeCharArray(*obj.getReceiptId());
        }
        if (obj.getAccountName())
        {
            jsonWriter.writePropertyName("accountName");
            jsonWriter.writeCharArray(*obj.getAccountName());
        }
        if (obj.getName())
        {
            jsonWriter.writePropertyName("name");
            jsonWriter.writeCharArray(*obj.getName());
        }
        if (obj.getDate())
        {
            jsonWriter.writePropertyName("date");
            jsonWriter.writeInt64(*obj.getDate());
        }
        if (obj.getAmount())
        {
            jsonWriter.writePropertyName("amount");
            jsonWriter.writeCharArray(*obj.getAmount());
        }
        if (obj.getPdfUrl())
        {
            jsonWriter.writePropertyName("pdfUrl");
            jsonWriter.writeCharArray(*obj.getPdfUrl());
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

    static void write(detail::json::JsonWriter& jsonWriter, const Billing& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getBillingId())
        {
            jsonWriter.writePropertyName("billingId");
            jsonWriter.writeCharArray(*obj.getBillingId());
        }
        if (obj.getProjectName())
        {
            jsonWriter.writePropertyName("projectName");
            jsonWriter.writeCharArray(*obj.getProjectName());
        }
        if (obj.getYear())
        {
            jsonWriter.writePropertyName("year");
            jsonWriter.writeInt32(*obj.getYear());
        }
        if (obj.getMonth())
        {
            jsonWriter.writePropertyName("month");
            jsonWriter.writeInt32(*obj.getMonth());
        }
        if (obj.getRegion())
        {
            jsonWriter.writePropertyName("region");
            jsonWriter.writeCharArray(*obj.getRegion());
        }
        if (obj.getService())
        {
            jsonWriter.writePropertyName("service");
            jsonWriter.writeCharArray(*obj.getService());
        }
        if (obj.getActivityType())
        {
            jsonWriter.writePropertyName("activityType");
            jsonWriter.writeCharArray(*obj.getActivityType());
        }
        if (obj.getUnit())
        {
            jsonWriter.writePropertyName("unit");
            jsonWriter.writeInt64(*obj.getUnit());
        }
        if (obj.getUnitName())
        {
            jsonWriter.writePropertyName("unitName");
            jsonWriter.writeCharArray(*obj.getUnitName());
        }
        if (obj.getPrice())
        {
            jsonWriter.writePropertyName("price");
            jsonWriter.writeInt64(*obj.getPrice());
        }
        if (obj.getCurrency())
        {
            jsonWriter.writePropertyName("currency");
            jsonWriter.writeCharArray(*obj.getCurrency());
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


public:
    /**
     * コンストラクタ。
     *
     * @param gs2WebSocketSession WebSocket API 用セッション
     */
    explicit Gs2ProjectWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
        AbstractGs2ClientBase(gs2WebSocketSession)
    {
    }

	/**
	 * アカウントを新規作成<br>
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
	 * GS2アカウントを有効化します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void verify_(VerifyRequest request, std::function<void(AsyncVerifyResult)> callback)
    {
        VerifyTask& task = *new VerifyTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * サインインします<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void signIn(SignInRequest request, std::function<void(AsyncSignInResult)> callback)
    {
        SignInTask& task = *new SignInTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 指定したアカウント名のアカウントトークンを発行<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void issueAccountToken(IssueAccountTokenRequest request, std::function<void(AsyncIssueAccountTokenResult)> callback)
    {
        IssueAccountTokenTask& task = *new IssueAccountTokenTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * パスワード再発行トークンを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void forget(ForgetRequest request, std::function<void(AsyncForgetResult)> callback)
    {
        ForgetTask& task = *new ForgetTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * パスワードを再発行<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void issuePassword(IssuePasswordRequest request, std::function<void(AsyncIssuePasswordResult)> callback)
    {
        IssuePasswordTask& task = *new IssuePasswordTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * GS2アカウントを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateAccount(UpdateAccountRequest request, std::function<void(AsyncUpdateAccountResult)> callback)
    {
        UpdateAccountTask& task = *new UpdateAccountTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * GS2アカウントを削除します<br>
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
	 * プロジェクトの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeProjects(DescribeProjectsRequest request, std::function<void(AsyncDescribeProjectsResult)> callback)
    {
        DescribeProjectsTask& task = *new DescribeProjectsTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * プロジェクトを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createProject(CreateProjectRequest request, std::function<void(AsyncCreateProjectResult)> callback)
    {
        CreateProjectTask& task = *new CreateProjectTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * プロジェクトを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getProject(GetProjectRequest request, std::function<void(AsyncGetProjectResult)> callback)
    {
        GetProjectTask& task = *new GetProjectTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * プロジェクトトークンを発行します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getProjectToken(GetProjectTokenRequest request, std::function<void(AsyncGetProjectTokenResult)> callback)
    {
        GetProjectTokenTask& task = *new GetProjectTokenTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * プロジェクトを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateProject(UpdateProjectRequest request, std::function<void(AsyncUpdateProjectResult)> callback)
    {
        UpdateProjectTask& task = *new UpdateProjectTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * プロジェクトを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteProject(DeleteProjectRequest request, std::function<void(AsyncDeleteProjectResult)> callback)
    {
        DeleteProjectTask& task = *new DeleteProjectTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 支払い方法の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeBillingMethods(DescribeBillingMethodsRequest request, std::function<void(AsyncDescribeBillingMethodsResult)> callback)
    {
        DescribeBillingMethodsTask& task = *new DescribeBillingMethodsTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 支払い方法を新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createBillingMethod(CreateBillingMethodRequest request, std::function<void(AsyncCreateBillingMethodResult)> callback)
    {
        CreateBillingMethodTask& task = *new CreateBillingMethodTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 支払い方法を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getBillingMethod(GetBillingMethodRequest request, std::function<void(AsyncGetBillingMethodResult)> callback)
    {
        GetBillingMethodTask& task = *new GetBillingMethodTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 支払い方法を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateBillingMethod(UpdateBillingMethodRequest request, std::function<void(AsyncUpdateBillingMethodResult)> callback)
    {
        UpdateBillingMethodTask& task = *new UpdateBillingMethodTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 支払い方法を削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteBillingMethod(DeleteBillingMethodRequest request, std::function<void(AsyncDeleteBillingMethodResult)> callback)
    {
        DeleteBillingMethodTask& task = *new DeleteBillingMethodTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 領収書の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeReceipts(DescribeReceiptsRequest request, std::function<void(AsyncDescribeReceiptsResult)> callback)
    {
        DescribeReceiptsTask& task = *new DescribeReceiptsTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 利用状況の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeBillings(DescribeBillingsRequest request, std::function<void(AsyncDescribeBillingsResult)> callback)
    {
        DescribeBillingsTask& task = *new DescribeBillingsTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_PROJECT_GS2PROJECTWEBSOCKETCLIENT_HPP_