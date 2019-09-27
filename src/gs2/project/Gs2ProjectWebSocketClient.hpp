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

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_PROJECT_GS2PROJECTWEBSOCKETCLIENT_HPP_