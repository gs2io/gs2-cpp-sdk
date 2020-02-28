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

#ifndef GS2_MISSION_GS2MISSIONRESTCLIENT_HPP_
#define GS2_MISSION_GS2MISSIONRESTCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2RestSessionTask.hpp>
#include <gs2/core/network/Gs2RestSession.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include "model/model.hpp"
#include "request/DescribeCounterModelsRequest.hpp"
#include "request/GetCounterModelRequest.hpp"
#include "request/DescribeMissionGroupModelsRequest.hpp"
#include "request/GetMissionGroupModelRequest.hpp"
#include "request/DescribeNamespacesRequest.hpp"
#include "request/CreateNamespaceRequest.hpp"
#include "request/GetNamespaceStatusRequest.hpp"
#include "request/GetNamespaceRequest.hpp"
#include "request/UpdateNamespaceRequest.hpp"
#include "request/DeleteNamespaceRequest.hpp"
#include "request/DescribeMissionTaskModelMastersRequest.hpp"
#include "request/CreateMissionTaskModelMasterRequest.hpp"
#include "request/GetMissionTaskModelMasterRequest.hpp"
#include "request/UpdateMissionTaskModelMasterRequest.hpp"
#include "request/DeleteMissionTaskModelMasterRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentMissionMasterRequest.hpp"
#include "request/UpdateCurrentMissionMasterRequest.hpp"
#include "request/UpdateCurrentMissionMasterFromGitHubRequest.hpp"
#include "request/DescribeCounterModelMastersRequest.hpp"
#include "request/CreateCounterModelMasterRequest.hpp"
#include "request/GetCounterModelMasterRequest.hpp"
#include "request/UpdateCounterModelMasterRequest.hpp"
#include "request/DeleteCounterModelMasterRequest.hpp"
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
#include "request/DescribeCountersRequest.hpp"
#include "request/DescribeCountersByUserIdRequest.hpp"
#include "request/IncreaseCounterByUserIdRequest.hpp"
#include "request/GetCounterRequest.hpp"
#include "request/GetCounterByUserIdRequest.hpp"
#include "request/DeleteCounterByUserIdRequest.hpp"
#include "request/IncreaseByStampSheetRequest.hpp"
#include "request/DescribeMissionTaskModelsRequest.hpp"
#include "request/GetMissionTaskModelRequest.hpp"
#include "result/DescribeCounterModelsResult.hpp"
#include "result/GetCounterModelResult.hpp"
#include "result/DescribeMissionGroupModelsResult.hpp"
#include "result/GetMissionGroupModelResult.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeMissionTaskModelMastersResult.hpp"
#include "result/CreateMissionTaskModelMasterResult.hpp"
#include "result/GetMissionTaskModelMasterResult.hpp"
#include "result/UpdateMissionTaskModelMasterResult.hpp"
#include "result/DeleteMissionTaskModelMasterResult.hpp"
#include "result/ExportMasterResult.hpp"
#include "result/GetCurrentMissionMasterResult.hpp"
#include "result/UpdateCurrentMissionMasterResult.hpp"
#include "result/UpdateCurrentMissionMasterFromGitHubResult.hpp"
#include "result/DescribeCounterModelMastersResult.hpp"
#include "result/CreateCounterModelMasterResult.hpp"
#include "result/GetCounterModelMasterResult.hpp"
#include "result/UpdateCounterModelMasterResult.hpp"
#include "result/DeleteCounterModelMasterResult.hpp"
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
#include "result/DescribeCountersResult.hpp"
#include "result/DescribeCountersByUserIdResult.hpp"
#include "result/IncreaseCounterByUserIdResult.hpp"
#include "result/GetCounterResult.hpp"
#include "result/GetCounterByUserIdResult.hpp"
#include "result/DeleteCounterByUserIdResult.hpp"
#include "result/IncreaseByStampSheetResult.hpp"
#include "result/DescribeMissionTaskModelsResult.hpp"
#include "result/GetMissionTaskModelResult.hpp"
#include <cstring>

namespace gs2 { namespace mission {

/**
 * GS2 Mission API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2MissionRestClient : public AbstractGs2ClientBase
{
private:

    class DescribeCounterModelsTask : public detail::Gs2RestSessionTask<DescribeCounterModelsResult>
    {
    private:
        DescribeCounterModelsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/counter";
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
        DescribeCounterModelsTask(
            DescribeCounterModelsRequest request,
            Gs2RestSessionTask<DescribeCounterModelsResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeCounterModelsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeCounterModelsTask() GS2_OVERRIDE = default;
    };

    class GetCounterModelTask : public detail::Gs2RestSessionTask<GetCounterModelResult>
    {
    private:
        GetCounterModelRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/counter/{counterName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getCounterName();
                url.replace("{counterName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetCounterModelTask(
            GetCounterModelRequest request,
            Gs2RestSessionTask<GetCounterModelResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetCounterModelResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetCounterModelTask() GS2_OVERRIDE = default;
    };

    class DescribeMissionGroupModelsTask : public detail::Gs2RestSessionTask<DescribeMissionGroupModelsResult>
    {
    private:
        DescribeMissionGroupModelsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/group";
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
        DescribeMissionGroupModelsTask(
            DescribeMissionGroupModelsRequest request,
            Gs2RestSessionTask<DescribeMissionGroupModelsResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeMissionGroupModelsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeMissionGroupModelsTask() GS2_OVERRIDE = default;
    };

    class GetMissionGroupModelTask : public detail::Gs2RestSessionTask<GetMissionGroupModelResult>
    {
    private:
        GetMissionGroupModelRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/group/{missionGroupName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMissionGroupName();
                url.replace("{missionGroupName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetMissionGroupModelTask(
            GetMissionGroupModelRequest request,
            Gs2RestSessionTask<GetMissionGroupModelResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetMissionGroupModelResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetMissionGroupModelTask() GS2_OVERRIDE = default;
    };

    class DescribeNamespacesTask : public detail::Gs2RestSessionTask<DescribeNamespacesResult>
    {
    private:
        DescribeNamespacesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
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
            return "mission";
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
            return "mission";
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
            return "mission";
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
            return "mission";
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
            return "mission";
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

    class DescribeMissionTaskModelMastersTask : public detail::Gs2RestSessionTask<DescribeMissionTaskModelMastersResult>
    {
    private:
        DescribeMissionTaskModelMastersRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/group/{missionGroupName}/task";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMissionGroupName();
                url.replace("{missionGroupName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DescribeMissionTaskModelMastersTask(
            DescribeMissionTaskModelMastersRequest request,
            Gs2RestSessionTask<DescribeMissionTaskModelMastersResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeMissionTaskModelMastersResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeMissionTaskModelMastersTask() GS2_OVERRIDE = default;
    };

    class CreateMissionTaskModelMasterTask : public detail::Gs2RestSessionTask<CreateMissionTaskModelMasterResult>
    {
    private:
        CreateMissionTaskModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/group/{missionGroupName}/task";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMissionGroupName();
                url.replace("{missionGroupName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            if (m_Request.getResetType())
            {
                jsonWriter.writePropertyName("resetType");
                jsonWriter.writeCharArray(*m_Request.getResetType());
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
        CreateMissionTaskModelMasterTask(
            CreateMissionTaskModelMasterRequest request,
            Gs2RestSessionTask<CreateMissionTaskModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CreateMissionTaskModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateMissionTaskModelMasterTask() GS2_OVERRIDE = default;
    };

    class GetMissionTaskModelMasterTask : public detail::Gs2RestSessionTask<GetMissionTaskModelMasterResult>
    {
    private:
        GetMissionTaskModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/group/{missionGroupName}/task/{missionTaskName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMissionGroupName();
                url.replace("{missionGroupName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMissionTaskName();
                url.replace("{missionTaskName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetMissionTaskModelMasterTask(
            GetMissionTaskModelMasterRequest request,
            Gs2RestSessionTask<GetMissionTaskModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetMissionTaskModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetMissionTaskModelMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateMissionTaskModelMasterTask : public detail::Gs2RestSessionTask<UpdateMissionTaskModelMasterResult>
    {
    private:
        UpdateMissionTaskModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/group/{missionGroupName}/task/{missionTaskName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMissionGroupName();
                url.replace("{missionGroupName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMissionTaskName();
                url.replace("{missionTaskName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
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
            if (m_Request.getResetType())
            {
                jsonWriter.writePropertyName("resetType");
                jsonWriter.writeCharArray(*m_Request.getResetType());
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
        UpdateMissionTaskModelMasterTask(
            UpdateMissionTaskModelMasterRequest request,
            Gs2RestSessionTask<UpdateMissionTaskModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateMissionTaskModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateMissionTaskModelMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteMissionTaskModelMasterTask : public detail::Gs2RestSessionTask<DeleteMissionTaskModelMasterResult>
    {
    private:
        DeleteMissionTaskModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/group/{missionGroupName}/task/{missionTaskName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMissionGroupName();
                url.replace("{missionGroupName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMissionTaskName();
                url.replace("{missionTaskName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DeleteMissionTaskModelMasterTask(
            DeleteMissionTaskModelMasterRequest request,
            Gs2RestSessionTask<DeleteMissionTaskModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteMissionTaskModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteMissionTaskModelMasterTask() GS2_OVERRIDE = default;
    };

    class ExportMasterTask : public detail::Gs2RestSessionTask<ExportMasterResult>
    {
    private:
        ExportMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
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

    class GetCurrentMissionMasterTask : public detail::Gs2RestSessionTask<GetCurrentMissionMasterResult>
    {
    private:
        GetCurrentMissionMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
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
        GetCurrentMissionMasterTask(
            GetCurrentMissionMasterRequest request,
            Gs2RestSessionTask<GetCurrentMissionMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetCurrentMissionMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetCurrentMissionMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentMissionMasterTask : public detail::Gs2RestSessionTask<UpdateCurrentMissionMasterResult>
    {
    private:
        UpdateCurrentMissionMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
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
        UpdateCurrentMissionMasterTask(
            UpdateCurrentMissionMasterRequest request,
            Gs2RestSessionTask<UpdateCurrentMissionMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateCurrentMissionMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateCurrentMissionMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentMissionMasterFromGitHubTask : public detail::Gs2RestSessionTask<UpdateCurrentMissionMasterFromGitHubResult>
    {
    private:
        UpdateCurrentMissionMasterFromGitHubRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
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
        UpdateCurrentMissionMasterFromGitHubTask(
            UpdateCurrentMissionMasterFromGitHubRequest request,
            Gs2RestSessionTask<UpdateCurrentMissionMasterFromGitHubResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateCurrentMissionMasterFromGitHubResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateCurrentMissionMasterFromGitHubTask() GS2_OVERRIDE = default;
    };

    class DescribeCounterModelMastersTask : public detail::Gs2RestSessionTask<DescribeCounterModelMastersResult>
    {
    private:
        DescribeCounterModelMastersRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/counter";
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
        DescribeCounterModelMastersTask(
            DescribeCounterModelMastersRequest request,
            Gs2RestSessionTask<DescribeCounterModelMastersResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeCounterModelMastersResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeCounterModelMastersTask() GS2_OVERRIDE = default;
    };

    class CreateCounterModelMasterTask : public detail::Gs2RestSessionTask<CreateCounterModelMasterResult>
    {
    private:
        CreateCounterModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/counter";
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
        CreateCounterModelMasterTask(
            CreateCounterModelMasterRequest request,
            Gs2RestSessionTask<CreateCounterModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CreateCounterModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateCounterModelMasterTask() GS2_OVERRIDE = default;
    };

    class GetCounterModelMasterTask : public detail::Gs2RestSessionTask<GetCounterModelMasterResult>
    {
    private:
        GetCounterModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/counter/{counterName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getCounterName();
                url.replace("{counterName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetCounterModelMasterTask(
            GetCounterModelMasterRequest request,
            Gs2RestSessionTask<GetCounterModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetCounterModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetCounterModelMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCounterModelMasterTask : public detail::Gs2RestSessionTask<UpdateCounterModelMasterResult>
    {
    private:
        UpdateCounterModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/counter/{counterName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getCounterName();
                url.replace("{counterName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
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
        UpdateCounterModelMasterTask(
            UpdateCounterModelMasterRequest request,
            Gs2RestSessionTask<UpdateCounterModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateCounterModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateCounterModelMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteCounterModelMasterTask : public detail::Gs2RestSessionTask<DeleteCounterModelMasterResult>
    {
    private:
        DeleteCounterModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/counter/{counterName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getCounterName();
                url.replace("{counterName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DeleteCounterModelMasterTask(
            DeleteCounterModelMasterRequest request,
            Gs2RestSessionTask<DeleteCounterModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteCounterModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteCounterModelMasterTask() GS2_OVERRIDE = default;
    };

    class DescribeCompletesTask : public detail::Gs2RestSessionTask<DescribeCompletesResult>
    {
    private:
        DescribeCompletesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/complete";
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
        DescribeCompletesTask(
            DescribeCompletesRequest request,
            Gs2RestSessionTask<DescribeCompletesResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeCompletesResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeCompletesTask() GS2_OVERRIDE = default;
    };

    class DescribeCompletesByUserIdTask : public detail::Gs2RestSessionTask<DescribeCompletesByUserIdResult>
    {
    private:
        DescribeCompletesByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/complete";
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
        DescribeCompletesByUserIdTask(
            DescribeCompletesByUserIdRequest request,
            Gs2RestSessionTask<DescribeCompletesByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeCompletesByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeCompletesByUserIdTask() GS2_OVERRIDE = default;
    };

    class CompleteTask : public detail::Gs2RestSessionTask<CompleteResult>
    {
    private:
        CompleteRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/complete/group/{missionGroupName}/task/{missionTaskName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMissionGroupName();
                url.replace("{missionGroupName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMissionTaskName();
                url.replace("{missionTaskName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
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
        CompleteTask(
            CompleteRequest request,
            Gs2RestSessionTask<CompleteResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CompleteResult>(callback),
            m_Request(std::move(request))
        {}

        ~CompleteTask() GS2_OVERRIDE = default;
    };

    class CompleteByUserIdTask : public detail::Gs2RestSessionTask<CompleteByUserIdResult>
    {
    private:
        CompleteByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/complete/group/{missionGroupName}/task/{missionTaskName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMissionGroupName();
                url.replace("{missionGroupName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMissionTaskName();
                url.replace("{missionTaskName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        CompleteByUserIdTask(
            CompleteByUserIdRequest request,
            Gs2RestSessionTask<CompleteByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CompleteByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~CompleteByUserIdTask() GS2_OVERRIDE = default;
    };

    class ReceiveByUserIdTask : public detail::Gs2RestSessionTask<ReceiveByUserIdResult>
    {
    private:
        ReceiveByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/complete/group/{missionGroupName}/task/{missionTaskName}/receive";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMissionGroupName();
                url.replace("{missionGroupName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMissionTaskName();
                url.replace("{missionTaskName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        ReceiveByUserIdTask(
            ReceiveByUserIdRequest request,
            Gs2RestSessionTask<ReceiveByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<ReceiveByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~ReceiveByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetCompleteTask : public detail::Gs2RestSessionTask<GetCompleteResult>
    {
    private:
        GetCompleteRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/complete/group/{missionGroupName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMissionGroupName();
                url.replace("{missionGroupName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetCompleteTask(
            GetCompleteRequest request,
            Gs2RestSessionTask<GetCompleteResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetCompleteResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetCompleteTask() GS2_OVERRIDE = default;
    };

    class GetCompleteByUserIdTask : public detail::Gs2RestSessionTask<GetCompleteByUserIdResult>
    {
    private:
        GetCompleteByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/complete/group/{missionGroupName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMissionGroupName();
                url.replace("{missionGroupName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetCompleteByUserIdTask(
            GetCompleteByUserIdRequest request,
            Gs2RestSessionTask<GetCompleteByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetCompleteByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetCompleteByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteCompleteByUserIdTask : public detail::Gs2RestSessionTask<DeleteCompleteByUserIdResult>
    {
    private:
        DeleteCompleteByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/complete/group/{missionGroupName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMissionGroupName();
                url.replace("{missionGroupName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DeleteCompleteByUserIdTask(
            DeleteCompleteByUserIdRequest request,
            Gs2RestSessionTask<DeleteCompleteByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteCompleteByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteCompleteByUserIdTask() GS2_OVERRIDE = default;
    };

    class ReceiveByStampTaskTask : public detail::Gs2RestSessionTask<ReceiveByStampTaskResult>
    {
    private:
        ReceiveByStampTaskRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stamp/receive";
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
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
        ReceiveByStampTaskTask(
            ReceiveByStampTaskRequest request,
            Gs2RestSessionTask<ReceiveByStampTaskResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<ReceiveByStampTaskResult>(callback),
            m_Request(std::move(request))
        {}

        ~ReceiveByStampTaskTask() GS2_OVERRIDE = default;
    };

    class DescribeMissionGroupModelMastersTask : public detail::Gs2RestSessionTask<DescribeMissionGroupModelMastersResult>
    {
    private:
        DescribeMissionGroupModelMastersRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/group";
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
        DescribeMissionGroupModelMastersTask(
            DescribeMissionGroupModelMastersRequest request,
            Gs2RestSessionTask<DescribeMissionGroupModelMastersResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeMissionGroupModelMastersResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeMissionGroupModelMastersTask() GS2_OVERRIDE = default;
    };

    class CreateMissionGroupModelMasterTask : public detail::Gs2RestSessionTask<CreateMissionGroupModelMasterResult>
    {
    private:
        CreateMissionGroupModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/group";
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
            if (m_Request.getCompleteNotificationNamespaceId())
            {
                jsonWriter.writePropertyName("completeNotificationNamespaceId");
                jsonWriter.writeCharArray(*m_Request.getCompleteNotificationNamespaceId());
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
        CreateMissionGroupModelMasterTask(
            CreateMissionGroupModelMasterRequest request,
            Gs2RestSessionTask<CreateMissionGroupModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CreateMissionGroupModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateMissionGroupModelMasterTask() GS2_OVERRIDE = default;
    };

    class GetMissionGroupModelMasterTask : public detail::Gs2RestSessionTask<GetMissionGroupModelMasterResult>
    {
    private:
        GetMissionGroupModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/group/{missionGroupName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMissionGroupName();
                url.replace("{missionGroupName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetMissionGroupModelMasterTask(
            GetMissionGroupModelMasterRequest request,
            Gs2RestSessionTask<GetMissionGroupModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetMissionGroupModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetMissionGroupModelMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateMissionGroupModelMasterTask : public detail::Gs2RestSessionTask<UpdateMissionGroupModelMasterResult>
    {
    private:
        UpdateMissionGroupModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/group/{missionGroupName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMissionGroupName();
                url.replace("{missionGroupName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
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
            if (m_Request.getCompleteNotificationNamespaceId())
            {
                jsonWriter.writePropertyName("completeNotificationNamespaceId");
                jsonWriter.writeCharArray(*m_Request.getCompleteNotificationNamespaceId());
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
        UpdateMissionGroupModelMasterTask(
            UpdateMissionGroupModelMasterRequest request,
            Gs2RestSessionTask<UpdateMissionGroupModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateMissionGroupModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateMissionGroupModelMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteMissionGroupModelMasterTask : public detail::Gs2RestSessionTask<DeleteMissionGroupModelMasterResult>
    {
    private:
        DeleteMissionGroupModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/group/{missionGroupName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMissionGroupName();
                url.replace("{missionGroupName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DeleteMissionGroupModelMasterTask(
            DeleteMissionGroupModelMasterRequest request,
            Gs2RestSessionTask<DeleteMissionGroupModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteMissionGroupModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteMissionGroupModelMasterTask() GS2_OVERRIDE = default;
    };

    class DescribeCountersTask : public detail::Gs2RestSessionTask<DescribeCountersResult>
    {
    private:
        DescribeCountersRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/counter";
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
        DescribeCountersTask(
            DescribeCountersRequest request,
            Gs2RestSessionTask<DescribeCountersResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeCountersResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeCountersTask() GS2_OVERRIDE = default;
    };

    class DescribeCountersByUserIdTask : public detail::Gs2RestSessionTask<DescribeCountersByUserIdResult>
    {
    private:
        DescribeCountersByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/counter";
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
        DescribeCountersByUserIdTask(
            DescribeCountersByUserIdRequest request,
            Gs2RestSessionTask<DescribeCountersByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeCountersByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeCountersByUserIdTask() GS2_OVERRIDE = default;
    };

    class IncreaseCounterByUserIdTask : public detail::Gs2RestSessionTask<IncreaseCounterByUserIdResult>
    {
    private:
        IncreaseCounterByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/counter/{counterName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getCounterName();
                url.replace("{counterName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            if (m_Request.getValue())
            {
                jsonWriter.writePropertyName("value");
                jsonWriter.writeInt64(*m_Request.getValue());
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
        IncreaseCounterByUserIdTask(
            IncreaseCounterByUserIdRequest request,
            Gs2RestSessionTask<IncreaseCounterByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<IncreaseCounterByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~IncreaseCounterByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetCounterTask : public detail::Gs2RestSessionTask<GetCounterResult>
    {
    private:
        GetCounterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/counter/{counterName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getCounterName();
                url.replace("{counterName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetCounterTask(
            GetCounterRequest request,
            Gs2RestSessionTask<GetCounterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetCounterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetCounterTask() GS2_OVERRIDE = default;
    };

    class GetCounterByUserIdTask : public detail::Gs2RestSessionTask<GetCounterByUserIdResult>
    {
    private:
        GetCounterByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/counter/{counterName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getCounterName();
                url.replace("{counterName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetCounterByUserIdTask(
            GetCounterByUserIdRequest request,
            Gs2RestSessionTask<GetCounterByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetCounterByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetCounterByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteCounterByUserIdTask : public detail::Gs2RestSessionTask<DeleteCounterByUserIdResult>
    {
    private:
        DeleteCounterByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/counter/{counterName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getCounterName();
                url.replace("{counterName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DeleteCounterByUserIdTask(
            DeleteCounterByUserIdRequest request,
            Gs2RestSessionTask<DeleteCounterByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteCounterByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteCounterByUserIdTask() GS2_OVERRIDE = default;
    };

    class IncreaseByStampSheetTask : public detail::Gs2RestSessionTask<IncreaseByStampSheetResult>
    {
    private:
        IncreaseByStampSheetRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stamp/increase";
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
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
        IncreaseByStampSheetTask(
            IncreaseByStampSheetRequest request,
            Gs2RestSessionTask<IncreaseByStampSheetResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<IncreaseByStampSheetResult>(callback),
            m_Request(std::move(request))
        {}

        ~IncreaseByStampSheetTask() GS2_OVERRIDE = default;
    };

    class DescribeMissionTaskModelsTask : public detail::Gs2RestSessionTask<DescribeMissionTaskModelsResult>
    {
    private:
        DescribeMissionTaskModelsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/group/{missionGroupName}/task";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMissionGroupName();
                url.replace("{missionGroupName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DescribeMissionTaskModelsTask(
            DescribeMissionTaskModelsRequest request,
            Gs2RestSessionTask<DescribeMissionTaskModelsResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeMissionTaskModelsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeMissionTaskModelsTask() GS2_OVERRIDE = default;
    };

    class GetMissionTaskModelTask : public detail::Gs2RestSessionTask<GetMissionTaskModelResult>
    {
    private:
        GetMissionTaskModelRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "mission";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/group/{missionGroupName}/task/{missionTaskName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMissionGroupName();
                url.replace("{missionGroupName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMissionTaskName();
                url.replace("{missionTaskName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetMissionTaskModelTask(
            GetMissionTaskModelRequest request,
            Gs2RestSessionTask<GetMissionTaskModelResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetMissionTaskModelResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetMissionTaskModelTask() GS2_OVERRIDE = default;
    };

protected:
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
        if (obj.getCompleteNotificationNamespaceId())
        {
            jsonWriter.writePropertyName("completeNotificationNamespaceId");
            jsonWriter.writeCharArray(*obj.getCompleteNotificationNamespaceId());
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
        if (obj.getResetType())
        {
            jsonWriter.writePropertyName("resetType");
            jsonWriter.writeCharArray(*obj.getResetType());
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
        if (obj.getResetType())
        {
            jsonWriter.writePropertyName("resetType");
            jsonWriter.writeCharArray(*obj.getResetType());
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



public:
    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
     */
    explicit Gs2MissionRestClient(Gs2RestSession& gs2RestSession) :
        AbstractGs2ClientBase(gs2RestSession)
    {
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
	 * ミッションタスクマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeMissionTaskModelMasters(DescribeMissionTaskModelMastersRequest request, std::function<void(AsyncDescribeMissionTaskModelMastersResult)> callback)
    {
        DescribeMissionTaskModelMastersTask& task = *new DescribeMissionTaskModelMastersTask(std::move(request), callback);
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
    }

protected:
    Gs2RestSession& getGs2RestSession()
    {
        return static_cast<Gs2RestSession&>(getGs2Session());
    }
};

} }

#endif //GS2_MISSION_GS2MISSIONRESTCLIENT_HPP_