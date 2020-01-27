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

#ifndef GS2_LIMIT_GS2LIMITWEBSOCKETCLIENT_HPP_
#define GS2_LIMIT_GS2LIMITWEBSOCKETCLIENT_HPP_

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
#include "request/DescribeCountersRequest.hpp"
#include "request/DescribeCountersByUserIdRequest.hpp"
#include "request/GetCounterRequest.hpp"
#include "request/GetCounterByUserIdRequest.hpp"
#include "request/CountUpRequest.hpp"
#include "request/CountUpByUserIdRequest.hpp"
#include "request/DeleteCounterByUserIdRequest.hpp"
#include "request/CountUpByStampTaskRequest.hpp"
#include "request/DeleteByStampSheetRequest.hpp"
#include "request/DescribeLimitModelMastersRequest.hpp"
#include "request/CreateLimitModelMasterRequest.hpp"
#include "request/GetLimitModelMasterRequest.hpp"
#include "request/UpdateLimitModelMasterRequest.hpp"
#include "request/DeleteLimitModelMasterRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentLimitMasterRequest.hpp"
#include "request/UpdateCurrentLimitMasterRequest.hpp"
#include "request/UpdateCurrentLimitMasterFromGitHubRequest.hpp"
#include "request/DescribeLimitModelsRequest.hpp"
#include "request/GetLimitModelRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeCountersResult.hpp"
#include "result/DescribeCountersByUserIdResult.hpp"
#include "result/GetCounterResult.hpp"
#include "result/GetCounterByUserIdResult.hpp"
#include "result/CountUpResult.hpp"
#include "result/CountUpByUserIdResult.hpp"
#include "result/DeleteCounterByUserIdResult.hpp"
#include "result/CountUpByStampTaskResult.hpp"
#include "result/DeleteByStampSheetResult.hpp"
#include "result/DescribeLimitModelMastersResult.hpp"
#include "result/CreateLimitModelMasterResult.hpp"
#include "result/GetLimitModelMasterResult.hpp"
#include "result/UpdateLimitModelMasterResult.hpp"
#include "result/DeleteLimitModelMasterResult.hpp"
#include "result/ExportMasterResult.hpp"
#include "result/GetCurrentLimitMasterResult.hpp"
#include "result/UpdateCurrentLimitMasterResult.hpp"
#include "result/UpdateCurrentLimitMasterFromGitHubResult.hpp"
#include "result/DescribeLimitModelsResult.hpp"
#include "result/GetLimitModelResult.hpp"
#include <cstring>

namespace gs2 { namespace limit {

/**
 * GS2 Limit API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2LimitWebSocketClient : public AbstractGs2ClientBase
{
private:

    class DescribeNamespacesTask : public detail::Gs2WebSocketSessionTask<DescribeNamespacesResult>
    {
    private:
        DescribeNamespacesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "limit";
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
            return "limit";
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
            return "limit";
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
            return "limit";
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
            return "limit";
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

    class DeleteNamespaceTask : public detail::Gs2WebSocketSessionTask<DeleteNamespaceResult>
    {
    private:
        DeleteNamespaceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "limit";
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

    class DescribeCountersTask : public detail::Gs2WebSocketSessionTask<DescribeCountersResult>
    {
    private:
        DescribeCountersRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "limit";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "counter";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeCounters";
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
            if (m_Request.getLimitName())
            {
                jsonWriter.writePropertyName("limitName");
                jsonWriter.writeCharArray(*m_Request.getLimitName());
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
        DescribeCountersTask(
            DescribeCountersRequest request,
            Gs2WebSocketSessionTask<DescribeCountersResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeCountersResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeCountersTask() GS2_OVERRIDE = default;
    };

    class DescribeCountersByUserIdTask : public detail::Gs2WebSocketSessionTask<DescribeCountersByUserIdResult>
    {
    private:
        DescribeCountersByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "limit";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "counter";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeCountersByUserId";
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
            if (m_Request.getLimitName())
            {
                jsonWriter.writePropertyName("limitName");
                jsonWriter.writeCharArray(*m_Request.getLimitName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
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
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        DescribeCountersByUserIdTask(
            DescribeCountersByUserIdRequest request,
            Gs2WebSocketSessionTask<DescribeCountersByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeCountersByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeCountersByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetCounterTask : public detail::Gs2WebSocketSessionTask<GetCounterResult>
    {
    private:
        GetCounterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "limit";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "counter";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getCounter";
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
            if (m_Request.getLimitName())
            {
                jsonWriter.writePropertyName("limitName");
                jsonWriter.writeCharArray(*m_Request.getLimitName());
            }
            if (m_Request.getCounterName())
            {
                jsonWriter.writePropertyName("counterName");
                jsonWriter.writeCharArray(*m_Request.getCounterName());
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
        GetCounterTask(
            GetCounterRequest request,
            Gs2WebSocketSessionTask<GetCounterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetCounterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetCounterTask() GS2_OVERRIDE = default;
    };

    class GetCounterByUserIdTask : public detail::Gs2WebSocketSessionTask<GetCounterByUserIdResult>
    {
    private:
        GetCounterByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "limit";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "counter";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getCounterByUserId";
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
            if (m_Request.getLimitName())
            {
                jsonWriter.writePropertyName("limitName");
                jsonWriter.writeCharArray(*m_Request.getLimitName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getCounterName())
            {
                jsonWriter.writePropertyName("counterName");
                jsonWriter.writeCharArray(*m_Request.getCounterName());
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
        GetCounterByUserIdTask(
            GetCounterByUserIdRequest request,
            Gs2WebSocketSessionTask<GetCounterByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetCounterByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetCounterByUserIdTask() GS2_OVERRIDE = default;
    };

    class CountUpTask : public detail::Gs2WebSocketSessionTask<CountUpResult>
    {
    private:
        CountUpRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "limit";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "counter";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "countUp";
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
            if (m_Request.getLimitName())
            {
                jsonWriter.writePropertyName("limitName");
                jsonWriter.writeCharArray(*m_Request.getLimitName());
            }
            if (m_Request.getCounterName())
            {
                jsonWriter.writePropertyName("counterName");
                jsonWriter.writeCharArray(*m_Request.getCounterName());
            }
            if (m_Request.getCountUpValue())
            {
                jsonWriter.writePropertyName("countUpValue");
                jsonWriter.writeInt32(*m_Request.getCountUpValue());
            }
            if (m_Request.getMaxValue())
            {
                jsonWriter.writePropertyName("maxValue");
                jsonWriter.writeInt32(*m_Request.getMaxValue());
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
        CountUpTask(
            CountUpRequest request,
            Gs2WebSocketSessionTask<CountUpResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CountUpResult>(callback),
            m_Request(std::move(request))
        {}

        ~CountUpTask() GS2_OVERRIDE = default;
    };

    class CountUpByUserIdTask : public detail::Gs2WebSocketSessionTask<CountUpByUserIdResult>
    {
    private:
        CountUpByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "limit";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "counter";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "countUpByUserId";
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
            if (m_Request.getLimitName())
            {
                jsonWriter.writePropertyName("limitName");
                jsonWriter.writeCharArray(*m_Request.getLimitName());
            }
            if (m_Request.getCounterName())
            {
                jsonWriter.writePropertyName("counterName");
                jsonWriter.writeCharArray(*m_Request.getCounterName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getCountUpValue())
            {
                jsonWriter.writePropertyName("countUpValue");
                jsonWriter.writeInt32(*m_Request.getCountUpValue());
            }
            if (m_Request.getMaxValue())
            {
                jsonWriter.writePropertyName("maxValue");
                jsonWriter.writeInt32(*m_Request.getMaxValue());
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
        CountUpByUserIdTask(
            CountUpByUserIdRequest request,
            Gs2WebSocketSessionTask<CountUpByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CountUpByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~CountUpByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteCounterByUserIdTask : public detail::Gs2WebSocketSessionTask<DeleteCounterByUserIdResult>
    {
    private:
        DeleteCounterByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "limit";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "counter";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteCounterByUserId";
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
            if (m_Request.getLimitName())
            {
                jsonWriter.writePropertyName("limitName");
                jsonWriter.writeCharArray(*m_Request.getLimitName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getCounterName())
            {
                jsonWriter.writePropertyName("counterName");
                jsonWriter.writeCharArray(*m_Request.getCounterName());
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
        DeleteCounterByUserIdTask(
            DeleteCounterByUserIdRequest request,
            Gs2WebSocketSessionTask<DeleteCounterByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteCounterByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteCounterByUserIdTask() GS2_OVERRIDE = default;
    };

    class CountUpByStampTaskTask : public detail::Gs2WebSocketSessionTask<CountUpByStampTaskResult>
    {
    private:
        CountUpByStampTaskRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "limit";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "counter";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "countUpByStampTask";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getStampTask())
            {
                jsonWriter.writePropertyName("stampTask");
                jsonWriter.writeCharArray(*m_Request.getStampTask());
            }
            if (m_Request.getKeyId())
            {
                jsonWriter.writePropertyName("keyId");
                jsonWriter.writeCharArray(*m_Request.getKeyId());
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
        CountUpByStampTaskTask(
            CountUpByStampTaskRequest request,
            Gs2WebSocketSessionTask<CountUpByStampTaskResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CountUpByStampTaskResult>(callback),
            m_Request(std::move(request))
        {}

        ~CountUpByStampTaskTask() GS2_OVERRIDE = default;
    };

    class DeleteByStampSheetTask : public detail::Gs2WebSocketSessionTask<DeleteByStampSheetResult>
    {
    private:
        DeleteByStampSheetRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "limit";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "counter";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteByStampSheet";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getStampSheet())
            {
                jsonWriter.writePropertyName("stampSheet");
                jsonWriter.writeCharArray(*m_Request.getStampSheet());
            }
            if (m_Request.getKeyId())
            {
                jsonWriter.writePropertyName("keyId");
                jsonWriter.writeCharArray(*m_Request.getKeyId());
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
        DeleteByStampSheetTask(
            DeleteByStampSheetRequest request,
            Gs2WebSocketSessionTask<DeleteByStampSheetResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteByStampSheetResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteByStampSheetTask() GS2_OVERRIDE = default;
    };

    class DescribeLimitModelMastersTask : public detail::Gs2WebSocketSessionTask<DescribeLimitModelMastersResult>
    {
    private:
        DescribeLimitModelMastersRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "limit";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "limitModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeLimitModelMasters";
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
        DescribeLimitModelMastersTask(
            DescribeLimitModelMastersRequest request,
            Gs2WebSocketSessionTask<DescribeLimitModelMastersResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeLimitModelMastersResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeLimitModelMastersTask() GS2_OVERRIDE = default;
    };

    class CreateLimitModelMasterTask : public detail::Gs2WebSocketSessionTask<CreateLimitModelMasterResult>
    {
    private:
        CreateLimitModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "limit";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "limitModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "createLimitModelMaster";
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
            if (m_Request.getResetType())
            {
                jsonWriter.writePropertyName("resetType");
                jsonWriter.writeCharArray(*m_Request.getResetType());
            }
            if (m_Request.getResetDayOfMonth())
            {
                jsonWriter.writePropertyName("resetDayOfMonth");
                jsonWriter.writeInt32(*m_Request.getResetDayOfMonth());
            }
            if (m_Request.getResetDayOfWeek())
            {
                jsonWriter.writePropertyName("resetDayOfWeek");
                jsonWriter.writeCharArray(*m_Request.getResetDayOfWeek());
            }
            if (m_Request.getResetHour())
            {
                jsonWriter.writePropertyName("resetHour");
                jsonWriter.writeInt32(*m_Request.getResetHour());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        CreateLimitModelMasterTask(
            CreateLimitModelMasterRequest request,
            Gs2WebSocketSessionTask<CreateLimitModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateLimitModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateLimitModelMasterTask() GS2_OVERRIDE = default;
    };

    class GetLimitModelMasterTask : public detail::Gs2WebSocketSessionTask<GetLimitModelMasterResult>
    {
    private:
        GetLimitModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "limit";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "limitModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getLimitModelMaster";
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
            if (m_Request.getLimitName())
            {
                jsonWriter.writePropertyName("limitName");
                jsonWriter.writeCharArray(*m_Request.getLimitName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetLimitModelMasterTask(
            GetLimitModelMasterRequest request,
            Gs2WebSocketSessionTask<GetLimitModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetLimitModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetLimitModelMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateLimitModelMasterTask : public detail::Gs2WebSocketSessionTask<UpdateLimitModelMasterResult>
    {
    private:
        UpdateLimitModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "limit";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "limitModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateLimitModelMaster";
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
            if (m_Request.getLimitName())
            {
                jsonWriter.writePropertyName("limitName");
                jsonWriter.writeCharArray(*m_Request.getLimitName());
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
            if (m_Request.getResetType())
            {
                jsonWriter.writePropertyName("resetType");
                jsonWriter.writeCharArray(*m_Request.getResetType());
            }
            if (m_Request.getResetDayOfMonth())
            {
                jsonWriter.writePropertyName("resetDayOfMonth");
                jsonWriter.writeInt32(*m_Request.getResetDayOfMonth());
            }
            if (m_Request.getResetDayOfWeek())
            {
                jsonWriter.writePropertyName("resetDayOfWeek");
                jsonWriter.writeCharArray(*m_Request.getResetDayOfWeek());
            }
            if (m_Request.getResetHour())
            {
                jsonWriter.writePropertyName("resetHour");
                jsonWriter.writeInt32(*m_Request.getResetHour());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        UpdateLimitModelMasterTask(
            UpdateLimitModelMasterRequest request,
            Gs2WebSocketSessionTask<UpdateLimitModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateLimitModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateLimitModelMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteLimitModelMasterTask : public detail::Gs2WebSocketSessionTask<DeleteLimitModelMasterResult>
    {
    private:
        DeleteLimitModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "limit";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "limitModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteLimitModelMaster";
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
            if (m_Request.getLimitName())
            {
                jsonWriter.writePropertyName("limitName");
                jsonWriter.writeCharArray(*m_Request.getLimitName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        DeleteLimitModelMasterTask(
            DeleteLimitModelMasterRequest request,
            Gs2WebSocketSessionTask<DeleteLimitModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteLimitModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteLimitModelMasterTask() GS2_OVERRIDE = default;
    };

    class ExportMasterTask : public detail::Gs2WebSocketSessionTask<ExportMasterResult>
    {
    private:
        ExportMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "limit";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "currentLimitMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "exportMaster";
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
        ExportMasterTask(
            ExportMasterRequest request,
            Gs2WebSocketSessionTask<ExportMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<ExportMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~ExportMasterTask() GS2_OVERRIDE = default;
    };

    class GetCurrentLimitMasterTask : public detail::Gs2WebSocketSessionTask<GetCurrentLimitMasterResult>
    {
    private:
        GetCurrentLimitMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "limit";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "currentLimitMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getCurrentLimitMaster";
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
        GetCurrentLimitMasterTask(
            GetCurrentLimitMasterRequest request,
            Gs2WebSocketSessionTask<GetCurrentLimitMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetCurrentLimitMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetCurrentLimitMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentLimitMasterTask : public detail::Gs2WebSocketSessionTask<UpdateCurrentLimitMasterResult>
    {
    private:
        UpdateCurrentLimitMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "limit";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "currentLimitMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateCurrentLimitMaster";
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
            if (m_Request.getSettings())
            {
                jsonWriter.writePropertyName("settings");
                jsonWriter.writeCharArray(*m_Request.getSettings());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        UpdateCurrentLimitMasterTask(
            UpdateCurrentLimitMasterRequest request,
            Gs2WebSocketSessionTask<UpdateCurrentLimitMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateCurrentLimitMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateCurrentLimitMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentLimitMasterFromGitHubTask : public detail::Gs2WebSocketSessionTask<UpdateCurrentLimitMasterFromGitHubResult>
    {
    private:
        UpdateCurrentLimitMasterFromGitHubRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "limit";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "currentLimitMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateCurrentLimitMasterFromGitHub";
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
        UpdateCurrentLimitMasterFromGitHubTask(
            UpdateCurrentLimitMasterFromGitHubRequest request,
            Gs2WebSocketSessionTask<UpdateCurrentLimitMasterFromGitHubResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateCurrentLimitMasterFromGitHubResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateCurrentLimitMasterFromGitHubTask() GS2_OVERRIDE = default;
    };

    class DescribeLimitModelsTask : public detail::Gs2WebSocketSessionTask<DescribeLimitModelsResult>
    {
    private:
        DescribeLimitModelsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "limit";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "limitModel";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeLimitModels";
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
        DescribeLimitModelsTask(
            DescribeLimitModelsRequest request,
            Gs2WebSocketSessionTask<DescribeLimitModelsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeLimitModelsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeLimitModelsTask() GS2_OVERRIDE = default;
    };

    class GetLimitModelTask : public detail::Gs2WebSocketSessionTask<GetLimitModelResult>
    {
    private:
        GetLimitModelRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "limit";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "limitModel";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getLimitModel";
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
            if (m_Request.getLimitName())
            {
                jsonWriter.writePropertyName("limitName");
                jsonWriter.writeCharArray(*m_Request.getLimitName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetLimitModelTask(
            GetLimitModelRequest request,
            Gs2WebSocketSessionTask<GetLimitModelResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetLimitModelResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetLimitModelTask() GS2_OVERRIDE = default;
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

    static void write(detail::json::JsonWriter& jsonWriter, const Counter& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getCounterId())
        {
            jsonWriter.writePropertyName("counterId");
            jsonWriter.writeCharArray(*obj.getCounterId());
        }
        if (obj.getLimitName())
        {
            jsonWriter.writePropertyName("limitName");
            jsonWriter.writeCharArray(*obj.getLimitName());
        }
        if (obj.getName())
        {
            jsonWriter.writePropertyName("name");
            jsonWriter.writeCharArray(*obj.getName());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getCount())
        {
            jsonWriter.writePropertyName("count");
            jsonWriter.writeInt32(*obj.getCount());
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

    static void write(detail::json::JsonWriter& jsonWriter, const LimitModelMaster& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getLimitModelId())
        {
            jsonWriter.writePropertyName("limitModelId");
            jsonWriter.writeCharArray(*obj.getLimitModelId());
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
        if (obj.getResetType())
        {
            jsonWriter.writePropertyName("resetType");
            jsonWriter.writeCharArray(*obj.getResetType());
        }
        if (obj.getResetDayOfMonth())
        {
            jsonWriter.writePropertyName("resetDayOfMonth");
            jsonWriter.writeInt32(*obj.getResetDayOfMonth());
        }
        if (obj.getResetDayOfWeek())
        {
            jsonWriter.writePropertyName("resetDayOfWeek");
            jsonWriter.writeCharArray(*obj.getResetDayOfWeek());
        }
        if (obj.getResetHour())
        {
            jsonWriter.writePropertyName("resetHour");
            jsonWriter.writeInt32(*obj.getResetHour());
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

    static void write(detail::json::JsonWriter& jsonWriter, const CurrentLimitMaster& obj)
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
        if (obj.getCreatedAt())
        {
            jsonWriter.writePropertyName("createdAt");
            jsonWriter.writeInt64(*obj.getCreatedAt());
        }
        if (obj.getExpiredAt())
        {
            jsonWriter.writePropertyName("expiredAt");
            jsonWriter.writeInt64(*obj.getExpiredAt());
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

    static void write(detail::json::JsonWriter& jsonWriter, const LimitModel& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getLimitModelId())
        {
            jsonWriter.writePropertyName("limitModelId");
            jsonWriter.writeCharArray(*obj.getLimitModelId());
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
        if (obj.getResetType())
        {
            jsonWriter.writePropertyName("resetType");
            jsonWriter.writeCharArray(*obj.getResetType());
        }
        if (obj.getResetDayOfMonth())
        {
            jsonWriter.writePropertyName("resetDayOfMonth");
            jsonWriter.writeInt32(*obj.getResetDayOfMonth());
        }
        if (obj.getResetDayOfWeek())
        {
            jsonWriter.writePropertyName("resetDayOfWeek");
            jsonWriter.writeCharArray(*obj.getResetDayOfWeek());
        }
        if (obj.getResetHour())
        {
            jsonWriter.writePropertyName("resetHour");
            jsonWriter.writeInt32(*obj.getResetHour());
        }
        jsonWriter.writeObjectEnd();
    }


public:
    /**
     * コンストラクタ。
     *
     * @param gs2WebSocketSession WebSocket API 用セッション
     */
    explicit Gs2LimitWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
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
	 * カウンターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCounters(DescribeCountersRequest request, std::function<void(AsyncDescribeCountersResult)> callback)
    {
        DescribeCountersTask& task = *new DescribeCountersTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * カウンターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCountersByUserId(DescribeCountersByUserIdRequest request, std::function<void(AsyncDescribeCountersByUserIdResult)> callback)
    {
        DescribeCountersByUserIdTask& task = *new DescribeCountersByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * カウンターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCounter(GetCounterRequest request, std::function<void(AsyncGetCounterResult)> callback)
    {
        GetCounterTask& task = *new GetCounterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザIDを指定してカウンターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCounterByUserId(GetCounterByUserIdRequest request, std::function<void(AsyncGetCounterByUserIdResult)> callback)
    {
        GetCounterByUserIdTask& task = *new GetCounterByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * カウントアップ<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void countUp(CountUpRequest request, std::function<void(AsyncCountUpResult)> callback)
    {
        CountUpTask& task = *new CountUpTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザIDを指定してカウントアップ<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void countUpByUserId(CountUpByUserIdRequest request, std::function<void(AsyncCountUpByUserIdResult)> callback)
    {
        CountUpByUserIdTask& task = *new CountUpByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザIDを指定してカウンターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteCounterByUserId(DeleteCounterByUserIdRequest request, std::function<void(AsyncDeleteCounterByUserIdResult)> callback)
    {
        DeleteCounterByUserIdTask& task = *new DeleteCounterByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * スタンプシートでカウントアップ<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void countUpByStampTask(CountUpByStampTaskRequest request, std::function<void(AsyncCountUpByStampTaskResult)> callback)
    {
        CountUpByStampTaskTask& task = *new CountUpByStampTaskTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * スタンプシートでカウンターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteByStampSheet(DeleteByStampSheetRequest request, std::function<void(AsyncDeleteByStampSheetResult)> callback)
    {
        DeleteByStampSheetTask& task = *new DeleteByStampSheetTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 回数制限の種類マスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeLimitModelMasters(DescribeLimitModelMastersRequest request, std::function<void(AsyncDescribeLimitModelMastersResult)> callback)
    {
        DescribeLimitModelMastersTask& task = *new DescribeLimitModelMastersTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 回数制限の種類マスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createLimitModelMaster(CreateLimitModelMasterRequest request, std::function<void(AsyncCreateLimitModelMasterResult)> callback)
    {
        CreateLimitModelMasterTask& task = *new CreateLimitModelMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 回数制限の種類マスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getLimitModelMaster(GetLimitModelMasterRequest request, std::function<void(AsyncGetLimitModelMasterResult)> callback)
    {
        GetLimitModelMasterTask& task = *new GetLimitModelMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 回数制限の種類マスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateLimitModelMaster(UpdateLimitModelMasterRequest request, std::function<void(AsyncUpdateLimitModelMasterResult)> callback)
    {
        UpdateLimitModelMasterTask& task = *new UpdateLimitModelMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 回数制限の種類マスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteLimitModelMaster(DeleteLimitModelMasterRequest request, std::function<void(AsyncDeleteLimitModelMasterResult)> callback)
    {
        DeleteLimitModelMasterTask& task = *new DeleteLimitModelMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 現在有効な回数制限設定のマスターデータをエクスポートします<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void exportMaster(ExportMasterRequest request, std::function<void(AsyncExportMasterResult)> callback)
    {
        ExportMasterTask& task = *new ExportMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 現在有効な回数制限設定を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentLimitMaster(GetCurrentLimitMasterRequest request, std::function<void(AsyncGetCurrentLimitMasterResult)> callback)
    {
        GetCurrentLimitMasterTask& task = *new GetCurrentLimitMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 現在有効な回数制限設定を更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentLimitMaster(UpdateCurrentLimitMasterRequest request, std::function<void(AsyncUpdateCurrentLimitMasterResult)> callback)
    {
        UpdateCurrentLimitMasterTask& task = *new UpdateCurrentLimitMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 現在有効な回数制限設定を更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentLimitMasterFromGitHub(UpdateCurrentLimitMasterFromGitHubRequest request, std::function<void(AsyncUpdateCurrentLimitMasterFromGitHubResult)> callback)
    {
        UpdateCurrentLimitMasterFromGitHubTask& task = *new UpdateCurrentLimitMasterFromGitHubTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 回数制限の種類の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeLimitModels(DescribeLimitModelsRequest request, std::function<void(AsyncDescribeLimitModelsResult)> callback)
    {
        DescribeLimitModelsTask& task = *new DescribeLimitModelsTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 回数制限の種類を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getLimitModel(GetLimitModelRequest request, std::function<void(AsyncGetLimitModelResult)> callback)
    {
        GetLimitModelTask& task = *new GetLimitModelTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_LIMIT_GS2LIMITWEBSOCKETCLIENT_HPP_