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

#ifndef GS2_VERSION_GS2VERSIONWEBSOCKETCLIENT_HPP_
#define GS2_VERSION_GS2VERSIONWEBSOCKETCLIENT_HPP_

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
class Gs2VersionWebSocketClient : public AbstractGs2ClientBase
{
private:

    class CreateNamespaceTask : public detail::Gs2WebSocketSessionTask<CreateNamespaceResult>
    {
    private:
        CreateNamespaceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
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
            if (m_Request.getAssumeUserId())
            {
                jsonWriter.writePropertyName("assumeUserId");
                jsonWriter.writeCharArray(*m_Request.getAssumeUserId());
            }
            if (m_Request.getAcceptVersionScript())
            {
                jsonWriter.writePropertyName("acceptVersionScript");
                write(jsonWriter, *m_Request.getAcceptVersionScript());
            }
            if (m_Request.getCheckVersionTriggerScriptId())
            {
                jsonWriter.writePropertyName("checkVersionTriggerScriptId");
                jsonWriter.writeCharArray(*m_Request.getCheckVersionTriggerScriptId());
            }
            if (m_Request.getLogSetting())
            {
                jsonWriter.writePropertyName("logSetting");
                write(jsonWriter, *m_Request.getLogSetting());
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
            return "version";
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
            return "version";
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
            return "version";
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
            if (m_Request.getAssumeUserId())
            {
                jsonWriter.writePropertyName("assumeUserId");
                jsonWriter.writeCharArray(*m_Request.getAssumeUserId());
            }
            if (m_Request.getAcceptVersionScript())
            {
                jsonWriter.writePropertyName("acceptVersionScript");
                write(jsonWriter, *m_Request.getAcceptVersionScript());
            }
            if (m_Request.getCheckVersionTriggerScriptId())
            {
                jsonWriter.writePropertyName("checkVersionTriggerScriptId");
                jsonWriter.writeCharArray(*m_Request.getCheckVersionTriggerScriptId());
            }
            if (m_Request.getLogSetting())
            {
                jsonWriter.writePropertyName("logSetting");
                write(jsonWriter, *m_Request.getLogSetting());
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

    class DeleteNamespaceTask : public detail::Gs2WebSocketSessionTask<DeleteNamespaceResult>
    {
    private:
        DeleteNamespaceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
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
            Gs2WebSocketSessionTask<DeleteNamespaceResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteNamespaceResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteNamespaceTask() GS2_OVERRIDE = default;
    };

    class CreateVersionModelMasterTask : public detail::Gs2WebSocketSessionTask<CreateVersionModelMasterResult>
    {
    private:
        CreateVersionModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "versionModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "createVersionModelMaster";
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
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        CreateVersionModelMasterTask(
            CreateVersionModelMasterRequest request,
            Gs2WebSocketSessionTask<CreateVersionModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateVersionModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateVersionModelMasterTask() GS2_OVERRIDE = default;
    };

    class GetVersionModelMasterTask : public detail::Gs2WebSocketSessionTask<GetVersionModelMasterResult>
    {
    private:
        GetVersionModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "versionModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getVersionModelMaster";
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
            if (m_Request.getVersionName())
            {
                jsonWriter.writePropertyName("versionName");
                jsonWriter.writeCharArray(*m_Request.getVersionName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetVersionModelMasterTask(
            GetVersionModelMasterRequest request,
            Gs2WebSocketSessionTask<GetVersionModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetVersionModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetVersionModelMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateVersionModelMasterTask : public detail::Gs2WebSocketSessionTask<UpdateVersionModelMasterResult>
    {
    private:
        UpdateVersionModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "versionModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateVersionModelMaster";
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
            if (m_Request.getVersionName())
            {
                jsonWriter.writePropertyName("versionName");
                jsonWriter.writeCharArray(*m_Request.getVersionName());
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
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        UpdateVersionModelMasterTask(
            UpdateVersionModelMasterRequest request,
            Gs2WebSocketSessionTask<UpdateVersionModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateVersionModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateVersionModelMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteVersionModelMasterTask : public detail::Gs2WebSocketSessionTask<DeleteVersionModelMasterResult>
    {
    private:
        DeleteVersionModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "versionModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteVersionModelMaster";
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
            if (m_Request.getVersionName())
            {
                jsonWriter.writePropertyName("versionName");
                jsonWriter.writeCharArray(*m_Request.getVersionName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        DeleteVersionModelMasterTask(
            DeleteVersionModelMasterRequest request,
            Gs2WebSocketSessionTask<DeleteVersionModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteVersionModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteVersionModelMasterTask() GS2_OVERRIDE = default;
    };

    class GetVersionModelTask : public detail::Gs2WebSocketSessionTask<GetVersionModelResult>
    {
    private:
        GetVersionModelRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "versionModel";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getVersionModel";
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
            if (m_Request.getVersionName())
            {
                jsonWriter.writePropertyName("versionName");
                jsonWriter.writeCharArray(*m_Request.getVersionName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetVersionModelTask(
            GetVersionModelRequest request,
            Gs2WebSocketSessionTask<GetVersionModelResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetVersionModelResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetVersionModelTask() GS2_OVERRIDE = default;
    };

    class AcceptTask : public detail::Gs2WebSocketSessionTask<AcceptResult>
    {
    private:
        AcceptRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "acceptVersion";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "accept";
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
            if (m_Request.getVersionName())
            {
                jsonWriter.writePropertyName("versionName");
                jsonWriter.writeCharArray(*m_Request.getVersionName());
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
        AcceptTask(
            AcceptRequest request,
            Gs2WebSocketSessionTask<AcceptResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<AcceptResult>(callback),
            m_Request(std::move(request))
        {}

        ~AcceptTask() GS2_OVERRIDE = default;
    };

    class AcceptByUserIdTask : public detail::Gs2WebSocketSessionTask<AcceptByUserIdResult>
    {
    private:
        AcceptByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "acceptVersion";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "acceptByUserId";
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
        AcceptByUserIdTask(
            AcceptByUserIdRequest request,
            Gs2WebSocketSessionTask<AcceptByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<AcceptByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~AcceptByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetAcceptVersionTask : public detail::Gs2WebSocketSessionTask<GetAcceptVersionResult>
    {
    private:
        GetAcceptVersionRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "acceptVersion";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getAcceptVersion";
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
            if (m_Request.getVersionName())
            {
                jsonWriter.writePropertyName("versionName");
                jsonWriter.writeCharArray(*m_Request.getVersionName());
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
        GetAcceptVersionTask(
            GetAcceptVersionRequest request,
            Gs2WebSocketSessionTask<GetAcceptVersionResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetAcceptVersionResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetAcceptVersionTask() GS2_OVERRIDE = default;
    };

    class GetAcceptVersionByUserIdTask : public detail::Gs2WebSocketSessionTask<GetAcceptVersionByUserIdResult>
    {
    private:
        GetAcceptVersionByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "acceptVersion";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getAcceptVersionByUserId";
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
            if (m_Request.getVersionName())
            {
                jsonWriter.writePropertyName("versionName");
                jsonWriter.writeCharArray(*m_Request.getVersionName());
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
        GetAcceptVersionByUserIdTask(
            GetAcceptVersionByUserIdRequest request,
            Gs2WebSocketSessionTask<GetAcceptVersionByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetAcceptVersionByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetAcceptVersionByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteAcceptVersionTask : public detail::Gs2WebSocketSessionTask<void>
    {
    private:
        DeleteAcceptVersionRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "acceptVersion";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteAcceptVersion";
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
            if (m_Request.getVersionName())
            {
                jsonWriter.writePropertyName("versionName");
                jsonWriter.writeCharArray(*m_Request.getVersionName());
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
        DeleteAcceptVersionTask(
            DeleteAcceptVersionRequest request,
            Gs2WebSocketSessionTask<void>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<void>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteAcceptVersionTask() GS2_OVERRIDE = default;
    };

    class DeleteAcceptVersionByUserIdTask : public detail::Gs2WebSocketSessionTask<void>
    {
    private:
        DeleteAcceptVersionByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "acceptVersion";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteAcceptVersionByUserId";
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
            if (m_Request.getVersionName())
            {
                jsonWriter.writePropertyName("versionName");
                jsonWriter.writeCharArray(*m_Request.getVersionName());
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
        DeleteAcceptVersionByUserIdTask(
            DeleteAcceptVersionByUserIdRequest request,
            Gs2WebSocketSessionTask<void>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<void>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteAcceptVersionByUserIdTask() GS2_OVERRIDE = default;
    };

    class CheckVersionTask : public detail::Gs2WebSocketSessionTask<CheckVersionResult>
    {
    private:
        CheckVersionRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "checker";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "checkVersion";
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
        CheckVersionTask(
            CheckVersionRequest request,
            Gs2WebSocketSessionTask<CheckVersionResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CheckVersionResult>(callback),
            m_Request(std::move(request))
        {}

        ~CheckVersionTask() GS2_OVERRIDE = default;
    };

    class CheckVersionByUserIdTask : public detail::Gs2WebSocketSessionTask<CheckVersionByUserIdResult>
    {
    private:
        CheckVersionByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "checker";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "checkVersionByUserId";
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
        CheckVersionByUserIdTask(
            CheckVersionByUserIdRequest request,
            Gs2WebSocketSessionTask<CheckVersionByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CheckVersionByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~CheckVersionByUserIdTask() GS2_OVERRIDE = default;
    };

    class CalculateSignatureTask : public detail::Gs2WebSocketSessionTask<CalculateSignatureResult>
    {
    private:
        CalculateSignatureRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "version";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "checker";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "calculateSignature";
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
            if (m_Request.getVersionName())
            {
                jsonWriter.writePropertyName("versionName");
                jsonWriter.writeCharArray(*m_Request.getVersionName());
            }
            if (m_Request.getVersion())
            {
                jsonWriter.writePropertyName("version");
                write(jsonWriter, *m_Request.getVersion());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        CalculateSignatureTask(
            CalculateSignatureRequest request,
            Gs2WebSocketSessionTask<CalculateSignatureResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CalculateSignatureResult>(callback),
            m_Request(std::move(request))
        {}

        ~CalculateSignatureTask() GS2_OVERRIDE = default;
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
     * @param gs2WebSocketSession WebSocket API 用セッション
     */
    explicit Gs2VersionWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
        AbstractGs2ClientBase(gs2WebSocketSession)
    {
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
	 * ネームスペースの状態を取得<br>
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
	 * バージョンマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createVersionModelMaster(CreateVersionModelMasterRequest request, std::function<void(AsyncCreateVersionModelMasterResult)> callback)
    {
        CreateVersionModelMasterTask& task = *new CreateVersionModelMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
    }

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_VERSION_GS2VERSIONWEBSOCKETCLIENT_HPP_