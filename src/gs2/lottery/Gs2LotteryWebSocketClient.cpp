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

#include "Gs2LotteryWebSocketClient.hpp"
#include "model/model.hpp"
#include "request/DescribeNamespacesRequest.hpp"
#include "request/CreateNamespaceRequest.hpp"
#include "request/GetNamespaceStatusRequest.hpp"
#include "request/GetNamespaceRequest.hpp"
#include "request/UpdateNamespaceRequest.hpp"
#include "request/DeleteNamespaceRequest.hpp"
#include "request/DescribeLotteryModelMastersRequest.hpp"
#include "request/CreateLotteryModelMasterRequest.hpp"
#include "request/GetLotteryModelMasterRequest.hpp"
#include "request/UpdateLotteryModelMasterRequest.hpp"
#include "request/DeleteLotteryModelMasterRequest.hpp"
#include "request/DescribePrizeTableMastersRequest.hpp"
#include "request/CreatePrizeTableMasterRequest.hpp"
#include "request/GetPrizeTableMasterRequest.hpp"
#include "request/UpdatePrizeTableMasterRequest.hpp"
#include "request/DeletePrizeTableMasterRequest.hpp"
#include "request/DescribeBoxesRequest.hpp"
#include "request/DescribeBoxesByUserIdRequest.hpp"
#include "request/GetBoxRequest.hpp"
#include "request/GetBoxByUserIdRequest.hpp"
#include "request/ResetBoxRequest.hpp"
#include "request/ResetBoxByUserIdRequest.hpp"
#include "request/DescribeLotteryModelsRequest.hpp"
#include "request/GetLotteryModelRequest.hpp"
#include "request/DescribePrizeTablesRequest.hpp"
#include "request/GetPrizeTableRequest.hpp"
#include "request/DrawByUserIdRequest.hpp"
#include "request/DescribeProbabilitiesRequest.hpp"
#include "request/DescribeProbabilitiesByUserIdRequest.hpp"
#include "request/DrawByStampSheetRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentLotteryMasterRequest.hpp"
#include "request/UpdateCurrentLotteryMasterRequest.hpp"
#include "request/UpdateCurrentLotteryMasterFromGitHubRequest.hpp"
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <cstring>

namespace gs2 { namespace lottery {

namespace {

void write(detail::json::JsonWriter& jsonWriter, const Namespace& obj);
void write(detail::json::JsonWriter& jsonWriter, const LotteryModelMaster& obj);
void write(detail::json::JsonWriter& jsonWriter, const PrizeTableMaster& obj);
void write(detail::json::JsonWriter& jsonWriter, const Box& obj);
void write(detail::json::JsonWriter& jsonWriter, const LotteryModel& obj);
void write(detail::json::JsonWriter& jsonWriter, const PrizeTable& obj);
void write(detail::json::JsonWriter& jsonWriter, const Probability& obj);
void write(detail::json::JsonWriter& jsonWriter, const CurrentLotteryMaster& obj);
void write(detail::json::JsonWriter& jsonWriter, const ResponseCache& obj);
void write(detail::json::JsonWriter& jsonWriter, const GitHubCheckoutSetting& obj);
void write(detail::json::JsonWriter& jsonWriter, const LogSetting& obj);
void write(detail::json::JsonWriter& jsonWriter, const Prize& obj);
void write(detail::json::JsonWriter& jsonWriter, const AcquireAction& obj);
void write(detail::json::JsonWriter& jsonWriter, const DrawnPrize& obj);
void write(detail::json::JsonWriter& jsonWriter, const BoxItem& obj);
void write(detail::json::JsonWriter& jsonWriter, const BoxItems& obj);
void write(detail::json::JsonWriter& jsonWriter, const Config& obj);

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
    if (obj.getLotteryTriggerScriptId())
    {
        jsonWriter.writePropertyName("lotteryTriggerScriptId");
        jsonWriter.writeCharArray(*obj.getLotteryTriggerScriptId());
    }
    if (obj.getChoicePrizeTableScriptId())
    {
        jsonWriter.writePropertyName("choicePrizeTableScriptId");
        jsonWriter.writeCharArray(*obj.getChoicePrizeTableScriptId());
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

void write(detail::json::JsonWriter& jsonWriter, const LotteryModelMaster& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getLotteryModelId())
    {
        jsonWriter.writePropertyName("lotteryModelId");
        jsonWriter.writeCharArray(*obj.getLotteryModelId());
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
    if (obj.getMode())
    {
        jsonWriter.writePropertyName("mode");
        jsonWriter.writeCharArray(*obj.getMode());
    }
    if (obj.getMethod())
    {
        jsonWriter.writePropertyName("method");
        jsonWriter.writeCharArray(*obj.getMethod());
    }
    if (obj.getPrizeTableName())
    {
        jsonWriter.writePropertyName("prizeTableName");
        jsonWriter.writeCharArray(*obj.getPrizeTableName());
    }
    if (obj.getChoicePrizeTableScriptId())
    {
        jsonWriter.writePropertyName("choicePrizeTableScriptId");
        jsonWriter.writeCharArray(*obj.getChoicePrizeTableScriptId());
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

void write(detail::json::JsonWriter& jsonWriter, const PrizeTableMaster& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getPrizeTableId())
    {
        jsonWriter.writePropertyName("prizeTableId");
        jsonWriter.writeCharArray(*obj.getPrizeTableId());
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
    if (obj.getPrizes())
    {
        jsonWriter.writePropertyName("prizes");
        jsonWriter.writeArrayStart();
        auto& list = *obj.getPrizes();
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

void write(detail::json::JsonWriter& jsonWriter, const Box& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getBoxId())
    {
        jsonWriter.writePropertyName("boxId");
        jsonWriter.writeCharArray(*obj.getBoxId());
    }
    if (obj.getPrizeTableName())
    {
        jsonWriter.writePropertyName("prizeTableName");
        jsonWriter.writeCharArray(*obj.getPrizeTableName());
    }
    if (obj.getUserId())
    {
        jsonWriter.writePropertyName("userId");
        jsonWriter.writeCharArray(*obj.getUserId());
    }
    if (obj.getDrawnIndexes())
    {
        jsonWriter.writePropertyName("drawnIndexes");
        jsonWriter.writeArrayStart();
        auto& list = *obj.getDrawnIndexes();
        for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
        {
            jsonWriter.writeInt32(list[i]);
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

void write(detail::json::JsonWriter& jsonWriter, const LotteryModel& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getLotteryModelId())
    {
        jsonWriter.writePropertyName("lotteryModelId");
        jsonWriter.writeCharArray(*obj.getLotteryModelId());
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
    if (obj.getMode())
    {
        jsonWriter.writePropertyName("mode");
        jsonWriter.writeCharArray(*obj.getMode());
    }
    if (obj.getMethod())
    {
        jsonWriter.writePropertyName("method");
        jsonWriter.writeCharArray(*obj.getMethod());
    }
    if (obj.getPrizeTableName())
    {
        jsonWriter.writePropertyName("prizeTableName");
        jsonWriter.writeCharArray(*obj.getPrizeTableName());
    }
    if (obj.getChoicePrizeTableScriptId())
    {
        jsonWriter.writePropertyName("choicePrizeTableScriptId");
        jsonWriter.writeCharArray(*obj.getChoicePrizeTableScriptId());
    }
    jsonWriter.writeObjectEnd();
}

void write(detail::json::JsonWriter& jsonWriter, const PrizeTable& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getPrizeTableId())
    {
        jsonWriter.writePropertyName("prizeTableId");
        jsonWriter.writeCharArray(*obj.getPrizeTableId());
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
    if (obj.getPrizes())
    {
        jsonWriter.writePropertyName("prizes");
        jsonWriter.writeArrayStart();
        auto& list = *obj.getPrizes();
        for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
        {
            write(jsonWriter, list[i]);
        }
        jsonWriter.writeArrayEnd();
    }
    jsonWriter.writeObjectEnd();
}

void write(detail::json::JsonWriter& jsonWriter, const Probability& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getPrize())
    {
        jsonWriter.writePropertyName("prize");
        write(jsonWriter, *obj.getPrize());
    }
    if (obj.getRate())
    {
        jsonWriter.writePropertyName("rate");
        jsonWriter.writeFloat(*obj.getRate());
    }
    jsonWriter.writeObjectEnd();
}

void write(detail::json::JsonWriter& jsonWriter, const CurrentLotteryMaster& obj)
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

void write(detail::json::JsonWriter& jsonWriter, const Prize& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getPrizeId())
    {
        jsonWriter.writePropertyName("prizeId");
        jsonWriter.writeCharArray(*obj.getPrizeId());
    }
    if (obj.getType())
    {
        jsonWriter.writePropertyName("type");
        jsonWriter.writeCharArray(*obj.getType());
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
    if (obj.getPrizeTableName())
    {
        jsonWriter.writePropertyName("prizeTableName");
        jsonWriter.writeCharArray(*obj.getPrizeTableName());
    }
    if (obj.getWeight())
    {
        jsonWriter.writePropertyName("weight");
        jsonWriter.writeInt32(*obj.getWeight());
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

void write(detail::json::JsonWriter& jsonWriter, const DrawnPrize& obj)
{
    jsonWriter.writeObjectStart();
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

void write(detail::json::JsonWriter& jsonWriter, const BoxItem& obj)
{
    jsonWriter.writeObjectStart();
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
    if (obj.getRemaining())
    {
        jsonWriter.writePropertyName("remaining");
        jsonWriter.writeInt32(*obj.getRemaining());
    }
    if (obj.getInitial())
    {
        jsonWriter.writePropertyName("initial");
        jsonWriter.writeInt32(*obj.getInitial());
    }
    jsonWriter.writeObjectEnd();
}

void write(detail::json::JsonWriter& jsonWriter, const BoxItems& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getBoxId())
    {
        jsonWriter.writePropertyName("boxId");
        jsonWriter.writeCharArray(*obj.getBoxId());
    }
    if (obj.getPrizeTableName())
    {
        jsonWriter.writePropertyName("prizeTableName");
        jsonWriter.writeCharArray(*obj.getPrizeTableName());
    }
    if (obj.getUserId())
    {
        jsonWriter.writePropertyName("userId");
        jsonWriter.writeCharArray(*obj.getUserId());
    }
    if (obj.getItems())
    {
        jsonWriter.writePropertyName("items");
        jsonWriter.writeArrayStart();
        auto& list = *obj.getItems();
        for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
        {
            write(jsonWriter, list[i]);
        }
        jsonWriter.writeArrayEnd();
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


class DescribeNamespacesTask : public detail::Gs2WebSocketSessionTask<DescribeNamespacesResult>
{
private:
    DescribeNamespacesRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "lottery";
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
        return "lottery";
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
        if (m_Request.getLotteryTriggerScriptId())
        {
            jsonWriter.writePropertyName("lotteryTriggerScriptId");
            jsonWriter.writeCharArray(*m_Request.getLotteryTriggerScriptId());
        }
        if (m_Request.getChoicePrizeTableScriptId())
        {
            jsonWriter.writePropertyName("choicePrizeTableScriptId");
            jsonWriter.writeCharArray(*m_Request.getChoicePrizeTableScriptId());
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
        return "lottery";
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
        return "lottery";
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
        return "lottery";
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
        if (m_Request.getLotteryTriggerScriptId())
        {
            jsonWriter.writePropertyName("lotteryTriggerScriptId");
            jsonWriter.writeCharArray(*m_Request.getLotteryTriggerScriptId());
        }
        if (m_Request.getChoicePrizeTableScriptId())
        {
            jsonWriter.writePropertyName("choicePrizeTableScriptId");
            jsonWriter.writeCharArray(*m_Request.getChoicePrizeTableScriptId());
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
        return "lottery";
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

class DescribeLotteryModelMastersTask : public detail::Gs2WebSocketSessionTask<DescribeLotteryModelMastersResult>
{
private:
    DescribeLotteryModelMastersRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "lottery";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "lotteryModelMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "describeLotteryModelMasters";
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
    DescribeLotteryModelMastersTask(
        DescribeLotteryModelMastersRequest request,
        Gs2WebSocketSessionTask<DescribeLotteryModelMastersResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DescribeLotteryModelMastersResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeLotteryModelMastersTask() GS2_OVERRIDE = default;
};

class CreateLotteryModelMasterTask : public detail::Gs2WebSocketSessionTask<CreateLotteryModelMasterResult>
{
private:
    CreateLotteryModelMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "lottery";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "lotteryModelMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "createLotteryModelMaster";
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
        if (m_Request.getMode())
        {
            jsonWriter.writePropertyName("mode");
            jsonWriter.writeCharArray(*m_Request.getMode());
        }
        if (m_Request.getMethod())
        {
            jsonWriter.writePropertyName("method");
            jsonWriter.writeCharArray(*m_Request.getMethod());
        }
        if (m_Request.getPrizeTableName())
        {
            jsonWriter.writePropertyName("prizeTableName");
            jsonWriter.writeCharArray(*m_Request.getPrizeTableName());
        }
        if (m_Request.getChoicePrizeTableScriptId())
        {
            jsonWriter.writePropertyName("choicePrizeTableScriptId");
            jsonWriter.writeCharArray(*m_Request.getChoicePrizeTableScriptId());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    CreateLotteryModelMasterTask(
        CreateLotteryModelMasterRequest request,
        Gs2WebSocketSessionTask<CreateLotteryModelMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<CreateLotteryModelMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~CreateLotteryModelMasterTask() GS2_OVERRIDE = default;
};

class GetLotteryModelMasterTask : public detail::Gs2WebSocketSessionTask<GetLotteryModelMasterResult>
{
private:
    GetLotteryModelMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "lottery";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "lotteryModelMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "getLotteryModelMaster";
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
        if (m_Request.getLotteryName())
        {
            jsonWriter.writePropertyName("lotteryName");
            jsonWriter.writeCharArray(*m_Request.getLotteryName());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    GetLotteryModelMasterTask(
        GetLotteryModelMasterRequest request,
        Gs2WebSocketSessionTask<GetLotteryModelMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<GetLotteryModelMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetLotteryModelMasterTask() GS2_OVERRIDE = default;
};

class UpdateLotteryModelMasterTask : public detail::Gs2WebSocketSessionTask<UpdateLotteryModelMasterResult>
{
private:
    UpdateLotteryModelMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "lottery";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "lotteryModelMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "updateLotteryModelMaster";
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
        if (m_Request.getLotteryName())
        {
            jsonWriter.writePropertyName("lotteryName");
            jsonWriter.writeCharArray(*m_Request.getLotteryName());
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
        if (m_Request.getMode())
        {
            jsonWriter.writePropertyName("mode");
            jsonWriter.writeCharArray(*m_Request.getMode());
        }
        if (m_Request.getMethod())
        {
            jsonWriter.writePropertyName("method");
            jsonWriter.writeCharArray(*m_Request.getMethod());
        }
        if (m_Request.getPrizeTableName())
        {
            jsonWriter.writePropertyName("prizeTableName");
            jsonWriter.writeCharArray(*m_Request.getPrizeTableName());
        }
        if (m_Request.getChoicePrizeTableScriptId())
        {
            jsonWriter.writePropertyName("choicePrizeTableScriptId");
            jsonWriter.writeCharArray(*m_Request.getChoicePrizeTableScriptId());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    UpdateLotteryModelMasterTask(
        UpdateLotteryModelMasterRequest request,
        Gs2WebSocketSessionTask<UpdateLotteryModelMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<UpdateLotteryModelMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~UpdateLotteryModelMasterTask() GS2_OVERRIDE = default;
};

class DeleteLotteryModelMasterTask : public detail::Gs2WebSocketSessionTask<DeleteLotteryModelMasterResult>
{
private:
    DeleteLotteryModelMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "lottery";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "lotteryModelMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "deleteLotteryModelMaster";
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
        if (m_Request.getLotteryName())
        {
            jsonWriter.writePropertyName("lotteryName");
            jsonWriter.writeCharArray(*m_Request.getLotteryName());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    DeleteLotteryModelMasterTask(
        DeleteLotteryModelMasterRequest request,
        Gs2WebSocketSessionTask<DeleteLotteryModelMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DeleteLotteryModelMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~DeleteLotteryModelMasterTask() GS2_OVERRIDE = default;
};

class DescribePrizeTableMastersTask : public detail::Gs2WebSocketSessionTask<DescribePrizeTableMastersResult>
{
private:
    DescribePrizeTableMastersRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "lottery";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "prizeTableMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "describePrizeTableMasters";
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
    DescribePrizeTableMastersTask(
        DescribePrizeTableMastersRequest request,
        Gs2WebSocketSessionTask<DescribePrizeTableMastersResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DescribePrizeTableMastersResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribePrizeTableMastersTask() GS2_OVERRIDE = default;
};

class CreatePrizeTableMasterTask : public detail::Gs2WebSocketSessionTask<CreatePrizeTableMasterResult>
{
private:
    CreatePrizeTableMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "lottery";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "prizeTableMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "createPrizeTableMaster";
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
        if (m_Request.getPrizes())
        {
            jsonWriter.writePropertyName("prizes");
            jsonWriter.writeArrayStart();
            auto& list = *m_Request.getPrizes();
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
    CreatePrizeTableMasterTask(
        CreatePrizeTableMasterRequest request,
        Gs2WebSocketSessionTask<CreatePrizeTableMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<CreatePrizeTableMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~CreatePrizeTableMasterTask() GS2_OVERRIDE = default;
};

class GetPrizeTableMasterTask : public detail::Gs2WebSocketSessionTask<GetPrizeTableMasterResult>
{
private:
    GetPrizeTableMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "lottery";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "prizeTableMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "getPrizeTableMaster";
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
        if (m_Request.getPrizeTableName())
        {
            jsonWriter.writePropertyName("prizeTableName");
            jsonWriter.writeCharArray(*m_Request.getPrizeTableName());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    GetPrizeTableMasterTask(
        GetPrizeTableMasterRequest request,
        Gs2WebSocketSessionTask<GetPrizeTableMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<GetPrizeTableMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetPrizeTableMasterTask() GS2_OVERRIDE = default;
};

class UpdatePrizeTableMasterTask : public detail::Gs2WebSocketSessionTask<UpdatePrizeTableMasterResult>
{
private:
    UpdatePrizeTableMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "lottery";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "prizeTableMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "updatePrizeTableMaster";
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
        if (m_Request.getPrizeTableName())
        {
            jsonWriter.writePropertyName("prizeTableName");
            jsonWriter.writeCharArray(*m_Request.getPrizeTableName());
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
        if (m_Request.getPrizes())
        {
            jsonWriter.writePropertyName("prizes");
            jsonWriter.writeArrayStart();
            auto& list = *m_Request.getPrizes();
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
    UpdatePrizeTableMasterTask(
        UpdatePrizeTableMasterRequest request,
        Gs2WebSocketSessionTask<UpdatePrizeTableMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<UpdatePrizeTableMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~UpdatePrizeTableMasterTask() GS2_OVERRIDE = default;
};

class DeletePrizeTableMasterTask : public detail::Gs2WebSocketSessionTask<DeletePrizeTableMasterResult>
{
private:
    DeletePrizeTableMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "lottery";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "prizeTableMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "deletePrizeTableMaster";
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
        if (m_Request.getPrizeTableName())
        {
            jsonWriter.writePropertyName("prizeTableName");
            jsonWriter.writeCharArray(*m_Request.getPrizeTableName());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    DeletePrizeTableMasterTask(
        DeletePrizeTableMasterRequest request,
        Gs2WebSocketSessionTask<DeletePrizeTableMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DeletePrizeTableMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~DeletePrizeTableMasterTask() GS2_OVERRIDE = default;
};

class DescribeBoxesTask : public detail::Gs2WebSocketSessionTask<DescribeBoxesResult>
{
private:
    DescribeBoxesRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "lottery";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "box";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "describeBoxes";
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
    DescribeBoxesTask(
        DescribeBoxesRequest request,
        Gs2WebSocketSessionTask<DescribeBoxesResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DescribeBoxesResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeBoxesTask() GS2_OVERRIDE = default;
};

class DescribeBoxesByUserIdTask : public detail::Gs2WebSocketSessionTask<DescribeBoxesByUserIdResult>
{
private:
    DescribeBoxesByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "lottery";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "box";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "describeBoxesByUserId";
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
    DescribeBoxesByUserIdTask(
        DescribeBoxesByUserIdRequest request,
        Gs2WebSocketSessionTask<DescribeBoxesByUserIdResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DescribeBoxesByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeBoxesByUserIdTask() GS2_OVERRIDE = default;
};

class GetBoxTask : public detail::Gs2WebSocketSessionTask<GetBoxResult>
{
private:
    GetBoxRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "lottery";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "box";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "getBox";
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
        if (m_Request.getLotteryName())
        {
            jsonWriter.writePropertyName("lotteryName");
            jsonWriter.writeCharArray(*m_Request.getLotteryName());
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
    GetBoxTask(
        GetBoxRequest request,
        Gs2WebSocketSessionTask<GetBoxResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<GetBoxResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetBoxTask() GS2_OVERRIDE = default;
};

class GetBoxByUserIdTask : public detail::Gs2WebSocketSessionTask<GetBoxByUserIdResult>
{
private:
    GetBoxByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "lottery";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "box";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "getBoxByUserId";
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
        if (m_Request.getLotteryName())
        {
            jsonWriter.writePropertyName("lotteryName");
            jsonWriter.writeCharArray(*m_Request.getLotteryName());
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
    GetBoxByUserIdTask(
        GetBoxByUserIdRequest request,
        Gs2WebSocketSessionTask<GetBoxByUserIdResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<GetBoxByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetBoxByUserIdTask() GS2_OVERRIDE = default;
};

class ResetBoxTask : public detail::Gs2WebSocketSessionTask<void>
{
private:
    ResetBoxRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "lottery";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "box";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "resetBox";
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
        if (m_Request.getLotteryName())
        {
            jsonWriter.writePropertyName("lotteryName");
            jsonWriter.writeCharArray(*m_Request.getLotteryName());
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
    ResetBoxTask(
        ResetBoxRequest request,
        Gs2WebSocketSessionTask<void>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<void>(callback),
        m_Request(std::move(request))
    {}

    ~ResetBoxTask() GS2_OVERRIDE = default;
};

class ResetBoxByUserIdTask : public detail::Gs2WebSocketSessionTask<void>
{
private:
    ResetBoxByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "lottery";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "box";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "resetBoxByUserId";
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
        if (m_Request.getLotteryName())
        {
            jsonWriter.writePropertyName("lotteryName");
            jsonWriter.writeCharArray(*m_Request.getLotteryName());
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
    ResetBoxByUserIdTask(
        ResetBoxByUserIdRequest request,
        Gs2WebSocketSessionTask<void>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<void>(callback),
        m_Request(std::move(request))
    {}

    ~ResetBoxByUserIdTask() GS2_OVERRIDE = default;
};

class DescribeLotteryModelsTask : public detail::Gs2WebSocketSessionTask<DescribeLotteryModelsResult>
{
private:
    DescribeLotteryModelsRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "lottery";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "lotteryModel";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "describeLotteryModels";
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
    DescribeLotteryModelsTask(
        DescribeLotteryModelsRequest request,
        Gs2WebSocketSessionTask<DescribeLotteryModelsResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DescribeLotteryModelsResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeLotteryModelsTask() GS2_OVERRIDE = default;
};

class GetLotteryModelTask : public detail::Gs2WebSocketSessionTask<GetLotteryModelResult>
{
private:
    GetLotteryModelRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "lottery";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "lotteryModel";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "getLotteryModel";
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
        if (m_Request.getLotteryName())
        {
            jsonWriter.writePropertyName("lotteryName");
            jsonWriter.writeCharArray(*m_Request.getLotteryName());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    GetLotteryModelTask(
        GetLotteryModelRequest request,
        Gs2WebSocketSessionTask<GetLotteryModelResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<GetLotteryModelResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetLotteryModelTask() GS2_OVERRIDE = default;
};

class DescribePrizeTablesTask : public detail::Gs2WebSocketSessionTask<DescribePrizeTablesResult>
{
private:
    DescribePrizeTablesRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "lottery";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "prizeTable";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "describePrizeTables";
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
    DescribePrizeTablesTask(
        DescribePrizeTablesRequest request,
        Gs2WebSocketSessionTask<DescribePrizeTablesResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DescribePrizeTablesResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribePrizeTablesTask() GS2_OVERRIDE = default;
};

class GetPrizeTableTask : public detail::Gs2WebSocketSessionTask<GetPrizeTableResult>
{
private:
    GetPrizeTableRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "lottery";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "prizeTable";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "getPrizeTable";
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
        if (m_Request.getPrizeTableName())
        {
            jsonWriter.writePropertyName("prizeTableName");
            jsonWriter.writeCharArray(*m_Request.getPrizeTableName());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    GetPrizeTableTask(
        GetPrizeTableRequest request,
        Gs2WebSocketSessionTask<GetPrizeTableResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<GetPrizeTableResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetPrizeTableTask() GS2_OVERRIDE = default;
};

class DrawByUserIdTask : public detail::Gs2WebSocketSessionTask<DrawByUserIdResult>
{
private:
    DrawByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "lottery";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "lottery";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "drawByUserId";
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
        if (m_Request.getLotteryName())
        {
            jsonWriter.writePropertyName("lotteryName");
            jsonWriter.writeCharArray(*m_Request.getLotteryName());
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
    DrawByUserIdTask(
        DrawByUserIdRequest request,
        Gs2WebSocketSessionTask<DrawByUserIdResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DrawByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~DrawByUserIdTask() GS2_OVERRIDE = default;
};

class DescribeProbabilitiesTask : public detail::Gs2WebSocketSessionTask<DescribeProbabilitiesResult>
{
private:
    DescribeProbabilitiesRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "lottery";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "lottery";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "describeProbabilities";
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
        if (m_Request.getLotteryName())
        {
            jsonWriter.writePropertyName("lotteryName");
            jsonWriter.writeCharArray(*m_Request.getLotteryName());
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
    DescribeProbabilitiesTask(
        DescribeProbabilitiesRequest request,
        Gs2WebSocketSessionTask<DescribeProbabilitiesResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DescribeProbabilitiesResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeProbabilitiesTask() GS2_OVERRIDE = default;
};

class DescribeProbabilitiesByUserIdTask : public detail::Gs2WebSocketSessionTask<DescribeProbabilitiesByUserIdResult>
{
private:
    DescribeProbabilitiesByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "lottery";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "lottery";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "describeProbabilitiesByUserId";
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
        if (m_Request.getLotteryName())
        {
            jsonWriter.writePropertyName("lotteryName");
            jsonWriter.writeCharArray(*m_Request.getLotteryName());
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
    DescribeProbabilitiesByUserIdTask(
        DescribeProbabilitiesByUserIdRequest request,
        Gs2WebSocketSessionTask<DescribeProbabilitiesByUserIdResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DescribeProbabilitiesByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeProbabilitiesByUserIdTask() GS2_OVERRIDE = default;
};

class DrawByStampSheetTask : public detail::Gs2WebSocketSessionTask<DrawByStampSheetResult>
{
private:
    DrawByStampSheetRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "lottery";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "lottery";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "drawByStampSheet";
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
    DrawByStampSheetTask(
        DrawByStampSheetRequest request,
        Gs2WebSocketSessionTask<DrawByStampSheetResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DrawByStampSheetResult>(callback),
        m_Request(std::move(request))
    {}

    ~DrawByStampSheetTask() GS2_OVERRIDE = default;
};

class ExportMasterTask : public detail::Gs2WebSocketSessionTask<ExportMasterResult>
{
private:
    ExportMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "lottery";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "currentLotteryMaster";
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

class GetCurrentLotteryMasterTask : public detail::Gs2WebSocketSessionTask<GetCurrentLotteryMasterResult>
{
private:
    GetCurrentLotteryMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "lottery";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "currentLotteryMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "getCurrentLotteryMaster";
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
    GetCurrentLotteryMasterTask(
        GetCurrentLotteryMasterRequest request,
        Gs2WebSocketSessionTask<GetCurrentLotteryMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<GetCurrentLotteryMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetCurrentLotteryMasterTask() GS2_OVERRIDE = default;
};

class UpdateCurrentLotteryMasterTask : public detail::Gs2WebSocketSessionTask<UpdateCurrentLotteryMasterResult>
{
private:
    UpdateCurrentLotteryMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "lottery";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "currentLotteryMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "updateCurrentLotteryMaster";
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
    UpdateCurrentLotteryMasterTask(
        UpdateCurrentLotteryMasterRequest request,
        Gs2WebSocketSessionTask<UpdateCurrentLotteryMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<UpdateCurrentLotteryMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~UpdateCurrentLotteryMasterTask() GS2_OVERRIDE = default;
};

class UpdateCurrentLotteryMasterFromGitHubTask : public detail::Gs2WebSocketSessionTask<UpdateCurrentLotteryMasterFromGitHubResult>
{
private:
    UpdateCurrentLotteryMasterFromGitHubRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "lottery";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "currentLotteryMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "updateCurrentLotteryMasterFromGitHub";
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
    UpdateCurrentLotteryMasterFromGitHubTask(
        UpdateCurrentLotteryMasterFromGitHubRequest request,
        Gs2WebSocketSessionTask<UpdateCurrentLotteryMasterFromGitHubResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<UpdateCurrentLotteryMasterFromGitHubResult>(callback),
        m_Request(std::move(request))
    {}

    ~UpdateCurrentLotteryMasterFromGitHubTask() GS2_OVERRIDE = default;
};
}

/**
 * ネームスペースの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2LotteryWebSocketClient::describeNamespaces(DescribeNamespacesRequest request, std::function<void(AsyncDescribeNamespacesResult)> callback)
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
void Gs2LotteryWebSocketClient::createNamespace(CreateNamespaceRequest request, std::function<void(AsyncCreateNamespaceResult)> callback)
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
void Gs2LotteryWebSocketClient::getNamespaceStatus(GetNamespaceStatusRequest request, std::function<void(AsyncGetNamespaceStatusResult)> callback)
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
void Gs2LotteryWebSocketClient::getNamespace(GetNamespaceRequest request, std::function<void(AsyncGetNamespaceResult)> callback)
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
void Gs2LotteryWebSocketClient::updateNamespace(UpdateNamespaceRequest request, std::function<void(AsyncUpdateNamespaceResult)> callback)
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
void Gs2LotteryWebSocketClient::deleteNamespace(DeleteNamespaceRequest request, std::function<void(AsyncDeleteNamespaceResult)> callback)
{
    DeleteNamespaceTask& task = *new DeleteNamespaceTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 抽選の種類マスターの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2LotteryWebSocketClient::describeLotteryModelMasters(DescribeLotteryModelMastersRequest request, std::function<void(AsyncDescribeLotteryModelMastersResult)> callback)
{
    DescribeLotteryModelMastersTask& task = *new DescribeLotteryModelMastersTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 抽選の種類マスターを新規作成<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2LotteryWebSocketClient::createLotteryModelMaster(CreateLotteryModelMasterRequest request, std::function<void(AsyncCreateLotteryModelMasterResult)> callback)
{
    CreateLotteryModelMasterTask& task = *new CreateLotteryModelMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 抽選の種類マスターを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2LotteryWebSocketClient::getLotteryModelMaster(GetLotteryModelMasterRequest request, std::function<void(AsyncGetLotteryModelMasterResult)> callback)
{
    GetLotteryModelMasterTask& task = *new GetLotteryModelMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 抽選の種類マスターを更新<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2LotteryWebSocketClient::updateLotteryModelMaster(UpdateLotteryModelMasterRequest request, std::function<void(AsyncUpdateLotteryModelMasterResult)> callback)
{
    UpdateLotteryModelMasterTask& task = *new UpdateLotteryModelMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 抽選の種類マスターを削除<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2LotteryWebSocketClient::deleteLotteryModelMaster(DeleteLotteryModelMasterRequest request, std::function<void(AsyncDeleteLotteryModelMasterResult)> callback)
{
    DeleteLotteryModelMasterTask& task = *new DeleteLotteryModelMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 排出確率テーブルマスターの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2LotteryWebSocketClient::describePrizeTableMasters(DescribePrizeTableMastersRequest request, std::function<void(AsyncDescribePrizeTableMastersResult)> callback)
{
    DescribePrizeTableMastersTask& task = *new DescribePrizeTableMastersTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 排出確率テーブルマスターを新規作成<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2LotteryWebSocketClient::createPrizeTableMaster(CreatePrizeTableMasterRequest request, std::function<void(AsyncCreatePrizeTableMasterResult)> callback)
{
    CreatePrizeTableMasterTask& task = *new CreatePrizeTableMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 排出確率テーブルマスターを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2LotteryWebSocketClient::getPrizeTableMaster(GetPrizeTableMasterRequest request, std::function<void(AsyncGetPrizeTableMasterResult)> callback)
{
    GetPrizeTableMasterTask& task = *new GetPrizeTableMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 排出確率テーブルマスターを更新<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2LotteryWebSocketClient::updatePrizeTableMaster(UpdatePrizeTableMasterRequest request, std::function<void(AsyncUpdatePrizeTableMasterResult)> callback)
{
    UpdatePrizeTableMasterTask& task = *new UpdatePrizeTableMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 排出確率テーブルマスターを削除<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2LotteryWebSocketClient::deletePrizeTableMaster(DeletePrizeTableMasterRequest request, std::function<void(AsyncDeletePrizeTableMasterResult)> callback)
{
    DeletePrizeTableMasterTask& task = *new DeletePrizeTableMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ボックスの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2LotteryWebSocketClient::describeBoxes(DescribeBoxesRequest request, std::function<void(AsyncDescribeBoxesResult)> callback)
{
    DescribeBoxesTask& task = *new DescribeBoxesTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ユーザIDを指定してボックスの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2LotteryWebSocketClient::describeBoxesByUserId(DescribeBoxesByUserIdRequest request, std::function<void(AsyncDescribeBoxesByUserIdResult)> callback)
{
    DescribeBoxesByUserIdTask& task = *new DescribeBoxesByUserIdTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ボックスを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2LotteryWebSocketClient::getBox(GetBoxRequest request, std::function<void(AsyncGetBoxResult)> callback)
{
    GetBoxTask& task = *new GetBoxTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ユーザIDを指定してボックスを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2LotteryWebSocketClient::getBoxByUserId(GetBoxByUserIdRequest request, std::function<void(AsyncGetBoxByUserIdResult)> callback)
{
    GetBoxByUserIdTask& task = *new GetBoxByUserIdTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ボックスをリセット<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2LotteryWebSocketClient::resetBox(ResetBoxRequest request, std::function<void(AsyncResetBoxResult)> callback)
{
    ResetBoxTask& task = *new ResetBoxTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ユーザIDを指定してボックスをリセット<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2LotteryWebSocketClient::resetBoxByUserId(ResetBoxByUserIdRequest request, std::function<void(AsyncResetBoxByUserIdResult)> callback)
{
    ResetBoxByUserIdTask& task = *new ResetBoxByUserIdTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 抽選の種類の一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2LotteryWebSocketClient::describeLotteryModels(DescribeLotteryModelsRequest request, std::function<void(AsyncDescribeLotteryModelsResult)> callback)
{
    DescribeLotteryModelsTask& task = *new DescribeLotteryModelsTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 抽選の種類を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2LotteryWebSocketClient::getLotteryModel(GetLotteryModelRequest request, std::function<void(AsyncGetLotteryModelResult)> callback)
{
    GetLotteryModelTask& task = *new GetLotteryModelTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 排出確率テーブルの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2LotteryWebSocketClient::describePrizeTables(DescribePrizeTablesRequest request, std::function<void(AsyncDescribePrizeTablesResult)> callback)
{
    DescribePrizeTablesTask& task = *new DescribePrizeTablesTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 排出確率テーブルを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2LotteryWebSocketClient::getPrizeTable(GetPrizeTableRequest request, std::function<void(AsyncGetPrizeTableResult)> callback)
{
    GetPrizeTableTask& task = *new GetPrizeTableTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ユーザIDを指定して抽選を実行<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2LotteryWebSocketClient::drawByUserId(DrawByUserIdRequest request, std::function<void(AsyncDrawByUserIdResult)> callback)
{
    DrawByUserIdTask& task = *new DrawByUserIdTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 排出確率を取得<br>
 *   <br>
 *   通常抽選ではすべてのゲームプレイヤーに対して同じ確率を応答します。<br>
 *   ボックス抽選ではボックスの中身の残りを考慮したゲームプレイヤーごとに異なる確率を応答します。<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2LotteryWebSocketClient::describeProbabilities(DescribeProbabilitiesRequest request, std::function<void(AsyncDescribeProbabilitiesResult)> callback)
{
    DescribeProbabilitiesTask& task = *new DescribeProbabilitiesTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 排出確率を取得<br>
 *   <br>
 *   通常抽選ではすべてのゲームプレイヤーに対して同じ確率を応答します。<br>
 *   ボックス抽選ではボックスの中身の残りを考慮したゲームプレイヤーごとに異なる確率を応答します。<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2LotteryWebSocketClient::describeProbabilitiesByUserId(DescribeProbabilitiesByUserIdRequest request, std::function<void(AsyncDescribeProbabilitiesByUserIdResult)> callback)
{
    DescribeProbabilitiesByUserIdTask& task = *new DescribeProbabilitiesByUserIdTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタンプシートを使用して抽選処理を実行<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2LotteryWebSocketClient::drawByStampSheet(DrawByStampSheetRequest request, std::function<void(AsyncDrawByStampSheetResult)> callback)
{
    DrawByStampSheetTask& task = *new DrawByStampSheetTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 現在有効な抽選設定のマスターデータをエクスポートします<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2LotteryWebSocketClient::exportMaster(ExportMasterRequest request, std::function<void(AsyncExportMasterResult)> callback)
{
    ExportMasterTask& task = *new ExportMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 現在有効な抽選設定を取得します<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2LotteryWebSocketClient::getCurrentLotteryMaster(GetCurrentLotteryMasterRequest request, std::function<void(AsyncGetCurrentLotteryMasterResult)> callback)
{
    GetCurrentLotteryMasterTask& task = *new GetCurrentLotteryMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 現在有効な抽選設定を更新します<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2LotteryWebSocketClient::updateCurrentLotteryMaster(UpdateCurrentLotteryMasterRequest request, std::function<void(AsyncUpdateCurrentLotteryMasterResult)> callback)
{
    UpdateCurrentLotteryMasterTask& task = *new UpdateCurrentLotteryMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 現在有効な抽選設定を更新します<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2LotteryWebSocketClient::updateCurrentLotteryMasterFromGitHub(UpdateCurrentLotteryMasterFromGitHubRequest request, std::function<void(AsyncUpdateCurrentLotteryMasterFromGitHubResult)> callback)
{
    UpdateCurrentLotteryMasterFromGitHubTask& task = *new UpdateCurrentLotteryMasterFromGitHubTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

} }