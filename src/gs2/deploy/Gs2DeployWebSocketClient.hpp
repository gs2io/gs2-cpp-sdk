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

#ifndef GS2_DEPLOY_GS2DEPLOYWEBSOCKETCLIENT_HPP_
#define GS2_DEPLOY_GS2DEPLOYWEBSOCKETCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2WebSocketSessionTask.hpp>
#include <gs2/core/network/Gs2WebSocketSession.hpp>
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "model/model.hpp"
#include "request/DescribeStacksRequest.hpp"
#include "request/CreateStackRequest.hpp"
#include "request/CreateStackFromGitHubRequest.hpp"
#include "request/GetStackStatusRequest.hpp"
#include "request/GetStackRequest.hpp"
#include "request/UpdateStackRequest.hpp"
#include "request/UpdateStackFromGitHubRequest.hpp"
#include "request/DeleteStackRequest.hpp"
#include "request/ForceDeleteStackRequest.hpp"
#include "request/DescribeResourcesRequest.hpp"
#include "request/GetResourceRequest.hpp"
#include "request/DescribeEventsRequest.hpp"
#include "request/GetEventRequest.hpp"
#include "request/DescribeOutputsRequest.hpp"
#include "request/GetOutputRequest.hpp"
#include "result/DescribeStacksResult.hpp"
#include "result/CreateStackResult.hpp"
#include "result/CreateStackFromGitHubResult.hpp"
#include "result/GetStackStatusResult.hpp"
#include "result/GetStackResult.hpp"
#include "result/UpdateStackResult.hpp"
#include "result/UpdateStackFromGitHubResult.hpp"
#include "result/DeleteStackResult.hpp"
#include "result/ForceDeleteStackResult.hpp"
#include "result/DescribeResourcesResult.hpp"
#include "result/GetResourceResult.hpp"
#include "result/DescribeEventsResult.hpp"
#include "result/GetEventResult.hpp"
#include "result/DescribeOutputsResult.hpp"
#include "result/GetOutputResult.hpp"
#include <cstring>

namespace gs2 { namespace deploy {

typedef AsyncResult<DescribeStacksResult> AsyncDescribeStacksResult;
typedef AsyncResult<CreateStackResult> AsyncCreateStackResult;
typedef AsyncResult<CreateStackFromGitHubResult> AsyncCreateStackFromGitHubResult;
typedef AsyncResult<GetStackStatusResult> AsyncGetStackStatusResult;
typedef AsyncResult<GetStackResult> AsyncGetStackResult;
typedef AsyncResult<UpdateStackResult> AsyncUpdateStackResult;
typedef AsyncResult<UpdateStackFromGitHubResult> AsyncUpdateStackFromGitHubResult;
typedef AsyncResult<DeleteStackResult> AsyncDeleteStackResult;
typedef AsyncResult<ForceDeleteStackResult> AsyncForceDeleteStackResult;
typedef AsyncResult<DescribeResourcesResult> AsyncDescribeResourcesResult;
typedef AsyncResult<GetResourceResult> AsyncGetResourceResult;
typedef AsyncResult<DescribeEventsResult> AsyncDescribeEventsResult;
typedef AsyncResult<GetEventResult> AsyncGetEventResult;
typedef AsyncResult<DescribeOutputsResult> AsyncDescribeOutputsResult;
typedef AsyncResult<GetOutputResult> AsyncGetOutputResult;

/**
 * GS2 Deploy API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2DeployWebSocketClient : public AbstractGs2ClientBase
{
private:

    class DescribeStacksTask : public detail::Gs2WebSocketSessionTask<DescribeStacksResult>
    {
    private:
        DescribeStacksRequest& m_Request;

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
            writer.writeCharArray("deploy");
            writer.writePropertyName("component");
            writer.writeCharArray("stack");
            writer.writePropertyName("function");
            writer.writeCharArray("describeStacks");
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
        DescribeStacksTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeStacksRequest& request,
            Gs2WebSocketSessionTask<DescribeStacksResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeStacksResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeStacksTask() GS2_OVERRIDE = default;
    };

    class CreateStackTask : public detail::Gs2WebSocketSessionTask<CreateStackResult>
    {
    private:
        CreateStackRequest& m_Request;

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
            if (m_Request.getTemplate())
            {
                writer.writePropertyName("template");
                writer.writeCharArray(*m_Request.getTemplate());
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
            writer.writeCharArray("deploy");
            writer.writePropertyName("component");
            writer.writeCharArray("stack");
            writer.writePropertyName("function");
            writer.writeCharArray("createStack");
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
        CreateStackTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            CreateStackRequest& request,
            Gs2WebSocketSessionTask<CreateStackResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateStackResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~CreateStackTask() GS2_OVERRIDE = default;
    };

    class CreateStackFromGitHubTask : public detail::Gs2WebSocketSessionTask<CreateStackFromGitHubResult>
    {
    private:
        CreateStackFromGitHubRequest& m_Request;

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
            writer.writeCharArray("deploy");
            writer.writePropertyName("component");
            writer.writeCharArray("stack");
            writer.writePropertyName("function");
            writer.writeCharArray("createStackFromGitHub");
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
        CreateStackFromGitHubTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            CreateStackFromGitHubRequest& request,
            Gs2WebSocketSessionTask<CreateStackFromGitHubResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateStackFromGitHubResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~CreateStackFromGitHubTask() GS2_OVERRIDE = default;
    };

    class GetStackStatusTask : public detail::Gs2WebSocketSessionTask<GetStackStatusResult>
    {
    private:
        GetStackStatusRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getStackName())
            {
                writer.writePropertyName("stackName");
                writer.writeCharArray(*m_Request.getStackName());
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
            writer.writeCharArray("deploy");
            writer.writePropertyName("component");
            writer.writeCharArray("stack");
            writer.writePropertyName("function");
            writer.writeCharArray("getStackStatus");
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
        GetStackStatusTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetStackStatusRequest& request,
            Gs2WebSocketSessionTask<GetStackStatusResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetStackStatusResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetStackStatusTask() GS2_OVERRIDE = default;
    };

    class GetStackTask : public detail::Gs2WebSocketSessionTask<GetStackResult>
    {
    private:
        GetStackRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getStackName())
            {
                writer.writePropertyName("stackName");
                writer.writeCharArray(*m_Request.getStackName());
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
            writer.writeCharArray("deploy");
            writer.writePropertyName("component");
            writer.writeCharArray("stack");
            writer.writePropertyName("function");
            writer.writeCharArray("getStack");
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
        GetStackTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetStackRequest& request,
            Gs2WebSocketSessionTask<GetStackResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetStackResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetStackTask() GS2_OVERRIDE = default;
    };

    class UpdateStackTask : public detail::Gs2WebSocketSessionTask<UpdateStackResult>
    {
    private:
        UpdateStackRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getStackName())
            {
                writer.writePropertyName("stackName");
                writer.writeCharArray(*m_Request.getStackName());
            }
            if (m_Request.getDescription())
            {
                writer.writePropertyName("description");
                writer.writeCharArray(*m_Request.getDescription());
            }
            if (m_Request.getTemplate())
            {
                writer.writePropertyName("template");
                writer.writeCharArray(*m_Request.getTemplate());
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
            writer.writeCharArray("deploy");
            writer.writePropertyName("component");
            writer.writeCharArray("stack");
            writer.writePropertyName("function");
            writer.writeCharArray("updateStack");
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
        UpdateStackTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateStackRequest& request,
            Gs2WebSocketSessionTask<UpdateStackResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateStackResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateStackTask() GS2_OVERRIDE = default;
    };

    class UpdateStackFromGitHubTask : public detail::Gs2WebSocketSessionTask<UpdateStackFromGitHubResult>
    {
    private:
        UpdateStackFromGitHubRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getStackName())
            {
                writer.writePropertyName("stackName");
                writer.writeCharArray(*m_Request.getStackName());
            }
            if (m_Request.getDescription())
            {
                writer.writePropertyName("description");
                writer.writeCharArray(*m_Request.getDescription());
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
            writer.writeCharArray("deploy");
            writer.writePropertyName("component");
            writer.writeCharArray("stack");
            writer.writePropertyName("function");
            writer.writeCharArray("updateStackFromGitHub");
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
        UpdateStackFromGitHubTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateStackFromGitHubRequest& request,
            Gs2WebSocketSessionTask<UpdateStackFromGitHubResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateStackFromGitHubResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateStackFromGitHubTask() GS2_OVERRIDE = default;
    };

    class DeleteStackTask : public detail::Gs2WebSocketSessionTask<DeleteStackResult>
    {
    private:
        DeleteStackRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getStackName())
            {
                writer.writePropertyName("stackName");
                writer.writeCharArray(*m_Request.getStackName());
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
            writer.writeCharArray("deploy");
            writer.writePropertyName("component");
            writer.writeCharArray("stack");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteStack");
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
        DeleteStackTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteStackRequest& request,
            Gs2WebSocketSessionTask<DeleteStackResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteStackResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteStackTask() GS2_OVERRIDE = default;
    };

    class ForceDeleteStackTask : public detail::Gs2WebSocketSessionTask<ForceDeleteStackResult>
    {
    private:
        ForceDeleteStackRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getStackName())
            {
                writer.writePropertyName("stackName");
                writer.writeCharArray(*m_Request.getStackName());
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
            writer.writeCharArray("deploy");
            writer.writePropertyName("component");
            writer.writeCharArray("stack");
            writer.writePropertyName("function");
            writer.writeCharArray("forceDeleteStack");
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
        ForceDeleteStackTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            ForceDeleteStackRequest& request,
            Gs2WebSocketSessionTask<ForceDeleteStackResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<ForceDeleteStackResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~ForceDeleteStackTask() GS2_OVERRIDE = default;
    };

    class DescribeResourcesTask : public detail::Gs2WebSocketSessionTask<DescribeResourcesResult>
    {
    private:
        DescribeResourcesRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getStackName())
            {
                writer.writePropertyName("stackName");
                writer.writeCharArray(*m_Request.getStackName());
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
            writer.writeCharArray("deploy");
            writer.writePropertyName("component");
            writer.writeCharArray("resource");
            writer.writePropertyName("function");
            writer.writeCharArray("describeResources");
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
        DescribeResourcesTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeResourcesRequest& request,
            Gs2WebSocketSessionTask<DescribeResourcesResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeResourcesResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeResourcesTask() GS2_OVERRIDE = default;
    };

    class GetResourceTask : public detail::Gs2WebSocketSessionTask<GetResourceResult>
    {
    private:
        GetResourceRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getStackName())
            {
                writer.writePropertyName("stackName");
                writer.writeCharArray(*m_Request.getStackName());
            }
            if (m_Request.getResourceName())
            {
                writer.writePropertyName("resourceName");
                writer.writeCharArray(*m_Request.getResourceName());
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
            writer.writeCharArray("deploy");
            writer.writePropertyName("component");
            writer.writeCharArray("resource");
            writer.writePropertyName("function");
            writer.writeCharArray("getResource");
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
        GetResourceTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetResourceRequest& request,
            Gs2WebSocketSessionTask<GetResourceResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetResourceResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetResourceTask() GS2_OVERRIDE = default;
    };

    class DescribeEventsTask : public detail::Gs2WebSocketSessionTask<DescribeEventsResult>
    {
    private:
        DescribeEventsRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getStackName())
            {
                writer.writePropertyName("stackName");
                writer.writeCharArray(*m_Request.getStackName());
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
            writer.writeCharArray("deploy");
            writer.writePropertyName("component");
            writer.writeCharArray("event");
            writer.writePropertyName("function");
            writer.writeCharArray("describeEvents");
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
        DescribeEventsTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeEventsRequest& request,
            Gs2WebSocketSessionTask<DescribeEventsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeEventsResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeEventsTask() GS2_OVERRIDE = default;
    };

    class GetEventTask : public detail::Gs2WebSocketSessionTask<GetEventResult>
    {
    private:
        GetEventRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getStackName())
            {
                writer.writePropertyName("stackName");
                writer.writeCharArray(*m_Request.getStackName());
            }
            if (m_Request.getEventName())
            {
                writer.writePropertyName("eventName");
                writer.writeCharArray(*m_Request.getEventName());
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
            writer.writeCharArray("deploy");
            writer.writePropertyName("component");
            writer.writeCharArray("event");
            writer.writePropertyName("function");
            writer.writeCharArray("getEvent");
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
        GetEventTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetEventRequest& request,
            Gs2WebSocketSessionTask<GetEventResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetEventResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetEventTask() GS2_OVERRIDE = default;
    };

    class DescribeOutputsTask : public detail::Gs2WebSocketSessionTask<DescribeOutputsResult>
    {
    private:
        DescribeOutputsRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getStackName())
            {
                writer.writePropertyName("stackName");
                writer.writeCharArray(*m_Request.getStackName());
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
            writer.writeCharArray("deploy");
            writer.writePropertyName("component");
            writer.writeCharArray("output");
            writer.writePropertyName("function");
            writer.writeCharArray("describeOutputs");
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
        DescribeOutputsTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeOutputsRequest& request,
            Gs2WebSocketSessionTask<DescribeOutputsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeOutputsResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeOutputsTask() GS2_OVERRIDE = default;
    };

    class GetOutputTask : public detail::Gs2WebSocketSessionTask<GetOutputResult>
    {
    private:
        GetOutputRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            auto& writer = detail::json::JsonWriter::getInstance();
            writer.reset();
            writer.writeObjectStart();

            if (m_Request.getStackName())
            {
                writer.writePropertyName("stackName");
                writer.writeCharArray(*m_Request.getStackName());
            }
            if (m_Request.getOutputName())
            {
                writer.writePropertyName("outputName");
                writer.writeCharArray(*m_Request.getOutputName());
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
            writer.writeCharArray("deploy");
            writer.writePropertyName("component");
            writer.writeCharArray("output");
            writer.writePropertyName("function");
            writer.writeCharArray("getOutput");
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
        GetOutputTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetOutputRequest& request,
            Gs2WebSocketSessionTask<GetOutputResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetOutputResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetOutputTask() GS2_OVERRIDE = default;
    };

private:
    static void write(detail::json::JsonWriter& writer, const Stack& obj)
    {
        writer.writeObjectStart();
        if (obj.getStackId())
        {
            writer.writePropertyName("stackId");
            writer.writeCharArray(*obj.getStackId());
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
        if (obj.getTemplate())
        {
            writer.writePropertyName("template");
            writer.writeCharArray(*obj.getTemplate());
        }
        if (obj.getStatus())
        {
            writer.writePropertyName("status");
            writer.writeCharArray(*obj.getStatus());
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

    static void write(detail::json::JsonWriter& writer, const Resource& obj)
    {
        writer.writeObjectStart();
        if (obj.getResourceId())
        {
            writer.writePropertyName("resourceId");
            writer.writeCharArray(*obj.getResourceId());
        }
        if (obj.getType())
        {
            writer.writePropertyName("type");
            writer.writeCharArray(*obj.getType());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*obj.getName());
        }
        if (obj.getRequest())
        {
            writer.writePropertyName("request");
            writer.writeCharArray(*obj.getRequest());
        }
        if (obj.getResponse())
        {
            writer.writePropertyName("response");
            writer.writeCharArray(*obj.getResponse());
        }
        if (obj.getRollbackContext())
        {
            writer.writePropertyName("rollbackContext");
            writer.writeCharArray(*obj.getRollbackContext());
        }
        if (obj.getRollbackRequest())
        {
            writer.writePropertyName("rollbackRequest");
            writer.writeCharArray(*obj.getRollbackRequest());
        }
        if (obj.getRollbackAfter())
        {
            writer.writePropertyName("rollbackAfter");
            writer.writeArrayStart();
            auto& list = *obj.getRollbackAfter();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                writer.writeCharArray(list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getOutputKeys())
        {
            writer.writePropertyName("outputKeys");
            writer.writeArrayStart();
            auto& list = *obj.getOutputKeys();
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
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const WorkingStack& obj)
    {
        writer.writeObjectStart();
        if (obj.getStackId())
        {
            writer.writePropertyName("stackId");
            writer.writeCharArray(*obj.getStackId());
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

    static void write(detail::json::JsonWriter& writer, const WorkingResource& obj)
    {
        writer.writeObjectStart();
        if (obj.getResourceId())
        {
            writer.writePropertyName("resourceId");
            writer.writeCharArray(*obj.getResourceId());
        }
        if (obj.getContext())
        {
            writer.writePropertyName("context");
            writer.writeCharArray(*obj.getContext());
        }
        if (obj.getType())
        {
            writer.writePropertyName("type");
            writer.writeCharArray(*obj.getType());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*obj.getName());
        }
        if (obj.getRequest())
        {
            writer.writePropertyName("request");
            writer.writeCharArray(*obj.getRequest());
        }
        if (obj.getAfter())
        {
            writer.writePropertyName("after");
            writer.writeArrayStart();
            auto& list = *obj.getAfter();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                writer.writeCharArray(list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getRollbackContext())
        {
            writer.writePropertyName("rollbackContext");
            writer.writeCharArray(*obj.getRollbackContext());
        }
        if (obj.getRollbackRequest())
        {
            writer.writePropertyName("rollbackRequest");
            writer.writeCharArray(*obj.getRollbackRequest());
        }
        if (obj.getRollbackAfter())
        {
            writer.writePropertyName("rollbackAfter");
            writer.writeArrayStart();
            auto& list = *obj.getRollbackAfter();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                writer.writeCharArray(list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getOutputFields())
        {
            writer.writePropertyName("outputFields");
            writer.writeArrayStart();
            auto& list = *obj.getOutputFields();
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

    static void write(detail::json::JsonWriter& writer, const Event& obj)
    {
        writer.writeObjectStart();
        if (obj.getEventId())
        {
            writer.writePropertyName("eventId");
            writer.writeCharArray(*obj.getEventId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*obj.getName());
        }
        if (obj.getResourceName())
        {
            writer.writePropertyName("resourceName");
            writer.writeCharArray(*obj.getResourceName());
        }
        if (obj.getType())
        {
            writer.writePropertyName("type");
            writer.writeCharArray(*obj.getType());
        }
        if (obj.getMessage())
        {
            writer.writePropertyName("message");
            writer.writeCharArray(*obj.getMessage());
        }
        if (obj.getEventAt())
        {
            writer.writePropertyName("eventAt");
            writer.writeInt64(*obj.getEventAt());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const Output& obj)
    {
        writer.writeObjectStart();
        if (obj.getOutputId())
        {
            writer.writePropertyName("outputId");
            writer.writeCharArray(*obj.getOutputId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*obj.getName());
        }
        if (obj.getValue())
        {
            writer.writePropertyName("value");
            writer.writeCharArray(*obj.getValue());
        }
        if (obj.getCreatedAt())
        {
            writer.writePropertyName("createdAt");
            writer.writeInt64(*obj.getCreatedAt());
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

    static void write(detail::json::JsonWriter& writer, const OutputField& obj)
    {
        writer.writeObjectStart();
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*obj.getName());
        }
        if (obj.getFieldName())
        {
            writer.writePropertyName("fieldName");
            writer.writeCharArray(*obj.getFieldName());
        }
        writer.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param gs2WebSocketSession WebSocket API 用セッション
     */
    explicit Gs2DeployWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
        AbstractGs2ClientBase(gs2WebSocketSession)
    {
    }

	/**
	 * スタックの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeStacks(std::function<void(AsyncDescribeStacksResult&)> callback, DescribeStacksRequest& request)
    {
        DescribeStacksTask& task = *new DescribeStacksTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * スタックを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createStack(std::function<void(AsyncCreateStackResult&)> callback, CreateStackRequest& request)
    {
        CreateStackTask& task = *new CreateStackTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * スタックを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createStackFromGitHub(std::function<void(AsyncCreateStackFromGitHubResult&)> callback, CreateStackFromGitHubRequest& request)
    {
        CreateStackFromGitHubTask& task = *new CreateStackFromGitHubTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * スタックを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStackStatus(std::function<void(AsyncGetStackStatusResult&)> callback, GetStackStatusRequest& request)
    {
        GetStackStatusTask& task = *new GetStackStatusTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * スタックを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStack(std::function<void(AsyncGetStackResult&)> callback, GetStackRequest& request)
    {
        GetStackTask& task = *new GetStackTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * スタックを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateStack(std::function<void(AsyncUpdateStackResult&)> callback, UpdateStackRequest& request)
    {
        UpdateStackTask& task = *new UpdateStackTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * スタックを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateStackFromGitHub(std::function<void(AsyncUpdateStackFromGitHubResult&)> callback, UpdateStackFromGitHubRequest& request)
    {
        UpdateStackFromGitHubTask& task = *new UpdateStackFromGitHubTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * スタックを削除<br>
	 *   <br>
	 *   スタックの削除は2段階で行われます。<br>
	 *   DELETE_COMPLETED ステータスではないスタックを削除すると、まずはスタックによって作成されたリソースの削除を行います。<br>
	 *   DELETE_COMPLETED ステータスのスタックを削除すると、完全にエンティティを削除します。<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteStack(std::function<void(AsyncDeleteStackResult&)> callback, DeleteStackRequest& request)
    {
        DeleteStackTask& task = *new DeleteStackTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * スタックを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void forceDeleteStack(std::function<void(AsyncForceDeleteStackResult&)> callback, ForceDeleteStackRequest& request)
    {
        ForceDeleteStackTask& task = *new ForceDeleteStackTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 作成されたのリソースの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeResources(std::function<void(AsyncDescribeResourcesResult&)> callback, DescribeResourcesRequest& request)
    {
        DescribeResourcesTask& task = *new DescribeResourcesTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 作成されたのリソースを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getResource(std::function<void(AsyncGetResourceResult&)> callback, GetResourceRequest& request)
    {
        GetResourceTask& task = *new GetResourceTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 発生したイベントの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeEvents(std::function<void(AsyncDescribeEventsResult&)> callback, DescribeEventsRequest& request)
    {
        DescribeEventsTask& task = *new DescribeEventsTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 発生したイベントを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getEvent(std::function<void(AsyncGetEventResult&)> callback, GetEventRequest& request)
    {
        GetEventTask& task = *new GetEventTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * アウトプットの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeOutputs(std::function<void(AsyncDescribeOutputsResult&)> callback, DescribeOutputsRequest& request)
    {
        DescribeOutputsTask& task = *new DescribeOutputsTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * アウトプットを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getOutput(std::function<void(AsyncGetOutputResult&)> callback, GetOutputRequest& request)
    {
        GetOutputTask& task = *new GetOutputTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_DEPLOY_GS2DEPLOYWEBSOCKETCLIENT_HPP_