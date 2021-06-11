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

#ifndef GS2_VERSION_GS2VERSIONRESTCLIENT_HPP_
#define GS2_VERSION_GS2VERSIONRESTCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2RestSessionTask.hpp>
#include <gs2/core/network/Gs2RestSession.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include "model/model.hpp"
#include "request/DescribeNamespacesRequest.hpp"
#include "request/CreateNamespaceRequest.hpp"
#include "request/GetNamespaceStatusRequest.hpp"
#include "request/GetNamespaceRequest.hpp"
#include "request/UpdateNamespaceRequest.hpp"
#include "request/DeleteNamespaceRequest.hpp"
#include "request/DescribeVersionModelMastersRequest.hpp"
#include "request/CreateVersionModelMasterRequest.hpp"
#include "request/GetVersionModelMasterRequest.hpp"
#include "request/UpdateVersionModelMasterRequest.hpp"
#include "request/DeleteVersionModelMasterRequest.hpp"
#include "request/DescribeVersionModelsRequest.hpp"
#include "request/GetVersionModelRequest.hpp"
#include "request/DescribeAcceptVersionsRequest.hpp"
#include "request/DescribeAcceptVersionsByUserIdRequest.hpp"
#include "request/AcceptRequest.hpp"
#include "request/AcceptByUserIdRequest.hpp"
#include "request/GetAcceptVersionRequest.hpp"
#include "request/GetAcceptVersionByUserIdRequest.hpp"
#include "request/DeleteAcceptVersionRequest.hpp"
#include "request/DeleteAcceptVersionByUserIdRequest.hpp"
#include "request/CheckVersionRequest.hpp"
#include "request/CheckVersionByUserIdRequest.hpp"
#include "request/CalculateSignatureRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentVersionMasterRequest.hpp"
#include "request/UpdateCurrentVersionMasterRequest.hpp"
#include "request/UpdateCurrentVersionMasterFromGitHubRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeVersionModelMastersResult.hpp"
#include "result/CreateVersionModelMasterResult.hpp"
#include "result/GetVersionModelMasterResult.hpp"
#include "result/UpdateVersionModelMasterResult.hpp"
#include "result/DeleteVersionModelMasterResult.hpp"
#include "result/DescribeVersionModelsResult.hpp"
#include "result/GetVersionModelResult.hpp"
#include "result/DescribeAcceptVersionsResult.hpp"
#include "result/DescribeAcceptVersionsByUserIdResult.hpp"
#include "result/AcceptResult.hpp"
#include "result/AcceptByUserIdResult.hpp"
#include "result/GetAcceptVersionResult.hpp"
#include "result/GetAcceptVersionByUserIdResult.hpp"
#include "result/DeleteAcceptVersionResult.hpp"
#include "result/DeleteAcceptVersionByUserIdResult.hpp"
#include "result/CheckVersionResult.hpp"
#include "result/CheckVersionByUserIdResult.hpp"
#include "result/CalculateSignatureResult.hpp"
#include "result/ExportMasterResult.hpp"
#include "result/GetCurrentVersionMasterResult.hpp"
#include "result/UpdateCurrentVersionMasterResult.hpp"
#include "result/UpdateCurrentVersionMasterFromGitHubResult.hpp"
#include <cstring>

namespace gs2 { namespace version {

/**
 * GS2 Version API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2VersionRestClient : public AbstractGs2ClientBase
{
private:

    class DescribeNamespacesTask : public detail::Gs2RestSessionTask<DescribeNamespacesResult>
    {
    private:
        DescribeNamespacesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/";

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
        DescribeNamespacesTask(
            DescribeNamespacesRequest request,
            Gs2RestSessionTask<DescribeNamespacesResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeNamespacesResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeNamespacesTask() GS2_OVERRIDE = default;
    };

    class CreateNamespaceTask : public detail::Gs2RestSessionTask<CreateNamespaceResult>
    {
    private:
        CreateNamespaceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/";
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
            if (m_Request.getAssumeUserId())
            {
                jsonWriter.writePropertyName("assumeUserId");
                jsonWriter.writeCharArray(*m_Request.getAssumeUserId());
            }
            if (m_Request.getLogSetting())
            {
                jsonWriter.writePropertyName("logSetting");
                write(jsonWriter, *m_Request.getLogSetting());
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
        CreateNamespaceTask(
            CreateNamespaceRequest request,
            Gs2RestSessionTask<CreateNamespaceResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CreateNamespaceResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateNamespaceTask() GS2_OVERRIDE = default;
    };

    class GetNamespaceStatusTask : public detail::Gs2RestSessionTask<GetNamespaceStatusResult>
    {
    private:
        GetNamespaceStatusRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/status";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetNamespaceStatusTask(
            GetNamespaceStatusRequest request,
            Gs2RestSessionTask<GetNamespaceStatusResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetNamespaceStatusResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetNamespaceStatusTask() GS2_OVERRIDE = default;
    };

    class GetNamespaceTask : public detail::Gs2RestSessionTask<GetNamespaceResult>
    {
    private:
        GetNamespaceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetNamespaceTask(
            GetNamespaceRequest request,
            Gs2RestSessionTask<GetNamespaceResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetNamespaceResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetNamespaceTask() GS2_OVERRIDE = default;
    };

    class UpdateNamespaceTask : public detail::Gs2RestSessionTask<UpdateNamespaceResult>
    {
    private:
        UpdateNamespaceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            if (m_Request.getAssumeUserId())
            {
                jsonWriter.writePropertyName("assumeUserId");
                jsonWriter.writeCharArray(*m_Request.getAssumeUserId());
            }
            if (m_Request.getLogSetting())
            {
                jsonWriter.writePropertyName("logSetting");
                write(jsonWriter, *m_Request.getLogSetting());
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
        UpdateNamespaceTask(
            UpdateNamespaceRequest request,
            Gs2RestSessionTask<UpdateNamespaceResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateNamespaceResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateNamespaceTask() GS2_OVERRIDE = default;
    };

    class DeleteNamespaceTask : public detail::Gs2RestSessionTask<DeleteNamespaceResult>
    {
    private:
        DeleteNamespaceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
                gs2HttpTask.setBody("{}");
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Delete;
        }

    public:
        DeleteNamespaceTask(
            DeleteNamespaceRequest request,
            Gs2RestSessionTask<DeleteNamespaceResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteNamespaceResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteNamespaceTask() GS2_OVERRIDE = default;
    };

    class DescribeVersionModelMastersTask : public detail::Gs2RestSessionTask<DescribeVersionModelMastersResult>
    {
    private:
        DescribeVersionModelMastersRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/version";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DescribeVersionModelMastersTask(
            DescribeVersionModelMastersRequest request,
            Gs2RestSessionTask<DescribeVersionModelMastersResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeVersionModelMastersResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeVersionModelMastersTask() GS2_OVERRIDE = default;
    };

    class CreateVersionModelMasterTask : public detail::Gs2RestSessionTask<CreateVersionModelMasterResult>
    {
    private:
        CreateVersionModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/version";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
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
            if (m_Request.getMetadata())
            {
                jsonWriter.writePropertyName("metadata");
                jsonWriter.writeCharArray(*m_Request.getMetadata());
            }
            if (m_Request.getWarningVersion())
            {
                jsonWriter.writePropertyName("warningVersion");
                write(jsonWriter, *m_Request.getWarningVersion());
            }
            if (m_Request.getErrorVersion())
            {
                jsonWriter.writePropertyName("errorVersion");
                write(jsonWriter, *m_Request.getErrorVersion());
            }
            if (m_Request.getScope())
            {
                jsonWriter.writePropertyName("scope");
                jsonWriter.writeCharArray(*m_Request.getScope());
            }
            if (m_Request.getCurrentVersion())
            {
                jsonWriter.writePropertyName("currentVersion");
                write(jsonWriter, *m_Request.getCurrentVersion());
            }
            if (m_Request.getNeedSignature())
            {
                jsonWriter.writePropertyName("needSignature");
                jsonWriter.writeBool(*m_Request.getNeedSignature());
            }
            if (m_Request.getSignatureKeyId())
            {
                jsonWriter.writePropertyName("signatureKeyId");
                jsonWriter.writeCharArray(*m_Request.getSignatureKeyId());
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
        CreateVersionModelMasterTask(
            CreateVersionModelMasterRequest request,
            Gs2RestSessionTask<CreateVersionModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CreateVersionModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateVersionModelMasterTask() GS2_OVERRIDE = default;
    };

    class GetVersionModelMasterTask : public detail::Gs2RestSessionTask<GetVersionModelMasterResult>
    {
    private:
        GetVersionModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/version/{versionName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getVersionName();
                url.replace("{versionName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetVersionModelMasterTask(
            GetVersionModelMasterRequest request,
            Gs2RestSessionTask<GetVersionModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetVersionModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetVersionModelMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateVersionModelMasterTask : public detail::Gs2RestSessionTask<UpdateVersionModelMasterResult>
    {
    private:
        UpdateVersionModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/version/{versionName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getVersionName();
                url.replace("{versionName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            if (m_Request.getMetadata())
            {
                jsonWriter.writePropertyName("metadata");
                jsonWriter.writeCharArray(*m_Request.getMetadata());
            }
            if (m_Request.getWarningVersion())
            {
                jsonWriter.writePropertyName("warningVersion");
                write(jsonWriter, *m_Request.getWarningVersion());
            }
            if (m_Request.getErrorVersion())
            {
                jsonWriter.writePropertyName("errorVersion");
                write(jsonWriter, *m_Request.getErrorVersion());
            }
            if (m_Request.getScope())
            {
                jsonWriter.writePropertyName("scope");
                jsonWriter.writeCharArray(*m_Request.getScope());
            }
            if (m_Request.getCurrentVersion())
            {
                jsonWriter.writePropertyName("currentVersion");
                write(jsonWriter, *m_Request.getCurrentVersion());
            }
            if (m_Request.getNeedSignature())
            {
                jsonWriter.writePropertyName("needSignature");
                jsonWriter.writeBool(*m_Request.getNeedSignature());
            }
            if (m_Request.getSignatureKeyId())
            {
                jsonWriter.writePropertyName("signatureKeyId");
                jsonWriter.writeCharArray(*m_Request.getSignatureKeyId());
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
        UpdateVersionModelMasterTask(
            UpdateVersionModelMasterRequest request,
            Gs2RestSessionTask<UpdateVersionModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateVersionModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateVersionModelMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteVersionModelMasterTask : public detail::Gs2RestSessionTask<DeleteVersionModelMasterResult>
    {
    private:
        DeleteVersionModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/version/{versionName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getVersionName();
                url.replace("{versionName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
                gs2HttpTask.setBody("{}");
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Delete;
        }

    public:
        DeleteVersionModelMasterTask(
            DeleteVersionModelMasterRequest request,
            Gs2RestSessionTask<DeleteVersionModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteVersionModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteVersionModelMasterTask() GS2_OVERRIDE = default;
    };

    class DescribeVersionModelsTask : public detail::Gs2RestSessionTask<DescribeVersionModelsResult>
    {
    private:
        DescribeVersionModelsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/version";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DescribeVersionModelsTask(
            DescribeVersionModelsRequest request,
            Gs2RestSessionTask<DescribeVersionModelsResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeVersionModelsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeVersionModelsTask() GS2_OVERRIDE = default;
    };

    class GetVersionModelTask : public detail::Gs2RestSessionTask<GetVersionModelResult>
    {
    private:
        GetVersionModelRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/version/{versionName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getVersionName();
                url.replace("{versionName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetVersionModelTask(
            GetVersionModelRequest request,
            Gs2RestSessionTask<GetVersionModelResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetVersionModelResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetVersionModelTask() GS2_OVERRIDE = default;
    };

    class DescribeAcceptVersionsTask : public detail::Gs2RestSessionTask<DescribeAcceptVersionsResult>
    {
    private:
        DescribeAcceptVersionsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/acceptVersion";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            if (m_Request.getAccessToken())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-ACCESS-TOKEN", *m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        DescribeAcceptVersionsTask(
            DescribeAcceptVersionsRequest request,
            Gs2RestSessionTask<DescribeAcceptVersionsResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeAcceptVersionsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeAcceptVersionsTask() GS2_OVERRIDE = default;
    };

    class DescribeAcceptVersionsByUserIdTask : public detail::Gs2RestSessionTask<DescribeAcceptVersionsByUserIdResult>
    {
    private:
        DescribeAcceptVersionsByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/acceptVersion";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getUserId())
            {
                url += joint;
                url += "userId=";
                url += detail::StringVariable(*m_Request.getUserId(), detail::StringVariable::UrlSafeEncode()).c_str();
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
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        DescribeAcceptVersionsByUserIdTask(
            DescribeAcceptVersionsByUserIdRequest request,
            Gs2RestSessionTask<DescribeAcceptVersionsByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeAcceptVersionsByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeAcceptVersionsByUserIdTask() GS2_OVERRIDE = default;
    };

    class AcceptTask : public detail::Gs2RestSessionTask<AcceptResult>
    {
    private:
        AcceptRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/acceptVersion";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getVersionName())
            {
                jsonWriter.writePropertyName("versionName");
                jsonWriter.writeCharArray(*m_Request.getVersionName());
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
            if (m_Request.getAccessToken())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-ACCESS-TOKEN", *m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Post;
        }

    public:
        AcceptTask(
            AcceptRequest request,
            Gs2RestSessionTask<AcceptResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<AcceptResult>(callback),
            m_Request(std::move(request))
        {}

        ~AcceptTask() GS2_OVERRIDE = default;
    };

    class AcceptByUserIdTask : public detail::Gs2RestSessionTask<AcceptByUserIdResult>
    {
    private:
        AcceptByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/acceptVersion";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getVersionName())
            {
                jsonWriter.writePropertyName("versionName");
                jsonWriter.writeCharArray(*m_Request.getVersionName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
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
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Post;
        }

    public:
        AcceptByUserIdTask(
            AcceptByUserIdRequest request,
            Gs2RestSessionTask<AcceptByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<AcceptByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~AcceptByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetAcceptVersionTask : public detail::Gs2RestSessionTask<GetAcceptVersionResult>
    {
    private:
        GetAcceptVersionRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/{versionName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getVersionName();
                url.replace("{versionName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            if (m_Request.getAccessToken())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-ACCESS-TOKEN", *m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        GetAcceptVersionTask(
            GetAcceptVersionRequest request,
            Gs2RestSessionTask<GetAcceptVersionResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetAcceptVersionResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetAcceptVersionTask() GS2_OVERRIDE = default;
    };

    class GetAcceptVersionByUserIdTask : public detail::Gs2RestSessionTask<GetAcceptVersionByUserIdResult>
    {
    private:
        GetAcceptVersionByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/{versionName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getVersionName();
                url.replace("{versionName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        GetAcceptVersionByUserIdTask(
            GetAcceptVersionByUserIdRequest request,
            Gs2RestSessionTask<GetAcceptVersionByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetAcceptVersionByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetAcceptVersionByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteAcceptVersionTask : public detail::Gs2RestSessionTask<void>
    {
    private:
        DeleteAcceptVersionRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/{versionName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getVersionName();
                url.replace("{versionName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
                gs2HttpTask.setBody("{}");
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-ACCESS-TOKEN", *m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Delete;
        }

    public:
        DeleteAcceptVersionTask(
            DeleteAcceptVersionRequest request,
            Gs2RestSessionTask<void>::CallbackType callback
        ) :
            Gs2RestSessionTask<void>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteAcceptVersionTask() GS2_OVERRIDE = default;
    };

    class DeleteAcceptVersionByUserIdTask : public detail::Gs2RestSessionTask<void>
    {
    private:
        DeleteAcceptVersionByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/{versionName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getVersionName();
                url.replace("{versionName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
                gs2HttpTask.setBody("{}");
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Delete;
        }

    public:
        DeleteAcceptVersionByUserIdTask(
            DeleteAcceptVersionByUserIdRequest request,
            Gs2RestSessionTask<void>::CallbackType callback
        ) :
            Gs2RestSessionTask<void>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteAcceptVersionByUserIdTask() GS2_OVERRIDE = default;
    };

    class CheckVersionTask : public detail::Gs2RestSessionTask<CheckVersionResult>
    {
    private:
        CheckVersionRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/check";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getTargetVersions())
            {
                jsonWriter.writePropertyName("targetVersions");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getTargetVersions();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(jsonWriter, list[i]);
                }
                jsonWriter.writeArrayEnd();
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
            if (m_Request.getAccessToken())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-ACCESS-TOKEN", *m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Post;
        }

    public:
        CheckVersionTask(
            CheckVersionRequest request,
            Gs2RestSessionTask<CheckVersionResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CheckVersionResult>(callback),
            m_Request(std::move(request))
        {}

        ~CheckVersionTask() GS2_OVERRIDE = default;
    };

    class CheckVersionByUserIdTask : public detail::Gs2RestSessionTask<CheckVersionByUserIdResult>
    {
    private:
        CheckVersionByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/check";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getTargetVersions())
            {
                jsonWriter.writePropertyName("targetVersions");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getTargetVersions();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(jsonWriter, list[i]);
                }
                jsonWriter.writeArrayEnd();
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
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Post;
        }

    public:
        CheckVersionByUserIdTask(
            CheckVersionByUserIdRequest request,
            Gs2RestSessionTask<CheckVersionByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CheckVersionByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~CheckVersionByUserIdTask() GS2_OVERRIDE = default;
    };

    class CalculateSignatureTask : public detail::Gs2RestSessionTask<CalculateSignatureResult>
    {
    private:
        CalculateSignatureRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/calculate/signature";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getVersionName();
                url.replace("{versionName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getVersion())
            {
                jsonWriter.writePropertyName("version");
                write(jsonWriter, *m_Request.getVersion());
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
        CalculateSignatureTask(
            CalculateSignatureRequest request,
            Gs2RestSessionTask<CalculateSignatureResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CalculateSignatureResult>(callback),
            m_Request(std::move(request))
        {}

        ~CalculateSignatureTask() GS2_OVERRIDE = default;
    };

    class ExportMasterTask : public detail::Gs2RestSessionTask<ExportMasterResult>
    {
    private:
        ExportMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/export";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        ExportMasterTask(
            ExportMasterRequest request,
            Gs2RestSessionTask<ExportMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<ExportMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~ExportMasterTask() GS2_OVERRIDE = default;
    };

    class GetCurrentVersionMasterTask : public detail::Gs2RestSessionTask<GetCurrentVersionMasterResult>
    {
    private:
        GetCurrentVersionMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetCurrentVersionMasterTask(
            GetCurrentVersionMasterRequest request,
            Gs2RestSessionTask<GetCurrentVersionMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetCurrentVersionMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetCurrentVersionMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentVersionMasterTask : public detail::Gs2RestSessionTask<UpdateCurrentVersionMasterResult>
    {
    private:
        UpdateCurrentVersionMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getSettings())
            {
                jsonWriter.writePropertyName("settings");
                jsonWriter.writeCharArray(*m_Request.getSettings());
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
        UpdateCurrentVersionMasterTask(
            UpdateCurrentVersionMasterRequest request,
            Gs2RestSessionTask<UpdateCurrentVersionMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateCurrentVersionMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateCurrentVersionMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentVersionMasterFromGitHubTask : public detail::Gs2RestSessionTask<UpdateCurrentVersionMasterFromGitHubResult>
    {
    private:
        UpdateCurrentVersionMasterFromGitHubRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/from_git_hub";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
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
        UpdateCurrentVersionMasterFromGitHubTask(
            UpdateCurrentVersionMasterFromGitHubRequest request,
            Gs2RestSessionTask<UpdateCurrentVersionMasterFromGitHubResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateCurrentVersionMasterFromGitHubResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateCurrentVersionMasterFromGitHubTask() GS2_OVERRIDE = default;
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
        if (obj.getAssumeUserId())
        {
            jsonWriter.writePropertyName("assumeUserId");
            jsonWriter.writeCharArray(*obj.getAssumeUserId());
        }
        if (obj.getAcceptVersionScript())
        {
            jsonWriter.writePropertyName("acceptVersionScript");
            write(jsonWriter, *obj.getAcceptVersionScript());
        }
        if (obj.getCheckVersionTriggerScriptId())
        {
            jsonWriter.writePropertyName("checkVersionTriggerScriptId");
            jsonWriter.writeCharArray(*obj.getCheckVersionTriggerScriptId());
        }
        if (obj.getLogSetting())
        {
            jsonWriter.writePropertyName("logSetting");
            write(jsonWriter, *obj.getLogSetting());
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

    static void write(detail::json::JsonWriter& jsonWriter, const VersionModelMaster& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getVersionModelId())
        {
            jsonWriter.writePropertyName("versionModelId");
            jsonWriter.writeCharArray(*obj.getVersionModelId());
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
        if (obj.getMetadata())
        {
            jsonWriter.writePropertyName("metadata");
            jsonWriter.writeCharArray(*obj.getMetadata());
        }
        if (obj.getWarningVersion())
        {
            jsonWriter.writePropertyName("warningVersion");
            write(jsonWriter, *obj.getWarningVersion());
        }
        if (obj.getErrorVersion())
        {
            jsonWriter.writePropertyName("errorVersion");
            write(jsonWriter, *obj.getErrorVersion());
        }
        if (obj.getScope())
        {
            jsonWriter.writePropertyName("scope");
            jsonWriter.writeCharArray(*obj.getScope());
        }
        if (obj.getCurrentVersion())
        {
            jsonWriter.writePropertyName("currentVersion");
            write(jsonWriter, *obj.getCurrentVersion());
        }
        if (obj.getNeedSignature())
        {
            jsonWriter.writePropertyName("needSignature");
            jsonWriter.writeBool(*obj.getNeedSignature());
        }
        if (obj.getSignatureKeyId())
        {
            jsonWriter.writePropertyName("signatureKeyId");
            jsonWriter.writeCharArray(*obj.getSignatureKeyId());
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

    static void write(detail::json::JsonWriter& jsonWriter, const Version& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getMajor())
        {
            jsonWriter.writePropertyName("major");
            jsonWriter.writeInt32(*obj.getMajor());
        }
        if (obj.getMinor())
        {
            jsonWriter.writePropertyName("minor");
            jsonWriter.writeInt32(*obj.getMinor());
        }
        if (obj.getMicro())
        {
            jsonWriter.writePropertyName("micro");
            jsonWriter.writeInt32(*obj.getMicro());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const VersionModel& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getVersionModelId())
        {
            jsonWriter.writePropertyName("versionModelId");
            jsonWriter.writeCharArray(*obj.getVersionModelId());
        }
        if (obj.getName())
        {
            jsonWriter.writePropertyName("name");
            jsonWriter.writeCharArray(*obj.getName());
        }
        if (obj.getMetadata())
        {
            jsonWriter.writePropertyName("metadata");
            jsonWriter.writeCharArray(*obj.getMetadata());
        }
        if (obj.getWarningVersion())
        {
            jsonWriter.writePropertyName("warningVersion");
            write(jsonWriter, *obj.getWarningVersion());
        }
        if (obj.getErrorVersion())
        {
            jsonWriter.writePropertyName("errorVersion");
            write(jsonWriter, *obj.getErrorVersion());
        }
        if (obj.getScope())
        {
            jsonWriter.writePropertyName("scope");
            jsonWriter.writeCharArray(*obj.getScope());
        }
        if (obj.getCurrentVersion())
        {
            jsonWriter.writePropertyName("currentVersion");
            write(jsonWriter, *obj.getCurrentVersion());
        }
        if (obj.getNeedSignature())
        {
            jsonWriter.writePropertyName("needSignature");
            jsonWriter.writeBool(*obj.getNeedSignature());
        }
        if (obj.getSignatureKeyId())
        {
            jsonWriter.writePropertyName("signatureKeyId");
            jsonWriter.writeCharArray(*obj.getSignatureKeyId());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const AcceptVersion& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getAcceptVersionId())
        {
            jsonWriter.writePropertyName("acceptVersionId");
            jsonWriter.writeCharArray(*obj.getAcceptVersionId());
        }
        if (obj.getVersionName())
        {
            jsonWriter.writePropertyName("versionName");
            jsonWriter.writeCharArray(*obj.getVersionName());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getVersion())
        {
            jsonWriter.writePropertyName("version");
            write(jsonWriter, *obj.getVersion());
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

    static void write(detail::json::JsonWriter& jsonWriter, const Status& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getVersionModel())
        {
            jsonWriter.writePropertyName("versionModel");
            write(jsonWriter, *obj.getVersionModel());
        }
        if (obj.getCurrentVersion())
        {
            jsonWriter.writePropertyName("currentVersion");
            write(jsonWriter, *obj.getCurrentVersion());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const TargetVersion& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getVersionName())
        {
            jsonWriter.writePropertyName("versionName");
            jsonWriter.writeCharArray(*obj.getVersionName());
        }
        if (obj.getVersion())
        {
            jsonWriter.writePropertyName("version");
            write(jsonWriter, *obj.getVersion());
        }
        if (obj.getBody())
        {
            jsonWriter.writePropertyName("body");
            jsonWriter.writeCharArray(*obj.getBody());
        }
        if (obj.getSignature())
        {
            jsonWriter.writePropertyName("signature");
            jsonWriter.writeCharArray(*obj.getSignature());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const SignTargetVersion& obj)
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
        if (obj.getNamespaceName())
        {
            jsonWriter.writePropertyName("namespaceName");
            jsonWriter.writeCharArray(*obj.getNamespaceName());
        }
        if (obj.getVersionName())
        {
            jsonWriter.writePropertyName("versionName");
            jsonWriter.writeCharArray(*obj.getVersionName());
        }
        if (obj.getVersion())
        {
            jsonWriter.writePropertyName("version");
            write(jsonWriter, *obj.getVersion());
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

    static void write(detail::json::JsonWriter& jsonWriter, const CurrentVersionMaster& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getNamespaceName())
        {
            jsonWriter.writePropertyName("namespaceName");
            jsonWriter.writeCharArray(*obj.getNamespaceName());
        }
        if (obj.getSettings())
        {
            jsonWriter.writePropertyName("settings");
            jsonWriter.writeCharArray(*obj.getSettings());
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
        if (obj.getDoneTriggerTargetType())
        {
            jsonWriter.writePropertyName("doneTriggerTargetType");
            jsonWriter.writeCharArray(*obj.getDoneTriggerTargetType());
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

    static void write(detail::json::JsonWriter& jsonWriter, const LogSetting& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getLoggingNamespaceId())
        {
            jsonWriter.writePropertyName("loggingNamespaceId");
            jsonWriter.writeCharArray(*obj.getLoggingNamespaceId());
        }
        jsonWriter.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
     */
    explicit Gs2VersionRestClient(Gs2RestSession& gs2RestSession) :
        AbstractGs2ClientBase(gs2RestSession)
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
    }

	/**
	 * ネームスペースの状態を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getNamespaceStatus(GetNamespaceStatusRequest request, std::function<void(AsyncGetNamespaceStatusResult)> callback)
    {
        GetNamespaceStatusTask& task = *new GetNamespaceStatusTask(std::move(request), callback);
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
    }

	/**
	 * バージョンマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeVersionModelMasters(DescribeVersionModelMastersRequest request, std::function<void(AsyncDescribeVersionModelMastersResult)> callback)
    {
        DescribeVersionModelMastersTask& task = *new DescribeVersionModelMastersTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * バージョンマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createVersionModelMaster(CreateVersionModelMasterRequest request, std::function<void(AsyncCreateVersionModelMasterResult)> callback)
    {
        CreateVersionModelMasterTask& task = *new CreateVersionModelMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * バージョンマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getVersionModelMaster(GetVersionModelMasterRequest request, std::function<void(AsyncGetVersionModelMasterResult)> callback)
    {
        GetVersionModelMasterTask& task = *new GetVersionModelMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * バージョンマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateVersionModelMaster(UpdateVersionModelMasterRequest request, std::function<void(AsyncUpdateVersionModelMasterResult)> callback)
    {
        UpdateVersionModelMasterTask& task = *new UpdateVersionModelMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * バージョンマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteVersionModelMaster(DeleteVersionModelMasterRequest request, std::function<void(AsyncDeleteVersionModelMasterResult)> callback)
    {
        DeleteVersionModelMasterTask& task = *new DeleteVersionModelMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * バージョン設定の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeVersionModels(DescribeVersionModelsRequest request, std::function<void(AsyncDescribeVersionModelsResult)> callback)
    {
        DescribeVersionModelsTask& task = *new DescribeVersionModelsTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * バージョン設定を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getVersionModel(GetVersionModelRequest request, std::function<void(AsyncGetVersionModelResult)> callback)
    {
        GetVersionModelTask& task = *new GetVersionModelTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 承認したバージョンの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeAcceptVersions(DescribeAcceptVersionsRequest request, std::function<void(AsyncDescribeAcceptVersionsResult)> callback)
    {
        DescribeAcceptVersionsTask& task = *new DescribeAcceptVersionsTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 承認したバージョンの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeAcceptVersionsByUserId(DescribeAcceptVersionsByUserIdRequest request, std::function<void(AsyncDescribeAcceptVersionsByUserIdResult)> callback)
    {
        DescribeAcceptVersionsByUserIdTask& task = *new DescribeAcceptVersionsByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 現在のバージョンを承認<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void accept(AcceptRequest request, std::function<void(AsyncAcceptResult)> callback)
    {
        AcceptTask& task = *new AcceptTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定して現在のバージョンを承認<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void acceptByUserId(AcceptByUserIdRequest request, std::function<void(AsyncAcceptByUserIdResult)> callback)
    {
        AcceptByUserIdTask& task = *new AcceptByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 承認したバージョンを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getAcceptVersion(GetAcceptVersionRequest request, std::function<void(AsyncGetAcceptVersionResult)> callback)
    {
        GetAcceptVersionTask& task = *new GetAcceptVersionTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザーIDを指定して承認したバージョンを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getAcceptVersionByUserId(GetAcceptVersionByUserIdRequest request, std::function<void(AsyncGetAcceptVersionByUserIdResult)> callback)
    {
        GetAcceptVersionByUserIdTask& task = *new GetAcceptVersionByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 承認したバージョンを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteAcceptVersion(DeleteAcceptVersionRequest request, std::function<void(AsyncDeleteAcceptVersionResult)> callback)
    {
        DeleteAcceptVersionTask& task = *new DeleteAcceptVersionTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザーIDを指定して承認したバージョンを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteAcceptVersionByUserId(DeleteAcceptVersionByUserIdRequest request, std::function<void(AsyncDeleteAcceptVersionByUserIdResult)> callback)
    {
        DeleteAcceptVersionByUserIdTask& task = *new DeleteAcceptVersionByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * バージョンチェック<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void checkVersion(CheckVersionRequest request, std::function<void(AsyncCheckVersionResult)> callback)
    {
        CheckVersionTask& task = *new CheckVersionTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * バージョンチェック<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void checkVersionByUserId(CheckVersionByUserIdRequest request, std::function<void(AsyncCheckVersionByUserIdResult)> callback)
    {
        CheckVersionByUserIdTask& task = *new CheckVersionByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタンプシートのタスクを実行する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void calculateSignature(CalculateSignatureRequest request, std::function<void(AsyncCalculateSignatureResult)> callback)
    {
        CalculateSignatureTask& task = *new CalculateSignatureTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 現在有効なバージョンのマスターデータをエクスポートします<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void exportMaster(ExportMasterRequest request, std::function<void(AsyncExportMasterResult)> callback)
    {
        ExportMasterTask& task = *new ExportMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 現在有効なバージョンを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentVersionMaster(GetCurrentVersionMasterRequest request, std::function<void(AsyncGetCurrentVersionMasterResult)> callback)
    {
        GetCurrentVersionMasterTask& task = *new GetCurrentVersionMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 現在有効なバージョンを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentVersionMaster(UpdateCurrentVersionMasterRequest request, std::function<void(AsyncUpdateCurrentVersionMasterResult)> callback)
    {
        UpdateCurrentVersionMasterTask& task = *new UpdateCurrentVersionMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 現在有効なバージョンを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentVersionMasterFromGitHub(UpdateCurrentVersionMasterFromGitHubRequest request, std::function<void(AsyncUpdateCurrentVersionMasterFromGitHubResult)> callback)
    {
        UpdateCurrentVersionMasterFromGitHubTask& task = *new UpdateCurrentVersionMasterFromGitHubTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

protected:
    Gs2RestSession& getGs2RestSession()
    {
        return static_cast<Gs2RestSession&>(getGs2Session());
    }
};

} }

#endif //GS2_VERSION_GS2VERSIONRESTCLIENT_HPP_