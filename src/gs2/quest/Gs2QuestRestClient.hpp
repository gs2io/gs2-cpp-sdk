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

#ifndef GS2_QUEST_GS2QUESTRESTCLIENT_HPP_
#define GS2_QUEST_GS2QUESTRESTCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2RestSessionTask.hpp>
#include <gs2/core/network/Gs2RestSession.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
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
#include "request/DescribeCompletedQuestListsRequest.hpp"
#include "request/DescribeCompletedQuestListsByUserIdRequest.hpp"
#include "request/GetCompletedQuestListRequest.hpp"
#include "request/GetCompletedQuestListByUserIdRequest.hpp"
#include "request/DeleteCompletedQuestListByUserIdRequest.hpp"
#include "request/DescribeQuestGroupModelsRequest.hpp"
#include "request/GetQuestGroupModelRequest.hpp"
#include "request/DescribeQuestModelsRequest.hpp"
#include "request/GetQuestModelRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeQuestGroupModelMastersResult.hpp"
#include "result/CreateQuestGroupModelMasterResult.hpp"
#include "result/GetQuestGroupModelMasterResult.hpp"
#include "result/UpdateQuestGroupModelMasterResult.hpp"
#include "result/DeleteQuestGroupModelMasterResult.hpp"
#include "result/DescribeQuestModelMastersResult.hpp"
#include "result/CreateQuestModelMasterResult.hpp"
#include "result/GetQuestModelMasterResult.hpp"
#include "result/UpdateQuestModelMasterResult.hpp"
#include "result/DeleteQuestModelMasterResult.hpp"
#include "result/ExportMasterResult.hpp"
#include "result/GetCurrentQuestMasterResult.hpp"
#include "result/UpdateCurrentQuestMasterResult.hpp"
#include "result/UpdateCurrentQuestMasterFromGitHubResult.hpp"
#include "result/DescribeProgressesByUserIdResult.hpp"
#include "result/CreateProgressByUserIdResult.hpp"
#include "result/GetProgressResult.hpp"
#include "result/GetProgressByUserIdResult.hpp"
#include "result/StartResult.hpp"
#include "result/StartByUserIdResult.hpp"
#include "result/EndResult.hpp"
#include "result/EndByUserIdResult.hpp"
#include "result/DeleteProgressResult.hpp"
#include "result/DeleteProgressByUserIdResult.hpp"
#include "result/CreateProgressByStampSheetResult.hpp"
#include "result/DescribeCompletedQuestListsResult.hpp"
#include "result/DescribeCompletedQuestListsByUserIdResult.hpp"
#include "result/GetCompletedQuestListResult.hpp"
#include "result/GetCompletedQuestListByUserIdResult.hpp"
#include "result/DeleteCompletedQuestListByUserIdResult.hpp"
#include "result/DescribeQuestGroupModelsResult.hpp"
#include "result/GetQuestGroupModelResult.hpp"
#include "result/DescribeQuestModelsResult.hpp"
#include "result/GetQuestModelResult.hpp"
#include <cstring>

namespace gs2 { namespace quest {

typedef AsyncResult<DescribeNamespacesResult> AsyncDescribeNamespacesResult;
typedef AsyncResult<CreateNamespaceResult> AsyncCreateNamespaceResult;
typedef AsyncResult<GetNamespaceStatusResult> AsyncGetNamespaceStatusResult;
typedef AsyncResult<GetNamespaceResult> AsyncGetNamespaceResult;
typedef AsyncResult<UpdateNamespaceResult> AsyncUpdateNamespaceResult;
typedef AsyncResult<DeleteNamespaceResult> AsyncDeleteNamespaceResult;
typedef AsyncResult<DescribeQuestGroupModelMastersResult> AsyncDescribeQuestGroupModelMastersResult;
typedef AsyncResult<CreateQuestGroupModelMasterResult> AsyncCreateQuestGroupModelMasterResult;
typedef AsyncResult<GetQuestGroupModelMasterResult> AsyncGetQuestGroupModelMasterResult;
typedef AsyncResult<UpdateQuestGroupModelMasterResult> AsyncUpdateQuestGroupModelMasterResult;
typedef AsyncResult<DeleteQuestGroupModelMasterResult> AsyncDeleteQuestGroupModelMasterResult;
typedef AsyncResult<DescribeQuestModelMastersResult> AsyncDescribeQuestModelMastersResult;
typedef AsyncResult<CreateQuestModelMasterResult> AsyncCreateQuestModelMasterResult;
typedef AsyncResult<GetQuestModelMasterResult> AsyncGetQuestModelMasterResult;
typedef AsyncResult<UpdateQuestModelMasterResult> AsyncUpdateQuestModelMasterResult;
typedef AsyncResult<DeleteQuestModelMasterResult> AsyncDeleteQuestModelMasterResult;
typedef AsyncResult<ExportMasterResult> AsyncExportMasterResult;
typedef AsyncResult<GetCurrentQuestMasterResult> AsyncGetCurrentQuestMasterResult;
typedef AsyncResult<UpdateCurrentQuestMasterResult> AsyncUpdateCurrentQuestMasterResult;
typedef AsyncResult<UpdateCurrentQuestMasterFromGitHubResult> AsyncUpdateCurrentQuestMasterFromGitHubResult;
typedef AsyncResult<DescribeProgressesByUserIdResult> AsyncDescribeProgressesByUserIdResult;
typedef AsyncResult<CreateProgressByUserIdResult> AsyncCreateProgressByUserIdResult;
typedef AsyncResult<GetProgressResult> AsyncGetProgressResult;
typedef AsyncResult<GetProgressByUserIdResult> AsyncGetProgressByUserIdResult;
typedef AsyncResult<StartResult> AsyncStartResult;
typedef AsyncResult<StartByUserIdResult> AsyncStartByUserIdResult;
typedef AsyncResult<EndResult> AsyncEndResult;
typedef AsyncResult<EndByUserIdResult> AsyncEndByUserIdResult;
typedef AsyncResult<DeleteProgressResult> AsyncDeleteProgressResult;
typedef AsyncResult<DeleteProgressByUserIdResult> AsyncDeleteProgressByUserIdResult;
typedef AsyncResult<CreateProgressByStampSheetResult> AsyncCreateProgressByStampSheetResult;
typedef AsyncResult<DescribeCompletedQuestListsResult> AsyncDescribeCompletedQuestListsResult;
typedef AsyncResult<DescribeCompletedQuestListsByUserIdResult> AsyncDescribeCompletedQuestListsByUserIdResult;
typedef AsyncResult<GetCompletedQuestListResult> AsyncGetCompletedQuestListResult;
typedef AsyncResult<GetCompletedQuestListByUserIdResult> AsyncGetCompletedQuestListByUserIdResult;
typedef AsyncResult<DeleteCompletedQuestListByUserIdResult> AsyncDeleteCompletedQuestListByUserIdResult;
typedef AsyncResult<DescribeQuestGroupModelsResult> AsyncDescribeQuestGroupModelsResult;
typedef AsyncResult<GetQuestGroupModelResult> AsyncGetQuestGroupModelResult;
typedef AsyncResult<DescribeQuestModelsResult> AsyncDescribeQuestModelsResult;
typedef AsyncResult<GetQuestModelResult> AsyncGetQuestModelResult;

/**
 * GS2 Quest API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2QuestRestClient : public AbstractGs2ClientBase
{
private:
    static void write(detail::json::JsonWriter& writer, const Namespace& obj)
    {
        writer.writeObjectStart();
        if (obj.getNamespaceId())
        {
            writer.writePropertyName("namespaceId");
            writer.writeCharArray(*obj.getNamespaceId());
        }
        if (obj.getOwnerId())
        {
            writer.writePropertyName("ownerId");
            writer.writeCharArray(*obj.getOwnerId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*obj.getName());
        }
        if (obj.getDescription())
        {
            writer.writePropertyName("description");
            writer.writeCharArray(*obj.getDescription());
        }
        if (obj.getStartQuestTriggerScriptId())
        {
            writer.writePropertyName("startQuestTriggerScriptId");
            writer.writeCharArray(*obj.getStartQuestTriggerScriptId());
        }
        if (obj.getStartQuestDoneTriggerScriptId())
        {
            writer.writePropertyName("startQuestDoneTriggerScriptId");
            writer.writeCharArray(*obj.getStartQuestDoneTriggerScriptId());
        }
        if (obj.getStartQuestDoneTriggerQueueNamespaceId())
        {
            writer.writePropertyName("startQuestDoneTriggerQueueNamespaceId");
            writer.writeCharArray(*obj.getStartQuestDoneTriggerQueueNamespaceId());
        }
        if (obj.getCompleteQuestTriggerScriptId())
        {
            writer.writePropertyName("completeQuestTriggerScriptId");
            writer.writeCharArray(*obj.getCompleteQuestTriggerScriptId());
        }
        if (obj.getCompleteQuestDoneTriggerScriptId())
        {
            writer.writePropertyName("completeQuestDoneTriggerScriptId");
            writer.writeCharArray(*obj.getCompleteQuestDoneTriggerScriptId());
        }
        if (obj.getCompleteQuestDoneTriggerQueueNamespaceId())
        {
            writer.writePropertyName("completeQuestDoneTriggerQueueNamespaceId");
            writer.writeCharArray(*obj.getCompleteQuestDoneTriggerQueueNamespaceId());
        }
        if (obj.getFailedQuestTriggerScriptId())
        {
            writer.writePropertyName("failedQuestTriggerScriptId");
            writer.writeCharArray(*obj.getFailedQuestTriggerScriptId());
        }
        if (obj.getFailedQuestDoneTriggerScriptId())
        {
            writer.writePropertyName("failedQuestDoneTriggerScriptId");
            writer.writeCharArray(*obj.getFailedQuestDoneTriggerScriptId());
        }
        if (obj.getFailedQuestDoneTriggerQueueNamespaceId())
        {
            writer.writePropertyName("failedQuestDoneTriggerQueueNamespaceId");
            writer.writeCharArray(*obj.getFailedQuestDoneTriggerQueueNamespaceId());
        }
        if (obj.getQueueNamespaceId())
        {
            writer.writePropertyName("queueNamespaceId");
            writer.writeCharArray(*obj.getQueueNamespaceId());
        }
        if (obj.getKeyId())
        {
            writer.writePropertyName("keyId");
            writer.writeCharArray(*obj.getKeyId());
        }
        if (obj.getCreatedAt())
        {
            writer.writePropertyName("createdAt");
            writer.writeInt64(*obj.getCreatedAt());
        }
        if (obj.getUpdatedAt())
        {
            writer.writePropertyName("updatedAt");
            writer.writeInt64(*obj.getUpdatedAt());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const QuestGroupModelMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getQuestGroupModelId())
        {
            writer.writePropertyName("questGroupModelId");
            writer.writeCharArray(*obj.getQuestGroupModelId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*obj.getName());
        }
        if (obj.getDescription())
        {
            writer.writePropertyName("description");
            writer.writeCharArray(*obj.getDescription());
        }
        if (obj.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.writeCharArray(*obj.getMetadata());
        }
        if (obj.getChallengePeriodEventId())
        {
            writer.writePropertyName("challengePeriodEventId");
            writer.writeCharArray(*obj.getChallengePeriodEventId());
        }
        if (obj.getCreatedAt())
        {
            writer.writePropertyName("createdAt");
            writer.writeInt64(*obj.getCreatedAt());
        }
        if (obj.getUpdatedAt())
        {
            writer.writePropertyName("updatedAt");
            writer.writeInt64(*obj.getUpdatedAt());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const QuestModelMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getQuestModelId())
        {
            writer.writePropertyName("questModelId");
            writer.writeCharArray(*obj.getQuestModelId());
        }
        if (obj.getQuestGroupName())
        {
            writer.writePropertyName("questGroupName");
            writer.writeCharArray(*obj.getQuestGroupName());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*obj.getName());
        }
        if (obj.getDescription())
        {
            writer.writePropertyName("description");
            writer.writeCharArray(*obj.getDescription());
        }
        if (obj.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.writeCharArray(*obj.getMetadata());
        }
        if (obj.getContents())
        {
            writer.writePropertyName("contents");
            writer.writeArrayStart();
            auto& list = *obj.getContents();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getChallengePeriodEventId())
        {
            writer.writePropertyName("challengePeriodEventId");
            writer.writeCharArray(*obj.getChallengePeriodEventId());
        }
        if (obj.getConsumeActions())
        {
            writer.writePropertyName("consumeActions");
            writer.writeArrayStart();
            auto& list = *obj.getConsumeActions();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getFailedAcquireActions())
        {
            writer.writePropertyName("failedAcquireActions");
            writer.writeArrayStart();
            auto& list = *obj.getFailedAcquireActions();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getPremiseQuestNames())
        {
            writer.writePropertyName("premiseQuestNames");
            writer.writeArrayStart();
            auto& list = *obj.getPremiseQuestNames();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                writer.writeCharArray(list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getCreatedAt())
        {
            writer.writePropertyName("createdAt");
            writer.writeInt64(*obj.getCreatedAt());
        }
        if (obj.getUpdatedAt())
        {
            writer.writePropertyName("updatedAt");
            writer.writeInt64(*obj.getUpdatedAt());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const CurrentQuestMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getNamespaceName())
        {
            writer.writePropertyName("namespaceName");
            writer.writeCharArray(*obj.getNamespaceName());
        }
        if (obj.getSettings())
        {
            writer.writePropertyName("settings");
            writer.writeCharArray(*obj.getSettings());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const ResponseCache& obj)
    {
        writer.writeObjectStart();
        if (obj.getRegion())
        {
            writer.writePropertyName("region");
            writer.writeCharArray(*obj.getRegion());
        }
        if (obj.getOwnerId())
        {
            writer.writePropertyName("ownerId");
            writer.writeCharArray(*obj.getOwnerId());
        }
        if (obj.getResponseCacheId())
        {
            writer.writePropertyName("responseCacheId");
            writer.writeCharArray(*obj.getResponseCacheId());
        }
        if (obj.getRequestHash())
        {
            writer.writePropertyName("requestHash");
            writer.writeCharArray(*obj.getRequestHash());
        }
        if (obj.getResult())
        {
            writer.writePropertyName("result");
            writer.writeCharArray(*obj.getResult());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const Contents& obj)
    {
        writer.writeObjectStart();
        if (obj.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.writeCharArray(*obj.getMetadata());
        }
        if (obj.getCompleteAcquireActions())
        {
            writer.writePropertyName("completeAcquireActions");
            writer.writeArrayStart();
            auto& list = *obj.getCompleteAcquireActions();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getWeight())
        {
            writer.writePropertyName("weight");
            writer.writeInt32(*obj.getWeight());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const ConsumeAction& obj)
    {
        writer.writeObjectStart();
        if (obj.getAction())
        {
            writer.writePropertyName("action");
            writer.writeCharArray(*obj.getAction());
        }
        if (obj.getRequest())
        {
            writer.writePropertyName("request");
            writer.writeCharArray(*obj.getRequest());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const AcquireAction& obj)
    {
        writer.writeObjectStart();
        if (obj.getAction())
        {
            writer.writePropertyName("action");
            writer.writeCharArray(*obj.getAction());
        }
        if (obj.getRequest())
        {
            writer.writePropertyName("request");
            writer.writeCharArray(*obj.getRequest());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const Reward& obj)
    {
        writer.writeObjectStart();
        if (obj.getAction())
        {
            writer.writePropertyName("action");
            writer.writeCharArray(*obj.getAction());
        }
        if (obj.getRequest())
        {
            writer.writePropertyName("request");
            writer.writeCharArray(*obj.getRequest());
        }
        if (obj.getItemId())
        {
            writer.writePropertyName("itemId");
            writer.writeCharArray(*obj.getItemId());
        }
        if (obj.getValue())
        {
            writer.writePropertyName("value");
            writer.writeInt32(*obj.getValue());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const Config& obj)
    {
        writer.writeObjectStart();
        if (obj.getKey())
        {
            writer.writePropertyName("key");
            writer.writeCharArray(*obj.getKey());
        }
        if (obj.getValue())
        {
            writer.writePropertyName("value");
            writer.writeCharArray(*obj.getValue());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const GitHubCheckoutSetting& obj)
    {
        writer.writeObjectStart();
        if (obj.getGitHubApiKeyId())
        {
            writer.writePropertyName("gitHubApiKeyId");
            writer.writeCharArray(*obj.getGitHubApiKeyId());
        }
        if (obj.getRepositoryName())
        {
            writer.writePropertyName("repositoryName");
            writer.writeCharArray(*obj.getRepositoryName());
        }
        if (obj.getSourcePath())
        {
            writer.writePropertyName("sourcePath");
            writer.writeCharArray(*obj.getSourcePath());
        }
        if (obj.getReferenceType())
        {
            writer.writePropertyName("referenceType");
            writer.writeCharArray(*obj.getReferenceType());
        }
        if (obj.getCommitHash())
        {
            writer.writePropertyName("commitHash");
            writer.writeCharArray(*obj.getCommitHash());
        }
        if (obj.getBranchName())
        {
            writer.writePropertyName("branchName");
            writer.writeCharArray(*obj.getBranchName());
        }
        if (obj.getTagName())
        {
            writer.writePropertyName("tagName");
            writer.writeCharArray(*obj.getTagName());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const Progress& obj)
    {
        writer.writeObjectStart();
        if (obj.getProgressId())
        {
            writer.writePropertyName("progressId");
            writer.writeCharArray(*obj.getProgressId());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.writeCharArray(*obj.getUserId());
        }
        if (obj.getTransactionId())
        {
            writer.writePropertyName("transactionId");
            writer.writeCharArray(*obj.getTransactionId());
        }
        if (obj.getQuestModelId())
        {
            writer.writePropertyName("questModelId");
            writer.writeCharArray(*obj.getQuestModelId());
        }
        if (obj.getRandomSeed())
        {
            writer.writePropertyName("randomSeed");
            writer.writeInt64(*obj.getRandomSeed());
        }
        if (obj.getRewards())
        {
            writer.writePropertyName("rewards");
            writer.writeArrayStart();
            auto& list = *obj.getRewards();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getCreatedAt())
        {
            writer.writePropertyName("createdAt");
            writer.writeInt64(*obj.getCreatedAt());
        }
        if (obj.getUpdatedAt())
        {
            writer.writePropertyName("updatedAt");
            writer.writeInt64(*obj.getUpdatedAt());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const CompletedQuestList& obj)
    {
        writer.writeObjectStart();
        if (obj.getCompletedQuestListId())
        {
            writer.writePropertyName("completedQuestListId");
            writer.writeCharArray(*obj.getCompletedQuestListId());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.writeCharArray(*obj.getUserId());
        }
        if (obj.getQuestGroupName())
        {
            writer.writePropertyName("questGroupName");
            writer.writeCharArray(*obj.getQuestGroupName());
        }
        if (obj.getCompleteQuestNames())
        {
            writer.writePropertyName("completeQuestNames");
            writer.writeArrayStart();
            auto& list = *obj.getCompleteQuestNames();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                writer.writeCharArray(list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getCreatedAt())
        {
            writer.writePropertyName("createdAt");
            writer.writeInt64(*obj.getCreatedAt());
        }
        if (obj.getUpdatedAt())
        {
            writer.writePropertyName("updatedAt");
            writer.writeInt64(*obj.getUpdatedAt());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const QuestGroupModel& obj)
    {
        writer.writeObjectStart();
        if (obj.getQuestGroupModelId())
        {
            writer.writePropertyName("questGroupModelId");
            writer.writeCharArray(*obj.getQuestGroupModelId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*obj.getName());
        }
        if (obj.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.writeCharArray(*obj.getMetadata());
        }
        if (obj.getQuests())
        {
            writer.writePropertyName("quests");
            writer.writeArrayStart();
            auto& list = *obj.getQuests();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getChallengePeriodEventId())
        {
            writer.writePropertyName("challengePeriodEventId");
            writer.writeCharArray(*obj.getChallengePeriodEventId());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const QuestModel& obj)
    {
        writer.writeObjectStart();
        if (obj.getQuestModelId())
        {
            writer.writePropertyName("questModelId");
            writer.writeCharArray(*obj.getQuestModelId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*obj.getName());
        }
        if (obj.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.writeCharArray(*obj.getMetadata());
        }
        if (obj.getContents())
        {
            writer.writePropertyName("contents");
            writer.writeArrayStart();
            auto& list = *obj.getContents();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getChallengePeriodEventId())
        {
            writer.writePropertyName("challengePeriodEventId");
            writer.writeCharArray(*obj.getChallengePeriodEventId());
        }
        if (obj.getConsumeActions())
        {
            writer.writePropertyName("consumeActions");
            writer.writeArrayStart();
            auto& list = *obj.getConsumeActions();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getFailedAcquireActions())
        {
            writer.writePropertyName("failedAcquireActions");
            writer.writeArrayStart();
            auto& list = *obj.getFailedAcquireActions();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getPremiseQuestNames())
        {
            writer.writePropertyName("premiseQuestNames");
            writer.writeArrayStart();
            auto& list = *obj.getPremiseQuestNames();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                writer.writeCharArray(list[i]);
            }
            writer.writeArrayEnd();
        }
        writer.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
     */
    explicit Gs2QuestRestClient(Gs2RestSession& gs2RestSession) :
        AbstractGs2ClientBase(gs2RestSession)
    {
    }

	/**
	 * クエストを分類するカテゴリーの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeNamespaces(std::function<void(AsyncDescribeNamespacesResult&)> callback, DescribeNamespacesRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeNamespacesResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "quest");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/";

        Char joint[] = { '?', '\0' };
        if (request.getPageToken()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getPageToken(), sizeof(urlSafeValue));
            url += joint;
            url += "pageToken=";
            url += urlSafeValue;
            joint[0] = '&';
        }
        if (request.getLimit()) {
            url += joint;
            url += "limit=";
            url += detail::StringVariable(*request.getLimit()).c_str();
            joint[0] = '&';
        }
        httpRequest.SetURL(url.c_str());
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * クエストを分類するカテゴリーを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createNamespace(std::function<void(AsyncCreateNamespaceResult&)> callback, CreateNamespaceRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<CreateNamespaceResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "quest");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/";
        httpRequest.SetURL(url.c_str());
        detail::json::JsonWriter writer;

        writer.writeObjectStart();
        if (request.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*request.getName());
        }
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.writeCharArray(*request.getDescription());
        }
        if (request.getStartQuestTriggerScriptId())
        {
            writer.writePropertyName("startQuestTriggerScriptId");
            writer.writeCharArray(*request.getStartQuestTriggerScriptId());
        }
        if (request.getStartQuestDoneTriggerScriptId())
        {
            writer.writePropertyName("startQuestDoneTriggerScriptId");
            writer.writeCharArray(*request.getStartQuestDoneTriggerScriptId());
        }
        if (request.getStartQuestDoneTriggerQueueNamespaceId())
        {
            writer.writePropertyName("startQuestDoneTriggerQueueNamespaceId");
            writer.writeCharArray(*request.getStartQuestDoneTriggerQueueNamespaceId());
        }
        if (request.getCompleteQuestTriggerScriptId())
        {
            writer.writePropertyName("completeQuestTriggerScriptId");
            writer.writeCharArray(*request.getCompleteQuestTriggerScriptId());
        }
        if (request.getCompleteQuestDoneTriggerScriptId())
        {
            writer.writePropertyName("completeQuestDoneTriggerScriptId");
            writer.writeCharArray(*request.getCompleteQuestDoneTriggerScriptId());
        }
        if (request.getCompleteQuestDoneTriggerQueueNamespaceId())
        {
            writer.writePropertyName("completeQuestDoneTriggerQueueNamespaceId");
            writer.writeCharArray(*request.getCompleteQuestDoneTriggerQueueNamespaceId());
        }
        if (request.getFailedQuestTriggerScriptId())
        {
            writer.writePropertyName("failedQuestTriggerScriptId");
            writer.writeCharArray(*request.getFailedQuestTriggerScriptId());
        }
        if (request.getFailedQuestDoneTriggerScriptId())
        {
            writer.writePropertyName("failedQuestDoneTriggerScriptId");
            writer.writeCharArray(*request.getFailedQuestDoneTriggerScriptId());
        }
        if (request.getFailedQuestDoneTriggerQueueNamespaceId())
        {
            writer.writePropertyName("failedQuestDoneTriggerQueueNamespaceId");
            writer.writeCharArray(*request.getFailedQuestDoneTriggerQueueNamespaceId());
        }
        if (request.getQueueNamespaceId())
        {
            writer.writePropertyName("queueNamespaceId");
            writer.writeCharArray(*request.getQueueNamespaceId());
        }
        if (request.getKeyId())
        {
            writer.writePropertyName("keyId");
            writer.writeCharArray(*request.getKeyId());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * クエストを分類するカテゴリーの状態を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getNamespaceStatus(std::function<void(AsyncGetNamespaceStatusResult&)> callback, GetNamespaceStatusRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetNamespaceStatusResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "quest");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/status";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * クエストを分類するカテゴリーを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getNamespace(std::function<void(AsyncGetNamespaceResult&)> callback, GetNamespaceRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetNamespaceResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "quest");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * クエストを分類するカテゴリーを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateNamespace(std::function<void(AsyncUpdateNamespaceResult&)> callback, UpdateNamespaceRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<UpdateNamespaceResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("PUT");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "quest");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        detail::json::JsonWriter writer;

        writer.writeObjectStart();
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.writeCharArray(*request.getDescription());
        }
        if (request.getStartQuestTriggerScriptId())
        {
            writer.writePropertyName("startQuestTriggerScriptId");
            writer.writeCharArray(*request.getStartQuestTriggerScriptId());
        }
        if (request.getStartQuestDoneTriggerScriptId())
        {
            writer.writePropertyName("startQuestDoneTriggerScriptId");
            writer.writeCharArray(*request.getStartQuestDoneTriggerScriptId());
        }
        if (request.getStartQuestDoneTriggerQueueNamespaceId())
        {
            writer.writePropertyName("startQuestDoneTriggerQueueNamespaceId");
            writer.writeCharArray(*request.getStartQuestDoneTriggerQueueNamespaceId());
        }
        if (request.getCompleteQuestTriggerScriptId())
        {
            writer.writePropertyName("completeQuestTriggerScriptId");
            writer.writeCharArray(*request.getCompleteQuestTriggerScriptId());
        }
        if (request.getCompleteQuestDoneTriggerScriptId())
        {
            writer.writePropertyName("completeQuestDoneTriggerScriptId");
            writer.writeCharArray(*request.getCompleteQuestDoneTriggerScriptId());
        }
        if (request.getCompleteQuestDoneTriggerQueueNamespaceId())
        {
            writer.writePropertyName("completeQuestDoneTriggerQueueNamespaceId");
            writer.writeCharArray(*request.getCompleteQuestDoneTriggerQueueNamespaceId());
        }
        if (request.getFailedQuestTriggerScriptId())
        {
            writer.writePropertyName("failedQuestTriggerScriptId");
            writer.writeCharArray(*request.getFailedQuestTriggerScriptId());
        }
        if (request.getFailedQuestDoneTriggerScriptId())
        {
            writer.writePropertyName("failedQuestDoneTriggerScriptId");
            writer.writeCharArray(*request.getFailedQuestDoneTriggerScriptId());
        }
        if (request.getFailedQuestDoneTriggerQueueNamespaceId())
        {
            writer.writePropertyName("failedQuestDoneTriggerQueueNamespaceId");
            writer.writeCharArray(*request.getFailedQuestDoneTriggerQueueNamespaceId());
        }
        if (request.getQueueNamespaceId())
        {
            writer.writePropertyName("queueNamespaceId");
            writer.writeCharArray(*request.getQueueNamespaceId());
        }
        if (request.getKeyId())
        {
            writer.writePropertyName("keyId");
            writer.writeCharArray(*request.getKeyId());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * クエストを分類するカテゴリーを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteNamespace(std::function<void(AsyncDeleteNamespaceResult&)> callback, DeleteNamespaceRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DeleteNamespaceResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("DELETE");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "quest");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());
        {
            TArray<uint8> content(reinterpret_cast<const uint8*>("[]"), sizeof("[]") - 1);
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * クエストグループマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeQuestGroupModelMasters(std::function<void(AsyncDescribeQuestGroupModelMastersResult&)> callback, DescribeQuestGroupModelMastersRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeQuestGroupModelMastersResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "quest");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/group";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (request.getPageToken()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getPageToken(), sizeof(urlSafeValue));
            url += joint;
            url += "pageToken=";
            url += urlSafeValue;
            joint[0] = '&';
        }
        if (request.getLimit()) {
            url += joint;
            url += "limit=";
            url += detail::StringVariable(*request.getLimit()).c_str();
            joint[0] = '&';
        }
        httpRequest.SetURL(url.c_str());
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * クエストグループマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createQuestGroupModelMaster(std::function<void(AsyncCreateQuestGroupModelMasterResult&)> callback, CreateQuestGroupModelMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<CreateQuestGroupModelMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "quest");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/group";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        detail::json::JsonWriter writer;

        writer.writeObjectStart();
        if (request.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*request.getName());
        }
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.writeCharArray(*request.getDescription());
        }
        if (request.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.writeCharArray(*request.getMetadata());
        }
        if (request.getChallengePeriodEventId())
        {
            writer.writePropertyName("challengePeriodEventId");
            writer.writeCharArray(*request.getChallengePeriodEventId());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * クエストグループマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getQuestGroupModelMaster(std::function<void(AsyncGetQuestGroupModelMasterResult&)> callback, GetQuestGroupModelMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetQuestGroupModelMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "quest");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/group/{questGroupName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getQuestGroupName();
            url.replace("{questGroupName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * クエストグループマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateQuestGroupModelMaster(std::function<void(AsyncUpdateQuestGroupModelMasterResult&)> callback, UpdateQuestGroupModelMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<UpdateQuestGroupModelMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("PUT");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "quest");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/group/{questGroupName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getQuestGroupName();
            url.replace("{questGroupName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        detail::json::JsonWriter writer;

        writer.writeObjectStart();
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.writeCharArray(*request.getDescription());
        }
        if (request.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.writeCharArray(*request.getMetadata());
        }
        if (request.getChallengePeriodEventId())
        {
            writer.writePropertyName("challengePeriodEventId");
            writer.writeCharArray(*request.getChallengePeriodEventId());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * クエストグループマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteQuestGroupModelMaster(std::function<void(AsyncDeleteQuestGroupModelMasterResult&)> callback, DeleteQuestGroupModelMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DeleteQuestGroupModelMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("DELETE");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "quest");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/group/{questGroupName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getQuestGroupName();
            url.replace("{questGroupName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());
        {
            TArray<uint8> content(reinterpret_cast<const uint8*>("[]"), sizeof("[]") - 1);
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * クエストモデルマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeQuestModelMasters(std::function<void(AsyncDescribeQuestModelMastersResult&)> callback, DescribeQuestModelMastersRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeQuestModelMastersResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "quest");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/group/{questGroupName}/quest";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getQuestGroupName();
            url.replace("{questGroupName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (request.getPageToken()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getPageToken(), sizeof(urlSafeValue));
            url += joint;
            url += "pageToken=";
            url += urlSafeValue;
            joint[0] = '&';
        }
        if (request.getLimit()) {
            url += joint;
            url += "limit=";
            url += detail::StringVariable(*request.getLimit()).c_str();
            joint[0] = '&';
        }
        httpRequest.SetURL(url.c_str());
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * クエストモデルマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createQuestModelMaster(std::function<void(AsyncCreateQuestModelMasterResult&)> callback, CreateQuestModelMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<CreateQuestModelMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "quest");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/group/{questGroupName}/quest";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getQuestGroupName();
            url.replace("{questGroupName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        detail::json::JsonWriter writer;

        writer.writeObjectStart();
        if (request.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*request.getName());
        }
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.writeCharArray(*request.getDescription());
        }
        if (request.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.writeCharArray(*request.getMetadata());
        }
        if (request.getContents())
        {
            writer.writePropertyName("contents");
            writer.writeArrayStart();
            auto& list = *request.getContents();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        if (request.getChallengePeriodEventId())
        {
            writer.writePropertyName("challengePeriodEventId");
            writer.writeCharArray(*request.getChallengePeriodEventId());
        }
        if (request.getConsumeActions())
        {
            writer.writePropertyName("consumeActions");
            writer.writeArrayStart();
            auto& list = *request.getConsumeActions();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        if (request.getFailedAcquireActions())
        {
            writer.writePropertyName("failedAcquireActions");
            writer.writeArrayStart();
            auto& list = *request.getFailedAcquireActions();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        if (request.getPremiseQuestNames())
        {
            writer.writePropertyName("premiseQuestNames");
            writer.writeArrayStart();
            auto& list = *request.getPremiseQuestNames();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                writer.writeCharArray(list[i]);
            }
            writer.writeArrayEnd();
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * クエストモデルマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getQuestModelMaster(std::function<void(AsyncGetQuestModelMasterResult&)> callback, GetQuestModelMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetQuestModelMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "quest");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/group/{questGroupName}/quest/{questName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getQuestGroupName();
            url.replace("{questGroupName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getQuestName();
            url.replace("{questName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * クエストモデルマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateQuestModelMaster(std::function<void(AsyncUpdateQuestModelMasterResult&)> callback, UpdateQuestModelMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<UpdateQuestModelMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("PUT");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "quest");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/group/{questGroupName}/quest/{questName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getQuestGroupName();
            url.replace("{questGroupName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getQuestName();
            url.replace("{questName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        detail::json::JsonWriter writer;

        writer.writeObjectStart();
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.writeCharArray(*request.getDescription());
        }
        if (request.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.writeCharArray(*request.getMetadata());
        }
        if (request.getContents())
        {
            writer.writePropertyName("contents");
            writer.writeArrayStart();
            auto& list = *request.getContents();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        if (request.getChallengePeriodEventId())
        {
            writer.writePropertyName("challengePeriodEventId");
            writer.writeCharArray(*request.getChallengePeriodEventId());
        }
        if (request.getConsumeActions())
        {
            writer.writePropertyName("consumeActions");
            writer.writeArrayStart();
            auto& list = *request.getConsumeActions();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        if (request.getFailedAcquireActions())
        {
            writer.writePropertyName("failedAcquireActions");
            writer.writeArrayStart();
            auto& list = *request.getFailedAcquireActions();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        if (request.getPremiseQuestNames())
        {
            writer.writePropertyName("premiseQuestNames");
            writer.writeArrayStart();
            auto& list = *request.getPremiseQuestNames();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                writer.writeCharArray(list[i]);
            }
            writer.writeArrayEnd();
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * クエストモデルマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteQuestModelMaster(std::function<void(AsyncDeleteQuestModelMasterResult&)> callback, DeleteQuestModelMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DeleteQuestModelMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("DELETE");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "quest");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/group/{questGroupName}/quest/{questName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getQuestGroupName();
            url.replace("{questGroupName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getQuestName();
            url.replace("{questName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());
        {
            TArray<uint8> content(reinterpret_cast<const uint8*>("[]"), sizeof("[]") - 1);
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * 現在有効なクエストマスターのマスターデータをエクスポートします<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void exportMaster(std::function<void(AsyncExportMasterResult&)> callback, ExportMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<ExportMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "quest");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/export";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * 現在有効な現在有効なクエストマスターを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentQuestMaster(std::function<void(AsyncGetCurrentQuestMasterResult&)> callback, GetCurrentQuestMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetCurrentQuestMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "quest");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * 現在有効な現在有効なクエストマスターを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentQuestMaster(std::function<void(AsyncUpdateCurrentQuestMasterResult&)> callback, UpdateCurrentQuestMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<UpdateCurrentQuestMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("PUT");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "quest");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        detail::json::JsonWriter writer;

        writer.writeObjectStart();
        if (request.getSettings())
        {
            writer.writePropertyName("settings");
            writer.writeCharArray(*request.getSettings());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * 現在有効な現在有効なクエストマスターを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentQuestMasterFromGitHub(std::function<void(AsyncUpdateCurrentQuestMasterFromGitHubResult&)> callback, UpdateCurrentQuestMasterFromGitHubRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<UpdateCurrentQuestMasterFromGitHubResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("PUT");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "quest");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/from_git_hub";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        detail::json::JsonWriter writer;

        writer.writeObjectStart();
        if (request.getCheckoutSetting())
        {
            writer.writePropertyName("checkoutSetting");
            write(writer, *request.getCheckoutSetting());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * クエスト挑戦の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeProgressesByUserId(std::function<void(AsyncDescribeProgressesByUserIdResult&)> callback, DescribeProgressesByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeProgressesByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "quest");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/progress";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (request.getUserId()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getUserId(), sizeof(urlSafeValue));
            url += joint;
            url += "userId=";
            url += urlSafeValue;
            joint[0] = '&';
        }
        if (request.getPageToken()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getPageToken(), sizeof(urlSafeValue));
            url += joint;
            url += "pageToken=";
            url += urlSafeValue;
            joint[0] = '&';
        }
        if (request.getLimit()) {
            url += joint;
            url += "limit=";
            url += detail::StringVariable(*request.getLimit()).c_str();
            joint[0] = '&';
        }
        httpRequest.SetURL(url.c_str());
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ユーザIDを指定してクエスト挑戦を作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createProgressByUserId(std::function<void(AsyncCreateProgressByUserIdResult&)> callback, CreateProgressByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<CreateProgressByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "quest");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/progress";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        detail::json::JsonWriter writer;

        writer.writeObjectStart();
        if (request.getQuestModelId())
        {
            writer.writePropertyName("questModelId");
            writer.writeCharArray(*request.getQuestModelId());
        }
        if (request.getForce())
        {
            writer.writePropertyName("force");
            writer.writeBool(*request.getForce());
        }
        if (request.getConfig())
        {
            writer.writePropertyName("config");
            writer.writeArrayStart();
            auto& list = *request.getConfig();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * クエスト挑戦を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getProgress(std::function<void(AsyncGetProgressResult&)> callback, GetProgressRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetProgressResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "quest");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/me/progress";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ユーザIDを指定してクエスト挑戦を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getProgressByUserId(std::function<void(AsyncGetProgressByUserIdResult&)> callback, GetProgressByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetProgressByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "quest");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/progress";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
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
    void start(std::function<void(AsyncStartResult&)> callback, StartRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<StartResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "quest");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/me/progress/group/{questGroupName}/quest/{questName}/start";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getQuestGroupName();
            url.replace("{questGroupName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getQuestName();
            url.replace("{questName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        detail::json::JsonWriter writer;

        writer.writeObjectStart();
        if (request.getForce())
        {
            writer.writePropertyName("force");
            writer.writeBool(*request.getForce());
        }
        if (request.getConfig())
        {
            writer.writePropertyName("config");
            writer.writeArrayStart();
            auto& list = *request.getConfig();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
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
    void startByUserId(std::function<void(AsyncStartByUserIdResult&)> callback, StartByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<StartByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "quest");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/progress/group/{questGroupName}/quest/{questName}/start";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getQuestGroupName();
            url.replace("{questGroupName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getQuestName();
            url.replace("{questName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        detail::json::JsonWriter writer;

        writer.writeObjectStart();
        if (request.getForce())
        {
            writer.writePropertyName("force");
            writer.writeBool(*request.getForce());
        }
        if (request.getConfig())
        {
            writer.writePropertyName("config");
            writer.writeArrayStart();
            auto& list = *request.getConfig();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
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
    void end(std::function<void(AsyncEndResult&)> callback, EndRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<EndResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "quest");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/me/progress/end";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        detail::json::JsonWriter writer;

        writer.writeObjectStart();
        if (request.getTransactionId())
        {
            writer.writePropertyName("transactionId");
            writer.writeCharArray(*request.getTransactionId());
        }
        if (request.getRewards())
        {
            writer.writePropertyName("rewards");
            writer.writeArrayStart();
            auto& list = *request.getRewards();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        if (request.getIsComplete())
        {
            writer.writePropertyName("isComplete");
            writer.writeBool(*request.getIsComplete());
        }
        if (request.getConfig())
        {
            writer.writePropertyName("config");
            writer.writeArrayStart();
            auto& list = *request.getConfig();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
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
    void endByUserId(std::function<void(AsyncEndByUserIdResult&)> callback, EndByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<EndByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "quest");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/progress/end";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        detail::json::JsonWriter writer;

        writer.writeObjectStart();
        if (request.getTransactionId())
        {
            writer.writePropertyName("transactionId");
            writer.writeCharArray(*request.getTransactionId());
        }
        if (request.getRewards())
        {
            writer.writePropertyName("rewards");
            writer.writeArrayStart();
            auto& list = *request.getRewards();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        if (request.getIsComplete())
        {
            writer.writePropertyName("isComplete");
            writer.writeBool(*request.getIsComplete());
        }
        if (request.getConfig())
        {
            writer.writePropertyName("config");
            writer.writeArrayStart();
            auto& list = *request.getConfig();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * クエスト挑戦を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteProgress(std::function<void(AsyncDeleteProgressResult&)> callback, DeleteProgressRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DeleteProgressResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("DELETE");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "quest");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/me/progress";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());
        {
            TArray<uint8> content(reinterpret_cast<const uint8*>("[]"), sizeof("[]") - 1);
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ユーザIDを指定してクエスト挑戦を削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteProgressByUserId(std::function<void(AsyncDeleteProgressByUserIdResult&)> callback, DeleteProgressByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DeleteProgressByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("DELETE");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "quest");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/progress";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());
        {
            TArray<uint8> content(reinterpret_cast<const uint8*>("[]"), sizeof("[]") - 1);
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * スタンプシートでクエストを開始<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createProgressByStampSheet(std::function<void(AsyncCreateProgressByStampSheetResult&)> callback, CreateProgressByStampSheetRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<CreateProgressByStampSheetResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "quest");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/stamp/progress/create";
        httpRequest.SetURL(url.c_str());
        detail::json::JsonWriter writer;

        writer.writeObjectStart();
        if (request.getStampSheet())
        {
            writer.writePropertyName("stampSheet");
            writer.writeCharArray(*request.getStampSheet());
        }
        if (request.getKeyId())
        {
            writer.writePropertyName("keyId");
            writer.writeCharArray(*request.getKeyId());
        }
        if (request.getConfig())
        {
            writer.writePropertyName("config");
            writer.writeArrayStart();
            auto& list = *request.getConfig();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * クエスト進行の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCompletedQuestLists(std::function<void(AsyncDescribeCompletedQuestListsResult&)> callback, DescribeCompletedQuestListsRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeCompletedQuestListsResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "quest");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/me/completed";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (request.getPageToken()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getPageToken(), sizeof(urlSafeValue));
            url += joint;
            url += "pageToken=";
            url += urlSafeValue;
            joint[0] = '&';
        }
        if (request.getLimit()) {
            url += joint;
            url += "limit=";
            url += detail::StringVariable(*request.getLimit()).c_str();
            joint[0] = '&';
        }
        httpRequest.SetURL(url.c_str());
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ユーザIDを指定してクエスト進行の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCompletedQuestListsByUserId(std::function<void(AsyncDescribeCompletedQuestListsByUserIdResult&)> callback, DescribeCompletedQuestListsByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeCompletedQuestListsByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "quest");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/completed";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (request.getPageToken()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getPageToken(), sizeof(urlSafeValue));
            url += joint;
            url += "pageToken=";
            url += urlSafeValue;
            joint[0] = '&';
        }
        if (request.getLimit()) {
            url += joint;
            url += "limit=";
            url += detail::StringVariable(*request.getLimit()).c_str();
            joint[0] = '&';
        }
        httpRequest.SetURL(url.c_str());
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * クエスト進行を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCompletedQuestList(std::function<void(AsyncGetCompletedQuestListResult&)> callback, GetCompletedQuestListRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetCompletedQuestListResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "quest");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/me/completed/group/{questGroupName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getQuestGroupName();
            url.replace("{questGroupName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ユーザIDを指定してクエスト進行を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCompletedQuestListByUserId(std::function<void(AsyncGetCompletedQuestListByUserIdResult&)> callback, GetCompletedQuestListByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetCompletedQuestListByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "quest");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/completed/group/{questGroupName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getQuestGroupName();
            url.replace("{questGroupName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ユーザIDを指定してクエスト進行を削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteCompletedQuestListByUserId(std::function<void(AsyncDeleteCompletedQuestListByUserIdResult&)> callback, DeleteCompletedQuestListByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DeleteCompletedQuestListByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("DELETE");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "quest");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/completed/group/{questGroupName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getQuestGroupName();
            url.replace("{questGroupName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());
        {
            TArray<uint8> content(reinterpret_cast<const uint8*>("[]"), sizeof("[]") - 1);
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * クエストグループの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeQuestGroupModels(std::function<void(AsyncDescribeQuestGroupModelsResult&)> callback, DescribeQuestGroupModelsRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeQuestGroupModelsResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "quest");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/group";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * クエストグループを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getQuestGroupModel(std::function<void(AsyncGetQuestGroupModelResult&)> callback, GetQuestGroupModelRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetQuestGroupModelResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "quest");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/group/{questGroupName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getQuestGroupName();
            url.replace("{questGroupName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * クエストモデルの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeQuestModels(std::function<void(AsyncDescribeQuestModelsResult&)> callback, DescribeQuestModelsRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeQuestModelsResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "quest");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/group/{questGroupName}/quest";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getQuestGroupName();
            url.replace("{questGroupName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * クエストモデルを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getQuestModel(std::function<void(AsyncGetQuestModelResult&)> callback, GetQuestModelRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetQuestModelResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "quest");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/group/{questGroupName}/quest/{questName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getQuestGroupName();
            url.replace("{questGroupName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getQuestName();
            url.replace("{questName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

protected:
    Gs2RestSession& getGs2RestSession()
    {
        return static_cast<Gs2RestSession&>(getGs2Session());
    }
};

} }

#endif //GS2_QUEST_GS2QUESTRESTCLIENT_HPP_