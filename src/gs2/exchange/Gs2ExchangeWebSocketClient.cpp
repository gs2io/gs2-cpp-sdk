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

#include "Gs2ExchangeWebSocketClient.hpp"
#include "model/model.hpp"
#include "request/DescribeNamespacesRequest.hpp"
#include "request/CreateNamespaceRequest.hpp"
#include "request/GetNamespaceStatusRequest.hpp"
#include "request/GetNamespaceRequest.hpp"
#include "request/UpdateNamespaceRequest.hpp"
#include "request/DeleteNamespaceRequest.hpp"
#include "request/DescribeRateModelsRequest.hpp"
#include "request/GetRateModelRequest.hpp"
#include "request/DescribeRateModelMastersRequest.hpp"
#include "request/CreateRateModelMasterRequest.hpp"
#include "request/GetRateModelMasterRequest.hpp"
#include "request/UpdateRateModelMasterRequest.hpp"
#include "request/DeleteRateModelMasterRequest.hpp"
#include "request/ExchangeRequest.hpp"
#include "request/ExchangeByUserIdRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentRateMasterRequest.hpp"
#include "request/UpdateCurrentRateMasterRequest.hpp"
#include "request/UpdateCurrentRateMasterFromGitHubRequest.hpp"
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <cstring>

namespace gs2 { namespace exchange {

namespace {

void write(detail::json::JsonWriter& jsonWriter, const Namespace& obj);
void write(detail::json::JsonWriter& jsonWriter, const RateModel& obj);
void write(detail::json::JsonWriter& jsonWriter, const RateModelMaster& obj);
void write(detail::json::JsonWriter& jsonWriter, const CurrentRateMaster& obj);
void write(detail::json::JsonWriter& jsonWriter, const ResponseCache& obj);
void write(detail::json::JsonWriter& jsonWriter, const Config& obj);
void write(detail::json::JsonWriter& jsonWriter, const GitHubCheckoutSetting& obj);
void write(detail::json::JsonWriter& jsonWriter, const LogSetting& obj);
void write(detail::json::JsonWriter& jsonWriter, const AcquireAction& obj);
void write(detail::json::JsonWriter& jsonWriter, const ConsumeAction& obj);

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

void write(detail::json::JsonWriter& jsonWriter, const RateModel& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getRateModelId())
    {
        jsonWriter.writePropertyName("rateModelId");
        jsonWriter.writeCharArray(*obj.getRateModelId());
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
    if (obj.getConsumeActions())
    {
        jsonWriter.writePropertyName("consumeActions");
        jsonWriter.writeArrayStart();
        auto& list = *obj.getConsumeActions();
        for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
        {
            write(jsonWriter, list[i]);
        }
        jsonWriter.writeArrayEnd();
    }
    if (obj.getAcquireActions())
    {
        jsonWriter.writePropertyName("acquireActions");
        jsonWriter.writeArrayStart();
        auto& list = *obj.getAcquireActions();
        for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
        {
            write(jsonWriter, list[i]);
        }
        jsonWriter.writeArrayEnd();
    }
    jsonWriter.writeObjectEnd();
}

void write(detail::json::JsonWriter& jsonWriter, const RateModelMaster& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getRateModelId())
    {
        jsonWriter.writePropertyName("rateModelId");
        jsonWriter.writeCharArray(*obj.getRateModelId());
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
    if (obj.getConsumeActions())
    {
        jsonWriter.writePropertyName("consumeActions");
        jsonWriter.writeArrayStart();
        auto& list = *obj.getConsumeActions();
        for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
        {
            write(jsonWriter, list[i]);
        }
        jsonWriter.writeArrayEnd();
    }
    if (obj.getAcquireActions())
    {
        jsonWriter.writePropertyName("acquireActions");
        jsonWriter.writeArrayStart();
        auto& list = *obj.getAcquireActions();
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

void write(detail::json::JsonWriter& jsonWriter, const CurrentRateMaster& obj)
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

void write(detail::json::JsonWriter& jsonWriter, const Config& obj)
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

void write(detail::json::JsonWriter& jsonWriter, const AcquireAction& obj)
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

void write(detail::json::JsonWriter& jsonWriter, const ConsumeAction& obj)
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


class DescribeNamespacesTask : public detail::Gs2WebSocketSessionTask<DescribeNamespacesResult>
{
private:
    DescribeNamespacesRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "exchange";
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
        return "exchange";
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
        return "exchange";
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
        return "exchange";
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
        return "exchange";
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
        return "exchange";
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

class DescribeRateModelsTask : public detail::Gs2WebSocketSessionTask<DescribeRateModelsResult>
{
private:
    DescribeRateModelsRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "exchange";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "rateModel";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "describeRateModels";
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
    DescribeRateModelsTask(
        DescribeRateModelsRequest request,
        Gs2WebSocketSessionTask<DescribeRateModelsResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DescribeRateModelsResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeRateModelsTask() GS2_OVERRIDE = default;
};

class GetRateModelTask : public detail::Gs2WebSocketSessionTask<GetRateModelResult>
{
private:
    GetRateModelRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "exchange";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "rateModel";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "getRateModel";
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
        if (m_Request.getRateName())
        {
            jsonWriter.writePropertyName("rateName");
            jsonWriter.writeCharArray(*m_Request.getRateName());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    GetRateModelTask(
        GetRateModelRequest request,
        Gs2WebSocketSessionTask<GetRateModelResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<GetRateModelResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetRateModelTask() GS2_OVERRIDE = default;
};

class DescribeRateModelMastersTask : public detail::Gs2WebSocketSessionTask<DescribeRateModelMastersResult>
{
private:
    DescribeRateModelMastersRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "exchange";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "rateModelMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "describeRateModelMasters";
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
    DescribeRateModelMastersTask(
        DescribeRateModelMastersRequest request,
        Gs2WebSocketSessionTask<DescribeRateModelMastersResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DescribeRateModelMastersResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeRateModelMastersTask() GS2_OVERRIDE = default;
};

class CreateRateModelMasterTask : public detail::Gs2WebSocketSessionTask<CreateRateModelMasterResult>
{
private:
    CreateRateModelMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "exchange";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "rateModelMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "createRateModelMaster";
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
        if (m_Request.getAcquireActions())
        {
            jsonWriter.writePropertyName("acquireActions");
            jsonWriter.writeArrayStart();
            auto& list = *m_Request.getAcquireActions();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (m_Request.getConsumeActions())
        {
            jsonWriter.writePropertyName("consumeActions");
            jsonWriter.writeArrayStart();
            auto& list = *m_Request.getConsumeActions();
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
    CreateRateModelMasterTask(
        CreateRateModelMasterRequest request,
        Gs2WebSocketSessionTask<CreateRateModelMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<CreateRateModelMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~CreateRateModelMasterTask() GS2_OVERRIDE = default;
};

class GetRateModelMasterTask : public detail::Gs2WebSocketSessionTask<GetRateModelMasterResult>
{
private:
    GetRateModelMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "exchange";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "rateModelMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "getRateModelMaster";
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
        if (m_Request.getRateName())
        {
            jsonWriter.writePropertyName("rateName");
            jsonWriter.writeCharArray(*m_Request.getRateName());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    GetRateModelMasterTask(
        GetRateModelMasterRequest request,
        Gs2WebSocketSessionTask<GetRateModelMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<GetRateModelMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetRateModelMasterTask() GS2_OVERRIDE = default;
};

class UpdateRateModelMasterTask : public detail::Gs2WebSocketSessionTask<UpdateRateModelMasterResult>
{
private:
    UpdateRateModelMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "exchange";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "rateModelMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "updateRateModelMaster";
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
        if (m_Request.getRateName())
        {
            jsonWriter.writePropertyName("rateName");
            jsonWriter.writeCharArray(*m_Request.getRateName());
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
        if (m_Request.getAcquireActions())
        {
            jsonWriter.writePropertyName("acquireActions");
            jsonWriter.writeArrayStart();
            auto& list = *m_Request.getAcquireActions();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (m_Request.getConsumeActions())
        {
            jsonWriter.writePropertyName("consumeActions");
            jsonWriter.writeArrayStart();
            auto& list = *m_Request.getConsumeActions();
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
    UpdateRateModelMasterTask(
        UpdateRateModelMasterRequest request,
        Gs2WebSocketSessionTask<UpdateRateModelMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<UpdateRateModelMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~UpdateRateModelMasterTask() GS2_OVERRIDE = default;
};

class DeleteRateModelMasterTask : public detail::Gs2WebSocketSessionTask<DeleteRateModelMasterResult>
{
private:
    DeleteRateModelMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "exchange";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "rateModelMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "deleteRateModelMaster";
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
        if (m_Request.getRateName())
        {
            jsonWriter.writePropertyName("rateName");
            jsonWriter.writeCharArray(*m_Request.getRateName());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    DeleteRateModelMasterTask(
        DeleteRateModelMasterRequest request,
        Gs2WebSocketSessionTask<DeleteRateModelMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DeleteRateModelMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~DeleteRateModelMasterTask() GS2_OVERRIDE = default;
};

class ExchangeTask : public detail::Gs2WebSocketSessionTask<ExchangeResult>
{
private:
    ExchangeRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "exchange";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "exchange";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "exchange";
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
        if (m_Request.getRateName())
        {
            jsonWriter.writePropertyName("rateName");
            jsonWriter.writeCharArray(*m_Request.getRateName());
        }
        if (m_Request.getCount())
        {
            jsonWriter.writePropertyName("count");
            jsonWriter.writeInt32(*m_Request.getCount());
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
    ExchangeTask(
        ExchangeRequest request,
        Gs2WebSocketSessionTask<ExchangeResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<ExchangeResult>(callback),
        m_Request(std::move(request))
    {}

    ~ExchangeTask() GS2_OVERRIDE = default;
};

class ExchangeByUserIdTask : public detail::Gs2WebSocketSessionTask<ExchangeByUserIdResult>
{
private:
    ExchangeByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "exchange";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "exchange";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "exchangeByUserId";
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
        if (m_Request.getRateName())
        {
            jsonWriter.writePropertyName("rateName");
            jsonWriter.writeCharArray(*m_Request.getRateName());
        }
        if (m_Request.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*m_Request.getUserId());
        }
        if (m_Request.getCount())
        {
            jsonWriter.writePropertyName("count");
            jsonWriter.writeInt32(*m_Request.getCount());
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
    ExchangeByUserIdTask(
        ExchangeByUserIdRequest request,
        Gs2WebSocketSessionTask<ExchangeByUserIdResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<ExchangeByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~ExchangeByUserIdTask() GS2_OVERRIDE = default;
};

class ExportMasterTask : public detail::Gs2WebSocketSessionTask<ExportMasterResult>
{
private:
    ExportMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "exchange";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "currentRateMaster";
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

class GetCurrentRateMasterTask : public detail::Gs2WebSocketSessionTask<GetCurrentRateMasterResult>
{
private:
    GetCurrentRateMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "exchange";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "currentRateMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "getCurrentRateMaster";
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
    GetCurrentRateMasterTask(
        GetCurrentRateMasterRequest request,
        Gs2WebSocketSessionTask<GetCurrentRateMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<GetCurrentRateMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetCurrentRateMasterTask() GS2_OVERRIDE = default;
};

class UpdateCurrentRateMasterTask : public detail::Gs2WebSocketSessionTask<UpdateCurrentRateMasterResult>
{
private:
    UpdateCurrentRateMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "exchange";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "currentRateMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "updateCurrentRateMaster";
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
    UpdateCurrentRateMasterTask(
        UpdateCurrentRateMasterRequest request,
        Gs2WebSocketSessionTask<UpdateCurrentRateMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<UpdateCurrentRateMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~UpdateCurrentRateMasterTask() GS2_OVERRIDE = default;
};

class UpdateCurrentRateMasterFromGitHubTask : public detail::Gs2WebSocketSessionTask<UpdateCurrentRateMasterFromGitHubResult>
{
private:
    UpdateCurrentRateMasterFromGitHubRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "exchange";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "currentRateMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "updateCurrentRateMasterFromGitHub";
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
    UpdateCurrentRateMasterFromGitHubTask(
        UpdateCurrentRateMasterFromGitHubRequest request,
        Gs2WebSocketSessionTask<UpdateCurrentRateMasterFromGitHubResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<UpdateCurrentRateMasterFromGitHubResult>(callback),
        m_Request(std::move(request))
    {}

    ~UpdateCurrentRateMasterFromGitHubTask() GS2_OVERRIDE = default;
};
}

/**
 * ネームスペースの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2ExchangeWebSocketClient::describeNamespaces(DescribeNamespacesRequest request, std::function<void(AsyncDescribeNamespacesResult)> callback)
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
void Gs2ExchangeWebSocketClient::createNamespace(CreateNamespaceRequest request, std::function<void(AsyncCreateNamespaceResult)> callback)
{
    CreateNamespaceTask& task = *new CreateNamespaceTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ネームスペースを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2ExchangeWebSocketClient::getNamespaceStatus(GetNamespaceStatusRequest request, std::function<void(AsyncGetNamespaceStatusResult)> callback)
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
void Gs2ExchangeWebSocketClient::getNamespace(GetNamespaceRequest request, std::function<void(AsyncGetNamespaceResult)> callback)
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
void Gs2ExchangeWebSocketClient::updateNamespace(UpdateNamespaceRequest request, std::function<void(AsyncUpdateNamespaceResult)> callback)
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
void Gs2ExchangeWebSocketClient::deleteNamespace(DeleteNamespaceRequest request, std::function<void(AsyncDeleteNamespaceResult)> callback)
{
    DeleteNamespaceTask& task = *new DeleteNamespaceTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 交換レートモデルの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2ExchangeWebSocketClient::describeRateModels(DescribeRateModelsRequest request, std::function<void(AsyncDescribeRateModelsResult)> callback)
{
    DescribeRateModelsTask& task = *new DescribeRateModelsTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 交換レートモデルを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2ExchangeWebSocketClient::getRateModel(GetRateModelRequest request, std::function<void(AsyncGetRateModelResult)> callback)
{
    GetRateModelTask& task = *new GetRateModelTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 交換レートマスターの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2ExchangeWebSocketClient::describeRateModelMasters(DescribeRateModelMastersRequest request, std::function<void(AsyncDescribeRateModelMastersResult)> callback)
{
    DescribeRateModelMastersTask& task = *new DescribeRateModelMastersTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 交換レートマスターを新規作成<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2ExchangeWebSocketClient::createRateModelMaster(CreateRateModelMasterRequest request, std::function<void(AsyncCreateRateModelMasterResult)> callback)
{
    CreateRateModelMasterTask& task = *new CreateRateModelMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 交換レートマスターを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2ExchangeWebSocketClient::getRateModelMaster(GetRateModelMasterRequest request, std::function<void(AsyncGetRateModelMasterResult)> callback)
{
    GetRateModelMasterTask& task = *new GetRateModelMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 交換レートマスターを更新<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2ExchangeWebSocketClient::updateRateModelMaster(UpdateRateModelMasterRequest request, std::function<void(AsyncUpdateRateModelMasterResult)> callback)
{
    UpdateRateModelMasterTask& task = *new UpdateRateModelMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 交換レートマスターを削除<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2ExchangeWebSocketClient::deleteRateModelMaster(DeleteRateModelMasterRequest request, std::function<void(AsyncDeleteRateModelMasterResult)> callback)
{
    DeleteRateModelMasterTask& task = *new DeleteRateModelMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 交換を実行<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2ExchangeWebSocketClient::exchange(ExchangeRequest request, std::function<void(AsyncExchangeResult)> callback)
{
    ExchangeTask& task = *new ExchangeTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ユーザIDを指定して交換を実行<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2ExchangeWebSocketClient::exchangeByUserId(ExchangeByUserIdRequest request, std::function<void(AsyncExchangeByUserIdResult)> callback)
{
    ExchangeByUserIdTask& task = *new ExchangeByUserIdTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 現在有効な交換レート設定のマスターデータをエクスポートします<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2ExchangeWebSocketClient::exportMaster(ExportMasterRequest request, std::function<void(AsyncExportMasterResult)> callback)
{
    ExportMasterTask& task = *new ExportMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 現在有効な交換レート設定を取得します<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2ExchangeWebSocketClient::getCurrentRateMaster(GetCurrentRateMasterRequest request, std::function<void(AsyncGetCurrentRateMasterResult)> callback)
{
    GetCurrentRateMasterTask& task = *new GetCurrentRateMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 現在有効な交換レート設定を更新します<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2ExchangeWebSocketClient::updateCurrentRateMaster(UpdateCurrentRateMasterRequest request, std::function<void(AsyncUpdateCurrentRateMasterResult)> callback)
{
    UpdateCurrentRateMasterTask& task = *new UpdateCurrentRateMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 現在有効な交換レート設定を更新します<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2ExchangeWebSocketClient::updateCurrentRateMasterFromGitHub(UpdateCurrentRateMasterFromGitHubRequest request, std::function<void(AsyncUpdateCurrentRateMasterFromGitHubResult)> callback)
{
    UpdateCurrentRateMasterFromGitHubTask& task = *new UpdateCurrentRateMasterFromGitHubTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

} }