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

#ifndef GS2_PROJECT_GS2PROJECTRESTCLIENT_HPP_
#define GS2_PROJECT_GS2PROJECTRESTCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2RestSessionTask.hpp>
#include <gs2/core/network/Gs2RestSession.hpp>
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
class Gs2ProjectRestClient : public AbstractGs2ClientBase
{
private:

    class CreateAccountTask : public detail::Gs2RestSessionTask<CreateAccountResult>
    {
    private:
        CreateAccountRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "project";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/account";
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
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
            jsonWriter.writeObjectEnd();
            {
                gs2HttpTask.setBody(jsonWriter.toString());
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Post;
        }

    public:
        CreateAccountTask(
            CreateAccountRequest request,
            Gs2RestSessionTask<CreateAccountResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CreateAccountResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateAccountTask() GS2_OVERRIDE = default;
    };

    class VerifyTask : public detail::Gs2RestSessionTask<VerifyResult>
    {
    private:
        VerifyRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "project";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/account/verify";
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
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
            jsonWriter.writeObjectEnd();
            {
                gs2HttpTask.setBody(jsonWriter.toString());
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Post;
        }

    public:
        VerifyTask(
            VerifyRequest request,
            Gs2RestSessionTask<VerifyResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<VerifyResult>(callback),
            m_Request(std::move(request))
        {}

        ~VerifyTask() GS2_OVERRIDE = default;
    };

    class SignInTask : public detail::Gs2RestSessionTask<SignInResult>
    {
    private:
        SignInRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "project";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/account/signIn";
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
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
            jsonWriter.writeObjectEnd();
            {
                gs2HttpTask.setBody(jsonWriter.toString());
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Post;
        }

    public:
        SignInTask(
            SignInRequest request,
            Gs2RestSessionTask<SignInResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<SignInResult>(callback),
            m_Request(std::move(request))
        {}

        ~SignInTask() GS2_OVERRIDE = default;
    };

    class IssueAccountTokenTask : public detail::Gs2RestSessionTask<IssueAccountTokenResult>
    {
    private:
        IssueAccountTokenRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "project";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/account/accountToken";
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
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
            jsonWriter.writeObjectEnd();
            {
                gs2HttpTask.setBody(jsonWriter.toString());
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Post;
        }

    public:
        IssueAccountTokenTask(
            IssueAccountTokenRequest request,
            Gs2RestSessionTask<IssueAccountTokenResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<IssueAccountTokenResult>(callback),
            m_Request(std::move(request))
        {}

        ~IssueAccountTokenTask() GS2_OVERRIDE = default;
    };

    class ForgetTask : public detail::Gs2RestSessionTask<ForgetResult>
    {
    private:
        ForgetRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "project";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/account/forget";
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
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
            jsonWriter.writeObjectEnd();
            {
                gs2HttpTask.setBody(jsonWriter.toString());
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Post;
        }

    public:
        ForgetTask(
            ForgetRequest request,
            Gs2RestSessionTask<ForgetResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<ForgetResult>(callback),
            m_Request(std::move(request))
        {}

        ~ForgetTask() GS2_OVERRIDE = default;
    };

    class IssuePasswordTask : public detail::Gs2RestSessionTask<IssuePasswordResult>
    {
    private:
        IssuePasswordRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "project";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/account/password/issue";
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
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
            jsonWriter.writeObjectEnd();
            {
                gs2HttpTask.setBody(jsonWriter.toString());
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Post;
        }

    public:
        IssuePasswordTask(
            IssuePasswordRequest request,
            Gs2RestSessionTask<IssuePasswordResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<IssuePasswordResult>(callback),
            m_Request(std::move(request))
        {}

        ~IssuePasswordTask() GS2_OVERRIDE = default;
    };

    class UpdateAccountTask : public detail::Gs2RestSessionTask<UpdateAccountResult>
    {
    private:
        UpdateAccountRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "project";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/account";
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
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
            jsonWriter.writeObjectEnd();
            {
                gs2HttpTask.setBody(jsonWriter.toString());
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Put;
        }

    public:
        UpdateAccountTask(
            UpdateAccountRequest request,
            Gs2RestSessionTask<UpdateAccountResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateAccountResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateAccountTask() GS2_OVERRIDE = default;
    };

    class DeleteAccountTask : public detail::Gs2RestSessionTask<void>
    {
    private:
        DeleteAccountRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "project";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/account";

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            {
                gs2HttpTask.setBody("[]");
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Delete;
        }

    public:
        DeleteAccountTask(
            DeleteAccountRequest request,
            Gs2RestSessionTask<void>::CallbackType callback
        ) :
            Gs2RestSessionTask<void>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteAccountTask() GS2_OVERRIDE = default;
    };

    class DescribeProjectsTask : public detail::Gs2RestSessionTask<DescribeProjectsResult>
    {
    private:
        DescribeProjectsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "project";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/account/me/project";

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getAccountToken())
            {
                url += joint;
                url += "accountToken=";
                url += detail::StringVariable(*m_Request.getAccountToken(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getPageToken())
            {
                url += joint;
                url += "pageToken=";
                url += detail::StringVariable(*m_Request.getPageToken(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getLimit())
            {
                url += joint;
                url += "limit=";
                url += detail::StringVariable(*m_Request.getLimit()).c_str();
                joint[0] = '&';
            }

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        DescribeProjectsTask(
            DescribeProjectsRequest request,
            Gs2RestSessionTask<DescribeProjectsResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeProjectsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeProjectsTask() GS2_OVERRIDE = default;
    };

    class CreateProjectTask : public detail::Gs2RestSessionTask<CreateProjectResult>
    {
    private:
        CreateProjectRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "project";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/account/me/project";
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
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
            jsonWriter.writeObjectEnd();
            {
                gs2HttpTask.setBody(jsonWriter.toString());
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Post;
        }

    public:
        CreateProjectTask(
            CreateProjectRequest request,
            Gs2RestSessionTask<CreateProjectResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CreateProjectResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateProjectTask() GS2_OVERRIDE = default;
    };

    class GetProjectTask : public detail::Gs2RestSessionTask<GetProjectResult>
    {
    private:
        GetProjectRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "project";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/account/me/project/{projectName}";
            {
                auto& value = m_Request.getProjectName();
                url.replace("{projectName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getAccountToken())
            {
                url += joint;
                url += "accountToken=";
                url += detail::StringVariable(*m_Request.getAccountToken(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        GetProjectTask(
            GetProjectRequest request,
            Gs2RestSessionTask<GetProjectResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetProjectResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetProjectTask() GS2_OVERRIDE = default;
    };

    class GetProjectTokenTask : public detail::Gs2RestSessionTask<GetProjectTokenResult>
    {
    private:
        GetProjectTokenRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "project";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/project/{projectName}/projectToken";
            {
                auto& value = m_Request.getProjectName();
                url.replace("{projectName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
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
            jsonWriter.writeObjectEnd();
            {
                gs2HttpTask.setBody(jsonWriter.toString());
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Post;
        }

    public:
        GetProjectTokenTask(
            GetProjectTokenRequest request,
            Gs2RestSessionTask<GetProjectTokenResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetProjectTokenResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetProjectTokenTask() GS2_OVERRIDE = default;
    };

    class UpdateProjectTask : public detail::Gs2RestSessionTask<UpdateProjectResult>
    {
    private:
        UpdateProjectRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "project";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/account/me/project/{projectName}";
            {
                auto& value = m_Request.getProjectName();
                url.replace("{projectName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
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
            jsonWriter.writeObjectEnd();
            {
                gs2HttpTask.setBody(jsonWriter.toString());
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Put;
        }

    public:
        UpdateProjectTask(
            UpdateProjectRequest request,
            Gs2RestSessionTask<UpdateProjectResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateProjectResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateProjectTask() GS2_OVERRIDE = default;
    };

    class DeleteProjectTask : public detail::Gs2RestSessionTask<DeleteProjectResult>
    {
    private:
        DeleteProjectRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "project";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/account/me/project/{projectName}";
            {
                auto& value = m_Request.getProjectName();
                url.replace("{projectName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getAccountToken())
            {
                url += joint;
                url += "accountToken=";
                url += detail::StringVariable(*m_Request.getAccountToken(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            {
                gs2HttpTask.setBody("[]");
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Delete;
        }

    public:
        DeleteProjectTask(
            DeleteProjectRequest request,
            Gs2RestSessionTask<DeleteProjectResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteProjectResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteProjectTask() GS2_OVERRIDE = default;
    };

private:
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
     * @param gs2RestSession REST API 用セッション
     */
    explicit Gs2ProjectRestClient(Gs2RestSession& gs2RestSession) :
        AbstractGs2ClientBase(gs2RestSession)
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
        getGs2RestSession().execute(task);
    }

	/**
	 * GS2アカウントを有効化します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void verify(VerifyRequest request, std::function<void(AsyncVerifyResult)> callback)
    {
        VerifyTask& task = *new VerifyTask(std::move(request), callback);
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
    }

protected:
    Gs2RestSession& getGs2RestSession()
    {
        return static_cast<Gs2RestSession&>(getGs2Session());
    }
};

} }

#endif //GS2_PROJECT_GS2PROJECTRESTCLIENT_HPP_