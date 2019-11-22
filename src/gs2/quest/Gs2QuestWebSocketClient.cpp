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

#include "Gs2QuestWebSocketClient.hpp"
#include "model/model.hpp"
#include "request/DescribeNamespacesRequest.hpp"
#include "request/CreateNamespaceRequest.hpp"
#include "request/GetNamespaceStatusRequest.hpp"
#include "request/GetNamespaceRequest.hpp"
#include "request/UpdateNamespaceRequest.hpp"
#include "request/DeleteNamespaceRequest.hpp"
#include "request/DescribeQuestGroupModelMastersRequest.hpp"
#include "request/CreateQuestGroupModelMasterRequest.hpp"
#include "request/GetQuestGroupModelMasterRequest.hpp"
#include "request/UpdateQuestGroupModelMasterRequest.hpp"
#include "request/DeleteQuestGroupModelMasterRequest.hpp"
#include "request/DescribeQuestModelMastersRequest.hpp"
#include "request/CreateQuestModelMasterRequest.hpp"
#include "request/GetQuestModelMasterRequest.hpp"
#include "request/UpdateQuestModelMasterRequest.hpp"
#include "request/DeleteQuestModelMasterRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentQuestMasterRequest.hpp"
#include "request/UpdateCurrentQuestMasterRequest.hpp"
#include "request/UpdateCurrentQuestMasterFromGitHubRequest.hpp"
#include "request/DescribeProgressesByUserIdRequest.hpp"
#include "request/CreateProgressByUserIdRequest.hpp"
#include "request/GetProgressRequest.hpp"
#include "request/GetProgressByUserIdRequest.hpp"
#include "request/StartRequest.hpp"
#include "request/StartByUserIdRequest.hpp"
#include "request/EndRequest.hpp"
#include "request/EndByUserIdRequest.hpp"
#include "request/DeleteProgressRequest.hpp"
#include "request/DeleteProgressByUserIdRequest.hpp"
#include "request/CreateProgressByStampSheetRequest.hpp"
#include "request/DeleteProgressByStampTaskRequest.hpp"
#include "request/DescribeCompletedQuestListsRequest.hpp"
#include "request/DescribeCompletedQuestListsByUserIdRequest.hpp"
#include "request/GetCompletedQuestListRequest.hpp"
#include "request/GetCompletedQuestListByUserIdRequest.hpp"
#include "request/DeleteCompletedQuestListByUserIdRequest.hpp"
#include "request/DescribeQuestGroupModelsRequest.hpp"
#include "request/GetQuestGroupModelRequest.hpp"
#include "request/DescribeQuestModelsRequest.hpp"
#include "request/GetQuestModelRequest.hpp"
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <cstring>

namespace gs2 { namespace quest {

namespace {

void write(detail::json::JsonWriter& jsonWriter, const Namespace& obj);
void write(detail::json::JsonWriter& jsonWriter, const QuestGroupModelMaster& obj);
void write(detail::json::JsonWriter& jsonWriter, const QuestModelMaster& obj);
void write(detail::json::JsonWriter& jsonWriter, const CurrentQuestMaster& obj);
void write(detail::json::JsonWriter& jsonWriter, const ResponseCache& obj);
void write(detail::json::JsonWriter& jsonWriter, const Contents& obj);
void write(detail::json::JsonWriter& jsonWriter, const ConsumeAction& obj);
void write(detail::json::JsonWriter& jsonWriter, const AcquireAction& obj);
void write(detail::json::JsonWriter& jsonWriter, const Reward& obj);
void write(detail::json::JsonWriter& jsonWriter, const Config& obj);
void write(detail::json::JsonWriter& jsonWriter, const GitHubCheckoutSetting& obj);
void write(detail::json::JsonWriter& jsonWriter, const ScriptSetting& obj);
void write(detail::json::JsonWriter& jsonWriter, const LogSetting& obj);
void write(detail::json::JsonWriter& jsonWriter, const Progress& obj);
void write(detail::json::JsonWriter& jsonWriter, const CompletedQuestList& obj);
void write(detail::json::JsonWriter& jsonWriter, const QuestGroupModel& obj);
void write(detail::json::JsonWriter& jsonWriter, const QuestModel& obj);

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
    if (obj.getStartQuestScript())
    {
        jsonWriter.writePropertyName("startQuestScript");
        write(jsonWriter, *obj.getStartQuestScript());
    }
    if (obj.getCompleteQuestScript())
    {
        jsonWriter.writePropertyName("completeQuestScript");
        write(jsonWriter, *obj.getCompleteQuestScript());
    }
    if (obj.getFailedQuestScript())
    {
        jsonWriter.writePropertyName("failedQuestScript");
        write(jsonWriter, *obj.getFailedQuestScript());
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

void write(detail::json::JsonWriter& jsonWriter, const QuestGroupModelMaster& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getQuestGroupModelId())
    {
        jsonWriter.writePropertyName("questGroupModelId");
        jsonWriter.writeCharArray(*obj.getQuestGroupModelId());
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

void write(detail::json::JsonWriter& jsonWriter, const QuestModelMaster& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getQuestModelId())
    {
        jsonWriter.writePropertyName("questModelId");
        jsonWriter.writeCharArray(*obj.getQuestModelId());
    }
    if (obj.getQuestGroupName())
    {
        jsonWriter.writePropertyName("questGroupName");
        jsonWriter.writeCharArray(*obj.getQuestGroupName());
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
    if (obj.getContents())
    {
        jsonWriter.writePropertyName("contents");
        jsonWriter.writeArrayStart();
        auto& list = *obj.getContents();
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
    if (obj.getFailedAcquireActions())
    {
        jsonWriter.writePropertyName("failedAcquireActions");
        jsonWriter.writeArrayStart();
        auto& list = *obj.getFailedAcquireActions();
        for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
        {
            write(jsonWriter, list[i]);
        }
        jsonWriter.writeArrayEnd();
    }
    if (obj.getPremiseQuestNames())
    {
        jsonWriter.writePropertyName("premiseQuestNames");
        jsonWriter.writeArrayStart();
        auto& list = *obj.getPremiseQuestNames();
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

void write(detail::json::JsonWriter& jsonWriter, const CurrentQuestMaster& obj)
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

void write(detail::json::JsonWriter& jsonWriter, const Contents& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getMetadata())
    {
        jsonWriter.writePropertyName("metadata");
        jsonWriter.writeCharArray(*obj.getMetadata());
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
    if (obj.getWeight())
    {
        jsonWriter.writePropertyName("weight");
        jsonWriter.writeInt32(*obj.getWeight());
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

void write(detail::json::JsonWriter& jsonWriter, const Reward& obj)
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
    if (obj.getItemId())
    {
        jsonWriter.writePropertyName("itemId");
        jsonWriter.writeCharArray(*obj.getItemId());
    }
    if (obj.getValue())
    {
        jsonWriter.writePropertyName("value");
        jsonWriter.writeInt32(*obj.getValue());
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

void write(detail::json::JsonWriter& jsonWriter, const ScriptSetting& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getTriggerScriptId())
    {
        jsonWriter.writePropertyName("triggerScriptId");
        jsonWriter.writeCharArray(*obj.getTriggerScriptId());
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

void write(detail::json::JsonWriter& jsonWriter, const Progress& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getProgressId())
    {
        jsonWriter.writePropertyName("progressId");
        jsonWriter.writeCharArray(*obj.getProgressId());
    }
    if (obj.getUserId())
    {
        jsonWriter.writePropertyName("userId");
        jsonWriter.writeCharArray(*obj.getUserId());
    }
    if (obj.getTransactionId())
    {
        jsonWriter.writePropertyName("transactionId");
        jsonWriter.writeCharArray(*obj.getTransactionId());
    }
    if (obj.getQuestModelId())
    {
        jsonWriter.writePropertyName("questModelId");
        jsonWriter.writeCharArray(*obj.getQuestModelId());
    }
    if (obj.getRandomSeed())
    {
        jsonWriter.writePropertyName("randomSeed");
        jsonWriter.writeInt64(*obj.getRandomSeed());
    }
    if (obj.getRewards())
    {
        jsonWriter.writePropertyName("rewards");
        jsonWriter.writeArrayStart();
        auto& list = *obj.getRewards();
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

void write(detail::json::JsonWriter& jsonWriter, const CompletedQuestList& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getCompletedQuestListId())
    {
        jsonWriter.writePropertyName("completedQuestListId");
        jsonWriter.writeCharArray(*obj.getCompletedQuestListId());
    }
    if (obj.getUserId())
    {
        jsonWriter.writePropertyName("userId");
        jsonWriter.writeCharArray(*obj.getUserId());
    }
    if (obj.getQuestGroupName())
    {
        jsonWriter.writePropertyName("questGroupName");
        jsonWriter.writeCharArray(*obj.getQuestGroupName());
    }
    if (obj.getCompleteQuestNames())
    {
        jsonWriter.writePropertyName("completeQuestNames");
        jsonWriter.writeArrayStart();
        auto& list = *obj.getCompleteQuestNames();
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

void write(detail::json::JsonWriter& jsonWriter, const QuestGroupModel& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getQuestGroupModelId())
    {
        jsonWriter.writePropertyName("questGroupModelId");
        jsonWriter.writeCharArray(*obj.getQuestGroupModelId());
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
    if (obj.getQuests())
    {
        jsonWriter.writePropertyName("quests");
        jsonWriter.writeArrayStart();
        auto& list = *obj.getQuests();
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

void write(detail::json::JsonWriter& jsonWriter, const QuestModel& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getQuestModelId())
    {
        jsonWriter.writePropertyName("questModelId");
        jsonWriter.writeCharArray(*obj.getQuestModelId());
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
    if (obj.getContents())
    {
        jsonWriter.writePropertyName("contents");
        jsonWriter.writeArrayStart();
        auto& list = *obj.getContents();
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
    if (obj.getFailedAcquireActions())
    {
        jsonWriter.writePropertyName("failedAcquireActions");
        jsonWriter.writeArrayStart();
        auto& list = *obj.getFailedAcquireActions();
        for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
        {
            write(jsonWriter, list[i]);
        }
        jsonWriter.writeArrayEnd();
    }
    if (obj.getPremiseQuestNames())
    {
        jsonWriter.writePropertyName("premiseQuestNames");
        jsonWriter.writeArrayStart();
        auto& list = *obj.getPremiseQuestNames();
        for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
        {
            jsonWriter.writeCharArray(list[i]);
        }
        jsonWriter.writeArrayEnd();
    }
    jsonWriter.writeObjectEnd();
}


class DescribeNamespacesTask : public detail::Gs2WebSocketSessionTask<DescribeNamespacesResult>
{
private:
    DescribeNamespacesRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "quest";
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
        return "quest";
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
        if (m_Request.getStartQuestScript())
        {
            jsonWriter.writePropertyName("startQuestScript");
            write(jsonWriter, *m_Request.getStartQuestScript());
        }
        if (m_Request.getCompleteQuestScript())
        {
            jsonWriter.writePropertyName("completeQuestScript");
            write(jsonWriter, *m_Request.getCompleteQuestScript());
        }
        if (m_Request.getFailedQuestScript())
        {
            jsonWriter.writePropertyName("failedQuestScript");
            write(jsonWriter, *m_Request.getFailedQuestScript());
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
        return "quest";
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
        return "quest";
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
        return "quest";
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
        if (m_Request.getStartQuestScript())
        {
            jsonWriter.writePropertyName("startQuestScript");
            write(jsonWriter, *m_Request.getStartQuestScript());
        }
        if (m_Request.getCompleteQuestScript())
        {
            jsonWriter.writePropertyName("completeQuestScript");
            write(jsonWriter, *m_Request.getCompleteQuestScript());
        }
        if (m_Request.getFailedQuestScript())
        {
            jsonWriter.writePropertyName("failedQuestScript");
            write(jsonWriter, *m_Request.getFailedQuestScript());
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
        return "quest";
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

class DescribeQuestGroupModelMastersTask : public detail::Gs2WebSocketSessionTask<DescribeQuestGroupModelMastersResult>
{
private:
    DescribeQuestGroupModelMastersRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "quest";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "questGroupModelMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "describeQuestGroupModelMasters";
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
    DescribeQuestGroupModelMastersTask(
        DescribeQuestGroupModelMastersRequest request,
        Gs2WebSocketSessionTask<DescribeQuestGroupModelMastersResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DescribeQuestGroupModelMastersResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeQuestGroupModelMastersTask() GS2_OVERRIDE = default;
};

class CreateQuestGroupModelMasterTask : public detail::Gs2WebSocketSessionTask<CreateQuestGroupModelMasterResult>
{
private:
    CreateQuestGroupModelMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "quest";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "questGroupModelMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "createQuestGroupModelMaster";
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
    CreateQuestGroupModelMasterTask(
        CreateQuestGroupModelMasterRequest request,
        Gs2WebSocketSessionTask<CreateQuestGroupModelMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<CreateQuestGroupModelMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~CreateQuestGroupModelMasterTask() GS2_OVERRIDE = default;
};

class GetQuestGroupModelMasterTask : public detail::Gs2WebSocketSessionTask<GetQuestGroupModelMasterResult>
{
private:
    GetQuestGroupModelMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "quest";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "questGroupModelMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "getQuestGroupModelMaster";
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
        if (m_Request.getQuestGroupName())
        {
            jsonWriter.writePropertyName("questGroupName");
            jsonWriter.writeCharArray(*m_Request.getQuestGroupName());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    GetQuestGroupModelMasterTask(
        GetQuestGroupModelMasterRequest request,
        Gs2WebSocketSessionTask<GetQuestGroupModelMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<GetQuestGroupModelMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetQuestGroupModelMasterTask() GS2_OVERRIDE = default;
};

class UpdateQuestGroupModelMasterTask : public detail::Gs2WebSocketSessionTask<UpdateQuestGroupModelMasterResult>
{
private:
    UpdateQuestGroupModelMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "quest";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "questGroupModelMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "updateQuestGroupModelMaster";
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
        if (m_Request.getQuestGroupName())
        {
            jsonWriter.writePropertyName("questGroupName");
            jsonWriter.writeCharArray(*m_Request.getQuestGroupName());
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
    UpdateQuestGroupModelMasterTask(
        UpdateQuestGroupModelMasterRequest request,
        Gs2WebSocketSessionTask<UpdateQuestGroupModelMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<UpdateQuestGroupModelMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~UpdateQuestGroupModelMasterTask() GS2_OVERRIDE = default;
};

class DeleteQuestGroupModelMasterTask : public detail::Gs2WebSocketSessionTask<DeleteQuestGroupModelMasterResult>
{
private:
    DeleteQuestGroupModelMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "quest";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "questGroupModelMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "deleteQuestGroupModelMaster";
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
        if (m_Request.getQuestGroupName())
        {
            jsonWriter.writePropertyName("questGroupName");
            jsonWriter.writeCharArray(*m_Request.getQuestGroupName());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    DeleteQuestGroupModelMasterTask(
        DeleteQuestGroupModelMasterRequest request,
        Gs2WebSocketSessionTask<DeleteQuestGroupModelMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DeleteQuestGroupModelMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~DeleteQuestGroupModelMasterTask() GS2_OVERRIDE = default;
};

class DescribeQuestModelMastersTask : public detail::Gs2WebSocketSessionTask<DescribeQuestModelMastersResult>
{
private:
    DescribeQuestModelMastersRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "quest";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "questModelMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "describeQuestModelMasters";
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
        if (m_Request.getQuestGroupName())
        {
            jsonWriter.writePropertyName("questGroupName");
            jsonWriter.writeCharArray(*m_Request.getQuestGroupName());
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
    DescribeQuestModelMastersTask(
        DescribeQuestModelMastersRequest request,
        Gs2WebSocketSessionTask<DescribeQuestModelMastersResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DescribeQuestModelMastersResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeQuestModelMastersTask() GS2_OVERRIDE = default;
};

class CreateQuestModelMasterTask : public detail::Gs2WebSocketSessionTask<CreateQuestModelMasterResult>
{
private:
    CreateQuestModelMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "quest";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "questModelMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "createQuestModelMaster";
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
        if (m_Request.getQuestGroupName())
        {
            jsonWriter.writePropertyName("questGroupName");
            jsonWriter.writeCharArray(*m_Request.getQuestGroupName());
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
        if (m_Request.getContents())
        {
            jsonWriter.writePropertyName("contents");
            jsonWriter.writeArrayStart();
            auto& list = *m_Request.getContents();
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
        if (m_Request.getFailedAcquireActions())
        {
            jsonWriter.writePropertyName("failedAcquireActions");
            jsonWriter.writeArrayStart();
            auto& list = *m_Request.getFailedAcquireActions();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (m_Request.getPremiseQuestNames())
        {
            jsonWriter.writePropertyName("premiseQuestNames");
            jsonWriter.writeArrayStart();
            auto& list = *m_Request.getPremiseQuestNames();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                jsonWriter.writeCharArray(list[i]);
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
    CreateQuestModelMasterTask(
        CreateQuestModelMasterRequest request,
        Gs2WebSocketSessionTask<CreateQuestModelMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<CreateQuestModelMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~CreateQuestModelMasterTask() GS2_OVERRIDE = default;
};

class GetQuestModelMasterTask : public detail::Gs2WebSocketSessionTask<GetQuestModelMasterResult>
{
private:
    GetQuestModelMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "quest";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "questModelMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "getQuestModelMaster";
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
        if (m_Request.getQuestGroupName())
        {
            jsonWriter.writePropertyName("questGroupName");
            jsonWriter.writeCharArray(*m_Request.getQuestGroupName());
        }
        if (m_Request.getQuestName())
        {
            jsonWriter.writePropertyName("questName");
            jsonWriter.writeCharArray(*m_Request.getQuestName());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    GetQuestModelMasterTask(
        GetQuestModelMasterRequest request,
        Gs2WebSocketSessionTask<GetQuestModelMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<GetQuestModelMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetQuestModelMasterTask() GS2_OVERRIDE = default;
};

class UpdateQuestModelMasterTask : public detail::Gs2WebSocketSessionTask<UpdateQuestModelMasterResult>
{
private:
    UpdateQuestModelMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "quest";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "questModelMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "updateQuestModelMaster";
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
        if (m_Request.getQuestGroupName())
        {
            jsonWriter.writePropertyName("questGroupName");
            jsonWriter.writeCharArray(*m_Request.getQuestGroupName());
        }
        if (m_Request.getQuestName())
        {
            jsonWriter.writePropertyName("questName");
            jsonWriter.writeCharArray(*m_Request.getQuestName());
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
        if (m_Request.getContents())
        {
            jsonWriter.writePropertyName("contents");
            jsonWriter.writeArrayStart();
            auto& list = *m_Request.getContents();
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
        if (m_Request.getFailedAcquireActions())
        {
            jsonWriter.writePropertyName("failedAcquireActions");
            jsonWriter.writeArrayStart();
            auto& list = *m_Request.getFailedAcquireActions();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (m_Request.getPremiseQuestNames())
        {
            jsonWriter.writePropertyName("premiseQuestNames");
            jsonWriter.writeArrayStart();
            auto& list = *m_Request.getPremiseQuestNames();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                jsonWriter.writeCharArray(list[i]);
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
    UpdateQuestModelMasterTask(
        UpdateQuestModelMasterRequest request,
        Gs2WebSocketSessionTask<UpdateQuestModelMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<UpdateQuestModelMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~UpdateQuestModelMasterTask() GS2_OVERRIDE = default;
};

class DeleteQuestModelMasterTask : public detail::Gs2WebSocketSessionTask<DeleteQuestModelMasterResult>
{
private:
    DeleteQuestModelMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "quest";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "questModelMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "deleteQuestModelMaster";
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
        if (m_Request.getQuestGroupName())
        {
            jsonWriter.writePropertyName("questGroupName");
            jsonWriter.writeCharArray(*m_Request.getQuestGroupName());
        }
        if (m_Request.getQuestName())
        {
            jsonWriter.writePropertyName("questName");
            jsonWriter.writeCharArray(*m_Request.getQuestName());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    DeleteQuestModelMasterTask(
        DeleteQuestModelMasterRequest request,
        Gs2WebSocketSessionTask<DeleteQuestModelMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DeleteQuestModelMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~DeleteQuestModelMasterTask() GS2_OVERRIDE = default;
};

class ExportMasterTask : public detail::Gs2WebSocketSessionTask<ExportMasterResult>
{
private:
    ExportMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "quest";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "currentQuestMaster";
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

class GetCurrentQuestMasterTask : public detail::Gs2WebSocketSessionTask<GetCurrentQuestMasterResult>
{
private:
    GetCurrentQuestMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "quest";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "currentQuestMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "getCurrentQuestMaster";
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
    GetCurrentQuestMasterTask(
        GetCurrentQuestMasterRequest request,
        Gs2WebSocketSessionTask<GetCurrentQuestMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<GetCurrentQuestMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetCurrentQuestMasterTask() GS2_OVERRIDE = default;
};

class UpdateCurrentQuestMasterTask : public detail::Gs2WebSocketSessionTask<UpdateCurrentQuestMasterResult>
{
private:
    UpdateCurrentQuestMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "quest";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "currentQuestMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "updateCurrentQuestMaster";
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
    UpdateCurrentQuestMasterTask(
        UpdateCurrentQuestMasterRequest request,
        Gs2WebSocketSessionTask<UpdateCurrentQuestMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<UpdateCurrentQuestMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~UpdateCurrentQuestMasterTask() GS2_OVERRIDE = default;
};

class UpdateCurrentQuestMasterFromGitHubTask : public detail::Gs2WebSocketSessionTask<UpdateCurrentQuestMasterFromGitHubResult>
{
private:
    UpdateCurrentQuestMasterFromGitHubRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "quest";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "currentQuestMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "updateCurrentQuestMasterFromGitHub";
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
    UpdateCurrentQuestMasterFromGitHubTask(
        UpdateCurrentQuestMasterFromGitHubRequest request,
        Gs2WebSocketSessionTask<UpdateCurrentQuestMasterFromGitHubResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<UpdateCurrentQuestMasterFromGitHubResult>(callback),
        m_Request(std::move(request))
    {}

    ~UpdateCurrentQuestMasterFromGitHubTask() GS2_OVERRIDE = default;
};

class DescribeProgressesByUserIdTask : public detail::Gs2WebSocketSessionTask<DescribeProgressesByUserIdResult>
{
private:
    DescribeProgressesByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "quest";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "progress";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "describeProgressesByUserId";
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
    DescribeProgressesByUserIdTask(
        DescribeProgressesByUserIdRequest request,
        Gs2WebSocketSessionTask<DescribeProgressesByUserIdResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DescribeProgressesByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeProgressesByUserIdTask() GS2_OVERRIDE = default;
};

class CreateProgressByUserIdTask : public detail::Gs2WebSocketSessionTask<CreateProgressByUserIdResult>
{
private:
    CreateProgressByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "quest";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "progress";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "createProgressByUserId";
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
        if (m_Request.getQuestModelId())
        {
            jsonWriter.writePropertyName("questModelId");
            jsonWriter.writeCharArray(*m_Request.getQuestModelId());
        }
        if (m_Request.getForce())
        {
            jsonWriter.writePropertyName("force");
            jsonWriter.writeBool(*m_Request.getForce());
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
    CreateProgressByUserIdTask(
        CreateProgressByUserIdRequest request,
        Gs2WebSocketSessionTask<CreateProgressByUserIdResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<CreateProgressByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~CreateProgressByUserIdTask() GS2_OVERRIDE = default;
};

class GetProgressTask : public detail::Gs2WebSocketSessionTask<GetProgressResult>
{
private:
    GetProgressRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "quest";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "progress";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "getProgress";
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
    GetProgressTask(
        GetProgressRequest request,
        Gs2WebSocketSessionTask<GetProgressResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<GetProgressResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetProgressTask() GS2_OVERRIDE = default;
};

class GetProgressByUserIdTask : public detail::Gs2WebSocketSessionTask<GetProgressByUserIdResult>
{
private:
    GetProgressByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "quest";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "progress";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "getProgressByUserId";
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
    GetProgressByUserIdTask(
        GetProgressByUserIdRequest request,
        Gs2WebSocketSessionTask<GetProgressByUserIdResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<GetProgressByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetProgressByUserIdTask() GS2_OVERRIDE = default;
};

class StartTask : public detail::Gs2WebSocketSessionTask<StartResult>
{
private:
    StartRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "quest";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "progress";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "start";
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
        if (m_Request.getQuestGroupName())
        {
            jsonWriter.writePropertyName("questGroupName");
            jsonWriter.writeCharArray(*m_Request.getQuestGroupName());
        }
        if (m_Request.getQuestName())
        {
            jsonWriter.writePropertyName("questName");
            jsonWriter.writeCharArray(*m_Request.getQuestName());
        }
        if (m_Request.getForce())
        {
            jsonWriter.writePropertyName("force");
            jsonWriter.writeBool(*m_Request.getForce());
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
    StartTask(
        StartRequest request,
        Gs2WebSocketSessionTask<StartResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<StartResult>(callback),
        m_Request(std::move(request))
    {}

    ~StartTask() GS2_OVERRIDE = default;
};

class StartByUserIdTask : public detail::Gs2WebSocketSessionTask<StartByUserIdResult>
{
private:
    StartByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "quest";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "progress";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "startByUserId";
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
        if (m_Request.getQuestGroupName())
        {
            jsonWriter.writePropertyName("questGroupName");
            jsonWriter.writeCharArray(*m_Request.getQuestGroupName());
        }
        if (m_Request.getQuestName())
        {
            jsonWriter.writePropertyName("questName");
            jsonWriter.writeCharArray(*m_Request.getQuestName());
        }
        if (m_Request.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*m_Request.getUserId());
        }
        if (m_Request.getForce())
        {
            jsonWriter.writePropertyName("force");
            jsonWriter.writeBool(*m_Request.getForce());
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
    StartByUserIdTask(
        StartByUserIdRequest request,
        Gs2WebSocketSessionTask<StartByUserIdResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<StartByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~StartByUserIdTask() GS2_OVERRIDE = default;
};

class EndTask : public detail::Gs2WebSocketSessionTask<EndResult>
{
private:
    EndRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "quest";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "progress";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "end";
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
        if (m_Request.getTransactionId())
        {
            jsonWriter.writePropertyName("transactionId");
            jsonWriter.writeCharArray(*m_Request.getTransactionId());
        }
        if (m_Request.getRewards())
        {
            jsonWriter.writePropertyName("rewards");
            jsonWriter.writeArrayStart();
            auto& list = *m_Request.getRewards();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (m_Request.getIsComplete())
        {
            jsonWriter.writePropertyName("isComplete");
            jsonWriter.writeBool(*m_Request.getIsComplete());
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
    EndTask(
        EndRequest request,
        Gs2WebSocketSessionTask<EndResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<EndResult>(callback),
        m_Request(std::move(request))
    {}

    ~EndTask() GS2_OVERRIDE = default;
};

class EndByUserIdTask : public detail::Gs2WebSocketSessionTask<EndByUserIdResult>
{
private:
    EndByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "quest";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "progress";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "endByUserId";
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
        if (m_Request.getTransactionId())
        {
            jsonWriter.writePropertyName("transactionId");
            jsonWriter.writeCharArray(*m_Request.getTransactionId());
        }
        if (m_Request.getRewards())
        {
            jsonWriter.writePropertyName("rewards");
            jsonWriter.writeArrayStart();
            auto& list = *m_Request.getRewards();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (m_Request.getIsComplete())
        {
            jsonWriter.writePropertyName("isComplete");
            jsonWriter.writeBool(*m_Request.getIsComplete());
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
    EndByUserIdTask(
        EndByUserIdRequest request,
        Gs2WebSocketSessionTask<EndByUserIdResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<EndByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~EndByUserIdTask() GS2_OVERRIDE = default;
};

class DeleteProgressTask : public detail::Gs2WebSocketSessionTask<DeleteProgressResult>
{
private:
    DeleteProgressRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "quest";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "progress";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "deleteProgress";
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
    DeleteProgressTask(
        DeleteProgressRequest request,
        Gs2WebSocketSessionTask<DeleteProgressResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DeleteProgressResult>(callback),
        m_Request(std::move(request))
    {}

    ~DeleteProgressTask() GS2_OVERRIDE = default;
};

class DeleteProgressByUserIdTask : public detail::Gs2WebSocketSessionTask<DeleteProgressByUserIdResult>
{
private:
    DeleteProgressByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "quest";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "progress";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "deleteProgressByUserId";
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
    DeleteProgressByUserIdTask(
        DeleteProgressByUserIdRequest request,
        Gs2WebSocketSessionTask<DeleteProgressByUserIdResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DeleteProgressByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~DeleteProgressByUserIdTask() GS2_OVERRIDE = default;
};

class CreateProgressByStampSheetTask : public detail::Gs2WebSocketSessionTask<CreateProgressByStampSheetResult>
{
private:
    CreateProgressByStampSheetRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "quest";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "progress";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "createProgressByStampSheet";
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
    CreateProgressByStampSheetTask(
        CreateProgressByStampSheetRequest request,
        Gs2WebSocketSessionTask<CreateProgressByStampSheetResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<CreateProgressByStampSheetResult>(callback),
        m_Request(std::move(request))
    {}

    ~CreateProgressByStampSheetTask() GS2_OVERRIDE = default;
};

class DeleteProgressByStampTaskTask : public detail::Gs2WebSocketSessionTask<DeleteProgressByStampTaskResult>
{
private:
    DeleteProgressByStampTaskRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "quest";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "progress";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "deleteProgressByStampTask";
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
    DeleteProgressByStampTaskTask(
        DeleteProgressByStampTaskRequest request,
        Gs2WebSocketSessionTask<DeleteProgressByStampTaskResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DeleteProgressByStampTaskResult>(callback),
        m_Request(std::move(request))
    {}

    ~DeleteProgressByStampTaskTask() GS2_OVERRIDE = default;
};

class DescribeCompletedQuestListsTask : public detail::Gs2WebSocketSessionTask<DescribeCompletedQuestListsResult>
{
private:
    DescribeCompletedQuestListsRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "quest";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "completedQuestList";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "describeCompletedQuestLists";
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
    DescribeCompletedQuestListsTask(
        DescribeCompletedQuestListsRequest request,
        Gs2WebSocketSessionTask<DescribeCompletedQuestListsResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DescribeCompletedQuestListsResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeCompletedQuestListsTask() GS2_OVERRIDE = default;
};

class DescribeCompletedQuestListsByUserIdTask : public detail::Gs2WebSocketSessionTask<DescribeCompletedQuestListsByUserIdResult>
{
private:
    DescribeCompletedQuestListsByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "quest";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "completedQuestList";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "describeCompletedQuestListsByUserId";
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
    DescribeCompletedQuestListsByUserIdTask(
        DescribeCompletedQuestListsByUserIdRequest request,
        Gs2WebSocketSessionTask<DescribeCompletedQuestListsByUserIdResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DescribeCompletedQuestListsByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeCompletedQuestListsByUserIdTask() GS2_OVERRIDE = default;
};

class GetCompletedQuestListTask : public detail::Gs2WebSocketSessionTask<GetCompletedQuestListResult>
{
private:
    GetCompletedQuestListRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "quest";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "completedQuestList";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "getCompletedQuestList";
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
        if (m_Request.getQuestGroupName())
        {
            jsonWriter.writePropertyName("questGroupName");
            jsonWriter.writeCharArray(*m_Request.getQuestGroupName());
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
    GetCompletedQuestListTask(
        GetCompletedQuestListRequest request,
        Gs2WebSocketSessionTask<GetCompletedQuestListResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<GetCompletedQuestListResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetCompletedQuestListTask() GS2_OVERRIDE = default;
};

class GetCompletedQuestListByUserIdTask : public detail::Gs2WebSocketSessionTask<GetCompletedQuestListByUserIdResult>
{
private:
    GetCompletedQuestListByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "quest";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "completedQuestList";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "getCompletedQuestListByUserId";
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
        if (m_Request.getQuestGroupName())
        {
            jsonWriter.writePropertyName("questGroupName");
            jsonWriter.writeCharArray(*m_Request.getQuestGroupName());
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
    GetCompletedQuestListByUserIdTask(
        GetCompletedQuestListByUserIdRequest request,
        Gs2WebSocketSessionTask<GetCompletedQuestListByUserIdResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<GetCompletedQuestListByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetCompletedQuestListByUserIdTask() GS2_OVERRIDE = default;
};

class DeleteCompletedQuestListByUserIdTask : public detail::Gs2WebSocketSessionTask<DeleteCompletedQuestListByUserIdResult>
{
private:
    DeleteCompletedQuestListByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "quest";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "completedQuestList";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "deleteCompletedQuestListByUserId";
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
        if (m_Request.getQuestGroupName())
        {
            jsonWriter.writePropertyName("questGroupName");
            jsonWriter.writeCharArray(*m_Request.getQuestGroupName());
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
    DeleteCompletedQuestListByUserIdTask(
        DeleteCompletedQuestListByUserIdRequest request,
        Gs2WebSocketSessionTask<DeleteCompletedQuestListByUserIdResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DeleteCompletedQuestListByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~DeleteCompletedQuestListByUserIdTask() GS2_OVERRIDE = default;
};

class DescribeQuestGroupModelsTask : public detail::Gs2WebSocketSessionTask<DescribeQuestGroupModelsResult>
{
private:
    DescribeQuestGroupModelsRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "quest";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "questGroupModel";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "describeQuestGroupModels";
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
    DescribeQuestGroupModelsTask(
        DescribeQuestGroupModelsRequest request,
        Gs2WebSocketSessionTask<DescribeQuestGroupModelsResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DescribeQuestGroupModelsResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeQuestGroupModelsTask() GS2_OVERRIDE = default;
};

class GetQuestGroupModelTask : public detail::Gs2WebSocketSessionTask<GetQuestGroupModelResult>
{
private:
    GetQuestGroupModelRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "quest";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "questGroupModel";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "getQuestGroupModel";
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
        if (m_Request.getQuestGroupName())
        {
            jsonWriter.writePropertyName("questGroupName");
            jsonWriter.writeCharArray(*m_Request.getQuestGroupName());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    GetQuestGroupModelTask(
        GetQuestGroupModelRequest request,
        Gs2WebSocketSessionTask<GetQuestGroupModelResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<GetQuestGroupModelResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetQuestGroupModelTask() GS2_OVERRIDE = default;
};

class DescribeQuestModelsTask : public detail::Gs2WebSocketSessionTask<DescribeQuestModelsResult>
{
private:
    DescribeQuestModelsRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "quest";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "questModel";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "describeQuestModels";
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
        if (m_Request.getQuestGroupName())
        {
            jsonWriter.writePropertyName("questGroupName");
            jsonWriter.writeCharArray(*m_Request.getQuestGroupName());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    DescribeQuestModelsTask(
        DescribeQuestModelsRequest request,
        Gs2WebSocketSessionTask<DescribeQuestModelsResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DescribeQuestModelsResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeQuestModelsTask() GS2_OVERRIDE = default;
};

class GetQuestModelTask : public detail::Gs2WebSocketSessionTask<GetQuestModelResult>
{
private:
    GetQuestModelRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "quest";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "questModel";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "getQuestModel";
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
        if (m_Request.getQuestGroupName())
        {
            jsonWriter.writePropertyName("questGroupName");
            jsonWriter.writeCharArray(*m_Request.getQuestGroupName());
        }
        if (m_Request.getQuestName())
        {
            jsonWriter.writePropertyName("questName");
            jsonWriter.writeCharArray(*m_Request.getQuestName());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    GetQuestModelTask(
        GetQuestModelRequest request,
        Gs2WebSocketSessionTask<GetQuestModelResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<GetQuestModelResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetQuestModelTask() GS2_OVERRIDE = default;
};
}

/**
 * クエストを分類するカテゴリーの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2QuestWebSocketClient::describeNamespaces(DescribeNamespacesRequest request, std::function<void(AsyncDescribeNamespacesResult)> callback)
{
    DescribeNamespacesTask& task = *new DescribeNamespacesTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * クエストを分類するカテゴリーを新規作成<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2QuestWebSocketClient::createNamespace(CreateNamespaceRequest request, std::function<void(AsyncCreateNamespaceResult)> callback)
{
    CreateNamespaceTask& task = *new CreateNamespaceTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * クエストを分類するカテゴリーの状態を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2QuestWebSocketClient::getNamespaceStatus(GetNamespaceStatusRequest request, std::function<void(AsyncGetNamespaceStatusResult)> callback)
{
    GetNamespaceStatusTask& task = *new GetNamespaceStatusTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * クエストを分類するカテゴリーを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2QuestWebSocketClient::getNamespace(GetNamespaceRequest request, std::function<void(AsyncGetNamespaceResult)> callback)
{
    GetNamespaceTask& task = *new GetNamespaceTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * クエストを分類するカテゴリーを更新<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2QuestWebSocketClient::updateNamespace(UpdateNamespaceRequest request, std::function<void(AsyncUpdateNamespaceResult)> callback)
{
    UpdateNamespaceTask& task = *new UpdateNamespaceTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * クエストを分類するカテゴリーを削除<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2QuestWebSocketClient::deleteNamespace(DeleteNamespaceRequest request, std::function<void(AsyncDeleteNamespaceResult)> callback)
{
    DeleteNamespaceTask& task = *new DeleteNamespaceTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * クエストグループマスターの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2QuestWebSocketClient::describeQuestGroupModelMasters(DescribeQuestGroupModelMastersRequest request, std::function<void(AsyncDescribeQuestGroupModelMastersResult)> callback)
{
    DescribeQuestGroupModelMastersTask& task = *new DescribeQuestGroupModelMastersTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * クエストグループマスターを新規作成<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2QuestWebSocketClient::createQuestGroupModelMaster(CreateQuestGroupModelMasterRequest request, std::function<void(AsyncCreateQuestGroupModelMasterResult)> callback)
{
    CreateQuestGroupModelMasterTask& task = *new CreateQuestGroupModelMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * クエストグループマスターを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2QuestWebSocketClient::getQuestGroupModelMaster(GetQuestGroupModelMasterRequest request, std::function<void(AsyncGetQuestGroupModelMasterResult)> callback)
{
    GetQuestGroupModelMasterTask& task = *new GetQuestGroupModelMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * クエストグループマスターを更新<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2QuestWebSocketClient::updateQuestGroupModelMaster(UpdateQuestGroupModelMasterRequest request, std::function<void(AsyncUpdateQuestGroupModelMasterResult)> callback)
{
    UpdateQuestGroupModelMasterTask& task = *new UpdateQuestGroupModelMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * クエストグループマスターを削除<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2QuestWebSocketClient::deleteQuestGroupModelMaster(DeleteQuestGroupModelMasterRequest request, std::function<void(AsyncDeleteQuestGroupModelMasterResult)> callback)
{
    DeleteQuestGroupModelMasterTask& task = *new DeleteQuestGroupModelMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * クエストモデルマスターの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2QuestWebSocketClient::describeQuestModelMasters(DescribeQuestModelMastersRequest request, std::function<void(AsyncDescribeQuestModelMastersResult)> callback)
{
    DescribeQuestModelMastersTask& task = *new DescribeQuestModelMastersTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * クエストモデルマスターを新規作成<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2QuestWebSocketClient::createQuestModelMaster(CreateQuestModelMasterRequest request, std::function<void(AsyncCreateQuestModelMasterResult)> callback)
{
    CreateQuestModelMasterTask& task = *new CreateQuestModelMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * クエストモデルマスターを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2QuestWebSocketClient::getQuestModelMaster(GetQuestModelMasterRequest request, std::function<void(AsyncGetQuestModelMasterResult)> callback)
{
    GetQuestModelMasterTask& task = *new GetQuestModelMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * クエストモデルマスターを更新<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2QuestWebSocketClient::updateQuestModelMaster(UpdateQuestModelMasterRequest request, std::function<void(AsyncUpdateQuestModelMasterResult)> callback)
{
    UpdateQuestModelMasterTask& task = *new UpdateQuestModelMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * クエストモデルマスターを削除<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2QuestWebSocketClient::deleteQuestModelMaster(DeleteQuestModelMasterRequest request, std::function<void(AsyncDeleteQuestModelMasterResult)> callback)
{
    DeleteQuestModelMasterTask& task = *new DeleteQuestModelMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 現在有効なクエストマスターのマスターデータをエクスポートします<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2QuestWebSocketClient::exportMaster(ExportMasterRequest request, std::function<void(AsyncExportMasterResult)> callback)
{
    ExportMasterTask& task = *new ExportMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 現在有効なクエストマスターを取得します<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2QuestWebSocketClient::getCurrentQuestMaster(GetCurrentQuestMasterRequest request, std::function<void(AsyncGetCurrentQuestMasterResult)> callback)
{
    GetCurrentQuestMasterTask& task = *new GetCurrentQuestMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 現在有効なクエストマスターを更新します<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2QuestWebSocketClient::updateCurrentQuestMaster(UpdateCurrentQuestMasterRequest request, std::function<void(AsyncUpdateCurrentQuestMasterResult)> callback)
{
    UpdateCurrentQuestMasterTask& task = *new UpdateCurrentQuestMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 現在有効なクエストマスターを更新します<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2QuestWebSocketClient::updateCurrentQuestMasterFromGitHub(UpdateCurrentQuestMasterFromGitHubRequest request, std::function<void(AsyncUpdateCurrentQuestMasterFromGitHubResult)> callback)
{
    UpdateCurrentQuestMasterFromGitHubTask& task = *new UpdateCurrentQuestMasterFromGitHubTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * クエスト挑戦の一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2QuestWebSocketClient::describeProgressesByUserId(DescribeProgressesByUserIdRequest request, std::function<void(AsyncDescribeProgressesByUserIdResult)> callback)
{
    DescribeProgressesByUserIdTask& task = *new DescribeProgressesByUserIdTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ユーザIDを指定してクエスト挑戦を作成<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2QuestWebSocketClient::createProgressByUserId(CreateProgressByUserIdRequest request, std::function<void(AsyncCreateProgressByUserIdResult)> callback)
{
    CreateProgressByUserIdTask& task = *new CreateProgressByUserIdTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * クエスト挑戦を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2QuestWebSocketClient::getProgress(GetProgressRequest request, std::function<void(AsyncGetProgressResult)> callback)
{
    GetProgressTask& task = *new GetProgressTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ユーザIDを指定してクエスト挑戦を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2QuestWebSocketClient::getProgressByUserId(GetProgressByUserIdRequest request, std::function<void(AsyncGetProgressByUserIdResult)> callback)
{
    GetProgressByUserIdTask& task = *new GetProgressByUserIdTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * クエストを開始<br>
 *   <br>
 *   同一カテゴリ内でゲームプレイヤーは同時に1つのクエストを実行できます。<br>
 *   すでに同一カテゴリ内で実行中のクエストがある場合、このAPIはエラーを返します。<br>
 *   進行中のクエストを取得するAPIを呼び出すことで、クエストを再開するために必要な情報を得ることができます。<br>
 *   強制的にクエストを開始するには force パラメータに true を指定することで強制的にクエストを開始できます。<br>
 *   <br>
 *   クエストが正常に開始できた場合、Progress オブジェクトを応答します。<br>
 *   Progress オブジェクトはクエストを実行するために必要ないくつかの情報を応答します。<br>
 *   <br>
 *   transactionId は実行中のクエスト固有のIDです。<br>
 *   クエストの完了報告にはこのIDを指定する必要があります。<br>
 *   <br>
 *   randomSeed はクエストの内容を決定するために使用できる乱数シードです。<br>
 *   クエストを開始するたびに異なる乱数が払い出されますので、この値をシード値としてゲームを進行させることで<br>
 *   クエスト中にアプリケーションを強制終了したとしても同一条件で再開することができます。<br>
 *   <br>
 *   rewards にはこのクエストにおいて入手可能な報酬とその数量の"最大値"が得られます。<br>
 *   クエストの完了報告にも rewards を渡すことができ、そこでクエスト中に実際に入手したアイテムの数量を指定します。<br>
 *   詳細はクエストの完了報告APIのドキュメントを参照してください。<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2QuestWebSocketClient::start(StartRequest request, std::function<void(AsyncStartResult)> callback)
{
    StartTask& task = *new StartTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ユーザIDを指定してクエストを開始<br>
 *   <br>
 *   同一カテゴリ内でゲームプレイヤーは同時に1つのクエストを実行できます。<br>
 *   すでに同一カテゴリ内で実行中のクエストがある場合、このAPIはエラーを返します。<br>
 *   進行中のクエストを取得するAPIを呼び出すことで、クエストを再開するために必要な情報を得ることができます。<br>
 *   強制的にクエストを開始するには force パラメータに true を指定することで強制的にクエストを開始できます。<br>
 *   <br>
 *   クエストが正常に開始できた場合、Progress オブジェクトを応答します。<br>
 *   Progress オブジェクトはクエストを実行するために必要ないくつかの情報を応答します。<br>
 *   <br>
 *   transactionId は実行中のクエスト固有のIDです。<br>
 *   クエストの完了報告にはこのIDを指定する必要があります。<br>
 *   <br>
 *   randomSeed はクエストの内容を決定するために使用できる乱数シードです。<br>
 *   クエストを開®®始するたびに異なる乱数が払い出されますので、この値をシード値としてゲームを進行させることで<br>
 *   クエスト中にアプリケーションを強制終了したとしても同一条件で再開することができます。<br>
 *   <br>
 *   rewards にはこのクエストにおいて入手可能な報酬とその数量の"最大値"が得られます。<br>
 *   クエストの完了報告にも rewards を渡すことができ、そこでクエスト中に実際に入手したアイテムの数量を指定します。<br>
 *   詳細はクエストの完了報告APIのドキュメントを参照してください。<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2QuestWebSocketClient::startByUserId(StartByUserIdRequest request, std::function<void(AsyncStartByUserIdResult)> callback)
{
    StartByUserIdTask& task = *new StartByUserIdTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * クエストを完了<br>
 *   <br>
 *   開始時に受け取ったクエストにおいて入手可能な報酬とその数量の"最大値"のうち、クエスト内で実際に入手した報酬を rewards で報告します。<br>
 *   isComplete にはクエストをクリアできたかを報告します。クエストに失敗した場合、rewards の値は無視してクエストに設定された失敗した場合の報酬が付与されます。<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2QuestWebSocketClient::end(EndRequest request, std::function<void(AsyncEndResult)> callback)
{
    EndTask& task = *new EndTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ユーザIDを指定してクエストを完了<br>
 *   <br>
 *   開始時に受け取ったクエストにおいて入手可能な報酬とその数量の"最大値"のうち、クエスト内で実際に入手した報酬を rewards で報告します。<br>
 *   isComplete にはクエストをクリアできたかを報告します。クエストに失敗した場合、rewards の値は無視してクエストに設定された失敗した場合の報酬が付与されます。<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2QuestWebSocketClient::endByUserId(EndByUserIdRequest request, std::function<void(AsyncEndByUserIdResult)> callback)
{
    EndByUserIdTask& task = *new EndByUserIdTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * クエスト挑戦を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2QuestWebSocketClient::deleteProgress(DeleteProgressRequest request, std::function<void(AsyncDeleteProgressResult)> callback)
{
    DeleteProgressTask& task = *new DeleteProgressTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ユーザIDを指定してクエスト挑戦を削除<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2QuestWebSocketClient::deleteProgressByUserId(DeleteProgressByUserIdRequest request, std::function<void(AsyncDeleteProgressByUserIdResult)> callback)
{
    DeleteProgressByUserIdTask& task = *new DeleteProgressByUserIdTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタンプシートでクエストを開始<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2QuestWebSocketClient::createProgressByStampSheet(CreateProgressByStampSheetRequest request, std::function<void(AsyncCreateProgressByStampSheetResult)> callback)
{
    CreateProgressByStampSheetTask& task = *new CreateProgressByStampSheetTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタンプタスクで クエスト挑戦 を削除<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2QuestWebSocketClient::deleteProgressByStampTask(DeleteProgressByStampTaskRequest request, std::function<void(AsyncDeleteProgressByStampTaskResult)> callback)
{
    DeleteProgressByStampTaskTask& task = *new DeleteProgressByStampTaskTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * クエスト進行の一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2QuestWebSocketClient::describeCompletedQuestLists(DescribeCompletedQuestListsRequest request, std::function<void(AsyncDescribeCompletedQuestListsResult)> callback)
{
    DescribeCompletedQuestListsTask& task = *new DescribeCompletedQuestListsTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ユーザIDを指定してクエスト進行の一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2QuestWebSocketClient::describeCompletedQuestListsByUserId(DescribeCompletedQuestListsByUserIdRequest request, std::function<void(AsyncDescribeCompletedQuestListsByUserIdResult)> callback)
{
    DescribeCompletedQuestListsByUserIdTask& task = *new DescribeCompletedQuestListsByUserIdTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * クエスト進行を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2QuestWebSocketClient::getCompletedQuestList(GetCompletedQuestListRequest request, std::function<void(AsyncGetCompletedQuestListResult)> callback)
{
    GetCompletedQuestListTask& task = *new GetCompletedQuestListTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ユーザIDを指定してクエスト進行を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2QuestWebSocketClient::getCompletedQuestListByUserId(GetCompletedQuestListByUserIdRequest request, std::function<void(AsyncGetCompletedQuestListByUserIdResult)> callback)
{
    GetCompletedQuestListByUserIdTask& task = *new GetCompletedQuestListByUserIdTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ユーザIDを指定してクエスト進行を削除<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2QuestWebSocketClient::deleteCompletedQuestListByUserId(DeleteCompletedQuestListByUserIdRequest request, std::function<void(AsyncDeleteCompletedQuestListByUserIdResult)> callback)
{
    DeleteCompletedQuestListByUserIdTask& task = *new DeleteCompletedQuestListByUserIdTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * クエストグループの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2QuestWebSocketClient::describeQuestGroupModels(DescribeQuestGroupModelsRequest request, std::function<void(AsyncDescribeQuestGroupModelsResult)> callback)
{
    DescribeQuestGroupModelsTask& task = *new DescribeQuestGroupModelsTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * クエストグループを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2QuestWebSocketClient::getQuestGroupModel(GetQuestGroupModelRequest request, std::function<void(AsyncGetQuestGroupModelResult)> callback)
{
    GetQuestGroupModelTask& task = *new GetQuestGroupModelTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * クエストモデルの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2QuestWebSocketClient::describeQuestModels(DescribeQuestModelsRequest request, std::function<void(AsyncDescribeQuestModelsResult)> callback)
{
    DescribeQuestModelsTask& task = *new DescribeQuestModelsTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * クエストモデルを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2QuestWebSocketClient::getQuestModel(GetQuestModelRequest request, std::function<void(AsyncGetQuestModelResult)> callback)
{
    GetQuestModelTask& task = *new GetQuestModelTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

} }