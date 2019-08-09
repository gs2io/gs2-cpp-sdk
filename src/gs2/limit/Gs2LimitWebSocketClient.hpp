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
#include <gs2/core/util/UrlEncoder.hpp>
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

typedef AsyncResult<DescribeNamespacesResult> AsyncDescribeNamespacesResult;
typedef AsyncResult<CreateNamespaceResult> AsyncCreateNamespaceResult;
typedef AsyncResult<GetNamespaceStatusResult> AsyncGetNamespaceStatusResult;
typedef AsyncResult<GetNamespaceResult> AsyncGetNamespaceResult;
typedef AsyncResult<UpdateNamespaceResult> AsyncUpdateNamespaceResult;
typedef AsyncResult<DeleteNamespaceResult> AsyncDeleteNamespaceResult;
typedef AsyncResult<DescribeCountersResult> AsyncDescribeCountersResult;
typedef AsyncResult<DescribeCountersByUserIdResult> AsyncDescribeCountersByUserIdResult;
typedef AsyncResult<GetCounterResult> AsyncGetCounterResult;
typedef AsyncResult<GetCounterByUserIdResult> AsyncGetCounterByUserIdResult;
typedef AsyncResult<CountUpByUserIdResult> AsyncCountUpByUserIdResult;
typedef AsyncResult<DeleteCounterByUserIdResult> AsyncDeleteCounterByUserIdResult;
typedef AsyncResult<CountUpByStampTaskResult> AsyncCountUpByStampTaskResult;
typedef AsyncResult<DeleteByStampSheetResult> AsyncDeleteByStampSheetResult;
typedef AsyncResult<DescribeLimitModelMastersResult> AsyncDescribeLimitModelMastersResult;
typedef AsyncResult<CreateLimitModelMasterResult> AsyncCreateLimitModelMasterResult;
typedef AsyncResult<GetLimitModelMasterResult> AsyncGetLimitModelMasterResult;
typedef AsyncResult<UpdateLimitModelMasterResult> AsyncUpdateLimitModelMasterResult;
typedef AsyncResult<DeleteLimitModelMasterResult> AsyncDeleteLimitModelMasterResult;
typedef AsyncResult<ExportMasterResult> AsyncExportMasterResult;
typedef AsyncResult<GetCurrentLimitMasterResult> AsyncGetCurrentLimitMasterResult;
typedef AsyncResult<UpdateCurrentLimitMasterResult> AsyncUpdateCurrentLimitMasterResult;
typedef AsyncResult<UpdateCurrentLimitMasterFromGitHubResult> AsyncUpdateCurrentLimitMasterFromGitHubResult;
typedef AsyncResult<DescribeLimitModelsResult> AsyncDescribeLimitModelsResult;
typedef AsyncResult<GetLimitModelResult> AsyncGetLimitModelResult;

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
        DescribeNamespacesRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

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

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("limit");
            writer.writePropertyName("component");
            writer.writeCharArray("namespace");
            writer.writePropertyName("function");
            writer.writeCharArray("describeNamespaces");
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
        DescribeNamespacesTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeNamespacesRequest& request,
            Gs2WebSocketSessionTask<DescribeNamespacesResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeNamespacesResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeNamespacesTask() GS2_OVERRIDE = default;
    };

    class CreateNamespaceTask : public detail::Gs2WebSocketSessionTask<CreateNamespaceResult>
    {
    private:
        CreateNamespaceRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

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

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("limit");
            writer.writePropertyName("component");
            writer.writeCharArray("namespace");
            writer.writePropertyName("function");
            writer.writeCharArray("createNamespace");
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
        CreateNamespaceTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            CreateNamespaceRequest& request,
            Gs2WebSocketSessionTask<CreateNamespaceResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateNamespaceResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~CreateNamespaceTask() GS2_OVERRIDE = default;
    };

    class GetNamespaceStatusTask : public detail::Gs2WebSocketSessionTask<GetNamespaceStatusResult>
    {
    private:
        GetNamespaceStatusRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("limit");
            writer.writePropertyName("component");
            writer.writeCharArray("namespace");
            writer.writePropertyName("function");
            writer.writeCharArray("getNamespaceStatus");
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
        GetNamespaceStatusTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetNamespaceStatusRequest& request,
            Gs2WebSocketSessionTask<GetNamespaceStatusResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetNamespaceStatusResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetNamespaceStatusTask() GS2_OVERRIDE = default;
    };

    class GetNamespaceTask : public detail::Gs2WebSocketSessionTask<GetNamespaceResult>
    {
    private:
        GetNamespaceRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("limit");
            writer.writePropertyName("component");
            writer.writeCharArray("namespace");
            writer.writePropertyName("function");
            writer.writeCharArray("getNamespace");
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
        GetNamespaceTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetNamespaceRequest& request,
            Gs2WebSocketSessionTask<GetNamespaceResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetNamespaceResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetNamespaceTask() GS2_OVERRIDE = default;
    };

    class UpdateNamespaceTask : public detail::Gs2WebSocketSessionTask<UpdateNamespaceResult>
    {
    private:
        UpdateNamespaceRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
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

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("limit");
            writer.writePropertyName("component");
            writer.writeCharArray("namespace");
            writer.writePropertyName("function");
            writer.writeCharArray("updateNamespace");
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
        UpdateNamespaceTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateNamespaceRequest& request,
            Gs2WebSocketSessionTask<UpdateNamespaceResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateNamespaceResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateNamespaceTask() GS2_OVERRIDE = default;
    };

    class DeleteNamespaceTask : public detail::Gs2WebSocketSessionTask<DeleteNamespaceResult>
    {
    private:
        DeleteNamespaceRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("limit");
            writer.writePropertyName("component");
            writer.writeCharArray("namespace");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteNamespace");
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
        DeleteNamespaceTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteNamespaceRequest& request,
            Gs2WebSocketSessionTask<DeleteNamespaceResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteNamespaceResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteNamespaceTask() GS2_OVERRIDE = default;
    };

    class DescribeCountersTask : public detail::Gs2WebSocketSessionTask<DescribeCountersResult>
    {
    private:
        DescribeCountersRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getLimitName())
            {
                writer.writePropertyName("limitName");
                writer.writeCharArray(*m_Request.getLimitName());
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
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("limit");
            writer.writePropertyName("component");
            writer.writeCharArray("counter");
            writer.writePropertyName("function");
            writer.writeCharArray("describeCounters");
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
        DescribeCountersTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeCountersRequest& request,
            Gs2WebSocketSessionTask<DescribeCountersResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeCountersResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeCountersTask() GS2_OVERRIDE = default;
    };

    class DescribeCountersByUserIdTask : public detail::Gs2WebSocketSessionTask<DescribeCountersByUserIdResult>
    {
    private:
        DescribeCountersByUserIdRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getLimitName())
            {
                writer.writePropertyName("limitName");
                writer.writeCharArray(*m_Request.getLimitName());
            }
            if (m_Request.getUserId())
            {
                writer.writePropertyName("userId");
                writer.writeCharArray(*m_Request.getUserId());
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
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("limit");
            writer.writePropertyName("component");
            writer.writeCharArray("counter");
            writer.writePropertyName("function");
            writer.writeCharArray("describeCountersByUserId");
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
        DescribeCountersByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeCountersByUserIdRequest& request,
            Gs2WebSocketSessionTask<DescribeCountersByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeCountersByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeCountersByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetCounterTask : public detail::Gs2WebSocketSessionTask<GetCounterResult>
    {
    private:
        GetCounterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getLimitName())
            {
                writer.writePropertyName("limitName");
                writer.writeCharArray(*m_Request.getLimitName());
            }
            if (m_Request.getCounterName())
            {
                writer.writePropertyName("counterName");
                writer.writeCharArray(*m_Request.getCounterName());
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
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("limit");
            writer.writePropertyName("component");
            writer.writeCharArray("counter");
            writer.writePropertyName("function");
            writer.writeCharArray("getCounter");
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
        GetCounterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetCounterRequest& request,
            Gs2WebSocketSessionTask<GetCounterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetCounterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetCounterTask() GS2_OVERRIDE = default;
    };

    class GetCounterByUserIdTask : public detail::Gs2WebSocketSessionTask<GetCounterByUserIdResult>
    {
    private:
        GetCounterByUserIdRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getLimitName())
            {
                writer.writePropertyName("limitName");
                writer.writeCharArray(*m_Request.getLimitName());
            }
            if (m_Request.getUserId())
            {
                writer.writePropertyName("userId");
                writer.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getCounterName())
            {
                writer.writePropertyName("counterName");
                writer.writeCharArray(*m_Request.getCounterName());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("limit");
            writer.writePropertyName("component");
            writer.writeCharArray("counter");
            writer.writePropertyName("function");
            writer.writeCharArray("getCounterByUserId");
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
        GetCounterByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetCounterByUserIdRequest& request,
            Gs2WebSocketSessionTask<GetCounterByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetCounterByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetCounterByUserIdTask() GS2_OVERRIDE = default;
    };

    class CountUpByUserIdTask : public detail::Gs2WebSocketSessionTask<CountUpByUserIdResult>
    {
    private:
        CountUpByUserIdRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getLimitName())
            {
                writer.writePropertyName("limitName");
                writer.writeCharArray(*m_Request.getLimitName());
            }
            if (m_Request.getCounterName())
            {
                writer.writePropertyName("counterName");
                writer.writeCharArray(*m_Request.getCounterName());
            }
            if (m_Request.getUserId())
            {
                writer.writePropertyName("userId");
                writer.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getCountUpValue())
            {
                writer.writePropertyName("countUpValue");
                writer.writeInt32(*m_Request.getCountUpValue());
            }
            if (m_Request.getMaxValue())
            {
                writer.writePropertyName("maxValue");
                writer.writeInt32(*m_Request.getMaxValue());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("limit");
            writer.writePropertyName("component");
            writer.writeCharArray("counter");
            writer.writePropertyName("function");
            writer.writeCharArray("countUpByUserId");
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
        CountUpByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            CountUpByUserIdRequest& request,
            Gs2WebSocketSessionTask<CountUpByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CountUpByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~CountUpByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteCounterByUserIdTask : public detail::Gs2WebSocketSessionTask<DeleteCounterByUserIdResult>
    {
    private:
        DeleteCounterByUserIdRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getLimitName())
            {
                writer.writePropertyName("limitName");
                writer.writeCharArray(*m_Request.getLimitName());
            }
            if (m_Request.getUserId())
            {
                writer.writePropertyName("userId");
                writer.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getCounterName())
            {
                writer.writePropertyName("counterName");
                writer.writeCharArray(*m_Request.getCounterName());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("limit");
            writer.writePropertyName("component");
            writer.writeCharArray("counter");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteCounterByUserId");
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
        DeleteCounterByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteCounterByUserIdRequest& request,
            Gs2WebSocketSessionTask<DeleteCounterByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteCounterByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteCounterByUserIdTask() GS2_OVERRIDE = default;
    };

    class CountUpByStampTaskTask : public detail::Gs2WebSocketSessionTask<CountUpByStampTaskResult>
    {
    private:
        CountUpByStampTaskRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getStampTask())
            {
                writer.writePropertyName("stampTask");
                writer.writeCharArray(*m_Request.getStampTask());
            }
            if (m_Request.getKeyId())
            {
                writer.writePropertyName("keyId");
                writer.writeCharArray(*m_Request.getKeyId());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("limit");
            writer.writePropertyName("component");
            writer.writeCharArray("counter");
            writer.writePropertyName("function");
            writer.writeCharArray("countUpByStampTask");
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
        CountUpByStampTaskTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            CountUpByStampTaskRequest& request,
            Gs2WebSocketSessionTask<CountUpByStampTaskResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CountUpByStampTaskResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~CountUpByStampTaskTask() GS2_OVERRIDE = default;
    };

    class DeleteByStampSheetTask : public detail::Gs2WebSocketSessionTask<DeleteByStampSheetResult>
    {
    private:
        DeleteByStampSheetRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getStampSheet())
            {
                writer.writePropertyName("stampSheet");
                writer.writeCharArray(*m_Request.getStampSheet());
            }
            if (m_Request.getKeyId())
            {
                writer.writePropertyName("keyId");
                writer.writeCharArray(*m_Request.getKeyId());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("limit");
            writer.writePropertyName("component");
            writer.writeCharArray("counter");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteByStampSheet");
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
        DeleteByStampSheetTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteByStampSheetRequest& request,
            Gs2WebSocketSessionTask<DeleteByStampSheetResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteByStampSheetResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteByStampSheetTask() GS2_OVERRIDE = default;
    };

    class DescribeLimitModelMastersTask : public detail::Gs2WebSocketSessionTask<DescribeLimitModelMastersResult>
    {
    private:
        DescribeLimitModelMastersRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
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

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("limit");
            writer.writePropertyName("component");
            writer.writeCharArray("limitModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("describeLimitModelMasters");
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
        DescribeLimitModelMastersTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeLimitModelMastersRequest& request,
            Gs2WebSocketSessionTask<DescribeLimitModelMastersResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeLimitModelMastersResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeLimitModelMastersTask() GS2_OVERRIDE = default;
    };

    class CreateLimitModelMasterTask : public detail::Gs2WebSocketSessionTask<CreateLimitModelMasterResult>
    {
    private:
        CreateLimitModelMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
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
            if (m_Request.getMetadata())
            {
                writer.writePropertyName("metadata");
                writer.writeCharArray(*m_Request.getMetadata());
            }
            if (m_Request.getResetType())
            {
                writer.writePropertyName("resetType");
                writer.writeCharArray(*m_Request.getResetType());
            }
            if (m_Request.getResetDayOfMonth())
            {
                writer.writePropertyName("resetDayOfMonth");
                writer.writeInt32(*m_Request.getResetDayOfMonth());
            }
            if (m_Request.getResetDayOfWeek())
            {
                writer.writePropertyName("resetDayOfWeek");
                writer.writeCharArray(*m_Request.getResetDayOfWeek());
            }
            if (m_Request.getResetHour())
            {
                writer.writePropertyName("resetHour");
                writer.writeInt32(*m_Request.getResetHour());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("limit");
            writer.writePropertyName("component");
            writer.writeCharArray("limitModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("createLimitModelMaster");
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
        CreateLimitModelMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            CreateLimitModelMasterRequest& request,
            Gs2WebSocketSessionTask<CreateLimitModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateLimitModelMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~CreateLimitModelMasterTask() GS2_OVERRIDE = default;
    };

    class GetLimitModelMasterTask : public detail::Gs2WebSocketSessionTask<GetLimitModelMasterResult>
    {
    private:
        GetLimitModelMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getLimitName())
            {
                writer.writePropertyName("limitName");
                writer.writeCharArray(*m_Request.getLimitName());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("limit");
            writer.writePropertyName("component");
            writer.writeCharArray("limitModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("getLimitModelMaster");
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
        GetLimitModelMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetLimitModelMasterRequest& request,
            Gs2WebSocketSessionTask<GetLimitModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetLimitModelMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetLimitModelMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateLimitModelMasterTask : public detail::Gs2WebSocketSessionTask<UpdateLimitModelMasterResult>
    {
    private:
        UpdateLimitModelMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getLimitName())
            {
                writer.writePropertyName("limitName");
                writer.writeCharArray(*m_Request.getLimitName());
            }
            if (m_Request.getDescription())
            {
                writer.writePropertyName("description");
                writer.writeCharArray(*m_Request.getDescription());
            }
            if (m_Request.getMetadata())
            {
                writer.writePropertyName("metadata");
                writer.writeCharArray(*m_Request.getMetadata());
            }
            if (m_Request.getResetType())
            {
                writer.writePropertyName("resetType");
                writer.writeCharArray(*m_Request.getResetType());
            }
            if (m_Request.getResetDayOfMonth())
            {
                writer.writePropertyName("resetDayOfMonth");
                writer.writeInt32(*m_Request.getResetDayOfMonth());
            }
            if (m_Request.getResetDayOfWeek())
            {
                writer.writePropertyName("resetDayOfWeek");
                writer.writeCharArray(*m_Request.getResetDayOfWeek());
            }
            if (m_Request.getResetHour())
            {
                writer.writePropertyName("resetHour");
                writer.writeInt32(*m_Request.getResetHour());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("limit");
            writer.writePropertyName("component");
            writer.writeCharArray("limitModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("updateLimitModelMaster");
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
        UpdateLimitModelMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateLimitModelMasterRequest& request,
            Gs2WebSocketSessionTask<UpdateLimitModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateLimitModelMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateLimitModelMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteLimitModelMasterTask : public detail::Gs2WebSocketSessionTask<DeleteLimitModelMasterResult>
    {
    private:
        DeleteLimitModelMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getLimitName())
            {
                writer.writePropertyName("limitName");
                writer.writeCharArray(*m_Request.getLimitName());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("limit");
            writer.writePropertyName("component");
            writer.writeCharArray("limitModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteLimitModelMaster");
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
        DeleteLimitModelMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteLimitModelMasterRequest& request,
            Gs2WebSocketSessionTask<DeleteLimitModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteLimitModelMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteLimitModelMasterTask() GS2_OVERRIDE = default;
    };

    class ExportMasterTask : public detail::Gs2WebSocketSessionTask<ExportMasterResult>
    {
    private:
        ExportMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("limit");
            writer.writePropertyName("component");
            writer.writeCharArray("currentLimitMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("exportMaster");
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
        ExportMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            ExportMasterRequest& request,
            Gs2WebSocketSessionTask<ExportMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<ExportMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~ExportMasterTask() GS2_OVERRIDE = default;
    };

    class GetCurrentLimitMasterTask : public detail::Gs2WebSocketSessionTask<GetCurrentLimitMasterResult>
    {
    private:
        GetCurrentLimitMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("limit");
            writer.writePropertyName("component");
            writer.writeCharArray("currentLimitMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("getCurrentLimitMaster");
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
        GetCurrentLimitMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetCurrentLimitMasterRequest& request,
            Gs2WebSocketSessionTask<GetCurrentLimitMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetCurrentLimitMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetCurrentLimitMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentLimitMasterTask : public detail::Gs2WebSocketSessionTask<UpdateCurrentLimitMasterResult>
    {
    private:
        UpdateCurrentLimitMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getSettings())
            {
                writer.writePropertyName("settings");
                writer.writeCharArray(*m_Request.getSettings());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("limit");
            writer.writePropertyName("component");
            writer.writeCharArray("currentLimitMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("updateCurrentLimitMaster");
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
        UpdateCurrentLimitMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateCurrentLimitMasterRequest& request,
            Gs2WebSocketSessionTask<UpdateCurrentLimitMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateCurrentLimitMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateCurrentLimitMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentLimitMasterFromGitHubTask : public detail::Gs2WebSocketSessionTask<UpdateCurrentLimitMasterFromGitHubResult>
    {
    private:
        UpdateCurrentLimitMasterFromGitHubRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getCheckoutSetting())
            {
                writer.writePropertyName("checkoutSetting");
                write(writer, *m_Request.getCheckoutSetting());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("limit");
            writer.writePropertyName("component");
            writer.writeCharArray("currentLimitMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("updateCurrentLimitMasterFromGitHub");
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
        UpdateCurrentLimitMasterFromGitHubTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateCurrentLimitMasterFromGitHubRequest& request,
            Gs2WebSocketSessionTask<UpdateCurrentLimitMasterFromGitHubResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateCurrentLimitMasterFromGitHubResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateCurrentLimitMasterFromGitHubTask() GS2_OVERRIDE = default;
    };

    class DescribeLimitModelsTask : public detail::Gs2WebSocketSessionTask<DescribeLimitModelsResult>
    {
    private:
        DescribeLimitModelsRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("limit");
            writer.writePropertyName("component");
            writer.writeCharArray("limitModel");
            writer.writePropertyName("function");
            writer.writeCharArray("describeLimitModels");
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
        DescribeLimitModelsTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeLimitModelsRequest& request,
            Gs2WebSocketSessionTask<DescribeLimitModelsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeLimitModelsResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeLimitModelsTask() GS2_OVERRIDE = default;
    };

    class GetLimitModelTask : public detail::Gs2WebSocketSessionTask<GetLimitModelResult>
    {
    private:
        GetLimitModelRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getLimitName())
            {
                writer.writePropertyName("limitName");
                writer.writeCharArray(*m_Request.getLimitName());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("limit");
            writer.writePropertyName("component");
            writer.writeCharArray("limitModel");
            writer.writePropertyName("function");
            writer.writeCharArray("getLimitModel");
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
        GetLimitModelTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetLimitModelRequest& request,
            Gs2WebSocketSessionTask<GetLimitModelResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetLimitModelResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetLimitModelTask() GS2_OVERRIDE = default;
    };

private:
    static void write(detail::json::JsonWriter& writer, const Namespace& obj)
    {
        writer.writeObjectStart();
        if (obj.getNamespaceId())
        {
            writer.writePropertyName("namespaceId");
            writer.writeCharArray(*obj.getNamespaceId());
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

    static void write(detail::json::JsonWriter& writer, const Counter& obj)
    {
        writer.writeObjectStart();
        if (obj.getCounterId())
        {
            writer.writePropertyName("counterId");
            writer.writeCharArray(*obj.getCounterId());
        }
        if (obj.getLimitName())
        {
            writer.writePropertyName("limitName");
            writer.writeCharArray(*obj.getLimitName());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*obj.getName());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.writeCharArray(*obj.getUserId());
        }
        if (obj.getCount())
        {
            writer.writePropertyName("count");
            writer.writeInt32(*obj.getCount());
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

    static void write(detail::json::JsonWriter& writer, const LimitModelMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getLimitModelId())
        {
            writer.writePropertyName("limitModelId");
            writer.writeCharArray(*obj.getLimitModelId());
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
        if (obj.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.writeCharArray(*obj.getMetadata());
        }
        if (obj.getResetType())
        {
            writer.writePropertyName("resetType");
            writer.writeCharArray(*obj.getResetType());
        }
        if (obj.getResetDayOfMonth())
        {
            writer.writePropertyName("resetDayOfMonth");
            writer.writeInt32(*obj.getResetDayOfMonth());
        }
        if (obj.getResetDayOfWeek())
        {
            writer.writePropertyName("resetDayOfWeek");
            writer.writeCharArray(*obj.getResetDayOfWeek());
        }
        if (obj.getResetHour())
        {
            writer.writePropertyName("resetHour");
            writer.writeInt32(*obj.getResetHour());
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

    static void write(detail::json::JsonWriter& writer, const CurrentLimitMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getNamespaceName())
        {
            writer.writePropertyName("namespaceName");
            writer.writeCharArray(*obj.getNamespaceName());
        }
        if (obj.getSettings())
        {
            writer.writePropertyName("settings");
            writer.writeCharArray(*obj.getSettings());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const ResponseCache& obj)
    {
        writer.writeObjectStart();
        if (obj.getRegion())
        {
            writer.writePropertyName("region");
            writer.writeCharArray(*obj.getRegion());
        }
        if (obj.getOwnerId())
        {
            writer.writePropertyName("ownerId");
            writer.writeCharArray(*obj.getOwnerId());
        }
        if (obj.getResponseCacheId())
        {
            writer.writePropertyName("responseCacheId");
            writer.writeCharArray(*obj.getResponseCacheId());
        }
        if (obj.getRequestHash())
        {
            writer.writePropertyName("requestHash");
            writer.writeCharArray(*obj.getRequestHash());
        }
        if (obj.getResult())
        {
            writer.writePropertyName("result");
            writer.writeCharArray(*obj.getResult());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const GitHubCheckoutSetting& obj)
    {
        writer.writeObjectStart();
        if (obj.getGitHubApiKeyId())
        {
            writer.writePropertyName("gitHubApiKeyId");
            writer.writeCharArray(*obj.getGitHubApiKeyId());
        }
        if (obj.getRepositoryName())
        {
            writer.writePropertyName("repositoryName");
            writer.writeCharArray(*obj.getRepositoryName());
        }
        if (obj.getSourcePath())
        {
            writer.writePropertyName("sourcePath");
            writer.writeCharArray(*obj.getSourcePath());
        }
        if (obj.getReferenceType())
        {
            writer.writePropertyName("referenceType");
            writer.writeCharArray(*obj.getReferenceType());
        }
        if (obj.getCommitHash())
        {
            writer.writePropertyName("commitHash");
            writer.writeCharArray(*obj.getCommitHash());
        }
        if (obj.getBranchName())
        {
            writer.writePropertyName("branchName");
            writer.writeCharArray(*obj.getBranchName());
        }
        if (obj.getTagName())
        {
            writer.writePropertyName("tagName");
            writer.writeCharArray(*obj.getTagName());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const LimitModel& obj)
    {
        writer.writeObjectStart();
        if (obj.getLimitModelId())
        {
            writer.writePropertyName("limitModelId");
            writer.writeCharArray(*obj.getLimitModelId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*obj.getName());
        }
        if (obj.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.writeCharArray(*obj.getMetadata());
        }
        if (obj.getResetType())
        {
            writer.writePropertyName("resetType");
            writer.writeCharArray(*obj.getResetType());
        }
        if (obj.getResetDayOfMonth())
        {
            writer.writePropertyName("resetDayOfMonth");
            writer.writeInt32(*obj.getResetDayOfMonth());
        }
        if (obj.getResetDayOfWeek())
        {
            writer.writePropertyName("resetDayOfWeek");
            writer.writeCharArray(*obj.getResetDayOfWeek());
        }
        if (obj.getResetHour())
        {
            writer.writePropertyName("resetHour");
            writer.writeInt32(*obj.getResetHour());
        }
        writer.writeObjectEnd();
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
    void describeNamespaces(std::function<void(AsyncDescribeNamespacesResult&)> callback, DescribeNamespacesRequest& request)
    {
        DescribeNamespacesTask& task = *new DescribeNamespacesTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ネームスペースを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createNamespace(std::function<void(AsyncCreateNamespaceResult&)> callback, CreateNamespaceRequest& request)
    {
        CreateNamespaceTask& task = *new CreateNamespaceTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ネームスペースの状態を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getNamespaceStatus(std::function<void(AsyncGetNamespaceStatusResult&)> callback, GetNamespaceStatusRequest& request)
    {
        GetNamespaceStatusTask& task = *new GetNamespaceStatusTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ネームスペースを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getNamespace(std::function<void(AsyncGetNamespaceResult&)> callback, GetNamespaceRequest& request)
    {
        GetNamespaceTask& task = *new GetNamespaceTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ネームスペースを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateNamespace(std::function<void(AsyncUpdateNamespaceResult&)> callback, UpdateNamespaceRequest& request)
    {
        UpdateNamespaceTask& task = *new UpdateNamespaceTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ネームスペースを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteNamespace(std::function<void(AsyncDeleteNamespaceResult&)> callback, DeleteNamespaceRequest& request)
    {
        DeleteNamespaceTask& task = *new DeleteNamespaceTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * カウンターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCounters(std::function<void(AsyncDescribeCountersResult&)> callback, DescribeCountersRequest& request)
    {
        DescribeCountersTask& task = *new DescribeCountersTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * カウンターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCountersByUserId(std::function<void(AsyncDescribeCountersByUserIdResult&)> callback, DescribeCountersByUserIdRequest& request)
    {
        DescribeCountersByUserIdTask& task = *new DescribeCountersByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * カウンターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCounter(std::function<void(AsyncGetCounterResult&)> callback, GetCounterRequest& request)
    {
        GetCounterTask& task = *new GetCounterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザIDを指定してカウンターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCounterByUserId(std::function<void(AsyncGetCounterByUserIdResult&)> callback, GetCounterByUserIdRequest& request)
    {
        GetCounterByUserIdTask& task = *new GetCounterByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザIDを指定してカウントアップ<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void countUpByUserId(std::function<void(AsyncCountUpByUserIdResult&)> callback, CountUpByUserIdRequest& request)
    {
        CountUpByUserIdTask& task = *new CountUpByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザIDを指定してカウンターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteCounterByUserId(std::function<void(AsyncDeleteCounterByUserIdResult&)> callback, DeleteCounterByUserIdRequest& request)
    {
        DeleteCounterByUserIdTask& task = *new DeleteCounterByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * スタンプシートでカウントアップ<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void countUpByStampTask(std::function<void(AsyncCountUpByStampTaskResult&)> callback, CountUpByStampTaskRequest& request)
    {
        CountUpByStampTaskTask& task = *new CountUpByStampTaskTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * スタンプシートでカウンターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteByStampSheet(std::function<void(AsyncDeleteByStampSheetResult&)> callback, DeleteByStampSheetRequest& request)
    {
        DeleteByStampSheetTask& task = *new DeleteByStampSheetTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 回数制限の種類マスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeLimitModelMasters(std::function<void(AsyncDescribeLimitModelMastersResult&)> callback, DescribeLimitModelMastersRequest& request)
    {
        DescribeLimitModelMastersTask& task = *new DescribeLimitModelMastersTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 回数制限の種類マスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createLimitModelMaster(std::function<void(AsyncCreateLimitModelMasterResult&)> callback, CreateLimitModelMasterRequest& request)
    {
        CreateLimitModelMasterTask& task = *new CreateLimitModelMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 回数制限の種類マスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getLimitModelMaster(std::function<void(AsyncGetLimitModelMasterResult&)> callback, GetLimitModelMasterRequest& request)
    {
        GetLimitModelMasterTask& task = *new GetLimitModelMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 回数制限の種類マスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateLimitModelMaster(std::function<void(AsyncUpdateLimitModelMasterResult&)> callback, UpdateLimitModelMasterRequest& request)
    {
        UpdateLimitModelMasterTask& task = *new UpdateLimitModelMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 回数制限の種類マスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteLimitModelMaster(std::function<void(AsyncDeleteLimitModelMasterResult&)> callback, DeleteLimitModelMasterRequest& request)
    {
        DeleteLimitModelMasterTask& task = *new DeleteLimitModelMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 現在有効な回数制限設定のマスターデータをエクスポートします<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void exportMaster(std::function<void(AsyncExportMasterResult&)> callback, ExportMasterRequest& request)
    {
        ExportMasterTask& task = *new ExportMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 現在有効な現在有効な回数制限設定を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentLimitMaster(std::function<void(AsyncGetCurrentLimitMasterResult&)> callback, GetCurrentLimitMasterRequest& request)
    {
        GetCurrentLimitMasterTask& task = *new GetCurrentLimitMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 現在有効な現在有効な回数制限設定を更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentLimitMaster(std::function<void(AsyncUpdateCurrentLimitMasterResult&)> callback, UpdateCurrentLimitMasterRequest& request)
    {
        UpdateCurrentLimitMasterTask& task = *new UpdateCurrentLimitMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 現在有効な現在有効な回数制限設定を更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentLimitMasterFromGitHub(std::function<void(AsyncUpdateCurrentLimitMasterFromGitHubResult&)> callback, UpdateCurrentLimitMasterFromGitHubRequest& request)
    {
        UpdateCurrentLimitMasterFromGitHubTask& task = *new UpdateCurrentLimitMasterFromGitHubTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 回数制限の種類の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeLimitModels(std::function<void(AsyncDescribeLimitModelsResult&)> callback, DescribeLimitModelsRequest& request)
    {
        DescribeLimitModelsTask& task = *new DescribeLimitModelsTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 回数制限の種類を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getLimitModel(std::function<void(AsyncGetLimitModelResult&)> callback, GetLimitModelRequest& request)
    {
        GetLimitModelTask& task = *new GetLimitModelTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_LIMIT_GS2LIMITWEBSOCKETCLIENT_HPP_