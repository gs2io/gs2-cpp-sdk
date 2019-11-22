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

#include "Gs2DistributorRestClient.hpp"
#include "model/model.hpp"
#include "request/DescribeNamespacesRequest.hpp"
#include "request/CreateNamespaceRequest.hpp"
#include "request/GetNamespaceStatusRequest.hpp"
#include "request/GetNamespaceRequest.hpp"
#include "request/UpdateNamespaceRequest.hpp"
#include "request/DeleteNamespaceRequest.hpp"
#include "request/DescribeDistributorModelMastersRequest.hpp"
#include "request/CreateDistributorModelMasterRequest.hpp"
#include "request/GetDistributorModelMasterRequest.hpp"
#include "request/UpdateDistributorModelMasterRequest.hpp"
#include "request/DeleteDistributorModelMasterRequest.hpp"
#include "request/DescribeDistributorModelsRequest.hpp"
#include "request/GetDistributorModelRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentDistributorMasterRequest.hpp"
#include "request/UpdateCurrentDistributorMasterRequest.hpp"
#include "request/UpdateCurrentDistributorMasterFromGitHubRequest.hpp"
#include "request/DistributeRequest.hpp"
#include "request/RunStampTaskRequest.hpp"
#include "request/RunStampSheetRequest.hpp"
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <cstring>

namespace gs2 { namespace distributor {

namespace {

void write(detail::json::JsonWriter& jsonWriter, const Namespace& obj);
void write(detail::json::JsonWriter& jsonWriter, const DistributorModelMaster& obj);
void write(detail::json::JsonWriter& jsonWriter, const DistributorModel& obj);
void write(detail::json::JsonWriter& jsonWriter, const CurrentDistributorMaster& obj);
void write(detail::json::JsonWriter& jsonWriter, const ResponseCache& obj);
void write(detail::json::JsonWriter& jsonWriter, const GitHubCheckoutSetting& obj);
void write(detail::json::JsonWriter& jsonWriter, const DistributeResource& obj);
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
    if (obj.getAssumeUserId())
    {
        jsonWriter.writePropertyName("assumeUserId");
        jsonWriter.writeCharArray(*obj.getAssumeUserId());
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

void write(detail::json::JsonWriter& jsonWriter, const DistributorModelMaster& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getDistributorModelId())
    {
        jsonWriter.writePropertyName("distributorModelId");
        jsonWriter.writeCharArray(*obj.getDistributorModelId());
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
    if (obj.getInboxNamespaceId())
    {
        jsonWriter.writePropertyName("inboxNamespaceId");
        jsonWriter.writeCharArray(*obj.getInboxNamespaceId());
    }
    if (obj.getWhiteListTargetIds())
    {
        jsonWriter.writePropertyName("whiteListTargetIds");
        jsonWriter.writeArrayStart();
        auto& list = *obj.getWhiteListTargetIds();
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

void write(detail::json::JsonWriter& jsonWriter, const DistributorModel& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getDistributorModelId())
    {
        jsonWriter.writePropertyName("distributorModelId");
        jsonWriter.writeCharArray(*obj.getDistributorModelId());
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
    if (obj.getInboxNamespaceId())
    {
        jsonWriter.writePropertyName("inboxNamespaceId");
        jsonWriter.writeCharArray(*obj.getInboxNamespaceId());
    }
    if (obj.getWhiteListTargetIds())
    {
        jsonWriter.writePropertyName("whiteListTargetIds");
        jsonWriter.writeArrayStart();
        auto& list = *obj.getWhiteListTargetIds();
        for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
        {
            jsonWriter.writeCharArray(list[i]);
        }
        jsonWriter.writeArrayEnd();
    }
    jsonWriter.writeObjectEnd();
}

void write(detail::json::JsonWriter& jsonWriter, const CurrentDistributorMaster& obj)
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

void write(detail::json::JsonWriter& jsonWriter, const DistributeResource& obj)
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
        return "distributor";
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
        return "distributor";
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
        if (m_Request.getAssumeUserId())
        {
            jsonWriter.writePropertyName("assumeUserId");
            jsonWriter.writeCharArray(*m_Request.getAssumeUserId());
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
        return "distributor";
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
        return "distributor";
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
        return "distributor";
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
        if (m_Request.getAssumeUserId())
        {
            jsonWriter.writePropertyName("assumeUserId");
            jsonWriter.writeCharArray(*m_Request.getAssumeUserId());
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
        return "distributor";
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

class DescribeDistributorModelMastersTask : public detail::Gs2RestSessionTask<DescribeDistributorModelMastersResult>
{
private:
    DescribeDistributorModelMastersRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "distributor";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/master/distributor";
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
    DescribeDistributorModelMastersTask(
        DescribeDistributorModelMastersRequest request,
        Gs2RestSessionTask<DescribeDistributorModelMastersResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<DescribeDistributorModelMastersResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeDistributorModelMastersTask() GS2_OVERRIDE = default;
};

class CreateDistributorModelMasterTask : public detail::Gs2RestSessionTask<CreateDistributorModelMasterResult>
{
private:
    CreateDistributorModelMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "distributor";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/master/distributor";
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
        if (m_Request.getInboxNamespaceId())
        {
            jsonWriter.writePropertyName("inboxNamespaceId");
            jsonWriter.writeCharArray(*m_Request.getInboxNamespaceId());
        }
        if (m_Request.getWhiteListTargetIds())
        {
            jsonWriter.writePropertyName("whiteListTargetIds");
            jsonWriter.writeArrayStart();
            auto& list = *m_Request.getWhiteListTargetIds();
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

        return detail::Gs2HttpTask::Verb::Post;
    }

public:
    CreateDistributorModelMasterTask(
        CreateDistributorModelMasterRequest request,
        Gs2RestSessionTask<CreateDistributorModelMasterResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<CreateDistributorModelMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~CreateDistributorModelMasterTask() GS2_OVERRIDE = default;
};

class GetDistributorModelMasterTask : public detail::Gs2RestSessionTask<GetDistributorModelMasterResult>
{
private:
    GetDistributorModelMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "distributor";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/master/distributor/{distributorName}";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getDistributorName();
            url.replace("{distributorName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
    GetDistributorModelMasterTask(
        GetDistributorModelMasterRequest request,
        Gs2RestSessionTask<GetDistributorModelMasterResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<GetDistributorModelMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetDistributorModelMasterTask() GS2_OVERRIDE = default;
};

class UpdateDistributorModelMasterTask : public detail::Gs2RestSessionTask<UpdateDistributorModelMasterResult>
{
private:
    UpdateDistributorModelMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "distributor";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/master/distributor/{distributorName}";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getDistributorName();
            url.replace("{distributorName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        if (m_Request.getInboxNamespaceId())
        {
            jsonWriter.writePropertyName("inboxNamespaceId");
            jsonWriter.writeCharArray(*m_Request.getInboxNamespaceId());
        }
        if (m_Request.getWhiteListTargetIds())
        {
            jsonWriter.writePropertyName("whiteListTargetIds");
            jsonWriter.writeArrayStart();
            auto& list = *m_Request.getWhiteListTargetIds();
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

        return detail::Gs2HttpTask::Verb::Put;
    }

public:
    UpdateDistributorModelMasterTask(
        UpdateDistributorModelMasterRequest request,
        Gs2RestSessionTask<UpdateDistributorModelMasterResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<UpdateDistributorModelMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~UpdateDistributorModelMasterTask() GS2_OVERRIDE = default;
};

class DeleteDistributorModelMasterTask : public detail::Gs2RestSessionTask<DeleteDistributorModelMasterResult>
{
private:
    DeleteDistributorModelMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "distributor";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/master/distributor/{distributorName}";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getDistributorName();
            url.replace("{distributorName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
    DeleteDistributorModelMasterTask(
        DeleteDistributorModelMasterRequest request,
        Gs2RestSessionTask<DeleteDistributorModelMasterResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<DeleteDistributorModelMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~DeleteDistributorModelMasterTask() GS2_OVERRIDE = default;
};

class DescribeDistributorModelsTask : public detail::Gs2RestSessionTask<DescribeDistributorModelsResult>
{
private:
    DescribeDistributorModelsRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "distributor";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/distributor";
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
    DescribeDistributorModelsTask(
        DescribeDistributorModelsRequest request,
        Gs2RestSessionTask<DescribeDistributorModelsResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<DescribeDistributorModelsResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeDistributorModelsTask() GS2_OVERRIDE = default;
};

class GetDistributorModelTask : public detail::Gs2RestSessionTask<GetDistributorModelResult>
{
private:
    GetDistributorModelRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "distributor";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/distributor/{distributorName}";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getDistributorName();
            url.replace("{distributorName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
    GetDistributorModelTask(
        GetDistributorModelRequest request,
        Gs2RestSessionTask<GetDistributorModelResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<GetDistributorModelResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetDistributorModelTask() GS2_OVERRIDE = default;
};

class ExportMasterTask : public detail::Gs2RestSessionTask<ExportMasterResult>
{
private:
    ExportMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "distributor";
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

class GetCurrentDistributorMasterTask : public detail::Gs2RestSessionTask<GetCurrentDistributorMasterResult>
{
private:
    GetCurrentDistributorMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "distributor";
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
    GetCurrentDistributorMasterTask(
        GetCurrentDistributorMasterRequest request,
        Gs2RestSessionTask<GetCurrentDistributorMasterResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<GetCurrentDistributorMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetCurrentDistributorMasterTask() GS2_OVERRIDE = default;
};

class UpdateCurrentDistributorMasterTask : public detail::Gs2RestSessionTask<UpdateCurrentDistributorMasterResult>
{
private:
    UpdateCurrentDistributorMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "distributor";
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
    UpdateCurrentDistributorMasterTask(
        UpdateCurrentDistributorMasterRequest request,
        Gs2RestSessionTask<UpdateCurrentDistributorMasterResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<UpdateCurrentDistributorMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~UpdateCurrentDistributorMasterTask() GS2_OVERRIDE = default;
};

class UpdateCurrentDistributorMasterFromGitHubTask : public detail::Gs2RestSessionTask<UpdateCurrentDistributorMasterFromGitHubResult>
{
private:
    UpdateCurrentDistributorMasterFromGitHubRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "distributor";
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
    UpdateCurrentDistributorMasterFromGitHubTask(
        UpdateCurrentDistributorMasterFromGitHubRequest request,
        Gs2RestSessionTask<UpdateCurrentDistributorMasterFromGitHubResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<UpdateCurrentDistributorMasterFromGitHubResult>(callback),
        m_Request(std::move(request))
    {}

    ~UpdateCurrentDistributorMasterFromGitHubTask() GS2_OVERRIDE = default;
};

class DistributeTask : public detail::Gs2RestSessionTask<DistributeResult>
{
private:
    DistributeRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "distributor";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/distribute";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getDistributorName();
            url.replace("{distributorName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        detail::json::JsonWriter jsonWriter;

        jsonWriter.writeObjectStart();
        if (m_Request.getContextStack())
        {
            jsonWriter.writePropertyName("contextStack");
            jsonWriter.writeCharArray(*m_Request.getContextStack());
        }
        if (m_Request.getDistributeResource())
        {
            jsonWriter.writePropertyName("distributeResource");
            write(jsonWriter, *m_Request.getDistributeResource());
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
    DistributeTask(
        DistributeRequest request,
        Gs2RestSessionTask<DistributeResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<DistributeResult>(callback),
        m_Request(std::move(request))
    {}

    ~DistributeTask() GS2_OVERRIDE = default;
};

class RunStampTaskTask : public detail::Gs2RestSessionTask<RunStampTaskResult>
{
private:
    RunStampTaskRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "distributor";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/distribute/stamp/task/run";
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
    RunStampTaskTask(
        RunStampTaskRequest request,
        Gs2RestSessionTask<RunStampTaskResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<RunStampTaskResult>(callback),
        m_Request(std::move(request))
    {}

    ~RunStampTaskTask() GS2_OVERRIDE = default;
};

class RunStampSheetTask : public detail::Gs2RestSessionTask<RunStampSheetResult>
{
private:
    RunStampSheetRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "distributor";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/distribute/stamp/sheet/run";
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
    RunStampSheetTask(
        RunStampSheetRequest request,
        Gs2RestSessionTask<RunStampSheetResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<RunStampSheetResult>(callback),
        m_Request(std::move(request))
    {}

    ~RunStampSheetTask() GS2_OVERRIDE = default;
};
}

/**
 * ネームスペースの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2DistributorRestClient::describeNamespaces(DescribeNamespacesRequest request, std::function<void(AsyncDescribeNamespacesResult)> callback)
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
void Gs2DistributorRestClient::createNamespace(CreateNamespaceRequest request, std::function<void(AsyncCreateNamespaceResult)> callback)
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
void Gs2DistributorRestClient::getNamespaceStatus(GetNamespaceStatusRequest request, std::function<void(AsyncGetNamespaceStatusResult)> callback)
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
void Gs2DistributorRestClient::getNamespace(GetNamespaceRequest request, std::function<void(AsyncGetNamespaceResult)> callback)
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
void Gs2DistributorRestClient::updateNamespace(UpdateNamespaceRequest request, std::function<void(AsyncUpdateNamespaceResult)> callback)
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
void Gs2DistributorRestClient::deleteNamespace(DeleteNamespaceRequest request, std::function<void(AsyncDeleteNamespaceResult)> callback)
{
    DeleteNamespaceTask& task = *new DeleteNamespaceTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * 配信設定マスターの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2DistributorRestClient::describeDistributorModelMasters(DescribeDistributorModelMastersRequest request, std::function<void(AsyncDescribeDistributorModelMastersResult)> callback)
{
    DescribeDistributorModelMastersTask& task = *new DescribeDistributorModelMastersTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * 配信設定マスターを新規作成<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2DistributorRestClient::createDistributorModelMaster(CreateDistributorModelMasterRequest request, std::function<void(AsyncCreateDistributorModelMasterResult)> callback)
{
    CreateDistributorModelMasterTask& task = *new CreateDistributorModelMasterTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * 配信設定マスターを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2DistributorRestClient::getDistributorModelMaster(GetDistributorModelMasterRequest request, std::function<void(AsyncGetDistributorModelMasterResult)> callback)
{
    GetDistributorModelMasterTask& task = *new GetDistributorModelMasterTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * 配信設定マスターを更新<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2DistributorRestClient::updateDistributorModelMaster(UpdateDistributorModelMasterRequest request, std::function<void(AsyncUpdateDistributorModelMasterResult)> callback)
{
    UpdateDistributorModelMasterTask& task = *new UpdateDistributorModelMasterTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * 配信設定マスターを削除<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2DistributorRestClient::deleteDistributorModelMaster(DeleteDistributorModelMasterRequest request, std::function<void(AsyncDeleteDistributorModelMasterResult)> callback)
{
    DeleteDistributorModelMasterTask& task = *new DeleteDistributorModelMasterTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * 配信設定の一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2DistributorRestClient::describeDistributorModels(DescribeDistributorModelsRequest request, std::function<void(AsyncDescribeDistributorModelsResult)> callback)
{
    DescribeDistributorModelsTask& task = *new DescribeDistributorModelsTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * 配信設定を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2DistributorRestClient::getDistributorModel(GetDistributorModelRequest request, std::function<void(AsyncGetDistributorModelResult)> callback)
{
    GetDistributorModelTask& task = *new GetDistributorModelTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * 現在有効な配信設定のマスターデータをエクスポートします<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2DistributorRestClient::exportMaster(ExportMasterRequest request, std::function<void(AsyncExportMasterResult)> callback)
{
    ExportMasterTask& task = *new ExportMasterTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * 現在有効な配信設定を取得します<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2DistributorRestClient::getCurrentDistributorMaster(GetCurrentDistributorMasterRequest request, std::function<void(AsyncGetCurrentDistributorMasterResult)> callback)
{
    GetCurrentDistributorMasterTask& task = *new GetCurrentDistributorMasterTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * 現在有効な配信設定を更新します<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2DistributorRestClient::updateCurrentDistributorMaster(UpdateCurrentDistributorMasterRequest request, std::function<void(AsyncUpdateCurrentDistributorMasterResult)> callback)
{
    UpdateCurrentDistributorMasterTask& task = *new UpdateCurrentDistributorMasterTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * 現在有効な配信設定を更新します<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2DistributorRestClient::updateCurrentDistributorMasterFromGitHub(UpdateCurrentDistributorMasterFromGitHubRequest request, std::function<void(AsyncUpdateCurrentDistributorMasterFromGitHubResult)> callback)
{
    UpdateCurrentDistributorMasterFromGitHubTask& task = *new UpdateCurrentDistributorMasterFromGitHubTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * 所持品を配布する<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2DistributorRestClient::distribute(DistributeRequest request, std::function<void(AsyncDistributeResult)> callback)
{
    DistributeTask& task = *new DistributeTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * スタンプシートのタスクを実行する<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2DistributorRestClient::runStampTask(RunStampTaskRequest request, std::function<void(AsyncRunStampTaskResult)> callback)
{
    RunStampTaskTask& task = *new RunStampTaskTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * スタンプシートの完了を報告する<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2DistributorRestClient::runStampSheet(RunStampSheetRequest request, std::function<void(AsyncRunStampSheetResult)> callback)
{
    RunStampSheetTask& task = *new RunStampSheetTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

} }