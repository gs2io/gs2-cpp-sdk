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

#include "Gs2JobQueueRestClient.hpp"
#include "model/model.hpp"
#include "request/DescribeNamespacesRequest.hpp"
#include "request/CreateNamespaceRequest.hpp"
#include "request/GetNamespaceStatusRequest.hpp"
#include "request/GetNamespaceRequest.hpp"
#include "request/UpdateNamespaceRequest.hpp"
#include "request/DeleteNamespaceRequest.hpp"
#include "request/DescribeJobsByUserIdRequest.hpp"
#include "request/GetJobByUserIdRequest.hpp"
#include "request/PushByUserIdRequest.hpp"
#include "request/RunRequest.hpp"
#include "request/RunByUserIdRequest.hpp"
#include "request/DeleteJobByUserIdRequest.hpp"
#include "request/PushByStampSheetRequest.hpp"
#include "request/DescribeDeadLetterJobsByUserIdRequest.hpp"
#include "request/GetDeadLetterJobByUserIdRequest.hpp"
#include "request/DeleteDeadLetterJobByUserIdRequest.hpp"
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <cstring>

namespace gs2 { namespace jobQueue {

namespace {

void write(detail::json::JsonWriter& jsonWriter, const Namespace& obj);
void write(detail::json::JsonWriter& jsonWriter, const Job& obj);
void write(detail::json::JsonWriter& jsonWriter, const JobResult& obj);
void write(detail::json::JsonWriter& jsonWriter, const DeadLetterJob& obj);
void write(detail::json::JsonWriter& jsonWriter, const ResponseCache& obj);
void write(detail::json::JsonWriter& jsonWriter, const NotificationSetting& obj);
void write(detail::json::JsonWriter& jsonWriter, const LogSetting& obj);
void write(detail::json::JsonWriter& jsonWriter, const JobEntry& obj);
void write(detail::json::JsonWriter& jsonWriter, const JobResultBody& obj);

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
    if (obj.getPushNotification())
    {
        jsonWriter.writePropertyName("pushNotification");
        write(jsonWriter, *obj.getPushNotification());
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

void write(detail::json::JsonWriter& jsonWriter, const Job& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getJobId())
    {
        jsonWriter.writePropertyName("jobId");
        jsonWriter.writeCharArray(*obj.getJobId());
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
    if (obj.getScriptId())
    {
        jsonWriter.writePropertyName("scriptId");
        jsonWriter.writeCharArray(*obj.getScriptId());
    }
    if (obj.getArgs())
    {
        jsonWriter.writePropertyName("args");
        jsonWriter.writeCharArray(*obj.getArgs());
    }
    if (obj.getCurrentRetryCount())
    {
        jsonWriter.writePropertyName("currentRetryCount");
        jsonWriter.writeInt32(*obj.getCurrentRetryCount());
    }
    if (obj.getMaxTryCount())
    {
        jsonWriter.writePropertyName("maxTryCount");
        jsonWriter.writeInt32(*obj.getMaxTryCount());
    }
    if (obj.getIndex())
    {
        jsonWriter.writePropertyName("index");
        jsonWriter.writeDouble(*obj.getIndex());
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

void write(detail::json::JsonWriter& jsonWriter, const JobResult& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getJobResultId())
    {
        jsonWriter.writePropertyName("jobResultId");
        jsonWriter.writeCharArray(*obj.getJobResultId());
    }
    if (obj.getJobId())
    {
        jsonWriter.writePropertyName("jobId");
        jsonWriter.writeCharArray(*obj.getJobId());
    }
    if (obj.getTryNumber())
    {
        jsonWriter.writePropertyName("tryNumber");
        jsonWriter.writeInt32(*obj.getTryNumber());
    }
    if (obj.getStatusCode())
    {
        jsonWriter.writePropertyName("statusCode");
        jsonWriter.writeInt32(*obj.getStatusCode());
    }
    if (obj.getResult())
    {
        jsonWriter.writePropertyName("result");
        jsonWriter.writeCharArray(*obj.getResult());
    }
    if (obj.getTryAt())
    {
        jsonWriter.writePropertyName("tryAt");
        jsonWriter.writeInt64(*obj.getTryAt());
    }
    jsonWriter.writeObjectEnd();
}

void write(detail::json::JsonWriter& jsonWriter, const DeadLetterJob& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getDeadLetterJobId())
    {
        jsonWriter.writePropertyName("deadLetterJobId");
        jsonWriter.writeCharArray(*obj.getDeadLetterJobId());
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
    if (obj.getScriptId())
    {
        jsonWriter.writePropertyName("scriptId");
        jsonWriter.writeCharArray(*obj.getScriptId());
    }
    if (obj.getArgs())
    {
        jsonWriter.writePropertyName("args");
        jsonWriter.writeCharArray(*obj.getArgs());
    }
    if (obj.getResult())
    {
        jsonWriter.writePropertyName("result");
        jsonWriter.writeArrayStart();
        auto& list = *obj.getResult();
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

void write(detail::json::JsonWriter& jsonWriter, const NotificationSetting& obj)
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

void write(detail::json::JsonWriter& jsonWriter, const JobEntry& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getScriptId())
    {
        jsonWriter.writePropertyName("scriptId");
        jsonWriter.writeCharArray(*obj.getScriptId());
    }
    if (obj.getArgs())
    {
        jsonWriter.writePropertyName("args");
        jsonWriter.writeCharArray(*obj.getArgs());
    }
    if (obj.getMaxTryCount())
    {
        jsonWriter.writePropertyName("maxTryCount");
        jsonWriter.writeInt32(*obj.getMaxTryCount());
    }
    jsonWriter.writeObjectEnd();
}

void write(detail::json::JsonWriter& jsonWriter, const JobResultBody& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getTryNumber())
    {
        jsonWriter.writePropertyName("tryNumber");
        jsonWriter.writeInt32(*obj.getTryNumber());
    }
    if (obj.getStatusCode())
    {
        jsonWriter.writePropertyName("statusCode");
        jsonWriter.writeInt32(*obj.getStatusCode());
    }
    if (obj.getResult())
    {
        jsonWriter.writePropertyName("result");
        jsonWriter.writeCharArray(*obj.getResult());
    }
    if (obj.getTryAt())
    {
        jsonWriter.writePropertyName("tryAt");
        jsonWriter.writeInt64(*obj.getTryAt());
    }
    jsonWriter.writeObjectEnd();
}


class DescribeNamespacesTask : public detail::Gs2RestSessionTask<DescribeNamespacesResult>
{
private:
    DescribeNamespacesRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "job-queue";
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
        return "job-queue";
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
        if (m_Request.getPushNotification())
        {
            jsonWriter.writePropertyName("pushNotification");
            write(jsonWriter, *m_Request.getPushNotification());
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
        return "job-queue";
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
        return "job-queue";
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
        return "job-queue";
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
        if (m_Request.getPushNotification())
        {
            jsonWriter.writePropertyName("pushNotification");
            write(jsonWriter, *m_Request.getPushNotification());
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
        return "job-queue";
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

class DescribeJobsByUserIdTask : public detail::Gs2RestSessionTask<DescribeJobsByUserIdResult>
{
private:
    DescribeJobsByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "job-queue";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/user/{userId}/job";
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
    DescribeJobsByUserIdTask(
        DescribeJobsByUserIdRequest request,
        Gs2RestSessionTask<DescribeJobsByUserIdResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<DescribeJobsByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeJobsByUserIdTask() GS2_OVERRIDE = default;
};

class GetJobByUserIdTask : public detail::Gs2RestSessionTask<GetJobByUserIdResult>
{
private:
    GetJobByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "job-queue";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/user/{userId}/job/{jobName}";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getJobName();
            url.replace("{jobName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
    GetJobByUserIdTask(
        GetJobByUserIdRequest request,
        Gs2RestSessionTask<GetJobByUserIdResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<GetJobByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetJobByUserIdTask() GS2_OVERRIDE = default;
};

class PushByUserIdTask : public detail::Gs2RestSessionTask<PushByUserIdResult>
{
private:
    PushByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "job-queue";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/user/{userId}/job";
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
        if (m_Request.getJobs())
        {
            jsonWriter.writePropertyName("jobs");
            jsonWriter.writeArrayStart();
            auto& list = *m_Request.getJobs();
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
    PushByUserIdTask(
        PushByUserIdRequest request,
        Gs2RestSessionTask<PushByUserIdResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<PushByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~PushByUserIdTask() GS2_OVERRIDE = default;
};

class RunTask : public detail::Gs2RestSessionTask<RunResult>
{
private:
    RunRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "job-queue";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/user/me/job/run";
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
    RunTask(
        RunRequest request,
        Gs2RestSessionTask<RunResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<RunResult>(callback),
        m_Request(std::move(request))
    {}

    ~RunTask() GS2_OVERRIDE = default;
};

class RunByUserIdTask : public detail::Gs2RestSessionTask<RunByUserIdResult>
{
private:
    RunByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "job-queue";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/user/{userId}/job/run";
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
    RunByUserIdTask(
        RunByUserIdRequest request,
        Gs2RestSessionTask<RunByUserIdResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<RunByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~RunByUserIdTask() GS2_OVERRIDE = default;
};

class DeleteJobByUserIdTask : public detail::Gs2RestSessionTask<DeleteJobByUserIdResult>
{
private:
    DeleteJobByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "job-queue";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/user/{userId}/job/{jobName}";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getJobName();
            url.replace("{jobName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
    DeleteJobByUserIdTask(
        DeleteJobByUserIdRequest request,
        Gs2RestSessionTask<DeleteJobByUserIdResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<DeleteJobByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~DeleteJobByUserIdTask() GS2_OVERRIDE = default;
};

class PushByStampSheetTask : public detail::Gs2RestSessionTask<PushByStampSheetResult>
{
private:
    PushByStampSheetRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "job-queue";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/stamp/job";
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
    PushByStampSheetTask(
        PushByStampSheetRequest request,
        Gs2RestSessionTask<PushByStampSheetResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<PushByStampSheetResult>(callback),
        m_Request(std::move(request))
    {}

    ~PushByStampSheetTask() GS2_OVERRIDE = default;
};

class DescribeDeadLetterJobsByUserIdTask : public detail::Gs2RestSessionTask<DescribeDeadLetterJobsByUserIdResult>
{
private:
    DescribeDeadLetterJobsByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "job-queue";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/user/{userId}/dead";
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
    DescribeDeadLetterJobsByUserIdTask(
        DescribeDeadLetterJobsByUserIdRequest request,
        Gs2RestSessionTask<DescribeDeadLetterJobsByUserIdResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<DescribeDeadLetterJobsByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeDeadLetterJobsByUserIdTask() GS2_OVERRIDE = default;
};

class GetDeadLetterJobByUserIdTask : public detail::Gs2RestSessionTask<GetDeadLetterJobByUserIdResult>
{
private:
    GetDeadLetterJobByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "job-queue";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/user/{userId}/dead/{deadLetterJobName}";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getDeadLetterJobName();
            url.replace("{deadLetterJobName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
    GetDeadLetterJobByUserIdTask(
        GetDeadLetterJobByUserIdRequest request,
        Gs2RestSessionTask<GetDeadLetterJobByUserIdResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<GetDeadLetterJobByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetDeadLetterJobByUserIdTask() GS2_OVERRIDE = default;
};

class DeleteDeadLetterJobByUserIdTask : public detail::Gs2RestSessionTask<DeleteDeadLetterJobByUserIdResult>
{
private:
    DeleteDeadLetterJobByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "job-queue";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/user/{userId}/dead/{deadLetterJobName}";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getDeadLetterJobName();
            url.replace("{deadLetterJobName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
    DeleteDeadLetterJobByUserIdTask(
        DeleteDeadLetterJobByUserIdRequest request,
        Gs2RestSessionTask<DeleteDeadLetterJobByUserIdResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<DeleteDeadLetterJobByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~DeleteDeadLetterJobByUserIdTask() GS2_OVERRIDE = default;
};
}

/**
 * ネームスペースの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2JobQueueRestClient::describeNamespaces(DescribeNamespacesRequest request, std::function<void(AsyncDescribeNamespacesResult)> callback)
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
void Gs2JobQueueRestClient::createNamespace(CreateNamespaceRequest request, std::function<void(AsyncCreateNamespaceResult)> callback)
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
void Gs2JobQueueRestClient::getNamespaceStatus(GetNamespaceStatusRequest request, std::function<void(AsyncGetNamespaceStatusResult)> callback)
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
void Gs2JobQueueRestClient::getNamespace(GetNamespaceRequest request, std::function<void(AsyncGetNamespaceResult)> callback)
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
void Gs2JobQueueRestClient::updateNamespace(UpdateNamespaceRequest request, std::function<void(AsyncUpdateNamespaceResult)> callback)
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
void Gs2JobQueueRestClient::deleteNamespace(DeleteNamespaceRequest request, std::function<void(AsyncDeleteNamespaceResult)> callback)
{
    DeleteNamespaceTask& task = *new DeleteNamespaceTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * ジョブの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2JobQueueRestClient::describeJobsByUserId(DescribeJobsByUserIdRequest request, std::function<void(AsyncDescribeJobsByUserIdResult)> callback)
{
    DescribeJobsByUserIdTask& task = *new DescribeJobsByUserIdTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * ジョブを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2JobQueueRestClient::getJobByUserId(GetJobByUserIdRequest request, std::function<void(AsyncGetJobByUserIdResult)> callback)
{
    GetJobByUserIdTask& task = *new GetJobByUserIdTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * ユーザIDを指定してジョブを登録<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2JobQueueRestClient::pushByUserId(PushByUserIdRequest request, std::function<void(AsyncPushByUserIdResult)> callback)
{
    PushByUserIdTask& task = *new PushByUserIdTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * ジョブを実行<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2JobQueueRestClient::run(RunRequest request, std::function<void(AsyncRunResult)> callback)
{
    RunTask& task = *new RunTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * ユーザIDを指定してジョブを実行<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2JobQueueRestClient::runByUserId(RunByUserIdRequest request, std::function<void(AsyncRunByUserIdResult)> callback)
{
    RunByUserIdTask& task = *new RunByUserIdTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * ジョブを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2JobQueueRestClient::deleteJobByUserId(DeleteJobByUserIdRequest request, std::function<void(AsyncDeleteJobByUserIdResult)> callback)
{
    DeleteJobByUserIdTask& task = *new DeleteJobByUserIdTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * スタンプシートでジョブを登録<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2JobQueueRestClient::pushByStampSheet(PushByStampSheetRequest request, std::function<void(AsyncPushByStampSheetResult)> callback)
{
    PushByStampSheetTask& task = *new PushByStampSheetTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * デッドレタージョブの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2JobQueueRestClient::describeDeadLetterJobsByUserId(DescribeDeadLetterJobsByUserIdRequest request, std::function<void(AsyncDescribeDeadLetterJobsByUserIdResult)> callback)
{
    DescribeDeadLetterJobsByUserIdTask& task = *new DescribeDeadLetterJobsByUserIdTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * デッドレタージョブを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2JobQueueRestClient::getDeadLetterJobByUserId(GetDeadLetterJobByUserIdRequest request, std::function<void(AsyncGetDeadLetterJobByUserIdResult)> callback)
{
    GetDeadLetterJobByUserIdTask& task = *new GetDeadLetterJobByUserIdTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * デッドレタージョブを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2JobQueueRestClient::deleteDeadLetterJobByUserId(DeleteDeadLetterJobByUserIdRequest request, std::function<void(AsyncDeleteDeadLetterJobByUserIdResult)> callback)
{
    DeleteDeadLetterJobByUserIdTask& task = *new DeleteDeadLetterJobByUserIdTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

} }