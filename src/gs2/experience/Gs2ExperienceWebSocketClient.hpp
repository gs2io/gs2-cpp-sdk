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

#ifndef GS2_EXPERIENCE_GS2EXPERIENCEWEBSOCKETCLIENT_HPP_
#define GS2_EXPERIENCE_GS2EXPERIENCEWEBSOCKETCLIENT_HPP_

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
#include "request/DescribeExperienceModelMastersRequest.hpp"
#include "request/CreateExperienceModelMasterRequest.hpp"
#include "request/GetExperienceModelMasterRequest.hpp"
#include "request/UpdateExperienceModelMasterRequest.hpp"
#include "request/DeleteExperienceModelMasterRequest.hpp"
#include "request/DescribeExperienceModelsRequest.hpp"
#include "request/GetExperienceModelRequest.hpp"
#include "request/DescribeThresholdMastersRequest.hpp"
#include "request/CreateThresholdMasterRequest.hpp"
#include "request/GetThresholdMasterRequest.hpp"
#include "request/UpdateThresholdMasterRequest.hpp"
#include "request/DeleteThresholdMasterRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentExperienceMasterRequest.hpp"
#include "request/UpdateCurrentExperienceMasterRequest.hpp"
#include "request/UpdateCurrentExperienceMasterFromGitHubRequest.hpp"
#include "request/DescribeStatusesRequest.hpp"
#include "request/DescribeStatusesByUserIdRequest.hpp"
#include "request/GetStatusRequest.hpp"
#include "request/GetStatusByUserIdRequest.hpp"
#include "request/GetStatusWithSignatureRequest.hpp"
#include "request/AddExperienceByUserIdRequest.hpp"
#include "request/SetExperienceByUserIdRequest.hpp"
#include "request/AddRankCapByUserIdRequest.hpp"
#include "request/SetRankCapByUserIdRequest.hpp"
#include "request/DeleteStatusByUserIdRequest.hpp"
#include "request/AddExperienceByStampSheetRequest.hpp"
#include "request/AddRankCapByStampSheetRequest.hpp"
#include "request/SetRankCapByStampSheetRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeExperienceModelMastersResult.hpp"
#include "result/CreateExperienceModelMasterResult.hpp"
#include "result/GetExperienceModelMasterResult.hpp"
#include "result/UpdateExperienceModelMasterResult.hpp"
#include "result/DeleteExperienceModelMasterResult.hpp"
#include "result/DescribeExperienceModelsResult.hpp"
#include "result/GetExperienceModelResult.hpp"
#include "result/DescribeThresholdMastersResult.hpp"
#include "result/CreateThresholdMasterResult.hpp"
#include "result/GetThresholdMasterResult.hpp"
#include "result/UpdateThresholdMasterResult.hpp"
#include "result/DeleteThresholdMasterResult.hpp"
#include "result/ExportMasterResult.hpp"
#include "result/GetCurrentExperienceMasterResult.hpp"
#include "result/UpdateCurrentExperienceMasterResult.hpp"
#include "result/UpdateCurrentExperienceMasterFromGitHubResult.hpp"
#include "result/DescribeStatusesResult.hpp"
#include "result/DescribeStatusesByUserIdResult.hpp"
#include "result/GetStatusResult.hpp"
#include "result/GetStatusByUserIdResult.hpp"
#include "result/GetStatusWithSignatureResult.hpp"
#include "result/AddExperienceByUserIdResult.hpp"
#include "result/SetExperienceByUserIdResult.hpp"
#include "result/AddRankCapByUserIdResult.hpp"
#include "result/SetRankCapByUserIdResult.hpp"
#include "result/DeleteStatusByUserIdResult.hpp"
#include "result/AddExperienceByStampSheetResult.hpp"
#include "result/AddRankCapByStampSheetResult.hpp"
#include "result/SetRankCapByStampSheetResult.hpp"
#include <cstring>

namespace gs2 { namespace experience {

/**
 * GS2 Experience API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2ExperienceWebSocketClient : public AbstractGs2ClientBase
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

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
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
            writer.writeCharArray("experience");
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

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
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
            if (m_Request.getExperienceCapScriptId())
            {
                writer.writePropertyName("experienceCapScriptId");
                writer.writeCharArray(*m_Request.getExperienceCapScriptId());
            }
            if (m_Request.getChangeExperienceScript())
            {
                writer.writePropertyName("changeExperienceScript");
                write(writer, *m_Request.getChangeExperienceScript());
            }
            if (m_Request.getChangeRankScript())
            {
                writer.writePropertyName("changeRankScript");
                write(writer, *m_Request.getChangeRankScript());
            }
            if (m_Request.getChangeRankCapScript())
            {
                writer.writePropertyName("changeRankCapScript");
                write(writer, *m_Request.getChangeRankCapScript());
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
            writer.writeCharArray("experience");
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

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
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
            writer.writeCharArray("experience");
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

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
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
            writer.writeCharArray("experience");
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

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
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
            if (m_Request.getExperienceCapScriptId())
            {
                writer.writePropertyName("experienceCapScriptId");
                writer.writeCharArray(*m_Request.getExperienceCapScriptId());
            }
            if (m_Request.getChangeExperienceScript())
            {
                writer.writePropertyName("changeExperienceScript");
                write(writer, *m_Request.getChangeExperienceScript());
            }
            if (m_Request.getChangeRankScript())
            {
                writer.writePropertyName("changeRankScript");
                write(writer, *m_Request.getChangeRankScript());
            }
            if (m_Request.getChangeRankCapScript())
            {
                writer.writePropertyName("changeRankCapScript");
                write(writer, *m_Request.getChangeRankCapScript());
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
            writer.writeCharArray("experience");
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

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
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
            writer.writeCharArray("experience");
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

    class DescribeExperienceModelMastersTask : public detail::Gs2WebSocketSessionTask<DescribeExperienceModelMastersResult>
    {
    private:
        DescribeExperienceModelMastersRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
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
            writer.writeCharArray("experience");
            writer.writePropertyName("component");
            writer.writeCharArray("experienceModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("describeExperienceModelMasters");
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
        DescribeExperienceModelMastersTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeExperienceModelMastersRequest& request,
            Gs2WebSocketSessionTask<DescribeExperienceModelMastersResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeExperienceModelMastersResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeExperienceModelMastersTask() GS2_OVERRIDE = default;
    };

    class CreateExperienceModelMasterTask : public detail::Gs2WebSocketSessionTask<CreateExperienceModelMasterResult>
    {
    private:
        CreateExperienceModelMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
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
            if (m_Request.getDefaultExperience())
            {
                writer.writePropertyName("defaultExperience");
                writer.writeInt64(*m_Request.getDefaultExperience());
            }
            if (m_Request.getDefaultRankCap())
            {
                writer.writePropertyName("defaultRankCap");
                writer.writeInt64(*m_Request.getDefaultRankCap());
            }
            if (m_Request.getMaxRankCap())
            {
                writer.writePropertyName("maxRankCap");
                writer.writeInt64(*m_Request.getMaxRankCap());
            }
            if (m_Request.getRankThresholdId())
            {
                writer.writePropertyName("rankThresholdId");
                writer.writeCharArray(*m_Request.getRankThresholdId());
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
            writer.writeCharArray("experience");
            writer.writePropertyName("component");
            writer.writeCharArray("experienceModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("createExperienceModelMaster");
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
        CreateExperienceModelMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            CreateExperienceModelMasterRequest& request,
            Gs2WebSocketSessionTask<CreateExperienceModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateExperienceModelMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~CreateExperienceModelMasterTask() GS2_OVERRIDE = default;
    };

    class GetExperienceModelMasterTask : public detail::Gs2WebSocketSessionTask<GetExperienceModelMasterResult>
    {
    private:
        GetExperienceModelMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getExperienceName())
            {
                writer.writePropertyName("experienceName");
                writer.writeCharArray(*m_Request.getExperienceName());
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
            writer.writeCharArray("experience");
            writer.writePropertyName("component");
            writer.writeCharArray("experienceModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("getExperienceModelMaster");
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
        GetExperienceModelMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetExperienceModelMasterRequest& request,
            Gs2WebSocketSessionTask<GetExperienceModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetExperienceModelMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetExperienceModelMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateExperienceModelMasterTask : public detail::Gs2WebSocketSessionTask<UpdateExperienceModelMasterResult>
    {
    private:
        UpdateExperienceModelMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getExperienceName())
            {
                writer.writePropertyName("experienceName");
                writer.writeCharArray(*m_Request.getExperienceName());
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
            if (m_Request.getDefaultExperience())
            {
                writer.writePropertyName("defaultExperience");
                writer.writeInt64(*m_Request.getDefaultExperience());
            }
            if (m_Request.getDefaultRankCap())
            {
                writer.writePropertyName("defaultRankCap");
                writer.writeInt64(*m_Request.getDefaultRankCap());
            }
            if (m_Request.getMaxRankCap())
            {
                writer.writePropertyName("maxRankCap");
                writer.writeInt64(*m_Request.getMaxRankCap());
            }
            if (m_Request.getRankThresholdId())
            {
                writer.writePropertyName("rankThresholdId");
                writer.writeCharArray(*m_Request.getRankThresholdId());
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
            writer.writeCharArray("experience");
            writer.writePropertyName("component");
            writer.writeCharArray("experienceModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("updateExperienceModelMaster");
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
        UpdateExperienceModelMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateExperienceModelMasterRequest& request,
            Gs2WebSocketSessionTask<UpdateExperienceModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateExperienceModelMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateExperienceModelMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteExperienceModelMasterTask : public detail::Gs2WebSocketSessionTask<DeleteExperienceModelMasterResult>
    {
    private:
        DeleteExperienceModelMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getExperienceName())
            {
                writer.writePropertyName("experienceName");
                writer.writeCharArray(*m_Request.getExperienceName());
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
            writer.writeCharArray("experience");
            writer.writePropertyName("component");
            writer.writeCharArray("experienceModelMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteExperienceModelMaster");
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
        DeleteExperienceModelMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteExperienceModelMasterRequest& request,
            Gs2WebSocketSessionTask<DeleteExperienceModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteExperienceModelMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteExperienceModelMasterTask() GS2_OVERRIDE = default;
    };

    class DescribeExperienceModelsTask : public detail::Gs2WebSocketSessionTask<DescribeExperienceModelsResult>
    {
    private:
        DescribeExperienceModelsRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
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
            writer.writeCharArray("experience");
            writer.writePropertyName("component");
            writer.writeCharArray("experienceModel");
            writer.writePropertyName("function");
            writer.writeCharArray("describeExperienceModels");
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
        DescribeExperienceModelsTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeExperienceModelsRequest& request,
            Gs2WebSocketSessionTask<DescribeExperienceModelsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeExperienceModelsResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeExperienceModelsTask() GS2_OVERRIDE = default;
    };

    class GetExperienceModelTask : public detail::Gs2WebSocketSessionTask<GetExperienceModelResult>
    {
    private:
        GetExperienceModelRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getExperienceName())
            {
                writer.writePropertyName("experienceName");
                writer.writeCharArray(*m_Request.getExperienceName());
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
            writer.writeCharArray("experience");
            writer.writePropertyName("component");
            writer.writeCharArray("experienceModel");
            writer.writePropertyName("function");
            writer.writeCharArray("getExperienceModel");
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
        GetExperienceModelTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetExperienceModelRequest& request,
            Gs2WebSocketSessionTask<GetExperienceModelResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetExperienceModelResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetExperienceModelTask() GS2_OVERRIDE = default;
    };

    class DescribeThresholdMastersTask : public detail::Gs2WebSocketSessionTask<DescribeThresholdMastersResult>
    {
    private:
        DescribeThresholdMastersRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
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
            writer.writeCharArray("experience");
            writer.writePropertyName("component");
            writer.writeCharArray("thresholdMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("describeThresholdMasters");
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
        DescribeThresholdMastersTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeThresholdMastersRequest& request,
            Gs2WebSocketSessionTask<DescribeThresholdMastersResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeThresholdMastersResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeThresholdMastersTask() GS2_OVERRIDE = default;
    };

    class CreateThresholdMasterTask : public detail::Gs2WebSocketSessionTask<CreateThresholdMasterResult>
    {
    private:
        CreateThresholdMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
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
            if (m_Request.getValues())
            {
                writer.writePropertyName("values");
                writer.writeArrayStart();
                auto& list = *m_Request.getValues();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    writer.writeInt64(list[i]);
                }
                writer.writeArrayEnd();
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
            writer.writeCharArray("experience");
            writer.writePropertyName("component");
            writer.writeCharArray("thresholdMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("createThresholdMaster");
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
        CreateThresholdMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            CreateThresholdMasterRequest& request,
            Gs2WebSocketSessionTask<CreateThresholdMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateThresholdMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~CreateThresholdMasterTask() GS2_OVERRIDE = default;
    };

    class GetThresholdMasterTask : public detail::Gs2WebSocketSessionTask<GetThresholdMasterResult>
    {
    private:
        GetThresholdMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getThresholdName())
            {
                writer.writePropertyName("thresholdName");
                writer.writeCharArray(*m_Request.getThresholdName());
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
            writer.writeCharArray("experience");
            writer.writePropertyName("component");
            writer.writeCharArray("thresholdMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("getThresholdMaster");
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
        GetThresholdMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetThresholdMasterRequest& request,
            Gs2WebSocketSessionTask<GetThresholdMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetThresholdMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetThresholdMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateThresholdMasterTask : public detail::Gs2WebSocketSessionTask<UpdateThresholdMasterResult>
    {
    private:
        UpdateThresholdMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getThresholdName())
            {
                writer.writePropertyName("thresholdName");
                writer.writeCharArray(*m_Request.getThresholdName());
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
            if (m_Request.getValues())
            {
                writer.writePropertyName("values");
                writer.writeArrayStart();
                auto& list = *m_Request.getValues();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    writer.writeInt64(list[i]);
                }
                writer.writeArrayEnd();
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
            writer.writeCharArray("experience");
            writer.writePropertyName("component");
            writer.writeCharArray("thresholdMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("updateThresholdMaster");
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
        UpdateThresholdMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateThresholdMasterRequest& request,
            Gs2WebSocketSessionTask<UpdateThresholdMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateThresholdMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateThresholdMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteThresholdMasterTask : public detail::Gs2WebSocketSessionTask<DeleteThresholdMasterResult>
    {
    private:
        DeleteThresholdMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getThresholdName())
            {
                writer.writePropertyName("thresholdName");
                writer.writeCharArray(*m_Request.getThresholdName());
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
            writer.writeCharArray("experience");
            writer.writePropertyName("component");
            writer.writeCharArray("thresholdMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteThresholdMaster");
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
        DeleteThresholdMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteThresholdMasterRequest& request,
            Gs2WebSocketSessionTask<DeleteThresholdMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteThresholdMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteThresholdMasterTask() GS2_OVERRIDE = default;
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

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
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
            writer.writeCharArray("experience");
            writer.writePropertyName("component");
            writer.writeCharArray("currentExperienceMaster");
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

    class GetCurrentExperienceMasterTask : public detail::Gs2WebSocketSessionTask<GetCurrentExperienceMasterResult>
    {
    private:
        GetCurrentExperienceMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
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
            writer.writeCharArray("experience");
            writer.writePropertyName("component");
            writer.writeCharArray("currentExperienceMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("getCurrentExperienceMaster");
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
        GetCurrentExperienceMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetCurrentExperienceMasterRequest& request,
            Gs2WebSocketSessionTask<GetCurrentExperienceMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetCurrentExperienceMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetCurrentExperienceMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentExperienceMasterTask : public detail::Gs2WebSocketSessionTask<UpdateCurrentExperienceMasterResult>
    {
    private:
        UpdateCurrentExperienceMasterRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
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
            writer.writeCharArray("experience");
            writer.writePropertyName("component");
            writer.writeCharArray("currentExperienceMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("updateCurrentExperienceMaster");
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
        UpdateCurrentExperienceMasterTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateCurrentExperienceMasterRequest& request,
            Gs2WebSocketSessionTask<UpdateCurrentExperienceMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateCurrentExperienceMasterResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateCurrentExperienceMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentExperienceMasterFromGitHubTask : public detail::Gs2WebSocketSessionTask<UpdateCurrentExperienceMasterFromGitHubResult>
    {
    private:
        UpdateCurrentExperienceMasterFromGitHubRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
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
            writer.writeCharArray("experience");
            writer.writePropertyName("component");
            writer.writeCharArray("currentExperienceMaster");
            writer.writePropertyName("function");
            writer.writeCharArray("updateCurrentExperienceMasterFromGitHub");
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
        UpdateCurrentExperienceMasterFromGitHubTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateCurrentExperienceMasterFromGitHubRequest& request,
            Gs2WebSocketSessionTask<UpdateCurrentExperienceMasterFromGitHubResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateCurrentExperienceMasterFromGitHubResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateCurrentExperienceMasterFromGitHubTask() GS2_OVERRIDE = default;
    };

    class DescribeStatusesTask : public detail::Gs2WebSocketSessionTask<DescribeStatusesResult>
    {
    private:
        DescribeStatusesRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getExperienceName())
            {
                writer.writePropertyName("experienceName");
                writer.writeCharArray(*m_Request.getExperienceName());
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
            writer.writeCharArray("experience");
            writer.writePropertyName("component");
            writer.writeCharArray("status");
            writer.writePropertyName("function");
            writer.writeCharArray("describeStatuses");
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
        DescribeStatusesTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeStatusesRequest& request,
            Gs2WebSocketSessionTask<DescribeStatusesResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeStatusesResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeStatusesTask() GS2_OVERRIDE = default;
    };

    class DescribeStatusesByUserIdTask : public detail::Gs2WebSocketSessionTask<DescribeStatusesByUserIdResult>
    {
    private:
        DescribeStatusesByUserIdRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getExperienceName())
            {
                writer.writePropertyName("experienceName");
                writer.writeCharArray(*m_Request.getExperienceName());
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
            writer.writeCharArray("experience");
            writer.writePropertyName("component");
            writer.writeCharArray("status");
            writer.writePropertyName("function");
            writer.writeCharArray("describeStatusesByUserId");
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
        DescribeStatusesByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeStatusesByUserIdRequest& request,
            Gs2WebSocketSessionTask<DescribeStatusesByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeStatusesByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeStatusesByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetStatusTask : public detail::Gs2WebSocketSessionTask<GetStatusResult>
    {
    private:
        GetStatusRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getExperienceName())
            {
                writer.writePropertyName("experienceName");
                writer.writeCharArray(*m_Request.getExperienceName());
            }
            if (m_Request.getPropertyId())
            {
                writer.writePropertyName("propertyId");
                writer.writeCharArray(*m_Request.getPropertyId());
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
            writer.writeCharArray("experience");
            writer.writePropertyName("component");
            writer.writeCharArray("status");
            writer.writePropertyName("function");
            writer.writeCharArray("getStatus");
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
        GetStatusTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetStatusRequest& request,
            Gs2WebSocketSessionTask<GetStatusResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetStatusResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetStatusTask() GS2_OVERRIDE = default;
    };

    class GetStatusByUserIdTask : public detail::Gs2WebSocketSessionTask<GetStatusByUserIdResult>
    {
    private:
        GetStatusByUserIdRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
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
            if (m_Request.getExperienceName())
            {
                writer.writePropertyName("experienceName");
                writer.writeCharArray(*m_Request.getExperienceName());
            }
            if (m_Request.getPropertyId())
            {
                writer.writePropertyName("propertyId");
                writer.writeCharArray(*m_Request.getPropertyId());
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
            writer.writeCharArray("experience");
            writer.writePropertyName("component");
            writer.writeCharArray("status");
            writer.writePropertyName("function");
            writer.writeCharArray("getStatusByUserId");
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
        GetStatusByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetStatusByUserIdRequest& request,
            Gs2WebSocketSessionTask<GetStatusByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetStatusByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetStatusByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetStatusWithSignatureTask : public detail::Gs2WebSocketSessionTask<GetStatusWithSignatureResult>
    {
    private:
        GetStatusWithSignatureRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getExperienceName())
            {
                writer.writePropertyName("experienceName");
                writer.writeCharArray(*m_Request.getExperienceName());
            }
            if (m_Request.getPropertyId())
            {
                writer.writePropertyName("propertyId");
                writer.writeCharArray(*m_Request.getPropertyId());
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
            writer.writeCharArray("experience");
            writer.writePropertyName("component");
            writer.writeCharArray("status");
            writer.writePropertyName("function");
            writer.writeCharArray("getStatusWithSignature");
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
        GetStatusWithSignatureTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetStatusWithSignatureRequest& request,
            Gs2WebSocketSessionTask<GetStatusWithSignatureResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetStatusWithSignatureResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetStatusWithSignatureTask() GS2_OVERRIDE = default;
    };

    class AddExperienceByUserIdTask : public detail::Gs2WebSocketSessionTask<AddExperienceByUserIdResult>
    {
    private:
        AddExperienceByUserIdRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
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
            if (m_Request.getExperienceName())
            {
                writer.writePropertyName("experienceName");
                writer.writeCharArray(*m_Request.getExperienceName());
            }
            if (m_Request.getPropertyId())
            {
                writer.writePropertyName("propertyId");
                writer.writeCharArray(*m_Request.getPropertyId());
            }
            if (m_Request.getExperienceValue())
            {
                writer.writePropertyName("experienceValue");
                writer.writeInt64(*m_Request.getExperienceValue());
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
            writer.writeCharArray("experience");
            writer.writePropertyName("component");
            writer.writeCharArray("status");
            writer.writePropertyName("function");
            writer.writeCharArray("addExperienceByUserId");
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
        AddExperienceByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            AddExperienceByUserIdRequest& request,
            Gs2WebSocketSessionTask<AddExperienceByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<AddExperienceByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~AddExperienceByUserIdTask() GS2_OVERRIDE = default;
    };

    class SetExperienceByUserIdTask : public detail::Gs2WebSocketSessionTask<SetExperienceByUserIdResult>
    {
    private:
        SetExperienceByUserIdRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
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
            if (m_Request.getExperienceName())
            {
                writer.writePropertyName("experienceName");
                writer.writeCharArray(*m_Request.getExperienceName());
            }
            if (m_Request.getPropertyId())
            {
                writer.writePropertyName("propertyId");
                writer.writeCharArray(*m_Request.getPropertyId());
            }
            if (m_Request.getExperienceValue())
            {
                writer.writePropertyName("experienceValue");
                writer.writeInt64(*m_Request.getExperienceValue());
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
            writer.writeCharArray("experience");
            writer.writePropertyName("component");
            writer.writeCharArray("status");
            writer.writePropertyName("function");
            writer.writeCharArray("setExperienceByUserId");
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
        SetExperienceByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            SetExperienceByUserIdRequest& request,
            Gs2WebSocketSessionTask<SetExperienceByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<SetExperienceByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~SetExperienceByUserIdTask() GS2_OVERRIDE = default;
    };

    class AddRankCapByUserIdTask : public detail::Gs2WebSocketSessionTask<AddRankCapByUserIdResult>
    {
    private:
        AddRankCapByUserIdRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
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
            if (m_Request.getExperienceName())
            {
                writer.writePropertyName("experienceName");
                writer.writeCharArray(*m_Request.getExperienceName());
            }
            if (m_Request.getPropertyId())
            {
                writer.writePropertyName("propertyId");
                writer.writeCharArray(*m_Request.getPropertyId());
            }
            if (m_Request.getRankCapValue())
            {
                writer.writePropertyName("rankCapValue");
                writer.writeInt64(*m_Request.getRankCapValue());
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
            writer.writeCharArray("experience");
            writer.writePropertyName("component");
            writer.writeCharArray("status");
            writer.writePropertyName("function");
            writer.writeCharArray("addRankCapByUserId");
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
        AddRankCapByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            AddRankCapByUserIdRequest& request,
            Gs2WebSocketSessionTask<AddRankCapByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<AddRankCapByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~AddRankCapByUserIdTask() GS2_OVERRIDE = default;
    };

    class SetRankCapByUserIdTask : public detail::Gs2WebSocketSessionTask<SetRankCapByUserIdResult>
    {
    private:
        SetRankCapByUserIdRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
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
            if (m_Request.getExperienceName())
            {
                writer.writePropertyName("experienceName");
                writer.writeCharArray(*m_Request.getExperienceName());
            }
            if (m_Request.getPropertyId())
            {
                writer.writePropertyName("propertyId");
                writer.writeCharArray(*m_Request.getPropertyId());
            }
            if (m_Request.getRankCapValue())
            {
                writer.writePropertyName("rankCapValue");
                writer.writeInt64(*m_Request.getRankCapValue());
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
            writer.writeCharArray("experience");
            writer.writePropertyName("component");
            writer.writeCharArray("status");
            writer.writePropertyName("function");
            writer.writeCharArray("setRankCapByUserId");
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
        SetRankCapByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            SetRankCapByUserIdRequest& request,
            Gs2WebSocketSessionTask<SetRankCapByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<SetRankCapByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~SetRankCapByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteStatusByUserIdTask : public detail::Gs2WebSocketSessionTask<DeleteStatusByUserIdResult>
    {
    private:
        DeleteStatusByUserIdRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
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
            if (m_Request.getExperienceName())
            {
                writer.writePropertyName("experienceName");
                writer.writeCharArray(*m_Request.getExperienceName());
            }
            if (m_Request.getPropertyId())
            {
                writer.writePropertyName("propertyId");
                writer.writeCharArray(*m_Request.getPropertyId());
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
            writer.writeCharArray("experience");
            writer.writePropertyName("component");
            writer.writeCharArray("status");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteStatusByUserId");
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
        DeleteStatusByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteStatusByUserIdRequest& request,
            Gs2WebSocketSessionTask<DeleteStatusByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteStatusByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteStatusByUserIdTask() GS2_OVERRIDE = default;
    };

    class AddExperienceByStampSheetTask : public detail::Gs2WebSocketSessionTask<AddExperienceByStampSheetResult>
    {
    private:
        AddExperienceByStampSheetRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
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
            writer.writeCharArray("experience");
            writer.writePropertyName("component");
            writer.writeCharArray("status");
            writer.writePropertyName("function");
            writer.writeCharArray("addExperienceByStampSheet");
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
        AddExperienceByStampSheetTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            AddExperienceByStampSheetRequest& request,
            Gs2WebSocketSessionTask<AddExperienceByStampSheetResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<AddExperienceByStampSheetResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~AddExperienceByStampSheetTask() GS2_OVERRIDE = default;
    };

    class AddRankCapByStampSheetTask : public detail::Gs2WebSocketSessionTask<AddRankCapByStampSheetResult>
    {
    private:
        AddRankCapByStampSheetRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
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
            writer.writeCharArray("experience");
            writer.writePropertyName("component");
            writer.writeCharArray("status");
            writer.writePropertyName("function");
            writer.writeCharArray("addRankCapByStampSheet");
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
        AddRankCapByStampSheetTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            AddRankCapByStampSheetRequest& request,
            Gs2WebSocketSessionTask<AddRankCapByStampSheetResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<AddRankCapByStampSheetResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~AddRankCapByStampSheetTask() GS2_OVERRIDE = default;
    };

    class SetRankCapByStampSheetTask : public detail::Gs2WebSocketSessionTask<SetRankCapByStampSheetResult>
    {
    private:
        SetRankCapByStampSheetRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getContextStack())
            {
                writer.writePropertyName("contextStack");
                writer.writeCharArray(*m_Request.getContextStack());
            }
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
            writer.writeCharArray("experience");
            writer.writePropertyName("component");
            writer.writeCharArray("status");
            writer.writePropertyName("function");
            writer.writeCharArray("setRankCapByStampSheet");
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
        SetRankCapByStampSheetTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            SetRankCapByStampSheetRequest& request,
            Gs2WebSocketSessionTask<SetRankCapByStampSheetResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<SetRankCapByStampSheetResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~SetRankCapByStampSheetTask() GS2_OVERRIDE = default;
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
        if (obj.getExperienceCapScriptId())
        {
            writer.writePropertyName("experienceCapScriptId");
            writer.writeCharArray(*obj.getExperienceCapScriptId());
        }
        if (obj.getChangeExperienceScript())
        {
            writer.writePropertyName("changeExperienceScript");
            write(writer, *obj.getChangeExperienceScript());
        }
        if (obj.getChangeRankScript())
        {
            writer.writePropertyName("changeRankScript");
            write(writer, *obj.getChangeRankScript());
        }
        if (obj.getChangeRankCapScript())
        {
            writer.writePropertyName("changeRankCapScript");
            write(writer, *obj.getChangeRankCapScript());
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

    static void write(detail::json::JsonWriter& writer, const ExperienceModelMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getExperienceModelId())
        {
            writer.writePropertyName("experienceModelId");
            writer.writeCharArray(*obj.getExperienceModelId());
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
        if (obj.getDefaultExperience())
        {
            writer.writePropertyName("defaultExperience");
            writer.writeInt64(*obj.getDefaultExperience());
        }
        if (obj.getDefaultRankCap())
        {
            writer.writePropertyName("defaultRankCap");
            writer.writeInt64(*obj.getDefaultRankCap());
        }
        if (obj.getMaxRankCap())
        {
            writer.writePropertyName("maxRankCap");
            writer.writeInt64(*obj.getMaxRankCap());
        }
        if (obj.getRankThresholdId())
        {
            writer.writePropertyName("rankThresholdId");
            writer.writeCharArray(*obj.getRankThresholdId());
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

    static void write(detail::json::JsonWriter& writer, const ExperienceModel& obj)
    {
        writer.writeObjectStart();
        if (obj.getExperienceModelId())
        {
            writer.writePropertyName("experienceModelId");
            writer.writeCharArray(*obj.getExperienceModelId());
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
        if (obj.getDefaultExperience())
        {
            writer.writePropertyName("defaultExperience");
            writer.writeInt64(*obj.getDefaultExperience());
        }
        if (obj.getDefaultRankCap())
        {
            writer.writePropertyName("defaultRankCap");
            writer.writeInt64(*obj.getDefaultRankCap());
        }
        if (obj.getMaxRankCap())
        {
            writer.writePropertyName("maxRankCap");
            writer.writeInt64(*obj.getMaxRankCap());
        }
        if (obj.getRankThreshold())
        {
            writer.writePropertyName("rankThreshold");
            write(writer, *obj.getRankThreshold());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const ThresholdMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getThresholdId())
        {
            writer.writePropertyName("thresholdId");
            writer.writeCharArray(*obj.getThresholdId());
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
        if (obj.getValues())
        {
            writer.writePropertyName("values");
            writer.writeArrayStart();
            auto& list = *obj.getValues();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                writer.writeInt64(list[i]);
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

    static void write(detail::json::JsonWriter& writer, const Threshold& obj)
    {
        writer.writeObjectStart();
        if (obj.getThresholdId())
        {
            writer.writePropertyName("thresholdId");
            writer.writeCharArray(*obj.getThresholdId());
        }
        if (obj.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.writeCharArray(*obj.getMetadata());
        }
        if (obj.getValues())
        {
            writer.writePropertyName("values");
            writer.writeArrayStart();
            auto& list = *obj.getValues();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                writer.writeInt64(list[i]);
            }
            writer.writeArrayEnd();
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const CurrentExperienceMaster& obj)
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

    static void write(detail::json::JsonWriter& writer, const Status& obj)
    {
        writer.writeObjectStart();
        if (obj.getStatusId())
        {
            writer.writePropertyName("statusId");
            writer.writeCharArray(*obj.getStatusId());
        }
        if (obj.getExperienceName())
        {
            writer.writePropertyName("experienceName");
            writer.writeCharArray(*obj.getExperienceName());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.writeCharArray(*obj.getUserId());
        }
        if (obj.getPropertyId())
        {
            writer.writePropertyName("propertyId");
            writer.writeCharArray(*obj.getPropertyId());
        }
        if (obj.getExperienceValue())
        {
            writer.writePropertyName("experienceValue");
            writer.writeInt64(*obj.getExperienceValue());
        }
        if (obj.getRankValue())
        {
            writer.writePropertyName("rankValue");
            writer.writeInt64(*obj.getRankValue());
        }
        if (obj.getRankCapValue())
        {
            writer.writePropertyName("rankCapValue");
            writer.writeInt64(*obj.getRankCapValue());
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

    static void write(detail::json::JsonWriter& writer, const ScriptSetting& obj)
    {
        writer.writeObjectStart();
        if (obj.getTriggerScriptId())
        {
            writer.writePropertyName("triggerScriptId");
            writer.writeCharArray(*obj.getTriggerScriptId());
        }
        if (obj.getDoneTriggerScriptId())
        {
            writer.writePropertyName("doneTriggerScriptId");
            writer.writeCharArray(*obj.getDoneTriggerScriptId());
        }
        if (obj.getDoneTriggerQueueNamespaceId())
        {
            writer.writePropertyName("doneTriggerQueueNamespaceId");
            writer.writeCharArray(*obj.getDoneTriggerQueueNamespaceId());
        }
        writer.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param gs2WebSocketSession WebSocket API 用セッション
     */
    explicit Gs2ExperienceWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
        AbstractGs2ClientBase(gs2WebSocketSession)
    {
    }

	/**
	 * ネームスペースの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeNamespaces(DescribeNamespacesRequest& request, std::function<void(AsyncDescribeNamespacesResult&)> callback)
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
    void createNamespace(CreateNamespaceRequest& request, std::function<void(AsyncCreateNamespaceResult&)> callback)
    {
        CreateNamespaceTask& task = *new CreateNamespaceTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ネームスペースを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getNamespaceStatus(GetNamespaceStatusRequest& request, std::function<void(AsyncGetNamespaceStatusResult&)> callback)
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
    void getNamespace(GetNamespaceRequest& request, std::function<void(AsyncGetNamespaceResult&)> callback)
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
    void updateNamespace(UpdateNamespaceRequest& request, std::function<void(AsyncUpdateNamespaceResult&)> callback)
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
    void deleteNamespace(DeleteNamespaceRequest& request, std::function<void(AsyncDeleteNamespaceResult&)> callback)
    {
        DeleteNamespaceTask& task = *new DeleteNamespaceTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 経験値の種類マスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeExperienceModelMasters(DescribeExperienceModelMastersRequest& request, std::function<void(AsyncDescribeExperienceModelMastersResult&)> callback)
    {
        DescribeExperienceModelMastersTask& task = *new DescribeExperienceModelMastersTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 経験値の種類マスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createExperienceModelMaster(CreateExperienceModelMasterRequest& request, std::function<void(AsyncCreateExperienceModelMasterResult&)> callback)
    {
        CreateExperienceModelMasterTask& task = *new CreateExperienceModelMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 経験値の種類マスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getExperienceModelMaster(GetExperienceModelMasterRequest& request, std::function<void(AsyncGetExperienceModelMasterResult&)> callback)
    {
        GetExperienceModelMasterTask& task = *new GetExperienceModelMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 経験値の種類マスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateExperienceModelMaster(UpdateExperienceModelMasterRequest& request, std::function<void(AsyncUpdateExperienceModelMasterResult&)> callback)
    {
        UpdateExperienceModelMasterTask& task = *new UpdateExperienceModelMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 経験値の種類マスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteExperienceModelMaster(DeleteExperienceModelMasterRequest& request, std::function<void(AsyncDeleteExperienceModelMasterResult&)> callback)
    {
        DeleteExperienceModelMasterTask& task = *new DeleteExperienceModelMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 経験値・ランクアップ閾値モデルの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeExperienceModels(DescribeExperienceModelsRequest& request, std::function<void(AsyncDescribeExperienceModelsResult&)> callback)
    {
        DescribeExperienceModelsTask& task = *new DescribeExperienceModelsTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 経験値・ランクアップ閾値モデルを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getExperienceModel(GetExperienceModelRequest& request, std::function<void(AsyncGetExperienceModelResult&)> callback)
    {
        GetExperienceModelTask& task = *new GetExperienceModelTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ランクアップ閾値マスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeThresholdMasters(DescribeThresholdMastersRequest& request, std::function<void(AsyncDescribeThresholdMastersResult&)> callback)
    {
        DescribeThresholdMastersTask& task = *new DescribeThresholdMastersTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ランクアップ閾値マスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createThresholdMaster(CreateThresholdMasterRequest& request, std::function<void(AsyncCreateThresholdMasterResult&)> callback)
    {
        CreateThresholdMasterTask& task = *new CreateThresholdMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ランクアップ閾値マスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getThresholdMaster(GetThresholdMasterRequest& request, std::function<void(AsyncGetThresholdMasterResult&)> callback)
    {
        GetThresholdMasterTask& task = *new GetThresholdMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ランクアップ閾値マスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateThresholdMaster(UpdateThresholdMasterRequest& request, std::function<void(AsyncUpdateThresholdMasterResult&)> callback)
    {
        UpdateThresholdMasterTask& task = *new UpdateThresholdMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ランクアップ閾値マスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteThresholdMaster(DeleteThresholdMasterRequest& request, std::function<void(AsyncDeleteThresholdMasterResult&)> callback)
    {
        DeleteThresholdMasterTask& task = *new DeleteThresholdMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 現在有効な経験値設定のマスターデータをエクスポートします<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void exportMaster(ExportMasterRequest& request, std::function<void(AsyncExportMasterResult&)> callback)
    {
        ExportMasterTask& task = *new ExportMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 現在有効な現在有効な経験値設定を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentExperienceMaster(GetCurrentExperienceMasterRequest& request, std::function<void(AsyncGetCurrentExperienceMasterResult&)> callback)
    {
        GetCurrentExperienceMasterTask& task = *new GetCurrentExperienceMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 現在有効な現在有効な経験値設定を更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentExperienceMaster(UpdateCurrentExperienceMasterRequest& request, std::function<void(AsyncUpdateCurrentExperienceMasterResult&)> callback)
    {
        UpdateCurrentExperienceMasterTask& task = *new UpdateCurrentExperienceMasterTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 現在有効な現在有効な経験値設定を更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentExperienceMasterFromGitHub(UpdateCurrentExperienceMasterFromGitHubRequest& request, std::function<void(AsyncUpdateCurrentExperienceMasterFromGitHubResult&)> callback)
    {
        UpdateCurrentExperienceMasterFromGitHubTask& task = *new UpdateCurrentExperienceMasterFromGitHubTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ステータスの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeStatuses(DescribeStatusesRequest& request, std::function<void(AsyncDescribeStatusesResult&)> callback)
    {
        DescribeStatusesTask& task = *new DescribeStatusesTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ステータスの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeStatusesByUserId(DescribeStatusesByUserIdRequest& request, std::function<void(AsyncDescribeStatusesByUserIdResult&)> callback)
    {
        DescribeStatusesByUserIdTask& task = *new DescribeStatusesByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ステータスを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStatus(GetStatusRequest& request, std::function<void(AsyncGetStatusResult&)> callback)
    {
        GetStatusTask& task = *new GetStatusTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ステータスを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStatusByUserId(GetStatusByUserIdRequest& request, std::function<void(AsyncGetStatusByUserIdResult&)> callback)
    {
        GetStatusByUserIdTask& task = *new GetStatusByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ステータスを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStatusWithSignature(GetStatusWithSignatureRequest& request, std::function<void(AsyncGetStatusWithSignatureResult&)> callback)
    {
        GetStatusWithSignatureTask& task = *new GetStatusWithSignatureTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 経験値を加算<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void addExperienceByUserId(AddExperienceByUserIdRequest& request, std::function<void(AsyncAddExperienceByUserIdResult&)> callback)
    {
        AddExperienceByUserIdTask& task = *new AddExperienceByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 累計獲得経験値を設定<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setExperienceByUserId(SetExperienceByUserIdRequest& request, std::function<void(AsyncSetExperienceByUserIdResult&)> callback)
    {
        SetExperienceByUserIdTask& task = *new SetExperienceByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ランクキャップを加算<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void addRankCapByUserId(AddRankCapByUserIdRequest& request, std::function<void(AsyncAddRankCapByUserIdResult&)> callback)
    {
        AddRankCapByUserIdTask& task = *new AddRankCapByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ランクキャップを設定<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setRankCapByUserId(SetRankCapByUserIdRequest& request, std::function<void(AsyncSetRankCapByUserIdResult&)> callback)
    {
        SetRankCapByUserIdTask& task = *new SetRankCapByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ステータスを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteStatusByUserId(DeleteStatusByUserIdRequest& request, std::function<void(AsyncDeleteStatusByUserIdResult&)> callback)
    {
        DeleteStatusByUserIdTask& task = *new DeleteStatusByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * 経験値を加算<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void addExperienceByStampSheet(AddExperienceByStampSheetRequest& request, std::function<void(AsyncAddExperienceByStampSheetResult&)> callback)
    {
        AddExperienceByStampSheetTask& task = *new AddExperienceByStampSheetTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ランクキャップを加算<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void addRankCapByStampSheet(AddRankCapByStampSheetRequest& request, std::function<void(AsyncAddRankCapByStampSheetResult&)> callback)
    {
        AddRankCapByStampSheetTask& task = *new AddRankCapByStampSheetTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ランクキャップを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setRankCapByStampSheet(SetRankCapByStampSheetRequest& request, std::function<void(AsyncSetRankCapByStampSheetResult&)> callback)
    {
        SetRankCapByStampSheetTask& task = *new SetRankCapByStampSheetTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_EXPERIENCE_GS2EXPERIENCEWEBSOCKETCLIENT_HPP_