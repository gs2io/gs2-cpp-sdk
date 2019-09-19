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

private:
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

protected:
    Gs2RestSession& getGs2RestSession()
    {
        return static_cast<Gs2RestSession&>(getGs2Session());
    }
};

} }

#endif //GS2_MATCHMAKING_GS2MATCHMAKINGRESTCLIENT_HPP_