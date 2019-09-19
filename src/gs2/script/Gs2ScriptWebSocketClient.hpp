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

#ifndef GS2_SCRIPT_GS2SCRIPTWEBSOCKETCLIENT_HPP_
#define GS2_SCRIPT_GS2SCRIPTWEBSOCKETCLIENT_HPP_

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
#include "request/DescribeScriptsRequest.hpp"
#include "request/CreateScriptRequest.hpp"
#include "request/CreateScriptFromGitHubRequest.hpp"
#include "request/GetScriptRequest.hpp"
#include "request/UpdateScriptRequest.hpp"
#include "request/UpdateScriptFromGitHubRequest.hpp"
#include "request/DeleteScriptRequest.hpp"
#include "request/DebugInvokeRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeScriptsResult.hpp"
#include "result/CreateScriptResult.hpp"
#include "result/CreateScriptFromGitHubResult.hpp"
#include "result/GetScriptResult.hpp"
#include "result/UpdateScriptResult.hpp"
#include "result/UpdateScriptFromGitHubResult.hpp"
#include "result/DeleteScriptResult.hpp"
#include "result/DebugInvokeResult.hpp"
#include <cstring>

namespace gs2 { namespace script {

/**
 * GS2 Script API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2ScriptWebSocketClient : public AbstractGs2ClientBase
{
private:

    class DescribeNamespacesTask : public detail::Gs2WebSocketSessionTask<DescribeNamespacesResult>
    {
    private:
        DescribeNamespacesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "script";
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
            return "script";
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
            return "script";
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
            return "script";
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
            return "script";
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
            return "script";
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

    class DescribeScriptsTask : public detail::Gs2WebSocketSessionTask<DescribeScriptsResult>
    {
    private:
        DescribeScriptsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "script";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "script";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeScripts";
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
        DescribeScriptsTask(
            DescribeScriptsRequest request,
            Gs2WebSocketSessionTask<DescribeScriptsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeScriptsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeScriptsTask() GS2_OVERRIDE = default;
    };

    class CreateScriptTask : public detail::Gs2WebSocketSessionTask<CreateScriptResult>
    {
    private:
        CreateScriptRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "script";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "script";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "createScript";
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
            if (m_Request.getScript())
            {
                jsonWriter.writePropertyName("script");
                jsonWriter.writeCharArray(*m_Request.getScript());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        CreateScriptTask(
            CreateScriptRequest request,
            Gs2WebSocketSessionTask<CreateScriptResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateScriptResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateScriptTask() GS2_OVERRIDE = default;
    };

    class CreateScriptFromGitHubTask : public detail::Gs2WebSocketSessionTask<CreateScriptFromGitHubResult>
    {
    private:
        CreateScriptFromGitHubRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "script";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "script";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "createScriptFromGitHub";
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
            if (m_Request.getCheckoutSetting())
            {
                jsonWriter.writePropertyName("checkoutSetting");
                write(jsonWriter, *m_Request.getCheckoutSetting());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        CreateScriptFromGitHubTask(
            CreateScriptFromGitHubRequest request,
            Gs2WebSocketSessionTask<CreateScriptFromGitHubResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateScriptFromGitHubResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateScriptFromGitHubTask() GS2_OVERRIDE = default;
    };

    class GetScriptTask : public detail::Gs2WebSocketSessionTask<GetScriptResult>
    {
    private:
        GetScriptRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "script";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "script";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getScript";
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
            if (m_Request.getScriptName())
            {
                jsonWriter.writePropertyName("scriptName");
                jsonWriter.writeCharArray(*m_Request.getScriptName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetScriptTask(
            GetScriptRequest request,
            Gs2WebSocketSessionTask<GetScriptResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetScriptResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetScriptTask() GS2_OVERRIDE = default;
    };

    class UpdateScriptTask : public detail::Gs2WebSocketSessionTask<UpdateScriptResult>
    {
    private:
        UpdateScriptRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "script";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "script";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateScript";
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
            if (m_Request.getScriptName())
            {
                jsonWriter.writePropertyName("scriptName");
                jsonWriter.writeCharArray(*m_Request.getScriptName());
            }
            if (m_Request.getDescription())
            {
                jsonWriter.writePropertyName("description");
                jsonWriter.writeCharArray(*m_Request.getDescription());
            }
            if (m_Request.getScript())
            {
                jsonWriter.writePropertyName("script");
                jsonWriter.writeCharArray(*m_Request.getScript());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        UpdateScriptTask(
            UpdateScriptRequest request,
            Gs2WebSocketSessionTask<UpdateScriptResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateScriptResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateScriptTask() GS2_OVERRIDE = default;
    };

    class UpdateScriptFromGitHubTask : public detail::Gs2WebSocketSessionTask<UpdateScriptFromGitHubResult>
    {
    private:
        UpdateScriptFromGitHubRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "script";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "script";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateScriptFromGitHub";
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
            if (m_Request.getScriptName())
            {
                jsonWriter.writePropertyName("scriptName");
                jsonWriter.writeCharArray(*m_Request.getScriptName());
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
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        UpdateScriptFromGitHubTask(
            UpdateScriptFromGitHubRequest request,
            Gs2WebSocketSessionTask<UpdateScriptFromGitHubResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateScriptFromGitHubResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateScriptFromGitHubTask() GS2_OVERRIDE = default;
    };

    class DeleteScriptTask : public detail::Gs2WebSocketSessionTask<void>
    {
    private:
        DeleteScriptRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "script";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "script";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteScript";
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
            if (m_Request.getScriptName())
            {
                jsonWriter.writePropertyName("scriptName");
                jsonWriter.writeCharArray(*m_Request.getScriptName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        DeleteScriptTask(
            DeleteScriptRequest request,
            Gs2WebSocketSessionTask<void>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<void>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteScriptTask() GS2_OVERRIDE = default;
    };

    class DebugInvokeTask : public detail::Gs2WebSocketSessionTask<DebugInvokeResult>
    {
    private:
        DebugInvokeRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "script";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "script";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "debugInvoke";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getScript())
            {
                jsonWriter.writePropertyName("script");
                jsonWriter.writeCharArray(*m_Request.getScript());
            }
            if (m_Request.getArgs())
            {
                jsonWriter.writePropertyName("args");
                jsonWriter.writeCharArray(*m_Request.getArgs());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        DebugInvokeTask(
            DebugInvokeRequest request,
            Gs2WebSocketSessionTask<DebugInvokeResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DebugInvokeResult>(callback),
            m_Request(std::move(request))
        {}

        ~DebugInvokeTask() GS2_OVERRIDE = default;
    };

private:
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

    static void write(detail::json::JsonWriter& jsonWriter, const Script& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getScriptId())
        {
            jsonWriter.writePropertyName("scriptId");
            jsonWriter.writeCharArray(*obj.getScriptId());
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
        if (obj.getScript())
        {
            jsonWriter.writePropertyName("script");
            jsonWriter.writeCharArray(*obj.getScript());
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


public:
    /**
     * コンストラクタ。
     *
     * @param gs2WebSocketSession WebSocket API 用セッション
     */
    explicit Gs2ScriptWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
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
	 * スクリプトの一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeScripts(DescribeScriptsRequest request, std::function<void(AsyncDescribeScriptsResult)> callback)
    {
        DescribeScriptsTask& task = *new DescribeScriptsTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * スクリプトを新規作成します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createScript(CreateScriptRequest request, std::function<void(AsyncCreateScriptResult)> callback)
    {
        CreateScriptTask& task = *new CreateScriptTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * GitHubリポジトリのコードからスクリプトを新規作成します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createScriptFromGitHub(CreateScriptFromGitHubRequest request, std::function<void(AsyncCreateScriptFromGitHubResult)> callback)
    {
        CreateScriptFromGitHubTask& task = *new CreateScriptFromGitHubTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * スクリプトを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getScript(GetScriptRequest request, std::function<void(AsyncGetScriptResult)> callback)
    {
        GetScriptTask& task = *new GetScriptTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * スクリプトを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateScript(UpdateScriptRequest request, std::function<void(AsyncUpdateScriptResult)> callback)
    {
        UpdateScriptTask& task = *new UpdateScriptTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * GithHub をデータソースとしてスクリプトを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateScriptFromGitHub(UpdateScriptFromGitHubRequest request, std::function<void(AsyncUpdateScriptFromGitHubResult)> callback)
    {
        UpdateScriptFromGitHubTask& task = *new UpdateScriptFromGitHubTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * スクリプトを削除します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteScript(DeleteScriptRequest request, std::function<void(AsyncDeleteScriptResult)> callback)
    {
        DeleteScriptTask& task = *new DeleteScriptTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * スクリプトを実行します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void debugInvoke(DebugInvokeRequest request, std::function<void(AsyncDebugInvokeResult)> callback)
    {
        DebugInvokeTask& task = *new DebugInvokeTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_SCRIPT_GS2SCRIPTWEBSOCKETCLIENT_HPP_