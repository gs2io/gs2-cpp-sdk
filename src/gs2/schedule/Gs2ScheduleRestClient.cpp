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

#include "Gs2ScheduleRestClient.hpp"
#include "model/model.hpp"
#include "request/DescribeNamespacesRequest.hpp"
#include "request/CreateNamespaceRequest.hpp"
#include "request/GetNamespaceStatusRequest.hpp"
#include "request/GetNamespaceRequest.hpp"
#include "request/UpdateNamespaceRequest.hpp"
#include "request/DeleteNamespaceRequest.hpp"
#include "request/DescribeEventMastersRequest.hpp"
#include "request/CreateEventMasterRequest.hpp"
#include "request/GetEventMasterRequest.hpp"
#include "request/UpdateEventMasterRequest.hpp"
#include "request/DeleteEventMasterRequest.hpp"
#include "request/DescribeTriggersRequest.hpp"
#include "request/DescribeTriggersByUserIdRequest.hpp"
#include "request/GetTriggerRequest.hpp"
#include "request/GetTriggerByUserIdRequest.hpp"
#include "request/TriggerByUserIdRequest.hpp"
#include "request/DeleteTriggerRequest.hpp"
#include "request/DeleteTriggerByUserIdRequest.hpp"
#include "request/DescribeEventsRequest.hpp"
#include "request/DescribeEventsByUserIdRequest.hpp"
#include "request/DescribeRawEventsRequest.hpp"
#include "request/GetEventRequest.hpp"
#include "request/GetEventByUserIdRequest.hpp"
#include "request/GetRawEventRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentEventMasterRequest.hpp"
#include "request/UpdateCurrentEventMasterRequest.hpp"
#include "request/UpdateCurrentEventMasterFromGitHubRequest.hpp"
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <cstring>

namespace gs2 { namespace schedule {

namespace {

void write(detail::json::JsonWriter& jsonWriter, const Namespace& obj);
void write(detail::json::JsonWriter& jsonWriter, const EventMaster& obj);
void write(detail::json::JsonWriter& jsonWriter, const Trigger& obj);
void write(detail::json::JsonWriter& jsonWriter, const Event& obj);
void write(detail::json::JsonWriter& jsonWriter, const CurrentEventMaster& obj);
void write(detail::json::JsonWriter& jsonWriter, const ResponseCache& obj);
void write(detail::json::JsonWriter& jsonWriter, const GitHubCheckoutSetting& obj);
void write(detail::json::JsonWriter& jsonWriter, const LogSetting& obj);

void write(detail::json::JsonWriter& jsonWriter, const Namespace& obj)
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

void write(detail::json::JsonWriter& jsonWriter, const EventMaster& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getEventId())
    {
        jsonWriter.writePropertyName("eventId");
        jsonWriter.writeCharArray(*obj.getEventId());
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
    if (obj.getMetadata())
    {
        jsonWriter.writePropertyName("metadata");
        jsonWriter.writeCharArray(*obj.getMetadata());
    }
    if (obj.getScheduleType())
    {
        jsonWriter.writePropertyName("scheduleType");
        jsonWriter.writeCharArray(*obj.getScheduleType());
    }
    if (obj.getRepeatType())
    {
        jsonWriter.writePropertyName("repeatType");
        jsonWriter.writeCharArray(*obj.getRepeatType());
    }
    if (obj.getAbsoluteBegin())
    {
        jsonWriter.writePropertyName("absoluteBegin");
        jsonWriter.writeInt64(*obj.getAbsoluteBegin());
    }
    if (obj.getAbsoluteEnd())
    {
        jsonWriter.writePropertyName("absoluteEnd");
        jsonWriter.writeInt64(*obj.getAbsoluteEnd());
    }
    if (obj.getRepeatBeginDayOfMonth())
    {
        jsonWriter.writePropertyName("repeatBeginDayOfMonth");
        jsonWriter.writeInt32(*obj.getRepeatBeginDayOfMonth());
    }
    if (obj.getRepeatEndDayOfMonth())
    {
        jsonWriter.writePropertyName("repeatEndDayOfMonth");
        jsonWriter.writeInt32(*obj.getRepeatEndDayOfMonth());
    }
    if (obj.getRepeatBeginDayOfWeek())
    {
        jsonWriter.writePropertyName("repeatBeginDayOfWeek");
        jsonWriter.writeCharArray(*obj.getRepeatBeginDayOfWeek());
    }
    if (obj.getRepeatEndDayOfWeek())
    {
        jsonWriter.writePropertyName("repeatEndDayOfWeek");
        jsonWriter.writeCharArray(*obj.getRepeatEndDayOfWeek());
    }
    if (obj.getRepeatBeginHour())
    {
        jsonWriter.writePropertyName("repeatBeginHour");
        jsonWriter.writeInt32(*obj.getRepeatBeginHour());
    }
    if (obj.getRepeatEndHour())
    {
        jsonWriter.writePropertyName("repeatEndHour");
        jsonWriter.writeInt32(*obj.getRepeatEndHour());
    }
    if (obj.getRelativeTriggerName())
    {
        jsonWriter.writePropertyName("relativeTriggerName");
        jsonWriter.writeCharArray(*obj.getRelativeTriggerName());
    }
    if (obj.getRelativeDuration())
    {
        jsonWriter.writePropertyName("relativeDuration");
        jsonWriter.writeInt32(*obj.getRelativeDuration());
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

void write(detail::json::JsonWriter& jsonWriter, const Trigger& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getTriggerId())
    {
        jsonWriter.writePropertyName("triggerId");
        jsonWriter.writeCharArray(*obj.getTriggerId());
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
    if (obj.getCreatedAt())
    {
        jsonWriter.writePropertyName("createdAt");
        jsonWriter.writeInt64(*obj.getCreatedAt());
    }
    if (obj.getExpiresAt())
    {
        jsonWriter.writePropertyName("expiresAt");
        jsonWriter.writeInt64(*obj.getExpiresAt());
    }
    jsonWriter.writeObjectEnd();
}

void write(detail::json::JsonWriter& jsonWriter, const Event& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getEventId())
    {
        jsonWriter.writePropertyName("eventId");
        jsonWriter.writeCharArray(*obj.getEventId());
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
    if (obj.getScheduleType())
    {
        jsonWriter.writePropertyName("scheduleType");
        jsonWriter.writeCharArray(*obj.getScheduleType());
    }
    if (obj.getRepeatType())
    {
        jsonWriter.writePropertyName("repeatType");
        jsonWriter.writeCharArray(*obj.getRepeatType());
    }
    if (obj.getAbsoluteBegin())
    {
        jsonWriter.writePropertyName("absoluteBegin");
        jsonWriter.writeInt64(*obj.getAbsoluteBegin());
    }
    if (obj.getAbsoluteEnd())
    {
        jsonWriter.writePropertyName("absoluteEnd");
        jsonWriter.writeInt64(*obj.getAbsoluteEnd());
    }
    if (obj.getRepeatBeginDayOfMonth())
    {
        jsonWriter.writePropertyName("repeatBeginDayOfMonth");
        jsonWriter.writeInt32(*obj.getRepeatBeginDayOfMonth());
    }
    if (obj.getRepeatEndDayOfMonth())
    {
        jsonWriter.writePropertyName("repeatEndDayOfMonth");
        jsonWriter.writeInt32(*obj.getRepeatEndDayOfMonth());
    }
    if (obj.getRepeatBeginDayOfWeek())
    {
        jsonWriter.writePropertyName("repeatBeginDayOfWeek");
        jsonWriter.writeCharArray(*obj.getRepeatBeginDayOfWeek());
    }
    if (obj.getRepeatEndDayOfWeek())
    {
        jsonWriter.writePropertyName("repeatEndDayOfWeek");
        jsonWriter.writeCharArray(*obj.getRepeatEndDayOfWeek());
    }
    if (obj.getRepeatBeginHour())
    {
        jsonWriter.writePropertyName("repeatBeginHour");
        jsonWriter.writeInt32(*obj.getRepeatBeginHour());
    }
    if (obj.getRepeatEndHour())
    {
        jsonWriter.writePropertyName("repeatEndHour");
        jsonWriter.writeInt32(*obj.getRepeatEndHour());
    }
    if (obj.getRelativeTriggerName())
    {
        jsonWriter.writePropertyName("relativeTriggerName");
        jsonWriter.writeCharArray(*obj.getRelativeTriggerName());
    }
    if (obj.getRelativeDuration())
    {
        jsonWriter.writePropertyName("relativeDuration");
        jsonWriter.writeInt32(*obj.getRelativeDuration());
    }
    jsonWriter.writeObjectEnd();
}

void write(detail::json::JsonWriter& jsonWriter, const CurrentEventMaster& obj)
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

void write(detail::json::JsonWriter& jsonWriter, const ResponseCache& obj)
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

void write(detail::json::JsonWriter& jsonWriter, const GitHubCheckoutSetting& obj)
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

void write(detail::json::JsonWriter& jsonWriter, const LogSetting& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getLoggingNamespaceId())
    {
        jsonWriter.writePropertyName("loggingNamespaceId");
        jsonWriter.writeCharArray(*obj.getLoggingNamespaceId());
    }
    jsonWriter.writeObjectEnd();
}


class DescribeNamespacesTask : public detail::Gs2RestSessionTask<DescribeNamespacesResult>
{
private:
    DescribeNamespacesRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "schedule";
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
        return "schedule";
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
        return "schedule";
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
        return "schedule";
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
        return "schedule";
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
        return "schedule";
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

class DescribeEventMastersTask : public detail::Gs2RestSessionTask<DescribeEventMastersResult>
{
private:
    DescribeEventMastersRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "schedule";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/master/event";
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
    DescribeEventMastersTask(
        DescribeEventMastersRequest request,
        Gs2RestSessionTask<DescribeEventMastersResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<DescribeEventMastersResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeEventMastersTask() GS2_OVERRIDE = default;
};

class CreateEventMasterTask : public detail::Gs2RestSessionTask<CreateEventMasterResult>
{
private:
    CreateEventMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "schedule";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/master/event";
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
        if (m_Request.getScheduleType())
        {
            jsonWriter.writePropertyName("scheduleType");
            jsonWriter.writeCharArray(*m_Request.getScheduleType());
        }
        if (m_Request.getAbsoluteBegin())
        {
            jsonWriter.writePropertyName("absoluteBegin");
            jsonWriter.writeInt64(*m_Request.getAbsoluteBegin());
        }
        if (m_Request.getAbsoluteEnd())
        {
            jsonWriter.writePropertyName("absoluteEnd");
            jsonWriter.writeInt64(*m_Request.getAbsoluteEnd());
        }
        if (m_Request.getRepeatType())
        {
            jsonWriter.writePropertyName("repeatType");
            jsonWriter.writeCharArray(*m_Request.getRepeatType());
        }
        if (m_Request.getRepeatBeginDayOfMonth())
        {
            jsonWriter.writePropertyName("repeatBeginDayOfMonth");
            jsonWriter.writeInt32(*m_Request.getRepeatBeginDayOfMonth());
        }
        if (m_Request.getRepeatEndDayOfMonth())
        {
            jsonWriter.writePropertyName("repeatEndDayOfMonth");
            jsonWriter.writeInt32(*m_Request.getRepeatEndDayOfMonth());
        }
        if (m_Request.getRepeatBeginDayOfWeek())
        {
            jsonWriter.writePropertyName("repeatBeginDayOfWeek");
            jsonWriter.writeCharArray(*m_Request.getRepeatBeginDayOfWeek());
        }
        if (m_Request.getRepeatEndDayOfWeek())
        {
            jsonWriter.writePropertyName("repeatEndDayOfWeek");
            jsonWriter.writeCharArray(*m_Request.getRepeatEndDayOfWeek());
        }
        if (m_Request.getRepeatBeginHour())
        {
            jsonWriter.writePropertyName("repeatBeginHour");
            jsonWriter.writeInt32(*m_Request.getRepeatBeginHour());
        }
        if (m_Request.getRepeatEndHour())
        {
            jsonWriter.writePropertyName("repeatEndHour");
            jsonWriter.writeInt32(*m_Request.getRepeatEndHour());
        }
        if (m_Request.getRelativeTriggerName())
        {
            jsonWriter.writePropertyName("relativeTriggerName");
            jsonWriter.writeCharArray(*m_Request.getRelativeTriggerName());
        }
        if (m_Request.getRelativeDuration())
        {
            jsonWriter.writePropertyName("relativeDuration");
            jsonWriter.writeInt32(*m_Request.getRelativeDuration());
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
    CreateEventMasterTask(
        CreateEventMasterRequest request,
        Gs2RestSessionTask<CreateEventMasterResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<CreateEventMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~CreateEventMasterTask() GS2_OVERRIDE = default;
};

class GetEventMasterTask : public detail::Gs2RestSessionTask<GetEventMasterResult>
{
private:
    GetEventMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "schedule";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/master/event/{eventName}";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getEventName();
            url.replace("{eventName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
    GetEventMasterTask(
        GetEventMasterRequest request,
        Gs2RestSessionTask<GetEventMasterResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<GetEventMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetEventMasterTask() GS2_OVERRIDE = default;
};

class UpdateEventMasterTask : public detail::Gs2RestSessionTask<UpdateEventMasterResult>
{
private:
    UpdateEventMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "schedule";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/master/event/{eventName}";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getEventName();
            url.replace("{eventName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        if (m_Request.getScheduleType())
        {
            jsonWriter.writePropertyName("scheduleType");
            jsonWriter.writeCharArray(*m_Request.getScheduleType());
        }
        if (m_Request.getAbsoluteBegin())
        {
            jsonWriter.writePropertyName("absoluteBegin");
            jsonWriter.writeInt64(*m_Request.getAbsoluteBegin());
        }
        if (m_Request.getAbsoluteEnd())
        {
            jsonWriter.writePropertyName("absoluteEnd");
            jsonWriter.writeInt64(*m_Request.getAbsoluteEnd());
        }
        if (m_Request.getRepeatType())
        {
            jsonWriter.writePropertyName("repeatType");
            jsonWriter.writeCharArray(*m_Request.getRepeatType());
        }
        if (m_Request.getRepeatBeginDayOfMonth())
        {
            jsonWriter.writePropertyName("repeatBeginDayOfMonth");
            jsonWriter.writeInt32(*m_Request.getRepeatBeginDayOfMonth());
        }
        if (m_Request.getRepeatEndDayOfMonth())
        {
            jsonWriter.writePropertyName("repeatEndDayOfMonth");
            jsonWriter.writeInt32(*m_Request.getRepeatEndDayOfMonth());
        }
        if (m_Request.getRepeatBeginDayOfWeek())
        {
            jsonWriter.writePropertyName("repeatBeginDayOfWeek");
            jsonWriter.writeCharArray(*m_Request.getRepeatBeginDayOfWeek());
        }
        if (m_Request.getRepeatEndDayOfWeek())
        {
            jsonWriter.writePropertyName("repeatEndDayOfWeek");
            jsonWriter.writeCharArray(*m_Request.getRepeatEndDayOfWeek());
        }
        if (m_Request.getRepeatBeginHour())
        {
            jsonWriter.writePropertyName("repeatBeginHour");
            jsonWriter.writeInt32(*m_Request.getRepeatBeginHour());
        }
        if (m_Request.getRepeatEndHour())
        {
            jsonWriter.writePropertyName("repeatEndHour");
            jsonWriter.writeInt32(*m_Request.getRepeatEndHour());
        }
        if (m_Request.getRelativeTriggerName())
        {
            jsonWriter.writePropertyName("relativeTriggerName");
            jsonWriter.writeCharArray(*m_Request.getRelativeTriggerName());
        }
        if (m_Request.getRelativeDuration())
        {
            jsonWriter.writePropertyName("relativeDuration");
            jsonWriter.writeInt32(*m_Request.getRelativeDuration());
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
    UpdateEventMasterTask(
        UpdateEventMasterRequest request,
        Gs2RestSessionTask<UpdateEventMasterResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<UpdateEventMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~UpdateEventMasterTask() GS2_OVERRIDE = default;
};

class DeleteEventMasterTask : public detail::Gs2RestSessionTask<DeleteEventMasterResult>
{
private:
    DeleteEventMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "schedule";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/master/event/{eventName}";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getEventName();
            url.replace("{eventName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
    DeleteEventMasterTask(
        DeleteEventMasterRequest request,
        Gs2RestSessionTask<DeleteEventMasterResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<DeleteEventMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~DeleteEventMasterTask() GS2_OVERRIDE = default;
};

class DescribeTriggersTask : public detail::Gs2RestSessionTask<DescribeTriggersResult>
{
private:
    DescribeTriggersRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "schedule";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/user/me/trigger";
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
    DescribeTriggersTask(
        DescribeTriggersRequest request,
        Gs2RestSessionTask<DescribeTriggersResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<DescribeTriggersResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeTriggersTask() GS2_OVERRIDE = default;
};

class DescribeTriggersByUserIdTask : public detail::Gs2RestSessionTask<DescribeTriggersByUserIdResult>
{
private:
    DescribeTriggersByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "schedule";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/user/{userId}/trigger";
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
    DescribeTriggersByUserIdTask(
        DescribeTriggersByUserIdRequest request,
        Gs2RestSessionTask<DescribeTriggersByUserIdResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<DescribeTriggersByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeTriggersByUserIdTask() GS2_OVERRIDE = default;
};

class GetTriggerTask : public detail::Gs2RestSessionTask<GetTriggerResult>
{
private:
    GetTriggerRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "schedule";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/user/me/trigger/{triggerName}";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getTriggerName();
            url.replace("{triggerName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
    GetTriggerTask(
        GetTriggerRequest request,
        Gs2RestSessionTask<GetTriggerResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<GetTriggerResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetTriggerTask() GS2_OVERRIDE = default;
};

class GetTriggerByUserIdTask : public detail::Gs2RestSessionTask<GetTriggerByUserIdResult>
{
private:
    GetTriggerByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "schedule";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/user/{userId}/trigger/{triggerName}";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getTriggerName();
            url.replace("{triggerName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
    GetTriggerByUserIdTask(
        GetTriggerByUserIdRequest request,
        Gs2RestSessionTask<GetTriggerByUserIdResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<GetTriggerByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetTriggerByUserIdTask() GS2_OVERRIDE = default;
};

class TriggerByUserIdTask : public detail::Gs2RestSessionTask<TriggerByUserIdResult>
{
private:
    TriggerByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "schedule";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/user/{userId}/trigger/{triggerName}";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getTriggerName();
            url.replace("{triggerName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        if (m_Request.getTriggerStrategy())
        {
            jsonWriter.writePropertyName("triggerStrategy");
            jsonWriter.writeCharArray(*m_Request.getTriggerStrategy());
        }
        if (m_Request.getTtl())
        {
            jsonWriter.writePropertyName("ttl");
            jsonWriter.writeInt32(*m_Request.getTtl());
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
    TriggerByUserIdTask(
        TriggerByUserIdRequest request,
        Gs2RestSessionTask<TriggerByUserIdResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<TriggerByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~TriggerByUserIdTask() GS2_OVERRIDE = default;
};

class DeleteTriggerTask : public detail::Gs2RestSessionTask<DeleteTriggerResult>
{
private:
    DeleteTriggerRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "schedule";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/user/me/trigger/{triggerName}";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getTriggerName();
            url.replace("{triggerName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
    DeleteTriggerTask(
        DeleteTriggerRequest request,
        Gs2RestSessionTask<DeleteTriggerResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<DeleteTriggerResult>(callback),
        m_Request(std::move(request))
    {}

    ~DeleteTriggerTask() GS2_OVERRIDE = default;
};

class DeleteTriggerByUserIdTask : public detail::Gs2RestSessionTask<DeleteTriggerByUserIdResult>
{
private:
    DeleteTriggerByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "schedule";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/user/{userId}/trigger/{triggerName}";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getTriggerName();
            url.replace("{triggerName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
    DeleteTriggerByUserIdTask(
        DeleteTriggerByUserIdRequest request,
        Gs2RestSessionTask<DeleteTriggerByUserIdResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<DeleteTriggerByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~DeleteTriggerByUserIdTask() GS2_OVERRIDE = default;
};

class DescribeEventsTask : public detail::Gs2RestSessionTask<DescribeEventsResult>
{
private:
    DescribeEventsRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "schedule";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/user/me/event";
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
    DescribeEventsTask(
        DescribeEventsRequest request,
        Gs2RestSessionTask<DescribeEventsResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<DescribeEventsResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeEventsTask() GS2_OVERRIDE = default;
};

class DescribeEventsByUserIdTask : public detail::Gs2RestSessionTask<DescribeEventsByUserIdResult>
{
private:
    DescribeEventsByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "schedule";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/user/{userId}/event";
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
    DescribeEventsByUserIdTask(
        DescribeEventsByUserIdRequest request,
        Gs2RestSessionTask<DescribeEventsByUserIdResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<DescribeEventsByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeEventsByUserIdTask() GS2_OVERRIDE = default;
};

class DescribeRawEventsTask : public detail::Gs2RestSessionTask<DescribeRawEventsResult>
{
private:
    DescribeRawEventsRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "schedule";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/event";
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
    DescribeRawEventsTask(
        DescribeRawEventsRequest request,
        Gs2RestSessionTask<DescribeRawEventsResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<DescribeRawEventsResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeRawEventsTask() GS2_OVERRIDE = default;
};

class GetEventTask : public detail::Gs2RestSessionTask<GetEventResult>
{
private:
    GetEventRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "schedule";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/user/me/event/{eventName}";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getEventName();
            url.replace("{eventName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
    GetEventTask(
        GetEventRequest request,
        Gs2RestSessionTask<GetEventResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<GetEventResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetEventTask() GS2_OVERRIDE = default;
};

class GetEventByUserIdTask : public detail::Gs2RestSessionTask<GetEventByUserIdResult>
{
private:
    GetEventByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "schedule";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/user/{userId}/event/{eventName}";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getEventName();
            url.replace("{eventName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
    GetEventByUserIdTask(
        GetEventByUserIdRequest request,
        Gs2RestSessionTask<GetEventByUserIdResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<GetEventByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetEventByUserIdTask() GS2_OVERRIDE = default;
};

class GetRawEventTask : public detail::Gs2RestSessionTask<GetRawEventResult>
{
private:
    GetRawEventRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "schedule";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/event/{eventName}";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getEventName();
            url.replace("{eventName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
    GetRawEventTask(
        GetRawEventRequest request,
        Gs2RestSessionTask<GetRawEventResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<GetRawEventResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetRawEventTask() GS2_OVERRIDE = default;
};

class ExportMasterTask : public detail::Gs2RestSessionTask<ExportMasterResult>
{
private:
    ExportMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "schedule";
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

class GetCurrentEventMasterTask : public detail::Gs2RestSessionTask<GetCurrentEventMasterResult>
{
private:
    GetCurrentEventMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "schedule";
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
    GetCurrentEventMasterTask(
        GetCurrentEventMasterRequest request,
        Gs2RestSessionTask<GetCurrentEventMasterResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<GetCurrentEventMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetCurrentEventMasterTask() GS2_OVERRIDE = default;
};

class UpdateCurrentEventMasterTask : public detail::Gs2RestSessionTask<UpdateCurrentEventMasterResult>
{
private:
    UpdateCurrentEventMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "schedule";
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
    UpdateCurrentEventMasterTask(
        UpdateCurrentEventMasterRequest request,
        Gs2RestSessionTask<UpdateCurrentEventMasterResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<UpdateCurrentEventMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~UpdateCurrentEventMasterTask() GS2_OVERRIDE = default;
};

class UpdateCurrentEventMasterFromGitHubTask : public detail::Gs2RestSessionTask<UpdateCurrentEventMasterFromGitHubResult>
{
private:
    UpdateCurrentEventMasterFromGitHubRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "schedule";
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
    UpdateCurrentEventMasterFromGitHubTask(
        UpdateCurrentEventMasterFromGitHubRequest request,
        Gs2RestSessionTask<UpdateCurrentEventMasterFromGitHubResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<UpdateCurrentEventMasterFromGitHubResult>(callback),
        m_Request(std::move(request))
    {}

    ~UpdateCurrentEventMasterFromGitHubTask() GS2_OVERRIDE = default;
};
}

/**
 * ネームスペースの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2ScheduleRestClient::describeNamespaces(DescribeNamespacesRequest request, std::function<void(AsyncDescribeNamespacesResult)> callback)
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
void Gs2ScheduleRestClient::createNamespace(CreateNamespaceRequest request, std::function<void(AsyncCreateNamespaceResult)> callback)
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
void Gs2ScheduleRestClient::getNamespaceStatus(GetNamespaceStatusRequest request, std::function<void(AsyncGetNamespaceStatusResult)> callback)
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
void Gs2ScheduleRestClient::getNamespace(GetNamespaceRequest request, std::function<void(AsyncGetNamespaceResult)> callback)
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
void Gs2ScheduleRestClient::updateNamespace(UpdateNamespaceRequest request, std::function<void(AsyncUpdateNamespaceResult)> callback)
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
void Gs2ScheduleRestClient::deleteNamespace(DeleteNamespaceRequest request, std::function<void(AsyncDeleteNamespaceResult)> callback)
{
    DeleteNamespaceTask& task = *new DeleteNamespaceTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * イベントマスターの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2ScheduleRestClient::describeEventMasters(DescribeEventMastersRequest request, std::function<void(AsyncDescribeEventMastersResult)> callback)
{
    DescribeEventMastersTask& task = *new DescribeEventMastersTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * イベントマスターを新規作成<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2ScheduleRestClient::createEventMaster(CreateEventMasterRequest request, std::function<void(AsyncCreateEventMasterResult)> callback)
{
    CreateEventMasterTask& task = *new CreateEventMasterTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * イベントマスターを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2ScheduleRestClient::getEventMaster(GetEventMasterRequest request, std::function<void(AsyncGetEventMasterResult)> callback)
{
    GetEventMasterTask& task = *new GetEventMasterTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * イベントマスターを更新<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2ScheduleRestClient::updateEventMaster(UpdateEventMasterRequest request, std::function<void(AsyncUpdateEventMasterResult)> callback)
{
    UpdateEventMasterTask& task = *new UpdateEventMasterTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * イベントマスターを削除<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2ScheduleRestClient::deleteEventMaster(DeleteEventMasterRequest request, std::function<void(AsyncDeleteEventMasterResult)> callback)
{
    DeleteEventMasterTask& task = *new DeleteEventMasterTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * トリガーの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2ScheduleRestClient::describeTriggers(DescribeTriggersRequest request, std::function<void(AsyncDescribeTriggersResult)> callback)
{
    DescribeTriggersTask& task = *new DescribeTriggersTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * ユーザIDを指定してトリガーの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2ScheduleRestClient::describeTriggersByUserId(DescribeTriggersByUserIdRequest request, std::function<void(AsyncDescribeTriggersByUserIdResult)> callback)
{
    DescribeTriggersByUserIdTask& task = *new DescribeTriggersByUserIdTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * トリガーを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2ScheduleRestClient::getTrigger(GetTriggerRequest request, std::function<void(AsyncGetTriggerResult)> callback)
{
    GetTriggerTask& task = *new GetTriggerTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * ユーザIDを指定してトリガーを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2ScheduleRestClient::getTriggerByUserId(GetTriggerByUserIdRequest request, std::function<void(AsyncGetTriggerByUserIdResult)> callback)
{
    GetTriggerByUserIdTask& task = *new GetTriggerByUserIdTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * ユーザIDを指定してトリガーを登録<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2ScheduleRestClient::triggerByUserId(TriggerByUserIdRequest request, std::function<void(AsyncTriggerByUserIdResult)> callback)
{
    TriggerByUserIdTask& task = *new TriggerByUserIdTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * トリガーを削除<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2ScheduleRestClient::deleteTrigger(DeleteTriggerRequest request, std::function<void(AsyncDeleteTriggerResult)> callback)
{
    DeleteTriggerTask& task = *new DeleteTriggerTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * ユーザIDを指定してトリガーを削除<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2ScheduleRestClient::deleteTriggerByUserId(DeleteTriggerByUserIdRequest request, std::function<void(AsyncDeleteTriggerByUserIdResult)> callback)
{
    DeleteTriggerByUserIdTask& task = *new DeleteTriggerByUserIdTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * イベントの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2ScheduleRestClient::describeEvents(DescribeEventsRequest request, std::function<void(AsyncDescribeEventsResult)> callback)
{
    DescribeEventsTask& task = *new DescribeEventsTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * ユーザIDを指定してイベントの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2ScheduleRestClient::describeEventsByUserId(DescribeEventsByUserIdRequest request, std::function<void(AsyncDescribeEventsByUserIdResult)> callback)
{
    DescribeEventsByUserIdTask& task = *new DescribeEventsByUserIdTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * イベントの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2ScheduleRestClient::describeRawEvents(DescribeRawEventsRequest request, std::function<void(AsyncDescribeRawEventsResult)> callback)
{
    DescribeRawEventsTask& task = *new DescribeRawEventsTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * イベントを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2ScheduleRestClient::getEvent(GetEventRequest request, std::function<void(AsyncGetEventResult)> callback)
{
    GetEventTask& task = *new GetEventTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * ユーザIDを指定してイベントを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2ScheduleRestClient::getEventByUserId(GetEventByUserIdRequest request, std::function<void(AsyncGetEventByUserIdResult)> callback)
{
    GetEventByUserIdTask& task = *new GetEventByUserIdTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * イベントを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2ScheduleRestClient::getRawEvent(GetRawEventRequest request, std::function<void(AsyncGetRawEventResult)> callback)
{
    GetRawEventTask& task = *new GetRawEventTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * 現在有効なイベントスケジュールマスターのマスターデータをエクスポートします<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2ScheduleRestClient::exportMaster(ExportMasterRequest request, std::function<void(AsyncExportMasterResult)> callback)
{
    ExportMasterTask& task = *new ExportMasterTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * 現在有効なイベントスケジュールマスターを取得します<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2ScheduleRestClient::getCurrentEventMaster(GetCurrentEventMasterRequest request, std::function<void(AsyncGetCurrentEventMasterResult)> callback)
{
    GetCurrentEventMasterTask& task = *new GetCurrentEventMasterTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * 現在有効なイベントスケジュールマスターを更新します<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2ScheduleRestClient::updateCurrentEventMaster(UpdateCurrentEventMasterRequest request, std::function<void(AsyncUpdateCurrentEventMasterResult)> callback)
{
    UpdateCurrentEventMasterTask& task = *new UpdateCurrentEventMasterTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * 現在有効なイベントスケジュールマスターを更新します<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2ScheduleRestClient::updateCurrentEventMasterFromGitHub(UpdateCurrentEventMasterFromGitHubRequest request, std::function<void(AsyncUpdateCurrentEventMasterFromGitHubResult)> callback)
{
    UpdateCurrentEventMasterFromGitHubTask& task = *new UpdateCurrentEventMasterFromGitHubTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

} }