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

#ifndef GS2_SHOWCASE_GS2SHOWCASEWEBSOCKETCLIENT_HPP_
#define GS2_SHOWCASE_GS2SHOWCASEWEBSOCKETCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2WebSocketSessionTask.hpp>
#include <gs2/core/network/Gs2WebSocketSession.hpp>
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "model/model.hpp"
#include "request/DescribeNamespacesRequest.hpp"
#include "request/CreateNamespaceRequest.hpp"
#include "request/GetNamespaceStatusRequest.hpp"
#include "request/GetNamespaceRequest.hpp"
#include "request/UpdateNamespaceRequest.hpp"
#include "request/DeleteNamespaceRequest.hpp"
#include "request/DescribeSalesItemMastersRequest.hpp"
#include "request/CreateSalesItemMasterRequest.hpp"
#include "request/GetSalesItemMasterRequest.hpp"
#include "request/UpdateSalesItemMasterRequest.hpp"
#include "request/DeleteSalesItemMasterRequest.hpp"
#include "request/DescribeSalesItemGroupMastersRequest.hpp"
#include "request/CreateSalesItemGroupMasterRequest.hpp"
#include "request/GetSalesItemGroupMasterRequest.hpp"
#include "request/UpdateSalesItemGroupMasterRequest.hpp"
#include "request/DeleteSalesItemGroupMasterRequest.hpp"
#include "request/DescribeShowcaseMastersRequest.hpp"
#include "request/CreateShowcaseMasterRequest.hpp"
#include "request/GetShowcaseMasterRequest.hpp"
#include "request/UpdateShowcaseMasterRequest.hpp"
#include "request/DeleteShowcaseMasterRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentShowcaseMasterRequest.hpp"
#include "request/UpdateCurrentShowcaseMasterRequest.hpp"
#include "request/UpdateCurrentShowcaseMasterFromGitHubRequest.hpp"
#include "request/DescribeShowcasesRequest.hpp"
#include "request/DescribeShowcasesByUserIdRequest.hpp"
#include "request/GetShowcaseRequest.hpp"
#include "request/GetShowcaseByUserIdRequest.hpp"
#include "request/BuyRequest.hpp"
#include "request/BuyByUserIdRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeSalesItemMastersResult.hpp"
#include "result/CreateSalesItemMasterResult.hpp"
#include "result/GetSalesItemMasterResult.hpp"
#include "result/UpdateSalesItemMasterResult.hpp"
#include "result/DeleteSalesItemMasterResult.hpp"
#include "result/DescribeSalesItemGroupMastersResult.hpp"
#include "result/CreateSalesItemGroupMasterResult.hpp"
#include "result/GetSalesItemGroupMasterResult.hpp"
#include "result/UpdateSalesItemGroupMasterResult.hpp"
#include "result/DeleteSalesItemGroupMasterResult.hpp"
#include "result/DescribeShowcaseMastersResult.hpp"
#include "result/CreateShowcaseMasterResult.hpp"
#include "result/GetShowcaseMasterResult.hpp"
#include "result/UpdateShowcaseMasterResult.hpp"
#include "result/DeleteShowcaseMasterResult.hpp"
#include "result/ExportMasterResult.hpp"
#include "result/GetCurrentShowcaseMasterResult.hpp"
#include "result/UpdateCurrentShowcaseMasterResult.hpp"
#include "result/UpdateCurrentShowcaseMasterFromGitHubResult.hpp"
#include "result/DescribeShowcasesResult.hpp"
#include "result/DescribeShowcasesByUserIdResult.hpp"
#include "result/GetShowcaseResult.hpp"
#include "result/GetShowcaseByUserIdResult.hpp"
#include "result/BuyResult.hpp"
#include "result/BuyByUserIdResult.hpp"
#include <cstring>

namespace gs2 { namespace showcase {

typedef AsyncResult<DescribeNamespacesResult> AsyncDescribeNamespacesResult;
typedef AsyncResult<CreateNamespaceResult> AsyncCreateNamespaceResult;
typedef AsyncResult<GetNamespaceStatusResult> AsyncGetNamespaceStatusResult;
typedef AsyncResult<GetNamespaceResult> AsyncGetNamespaceResult;
typedef AsyncResult<UpdateNamespaceResult> AsyncUpdateNamespaceResult;
typedef AsyncResult<DeleteNamespaceResult> AsyncDeleteNamespaceResult;
typedef AsyncResult<DescribeSalesItemMastersResult> AsyncDescribeSalesItemMastersResult;
typedef AsyncResult<CreateSalesItemMasterResult> AsyncCreateSalesItemMasterResult;
typedef AsyncResult<GetSalesItemMasterResult> AsyncGetSalesItemMasterResult;
typedef AsyncResult<UpdateSalesItemMasterResult> AsyncUpdateSalesItemMasterResult;
typedef AsyncResult<DeleteSalesItemMasterResult> AsyncDeleteSalesItemMasterResult;
typedef AsyncResult<DescribeSalesItemGroupMastersResult> AsyncDescribeSalesItemGroupMastersResult;
typedef AsyncResult<CreateSalesItemGroupMasterResult> AsyncCreateSalesItemGroupMasterResult;
typedef AsyncResult<GetSalesItemGroupMasterResult> AsyncGetSalesItemGroupMasterResult;
typedef AsyncResult<UpdateSalesItemGroupMasterResult> AsyncUpdateSalesItemGroupMasterResult;
typedef AsyncResult<DeleteSalesItemGroupMasterResult> AsyncDeleteSalesItemGroupMasterResult;
typedef AsyncResult<DescribeShowcaseMastersResult> AsyncDescribeShowcaseMastersResult;
typedef AsyncResult<CreateShowcaseMasterResult> AsyncCreateShowcaseMasterResult;
typedef AsyncResult<GetShowcaseMasterResult> AsyncGetShowcaseMasterResult;
typedef AsyncResult<UpdateShowcaseMasterResult> AsyncUpdateShowcaseMasterResult;
typedef AsyncResult<DeleteShowcaseMasterResult> AsyncDeleteShowcaseMasterResult;
typedef AsyncResult<ExportMasterResult> AsyncExportMasterResult;
typedef AsyncResult<GetCurrentShowcaseMasterResult> AsyncGetCurrentShowcaseMasterResult;
typedef AsyncResult<UpdateCurrentShowcaseMasterResult> AsyncUpdateCurrentShowcaseMasterResult;
typedef AsyncResult<UpdateCurrentShowcaseMasterFromGitHubResult> AsyncUpdateCurrentShowcaseMasterFromGitHubResult;
typedef AsyncResult<DescribeShowcasesResult> AsyncDescribeShowcasesResult;
typedef AsyncResult<DescribeShowcasesByUserIdResult> AsyncDescribeShowcasesByUserIdResult;
typedef AsyncResult<GetShowcaseResult> AsyncGetShowcaseResult;
typedef AsyncResult<GetShowcaseByUserIdResult> AsyncGetShowcaseByUserIdResult;
typedef AsyncResult<BuyResult> AsyncBuyResult;
typedef AsyncResult<BuyByUserIdResult> AsyncBuyByUserIdResult;

/**
 * GS2 Showcase API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2ShowcaseWebSocketClient : public AbstractGs2ClientBase
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
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
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
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("showcase");
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
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
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
            if (m_Request.getQueueNamespaceId())
            {
                writer.writePropertyName("queueNamespaceId");
                writer.writeCharArray(*m_Request.getQueueNamespaceId());
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
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("showcase");
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
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
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
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("showcase");
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
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
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
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("showcase");
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
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
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
            if (m_Request.getQueueNamespaceId())
            {
                writer.writePropertyName("queueNamespaceId");
                writer.writeCharArray(*m_Request.getQueueNamespaceId());
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
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("showcase");
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
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
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
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("showcase");
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

    class DescribeSalesItemMastersTask : public detail::Gs2WebSocketSessionTask<DescribeSalesItemMastersResult>
    {
    private:
        DescribeSalesItemMastersRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
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
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("showcase");
            writer.writePropertyName("component");
            writer.writeCharArray("salesItemMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("describeSalesItemMasters");
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
        DescribeSalesItemMastersTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeSalesItemMastersRequest& request,
            Gs2WebSocketSessionTask<DescribeSalesItemMastersResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeSalesItemMastersResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeSalesItemMastersTask() GS2_OVERRIDE = default;
    };

    class CreateSalesItemMasterTask : public detail::Gs2WebSocketSessionTask<CreateSalesItemMasterResult>
    {
    private:
        CreateSalesItemMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
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
            if (m_Request.getConsumeActions())
            {
                writer.writePropertyName("consumeActions");
                writer.writeArrayStart();
                auto& list = *m_Request.getConsumeActions();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(writer, list[i]);
                }
                writer.writeArrayEnd();
            }
            if (m_Request.getAcquireActions())
            {
                writer.writePropertyName("acquireActions");
                writer.writeArrayStart();
                auto& list = *m_Request.getAcquireActions();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(writer, list[i]);
                }
                writer.writeArrayEnd();
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

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("showcase");
            writer.writePropertyName("component");
            writer.writeCharArray("salesItemMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("createSalesItemMaster");
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
        CreateSalesItemMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            CreateSalesItemMasterRequest& request,
            Gs2WebSocketSessionTask<CreateSalesItemMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateSalesItemMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~CreateSalesItemMasterTask() GS2_OVERRIDE = default;
    };

    class GetSalesItemMasterTask : public detail::Gs2WebSocketSessionTask<GetSalesItemMasterResult>
    {
    private:
        GetSalesItemMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getSalesItemName())
            {
                writer.writePropertyName("salesItemName");
                writer.writeCharArray(*m_Request.getSalesItemName());
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

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("showcase");
            writer.writePropertyName("component");
            writer.writeCharArray("salesItemMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("getSalesItemMaster");
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
        GetSalesItemMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetSalesItemMasterRequest& request,
            Gs2WebSocketSessionTask<GetSalesItemMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetSalesItemMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetSalesItemMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateSalesItemMasterTask : public detail::Gs2WebSocketSessionTask<UpdateSalesItemMasterResult>
    {
    private:
        UpdateSalesItemMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getSalesItemName())
            {
                writer.writePropertyName("salesItemName");
                writer.writeCharArray(*m_Request.getSalesItemName());
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
            if (m_Request.getConsumeActions())
            {
                writer.writePropertyName("consumeActions");
                writer.writeArrayStart();
                auto& list = *m_Request.getConsumeActions();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(writer, list[i]);
                }
                writer.writeArrayEnd();
            }
            if (m_Request.getAcquireActions())
            {
                writer.writePropertyName("acquireActions");
                writer.writeArrayStart();
                auto& list = *m_Request.getAcquireActions();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(writer, list[i]);
                }
                writer.writeArrayEnd();
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

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("showcase");
            writer.writePropertyName("component");
            writer.writeCharArray("salesItemMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("updateSalesItemMaster");
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
        UpdateSalesItemMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateSalesItemMasterRequest& request,
            Gs2WebSocketSessionTask<UpdateSalesItemMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateSalesItemMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateSalesItemMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteSalesItemMasterTask : public detail::Gs2WebSocketSessionTask<DeleteSalesItemMasterResult>
    {
    private:
        DeleteSalesItemMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getSalesItemName())
            {
                writer.writePropertyName("salesItemName");
                writer.writeCharArray(*m_Request.getSalesItemName());
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

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("showcase");
            writer.writePropertyName("component");
            writer.writeCharArray("salesItemMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteSalesItemMaster");
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
        DeleteSalesItemMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteSalesItemMasterRequest& request,
            Gs2WebSocketSessionTask<DeleteSalesItemMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteSalesItemMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteSalesItemMasterTask() GS2_OVERRIDE = default;
    };

    class DescribeSalesItemGroupMastersTask : public detail::Gs2WebSocketSessionTask<DescribeSalesItemGroupMastersResult>
    {
    private:
        DescribeSalesItemGroupMastersRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
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
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("showcase");
            writer.writePropertyName("component");
            writer.writeCharArray("salesItemGroupMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("describeSalesItemGroupMasters");
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
        DescribeSalesItemGroupMastersTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeSalesItemGroupMastersRequest& request,
            Gs2WebSocketSessionTask<DescribeSalesItemGroupMastersResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeSalesItemGroupMastersResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeSalesItemGroupMastersTask() GS2_OVERRIDE = default;
    };

    class CreateSalesItemGroupMasterTask : public detail::Gs2WebSocketSessionTask<CreateSalesItemGroupMasterResult>
    {
    private:
        CreateSalesItemGroupMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
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
            if (m_Request.getSalesItemNames())
            {
                writer.writePropertyName("salesItemNames");
                writer.writeArrayStart();
                auto& list = *m_Request.getSalesItemNames();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    writer.writeCharArray(list[i]);
                }
                writer.writeArrayEnd();
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

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("showcase");
            writer.writePropertyName("component");
            writer.writeCharArray("salesItemGroupMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("createSalesItemGroupMaster");
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
        CreateSalesItemGroupMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            CreateSalesItemGroupMasterRequest& request,
            Gs2WebSocketSessionTask<CreateSalesItemGroupMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateSalesItemGroupMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~CreateSalesItemGroupMasterTask() GS2_OVERRIDE = default;
    };

    class GetSalesItemGroupMasterTask : public detail::Gs2WebSocketSessionTask<GetSalesItemGroupMasterResult>
    {
    private:
        GetSalesItemGroupMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getSalesItemGroupName())
            {
                writer.writePropertyName("salesItemGroupName");
                writer.writeCharArray(*m_Request.getSalesItemGroupName());
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

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("showcase");
            writer.writePropertyName("component");
            writer.writeCharArray("salesItemGroupMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("getSalesItemGroupMaster");
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
        GetSalesItemGroupMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetSalesItemGroupMasterRequest& request,
            Gs2WebSocketSessionTask<GetSalesItemGroupMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetSalesItemGroupMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetSalesItemGroupMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateSalesItemGroupMasterTask : public detail::Gs2WebSocketSessionTask<UpdateSalesItemGroupMasterResult>
    {
    private:
        UpdateSalesItemGroupMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getSalesItemGroupName())
            {
                writer.writePropertyName("salesItemGroupName");
                writer.writeCharArray(*m_Request.getSalesItemGroupName());
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
            if (m_Request.getSalesItemNames())
            {
                writer.writePropertyName("salesItemNames");
                writer.writeArrayStart();
                auto& list = *m_Request.getSalesItemNames();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    writer.writeCharArray(list[i]);
                }
                writer.writeArrayEnd();
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

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("showcase");
            writer.writePropertyName("component");
            writer.writeCharArray("salesItemGroupMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("updateSalesItemGroupMaster");
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
        UpdateSalesItemGroupMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateSalesItemGroupMasterRequest& request,
            Gs2WebSocketSessionTask<UpdateSalesItemGroupMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateSalesItemGroupMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateSalesItemGroupMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteSalesItemGroupMasterTask : public detail::Gs2WebSocketSessionTask<DeleteSalesItemGroupMasterResult>
    {
    private:
        DeleteSalesItemGroupMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getSalesItemGroupName())
            {
                writer.writePropertyName("salesItemGroupName");
                writer.writeCharArray(*m_Request.getSalesItemGroupName());
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

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("showcase");
            writer.writePropertyName("component");
            writer.writeCharArray("salesItemGroupMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteSalesItemGroupMaster");
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
        DeleteSalesItemGroupMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteSalesItemGroupMasterRequest& request,
            Gs2WebSocketSessionTask<DeleteSalesItemGroupMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteSalesItemGroupMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteSalesItemGroupMasterTask() GS2_OVERRIDE = default;
    };

    class DescribeShowcaseMastersTask : public detail::Gs2WebSocketSessionTask<DescribeShowcaseMastersResult>
    {
    private:
        DescribeShowcaseMastersRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
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
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("showcase");
            writer.writePropertyName("component");
            writer.writeCharArray("showcaseMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("describeShowcaseMasters");
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
        DescribeShowcaseMastersTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeShowcaseMastersRequest& request,
            Gs2WebSocketSessionTask<DescribeShowcaseMastersResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeShowcaseMastersResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeShowcaseMastersTask() GS2_OVERRIDE = default;
    };

    class CreateShowcaseMasterTask : public detail::Gs2WebSocketSessionTask<CreateShowcaseMasterResult>
    {
    private:
        CreateShowcaseMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
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
            if (m_Request.getDisplayItems())
            {
                writer.writePropertyName("displayItems");
                writer.writeArrayStart();
                auto& list = *m_Request.getDisplayItems();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(writer, list[i]);
                }
                writer.writeArrayEnd();
            }
            if (m_Request.getSalesPeriodEventId())
            {
                writer.writePropertyName("salesPeriodEventId");
                writer.writeCharArray(*m_Request.getSalesPeriodEventId());
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

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("showcase");
            writer.writePropertyName("component");
            writer.writeCharArray("showcaseMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("createShowcaseMaster");
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
        CreateShowcaseMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            CreateShowcaseMasterRequest& request,
            Gs2WebSocketSessionTask<CreateShowcaseMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateShowcaseMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~CreateShowcaseMasterTask() GS2_OVERRIDE = default;
    };

    class GetShowcaseMasterTask : public detail::Gs2WebSocketSessionTask<GetShowcaseMasterResult>
    {
    private:
        GetShowcaseMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getShowcaseName())
            {
                writer.writePropertyName("showcaseName");
                writer.writeCharArray(*m_Request.getShowcaseName());
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

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("showcase");
            writer.writePropertyName("component");
            writer.writeCharArray("showcaseMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("getShowcaseMaster");
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
        GetShowcaseMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetShowcaseMasterRequest& request,
            Gs2WebSocketSessionTask<GetShowcaseMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetShowcaseMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetShowcaseMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateShowcaseMasterTask : public detail::Gs2WebSocketSessionTask<UpdateShowcaseMasterResult>
    {
    private:
        UpdateShowcaseMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getShowcaseName())
            {
                writer.writePropertyName("showcaseName");
                writer.writeCharArray(*m_Request.getShowcaseName());
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
            if (m_Request.getDisplayItems())
            {
                writer.writePropertyName("displayItems");
                writer.writeArrayStart();
                auto& list = *m_Request.getDisplayItems();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(writer, list[i]);
                }
                writer.writeArrayEnd();
            }
            if (m_Request.getSalesPeriodEventId())
            {
                writer.writePropertyName("salesPeriodEventId");
                writer.writeCharArray(*m_Request.getSalesPeriodEventId());
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

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("showcase");
            writer.writePropertyName("component");
            writer.writeCharArray("showcaseMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("updateShowcaseMaster");
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
        UpdateShowcaseMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateShowcaseMasterRequest& request,
            Gs2WebSocketSessionTask<UpdateShowcaseMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateShowcaseMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateShowcaseMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteShowcaseMasterTask : public detail::Gs2WebSocketSessionTask<DeleteShowcaseMasterResult>
    {
    private:
        DeleteShowcaseMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getShowcaseName())
            {
                writer.writePropertyName("showcaseName");
                writer.writeCharArray(*m_Request.getShowcaseName());
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

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("showcase");
            writer.writePropertyName("component");
            writer.writeCharArray("showcaseMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteShowcaseMaster");
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
        DeleteShowcaseMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteShowcaseMasterRequest& request,
            Gs2WebSocketSessionTask<DeleteShowcaseMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteShowcaseMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteShowcaseMasterTask() GS2_OVERRIDE = default;
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
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
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
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("showcase");
            writer.writePropertyName("component");
            writer.writeCharArray("currentShowcaseMaster");
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

    class GetCurrentShowcaseMasterTask : public detail::Gs2WebSocketSessionTask<GetCurrentShowcaseMasterResult>
    {
    private:
        GetCurrentShowcaseMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
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
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("showcase");
            writer.writePropertyName("component");
            writer.writeCharArray("currentShowcaseMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("getCurrentShowcaseMaster");
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
        GetCurrentShowcaseMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetCurrentShowcaseMasterRequest& request,
            Gs2WebSocketSessionTask<GetCurrentShowcaseMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetCurrentShowcaseMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetCurrentShowcaseMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentShowcaseMasterTask : public detail::Gs2WebSocketSessionTask<UpdateCurrentShowcaseMasterResult>
    {
    private:
        UpdateCurrentShowcaseMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
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
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("showcase");
            writer.writePropertyName("component");
            writer.writeCharArray("currentShowcaseMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("updateCurrentShowcaseMaster");
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
        UpdateCurrentShowcaseMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateCurrentShowcaseMasterRequest& request,
            Gs2WebSocketSessionTask<UpdateCurrentShowcaseMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateCurrentShowcaseMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateCurrentShowcaseMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentShowcaseMasterFromGitHubTask : public detail::Gs2WebSocketSessionTask<UpdateCurrentShowcaseMasterFromGitHubResult>
    {
    private:
        UpdateCurrentShowcaseMasterFromGitHubRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
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
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("showcase");
            writer.writePropertyName("component");
            writer.writeCharArray("currentShowcaseMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("updateCurrentShowcaseMasterFromGitHub");
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
        UpdateCurrentShowcaseMasterFromGitHubTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateCurrentShowcaseMasterFromGitHubRequest& request,
            Gs2WebSocketSessionTask<UpdateCurrentShowcaseMasterFromGitHubResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateCurrentShowcaseMasterFromGitHubResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateCurrentShowcaseMasterFromGitHubTask() GS2_OVERRIDE = default;
    };

    class DescribeShowcasesTask : public detail::Gs2WebSocketSessionTask<DescribeShowcasesResult>
    {
    private:
        DescribeShowcasesRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
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
            writer.writeCharArray("showcase");
            writer.writePropertyName("component");
            writer.writeCharArray("showcase");
            writer.writePropertyName("function");
            writer.writeCharArray("describeShowcases");
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
        DescribeShowcasesTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeShowcasesRequest& request,
            Gs2WebSocketSessionTask<DescribeShowcasesResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeShowcasesResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeShowcasesTask() GS2_OVERRIDE = default;
    };

    class DescribeShowcasesByUserIdTask : public detail::Gs2WebSocketSessionTask<DescribeShowcasesByUserIdResult>
    {
    private:
        DescribeShowcasesByUserIdRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                writer.writePropertyName("userId");
                writer.writeCharArray(*m_Request.getUserId());
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
            writer.writeCharArray("showcase");
            writer.writePropertyName("component");
            writer.writeCharArray("showcase");
            writer.writePropertyName("function");
            writer.writeCharArray("describeShowcasesByUserId");
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
        DescribeShowcasesByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeShowcasesByUserIdRequest& request,
            Gs2WebSocketSessionTask<DescribeShowcasesByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeShowcasesByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeShowcasesByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetShowcaseTask : public detail::Gs2WebSocketSessionTask<GetShowcaseResult>
    {
    private:
        GetShowcaseRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getShowcaseName())
            {
                writer.writePropertyName("showcaseName");
                writer.writeCharArray(*m_Request.getShowcaseName());
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
            writer.writeCharArray("showcase");
            writer.writePropertyName("component");
            writer.writeCharArray("showcase");
            writer.writePropertyName("function");
            writer.writeCharArray("getShowcase");
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
        GetShowcaseTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetShowcaseRequest& request,
            Gs2WebSocketSessionTask<GetShowcaseResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetShowcaseResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetShowcaseTask() GS2_OVERRIDE = default;
    };

    class GetShowcaseByUserIdTask : public detail::Gs2WebSocketSessionTask<GetShowcaseByUserIdResult>
    {
    private:
        GetShowcaseByUserIdRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getShowcaseName())
            {
                writer.writePropertyName("showcaseName");
                writer.writeCharArray(*m_Request.getShowcaseName());
            }
            if (m_Request.getUserId())
            {
                writer.writePropertyName("userId");
                writer.writeCharArray(*m_Request.getUserId());
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
            writer.writeCharArray("showcase");
            writer.writePropertyName("component");
            writer.writeCharArray("showcase");
            writer.writePropertyName("function");
            writer.writeCharArray("getShowcaseByUserId");
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
        GetShowcaseByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetShowcaseByUserIdRequest& request,
            Gs2WebSocketSessionTask<GetShowcaseByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetShowcaseByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetShowcaseByUserIdTask() GS2_OVERRIDE = default;
    };

    class BuyTask : public detail::Gs2WebSocketSessionTask<BuyResult>
    {
    private:
        BuyRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getShowcaseName())
            {
                writer.writePropertyName("showcaseName");
                writer.writeCharArray(*m_Request.getShowcaseName());
            }
            if (m_Request.getDisplayItemId())
            {
                writer.writePropertyName("displayItemId");
                writer.writeCharArray(*m_Request.getDisplayItemId());
            }
            if (m_Request.getConfig())
            {
                writer.writePropertyName("config");
                writer.writeArrayStart();
                auto& list = *m_Request.getConfig();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(writer, list[i]);
                }
                writer.writeArrayEnd();
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
            writer.writeCharArray("showcase");
            writer.writePropertyName("component");
            writer.writeCharArray("showcase");
            writer.writePropertyName("function");
            writer.writeCharArray("buy");
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
        BuyTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            BuyRequest& request,
            Gs2WebSocketSessionTask<BuyResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<BuyResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~BuyTask() GS2_OVERRIDE = default;
    };

    class BuyByUserIdTask : public detail::Gs2WebSocketSessionTask<BuyByUserIdResult>
    {
    private:
        BuyByUserIdRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getShowcaseName())
            {
                writer.writePropertyName("showcaseName");
                writer.writeCharArray(*m_Request.getShowcaseName());
            }
            if (m_Request.getDisplayItemId())
            {
                writer.writePropertyName("displayItemId");
                writer.writeCharArray(*m_Request.getDisplayItemId());
            }
            if (m_Request.getUserId())
            {
                writer.writePropertyName("userId");
                writer.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getConfig())
            {
                writer.writePropertyName("config");
                writer.writeArrayStart();
                auto& list = *m_Request.getConfig();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(writer, list[i]);
                }
                writer.writeArrayEnd();
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
            writer.writeCharArray("showcase");
            writer.writePropertyName("component");
            writer.writeCharArray("showcase");
            writer.writePropertyName("function");
            writer.writeCharArray("buyByUserId");
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
        BuyByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            BuyByUserIdRequest& request,
            Gs2WebSocketSessionTask<BuyByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<BuyByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~BuyByUserIdTask() GS2_OVERRIDE = default;
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
        if (obj.getQueueNamespaceId())
        {
            writer.writePropertyName("queueNamespaceId");
            writer.writeCharArray(*obj.getQueueNamespaceId());
        }
        if (obj.getKeyId())
        {
            writer.writePropertyName("keyId");
            writer.writeCharArray(*obj.getKeyId());
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

    static void write(detail::json::JsonWriter& writer, const SalesItemMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getSalesItemId())
        {
            writer.writePropertyName("salesItemId");
            writer.writeCharArray(*obj.getSalesItemId());
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
        if (obj.getConsumeActions())
        {
            writer.writePropertyName("consumeActions");
            writer.writeArrayStart();
            auto& list = *obj.getConsumeActions();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getAcquireActions())
        {
            writer.writePropertyName("acquireActions");
            writer.writeArrayStart();
            auto& list = *obj.getAcquireActions();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
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

    static void write(detail::json::JsonWriter& writer, const SalesItemGroupMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getSalesItemGroupId())
        {
            writer.writePropertyName("salesItemGroupId");
            writer.writeCharArray(*obj.getSalesItemGroupId());
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
        if (obj.getSalesItemNames())
        {
            writer.writePropertyName("salesItemNames");
            writer.writeArrayStart();
            auto& list = *obj.getSalesItemNames();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                writer.writeCharArray(list[i]);
            }
            writer.writeArrayEnd();
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

    static void write(detail::json::JsonWriter& writer, const ShowcaseMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getShowcaseId())
        {
            writer.writePropertyName("showcaseId");
            writer.writeCharArray(*obj.getShowcaseId());
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
        if (obj.getDisplayItems())
        {
            writer.writePropertyName("displayItems");
            writer.writeArrayStart();
            auto& list = *obj.getDisplayItems();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getSalesPeriodEventId())
        {
            writer.writePropertyName("salesPeriodEventId");
            writer.writeCharArray(*obj.getSalesPeriodEventId());
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

    static void write(detail::json::JsonWriter& writer, const CurrentShowcaseMaster& obj)
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

    static void write(detail::json::JsonWriter& writer, const SalesItem& obj)
    {
        writer.writeObjectStart();
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
        if (obj.getConsumeActions())
        {
            writer.writePropertyName("consumeActions");
            writer.writeArrayStart();
            auto& list = *obj.getConsumeActions();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getAcquireActions())
        {
            writer.writePropertyName("acquireActions");
            writer.writeArrayStart();
            auto& list = *obj.getAcquireActions();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const SalesItemGroup& obj)
    {
        writer.writeObjectStart();
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
        if (obj.getSalesItems())
        {
            writer.writePropertyName("salesItems");
            writer.writeArrayStart();
            auto& list = *obj.getSalesItems();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const Showcase& obj)
    {
        writer.writeObjectStart();
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
        if (obj.getDisplayItems())
        {
            writer.writePropertyName("displayItems");
            writer.writeArrayStart();
            auto& list = *obj.getDisplayItems();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getSalesPeriodEventId())
        {
            writer.writePropertyName("salesPeriodEventId");
            writer.writeCharArray(*obj.getSalesPeriodEventId());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const DisplayItem& obj)
    {
        writer.writeObjectStart();
        if (obj.getDisplayItemId())
        {
            writer.writePropertyName("displayItemId");
            writer.writeCharArray(*obj.getDisplayItemId());
        }
        if (obj.getType())
        {
            writer.writePropertyName("type");
            writer.writeCharArray(*obj.getType());
        }
        if (obj.getSalesItem())
        {
            writer.writePropertyName("salesItem");
            write(writer, *obj.getSalesItem());
        }
        if (obj.getSalesItemGroup())
        {
            writer.writePropertyName("salesItemGroup");
            write(writer, *obj.getSalesItemGroup());
        }
        if (obj.getSalesPeriodEventId())
        {
            writer.writePropertyName("salesPeriodEventId");
            writer.writeCharArray(*obj.getSalesPeriodEventId());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const Config& obj)
    {
        writer.writeObjectStart();
        if (obj.getKey())
        {
            writer.writePropertyName("key");
            writer.writeCharArray(*obj.getKey());
        }
        if (obj.getValue())
        {
            writer.writePropertyName("value");
            writer.writeCharArray(*obj.getValue());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const ConsumeAction& obj)
    {
        writer.writeObjectStart();
        if (obj.getAction())
        {
            writer.writePropertyName("action");
            writer.writeCharArray(*obj.getAction());
        }
        if (obj.getRequest())
        {
            writer.writePropertyName("request");
            writer.writeCharArray(*obj.getRequest());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const AcquireAction& obj)
    {
        writer.writeObjectStart();
        if (obj.getAction())
        {
            writer.writePropertyName("action");
            writer.writeCharArray(*obj.getAction());
        }
        if (obj.getRequest())
        {
            writer.writePropertyName("request");
            writer.writeCharArray(*obj.getRequest());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const DisplayItemMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getDisplayItemId())
        {
            writer.writePropertyName("displayItemId");
            writer.writeCharArray(*obj.getDisplayItemId());
        }
        if (obj.getType())
        {
            writer.writePropertyName("type");
            writer.writeCharArray(*obj.getType());
        }
        if (obj.getSalesItemName())
        {
            writer.writePropertyName("salesItemName");
            writer.writeCharArray(*obj.getSalesItemName());
        }
        if (obj.getSalesItemGroupName())
        {
            writer.writePropertyName("salesItemGroupName");
            writer.writeCharArray(*obj.getSalesItemGroupName());
        }
        if (obj.getSalesPeriodEventId())
        {
            writer.writePropertyName("salesPeriodEventId");
            writer.writeCharArray(*obj.getSalesPeriodEventId());
        }
        writer.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param gs2WebSocketSession WebSocket API 用セッション
     */
    explicit Gs2ShowcaseWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
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
	 * 商品マスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeSalesItemMasters(std::function<void(AsyncDescribeSalesItemMastersResult&)> callback, DescribeSalesItemMastersRequest& request)
    {
        DescribeSalesItemMastersTask& task = *new DescribeSalesItemMastersTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 商品マスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createSalesItemMaster(std::function<void(AsyncCreateSalesItemMasterResult&)> callback, CreateSalesItemMasterRequest& request)
    {
        CreateSalesItemMasterTask& task = *new CreateSalesItemMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 商品マスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getSalesItemMaster(std::function<void(AsyncGetSalesItemMasterResult&)> callback, GetSalesItemMasterRequest& request)
    {
        GetSalesItemMasterTask& task = *new GetSalesItemMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 商品マスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateSalesItemMaster(std::function<void(AsyncUpdateSalesItemMasterResult&)> callback, UpdateSalesItemMasterRequest& request)
    {
        UpdateSalesItemMasterTask& task = *new UpdateSalesItemMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 商品マスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteSalesItemMaster(std::function<void(AsyncDeleteSalesItemMasterResult&)> callback, DeleteSalesItemMasterRequest& request)
    {
        DeleteSalesItemMasterTask& task = *new DeleteSalesItemMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 商品グループマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeSalesItemGroupMasters(std::function<void(AsyncDescribeSalesItemGroupMastersResult&)> callback, DescribeSalesItemGroupMastersRequest& request)
    {
        DescribeSalesItemGroupMastersTask& task = *new DescribeSalesItemGroupMastersTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 商品グループマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createSalesItemGroupMaster(std::function<void(AsyncCreateSalesItemGroupMasterResult&)> callback, CreateSalesItemGroupMasterRequest& request)
    {
        CreateSalesItemGroupMasterTask& task = *new CreateSalesItemGroupMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 商品グループマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getSalesItemGroupMaster(std::function<void(AsyncGetSalesItemGroupMasterResult&)> callback, GetSalesItemGroupMasterRequest& request)
    {
        GetSalesItemGroupMasterTask& task = *new GetSalesItemGroupMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 商品グループマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateSalesItemGroupMaster(std::function<void(AsyncUpdateSalesItemGroupMasterResult&)> callback, UpdateSalesItemGroupMasterRequest& request)
    {
        UpdateSalesItemGroupMasterTask& task = *new UpdateSalesItemGroupMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 商品グループマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteSalesItemGroupMaster(std::function<void(AsyncDeleteSalesItemGroupMasterResult&)> callback, DeleteSalesItemGroupMasterRequest& request)
    {
        DeleteSalesItemGroupMasterTask& task = *new DeleteSalesItemGroupMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 陳列棚マスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeShowcaseMasters(std::function<void(AsyncDescribeShowcaseMastersResult&)> callback, DescribeShowcaseMastersRequest& request)
    {
        DescribeShowcaseMastersTask& task = *new DescribeShowcaseMastersTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 陳列棚マスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createShowcaseMaster(std::function<void(AsyncCreateShowcaseMasterResult&)> callback, CreateShowcaseMasterRequest& request)
    {
        CreateShowcaseMasterTask& task = *new CreateShowcaseMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 陳列棚マスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getShowcaseMaster(std::function<void(AsyncGetShowcaseMasterResult&)> callback, GetShowcaseMasterRequest& request)
    {
        GetShowcaseMasterTask& task = *new GetShowcaseMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 陳列棚マスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateShowcaseMaster(std::function<void(AsyncUpdateShowcaseMasterResult&)> callback, UpdateShowcaseMasterRequest& request)
    {
        UpdateShowcaseMasterTask& task = *new UpdateShowcaseMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 陳列棚マスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteShowcaseMaster(std::function<void(AsyncDeleteShowcaseMasterResult&)> callback, DeleteShowcaseMasterRequest& request)
    {
        DeleteShowcaseMasterTask& task = *new DeleteShowcaseMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 現在有効な陳列棚マスターのマスターデータをエクスポートします<br>
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
	 * 現在有効な現在有効な陳列棚マスターを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentShowcaseMaster(std::function<void(AsyncGetCurrentShowcaseMasterResult&)> callback, GetCurrentShowcaseMasterRequest& request)
    {
        GetCurrentShowcaseMasterTask& task = *new GetCurrentShowcaseMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 現在有効な現在有効な陳列棚マスターを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentShowcaseMaster(std::function<void(AsyncUpdateCurrentShowcaseMasterResult&)> callback, UpdateCurrentShowcaseMasterRequest& request)
    {
        UpdateCurrentShowcaseMasterTask& task = *new UpdateCurrentShowcaseMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 現在有効な現在有効な陳列棚マスターを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentShowcaseMasterFromGitHub(std::function<void(AsyncUpdateCurrentShowcaseMasterFromGitHubResult&)> callback, UpdateCurrentShowcaseMasterFromGitHubRequest& request)
    {
        UpdateCurrentShowcaseMasterFromGitHubTask& task = *new UpdateCurrentShowcaseMasterFromGitHubTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 陳列棚の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeShowcases(std::function<void(AsyncDescribeShowcasesResult&)> callback, DescribeShowcasesRequest& request)
    {
        DescribeShowcasesTask& task = *new DescribeShowcasesTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザIDを指定して陳列棚の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeShowcasesByUserId(std::function<void(AsyncDescribeShowcasesByUserIdResult&)> callback, DescribeShowcasesByUserIdRequest& request)
    {
        DescribeShowcasesByUserIdTask& task = *new DescribeShowcasesByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 陳列棚を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getShowcase(std::function<void(AsyncGetShowcaseResult&)> callback, GetShowcaseRequest& request)
    {
        GetShowcaseTask& task = *new GetShowcaseTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザIDを指定して陳列棚を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getShowcaseByUserId(std::function<void(AsyncGetShowcaseByUserIdResult&)> callback, GetShowcaseByUserIdRequest& request)
    {
        GetShowcaseByUserIdTask& task = *new GetShowcaseByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 陳列棚を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void buy(std::function<void(AsyncBuyResult&)> callback, BuyRequest& request)
    {
        BuyTask& task = *new BuyTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザIDを指定して陳列棚を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void buyByUserId(std::function<void(AsyncBuyByUserIdResult&)> callback, BuyByUserIdRequest& request)
    {
        BuyByUserIdTask& task = *new BuyByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_SHOWCASE_GS2SHOWCASEWEBSOCKETCLIENT_HPP_