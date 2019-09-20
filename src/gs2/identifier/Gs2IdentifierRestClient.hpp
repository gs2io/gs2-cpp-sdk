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

#ifndef GS2_IDENTIFIER_GS2IDENTIFIERRESTCLIENT_HPP_
#define GS2_IDENTIFIER_GS2IDENTIFIERRESTCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2RestSessionTask.hpp>
#include <gs2/core/network/Gs2RestSession.hpp>
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

/**
 * GS2 Identifier API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2IdentifierRestClient : public AbstractGs2ClientBase
{
private:

    class DescribeUsersTask : public detail::Gs2RestSessionTask<DescribeUsersResult>
    {
    private:
        DescribeUsersRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/user";

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
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
        DescribeUsersTask(
            DescribeUsersRequest request,
            Gs2RestSessionTask<DescribeUsersResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeUsersResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeUsersTask() GS2_OVERRIDE = default;
    };

    class CreateUserTask : public detail::Gs2RestSessionTask<CreateUserResult>
    {
    private:
        CreateUserRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/user";
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
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
        CreateUserTask(
            CreateUserRequest request,
            Gs2RestSessionTask<CreateUserResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CreateUserResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateUserTask() GS2_OVERRIDE = default;
    };

    class UpdateUserTask : public detail::Gs2RestSessionTask<UpdateUserResult>
    {
    private:
        UpdateUserRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/user/{userName}";
            {
                auto& value = m_Request.getUserName();
                url.replace("{userName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
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
        UpdateUserTask(
            UpdateUserRequest request,
            Gs2RestSessionTask<UpdateUserResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateUserResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateUserTask() GS2_OVERRIDE = default;
    };

    class GetUserTask : public detail::Gs2RestSessionTask<GetUserResult>
    {
    private:
        GetUserRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/user/{userName}";
            {
                auto& value = m_Request.getUserName();
                url.replace("{userName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        GetUserTask(
            GetUserRequest request,
            Gs2RestSessionTask<GetUserResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetUserResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetUserTask() GS2_OVERRIDE = default;
    };

    class DeleteUserTask : public detail::Gs2RestSessionTask<void>
    {
    private:
        DeleteUserRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/user/{userName}";
            {
                auto& value = m_Request.getUserName();
                url.replace("{userName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

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
        DeleteUserTask(
            DeleteUserRequest request,
            Gs2RestSessionTask<void>::CallbackType callback
        ) :
            Gs2RestSessionTask<void>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteUserTask() GS2_OVERRIDE = default;
    };

    class DescribeSecurityPoliciesTask : public detail::Gs2RestSessionTask<DescribeSecurityPoliciesResult>
    {
    private:
        DescribeSecurityPoliciesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/securityPolicy";

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
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
        DescribeSecurityPoliciesTask(
            DescribeSecurityPoliciesRequest request,
            Gs2RestSessionTask<DescribeSecurityPoliciesResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeSecurityPoliciesResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeSecurityPoliciesTask() GS2_OVERRIDE = default;
    };

    class DescribeCommonSecurityPoliciesTask : public detail::Gs2RestSessionTask<DescribeCommonSecurityPoliciesResult>
    {
    private:
        DescribeCommonSecurityPoliciesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/securityPolicy/common";

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
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
        DescribeCommonSecurityPoliciesTask(
            DescribeCommonSecurityPoliciesRequest request,
            Gs2RestSessionTask<DescribeCommonSecurityPoliciesResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeCommonSecurityPoliciesResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeCommonSecurityPoliciesTask() GS2_OVERRIDE = default;
    };

    class CreateSecurityPolicyTask : public detail::Gs2RestSessionTask<CreateSecurityPolicyResult>
    {
    private:
        CreateSecurityPolicyRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/securityPolicy";
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
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
        CreateSecurityPolicyTask(
            CreateSecurityPolicyRequest request,
            Gs2RestSessionTask<CreateSecurityPolicyResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CreateSecurityPolicyResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateSecurityPolicyTask() GS2_OVERRIDE = default;
    };

    class UpdateSecurityPolicyTask : public detail::Gs2RestSessionTask<UpdateSecurityPolicyResult>
    {
    private:
        UpdateSecurityPolicyRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/securityPolicy/{securityPolicyName}";
            {
                auto& value = m_Request.getSecurityPolicyName();
                url.replace("{securityPolicyName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
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
        UpdateSecurityPolicyTask(
            UpdateSecurityPolicyRequest request,
            Gs2RestSessionTask<UpdateSecurityPolicyResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateSecurityPolicyResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateSecurityPolicyTask() GS2_OVERRIDE = default;
    };

    class GetSecurityPolicyTask : public detail::Gs2RestSessionTask<GetSecurityPolicyResult>
    {
    private:
        GetSecurityPolicyRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/securityPolicy/{securityPolicyName}";
            {
                auto& value = m_Request.getSecurityPolicyName();
                url.replace("{securityPolicyName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        GetSecurityPolicyTask(
            GetSecurityPolicyRequest request,
            Gs2RestSessionTask<GetSecurityPolicyResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetSecurityPolicyResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetSecurityPolicyTask() GS2_OVERRIDE = default;
    };

    class DeleteSecurityPolicyTask : public detail::Gs2RestSessionTask<void>
    {
    private:
        DeleteSecurityPolicyRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/securityPolicy/{securityPolicyName}";
            {
                auto& value = m_Request.getSecurityPolicyName();
                url.replace("{securityPolicyName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

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
        DeleteSecurityPolicyTask(
            DeleteSecurityPolicyRequest request,
            Gs2RestSessionTask<void>::CallbackType callback
        ) :
            Gs2RestSessionTask<void>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteSecurityPolicyTask() GS2_OVERRIDE = default;
    };

    class DescribeIdentifiersTask : public detail::Gs2RestSessionTask<DescribeIdentifiersResult>
    {
    private:
        DescribeIdentifiersRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/user/{userName}/identifier";
            {
                auto& value = m_Request.getUserName();
                url.replace("{userName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
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
        DescribeIdentifiersTask(
            DescribeIdentifiersRequest request,
            Gs2RestSessionTask<DescribeIdentifiersResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeIdentifiersResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeIdentifiersTask() GS2_OVERRIDE = default;
    };

    class CreateIdentifierTask : public detail::Gs2RestSessionTask<CreateIdentifierResult>
    {
    private:
        CreateIdentifierRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/user/{userName}/identifier";
            {
                auto& value = m_Request.getUserName();
                url.replace("{userName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
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
        CreateIdentifierTask(
            CreateIdentifierRequest request,
            Gs2RestSessionTask<CreateIdentifierResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CreateIdentifierResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateIdentifierTask() GS2_OVERRIDE = default;
    };

    class GetIdentifierTask : public detail::Gs2RestSessionTask<GetIdentifierResult>
    {
    private:
        GetIdentifierRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/user/{userName}/identifier/{clientId}";
            {
                auto& value = m_Request.getUserName();
                url.replace("{userName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getClientId();
                url.replace("{clientId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        GetIdentifierTask(
            GetIdentifierRequest request,
            Gs2RestSessionTask<GetIdentifierResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetIdentifierResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetIdentifierTask() GS2_OVERRIDE = default;
    };

    class DeleteIdentifierTask : public detail::Gs2RestSessionTask<void>
    {
    private:
        DeleteIdentifierRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/user/{userName}/identifier/{clientId}";
            {
                auto& value = m_Request.getUserName();
                url.replace("{userName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getClientId();
                url.replace("{clientId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

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
        DeleteIdentifierTask(
            DeleteIdentifierRequest request,
            Gs2RestSessionTask<void>::CallbackType callback
        ) :
            Gs2RestSessionTask<void>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteIdentifierTask() GS2_OVERRIDE = default;
    };

    class GetHasSecurityPolicyTask : public detail::Gs2RestSessionTask<GetHasSecurityPolicyResult>
    {
    private:
        GetHasSecurityPolicyRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/user/{userName}/securityPolicy";
            {
                auto& value = m_Request.getUserName();
                url.replace("{userName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        GetHasSecurityPolicyTask(
            GetHasSecurityPolicyRequest request,
            Gs2RestSessionTask<GetHasSecurityPolicyResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetHasSecurityPolicyResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetHasSecurityPolicyTask() GS2_OVERRIDE = default;
    };

    class AttachSecurityPolicyTask : public detail::Gs2RestSessionTask<AttachSecurityPolicyResult>
    {
    private:
        AttachSecurityPolicyRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/user/{userName}/securityPolicy";
            {
                auto& value = m_Request.getUserName();
                url.replace("{userName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getSecurityPolicyId())
            {
                jsonWriter.writePropertyName("securityPolicyId");
                jsonWriter.writeCharArray(*m_Request.getSecurityPolicyId());
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
        AttachSecurityPolicyTask(
            AttachSecurityPolicyRequest request,
            Gs2RestSessionTask<AttachSecurityPolicyResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<AttachSecurityPolicyResult>(callback),
            m_Request(std::move(request))
        {}

        ~AttachSecurityPolicyTask() GS2_OVERRIDE = default;
    };

    class DetachSecurityPolicyTask : public detail::Gs2RestSessionTask<DetachSecurityPolicyResult>
    {
    private:
        DetachSecurityPolicyRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/user/{userName}/securityPolicy/{securityPolicyId}";
            {
                auto& value = m_Request.getUserName();
                url.replace("{userName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getSecurityPolicyId();
                url.replace("{securityPolicyId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

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
        DetachSecurityPolicyTask(
            DetachSecurityPolicyRequest request,
            Gs2RestSessionTask<DetachSecurityPolicyResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DetachSecurityPolicyResult>(callback),
            m_Request(std::move(request))
        {}

        ~DetachSecurityPolicyTask() GS2_OVERRIDE = default;
    };

    class LoginTask : public detail::Gs2RestSessionTask<LoginResult>
    {
    private:
        LoginRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "identifier";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/projectToken/login";
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
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
        LoginTask(
            LoginRequest request,
            Gs2RestSessionTask<LoginResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<LoginResult>(callback),
            m_Request(std::move(request))
        {}

        ~LoginTask() GS2_OVERRIDE = default;
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
     * @param gs2RestSession REST API 用セッション
     */
    explicit Gs2IdentifierRestClient(Gs2RestSession& gs2RestSession) :
        AbstractGs2ClientBase(gs2RestSession)
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
    }

protected:
    Gs2RestSession& getGs2RestSession()
    {
        return static_cast<Gs2RestSession&>(getGs2Session());
    }
};

} }

#endif //GS2_IDENTIFIER_GS2IDENTIFIERRESTCLIENT_HPP_