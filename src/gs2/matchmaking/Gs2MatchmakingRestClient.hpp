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

#ifndef GS2_MATCHMAKING_GS2MATCHMAKINGRESTCLIENT_HPP_
#define GS2_MATCHMAKING_GS2MATCHMAKINGRESTCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2RestSessionTask.hpp>
#include <gs2/core/network/Gs2RestSession.hpp>
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
class Gs2MatchmakingRestClient : public AbstractGs2ClientBase
{
private:

    class DescribeNamespacesTask : public detail::Gs2RestSessionTask<DescribeNamespacesResult>
    {
    private:
        DescribeNamespacesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/";

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getPageToken())
            {
                url += joint;
                url += "pageToken=";
                url += detail::StringVariable(*m_Request.getPageToken(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getLimit())
            {
                url += joint;
                url += "limit=";
                url += detail::StringVariable(*m_Request.getLimit()).c_str();
                joint[0] = '&';
            }

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        DescribeNamespacesTask(
            DescribeNamespacesRequest request,
            Gs2RestSessionTask<DescribeNamespacesResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeNamespacesResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeNamespacesTask() GS2_OVERRIDE = default;
    };

    class CreateNamespaceTask : public detail::Gs2RestSessionTask<CreateNamespaceResult>
    {
    private:
        CreateNamespaceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/";
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
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
            jsonWriter.writeObjectEnd();
            {
                gs2HttpTask.setBody(jsonWriter.toString());
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Post;
        }

    public:
        CreateNamespaceTask(
            CreateNamespaceRequest request,
            Gs2RestSessionTask<CreateNamespaceResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CreateNamespaceResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateNamespaceTask() GS2_OVERRIDE = default;
    };

    class GetNamespaceStatusTask : public detail::Gs2RestSessionTask<GetNamespaceStatusResult>
    {
    private:
        GetNamespaceStatusRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/status";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        GetNamespaceStatusTask(
            GetNamespaceStatusRequest request,
            Gs2RestSessionTask<GetNamespaceStatusResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetNamespaceStatusResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetNamespaceStatusTask() GS2_OVERRIDE = default;
    };

    class GetNamespaceTask : public detail::Gs2RestSessionTask<GetNamespaceResult>
    {
    private:
        GetNamespaceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        GetNamespaceTask(
            GetNamespaceRequest request,
            Gs2RestSessionTask<GetNamespaceResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetNamespaceResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetNamespaceTask() GS2_OVERRIDE = default;
    };

    class UpdateNamespaceTask : public detail::Gs2RestSessionTask<UpdateNamespaceResult>
    {
    private:
        UpdateNamespaceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
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
            jsonWriter.writeObjectEnd();
            {
                gs2HttpTask.setBody(jsonWriter.toString());
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Put;
        }

    public:
        UpdateNamespaceTask(
            UpdateNamespaceRequest request,
            Gs2RestSessionTask<UpdateNamespaceResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateNamespaceResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateNamespaceTask() GS2_OVERRIDE = default;
    };

    class DeleteNamespaceTask : public detail::Gs2RestSessionTask<DeleteNamespaceResult>
    {
    private:
        DeleteNamespaceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            {
                gs2HttpTask.setBody("[]");
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Delete;
        }

    public:
        DeleteNamespaceTask(
            DeleteNamespaceRequest request,
            Gs2RestSessionTask<DeleteNamespaceResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteNamespaceResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteNamespaceTask() GS2_OVERRIDE = default;
    };

    class DescribeGatheringsTask : public detail::Gs2RestSessionTask<DescribeGatheringsResult>
    {
    private:
        DescribeGatheringsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/gathering";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getPageToken())
            {
                url += joint;
                url += "pageToken=";
                url += detail::StringVariable(*m_Request.getPageToken(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getLimit())
            {
                url += joint;
                url += "limit=";
                url += detail::StringVariable(*m_Request.getLimit()).c_str();
                joint[0] = '&';
            }

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        DescribeGatheringsTask(
            DescribeGatheringsRequest request,
            Gs2RestSessionTask<DescribeGatheringsResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeGatheringsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeGatheringsTask() GS2_OVERRIDE = default;
    };

    class CreateGatheringTask : public detail::Gs2RestSessionTask<CreateGatheringResult>
    {
    private:
        CreateGatheringRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/gathering";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
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
            jsonWriter.writeObjectEnd();
            {
                gs2HttpTask.setBody(jsonWriter.toString());
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-ACCESS-TOKEN", *m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Post;
        }

    public:
        CreateGatheringTask(
            CreateGatheringRequest request,
            Gs2RestSessionTask<CreateGatheringResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CreateGatheringResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateGatheringTask() GS2_OVERRIDE = default;
    };

    class CreateGatheringByUserIdTask : public detail::Gs2RestSessionTask<CreateGatheringByUserIdResult>
    {
    private:
        CreateGatheringByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/gathering/user/{userId}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
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
            jsonWriter.writeObjectEnd();
            {
                gs2HttpTask.setBody(jsonWriter.toString());
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Post;
        }

    public:
        CreateGatheringByUserIdTask(
            CreateGatheringByUserIdRequest request,
            Gs2RestSessionTask<CreateGatheringByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CreateGatheringByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateGatheringByUserIdTask() GS2_OVERRIDE = default;
    };

    class UpdateGatheringTask : public detail::Gs2RestSessionTask<UpdateGatheringResult>
    {
    private:
        UpdateGatheringRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/gathering/{gatheringName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getGatheringName();
                url.replace("{gatheringName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
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
            jsonWriter.writeObjectEnd();
            {
                gs2HttpTask.setBody(jsonWriter.toString());
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-ACCESS-TOKEN", *m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Post;
        }

    public:
        UpdateGatheringTask(
            UpdateGatheringRequest request,
            Gs2RestSessionTask<UpdateGatheringResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateGatheringResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateGatheringTask() GS2_OVERRIDE = default;
    };

    class UpdateGatheringByUserIdTask : public detail::Gs2RestSessionTask<UpdateGatheringByUserIdResult>
    {
    private:
        UpdateGatheringByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/gathering/{gatheringName}/user/{userId}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getGatheringName();
                url.replace("{gatheringName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
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
            jsonWriter.writeObjectEnd();
            {
                gs2HttpTask.setBody(jsonWriter.toString());
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Post;
        }

    public:
        UpdateGatheringByUserIdTask(
            UpdateGatheringByUserIdRequest request,
            Gs2RestSessionTask<UpdateGatheringByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateGatheringByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateGatheringByUserIdTask() GS2_OVERRIDE = default;
    };

    class DoMatchmakingByPlayerTask : public detail::Gs2RestSessionTask<DoMatchmakingByPlayerResult>
    {
    private:
        DoMatchmakingByPlayerRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/gathering/player/do";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
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
            jsonWriter.writeObjectEnd();
            {
                gs2HttpTask.setBody(jsonWriter.toString());
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Post;
        }

    public:
        DoMatchmakingByPlayerTask(
            DoMatchmakingByPlayerRequest request,
            Gs2RestSessionTask<DoMatchmakingByPlayerResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DoMatchmakingByPlayerResult>(callback),
            m_Request(std::move(request))
        {}

        ~DoMatchmakingByPlayerTask() GS2_OVERRIDE = default;
    };

    class DoMatchmakingTask : public detail::Gs2RestSessionTask<DoMatchmakingResult>
    {
    private:
        DoMatchmakingRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/gathering/do";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
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
            jsonWriter.writeObjectEnd();
            {
                gs2HttpTask.setBody(jsonWriter.toString());
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-ACCESS-TOKEN", *m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Post;
        }

    public:
        DoMatchmakingTask(
            DoMatchmakingRequest request,
            Gs2RestSessionTask<DoMatchmakingResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DoMatchmakingResult>(callback),
            m_Request(std::move(request))
        {}

        ~DoMatchmakingTask() GS2_OVERRIDE = default;
    };

    class GetGatheringTask : public detail::Gs2RestSessionTask<GetGatheringResult>
    {
    private:
        GetGatheringRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/gathering/{gatheringName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getGatheringName();
                url.replace("{gatheringName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        GetGatheringTask(
            GetGatheringRequest request,
            Gs2RestSessionTask<GetGatheringResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetGatheringResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetGatheringTask() GS2_OVERRIDE = default;
    };

    class CancelMatchmakingTask : public detail::Gs2RestSessionTask<CancelMatchmakingResult>
    {
    private:
        CancelMatchmakingRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/gathering/{gatheringName}/user/me";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getGatheringName();
                url.replace("{gatheringName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            {
                gs2HttpTask.setBody("[]");
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-ACCESS-TOKEN", *m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Delete;
        }

    public:
        CancelMatchmakingTask(
            CancelMatchmakingRequest request,
            Gs2RestSessionTask<CancelMatchmakingResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CancelMatchmakingResult>(callback),
            m_Request(std::move(request))
        {}

        ~CancelMatchmakingTask() GS2_OVERRIDE = default;
    };

    class CancelMatchmakingByUserIdTask : public detail::Gs2RestSessionTask<CancelMatchmakingByUserIdResult>
    {
    private:
        CancelMatchmakingByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/gathering/{gatheringName}/user/{userId}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getGatheringName();
                url.replace("{gatheringName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            {
                gs2HttpTask.setBody("[]");
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Delete;
        }

    public:
        CancelMatchmakingByUserIdTask(
            CancelMatchmakingByUserIdRequest request,
            Gs2RestSessionTask<CancelMatchmakingByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CancelMatchmakingByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~CancelMatchmakingByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteGatheringTask : public detail::Gs2RestSessionTask<DeleteGatheringResult>
    {
    private:
        DeleteGatheringRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/gathering/{gatheringName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getGatheringName();
                url.replace("{gatheringName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            {
                gs2HttpTask.setBody("[]");
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Delete;
        }

    public:
        DeleteGatheringTask(
            DeleteGatheringRequest request,
            Gs2RestSessionTask<DeleteGatheringResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteGatheringResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteGatheringTask() GS2_OVERRIDE = default;
    };

    class DescribeRatingModelMastersTask : public detail::Gs2RestSessionTask<DescribeRatingModelMastersResult>
    {
    private:
        DescribeRatingModelMastersRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/rating";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getPageToken())
            {
                url += joint;
                url += "pageToken=";
                url += detail::StringVariable(*m_Request.getPageToken(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getLimit())
            {
                url += joint;
                url += "limit=";
                url += detail::StringVariable(*m_Request.getLimit()).c_str();
                joint[0] = '&';
            }

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        DescribeRatingModelMastersTask(
            DescribeRatingModelMastersRequest request,
            Gs2RestSessionTask<DescribeRatingModelMastersResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeRatingModelMastersResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeRatingModelMastersTask() GS2_OVERRIDE = default;
    };

    class CreateRatingModelMasterTask : public detail::Gs2RestSessionTask<CreateRatingModelMasterResult>
    {
    private:
        CreateRatingModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/rating";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
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
            jsonWriter.writeObjectEnd();
            {
                gs2HttpTask.setBody(jsonWriter.toString());
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Post;
        }

    public:
        CreateRatingModelMasterTask(
            CreateRatingModelMasterRequest request,
            Gs2RestSessionTask<CreateRatingModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CreateRatingModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateRatingModelMasterTask() GS2_OVERRIDE = default;
    };

    class GetRatingModelMasterTask : public detail::Gs2RestSessionTask<GetRatingModelMasterResult>
    {
    private:
        GetRatingModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/rating/{ratingName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getRatingName();
                url.replace("{ratingName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        GetRatingModelMasterTask(
            GetRatingModelMasterRequest request,
            Gs2RestSessionTask<GetRatingModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetRatingModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetRatingModelMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateRatingModelMasterTask : public detail::Gs2RestSessionTask<UpdateRatingModelMasterResult>
    {
    private:
        UpdateRatingModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/rating/{ratingName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getRatingName();
                url.replace("{ratingName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
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
            jsonWriter.writeObjectEnd();
            {
                gs2HttpTask.setBody(jsonWriter.toString());
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Put;
        }

    public:
        UpdateRatingModelMasterTask(
            UpdateRatingModelMasterRequest request,
            Gs2RestSessionTask<UpdateRatingModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateRatingModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateRatingModelMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteRatingModelMasterTask : public detail::Gs2RestSessionTask<DeleteRatingModelMasterResult>
    {
    private:
        DeleteRatingModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/rating/{ratingName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getRatingName();
                url.replace("{ratingName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            {
                gs2HttpTask.setBody("[]");
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Delete;
        }

    public:
        DeleteRatingModelMasterTask(
            DeleteRatingModelMasterRequest request,
            Gs2RestSessionTask<DeleteRatingModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteRatingModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteRatingModelMasterTask() GS2_OVERRIDE = default;
    };

    class DescribeRatingModelsTask : public detail::Gs2RestSessionTask<DescribeRatingModelsResult>
    {
    private:
        DescribeRatingModelsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/rating";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        DescribeRatingModelsTask(
            DescribeRatingModelsRequest request,
            Gs2RestSessionTask<DescribeRatingModelsResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeRatingModelsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeRatingModelsTask() GS2_OVERRIDE = default;
    };

    class GetRatingModelTask : public detail::Gs2RestSessionTask<GetRatingModelResult>
    {
    private:
        GetRatingModelRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/rating/{ratingName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getRatingName();
                url.replace("{ratingName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        GetRatingModelTask(
            GetRatingModelRequest request,
            Gs2RestSessionTask<GetRatingModelResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetRatingModelResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetRatingModelTask() GS2_OVERRIDE = default;
    };

    class ExportMasterTask : public detail::Gs2RestSessionTask<ExportMasterResult>
    {
    private:
        ExportMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/export";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        ExportMasterTask(
            ExportMasterRequest request,
            Gs2RestSessionTask<ExportMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<ExportMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~ExportMasterTask() GS2_OVERRIDE = default;
    };

    class GetCurrentRatingModelMasterTask : public detail::Gs2RestSessionTask<GetCurrentRatingModelMasterResult>
    {
    private:
        GetCurrentRatingModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        GetCurrentRatingModelMasterTask(
            GetCurrentRatingModelMasterRequest request,
            Gs2RestSessionTask<GetCurrentRatingModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetCurrentRatingModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetCurrentRatingModelMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentRatingModelMasterTask : public detail::Gs2RestSessionTask<UpdateCurrentRatingModelMasterResult>
    {
    private:
        UpdateCurrentRatingModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getSettings())
            {
                jsonWriter.writePropertyName("settings");
                jsonWriter.writeCharArray(*m_Request.getSettings());
            }
            jsonWriter.writeObjectEnd();
            {
                gs2HttpTask.setBody(jsonWriter.toString());
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Put;
        }

    public:
        UpdateCurrentRatingModelMasterTask(
            UpdateCurrentRatingModelMasterRequest request,
            Gs2RestSessionTask<UpdateCurrentRatingModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateCurrentRatingModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateCurrentRatingModelMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentRatingModelMasterFromGitHubTask : public detail::Gs2RestSessionTask<UpdateCurrentRatingModelMasterFromGitHubResult>
    {
    private:
        UpdateCurrentRatingModelMasterFromGitHubRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/from_git_hub";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getCheckoutSetting())
            {
                jsonWriter.writePropertyName("checkoutSetting");
                write(jsonWriter, *m_Request.getCheckoutSetting());
            }
            jsonWriter.writeObjectEnd();
            {
                gs2HttpTask.setBody(jsonWriter.toString());
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Put;
        }

    public:
        UpdateCurrentRatingModelMasterFromGitHubTask(
            UpdateCurrentRatingModelMasterFromGitHubRequest request,
            Gs2RestSessionTask<UpdateCurrentRatingModelMasterFromGitHubResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateCurrentRatingModelMasterFromGitHubResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateCurrentRatingModelMasterFromGitHubTask() GS2_OVERRIDE = default;
    };

    class DescribeRatingsTask : public detail::Gs2RestSessionTask<DescribeRatingsResult>
    {
    private:
        DescribeRatingsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/rating";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getPageToken())
            {
                url += joint;
                url += "pageToken=";
                url += detail::StringVariable(*m_Request.getPageToken(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getLimit())
            {
                url += joint;
                url += "limit=";
                url += detail::StringVariable(*m_Request.getLimit()).c_str();
                joint[0] = '&';
            }

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-ACCESS-TOKEN", *m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        DescribeRatingsTask(
            DescribeRatingsRequest request,
            Gs2RestSessionTask<DescribeRatingsResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeRatingsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeRatingsTask() GS2_OVERRIDE = default;
    };

    class DescribeRatingsByUserIdTask : public detail::Gs2RestSessionTask<DescribeRatingsByUserIdResult>
    {
    private:
        DescribeRatingsByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/rating";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getPageToken())
            {
                url += joint;
                url += "pageToken=";
                url += detail::StringVariable(*m_Request.getPageToken(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getLimit())
            {
                url += joint;
                url += "limit=";
                url += detail::StringVariable(*m_Request.getLimit()).c_str();
                joint[0] = '&';
            }

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        DescribeRatingsByUserIdTask(
            DescribeRatingsByUserIdRequest request,
            Gs2RestSessionTask<DescribeRatingsByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeRatingsByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeRatingsByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetRatingTask : public detail::Gs2RestSessionTask<GetRatingResult>
    {
    private:
        GetRatingRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/rating/{ratingName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getRatingName();
                url.replace("{ratingName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-ACCESS-TOKEN", *m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        GetRatingTask(
            GetRatingRequest request,
            Gs2RestSessionTask<GetRatingResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetRatingResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetRatingTask() GS2_OVERRIDE = default;
    };

    class GetRatingByUserIdTask : public detail::Gs2RestSessionTask<GetRatingByUserIdResult>
    {
    private:
        GetRatingByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/rating/{ratingName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getRatingName();
                url.replace("{ratingName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        GetRatingByUserIdTask(
            GetRatingByUserIdRequest request,
            Gs2RestSessionTask<GetRatingByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetRatingByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetRatingByUserIdTask() GS2_OVERRIDE = default;
    };

    class PutResultTask : public detail::Gs2RestSessionTask<PutResultResult>
    {
    private:
        PutResultRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/rating/{ratingName}/vote";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getRatingName();
                url.replace("{ratingName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
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
            jsonWriter.writeObjectEnd();
            {
                gs2HttpTask.setBody(jsonWriter.toString());
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Post;
        }

    public:
        PutResultTask(
            PutResultRequest request,
            Gs2RestSessionTask<PutResultResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<PutResultResult>(callback),
            m_Request(std::move(request))
        {}

        ~PutResultTask() GS2_OVERRIDE = default;
    };

    class DeleteRatingTask : public detail::Gs2RestSessionTask<DeleteRatingResult>
    {
    private:
        DeleteRatingRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/rating/{ratingName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getRatingName();
                url.replace("{ratingName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            {
                gs2HttpTask.setBody("[]");
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Delete;
        }

    public:
        DeleteRatingTask(
            DeleteRatingRequest request,
            Gs2RestSessionTask<DeleteRatingResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteRatingResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteRatingTask() GS2_OVERRIDE = default;
    };

    class GetBallotTask : public detail::Gs2RestSessionTask<GetBallotResult>
    {
    private:
        GetBallotRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/vote/{ratingName}/{gatheringName}/ballot";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getRatingName();
                url.replace("{ratingName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getGatheringName();
                url.replace("{gatheringName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getGatheringId())
            {
                jsonWriter.writePropertyName("gatheringId");
                jsonWriter.writeCharArray(*m_Request.getGatheringId());
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
            jsonWriter.writeObjectEnd();
            {
                gs2HttpTask.setBody(jsonWriter.toString());
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-ACCESS-TOKEN", *m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Post;
        }

    public:
        GetBallotTask(
            GetBallotRequest request,
            Gs2RestSessionTask<GetBallotResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetBallotResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetBallotTask() GS2_OVERRIDE = default;
    };

    class GetBallotByUserIdTask : public detail::Gs2RestSessionTask<GetBallotByUserIdResult>
    {
    private:
        GetBallotByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/vote/{ratingName}/{gatheringName}/ballot";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getRatingName();
                url.replace("{ratingName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getGatheringName();
                url.replace("{gatheringName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getGatheringId())
            {
                jsonWriter.writePropertyName("gatheringId");
                jsonWriter.writeCharArray(*m_Request.getGatheringId());
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
            jsonWriter.writeObjectEnd();
            {
                gs2HttpTask.setBody(jsonWriter.toString());
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Post;
        }

    public:
        GetBallotByUserIdTask(
            GetBallotByUserIdRequest request,
            Gs2RestSessionTask<GetBallotByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetBallotByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetBallotByUserIdTask() GS2_OVERRIDE = default;
    };

    class VoteTask : public detail::Gs2RestSessionTask<VoteResult>
    {
    private:
        VoteRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/action/vote";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
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
            jsonWriter.writeObjectEnd();
            {
                gs2HttpTask.setBody(jsonWriter.toString());
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Post;
        }

    public:
        VoteTask(
            VoteRequest request,
            Gs2RestSessionTask<VoteResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<VoteResult>(callback),
            m_Request(std::move(request))
        {}

        ~VoteTask() GS2_OVERRIDE = default;
    };

    class VoteMultipleTask : public detail::Gs2RestSessionTask<VoteMultipleResult>
    {
    private:
        VoteMultipleRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/action/vote/multiple";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
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
            jsonWriter.writeObjectEnd();
            {
                gs2HttpTask.setBody(jsonWriter.toString());
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Post;
        }

    public:
        VoteMultipleTask(
            VoteMultipleRequest request,
            Gs2RestSessionTask<VoteMultipleResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<VoteMultipleResult>(callback),
            m_Request(std::move(request))
        {}

        ~VoteMultipleTask() GS2_OVERRIDE = default;
    };

    class CommitVoteTask : public detail::Gs2RestSessionTask<void>
    {
    private:
        CommitVoteRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "matchmaking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/action/vote/commit";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            jsonWriter.writeObjectEnd();
            {
                gs2HttpTask.setBody(jsonWriter.toString());
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Post;
        }

    public:
        CommitVoteTask(
            CommitVoteRequest request,
            Gs2RestSessionTask<void>::CallbackType callback
        ) :
            Gs2RestSessionTask<void>(callback),
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
     * @param gs2RestSession REST API 用セッション
     */
    explicit Gs2MatchmakingRestClient(Gs2RestSession& gs2RestSession) :
        AbstractGs2ClientBase(gs2RestSession)
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
    }

	/**
	 * ギャザリングの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeGatherings(DescribeGatheringsRequest request, std::function<void(AsyncDescribeGatheringsResult)> callback)
    {
        DescribeGatheringsTask& task = *new DescribeGatheringsTask(std::move(request), callback);
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
    }

	/**
	 * レーティングモデルマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeRatingModelMasters(DescribeRatingModelMastersRequest request, std::function<void(AsyncDescribeRatingModelMastersResult)> callback)
    {
        DescribeRatingModelMastersTask& task = *new DescribeRatingModelMastersTask(std::move(request), callback);
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
    }

	/**
	 * レーティングモデルの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeRatingModels(DescribeRatingModelsRequest request, std::function<void(AsyncDescribeRatingModelsResult)> callback)
    {
        DescribeRatingModelsTask& task = *new DescribeRatingModelsTask(std::move(request), callback);
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
    }

	/**
	 * 現在有効なレーティングマスターのマスターデータをエクスポートします<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void exportMaster(ExportMasterRequest request, std::function<void(AsyncExportMasterResult)> callback)
    {
        ExportMasterTask& task = *new ExportMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 現在有効なレーティングマスターを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentRatingModelMaster(GetCurrentRatingModelMasterRequest request, std::function<void(AsyncGetCurrentRatingModelMasterResult)> callback)
    {
        GetCurrentRatingModelMasterTask& task = *new GetCurrentRatingModelMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 現在有効なレーティングマスターを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentRatingModelMaster(UpdateCurrentRatingModelMasterRequest request, std::function<void(AsyncUpdateCurrentRatingModelMasterResult)> callback)
    {
        UpdateCurrentRatingModelMasterTask& task = *new UpdateCurrentRatingModelMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 現在有効なレーティングマスターを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentRatingModelMasterFromGitHub(UpdateCurrentRatingModelMasterFromGitHubRequest request, std::function<void(AsyncUpdateCurrentRatingModelMasterFromGitHubResult)> callback)
    {
        UpdateCurrentRatingModelMasterFromGitHubTask& task = *new UpdateCurrentRatingModelMasterFromGitHubTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * レーティングの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeRatings(DescribeRatingsRequest request, std::function<void(AsyncDescribeRatingsResult)> callback)
    {
        DescribeRatingsTask& task = *new DescribeRatingsTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定してレーティングの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeRatingsByUserId(DescribeRatingsByUserIdRequest request, std::function<void(AsyncDescribeRatingsByUserIdResult)> callback)
    {
        DescribeRatingsByUserIdTask& task = *new DescribeRatingsByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
    }

protected:
    Gs2RestSession& getGs2RestSession()
    {
        return static_cast<Gs2RestSession&>(getGs2Session());
    }
};

} }

#endif //GS2_MATCHMAKING_GS2MATCHMAKINGRESTCLIENT_HPP_