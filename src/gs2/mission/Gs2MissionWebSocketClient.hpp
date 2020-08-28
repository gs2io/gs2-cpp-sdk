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

#ifndef GS2_MISSION_GS2MISSIONWEBSOCKETCLIENT_HPP_
#define GS2_MISSION_GS2MISSIONWEBSOCKETCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2WebSocketSessionTask.hpp>
#include <gs2/core/network/Gs2WebSocketSession.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include "model/model.hpp"
#include "request/DescribeMissionTaskModelMastersRequest.hpp"
#include "request/CreateMissionTaskModelMasterRequest.hpp"
#include "request/GetMissionTaskModelMasterRequest.hpp"
#include "request/UpdateMissionTaskModelMasterRequest.hpp"
#include "request/DeleteMissionTaskModelMasterRequest.hpp"
#include "request/DescribeMissionGroupModelsRequest.hpp"
#include "request/GetMissionGroupModelRequest.hpp"
#include "request/DescribeCounterModelMastersRequest.hpp"
#include "request/CreateCounterModelMasterRequest.hpp"
#include "request/GetCounterModelMasterRequest.hpp"
#include "request/UpdateCounterModelMasterRequest.hpp"
#include "request/DeleteCounterModelMasterRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentMissionMasterRequest.hpp"
#include "request/UpdateCurrentMissionMasterRequest.hpp"
#include "request/UpdateCurrentMissionMasterFromGitHubRequest.hpp"
#include "request/DescribeCountersRequest.hpp"
#include "request/DescribeCountersByUserIdRequest.hpp"
#include "request/IncreaseCounterByUserIdRequest.hpp"
#include "request/GetCounterRequest.hpp"
#include "request/GetCounterByUserIdRequest.hpp"
#include "request/DeleteCounterByUserIdRequest.hpp"
#include "request/IncreaseByStampSheetRequest.hpp"
#include "request/DescribeMissionTaskModelsRequest.hpp"
#include "request/GetMissionTaskModelRequest.hpp"
#include "request/DescribeCompletesRequest.hpp"
#include "request/DescribeCompletesByUserIdRequest.hpp"
#include "request/CompleteRequest.hpp"
#include "request/CompleteByUserIdRequest.hpp"
#include "request/ReceiveByUserIdRequest.hpp"
#include "request/GetCompleteRequest.hpp"
#include "request/GetCompleteByUserIdRequest.hpp"
#include "request/DeleteCompleteByUserIdRequest.hpp"
#include "request/ReceiveByStampTaskRequest.hpp"
#include "request/DescribeMissionGroupModelMastersRequest.hpp"
#include "request/CreateMissionGroupModelMasterRequest.hpp"
#include "request/GetMissionGroupModelMasterRequest.hpp"
#include "request/UpdateMissionGroupModelMasterRequest.hpp"
#include "request/DeleteMissionGroupModelMasterRequest.hpp"
#include "request/DescribeNamespacesRequest.hpp"
#include "request/CreateNamespaceRequest.hpp"
#include "request/GetNamespaceStatusRequest.hpp"
#include "request/GetNamespaceRequest.hpp"
#include "request/UpdateNamespaceRequest.hpp"
#include "request/DeleteNamespaceRequest.hpp"
#include "request/DescribeCounterModelsRequest.hpp"
#include "request/GetCounterModelRequest.hpp"
#include "result/DescribeMissionTaskModelMastersResult.hpp"
#include "result/CreateMissionTaskModelMasterResult.hpp"
#include "result/GetMissionTaskModelMasterResult.hpp"
#include "result/UpdateMissionTaskModelMasterResult.hpp"
#include "result/DeleteMissionTaskModelMasterResult.hpp"
#include "result/DescribeMissionGroupModelsResult.hpp"
#include "result/GetMissionGroupModelResult.hpp"
#include "result/DescribeCounterModelMastersResult.hpp"
#include "result/CreateCounterModelMasterResult.hpp"
#include "result/GetCounterModelMasterResult.hpp"
#include "result/UpdateCounterModelMasterResult.hpp"
#include "result/DeleteCounterModelMasterResult.hpp"
#include "result/ExportMasterResult.hpp"
#include "result/GetCurrentMissionMasterResult.hpp"
#include "result/UpdateCurrentMissionMasterResult.hpp"
#include "result/UpdateCurrentMissionMasterFromGitHubResult.hpp"
#include "result/DescribeCountersResult.hpp"
#include "result/DescribeCountersByUserIdResult.hpp"
#include "result/IncreaseCounterByUserIdResult.hpp"
#include "result/GetCounterResult.hpp"
#include "result/GetCounterByUserIdResult.hpp"
#include "result/DeleteCounterByUserIdResult.hpp"
#include "result/IncreaseByStampSheetResult.hpp"
#include "result/DescribeMissionTaskModelsResult.hpp"
#include "result/GetMissionTaskModelResult.hpp"
#include "result/DescribeCompletesResult.hpp"
#include "result/DescribeCompletesByUserIdResult.hpp"
#include "result/CompleteResult.hpp"
#include "result/CompleteByUserIdResult.hpp"
#include "result/ReceiveByUserIdResult.hpp"
#include "result/GetCompleteResult.hpp"
#include "result/GetCompleteByUserIdResult.hpp"
#include "result/DeleteCompleteByUserIdResult.hpp"
#include "result/ReceiveByStampTaskResult.hpp"
#include "result/DescribeMissionGroupModelMastersResult.hpp"
#include "result/CreateMissionGroupModelMasterResult.hpp"
#include "result/GetMissionGroupModelMasterResult.hpp"
#include "result/UpdateMissionGroupModelMasterResult.hpp"
#include "result/DeleteMissionGroupModelMasterResult.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeCounterModelsResult.hpp"
#include "result/GetCounterModelResult.hpp"
#include <cstring>

namespace gs2 { namespace mission {

/**
 * GS2 Mission API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2MissionWebSocketClient : public AbstractGs2ClientBase
{
private:

    class DescribeMissionTaskModelMastersTask : public detail::Gs2WebSocketSessionTask<DescribeMissionTaskModelMastersResult>
    {
    private:
        DescribeMissionTaskModelMastersRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "missionTaskModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeMissionTaskModelMasters";
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
            if (m_Request.getMissionGroupName())
            {
                jsonWriter.writePropertyName("missionGroupName");
                jsonWriter.writeCharArray(*m_Request.getMissionGroupName());
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
        DescribeMissionTaskModelMastersTask(
            DescribeMissionTaskModelMastersRequest request,
            Gs2WebSocketSessionTask<DescribeMissionTaskModelMastersResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeMissionTaskModelMastersResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeMissionTaskModelMastersTask() GS2_OVERRIDE = default;
    };

    class CreateMissionTaskModelMasterTask : public detail::Gs2WebSocketSessionTask<CreateMissionTaskModelMasterResult>
    {
    private:
        CreateMissionTaskModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "missionTaskModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "createMissionTaskModelMaster";
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
            if (m_Request.getMissionGroupName())
            {
                jsonWriter.writePropertyName("missionGroupName");
                jsonWriter.writeCharArray(*m_Request.getMissionGroupName());
            }
            if (m_Request.getName())
            {
                jsonWriter.writePropertyName("name");
                jsonWriter.writeCharArray(*m_Request.getName());
            }
            if (m_Request.getMetadata())
            {
                jsonWriter.writePropertyName("metadata");
                jsonWriter.writeCharArray(*m_Request.getMetadata());
            }
            if (m_Request.getDescription())
            {
                jsonWriter.writePropertyName("description");
                jsonWriter.writeCharArray(*m_Request.getDescription());
            }
            if (m_Request.getCounterName())
            {
                jsonWriter.writePropertyName("counterName");
                jsonWriter.writeCharArray(*m_Request.getCounterName());
            }
            if (m_Request.getTargetValue())
            {
                jsonWriter.writePropertyName("targetValue");
                jsonWriter.writeInt64(*m_Request.getTargetValue());
            }
            if (m_Request.getCompleteAcquireActions())
            {
                jsonWriter.writePropertyName("completeAcquireActions");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getCompleteAcquireActions();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(jsonWriter, list[i]);
                }
                jsonWriter.writeArrayEnd();
            }
            if (m_Request.getChallengePeriodEventId())
            {
                jsonWriter.writePropertyName("challengePeriodEventId");
                jsonWriter.writeCharArray(*m_Request.getChallengePeriodEventId());
            }
            if (m_Request.getPremiseMissionTaskName())
            {
                jsonWriter.writePropertyName("premiseMissionTaskName");
                jsonWriter.writeCharArray(*m_Request.getPremiseMissionTaskName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        CreateMissionTaskModelMasterTask(
            CreateMissionTaskModelMasterRequest request,
            Gs2WebSocketSessionTask<CreateMissionTaskModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateMissionTaskModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateMissionTaskModelMasterTask() GS2_OVERRIDE = default;
    };

    class GetMissionTaskModelMasterTask : public detail::Gs2WebSocketSessionTask<GetMissionTaskModelMasterResult>
    {
    private:
        GetMissionTaskModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "missionTaskModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getMissionTaskModelMaster";
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
            if (m_Request.getMissionGroupName())
            {
                jsonWriter.writePropertyName("missionGroupName");
                jsonWriter.writeCharArray(*m_Request.getMissionGroupName());
            }
            if (m_Request.getMissionTaskName())
            {
                jsonWriter.writePropertyName("missionTaskName");
                jsonWriter.writeCharArray(*m_Request.getMissionTaskName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetMissionTaskModelMasterTask(
            GetMissionTaskModelMasterRequest request,
            Gs2WebSocketSessionTask<GetMissionTaskModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetMissionTaskModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetMissionTaskModelMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateMissionTaskModelMasterTask : public detail::Gs2WebSocketSessionTask<UpdateMissionTaskModelMasterResult>
    {
    private:
        UpdateMissionTaskModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "missionTaskModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateMissionTaskModelMaster";
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
            if (m_Request.getMissionGroupName())
            {
                jsonWriter.writePropertyName("missionGroupName");
                jsonWriter.writeCharArray(*m_Request.getMissionGroupName());
            }
            if (m_Request.getMissionTaskName())
            {
                jsonWriter.writePropertyName("missionTaskName");
                jsonWriter.writeCharArray(*m_Request.getMissionTaskName());
            }
            if (m_Request.getMetadata())
            {
                jsonWriter.writePropertyName("metadata");
                jsonWriter.writeCharArray(*m_Request.getMetadata());
            }
            if (m_Request.getDescription())
            {
                jsonWriter.writePropertyName("description");
                jsonWriter.writeCharArray(*m_Request.getDescription());
            }
            if (m_Request.getCounterName())
            {
                jsonWriter.writePropertyName("counterName");
                jsonWriter.writeCharArray(*m_Request.getCounterName());
            }
            if (m_Request.getTargetValue())
            {
                jsonWriter.writePropertyName("targetValue");
                jsonWriter.writeInt64(*m_Request.getTargetValue());
            }
            if (m_Request.getCompleteAcquireActions())
            {
                jsonWriter.writePropertyName("completeAcquireActions");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getCompleteAcquireActions();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(jsonWriter, list[i]);
                }
                jsonWriter.writeArrayEnd();
            }
            if (m_Request.getChallengePeriodEventId())
            {
                jsonWriter.writePropertyName("challengePeriodEventId");
                jsonWriter.writeCharArray(*m_Request.getChallengePeriodEventId());
            }
            if (m_Request.getPremiseMissionTaskName())
            {
                jsonWriter.writePropertyName("premiseMissionTaskName");
                jsonWriter.writeCharArray(*m_Request.getPremiseMissionTaskName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        UpdateMissionTaskModelMasterTask(
            UpdateMissionTaskModelMasterRequest request,
            Gs2WebSocketSessionTask<UpdateMissionTaskModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateMissionTaskModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateMissionTaskModelMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteMissionTaskModelMasterTask : public detail::Gs2WebSocketSessionTask<DeleteMissionTaskModelMasterResult>
    {
    private:
        DeleteMissionTaskModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "missionTaskModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteMissionTaskModelMaster";
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
            if (m_Request.getMissionGroupName())
            {
                jsonWriter.writePropertyName("missionGroupName");
                jsonWriter.writeCharArray(*m_Request.getMissionGroupName());
            }
            if (m_Request.getMissionTaskName())
            {
                jsonWriter.writePropertyName("missionTaskName");
                jsonWriter.writeCharArray(*m_Request.getMissionTaskName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        DeleteMissionTaskModelMasterTask(
            DeleteMissionTaskModelMasterRequest request,
            Gs2WebSocketSessionTask<DeleteMissionTaskModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteMissionTaskModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteMissionTaskModelMasterTask() GS2_OVERRIDE = default;
    };

    class DescribeMissionGroupModelsTask : public detail::Gs2WebSocketSessionTask<DescribeMissionGroupModelsResult>
    {
    private:
        DescribeMissionGroupModelsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "missionGroupModel";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeMissionGroupModels";
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
        DescribeMissionGroupModelsTask(
            DescribeMissionGroupModelsRequest request,
            Gs2WebSocketSessionTask<DescribeMissionGroupModelsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeMissionGroupModelsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeMissionGroupModelsTask() GS2_OVERRIDE = default;
    };

    class GetMissionGroupModelTask : public detail::Gs2WebSocketSessionTask<GetMissionGroupModelResult>
    {
    private:
        GetMissionGroupModelRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "missionGroupModel";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getMissionGroupModel";
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
            if (m_Request.getMissionGroupName())
            {
                jsonWriter.writePropertyName("missionGroupName");
                jsonWriter.writeCharArray(*m_Request.getMissionGroupName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetMissionGroupModelTask(
            GetMissionGroupModelRequest request,
            Gs2WebSocketSessionTask<GetMissionGroupModelResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetMissionGroupModelResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetMissionGroupModelTask() GS2_OVERRIDE = default;
    };

    class DescribeCounterModelMastersTask : public detail::Gs2WebSocketSessionTask<DescribeCounterModelMastersResult>
    {
    private:
        DescribeCounterModelMastersRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "counterModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeCounterModelMasters";
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
        DescribeCounterModelMastersTask(
            DescribeCounterModelMastersRequest request,
            Gs2WebSocketSessionTask<DescribeCounterModelMastersResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeCounterModelMastersResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeCounterModelMastersTask() GS2_OVERRIDE = default;
    };

    class CreateCounterModelMasterTask : public detail::Gs2WebSocketSessionTask<CreateCounterModelMasterResult>
    {
    private:
        CreateCounterModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "counterModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "createCounterModelMaster";
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
            if (m_Request.getMetadata())
            {
                jsonWriter.writePropertyName("metadata");
                jsonWriter.writeCharArray(*m_Request.getMetadata());
            }
            if (m_Request.getDescription())
            {
                jsonWriter.writePropertyName("description");
                jsonWriter.writeCharArray(*m_Request.getDescription());
            }
            if (m_Request.getScopes())
            {
                jsonWriter.writePropertyName("scopes");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getScopes();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(jsonWriter, list[i]);
                }
                jsonWriter.writeArrayEnd();
            }
            if (m_Request.getChallengePeriodEventId())
            {
                jsonWriter.writePropertyName("challengePeriodEventId");
                jsonWriter.writeCharArray(*m_Request.getChallengePeriodEventId());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        CreateCounterModelMasterTask(
            CreateCounterModelMasterRequest request,
            Gs2WebSocketSessionTask<CreateCounterModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateCounterModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateCounterModelMasterTask() GS2_OVERRIDE = default;
    };

    class GetCounterModelMasterTask : public detail::Gs2WebSocketSessionTask<GetCounterModelMasterResult>
    {
    private:
        GetCounterModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "counterModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getCounterModelMaster";
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
        }

    public:
        GetCounterModelMasterTask(
            GetCounterModelMasterRequest request,
            Gs2WebSocketSessionTask<GetCounterModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetCounterModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetCounterModelMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCounterModelMasterTask : public detail::Gs2WebSocketSessionTask<UpdateCounterModelMasterResult>
    {
    private:
        UpdateCounterModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "counterModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateCounterModelMaster";
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
            if (m_Request.getCounterName())
            {
                jsonWriter.writePropertyName("counterName");
                jsonWriter.writeCharArray(*m_Request.getCounterName());
            }
            if (m_Request.getMetadata())
            {
                jsonWriter.writePropertyName("metadata");
                jsonWriter.writeCharArray(*m_Request.getMetadata());
            }
            if (m_Request.getDescription())
            {
                jsonWriter.writePropertyName("description");
                jsonWriter.writeCharArray(*m_Request.getDescription());
            }
            if (m_Request.getScopes())
            {
                jsonWriter.writePropertyName("scopes");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getScopes();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(jsonWriter, list[i]);
                }
                jsonWriter.writeArrayEnd();
            }
            if (m_Request.getChallengePeriodEventId())
            {
                jsonWriter.writePropertyName("challengePeriodEventId");
                jsonWriter.writeCharArray(*m_Request.getChallengePeriodEventId());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        UpdateCounterModelMasterTask(
            UpdateCounterModelMasterRequest request,
            Gs2WebSocketSessionTask<UpdateCounterModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateCounterModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateCounterModelMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteCounterModelMasterTask : public detail::Gs2WebSocketSessionTask<DeleteCounterModelMasterResult>
    {
    private:
        DeleteCounterModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "counterModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteCounterModelMaster";
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
        }

    public:
        DeleteCounterModelMasterTask(
            DeleteCounterModelMasterRequest request,
            Gs2WebSocketSessionTask<DeleteCounterModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteCounterModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteCounterModelMasterTask() GS2_OVERRIDE = default;
    };

    class ExportMasterTask : public detail::Gs2WebSocketSessionTask<ExportMasterResult>
    {
    private:
        ExportMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "currentMissionMaster";
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

    class GetCurrentMissionMasterTask : public detail::Gs2WebSocketSessionTask<GetCurrentMissionMasterResult>
    {
    private:
        GetCurrentMissionMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "currentMissionMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getCurrentMissionMaster";
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
        GetCurrentMissionMasterTask(
            GetCurrentMissionMasterRequest request,
            Gs2WebSocketSessionTask<GetCurrentMissionMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetCurrentMissionMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetCurrentMissionMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentMissionMasterTask : public detail::Gs2WebSocketSessionTask<UpdateCurrentMissionMasterResult>
    {
    private:
        UpdateCurrentMissionMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "currentMissionMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateCurrentMissionMaster";
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
        UpdateCurrentMissionMasterTask(
            UpdateCurrentMissionMasterRequest request,
            Gs2WebSocketSessionTask<UpdateCurrentMissionMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateCurrentMissionMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateCurrentMissionMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentMissionMasterFromGitHubTask : public detail::Gs2WebSocketSessionTask<UpdateCurrentMissionMasterFromGitHubResult>
    {
    private:
        UpdateCurrentMissionMasterFromGitHubRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "currentMissionMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateCurrentMissionMasterFromGitHub";
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
        UpdateCurrentMissionMasterFromGitHubTask(
            UpdateCurrentMissionMasterFromGitHubRequest request,
            Gs2WebSocketSessionTask<UpdateCurrentMissionMasterFromGitHubResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateCurrentMissionMasterFromGitHubResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateCurrentMissionMasterFromGitHubTask() GS2_OVERRIDE = default;
    };

    class DescribeCountersTask : public detail::Gs2WebSocketSessionTask<DescribeCountersResult>
    {
    private:
        DescribeCountersRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
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
            return "mission";
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

    class IncreaseCounterByUserIdTask : public detail::Gs2WebSocketSessionTask<IncreaseCounterByUserIdResult>
    {
    private:
        IncreaseCounterByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "counter";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "increaseCounterByUserId";
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
            if (m_Request.getValue())
            {
                jsonWriter.writePropertyName("value");
                jsonWriter.writeInt64(*m_Request.getValue());
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
        IncreaseCounterByUserIdTask(
            IncreaseCounterByUserIdRequest request,
            Gs2WebSocketSessionTask<IncreaseCounterByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<IncreaseCounterByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~IncreaseCounterByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetCounterTask : public detail::Gs2WebSocketSessionTask<GetCounterResult>
    {
    private:
        GetCounterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
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
            return "mission";
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

    class DeleteCounterByUserIdTask : public detail::Gs2WebSocketSessionTask<DeleteCounterByUserIdResult>
    {
    private:
        DeleteCounterByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
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

    class IncreaseByStampSheetTask : public detail::Gs2WebSocketSessionTask<IncreaseByStampSheetResult>
    {
    private:
        IncreaseByStampSheetRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "counter";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "increaseByStampSheet";
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
        IncreaseByStampSheetTask(
            IncreaseByStampSheetRequest request,
            Gs2WebSocketSessionTask<IncreaseByStampSheetResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<IncreaseByStampSheetResult>(callback),
            m_Request(std::move(request))
        {}

        ~IncreaseByStampSheetTask() GS2_OVERRIDE = default;
    };

    class DescribeMissionTaskModelsTask : public detail::Gs2WebSocketSessionTask<DescribeMissionTaskModelsResult>
    {
    private:
        DescribeMissionTaskModelsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "missionTaskModel";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeMissionTaskModels";
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
            if (m_Request.getMissionGroupName())
            {
                jsonWriter.writePropertyName("missionGroupName");
                jsonWriter.writeCharArray(*m_Request.getMissionGroupName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        DescribeMissionTaskModelsTask(
            DescribeMissionTaskModelsRequest request,
            Gs2WebSocketSessionTask<DescribeMissionTaskModelsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeMissionTaskModelsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeMissionTaskModelsTask() GS2_OVERRIDE = default;
    };

    class GetMissionTaskModelTask : public detail::Gs2WebSocketSessionTask<GetMissionTaskModelResult>
    {
    private:
        GetMissionTaskModelRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "missionTaskModel";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getMissionTaskModel";
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
            if (m_Request.getMissionGroupName())
            {
                jsonWriter.writePropertyName("missionGroupName");
                jsonWriter.writeCharArray(*m_Request.getMissionGroupName());
            }
            if (m_Request.getMissionTaskName())
            {
                jsonWriter.writePropertyName("missionTaskName");
                jsonWriter.writeCharArray(*m_Request.getMissionTaskName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetMissionTaskModelTask(
            GetMissionTaskModelRequest request,
            Gs2WebSocketSessionTask<GetMissionTaskModelResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetMissionTaskModelResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetMissionTaskModelTask() GS2_OVERRIDE = default;
    };

    class DescribeCompletesTask : public detail::Gs2WebSocketSessionTask<DescribeCompletesResult>
    {
    private:
        DescribeCompletesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "complete";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeCompletes";
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
        DescribeCompletesTask(
            DescribeCompletesRequest request,
            Gs2WebSocketSessionTask<DescribeCompletesResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeCompletesResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeCompletesTask() GS2_OVERRIDE = default;
    };

    class DescribeCompletesByUserIdTask : public detail::Gs2WebSocketSessionTask<DescribeCompletesByUserIdResult>
    {
    private:
        DescribeCompletesByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "complete";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeCompletesByUserId";
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
        DescribeCompletesByUserIdTask(
            DescribeCompletesByUserIdRequest request,
            Gs2WebSocketSessionTask<DescribeCompletesByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeCompletesByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeCompletesByUserIdTask() GS2_OVERRIDE = default;
    };

    class CompleteTask : public detail::Gs2WebSocketSessionTask<CompleteResult>
    {
    private:
        CompleteRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "complete";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "complete";
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
            if (m_Request.getMissionGroupName())
            {
                jsonWriter.writePropertyName("missionGroupName");
                jsonWriter.writeCharArray(*m_Request.getMissionGroupName());
            }
            if (m_Request.getMissionTaskName())
            {
                jsonWriter.writePropertyName("missionTaskName");
                jsonWriter.writeCharArray(*m_Request.getMissionTaskName());
            }
            if (m_Request.getConfig())
            {
                jsonWriter.writePropertyName("config");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getConfig();
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
        CompleteTask(
            CompleteRequest request,
            Gs2WebSocketSessionTask<CompleteResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CompleteResult>(callback),
            m_Request(std::move(request))
        {}

        ~CompleteTask() GS2_OVERRIDE = default;
    };

    class CompleteByUserIdTask : public detail::Gs2WebSocketSessionTask<CompleteByUserIdResult>
    {
    private:
        CompleteByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "complete";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "completeByUserId";
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
            if (m_Request.getMissionGroupName())
            {
                jsonWriter.writePropertyName("missionGroupName");
                jsonWriter.writeCharArray(*m_Request.getMissionGroupName());
            }
            if (m_Request.getMissionTaskName())
            {
                jsonWriter.writePropertyName("missionTaskName");
                jsonWriter.writeCharArray(*m_Request.getMissionTaskName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getConfig())
            {
                jsonWriter.writePropertyName("config");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getConfig();
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
        CompleteByUserIdTask(
            CompleteByUserIdRequest request,
            Gs2WebSocketSessionTask<CompleteByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CompleteByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~CompleteByUserIdTask() GS2_OVERRIDE = default;
    };

    class ReceiveByUserIdTask : public detail::Gs2WebSocketSessionTask<ReceiveByUserIdResult>
    {
    private:
        ReceiveByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "complete";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "receiveByUserId";
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
            if (m_Request.getMissionGroupName())
            {
                jsonWriter.writePropertyName("missionGroupName");
                jsonWriter.writeCharArray(*m_Request.getMissionGroupName());
            }
            if (m_Request.getMissionTaskName())
            {
                jsonWriter.writePropertyName("missionTaskName");
                jsonWriter.writeCharArray(*m_Request.getMissionTaskName());
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
        ReceiveByUserIdTask(
            ReceiveByUserIdRequest request,
            Gs2WebSocketSessionTask<ReceiveByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<ReceiveByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~ReceiveByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetCompleteTask : public detail::Gs2WebSocketSessionTask<GetCompleteResult>
    {
    private:
        GetCompleteRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "complete";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getComplete";
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
            if (m_Request.getMissionGroupName())
            {
                jsonWriter.writePropertyName("missionGroupName");
                jsonWriter.writeCharArray(*m_Request.getMissionGroupName());
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
        GetCompleteTask(
            GetCompleteRequest request,
            Gs2WebSocketSessionTask<GetCompleteResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetCompleteResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetCompleteTask() GS2_OVERRIDE = default;
    };

    class GetCompleteByUserIdTask : public detail::Gs2WebSocketSessionTask<GetCompleteByUserIdResult>
    {
    private:
        GetCompleteByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "complete";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getCompleteByUserId";
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
            if (m_Request.getMissionGroupName())
            {
                jsonWriter.writePropertyName("missionGroupName");
                jsonWriter.writeCharArray(*m_Request.getMissionGroupName());
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
        GetCompleteByUserIdTask(
            GetCompleteByUserIdRequest request,
            Gs2WebSocketSessionTask<GetCompleteByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetCompleteByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetCompleteByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteCompleteByUserIdTask : public detail::Gs2WebSocketSessionTask<DeleteCompleteByUserIdResult>
    {
    private:
        DeleteCompleteByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "complete";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteCompleteByUserId";
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
            if (m_Request.getMissionGroupName())
            {
                jsonWriter.writePropertyName("missionGroupName");
                jsonWriter.writeCharArray(*m_Request.getMissionGroupName());
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
        DeleteCompleteByUserIdTask(
            DeleteCompleteByUserIdRequest request,
            Gs2WebSocketSessionTask<DeleteCompleteByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteCompleteByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteCompleteByUserIdTask() GS2_OVERRIDE = default;
    };

    class ReceiveByStampTaskTask : public detail::Gs2WebSocketSessionTask<ReceiveByStampTaskResult>
    {
    private:
        ReceiveByStampTaskRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "complete";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "receiveByStampTask";
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
        ReceiveByStampTaskTask(
            ReceiveByStampTaskRequest request,
            Gs2WebSocketSessionTask<ReceiveByStampTaskResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<ReceiveByStampTaskResult>(callback),
            m_Request(std::move(request))
        {}

        ~ReceiveByStampTaskTask() GS2_OVERRIDE = default;
    };

    class DescribeMissionGroupModelMastersTask : public detail::Gs2WebSocketSessionTask<DescribeMissionGroupModelMastersResult>
    {
    private:
        DescribeMissionGroupModelMastersRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "missionGroupModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeMissionGroupModelMasters";
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
        DescribeMissionGroupModelMastersTask(
            DescribeMissionGroupModelMastersRequest request,
            Gs2WebSocketSessionTask<DescribeMissionGroupModelMastersResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeMissionGroupModelMastersResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeMissionGroupModelMastersTask() GS2_OVERRIDE = default;
    };

    class CreateMissionGroupModelMasterTask : public detail::Gs2WebSocketSessionTask<CreateMissionGroupModelMasterResult>
    {
    private:
        CreateMissionGroupModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "missionGroupModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "createMissionGroupModelMaster";
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
            if (m_Request.getMetadata())
            {
                jsonWriter.writePropertyName("metadata");
                jsonWriter.writeCharArray(*m_Request.getMetadata());
            }
            if (m_Request.getDescription())
            {
                jsonWriter.writePropertyName("description");
                jsonWriter.writeCharArray(*m_Request.getDescription());
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
            if (m_Request.getCompleteNotificationNamespaceId())
            {
                jsonWriter.writePropertyName("completeNotificationNamespaceId");
                jsonWriter.writeCharArray(*m_Request.getCompleteNotificationNamespaceId());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        CreateMissionGroupModelMasterTask(
            CreateMissionGroupModelMasterRequest request,
            Gs2WebSocketSessionTask<CreateMissionGroupModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateMissionGroupModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateMissionGroupModelMasterTask() GS2_OVERRIDE = default;
    };

    class GetMissionGroupModelMasterTask : public detail::Gs2WebSocketSessionTask<GetMissionGroupModelMasterResult>
    {
    private:
        GetMissionGroupModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "missionGroupModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getMissionGroupModelMaster";
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
            if (m_Request.getMissionGroupName())
            {
                jsonWriter.writePropertyName("missionGroupName");
                jsonWriter.writeCharArray(*m_Request.getMissionGroupName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetMissionGroupModelMasterTask(
            GetMissionGroupModelMasterRequest request,
            Gs2WebSocketSessionTask<GetMissionGroupModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetMissionGroupModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetMissionGroupModelMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateMissionGroupModelMasterTask : public detail::Gs2WebSocketSessionTask<UpdateMissionGroupModelMasterResult>
    {
    private:
        UpdateMissionGroupModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "missionGroupModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateMissionGroupModelMaster";
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
            if (m_Request.getMissionGroupName())
            {
                jsonWriter.writePropertyName("missionGroupName");
                jsonWriter.writeCharArray(*m_Request.getMissionGroupName());
            }
            if (m_Request.getMetadata())
            {
                jsonWriter.writePropertyName("metadata");
                jsonWriter.writeCharArray(*m_Request.getMetadata());
            }
            if (m_Request.getDescription())
            {
                jsonWriter.writePropertyName("description");
                jsonWriter.writeCharArray(*m_Request.getDescription());
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
            if (m_Request.getCompleteNotificationNamespaceId())
            {
                jsonWriter.writePropertyName("completeNotificationNamespaceId");
                jsonWriter.writeCharArray(*m_Request.getCompleteNotificationNamespaceId());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        UpdateMissionGroupModelMasterTask(
            UpdateMissionGroupModelMasterRequest request,
            Gs2WebSocketSessionTask<UpdateMissionGroupModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateMissionGroupModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateMissionGroupModelMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteMissionGroupModelMasterTask : public detail::Gs2WebSocketSessionTask<DeleteMissionGroupModelMasterResult>
    {
    private:
        DeleteMissionGroupModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "missionGroupModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteMissionGroupModelMaster";
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
            if (m_Request.getMissionGroupName())
            {
                jsonWriter.writePropertyName("missionGroupName");
                jsonWriter.writeCharArray(*m_Request.getMissionGroupName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        DeleteMissionGroupModelMasterTask(
            DeleteMissionGroupModelMasterRequest request,
            Gs2WebSocketSessionTask<DeleteMissionGroupModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteMissionGroupModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteMissionGroupModelMasterTask() GS2_OVERRIDE = default;
    };

    class DescribeNamespacesTask : public detail::Gs2WebSocketSessionTask<DescribeNamespacesResult>
    {
    private:
        DescribeNamespacesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
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
            return "mission";
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
            if (m_Request.getMissionCompleteScript())
            {
                jsonWriter.writePropertyName("missionCompleteScript");
                write(jsonWriter, *m_Request.getMissionCompleteScript());
            }
            if (m_Request.getCounterIncrementScript())
            {
                jsonWriter.writePropertyName("counterIncrementScript");
                write(jsonWriter, *m_Request.getCounterIncrementScript());
            }
            if (m_Request.getReceiveRewardsScript())
            {
                jsonWriter.writePropertyName("receiveRewardsScript");
                write(jsonWriter, *m_Request.getReceiveRewardsScript());
            }
            if (m_Request.getQueueNamespaceId())
            {
                jsonWriter.writePropertyName("queueNamespaceId");
                jsonWriter.writeCharArray(*m_Request.getQueueNamespaceId());
            }
            if (m_Request.getKeyId())
            {
                jsonWriter.writePropertyName("keyId");
                jsonWriter.writeCharArray(*m_Request.getKeyId());
            }
            if (m_Request.getCompleteNotification())
            {
                jsonWriter.writePropertyName("completeNotification");
                write(jsonWriter, *m_Request.getCompleteNotification());
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
            return "mission";
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
            return "mission";
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
            return "mission";
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
            if (m_Request.getMissionCompleteScript())
            {
                jsonWriter.writePropertyName("missionCompleteScript");
                write(jsonWriter, *m_Request.getMissionCompleteScript());
            }
            if (m_Request.getCounterIncrementScript())
            {
                jsonWriter.writePropertyName("counterIncrementScript");
                write(jsonWriter, *m_Request.getCounterIncrementScript());
            }
            if (m_Request.getReceiveRewardsScript())
            {
                jsonWriter.writePropertyName("receiveRewardsScript");
                write(jsonWriter, *m_Request.getReceiveRewardsScript());
            }
            if (m_Request.getQueueNamespaceId())
            {
                jsonWriter.writePropertyName("queueNamespaceId");
                jsonWriter.writeCharArray(*m_Request.getQueueNamespaceId());
            }
            if (m_Request.getKeyId())
            {
                jsonWriter.writePropertyName("keyId");
                jsonWriter.writeCharArray(*m_Request.getKeyId());
            }
            if (m_Request.getCompleteNotification())
            {
                jsonWriter.writePropertyName("completeNotification");
                write(jsonWriter, *m_Request.getCompleteNotification());
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
            return "mission";
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

    class DescribeCounterModelsTask : public detail::Gs2WebSocketSessionTask<DescribeCounterModelsResult>
    {
    private:
        DescribeCounterModelsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "counterModel";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeCounterModels";
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
        DescribeCounterModelsTask(
            DescribeCounterModelsRequest request,
            Gs2WebSocketSessionTask<DescribeCounterModelsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeCounterModelsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeCounterModelsTask() GS2_OVERRIDE = default;
    };

    class GetCounterModelTask : public detail::Gs2WebSocketSessionTask<GetCounterModelResult>
    {
    private:
        GetCounterModelRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "counterModel";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getCounterModel";
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
        }

    public:
        GetCounterModelTask(
            GetCounterModelRequest request,
            Gs2WebSocketSessionTask<GetCounterModelResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetCounterModelResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetCounterModelTask() GS2_OVERRIDE = default;
    };

protected:
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

    static void write(detail::json::JsonWriter& jsonWriter, const MissionTaskModelMaster& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getMissionTaskId())
        {
            jsonWriter.writePropertyName("missionTaskId");
            jsonWriter.writeCharArray(*obj.getMissionTaskId());
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
        if (obj.getDescription())
        {
            jsonWriter.writePropertyName("description");
            jsonWriter.writeCharArray(*obj.getDescription());
        }
        if (obj.getCounterName())
        {
            jsonWriter.writePropertyName("counterName");
            jsonWriter.writeCharArray(*obj.getCounterName());
        }
        if (obj.getTargetValue())
        {
            jsonWriter.writePropertyName("targetValue");
            jsonWriter.writeInt64(*obj.getTargetValue());
        }
        if (obj.getCompleteAcquireActions())
        {
            jsonWriter.writePropertyName("completeAcquireActions");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getCompleteAcquireActions();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (obj.getChallengePeriodEventId())
        {
            jsonWriter.writePropertyName("challengePeriodEventId");
            jsonWriter.writeCharArray(*obj.getChallengePeriodEventId());
        }
        if (obj.getPremiseMissionTaskName())
        {
            jsonWriter.writePropertyName("premiseMissionTaskName");
            jsonWriter.writeCharArray(*obj.getPremiseMissionTaskName());
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

    static void write(detail::json::JsonWriter& jsonWriter, const MissionGroupModel& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getMissionGroupId())
        {
            jsonWriter.writePropertyName("missionGroupId");
            jsonWriter.writeCharArray(*obj.getMissionGroupId());
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
        if (obj.getTasks())
        {
            jsonWriter.writePropertyName("tasks");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getTasks();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
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
        if (obj.getCompleteNotificationNamespaceId())
        {
            jsonWriter.writePropertyName("completeNotificationNamespaceId");
            jsonWriter.writeCharArray(*obj.getCompleteNotificationNamespaceId());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const CounterModelMaster& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getCounterId())
        {
            jsonWriter.writePropertyName("counterId");
            jsonWriter.writeCharArray(*obj.getCounterId());
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
        if (obj.getDescription())
        {
            jsonWriter.writePropertyName("description");
            jsonWriter.writeCharArray(*obj.getDescription());
        }
        if (obj.getScopes())
        {
            jsonWriter.writePropertyName("scopes");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getScopes();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (obj.getChallengePeriodEventId())
        {
            jsonWriter.writePropertyName("challengePeriodEventId");
            jsonWriter.writeCharArray(*obj.getChallengePeriodEventId());
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

    static void write(detail::json::JsonWriter& jsonWriter, const NotificationSetting& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getGatewayNamespaceId())
        {
            jsonWriter.writePropertyName("gatewayNamespaceId");
            jsonWriter.writeCharArray(*obj.getGatewayNamespaceId());
        }
        if (obj.getEnableTransferMobileNotification())
        {
            jsonWriter.writePropertyName("enableTransferMobileNotification");
            jsonWriter.writeBool(*obj.getEnableTransferMobileNotification());
        }
        if (obj.getSound())
        {
            jsonWriter.writePropertyName("sound");
            jsonWriter.writeCharArray(*obj.getSound());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const ScopedValue& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getResetType())
        {
            jsonWriter.writePropertyName("resetType");
            jsonWriter.writeCharArray(*obj.getResetType());
        }
        if (obj.getValue())
        {
            jsonWriter.writePropertyName("value");
            jsonWriter.writeInt64(*obj.getValue());
        }
        if (obj.getUpdatedAt())
        {
            jsonWriter.writePropertyName("updatedAt");
            jsonWriter.writeInt64(*obj.getUpdatedAt());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const CurrentMissionMaster& obj)
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
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const Config& obj)
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

    static void write(detail::json::JsonWriter& jsonWriter, const Counter& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getCounterId())
        {
            jsonWriter.writePropertyName("counterId");
            jsonWriter.writeCharArray(*obj.getCounterId());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getName())
        {
            jsonWriter.writePropertyName("name");
            jsonWriter.writeCharArray(*obj.getName());
        }
        if (obj.getValues())
        {
            jsonWriter.writePropertyName("values");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getValues();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
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

    static void write(detail::json::JsonWriter& jsonWriter, const MissionTaskModel& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getMissionTaskId())
        {
            jsonWriter.writePropertyName("missionTaskId");
            jsonWriter.writeCharArray(*obj.getMissionTaskId());
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
        if (obj.getCounterName())
        {
            jsonWriter.writePropertyName("counterName");
            jsonWriter.writeCharArray(*obj.getCounterName());
        }
        if (obj.getTargetValue())
        {
            jsonWriter.writePropertyName("targetValue");
            jsonWriter.writeInt64(*obj.getTargetValue());
        }
        if (obj.getCompleteAcquireActions())
        {
            jsonWriter.writePropertyName("completeAcquireActions");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getCompleteAcquireActions();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (obj.getChallengePeriodEventId())
        {
            jsonWriter.writePropertyName("challengePeriodEventId");
            jsonWriter.writeCharArray(*obj.getChallengePeriodEventId());
        }
        if (obj.getPremiseMissionTaskName())
        {
            jsonWriter.writePropertyName("premiseMissionTaskName");
            jsonWriter.writeCharArray(*obj.getPremiseMissionTaskName());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const Complete& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getCompleteId())
        {
            jsonWriter.writePropertyName("completeId");
            jsonWriter.writeCharArray(*obj.getCompleteId());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getMissionGroupName())
        {
            jsonWriter.writePropertyName("missionGroupName");
            jsonWriter.writeCharArray(*obj.getMissionGroupName());
        }
        if (obj.getCompletedMissionTaskNames())
        {
            jsonWriter.writePropertyName("completedMissionTaskNames");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getCompletedMissionTaskNames();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                jsonWriter.writeCharArray(list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (obj.getReceivedMissionTaskNames())
        {
            jsonWriter.writePropertyName("receivedMissionTaskNames");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getReceivedMissionTaskNames();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                jsonWriter.writeCharArray(list[i]);
            }
            jsonWriter.writeArrayEnd();
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

    static void write(detail::json::JsonWriter& jsonWriter, const AcquireAction& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getAction())
        {
            jsonWriter.writePropertyName("action");
            jsonWriter.writeCharArray(*obj.getAction());
        }
        if (obj.getRequest())
        {
            jsonWriter.writePropertyName("request");
            jsonWriter.writeCharArray(*obj.getRequest());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const MissionGroupModelMaster& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getMissionGroupId())
        {
            jsonWriter.writePropertyName("missionGroupId");
            jsonWriter.writeCharArray(*obj.getMissionGroupId());
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
        if (obj.getDescription())
        {
            jsonWriter.writePropertyName("description");
            jsonWriter.writeCharArray(*obj.getDescription());
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
        if (obj.getCompleteNotificationNamespaceId())
        {
            jsonWriter.writePropertyName("completeNotificationNamespaceId");
            jsonWriter.writeCharArray(*obj.getCompleteNotificationNamespaceId());
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
        if (obj.getMissionCompleteScript())
        {
            jsonWriter.writePropertyName("missionCompleteScript");
            write(jsonWriter, *obj.getMissionCompleteScript());
        }
        if (obj.getCounterIncrementScript())
        {
            jsonWriter.writePropertyName("counterIncrementScript");
            write(jsonWriter, *obj.getCounterIncrementScript());
        }
        if (obj.getReceiveRewardsScript())
        {
            jsonWriter.writePropertyName("receiveRewardsScript");
            write(jsonWriter, *obj.getReceiveRewardsScript());
        }
        if (obj.getQueueNamespaceId())
        {
            jsonWriter.writePropertyName("queueNamespaceId");
            jsonWriter.writeCharArray(*obj.getQueueNamespaceId());
        }
        if (obj.getKeyId())
        {
            jsonWriter.writePropertyName("keyId");
            jsonWriter.writeCharArray(*obj.getKeyId());
        }
        if (obj.getCompleteNotification())
        {
            jsonWriter.writePropertyName("completeNotification");
            write(jsonWriter, *obj.getCompleteNotification());
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

    static void write(detail::json::JsonWriter& jsonWriter, const CounterScopeModel& obj)
    {
        jsonWriter.writeObjectStart();
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

    static void write(detail::json::JsonWriter& jsonWriter, const CounterModel& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getCounterId())
        {
            jsonWriter.writePropertyName("counterId");
            jsonWriter.writeCharArray(*obj.getCounterId());
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
        if (obj.getScopes())
        {
            jsonWriter.writePropertyName("scopes");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getScopes();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (obj.getChallengePeriodEventId())
        {
            jsonWriter.writePropertyName("challengePeriodEventId");
            jsonWriter.writeCharArray(*obj.getChallengePeriodEventId());
        }
        jsonWriter.writeObjectEnd();
    }


public:
    /**
     * コンストラクタ。
     *
     * @param gs2WebSocketSession WebSocket API 用セッション
     */
    explicit Gs2MissionWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
        AbstractGs2ClientBase(gs2WebSocketSession)
    {
    }

	/**
	 * ミッションタスクマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeMissionTaskModelMasters(DescribeMissionTaskModelMastersRequest request, std::function<void(AsyncDescribeMissionTaskModelMastersResult)> callback)
    {
        DescribeMissionTaskModelMastersTask& task = *new DescribeMissionTaskModelMastersTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ミッションタスクマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createMissionTaskModelMaster(CreateMissionTaskModelMasterRequest request, std::function<void(AsyncCreateMissionTaskModelMasterResult)> callback)
    {
        CreateMissionTaskModelMasterTask& task = *new CreateMissionTaskModelMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ミッションタスクマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMissionTaskModelMaster(GetMissionTaskModelMasterRequest request, std::function<void(AsyncGetMissionTaskModelMasterResult)> callback)
    {
        GetMissionTaskModelMasterTask& task = *new GetMissionTaskModelMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ミッションタスクマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateMissionTaskModelMaster(UpdateMissionTaskModelMasterRequest request, std::function<void(AsyncUpdateMissionTaskModelMasterResult)> callback)
    {
        UpdateMissionTaskModelMasterTask& task = *new UpdateMissionTaskModelMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ミッションタスクマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteMissionTaskModelMaster(DeleteMissionTaskModelMasterRequest request, std::function<void(AsyncDeleteMissionTaskModelMasterResult)> callback)
    {
        DeleteMissionTaskModelMasterTask& task = *new DeleteMissionTaskModelMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ミッショングループの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeMissionGroupModels(DescribeMissionGroupModelsRequest request, std::function<void(AsyncDescribeMissionGroupModelsResult)> callback)
    {
        DescribeMissionGroupModelsTask& task = *new DescribeMissionGroupModelsTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ミッショングループを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMissionGroupModel(GetMissionGroupModelRequest request, std::function<void(AsyncGetMissionGroupModelResult)> callback)
    {
        GetMissionGroupModelTask& task = *new GetMissionGroupModelTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * カウンターの種類マスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCounterModelMasters(DescribeCounterModelMastersRequest request, std::function<void(AsyncDescribeCounterModelMastersResult)> callback)
    {
        DescribeCounterModelMastersTask& task = *new DescribeCounterModelMastersTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * カウンターの種類マスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createCounterModelMaster(CreateCounterModelMasterRequest request, std::function<void(AsyncCreateCounterModelMasterResult)> callback)
    {
        CreateCounterModelMasterTask& task = *new CreateCounterModelMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * カウンターの種類マスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCounterModelMaster(GetCounterModelMasterRequest request, std::function<void(AsyncGetCounterModelMasterResult)> callback)
    {
        GetCounterModelMasterTask& task = *new GetCounterModelMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * カウンターの種類マスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCounterModelMaster(UpdateCounterModelMasterRequest request, std::function<void(AsyncUpdateCounterModelMasterResult)> callback)
    {
        UpdateCounterModelMasterTask& task = *new UpdateCounterModelMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * カウンターの種類マスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteCounterModelMaster(DeleteCounterModelMasterRequest request, std::function<void(AsyncDeleteCounterModelMasterResult)> callback)
    {
        DeleteCounterModelMasterTask& task = *new DeleteCounterModelMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 現在有効なミッションのマスターデータをエクスポートします<br>
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
	 * 現在有効なミッションを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentMissionMaster(GetCurrentMissionMasterRequest request, std::function<void(AsyncGetCurrentMissionMasterResult)> callback)
    {
        GetCurrentMissionMasterTask& task = *new GetCurrentMissionMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 現在有効なミッションを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentMissionMaster(UpdateCurrentMissionMasterRequest request, std::function<void(AsyncUpdateCurrentMissionMasterResult)> callback)
    {
        UpdateCurrentMissionMasterTask& task = *new UpdateCurrentMissionMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 現在有効なミッションを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentMissionMasterFromGitHub(UpdateCurrentMissionMasterFromGitHubRequest request, std::function<void(AsyncUpdateCurrentMissionMasterFromGitHubResult)> callback)
    {
        UpdateCurrentMissionMasterFromGitHubTask& task = *new UpdateCurrentMissionMasterFromGitHubTask(std::move(request), callback);
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
	 * ユーザIDを指定してカウンターの一覧を取得<br>
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
	 * カウンターに加算<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void increaseCounterByUserId(IncreaseCounterByUserIdRequest request, std::function<void(AsyncIncreaseCounterByUserIdResult)> callback)
    {
        IncreaseCounterByUserIdTask& task = *new IncreaseCounterByUserIdTask(std::move(request), callback);
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
	 * カウンターを削除<br>
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
	 * カウンター加算<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void increaseByStampSheet(IncreaseByStampSheetRequest request, std::function<void(AsyncIncreaseByStampSheetResult)> callback)
    {
        IncreaseByStampSheetTask& task = *new IncreaseByStampSheetTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ミッションタスクの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeMissionTaskModels(DescribeMissionTaskModelsRequest request, std::function<void(AsyncDescribeMissionTaskModelsResult)> callback)
    {
        DescribeMissionTaskModelsTask& task = *new DescribeMissionTaskModelsTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ミッションタスクを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMissionTaskModel(GetMissionTaskModelRequest request, std::function<void(AsyncGetMissionTaskModelResult)> callback)
    {
        GetMissionTaskModelTask& task = *new GetMissionTaskModelTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 達成状況の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCompletes(DescribeCompletesRequest request, std::function<void(AsyncDescribeCompletesResult)> callback)
    {
        DescribeCompletesTask& task = *new DescribeCompletesTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザIDを指定して達成状況の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCompletesByUserId(DescribeCompletesByUserIdRequest request, std::function<void(AsyncDescribeCompletesByUserIdResult)> callback)
    {
        DescribeCompletesByUserIdTask& task = *new DescribeCompletesByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ミッション達成報酬を受領するためのスタンプシートを発行<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void complete(CompleteRequest request, std::function<void(AsyncCompleteResult)> callback)
    {
        CompleteTask& task = *new CompleteTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 達成状況を新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void completeByUserId(CompleteByUserIdRequest request, std::function<void(AsyncCompleteByUserIdResult)> callback)
    {
        CompleteByUserIdTask& task = *new CompleteByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ミッション達成報酬を受領する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void receiveByUserId(ReceiveByUserIdRequest request, std::function<void(AsyncReceiveByUserIdResult)> callback)
    {
        ReceiveByUserIdTask& task = *new ReceiveByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 達成状況を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getComplete(GetCompleteRequest request, std::function<void(AsyncGetCompleteResult)> callback)
    {
        GetCompleteTask& task = *new GetCompleteTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザIDを指定して達成状況を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCompleteByUserId(GetCompleteByUserIdRequest request, std::function<void(AsyncGetCompleteByUserIdResult)> callback)
    {
        GetCompleteByUserIdTask& task = *new GetCompleteByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 達成状況を削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteCompleteByUserId(DeleteCompleteByUserIdRequest request, std::function<void(AsyncDeleteCompleteByUserIdResult)> callback)
    {
        DeleteCompleteByUserIdTask& task = *new DeleteCompleteByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 達成状況を作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void receiveByStampTask(ReceiveByStampTaskRequest request, std::function<void(AsyncReceiveByStampTaskResult)> callback)
    {
        ReceiveByStampTaskTask& task = *new ReceiveByStampTaskTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ミッショングループマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeMissionGroupModelMasters(DescribeMissionGroupModelMastersRequest request, std::function<void(AsyncDescribeMissionGroupModelMastersResult)> callback)
    {
        DescribeMissionGroupModelMastersTask& task = *new DescribeMissionGroupModelMastersTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ミッショングループマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createMissionGroupModelMaster(CreateMissionGroupModelMasterRequest request, std::function<void(AsyncCreateMissionGroupModelMasterResult)> callback)
    {
        CreateMissionGroupModelMasterTask& task = *new CreateMissionGroupModelMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ミッショングループマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMissionGroupModelMaster(GetMissionGroupModelMasterRequest request, std::function<void(AsyncGetMissionGroupModelMasterResult)> callback)
    {
        GetMissionGroupModelMasterTask& task = *new GetMissionGroupModelMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ミッショングループマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateMissionGroupModelMaster(UpdateMissionGroupModelMasterRequest request, std::function<void(AsyncUpdateMissionGroupModelMasterResult)> callback)
    {
        UpdateMissionGroupModelMasterTask& task = *new UpdateMissionGroupModelMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ミッショングループマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteMissionGroupModelMaster(DeleteMissionGroupModelMasterRequest request, std::function<void(AsyncDeleteMissionGroupModelMasterResult)> callback)
    {
        DeleteMissionGroupModelMasterTask& task = *new DeleteMissionGroupModelMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
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
	 * カウンターの種類の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCounterModels(DescribeCounterModelsRequest request, std::function<void(AsyncDescribeCounterModelsResult)> callback)
    {
        DescribeCounterModelsTask& task = *new DescribeCounterModelsTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * カウンターの種類を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCounterModel(GetCounterModelRequest request, std::function<void(AsyncGetCounterModelResult)> callback)
    {
        GetCounterModelTask& task = *new GetCounterModelTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_MISSION_GS2MISSIONWEBSOCKETCLIENT_HPP_