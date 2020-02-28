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

#ifndef GS2_DEPLOY_GS2DEPLOYRESTCLIENT_HPP_
#define GS2_DEPLOY_GS2DEPLOYRESTCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2RestSessionTask.hpp>
#include <gs2/core/network/Gs2RestSession.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include "model/model.hpp"
#include "request/DescribeStacksRequest.hpp"
#include "request/CreateStackRequest.hpp"
#include "request/CreateStackFromGitHubRequest.hpp"
#include "request/ValidateRequest.hpp"
#include "request/GetStackStatusRequest.hpp"
#include "request/GetStackRequest.hpp"
#include "request/UpdateStackRequest.hpp"
#include "request/UpdateStackFromGitHubRequest.hpp"
#include "request/DeleteStackRequest.hpp"
#include "request/ForceDeleteStackRequest.hpp"
#include "request/DeleteStackResourcesRequest.hpp"
#include "request/DeleteStackEntityRequest.hpp"
#include "request/DescribeResourcesRequest.hpp"
#include "request/GetResourceRequest.hpp"
#include "request/DescribeEventsRequest.hpp"
#include "request/GetEventRequest.hpp"
#include "request/DescribeOutputsRequest.hpp"
#include "request/GetOutputRequest.hpp"
#include "result/DescribeStacksResult.hpp"
#include "result/CreateStackResult.hpp"
#include "result/CreateStackFromGitHubResult.hpp"
#include "result/ValidateResult.hpp"
#include "result/GetStackStatusResult.hpp"
#include "result/GetStackResult.hpp"
#include "result/UpdateStackResult.hpp"
#include "result/UpdateStackFromGitHubResult.hpp"
#include "result/DeleteStackResult.hpp"
#include "result/ForceDeleteStackResult.hpp"
#include "result/DeleteStackResourcesResult.hpp"
#include "result/DeleteStackEntityResult.hpp"
#include "result/DescribeResourcesResult.hpp"
#include "result/GetResourceResult.hpp"
#include "result/DescribeEventsResult.hpp"
#include "result/GetEventResult.hpp"
#include "result/DescribeOutputsResult.hpp"
#include "result/GetOutputResult.hpp"
#include <cstring>

namespace gs2 { namespace deploy {

/**
 * GS2 Deploy API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2DeployRestClient : public AbstractGs2ClientBase
{
private:

    class DescribeStacksTask : public detail::Gs2RestSessionTask<DescribeStacksResult>
    {
    private:
        DescribeStacksRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "deploy";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stack";

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
        DescribeStacksTask(
            DescribeStacksRequest request,
            Gs2RestSessionTask<DescribeStacksResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeStacksResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeStacksTask() GS2_OVERRIDE = default;
    };

    class CreateStackTask : public detail::Gs2RestSessionTask<CreateStackResult>
    {
    private:
        CreateStackRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "deploy";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stack";
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
            if (m_Request.getTemplate())
            {
                jsonWriter.writePropertyName("template");
                jsonWriter.writeCharArray(*m_Request.getTemplate());
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
        CreateStackTask(
            CreateStackRequest request,
            Gs2RestSessionTask<CreateStackResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CreateStackResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateStackTask() GS2_OVERRIDE = default;
    };

    class CreateStackFromGitHubTask : public detail::Gs2RestSessionTask<CreateStackFromGitHubResult>
    {
    private:
        CreateStackFromGitHubRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "deploy";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stack/from_git_hub";
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
            if (m_Request.getCheckoutSetting())
            {
                jsonWriter.writePropertyName("checkoutSetting");
                write(jsonWriter, *m_Request.getCheckoutSetting());
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
        CreateStackFromGitHubTask(
            CreateStackFromGitHubRequest request,
            Gs2RestSessionTask<CreateStackFromGitHubResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CreateStackFromGitHubResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateStackFromGitHubTask() GS2_OVERRIDE = default;
    };

    class ValidateTask : public detail::Gs2RestSessionTask<void>
    {
    private:
        ValidateRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "deploy";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stack/validate";
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getTemplate())
            {
                jsonWriter.writePropertyName("template");
                jsonWriter.writeCharArray(*m_Request.getTemplate());
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
        ValidateTask(
            ValidateRequest request,
            Gs2RestSessionTask<void>::CallbackType callback
        ) :
            Gs2RestSessionTask<void>(callback),
            m_Request(std::move(request))
        {}

        ~ValidateTask() GS2_OVERRIDE = default;
    };

    class GetStackStatusTask : public detail::Gs2RestSessionTask<GetStackStatusResult>
    {
    private:
        GetStackStatusRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "deploy";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stack/{stackName}/status";
            {
                auto& value = m_Request.getStackName();
                url.replace("{stackName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetStackStatusTask(
            GetStackStatusRequest request,
            Gs2RestSessionTask<GetStackStatusResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetStackStatusResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetStackStatusTask() GS2_OVERRIDE = default;
    };

    class GetStackTask : public detail::Gs2RestSessionTask<GetStackResult>
    {
    private:
        GetStackRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "deploy";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stack/{stackName}";
            {
                auto& value = m_Request.getStackName();
                url.replace("{stackName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetStackTask(
            GetStackRequest request,
            Gs2RestSessionTask<GetStackResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetStackResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetStackTask() GS2_OVERRIDE = default;
    };

    class UpdateStackTask : public detail::Gs2RestSessionTask<UpdateStackResult>
    {
    private:
        UpdateStackRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "deploy";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stack/{stackName}";
            {
                auto& value = m_Request.getStackName();
                url.replace("{stackName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            if (m_Request.getTemplate())
            {
                jsonWriter.writePropertyName("template");
                jsonWriter.writeCharArray(*m_Request.getTemplate());
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
        UpdateStackTask(
            UpdateStackRequest request,
            Gs2RestSessionTask<UpdateStackResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateStackResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateStackTask() GS2_OVERRIDE = default;
    };

    class UpdateStackFromGitHubTask : public detail::Gs2RestSessionTask<UpdateStackFromGitHubResult>
    {
    private:
        UpdateStackFromGitHubRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "deploy";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stack/{stackName}/from_git_hub";
            {
                auto& value = m_Request.getStackName();
                url.replace("{stackName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            if (m_Request.getCheckoutSetting())
            {
                jsonWriter.writePropertyName("checkoutSetting");
                write(jsonWriter, *m_Request.getCheckoutSetting());
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
        UpdateStackFromGitHubTask(
            UpdateStackFromGitHubRequest request,
            Gs2RestSessionTask<UpdateStackFromGitHubResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateStackFromGitHubResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateStackFromGitHubTask() GS2_OVERRIDE = default;
    };

    class DeleteStackTask : public detail::Gs2RestSessionTask<DeleteStackResult>
    {
    private:
        DeleteStackRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "deploy";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stack/{stackName}";
            {
                auto& value = m_Request.getStackName();
                url.replace("{stackName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DeleteStackTask(
            DeleteStackRequest request,
            Gs2RestSessionTask<DeleteStackResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteStackResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteStackTask() GS2_OVERRIDE = default;
    };

    class ForceDeleteStackTask : public detail::Gs2RestSessionTask<ForceDeleteStackResult>
    {
    private:
        ForceDeleteStackRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "deploy";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stack/{stackName}/force";
            {
                auto& value = m_Request.getStackName();
                url.replace("{stackName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        ForceDeleteStackTask(
            ForceDeleteStackRequest request,
            Gs2RestSessionTask<ForceDeleteStackResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<ForceDeleteStackResult>(callback),
            m_Request(std::move(request))
        {}

        ~ForceDeleteStackTask() GS2_OVERRIDE = default;
    };

    class DeleteStackResourcesTask : public detail::Gs2RestSessionTask<DeleteStackResourcesResult>
    {
    private:
        DeleteStackResourcesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "deploy";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stack/{stackName}/resources";
            {
                auto& value = m_Request.getStackName();
                url.replace("{stackName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DeleteStackResourcesTask(
            DeleteStackResourcesRequest request,
            Gs2RestSessionTask<DeleteStackResourcesResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteStackResourcesResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteStackResourcesTask() GS2_OVERRIDE = default;
    };

    class DeleteStackEntityTask : public detail::Gs2RestSessionTask<DeleteStackEntityResult>
    {
    private:
        DeleteStackEntityRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "deploy";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stack/{stackName}/entity";
            {
                auto& value = m_Request.getStackName();
                url.replace("{stackName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DeleteStackEntityTask(
            DeleteStackEntityRequest request,
            Gs2RestSessionTask<DeleteStackEntityResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteStackEntityResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteStackEntityTask() GS2_OVERRIDE = default;
    };

    class DescribeResourcesTask : public detail::Gs2RestSessionTask<DescribeResourcesResult>
    {
    private:
        DescribeResourcesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "deploy";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stack/{stackName}/resource";
            {
                auto& value = m_Request.getStackName();
                url.replace("{stackName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DescribeResourcesTask(
            DescribeResourcesRequest request,
            Gs2RestSessionTask<DescribeResourcesResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeResourcesResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeResourcesTask() GS2_OVERRIDE = default;
    };

    class GetResourceTask : public detail::Gs2RestSessionTask<GetResourceResult>
    {
    private:
        GetResourceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "deploy";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stack/{stackName}/resource/{resourceName}";
            {
                auto& value = m_Request.getStackName();
                url.replace("{stackName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getResourceName();
                url.replace("{resourceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetResourceTask(
            GetResourceRequest request,
            Gs2RestSessionTask<GetResourceResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetResourceResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetResourceTask() GS2_OVERRIDE = default;
    };

    class DescribeEventsTask : public detail::Gs2RestSessionTask<DescribeEventsResult>
    {
    private:
        DescribeEventsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "deploy";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stack/{stackName}/event";
            {
                auto& value = m_Request.getStackName();
                url.replace("{stackName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DescribeEventsTask(
            DescribeEventsRequest request,
            Gs2RestSessionTask<DescribeEventsResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeEventsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeEventsTask() GS2_OVERRIDE = default;
    };

    class GetEventTask : public detail::Gs2RestSessionTask<GetEventResult>
    {
    private:
        GetEventRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "deploy";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stack/{stackName}/event/{eventName}";
            {
                auto& value = m_Request.getStackName();
                url.replace("{stackName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getEventName();
                url.replace("{eventName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetEventTask(
            GetEventRequest request,
            Gs2RestSessionTask<GetEventResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetEventResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetEventTask() GS2_OVERRIDE = default;
    };

    class DescribeOutputsTask : public detail::Gs2RestSessionTask<DescribeOutputsResult>
    {
    private:
        DescribeOutputsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "deploy";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stack/{stackName}/output";
            {
                auto& value = m_Request.getStackName();
                url.replace("{stackName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DescribeOutputsTask(
            DescribeOutputsRequest request,
            Gs2RestSessionTask<DescribeOutputsResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeOutputsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeOutputsTask() GS2_OVERRIDE = default;
    };

    class GetOutputTask : public detail::Gs2RestSessionTask<GetOutputResult>
    {
    private:
        GetOutputRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "deploy";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stack/{stackName}/output/{outputName}";
            {
                auto& value = m_Request.getStackName();
                url.replace("{stackName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getOutputName();
                url.replace("{outputName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetOutputTask(
            GetOutputRequest request,
            Gs2RestSessionTask<GetOutputResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetOutputResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetOutputTask() GS2_OVERRIDE = default;
    };

protected:
    static void write(detail::json::JsonWriter& jsonWriter, const Stack& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getStackId())
        {
            jsonWriter.writePropertyName("stackId");
            jsonWriter.writeCharArray(*obj.getStackId());
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
        if (obj.getTemplate())
        {
            jsonWriter.writePropertyName("template");
            jsonWriter.writeCharArray(*obj.getTemplate());
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

    static void write(detail::json::JsonWriter& jsonWriter, const Resource& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getResourceId())
        {
            jsonWriter.writePropertyName("resourceId");
            jsonWriter.writeCharArray(*obj.getResourceId());
        }
        if (obj.getType())
        {
            jsonWriter.writePropertyName("type");
            jsonWriter.writeCharArray(*obj.getType());
        }
        if (obj.getName())
        {
            jsonWriter.writePropertyName("name");
            jsonWriter.writeCharArray(*obj.getName());
        }
        if (obj.getRequest())
        {
            jsonWriter.writePropertyName("request");
            jsonWriter.writeCharArray(*obj.getRequest());
        }
        if (obj.getResponse())
        {
            jsonWriter.writePropertyName("response");
            jsonWriter.writeCharArray(*obj.getResponse());
        }
        if (obj.getRollbackContext())
        {
            jsonWriter.writePropertyName("rollbackContext");
            jsonWriter.writeCharArray(*obj.getRollbackContext());
        }
        if (obj.getRollbackRequest())
        {
            jsonWriter.writePropertyName("rollbackRequest");
            jsonWriter.writeCharArray(*obj.getRollbackRequest());
        }
        if (obj.getRollbackAfter())
        {
            jsonWriter.writePropertyName("rollbackAfter");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getRollbackAfter();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                jsonWriter.writeCharArray(list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (obj.getOutputFields())
        {
            jsonWriter.writePropertyName("outputFields");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getOutputFields();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (obj.getWorkId())
        {
            jsonWriter.writePropertyName("workId");
            jsonWriter.writeCharArray(*obj.getWorkId());
        }
        if (obj.getCreatedAt())
        {
            jsonWriter.writePropertyName("createdAt");
            jsonWriter.writeInt64(*obj.getCreatedAt());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const WorkingStack& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getStackId())
        {
            jsonWriter.writePropertyName("stackId");
            jsonWriter.writeCharArray(*obj.getStackId());
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
        if (obj.getWorkId())
        {
            jsonWriter.writePropertyName("workId");
            jsonWriter.writeCharArray(*obj.getWorkId());
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

    static void write(detail::json::JsonWriter& jsonWriter, const WorkingResource& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getResourceId())
        {
            jsonWriter.writePropertyName("resourceId");
            jsonWriter.writeCharArray(*obj.getResourceId());
        }
        if (obj.getContext())
        {
            jsonWriter.writePropertyName("context");
            jsonWriter.writeCharArray(*obj.getContext());
        }
        if (obj.getType())
        {
            jsonWriter.writePropertyName("type");
            jsonWriter.writeCharArray(*obj.getType());
        }
        if (obj.getName())
        {
            jsonWriter.writePropertyName("name");
            jsonWriter.writeCharArray(*obj.getName());
        }
        if (obj.getRequest())
        {
            jsonWriter.writePropertyName("request");
            jsonWriter.writeCharArray(*obj.getRequest());
        }
        if (obj.getAfter())
        {
            jsonWriter.writePropertyName("after");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getAfter();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                jsonWriter.writeCharArray(list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (obj.getRollbackContext())
        {
            jsonWriter.writePropertyName("rollbackContext");
            jsonWriter.writeCharArray(*obj.getRollbackContext());
        }
        if (obj.getRollbackRequest())
        {
            jsonWriter.writePropertyName("rollbackRequest");
            jsonWriter.writeCharArray(*obj.getRollbackRequest());
        }
        if (obj.getRollbackAfter())
        {
            jsonWriter.writePropertyName("rollbackAfter");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getRollbackAfter();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                jsonWriter.writeCharArray(list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (obj.getOutputFields())
        {
            jsonWriter.writePropertyName("outputFields");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getOutputFields();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (obj.getWorkId())
        {
            jsonWriter.writePropertyName("workId");
            jsonWriter.writeCharArray(*obj.getWorkId());
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

    static void write(detail::json::JsonWriter& jsonWriter, const Event& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getEventId())
        {
            jsonWriter.writePropertyName("eventId");
            jsonWriter.writeCharArray(*obj.getEventId());
        }
        if (obj.getName())
        {
            jsonWriter.writePropertyName("name");
            jsonWriter.writeCharArray(*obj.getName());
        }
        if (obj.getResourceName())
        {
            jsonWriter.writePropertyName("resourceName");
            jsonWriter.writeCharArray(*obj.getResourceName());
        }
        if (obj.getType())
        {
            jsonWriter.writePropertyName("type");
            jsonWriter.writeCharArray(*obj.getType());
        }
        if (obj.getMessage())
        {
            jsonWriter.writePropertyName("message");
            jsonWriter.writeCharArray(*obj.getMessage());
        }
        if (obj.getEventAt())
        {
            jsonWriter.writePropertyName("eventAt");
            jsonWriter.writeInt64(*obj.getEventAt());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const Output& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getOutputId())
        {
            jsonWriter.writePropertyName("outputId");
            jsonWriter.writeCharArray(*obj.getOutputId());
        }
        if (obj.getName())
        {
            jsonWriter.writePropertyName("name");
            jsonWriter.writeCharArray(*obj.getName());
        }
        if (obj.getValue())
        {
            jsonWriter.writePropertyName("value");
            jsonWriter.writeCharArray(*obj.getValue());
        }
        if (obj.getCreatedAt())
        {
            jsonWriter.writePropertyName("createdAt");
            jsonWriter.writeInt64(*obj.getCreatedAt());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const GitHubCheckoutSetting& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getGitHubApiKeyId())
        {
            jsonWriter.writePropertyName("gitHubApiKeyId");
            jsonWriter.writeCharArray(*obj.getGitHubApiKeyId());
        }
        if (obj.getRepositoryName())
        {
            jsonWriter.writePropertyName("repositoryName");
            jsonWriter.writeCharArray(*obj.getRepositoryName());
        }
        if (obj.getSourcePath())
        {
            jsonWriter.writePropertyName("sourcePath");
            jsonWriter.writeCharArray(*obj.getSourcePath());
        }
        if (obj.getReferenceType())
        {
            jsonWriter.writePropertyName("referenceType");
            jsonWriter.writeCharArray(*obj.getReferenceType());
        }
        if (obj.getCommitHash())
        {
            jsonWriter.writePropertyName("commitHash");
            jsonWriter.writeCharArray(*obj.getCommitHash());
        }
        if (obj.getBranchName())
        {
            jsonWriter.writePropertyName("branchName");
            jsonWriter.writeCharArray(*obj.getBranchName());
        }
        if (obj.getTagName())
        {
            jsonWriter.writePropertyName("tagName");
            jsonWriter.writeCharArray(*obj.getTagName());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const OutputField& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getName())
        {
            jsonWriter.writePropertyName("name");
            jsonWriter.writeCharArray(*obj.getName());
        }
        if (obj.getFieldName())
        {
            jsonWriter.writePropertyName("fieldName");
            jsonWriter.writeCharArray(*obj.getFieldName());
        }
        jsonWriter.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
     */
    explicit Gs2DeployRestClient(Gs2RestSession& gs2RestSession) :
        AbstractGs2ClientBase(gs2RestSession)
    {
    }

	/**
	 * スタックの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeStacks(DescribeStacksRequest request, std::function<void(AsyncDescribeStacksResult)> callback)
    {
        DescribeStacksTask& task = *new DescribeStacksTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタックを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createStack(CreateStackRequest request, std::function<void(AsyncCreateStackResult)> callback)
    {
        CreateStackTask& task = *new CreateStackTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタックを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createStackFromGitHub(CreateStackFromGitHubRequest request, std::function<void(AsyncCreateStackFromGitHubResult)> callback)
    {
        CreateStackFromGitHubTask& task = *new CreateStackFromGitHubTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * テンプレートを検証<br>
	 *   <br>
	 *   このAPIの検証内容は簡易検証を行うに過ぎず、<br>
	 *   このAPIで検証をパスしたとしても、実行したらエラーが発生する場合もあります<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void validate(ValidateRequest request, std::function<void(AsyncValidateResult)> callback)
    {
        ValidateTask& task = *new ValidateTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタックを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStackStatus(GetStackStatusRequest request, std::function<void(AsyncGetStackStatusResult)> callback)
    {
        GetStackStatusTask& task = *new GetStackStatusTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタックを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStack(GetStackRequest request, std::function<void(AsyncGetStackResult)> callback)
    {
        GetStackTask& task = *new GetStackTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタックを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateStack(UpdateStackRequest request, std::function<void(AsyncUpdateStackResult)> callback)
    {
        UpdateStackTask& task = *new UpdateStackTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタックを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateStackFromGitHub(UpdateStackFromGitHubRequest request, std::function<void(AsyncUpdateStackFromGitHubResult)> callback)
    {
        UpdateStackFromGitHubTask& task = *new UpdateStackFromGitHubTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタックを削除<br>
	 *   <br>
	 *   スタックによって作成されたリソースの削除を行い、成功すればエンティティを削除します。<br>
	 *   何らかの理由でリソースの削除に失敗した場合はエンティティが残ります。<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteStack(DeleteStackRequest request, std::function<void(AsyncDeleteStackResult)> callback)
    {
        DeleteStackTask& task = *new DeleteStackTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタックを強制的に最終削除<br>
	 *   <br>
	 *   スタックのエンティティを強制的に削除します。<br>
	 *   スタックが作成したリソースが残っていても、それらは削除されません。<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void forceDeleteStack(ForceDeleteStackRequest request, std::function<void(AsyncForceDeleteStackResult)> callback)
    {
        ForceDeleteStackTask& task = *new ForceDeleteStackTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタックのリソースを削除<br>
	 *   <br>
	 *   スタックによって作成されたリソースの削除を行います。<br>
	 *   空のテンプレートでスタックを更新するのとほぼ同様の挙動ですが、スタックに適用されていたテンプレートが残るため、誤操作時に、残ったテンプレートからリソースを復元することができます。<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteStackResources(DeleteStackResourcesRequest request, std::function<void(AsyncDeleteStackResourcesResult)> callback)
    {
        DeleteStackResourcesTask& task = *new DeleteStackResourcesTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタックを最終削除<br>
	 *   <br>
	 *   スタックのエンティティを削除します。<br>
	 *   リソースの残っているスタックを削除しようとするとエラーになります。<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteStackEntity(DeleteStackEntityRequest request, std::function<void(AsyncDeleteStackEntityResult)> callback)
    {
        DeleteStackEntityTask& task = *new DeleteStackEntityTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 作成されたのリソースの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeResources(DescribeResourcesRequest request, std::function<void(AsyncDescribeResourcesResult)> callback)
    {
        DescribeResourcesTask& task = *new DescribeResourcesTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 作成されたのリソースを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getResource(GetResourceRequest request, std::function<void(AsyncGetResourceResult)> callback)
    {
        GetResourceTask& task = *new GetResourceTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 発生したイベントの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeEvents(DescribeEventsRequest request, std::function<void(AsyncDescribeEventsResult)> callback)
    {
        DescribeEventsTask& task = *new DescribeEventsTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 発生したイベントを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getEvent(GetEventRequest request, std::function<void(AsyncGetEventResult)> callback)
    {
        GetEventTask& task = *new GetEventTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * アウトプットの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeOutputs(DescribeOutputsRequest request, std::function<void(AsyncDescribeOutputsResult)> callback)
    {
        DescribeOutputsTask& task = *new DescribeOutputsTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * アウトプットを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getOutput(GetOutputRequest request, std::function<void(AsyncGetOutputResult)> callback)
    {
        GetOutputTask& task = *new GetOutputTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

protected:
    Gs2RestSession& getGs2RestSession()
    {
        return static_cast<Gs2RestSession&>(getGs2Session());
    }
};

} }

#endif //GS2_DEPLOY_GS2DEPLOYRESTCLIENT_HPP_