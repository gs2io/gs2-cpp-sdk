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
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
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

typedef AsyncResult<CreateAccountResult> AsyncCreateAccountResult;
typedef AsyncResult<VerifyResult> AsyncVerifyResult;
typedef AsyncResult<SignInResult> AsyncSignInResult;
typedef AsyncResult<IssueAccountTokenResult> AsyncIssueAccountTokenResult;
typedef AsyncResult<ForgetResult> AsyncForgetResult;
typedef AsyncResult<IssuePasswordResult> AsyncIssuePasswordResult;
typedef AsyncResult<UpdateAccountResult> AsyncUpdateAccountResult;
typedef AsyncResult<void> AsyncDeleteAccountResult;
typedef AsyncResult<DescribeProjectsResult> AsyncDescribeProjectsResult;
typedef AsyncResult<CreateProjectResult> AsyncCreateProjectResult;
typedef AsyncResult<GetProjectResult> AsyncGetProjectResult;
typedef AsyncResult<GetProjectTokenResult> AsyncGetProjectTokenResult;
typedef AsyncResult<UpdateProjectResult> AsyncUpdateProjectResult;
typedef AsyncResult<DeleteProjectResult> AsyncDeleteProjectResult;

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
        CreateAccountRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getEmail())
            {
                writer.writePropertyName("email");
                writer.writeCharArray(*m_Request.getEmail());
            }
            if (m_Request.getFullName())
            {
                writer.writePropertyName("fullName");
                writer.writeCharArray(*m_Request.getFullName());
            }
            if (m_Request.getCompanyName())
            {
                writer.writePropertyName("companyName");
                writer.writeCharArray(*m_Request.getCompanyName());
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

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("project");
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

    class VerifyTask : public detail::Gs2WebSocketSessionTask<VerifyResult>
    {
    private:
        VerifyRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getVerifyToken())
            {
                writer.writePropertyName("verifyToken");
                writer.writeCharArray(*m_Request.getVerifyToken());
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
            writer.writeCharArray("project");
            writer.writePropertyName("component");
            writer.writeCharArray("account");
            writer.writePropertyName("function");
            writer.writeCharArray("verify");
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
        VerifyTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            VerifyRequest& request,
            Gs2WebSocketSessionTask<VerifyResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<VerifyResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~VerifyTask() GS2_OVERRIDE = default;
    };

    class SignInTask : public detail::Gs2WebSocketSessionTask<SignInResult>
    {
    private:
        SignInRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getEmail())
            {
                writer.writePropertyName("email");
                writer.writeCharArray(*m_Request.getEmail());
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

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("project");
            writer.writePropertyName("component");
            writer.writeCharArray("account");
            writer.writePropertyName("function");
            writer.writeCharArray("signIn");
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
        SignInTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            SignInRequest& request,
            Gs2WebSocketSessionTask<SignInResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<SignInResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~SignInTask() GS2_OVERRIDE = default;
    };

    class IssueAccountTokenTask : public detail::Gs2WebSocketSessionTask<IssueAccountTokenResult>
    {
    private:
        IssueAccountTokenRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getAccountName())
            {
                writer.writePropertyName("accountName");
                writer.writeCharArray(*m_Request.getAccountName());
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
            writer.writeCharArray("project");
            writer.writePropertyName("component");
            writer.writeCharArray("account");
            writer.writePropertyName("function");
            writer.writeCharArray("issueAccountToken");
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
        IssueAccountTokenTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            IssueAccountTokenRequest& request,
            Gs2WebSocketSessionTask<IssueAccountTokenResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<IssueAccountTokenResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~IssueAccountTokenTask() GS2_OVERRIDE = default;
    };

    class ForgetTask : public detail::Gs2WebSocketSessionTask<ForgetResult>
    {
    private:
        ForgetRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getEmail())
            {
                writer.writePropertyName("email");
                writer.writeCharArray(*m_Request.getEmail());
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
            writer.writeCharArray("project");
            writer.writePropertyName("component");
            writer.writeCharArray("account");
            writer.writePropertyName("function");
            writer.writeCharArray("forget");
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
        ForgetTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            ForgetRequest& request,
            Gs2WebSocketSessionTask<ForgetResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<ForgetResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~ForgetTask() GS2_OVERRIDE = default;
    };

    class IssuePasswordTask : public detail::Gs2WebSocketSessionTask<IssuePasswordResult>
    {
    private:
        IssuePasswordRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getIssuePasswordToken())
            {
                writer.writePropertyName("issuePasswordToken");
                writer.writeCharArray(*m_Request.getIssuePasswordToken());
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
            writer.writeCharArray("project");
            writer.writePropertyName("component");
            writer.writeCharArray("account");
            writer.writePropertyName("function");
            writer.writeCharArray("issuePassword");
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
        IssuePasswordTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            IssuePasswordRequest& request,
            Gs2WebSocketSessionTask<IssuePasswordResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<IssuePasswordResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~IssuePasswordTask() GS2_OVERRIDE = default;
    };

    class UpdateAccountTask : public detail::Gs2WebSocketSessionTask<UpdateAccountResult>
    {
    private:
        UpdateAccountRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getEmail())
            {
                writer.writePropertyName("email");
                writer.writeCharArray(*m_Request.getEmail());
            }
            if (m_Request.getFullName())
            {
                writer.writePropertyName("fullName");
                writer.writeCharArray(*m_Request.getFullName());
            }
            if (m_Request.getCompanyName())
            {
                writer.writePropertyName("companyName");
                writer.writeCharArray(*m_Request.getCompanyName());
            }
            if (m_Request.getPassword())
            {
                writer.writePropertyName("password");
                writer.writeCharArray(*m_Request.getPassword());
            }
            if (m_Request.getAccountToken())
            {
                writer.writePropertyName("accountToken");
                writer.writeCharArray(*m_Request.getAccountToken());
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
            writer.writeCharArray("project");
            writer.writePropertyName("component");
            writer.writeCharArray("account");
            writer.writePropertyName("function");
            writer.writeCharArray("updateAccount");
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
        UpdateAccountTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateAccountRequest& request,
            Gs2WebSocketSessionTask<UpdateAccountResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateAccountResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateAccountTask() GS2_OVERRIDE = default;
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
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

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
            writer.writeCharArray("project");
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

    class DescribeProjectsTask : public detail::Gs2WebSocketSessionTask<DescribeProjectsResult>
    {
    private:
        DescribeProjectsRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getAccountToken())
            {
                writer.writePropertyName("accountToken");
                writer.writeCharArray(*m_Request.getAccountToken());
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
            writer.writeCharArray("project");
            writer.writePropertyName("component");
            writer.writeCharArray("project");
            writer.writePropertyName("function");
            writer.writeCharArray("describeProjects");
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
        DescribeProjectsTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeProjectsRequest& request,
            Gs2WebSocketSessionTask<DescribeProjectsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeProjectsResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeProjectsTask() GS2_OVERRIDE = default;
    };

    class CreateProjectTask : public detail::Gs2WebSocketSessionTask<CreateProjectResult>
    {
    private:
        CreateProjectRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getAccountToken())
            {
                writer.writePropertyName("accountToken");
                writer.writeCharArray(*m_Request.getAccountToken());
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
            writer.writeCharArray("project");
            writer.writePropertyName("component");
            writer.writeCharArray("project");
            writer.writePropertyName("function");
            writer.writeCharArray("createProject");
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
        CreateProjectTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            CreateProjectRequest& request,
            Gs2WebSocketSessionTask<CreateProjectResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateProjectResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~CreateProjectTask() GS2_OVERRIDE = default;
    };

    class GetProjectTask : public detail::Gs2WebSocketSessionTask<GetProjectResult>
    {
    private:
        GetProjectRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getAccountToken())
            {
                writer.writePropertyName("accountToken");
                writer.writeCharArray(*m_Request.getAccountToken());
            }
            if (m_Request.getProjectName())
            {
                writer.writePropertyName("projectName");
                writer.writeCharArray(*m_Request.getProjectName());
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
            writer.writeCharArray("project");
            writer.writePropertyName("component");
            writer.writeCharArray("project");
            writer.writePropertyName("function");
            writer.writeCharArray("getProject");
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
        GetProjectTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetProjectRequest& request,
            Gs2WebSocketSessionTask<GetProjectResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetProjectResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetProjectTask() GS2_OVERRIDE = default;
    };

    class GetProjectTokenTask : public detail::Gs2WebSocketSessionTask<GetProjectTokenResult>
    {
    private:
        GetProjectTokenRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getProjectName())
            {
                writer.writePropertyName("projectName");
                writer.writeCharArray(*m_Request.getProjectName());
            }
            if (m_Request.getAccountToken())
            {
                writer.writePropertyName("accountToken");
                writer.writeCharArray(*m_Request.getAccountToken());
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
            writer.writeCharArray("project");
            writer.writePropertyName("component");
            writer.writeCharArray("project");
            writer.writePropertyName("function");
            writer.writeCharArray("getProjectToken");
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
        GetProjectTokenTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetProjectTokenRequest& request,
            Gs2WebSocketSessionTask<GetProjectTokenResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetProjectTokenResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetProjectTokenTask() GS2_OVERRIDE = default;
    };

    class UpdateProjectTask : public detail::Gs2WebSocketSessionTask<UpdateProjectResult>
    {
    private:
        UpdateProjectRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getAccountToken())
            {
                writer.writePropertyName("accountToken");
                writer.writeCharArray(*m_Request.getAccountToken());
            }
            if (m_Request.getProjectName())
            {
                writer.writePropertyName("projectName");
                writer.writeCharArray(*m_Request.getProjectName());
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
            writer.writeCharArray("project");
            writer.writePropertyName("component");
            writer.writeCharArray("project");
            writer.writePropertyName("function");
            writer.writeCharArray("updateProject");
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
        UpdateProjectTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateProjectRequest& request,
            Gs2WebSocketSessionTask<UpdateProjectResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateProjectResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateProjectTask() GS2_OVERRIDE = default;
    };

    class DeleteProjectTask : public detail::Gs2WebSocketSessionTask<DeleteProjectResult>
    {
    private:
        DeleteProjectRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getAccountToken())
            {
                writer.writePropertyName("accountToken");
                writer.writeCharArray(*m_Request.getAccountToken());
            }
            if (m_Request.getProjectName())
            {
                writer.writePropertyName("projectName");
                writer.writeCharArray(*m_Request.getProjectName());
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
            writer.writeCharArray("project");
            writer.writePropertyName("component");
            writer.writeCharArray("project");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteProject");
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
        DeleteProjectTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteProjectRequest& request,
            Gs2WebSocketSessionTask<DeleteProjectResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteProjectResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteProjectTask() GS2_OVERRIDE = default;
    };

private:
    static void write(detail::json::JsonWriter& writer, const Account& obj)
    {
        writer.writeObjectStart();
        if (obj.getAccountId())
        {
            writer.writePropertyName("accountId");
            writer.writeCharArray(*obj.getAccountId());
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
        if (obj.getEmail())
        {
            writer.writePropertyName("email");
            writer.writeCharArray(*obj.getEmail());
        }
        if (obj.getFullName())
        {
            writer.writePropertyName("fullName");
            writer.writeCharArray(*obj.getFullName());
        }
        if (obj.getCompanyName())
        {
            writer.writePropertyName("companyName");
            writer.writeCharArray(*obj.getCompanyName());
        }
        if (obj.getPassword())
        {
            writer.writePropertyName("password");
            writer.writeCharArray(*obj.getPassword());
        }
        if (obj.getStatus())
        {
            writer.writePropertyName("status");
            writer.writeCharArray(*obj.getStatus());
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

    static void write(detail::json::JsonWriter& writer, const Project& obj)
    {
        writer.writeObjectStart();
        if (obj.getProjectId())
        {
            writer.writePropertyName("projectId");
            writer.writeCharArray(*obj.getProjectId());
        }
        if (obj.getAccountName())
        {
            writer.writePropertyName("accountName");
            writer.writeCharArray(*obj.getAccountName());
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
    void createAccount(std::function<void(AsyncCreateAccountResult&)> callback, CreateAccountRequest& request)
    {
        CreateAccountTask& task = *new CreateAccountTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * GS2アカウントを有効化します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void verify(std::function<void(AsyncVerifyResult&)> callback, VerifyRequest& request)
    {
        VerifyTask& task = *new VerifyTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * サインインします<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void signIn(std::function<void(AsyncSignInResult&)> callback, SignInRequest& request)
    {
        SignInTask& task = *new SignInTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 指定したアカウント名のアカウントトークンを発行<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void issueAccountToken(std::function<void(AsyncIssueAccountTokenResult&)> callback, IssueAccountTokenRequest& request)
    {
        IssueAccountTokenTask& task = *new IssueAccountTokenTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * パスワード再発行トークンを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void forget(std::function<void(AsyncForgetResult&)> callback, ForgetRequest& request)
    {
        ForgetTask& task = *new ForgetTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * パスワードを再発行<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void issuePassword(std::function<void(AsyncIssuePasswordResult&)> callback, IssuePasswordRequest& request)
    {
        IssuePasswordTask& task = *new IssuePasswordTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * GS2アカウントを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateAccount(std::function<void(AsyncUpdateAccountResult&)> callback, UpdateAccountRequest& request)
    {
        UpdateAccountTask& task = *new UpdateAccountTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * GS2アカウントを削除します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteAccount(std::function<void(AsyncDeleteAccountResult&)> callback, DeleteAccountRequest& request)
    {
        DeleteAccountTask& task = *new DeleteAccountTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * プロジェクトの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeProjects(std::function<void(AsyncDescribeProjectsResult&)> callback, DescribeProjectsRequest& request)
    {
        DescribeProjectsTask& task = *new DescribeProjectsTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * プロジェクトを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createProject(std::function<void(AsyncCreateProjectResult&)> callback, CreateProjectRequest& request)
    {
        CreateProjectTask& task = *new CreateProjectTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * プロジェクトを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getProject(std::function<void(AsyncGetProjectResult&)> callback, GetProjectRequest& request)
    {
        GetProjectTask& task = *new GetProjectTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * プロジェクトトークンを発行します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getProjectToken(std::function<void(AsyncGetProjectTokenResult&)> callback, GetProjectTokenRequest& request)
    {
        GetProjectTokenTask& task = *new GetProjectTokenTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * プロジェクトを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateProject(std::function<void(AsyncUpdateProjectResult&)> callback, UpdateProjectRequest& request)
    {
        UpdateProjectTask& task = *new UpdateProjectTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * プロジェクトを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteProject(std::function<void(AsyncDeleteProjectResult&)> callback, DeleteProjectRequest& request)
    {
        DeleteProjectTask& task = *new DeleteProjectTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_PROJECT_GS2PROJECTWEBSOCKETCLIENT_HPP_