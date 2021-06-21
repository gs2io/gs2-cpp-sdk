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

#ifndef GS2_LOG_GS2LOGWEBSOCKETCLIENT_HPP_
#define GS2_LOG_GS2LOGWEBSOCKETCLIENT_HPP_

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
#include "request/QueryAccessLogRequest.hpp"
#include "request/CountAccessLogRequest.hpp"
#include "request/QueryIssueStampSheetLogRequest.hpp"
#include "request/CountIssueStampSheetLogRequest.hpp"
#include "request/QueryExecuteStampSheetLogRequest.hpp"
#include "request/CountExecuteStampSheetLogRequest.hpp"
#include "request/QueryExecuteStampTaskLogRequest.hpp"
#include "request/CountExecuteStampTaskLogRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/QueryAccessLogResult.hpp"
#include "result/CountAccessLogResult.hpp"
#include "result/QueryIssueStampSheetLogResult.hpp"
#include "result/CountIssueStampSheetLogResult.hpp"
#include "result/QueryExecuteStampSheetLogResult.hpp"
#include "result/CountExecuteStampSheetLogResult.hpp"
#include "result/QueryExecuteStampTaskLogResult.hpp"
#include "result/CountExecuteStampTaskLogResult.hpp"
#include <cstring>

namespace gs2 { namespace log {

/**
 * GS2 Log API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2LogWebSocketClient : public AbstractGs2ClientBase
{
private:

    class CreateNamespaceTask : public detail::Gs2WebSocketSessionTask<CreateNamespaceResult>
    {
    private:
        CreateNamespaceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "log";
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
            if (m_Request.getType())
            {
                jsonWriter.writePropertyName("type");
                jsonWriter.writeCharArray(*m_Request.getType());
            }
            if (m_Request.getGcpCredentialJson())
            {
                jsonWriter.writePropertyName("gcpCredentialJson");
                jsonWriter.writeCharArray(*m_Request.getGcpCredentialJson());
            }
            if (m_Request.getBigQueryDatasetName())
            {
                jsonWriter.writePropertyName("bigQueryDatasetName");
                jsonWriter.writeCharArray(*m_Request.getBigQueryDatasetName());
            }
            if (m_Request.getLogExpireDays())
            {
                jsonWriter.writePropertyName("logExpireDays");
                jsonWriter.writeInt32(*m_Request.getLogExpireDays());
            }
            if (m_Request.getAwsRegion())
            {
                jsonWriter.writePropertyName("awsRegion");
                jsonWriter.writeCharArray(*m_Request.getAwsRegion());
            }
            if (m_Request.getAwsAccessKeyId())
            {
                jsonWriter.writePropertyName("awsAccessKeyId");
                jsonWriter.writeCharArray(*m_Request.getAwsAccessKeyId());
            }
            if (m_Request.getAwsSecretAccessKey())
            {
                jsonWriter.writePropertyName("awsSecretAccessKey");
                jsonWriter.writeCharArray(*m_Request.getAwsSecretAccessKey());
            }
            if (m_Request.getFirehoseStreamName())
            {
                jsonWriter.writePropertyName("firehoseStreamName");
                jsonWriter.writeCharArray(*m_Request.getFirehoseStreamName());
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
            return "log";
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
            return "log";
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
            return "log";
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
            if (m_Request.getType())
            {
                jsonWriter.writePropertyName("type");
                jsonWriter.writeCharArray(*m_Request.getType());
            }
            if (m_Request.getGcpCredentialJson())
            {
                jsonWriter.writePropertyName("gcpCredentialJson");
                jsonWriter.writeCharArray(*m_Request.getGcpCredentialJson());
            }
            if (m_Request.getBigQueryDatasetName())
            {
                jsonWriter.writePropertyName("bigQueryDatasetName");
                jsonWriter.writeCharArray(*m_Request.getBigQueryDatasetName());
            }
            if (m_Request.getLogExpireDays())
            {
                jsonWriter.writePropertyName("logExpireDays");
                jsonWriter.writeInt32(*m_Request.getLogExpireDays());
            }
            if (m_Request.getAwsRegion())
            {
                jsonWriter.writePropertyName("awsRegion");
                jsonWriter.writeCharArray(*m_Request.getAwsRegion());
            }
            if (m_Request.getAwsAccessKeyId())
            {
                jsonWriter.writePropertyName("awsAccessKeyId");
                jsonWriter.writeCharArray(*m_Request.getAwsAccessKeyId());
            }
            if (m_Request.getAwsSecretAccessKey())
            {
                jsonWriter.writePropertyName("awsSecretAccessKey");
                jsonWriter.writeCharArray(*m_Request.getAwsSecretAccessKey());
            }
            if (m_Request.getFirehoseStreamName())
            {
                jsonWriter.writePropertyName("firehoseStreamName");
                jsonWriter.writeCharArray(*m_Request.getFirehoseStreamName());
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
            return "log";
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
        if (obj.getType())
        {
            jsonWriter.writePropertyName("type");
            jsonWriter.writeCharArray(*obj.getType());
        }
        if (obj.getGcpCredentialJson())
        {
            jsonWriter.writePropertyName("gcpCredentialJson");
            jsonWriter.writeCharArray(*obj.getGcpCredentialJson());
        }
        if (obj.getBigQueryDatasetName())
        {
            jsonWriter.writePropertyName("bigQueryDatasetName");
            jsonWriter.writeCharArray(*obj.getBigQueryDatasetName());
        }
        if (obj.getLogExpireDays())
        {
            jsonWriter.writePropertyName("logExpireDays");
            jsonWriter.writeInt32(*obj.getLogExpireDays());
        }
        if (obj.getAwsRegion())
        {
            jsonWriter.writePropertyName("awsRegion");
            jsonWriter.writeCharArray(*obj.getAwsRegion());
        }
        if (obj.getAwsAccessKeyId())
        {
            jsonWriter.writePropertyName("awsAccessKeyId");
            jsonWriter.writeCharArray(*obj.getAwsAccessKeyId());
        }
        if (obj.getAwsSecretAccessKey())
        {
            jsonWriter.writePropertyName("awsSecretAccessKey");
            jsonWriter.writeCharArray(*obj.getAwsSecretAccessKey());
        }
        if (obj.getFirehoseStreamName())
        {
            jsonWriter.writePropertyName("firehoseStreamName");
            jsonWriter.writeCharArray(*obj.getFirehoseStreamName());
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

    static void write(detail::json::JsonWriter& jsonWriter, const AccessLog& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getTimestamp())
        {
            jsonWriter.writePropertyName("timestamp");
            jsonWriter.writeInt64(*obj.getTimestamp());
        }
        if (obj.getRequestId())
        {
            jsonWriter.writePropertyName("requestId");
            jsonWriter.writeCharArray(*obj.getRequestId());
        }
        if (obj.getService())
        {
            jsonWriter.writePropertyName("service");
            jsonWriter.writeCharArray(*obj.getService());
        }
        if (obj.getMethod())
        {
            jsonWriter.writePropertyName("method");
            jsonWriter.writeCharArray(*obj.getMethod());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getRequest())
        {
            jsonWriter.writePropertyName("request");
            jsonWriter.writeCharArray(*obj.getRequest());
        }
        if (obj.getResult())
        {
            jsonWriter.writePropertyName("result");
            jsonWriter.writeCharArray(*obj.getResult());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const AccessLogCount& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getService())
        {
            jsonWriter.writePropertyName("service");
            jsonWriter.writeCharArray(*obj.getService());
        }
        if (obj.getMethod())
        {
            jsonWriter.writePropertyName("method");
            jsonWriter.writeCharArray(*obj.getMethod());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getCount())
        {
            jsonWriter.writePropertyName("count");
            jsonWriter.writeInt64(*obj.getCount());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const IssueStampSheetLog& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getTimestamp())
        {
            jsonWriter.writePropertyName("timestamp");
            jsonWriter.writeInt64(*obj.getTimestamp());
        }
        if (obj.getTransactionId())
        {
            jsonWriter.writePropertyName("transactionId");
            jsonWriter.writeCharArray(*obj.getTransactionId());
        }
        if (obj.getService())
        {
            jsonWriter.writePropertyName("service");
            jsonWriter.writeCharArray(*obj.getService());
        }
        if (obj.getMethod())
        {
            jsonWriter.writePropertyName("method");
            jsonWriter.writeCharArray(*obj.getMethod());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getAction())
        {
            jsonWriter.writePropertyName("action");
            jsonWriter.writeCharArray(*obj.getAction());
        }
        if (obj.getArgs())
        {
            jsonWriter.writePropertyName("args");
            jsonWriter.writeCharArray(*obj.getArgs());
        }
        if (obj.getTasks())
        {
            jsonWriter.writePropertyName("tasks");
            jsonWriter.writeCharArray(*obj.getTasks());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const IssueStampSheetLogCount& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getService())
        {
            jsonWriter.writePropertyName("service");
            jsonWriter.writeCharArray(*obj.getService());
        }
        if (obj.getMethod())
        {
            jsonWriter.writePropertyName("method");
            jsonWriter.writeCharArray(*obj.getMethod());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getAction())
        {
            jsonWriter.writePropertyName("action");
            jsonWriter.writeCharArray(*obj.getAction());
        }
        if (obj.getCount())
        {
            jsonWriter.writePropertyName("count");
            jsonWriter.writeInt64(*obj.getCount());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const ExecuteStampSheetLog& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getTimestamp())
        {
            jsonWriter.writePropertyName("timestamp");
            jsonWriter.writeInt64(*obj.getTimestamp());
        }
        if (obj.getTransactionId())
        {
            jsonWriter.writePropertyName("transactionId");
            jsonWriter.writeCharArray(*obj.getTransactionId());
        }
        if (obj.getService())
        {
            jsonWriter.writePropertyName("service");
            jsonWriter.writeCharArray(*obj.getService());
        }
        if (obj.getMethod())
        {
            jsonWriter.writePropertyName("method");
            jsonWriter.writeCharArray(*obj.getMethod());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getAction())
        {
            jsonWriter.writePropertyName("action");
            jsonWriter.writeCharArray(*obj.getAction());
        }
        if (obj.getArgs())
        {
            jsonWriter.writePropertyName("args");
            jsonWriter.writeCharArray(*obj.getArgs());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const ExecuteStampSheetLogCount& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getService())
        {
            jsonWriter.writePropertyName("service");
            jsonWriter.writeCharArray(*obj.getService());
        }
        if (obj.getMethod())
        {
            jsonWriter.writePropertyName("method");
            jsonWriter.writeCharArray(*obj.getMethod());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getAction())
        {
            jsonWriter.writePropertyName("action");
            jsonWriter.writeCharArray(*obj.getAction());
        }
        if (obj.getCount())
        {
            jsonWriter.writePropertyName("count");
            jsonWriter.writeInt64(*obj.getCount());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const ExecuteStampTaskLog& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getTimestamp())
        {
            jsonWriter.writePropertyName("timestamp");
            jsonWriter.writeInt64(*obj.getTimestamp());
        }
        if (obj.getTaskId())
        {
            jsonWriter.writePropertyName("taskId");
            jsonWriter.writeCharArray(*obj.getTaskId());
        }
        if (obj.getService())
        {
            jsonWriter.writePropertyName("service");
            jsonWriter.writeCharArray(*obj.getService());
        }
        if (obj.getMethod())
        {
            jsonWriter.writePropertyName("method");
            jsonWriter.writeCharArray(*obj.getMethod());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getAction())
        {
            jsonWriter.writePropertyName("action");
            jsonWriter.writeCharArray(*obj.getAction());
        }
        if (obj.getArgs())
        {
            jsonWriter.writePropertyName("args");
            jsonWriter.writeCharArray(*obj.getArgs());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const ExecuteStampTaskLogCount& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getService())
        {
            jsonWriter.writePropertyName("service");
            jsonWriter.writeCharArray(*obj.getService());
        }
        if (obj.getMethod())
        {
            jsonWriter.writePropertyName("method");
            jsonWriter.writeCharArray(*obj.getMethod());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getAction())
        {
            jsonWriter.writePropertyName("action");
            jsonWriter.writeCharArray(*obj.getAction());
        }
        if (obj.getCount())
        {
            jsonWriter.writePropertyName("count");
            jsonWriter.writeInt64(*obj.getCount());
        }
        jsonWriter.writeObjectEnd();
    }


public:
    /**
     * コンストラクタ。
     *
     * @param gs2WebSocketSession WebSocket API 用セッション
     */
    explicit Gs2LogWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
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

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_LOG_GS2LOGWEBSOCKETCLIENT_HPP_