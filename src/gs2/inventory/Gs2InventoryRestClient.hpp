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

#ifndef GS2_INVENTORY_GS2INVENTORYRESTCLIENT_HPP_
#define GS2_INVENTORY_GS2INVENTORYRESTCLIENT_HPP_

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
#include "request/DescribeInventoryModelMastersRequest.hpp"
#include "request/CreateInventoryModelMasterRequest.hpp"
#include "request/GetInventoryModelMasterRequest.hpp"
#include "request/UpdateInventoryModelMasterRequest.hpp"
#include "request/DeleteInventoryModelMasterRequest.hpp"
#include "request/DescribeInventoryModelsRequest.hpp"
#include "request/GetInventoryModelRequest.hpp"
#include "request/DescribeItemModelMastersRequest.hpp"
#include "request/CreateItemModelMasterRequest.hpp"
#include "request/GetItemModelMasterRequest.hpp"
#include "request/UpdateItemModelMasterRequest.hpp"
#include "request/DeleteItemModelMasterRequest.hpp"
#include "request/DescribeItemModelsRequest.hpp"
#include "request/GetItemModelRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentItemModelMasterRequest.hpp"
#include "request/UpdateCurrentItemModelMasterRequest.hpp"
#include "request/UpdateCurrentItemModelMasterFromGitHubRequest.hpp"
#include "request/DescribeInventoriesRequest.hpp"
#include "request/DescribeInventoriesByUserIdRequest.hpp"
#include "request/GetInventoryRequest.hpp"
#include "request/GetInventoryByUserIdRequest.hpp"
#include "request/AddCapacityByUserIdRequest.hpp"
#include "request/SetCapacityByUserIdRequest.hpp"
#include "request/DeleteInventoryByUserIdRequest.hpp"
#include "request/AddCapacityByStampSheetRequest.hpp"
#include "request/SetCapacityByStampSheetRequest.hpp"
#include "request/DescribeItemSetsRequest.hpp"
#include "request/DescribeItemSetsByUserIdRequest.hpp"
#include "request/GetItemSetRequest.hpp"
#include "request/GetItemSetByUserIdRequest.hpp"
#include "request/AcquireItemSetByUserIdRequest.hpp"
#include "request/ConsumeItemSetRequest.hpp"
#include "request/ConsumeItemSetByUserIdRequest.hpp"
#include "request/DeleteItemSetByUserIdRequest.hpp"
#include "request/AcquireItemSetByStampSheetRequest.hpp"
#include "request/ConsumeItemSetByStampTaskRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeInventoryModelMastersResult.hpp"
#include "result/CreateInventoryModelMasterResult.hpp"
#include "result/GetInventoryModelMasterResult.hpp"
#include "result/UpdateInventoryModelMasterResult.hpp"
#include "result/DeleteInventoryModelMasterResult.hpp"
#include "result/DescribeInventoryModelsResult.hpp"
#include "result/GetInventoryModelResult.hpp"
#include "result/DescribeItemModelMastersResult.hpp"
#include "result/CreateItemModelMasterResult.hpp"
#include "result/GetItemModelMasterResult.hpp"
#include "result/UpdateItemModelMasterResult.hpp"
#include "result/DeleteItemModelMasterResult.hpp"
#include "result/DescribeItemModelsResult.hpp"
#include "result/GetItemModelResult.hpp"
#include "result/ExportMasterResult.hpp"
#include "result/GetCurrentItemModelMasterResult.hpp"
#include "result/UpdateCurrentItemModelMasterResult.hpp"
#include "result/UpdateCurrentItemModelMasterFromGitHubResult.hpp"
#include "result/DescribeInventoriesResult.hpp"
#include "result/DescribeInventoriesByUserIdResult.hpp"
#include "result/GetInventoryResult.hpp"
#include "result/GetInventoryByUserIdResult.hpp"
#include "result/AddCapacityByUserIdResult.hpp"
#include "result/SetCapacityByUserIdResult.hpp"
#include "result/DeleteInventoryByUserIdResult.hpp"
#include "result/AddCapacityByStampSheetResult.hpp"
#include "result/SetCapacityByStampSheetResult.hpp"
#include "result/DescribeItemSetsResult.hpp"
#include "result/DescribeItemSetsByUserIdResult.hpp"
#include "result/GetItemSetResult.hpp"
#include "result/GetItemSetByUserIdResult.hpp"
#include "result/AcquireItemSetByUserIdResult.hpp"
#include "result/ConsumeItemSetResult.hpp"
#include "result/ConsumeItemSetByUserIdResult.hpp"
#include "result/DeleteItemSetByUserIdResult.hpp"
#include "result/AcquireItemSetByStampSheetResult.hpp"
#include "result/ConsumeItemSetByStampTaskResult.hpp"
#include <cstring>

namespace gs2 { namespace inventory {

typedef AsyncResult<DescribeNamespacesResult> AsyncDescribeNamespacesResult;
typedef AsyncResult<CreateNamespaceResult> AsyncCreateNamespaceResult;
typedef AsyncResult<GetNamespaceStatusResult> AsyncGetNamespaceStatusResult;
typedef AsyncResult<GetNamespaceResult> AsyncGetNamespaceResult;
typedef AsyncResult<UpdateNamespaceResult> AsyncUpdateNamespaceResult;
typedef AsyncResult<DeleteNamespaceResult> AsyncDeleteNamespaceResult;
typedef AsyncResult<DescribeInventoryModelMastersResult> AsyncDescribeInventoryModelMastersResult;
typedef AsyncResult<CreateInventoryModelMasterResult> AsyncCreateInventoryModelMasterResult;
typedef AsyncResult<GetInventoryModelMasterResult> AsyncGetInventoryModelMasterResult;
typedef AsyncResult<UpdateInventoryModelMasterResult> AsyncUpdateInventoryModelMasterResult;
typedef AsyncResult<DeleteInventoryModelMasterResult> AsyncDeleteInventoryModelMasterResult;
typedef AsyncResult<DescribeInventoryModelsResult> AsyncDescribeInventoryModelsResult;
typedef AsyncResult<GetInventoryModelResult> AsyncGetInventoryModelResult;
typedef AsyncResult<DescribeItemModelMastersResult> AsyncDescribeItemModelMastersResult;
typedef AsyncResult<CreateItemModelMasterResult> AsyncCreateItemModelMasterResult;
typedef AsyncResult<GetItemModelMasterResult> AsyncGetItemModelMasterResult;
typedef AsyncResult<UpdateItemModelMasterResult> AsyncUpdateItemModelMasterResult;
typedef AsyncResult<DeleteItemModelMasterResult> AsyncDeleteItemModelMasterResult;
typedef AsyncResult<DescribeItemModelsResult> AsyncDescribeItemModelsResult;
typedef AsyncResult<GetItemModelResult> AsyncGetItemModelResult;
typedef AsyncResult<ExportMasterResult> AsyncExportMasterResult;
typedef AsyncResult<GetCurrentItemModelMasterResult> AsyncGetCurrentItemModelMasterResult;
typedef AsyncResult<UpdateCurrentItemModelMasterResult> AsyncUpdateCurrentItemModelMasterResult;
typedef AsyncResult<UpdateCurrentItemModelMasterFromGitHubResult> AsyncUpdateCurrentItemModelMasterFromGitHubResult;
typedef AsyncResult<DescribeInventoriesResult> AsyncDescribeInventoriesResult;
typedef AsyncResult<DescribeInventoriesByUserIdResult> AsyncDescribeInventoriesByUserIdResult;
typedef AsyncResult<GetInventoryResult> AsyncGetInventoryResult;
typedef AsyncResult<GetInventoryByUserIdResult> AsyncGetInventoryByUserIdResult;
typedef AsyncResult<AddCapacityByUserIdResult> AsyncAddCapacityByUserIdResult;
typedef AsyncResult<SetCapacityByUserIdResult> AsyncSetCapacityByUserIdResult;
typedef AsyncResult<DeleteInventoryByUserIdResult> AsyncDeleteInventoryByUserIdResult;
typedef AsyncResult<AddCapacityByStampSheetResult> AsyncAddCapacityByStampSheetResult;
typedef AsyncResult<SetCapacityByStampSheetResult> AsyncSetCapacityByStampSheetResult;
typedef AsyncResult<DescribeItemSetsResult> AsyncDescribeItemSetsResult;
typedef AsyncResult<DescribeItemSetsByUserIdResult> AsyncDescribeItemSetsByUserIdResult;
typedef AsyncResult<GetItemSetResult> AsyncGetItemSetResult;
typedef AsyncResult<GetItemSetByUserIdResult> AsyncGetItemSetByUserIdResult;
typedef AsyncResult<AcquireItemSetByUserIdResult> AsyncAcquireItemSetByUserIdResult;
typedef AsyncResult<ConsumeItemSetResult> AsyncConsumeItemSetResult;
typedef AsyncResult<ConsumeItemSetByUserIdResult> AsyncConsumeItemSetByUserIdResult;
typedef AsyncResult<DeleteItemSetByUserIdResult> AsyncDeleteItemSetByUserIdResult;
typedef AsyncResult<AcquireItemSetByStampSheetResult> AsyncAcquireItemSetByStampSheetResult;
typedef AsyncResult<ConsumeItemSetByStampTaskResult> AsyncConsumeItemSetByStampTaskResult;

/**
 * GS2 Inventory API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2InventoryRestClient : public AbstractGs2ClientBase
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
        if (obj.getAcquireTriggerScriptId())
        {
            writer.writePropertyName("acquireTriggerScriptId");
            writer.writeCharArray(*obj.getAcquireTriggerScriptId());
        }
        if (obj.getAcquireDoneTriggerScriptId())
        {
            writer.writePropertyName("acquireDoneTriggerScriptId");
            writer.writeCharArray(*obj.getAcquireDoneTriggerScriptId());
        }
        if (obj.getAcquireDoneTriggerQueueNamespaceId())
        {
            writer.writePropertyName("acquireDoneTriggerQueueNamespaceId");
            writer.writeCharArray(*obj.getAcquireDoneTriggerQueueNamespaceId());
        }
        if (obj.getOverflowTriggerScriptId())
        {
            writer.writePropertyName("overflowTriggerScriptId");
            writer.writeCharArray(*obj.getOverflowTriggerScriptId());
        }
        if (obj.getOverflowTriggerQueueNamespaceId())
        {
            writer.writePropertyName("overflowTriggerQueueNamespaceId");
            writer.writeCharArray(*obj.getOverflowTriggerQueueNamespaceId());
        }
        if (obj.getConsumeTriggerScriptId())
        {
            writer.writePropertyName("consumeTriggerScriptId");
            writer.writeCharArray(*obj.getConsumeTriggerScriptId());
        }
        if (obj.getConsumeDoneTriggerScriptId())
        {
            writer.writePropertyName("consumeDoneTriggerScriptId");
            writer.writeCharArray(*obj.getConsumeDoneTriggerScriptId());
        }
        if (obj.getConsumeDoneTriggerQueueNamespaceId())
        {
            writer.writePropertyName("consumeDoneTriggerQueueNamespaceId");
            writer.writeCharArray(*obj.getConsumeDoneTriggerQueueNamespaceId());
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

    static void write(detail::json::JsonWriter& writer, const InventoryModelMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getInventoryModelId())
        {
            writer.writePropertyName("inventoryModelId");
            writer.writeCharArray(*obj.getInventoryModelId());
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
        if (obj.getDescription())
        {
            writer.writePropertyName("description");
            writer.writeCharArray(*obj.getDescription());
        }
        if (obj.getInitialCapacity())
        {
            writer.writePropertyName("initialCapacity");
            writer.writeInt32(*obj.getInitialCapacity());
        }
        if (obj.getMaxCapacity())
        {
            writer.writePropertyName("maxCapacity");
            writer.writeInt32(*obj.getMaxCapacity());
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

    static void write(detail::json::JsonWriter& writer, const InventoryModel& obj)
    {
        writer.writeObjectStart();
        if (obj.getInventoryModelId())
        {
            writer.writePropertyName("inventoryModelId");
            writer.writeCharArray(*obj.getInventoryModelId());
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
        if (obj.getInitialCapacity())
        {
            writer.writePropertyName("initialCapacity");
            writer.writeInt32(*obj.getInitialCapacity());
        }
        if (obj.getMaxCapacity())
        {
            writer.writePropertyName("maxCapacity");
            writer.writeInt32(*obj.getMaxCapacity());
        }
        if (obj.getItemModels())
        {
            writer.writePropertyName("itemModels");
            writer.writeArrayStart();
            auto& list = *obj.getItemModels();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const ItemModelMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getItemModelId())
        {
            writer.writePropertyName("itemModelId");
            writer.writeCharArray(*obj.getItemModelId());
        }
        if (obj.getInventoryName())
        {
            writer.writePropertyName("inventoryName");
            writer.writeCharArray(*obj.getInventoryName());
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
        if (obj.getMaxCount())
        {
            writer.writePropertyName("maxCount");
            writer.writeInt64(*obj.getMaxCount());
        }
        if (obj.getSortValue())
        {
            writer.writePropertyName("sortValue");
            writer.writeInt32(*obj.getSortValue());
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

    static void write(detail::json::JsonWriter& writer, const ItemModel& obj)
    {
        writer.writeObjectStart();
        if (obj.getItemModelId())
        {
            writer.writePropertyName("itemModelId");
            writer.writeCharArray(*obj.getItemModelId());
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
        if (obj.getMaxCount())
        {
            writer.writePropertyName("maxCount");
            writer.writeInt64(*obj.getMaxCount());
        }
        if (obj.getSortValue())
        {
            writer.writePropertyName("sortValue");
            writer.writeInt32(*obj.getSortValue());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const CurrentItemModelMaster& obj)
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

    static void write(detail::json::JsonWriter& writer, const Inventory& obj)
    {
        writer.writeObjectStart();
        if (obj.getInventoryId())
        {
            writer.writePropertyName("inventoryId");
            writer.writeCharArray(*obj.getInventoryId());
        }
        if (obj.getInventoryName())
        {
            writer.writePropertyName("inventoryName");
            writer.writeCharArray(*obj.getInventoryName());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.writeCharArray(*obj.getUserId());
        }
        if (obj.getCurrentInventoryCapacityUsage())
        {
            writer.writePropertyName("currentInventoryCapacityUsage");
            writer.writeInt32(*obj.getCurrentInventoryCapacityUsage());
        }
        if (obj.getCurrentInventoryMaxCapacity())
        {
            writer.writePropertyName("currentInventoryMaxCapacity");
            writer.writeInt32(*obj.getCurrentInventoryMaxCapacity());
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

    static void write(detail::json::JsonWriter& writer, const ItemSet& obj)
    {
        writer.writeObjectStart();
        if (obj.getItemSetId())
        {
            writer.writePropertyName("itemSetId");
            writer.writeCharArray(*obj.getItemSetId());
        }
        if (obj.getInventoryName())
        {
            writer.writePropertyName("inventoryName");
            writer.writeCharArray(*obj.getInventoryName());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.writeCharArray(*obj.getUserId());
        }
        if (obj.getItemName())
        {
            writer.writePropertyName("itemName");
            writer.writeCharArray(*obj.getItemName());
        }
        if (obj.getCount())
        {
            writer.writePropertyName("count");
            writer.writeInt64(*obj.getCount());
        }
        if (obj.getSortValue())
        {
            writer.writePropertyName("sortValue");
            writer.writeInt32(*obj.getSortValue());
        }
        if (obj.getExpiresAt())
        {
            writer.writePropertyName("expiresAt");
            writer.writeInt64(*obj.getExpiresAt());
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



public:
    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
     */
    explicit Gs2InventoryRestClient(Gs2RestSession& gs2RestSession) :
        AbstractGs2ClientBase(gs2RestSession)
    {
    }

	/**
	 * ネームスペースの一覧を取得<br>
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
        url.replace("{service}", "inventory");
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
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ネームスペースを新規作成<br>
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
        url.replace("{service}", "inventory");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/";
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
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
        if (request.getAcquireTriggerScriptId())
        {
            writer.writePropertyName("acquireTriggerScriptId");
            writer.writeCharArray(*request.getAcquireTriggerScriptId());
        }
        if (request.getAcquireDoneTriggerScriptId())
        {
            writer.writePropertyName("acquireDoneTriggerScriptId");
            writer.writeCharArray(*request.getAcquireDoneTriggerScriptId());
        }
        if (request.getAcquireDoneTriggerQueueNamespaceId())
        {
            writer.writePropertyName("acquireDoneTriggerQueueNamespaceId");
            writer.writeCharArray(*request.getAcquireDoneTriggerQueueNamespaceId());
        }
        if (request.getOverflowTriggerScriptId())
        {
            writer.writePropertyName("overflowTriggerScriptId");
            writer.writeCharArray(*request.getOverflowTriggerScriptId());
        }
        if (request.getOverflowTriggerQueueNamespaceId())
        {
            writer.writePropertyName("overflowTriggerQueueNamespaceId");
            writer.writeCharArray(*request.getOverflowTriggerQueueNamespaceId());
        }
        if (request.getConsumeTriggerScriptId())
        {
            writer.writePropertyName("consumeTriggerScriptId");
            writer.writeCharArray(*request.getConsumeTriggerScriptId());
        }
        if (request.getConsumeDoneTriggerScriptId())
        {
            writer.writePropertyName("consumeDoneTriggerScriptId");
            writer.writeCharArray(*request.getConsumeDoneTriggerScriptId());
        }
        if (request.getConsumeDoneTriggerQueueNamespaceId())
        {
            writer.writePropertyName("consumeDoneTriggerQueueNamespaceId");
            writer.writeCharArray(*request.getConsumeDoneTriggerQueueNamespaceId());
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
        gs2RestSessionTask.execute();
    }

	/**
	 * ネームスペースの状態を取得<br>
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
        url.replace("{service}", "inventory");
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
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ネームスペースを取得<br>
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
        url.replace("{service}", "inventory");
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
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ネームスペースを更新<br>
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
        url.replace("{service}", "inventory");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.writeCharArray(*request.getDescription());
        }
        if (request.getAcquireTriggerScriptId())
        {
            writer.writePropertyName("acquireTriggerScriptId");
            writer.writeCharArray(*request.getAcquireTriggerScriptId());
        }
        if (request.getAcquireDoneTriggerScriptId())
        {
            writer.writePropertyName("acquireDoneTriggerScriptId");
            writer.writeCharArray(*request.getAcquireDoneTriggerScriptId());
        }
        if (request.getAcquireDoneTriggerQueueNamespaceId())
        {
            writer.writePropertyName("acquireDoneTriggerQueueNamespaceId");
            writer.writeCharArray(*request.getAcquireDoneTriggerQueueNamespaceId());
        }
        if (request.getOverflowTriggerScriptId())
        {
            writer.writePropertyName("overflowTriggerScriptId");
            writer.writeCharArray(*request.getOverflowTriggerScriptId());
        }
        if (request.getOverflowTriggerQueueNamespaceId())
        {
            writer.writePropertyName("overflowTriggerQueueNamespaceId");
            writer.writeCharArray(*request.getOverflowTriggerQueueNamespaceId());
        }
        if (request.getConsumeTriggerScriptId())
        {
            writer.writePropertyName("consumeTriggerScriptId");
            writer.writeCharArray(*request.getConsumeTriggerScriptId());
        }
        if (request.getConsumeDoneTriggerScriptId())
        {
            writer.writePropertyName("consumeDoneTriggerScriptId");
            writer.writeCharArray(*request.getConsumeDoneTriggerScriptId());
        }
        if (request.getConsumeDoneTriggerQueueNamespaceId())
        {
            writer.writePropertyName("consumeDoneTriggerQueueNamespaceId");
            writer.writeCharArray(*request.getConsumeDoneTriggerQueueNamespaceId());
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
        gs2RestSessionTask.execute();
    }

	/**
	 * ネームスペースを削除<br>
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
        url.replace("{service}", "inventory");
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
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * インベントリモデルマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeInventoryModelMasters(std::function<void(AsyncDescribeInventoryModelMastersResult&)> callback, DescribeInventoryModelMastersRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeInventoryModelMastersResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "inventory");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/inventory";
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
        gs2RestSessionTask.execute();
    }

	/**
	 * インベントリモデルマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createInventoryModelMaster(std::function<void(AsyncCreateInventoryModelMasterResult&)> callback, CreateInventoryModelMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<CreateInventoryModelMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "inventory");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/inventory";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
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
        if (request.getInitialCapacity())
        {
            writer.writePropertyName("initialCapacity");
            writer.writeInt32(*request.getInitialCapacity());
        }
        if (request.getMaxCapacity())
        {
            writer.writePropertyName("maxCapacity");
            writer.writeInt32(*request.getMaxCapacity());
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
        gs2RestSessionTask.execute();
    }

	/**
	 * インベントリモデルマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getInventoryModelMaster(std::function<void(AsyncGetInventoryModelMasterResult&)> callback, GetInventoryModelMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetInventoryModelMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "inventory");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/inventory/{inventoryName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        gs2RestSessionTask.execute();
    }

	/**
	 * インベントリモデルマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateInventoryModelMaster(std::function<void(AsyncUpdateInventoryModelMasterResult&)> callback, UpdateInventoryModelMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<UpdateInventoryModelMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("PUT");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "inventory");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/inventory/{inventoryName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
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
        if (request.getInitialCapacity())
        {
            writer.writePropertyName("initialCapacity");
            writer.writeInt32(*request.getInitialCapacity());
        }
        if (request.getMaxCapacity())
        {
            writer.writePropertyName("maxCapacity");
            writer.writeInt32(*request.getMaxCapacity());
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
        gs2RestSessionTask.execute();
    }

	/**
	 * インベントリモデルマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteInventoryModelMaster(std::function<void(AsyncDeleteInventoryModelMasterResult&)> callback, DeleteInventoryModelMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DeleteInventoryModelMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("DELETE");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "inventory");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/inventory/{inventoryName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        gs2RestSessionTask.execute();
    }

	/**
	 * インベントリモデルの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeInventoryModels(std::function<void(AsyncDescribeInventoryModelsResult&)> callback, DescribeInventoryModelsRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeInventoryModelsResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "inventory");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/inventory";
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
        gs2RestSessionTask.execute();
    }

	/**
	 * インベントリモデルを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getInventoryModel(std::function<void(AsyncGetInventoryModelResult&)> callback, GetInventoryModelRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetInventoryModelResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "inventory");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/inventory/{inventoryName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        gs2RestSessionTask.execute();
    }

	/**
	 * アイテムモデルマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeItemModelMasters(std::function<void(AsyncDescribeItemModelMastersResult&)> callback, DescribeItemModelMastersRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeItemModelMastersResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "inventory");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/inventory/{inventoryName}/item";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        gs2RestSessionTask.execute();
    }

	/**
	 * アイテムモデルマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createItemModelMaster(std::function<void(AsyncCreateItemModelMasterResult&)> callback, CreateItemModelMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<CreateItemModelMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "inventory");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/inventory/{inventoryName}/item";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
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
        if (request.getMaxCount())
        {
            writer.writePropertyName("maxCount");
            writer.writeInt64(*request.getMaxCount());
        }
        if (request.getSortValue())
        {
            writer.writePropertyName("sortValue");
            writer.writeInt32(*request.getSortValue());
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
        gs2RestSessionTask.execute();
    }

	/**
	 * アイテムモデルマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getItemModelMaster(std::function<void(AsyncGetItemModelMasterResult&)> callback, GetItemModelMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetItemModelMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "inventory");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/inventory/{inventoryName}/item/{itemName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getItemName();
            url.replace("{itemName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        gs2RestSessionTask.execute();
    }

	/**
	 * アイテムモデルマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateItemModelMaster(std::function<void(AsyncUpdateItemModelMasterResult&)> callback, UpdateItemModelMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<UpdateItemModelMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("PUT");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "inventory");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/inventory/{inventoryName}/item/{itemName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getItemName();
            url.replace("{itemName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
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
        if (request.getMaxCount())
        {
            writer.writePropertyName("maxCount");
            writer.writeInt64(*request.getMaxCount());
        }
        if (request.getSortValue())
        {
            writer.writePropertyName("sortValue");
            writer.writeInt32(*request.getSortValue());
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
        gs2RestSessionTask.execute();
    }

	/**
	 * アイテムモデルマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteItemModelMaster(std::function<void(AsyncDeleteItemModelMasterResult&)> callback, DeleteItemModelMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DeleteItemModelMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("DELETE");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "inventory");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/inventory/{inventoryName}/item/{itemName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getItemName();
            url.replace("{itemName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        gs2RestSessionTask.execute();
    }

	/**
	 * Noneの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeItemModels(std::function<void(AsyncDescribeItemModelsResult&)> callback, DescribeItemModelsRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeItemModelsResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "inventory");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/inventory/{inventoryName}/item";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        gs2RestSessionTask.execute();
    }

	/**
	 * Noneを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getItemModel(std::function<void(AsyncGetItemModelResult&)> callback, GetItemModelRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetItemModelResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "inventory");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/inventory/{inventoryName}/item/{itemName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getItemName();
            url.replace("{itemName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        gs2RestSessionTask.execute();
    }

	/**
	 * 現在有効な所持品マスターのマスターデータをエクスポートします<br>
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
        url.replace("{service}", "inventory");
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
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * 現在有効な現在有効な所持品マスターを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentItemModelMaster(std::function<void(AsyncGetCurrentItemModelMasterResult&)> callback, GetCurrentItemModelMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetCurrentItemModelMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "inventory");
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
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * 現在有効な現在有効な所持品マスターを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentItemModelMaster(std::function<void(AsyncUpdateCurrentItemModelMasterResult&)> callback, UpdateCurrentItemModelMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<UpdateCurrentItemModelMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("PUT");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "inventory");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
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
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * 現在有効な現在有効な所持品マスターを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentItemModelMasterFromGitHub(std::function<void(AsyncUpdateCurrentItemModelMasterFromGitHubResult&)> callback, UpdateCurrentItemModelMasterFromGitHubRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<UpdateCurrentItemModelMasterFromGitHubResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("PUT");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "inventory");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/from_git_hub";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
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
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * インベントリの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeInventories(std::function<void(AsyncDescribeInventoriesResult&)> callback, DescribeInventoriesRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeInventoriesResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "inventory");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/me/inventory";
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
	 * インベントリの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeInventoriesByUserId(std::function<void(AsyncDescribeInventoriesByUserIdResult&)> callback, DescribeInventoriesByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeInventoriesByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "inventory");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/inventory";
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
	 * インベントリを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getInventory(std::function<void(AsyncGetInventoryResult&)> callback, GetInventoryRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetInventoryResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "inventory");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/me/inventory/{inventoryName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
	 * インベントリを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getInventoryByUserId(std::function<void(AsyncGetInventoryByUserIdResult&)> callback, GetInventoryByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetInventoryByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "inventory");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/inventory/{inventoryName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
	 * キャパシティサイズを加算<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void addCapacityByUserId(std::function<void(AsyncAddCapacityByUserIdResult&)> callback, AddCapacityByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<AddCapacityByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "inventory");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/inventory/{inventoryName}/capacity";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getAddCapacityValue())
        {
            writer.writePropertyName("addCapacityValue");
            writer.writeInt32(*request.getAddCapacityValue());
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
	 * キャパシティサイズを設定<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setCapacityByUserId(std::function<void(AsyncSetCapacityByUserIdResult&)> callback, SetCapacityByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<SetCapacityByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("PUT");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "inventory");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/inventory/{inventoryName}/capacity";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getNewCapacityValue())
        {
            writer.writePropertyName("newCapacityValue");
            writer.writeInt32(*request.getNewCapacityValue());
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
	 * インベントリを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteInventoryByUserId(std::function<void(AsyncDeleteInventoryByUserIdResult&)> callback, DeleteInventoryByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DeleteInventoryByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("DELETE");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "inventory");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/inventory/{inventoryName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
	 * スタンプシートでキャパシティサイズを加算<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void addCapacityByStampSheet(std::function<void(AsyncAddCapacityByStampSheetResult&)> callback, AddCapacityByStampSheetRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<AddCapacityByStampSheetResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "inventory");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/stamp/inventory/capacity/add";
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
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
	 * スタンプシートでキャパシティサイズを設定<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setCapacityByStampSheet(std::function<void(AsyncSetCapacityByStampSheetResult&)> callback, SetCapacityByStampSheetRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<SetCapacityByStampSheetResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "inventory");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/stamp/inventory/capacity/set";
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
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
	 * 有効期限ごとのアイテム所持数量の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeItemSets(std::function<void(AsyncDescribeItemSetsResult&)> callback, DescribeItemSetsRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeItemSetsResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "inventory");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/me/inventory/{inventoryName}/item";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
	 * 有効期限ごとのアイテム所持数量の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeItemSetsByUserId(std::function<void(AsyncDescribeItemSetsByUserIdResult&)> callback, DescribeItemSetsByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeItemSetsByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "inventory");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/inventory/{inventoryName}/item";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
	 * 有効期限ごとのアイテム所持数量を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getItemSet(std::function<void(AsyncGetItemSetResult&)> callback, GetItemSetRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetItemSetResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "inventory");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/me/inventory/{inventoryName}/item/{itemName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getItemName();
            url.replace("{itemName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (request.getExpiresAt()) {
            url += joint;
            url += "expiresAt=";
            url += detail::StringVariable(*request.getExpiresAt()).c_str();
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
	 * 有効期限ごとのアイテム所持数量を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getItemSetByUserId(std::function<void(AsyncGetItemSetByUserIdResult&)> callback, GetItemSetByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetItemSetByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "inventory");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/inventory/{inventoryName}/item/{itemName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getItemName();
            url.replace("{itemName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getExpiresAt();
            if (value.has_value())
            {
                detail::StringVariable urlSafeValue(*value);
                url.replace("{expiresAt}", urlSafeValue.c_str());
            }
            else
            {
                url.replace("{expiresAt}", "null");
            }
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
	 * アイテムをインベントリに追加<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void acquireItemSetByUserId(std::function<void(AsyncAcquireItemSetByUserIdResult&)> callback, AcquireItemSetByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<AcquireItemSetByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "inventory");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/inventory/{inventoryName}/item/{itemName}/acquire";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getItemName();
            url.replace("{itemName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getAcquireCount())
        {
            writer.writePropertyName("acquireCount");
            writer.writeInt64(*request.getAcquireCount());
        }
        if (request.getExpiresAt())
        {
            writer.writePropertyName("expiresAt");
            writer.writeInt64(*request.getExpiresAt());
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
	 * インベントリのアイテムを消費<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void consumeItemSet(std::function<void(AsyncConsumeItemSetResult&)> callback, ConsumeItemSetRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<ConsumeItemSetResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "inventory");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/me/inventory/{inventoryName}/item/{itemName}/consume";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getItemName();
            url.replace("{itemName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getConsumeCount())
        {
            writer.writePropertyName("consumeCount");
            writer.writeInt64(*request.getConsumeCount());
        }
        if (request.getExpiresAt())
        {
            writer.writePropertyName("expiresAt");
            writer.writeInt64(*request.getExpiresAt());
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
	 * インベントリのアイテムを消費<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void consumeItemSetByUserId(std::function<void(AsyncConsumeItemSetByUserIdResult&)> callback, ConsumeItemSetByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<ConsumeItemSetByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "inventory");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/inventory/{inventoryName}/item/{itemName}/consume";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getItemName();
            url.replace("{itemName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getConsumeCount())
        {
            writer.writePropertyName("consumeCount");
            writer.writeInt64(*request.getConsumeCount());
        }
        if (request.getExpiresAt())
        {
            writer.writePropertyName("expiresAt");
            writer.writeInt64(*request.getExpiresAt());
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
	 * 有効期限ごとのアイテム所持数量を削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteItemSetByUserId(std::function<void(AsyncDeleteItemSetByUserIdResult&)> callback, DeleteItemSetByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DeleteItemSetByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("DELETE");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "inventory");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/inventory/{inventoryName}/item/{itemName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getItemName();
            url.replace("{itemName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getExpiresAt();
            if (value.has_value())
            {
                detail::StringVariable urlSafeValue(*value);
                url.replace("{expiresAt}", urlSafeValue.c_str());
            }
            else
            {
                url.replace("{expiresAt}", "null");
            }
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
	 * スタンプシートでアイテムをインベントリに追加<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void acquireItemSetByStampSheet(std::function<void(AsyncAcquireItemSetByStampSheetResult&)> callback, AcquireItemSetByStampSheetRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<AcquireItemSetByStampSheetResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "inventory");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/stamp/item/acquire";
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
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
	 * スタンプシートでインベントリのアイテムを消費<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void consumeItemSetByStampTask(std::function<void(AsyncConsumeItemSetByStampTaskResult&)> callback, ConsumeItemSetByStampTaskRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<ConsumeItemSetByStampTaskResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "inventory");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/stamp/item/consume";
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getStampTask())
        {
            writer.writePropertyName("stampTask");
            writer.writeCharArray(*request.getStampTask());
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

protected:
    Gs2RestSession& getGs2RestSession()
    {
        return static_cast<Gs2RestSession&>(getGs2Session());
    }
};

} }

#endif //GS2_INVENTORY_GS2INVENTORYRESTCLIENT_HPP_