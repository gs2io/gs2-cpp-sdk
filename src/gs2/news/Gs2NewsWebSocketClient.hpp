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

#ifndef GS2_NEWS_GS2NEWSWEBSOCKETCLIENT_HPP_
#define GS2_NEWS_GS2NEWSWEBSOCKETCLIENT_HPP_

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
#include "request/PrepareUpdateCurrentNewsMasterRequest.hpp"
#include "request/UpdateCurrentNewsMasterRequest.hpp"
#include "request/PrepareUpdateCurrentNewsMasterFromGitHubRequest.hpp"
#include "request/DescribeNewsRequest.hpp"
#include "request/DescribeNewsByUserIdRequest.hpp"
#include "request/WantGrantRequest.hpp"
#include "request/WantGrantByUserIdRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/PrepareUpdateCurrentNewsMasterResult.hpp"
#include "result/UpdateCurrentNewsMasterResult.hpp"
#include "result/PrepareUpdateCurrentNewsMasterFromGitHubResult.hpp"
#include "result/DescribeNewsResult.hpp"
#include "result/DescribeNewsByUserIdResult.hpp"
#include "result/WantGrantResult.hpp"
#include "result/WantGrantByUserIdResult.hpp"
#include <cstring>

namespace gs2 { namespace news {

/**
 * GS2 News API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2NewsWebSocketClient : public AbstractGs2ClientBase
{
private:

    class DescribeNamespacesTask : public detail::Gs2WebSocketSessionTask<DescribeNamespacesResult>
    {
    private:
        DescribeNamespacesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "news";
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
            return "news";
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
            return "news";
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
            return "news";
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
            return "news";
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

    class DeleteNamespaceTask : public detail::Gs2WebSocketSessionTask<void>
    {
    private:
        DeleteNamespaceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "news";
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

    class PrepareUpdateCurrentNewsMasterTask : public detail::Gs2WebSocketSessionTask<PrepareUpdateCurrentNewsMasterResult>
    {
    private:
        PrepareUpdateCurrentNewsMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "news";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "currentNewsMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "prepareUpdateCurrentNewsMaster";
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
        PrepareUpdateCurrentNewsMasterTask(
            PrepareUpdateCurrentNewsMasterRequest request,
            Gs2WebSocketSessionTask<PrepareUpdateCurrentNewsMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<PrepareUpdateCurrentNewsMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~PrepareUpdateCurrentNewsMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentNewsMasterTask : public detail::Gs2WebSocketSessionTask<void>
    {
    private:
        UpdateCurrentNewsMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "news";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "currentNewsMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateCurrentNewsMaster";
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
            if (m_Request.getUploadToken())
            {
                jsonWriter.writePropertyName("uploadToken");
                jsonWriter.writeCharArray(*m_Request.getUploadToken());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        UpdateCurrentNewsMasterTask(
            UpdateCurrentNewsMasterRequest request,
            Gs2WebSocketSessionTask<void>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<void>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateCurrentNewsMasterTask() GS2_OVERRIDE = default;
    };

    class PrepareUpdateCurrentNewsMasterFromGitHubTask : public detail::Gs2WebSocketSessionTask<PrepareUpdateCurrentNewsMasterFromGitHubResult>
    {
    private:
        PrepareUpdateCurrentNewsMasterFromGitHubRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "news";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "currentNewsMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "prepareUpdateCurrentNewsMasterFromGitHub";
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
        PrepareUpdateCurrentNewsMasterFromGitHubTask(
            PrepareUpdateCurrentNewsMasterFromGitHubRequest request,
            Gs2WebSocketSessionTask<PrepareUpdateCurrentNewsMasterFromGitHubResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<PrepareUpdateCurrentNewsMasterFromGitHubResult>(callback),
            m_Request(std::move(request))
        {}

        ~PrepareUpdateCurrentNewsMasterFromGitHubTask() GS2_OVERRIDE = default;
    };

    class DescribeNewsTask : public detail::Gs2WebSocketSessionTask<DescribeNewsResult>
    {
    private:
        DescribeNewsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "news";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "news";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeNews";
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
        DescribeNewsTask(
            DescribeNewsRequest request,
            Gs2WebSocketSessionTask<DescribeNewsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeNewsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeNewsTask() GS2_OVERRIDE = default;
    };

    class DescribeNewsByUserIdTask : public detail::Gs2WebSocketSessionTask<DescribeNewsByUserIdResult>
    {
    private:
        DescribeNewsByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "news";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "news";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeNewsByUserId";
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
        DescribeNewsByUserIdTask(
            DescribeNewsByUserIdRequest request,
            Gs2WebSocketSessionTask<DescribeNewsByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeNewsByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeNewsByUserIdTask() GS2_OVERRIDE = default;
    };

    class WantGrantTask : public detail::Gs2WebSocketSessionTask<WantGrantResult>
    {
    private:
        WantGrantRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "news";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "news";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "wantGrant";
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
        WantGrantTask(
            WantGrantRequest request,
            Gs2WebSocketSessionTask<WantGrantResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<WantGrantResult>(callback),
            m_Request(std::move(request))
        {}

        ~WantGrantTask() GS2_OVERRIDE = default;
    };

    class WantGrantByUserIdTask : public detail::Gs2WebSocketSessionTask<WantGrantByUserIdResult>
    {
    private:
        WantGrantByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "news";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "news";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "wantGrantByUserId";
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
        WantGrantByUserIdTask(
            WantGrantByUserIdRequest request,
            Gs2WebSocketSessionTask<WantGrantByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<WantGrantByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~WantGrantByUserIdTask() GS2_OVERRIDE = default;
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
        if (obj.getVersion())
        {
            jsonWriter.writePropertyName("version");
            jsonWriter.writeCharArray(*obj.getVersion());
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

    static void write(detail::json::JsonWriter& jsonWriter, const News& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getSection())
        {
            jsonWriter.writePropertyName("section");
            jsonWriter.writeCharArray(*obj.getSection());
        }
        if (obj.getContent())
        {
            jsonWriter.writePropertyName("content");
            jsonWriter.writeCharArray(*obj.getContent());
        }
        if (obj.getTitle())
        {
            jsonWriter.writePropertyName("title");
            jsonWriter.writeCharArray(*obj.getTitle());
        }
        if (obj.getScheduleEventId())
        {
            jsonWriter.writePropertyName("scheduleEventId");
            jsonWriter.writeCharArray(*obj.getScheduleEventId());
        }
        if (obj.getTimestamp())
        {
            jsonWriter.writePropertyName("timestamp");
            jsonWriter.writeInt64(*obj.getTimestamp());
        }
        if (obj.getFrontMatter())
        {
            jsonWriter.writePropertyName("frontMatter");
            jsonWriter.writeCharArray(*obj.getFrontMatter());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const SetCookieRequestEntry& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getKey())
        {
            jsonWriter.writePropertyName("key");
            jsonWriter.writeCharArray(*obj.getKey());
        }
        if (obj.getValue())
        {
            jsonWriter.writePropertyName("value");
            jsonWriter.writeCharArray(*obj.getValue());
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
    explicit Gs2NewsWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
        AbstractGs2ClientBase(gs2WebSocketSession)
    {
    }

	/**
	 * ネームスペースの一覧を取得します<br>
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
	 * ネームスペースを新規作成します<br>
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
	 * ネームスペースの状態を取得します<br>
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
	 * ネームスペースを取得します<br>
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
	 * ネームスペースを更新します<br>
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
	 * ネームスペースを削除します<br>
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
	 * 現在有効なお知らせを更新準備する<br>
	 *   <br>
	 *   応答に含まれるURLにサイトデータを圧縮したzipファイルをアップロードし<br>
	 *   アップロード完了後に updateCurrentNewsMaster を呼び出して反映します。<br>
	 *   <br>
	 *   zipファイルをアップロードする際には Content-Type に application/zip を指定する必要があります。<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void prepareUpdateCurrentNewsMaster(PrepareUpdateCurrentNewsMasterRequest request, std::function<void(AsyncPrepareUpdateCurrentNewsMasterResult)> callback)
    {
        PrepareUpdateCurrentNewsMasterTask& task = *new PrepareUpdateCurrentNewsMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 現在有効なお知らせを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentNewsMaster(UpdateCurrentNewsMasterRequest request, std::function<void(AsyncUpdateCurrentNewsMasterResult)> callback)
    {
        UpdateCurrentNewsMasterTask& task = *new UpdateCurrentNewsMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 現在有効なお知らせを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void prepareUpdateCurrentNewsMasterFromGitHub(PrepareUpdateCurrentNewsMasterFromGitHubRequest request, std::function<void(AsyncPrepareUpdateCurrentNewsMasterFromGitHubResult)> callback)
    {
        PrepareUpdateCurrentNewsMasterFromGitHubTask& task = *new PrepareUpdateCurrentNewsMasterFromGitHubTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * お知らせ記事の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeNews(DescribeNewsRequest request, std::function<void(AsyncDescribeNewsResult)> callback)
    {
        DescribeNewsTask& task = *new DescribeNewsTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザIDを指定してお知らせ記事の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeNewsByUserId(DescribeNewsByUserIdRequest request, std::function<void(AsyncDescribeNewsByUserIdResult)> callback)
    {
        DescribeNewsByUserIdTask& task = *new DescribeNewsByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * お知らせ記事に加算<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void wantGrant(WantGrantRequest request, std::function<void(AsyncWantGrantResult)> callback)
    {
        WantGrantTask& task = *new WantGrantTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * お知らせ記事に加算<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void wantGrantByUserId(WantGrantByUserIdRequest request, std::function<void(AsyncWantGrantByUserIdResult)> callback)
    {
        WantGrantByUserIdTask& task = *new WantGrantByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_NEWS_GS2NEWSWEBSOCKETCLIENT_HPP_