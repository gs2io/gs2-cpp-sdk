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

#ifndef GS2_INVENTORY_GS2INVENTORYCLIENT_HPP_
#define GS2_INVENTORY_GS2INVENTORYCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/HttpRequest.hpp>
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "model/model.hpp"
#include "request/DescribeCategoriesRequest.hpp"
#include "request/CreateCategoryRequest.hpp"
#include "request/GetCategoryStatusRequest.hpp"
#include "request/GetCategoryRequest.hpp"
#include "request/UpdateCategoryRequest.hpp"
#include "request/DeleteCategoryRequest.hpp"
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
#include "request/DescribeInventoriesRequest.hpp"
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
#include "result/DescribeCategoriesResult.hpp"
#include "result/CreateCategoryResult.hpp"
#include "result/GetCategoryStatusResult.hpp"
#include "result/GetCategoryResult.hpp"
#include "result/UpdateCategoryResult.hpp"
#include "result/DeleteCategoryResult.hpp"
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
#include "result/DescribeInventoriesResult.hpp"
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

typedef AsyncResult<DescribeCategoriesResult> AsyncDescribeCategoriesResult;
typedef AsyncResult<CreateCategoryResult> AsyncCreateCategoryResult;
typedef AsyncResult<GetCategoryStatusResult> AsyncGetCategoryStatusResult;
typedef AsyncResult<GetCategoryResult> AsyncGetCategoryResult;
typedef AsyncResult<UpdateCategoryResult> AsyncUpdateCategoryResult;
typedef AsyncResult<DeleteCategoryResult> AsyncDeleteCategoryResult;
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
typedef AsyncResult<DescribeInventoriesResult> AsyncDescribeInventoriesResult;
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
class Gs2InventoryClient : public AbstractGs2ClientBase
{
private:
    constexpr static const Char* ENDPOINT = "inventory";

    virtual const Char* getEndPoint() const
    {
        return ENDPOINT;
    }

private:

    void write(detail::json::JsonWriter& writer, const Category& obj)
    {
        writer.writeObjectStart();
        if (obj.getCategoryId())
        {
            writer.writePropertyName("categoryId");
            writer.write(*obj.getCategoryId());
        }
        if (obj.getOwnerId())
        {
            writer.writePropertyName("ownerId");
            writer.write(*obj.getOwnerId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.write(*obj.getName());
        }
        if (obj.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*obj.getDescription());
        }
        if (obj.getOverflowTriggerScriptId())
        {
            writer.writePropertyName("overflowTriggerScriptId");
            writer.write(*obj.getOverflowTriggerScriptId());
        }
        if (obj.getOverflowTriggerQueueId())
        {
            writer.writePropertyName("overflowTriggerQueueId");
            writer.write(*obj.getOverflowTriggerQueueId());
        }
        if (obj.getCreateAt())
        {
            writer.writePropertyName("createAt");
            writer.write(*obj.getCreateAt());
        }
        if (obj.getUpdateAt())
        {
            writer.writePropertyName("updateAt");
            writer.write(*obj.getUpdateAt());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const InventoryModelMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getInventoryModelId())
        {
            writer.writePropertyName("inventoryModelId");
            writer.write(*obj.getInventoryModelId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.write(*obj.getName());
        }
        if (obj.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.write(*obj.getMetadata());
        }
        if (obj.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*obj.getDescription());
        }
        if (obj.getInitialCapacity())
        {
            writer.writePropertyName("initialCapacity");
            writer.write(*obj.getInitialCapacity());
        }
        if (obj.getMaxCapacity())
        {
            writer.writePropertyName("maxCapacity");
            writer.write(*obj.getMaxCapacity());
        }
        if (obj.getCreateAt())
        {
            writer.writePropertyName("createAt");
            writer.write(*obj.getCreateAt());
        }
        if (obj.getUpdateAt())
        {
            writer.writePropertyName("updateAt");
            writer.write(*obj.getUpdateAt());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const InventoryModel& obj)
    {
        writer.writeObjectStart();
        if (obj.getInventoryModelId())
        {
            writer.writePropertyName("inventoryModelId");
            writer.write(*obj.getInventoryModelId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.write(*obj.getName());
        }
        if (obj.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.write(*obj.getMetadata());
        }
        if (obj.getInitialCapacity())
        {
            writer.writePropertyName("initialCapacity");
            writer.write(*obj.getInitialCapacity());
        }
        if (obj.getMaxCapacity())
        {
            writer.writePropertyName("maxCapacity");
            writer.write(*obj.getMaxCapacity());
        }
        if (obj.getItemModels())
        {
            writer.writePropertyName("itemModels");
            writer.writeArrayStart();
            auto& list = *obj.getItemModels();
            for (Int32 i = 0; i < list.getCount(); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const ItemModelMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getItemModelId())
        {
            writer.writePropertyName("itemModelId");
            writer.write(*obj.getItemModelId());
        }
        if (obj.getInventoryModelName())
        {
            writer.writePropertyName("inventoryModelName");
            writer.write(*obj.getInventoryModelName());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.write(*obj.getName());
        }
        if (obj.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*obj.getDescription());
        }
        if (obj.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.write(*obj.getMetadata());
        }
        if (obj.getMaxCount())
        {
            writer.writePropertyName("maxCount");
            writer.write(*obj.getMaxCount());
        }
        if (obj.getSortValue())
        {
            writer.writePropertyName("sortValue");
            writer.write(*obj.getSortValue());
        }
        if (obj.getCreateAt())
        {
            writer.writePropertyName("createAt");
            writer.write(*obj.getCreateAt());
        }
        if (obj.getUpdateAt())
        {
            writer.writePropertyName("updateAt");
            writer.write(*obj.getUpdateAt());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const ItemModel& obj)
    {
        writer.writeObjectStart();
        if (obj.getItemModelId())
        {
            writer.writePropertyName("itemModelId");
            writer.write(*obj.getItemModelId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.write(*obj.getName());
        }
        if (obj.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.write(*obj.getMetadata());
        }
        if (obj.getMaxCount())
        {
            writer.writePropertyName("maxCount");
            writer.write(*obj.getMaxCount());
        }
        if (obj.getSortValue())
        {
            writer.writePropertyName("sortValue");
            writer.write(*obj.getSortValue());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const CurrentItemModelMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getCategoryName())
        {
            writer.writePropertyName("categoryName");
            writer.write(*obj.getCategoryName());
        }
        if (obj.getSettings())
        {
            writer.writePropertyName("settings");
            writer.write(*obj.getSettings());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const Inventory& obj)
    {
        writer.writeObjectStart();
        if (obj.getInventoryId())
        {
            writer.writePropertyName("inventoryId");
            writer.write(*obj.getInventoryId());
        }
        if (obj.getInventoryModelName())
        {
            writer.writePropertyName("inventoryModelName");
            writer.write(*obj.getInventoryModelName());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.write(*obj.getUserId());
        }
        if (obj.getCurrentInventoryCapacityUsage())
        {
            writer.writePropertyName("currentInventoryCapacityUsage");
            writer.write(*obj.getCurrentInventoryCapacityUsage());
        }
        if (obj.getCurrentInventoryMaxCapacity())
        {
            writer.writePropertyName("currentInventoryMaxCapacity");
            writer.write(*obj.getCurrentInventoryMaxCapacity());
        }
        if (obj.getCreateAt())
        {
            writer.writePropertyName("createAt");
            writer.write(*obj.getCreateAt());
        }
        if (obj.getUpdateAt())
        {
            writer.writePropertyName("updateAt");
            writer.write(*obj.getUpdateAt());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const ItemSet& obj)
    {
        writer.writeObjectStart();
        if (obj.getItemSetId())
        {
            writer.writePropertyName("itemSetId");
            writer.write(*obj.getItemSetId());
        }
        if (obj.getInventoryModelName())
        {
            writer.writePropertyName("inventoryModelName");
            writer.write(*obj.getInventoryModelName());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.write(*obj.getUserId());
        }
        if (obj.getItemModelName())
        {
            writer.writePropertyName("itemModelName");
            writer.write(*obj.getItemModelName());
        }
        if (obj.getCount())
        {
            writer.writePropertyName("count");
            writer.write(*obj.getCount());
        }
        if (obj.getSortValue())
        {
            writer.writePropertyName("sortValue");
            writer.write(*obj.getSortValue());
        }
        if (obj.getExpiresAt())
        {
            writer.writePropertyName("expiresAt");
            writer.write(*obj.getExpiresAt());
        }
        if (obj.getCreateAt())
        {
            writer.writePropertyName("createAt");
            writer.write(*obj.getCreateAt());
        }
        if (obj.getUpdateAt())
        {
            writer.writePropertyName("updateAt");
            writer.write(*obj.getUpdateAt());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const ResponseCache& obj)
    {
        writer.writeObjectStart();
        if (obj.getRegion())
        {
            writer.writePropertyName("region");
            writer.write(*obj.getRegion());
        }
        if (obj.getOwnerId())
        {
            writer.writePropertyName("ownerId");
            writer.write(*obj.getOwnerId());
        }
        if (obj.getResponseCacheId())
        {
            writer.writePropertyName("responseCacheId");
            writer.write(*obj.getResponseCacheId());
        }
        if (obj.getRequestHash())
        {
            writer.writePropertyName("requestHash");
            writer.write(*obj.getRequestHash());
        }
        if (obj.getResult())
        {
            writer.writePropertyName("result");
            writer.write(*obj.getResult());
        }
        writer.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
     */
    Gs2InventoryClient(IGs2Credential& credential) :
        AbstractGs2ClientBase(credential)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2InventoryClient(IGs2Credential& credential, const Region& region) :
        AbstractGs2ClientBase(credential, region)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2InventoryClient(IGs2Credential& credential, const Char region[]) :
        AbstractGs2ClientBase(credential, region)
    {
    }

	/**
	 * カテゴリの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCategories(std::function<void(AsyncDescribeCategoriesResult&)> callback, DescribeCategoriesRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeCategoriesResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inventory-handler?handler=gs2_inventory%2Fhandler%2FCategoryFunctionHandler.describeCategories");
        Char encodeBuffer[2048];
        if (request.getPageToken()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPageToken()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("pageToken={value}").replace("{value}", encodeBuffer);
        }
        if (request.getLimit()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLimit()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("limit={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * カテゴリを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createCategory(std::function<void(AsyncCreateCategoryResult&)> callback, CreateCategoryRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateCategoryResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inventory-handler?handler=gs2_inventory%2Fhandler%2FCategoryFunctionHandler.createCategory");
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getName())
        {
            writer.writePropertyName("name");
            writer.write(*request.getName());
        }
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*request.getDescription());
        }
        if (request.getOverflowTriggerScriptId())
        {
            writer.writePropertyName("overflowTriggerScriptId");
            writer.write(*request.getOverflowTriggerScriptId());
        }
        if (request.getOverflowTriggerQueueId())
        {
            writer.writePropertyName("overflowTriggerQueueId");
            writer.write(*request.getOverflowTriggerQueueId());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * カテゴリを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCategoryStatus(std::function<void(AsyncGetCategoryStatusResult&)> callback, GetCategoryStatusRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetCategoryStatusResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inventory-handler?handler=gs2_inventory%2Fhandler%2FCategoryFunctionHandler.getCategoryStatus");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * カテゴリを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCategory(std::function<void(AsyncGetCategoryResult&)> callback, GetCategoryRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetCategoryResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inventory-handler?handler=gs2_inventory%2Fhandler%2FCategoryFunctionHandler.getCategory");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * カテゴリを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCategory(std::function<void(AsyncUpdateCategoryResult&)> callback, UpdateCategoryRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateCategoryResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inventory-handler?handler=gs2_inventory%2Fhandler%2FCategoryFunctionHandler.updateCategory");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*request.getDescription());
        }
        if (request.getOverflowTriggerScriptId())
        {
            writer.writePropertyName("overflowTriggerScriptId");
            writer.write(*request.getOverflowTriggerScriptId());
        }
        if (request.getOverflowTriggerQueueId())
        {
            writer.writePropertyName("overflowTriggerQueueId");
            writer.write(*request.getOverflowTriggerQueueId());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * カテゴリを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteCategory(std::function<void(AsyncDeleteCategoryResult&)> callback, DeleteCategoryRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DeleteCategoryResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inventory-handler?handler=gs2_inventory%2Fhandler%2FCategoryFunctionHandler.deleteCategory");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * インベントリマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeInventoryModelMasters(std::function<void(AsyncDescribeInventoryModelMastersResult&)> callback, DescribeInventoryModelMastersRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeInventoryModelMastersResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inventory-handler?handler=gs2_inventory%2Fhandler%2FInventoryModelMasterFunctionHandler.describeInventoryModelMasters");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getPageToken()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPageToken()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("pageToken={value}").replace("{value}", encodeBuffer);
        }
        if (request.getLimit()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLimit()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("limit={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * インベントリマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createInventoryModelMaster(std::function<void(AsyncCreateInventoryModelMasterResult&)> callback, CreateInventoryModelMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateInventoryModelMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inventory-handler?handler=gs2_inventory%2Fhandler%2FInventoryModelMasterFunctionHandler.createInventoryModelMaster");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getName())
        {
            writer.writePropertyName("name");
            writer.write(*request.getName());
        }
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*request.getDescription());
        }
        if (request.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.write(*request.getMetadata());
        }
        if (request.getInitialCapacity())
        {
            writer.writePropertyName("initialCapacity");
            writer.write(*request.getInitialCapacity());
        }
        if (request.getMaxCapacity())
        {
            writer.writePropertyName("maxCapacity");
            writer.write(*request.getMaxCapacity());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * インベントリマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getInventoryModelMaster(std::function<void(AsyncGetInventoryModelMasterResult&)> callback, GetInventoryModelMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetInventoryModelMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inventory-handler?handler=gs2_inventory%2Fhandler%2FInventoryModelMasterFunctionHandler.getInventoryModelMaster");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getInventoryModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getInventoryModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("inventoryModelName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * インベントリマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateInventoryModelMaster(std::function<void(AsyncUpdateInventoryModelMasterResult&)> callback, UpdateInventoryModelMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateInventoryModelMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inventory-handler?handler=gs2_inventory%2Fhandler%2FInventoryModelMasterFunctionHandler.updateInventoryModelMaster");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getInventoryModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getInventoryModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("inventoryModelName={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*request.getDescription());
        }
        if (request.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.write(*request.getMetadata());
        }
        if (request.getInitialCapacity())
        {
            writer.writePropertyName("initialCapacity");
            writer.write(*request.getInitialCapacity());
        }
        if (request.getMaxCapacity())
        {
            writer.writePropertyName("maxCapacity");
            writer.write(*request.getMaxCapacity());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * インベントリマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteInventoryModelMaster(std::function<void(AsyncDeleteInventoryModelMasterResult&)> callback, DeleteInventoryModelMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DeleteInventoryModelMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inventory-handler?handler=gs2_inventory%2Fhandler%2FInventoryModelMasterFunctionHandler.deleteInventoryModelMaster");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getInventoryModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getInventoryModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("inventoryModelName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * インベントリマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeInventoryModels(std::function<void(AsyncDescribeInventoryModelsResult&)> callback, DescribeInventoryModelsRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeInventoryModelsResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inventory-handler?handler=gs2_inventory%2Fhandler%2FInventoryModelFunctionHandler.describeInventoryModels");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * インベントリマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getInventoryModel(std::function<void(AsyncGetInventoryModelResult&)> callback, GetInventoryModelRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetInventoryModelResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inventory-handler?handler=gs2_inventory%2Fhandler%2FInventoryModelFunctionHandler.getInventoryModel");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getInventoryModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getInventoryModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("inventoryModelName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * アイテムマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeItemModelMasters(std::function<void(AsyncDescribeItemModelMastersResult&)> callback, DescribeItemModelMastersRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeItemModelMastersResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inventory-handler?handler=gs2_inventory%2Fhandler%2FItemModelMasterFunctionHandler.describeItemModelMasters");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getInventoryModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getInventoryModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("inventoryModelName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getPageToken()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPageToken()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("pageToken={value}").replace("{value}", encodeBuffer);
        }
        if (request.getLimit()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLimit()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("limit={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * アイテムマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createItemModelMaster(std::function<void(AsyncCreateItemModelMasterResult&)> callback, CreateItemModelMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateItemModelMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inventory-handler?handler=gs2_inventory%2Fhandler%2FItemModelMasterFunctionHandler.createItemModelMaster");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getInventoryModelName())
        {
            writer.writePropertyName("inventoryModelName");
            writer.write(*request.getInventoryModelName());
        }
        if (request.getName())
        {
            writer.writePropertyName("name");
            writer.write(*request.getName());
        }
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*request.getDescription());
        }
        if (request.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.write(*request.getMetadata());
        }
        if (request.getMaxCount())
        {
            writer.writePropertyName("maxCount");
            writer.write(*request.getMaxCount());
        }
        if (request.getSortValue())
        {
            writer.writePropertyName("sortValue");
            writer.write(*request.getSortValue());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * アイテムマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getItemModelMaster(std::function<void(AsyncGetItemModelMasterResult&)> callback, GetItemModelMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetItemModelMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inventory-handler?handler=gs2_inventory%2Fhandler%2FItemModelMasterFunctionHandler.getItemModelMaster");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getInventoryModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getInventoryModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("inventoryModelName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getItemModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getItemModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("itemModelName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * アイテムマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateItemModelMaster(std::function<void(AsyncUpdateItemModelMasterResult&)> callback, UpdateItemModelMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateItemModelMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inventory-handler?handler=gs2_inventory%2Fhandler%2FItemModelMasterFunctionHandler.updateItemModelMaster");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getInventoryModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getInventoryModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("inventoryModelName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getItemModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getItemModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("itemModelName={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*request.getDescription());
        }
        if (request.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.write(*request.getMetadata());
        }
        if (request.getMaxCount())
        {
            writer.writePropertyName("maxCount");
            writer.write(*request.getMaxCount());
        }
        if (request.getSortValue())
        {
            writer.writePropertyName("sortValue");
            writer.write(*request.getSortValue());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * アイテムマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteItemModelMaster(std::function<void(AsyncDeleteItemModelMasterResult&)> callback, DeleteItemModelMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DeleteItemModelMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inventory-handler?handler=gs2_inventory%2Fhandler%2FItemModelMasterFunctionHandler.deleteItemModelMaster");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getInventoryModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getInventoryModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("inventoryModelName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getItemModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getItemModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("itemModelName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * アイテムマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeItemModels(std::function<void(AsyncDescribeItemModelsResult&)> callback, DescribeItemModelsRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeItemModelsResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inventory-handler?handler=gs2_inventory%2Fhandler%2FItemModelFunctionHandler.describeItemModels");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getInventoryModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getInventoryModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("inventoryModelName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * アイテムマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getItemModel(std::function<void(AsyncGetItemModelResult&)> callback, GetItemModelRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetItemModelResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inventory-handler?handler=gs2_inventory%2Fhandler%2FItemModelFunctionHandler.getItemModel");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getInventoryModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getInventoryModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("inventoryModelName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getItemModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getItemModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("itemModelName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * カテゴリマスターJSONのマスターデータをエクスポートします<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void exportMaster(std::function<void(AsyncExportMasterResult&)> callback, ExportMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<ExportMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inventory-handler?handler=gs2_inventory%2Fhandler%2FCurrentItemModelMasterFunctionHandler.exportMaster");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * 現在有効なカテゴリマスターJSONを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentItemModelMaster(std::function<void(AsyncGetCurrentItemModelMasterResult&)> callback, GetCurrentItemModelMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetCurrentItemModelMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inventory-handler?handler=gs2_inventory%2Fhandler%2FCurrentItemModelMasterFunctionHandler.getCurrentItemModelMaster");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * 現在有効なカテゴリマスターJSONを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentItemModelMaster(std::function<void(AsyncUpdateCurrentItemModelMasterResult&)> callback, UpdateCurrentItemModelMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateCurrentItemModelMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inventory-handler?handler=gs2_inventory%2Fhandler%2FCurrentItemModelMasterFunctionHandler.updateCurrentItemModelMaster");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getSettings())
        {
            writer.writePropertyName("settings");
            writer.write(*request.getSettings());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * インベントリの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeInventories(std::function<void(AsyncDescribeInventoriesResult&)> callback, DescribeInventoriesRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeInventoriesResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inventory-handler?handler=gs2_inventory%2Fhandler%2FInventoryFunctionHandler.describeInventories");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getPageToken()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPageToken()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("pageToken={value}").replace("{value}", encodeBuffer);
        }
        if (request.getLimit()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLimit()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("limit={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        if (request.getDuplicationAvoider())
        {
            httpRequest.addHeader("X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * インベントリを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getInventory(std::function<void(AsyncGetInventoryResult&)> callback, GetInventoryRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetInventoryResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inventory-handler?handler=gs2_inventory%2Fhandler%2FInventoryFunctionHandler.getInventory");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getInventoryModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getInventoryModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("inventoryModelName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        if (request.getDuplicationAvoider())
        {
            httpRequest.addHeader("X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * インベントリを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getInventoryByUserId(std::function<void(AsyncGetInventoryByUserIdResult&)> callback, GetInventoryByUserIdRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetInventoryByUserIdResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inventory-handler?handler=gs2_inventory%2Fhandler%2FInventoryFunctionHandler.getInventoryByUserId");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getInventoryModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getInventoryModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("inventoryModelName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        if (request.getDuplicationAvoider())
        {
            httpRequest.addHeader("X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * キャパシティサイズを加算<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void addCapacityByUserId(std::function<void(AsyncAddCapacityByUserIdResult&)> callback, AddCapacityByUserIdRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<AddCapacityByUserIdResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inventory-handler?handler=gs2_inventory%2Fhandler%2FInventoryFunctionHandler.addCapacityByUserId");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
        }
        if (request.getInventoryModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getInventoryModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("inventoryModelName={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getAddCapacityValue())
        {
            writer.writePropertyName("addCapacityValue");
            writer.write(*request.getAddCapacityValue());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        if (request.getDuplicationAvoider())
        {
            httpRequest.addHeader("X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * キャパシティサイズを設定<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setCapacityByUserId(std::function<void(AsyncSetCapacityByUserIdResult&)> callback, SetCapacityByUserIdRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<SetCapacityByUserIdResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inventory-handler?handler=gs2_inventory%2Fhandler%2FInventoryFunctionHandler.setCapacityByUserId");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
        }
        if (request.getInventoryModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getInventoryModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("inventoryModelName={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getNewCapacityValue())
        {
            writer.writePropertyName("newCapacityValue");
            writer.write(*request.getNewCapacityValue());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        if (request.getDuplicationAvoider())
        {
            httpRequest.addHeader("X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * インベントリを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteInventoryByUserId(std::function<void(AsyncDeleteInventoryByUserIdResult&)> callback, DeleteInventoryByUserIdRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DeleteInventoryByUserIdResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inventory-handler?handler=gs2_inventory%2Fhandler%2FInventoryFunctionHandler.deleteInventoryByUserId");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
        }
        if (request.getInventoryModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getInventoryModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("inventoryModelName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        if (request.getDuplicationAvoider())
        {
            httpRequest.addHeader("X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * キャパシティサイズを加算<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void addCapacityByStampSheet(std::function<void(AsyncAddCapacityByStampSheetResult&)> callback, AddCapacityByStampSheetRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<AddCapacityByStampSheetResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inventory-handler?handler=gs2_inventory%2Fhandler%2FInventoryFunctionHandler.addCapacityByStampSheet");
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getStampSheet())
        {
            writer.writePropertyName("stampSheet");
            writer.write(*request.getStampSheet());
        }
        if (request.getKeyId())
        {
            writer.writePropertyName("keyId");
            writer.write(*request.getKeyId());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        if (request.getDuplicationAvoider())
        {
            httpRequest.addHeader("X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * キャパシティサイズを設定<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setCapacityByStampSheet(std::function<void(AsyncSetCapacityByStampSheetResult&)> callback, SetCapacityByStampSheetRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<SetCapacityByStampSheetResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inventory-handler?handler=gs2_inventory%2Fhandler%2FInventoryFunctionHandler.setCapacityByStampSheet");
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getStampSheet())
        {
            writer.writePropertyName("stampSheet");
            writer.write(*request.getStampSheet());
        }
        if (request.getKeyId())
        {
            writer.writePropertyName("keyId");
            writer.write(*request.getKeyId());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        if (request.getDuplicationAvoider())
        {
            httpRequest.addHeader("X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * アイテムセットの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeItemSets(std::function<void(AsyncDescribeItemSetsResult&)> callback, DescribeItemSetsRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeItemSetsResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inventory-handler?handler=gs2_inventory%2Fhandler%2FItemSetFunctionHandler.describeItemSets");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getInventoryModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getInventoryModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("inventoryModelName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getPageToken()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPageToken()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("pageToken={value}").replace("{value}", encodeBuffer);
        }
        if (request.getLimit()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLimit()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("limit={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        if (request.getDuplicationAvoider())
        {
            httpRequest.addHeader("X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * アイテムセットの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeItemSetsByUserId(std::function<void(AsyncDescribeItemSetsByUserIdResult&)> callback, DescribeItemSetsByUserIdRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeItemSetsByUserIdResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inventory-handler?handler=gs2_inventory%2Fhandler%2FItemSetFunctionHandler.describeItemSetsByUserId");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getInventoryModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getInventoryModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("inventoryModelName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
        }
        if (request.getPageToken()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPageToken()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("pageToken={value}").replace("{value}", encodeBuffer);
        }
        if (request.getLimit()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLimit()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("limit={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        if (request.getDuplicationAvoider())
        {
            httpRequest.addHeader("X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * アイテムセットを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getItemSet(std::function<void(AsyncGetItemSetResult&)> callback, GetItemSetRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetItemSetResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inventory-handler?handler=gs2_inventory%2Fhandler%2FItemSetFunctionHandler.getItemSet");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getInventoryModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getInventoryModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("inventoryModelName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getItemModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getItemModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("itemModelName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getExpiresAt()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExpiresAt()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("expiresAt={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        if (request.getDuplicationAvoider())
        {
            httpRequest.addHeader("X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * アイテムセットを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getItemSetByUserId(std::function<void(AsyncGetItemSetByUserIdResult&)> callback, GetItemSetByUserIdRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetItemSetByUserIdResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inventory-handler?handler=gs2_inventory%2Fhandler%2FItemSetFunctionHandler.getItemSetByUserId");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getInventoryModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getInventoryModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("inventoryModelName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getItemModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getItemModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("itemModelName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
        }
        if (request.getExpiresAt()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExpiresAt()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("expiresAt={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        if (request.getDuplicationAvoider())
        {
            httpRequest.addHeader("X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * アイテムをインベントリに追加<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void acquireItemSetByUserId(std::function<void(AsyncAcquireItemSetByUserIdResult&)> callback, AcquireItemSetByUserIdRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<AcquireItemSetByUserIdResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inventory-handler?handler=gs2_inventory%2Fhandler%2FItemSetFunctionHandler.acquireItemSetByUserId");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getInventoryModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getInventoryModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("inventoryModelName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getItemModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getItemModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("itemModelName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getAcquireCount())
        {
            writer.writePropertyName("acquireCount");
            writer.write(*request.getAcquireCount());
        }
        if (request.getExpiresAt())
        {
            writer.writePropertyName("expiresAt");
            writer.write(*request.getExpiresAt());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        if (request.getDuplicationAvoider())
        {
            httpRequest.addHeader("X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * インベントリのアイテムを消費<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void consumeItemSet(std::function<void(AsyncConsumeItemSetResult&)> callback, ConsumeItemSetRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<ConsumeItemSetResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inventory-handler?handler=gs2_inventory%2Fhandler%2FItemSetFunctionHandler.consumeItemSet");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getInventoryModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getInventoryModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("inventoryModelName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getItemModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getItemModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("itemModelName={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getConsumeCount())
        {
            writer.writePropertyName("consumeCount");
            writer.write(*request.getConsumeCount());
        }
        if (request.getExpiresAt())
        {
            writer.writePropertyName("expiresAt");
            writer.write(*request.getExpiresAt());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        if (request.getDuplicationAvoider())
        {
            httpRequest.addHeader("X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * インベントリのアイテムを消費<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void consumeItemSetByUserId(std::function<void(AsyncConsumeItemSetByUserIdResult&)> callback, ConsumeItemSetByUserIdRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<ConsumeItemSetByUserIdResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inventory-handler?handler=gs2_inventory%2Fhandler%2FItemSetFunctionHandler.consumeItemSetByUserId");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getInventoryModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getInventoryModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("inventoryModelName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getItemModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getItemModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("itemModelName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getConsumeCount())
        {
            writer.writePropertyName("consumeCount");
            writer.write(*request.getConsumeCount());
        }
        if (request.getExpiresAt())
        {
            writer.writePropertyName("expiresAt");
            writer.write(*request.getExpiresAt());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        if (request.getDuplicationAvoider())
        {
            httpRequest.addHeader("X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * アイテムセットを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteItemSetByUserId(std::function<void(AsyncDeleteItemSetByUserIdResult&)> callback, DeleteItemSetByUserIdRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DeleteItemSetByUserIdResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inventory-handler?handler=gs2_inventory%2Fhandler%2FItemSetFunctionHandler.deleteItemSetByUserId");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
        }
        if (request.getInventoryModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getInventoryModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("inventoryModelName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getItemModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getItemModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("itemModelName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getExpiresAt()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExpiresAt()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("expiresAt={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        if (request.getDuplicationAvoider())
        {
            httpRequest.addHeader("X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * アイテムをインベントリに追加<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void acquireItemSetByStampSheet(std::function<void(AsyncAcquireItemSetByStampSheetResult&)> callback, AcquireItemSetByStampSheetRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<AcquireItemSetByStampSheetResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inventory-handler?handler=gs2_inventory%2Fhandler%2FItemSetFunctionHandler.acquireItemSetByStampSheet");
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getStampSheet())
        {
            writer.writePropertyName("stampSheet");
            writer.write(*request.getStampSheet());
        }
        if (request.getKeyId())
        {
            writer.writePropertyName("keyId");
            writer.write(*request.getKeyId());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        if (request.getDuplicationAvoider())
        {
            httpRequest.addHeader("X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * インベントリのアイテムを消費<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void consumeItemSetByStampTask(std::function<void(AsyncConsumeItemSetByStampTaskResult&)> callback, ConsumeItemSetByStampTaskRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<ConsumeItemSetByStampTaskResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inventory-handler?handler=gs2_inventory%2Fhandler%2FItemSetFunctionHandler.consumeItemSetByStampTask");
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getStampTask())
        {
            writer.writePropertyName("stampTask");
            writer.write(*request.getStampTask());
        }
        if (request.getKeyId())
        {
            writer.writePropertyName("keyId");
            writer.write(*request.getKeyId());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        if (request.getDuplicationAvoider())
        {
            httpRequest.addHeader("X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        httpRequest.setCallback(callback);
        send(httpRequest);
    }
};

} }

#endif //GS2_INVENTORY_GS2INVENTORYCLIENT_HPP_