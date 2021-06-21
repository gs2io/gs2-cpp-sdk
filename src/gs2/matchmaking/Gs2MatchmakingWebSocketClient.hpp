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
#include <gs2/core/util/StringVariable.hpp>
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
#include "request/DescribeRatingModelMastersRequest.hpp"
#include "request/CreateRatingModelMasterRequest.hpp"
#include "request/GetRatingModelMasterRequest.hpp"
#include "request/UpdateRatingModelMasterRequest.hpp"
#include "request/DeleteRatingModelMasterRequest.hpp"
#include "request/DescribeRatingModelsRequest.hpp"
#include "request/GetRatingModelRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentRatingModelMasterRequest.hpp"
#include "request/UpdateCurrentRatingModelMasterRequest.hpp"
#include "request/UpdateCurrentRatingModelMasterFromGitHubRequest.hpp"
#include "request/DescribeRatingsRequest.hpp"
#include "request/DescribeRatingsByUserIdRequest.hpp"
#include "request/GetRatingRequest.hpp"
#include "request/GetRatingByUserIdRequest.hpp"
#include "request/PutResultRequest.hpp"
#include "request/DeleteRatingRequest.hpp"
#include "request/GetBallotRequest.hpp"
#include "request/GetBallotByUserIdRequest.hpp"
#include "request/VoteRequest.hpp"
#include "request/VoteMultipleRequest.hpp"
#include "request/CommitVoteRequest.hpp"
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
#include "result/DescribeRatingModelMastersResult.hpp"
#include "result/CreateRatingModelMasterResult.hpp"
#include "result/GetRatingModelMasterResult.hpp"
#include "result/UpdateRatingModelMasterResult.hpp"
#include "result/DeleteRatingModelMasterResult.hpp"
#include "result/DescribeRatingModelsResult.hpp"
#include "result/GetRatingModelResult.hpp"
#include "result/ExportMasterResult.hpp"
#include "result/GetCurrentRatingModelMasterResult.hpp"
#include "result/UpdateCurrentRatingModelMasterResult.hpp"
#include "result/UpdateCurrentRatingModelMasterFromGitHubResult.hpp"
#include "result/DescribeRatingsResult.hpp"
#include "result/DescribeRatingsByUserIdResult.hpp"
#include "result/GetRatingResult.hpp"
#include "result/GetRatingByUserIdResult.hpp"
#include "result/PutResultResult.hpp"
#include "result/DeleteRatingResult.hpp"
#include "result/GetBallotResult.hpp"
#include "result/GetBallotByUserIdResult.hpp"
#include "result/VoteResult.hpp"
#include "result/VoteMultipleResult.hpp"
#include "result/CommitVoteResult.hpp"
#include <cstring>

namespace gs2 { namespace matchmaking {

/**
 * GS2 Matchmaking API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2MatchmakingWebSocketClient : public AbstractGs2ClientBase
{
private:

    class CreateNamespaceTask : public detail::Gs2WebSocketSessionTask<CreateNamespaceResult>
    {
    private:
        CreateNamespaceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
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
            if (m_Request.getEnableRating())
            {
                jsonWriter.writePropertyName("enableRating");
                jsonWriter.writeBool(*m_Request.getEnableRating());
            }
            if (m_Request.getCreateGatheringTriggerType())
            {
                jsonWriter.writePropertyName("createGatheringTriggerType");
                jsonWriter.writeCharArray(*m_Request.getCreateGatheringTriggerType());
            }
            if (m_Request.getCreateGatheringTriggerRealtimeNamespaceId())
            {
                jsonWriter.writePropertyName("createGatheringTriggerRealtimeNamespaceId");
                jsonWriter.writeCharArray(*m_Request.getCreateGatheringTriggerRealtimeNamespaceId());
            }
            if (m_Request.getCreateGatheringTriggerScriptId())
            {
                jsonWriter.writePropertyName("createGatheringTriggerScriptId");
                jsonWriter.writeCharArray(*m_Request.getCreateGatheringTriggerScriptId());
            }
            if (m_Request.getCompleteMatchmakingTriggerType())
            {
                jsonWriter.writePropertyName("completeMatchmakingTriggerType");
                jsonWriter.writeCharArray(*m_Request.getCompleteMatchmakingTriggerType());
            }
            if (m_Request.getCompleteMatchmakingTriggerRealtimeNamespaceId())
            {
                jsonWriter.writePropertyName("completeMatchmakingTriggerRealtimeNamespaceId");
                jsonWriter.writeCharArray(*m_Request.getCompleteMatchmakingTriggerRealtimeNamespaceId());
            }
            if (m_Request.getCompleteMatchmakingTriggerScriptId())
            {
                jsonWriter.writePropertyName("completeMatchmakingTriggerScriptId");
                jsonWriter.writeCharArray(*m_Request.getCompleteMatchmakingTriggerScriptId());
            }
            if (m_Request.getJoinNotification())
            {
                jsonWriter.writePropertyName("joinNotification");
                write(jsonWriter, *m_Request.getJoinNotification());
            }
            if (m_Request.getLeaveNotification())
            {
                jsonWriter.writePropertyName("leaveNotification");
                write(jsonWriter, *m_Request.getLeaveNotification());
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
            return "matchmaking";
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
            return "matchmaking";
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
            return "matchmaking";
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
            if (m_Request.getEnableRating())
            {
                jsonWriter.writePropertyName("enableRating");
                jsonWriter.writeBool(*m_Request.getEnableRating());
            }
            if (m_Request.getCreateGatheringTriggerType())
            {
                jsonWriter.writePropertyName("createGatheringTriggerType");
                jsonWriter.writeCharArray(*m_Request.getCreateGatheringTriggerType());
            }
            if (m_Request.getCreateGatheringTriggerRealtimeNamespaceId())
            {
                jsonWriter.writePropertyName("createGatheringTriggerRealtimeNamespaceId");
                jsonWriter.writeCharArray(*m_Request.getCreateGatheringTriggerRealtimeNamespaceId());
            }
            if (m_Request.getCreateGatheringTriggerScriptId())
            {
                jsonWriter.writePropertyName("createGatheringTriggerScriptId");
                jsonWriter.writeCharArray(*m_Request.getCreateGatheringTriggerScriptId());
            }
            if (m_Request.getCompleteMatchmakingTriggerType())
            {
                jsonWriter.writePropertyName("completeMatchmakingTriggerType");
                jsonWriter.writeCharArray(*m_Request.getCompleteMatchmakingTriggerType());
            }
            if (m_Request.getCompleteMatchmakingTriggerRealtimeNamespaceId())
            {
                jsonWriter.writePropertyName("completeMatchmakingTriggerRealtimeNamespaceId");
                jsonWriter.writeCharArray(*m_Request.getCompleteMatchmakingTriggerRealtimeNamespaceId());
            }
            if (m_Request.getCompleteMatchmakingTriggerScriptId())
            {
                jsonWriter.writePropertyName("completeMatchmakingTriggerScriptId");
                jsonWriter.writeCharArray(*m_Request.getCompleteMatchmakingTriggerScriptId());
            }
            if (m_Request.getJoinNotification())
            {
                jsonWriter.writePropertyName("joinNotification");
                write(jsonWriter, *m_Request.getJoinNotification());
            }
            if (m_Request.getLeaveNotification())
            {
                jsonWriter.writePropertyName("leaveNotification");
                write(jsonWriter, *m_Request.getLeaveNotification());
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
            return "matchmaking";
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

    class CreateGatheringTask : public detail::Gs2WebSocketSessionTask<CreateGatheringResult>
    {
    private:
        CreateGatheringRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "gathering";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "createGathering";
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
            if (m_Request.getPlayer())
            {
                jsonWriter.writePropertyName("player");
                write(jsonWriter, *m_Request.getPlayer());
            }
            if (m_Request.getAttributeRanges())
            {
                jsonWriter.writePropertyName("attributeRanges");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getAttributeRanges();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(jsonWriter, list[i]);
                }
                jsonWriter.writeArrayEnd();
            }
            if (m_Request.getCapacityOfRoles())
            {
                jsonWriter.writePropertyName("capacityOfRoles");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getCapacityOfRoles();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(jsonWriter, list[i]);
                }
                jsonWriter.writeArrayEnd();
            }
            if (m_Request.getAllowUserIds())
            {
                jsonWriter.writePropertyName("allowUserIds");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getAllowUserIds();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    jsonWriter.writeCharArray(list[i]);
                }
                jsonWriter.writeArrayEnd();
            }
            if (m_Request.getExpiresAt())
            {
                jsonWriter.writePropertyName("expiresAt");
                jsonWriter.writeInt64(*m_Request.getExpiresAt());
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
        CreateGatheringTask(
            CreateGatheringRequest request,
            Gs2WebSocketSessionTask<CreateGatheringResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateGatheringResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateGatheringTask() GS2_OVERRIDE = default;
    };

    class CreateGatheringByUserIdTask : public detail::Gs2WebSocketSessionTask<CreateGatheringByUserIdResult>
    {
    private:
        CreateGatheringByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "gathering";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "createGatheringByUserId";
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
            if (m_Request.getPlayer())
            {
                jsonWriter.writePropertyName("player");
                write(jsonWriter, *m_Request.getPlayer());
            }
            if (m_Request.getAttributeRanges())
            {
                jsonWriter.writePropertyName("attributeRanges");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getAttributeRanges();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(jsonWriter, list[i]);
                }
                jsonWriter.writeArrayEnd();
            }
            if (m_Request.getCapacityOfRoles())
            {
                jsonWriter.writePropertyName("capacityOfRoles");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getCapacityOfRoles();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(jsonWriter, list[i]);
                }
                jsonWriter.writeArrayEnd();
            }
            if (m_Request.getAllowUserIds())
            {
                jsonWriter.writePropertyName("allowUserIds");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getAllowUserIds();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    jsonWriter.writeCharArray(list[i]);
                }
                jsonWriter.writeArrayEnd();
            }
            if (m_Request.getExpiresAt())
            {
                jsonWriter.writePropertyName("expiresAt");
                jsonWriter.writeInt64(*m_Request.getExpiresAt());
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
        CreateGatheringByUserIdTask(
            CreateGatheringByUserIdRequest request,
            Gs2WebSocketSessionTask<CreateGatheringByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateGatheringByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateGatheringByUserIdTask() GS2_OVERRIDE = default;
    };

    class UpdateGatheringTask : public detail::Gs2WebSocketSessionTask<UpdateGatheringResult>
    {
    private:
        UpdateGatheringRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "gathering";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateGathering";
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
            if (m_Request.getGatheringName())
            {
                jsonWriter.writePropertyName("gatheringName");
                jsonWriter.writeCharArray(*m_Request.getGatheringName());
            }
            if (m_Request.getAttributeRanges())
            {
                jsonWriter.writePropertyName("attributeRanges");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getAttributeRanges();
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
        UpdateGatheringTask(
            UpdateGatheringRequest request,
            Gs2WebSocketSessionTask<UpdateGatheringResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateGatheringResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateGatheringTask() GS2_OVERRIDE = default;
    };

    class UpdateGatheringByUserIdTask : public detail::Gs2WebSocketSessionTask<UpdateGatheringByUserIdResult>
    {
    private:
        UpdateGatheringByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "gathering";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateGatheringByUserId";
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
            if (m_Request.getGatheringName())
            {
                jsonWriter.writePropertyName("gatheringName");
                jsonWriter.writeCharArray(*m_Request.getGatheringName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getAttributeRanges())
            {
                jsonWriter.writePropertyName("attributeRanges");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getAttributeRanges();
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
        UpdateGatheringByUserIdTask(
            UpdateGatheringByUserIdRequest request,
            Gs2WebSocketSessionTask<UpdateGatheringByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateGatheringByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateGatheringByUserIdTask() GS2_OVERRIDE = default;
    };

    class DoMatchmakingByPlayerTask : public detail::Gs2WebSocketSessionTask<DoMatchmakingByPlayerResult>
    {
    private:
        DoMatchmakingByPlayerRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "gathering";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "doMatchmakingByPlayer";
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
            if (m_Request.getPlayer())
            {
                jsonWriter.writePropertyName("player");
                write(jsonWriter, *m_Request.getPlayer());
            }
            if (m_Request.getMatchmakingContextToken())
            {
                jsonWriter.writePropertyName("matchmakingContextToken");
                jsonWriter.writeCharArray(*m_Request.getMatchmakingContextToken());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        DoMatchmakingByPlayerTask(
            DoMatchmakingByPlayerRequest request,
            Gs2WebSocketSessionTask<DoMatchmakingByPlayerResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DoMatchmakingByPlayerResult>(callback),
            m_Request(std::move(request))
        {}

        ~DoMatchmakingByPlayerTask() GS2_OVERRIDE = default;
    };

    class DoMatchmakingTask : public detail::Gs2WebSocketSessionTask<DoMatchmakingResult>
    {
    private:
        DoMatchmakingRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "gathering";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "doMatchmaking";
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
            if (m_Request.getPlayer())
            {
                jsonWriter.writePropertyName("player");
                write(jsonWriter, *m_Request.getPlayer());
            }
            if (m_Request.getMatchmakingContextToken())
            {
                jsonWriter.writePropertyName("matchmakingContextToken");
                jsonWriter.writeCharArray(*m_Request.getMatchmakingContextToken());
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
        DoMatchmakingTask(
            DoMatchmakingRequest request,
            Gs2WebSocketSessionTask<DoMatchmakingResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DoMatchmakingResult>(callback),
            m_Request(std::move(request))
        {}

        ~DoMatchmakingTask() GS2_OVERRIDE = default;
    };

    class GetGatheringTask : public detail::Gs2WebSocketSessionTask<GetGatheringResult>
    {
    private:
        GetGatheringRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "gathering";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getGathering";
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
            if (m_Request.getGatheringName())
            {
                jsonWriter.writePropertyName("gatheringName");
                jsonWriter.writeCharArray(*m_Request.getGatheringName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetGatheringTask(
            GetGatheringRequest request,
            Gs2WebSocketSessionTask<GetGatheringResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetGatheringResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetGatheringTask() GS2_OVERRIDE = default;
    };

    class CancelMatchmakingTask : public detail::Gs2WebSocketSessionTask<CancelMatchmakingResult>
    {
    private:
        CancelMatchmakingRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "gathering";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "cancelMatchmaking";
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
            if (m_Request.getGatheringName())
            {
                jsonWriter.writePropertyName("gatheringName");
                jsonWriter.writeCharArray(*m_Request.getGatheringName());
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
        CancelMatchmakingTask(
            CancelMatchmakingRequest request,
            Gs2WebSocketSessionTask<CancelMatchmakingResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CancelMatchmakingResult>(callback),
            m_Request(std::move(request))
        {}

        ~CancelMatchmakingTask() GS2_OVERRIDE = default;
    };

    class CancelMatchmakingByUserIdTask : public detail::Gs2WebSocketSessionTask<CancelMatchmakingByUserIdResult>
    {
    private:
        CancelMatchmakingByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "gathering";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "cancelMatchmakingByUserId";
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
            if (m_Request.getGatheringName())
            {
                jsonWriter.writePropertyName("gatheringName");
                jsonWriter.writeCharArray(*m_Request.getGatheringName());
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
        CancelMatchmakingByUserIdTask(
            CancelMatchmakingByUserIdRequest request,
            Gs2WebSocketSessionTask<CancelMatchmakingByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CancelMatchmakingByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~CancelMatchmakingByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteGatheringTask : public detail::Gs2WebSocketSessionTask<DeleteGatheringResult>
    {
    private:
        DeleteGatheringRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "gathering";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteGathering";
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
            if (m_Request.getGatheringName())
            {
                jsonWriter.writePropertyName("gatheringName");
                jsonWriter.writeCharArray(*m_Request.getGatheringName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        DeleteGatheringTask(
            DeleteGatheringRequest request,
            Gs2WebSocketSessionTask<DeleteGatheringResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteGatheringResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteGatheringTask() GS2_OVERRIDE = default;
    };

    class CreateRatingModelMasterTask : public detail::Gs2WebSocketSessionTask<CreateRatingModelMasterResult>
    {
    private:
        CreateRatingModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "ratingModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "createRatingModelMaster";
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
            if (m_Request.getVolatility())
            {
                jsonWriter.writePropertyName("volatility");
                jsonWriter.writeInt32(*m_Request.getVolatility());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        CreateRatingModelMasterTask(
            CreateRatingModelMasterRequest request,
            Gs2WebSocketSessionTask<CreateRatingModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateRatingModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateRatingModelMasterTask() GS2_OVERRIDE = default;
    };

    class GetRatingModelMasterTask : public detail::Gs2WebSocketSessionTask<GetRatingModelMasterResult>
    {
    private:
        GetRatingModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "ratingModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getRatingModelMaster";
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
            if (m_Request.getRatingName())
            {
                jsonWriter.writePropertyName("ratingName");
                jsonWriter.writeCharArray(*m_Request.getRatingName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetRatingModelMasterTask(
            GetRatingModelMasterRequest request,
            Gs2WebSocketSessionTask<GetRatingModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetRatingModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetRatingModelMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateRatingModelMasterTask : public detail::Gs2WebSocketSessionTask<UpdateRatingModelMasterResult>
    {
    private:
        UpdateRatingModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "ratingModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateRatingModelMaster";
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
            if (m_Request.getRatingName())
            {
                jsonWriter.writePropertyName("ratingName");
                jsonWriter.writeCharArray(*m_Request.getRatingName());
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
            if (m_Request.getVolatility())
            {
                jsonWriter.writePropertyName("volatility");
                jsonWriter.writeInt32(*m_Request.getVolatility());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        UpdateRatingModelMasterTask(
            UpdateRatingModelMasterRequest request,
            Gs2WebSocketSessionTask<UpdateRatingModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateRatingModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateRatingModelMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteRatingModelMasterTask : public detail::Gs2WebSocketSessionTask<DeleteRatingModelMasterResult>
    {
    private:
        DeleteRatingModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "ratingModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteRatingModelMaster";
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
            if (m_Request.getRatingName())
            {
                jsonWriter.writePropertyName("ratingName");
                jsonWriter.writeCharArray(*m_Request.getRatingName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        DeleteRatingModelMasterTask(
            DeleteRatingModelMasterRequest request,
            Gs2WebSocketSessionTask<DeleteRatingModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteRatingModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteRatingModelMasterTask() GS2_OVERRIDE = default;
    };

    class GetRatingModelTask : public detail::Gs2WebSocketSessionTask<GetRatingModelResult>
    {
    private:
        GetRatingModelRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "ratingModel";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getRatingModel";
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
            if (m_Request.getRatingName())
            {
                jsonWriter.writePropertyName("ratingName");
                jsonWriter.writeCharArray(*m_Request.getRatingName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetRatingModelTask(
            GetRatingModelRequest request,
            Gs2WebSocketSessionTask<GetRatingModelResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetRatingModelResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetRatingModelTask() GS2_OVERRIDE = default;
    };

    class GetRatingTask : public detail::Gs2WebSocketSessionTask<GetRatingResult>
    {
    private:
        GetRatingRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "rating";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getRating";
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
            if (m_Request.getRatingName())
            {
                jsonWriter.writePropertyName("ratingName");
                jsonWriter.writeCharArray(*m_Request.getRatingName());
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
        GetRatingTask(
            GetRatingRequest request,
            Gs2WebSocketSessionTask<GetRatingResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetRatingResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetRatingTask() GS2_OVERRIDE = default;
    };

    class GetRatingByUserIdTask : public detail::Gs2WebSocketSessionTask<GetRatingByUserIdResult>
    {
    private:
        GetRatingByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "rating";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getRatingByUserId";
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
            if (m_Request.getRatingName())
            {
                jsonWriter.writePropertyName("ratingName");
                jsonWriter.writeCharArray(*m_Request.getRatingName());
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
        GetRatingByUserIdTask(
            GetRatingByUserIdRequest request,
            Gs2WebSocketSessionTask<GetRatingByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetRatingByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetRatingByUserIdTask() GS2_OVERRIDE = default;
    };

    class PutResultTask : public detail::Gs2WebSocketSessionTask<PutResultResult>
    {
    private:
        PutResultRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "rating";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "putResult";
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
            if (m_Request.getRatingName())
            {
                jsonWriter.writePropertyName("ratingName");
                jsonWriter.writeCharArray(*m_Request.getRatingName());
            }
            if (m_Request.getGameResults())
            {
                jsonWriter.writePropertyName("gameResults");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getGameResults();
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
        }

    public:
        PutResultTask(
            PutResultRequest request,
            Gs2WebSocketSessionTask<PutResultResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<PutResultResult>(callback),
            m_Request(std::move(request))
        {}

        ~PutResultTask() GS2_OVERRIDE = default;
    };

    class DeleteRatingTask : public detail::Gs2WebSocketSessionTask<DeleteRatingResult>
    {
    private:
        DeleteRatingRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "rating";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteRating";
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
            if (m_Request.getRatingName())
            {
                jsonWriter.writePropertyName("ratingName");
                jsonWriter.writeCharArray(*m_Request.getRatingName());
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
        DeleteRatingTask(
            DeleteRatingRequest request,
            Gs2WebSocketSessionTask<DeleteRatingResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteRatingResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteRatingTask() GS2_OVERRIDE = default;
    };

    class GetBallotTask : public detail::Gs2WebSocketSessionTask<GetBallotResult>
    {
    private:
        GetBallotRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "vote";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getBallot";
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
            if (m_Request.getRatingName())
            {
                jsonWriter.writePropertyName("ratingName");
                jsonWriter.writeCharArray(*m_Request.getRatingName());
            }
            if (m_Request.getGatheringName())
            {
                jsonWriter.writePropertyName("gatheringName");
                jsonWriter.writeCharArray(*m_Request.getGatheringName());
            }
            if (m_Request.getNumberOfPlayer())
            {
                jsonWriter.writePropertyName("numberOfPlayer");
                jsonWriter.writeInt32(*m_Request.getNumberOfPlayer());
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
        GetBallotTask(
            GetBallotRequest request,
            Gs2WebSocketSessionTask<GetBallotResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetBallotResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetBallotTask() GS2_OVERRIDE = default;
    };

    class GetBallotByUserIdTask : public detail::Gs2WebSocketSessionTask<GetBallotByUserIdResult>
    {
    private:
        GetBallotByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "vote";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getBallotByUserId";
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
            if (m_Request.getRatingName())
            {
                jsonWriter.writePropertyName("ratingName");
                jsonWriter.writeCharArray(*m_Request.getRatingName());
            }
            if (m_Request.getGatheringName())
            {
                jsonWriter.writePropertyName("gatheringName");
                jsonWriter.writeCharArray(*m_Request.getGatheringName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getNumberOfPlayer())
            {
                jsonWriter.writePropertyName("numberOfPlayer");
                jsonWriter.writeInt32(*m_Request.getNumberOfPlayer());
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
        GetBallotByUserIdTask(
            GetBallotByUserIdRequest request,
            Gs2WebSocketSessionTask<GetBallotByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetBallotByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetBallotByUserIdTask() GS2_OVERRIDE = default;
    };

    class VoteTask : public detail::Gs2WebSocketSessionTask<VoteResult>
    {
    private:
        VoteRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "vote";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "vote";
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
            if (m_Request.getBallotBody())
            {
                jsonWriter.writePropertyName("ballotBody");
                jsonWriter.writeCharArray(*m_Request.getBallotBody());
            }
            if (m_Request.getBallotSignature())
            {
                jsonWriter.writePropertyName("ballotSignature");
                jsonWriter.writeCharArray(*m_Request.getBallotSignature());
            }
            if (m_Request.getGameResults())
            {
                jsonWriter.writePropertyName("gameResults");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getGameResults();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(jsonWriter, list[i]);
                }
                jsonWriter.writeArrayEnd();
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
        }

    public:
        VoteTask(
            VoteRequest request,
            Gs2WebSocketSessionTask<VoteResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<VoteResult>(callback),
            m_Request(std::move(request))
        {}

        ~VoteTask() GS2_OVERRIDE = default;
    };

    class VoteMultipleTask : public detail::Gs2WebSocketSessionTask<VoteMultipleResult>
    {
    private:
        VoteMultipleRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "vote";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "voteMultiple";
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
            if (m_Request.getSignedBallots())
            {
                jsonWriter.writePropertyName("signedBallots");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getSignedBallots();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(jsonWriter, list[i]);
                }
                jsonWriter.writeArrayEnd();
            }
            if (m_Request.getGameResults())
            {
                jsonWriter.writePropertyName("gameResults");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getGameResults();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(jsonWriter, list[i]);
                }
                jsonWriter.writeArrayEnd();
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
        }

    public:
        VoteMultipleTask(
            VoteMultipleRequest request,
            Gs2WebSocketSessionTask<VoteMultipleResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<VoteMultipleResult>(callback),
            m_Request(std::move(request))
        {}

        ~VoteMultipleTask() GS2_OVERRIDE = default;
    };

    class CommitVoteTask : public detail::Gs2WebSocketSessionTask<void>
    {
    private:
        CommitVoteRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "vote";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "commitVote";
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
            if (m_Request.getRatingName())
            {
                jsonWriter.writePropertyName("ratingName");
                jsonWriter.writeCharArray(*m_Request.getRatingName());
            }
            if (m_Request.getGatheringName())
            {
                jsonWriter.writePropertyName("gatheringName");
                jsonWriter.writeCharArray(*m_Request.getGatheringName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        CommitVoteTask(
            CommitVoteRequest request,
            Gs2WebSocketSessionTask<void>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<void>(callback),
            m_Request(std::move(request))
        {}

        ~CommitVoteTask() GS2_OVERRIDE = default;
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
        if (obj.getEnableRating())
        {
            jsonWriter.writePropertyName("enableRating");
            jsonWriter.writeBool(*obj.getEnableRating());
        }
        if (obj.getCreateGatheringTriggerType())
        {
            jsonWriter.writePropertyName("createGatheringTriggerType");
            jsonWriter.writeCharArray(*obj.getCreateGatheringTriggerType());
        }
        if (obj.getCreateGatheringTriggerRealtimeNamespaceId())
        {
            jsonWriter.writePropertyName("createGatheringTriggerRealtimeNamespaceId");
            jsonWriter.writeCharArray(*obj.getCreateGatheringTriggerRealtimeNamespaceId());
        }
        if (obj.getCreateGatheringTriggerScriptId())
        {
            jsonWriter.writePropertyName("createGatheringTriggerScriptId");
            jsonWriter.writeCharArray(*obj.getCreateGatheringTriggerScriptId());
        }
        if (obj.getCompleteMatchmakingTriggerType())
        {
            jsonWriter.writePropertyName("completeMatchmakingTriggerType");
            jsonWriter.writeCharArray(*obj.getCompleteMatchmakingTriggerType());
        }
        if (obj.getCompleteMatchmakingTriggerRealtimeNamespaceId())
        {
            jsonWriter.writePropertyName("completeMatchmakingTriggerRealtimeNamespaceId");
            jsonWriter.writeCharArray(*obj.getCompleteMatchmakingTriggerRealtimeNamespaceId());
        }
        if (obj.getCompleteMatchmakingTriggerScriptId())
        {
            jsonWriter.writePropertyName("completeMatchmakingTriggerScriptId");
            jsonWriter.writeCharArray(*obj.getCompleteMatchmakingTriggerScriptId());
        }
        if (obj.getJoinNotification())
        {
            jsonWriter.writePropertyName("joinNotification");
            write(jsonWriter, *obj.getJoinNotification());
        }
        if (obj.getLeaveNotification())
        {
            jsonWriter.writePropertyName("leaveNotification");
            write(jsonWriter, *obj.getLeaveNotification());
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

    static void write(detail::json::JsonWriter& jsonWriter, const Gathering& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getGatheringId())
        {
            jsonWriter.writePropertyName("gatheringId");
            jsonWriter.writeCharArray(*obj.getGatheringId());
        }
        if (obj.getName())
        {
            jsonWriter.writePropertyName("name");
            jsonWriter.writeCharArray(*obj.getName());
        }
        if (obj.getAttributeRanges())
        {
            jsonWriter.writePropertyName("attributeRanges");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getAttributeRanges();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (obj.getCapacityOfRoles())
        {
            jsonWriter.writePropertyName("capacityOfRoles");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getCapacityOfRoles();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (obj.getAllowUserIds())
        {
            jsonWriter.writePropertyName("allowUserIds");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getAllowUserIds();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                jsonWriter.writeCharArray(list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (obj.getMetadata())
        {
            jsonWriter.writePropertyName("metadata");
            jsonWriter.writeCharArray(*obj.getMetadata());
        }
        if (obj.getExpiresAt())
        {
            jsonWriter.writePropertyName("expiresAt");
            jsonWriter.writeInt64(*obj.getExpiresAt());
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

    static void write(detail::json::JsonWriter& jsonWriter, const RatingModelMaster& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getRatingModelId())
        {
            jsonWriter.writePropertyName("ratingModelId");
            jsonWriter.writeCharArray(*obj.getRatingModelId());
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
        if (obj.getVolatility())
        {
            jsonWriter.writePropertyName("volatility");
            jsonWriter.writeInt32(*obj.getVolatility());
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

    static void write(detail::json::JsonWriter& jsonWriter, const RatingModel& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getRatingModelId())
        {
            jsonWriter.writePropertyName("ratingModelId");
            jsonWriter.writeCharArray(*obj.getRatingModelId());
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
        if (obj.getVolatility())
        {
            jsonWriter.writePropertyName("volatility");
            jsonWriter.writeInt32(*obj.getVolatility());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const CurrentRatingModelMaster& obj)
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

    static void write(detail::json::JsonWriter& jsonWriter, const AttributeRange& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getName())
        {
            jsonWriter.writePropertyName("name");
            jsonWriter.writeCharArray(*obj.getName());
        }
        if (obj.getMin())
        {
            jsonWriter.writePropertyName("min");
            jsonWriter.writeInt32(*obj.getMin());
        }
        if (obj.getMax())
        {
            jsonWriter.writePropertyName("max");
            jsonWriter.writeInt32(*obj.getMax());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const CapacityOfRole& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getRoleName())
        {
            jsonWriter.writePropertyName("roleName");
            jsonWriter.writeCharArray(*obj.getRoleName());
        }
        if (obj.getRoleAliases())
        {
            jsonWriter.writePropertyName("roleAliases");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getRoleAliases();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                jsonWriter.writeCharArray(list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (obj.getCapacity())
        {
            jsonWriter.writePropertyName("capacity");
            jsonWriter.writeInt32(*obj.getCapacity());
        }
        if (obj.getParticipants())
        {
            jsonWriter.writePropertyName("participants");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getParticipants();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const Attribute& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getName())
        {
            jsonWriter.writePropertyName("name");
            jsonWriter.writeCharArray(*obj.getName());
        }
        if (obj.getValue())
        {
            jsonWriter.writePropertyName("value");
            jsonWriter.writeInt32(*obj.getValue());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const Player& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getAttributes())
        {
            jsonWriter.writePropertyName("attributes");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getAttributes();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (obj.getRoleName())
        {
            jsonWriter.writePropertyName("roleName");
            jsonWriter.writeCharArray(*obj.getRoleName());
        }
        if (obj.getDenyUserIds())
        {
            jsonWriter.writePropertyName("denyUserIds");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getDenyUserIds();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                jsonWriter.writeCharArray(list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const Rating& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getRatingId())
        {
            jsonWriter.writePropertyName("ratingId");
            jsonWriter.writeCharArray(*obj.getRatingId());
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
        if (obj.getRateValue())
        {
            jsonWriter.writePropertyName("rateValue");
            jsonWriter.writeFloat(*obj.getRateValue());
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

    static void write(detail::json::JsonWriter& jsonWriter, const GameResult& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getRank())
        {
            jsonWriter.writePropertyName("rank");
            jsonWriter.writeInt32(*obj.getRank());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const Ballot& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getRatingName())
        {
            jsonWriter.writePropertyName("ratingName");
            jsonWriter.writeCharArray(*obj.getRatingName());
        }
        if (obj.getGatheringName())
        {
            jsonWriter.writePropertyName("gatheringName");
            jsonWriter.writeCharArray(*obj.getGatheringName());
        }
        if (obj.getNumberOfPlayer())
        {
            jsonWriter.writePropertyName("numberOfPlayer");
            jsonWriter.writeInt32(*obj.getNumberOfPlayer());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const SignedBallot& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getBody())
        {
            jsonWriter.writePropertyName("body");
            jsonWriter.writeCharArray(*obj.getBody());
        }
        if (obj.getSignature())
        {
            jsonWriter.writePropertyName("signature");
            jsonWriter.writeCharArray(*obj.getSignature());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const WrittenBallot& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getBallot())
        {
            jsonWriter.writePropertyName("ballot");
            write(jsonWriter, *obj.getBallot());
        }
        if (obj.getGameResults())
        {
            jsonWriter.writePropertyName("gameResults");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getGameResults();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const Vote& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getVoteId())
        {
            jsonWriter.writePropertyName("voteId");
            jsonWriter.writeCharArray(*obj.getVoteId());
        }
        if (obj.getRatingName())
        {
            jsonWriter.writePropertyName("ratingName");
            jsonWriter.writeCharArray(*obj.getRatingName());
        }
        if (obj.getGatheringName())
        {
            jsonWriter.writePropertyName("gatheringName");
            jsonWriter.writeCharArray(*obj.getGatheringName());
        }
        if (obj.getWrittenBallots())
        {
            jsonWriter.writePropertyName("writtenBallots");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getWrittenBallots();
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
    void createGathering(CreateGatheringRequest request, std::function<void(AsyncCreateGatheringResult)> callback)
    {
        CreateGatheringTask& task = *new CreateGatheringTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
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
    void createGatheringByUserId(CreateGatheringByUserIdRequest request, std::function<void(AsyncCreateGatheringByUserIdResult)> callback)
    {
        CreateGatheringByUserIdTask& task = *new CreateGatheringByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ギャザリングを更新する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateGathering(UpdateGatheringRequest request, std::function<void(AsyncUpdateGatheringResult)> callback)
    {
        UpdateGatheringTask& task = *new UpdateGatheringTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ギャザリングを更新する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateGatheringByUserId(UpdateGatheringByUserIdRequest request, std::function<void(AsyncUpdateGatheringByUserIdResult)> callback)
    {
        UpdateGatheringByUserIdTask& task = *new UpdateGatheringByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
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
    void doMatchmakingByPlayer(DoMatchmakingByPlayerRequest request, std::function<void(AsyncDoMatchmakingByPlayerResult)> callback)
    {
        DoMatchmakingByPlayerTask& task = *new DoMatchmakingByPlayerTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
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
    void doMatchmaking(DoMatchmakingRequest request, std::function<void(AsyncDoMatchmakingResult)> callback)
    {
        DoMatchmakingTask& task = *new DoMatchmakingTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ギャザリングを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getGathering(GetGatheringRequest request, std::function<void(AsyncGetGatheringResult)> callback)
    {
        GetGatheringTask& task = *new GetGatheringTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * マッチメイキングをキャンセルする<br>
	 *   <br>
	 *   ギャザリングから離脱する前にマッチメイキングが完了した場合は、NotFoundException(404エラー) が発生し失敗します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void cancelMatchmaking(CancelMatchmakingRequest request, std::function<void(AsyncCancelMatchmakingResult)> callback)
    {
        CancelMatchmakingTask& task = *new CancelMatchmakingTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザIDを指定してマッチメイキングをキャンセルする<br>
	 *   <br>
	 *   ギャザリングから離脱する前にマッチメイキングが完了した場合は、NotFoundException(404エラー) が発生し失敗します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void cancelMatchmakingByUserId(CancelMatchmakingByUserIdRequest request, std::function<void(AsyncCancelMatchmakingByUserIdResult)> callback)
    {
        CancelMatchmakingByUserIdTask& task = *new CancelMatchmakingByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ギャザリングを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteGathering(DeleteGatheringRequest request, std::function<void(AsyncDeleteGatheringResult)> callback)
    {
        DeleteGatheringTask& task = *new DeleteGatheringTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * レーティングモデルマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createRatingModelMaster(CreateRatingModelMasterRequest request, std::function<void(AsyncCreateRatingModelMasterResult)> callback)
    {
        CreateRatingModelMasterTask& task = *new CreateRatingModelMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * レーティングモデルマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getRatingModelMaster(GetRatingModelMasterRequest request, std::function<void(AsyncGetRatingModelMasterResult)> callback)
    {
        GetRatingModelMasterTask& task = *new GetRatingModelMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * レーティングモデルマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateRatingModelMaster(UpdateRatingModelMasterRequest request, std::function<void(AsyncUpdateRatingModelMasterResult)> callback)
    {
        UpdateRatingModelMasterTask& task = *new UpdateRatingModelMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * レーティングモデルマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteRatingModelMaster(DeleteRatingModelMasterRequest request, std::function<void(AsyncDeleteRatingModelMasterResult)> callback)
    {
        DeleteRatingModelMasterTask& task = *new DeleteRatingModelMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * レーティングモデルを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getRatingModel(GetRatingModelRequest request, std::function<void(AsyncGetRatingModelResult)> callback)
    {
        GetRatingModelTask& task = *new GetRatingModelTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * レーティングを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getRating(GetRatingRequest request, std::function<void(AsyncGetRatingResult)> callback)
    {
        GetRatingTask& task = *new GetRatingTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * レーティングを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getRatingByUserId(GetRatingByUserIdRequest request, std::function<void(AsyncGetRatingByUserIdResult)> callback)
    {
        GetRatingByUserIdTask& task = *new GetRatingByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * レーティング値の再計算を実行<br>
	 *   <br>
	 *   レーティングの計算処理には Glicko-2 rating system をベースとした計算アルゴリズムを採用しています。<br>
	 *   レーティング値の初期値は1500で、レーティングの値が離れた相手に勝利するほど上昇幅は大きく、同じく負けた側は減少幅は大きくなります。<br>
	 *   <br>
	 *   レーティングの計算には参加したユーザIDのリストが必要となります。<br>
	 *   そのため、クライアントから直接このAPIを呼び出すのは適切ではありません。ゲームの勝敗を判断できるゲームサーバから呼び出すようにしてください。<br>
	 *   P2P 対戦など、クライアント主導で対戦を実現している場合は、投票機能を利用して勝敗を決定するようにしてください。<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void putResult(PutResultRequest request, std::function<void(AsyncPutResultResult)> callback)
    {
        PutResultTask& task = *new PutResultTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * レーティングを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteRating(DeleteRatingRequest request, std::function<void(AsyncDeleteRatingResult)> callback)
    {
        DeleteRatingTask& task = *new DeleteRatingTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 投票用紙を取得します。<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getBallot(GetBallotRequest request, std::function<void(AsyncGetBallotResult)> callback)
    {
        GetBallotTask& task = *new GetBallotTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 投票用紙を取得します。<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getBallotByUserId(GetBallotByUserIdRequest request, std::function<void(AsyncGetBallotByUserIdResult)> callback)
    {
        GetBallotByUserIdTask& task = *new GetBallotByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 対戦結果を投票します。<br>
	 *   <br>
	 *   投票は最初の投票が行われてから5分以内に行う必要があります。<br>
	 *   つまり、結果は即座に反映されず、投票開始からおよそ5分後または全てのプレイヤーが投票を行った際に結果が反映されます。<br>
	 *   5分以内に全ての投票用紙を回収できなかった場合はその時点の投票内容で多数決をとって結果を決定します。<br>
	 *   各結果の投票数が同一だった場合は結果は捨てられます（スクリプトで挙動を変更可）。<br>
	 *   <br>
	 *   結果を即座に反映したい場合は、勝利した側の代表プレイヤーが投票用紙を各プレイヤーから集めて voteMultiple を呼び出すことで結果を即座に反映できます。<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void vote(VoteRequest request, std::function<void(AsyncVoteResult)> callback)
    {
        VoteTask& task = *new VoteTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 対戦結果をまとめて投票します。<br>
	 *   <br>
	 *   ゲームに勝利した側が他プレイヤーの投票用紙を集めてまとめて投票するのに使用します。<br>
	 *   『勝利した側』としているのは、敗北した側が自分たちが勝ったことにして報告することにインセンティブはありますが、その逆はないためです。<br>
	 *   負けた側が投票用紙を渡してこない可能性がありますが、その場合も過半数の投票用紙があれば結果を通すことができます。<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void voteMultiple(VoteMultipleRequest request, std::function<void(AsyncVoteMultipleResult)> callback)
    {
        VoteMultipleTask& task = *new VoteMultipleTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 投票状況を強制確定<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void commitVote(CommitVoteRequest request, std::function<void(AsyncCommitVoteResult)> callback)
    {
        CommitVoteTask& task = *new CommitVoteTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_MATCHMAKING_GS2MATCHMAKINGWEBSOCKETCLIENT_HPP_