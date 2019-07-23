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

#ifndef GS2_MATCHMAKING_GS2MATCHMAKINGWEBSOCKETCLIENT_HPP_
#define GS2_MATCHMAKING_GS2MATCHMAKINGWEBSOCKETCLIENT_HPP_

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
#include "request/DescribeGatheringsRequest.hpp"
#include "request/CreateGatheringRequest.hpp"
#include "request/CreateGatheringByUserIdRequest.hpp"
#include "request/UpdateGatheringRequest.hpp"
#include "request/UpdateGatheringByUserIdRequest.hpp"
#include "request/DoMatchmakingByPlayerRequest.hpp"
#include "request/DoMatchmakingRequest.hpp"
#include "request/GetGatheringRequest.hpp"
#include "request/CancelMatchmakingRequest.hpp"
#include "request/CancelMatchmakingByUserIdRequest.hpp"
#include "request/DeleteGatheringRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeGatheringsResult.hpp"
#include "result/CreateGatheringResult.hpp"
#include "result/CreateGatheringByUserIdResult.hpp"
#include "result/UpdateGatheringResult.hpp"
#include "result/UpdateGatheringByUserIdResult.hpp"
#include "result/DoMatchmakingByPlayerResult.hpp"
#include "result/DoMatchmakingResult.hpp"
#include "result/GetGatheringResult.hpp"
#include "result/CancelMatchmakingResult.hpp"
#include "result/CancelMatchmakingByUserIdResult.hpp"
#include "result/DeleteGatheringResult.hpp"
#include <cstring>
#include <network/HttpRequest.h>

namespace gs2 { namespace matchmaking {

typedef AsyncResult<DescribeNamespacesResult> AsyncDescribeNamespacesResult;
typedef AsyncResult<CreateNamespaceResult> AsyncCreateNamespaceResult;
typedef AsyncResult<GetNamespaceStatusResult> AsyncGetNamespaceStatusResult;
typedef AsyncResult<GetNamespaceResult> AsyncGetNamespaceResult;
typedef AsyncResult<UpdateNamespaceResult> AsyncUpdateNamespaceResult;
typedef AsyncResult<DeleteNamespaceResult> AsyncDeleteNamespaceResult;
typedef AsyncResult<DescribeGatheringsResult> AsyncDescribeGatheringsResult;
typedef AsyncResult<CreateGatheringResult> AsyncCreateGatheringResult;
typedef AsyncResult<CreateGatheringByUserIdResult> AsyncCreateGatheringByUserIdResult;
typedef AsyncResult<UpdateGatheringResult> AsyncUpdateGatheringResult;
typedef AsyncResult<UpdateGatheringByUserIdResult> AsyncUpdateGatheringByUserIdResult;
typedef AsyncResult<DoMatchmakingByPlayerResult> AsyncDoMatchmakingByPlayerResult;
typedef AsyncResult<DoMatchmakingResult> AsyncDoMatchmakingResult;
typedef AsyncResult<GetGatheringResult> AsyncGetGatheringResult;
typedef AsyncResult<CancelMatchmakingResult> AsyncCancelMatchmakingResult;
typedef AsyncResult<CancelMatchmakingByUserIdResult> AsyncCancelMatchmakingByUserIdResult;
typedef AsyncResult<DeleteGatheringResult> AsyncDeleteGatheringResult;

/**
 * GS2 Matchmaking API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2MatchmakingWebSocketClient : public AbstractGs2ClientBase
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
            writer.writeCharArray("matchmaking");
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
            writer.writeCharArray("matchmaking");
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
            writer.writeCharArray("matchmaking");
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
            writer.writeCharArray("matchmaking");
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
            writer.writeCharArray("matchmaking");
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
            writer.writeCharArray("matchmaking");
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

    class DescribeGatheringsTask : public detail::Gs2WebSocketSessionTask<DescribeGatheringsResult>
    {
    private:
        DescribeGatheringsRequest& m_Request;

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
            writer.writeCharArray("matchmaking");
            writer.writePropertyName("component");
            writer.writeCharArray("gathering");
            writer.writePropertyName("function");
            writer.writeCharArray("describeGatherings");
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
        DescribeGatheringsTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeGatheringsRequest& request,
            Gs2WebSocketSessionTask<DescribeGatheringsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeGatheringsResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeGatheringsTask() GS2_OVERRIDE = default;
    };

    class CreateGatheringTask : public detail::Gs2WebSocketSessionTask<CreateGatheringResult>
    {
    private:
        CreateGatheringRequest& m_Request;

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
            if (m_Request.getPlayer())
            {
                writer.writePropertyName("player");
                write(writer, *m_Request.getPlayer());
            }
            if (m_Request.getAttributeRanges())
            {
                writer.writePropertyName("attributeRanges");
                writer.writeArrayStart();
                auto& list = *m_Request.getAttributeRanges();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(writer, list[i]);
                }
                writer.writeArrayEnd();
            }
            if (m_Request.getCapacityOfRoles())
            {
                writer.writePropertyName("capacityOfRoles");
                writer.writeArrayStart();
                auto& list = *m_Request.getCapacityOfRoles();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(writer, list[i]);
                }
                writer.writeArrayEnd();
            }
            if (m_Request.getAllowUserIds())
            {
                writer.writePropertyName("allowUserIds");
                writer.writeArrayStart();
                auto& list = *m_Request.getAllowUserIds();
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
            writer.writeCharArray("matchmaking");
            writer.writePropertyName("component");
            writer.writeCharArray("gathering");
            writer.writePropertyName("function");
            writer.writeCharArray("createGathering");
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
        CreateGatheringTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            CreateGatheringRequest& request,
            Gs2WebSocketSessionTask<CreateGatheringResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateGatheringResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~CreateGatheringTask() GS2_OVERRIDE = default;
    };

    class CreateGatheringByUserIdTask : public detail::Gs2WebSocketSessionTask<CreateGatheringByUserIdResult>
    {
    private:
        CreateGatheringByUserIdRequest& m_Request;

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
            if (m_Request.getPlayer())
            {
                writer.writePropertyName("player");
                write(writer, *m_Request.getPlayer());
            }
            if (m_Request.getAttributeRanges())
            {
                writer.writePropertyName("attributeRanges");
                writer.writeArrayStart();
                auto& list = *m_Request.getAttributeRanges();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(writer, list[i]);
                }
                writer.writeArrayEnd();
            }
            if (m_Request.getCapacityOfRoles())
            {
                writer.writePropertyName("capacityOfRoles");
                writer.writeArrayStart();
                auto& list = *m_Request.getCapacityOfRoles();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(writer, list[i]);
                }
                writer.writeArrayEnd();
            }
            if (m_Request.getAllowUserIds())
            {
                writer.writePropertyName("allowUserIds");
                writer.writeArrayStart();
                auto& list = *m_Request.getAllowUserIds();
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
            writer.writeCharArray("matchmaking");
            writer.writePropertyName("component");
            writer.writeCharArray("gathering");
            writer.writePropertyName("function");
            writer.writeCharArray("createGatheringByUserId");
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
        CreateGatheringByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            CreateGatheringByUserIdRequest& request,
            Gs2WebSocketSessionTask<CreateGatheringByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateGatheringByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~CreateGatheringByUserIdTask() GS2_OVERRIDE = default;
    };

    class UpdateGatheringTask : public detail::Gs2WebSocketSessionTask<UpdateGatheringResult>
    {
    private:
        UpdateGatheringRequest& m_Request;

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
            if (m_Request.getGatheringName())
            {
                writer.writePropertyName("gatheringName");
                writer.writeCharArray(*m_Request.getGatheringName());
            }
            if (m_Request.getAttributeRanges())
            {
                writer.writePropertyName("attributeRanges");
                writer.writeArrayStart();
                auto& list = *m_Request.getAttributeRanges();
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
            writer.writeCharArray("matchmaking");
            writer.writePropertyName("component");
            writer.writeCharArray("gathering");
            writer.writePropertyName("function");
            writer.writeCharArray("updateGathering");
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
        UpdateGatheringTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateGatheringRequest& request,
            Gs2WebSocketSessionTask<UpdateGatheringResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateGatheringResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateGatheringTask() GS2_OVERRIDE = default;
    };

    class UpdateGatheringByUserIdTask : public detail::Gs2WebSocketSessionTask<UpdateGatheringByUserIdResult>
    {
    private:
        UpdateGatheringByUserIdRequest& m_Request;

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
            if (m_Request.getGatheringName())
            {
                writer.writePropertyName("gatheringName");
                writer.writeCharArray(*m_Request.getGatheringName());
            }
            if (m_Request.getUserId())
            {
                writer.writePropertyName("userId");
                writer.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getAttributeRanges())
            {
                writer.writePropertyName("attributeRanges");
                writer.writeArrayStart();
                auto& list = *m_Request.getAttributeRanges();
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
            writer.writeCharArray("matchmaking");
            writer.writePropertyName("component");
            writer.writeCharArray("gathering");
            writer.writePropertyName("function");
            writer.writeCharArray("updateGatheringByUserId");
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
        UpdateGatheringByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateGatheringByUserIdRequest& request,
            Gs2WebSocketSessionTask<UpdateGatheringByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateGatheringByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateGatheringByUserIdTask() GS2_OVERRIDE = default;
    };

    class DoMatchmakingByPlayerTask : public detail::Gs2WebSocketSessionTask<DoMatchmakingByPlayerResult>
    {
    private:
        DoMatchmakingByPlayerRequest& m_Request;

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
            if (m_Request.getPlayer())
            {
                writer.writePropertyName("player");
                write(writer, *m_Request.getPlayer());
            }
            if (m_Request.getMatchmakingContextToken())
            {
                writer.writePropertyName("matchmakingContextToken");
                writer.writeCharArray(*m_Request.getMatchmakingContextToken());
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
            writer.writeCharArray("matchmaking");
            writer.writePropertyName("component");
            writer.writeCharArray("gathering");
            writer.writePropertyName("function");
            writer.writeCharArray("doMatchmakingByPlayer");
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
        DoMatchmakingByPlayerTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DoMatchmakingByPlayerRequest& request,
            Gs2WebSocketSessionTask<DoMatchmakingByPlayerResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DoMatchmakingByPlayerResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DoMatchmakingByPlayerTask() GS2_OVERRIDE = default;
    };

    class DoMatchmakingTask : public detail::Gs2WebSocketSessionTask<DoMatchmakingResult>
    {
    private:
        DoMatchmakingRequest& m_Request;

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
            if (m_Request.getPlayer())
            {
                writer.writePropertyName("player");
                write(writer, *m_Request.getPlayer());
            }
            if (m_Request.getMatchmakingContextToken())
            {
                writer.writePropertyName("matchmakingContextToken");
                writer.writeCharArray(*m_Request.getMatchmakingContextToken());
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
            writer.writeCharArray("matchmaking");
            writer.writePropertyName("component");
            writer.writeCharArray("gathering");
            writer.writePropertyName("function");
            writer.writeCharArray("doMatchmaking");
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
        DoMatchmakingTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DoMatchmakingRequest& request,
            Gs2WebSocketSessionTask<DoMatchmakingResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DoMatchmakingResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DoMatchmakingTask() GS2_OVERRIDE = default;
    };

    class GetGatheringTask : public detail::Gs2WebSocketSessionTask<GetGatheringResult>
    {
    private:
        GetGatheringRequest& m_Request;

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
            if (m_Request.getGatheringName())
            {
                writer.writePropertyName("gatheringName");
                writer.writeCharArray(*m_Request.getGatheringName());
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
            writer.writeCharArray("matchmaking");
            writer.writePropertyName("component");
            writer.writeCharArray("gathering");
            writer.writePropertyName("function");
            writer.writeCharArray("getGathering");
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
        GetGatheringTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetGatheringRequest& request,
            Gs2WebSocketSessionTask<GetGatheringResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetGatheringResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetGatheringTask() GS2_OVERRIDE = default;
    };

    class CancelMatchmakingTask : public detail::Gs2WebSocketSessionTask<CancelMatchmakingResult>
    {
    private:
        CancelMatchmakingRequest& m_Request;

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
            if (m_Request.getGatheringName())
            {
                writer.writePropertyName("gatheringName");
                writer.writeCharArray(*m_Request.getGatheringName());
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
            writer.writeCharArray("matchmaking");
            writer.writePropertyName("component");
            writer.writeCharArray("gathering");
            writer.writePropertyName("function");
            writer.writeCharArray("cancelMatchmaking");
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
        CancelMatchmakingTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            CancelMatchmakingRequest& request,
            Gs2WebSocketSessionTask<CancelMatchmakingResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CancelMatchmakingResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~CancelMatchmakingTask() GS2_OVERRIDE = default;
    };

    class CancelMatchmakingByUserIdTask : public detail::Gs2WebSocketSessionTask<CancelMatchmakingByUserIdResult>
    {
    private:
        CancelMatchmakingByUserIdRequest& m_Request;

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
            if (m_Request.getGatheringName())
            {
                writer.writePropertyName("gatheringName");
                writer.writeCharArray(*m_Request.getGatheringName());
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
            writer.writeCharArray("matchmaking");
            writer.writePropertyName("component");
            writer.writeCharArray("gathering");
            writer.writePropertyName("function");
            writer.writeCharArray("cancelMatchmakingByUserId");
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
        CancelMatchmakingByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            CancelMatchmakingByUserIdRequest& request,
            Gs2WebSocketSessionTask<CancelMatchmakingByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CancelMatchmakingByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~CancelMatchmakingByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteGatheringTask : public detail::Gs2WebSocketSessionTask<DeleteGatheringResult>
    {
    private:
        DeleteGatheringRequest& m_Request;

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
            if (m_Request.getGatheringName())
            {
                writer.writePropertyName("gatheringName");
                writer.writeCharArray(*m_Request.getGatheringName());
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
            writer.writeCharArray("matchmaking");
            writer.writePropertyName("component");
            writer.writeCharArray("gathering");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteGathering");
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
        DeleteGatheringTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteGatheringRequest& request,
            Gs2WebSocketSessionTask<DeleteGatheringResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteGatheringResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteGatheringTask() GS2_OVERRIDE = default;
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

    static void write(detail::json::JsonWriter& writer, const Gathering& obj)
    {
        writer.writeObjectStart();
        if (obj.getGatheringId())
        {
            writer.writePropertyName("gatheringId");
            writer.writeCharArray(*obj.getGatheringId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*obj.getName());
        }
        if (obj.getAttributeRanges())
        {
            writer.writePropertyName("attributeRanges");
            writer.writeArrayStart();
            auto& list = *obj.getAttributeRanges();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getCapacityOfRoles())
        {
            writer.writePropertyName("capacityOfRoles");
            writer.writeArrayStart();
            auto& list = *obj.getCapacityOfRoles();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getAllowUserIds())
        {
            writer.writePropertyName("allowUserIds");
            writer.writeArrayStart();
            auto& list = *obj.getAllowUserIds();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                writer.writeCharArray(list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.writeCharArray(*obj.getMetadata());
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

    static void write(detail::json::JsonWriter& writer, const AttributeRange& obj)
    {
        writer.writeObjectStart();
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*obj.getName());
        }
        if (obj.getMin())
        {
            writer.writePropertyName("min");
            writer.writeInt32(*obj.getMin());
        }
        if (obj.getMax())
        {
            writer.writePropertyName("max");
            writer.writeInt32(*obj.getMax());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const CapacityOfRole& obj)
    {
        writer.writeObjectStart();
        if (obj.getRoleName())
        {
            writer.writePropertyName("roleName");
            writer.writeCharArray(*obj.getRoleName());
        }
        if (obj.getRoleAliases())
        {
            writer.writePropertyName("roleAliases");
            writer.writeArrayStart();
            auto& list = *obj.getRoleAliases();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                writer.writeCharArray(list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getCapacity())
        {
            writer.writePropertyName("capacity");
            writer.writeInt32(*obj.getCapacity());
        }
        if (obj.getParticipants())
        {
            writer.writePropertyName("participants");
            writer.writeArrayStart();
            auto& list = *obj.getParticipants();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const Attribute& obj)
    {
        writer.writeObjectStart();
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*obj.getName());
        }
        if (obj.getValue())
        {
            writer.writePropertyName("value");
            writer.writeInt32(*obj.getValue());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const Player& obj)
    {
        writer.writeObjectStart();
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.writeCharArray(*obj.getUserId());
        }
        if (obj.getAttributes())
        {
            writer.writePropertyName("attributes");
            writer.writeArrayStart();
            auto& list = *obj.getAttributes();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getRoleName())
        {
            writer.writePropertyName("roleName");
            writer.writeCharArray(*obj.getRoleName());
        }
        if (obj.getDenyUserIds())
        {
            writer.writePropertyName("denyUserIds");
            writer.writeArrayStart();
            auto& list = *obj.getDenyUserIds();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                writer.writeCharArray(list[i]);
            }
            writer.writeArrayEnd();
        }
        writer.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param gs2WebSocketSession WebSocket API 用セッション
     */
    explicit Gs2MatchmakingWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
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
	 * ギャザリングの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeGatherings(std::function<void(AsyncDescribeGatheringsResult&)> callback, DescribeGatheringsRequest& request)
    {
        DescribeGatheringsTask& task = *new DescribeGatheringsTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ギャザリングを作成して募集を開始<br>
	 *   <br>
	 *   `募集条件` には、作成したギャザリングに参加を許可する各属性値の範囲を指定します。<br>
	 *   <br>
	 *   たとえば、同一ゲームモードを希望するプレイヤーを募集したい場合は、ゲームモードに対応した属性値が完全一致する参加条件プレイヤーとマッチメイキングするように<br>
	 *   `属性名：ゲームモード` `属性最小値: ゲームモードを表す数値` `属性最大値: ゲームモードを表す数値`<br>
	 *   とすることで、同一ゲームモードを希望するプレイヤー同士をマッチメイキングできます。<br>
	 *   <br>
	 *   他にレーティングをベースにしたマッチメイキングを実施したい場合は、<br>
	 *   ルーム作成者のレーティング値を中心とした属性値の範囲を指定することで、レーティング値の近いプレイヤー同士をマッチメイキングできます。<br>
	 *   この `募集条件` はあとで更新することができますので、徐々に条件を緩和していくことができます。<br>
	 *   <br>
	 *   ロール とは 盾役1人・回復役1人・攻撃役2人 などの役割ごとに募集人数を設定したい場合に使用します。<br>
	 *   ロールにはエイリアスを指定できます。<br>
	 *   たとえば、盾役は パラディン と ナイト の2種類の `ジョブ` に更に分類できるとします。<br>
	 *   この場合、ロール名 に `盾役` エイリアス に `パラディン` `ナイト` として募集を出すようにゲームを実装します。<br>
	 *   そして、プレイヤーは自分自身の `ジョブ` を自身のプレイヤー情報のロールに指定します。<br>
	 *   <br>
	 *   こうすることで、募集条件が `盾役` になっているギャザリングには `パラディン` も `ナイト` も参加できます。<br>
	 *   一方で、ギャザリングを作成するときに、 `パラディン` だけ募集したくて、 `ナイト` を募集したくない場合は、<br>
	 *   募集するロール名に `パラディン` を直接指定したり、エイリアスに `ナイト` を含めないようにすることで実現できます。<br>
	 *   <br>
	 *   `参加者` の `募集人数` はプレイヤーの募集人数を指定します。ロール名を指定することで、ロール名ごとの募集人数を設定できます。<br>
	 *   <br>
	 *   `参加者` の `参加者のプレイヤー情報リスト` には事前にプレイヤー間でパーティを構築している場合や、参加者が離脱したあとの追加募集で使用します。<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createGathering(std::function<void(AsyncCreateGatheringResult&)> callback, CreateGatheringRequest& request)
    {
        CreateGatheringTask& task = *new CreateGatheringTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ギャザリングを作成して募集を開始<br>
	 *   <br>
	 *   `募集条件` には、作成したギャザリングに参加を許可する各属性値の範囲を指定します。<br>
	 *   <br>
	 *   たとえば、同一ゲームモードを希望するプレイヤーを募集したい場合は、ゲームモードに対応した属性値が完全一致する参加条件プレイヤーとマッチメイキングするように<br>
	 *   `属性名：ゲームモード` `属性最小値: ゲームモードを表す数値` `属性最大値: ゲームモードを表す数値`<br>
	 *   とすることで、同一ゲームモードを希望するプレイヤー同士をマッチメイキングできます。<br>
	 *   <br>
	 *   他にレーティングをベースにしたマッチメイキングを実施したい場合は、<br>
	 *   ルーム作成者のレーティング値を中心とした属性値の範囲を指定することで、レーティング値の近いプレイヤー同士をマッチメイキングできます。<br>
	 *   この `募集条件` はあとで更新することができますので、徐々に条件を緩和していくことができます。<br>
	 *   <br>
	 *   ロール とは 盾役1人・回復役1人・攻撃役2人 などの役割ごとに募集人数を設定したい場合に使用します。<br>
	 *   ロールにはエイリアスを指定できます。<br>
	 *   たとえば、盾役は パラディン と ナイト の2種類の `ジョブ` に更に分類できるとします。<br>
	 *   この場合、ロール名 に `盾役` エイリアス に `パラディン` `ナイト` として募集を出すようにゲームを実装します。<br>
	 *   そして、プレイヤーは自分自身の `ジョブ` を自身のプレイヤー情報のロールに指定します。<br>
	 *   <br>
	 *   こうすることで、募集条件が `盾役` になっているギャザリングには `パラディン` も `ナイト` も参加できます。<br>
	 *   一方で、ギャザリングを作成するときに、 `パラディン` だけ募集したくて、 `ナイト` を募集したくない場合は、<br>
	 *   募集するロール名に `パラディン` を直接指定したり、エイリアスに `ナイト` を含めないようにすることで実現できます。<br>
	 *   <br>
	 *   `参加者` の `募集人数` はプレイヤーの募集人数を指定します。ロール名を指定することで、ロール名ごとの募集人数を設定できます。<br>
	 *   <br>
	 *   `参加者` の `参加者のプレイヤー情報リスト` には事前にプレイヤー間でパーティを構築している場合や、参加者が離脱したあとの追加募集で使用します。<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createGatheringByUserId(std::function<void(AsyncCreateGatheringByUserIdResult&)> callback, CreateGatheringByUserIdRequest& request)
    {
        CreateGatheringByUserIdTask& task = *new CreateGatheringByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ギャザリングを更新する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateGathering(std::function<void(AsyncUpdateGatheringResult&)> callback, UpdateGatheringRequest& request)
    {
        UpdateGatheringTask& task = *new UpdateGatheringTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ギャザリングを更新する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateGatheringByUserId(std::function<void(AsyncUpdateGatheringByUserIdResult&)> callback, UpdateGatheringByUserIdRequest& request)
    {
        UpdateGatheringByUserIdTask& task = *new UpdateGatheringByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * Player が参加できるギャザリングを探して参加する<br>
	 *   <br>
	 *   一定時間 検索を行い、対象が見つからなかったときには `マッチメイキングの状態を保持するトークン` を返す。<br>
	 *   次回 `マッチメイキングの状態を保持するトークン` をつけて再度リクエストを出すことで、前回の続きから検索処理を再開できる。<br>
	 *   すべてのギャザリングを検索したが、参加できるギャザリングが存在しなかった場合はギャザリングもトークンもどちらも null が応答される。<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void doMatchmakingByPlayer(std::function<void(AsyncDoMatchmakingByPlayerResult&)> callback, DoMatchmakingByPlayerRequest& request)
    {
        DoMatchmakingByPlayerTask& task = *new DoMatchmakingByPlayerTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 自分が参加できるギャザリングを探して参加する<br>
	 *   <br>
	 *   一定時間 検索を行い、対象が見つからなかったときには `マッチメイキングの状態を保持するトークン` を返す。<br>
	 *   次回 `マッチメイキングの状態を保持するトークン` をつけて再度リクエストを出すことで、前回の続きから検索処理を再開できる。<br>
	 *   すべてのギャザリングを検索したが、参加できるギャザリングが存在しなかった場合はギャザリングもトークンもどちらも null が応答される。<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void doMatchmaking(std::function<void(AsyncDoMatchmakingResult&)> callback, DoMatchmakingRequest& request)
    {
        DoMatchmakingTask& task = *new DoMatchmakingTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ギャザリングを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getGathering(std::function<void(AsyncGetGatheringResult&)> callback, GetGatheringRequest& request)
    {
        GetGatheringTask& task = *new GetGatheringTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * マッチメイキングをキャンセルする<br>
	 *   <br>
	 *   ギャザリングから離脱する前にマッチメイキングが完了した場合は、NotFoundException(404エラー) が発生し失敗します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void cancelMatchmaking(std::function<void(AsyncCancelMatchmakingResult&)> callback, CancelMatchmakingRequest& request)
    {
        CancelMatchmakingTask& task = *new CancelMatchmakingTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザIDを指定してマッチメイキングをキャンセルする<br>
	 *   <br>
	 *   ギャザリングから離脱する前にマッチメイキングが完了した場合は、NotFoundException(404エラー) が発生し失敗します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void cancelMatchmakingByUserId(std::function<void(AsyncCancelMatchmakingByUserIdResult&)> callback, CancelMatchmakingByUserIdRequest& request)
    {
        CancelMatchmakingByUserIdTask& task = *new CancelMatchmakingByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ギャザリングを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteGathering(std::function<void(AsyncDeleteGatheringResult&)> callback, DeleteGatheringRequest& request)
    {
        DeleteGatheringTask& task = *new DeleteGatheringTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_MATCHMAKING_GS2MATCHMAKINGWEBSOCKETCLIENT_HPP_